#pragma once

namespace spaic::state
{
template <typename T>
class State
{
public:
    State() {}

    // todo:
    T &operator*();
};
} // namespace spaic::state
