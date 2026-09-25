#include "DoubleLinkedList.h"
#include <algorithm>
#include <iostream>

// Only wrote non-const iterator, so passing LinkedList as non-const
template <typename T>
void print(DoubleLinkedList<T>& ll)
{
    std::cout << std::boolalpha << "Size: " << ll.size()
              << "\nEmpty: " << ll.empty() << "\nContents: ";
    for (const auto& e : ll)
        std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    DoubleLinkedList ll{ 2, 3, 4, 5 };
    ll.postpend(6);
    print(ll);
    std::cout << '\n';

    ll[0] = 1;
    ll[3] = 6;
    ll.remove(
        std::find(ll.begin(), ll.end(), 3)
    );
    print(ll);

    return 0;
}