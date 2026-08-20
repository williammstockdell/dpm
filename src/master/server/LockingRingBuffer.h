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

#ifndef MASTER_LOCKING_RING_BUFFER_H_
#define MASTER_LOCKING_RING_BUFFER_H_

#include <algorithm>
#include <deque>
#include <iterator>
#include <mutex>
#include <string>
#include <vector>

//! \brief Fixed-size locking ring buffer specialized for strings.
class LockingStringRingBuffer {
    std::deque<std::string> _ring_buff;
    std::size_t _capacity;
    std::mutex _mutex;

  public:
    explicit LockingStringRingBuffer(unsigned buffsize) : _capacity(buffsize) {}

    void push_back(const std::string& item) {
        std::lock_guard scoped_lock(_mutex);

        if (_ring_buff.size() == _capacity) {
            _ring_buff.pop_front();
        }

        _ring_buff.push_back(item);
    }

    //! \brief Get the contents of the ring buffer in a string vector.
    //! \param messages The string vector to fill.
    void getContents(std::vector<std::string>& messages) {
        std::lock_guard scoped_lock(_mutex);

        std::copy(_ring_buff.begin(), _ring_buff.end(), std::back_inserter(messages));
    }
};

#endif
