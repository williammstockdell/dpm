/* begin_generated_IBM_copyright_prolog                             */
/*                                                                  */
/* This is an automatically generated copyright prolog.             */
/* After initializing,  DO NOT MODIFY OR MOVE                       */
/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of IBM                             */
/*                                                                  */
/* Blue Gene/Q                                                      */
/*                                                                  */
/* (C) Copyright IBM Corp.  2010, 2011                              */
/*                                                                  */
/* US Government Users Restricted Rights -                          */
/* Use, duplication or disclosure restricted                        */
/* by GSA ADP Schedule Contract with IBM Corp.                      */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL).                                    */
/*                                                                  */
/* ================================================================ */
/*                                                                  */
/* end_generated_IBM_copyright_prolog                               */

/* ================================================================ */
/*                                                                  */
/* Modifications Copyright (C) Will Stockdell 2026                  */
/*                                                                  */
/* Modifications to this file are made available under the          */
/* Eclipse Public License (EPL) version 1.0.                        */
/*                                                                  */
/* ================================================================ */

#include <UserId.h>
#include <Log.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>
#include <assert.h>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/logger.h>
#include <sys/types.h>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <exception>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include <arpa/inet.h>
#include <cstdint>
#include <limits>
#include <stdexcept>

LOG_DECLARE_FILE("utility");

namespace {

    constexpr uint32_t UserIdWireVersion = 1;

    void appendUint32(std::string& out, const uint32_t value) {
        const uint32_t networkValue = htonl(value);
        const char* bytes = reinterpret_cast<const char*>(&networkValue);

        out.append(bytes, sizeof(networkValue));
    }

    uint32_t readUint32(const std::vector<char>& buf, size_t& offset) {
        if (offset > buf.size() ||
            buf.size() - offset < sizeof(uint32_t)) {
            throw std::runtime_error("Truncated UserId serialization");
        }

        uint32_t networkValue;
        memcpy(&networkValue, buf.data() + offset, sizeof(networkValue));

        offset += sizeof(networkValue);

        return ntohl(networkValue);
    }

    void appendString(std::string& out, const std::string& value) {
        if (value.size() > std::numeric_limits<uint32_t>::max()) {
            throw std::runtime_error("UserId string too large to serialize");
        }

        appendUint32(out, static_cast<uint32_t>(value.size()));
        out.append(value);
    }

    std::string readString(const std::vector<char>& buf, size_t& offset) {
        const uint32_t length = readUint32(buf, offset);

        if (offset > buf.size() ||
            buf.size() - offset < length) {
            throw std::runtime_error("Truncated UserId string");
        }

        std::string result(
                           buf.data() + offset,
                           buf.data() + offset + length);

        offset += length;

        return result;
    }

} // anonymous namespace

namespace bgq {
namespace utility {

UserId::UserId(const uid_t uid) : _name(), _uid(uid), _groups() {
    // get username
    LOG_DEBUG_MSG("Getting username for uid " << _uid);

    const long usernameLength = sysconf(_SC_GETPW_R_SIZE_MAX);
    const std::size_t bufferSize = usernameLength > 0 ? static_cast<std::size_t>(usernameLength) : 16384;

    std::vector<char> buf(bufferSize);

    struct passwd mypwent{};
    struct passwd* mypwent_p = nullptr;

    errno = 0;

    const int result = getpwuid_r(_uid, &mypwent, buf.data(), buf.size(), &mypwent_p);

    if (!result && mypwent_p) {
        _name = mypwent_p->pw_name;
        LOG_DEBUG_MSG("username " << _name);
    } else {
        std::ostringstream errmsg;
        errmsg << "Failed to get user for uid " << uid << ": ";
        if (result == 0 || result == ENOENT || result == ESRCH || result == EBADF || result == EPERM) {
            errmsg << "user not found";
        } else {
            char strbuf[1024];
            errmsg << "result=" << result << " (" << strerror_r(result, strbuf, sizeof(buf)) << ")";
        }
        LOG_WARN_MSG(errmsg.str());
        throw std::runtime_error(errmsg.str());
    }

    // get secondary groups
    this->setGroupList(mypwent_p->pw_gid);
}

UserId::UserId(const std::string& user, const bool allowRemoteUser) : _name(user), _uid(), _groups() {
    // get uid
    LOG_DEBUG_MSG("Getting uid for username " << _name);
    const long usernameLength = sysconf(_SC_GETPW_R_SIZE_MAX);
    const std::size_t bufferSize = usernameLength > 0 ? static_cast<std::size_t>(usernameLength) : 16384;

    std::vector<char> buf(bufferSize);

    struct passwd mypwent;
    memset(&mypwent, 0, sizeof(mypwent));

    struct passwd* mypwent_p = NULL;

    const int result = getpwnam_r(_name.c_str(), &mypwent, buf.data(), buf.size(), &mypwent_p);

    if (!result && mypwent_p) {
        _uid = mypwent_p->pw_uid;
        LOG_DEBUG_MSG("uid " << _uid);
    } else if (allowRemoteUser) {
        // If remote user indicator then only user field needs to be set
        return;
    } else {
        std::ostringstream errmsg;
        errmsg << "Failed to get uid for user '" << _name << "', ";
        if (result == 0 || result == ENOENT || result == ESRCH || result == EBADF || result == EPERM) {
            errmsg << "user not found";
        } else {
            char strbuf[1024];
            errmsg << "result=" << result << " (" << strerror_r(result, strbuf, sizeof(buf)) << ")";
        }
        LOG_WARN_MSG(errmsg.str());
        throw std::runtime_error(errmsg.str());
    }

    // get secondary groups
    this->setGroupList(mypwent_p->pw_gid);
}

UserId::UserId(const std::vector<char>& buf) {

    try {
        size_t offset = 0;

        const uint32_t version = readUint32(buf, offset);
        if (version != UserIdWireVersion) {
            throw std::runtime_error(
                "Unsupported UserId serialization version");
        }

        _name = readString(buf, offset);

        _uid = static_cast<uid_t>(
            readUint32(buf, offset));

        const uint32_t groupCount =
            readUint32(buf, offset);

        for (uint32_t i = 0; i < groupCount; ++i) {
            const gid_t gid = static_cast<gid_t>(
                readUint32(buf, offset));

            std::string groupName =
                readString(buf, offset);

            _groups.emplace_back(
                gid,
                std::move(groupName));
        }

        if (offset != buf.size()) {
            throw std::runtime_error(
                "Unexpected trailing data in UserId serialization");
        }
    } catch (const std::exception& e) {

        LOG_ERROR_MSG("Could not deserialize UserId buffer: " << e.what());

        throw;
    }
}

bool UserId::isMember(const std::string& group) const {
    for (const Group& g : _groups) {
        LOG_DEBUG_MSG("Comparing " << group << " to " << g.second);
        if (g.second == group) {
            return true;
        }
    }
    LOG_DEBUG_MSG(_name << " is not a member of group " << group);

    return false;
}

void UserId::setGroupList(const gid_t gid) {

    LOG_DEBUG_MSG("Getting secondary group list for '" << _name << "' gid '" << gid << "'");
    // get supplementary group list
    int group_count = 0;
    std::vector<gid_t> grouplist;

    if (getgrouplist(_name.c_str(), gid, nullptr, &group_count) < 0) {
        grouplist.resize(static_cast<std::size_t>(group_count));

        if (getgrouplist(_name.c_str(), gid, grouplist.data(), &group_count) < 0) {
            // FIXME: handle failure
            assert(false);
        }
    }

    LOG_TRACE_MSG("Secondary group list " << group_count);

    // add each group
    for (gid_t i = 0; i < static_cast<size_t>(group_count); ++i) {

        // get gid
        const gid_t gid = grouplist[i];

        // allocate storage for group name
        long group_buffer_length = sysconf(_SC_GETPW_R_SIZE_MAX);
        LOG_TRACE_MSG("Group buffer length " << group_buffer_length);

        std::vector<char> buf(static_cast<std::size_t>(group_buffer_length));

        struct group mygroup{};
        struct group* group_p = nullptr;
        errno = 0;
        int rc = 0;

        while ((rc = getgrgid_r(gid, &mygroup, buf.data(), buf.size(), &group_p)) == ERANGE) {
            group_buffer_length *= 2;

            LOG_TRACE_MSG("Increasing group buffer length to " << group_buffer_length);

            buf.resize(static_cast<std::size_t>(group_buffer_length));
        }

        if (rc == 0 && group_p) {
            // add to list
            assert(mygroup.gr_name);
            _groups.push_front(GroupList::value_type(gid, mygroup.gr_name));
            LOG_DEBUG_MSG("Added group " << mygroup.gr_name << " with " << gid);
        } else if (!rc) {
            LOG_DEBUG_MSG("Could not find group name for gid " << gid);
            // add entry with an empty group name
            _groups.push_front(GroupList::value_type(gid, Group::second_type()));
        } else {
            LOG_WARN_MSG("Could not find group name for gid " << gid << ": " << strerror(rc));
        }
    }

    // ensure group list matches expected count
    if (static_cast<int>(_groups.size()) != group_count) {
        LOG_WARN_MSG("Group list size (" << _groups.size() << ") does not equal expected size (" << group_count << ")");
    }

    // primary gid needs to be at the front
    const GroupList::iterator primary = std::find_if(_groups.begin(), _groups.end(), [gid](const Group& group) { return group.first == gid; });

    if (primary == _groups.end()) {
        LOG_WARN_MSG("Could not find primary gid " << gid << " in secondary group list");
    } else if (primary != _groups.begin()) {
        _groups.push_front(*primary);
        _groups.erase(primary);
        LOG_DEBUG_MSG("moved gid " << gid << " (" << _groups.begin()->second << ") to front");
    }
}

std::string UserId::serialize() {

    std::string out;

    appendUint32(out, UserIdWireVersion);
    appendString(out, _name);

    if (static_cast<uintmax_t>(_uid) >
        std::numeric_limits<uint32_t>::max()) {
        throw std::runtime_error(
            "UserId uid is too large to serialize");
    }

    appendUint32(
        out,
        static_cast<uint32_t>(_uid));

    if (_groups.size() >
        std::numeric_limits<uint32_t>::max()) {
        throw std::runtime_error(
            "Too many groups to serialize");
    }

    appendUint32(
        out,
        static_cast<uint32_t>(_groups.size()));

    for (const Group& group : _groups) {
        if (static_cast<uintmax_t>(group.first) >
            std::numeric_limits<uint32_t>::max()) {
            throw std::runtime_error(
                "UserId gid is too large to serialize");
        }

        appendUint32(
            out,
            static_cast<uint32_t>(group.first));

        appendString(out, group.second);
    }

    return out;
}

} // namespace utility
} // namespace bgq
