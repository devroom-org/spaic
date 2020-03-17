
#pragma once

#include <functional>
#include <variant>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{
template <typename... T>
ComponentParent ComponentSingle::operator()(T&&... children) noexcept
{
    // TODO: ComponentSingle::operator()(children)
    return ComponentParent(native_node_name, { std::forward<T>(children)... });
}

template <typename Props>
Component<Props>::Component(NativeNodeName native_node_name) : native_node_name(native_node_name) {}

template <typename Props>
template <typename... T>
ComponentSingle Component<Props>::operator()(T&&... args) noexcept
{
    // TODO: Component::operator()(args)
    return ComponentSingle(native_node_name);
}
} // namespace spaic::comp
