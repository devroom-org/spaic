#pragma once

#include <functional>

namespace spaic
{
using ShouldRender = bool;
template <typename State, typename Msg>
using Update = std::function(Msg)->ShouldRender;

template <typename Props, typename State>
class Component
{
};
template <typename Props, typename State>
Component<Props, State> create_component();
} // namespace spaic