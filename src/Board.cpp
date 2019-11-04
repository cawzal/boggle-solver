#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Board.h"

Board::Board(std::string str) {
    this->size = std::sqrt(str.length());
    this->generate(str);
}

void Board::find(Trie* trie, std::set<std::string>& words) {
    std::string empty = "";
    for (BoardNode* root : this->nodes) {
        root->visited = true;
        search(trie, empty + root->character, root, words);
        root->visited = false;
    }
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

void Board::search(Trie* trie, std::string str, BoardNode* node, std::set<std::string>& words) {
    if (!trie->prefix(str))
        return;

    if (trie->contains(str))
        words.insert(str);

    for (BoardNode* neighbour : node->neighbours) {
        if (!neighbour->visited) {
            neighbour->visited = true;
            search(trie, str + neighbour->character, neighbour, words);
            neighbour->visited = false;
        }
    }
}