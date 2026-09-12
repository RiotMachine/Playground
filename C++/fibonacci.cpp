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


int main()
{
    constexpr int terms{ 20 };
    for (int i{ 0 }; i < terms; ++i)
        std::cout << 'F' << i << " = " << fibonacci(i) << '\n';

    return 0;
}
