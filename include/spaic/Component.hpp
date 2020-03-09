#pragma once

#include <functional>
#include <variant>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{

class ComponentNode
{
};
class ComponentBody
{
public:
    template <typename... T>
    ComponentNode operator()(T... children) noexcept;
};
template <typename Props>
class Component
{
public:
    Component();
    template <typename... T>
    ComponentBody operator()(T... args) noexcept;
};
} // namespace spaic::comp

#include <spaic/detail/Component.hpp>