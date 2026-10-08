#include "WordTrie.h"
#include <iostream>


int main()
{
    WordTrie t{ "cat", "car", "CART" };
    t.insert("dog");

    std::cout << std::boolalpha << "Inserted words: cat, car, CART, dog.\n"
              << "searchWord(\"car\")           = " << t.searchWord("car") << " (expect true)\n"
              << "searchWord(\"cart\")          = " << t.searchWord("cart") << " (expect true - case-agnostic storage/lookup)\n"
              << "searchWord(\"ca\")            = " << t.searchWord("ca") << " (expect false -- path exists, but not a stored word)\n"
              << "searchWord(\"carts\")         = " << t.searchWord("carts") << " (expect false -- no such path)\n"
              << "searchPrefix(\"ca\")          = " << t.searchPrefix("ca") << " (expect true)\n"
              << "countWordsWithPrefix(\"ca\")  = " << t.countWordsWithPrefix("ca") << " (expect 3)\n";

    WordTrie t2{};

    std::cout << "\nTesting empty Trie.\n"
              << "searchWord(\"car\")           = " << t2.searchWord("car") << " (expect false)\n"
              << "searchPrefix(\"ca\")          = " << t2.searchPrefix("ca") << " (expect false)\n"
              << "countWordsWithPrefix(\"ca\")  = " << t2.countWordsWithPrefix("ca") << " (expect 0)\n";

    return 0;
}