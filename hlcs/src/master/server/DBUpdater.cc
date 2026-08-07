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
/* (C) Copyright IBM Corp.  2011, 2012                              */
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

#include "DBUpdater.h"


#include <utility/include/Log.h>


LOG_DECLARE_FILE("master");

DBUpdater::DBUpdater(
        ) :
    _ending(false),
    _ended(false)
{
    // Nothing to do
}

DBUpdater::~DBUpdater()
{
    end();
}

void
DBUpdater::start()
{
    return;
}

void
DBUpdater::runThread()
{
    LOG_TRACE_MSG(__FUNCTION__);
    return;
}

void
DBUpdater::addMsg(
        const std::string& msg
        )
{
    LOG_TRACE_MSG(__FUNCTION__);
    return;
    LOG_TRACE_MSG("Added following message to drop off queue: " << msg);
}

void
DBUpdater::end()
{
    LOG_TRACE_MSG(__FUNCTION__);
    return;
}
