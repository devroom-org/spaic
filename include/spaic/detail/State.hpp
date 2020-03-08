#pragma once

#include <spaic/State.hpp>

namespace spaic::state
{

template <typename T>
T &State<T>::operator*()
{
    throw "TODO: State::operator*()";
}

} // namespace spaic::state
