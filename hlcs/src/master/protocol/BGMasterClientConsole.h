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

#ifndef BGMASTERCLIENTCONSOLE_H
#define BGMASTERCLIENTCONSOLE_H

#include <string>
#include <vector>
#include "./BGMasterClientProtocolSpec.h"n
class BGMasterClientConsole
{
public:
  BGMasterClientConsole( BGMasterClientProtocolAPI *server);
  std::vector<std::string> readCommand();
  bool dispatch(const std::vector<std::string> &argv);
  void help();

protected:
  BGMasterClientProtocolAPI *_theServer;

  bool join (const std::vector<std::string> &argv);
  bool start (const std::vector<std::string> &argv);
  bool wait (const std::vector<std::string> &argv);
  bool alias_wait (const std::vector<std::string> &argv);
  bool stop (const std::vector<std::string> &argv);
  bool get_errors (const std::vector<std::string> &argv);
  bool get_history (const std::vector<std::string> &argv);
  bool status (const std::vector<std::string> &argv);
  bool failover (const std::vector<std::string> &argv);
  bool terminate (const std::vector<std::string> &argv);
  bool clients (const std::vector<std::string> &argv);
  bool agentlist (const std::vector<std::string> &argv);
  bool getidle (const std::vector<std::string> &argv);
  bool reload (const std::vector<std::string> &argv);
  bool masterstat (const std::vector<std::string> &argv);
  bool monitor (const std::vector<std::string> &argv);
  bool endmonitor (const std::vector<std::string> &argv);
  bool loglevel (const std::vector<std::string> &argv);

private:
  BGMasterClientConsole() {};
};

#endif
