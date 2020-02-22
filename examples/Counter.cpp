#include <cstdlib>

#include <spaic/Prelude.hpp>

namespace props::counter
{
auto is_dark_theme = fallback<bool>(false);
}
namespace state::counter
{
State<int> count;
}
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
        count += increment.get<0>();
        return true;
    }
    if (decrement)
    {
        count -= decrement.get<0>();
    }
    return true;
}

int main()
{
    using namespace props::counter;
    // new Counter(is_dark_theme = true);
    // Counter{is_dark_theme = true};
    // Counter(is_dark_theme = true);
    return EXIT_SUCCESS;
}
