#include "Map.hpp"

Map::Map(std::string map)
{
    this->loadMap(map);
}

void Map::loadMap(std::string map)
{
    std::fstream file;
    file.open(map, std::ios::in);

    if (!file.is_open())
        throw std::runtime_error("Cannot open file");
    
    std::string line;

    for (int y = 0; !file.eof(); y++) {
        getline(file, line);

        for (int x = 0; x < line.length(); x++) {
            Drawable drawable;
            drawable.x = x;
            drawable.y = y;
            drawable.draw = line[x];
            this->_map.push_back(drawable);
        }
    }
}

void Map::displayMap()
{
    for (auto drawable : this->_map) {
        if (drawable.draw == '/')
            std::cout << std::endl;
        else
            std::cout << drawable.draw;
    }
        
}