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

#include "ClientManager.h"

#include <log4cxx/logger.h>
#include <utility/include/Log.h>
#include <algorithm>
#include <memory>
#include <ostream>
#include <string>

#include "ClientController.h"
#include "server/types.h"

LOG_DECLARE_FILE("master");

ClientManager::ClientManager() : _ending(false) {
    // Nothing to do
}

void ClientManager::cancel() {
    LOG_TRACE_MSG(__FUNCTION__);
    _ending = true;

    std::vector<ClientControllerPtr> clients;
    {
        std::lock_guard lock(_clientMutex);
        clients = _clients;
    }

    for (unsigned i = 0; i < clients.size(); ++i)
        clients[i]->cancel();
}

void ClientManager::removeClient(ClientControllerPtr c) {
    LOG_TRACE_MSG(__FUNCTION__);
    std::lock_guard lock(_clientMutex);
    _clients.erase(remove(_clients.begin(), _clients.end(), c), _clients.end());
}

std::vector<ClientControllerPtr> ClientManager::getClients() {
    LOG_TRACE_MSG(__FUNCTION__);
    std::lock_guard lock(_clientMutex);
    return _clients;
}

void ClientManager::addClient(ClientControllerPtr c) {
    LOG_TRACE_MSG(__FUNCTION__);
    if (_ending)
        return; // Don't accept anybody new if we're going away.
    std::lock_guard lock(_clientMutex);
    _clients.push_back(c);
    LOG_DEBUG_MSG(_clients.size() << " clients managed");
    c->startPoller();
    return;
}
