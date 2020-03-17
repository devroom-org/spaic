#include <spaic/Component.hpp>
#include <spaic/VNode.hpp>

namespace spaic::comp
{
ComponentSingle::ComponentSingle(NativeNodeName native_node_name) : native_node_name(native_node_name) {}

ComponentParent::ComponentParent(NativeNodeName native_node_name, std::vector<spaic::vnode::VNode> children) : native_node_name(native_node_name), children(children) {}
} // namespace spaic::comp