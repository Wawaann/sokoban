#include "Game.hpp"

Game::Game(std::vector<std::string> levels)
{
    _levels = std::move(levels);
}

void Game::init(int width, int height)
{
    loadMap(_levels[_levelIndex]);
    setMap();
    _gameAssets[' '] = "./assets/Ground/ground.png";
    _gameAssets['#'] = "./assets/Wall/wall.png";
    _gameAssets['P'] = "./assets/Player/player.png";
    _gameAssets['X'] = "./assets/Crate/crate.png";
    _gameAssets['O'] = "./assets/Goal/goal.png";
    _windowWidth = width;
    _windowHeight = height;
}

void Game::update()
{
    if (isGameOver()) {
        return;
    }
    if (isLevelOver()) {
        resetLevel(true);
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
            resetLevel(false);
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
    if (_levelIndex >= _levels.size())
        return;
    std::fstream file;
    file.open(map, std::ios::in);

    if (!file.is_open())
        throw std::runtime_error("Cannot open file");

    std::string line;

    while (!file.eof()) {
        getline(file, line);
        _currentMap.push_back(line);
    }

    file.close();
}

void Game::setMap()
{
    int widthSizeTmp = 0;
    int y = 0;

    for (auto &line : _currentMap) {
        _mapHeight++;

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
        y++;
        if (widthSizeTmp > _mapWidth)
            _mapWidth = widthSizeTmp;
        widthSizeTmp = 0;
    }
    if (_mapWidth == 0 || _mapHeight == 0)
        throw std::runtime_error("Map is empty");
    if (_mapWidth > _windowWidth)
        _mapWidth--;
    if (_mapHeight > _windowHeight)
        _mapHeight--;
    std::cout << "MAP: " << _levelIndex << ", Map Width: " << _mapWidth << ", Map height: " << _mapHeight << std::endl;
    std::cout << "Level size: " << _levels.size() - 1 << std::endl;
}

void Game::createPlayer(int x, int y, char draw)
{
    Coord coord;
    coord.x = x;
    coord.y = y;
    _player.moveCount = 0;
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
    coord.moveCount = 0;
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
            if (crateCanMove(crate, x, y)) {
                moveCrate(crate, x, y, _player.moveCount + 1);
            }
            else
                return;
        }
    }
    _player.moveCount++;
    _player.moves.push_front(coord);

}

void Game::moveCrate(Crate &crate, int x, int y, int moveCount)
{
    Coord coord;
    coord.x = crate.moves.front().x + x;
    coord.y = crate.moves.front().y + y;
    coord.moveCount = moveCount;

    for (auto &goal : _goals) {
        if (goal.x == coord.x && goal.y == coord.y) {
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

void Game::resetLevel(bool nextLevel)
{
    if (nextLevel && _levelIndex <= _levels.size()) {
        _levelIndex++;
        _currentMap.clear();
        loadMap(_levels[_levelIndex]);
    }
    _grounds.clear();
    _walls.clear();
    _goals.clear();
    _crates.clear();
    _player.moves.clear();
    _mapWidth = 0;
    _mapHeight = 0;
    setMap();
}

void Game::moveBack()
{
    if (_player.moves.size() > 1) {
        _player.moves.pop_front();
        for (auto &crate : _crates) {
            if (crate.moves.size() > 1 && crate.moves.front().moveCount == _player.moveCount) {
                crate.moves.pop_front();
                for (auto &goal : _goals) {
                    if (goal.x == crate.moves.front().x && goal.y == crate.moves.front().y) {
                        crate.onGoal = true;
                        break;
                    }
                    else
                        crate.onGoal = false;
                }
            }
        }
        _player.moveCount--;
    }
}

bool Game::isLevelOver()
{
    int size = (int)_crates.size();
    int i = 0;

    for (auto &crate : _crates) {
        if (!crate.onGoal) {
            return false;
        }
        i++;
    }
    _isLevelOver = true;
    return true;
}

bool Game::isGameOver()
{
    if (_levelIndex == _levels.size()) {
        _isOver = true;
        return true;
    }
    return false;
}
