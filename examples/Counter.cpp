#include <cstdlib>

#include <spaic/Prelude.hpp>
#include <spaic-css/Prelude.hpp>

namespace props::counter
{
auto is_dark_theme = fallback<bool>(false);

auto all = is_dark_theme;
} // namespace props::counter
namespace state::counter
{
State<int> count;

auto all = count;
} // namespace state::counter
namespace msg
{
Message<int> increment;
Message<int> decrement;
} // namespace msg

ShouldRender update()
{
    using namespace state::counter;
    using namespace msg;
    if (increment)
    {
        *count += increment.get<0>();
        return true;
    }
    if (decrement)
    {
        *count -= decrement.get<0>();
    }
    return true;
}

VNode render()
{
    return 0;
}

auto counter = create_component(props::counter::all, state::counter::all, update, render);

int main()
{
    using namespace props::counter;
    auto wtf_is_this_style = css(
        width = 10.0_px);
    counter(is_dark_theme = true)("Hello, world!");
    return EXIT_SUCCESS;
}
