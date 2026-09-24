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
      : m_size{ list.size() }
    {
        for (const auto& e : list)
            postpend(e);
    }

    int size() const   { return m_size; }
    bool empty() const { return m_size == 0; }

    //Node* begin() const { return m_sentinel.next.get(); }
    //Node* end() const   { return m_sentinel.prev.get(); }

    void prepend(const T& val)
    {
        auto n{ 
            std::make_shared<Node>(m_sentinel.next, m_sentinel.next->prev, val)
        };
        m_sentinel.next->prev = n;
        m_sentinel.next = n;
    }

    void postpend(const T& val)
    {
        auto n{
            std::make_shared<Node>(m_sentinel.prev->next, m_sentinel.prev, val)
        };
        m_sentinel.prev->next = n;
        m_sentinel.prev = n;
    }

    remove(const T& val)
    {
        
    }

private:
    struct Node
    {
        std::shared_ptr<Node> next{ };
        std::shared_ptr<Node> prev{ };
        T data{ };
    };

    int m_size{ };
    Node m_sentinel{ };
};

#endif