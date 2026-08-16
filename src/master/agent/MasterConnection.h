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

#ifndef BGAGENT_MASTER_CONNECTION_H
#define BGAGENT_MASTER_CONNECTION_H

#include <utility/include/portConfiguration/PortConfiguration.h>

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

class Agent;

class MasterConnection : public boost::enable_shared_from_this<MasterConnection>
{
public:
    /*!
     * \brief Pointer type.
     */
    typedef boost::shared_ptr<MasterConnection> Ptr;

public:
    /*!
     * \brief Factory.
     */
    static void create(
            const bgq::utility::PortConfiguration::Pairs& ports,    //!< [in]
            Agent* const agent                                      //!< [in]
            );

    /*!
     * \brief dtor.
     */
    ~MasterConnection();

    MasterConnection(
            const bgq::utility::PortConfiguration::Pairs& ports,
            Agent* const agent
            );

    void run();

    void cleanupAndDie() { _ending = true; }
private:
    const bgq::utility::PortConfiguration::Pairs _ports;
    Agent* const _agent;
    bool _ending;
};

#endif
