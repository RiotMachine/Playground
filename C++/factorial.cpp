#include <iostream>

int factorial(int start)
{
    if (start < 0)
        return 0;
    // 0! == 1
    else if (start < 2)
        return 1;
    else
        return start * factorial(start-1);
}

int main()
{
    constexpr int top{ 10 };
    for (int i{ }; i < top; ++i)
        std::cout << i << "! = " << factorial(i) << '\n';

    return 0;
}
