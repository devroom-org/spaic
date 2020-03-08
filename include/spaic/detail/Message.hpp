#pragma once

#include <tuple>
#include <spaic/Message.hpp>

namespace spaic::msg
{

template <typename... T>
Message<T...>::operator bool()
{
    throw "TODO: Message::operator bool()";
}

template <typename... T>
template <size_t I>
typename std::tuple_element<I, std::tuple<T...>>::type Message<T...>::get()
{
    throw "TODO: Message::get<I>()";
}

} // namespace spaic::msg
