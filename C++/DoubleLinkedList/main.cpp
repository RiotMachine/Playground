#include "DoubleLinkedList.h"
#include <iostream>

template <typename T>
void print( DoubleLinkedList<T>& ll)
{
    std::cout << std::boolalpha
              << "Size: " << ll.size() << '\n'
              << "Empty: " << ll.empty() << '\n'
              << "Contents: ";
    for (const auto& e : ll)
        std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    DoubleLinkedList<int> ll{ };
    print(ll);

    ll.prepend(9);
    ll.postpend(10);

    print(ll);

    ll[1] = 22;
    print(ll);

    return 0;
}