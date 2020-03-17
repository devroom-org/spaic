#pragma once

#include <spaic-css/CssProperty.hpp>

namespace spaic::css::prop
{
template <typename T>
template <typename U>
AssignedCssProperty<T> CssProperty<T>::operator=(U&& value)
{
    return AssignedCssProperty<T>();
}
} // namespace spaic::css::prop