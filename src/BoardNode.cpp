#include <vector>

#include "BoardNode.h"

BoardNode::BoardNode(char character) {
    this->character = character;
}

void BoardNode::addNeighbour(BoardNode* neighbour) {
    this->neighbours.push_back(neighbour);
}

char BoardNode::getCharacter() {
    return this->character;
}

const std::vector<BoardNode*>& BoardNode:: getNeighbours() {
    return this->neighbours;
}
    
void BoardNode::setVisited(bool visited) {
    this->visited = visited;
}

bool BoardNode::getVisited() {
    return this->visited;
}