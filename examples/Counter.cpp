#include <cstdlib>

#include <spaic/Prelude.hpp>

namespace props::counter
{
auto is_dark_theme = fallback<bool>(false);
}
class Counter
{
private:
    bool test;

public:
    template <typename... T>
    Counter(T... values)
    {
    }
};

int main()
{
    using namespace props::counter;
    // new Counter(is_dark_theme = true);
    // Counter{is_dark_theme = true};
    // Counter(is_dark_theme = true);
    return EXIT_SUCCESS;
}
