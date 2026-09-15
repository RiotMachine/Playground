#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

/*
    Dynamic array
      - expands by factor of 2
      - length tracks number of items
      - capacity tracks allocated memory
*/

template <typename T>
class DynamicArray
{
public:
    DynamicArray() = default;

    explicit DynamicArray(std::size_t capacity)
      : m_capacity{ capacity }, m_data{ std::make_unique<T[]>(capacity) } {}

    DynamicArray(const DynamicArray& arr)
      : DynamicArray(arr.m_length)
    {
        m_length = arr.m_length;
        std::copy_n(arr.m_data.get(), arr.m_length, m_data.get());
    }

    ~DynamicArray() = default;

    DynamicArray& operator=(const DynamicArray& arr)
    {
        if (&arr == this)
            return *this;
        reallocate(arr.m_length);
        std::copy_n(arr.m_data.get(), arr.m_length, m_data.get());
        return *this;
    }

    T& operator[](std::size_t index)
    {
        assert(index < m_length);
        return m_data[index]; 
    }
    const T& operator[](std::size_t index) const
    {
        assert(index < m_length);
        return m_data[index]; 
    }

    std::size_t size() const     { return m_length; }
    std::size_t capacity() const { return m_capacity; }

    void push_back(const T& value)
    {
        if (m_length == m_capacity)
            grow();
        m_data[m_length] = value;
        ++m_length;
    }


private:
    void reallocate(std::size_t newLength)
    {
        m_length   = newLength;
        m_capacity = newLength;
        m_data     = std::make_unique<T[]>(newLength);
    }

    void grow()
    {
        constexpr int growthFactor{ 2 };
        if (!m_capacity)
            m_capacity = 1;
        else
            m_capacity *= growthFactor;

        auto newData{ std::make_unique<T[]>(m_capacity) };
        std::copy_n(m_data.get(), m_length, newData.get());
        m_data = std::move(newData);
    }

    std::size_t m_length{ };
    std::size_t m_capacity{ };
    std::unique_ptr<T[]> m_data{ };
};

#endif