#pragma once

#include <string>
#include <spaic/VNode.hpp>

namespace spaic::dom
{
std::string render(const spaic::vnode::VNode &node);
}