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
