#pragma once

#include <spaic-css/Stylesheet.hpp>

namespace spaic::css
{
template <typename... T>
Stylesheet css(T... params);
template <typename... T>
Stylesheet keyframes(T... params);
} // namespace spaic::css

#include <spaic-css/detail/CSS.hpp>