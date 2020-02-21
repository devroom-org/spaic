#pragma once

#include <spaic-css/Stylesheet.hpp>

namespace spaic
{
template <typename... T>
spaic::css::Stylesheet css(T... params);
}