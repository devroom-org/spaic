#pragma once

#include <functional>
#include <variant>
#include <spaic/VNode.hpp>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{
using ShouldRender = bool;
using Update = std::function<ShouldRender()>;
using Render = std::function<spaic::vnode::VNode()>;

class ComponentBody;
template <typename Props>
class Component
{
public:
    template <typename... T>
    ComponentBody operator()(T... args) noexcept;
};
class ComponentBody
{
public:
    spaic::vnode::VNode operator()(spaic::vnode::VNode children...) noexcept;
};
template <typename Props, typename StateSet>
Component<Props> create_component(Props props, StateSet state, Update update, Render render);
} // namespace spaic::comp