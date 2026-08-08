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


#include <utility/include/portConfiguration/Acceptor.h>

#include "Handshaker.h"
#include "pc_util.h"

#include "Log.h"
#include "UserId.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

#include <fcntl.h>
#include <unistd.h>


LOG_DECLARE_FILE( "utility" );


using std::exception;
using std::ostringstream;
using std::runtime_error;
using std::string;


namespace bgq {
namespace utility {


// Class Acceptor::AcceptArguments


const Acceptor::AcceptArguments Acceptor::AcceptArguments::ResolveError( Status::ResolveError );
const Acceptor::AcceptArguments Acceptor::AcceptArguments::ListenError( Status::ListenError );
const Acceptor::AcceptArguments Acceptor::AcceptArguments::NoAcceptors( Status::NoAcceptors );
const Acceptor::AcceptArguments Acceptor::AcceptArguments::AcceptError( Status::AcceptError );


Acceptor::AcceptArguments::AcceptArguments(
        Status::Value status
    ) :
        status(status),
        user_type(portConfig::UserType::Normal)
{
    // Nothing to do.
}


Acceptor::AcceptArguments::AcceptArguments(
    ) :
        status(Status::NowAccepting),
        socket_ptr(),
        user_id_ptr(),
        user_type(portConfig::UserType::None),
        client_cn()
{
    // Nothing to do.
}


Acceptor::AcceptArguments::AcceptArguments(
        portConfig::SocketPtr socket_ptr,
        UserId::ConstPtr user_id_ptr,
        portConfig::UserType::Value user_type,
        const std::string& client_cn
    ) :
        status(Status::OK),
        socket_ptr(socket_ptr),
        user_id_ptr(user_id_ptr),
        user_type(user_type),
        client_cn(client_cn)
{
    // Nothing to do.
}


// Class Acceptor

Acceptor::Acceptor(
        const ServerPortConfiguration& port_configuration,
        portConfig::UserIdHandling::Value user_id_handling
    ) :
    _port_config( port_configuration ),
    _user_id_handling(user_id_handling)
{
    // Nothing to do.
}


void
Acceptor::start(
    )
{
}


void
Acceptor::stop()
{
    LOG_DEBUG_MSG( "Requested to stop..." );

}


void
Acceptor::_startAccept(

    )
{
}


void
Acceptor::_handshakeComplete(
        portConfig::SocketPtr socket_ptr,
        UserId::ConstPtr user_id_ptr,
        portConfig::UserType::Value user_type,
        const std::string& client_cn
    )
{

}


void
Acceptor::_stopImpl()
{
    LOG_DEBUG_MSG( "In _stopImpl" );

}


} // namespace bgq::utility
} // namespace bgq
