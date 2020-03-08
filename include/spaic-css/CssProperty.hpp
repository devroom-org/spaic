#pragma once

namespace spaic::css::prop
{
template <typename T>
class AssignedCssProperty
{
};

template <typename T>
class CssProperty
{
public:
    AssignedCssProperty<T> operator=(T value);
};
} // namespace spaic::css::prop

#include <spaic-css/detail/CssProperty.hpp>