int main
{
    std::list l{ 2, 3, 10, 4};

    l.push_back(1);
    l.pop_front();

    l.sort();
    l.reverse();

    l.merge( {6, 7, 8, 77} );

    l.resize(2, 81);

    l.max_size();

    l.resize(l.size() + 2, 100);

    l.sort(
        [] (const int& a, const int& b,) { return a % 2 == 0; };
    );

    return 0;
}
