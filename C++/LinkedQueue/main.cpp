#include "LinkedQueue.h"
#include <iostream>

int main()
{
    LinkedQueue lq{1, 2, 3};
    while (!lq.empty())
        lq.dequeue();
    lq.enqueue(7);
    std::cout << "Front: " << lq.front() << "\nSize: "
              << lq.size() << '\n';

    return 0;
}