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

#ifndef _BGMASTERCLIENTPROTOCOLSPEC_H
#define _BGMASTERCLIENTPROTOCOLSPEC_H

#include <cstring>
#include <string>
#include <vector>
#include "xml/include/library/XML.h"


namespace BGMasterClientProtocolSpec
{

  /*! The BGMasterClientProtocolSpec version. */
  const std::string VERSION = "1";



  /*!
   * Class BGMasterClientReply.
   *
   */
  class BGMasterClientReply : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    BGMasterClientReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    BGMasterClientReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~BGMasterClientReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Return error code. */
    int         _rc;

    /*! Return error text. */
    std::string _rt;
  };


  /*!
   * Class JoinRequest.
   *
   */
  class JoinRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    JoinRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
    JoinRequest(const std::string& ip_address, const int port, const std::string& initiator, const std::string& host_name);

    /*!
     * Default destructor.
     *
     */
    ~JoinRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Initiator listener ip address. */
    std::string _ip_address;

    /*! Initiator listener port. */
    int         _port;

    /*! 'client' or 'agent'. */
    std::string _initiator;

    /*! Initiator listener host name. */
    std::string _host_name;
  };


  /*!
   * Class JoinReply.
   *
   */
  class JoinReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    JoinReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
    JoinReply(const int rc, const std::string& rt, const std::string& agent_ip, const std::string& master_ip, const std::string& master_port);

    /*!
     * Default destructor.
     *
     */
    ~JoinReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Initiator ip address. */
    std::string _agent_ip;

    /*! Master ip address. */
    std::string _master_ip;

    /*! Ephemeral port master is using for its requests. */
    std::string _master_port;
  };


  /*!
   * Class StartRequest.
   *
   */
  class StartRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    StartRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param alias
     *          Short identifier for the binary.
     * @param agent_id
     *          Optional id of agent to start the binary.
     */
    StartRequest(const std::string& alias, const std::string& agent_id);

    /*!
     * Default destructor.
     *
     */
    ~StartRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Short identifier for the binary. */
    std::string _alias;

    /*! Optional id of agent to start the binary. */
    std::string _agent_id;
  };


  /*!
   * Class StartReply.
   *
   */
  class StartReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    StartReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param binary_id
     *          Binary id generated from pid and ip address.
     */
    StartReply(const int rc, const std::string& rt, const std::string& binary_id);

    /*!
     * Default destructor.
     *
     */
    ~StartReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Binary id generated from pid and ip address. */
    std::string _binary_id;
  };


  /*!
   * Class WaitRequest.
   *
   */
  class WaitRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    WaitRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param binary_id
     *          Binaries to stop.
     */
    WaitRequest(const std::string& binary_id);

    /*!
     * Default destructor.
     *
     */
    ~WaitRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Binaries to stop. */
    std::string _binary_id;
  };


  /*!
   * Class WaitReply.
   *
   */
  class WaitReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class WaitReply::BinaryStatus.
     *
     */
    class BinaryStatus : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      BinaryStatus();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param binary_id
       *          Id of binary.
       * @param status
       *          Status of the binary.
       */
      BinaryStatus(const std::string& binary_id, const int status);

      /*!
       * Default destructor.
       *
       */
      ~BinaryStatus();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Id of binary. */
      std::string _binary_id;

      /*! Status of the binary. */
      int         _status;
    };

    /*!
     * Default constructor.
     *
     */
    WaitReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param status
     *          Status object.
     */
    WaitReply(const int rc, const std::string& rt, BinaryStatus status);

    /*!
     * Default destructor.
     *
     */
    ~WaitReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Status object. */
    BinaryStatus _status;
  };


  /*!
   * Class Alias_waitRequest.
   *
   */
  class Alias_waitRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Alias_waitRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param alias
     *          Short identifier for the binary.
     * @param timeout
     *          Wait timeout in seconds.
     */
    Alias_waitRequest(const std::string& alias, const unsigned timeout);

    /*!
     * Default destructor.
     *
     */
    ~Alias_waitRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Short identifier for the binary. */
    std::string _alias;

    /*! Wait timeout in seconds. */
    unsigned    _timeout;
  };


  /*!
   * Class Alias_waitReply.
   *
   */
  class Alias_waitReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Alias_waitReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     * @param binary_id
     *          Binary id generated from pid and ip address.
     */
    Alias_waitReply(const int rc, const std::string& rt, const std::string& binary_id);

    /*!
     * Default destructor.
     *
     */
    ~Alias_waitReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Binary id generated from pid and ip address. */
    std::string _binary_id;
  };


  /*!
   * Class StopRequest.
   *
   */
  class StopRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    StopRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param signal
     *          Initial signal number.
     */
    StopRequest(const int signal);

    /*!
     * Default destructor.
     *
     */
    ~StopRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Binaries to stop. */
    std::vector<std::string> _binary_ids;

    /*! Initial signal number. */
    int                      _signal;

    /*! Alias name for binary(ies) to stop. */
    std::vector<std::string> _aliases;
  };


  /*!
   * Class StopReply.
   *
   */
  class StopReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class StopReply::BinaryStatus.
     *
     */
    class BinaryStatus : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      BinaryStatus();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param binary_id
       *          Id of binary.
       * @param status
       *          Status of the binary.
       */
      BinaryStatus(const std::string& binary_id, const int status);

      /*!
       * Default destructor.
       *
       */
      ~BinaryStatus();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Id of binary. */
      std::string _binary_id;

      /*! Status of the binary. */
      int         _status;
    };

    /*!
     * Default constructor.
     *
     */
    StopReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    StopReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~StopReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Status objects. */
    std::vector<BinaryStatus> _statuses;
  };


  /*!
   * Class Get_errorsRequest.
   *
   */
  class Get_errorsRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Get_errorsRequest();
    /*!
     * Default destructor.
     *
     */
    ~Get_errorsRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class Get_errorsReply.
   *
   */
  class Get_errorsReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Get_errorsReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    Get_errorsReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~Get_errorsReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Error messages. */
    std::vector<std::string> _errors;
  };


  /*!
   * Class Get_historyRequest.
   *
   */
  class Get_historyRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Get_historyRequest();
    /*!
     * Default destructor.
     *
     */
    ~Get_historyRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class Get_historyReply.
   *
   */
  class Get_historyReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Get_historyReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    Get_historyReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~Get_historyReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Master events. */
    std::vector<std::string> _history;
  };


  /*!
   * Class StatusRequest.
   *
   */
  class StatusRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    StatusRequest();
    /*!
     * Default destructor.
     *
     */
    ~StatusRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Id of binary. */
    std::vector<std::string> _binary_ids;
  };


  /*!
   * Class StatusReply.
   *
   */
  class StatusReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class StatusReply::BinaryController.
     *
     */
    class BinaryController : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      BinaryController();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
      BinaryController(const int exit_status, const std::string& binary_id, const std::string& binary_name, const std::string& alias, const std::string& user, const unsigned status, const std::string& start_time);

      /*!
       * Default destructor.
       *
       */
      ~BinaryController();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Exit status of binary. */
      int         _exit_status;

      /*! Id of binary. */
      std::string _binary_id;

      /*! Path and arguments of binary. */
      std::string _binary_name;

      /*! Alias of binary. */
      std::string _alias;

      /*! User id under which the binary is running. */
      std::string _user;

      /*! Status of the binary. */
      unsigned    _status;

      /*! When the binary started. */
      std::string _start_time;
    };

    /*!
     * Default constructor.
     *
     */
    StatusReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    StatusReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~StatusReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Status objects. */
    std::vector<BinaryController> _binaries;
  };


  /*!
   * Class FailoverRequest.
   *
   */
  class FailoverRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    FailoverRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param trigger
     *          Trigger to use for policy selection.
     */
    FailoverRequest(const std::string& trigger);

    /*!
     * Default destructor.
     *
     */
    ~FailoverRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Binaries to stop. */
    std::vector<std::string> _binary_ids;

    /*! Trigger to use for policy selection. */
    std::string              _trigger;
  };


  /*!
   * Class FailoverReply.
   *
   */
  class FailoverReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class FailoverReply::BinaryStatus.
     *
     */
    class BinaryStatus : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      BinaryStatus();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param binary_id
       *          Id of binary.
       * @param status
       *          Status of the binary.
       */
      BinaryStatus(const std::string& binary_id, const unsigned status);

      /*!
       * Default destructor.
       *
       */
      ~BinaryStatus();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Id of binary. */
      std::string _binary_id;

      /*! Status of the binary. */
      unsigned    _status;
    };

    /*!
     * Default constructor.
     *
     */
    FailoverReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    FailoverReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~FailoverReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Status objects. */
    std::vector<BinaryStatus> _statuses;
  };


  /*!
   * Class TerminateRequest.
   *
   */
  class TerminateRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    TerminateRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param master_only
     *          Only kill bgmaster_server.
     * @param signal
     *          Signal to use to terminate managed binaries.
     */
    TerminateRequest(const bool master_only, const int signal);

    /*!
     * Default destructor.
     *
     */
    ~TerminateRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Only kill bgmaster_server. */
    bool _master_only;

    /*! Signal to use to terminate managed binaries. */
    int  _signal;
  };


  /*!
   * Class TerminateReply.
   *
   */
  class TerminateReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    TerminateReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    TerminateReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~TerminateReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class ClientsRequest.
   *
   */
  class ClientsRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    ClientsRequest();
    /*!
     * Default destructor.
     *
     */
    ~ClientsRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class ClientsReply.
   *
   */
  class ClientsReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class ClientsReply::Client.
     *
     */
    class Client : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      Client();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param client_id
       *          Clients connected to the server.
       * @param user_id
       *          Id of user owning client.
       */
      Client(const std::string& client_id, const std::string& user_id);

      /*!
       * Default destructor.
       *
       */
      ~Client();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Clients connected to the server. */
      std::string _client_id;

      /*! Id of user owning client. */
      std::string _user_id;
    };

    /*!
     * Default constructor.
     *
     */
    ClientsReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    ClientsReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~ClientsReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    std::vector<Client> _clients;
  };


  /*!
   * Class AgentlistRequest.
   *
   */
  class AgentlistRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    AgentlistRequest();
    /*!
     * Default destructor.
     *
     */
    ~AgentlistRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class AgentlistReply.
   *
   */
  class AgentlistReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class AgentlistReply::Agent.
     *
     */
    class Agent : public XML::Serializable
    {
    public:

      /*!
       * Class AgentlistReply::Agent::Binary.
       *
       */
      class Binary : public XML::Serializable
      {
      public:

        /*!
         * Default constructor.
         *
         */
        Binary();

        /*!
         * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
        Binary(const int status, const int exit_status, const std::string& name, const std::string& alias, const std::string& user, const std::string& binary_id, const std::string& start_time);

        /*!
         * Default destructor.
         *
         */
        ~Binary();

        /*!
         * Retrieves the class name. This is used for XML tag matching in client-server programs.
         *
         * @return a string containing the name of the class.
         */
        static std::string getClassName();

        /*!
         * Set the XML class attributes.
         *
         * @param attrs
         *          the XML class attributes to set.
         * @return the index of the read data.
         *           if there was a problem setting the new XML attributes.
         */
        virtual unsigned setAttributes(const char **attrs) ;

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
        XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

        /*!
         * Writes the XML members to an output stream.
         *
         * @param os
         *          the output stream to dump the XML to.
         */
        virtual void writeMembers(std::ostream& os) const;

        /*!
         * Writes the XML subentities to an output stream.
         *
         * @param os
         *          the output stream to dump the XML to.
         */
        virtual void writeSubentities(std::ostream& os) const;

        /*!
         * Writes the XML to the output stream.
         *
         * @param os
         *          the output stream to dump the XML to.
         */
        virtual void write(std::ostream& os) const;

        /*! Status of this binary. */
        int         _status;

        /*! Exit status of this binary. */
        int         _exit_status;

        /*! Path/args of the binary. */
        std::string _name;

        /*! Alias name of the binary. */
        std::string _alias;

        /*! User id under which the binary is running. */
        std::string _user;

        /*! Unique identifier for this binary. */
        std::string _binary_id;

        /*! Time the binary started. */
        std::string _start_time;
      };

      /*!
       * Default constructor.
       *
       */
      Agent();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param agent_id
       *          Id of this agent.
       */
      Agent(const std::string& agent_id);

      /*!
       * Default destructor.
       *
       */
      ~Agent();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! List of binaries associated with this agent. */
      std::vector<Binary> _binaries;

      /*! Id of this agent. */
      std::string         _agent_id;
    };

    /*!
     * Default constructor.
     *
     */
    AgentlistReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    AgentlistReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~AgentlistReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! This agent. */
    std::vector<Agent> _agent;
  };


  /*!
   * Class GetidleRequest.
   *
   */
  class GetidleRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    GetidleRequest();
    /*!
     * Default destructor.
     *
     */
    ~GetidleRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class GetidleReply.
   *
   */
  class GetidleReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    GetidleReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    GetidleReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~GetidleReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! List of aliases configured but not running. */
    std::vector<std::string> _aliases;
  };


  /*!
   * Class ReloadRequest.
   *
   */
  class ReloadRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    ReloadRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param config_file
     *          Config file to load (optional).
     */
    ReloadRequest(const std::string& config_file);

    /*!
     * Default destructor.
     *
     */
    ~ReloadRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Config file to load (optional). */
    std::string _config_file;
  };


  /*!
   * Class ReloadReply.
   *
   */
  class ReloadReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    ReloadReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    ReloadReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~ReloadReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class MasterstatRequest.
   *
   */
  class MasterstatRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    MasterstatRequest();
    /*!
     * Default destructor.
     *
     */
    ~MasterstatRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class MasterstatReply.
   *
   */
  class MasterstatReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    MasterstatReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
    MasterstatReply(const int rc, const std::string& rt, const int pid, const std::string& master_start_time, const std::string& version, const std::string& properties);

    /*!
     * Default destructor.
     *
     */
    ~MasterstatReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Bgmaster_server process id. */
    int         _pid;

    /*! Time bgmaster_server started. */
    std::string _master_start_time;

    /*! The version string for bgmaster_server. */
    std::string _version;

    /*! The bg.properties configuration path for bgmaster_server. */
    std::string _properties;
  };


  /*!
   * Class MonitorRequest.
   *
   */
  class MonitorRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    MonitorRequest();
    /*!
     * Default destructor.
     *
     */
    ~MonitorRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class MonitorReply.
   *
   */
  class MonitorReply : public BGMasterClientReply
  {
  public:

    /*!
     * Class MonitorReply::ErrorMessage.
     *
     */
    class ErrorMessage : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      ErrorMessage();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param errormsg
       *          Error message text.
       */
      ErrorMessage(const std::string& errormsg);

      /*!
       * Default destructor.
       *
       */
      ~ErrorMessage();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Error message text. */
      std::string _errormsg;
    };

    /*!
     * Class MonitorReply::EventMessage.
     *
     */
    class EventMessage : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      EventMessage();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
       *
       * @param eventmsg
       *          Event message text.
       */
      EventMessage(const std::string& eventmsg);

      /*!
       * Default destructor.
       *
       */
      ~EventMessage();

      /*!
       * Retrieves the class name. This is used for XML tag matching in client-server programs.
       *
       * @return a string containing the name of the class.
       */
      static std::string getClassName();

      /*!
       * Set the XML class attributes.
       *
       * @param attrs
       *          the XML class attributes to set.
       * @return the index of the read data.
       *           if there was a problem setting the new XML attributes.
       */
      virtual unsigned setAttributes(const char **attrs) ;

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
      XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

      /*!
       * Writes the XML members to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeMembers(std::ostream& os) const;

      /*!
       * Writes the XML subentities to an output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void writeSubentities(std::ostream& os) const;

      /*!
       * Writes the XML to the output stream.
       *
       * @param os
       *          the output stream to dump the XML to.
       */
      virtual void write(std::ostream& os) const;

      /*! Event message text. */
      std::string _eventmsg;
    };

    /*!
     * Default constructor.
     *
     */
    MonitorReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    MonitorReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~MonitorReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Contents of error buffer. */
    std::vector<ErrorMessage> _errormessages;

    /*! Contents of event buffer. */
    std::vector<EventMessage> _eventmessages;
  };


  /*!
   * Class EndmonitorRequest.
   *
   */
  class EndmonitorRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    EndmonitorRequest();
    /*!
     * Default destructor.
     *
     */
    ~EndmonitorRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class EndmonitorReply.
   *
   */
  class EndmonitorReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    EndmonitorReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    EndmonitorReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~EndmonitorReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;
  };


  /*!
   * Class EventMessage.
   *
   */
  class EventMessage : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    EventMessage();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param eventmsg
     *          Event message text.
     */
    EventMessage(const std::string& eventmsg);

    /*!
     * Default destructor.
     *
     */
    ~EventMessage();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Event message text. */
    std::string _eventmsg;
  };


  /*!
   * Class ErrorMessage.
   *
   */
  class ErrorMessage : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    ErrorMessage();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param errormsg
     *          Error message text.
     */
    ErrorMessage(const std::string& errormsg);

    /*!
     * Default destructor.
     *
     */
    ~ErrorMessage();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Error message text. */
    std::string _errormsg;
  };


  /*!
   * Class Logger.
   *
   */
  class Logger : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    Logger();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param name
     *          Logger name.
     * @param level
     *          Logger level.
     */
    Logger(const std::string& name, const std::string& level);

    /*!
     * Default destructor.
     *
     */
    ~Logger();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Logger name. */
    std::string _name;

    /*! Logger level. */
    std::string _level;
  };


  /*!
   * Class LoglevelRequest.
   *
   */
  class LoglevelRequest : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    LoglevelRequest();
    /*!
     * Default destructor.
     *
     */
    ~LoglevelRequest();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Loggers to change and new level. */
    std::vector<std::string> _loggers;
  };


  /*!
   * Class LoglevelReply.
   *
   */
  class LoglevelReply : public BGMasterClientReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    LoglevelReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    LoglevelReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~LoglevelReply();

    /*!
     * Retrieves the class name. This is used for XML tag matching in client-server programs.
     *
     * @return a string containing the name of the class.
     */
    static std::string getClassName();

    /*!
     * Set the XML class attributes.
     *
     * @param attrs
     *          the XML class attributes to set.
     * @return the index of the read data.
     *           if there was a problem setting the new XML attributes.
     */
    virtual unsigned setAttributes(const char **attrs) ;

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
    XML::Serializable* addSubEntity(const char *name, const char **attrs) ;

    /*!
     * Writes the XML members to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeMembers(std::ostream& os) const;

    /*!
     * Writes the XML subentities to an output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void writeSubentities(std::ostream& os) const;

    /*!
     * Writes the XML to the output stream.
     *
     * @param os
     *          the output stream to dump the XML to.
     */
    virtual void write(std::ostream& os) const;

    /*! Loggers and their level. */
    std::vector<Logger> _loggers;
  };

}

#endif
