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

#include "BGMasterClientConsole.h"
#include <stdio.h>using namespace BGMasterClientProtocolSpec;

void BGMasterClientConsole::help()
{
  printf("usage:\n"
    "join - Registration message.\n"
    "start - Start a managed binary message.\n"
    "wait - Wait for a managed binary to complete.\n"
    "alias_wait - Wait for a binary associated with an alias to start.\n"
    "stop - Stop a managed binary message.\n"
    "get_errors - Get server error ring buffer contents.\n"
    "get_history - Get server history ring buffer contents.\n"
    "status - Status of managed binaries.\n"
    "failover - Failover a managed binary message.\n"
    "terminate - Tell bgmaster_server to end.\n"
    "clients - Get a list of the ids of connected clients.\n"
    "agentlist - Get list of agents and their binaries.\n"
    "getidle - Get the aliases that are configured but not running.\n"
    "reload - Reload the config file.\n"
    "masterstat - Return the status of bgmaster_server.\n"
    "monitor - Start a monitor of bgmaster_server for new events and errors.\n"
    "endmonitor - Stop a monitor of bgmaster_server for new events and errors.\n"
    "loglevel - Change the logging levels of bgmaster_server.\n"
  );
}

std::vector<std::string> BGMasterClientConsole::readCommand()
{
  std::vector<std::string> result;
  // parse command here
  return result;
}

bool BGMasterClientConsole::dispatch(const std::vector<std::string> &argv)
{
  assert(argv.size() > 0);
  bool error = false;
  try
  {
    if(argv[0] == "join")
    {
      error = join(argv);
    }
    else if(argv[0] == "start")
    {
      error = start(argv);
    }
    else if(argv[0] == "wait")
    {
      error = wait(argv);
    }
    else if(argv[0] == "alias_wait")
    {
      error = alias_wait(argv);
    }
    else if(argv[0] == "stop")
    {
      error = stop(argv);
    }
    else if(argv[0] == "get_errors")
    {
      error = get_errors(argv);
    }
    else if(argv[0] == "get_history")
    {
      error = get_history(argv);
    }
    else if(argv[0] == "status")
    {
      error = status(argv);
    }
    else if(argv[0] == "failover")
    {
      error = failover(argv);
    }
    else if(argv[0] == "terminate")
    {
      error = terminate(argv);
    }
    else if(argv[0] == "clients")
    {
      error = clients(argv);
    }
    else if(argv[0] == "agentlist")
    {
      error = agentlist(argv);
    }
    else if(argv[0] == "getidle")
    {
      error = getidle(argv);
    }
    else if(argv[0] == "reload")
    {
      error = reload(argv);
    }
    else if(argv[0] == "masterstat")
    {
      error = masterstat(argv);
    }
    else if(argv[0] == "monitor")
    {
      error = monitor(argv);
    }
    else if(argv[0] == "endmonitor")
    {
      error = endmonitor(argv);
    }
    else if(argv[0] == "loglevel")
    {
      error = loglevel(argv);
    }
    else
    {
      printf("Unrecognized command");
      help();
    }
  }
  catch(invalid_argument &ia)
  {
    printf(std::string("!!!Exception from server: ").append(ia.what()));
  }

  return error;
}

bool BGMasterClientConsole::join(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    JoinRequest request();
    JoinReply   reply;
    _theServer->join(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::start(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    StartRequest request();
    StartReply   reply;
    _theServer->start(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::wait(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    WaitRequest request();
    WaitReply   reply;
    _theServer->wait(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::alias_wait(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    Alias_waitRequest request();
    Alias_waitReply   reply;
    _theServer->alias_wait(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::stop(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    StopRequest request();
    StopReply   reply;
    _theServer->stop(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::get_errors(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    Get_errorsRequest request();
    Get_errorsReply   reply;
    _theServer->get_errors(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::get_history(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    Get_historyRequest request();
    Get_historyReply   reply;
    _theServer->get_history(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::status(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    StatusRequest request();
    StatusReply   reply;
    _theServer->status(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::failover(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    FailoverRequest request();
    FailoverReply   reply;
    _theServer->failover(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::terminate(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    TerminateRequest request();
    TerminateReply   reply;
    _theServer->terminate(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::clients(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    ClientsRequest request();
    ClientsReply   reply;
    _theServer->clients(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::agentlist(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    AgentlistRequest request();
    AgentlistReply   reply;
    _theServer->agentlist(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::getidle(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    GetidleRequest request();
    GetidleReply   reply;
    _theServer->getidle(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::reload(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    ReloadRequest request();
    ReloadReply   reply;
    _theServer->reload(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::masterstat(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    MasterstatRequest request();
    MasterstatReply   reply;
    _theServer->masterstat(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::monitor(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    MonitorRequest request();
    MonitorReply   reply;
    _theServer->monitor(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::endmonitor(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    EndmonitorRequest request();
    EndmonitorReply   reply;
    _theServer->endmonitor(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

bool BGMasterClientConsole::loglevel(const std::vector<std::string> &argv)
{
  if(argv.size() < 1)
  {
    stdout << "args?";
    return false;
  }
  else
  {
    LoglevelRequest request();
    LoglevelReply   reply;
    _theServer->loglevel(request, reply);

    stdout << replyMsg( reply );
  }

  return true;
}

