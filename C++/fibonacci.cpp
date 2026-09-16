#include <iostream>

int fibonacci(int element)
{
    if (element < 0)
        return -1;
    else if (element == 0)
        return 0;
    else if (element == 1 || element == 2)
        return 1;
    else
        return fibonacci(element-1) + fibonacci(element-2);
}

int fibonacciIt(int element)
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
    constexpr int terms{ 20 };
    for (int i{ 0 }; i < terms; ++i)
        std::cout << "Recursive F" << i << " = " << fibonacci(i) << '\n';
    for (int i{ 0 }; i < terms; ++i)
        std::cout << "Iterative F" << i << " = " << fibonacciIt(i) << '\n';

    return 0;
}
