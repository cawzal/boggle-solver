#ifndef BOARDNODE_H
#define BOARDNODE_H

#include <vector>

class BoardNode {
private:
    char character;
    bool visited = false;
    std::vector<BoardNode*> neighbours;
public:
    BoardNode(char character);
    void addNeighbour(BoardNode* neighbour);
    char getCharacter();
    const std::vector<BoardNode*>& getNeighbours();
    void setVisited(bool visited);
    bool getVisited();
};

#endif
