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

#ifndef BGAGENT_MASTER_CONNECTION_H
#define BGAGENT_MASTER_CONNECTION_H

#include <utility/include/portConfiguration/PortConfiguration.h>
#include <memory>

class Agent;

// FIXME:  This object either needs to go or to be part of a
// refactor to pull all of the protocall and network manager
// inside from Agent.
class MasterConnection {
  public:
    /*!
     * \brief Pointer type.
     */
    typedef std::shared_ptr<MasterConnection> Ptr;

    /*!
     * \brief Factory.
     */
    static void create(const bgq::utility::PortConfiguration::Pairs& ports, //!< [in]
                       Agent* const agent                                   //!< [in]
    );

    /*!
     * \brief dtor.
     */
    ~MasterConnection();

    MasterConnection(const bgq::utility::PortConfiguration::Pairs& ports, Agent* const agent);

    void run(const int signal_read_fd);

    void cleanupAndDie() { _ending = true; }

  private:
    void makeConnection();
    bool pollConnection(const int signal_read_fd);

    const bgq::utility::PortConfiguration::Pairs _ports;
    Agent* const _agent;
    bool _ending = false;
};

#endif
