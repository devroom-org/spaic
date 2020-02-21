#include <spaic/Property.hpp>

#include <optional>

namespace spaic::props
{
template <typename T>
class Required : Property<T, T>
{
public:
    AssignedProperty<T, T> operator=(T &&value) noexcept
    {
        return std::move(new AssignedProperty(&this, value));
    };
};
template <typename T>
class Optional : Property<T, std::optional<T>>
{
public:
    AssignedProperty<T, std::optional<T>> operator=(T &&value) noexcept
    {
        return std::move(new AssignedProperty(&this, std::optional(value)));
    };
};
template <typename T>
class Fallback : Property<T, T>
{
private:
    T &&m_fallback_value;

public:
    Fallback(T &&fallback_value) : m_fallback_value(fallback_value)
    {
    }
    AssignedProperty<T, T> operator=(T &&value) noexcept
    {
        return std::move(new AssignedProperty(&this, value));
    };
};
template <typename T>
Property<T, T> &&required() noexcept
{
    return std::move(Required<T>());
}
template <typename T>
Property<T, std::optional<T>> &&optional() noexcept
{
    return std::move(Optional<T>());
}
template <typename T>
Property<T, T> &&fallback(T &&fallback_value) noexcept
{
    return std::move(Fallback<T>(fallback_value));
}
} // namespace spaic::props
