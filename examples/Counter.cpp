#include <cstdlib>
#include <iostream>
#include <string>

#include <spaic/Prelude.hpp>
#include <spaic-css/Prelude.hpp>
#include <spaic-dom/Render.hpp>

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

    auto node = counter(is_dark_theme = true)("Hello, world!", 1, 2.0);
    std::string test = "12345678";
    std::vector<VNode> test2;
    test2.push_back("1");
    test2.push_back(2);
    test2.push_back(3.0);

    std::cout << spaic::dom::render(node) << std::endl;
    std::cout << spaic::dom::render(nullptr) << std::endl;
    std::cout << spaic::dom::render(NULL) << std::endl;
    std::cout << spaic::dom::render(123456) << std::endl;
    std::cout << spaic::dom::render(123.456) << std::endl;
    std::cout << spaic::dom::render(true) << std::endl;
    std::cout << spaic::dom::render(false) << std::endl;
    std::cout << spaic::dom::render("WAAAY") << std::endl;
    std::cout << spaic::dom::render(test2) << std::endl;

    return EXIT_SUCCESS;
}
