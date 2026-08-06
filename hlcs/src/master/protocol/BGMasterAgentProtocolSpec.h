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

#ifndef _BGMASTERAGENTPROTOCOLSPEC_H
#define _BGMASTERAGENTPROTOCOLSPEC_H

#include <cstring>
#include <string>
#include <vector>
#include "xml/include/library/XML.h"


namespace BGMasterAgentProtocolSpec
{

  /*! The BGMasterAgentProtocolSpec version. */
  const std::string VERSION = "1";



  /*!
   * Class BGMasterAgentReply.
   *
   */
  class BGMasterAgentReply : public XML::Serializable
  {
  public:

    /*!
     * Default constructor.
     *
     */
    BGMasterAgentReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    BGMasterAgentReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~BGMasterAgentReply();

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
     * Class JoinRequest::WorkingBins.
     *
     */
    class WorkingBins : public XML::Serializable
    {
    public:

      /*!
       * Default constructor.
       *
       */
      WorkingBins();

      /*!
       * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
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
      WorkingBins(const std::string& binary_id, const std::string& name, const std::string& alias, const std::string& status, const std::string& user);

      /*!
       * Default destructor.
       *
       */
      ~WorkingBins();

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

      /*! Path/args for the binary. */
      std::string _name;

      /*! Standard alias for the binary. */
      std::string _alias;

      /*! Status of the binary. */
      std::string _status;

      /*! User under which binary is running. */
      std::string _user;
    };

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
    std::string              _ip_address;

    /*! Initiator listener port. */
    int                      _port;

    /*! 'client' or 'agent'. */
    std::string              _initiator;

    /*! Initiator listener host name. */
    std::string              _host_name;

    /*! Binaries running on this agent. */
    std::vector<WorkingBins> _running_binaries;
  };


  /*!
   * Class JoinReply.
   *
   */
  class JoinReply : public BGMasterAgentReply
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
    std::string              _agent_ip;

    /*! Master ip address. */
    std::string              _master_ip;

    /*! Ephemeral port master is using for its requests. */
    std::string              _master_port;

    /*! Invalid binary ids that must die. */
    std::vector<std::string> _bad_bins;
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
    StartRequest(const std::string& path, const std::string& arguments, const std::string& logdir, const std::string& alias, const std::string& user);

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

    /*! Full path to binary to execute. */
    std::string _path;

    /*! Argument string. */
    std::string _arguments;

    /*! Base log directory. */
    std::string _logdir;

    /*! Alias name for the binary. */
    std::string _alias;

    /*! User id for the binary. */
    std::string _user;
  };


  /*!
   * Class StartReply.
   *
   */
  class StartReply : public BGMasterAgentReply
  {
  public:

    /*!
     * Class StartReply::BinaryStatus.
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
       * @param exit_status
       *          Exit status of binary.
       */
      BinaryStatus(const std::string& binary_id, const int exit_status);

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

      /*! Exit status of binary. */
      int         _exit_status;
    };

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
     * @param status
     *          Status object.
     */
    StartReply(const int rc, const std::string& rt, BinaryStatus status);

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

    /*! Status object. */
    BinaryStatus _status;
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
     * @param binary_id
     *          Binary to stop.
     * @param signal
     *          Initial signal number.
     */
    StopRequest(const std::string& binary_id, const int signal);

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

    /*! Binary to stop. */
    std::string _binary_id;

    /*! Initial signal number. */
    int         _signal;
  };


  /*!
   * Class StopReply.
   *
   */
  class StopReply : public BGMasterAgentReply
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
       * @param exit_status
       *          Exit status of the binary if available.
       */
      BinaryStatus(const std::string& binary_id, const int exit_status);

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

      /*! Exit status of the binary if available. */
      int         _exit_status;
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
     * @param status
     *          Status of stopped binary.
     */
    StopReply(const int rc, const std::string& rt, BinaryStatus status);

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

    /*! Status of stopped binary. */
    BinaryStatus _status;
  };


  /*!
   * Class StatusRequest.
   *
   */
  class StatusRequest : public XML::Serializable
  {
  public:

    /*!
     * Class StatusRequest::BinaryStatus.
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
      BinaryStatus(const std::string& binary_id, const std::string& status);

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
      std::string _status;
    };

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

    /*! Status objects. */
    std::vector<BinaryStatus> _statuses;
  };


  /*!
   * Class StatusReply.
   *
   */
  class StatusReply : public BGMasterAgentReply
  {
  public:

    /*!
     * Class StatusReply::BinaryStatus.
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
      BinaryStatus(const std::string& binary_id, const std::string& status);

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
      std::string _status;
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
    std::vector<BinaryStatus> _statuses;
  };


  /*!
   * Class CompleteRequest.
   *
   */
  class CompleteRequest : public XML::Serializable
  {
  public:

    /*!
     * Class CompleteRequest::BinaryStatus.
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
      BinaryStatus(const std::string& binary_id, const std::string& status);

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
      std::string _status;
    };

    /*!
     * Default constructor.
     *
     */
    CompleteRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param status
     *          Status object.
     * @param exit_status
     *          Exit status of binary.
     */
    CompleteRequest(BinaryStatus status, const int exit_status);

    /*!
     * Default destructor.
     *
     */
    ~CompleteRequest();

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

    /*! Exit status of binary. */
    int          _exit_status;
  };


  /*!
   * Class CompleteReply.
   *
   */
  class CompleteReply : public BGMasterAgentReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    CompleteReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    CompleteReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~CompleteReply();

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
   * Class FailedRequest.
   *
   */
  class FailedRequest : public XML::Serializable
  {
  public:

    /*!
     * Class FailedRequest::BinaryStatus.
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
       * @param exit_status
       *          Exit status of binary.
       */
      BinaryStatus(const std::string& binary_id, const int exit_status);

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

      /*! Exit status of binary. */
      int         _exit_status;
    };

    /*!
     * Default constructor.
     *
     */
    FailedRequest();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param status
     *          Status object.
     */
    FailedRequest(BinaryStatus status);

    /*!
     * Default destructor.
     *
     */
    ~FailedRequest();

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
   * Class FailedReply.
   *
   */
  class FailedReply : public BGMasterAgentReply
  {
  public:

    /*!
     * Default constructor.
     *
     */
    FailedReply();

    /*!
     * Attribute constructor. The copy constructors of all attributes are used to initialize the class attributes.
     *
     * @param rc
     *          Return error code.
     * @param rt
     *          Return error text.
     */
    FailedReply(const int rc, const std::string& rt);

    /*!
     * Default destructor.
     *
     */
    ~FailedReply();

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

}

#endif
