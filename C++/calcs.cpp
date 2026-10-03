#include <iostream>

int factorial(int index, int value=1)
{
    if (index == 0 || index == 1)
        return value;
    return factorial(index-1, value*index);
}

int fibonacci(int element)
{
    if (element < 0)
        return -1;
    else if (element == 0)
        return 0;

    int twoBack{ 0 };
    int oneBack{ 1 };

    for (int i{ 2 }; i < element; ++i)
    {
        int currElement{ oneBack + twoBack };
        twoBack = oneBack;
        oneBack = currElement;
    }

    return oneBack + twoBack;
}

int main()
{
    constexpr int top{ 10 };
    for (int i{ }; i < top; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';

    return 0;
}
