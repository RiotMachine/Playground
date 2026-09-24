#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <initializer_list>
#include <memory>

template <typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList(std::initializer_list<T> list)
      : m_size{ list.size() }
    {
        m_head.next = 
        m_size = list.size();
    }

    int size() const   { return m_size; }
    bool empty() const { return *m_head->next == m_tail; }

    pushFront(const T& val)
    {
        Node n{ m_sentinel.next, &m_sentinel, val };
        m_head.next = n;
    }

    pushBack
    {

    }

    remove
    {

    }

private:
    struct Node
    {
        std::unique_ptr<Node> next{ };
        std::unique_ptr<Node> prev{ };
        T data{ };
    };

    struct Sentinel
    {
        std::shared_ptr
    }

    int m_size{ };
    Node m_head{ };
    Node m_tail{ };
};

#endif