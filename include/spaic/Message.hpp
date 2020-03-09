#pragma once

#include <tuple>

namespace spaic::msg
{
template <typename... T>
class Message
{
public:
    Message() {}

    operator bool();

    template <size_t I>
    std::tuple_element_t<I, std::tuple<T...>> get();
};

} // namespace spaic::msg

#include <spaic/detail/Message.hpp>