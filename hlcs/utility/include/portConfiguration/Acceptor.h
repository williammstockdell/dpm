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

#ifndef BGQ_UTILITY_ACCEPTOR_H_
#define BGQ_UTILITY_ACCEPTOR_H_

/*! \file
 *
 *  \brief Class for accepting connections.
 */


#include "ServerPortConfiguration.h"
#include "SslConfiguration.h"
#include "types.h"

#include <utility/include/UserId.h>


#include <string>
#include <vector>


namespace bgq {
namespace utility {


/*!
 * \brief Accept connections from configured ports.
 *
 * Usage:
 *
 * -# Create an Acceptor using a ServerPortConfiguration.
 * -# Call start() with your accept handler.
 *
 */
class Acceptor
{
public:

    /*! \brief name space for status values. */
    struct Status {
        enum Value {
            OK=0, //!< Everything's ok.
            NowAccepting, //!< Now accepting connections.
            ListenError, //!< Error listening on a port, might be in use.
            ResolveError, //!< Failed to resolve a pair, configuration error.
            AcceptError, //!< Async accept returned an error, but still accepting on other ports.
            NoAcceptors //!< Async accept returned an error, and now not accepting on any ports.
        };
    };


    /*! \brief Arguments to AcceptHandler.
     *
     * If the status is NowAccepting,
     * endpoints will be set to the endpoints that the
     * server is accepting connections on.
     *
     * If OK, the user_id will always be set.
     * The client usually sends its user info.
     * If the client uses the administrative certificate
     * and doesn't send its user info then the
     * user will be the current user
     * (i.e., whoever this process is running as).
     *
     * If the client presents the administrative certificate
     * then the user_type will be Administrative,
     * otherwise it will be Normal.
     *
     * \param socket_ptr The socket, connected to the client if OK, otherwise null.
     * \param status One of the Status values.
     * \param user_id_ptr If status is OK, the user that connected.
     * \param user_type If status is OK, the type of the user.
     *
     */
    struct AcceptArguments
    {
        static const AcceptArguments ResolveError;
        static const AcceptArguments ListenError;
        static const AcceptArguments NoAcceptors;
        static const AcceptArguments AcceptError;

        Status::Value status;
        portConfig::SocketPtr socket_ptr;
        UserId::ConstPtr user_id_ptr;
        portConfig::UserType::Value user_type;
        std::string client_cn;

        explicit AcceptArguments(
                Status::Value status
            );

        // status will be NowAccepting
        explicit AcceptArguments(
            );

        AcceptArguments(
                portConfig::SocketPtr socket_ptr,
                UserId::ConstPtr user_id_ptr,
                portConfig::UserType::Value user_type,
                const std::string& client_cn
            );
    };


    /*! \brief Constructor
     *
     * Call start() to start accepting.
     *
     */
    Acceptor(
            const ServerPortConfiguration& port_configuration, //!< [copied]
            portConfig::UserIdHandling::Value user_id_handling = portConfig::UserIdHandling::Process //!< user ID handling.
        );

    /*! \brief Start accepting connections.
     *
     * First, starts resolving the pairs from the port configuration.
     *
     * If resolving fails, calls the accept_handler with Status::ResolveError.
     * If can't start accepting on a socket, calls the accept_handler with Status::ListenError.
     * In either of these cases, gets rid of other acceptors so has no work.
     *
     * If resolving is successful, but no endpoints are returned,
     * calls the accept_handler with Status::NoAcceptors.
     * Has no work.
     *
     * If resolving is successful and is now accepting on at least one port,
     * calls the accept_handler with Status::NowAccepting.
     *
     * When a client connects, calls the accept_handler
     * with the socket and Status::OK.
     *
     * If the async accept fails on an acceptor, the acceptor
     * is closed.
     * If there is still an acceptor, the accept_handler is called with Status::AcceptError.
     * If there are no acceptors left, the accept_handler is called with Status::NoAcceptors.
     * If there are no acceptors then there is no work.
     *
     * After calling start(),
     * several file descriptors will likely be open for accepting.
     * The file descriptors have the close-on-exec flag set.
     *
     */
    void start(

        );

    /*! \brief Stop accepting connections. */
    void stop();


private:



    const ServerPortConfiguration _port_config;
    portConfig::UserIdHandling::Value _user_id_handling;


    void _startResolve(
            ServerPortConfiguration::Pairs::const_iterator pi
        );

    void _handleResolve(
            ServerPortConfiguration::Pairs::const_iterator pi
        );

    void _startAccept(

        );

    void _handleAccept(

            portConfig::SocketPtr socket_ptr
        );

    void _handshakeComplete(
            portConfig::SocketPtr socket_ptr,
            UserId::ConstPtr user_id_ptr,
            portConfig::UserType::Value user_type,
            const std::string& client_cn
        );


    void _stopImpl();
};


} // namespace bgq::utility
} // namespace bgq

#endif
