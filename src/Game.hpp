
#ifndef GAME_H
    #define GAME_H

    #include <iostream>
    #include <map>
    #include <fstream>
    #include <memory>
    #include <vector>
    #include <list>
    #include <utility>
    #include <algorithm>

    typedef struct {
        int top;
        int left;
        int width;
        int height;
    } Rect;

    typedef struct {
        int x;
        int y;
        char draw;
        Rect rect;
    } Drawable;

    typedef struct {
        int x;
        int y;
    } Coord;

    typedef struct {
        char draw;
        Rect rect;
        std::list<Coord> moves;
    } Player;

    typedef struct {
        bool onGoal;
        char draw;
        std::list<Coord> moves;
        Rect rect;
    } Crate;

    typedef enum {
        NOTHING,
        LEFT,
        RIGHT,
        UP,
        DOWN,
        R,
        Z
    } Input;

    typedef enum {
        NORTH,
        SOUTH,
        EAST,
        WEST
    } Direction ;

    class Game {
        public:
            explicit Game(std::vector<std::string> levels);
            ~Game() = default;

            void init();

            void update();

            void loadMap(std::string& map);

            void createPlayer(int x, int y, char draw);

            void createCrate(int x, int y, char draw, bool onGoal);

            void playerMove(int x, int y);

            void moveCrate(Crate &crate, int x, int y);

            bool crateCanMove(Crate &crate, int x, int y);

            void resetLevel();

            void moveBack();

            bool isLevelOver();

            bool getState() const { return _isRunning; }

            void setState(bool state) { _isRunning = state; }

            std::map<char, std::string> getGameAssets() { return _gameAssets; }

            std::vector<Drawable>& getGrounds() { return _grounds; }

            std::vector<Drawable>& getWalls() { return _walls; }

            std::vector<Drawable>& getGoals() { return _goals; }

            Player& getPlayer() { return _player; }

            std::vector<Crate>& getCrates() { return _crates; }

            int getMapHeight() const { return _mapHeight; }

            int getMapWidth() const { return _mapWidth; }

            Input getInput() const { return _input; }

            void setInput(Input newInput) { _input = newInput; }

        private:
            std::map<char, std::string> _gameAssets;
            std::vector<Drawable>       _grounds;
            std::vector<Drawable>       _walls;
            std::vector<Drawable>       _goals;
            std::vector<std::string>    _levels;
            bool                        _isRunning = true;
            Player                      _player;
            std::vector<Crate>          _crates;
            Input                       _input = NOTHING;
            int                         _levelIndex = 1;
            int                         _mapWidth = 0;
            int                         _mapHeight = 0;
    };

#endif // GAME_H