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

#include "pc_util.h"

#include "Log.h"

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/throw_exception.hpp>

#include <stdexcept>


LOG_DECLARE_FILE( "utility" );


using std::runtime_error;
using std::string;


namespace bgq {
namespace utility {
namespace pc_util {


std::shared_ptr<std::string> extractPeerCn(
        portConfig::Socket& ssl_stream
    )
{
    return std::shared_ptr<std::string>( new string("placeholder") );
}


}}} // namespace bgq::utility::pc_util
