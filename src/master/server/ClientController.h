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

#ifndef MASTER_CLIENT_CONTROLLER_H_
#define MASTER_CLIENT_CONTROLLER_H_

#include <utility/include/cxxsockets/SecureTCPSocket.h>
#include <pthread.h>
#include <utility/include/UserId.h>
#include <memory>
#include <thread>
#include <string>

#include "common/ClientProtocol.h"
#include "common/Ids.h"
#include "common/types.h"
#include "protocol/BGMasterClientProtocolSpec.h"

//! \brief One ClientController for each client connected to BGMaster.
//!
//! Client Controller owns the sockets connected to the client and all
//! messages to and from the client flow through it.
class ClientController : public std::enable_shared_from_this<ClientController> {
    //! \brief Protocol management object
    const ClientProtocolPtr _prot;
    bool _ending;

    //! \brief my id remote host:port
    const ClientId _client_id;

    //! \brief Thread to wait for requests
    std::thread _client_socket_poller;

    //! \brief my socket poller thread id
    pthread_t _my_tid;

    //! \brief Administrative or Normal user.
    const CxxSockets::UserType _utype;

    //! \brief process a start request
    void doStartRequest(const BGMasterClientProtocolSpec::StartRequest& startreq);
    //! \brief process an agent list request
    // Don't actually do anything with the request itself so don't take a parameter.
    void doAgentRequest();
    //! \brief process a wait request
    void doWaitRequest(const BGMasterClientProtocolSpec::WaitRequest& waitreq);
    //! \brief process a client list request
    void doClientsRequest();
    //! \brief process a stop request
    void doStopRequest(const BGMasterClientProtocolSpec::StopRequest& stopreq);
    //! \brief process a status request
    void doStatusRequest(const BGMasterClientProtocolSpec::StatusRequest& statusreq);
    //! \brief process a request to terminate bgmaster_server
    void doTermRequest(const BGMasterClientProtocolSpec::TerminateRequest& termreq);
    //! \brief process a request to reload config
    void doReloadRequest(const BGMasterClientProtocolSpec::ReloadRequest& relreq);
    //! \brief process a request to execute a failover
    void doFailRequest(const BGMasterClientProtocolSpec::FailoverRequest& failreq);
    //! \brief process a server status request
    void doMasterStatRequest();
    //! \brief wait for an alias to start
    void doAliasWaitRequest(const BGMasterClientProtocolSpec::Alias_waitRequest& waitreq);
    //! \brief get the errors from the ring buffer
    void doErrorsRequest();
    //! \brief get the history from the ring buffer
    void doHistoryRequest();
    //! \brief Start an event/error monitor
    void doMonitorRequest();
    //! \brief End an event/error monitor
    void doEndmonitorRequest();
    //! \brief Change/get log levels
    void doLoglevelRequest(const BGMasterClientProtocolSpec::LoglevelRequest& loglevreq);
    //! \brief Get list of idle aliases
    void doGetidleRequest();

  public:
    ClientController(const ClientProtocolPtr& prot, const std::string& ipaddr, const int port, const CxxSockets::UserType utype);

    ~ClientController();

    //! \brief clean up client
    void cancel();

    //! \brief Poll the socket for new messages from bgmaster
    void waitMessages();

    //! \brief Start the thread that polls the socket for messages
    void startPoller();

    void processRequest();

    const std::string& getUserId() const { return _prot->getResponder()->getUserId().getUser(); }
    const ClientId& get_client_id() const { return _client_id; }
};

#endif
