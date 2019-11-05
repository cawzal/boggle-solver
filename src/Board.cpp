#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Board.h"

Board::Board(std::string chars, Trie* trie) {
    this->size = std::sqrt(chars.length());
    this->trie = trie;
    this->generate(chars);
}

std::set<std::string> Board::find() {
    std::set<std::string> found;
    std::string empty = "";
    for (BoardNode* root : this->nodes) {
        root->visited = true;
        search(empty + root->character, root, found);
        root->visited = false;
    }
    return found;
}

void Board::generate(std::string str) {
    for (unsigned i = 0; i < str.length(); i++) {
        BoardNode* node = new BoardNode();
        node->character = str.at(i);
        nodes.push_back(node);
    }
    for (unsigned i = 0; i < str.length(); i++) {
        BoardNode* node = this->nodes.at(i);
        int row = i / this->size;
        int col = i % this->size;
        for (signed y = row - 1; y < row + 2; y++) {
            for (signed x = col - 1; x < col + 2; x++) {
                if (y == row && x == col)
                    continue;
                if (y >= 0 && y < this->size && x >= 0 && x < this->size) {
                    int position = y * this->size + x;
                    node->neighbours.push_back(nodes.at(position));
                }
            }
        }
    }
}

void Board::search(std::string str, BoardNode* node, std::set<std::string>& found) {
    if (!this->trie->prefix(str))
        return;

    if (this->trie->contains(str))
        found.insert(str);

    for (BoardNode* neighbour : node->neighbours) {
        if (!neighbour->visited) {
            neighbour->visited = true;
            search(str + neighbour->character, neighbour, found);
            neighbour->visited = false;
        }
    }
}