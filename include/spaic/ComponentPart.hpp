#pragma once

#include <functional>
#include <spaic/VNode.hpp>

namespace spaic::comp
{
using ShouldRender = bool;
using Update = std::function<ShouldRender()>;
using Render = std::function<spaic::vnode::VNode()>;

template <typename Props, typename StateSet>
Component<Props> create_component(Props &&props, StateSet &&state, const Update &update, const Render &render);
} // namespace spaic::comp

#include <spaic/detail/ComponentPart.hpp>