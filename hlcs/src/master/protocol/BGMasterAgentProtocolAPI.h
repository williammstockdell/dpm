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
//                                                                  
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

#ifndef BGMASTERAGENTPROTOCOLAPI_H
#define BGMASTERAGENTPROTOCOLAPI_H

#include "./BGMasterAgentProtocolSpec.h"

class BGMasterAgentProtocolAPI
{
public:

  virtual ~BGMasterAgentProtocolAPI() {}

  static BGMasterAgentProtocolAPI *Instance()
  {
    assert(_instance != 0);
    return _instance;
  }

  /*!
   * Registration message.
   *
   * @param JoinRequest
   *           request object
   * @param JoinReply
   *           reply object
   */
  virtual void join(const BGMasterAgentProtocolSpec::JoinRequest& request, BGMasterAgentProtocolSpec::JoinReply& reply) = 0;

  /*!
   * Start a managed binary message.
   *
   * @param StartRequest
   *           request object
   * @param StartReply
   *           reply object
   */
  virtual void start(const BGMasterAgentProtocolSpec::StartRequest& request, BGMasterAgentProtocolSpec::StartReply& reply) = 0;

  /*!
   * Stop a managed binary message.
   *
   * @param StopRequest
   *           request object
   * @param StopReply
   *           reply object
   */
  virtual void stop(const BGMasterAgentProtocolSpec::StopRequest& request, BGMasterAgentProtocolSpec::StopReply& reply) = 0;

  /*!
   * Status of managed binaries.
   *
   * @param StatusRequest
   *           request object
   * @param StatusReply
   *           reply object
   */
  virtual void status(const BGMasterAgentProtocolSpec::StatusRequest& request, BGMasterAgentProtocolSpec::StatusReply& reply) = 0;

  /*!
   * Tell bgmaster that binary(ies) completed.
   *
   * @param CompleteRequest
   *           request object
   * @param CompleteReply
   *           reply object
   */
  virtual void complete(const BGMasterAgentProtocolSpec::CompleteRequest& request, BGMasterAgentProtocolSpec::CompleteReply& reply) = 0;

  /*!
   * Tell bgmaster that binary(ies) failed.
   *
   * @param FailedRequest
   *           request object
   * @param FailedReply
   *           reply object
   */
  virtual void failed(const BGMasterAgentProtocolSpec::FailedRequest& request, BGMasterAgentProtocolSpec::FailedReply& reply) = 0;

protected:
  static BGMasterAgentProtocolAPI* _instance;
};

// access the singleton object
inline BGMasterAgentProtocolAPI *getBGMasterAgentProtocolAPI()
{
  return BGMasterAgentProtocolAPI::Instance();
}

#endif
