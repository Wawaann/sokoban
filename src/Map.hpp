#ifndef MAP_H
    #define MAP_H

    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <array>

    typedef struct {
        int x;
        int y;
        char draw;
    } Drawable;

class Map {
    public:
        Map(std::string map);

        ~Map() = default;

        void loadMap(std::string map);

        void displayMap();

    private:
        std::vector<Drawable> _map;
};

#endif // MAP_H
