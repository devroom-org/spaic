#pragma once

#include <variant>
#include <string>
#include <vector>

namespace spaic::vnode
{
using VNode = std::variant<
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
} // namespace spaic::vnode