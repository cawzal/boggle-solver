#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Trie.h"

struct BoardNode {
    char character;
    bool visited = false;
    std::vector<BoardNode*> neighbours;
};

class Board {
private:
    int size;
    Trie* trie;
    std::vector<BoardNode*> nodes;
public:
    Board(std::string str);
    void find(Trie* trie, std::set<std::string>& words);
private:
    void generate(std::string str);
    void search(Trie* trie, std::string str, BoardNode* node, std::set<std::string>& words);
};

#endif