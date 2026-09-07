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

/*!
 * \file utility/include/UserId.h
 * \brief \link bgq::utility::UserId UserId\endlink definition.
 */

#ifndef BGQ_UTILITY_USER_ID_
#define BGQ_UTILITY_USER_ID_

#include <sys/types.h>

#include <list>
#include <string>
#include <vector>
#include <memory>
#include <unistd.h>

namespace bgq {
namespace utility {

/*!
 * \brief Container for a user's real uid and group IDs.
 */
class UserId {
  public:
    typedef std::pair<gid_t, std::string> Group;
    typedef std::list<Group> GroupList;
    typedef std::shared_ptr<UserId> Ptr;
    typedef std::shared_ptr<const UserId> ConstPtr;

  public:
    /*!
     * \brief ctor.
     *
     * Obtains the uid's name and grouplist.
     *
     * \throws std::runtime_error if getpwuid_r fails
     */
    explicit UserId(uid_t uid = getuid() //!< [in] uid to lookup
    );

    /*!
     * \brief ctor.
     *
     * Obtains the requested user's uid and grouplist. If remote user indicator is set the uid and
     * gid is ignored (set to 0).
     *
     * \throws std::runtime_error if getpwnam_r fails unless remote user indicator is true
     */
    explicit UserId(const std::string& user,           //!< [in] User to lookup
                    const bool allowRemoteUser = false //!< [in] Remote user indicator
    );

    /*!
     * \brief ctor.
     *
     * Deserialize UserId from a string created by UserId::serialize
     *
     */
    explicit UserId(const std::vector<char>& buf);

    /*!
     * \brief Get the username as a string.
     */
    const std::string& getUser() const { return _name; }

    /*!
     * \brief Set the username.
     */
    void setUser(const std::string& name //!< [in]
    ) {
        _name = name;
    }

    /*!
     * \brief Get the uid.
     */
    uid_t getUid() const { return _uid; }

    /*!
     * \brief Set the uid.
     */
    void setUid(uid_t uid //!< [in]
    ) {
        _uid = uid;
    }

    /*!
     * \brief Get the user's group list.
     */
    const GroupList& getGroups() const { return _groups; }

    /*!
     * \brief Set the user's group list.
     */
    void setGroups(const GroupList& groups //!< [in]
    ) {
        _groups = groups;
    }

    /*!
     * \brief Equality operator.
     */
    bool operator==(const UserId& other) const { return _name == other._name; }

    /*!
     * \brief Test if this user is a member in the requested group.
     *
     * \returns true if the user is a member.
     * \returns false if the user is not a member.
     */
    bool isMember(const std::string& group //!< [in/
    ) const;

    /*!
     * \brief Serialize into a string.
     */
    std::string serialize();

  private:

    /*!
     * \brief
     */
    void setGroupList(gid_t gid //!< [in]
    );

  private:
    std::string _name; //!< user name
    uid_t _uid;        //!< real uid
    GroupList _groups; //!< secondary groups
};

} // namespace utility
} // namespace bgq

#endif
