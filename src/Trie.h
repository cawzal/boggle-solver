#ifndef TRIE_H
#define TRIE_H

#include <string>

struct TrieNode {
    TrieNode* children[26]{};
    bool terminator = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie();
    void insert(std::string str);
    bool prefix(std::string str);
    bool contains(std::string str);
};

#endif
