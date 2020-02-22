#pragma once

namespace spaic::msg
{
template <typename... T>
class Message
{
public:
    Message() {}

    operator bool();

    template <size_t I>
    std::tuple_element<I, T...> get();
};

} // namespace spaic::msg