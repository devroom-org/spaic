
#pragma once

#include <functional>
#include <variant>
#include <spaic/VNode.hpp>
#include <spaic/Component.hpp>
#include <spaic/Property.hpp>
#include <spaic/State.hpp>

namespace spaic::comp
{
template <typename Props, typename StateSet>
Component<Props> create_component(Props &&props, StateSet &&state, const Update &update, const Render &render)
{
    // TODO: create_component(props, state, update, render)
    return Component<Props>(std::nullopt);
}
} // namespace spaic::comp
