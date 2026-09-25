#include "DoubleLinkedList.h"
#include <iostream>

template <typename T>
void print(DoubleLinkedList<T>& ll)
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
    DoubleLinkedList ll{ 2, 3, 4 };
    print(ll);
    std::cout << '\n';

    ll.remove(1);
    print(ll);

    return 0;
}