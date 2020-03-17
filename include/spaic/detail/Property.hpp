#pragma once

#include <optional>
#include <spaic/Property.hpp>

namespace spaic::props
{

template <typename T>
class Required : public Property<T, T>
{
public:
    AssignedProperty<T, T> operator=(T &&value) noexcept
    {
        return AssignedProperty(*this, value);
    };
};
template <typename T>
class Optional : public Property<T, std::optional<T>>
{
public:
    AssignedProperty<T, std::optional<T>> operator=(T &&value) noexcept
    {
        return AssignedProperty(*this, std::optional(value));
    };
};
template <typename T>
class Fallback : public Property<T, T>
{
private:
    T m_fallback_value;

public:
    template <typename U>
    Fallback(U &&fallback_value) : m_fallback_value(std::forward<U>(fallback_value))
    {
    }
    AssignedProperty<T, T> operator=(T &&value) noexcept
    {
        return AssignedProperty(*this, value);
    };
};

template <typename I, typename O>
template <typename U>
AssignedProperty<I, O>::AssignedProperty(Property<I, O> &target, U &&value) : target(target), value(std::forward<U>(value)) {}

template <typename T>
Property<T, T> required() noexcept
{
    return Required<T>();
}
template <typename T>
Property<T, std::optional<T>> optional() noexcept
{
    return Optional<T>();
}
template <typename T>
Property<T, T> fallback(T &&fallback_value) noexcept
{
    return Fallback<T>(std::forward<T>(fallback_value));
}
} // namespace spaic::props
