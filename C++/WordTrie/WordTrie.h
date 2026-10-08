#ifndef WORDTRIE_H
#define WORDTRIE_H

#include <array>
#include <cassert>
#include <cctype>
#include <initializer_list>
#include <memory>
#include <string>

/*
Trie
  Position, not stored data, determines a node's meaning
  Root represents null value
  Location of node in parent stores node's value
  Sequence of nodes stores sequence of underlying data
*/

namespace Alphabet
{
    static constexpr int size{ 'z'-'a' + 1 };

    inline char lowerCase(char letter)
    {
        return static_cast<char>(
            std::tolower(static_cast<unsigned char>(letter))
        );
    }

    inline int indexify(char letter)
    {
        assert(letter >= 'A' && letter <= 'z');
        return lowerCase(letter) - 'a';
    }
}

class WordTrie
{
public:
    explicit WordTrie() = default;
    WordTrie(std::initializer_list<std::string> list)
    {
        for (const auto& word : list)
            insert(word);
    }

    WordTrie(const WordTrie&) = delete;
    ~WordTrie() = default;

    void insert(const std::string& word)
    {
        Node* node{ &m_root };
        for (const char ch : word)
        {
            const int letter{ Alphabet::indexify(ch) };
            if (!node->next[letter])
                node->next[letter] = std::make_unique<Node>();
            node = node->next[letter].get();
        }
        node->endsWord = true;
    }

    bool searchPrefix(const std::string& prefix) const
    {
        return findTerminalNode(prefix);
    }

    bool searchWord(const std::string& word) const
    {
        const Node* node{ findTerminalNode(word) };
        return node && node->endsWord;
    }
    
    int countWordsWithPrefix(const std::string& prefix) const
    {
        const Node* node{ findTerminalNode(prefix) };
        return (node ? countDerivedWords(node) : 0);
    }

private:
    struct Node
    {
        using Letters = std::array<std::unique_ptr<Node>, Alphabet::size>;

        Letters next{ };
        bool endsWord{ };
    };

    const Node* findTerminalNode(const std::string& str) const
    {
        const Node* node{ &m_root };
        for (const char ch : str)
        {
            const int letter{ Alphabet::indexify(ch) };
            if (!node->next[letter])
                return nullptr;
            node = node->next[letter].get();
        }
        return node;
    }

    int countDerivedWords(const Node* node) const
    {
        int count{ node->endsWord ? 1 : 0 };
        for (const auto& child : node->next)
        {
            if (child)
                count += countDerivedWords(child.get());
        }
        return count;
    }

    Node m_root{ };
};

#endif