#include <iostream>

#include "Map.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./sokoban <map>" << std::endl;
        return 1;
    }
    Map map(argv[1]);
    map.displayMap();
    return 0;
}
