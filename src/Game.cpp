#include "Game.hpp"

Game::Game(std::vector<std::string> levels)
{
    _levels = std::move(levels);
}

void Game::init()
{
    loadMap(_levels[_levelIndex]);
    _gameAssets[' '] = "./assets/Ground/ground.png";
    _gameAssets['#'] = "./assets/Wall/wall.png";
    _gameAssets['P'] = "./assets/Player/player.png";
    _gameAssets['X'] = "./assets/Crate/crate.png";
    _gameAssets['O'] = "./assets/Goal/goal.png";
}

void Game::update()
{
    if (isLevelOver()) {
        _levelIndex++;
        resetLevel();
    }
    for (auto &crate : _crates) {
        if (crate.onGoal)
            crate.rect.left = 128;
        else
            crate.rect.left = 0;
    }
    switch (_input) {
        case(LEFT) :
            playerMove(-1, 0);
            _input = NOTHING;
            return;
        case (RIGHT) :
            playerMove(1, 0);
            _input = NOTHING;
            return;
        case (UP) :
            playerMove(0, -1);
            _input = NOTHING;
            return;
        case (DOWN) :
            playerMove(0, 1);
            _input = NOTHING;
            return;
        case (R) :
            resetLevel();
            _input = NOTHING;
            return;
        case (Z) :
            moveBack();
            _input = NOTHING;
            return;
        case (NOTHING) :
            return;
    }
}

void Game::loadMap(std::string &map)
{
    int widthSizeTmp = 0;
    std::fstream file;
    file.open(map, std::ios::in);

    if (!file.is_open())
        throw std::runtime_error("Cannot open file");

    std::string line;

    for (int y = 0; !file.eof(); y++) {
        _mapHeight++;
        getline(file, line);

        for (int x = 0; x < line.length(); x++) {
            widthSizeTmp++;
            if (line[x] == ' ') {
                Drawable drawable;
                drawable.x = x;
                drawable.y = y;
                drawable.draw = line[x];
                drawable.rect = {0, 0, 128, 128};
                this->_grounds.push_back(drawable);
            }
            if (line[x] == '#') {
                Drawable drawable;
                drawable.x = x;
                drawable.y = y;
                drawable.draw = line[x];
                drawable.rect = {0, 0, 128, 128};
                this->_walls.push_back(drawable);
                drawable.draw = ' ';
                this->_grounds.push_back(drawable);
            }
            if (line[x] == 'P') {
                createPlayer(x, y, line[x]);
            }
            if (line[x] == 'X') {
                createCrate(x, y, line[x], false);
            }
            if (line[x] == 'O') {
                Drawable drawable;
                drawable.x = x;
                drawable.y = y;
                drawable.draw = line[x];
                drawable.rect = {0, 0, 128, 128};
                this->_goals.push_back(drawable);
                drawable.draw = ' ';
                this->_grounds.push_back(drawable);
            }
            if (line[x] == 'B') {
                Drawable drawable;
                drawable.x = x;
                drawable.y = y;
                drawable.draw = 'O';
                drawable.rect = {0, 0, 128, 128};
                this->_goals.push_back(drawable);
                createCrate(x, y, 'X', true);
                drawable.draw = ' ';
                this->_grounds.push_back(drawable);
            }
        }
        if (widthSizeTmp > _mapWidth)
            _mapWidth = widthSizeTmp;
        widthSizeTmp = 0;
    }
    _mapWidth--;
    std::cout << "Map Width: " << _mapWidth << ", Map height: " << _mapHeight << std::endl;
    file.close();

    for (auto &goal : _goals) {
        std::cout << "GOAL X: " << goal.x << ", GOAL Y: " << goal.y << std::endl;
    }
}

void Game::createPlayer(int x, int y, char draw)
{
    Coord coord;
    coord.x = x;
    coord.y = y;
    _player.draw = draw;
    _player.rect = {0, 0, 128, 128};
    _player.moves.push_back(coord);
    Drawable drawable;
    drawable.x = x;
    drawable.y = y;
    drawable.draw = ' ';
    drawable.rect = {0, 0, 128, 128};
    this->_grounds.push_back(drawable);
}

void Game::createCrate(int x, int y, char draw, bool onGoal)
{
    Coord coord;
    coord.x = x;
    coord.y = y;
    Crate crate;
    crate.onGoal = onGoal;
    crate.draw = draw;
    crate.moves.push_back(coord);
    crate.rect = {0, 0, 128, 128};
    this->_crates.push_back(crate);
    Drawable drawable;
    drawable.x = x;
    drawable.y = y;
    drawable.draw = ' ';
    drawable.rect = {0, 0, 128, 128};
    this->_grounds.push_back(drawable);
}

void Game::playerMove(int x, int y)
{
    Coord coord;
    coord.x = _player.moves.front().x + x;
    coord.y = _player.moves.front().y + y;

    for (auto &wall : _walls) {
        if (wall.x == coord.x && wall.y == coord.y) {
            return;
        }
    }

    for (auto &crate : _crates) {
        if (crate.moves.front().x == coord.x && crate.moves.front().y == coord.y) {
            if (crateCanMove(crate, x, y))
                moveCrate(crate, x, y);
            else
                return;
    }
    }
    _player.moves.push_front(coord);
}

void Game::moveCrate(Crate &crate, int x, int y)
{
    Coord coord;
    coord.x = crate.moves.front().x + x;
    coord.y = crate.moves.front().y + y;

    for (auto &goal : _goals) {
        if (goal.x == coord.x && goal.y == coord.y) {
            std::cout << "Crate on goal !" << std::endl;
            crate.onGoal = true;
            break;
        }
        else
            crate.onGoal = false;
    }

    crate.moves.push_front(coord);
}

bool Game::crateCanMove(Crate &crate, int x, int y)
{
    Coord coord;
    coord.x = crate.moves.front().x + x;
    coord.y = crate.moves.front().y + y;

    for (auto &wall : _walls) {
        if  (wall.x == coord.x && wall.y == coord.y)
            return false;
    }

    for (auto &tmpCrate : _crates) {
        if (tmpCrate.moves.front().x == coord.x && tmpCrate.moves.front().y == coord.y)
            return false;
    }

    return true;
}

void Game::resetLevel()
{
    _grounds.clear();
    _walls.clear();
    _goals.clear();
    _crates.clear();
    _player.moves.clear();
    _mapWidth = 0;
    _mapHeight = 0;
    loadMap(_levels[_levelIndex]);
}

void Game::moveBack()
{

}

bool Game::isLevelOver()
{
    int size = _crates.size();
    int i = 0;

    for (auto &crate : _crates) {
        if (!crate.onGoal) {
            std::cout << "Crate " << size - i << " is not on goal" << std::endl;
            return false;
        }
        i++;
    }
    return true;
}
