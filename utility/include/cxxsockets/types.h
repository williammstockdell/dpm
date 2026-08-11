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

/*!
 * \file utility/include/cxxsockets/types.h
 */

#ifndef CXXSOCKET_TYPES_H
#define CXXSOCKET_TYPES_H

#include <sstream>
#include <memory>

namespace CxxSockets {

class File;
class FileLocker;
class FileSet;
class ListenerSet;
class ListeningSocket;
class SecureTCPSocket;
class SockAddr;
class SockAddrList;
class Socket;
class TCPSocket;

typedef std::shared_ptr<File> FilePtr;
typedef std::shared_ptr<FileSet> FileSetPtr;
typedef std::shared_ptr<ListenerSet> ListenerSetPtr;
typedef std::shared_ptr<ListeningSocket> ListeningSocketPtr;
typedef std::shared_ptr<SecureTCPSocket> SecureTCPSocketPtr;
typedef std::shared_ptr<Socket> SocketPtr;
typedef std::shared_ptr<TCPSocket> TCPSocketPtr;

typedef std::stringstream Message;

}

#endif
