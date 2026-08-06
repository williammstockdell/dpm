// begin_generated_IBM_copyright_prolog                             
//                                                                  
// This is an automatically generated copyright prolog.             
// After initializing,  DO NOT MODIFY OR MOVE                       
// ---------------------------------------------------------------- 
// Licensed Materials - Property of IBM                             
//                                                                  
// Blue Gene/Q                                                      
//                                                                  
// (C) Copyright IBM Corp.  2010, 2011                              
//                                                                  
// US Government Users Restricted Rights -                          
// Use, duplication or disclosure restricted                        
// by GSA ADP Schedule Contract with IBM Corp.                      
//                                                                  
// This software is available to you under the                      
// Eclipse Public License (EPL).                                    
//  --------------------------------------------------------------- 
//                                                                  
// end_generated_IBM_copyright_prolog                               
// ========================================================================
//          WARNING               WARNING                 WARNING          
// ========================================================================
//
//          You are looking at a generated file. Do not edit!!!            
//
// Generated on Tue Aug  4 16:34:47 2026
// ========================================================================
//          WARNING               WARNING                 WARNING          
// ========================================================================

#ifndef BGMASTERCLIENTPROTOCOL.STUBS_H
#define BGMASTERCLIENTPROTOCOL.STUBS_H

#include "./BGMasterClientProtocolSpec.h"

class BGMasterClientProtocol.stubs: public BGMasterClientProtocolAPI
{
public:

  virtual ~BGMasterClientProtocol.stubs() {}

  /*!
   * Registration message.
   *
   * @param JoinRequest
   *           request object
   * @param JoinReply
   *           reply object
   */
  virtual void join(const BGMasterClientProtocolSpec::JoinRequest& request, BGMasterClientProtocolSpec::JoinReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::JoinRequest::getClassName(), request, BGMasterClientProtocolSpec::JoinReply::getClassName(), reply);
  }

  /*!
   * Start a managed binary message.
   *
   * @param StartRequest
   *           request object
   * @param StartReply
   *           reply object
   */
  virtual void start(const BGMasterClientProtocolSpec::StartRequest& request, BGMasterClientProtocolSpec::StartReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::StartRequest::getClassName(), request, BGMasterClientProtocolSpec::StartReply::getClassName(), reply);
  }

  /*!
   * Wait for a managed binary to complete.
   *
   * @param WaitRequest
   *           request object
   * @param WaitReply
   *           reply object
   */
  virtual void wait(const BGMasterClientProtocolSpec::WaitRequest& request, BGMasterClientProtocolSpec::WaitReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::WaitRequest::getClassName(), request, BGMasterClientProtocolSpec::WaitReply::getClassName(), reply);
  }

  /*!
   * Wait for a binary associated with an alias to start.
   *
   * @param Alias_waitRequest
   *           request object
   * @param Alias_waitReply
   *           reply object
   */
  virtual void alias_wait(const BGMasterClientProtocolSpec::Alias_waitRequest& request, BGMasterClientProtocolSpec::Alias_waitReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::Alias_waitRequest::getClassName(), request, BGMasterClientProtocolSpec::Alias_waitReply::getClassName(), reply);
  }

  /*!
   * Stop a managed binary message.
   *
   * @param StopRequest
   *           request object
   * @param StopReply
   *           reply object
   */
  virtual void stop(const BGMasterClientProtocolSpec::StopRequest& request, BGMasterClientProtocolSpec::StopReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::StopRequest::getClassName(), request, BGMasterClientProtocolSpec::StopReply::getClassName(), reply);
  }

  /*!
   * Get server error ring buffer contents.
   *
   * @param Get_errorsRequest
   *           request object
   * @param Get_errorsReply
   *           reply object
   */
  virtual void get_errors(const BGMasterClientProtocolSpec::Get_errorsRequest& request, BGMasterClientProtocolSpec::Get_errorsReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::Get_errorsRequest::getClassName(), request, BGMasterClientProtocolSpec::Get_errorsReply::getClassName(), reply);
  }

  /*!
   * Get server history ring buffer contents.
   *
   * @param Get_historyRequest
   *           request object
   * @param Get_historyReply
   *           reply object
   */
  virtual void get_history(const BGMasterClientProtocolSpec::Get_historyRequest& request, BGMasterClientProtocolSpec::Get_historyReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::Get_historyRequest::getClassName(), request, BGMasterClientProtocolSpec::Get_historyReply::getClassName(), reply);
  }

  /*!
   * Status of managed binaries.
   *
   * @param StatusRequest
   *           request object
   * @param StatusReply
   *           reply object
   */
  virtual void status(const BGMasterClientProtocolSpec::StatusRequest& request, BGMasterClientProtocolSpec::StatusReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::StatusRequest::getClassName(), request, BGMasterClientProtocolSpec::StatusReply::getClassName(), reply);
  }

  /*!
   * Failover a managed binary message.
   *
   * @param FailoverRequest
   *           request object
   * @param FailoverReply
   *           reply object
   */
  virtual void failover(const BGMasterClientProtocolSpec::FailoverRequest& request, BGMasterClientProtocolSpec::FailoverReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::FailoverRequest::getClassName(), request, BGMasterClientProtocolSpec::FailoverReply::getClassName(), reply);
  }

  /*!
   * Tell bgmaster_server to end.
   *
   * @param TerminateRequest
   *           request object
   * @param TerminateReply
   *           reply object
   */
  virtual void terminate(const BGMasterClientProtocolSpec::TerminateRequest& request, BGMasterClientProtocolSpec::TerminateReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::TerminateRequest::getClassName(), request, BGMasterClientProtocolSpec::TerminateReply::getClassName(), reply);
  }

  /*!
   * Get a list of the ids of connected clients.
   *
   * @param ClientsRequest
   *           request object
   * @param ClientsReply
   *           reply object
   */
  virtual void clients(const BGMasterClientProtocolSpec::ClientsRequest& request, BGMasterClientProtocolSpec::ClientsReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::ClientsRequest::getClassName(), request, BGMasterClientProtocolSpec::ClientsReply::getClassName(), reply);
  }

  /*!
   * Get list of agents and their binaries.
   *
   * @param AgentlistRequest
   *           request object
   * @param AgentlistReply
   *           reply object
   */
  virtual void agentlist(const BGMasterClientProtocolSpec::AgentlistRequest& request, BGMasterClientProtocolSpec::AgentlistReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::AgentlistRequest::getClassName(), request, BGMasterClientProtocolSpec::AgentlistReply::getClassName(), reply);
  }

  /*!
   * Get the aliases that are configured but not running.
   *
   * @param GetidleRequest
   *           request object
   * @param GetidleReply
   *           reply object
   */
  virtual void getidle(const BGMasterClientProtocolSpec::GetidleRequest& request, BGMasterClientProtocolSpec::GetidleReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::GetidleRequest::getClassName(), request, BGMasterClientProtocolSpec::GetidleReply::getClassName(), reply);
  }

  /*!
   * Reload the config file.
   *
   * @param ReloadRequest
   *           request object
   * @param ReloadReply
   *           reply object
   */
  virtual void reload(const BGMasterClientProtocolSpec::ReloadRequest& request, BGMasterClientProtocolSpec::ReloadReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::ReloadRequest::getClassName(), request, BGMasterClientProtocolSpec::ReloadReply::getClassName(), reply);
  }

  /*!
   * Return the status of bgmaster_server.
   *
   * @param MasterstatRequest
   *           request object
   * @param MasterstatReply
   *           reply object
   */
  virtual void masterstat(const BGMasterClientProtocolSpec::MasterstatRequest& request, BGMasterClientProtocolSpec::MasterstatReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::MasterstatRequest::getClassName(), request, BGMasterClientProtocolSpec::MasterstatReply::getClassName(), reply);
  }

  /*!
   * Start a monitor of bgmaster_server for new events and errors.
   *
   * @param MonitorRequest
   *           request object
   * @param MonitorReply
   *           reply object
   */
  virtual void monitor(const BGMasterClientProtocolSpec::MonitorRequest& request, BGMasterClientProtocolSpec::MonitorReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::MonitorRequest::getClassName(), request, BGMasterClientProtocolSpec::MonitorReply::getClassName(), reply);
  }

  /*!
   * Stop a monitor of bgmaster_server for new events and errors.
   *
   * @param EndmonitorRequest
   *           request object
   * @param EndmonitorReply
   *           reply object
   */
  virtual void endmonitor(const BGMasterClientProtocolSpec::EndmonitorRequest& request, BGMasterClientProtocolSpec::EndmonitorReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::EndmonitorRequest::getClassName(), request, BGMasterClientProtocolSpec::EndmonitorReply::getClassName(), reply);
  }

  /*!
   * Change the logging levels of bgmaster_server.
   *
   * @param LoglevelRequest
   *           request object
   * @param LoglevelReply
   *           reply object
   */
  virtual void loglevel(const BGMasterClientProtocolSpec::LoglevelRequest& request, BGMasterClientProtocolSpec::LoglevelReply& reply)
  {
    sendReceive(BGMasterClientProtocolSpec::LoglevelRequest::getClassName(), request, BGMasterClientProtocolSpec::LoglevelReply::getClassName(), reply);
  }

}

#endif
