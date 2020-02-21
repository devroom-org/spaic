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
    virtual AssignedProperty<I, O> operator=(I &&value) noexcept;
};

template <typename I, typename O>
class AssignedProperty
{
private:
    Property<I, O> &target;
    O value;

    AssignedProperty(Property<I, O> &target, O &&value);
};
template <typename T>
Property<T, T> &&required() noexcept;

template <typename T>
Property<T, std::optional<T>> &&optional() noexcept;

template <typename T>
Property<T, T> &&fallback(T &&value) noexcept;
} // namespace spaic::props
