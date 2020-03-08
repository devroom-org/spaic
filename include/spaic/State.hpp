#pragma once

namespace spaic::state
{
template <typename T>
class State
{
public:
    State() {}

    T &operator*();
};
} // namespace spaic::state

#include <spaic/detail/State.hpp>