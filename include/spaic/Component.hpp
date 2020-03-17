#pragma once

#include <functional>
#include <variant>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::vnode
{
class VNode;
}

namespace spaic::comp
{
using NativeNodeName = std::optional<const char *>;

class ComponentParent
{
public:
    const NativeNodeName native_node_name;
    const std::vector<spaic::vnode::VNode> children;

    ComponentParent(NativeNodeName native_node_name, std::vector<spaic::vnode::VNode> &&children);
};
class ComponentSingle
{
public:
    const NativeNodeName native_node_name;

    ComponentSingle(NativeNodeName native_node_name);

    template <typename... T>
    ComponentParent operator()(T&&... children) noexcept;
};
template <typename Props>
class Component
{
public:
    const NativeNodeName native_node_name;

    Component(NativeNodeName native_node_name);
    template <typename... T>
    ComponentSingle operator()(T&&... args) noexcept;
};
} // namespace spaic::comp

#include <spaic/detail/Component.hpp>