#pragma once

#include <spaic-css/CssProperty.hpp>

namespace spaic::css::prop
{

template <typename T>
AssignedCssProperty<T> CssProperty<T>::operator=(T value)
{
    return AssignedCssProperty<T>();
}

} // namespace spaic::css::prop