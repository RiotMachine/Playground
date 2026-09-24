#include "DoubleLinkedList.h"
#include <iostream>

template <typename T>
void print(const DoubleLinkedList<T>& ll)
{
    std::cout << std::boolalpha
              << "Size: " << ll.size() << '\n'
              << "Empty: " << ll.empty() << '\n';
}

int main()
{
    DoubleLinkedList<int> ll{ };
    print(ll);

    ll.prepend(9);
    ll.postpend(10);

    print(ll);

    return 0;
}