#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>

/*
  Notes:
    Design Choices
      Wanted to encapsulate Node and pointers to Nodes
      Iterator stores a pointer to a Node but provides Node's data

    Smart Ptr
      Copy assign std::shared_ptr another shared_ptr, not the object itself
      Should not point smart ptrs to items on the stack

    Iterators
      https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
      https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
*/

template <typename T>
class DoubleLinkedList
{
public:
    struct Iterator;

    DoubleLinkedList(std::initializer_list<T> list)
      : m_size{ list.size() }, m_sentinel{ std::make_shared<Node>() }
    {
        m_sentinel->next = m_sentinel->prev = m_sentinel;
        for (const auto& e : list)
            postpend(e);
    }

    DoubleLinkedList(const DoubleLinkedList&) = delete;

    ~DoubleLinkedList()
    {
        while (m_sentinel->next != m_sentinel)
            remove(m_sentinel->next);
        m_sentinel = m_sentinel->next = m_sentinel->prev = nullptr;
    }

    Iterator begin() { return m_sentinel->next; }
    Iterator end()   { return m_sentinel; }

    std::size_t size() const { return m_size; }
    bool empty() const       { return m_size == 0; }

    T& operator[](std::size_t index)
    {
        assert(index < m_size);
        auto it{ this->begin() };
        for (std::size_t i{ }; i < index; ++i)
            ++it;
        return *it;
    }

    const T& operator[](std::size_t index) const
    {
        assert(index < m_size);
        auto it{ this->begin() };
        for (std::size_t i{ }; i < index; ++i)
            ++it;
        return *it;
    }

    void prepend(const T& val)
    {
        auto n{ std::make_shared<Node>(
            Node { m_sentinel->next, m_sentinel->next->prev, val }
        )};
        m_sentinel->next->prev = n;
        m_sentinel->next = n;
        ++m_size;
    }

    void postpend(const T& val)
    {
        auto n{ std::make_shared<Node>(
            Node { m_sentinel->prev->next, m_sentinel->prev, val }
        )};
        m_sentinel->prev->next = n;
        m_sentinel->prev = n;
        ++m_size;
    }

    std::size_t search(const T& val)
    {        
        for (std::size_t i{ }; i < m_size; ++i)
        {
            if (*this[i] == val)
                return i;
        }
        return m_size;
    }

    int remove(std::size_t index)
    {
        assert(index < m_size);
        auto it{ this->begin() };
        for (std::size_t i{ }; i < index; ++i)
            ++it;
        remove(it.m_ptr.lock());
    }

private:
    struct Node
    {
        std::shared_ptr<Node> next{ };
        std::shared_ptr<Node> prev{ };
        T data{ };
    };

    void remove(std::shared_ptr<Node> n)
    {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        --m_size;
    }

    std::size_t m_size{ };
    std::shared_ptr<Node> m_sentinel{ };
};

template <typename T>
struct DoubleLinkedList<T>::Iterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;

    Iterator(std::shared_ptr<Node> ptr)
      : m_ptr(ptr) {}

    reference operator*() { return m_ptr.lock()->data; }
    pointer operator->()  { return &(m_ptr.lock()->data); }
    Iterator& operator++() {
        m_ptr = m_ptr.lock()->next;
        return *this;
    }
    Iterator operator++(int) {
        Iterator tmp{ *this };
        ++(*this);
        return tmp;
    }
    Iterator& operator--() {
        m_ptr = m_ptr.lock()->next;
        return *this;
    }
    Iterator operator--(int) {
        Iterator tmp{ *this };
        --(*this);
        return tmp;
    }
    friend bool operator==(const Iterator& a, const Iterator& b) {
        return a.m_ptr.lock() == b.m_ptr.lock(); 
    }
    friend bool operator!=(const Iterator& a, const Iterator& b) {
        return a.m_ptr.lock() != b.m_ptr.lock();
    }

private:
    std::weak_ptr<Node> m_ptr;
};

#endif