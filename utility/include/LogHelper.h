/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of Will Stockdell                  */
/*                                                                  */
/* DPM -- Distributed Process Manager                               */
/*                                                                  */
/* (C) Copyright Will Stockdell 2026                                */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL) version 1.0                         */
/*                                                                  */
/* ================================================================ */

#include <log4cxx/level.h>
#include <log4cxx/logger.h>
#include <log4cxx/spi/loggerrepository.h>

#ifndef LOG_HELPER_H
#define LOG_HELPER_H

template <typename T>
auto getRepository(T&& repository) {
    if constexpr (requires { repository.lock(); }) {
        return repository.lock();
    } else {
        return repository;
    }
}

#endif
