#pragma once

#include <spaic-css/Unit.hpp>

namespace spaic::css::unit
{
    template <CssUnitType T>
    CssUnit<T>::CssUnit(long double value) noexcept : value(value) {}
} // namespace spaic::css::unit
