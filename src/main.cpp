#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <set>
#include <string>

#include "Board.h"

int main(int argc, char **argv) {
    if (argc != 3)  {
        std::cout << "Error: Inputs not specified\n";
        return 0;
    }

    std::ifstream file(argv[1]);
    if (file.fail()) {
        std::cout << "Error: Unable to read input file\n";
        return 0;
    }

    std::string chars = argv[2];
    unsigned int size = std::sqrt(chars.length());
    if (chars.length() != size * size) {
        std::cout << "Error: Invalid length of characters provided\n";
        return 0;
    }
    
    std::regex exprc("[a-z]+");
    if (!std::regex_match(chars, exprc)) {
        std::cout << "Error: Invalid characters provided\n";
        return 0;
    }
    
    Trie trie;
    std::regex exprw("[a-z]{3,}");
    for (std::string word; getline(file, word);) {
        if (std::regex_match(word, exprw))
            trie.insert(word);
    }
    file.close();

    Board board(chars, &trie);
    std::set<std::string> found = board.find();
    
    std::cout << "Found: " << found.size() << "\n";
    int counter = 0;
    for (const std::string& word : found) {
        counter++;
        std::cout << std::left << std::setw(20) << word;
        if (counter % 5 == 0)
            std::cout << "\n";
    }
    if (counter % 5 != 0)
        std::cout << "\n";

    return 0;
}
