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
    Board(std::string chars, Trie* trie);
    std::set<std::string> find();
private:
    void generate(std::string chars);
    void search(std::string str, BoardNode* node, std::set<std::string>& found);
};

#endif