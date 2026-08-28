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

#pragma once

#include <utility>

template <typename F> class ScopeExit {
  public:
    explicit ScopeExit(F&& f) : _f(std::forward<F>(f)) {}

    ScopeExit(const ScopeExit&) = delete;
    ScopeExit& operator=(const ScopeExit&) = delete;

    ScopeExit(ScopeExit&& other) noexcept : _f(std::move(other._f)), _active(other._active) { other._active = false; }

    ~ScopeExit() noexcept {
        if (_active) {
            _f();
        }
    }

  private:
    F _f;
    bool _active{true};
};

template <typename F> ScopeExit(F) -> ScopeExit<F>;
