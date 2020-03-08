#pragma once

#include <optional>

namespace spaic::props
{

template <typename I, typename O>
class AssignedProperty;

template <typename I, typename O>
class Property
{

public:
    virtual AssignedProperty<I, O> operator=(I &&value) noexcept {};
};

template <typename I, typename O>
class AssignedProperty
{
private:
    Property<I, O> &target;
    O value;

public:
    template <typename U>
    AssignedProperty(Property<I, O> &target, U &&value);
};
template <typename T>
Property<T, T> required() noexcept;
template <typename T>
Property<T, std::optional<T>> optional() noexcept;
template <typename T>
Property<T, T> fallback(T &&fallback_value) noexcept;
} // namespace spaic::props

#include <spaic/detail/Property.hpp>