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

#include "AliasList.h"

#include <utility/include/Log.h>
#include <log4cxx/logger.h>
#include <memory>

#include "Alias.h"
#include "server/types.h"

LOG_DECLARE_FILE("master");

bool AliasList::find_alias(const std::string& al, AliasPtr& alias) const {
    LOG_TRACE_MSG(__FUNCTION__);
    for (const AliasPtr& curr_alias : _alias_list) {
        if (curr_alias->get_name() == al) {
            alias = curr_alias;
            return true;
        }
    }
    return false;
}
