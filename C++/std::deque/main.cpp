#include <iostream>
#include <stack>
#include <queue>

int main()
{
    std::stack<char> s{};
    std::queue<char> q{};
    char c{ 'a' };
    while (c <= 'z')
    {
        s.push(c);
        q.push(c);
        ++c;
    }

    std::cout << "Printing stack: \n";
    while (!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }

    std::cout << "\nPrinting queue: \n";
    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }

    std::cout << '\n';
    return 0;
}
