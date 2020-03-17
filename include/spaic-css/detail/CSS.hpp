#pragma once

#include <spaic-css/CSS.hpp>

namespace spaic::css
{
template <typename... T>
Stylesheet css(T&&... params)
{
    // TODO: css(params)
    return Stylesheet();
}
template<typename ...T>
Stylesheet keyframes(T&&... params)
{
    // TODO: keyframes(params)
    return Stylesheet();
}
} // namespace spaic::css
