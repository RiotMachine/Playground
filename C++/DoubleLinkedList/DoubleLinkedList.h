#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <initializer_list>
#include <memory>

/*
    
    Must assign std::shared_ptr another shared_ptr, not the object itself

*/

template <typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList(std::initializer_list<T> list)
      : m_size{ list.size() }, m_sentinel{ std::make_shared<Node>() }
    {
        m_sentinel->next = m_sentinel->prev = m_sentinel;
        for (const auto& e : list)
            postpend(e);
    }

    ~DoubleLinkedList()
    {
        while (m_sentinel->next != m_sentinel)
            remove(m_sentinel->next);
        m_sentinel = m_sentinel->next = m_sentinel->prev = nullptr;
    }

    std::size_t size() const   { return m_size; }
    bool empty() const { return m_size == 0; }

    //Node* begin() const { return m_sentinel.next.get(); }
    //Node* end() const   { return m_sentinel.prev.get(); }

    T& operator[](int i)
    {

    }

    const T& operator[](int i) const
    {

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

    int search(const T& val) const
    {
        return -1;
    }

    int remove(const T& val)
    {
        return -1;
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

#endif