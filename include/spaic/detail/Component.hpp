
#pragma once

#include <functional>
#include <variant>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{
template <typename... T>
ComponentNode ComponentBody::operator()(T... children) noexcept
{
    // TODO: ComponentBody::operator()(children)
    return ComponentNode();
}

template <typename Props>
Component<Props>::Component()
{
}
template <typename Props>
template <typename... T>
ComponentBody Component<Props>::operator()(T... args) noexcept
{
    // TODO: Component::operator()(args)
    return ComponentBody();
}
} // namespace spaic::comp
