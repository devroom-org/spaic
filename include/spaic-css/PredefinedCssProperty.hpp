#pragma once

#include <spaic-css/CssProperty.hpp>
#include <spaic-css/Unit.hpp>

namespace spaic::css::prop
{
using namespace spaic::css::unit;
// TODO: Strong type check, can we use Length type?
CssProperty<CssUnit<CssUnitType::px>> width;
} // namespace spaic::css::prop