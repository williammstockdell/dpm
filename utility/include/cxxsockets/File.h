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
/*!
 * \file include/cxxsockets/File.h
 */

#ifndef CXXSOCKET_FILE_H
#define CXXSOCKET_FILE_H

#include <memory>

#include <utility/include/pthreadmutex.h>

#include <utility/include/cxxsockets/types.h>

namespace CxxSockets {

class File {
  private:
    mutable PthreadMutex _fileLock;

  protected:
    int _fileDescriptor;
    std::unique_ptr<PthreadMutex> _receiver;
    std::unique_ptr<PthreadMutex> _sender;

    //! \brief Mutual exclusion for all operations on this file.
    void LockFile(FileLocker& locker) const;

    //! \brief Lock send side only
    [[nodiscard]] int LockSend(PthreadMutexHolder& mutex);

    //! \brief Lock receive side only
    [[nodiscard]] int LockReceive(PthreadMutexHolder& mutex);

    File();

    //! \brief Close the file
    int Close();

  public:
    int getFileDescriptor() const { return _fileDescriptor; }

    virtual ~File() = 0;
};

} // namespace CxxSockets

#endif
