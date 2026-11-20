#include <iostream>
#include <list>
#include <vector>

template <typename Container>
void print(const Container& c)
{
    std::cout << "{ ";
    for (const auto& e : c)
        std::cout << e << ' ';
    std::cout << "}\n";
}

int main()
{
    std::vector v{ 10, 20, 30 };
    print(v);

    std::list l{ 2, 3, 10, 4 };

    l.push_back(1);
    l.pop_front();
    l.insert(
        std::next(l.begin(), 3), 81
    );
    l.resize(l.size() + 2, 100);
    print(l);

    l.sort(
        [] (const int& a, const int& b) {
            if (a % 2 == b % 2)
                return a < b;
            return a % 2 == 0;
        }
    );
    l.merge( std::list (v.begin(), v.end()) );
    l.unique();
    print(l);

    l.remove_if( [] (const int& a) { return a % 2 == 0; } );
    print(l);

    return 0;
}
