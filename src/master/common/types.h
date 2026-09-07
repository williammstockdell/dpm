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
/* (C) Copyright IBM Corp.  2012, 2012                              */
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

#ifndef MASTER_TYPES_H_
#define MASTER_TYPES_H_

#include <xml/include/library/XML.h>

#include <log4cxx/log4cxx.h>
#include <log4cxx/mdc.h>

#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

class AgentBase;
typedef std::shared_ptr<AgentBase> AgentBasePtr;

class AgentProtocol;
typedef std::shared_ptr<AgentProtocol> AgentProtocolPtr;

class BinaryController;
typedef std::shared_ptr<BinaryController> BinaryControllerPtr;

class ClientProtocol;
typedef std::shared_ptr<ClientProtocol> ClientProtocolPtr;

class Protocol;
typedef std::shared_ptr<Protocol> ProtocolPtr;

typedef std::shared_ptr<XML::Serializable> MsgBasePtr;

template <typename T> std::string local_to_string(const T& value) {
    if constexpr (std::is_convertible_v<T, std::string_view>) {
        return std::string(value);
    } else {
        return std::to_string(value);
    }
}

#define LOGGING_DECLARE_ID_MDC(value) log4cxx::MDC _location_mdc("ID", std::string("{") + local_to_string(value) + "} ");

#endif
