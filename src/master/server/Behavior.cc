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

#include "Behavior.h"

#include <utility>
#include <log4cxx/helpers/messagebuffer.h>
#include <log4cxx/logger.h>
#include <log4cxx/mdc.h>
#include <utility/include/Log.h>


LOG_DECLARE_FILE("master");

CxxSockets::Host Behavior::findFailoverTarget(const CxxSockets::Host& failed_host) {

    for (const auto& pair : _pairs) {
        if (pair.first == failed_host) {
            LOG_TRACE_MSG("target is host " << pair.second.uhn());
            return pair.second;
        }
    }

    LOG_TRACE_MSG("BOGUS HOST IN BEHAVIOR");
    CxxSockets::Host bogus;
    return bogus;
}
