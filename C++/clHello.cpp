#include <iostream>

// Printing commandline args

int main(int argc, char* argv[])
{
    std::cout << "Hello,";

    if (argc < 2)
        std::cout << " you";
    else
    {
        for (int i{ 1 }; i < argc; ++i)
            std::cout << ' ' << argv[i];
    }

    std::cout << "!\n";

    return 0;
}
