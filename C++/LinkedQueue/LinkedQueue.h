#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <memory>

template <typename T>
class LinkedQueue
{
public:
    struct Iterator;

    LinkedQueue(std::initializer_list<T> list)
      : m_size{ }, m_head{ }, m_tail{ }
    {
        for (const auto& e : list)
            enqueue(e);
    }

    LinkedQueue(const LinkedQueue&) = delete;

    ~LinkedQueue()
    {
        while (!this->empty())
            this->dequeue();
    }

    std::size_t size() const { return m_size; }
    bool empty() const       { return m_size == 0; }

    T& front() { return m_head->data; }
    const T& front() const { return m_head->data; }

    void enqueue(const T& val)
    {
        if (this->empty())
        {
            m_head = std::make_unique<Node>(Node { val, nullptr });
            m_tail = m_head.get();
        }
        else
        {
            m_tail->next = std::make_unique<Node>(Node { val, nullptr });
            m_tail = m_tail->next.get();
        }
        ++m_size;
    }

    void dequeue() 
    {
        m_head = std::move(m_head->next);
        --m_size;
    }

private:
    struct Node
    {
        T data{ };
        std::unique_ptr<Node> next{ };
    };

    std::size_t m_size{ };
    std::unique_ptr<Node> m_head{ };
    Node* m_tail{ };
};

#endif