#include <cstdlib>
#include <iostream>

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

int main()
{
    std::cout << "안녕 세계는 개뿔이" << std::endl;
    try
    {
        using namespace props::counter;
        auto wtf_is_this_style = css(
            width = 10.0_px);
        auto counter = create_component(props::counter::all, state::counter::all, update, render);

        counter(is_dark_theme = true)("Hello, world!");
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return EXIT_SUCCESS;
}

// fucking test
void test(VNode node) {}

struct Incompatible
{
    int i;
};

void test()
{
    using namespace props::counter;
    test("STR");
    test(true);
    std::vector<VNode> wtf;
    wtf.push_back("STR");
    test(wtf);
    // test(Incompatible{3});
}