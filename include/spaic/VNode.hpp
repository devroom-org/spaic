#pragma once

#include <spaic/Component.hpp>
#include <variant>
#include <string>
#include <vector>

namespace spaic::vnode
{
using VNodeBase = std::variant<
    spaic::comp::ComponentSingle,
    spaic::comp::ComponentParent,
    std::string,
    const char *,
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
public:
    const std::variant<VNodeBase, std::vector<VNode>> value;

    template <typename T>
        requires std::is_convertible_v<std::remove_reference_t<T>, VNodeBase> ||
        std::is_convertible_v<std::remove_reference_t<T>, std::vector<VNode>>
        VNode(T &&v) noexcept(noexcept(std::is_constructible_v<decltype(value), decltype(std::forward<T>(v))>))
        : value(std::forward<T>(v)) {}
};
} // namespace spaic::vnode
