#include <string>
#include <spaic-dom/Render.hpp>
#include <spaic/VNode.hpp>
#include <type_traits>
#include <variant>
#include <sstream>
#include <vector>

namespace spaic::dom
{
template <class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

std::string render_base(const spaic::vnode::VNodeBase &node)
{
    std::ostringstream stream;
    std::visit(
        overloaded{
            [&](std::nullptr_t) {
                // do nothing, nullptr means empty string.
            },
            [&](const std::string &arg) { stream << arg; },
            [&](const char *arg) { stream << arg; },
            [&](const spaic::comp::ComponentParent &arg) {
                if (arg.native_node_name)
                {
                    stream << "<" << *arg.native_node_name << ">\n";
                }
                for (const auto &child : arg.children)
                {
                    stream << render(child) << "\n";
                }
                if (arg.native_node_name)
                {
                    stream << "</" << *arg.native_node_name << ">\n";
                }
            },
            [&](const spaic::comp::ComponentSingle &arg) { stream << typeid(std::decay_t<decltype(arg)>).name() << "(ComponentSingle)"; },
            [&](const auto &arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, bool>)
                {
                    stream << std::boolalpha << arg << std::noboolalpha;
                }
                else if constexpr (std::is_fundamental_v<T>)
                {
                    stream << arg;
                }
                else
                {
                    stream << "비야네 당신은 틀렸어!" << typeid(T).name();
                }
            },
        },
        node);
    return stream.str();
}
std::string render(const spaic::vnode::VNode &node)
{
    std::ostringstream stream;
    std::visit(
        [&](const auto &arg) {
            // wtf is that fucking bitches
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::vector<spaic::vnode::VNode>>)
            {
                for (const auto &element : arg)
                {
                    stream << render(element);
                }
            }
            else if constexpr (std::is_same_v<T, spaic::vnode::VNodeBase>)
            {
                stream << render_base(arg);
            }
            else
            {
                stream << "wtf is that you should report this: " << typeid(T).name();
            }
        },
        node.value);
    return stream.str();
}
} // namespace spaic::dom