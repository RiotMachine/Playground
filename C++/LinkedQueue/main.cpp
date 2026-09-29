#include "LinkedQueue.h"
#include <iostream>

int main()
{
    LinkedQueue lq{1, 2, 3};
    lq.dequeue();
    lq.enqueue(7);
    lq.front() = 9;
    while (!lq.empty())
    {
        std::cout << lq.front() << '\n';
        lq.dequeue();
    }

    return 0;
}