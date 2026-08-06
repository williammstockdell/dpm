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
// ---------------------------------------------------------------- 
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

#include <cstring>
#include <string>
#include <vector>
#include "xml/include/library/XML.h"
#include "./BGMasterAgentProtocolSpec.h"


namespace BGMasterAgentProtocolSpec
{


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class BGMasterAgentReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BGMasterAgentReply object.
   *
   */
  BGMasterAgentReply::BGMasterAgentReply()
      : _rt("")
  {}

  /*!
   * Constructs a BGMasterAgentReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  BGMasterAgentReply::BGMasterAgentReply(const int rc, const std::string& rt)
      : _rc(rc), _rt(rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  BGMasterAgentReply::~BGMasterAgentReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string BGMasterAgentReply::getClassName()
  {
    return "BGMasterAgentReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned BGMasterAgentReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _rc = XML::read_int32("BGMasterAgentReply", "rc", attrs[i], attrs[i+1], &i, 0);
    _rt = XML::read_text("BGMasterAgentReply", "rt", attrs[i], attrs[i+1], &i, 0);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *BGMasterAgentReply::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BGMasterAgentReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterAgentReply::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "BGMasterAgentReply", "rc", _rc);
    XML::write_text(os, "BGMasterAgentReply", "rt", _rt);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterAgentReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterAgentReply::write(std::ostream& os) const
  {
    os << "<BGMasterAgentReply";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BGMasterAgentReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class JoinRequest::WorkingBins
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a WorkingBins object.
   *
   */
  JoinRequest::WorkingBins::WorkingBins()
      : _binary_id(""), _name(""), _alias(""), _status(""), _user("")
  {}

  /*!
   * Constructs a WorkingBins object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param name
     *          Path/args for the binary.
     * @param alias
     *          Standard alias for the binary.
     * @param status
     *          Status of the binary.
     * @param user
     *          User under which binary is running.
   */
  JoinRequest::WorkingBins::WorkingBins(const std::string& binary_id, const std::string& name, const std::string& alias, const std::string& status, const std::string& user)
      : _binary_id(binary_id), _name(name), _alias(alias), _status(status), _user(user)
  {
  }

  /*!
   * Default destructor.
   *
   */
  JoinRequest::WorkingBins::~WorkingBins()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string JoinRequest::WorkingBins::getClassName()
  {
    return "JoinRequest::WorkingBins";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned JoinRequest::WorkingBins::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("JoinRequest::WorkingBins", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _name = XML::read_text("JoinRequest::WorkingBins", "name", attrs[i], attrs[i+1], &i, 0);
    _alias = XML::read_text("JoinRequest::WorkingBins", "alias", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_text("JoinRequest::WorkingBins", "status", attrs[i], attrs[i+1], &i, 0);
    _user = XML::read_text("JoinRequest::WorkingBins", "user", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("WorkingBins", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *JoinRequest::WorkingBins::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "WorkingBins", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::WorkingBins::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "JoinRequest::WorkingBins", "binary_id", _binary_id);
    XML::write_text(os, "JoinRequest::WorkingBins", "name", _name);
    XML::write_text(os, "JoinRequest::WorkingBins", "alias", _alias);
    XML::write_text(os, "JoinRequest::WorkingBins", "status", _status);
    XML::write_text(os, "JoinRequest::WorkingBins", "user", _user);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::WorkingBins::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::WorkingBins::write(std::ostream& os) const
  {
    os << "<WorkingBins";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</WorkingBins>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class JoinRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a JoinRequest object.
   *
   */
  JoinRequest::JoinRequest()
      : _ip_address(""), _initiator(""), _host_name(""), _running_binaries()
  {}

  /*!
   * Constructs a JoinRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param ip_address
     *          Initiator listener ip address.
     * @param port
     *          Initiator listener port.
     * @param initiator
     *          'client' or 'agent'.
     * @param host_name
     *          Initiator listener host name.
   */
  JoinRequest::JoinRequest(const std::string& ip_address, const int port, const std::string& initiator, const std::string& host_name)
      : _ip_address(ip_address), _port(port), _initiator(initiator), _host_name(host_name), _running_binaries()
  {
  }

  /*!
   * Default destructor.
   *
   */
  JoinRequest::~JoinRequest()
  {
    _running_binaries.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string JoinRequest::getClassName()
  {
    return "JoinRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned JoinRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _ip_address = XML::read_text("JoinRequest", "ip_address", attrs[i], attrs[i+1], &i, 0);
    _port = XML::read_int32("JoinRequest", "port", attrs[i], attrs[i+1], &i, 0);
    _initiator = XML::read_text("JoinRequest", "initiator", attrs[i], attrs[i+1], &i, 0);
    _host_name = XML::read_text("JoinRequest", "host_name", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("JoinRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *JoinRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "WorkingBins") == 0)
    {
      WorkingBins temp;
      temp.setAttributes(attrs);
      _running_binaries.push_back(temp);
      return &_running_binaries.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "JoinRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "JoinRequest", "ip_address", _ip_address);
    XML::write_int32(os, "JoinRequest", "port", _port);
    XML::write_text(os, "JoinRequest", "initiator", _initiator);
    XML::write_text(os, "JoinRequest", "host_name", _host_name);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::writeSubentities(std::ostream& os) const
  {
    for (std::vector<WorkingBins>::const_iterator iter = _running_binaries.begin(); iter != _running_binaries.end(); ++iter)
    {
      os << *iter;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinRequest::write(std::ostream& os) const
  {
    os << "<JoinRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</JoinRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class JoinReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a JoinReply object.
   *
   */
  JoinReply::JoinReply()
      : BGMasterAgentReply(), _agent_ip(""), _master_ip(""), _master_port(""), _bad_bins()
  {}

  /*!
   * Constructs a JoinReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param agent_ip
     *          Initiator ip address.
     * @param master_ip
     *          Master ip address.
     * @param master_port
     *          Ephemeral port master is using for its requests.
   */
  JoinReply::JoinReply(const int rc, const std::string& rt, const std::string& agent_ip, const std::string& master_ip, const std::string& master_port)
      : BGMasterAgentReply(rc, rt), _agent_ip(agent_ip), _master_ip(master_ip), _master_port(master_port), _bad_bins()
  {
  }

  /*!
   * Default destructor.
   *
   */
  JoinReply::~JoinReply()
  {
    _bad_bins.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string JoinReply::getClassName()
  {
    return "JoinReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned JoinReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    _agent_ip = XML::read_text("JoinReply", "agent_ip", attrs[i], attrs[i+1], &i, 0);
    _master_ip = XML::read_text("JoinReply", "master_ip", attrs[i], attrs[i+1], &i, 0);
    _master_port = XML::read_text("JoinReply", "master_port", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("JoinReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *JoinReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "bad_bins") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("bad_bins", "value", attrs[i], attrs[i+1], &i, 0);
      _bad_bins.push_back(temp);
      XML::verify_last_attr("bad_bins", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "JoinReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinReply::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "JoinReply", "agent_ip", _agent_ip);
    XML::write_text(os, "JoinReply", "master_ip", _master_ip);
    XML::write_text(os, "JoinReply", "master_port", _master_port);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _bad_bins.begin(); iter != _bad_bins.end(); ++iter)
    {
      os <<  "<bad_bins";
      XML::write_text(os, "bad_bins", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void JoinReply::write(std::ostream& os) const
  {
    os << "<JoinReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</JoinReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StartRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StartRequest object.
   *
   */
  StartRequest::StartRequest()
      : _path(""), _arguments(""), _logdir(""), _alias(""), _user("")
  {}

  /*!
   * Constructs a StartRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param path
     *          Full path to binary to execute.
     * @param arguments
     *          Argument string.
     * @param logdir
     *          Base log directory.
     * @param alias
     *          Alias name for the binary.
     * @param user
     *          User id for the binary.
   */
  StartRequest::StartRequest(const std::string& path, const std::string& arguments, const std::string& logdir, const std::string& alias, const std::string& user)
      : _path(path), _arguments(arguments), _logdir(logdir), _alias(alias), _user(user)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StartRequest::~StartRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StartRequest::getClassName()
  {
    return "StartRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StartRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _path = XML::read_text("StartRequest", "path", attrs[i], attrs[i+1], &i, 0);
    _arguments = XML::read_text("StartRequest", "arguments", attrs[i], attrs[i+1], &i, 0);
    _logdir = XML::read_text("StartRequest", "logdir", attrs[i], attrs[i+1], &i, 0);
    _alias = XML::read_text("StartRequest", "alias", attrs[i], attrs[i+1], &i, 0);
    _user = XML::read_text("StartRequest", "user", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("StartRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StartRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "StartRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StartRequest", "path", _path);
    XML::write_text(os, "StartRequest", "arguments", _arguments);
    XML::write_text(os, "StartRequest", "logdir", _logdir);
    XML::write_text(os, "StartRequest", "alias", _alias);
    XML::write_text(os, "StartRequest", "user", _user);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartRequest::write(std::ostream& os) const
  {
    os << "<StartRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</StartRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StartReply::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  StartReply::BinaryStatus::BinaryStatus()
      : _binary_id("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param exit_status
     *          Exit status of binary.
   */
  StartReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const int exit_status)
      : _binary_id(binary_id), _exit_status(exit_status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StartReply::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StartReply::BinaryStatus::getClassName()
  {
    return "StartReply::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StartReply::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("StartReply::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _exit_status = XML::read_int32("StartReply::BinaryStatus", "exit_status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StartReply::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StartReply::BinaryStatus", "binary_id", _binary_id);
    XML::write_int32(os, "StartReply::BinaryStatus", "exit_status", _exit_status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StartReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StartReply object.
   *
   */
  StartReply::StartReply()
      : BGMasterAgentReply()
  {}

  /*!
   * Constructs a StartReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param status
     *          Status object.
   */
  StartReply::StartReply(const int rc, const std::string& rt, BinaryStatus status)
      : BGMasterAgentReply(rc, rt), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StartReply::~StartReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StartReply::getClassName()
  {
    return "StartReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StartReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    XML::verify_last_attr("StartReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StartReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "BinaryStatus") == 0)
    {
      _status.setAttributes(attrs);
      return &_status;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "StartReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::writeSubentities(std::ostream& os) const
  {
    os << _status << std::endl;
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::write(std::ostream& os) const
  {
    os << "<StartReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StartReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StopRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StopRequest object.
   *
   */
  StopRequest::StopRequest()
      : _binary_id("")
  {}

  /*!
   * Constructs a StopRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Binary to stop.
     * @param signal
     *          Initial signal number.
   */
  StopRequest::StopRequest(const std::string& binary_id, const int signal)
      : _binary_id(binary_id), _signal(signal)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StopRequest::~StopRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StopRequest::getClassName()
  {
    return "StopRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StopRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("StopRequest", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _signal = XML::read_int32("StopRequest", "signal", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("StopRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StopRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "StopRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StopRequest", "binary_id", _binary_id);
    XML::write_int32(os, "StopRequest", "signal", _signal);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopRequest::write(std::ostream& os) const
  {
    os << "<StopRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</StopRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StopReply::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  StopReply::BinaryStatus::BinaryStatus()
      : _binary_id("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param exit_status
     *          Exit status of the binary if available.
   */
  StopReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const int exit_status)
      : _binary_id(binary_id), _exit_status(exit_status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StopReply::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StopReply::BinaryStatus::getClassName()
  {
    return "StopReply::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StopReply::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("StopReply::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _exit_status = XML::read_int32("StopReply::BinaryStatus", "exit_status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StopReply::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StopReply::BinaryStatus", "binary_id", _binary_id);
    XML::write_int32(os, "StopReply::BinaryStatus", "exit_status", _exit_status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StopReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StopReply object.
   *
   */
  StopReply::StopReply()
      : BGMasterAgentReply()
  {}

  /*!
   * Constructs a StopReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param status
     *          Status of stopped binary.
   */
  StopReply::StopReply(const int rc, const std::string& rt, BinaryStatus status)
      : BGMasterAgentReply(rc, rt), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StopReply::~StopReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StopReply::getClassName()
  {
    return "StopReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StopReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    XML::verify_last_attr("StopReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StopReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "BinaryStatus") == 0)
    {
      _status.setAttributes(attrs);
      return &_status;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "StopReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::writeSubentities(std::ostream& os) const
  {
    os << _status << std::endl;
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopReply::write(std::ostream& os) const
  {
    os << "<StopReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StopReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusRequest::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  StatusRequest::BinaryStatus::BinaryStatus()
      : _binary_id(""), _status("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param status
     *          Status of the binary.
   */
  StatusRequest::BinaryStatus::BinaryStatus(const std::string& binary_id, const std::string& status)
      : _binary_id(binary_id), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StatusRequest::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StatusRequest::BinaryStatus::getClassName()
  {
    return "StatusRequest::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StatusRequest::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("StatusRequest::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_text("StatusRequest::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StatusRequest::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StatusRequest::BinaryStatus", "binary_id", _binary_id);
    XML::write_text(os, "StatusRequest::BinaryStatus", "status", _status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StatusRequest object.
   *
   */
  StatusRequest::StatusRequest()
      : _statuses()
  {}


  /*!
   * Default destructor.
   *
   */
  StatusRequest::~StatusRequest()
  {
    _statuses.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StatusRequest::getClassName()
  {
    return "StatusRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StatusRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("StatusRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StatusRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "BinaryStatus") == 0)
    {
      BinaryStatus temp;
      temp.setAttributes(attrs);
      _statuses.push_back(temp);
      return &_statuses.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "StatusRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::writeSubentities(std::ostream& os) const
  {
    for (std::vector<BinaryStatus>::const_iterator iter = _statuses.begin(); iter != _statuses.end(); ++iter)
    {
      os << *iter;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusRequest::write(std::ostream& os) const
  {
    os << "<StatusRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</StatusRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusReply::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  StatusReply::BinaryStatus::BinaryStatus()
      : _binary_id(""), _status("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param status
     *          Status of the binary.
   */
  StatusReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const std::string& status)
      : _binary_id(binary_id), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StatusReply::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StatusReply::BinaryStatus::getClassName()
  {
    return "StatusReply::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StatusReply::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("StatusReply::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_text("StatusReply::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StatusReply::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StatusReply::BinaryStatus", "binary_id", _binary_id);
    XML::write_text(os, "StatusReply::BinaryStatus", "status", _status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StatusReply object.
   *
   */
  StatusReply::StatusReply()
      : BGMasterAgentReply(), _statuses()
  {}

  /*!
   * Constructs a StatusReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  StatusReply::StatusReply(const int rc, const std::string& rt)
      : BGMasterAgentReply(rc, rt), _statuses()
  {
  }

  /*!
   * Default destructor.
   *
   */
  StatusReply::~StatusReply()
  {
    _statuses.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StatusReply::getClassName()
  {
    return "StatusReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StatusReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    XML::verify_last_attr("StatusReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *StatusReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "BinaryStatus") == 0)
    {
      BinaryStatus temp;
      temp.setAttributes(attrs);
      _statuses.push_back(temp);
      return &_statuses.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "StatusReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<BinaryStatus>::const_iterator iter = _statuses.begin(); iter != _statuses.end(); ++iter)
    {
      os << *iter;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::write(std::ostream& os) const
  {
    os << "<StatusReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StatusReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class CompleteRequest::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  CompleteRequest::BinaryStatus::BinaryStatus()
      : _binary_id(""), _status("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param status
     *          Status of the binary.
   */
  CompleteRequest::BinaryStatus::BinaryStatus(const std::string& binary_id, const std::string& status)
      : _binary_id(binary_id), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  CompleteRequest::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string CompleteRequest::BinaryStatus::getClassName()
  {
    return "CompleteRequest::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned CompleteRequest::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("CompleteRequest::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_text("CompleteRequest::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *CompleteRequest::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "CompleteRequest::BinaryStatus", "binary_id", _binary_id);
    XML::write_text(os, "CompleteRequest::BinaryStatus", "status", _status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class CompleteRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a CompleteRequest object.
   *
   */
  CompleteRequest::CompleteRequest()
  {}

  /*!
   * Constructs a CompleteRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param status
     *          Status object.
     * @param exit_status
     *          Exit status of binary.
   */
  CompleteRequest::CompleteRequest(BinaryStatus status, const int exit_status)
      : _status(status), _exit_status(exit_status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  CompleteRequest::~CompleteRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string CompleteRequest::getClassName()
  {
    return "CompleteRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned CompleteRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _exit_status = XML::read_int32("CompleteRequest", "exit_status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("CompleteRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *CompleteRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "BinaryStatus") == 0)
    {
      _status.setAttributes(attrs);
      return &_status;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "CompleteRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "CompleteRequest", "exit_status", _exit_status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::writeSubentities(std::ostream& os) const
  {
    os << _status << std::endl;
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteRequest::write(std::ostream& os) const
  {
    os << "<CompleteRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</CompleteRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class CompleteReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a CompleteReply object.
   *
   */
  CompleteReply::CompleteReply()
      : BGMasterAgentReply()
  {}

  /*!
   * Constructs a CompleteReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  CompleteReply::CompleteReply(const int rc, const std::string& rt)
      : BGMasterAgentReply(rc, rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  CompleteReply::~CompleteReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string CompleteReply::getClassName()
  {
    return "CompleteReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned CompleteReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    XML::verify_last_attr("CompleteReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *CompleteReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "CompleteReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void CompleteReply::write(std::ostream& os) const
  {
    os << "<CompleteReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</CompleteReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailedRequest::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  FailedRequest::BinaryStatus::BinaryStatus()
      : _binary_id("")
  {}

  /*!
   * Constructs a BinaryStatus object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Id of binary.
     * @param exit_status
     *          Exit status of binary.
   */
  FailedRequest::BinaryStatus::BinaryStatus(const std::string& binary_id, const int exit_status)
      : _binary_id(binary_id), _exit_status(exit_status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailedRequest::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailedRequest::BinaryStatus::getClassName()
  {
    return "FailedRequest::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailedRequest::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("FailedRequest::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _exit_status = XML::read_int32("FailedRequest::BinaryStatus", "exit_status", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryStatus", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *FailedRequest::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryStatus", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "FailedRequest::BinaryStatus", "binary_id", _binary_id);
    XML::write_int32(os, "FailedRequest::BinaryStatus", "exit_status", _exit_status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailedRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a FailedRequest object.
   *
   */
  FailedRequest::FailedRequest()
  {}

  /*!
   * Constructs a FailedRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param status
     *          Status object.
   */
  FailedRequest::FailedRequest(BinaryStatus status)
      : _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailedRequest::~FailedRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailedRequest::getClassName()
  {
    return "FailedRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailedRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("FailedRequest", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *FailedRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "BinaryStatus") == 0)
    {
      _status.setAttributes(attrs);
      return &_status;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "FailedRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::writeSubentities(std::ostream& os) const
  {
    os << _status << std::endl;
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedRequest::write(std::ostream& os) const
  {
    os << "<FailedRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</FailedRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailedReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a FailedReply object.
   *
   */
  FailedReply::FailedReply()
      : BGMasterAgentReply()
  {}

  /*!
   * Constructs a FailedReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  FailedReply::FailedReply(const int rc, const std::string& rt)
      : BGMasterAgentReply(rc, rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailedReply::~FailedReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailedReply::getClassName()
  {
    return "FailedReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailedReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterAgentReply::setAttributes(attrs);
    XML::verify_last_attr("FailedReply", attrs[i]);
    return i;
  }

  /*!
   * Adds an XML subentity.
   *
   * @param name
   *          the name for the XML subentity to add.
   * @param attrs
   *          the XML class attributes to add for the subentity.
   * @return a pointer to the serializable object.
   *           if there was a problem adding the new XML subentity.
   */
  XML::Serializable *FailedReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterAgentReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "FailedReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailedReply::write(std::ostream& os) const
  {
    os << "<FailedReply";
    BGMasterAgentReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterAgentReply::writeSubentities(os);
    writeSubentities(os);
    os << "</FailedReply>" << std::endl;
  }

}

