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

#include "AgentBase.h"

#include "BinaryController.h"

#include <algorithm>
#include <utility/include/Log.h>

LOG_DECLARE_FILE("master");

bool AgentBase::find_binary(const BinaryId& id, BinaryControllerPtr& p) const {
    LOG_TRACE_MSG(__FUNCTION__);
    bool foundit = false;
    for (const BinaryControllerPtr& bincont : _binaries) {
        if (id == bincont->get_binid()) {
            p = bincont;
            foundit = true;
        }
    }
    return foundit;
}

bool AgentBase::runningAlias(const std::string& alias_name) const {
    LOG_TRACE_MSG(__FUNCTION__);
    for (const BinaryControllerPtr& bptr : _binaries) {
        if (bptr->get_alias_name() == alias_name)
            return true;
    }
    return false;
}

void AgentBase::addController(const BinaryControllerPtr& controller) {

    // FIXME: Remove the ordering and only add it back if it is policy based.
    _binaries.insert(_binaries.begin(), controller);
}

void AgentBase::removeController(const BinaryControllerPtr& controller) { _binaries.erase(std::remove(_binaries.begin(), _binaries.end(), controller), _binaries.end()); }
