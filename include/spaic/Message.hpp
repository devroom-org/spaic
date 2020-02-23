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
    typename std::tuple_element<I, std::tuple<T...>>::type get();
};

} // namespace spaic::msg