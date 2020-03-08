#pragma once

#include <functional>
#include <variant>
#include <spaic/VNode.hpp>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{
spaic::vnode::VNode ComponentBody::operator()(spaic::vnode::VNode children...) noexcept
{
    throw "TODO: ComponentBody::operator()(children)";
}

template <typename Props>
template <typename... T>
ComponentBody Component<Props>::operator()(T... args) noexcept
{
    throw "TODO: Component::operator()(args)";
}
template <typename Props, typename StateSet>
Component<Props> create_component(Props props, StateSet state, Update update, Render render)
{
    throw "TODO: create_component(props, state, update, render)";
}
} // namespace spaic::comp
