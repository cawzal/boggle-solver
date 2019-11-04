#include <iostream>
#include <string>

#include "Trie.h"

Trie::Trie() {
    this->root = new TrieNode();
}

void Trie::insert(std::string str) {
    TrieNode* node = this->root;
    for (unsigned int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->terminator = true;
}

bool Trie::prefix(std::string str) {
    TrieNode* node = this->root;
    for (unsigned int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return true;
}

bool Trie::contains(std::string str) {
    TrieNode* node = this->root;
    for (unsigned int i = 0; i < str.length(); i++) {
        int index = str[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }
    return node->terminator;
}