#pragma once

#include <spaic/Component.hpp>
#include <variant>
#include <string>
#include <vector>

namespace spaic::vnode
{
// TODO: Array of VNode should be VNode.
using VNodeBase = std::variant<
    spaic::comp::ComponentBody,
    spaic::comp::ComponentNode,
    std::string,
    std::nullptr_t,
    bool,
    short,
    unsigned short,
    int,
    unsigned int,
    long,
    unsigned long,
    long long,
    unsigned long long,
    char,
    signed char,
    unsigned char,
    wchar_t,
    char16_t,
    char32_t,
    float,
    double,
    long double>;

class VNode final
{
private:
    // I prefer `_value`
    // wtf is that noexcept(noexcept())
    std::variant<VNodeBase, std::vector<VNode>> _value;

public:
    template <typename T>
        requires std::is_convertible_v<std::remove_reference_t<T>, VNodeBase> ||
        std::is_convertible_v<std::remove_reference_t<T>, std::vector<VNode>>
        VNode(T &&v) noexcept(noexcept(std::is_constructible_v<decltype(_value), decltype(std::forward<T>(v))>))
        : _value(std::forward<T>(v)) {}
};
} // namespace spaic::vnode
