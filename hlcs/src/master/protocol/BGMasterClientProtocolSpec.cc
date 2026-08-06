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
#include "./BGMasterClientProtocolSpec.h"


namespace BGMasterClientProtocolSpec
{


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class BGMasterClientReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BGMasterClientReply object.
   *
   */
  BGMasterClientReply::BGMasterClientReply()
      : _rt("")
  {}

  /*!
   * Constructs a BGMasterClientReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  BGMasterClientReply::BGMasterClientReply(const int rc, const std::string& rt)
      : _rc(rc), _rt(rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  BGMasterClientReply::~BGMasterClientReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string BGMasterClientReply::getClassName()
  {
    return "BGMasterClientReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned BGMasterClientReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _rc = XML::read_int32("BGMasterClientReply", "rc", attrs[i], attrs[i+1], &i, 0);
    _rt = XML::read_text("BGMasterClientReply", "rt", attrs[i], attrs[i+1], &i, 0);
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
  XML::Serializable *BGMasterClientReply::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BGMasterClientReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterClientReply::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "BGMasterClientReply", "rc", _rc);
    XML::write_text(os, "BGMasterClientReply", "rt", _rt);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterClientReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void BGMasterClientReply::write(std::ostream& os) const
  {
    os << "<BGMasterClientReply";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BGMasterClientReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class JoinRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a JoinRequest object.
   *
   */
  JoinRequest::JoinRequest()
      : _ip_address(""), _initiator(""), _host_name("")
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
      : _ip_address(ip_address), _port(port), _initiator(initiator), _host_name(host_name)
  {
  }

  /*!
   * Default destructor.
   *
   */
  JoinRequest::~JoinRequest()
  {
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
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "JoinRequest", name);
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
      : BGMasterClientReply(), _agent_ip(""), _master_ip(""), _master_port("")
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
      : BGMasterClientReply(rc, rt), _agent_ip(agent_ip), _master_ip(master_ip), _master_port(master_port)
  {
  }

  /*!
   * Default destructor.
   *
   */
  JoinReply::~JoinReply()
  {
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
    i = BGMasterClientReply::setAttributes(attrs);
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
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "JoinReply", name);
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
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
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
      : _alias(""), _agent_id("")
  {}

  /*!
   * Constructs a StartRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param alias
     *          Short identifier for the binary.
     * @param agent_id
     *          Optional id of agent to start the binary.
   */
  StartRequest::StartRequest(const std::string& alias, const std::string& agent_id)
      : _alias(alias), _agent_id(agent_id)
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
    _alias = XML::read_text("StartRequest", "alias", attrs[i], attrs[i+1], &i, 0);
    _agent_id = XML::read_text("StartRequest", "agent_id", attrs[i], attrs[i+1], &i, 0);
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
    XML::write_text(os, "StartRequest", "alias", _alias);
    XML::write_text(os, "StartRequest", "agent_id", _agent_id);
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
  // Class StartReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StartReply object.
   *
   */
  StartReply::StartReply()
      : BGMasterClientReply(), _binary_id("")
  {}

  /*!
   * Constructs a StartReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param binary_id
     *          Binary id generated from pid and ip address.
   */
  StartReply::StartReply(const int rc, const std::string& rt, const std::string& binary_id)
      : BGMasterClientReply(rc, rt), _binary_id(binary_id)
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
    i = BGMasterClientReply::setAttributes(attrs);
    _binary_id = XML::read_text("StartReply", "binary_id", attrs[i], attrs[i+1], &i, 0);
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
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "StartReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "StartReply", "binary_id", _binary_id);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StartReply::writeSubentities(std::ostream& os) const
  {
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
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StartReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class WaitRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a WaitRequest object.
   *
   */
  WaitRequest::WaitRequest()
      : _binary_id("")
  {}

  /*!
   * Constructs a WaitRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param binary_id
     *          Binaries to stop.
   */
  WaitRequest::WaitRequest(const std::string& binary_id)
      : _binary_id(binary_id)
  {
  }

  /*!
   * Default destructor.
   *
   */
  WaitRequest::~WaitRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string WaitRequest::getClassName()
  {
    return "WaitRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned WaitRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("WaitRequest", "binary_id", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("WaitRequest", attrs[i]);
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
  XML::Serializable *WaitRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "WaitRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "WaitRequest", "binary_id", _binary_id);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitRequest::write(std::ostream& os) const
  {
    os << "<WaitRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</WaitRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class WaitReply::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  WaitReply::BinaryStatus::BinaryStatus()
      : _binary_id("")
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
  WaitReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const int status)
      : _binary_id(binary_id), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  WaitReply::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string WaitReply::BinaryStatus::getClassName()
  {
    return "WaitReply::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned WaitReply::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("WaitReply::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_int32("WaitReply::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
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
  XML::Serializable *WaitReply::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
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
  void WaitReply::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "WaitReply::BinaryStatus", "binary_id", _binary_id);
    XML::write_int32(os, "WaitReply::BinaryStatus", "status", _status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitReply::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitReply::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class WaitReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a WaitReply object.
   *
   */
  WaitReply::WaitReply()
      : BGMasterClientReply()
  {}

  /*!
   * Constructs a WaitReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param status
     *          Status object.
   */
  WaitReply::WaitReply(const int rc, const std::string& rt, BinaryStatus status)
      : BGMasterClientReply(rc, rt), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  WaitReply::~WaitReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string WaitReply::getClassName()
  {
    return "WaitReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned WaitReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("WaitReply", attrs[i]);
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
  XML::Serializable *WaitReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
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
      XMLLIB_THROW("XML %s: invalid subentity %s", "WaitReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitReply::writeSubentities(std::ostream& os) const
  {
    os << _status << std::endl;
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void WaitReply::write(std::ostream& os) const
  {
    os << "<WaitReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</WaitReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Alias_waitRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Alias_waitRequest object.
   *
   */
  Alias_waitRequest::Alias_waitRequest()
      : _alias("")
  {}

  /*!
   * Constructs a Alias_waitRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param alias
     *          Short identifier for the binary.
     * @param timeout
     *          Wait timeout in seconds.
   */
  Alias_waitRequest::Alias_waitRequest(const std::string& alias, const unsigned timeout)
      : _alias(alias), _timeout(timeout)
  {
  }

  /*!
   * Default destructor.
   *
   */
  Alias_waitRequest::~Alias_waitRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Alias_waitRequest::getClassName()
  {
    return "Alias_waitRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Alias_waitRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _alias = XML::read_text("Alias_waitRequest", "alias", attrs[i], attrs[i+1], &i, 0);
    _timeout = XML::read_uint32("Alias_waitRequest", "timeout", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Alias_waitRequest", attrs[i]);
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
  XML::Serializable *Alias_waitRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Alias_waitRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "Alias_waitRequest", "alias", _alias);
    XML::write_uint32(os, "Alias_waitRequest", "timeout", _timeout);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitRequest::write(std::ostream& os) const
  {
    os << "<Alias_waitRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Alias_waitRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Alias_waitReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Alias_waitReply object.
   *
   */
  Alias_waitReply::Alias_waitReply()
      : BGMasterClientReply(), _binary_id("")
  {}

  /*!
   * Constructs a Alias_waitReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param binary_id
     *          Binary id generated from pid and ip address.
   */
  Alias_waitReply::Alias_waitReply(const int rc, const std::string& rt, const std::string& binary_id)
      : BGMasterClientReply(rc, rt), _binary_id(binary_id)
  {
  }

  /*!
   * Default destructor.
   *
   */
  Alias_waitReply::~Alias_waitReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Alias_waitReply::getClassName()
  {
    return "Alias_waitReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Alias_waitReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    _binary_id = XML::read_text("Alias_waitReply", "binary_id", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Alias_waitReply", attrs[i]);
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
  XML::Serializable *Alias_waitReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Alias_waitReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitReply::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "Alias_waitReply", "binary_id", _binary_id);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Alias_waitReply::write(std::ostream& os) const
  {
    os << "<Alias_waitReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</Alias_waitReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StopRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StopRequest object.
   *
   */
  StopRequest::StopRequest()
      : _binary_ids(), _aliases()
  {}

  /*!
   * Constructs a StopRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param signal
     *          Initial signal number.
   */
  StopRequest::StopRequest(const int signal)
      : _binary_ids(), _signal(signal), _aliases()
  {
  }

  /*!
   * Default destructor.
   *
   */
  StopRequest::~StopRequest()
  {
    _binary_ids.clear();
    _aliases.clear();
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
    if(strcmp(name, "binary_ids") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("binary_ids", "value", attrs[i], attrs[i+1], &i, 0);
      _binary_ids.push_back(temp);
      XML::verify_last_attr("binary_ids", attrs[i]);
      return this;
    }
    else if(strcmp(name, "aliases") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("aliases", "value", attrs[i], attrs[i+1], &i, 0);
      _aliases.push_back(temp);
      XML::verify_last_attr("aliases", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "StopRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StopRequest::writeMembers(std::ostream& os) const
  {
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
    for (std::vector<std::string>::const_iterator iter = _binary_ids.begin(); iter != _binary_ids.end(); ++iter)
    {
      os <<  "<binary_ids";
      XML::write_text(os, "binary_ids", "value", *iter);
      os << "/>" << std::endl;
    }
    for (std::vector<std::string>::const_iterator iter = _aliases.begin(); iter != _aliases.end(); ++iter)
    {
      os <<  "<aliases";
      XML::write_text(os, "aliases", "value", *iter);
      os << "/>" << std::endl;
    }
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
     * @param status
     *          Status of the binary.
   */
  StopReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const int status)
      : _binary_id(binary_id), _status(status)
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
    _status = XML::read_int32("StopReply::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
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
    XML::write_int32(os, "StopReply::BinaryStatus", "status", _status);
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
      : BGMasterClientReply(), _statuses()
  {}

  /*!
   * Constructs a StopReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  StopReply::StopReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _statuses()
  {
  }

  /*!
   * Default destructor.
   *
   */
  StopReply::~StopReply()
  {
    _statuses.clear();
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
    i = BGMasterClientReply::setAttributes(attrs);
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
      return BGMasterClientReply::addSubEntity(name, attrs);
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
  void StopReply::write(std::ostream& os) const
  {
    os << "<StopReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StopReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Get_errorsRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Get_errorsRequest object.
   *
   */
  Get_errorsRequest::Get_errorsRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  Get_errorsRequest::~Get_errorsRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Get_errorsRequest::getClassName()
  {
    return "Get_errorsRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Get_errorsRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("Get_errorsRequest", attrs[i]);
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
  XML::Serializable *Get_errorsRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Get_errorsRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsRequest::write(std::ostream& os) const
  {
    os << "<Get_errorsRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Get_errorsRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Get_errorsReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Get_errorsReply object.
   *
   */
  Get_errorsReply::Get_errorsReply()
      : BGMasterClientReply(), _errors()
  {}

  /*!
   * Constructs a Get_errorsReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  Get_errorsReply::Get_errorsReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _errors()
  {
  }

  /*!
   * Default destructor.
   *
   */
  Get_errorsReply::~Get_errorsReply()
  {
    _errors.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Get_errorsReply::getClassName()
  {
    return "Get_errorsReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Get_errorsReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("Get_errorsReply", attrs[i]);
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
  XML::Serializable *Get_errorsReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "errors") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("errors", "value", attrs[i], attrs[i+1], &i, 0);
      _errors.push_back(temp);
      XML::verify_last_attr("errors", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "Get_errorsReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _errors.begin(); iter != _errors.end(); ++iter)
    {
      os <<  "<errors";
      XML::write_text(os, "errors", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_errorsReply::write(std::ostream& os) const
  {
    os << "<Get_errorsReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</Get_errorsReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Get_historyRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Get_historyRequest object.
   *
   */
  Get_historyRequest::Get_historyRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  Get_historyRequest::~Get_historyRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Get_historyRequest::getClassName()
  {
    return "Get_historyRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Get_historyRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("Get_historyRequest", attrs[i]);
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
  XML::Serializable *Get_historyRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Get_historyRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyRequest::write(std::ostream& os) const
  {
    os << "<Get_historyRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Get_historyRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Get_historyReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Get_historyReply object.
   *
   */
  Get_historyReply::Get_historyReply()
      : BGMasterClientReply(), _history()
  {}

  /*!
   * Constructs a Get_historyReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  Get_historyReply::Get_historyReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _history()
  {
  }

  /*!
   * Default destructor.
   *
   */
  Get_historyReply::~Get_historyReply()
  {
    _history.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Get_historyReply::getClassName()
  {
    return "Get_historyReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Get_historyReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("Get_historyReply", attrs[i]);
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
  XML::Serializable *Get_historyReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "history") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("history", "value", attrs[i], attrs[i+1], &i, 0);
      _history.push_back(temp);
      XML::verify_last_attr("history", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "Get_historyReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _history.begin(); iter != _history.end(); ++iter)
    {
      os <<  "<history";
      XML::write_text(os, "history", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Get_historyReply::write(std::ostream& os) const
  {
    os << "<Get_historyReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</Get_historyReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StatusRequest object.
   *
   */
  StatusRequest::StatusRequest()
      : _binary_ids()
  {}


  /*!
   * Default destructor.
   *
   */
  StatusRequest::~StatusRequest()
  {
    _binary_ids.clear();
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
    if(strcmp(name, "binary_ids") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("binary_ids", "value", attrs[i], attrs[i+1], &i, 0);
      _binary_ids.push_back(temp);
      XML::verify_last_attr("binary_ids", attrs[i]);
      return this;
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
    for (std::vector<std::string>::const_iterator iter = _binary_ids.begin(); iter != _binary_ids.end(); ++iter)
    {
      os <<  "<binary_ids";
      XML::write_text(os, "binary_ids", "value", *iter);
      os << "/>" << std::endl;
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
  // Class StatusReply::BinaryController
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryController object.
   *
   */
  StatusReply::BinaryController::BinaryController()
      : _binary_id(""), _binary_name(""), _alias(""), _user(""), _start_time("")
  {}

  /*!
   * Constructs a BinaryController object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param exit_status
     *          Exit status of binary.
     * @param binary_id
     *          Id of binary.
     * @param binary_name
     *          Path and arguments of binary.
     * @param alias
     *          Alias of binary.
     * @param user
     *          User id under which the binary is running.
     * @param status
     *          Status of the binary.
     * @param start_time
     *          When the binary started.
   */
  StatusReply::BinaryController::BinaryController(const int exit_status, const std::string& binary_id, const std::string& binary_name, const std::string& alias, const std::string& user, const unsigned status, const std::string& start_time)
      : _exit_status(exit_status), _binary_id(binary_id), _binary_name(binary_name), _alias(alias), _user(user), _status(status), _start_time(start_time)
  {
  }

  /*!
   * Default destructor.
   *
   */
  StatusReply::BinaryController::~BinaryController()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string StatusReply::BinaryController::getClassName()
  {
    return "StatusReply::BinaryController";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned StatusReply::BinaryController::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _exit_status = XML::read_int32("StatusReply::BinaryController", "exit_status", attrs[i], attrs[i+1], &i, 0);
    _binary_id = XML::read_text("StatusReply::BinaryController", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _binary_name = XML::read_text("StatusReply::BinaryController", "binary_name", attrs[i], attrs[i+1], &i, 0);
    _alias = XML::read_text("StatusReply::BinaryController", "alias", attrs[i], attrs[i+1], &i, 0);
    _user = XML::read_text("StatusReply::BinaryController", "user", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_uint32("StatusReply::BinaryController", "status", attrs[i], attrs[i+1], &i, 0);
    _start_time = XML::read_text("StatusReply::BinaryController", "start_time", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("BinaryController", attrs[i]);
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
  XML::Serializable *StatusReply::BinaryController::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "BinaryController", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryController::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "StatusReply::BinaryController", "exit_status", _exit_status);
    XML::write_text(os, "StatusReply::BinaryController", "binary_id", _binary_id);
    XML::write_text(os, "StatusReply::BinaryController", "binary_name", _binary_name);
    XML::write_text(os, "StatusReply::BinaryController", "alias", _alias);
    XML::write_text(os, "StatusReply::BinaryController", "user", _user);
    XML::write_uint32(os, "StatusReply::BinaryController", "status", _status);
    XML::write_text(os, "StatusReply::BinaryController", "start_time", _start_time);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryController::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void StatusReply::BinaryController::write(std::ostream& os) const
  {
    os << "<BinaryController";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryController>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class StatusReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a StatusReply object.
   *
   */
  StatusReply::StatusReply()
      : BGMasterClientReply(), _binaries()
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
      : BGMasterClientReply(rc, rt), _binaries()
  {
  }

  /*!
   * Default destructor.
   *
   */
  StatusReply::~StatusReply()
  {
    _binaries.clear();
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
    i = BGMasterClientReply::setAttributes(attrs);
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
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "BinaryController") == 0)
    {
      BinaryController temp;
      temp.setAttributes(attrs);
      _binaries.push_back(temp);
      return &_binaries.back();
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
    for (std::vector<BinaryController>::const_iterator iter = _binaries.begin(); iter != _binaries.end(); ++iter)
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
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</StatusReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailoverRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a FailoverRequest object.
   *
   */
  FailoverRequest::FailoverRequest()
      : _binary_ids(), _trigger("")
  {}

  /*!
   * Constructs a FailoverRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param trigger
     *          Trigger to use for policy selection.
   */
  FailoverRequest::FailoverRequest(const std::string& trigger)
      : _binary_ids(), _trigger(trigger)
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailoverRequest::~FailoverRequest()
  {
    _binary_ids.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailoverRequest::getClassName()
  {
    return "FailoverRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailoverRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _trigger = XML::read_text("FailoverRequest", "trigger", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("FailoverRequest", attrs[i]);
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
  XML::Serializable *FailoverRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "binary_ids") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("binary_ids", "value", attrs[i], attrs[i+1], &i, 0);
      _binary_ids.push_back(temp);
      XML::verify_last_attr("binary_ids", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "FailoverRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "FailoverRequest", "trigger", _trigger);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverRequest::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _binary_ids.begin(); iter != _binary_ids.end(); ++iter)
    {
      os <<  "<binary_ids";
      XML::write_text(os, "binary_ids", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverRequest::write(std::ostream& os) const
  {
    os << "<FailoverRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</FailoverRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailoverReply::BinaryStatus
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a BinaryStatus object.
   *
   */
  FailoverReply::BinaryStatus::BinaryStatus()
      : _binary_id("")
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
  FailoverReply::BinaryStatus::BinaryStatus(const std::string& binary_id, const unsigned status)
      : _binary_id(binary_id), _status(status)
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailoverReply::BinaryStatus::~BinaryStatus()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailoverReply::BinaryStatus::getClassName()
  {
    return "FailoverReply::BinaryStatus";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailoverReply::BinaryStatus::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _binary_id = XML::read_text("FailoverReply::BinaryStatus", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _status = XML::read_uint32("FailoverReply::BinaryStatus", "status", attrs[i], attrs[i+1], &i, 0);
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
  XML::Serializable *FailoverReply::BinaryStatus::addSubEntity(const char *name, const char **attrs) 
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
  void FailoverReply::BinaryStatus::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "FailoverReply::BinaryStatus", "binary_id", _binary_id);
    XML::write_uint32(os, "FailoverReply::BinaryStatus", "status", _status);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverReply::BinaryStatus::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverReply::BinaryStatus::write(std::ostream& os) const
  {
    os << "<BinaryStatus";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</BinaryStatus>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class FailoverReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a FailoverReply object.
   *
   */
  FailoverReply::FailoverReply()
      : BGMasterClientReply(), _statuses()
  {}

  /*!
   * Constructs a FailoverReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  FailoverReply::FailoverReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _statuses()
  {
  }

  /*!
   * Default destructor.
   *
   */
  FailoverReply::~FailoverReply()
  {
    _statuses.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string FailoverReply::getClassName()
  {
    return "FailoverReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned FailoverReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("FailoverReply", attrs[i]);
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
  XML::Serializable *FailoverReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
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
      XMLLIB_THROW("XML %s: invalid subentity %s", "FailoverReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void FailoverReply::writeSubentities(std::ostream& os) const
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
  void FailoverReply::write(std::ostream& os) const
  {
    os << "<FailoverReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</FailoverReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class TerminateRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a TerminateRequest object.
   *
   */
  TerminateRequest::TerminateRequest()
  {}

  /*!
   * Constructs a TerminateRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param master_only
     *          Only kill bgmaster_server.
     * @param signal
     *          Signal to use to terminate managed binaries.
   */
  TerminateRequest::TerminateRequest(const bool master_only, const int signal)
      : _master_only(master_only), _signal(signal)
  {
  }

  /*!
   * Default destructor.
   *
   */
  TerminateRequest::~TerminateRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string TerminateRequest::getClassName()
  {
    return "TerminateRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned TerminateRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _master_only = XML::read_bool("TerminateRequest", "master_only", attrs[i], attrs[i+1], &i, 0);
    _signal = XML::read_int32("TerminateRequest", "signal", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("TerminateRequest", attrs[i]);
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
  XML::Serializable *TerminateRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "TerminateRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateRequest::writeMembers(std::ostream& os) const
  {
    XML::write_bool(os, "TerminateRequest", "master_only", _master_only);
    XML::write_int32(os, "TerminateRequest", "signal", _signal);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateRequest::write(std::ostream& os) const
  {
    os << "<TerminateRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</TerminateRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class TerminateReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a TerminateReply object.
   *
   */
  TerminateReply::TerminateReply()
      : BGMasterClientReply()
  {}

  /*!
   * Constructs a TerminateReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  TerminateReply::TerminateReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  TerminateReply::~TerminateReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string TerminateReply::getClassName()
  {
    return "TerminateReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned TerminateReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("TerminateReply", attrs[i]);
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
  XML::Serializable *TerminateReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "TerminateReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void TerminateReply::write(std::ostream& os) const
  {
    os << "<TerminateReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</TerminateReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ClientsRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ClientsRequest object.
   *
   */
  ClientsRequest::ClientsRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  ClientsRequest::~ClientsRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ClientsRequest::getClassName()
  {
    return "ClientsRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ClientsRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("ClientsRequest", attrs[i]);
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
  XML::Serializable *ClientsRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "ClientsRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsRequest::write(std::ostream& os) const
  {
    os << "<ClientsRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</ClientsRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ClientsReply::Client
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Client object.
   *
   */
  ClientsReply::Client::Client()
      : _client_id(""), _user_id("")
  {}

  /*!
   * Constructs a Client object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param client_id
     *          Clients connected to the server.
     * @param user_id
     *          Id of user owning client.
   */
  ClientsReply::Client::Client(const std::string& client_id, const std::string& user_id)
      : _client_id(client_id), _user_id(user_id)
  {
  }

  /*!
   * Default destructor.
   *
   */
  ClientsReply::Client::~Client()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ClientsReply::Client::getClassName()
  {
    return "ClientsReply::Client";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ClientsReply::Client::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _client_id = XML::read_text("ClientsReply::Client", "client_id", attrs[i], attrs[i+1], &i, 0);
    _user_id = XML::read_text("ClientsReply::Client", "user_id", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Client", attrs[i]);
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
  XML::Serializable *ClientsReply::Client::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Client", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsReply::Client::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "ClientsReply::Client", "client_id", _client_id);
    XML::write_text(os, "ClientsReply::Client", "user_id", _user_id);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsReply::Client::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsReply::Client::write(std::ostream& os) const
  {
    os << "<Client";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Client>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ClientsReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ClientsReply object.
   *
   */
  ClientsReply::ClientsReply()
      : BGMasterClientReply(), _clients()
  {}

  /*!
   * Constructs a ClientsReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  ClientsReply::ClientsReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _clients()
  {
  }

  /*!
   * Default destructor.
   *
   */
  ClientsReply::~ClientsReply()
  {
    _clients.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ClientsReply::getClassName()
  {
    return "ClientsReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ClientsReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("ClientsReply", attrs[i]);
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
  XML::Serializable *ClientsReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "Client") == 0)
    {
      Client temp;
      temp.setAttributes(attrs);
      _clients.push_back(temp);
      return &_clients.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "ClientsReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ClientsReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<Client>::const_iterator iter = _clients.begin(); iter != _clients.end(); ++iter)
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
  void ClientsReply::write(std::ostream& os) const
  {
    os << "<ClientsReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</ClientsReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class AgentlistRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a AgentlistRequest object.
   *
   */
  AgentlistRequest::AgentlistRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  AgentlistRequest::~AgentlistRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string AgentlistRequest::getClassName()
  {
    return "AgentlistRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned AgentlistRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("AgentlistRequest", attrs[i]);
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
  XML::Serializable *AgentlistRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "AgentlistRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistRequest::write(std::ostream& os) const
  {
    os << "<AgentlistRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</AgentlistRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class AgentlistReply::Agent::Binary
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Binary object.
   *
   */
  AgentlistReply::Agent::Binary::Binary()
      : _name(""), _alias(""), _user(""), _binary_id(""), _start_time("")
  {}

  /*!
   * Constructs a Binary object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param status
     *          Status of this binary.
     * @param exit_status
     *          Exit status of this binary.
     * @param name
     *          Path/args of the binary.
     * @param alias
     *          Alias name of the binary.
     * @param user
     *          User id under which the binary is running.
     * @param binary_id
     *          Unique identifier for this binary.
     * @param start_time
     *          Time the binary started.
   */
  AgentlistReply::Agent::Binary::Binary(const int status, const int exit_status, const std::string& name, const std::string& alias, const std::string& user, const std::string& binary_id, const std::string& start_time)
      : _status(status), _exit_status(exit_status), _name(name), _alias(alias), _user(user), _binary_id(binary_id), _start_time(start_time)
  {
  }

  /*!
   * Default destructor.
   *
   */
  AgentlistReply::Agent::Binary::~Binary()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string AgentlistReply::Agent::Binary::getClassName()
  {
    return "AgentlistReply::Agent::Binary";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned AgentlistReply::Agent::Binary::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _status = XML::read_int32("AgentlistReply::Agent::Binary", "status", attrs[i], attrs[i+1], &i, 0);
    _exit_status = XML::read_int32("AgentlistReply::Agent::Binary", "exit_status", attrs[i], attrs[i+1], &i, 0);
    _name = XML::read_text("AgentlistReply::Agent::Binary", "name", attrs[i], attrs[i+1], &i, 0);
    _alias = XML::read_text("AgentlistReply::Agent::Binary", "alias", attrs[i], attrs[i+1], &i, 0);
    _user = XML::read_text("AgentlistReply::Agent::Binary", "user", attrs[i], attrs[i+1], &i, 0);
    _binary_id = XML::read_text("AgentlistReply::Agent::Binary", "binary_id", attrs[i], attrs[i+1], &i, 0);
    _start_time = XML::read_text("AgentlistReply::Agent::Binary", "start_time", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Binary", attrs[i]);
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
  XML::Serializable *AgentlistReply::Agent::Binary::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Binary", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::Agent::Binary::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "AgentlistReply::Agent::Binary", "status", _status);
    XML::write_int32(os, "AgentlistReply::Agent::Binary", "exit_status", _exit_status);
    XML::write_text(os, "AgentlistReply::Agent::Binary", "name", _name);
    XML::write_text(os, "AgentlistReply::Agent::Binary", "alias", _alias);
    XML::write_text(os, "AgentlistReply::Agent::Binary", "user", _user);
    XML::write_text(os, "AgentlistReply::Agent::Binary", "binary_id", _binary_id);
    XML::write_text(os, "AgentlistReply::Agent::Binary", "start_time", _start_time);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::Agent::Binary::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::Agent::Binary::write(std::ostream& os) const
  {
    os << "<Binary";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Binary>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class AgentlistReply::Agent
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Agent object.
   *
   */
  AgentlistReply::Agent::Agent()
      : _binaries(), _agent_id("")
  {}

  /*!
   * Constructs a Agent object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param agent_id
     *          Id of this agent.
   */
  AgentlistReply::Agent::Agent(const std::string& agent_id)
      : _binaries(), _agent_id(agent_id)
  {
  }

  /*!
   * Default destructor.
   *
   */
  AgentlistReply::Agent::~Agent()
  {
    _binaries.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string AgentlistReply::Agent::getClassName()
  {
    return "AgentlistReply::Agent";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned AgentlistReply::Agent::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _agent_id = XML::read_text("AgentlistReply::Agent", "agent_id", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Agent", attrs[i]);
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
  XML::Serializable *AgentlistReply::Agent::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "Binary") == 0)
    {
      Binary temp;
      temp.setAttributes(attrs);
      _binaries.push_back(temp);
      return &_binaries.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "Agent", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::Agent::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "AgentlistReply::Agent", "agent_id", _agent_id);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::Agent::writeSubentities(std::ostream& os) const
  {
    for (std::vector<Binary>::const_iterator iter = _binaries.begin(); iter != _binaries.end(); ++iter)
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
  void AgentlistReply::Agent::write(std::ostream& os) const
  {
    os << "<Agent";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Agent>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class AgentlistReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a AgentlistReply object.
   *
   */
  AgentlistReply::AgentlistReply()
      : BGMasterClientReply(), _agent()
  {}

  /*!
   * Constructs a AgentlistReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  AgentlistReply::AgentlistReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _agent()
  {
  }

  /*!
   * Default destructor.
   *
   */
  AgentlistReply::~AgentlistReply()
  {
    _agent.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string AgentlistReply::getClassName()
  {
    return "AgentlistReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned AgentlistReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("AgentlistReply", attrs[i]);
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
  XML::Serializable *AgentlistReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "Agent") == 0)
    {
      Agent temp;
      temp.setAttributes(attrs);
      _agent.push_back(temp);
      return &_agent.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "AgentlistReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void AgentlistReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<Agent>::const_iterator iter = _agent.begin(); iter != _agent.end(); ++iter)
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
  void AgentlistReply::write(std::ostream& os) const
  {
    os << "<AgentlistReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</AgentlistReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class GetidleRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a GetidleRequest object.
   *
   */
  GetidleRequest::GetidleRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  GetidleRequest::~GetidleRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string GetidleRequest::getClassName()
  {
    return "GetidleRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned GetidleRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("GetidleRequest", attrs[i]);
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
  XML::Serializable *GetidleRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "GetidleRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleRequest::write(std::ostream& os) const
  {
    os << "<GetidleRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</GetidleRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class GetidleReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a GetidleReply object.
   *
   */
  GetidleReply::GetidleReply()
      : BGMasterClientReply(), _aliases()
  {}

  /*!
   * Constructs a GetidleReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  GetidleReply::GetidleReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _aliases()
  {
  }

  /*!
   * Default destructor.
   *
   */
  GetidleReply::~GetidleReply()
  {
    _aliases.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string GetidleReply::getClassName()
  {
    return "GetidleReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned GetidleReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("GetidleReply", attrs[i]);
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
  XML::Serializable *GetidleReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "aliases") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("aliases", "value", attrs[i], attrs[i+1], &i, 0);
      _aliases.push_back(temp);
      XML::verify_last_attr("aliases", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "GetidleReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _aliases.begin(); iter != _aliases.end(); ++iter)
    {
      os <<  "<aliases";
      XML::write_text(os, "aliases", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void GetidleReply::write(std::ostream& os) const
  {
    os << "<GetidleReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</GetidleReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ReloadRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ReloadRequest object.
   *
   */
  ReloadRequest::ReloadRequest()
      : _config_file("")
  {}

  /*!
   * Constructs a ReloadRequest object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param config_file
     *          Config file to load (optional).
   */
  ReloadRequest::ReloadRequest(const std::string& config_file)
      : _config_file(config_file)
  {
  }

  /*!
   * Default destructor.
   *
   */
  ReloadRequest::~ReloadRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ReloadRequest::getClassName()
  {
    return "ReloadRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ReloadRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _config_file = XML::read_text("ReloadRequest", "config_file", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("ReloadRequest", attrs[i]);
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
  XML::Serializable *ReloadRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "ReloadRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadRequest::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "ReloadRequest", "config_file", _config_file);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadRequest::write(std::ostream& os) const
  {
    os << "<ReloadRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</ReloadRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ReloadReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ReloadReply object.
   *
   */
  ReloadReply::ReloadReply()
      : BGMasterClientReply()
  {}

  /*!
   * Constructs a ReloadReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  ReloadReply::ReloadReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  ReloadReply::~ReloadReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ReloadReply::getClassName()
  {
    return "ReloadReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ReloadReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("ReloadReply", attrs[i]);
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
  XML::Serializable *ReloadReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "ReloadReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ReloadReply::write(std::ostream& os) const
  {
    os << "<ReloadReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</ReloadReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MasterstatRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a MasterstatRequest object.
   *
   */
  MasterstatRequest::MasterstatRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  MasterstatRequest::~MasterstatRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MasterstatRequest::getClassName()
  {
    return "MasterstatRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MasterstatRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("MasterstatRequest", attrs[i]);
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
  XML::Serializable *MasterstatRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "MasterstatRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatRequest::write(std::ostream& os) const
  {
    os << "<MasterstatRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</MasterstatRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MasterstatReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a MasterstatReply object.
   *
   */
  MasterstatReply::MasterstatReply()
      : BGMasterClientReply(), _master_start_time(""), _version(""), _properties("")
  {}

  /*!
   * Constructs a MasterstatReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param pid
     *          Bgmaster_server process id.
     * @param master_start_time
     *          Time bgmaster_server started.
     * @param version
     *          The version string for bgmaster_server.
     * @param properties
     *          The bg.properties configuration path for bgmaster_server.
   */
  MasterstatReply::MasterstatReply(const int rc, const std::string& rt, const int pid, const std::string& master_start_time, const std::string& version, const std::string& properties)
      : BGMasterClientReply(rc, rt), _pid(pid), _master_start_time(master_start_time), _version(version), _properties(properties)
  {
  }

  /*!
   * Default destructor.
   *
   */
  MasterstatReply::~MasterstatReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MasterstatReply::getClassName()
  {
    return "MasterstatReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MasterstatReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    _pid = XML::read_int32("MasterstatReply", "pid", attrs[i], attrs[i+1], &i, 0);
    _master_start_time = XML::read_text("MasterstatReply", "master_start_time", attrs[i], attrs[i+1], &i, 0);
    _version = XML::read_text("MasterstatReply", "version", attrs[i], attrs[i+1], &i, 0);
    _properties = XML::read_text("MasterstatReply", "properties", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("MasterstatReply", attrs[i]);
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
  XML::Serializable *MasterstatReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "MasterstatReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatReply::writeMembers(std::ostream& os) const
  {
    XML::write_int32(os, "MasterstatReply", "pid", _pid);
    XML::write_text(os, "MasterstatReply", "master_start_time", _master_start_time);
    XML::write_text(os, "MasterstatReply", "version", _version);
    XML::write_text(os, "MasterstatReply", "properties", _properties);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MasterstatReply::write(std::ostream& os) const
  {
    os << "<MasterstatReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</MasterstatReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MonitorRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a MonitorRequest object.
   *
   */
  MonitorRequest::MonitorRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  MonitorRequest::~MonitorRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MonitorRequest::getClassName()
  {
    return "MonitorRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MonitorRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("MonitorRequest", attrs[i]);
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
  XML::Serializable *MonitorRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "MonitorRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorRequest::write(std::ostream& os) const
  {
    os << "<MonitorRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</MonitorRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MonitorReply::ErrorMessage
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ErrorMessage object.
   *
   */
  MonitorReply::ErrorMessage::ErrorMessage()
      : _errormsg("")
  {}

  /*!
   * Constructs a ErrorMessage object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param errormsg
     *          Error message text.
   */
  MonitorReply::ErrorMessage::ErrorMessage(const std::string& errormsg)
      : _errormsg(errormsg)
  {
  }

  /*!
   * Default destructor.
   *
   */
  MonitorReply::ErrorMessage::~ErrorMessage()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MonitorReply::ErrorMessage::getClassName()
  {
    return "MonitorReply::ErrorMessage";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MonitorReply::ErrorMessage::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _errormsg = XML::read_text("MonitorReply::ErrorMessage", "errormsg", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("ErrorMessage", attrs[i]);
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
  XML::Serializable *MonitorReply::ErrorMessage::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "ErrorMessage", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::ErrorMessage::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "MonitorReply::ErrorMessage", "errormsg", _errormsg);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::ErrorMessage::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::ErrorMessage::write(std::ostream& os) const
  {
    os << "<ErrorMessage";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</ErrorMessage>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MonitorReply::EventMessage
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a EventMessage object.
   *
   */
  MonitorReply::EventMessage::EventMessage()
      : _eventmsg("")
  {}

  /*!
   * Constructs a EventMessage object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param eventmsg
     *          Event message text.
   */
  MonitorReply::EventMessage::EventMessage(const std::string& eventmsg)
      : _eventmsg(eventmsg)
  {
  }

  /*!
   * Default destructor.
   *
   */
  MonitorReply::EventMessage::~EventMessage()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MonitorReply::EventMessage::getClassName()
  {
    return "MonitorReply::EventMessage";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MonitorReply::EventMessage::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _eventmsg = XML::read_text("MonitorReply::EventMessage", "eventmsg", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("EventMessage", attrs[i]);
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
  XML::Serializable *MonitorReply::EventMessage::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "EventMessage", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::EventMessage::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "MonitorReply::EventMessage", "eventmsg", _eventmsg);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::EventMessage::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::EventMessage::write(std::ostream& os) const
  {
    os << "<EventMessage";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</EventMessage>" << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class MonitorReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a MonitorReply object.
   *
   */
  MonitorReply::MonitorReply()
      : BGMasterClientReply(), _errormessages(), _eventmessages()
  {}

  /*!
   * Constructs a MonitorReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  MonitorReply::MonitorReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _errormessages(), _eventmessages()
  {
  }

  /*!
   * Default destructor.
   *
   */
  MonitorReply::~MonitorReply()
  {
    _errormessages.clear();
    _eventmessages.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string MonitorReply::getClassName()
  {
    return "MonitorReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned MonitorReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("MonitorReply", attrs[i]);
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
  XML::Serializable *MonitorReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "ErrorMessage") == 0)
    {
      ErrorMessage temp;
      temp.setAttributes(attrs);
      _errormessages.push_back(temp);
      return &_errormessages.back();
    }
    else if(strcmp(name, "EventMessage") == 0)
    {
      EventMessage temp;
      temp.setAttributes(attrs);
      _eventmessages.push_back(temp);
      return &_eventmessages.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "MonitorReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void MonitorReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<ErrorMessage>::const_iterator iter = _errormessages.begin(); iter != _errormessages.end(); ++iter)
    {
      os << *iter;
    }
    for (std::vector<EventMessage>::const_iterator iter = _eventmessages.begin(); iter != _eventmessages.end(); ++iter)
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
  void MonitorReply::write(std::ostream& os) const
  {
    os << "<MonitorReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</MonitorReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class EndmonitorRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a EndmonitorRequest object.
   *
   */
  EndmonitorRequest::EndmonitorRequest()
  {}


  /*!
   * Default destructor.
   *
   */
  EndmonitorRequest::~EndmonitorRequest()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string EndmonitorRequest::getClassName()
  {
    return "EndmonitorRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned EndmonitorRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("EndmonitorRequest", attrs[i]);
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
  XML::Serializable *EndmonitorRequest::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "EndmonitorRequest", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorRequest::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorRequest::write(std::ostream& os) const
  {
    os << "<EndmonitorRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</EndmonitorRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class EndmonitorReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a EndmonitorReply object.
   *
   */
  EndmonitorReply::EndmonitorReply()
      : BGMasterClientReply()
  {}

  /*!
   * Constructs a EndmonitorReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  EndmonitorReply::EndmonitorReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt)
  {
  }

  /*!
   * Default destructor.
   *
   */
  EndmonitorReply::~EndmonitorReply()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string EndmonitorReply::getClassName()
  {
    return "EndmonitorReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned EndmonitorReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("EndmonitorReply", attrs[i]);
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
  XML::Serializable *EndmonitorReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "EndmonitorReply", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorReply::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EndmonitorReply::write(std::ostream& os) const
  {
    os << "<EndmonitorReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</EndmonitorReply>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class EventMessage
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a EventMessage object.
   *
   */
  EventMessage::EventMessage()
      : _eventmsg("")
  {}

  /*!
   * Constructs a EventMessage object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param eventmsg
     *          Event message text.
   */
  EventMessage::EventMessage(const std::string& eventmsg)
      : _eventmsg(eventmsg)
  {
  }

  /*!
   * Default destructor.
   *
   */
  EventMessage::~EventMessage()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string EventMessage::getClassName()
  {
    return "EventMessage";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned EventMessage::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _eventmsg = XML::read_text("EventMessage", "eventmsg", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("EventMessage", attrs[i]);
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
  XML::Serializable *EventMessage::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "EventMessage", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EventMessage::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "EventMessage", "eventmsg", _eventmsg);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EventMessage::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void EventMessage::write(std::ostream& os) const
  {
    os << "<EventMessage";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</EventMessage>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class ErrorMessage
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a ErrorMessage object.
   *
   */
  ErrorMessage::ErrorMessage()
      : _errormsg("")
  {}

  /*!
   * Constructs a ErrorMessage object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param errormsg
     *          Error message text.
   */
  ErrorMessage::ErrorMessage(const std::string& errormsg)
      : _errormsg(errormsg)
  {
  }

  /*!
   * Default destructor.
   *
   */
  ErrorMessage::~ErrorMessage()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string ErrorMessage::getClassName()
  {
    return "ErrorMessage";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned ErrorMessage::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _errormsg = XML::read_text("ErrorMessage", "errormsg", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("ErrorMessage", attrs[i]);
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
  XML::Serializable *ErrorMessage::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "ErrorMessage", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ErrorMessage::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "ErrorMessage", "errormsg", _errormsg);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ErrorMessage::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void ErrorMessage::write(std::ostream& os) const
  {
    os << "<ErrorMessage";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</ErrorMessage>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class Logger
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a Logger object.
   *
   */
  Logger::Logger()
      : _name(""), _level("")
  {}

  /*!
   * Constructs a Logger object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param name
     *          Logger name.
     * @param level
     *          Logger level.
   */
  Logger::Logger(const std::string& name, const std::string& level)
      : _name(name), _level(level)
  {
  }

  /*!
   * Default destructor.
   *
   */
  Logger::~Logger()
  {
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string Logger::getClassName()
  {
    return "Logger";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned Logger::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    _name = XML::read_text("Logger", "name", attrs[i], attrs[i+1], &i, 0);
    _level = XML::read_text("Logger", "level", attrs[i], attrs[i+1], &i, 0);
    XML::verify_last_attr("Logger", attrs[i]);
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
  XML::Serializable *Logger::addSubEntity(const char *name, const char **attrs) 
  {
    // There are no subentities for this class. Throw an exception if this is called.
    XMLLIB_THROW("XML %s: invalid subentity %s", "Logger", name);
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Logger::writeMembers(std::ostream& os) const
  {
    XML::write_text(os, "Logger", "name", _name);
    XML::write_text(os, "Logger", "level", _level);
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Logger::writeSubentities(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void Logger::write(std::ostream& os) const
  {
    os << "<Logger";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</Logger>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class LoglevelRequest
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a LoglevelRequest object.
   *
   */
  LoglevelRequest::LoglevelRequest()
      : _loggers()
  {}


  /*!
   * Default destructor.
   *
   */
  LoglevelRequest::~LoglevelRequest()
  {
    _loggers.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string LoglevelRequest::getClassName()
  {
    return "LoglevelRequest";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned LoglevelRequest::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    XML::verify_last_attr("LoglevelRequest", attrs[i]);
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
  XML::Serializable *LoglevelRequest::addSubEntity(const char *name, const char **attrs) 
  {
    if(strcmp(name, "loggers") == 0)
    {
      unsigned i = 0;
      std::string temp = XML::read_text("loggers", "value", attrs[i], attrs[i+1], &i, 0);
      _loggers.push_back(temp);
      XML::verify_last_attr("loggers", attrs[i]);
      return this;
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "LoglevelRequest", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void LoglevelRequest::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void LoglevelRequest::writeSubentities(std::ostream& os) const
  {
    for (std::vector<std::string>::const_iterator iter = _loggers.begin(); iter != _loggers.end(); ++iter)
    {
      os <<  "<loggers";
      XML::write_text(os, "loggers", "value", *iter);
      os << "/>" << std::endl;
    }
  }

  /*!
   * Writes the XML to the output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void LoglevelRequest::write(std::ostream& os) const
  {
    os << "<LoglevelRequest";
    writeMembers(os);
    os << ">" << std::endl;
    writeSubentities(os);
    os << "</LoglevelRequest>" << std::endl;
  }



  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Class LoglevelReply
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*!
   * Constructs a LoglevelReply object.
   *
   */
  LoglevelReply::LoglevelReply()
      : BGMasterClientReply(), _loggers()
  {}

  /*!
   * Constructs a LoglevelReply object. The copy constructors of all attributes are
   * used to initialize the class attributes.
   *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
   */
  LoglevelReply::LoglevelReply(const int rc, const std::string& rt)
      : BGMasterClientReply(rc, rt), _loggers()
  {
  }

  /*!
   * Default destructor.
   *
   */
  LoglevelReply::~LoglevelReply()
  {
    _loggers.clear();
  }

  /*!
   * Retrieves the class name. This is used for XML tag matching in client-server programs.
   *
   * @return a string containing the name of the class.
   */
  std::string LoglevelReply::getClassName()
  {
    return "LoglevelReply";
  }

  /*!
   * Set the XML class attributes.
   *
   * @param attrs
   *         the XML class attributes to set.
   * @return the index of the read data.
   *          if there was a problem setting the new XML attributes.
   */
  unsigned LoglevelReply::setAttributes(const char **attrs) 
  {
    unsigned i = 0;
    i = BGMasterClientReply::setAttributes(attrs);
    XML::verify_last_attr("LoglevelReply", attrs[i]);
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
  XML::Serializable *LoglevelReply::addSubEntity(const char *name, const char **attrs) 
  {
    try
    {
      return BGMasterClientReply::addSubEntity(name, attrs);
    }
    catch(...)
    {
      // If this subentity is not from the base class then catch the exception and ignore it.
    }

    if(strcmp(name, "Logger") == 0)
    {
      Logger temp;
      temp.setAttributes(attrs);
      _loggers.push_back(temp);
      return &_loggers.back();
    }
    else
    {
      // Could not find a subentity by the given name for this class. Throw an exception.
      XMLLIB_THROW("XML %s: invalid subentity %s", "LoglevelReply", name);
    }
  }

  /*!
   * Writes the XML members to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void LoglevelReply::writeMembers(std::ostream& os) const
  {
  }

  /*!
   * Writes the XML subentities to an output stream.
   *
   * @param os
   *          the output stream to dump the XML to.
   */
  void LoglevelReply::writeSubentities(std::ostream& os) const
  {
    for (std::vector<Logger>::const_iterator iter = _loggers.begin(); iter != _loggers.end(); ++iter)
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
  void LoglevelReply::write(std::ostream& os) const
  {
    os << "<LoglevelReply";
    BGMasterClientReply::writeMembers(os);
    writeMembers(os);
    os << ">" << std::endl;
    BGMasterClientReply::writeSubentities(os);
    writeSubentities(os);
    os << "</LoglevelReply>" << std::endl;
  }

}

