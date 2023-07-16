#include "SFML.hpp"

void SFML::init(const std::map<char, std::string> &gameAssets)
{
    _videoMode = sf::VideoMode::getDesktopMode();
    _window.create(sf::VideoMode(_videoMode.width, _videoMode.height), "Zappy", sf::Style::Close);
    _window.setFramerateLimit(60);
    _window.setVerticalSyncEnabled(true);
    _window.setPosition(sf::Vector2i(0, 0));

    for (auto &asset : gameAssets) {
        sf::Texture texture;
        texture.loadFromFile(asset.second);
        _textures[asset.first] = texture;

        sf::Sprite sprite;
        sprite.setTexture(_textures[asset.first]);
        _sprites[asset.first] = sprite;
    }
}

void SFML::getEvent(Game &game)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || _event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape) {
            _window.close();
            game.setState(false);
        }
        if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Left)
            game.setInput(LEFT);
        else if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Right)
            game.setInput(RIGHT);
        else if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Up)
            game.setInput(UP);
        else if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Down)
            game.setInput(DOWN);
        else if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::R)
            game.setInput(R);
        else if (_event.type == sf::Event::KeyReleased && _event.key.code == sf::Keyboard::Z)
            game.setInput(Z);
        else
            game.setInput(NOTHING);
    }
}

void SFML::update()
{
    _window.display();
}

void SFML::clear()
{
    _window.clear(sf::Color(200, 200, 200));
}

void SFML::display(Game &game)
{
    float scaleFactorX = 1;
    float scaleFactorY = 1;
    float posX = 64;
    float posY = 64;
    float spaceX = 128;
    float spaceY = 128;

    if (game.getMapWidth() * 128 > _videoMode.width) {
        scaleFactorX = (float)_videoMode.width / (float)(game.getMapWidth() * 128);
        spaceX = (float)_videoMode.width / (float)game.getMapWidth();
        // faire les pos pour que ca commence des le debut de la window est non en décalé
        posX = (128 * scaleFactorX) / 2;
    }
    else {
        posX = (float)(_videoMode.width - game.getMapWidth() * 128) / 2;
    }

    if (game.getMapHeight() * 128 > _videoMode.height) {
        scaleFactorY = (float)_videoMode.height / (float)(game.getMapHeight() * 128);
        spaceY = (float)_videoMode.height / (float)game.getMapHeight();
        posY = (128 * scaleFactorY) / 2;
    }
    else {
        posY = (float)(_videoMode.height - game.getMapHeight() * 128) / 2;
    }

    for (auto &drawable : game.getGrounds()) {
        this->_sprites[drawable.draw].setOrigin(_sprites[drawable.draw].getLocalBounds().width / 2, _sprites[drawable.draw].getLocalBounds().height / 2);
        this->_sprites[drawable.draw].setPosition(posX + (float)drawable.x * spaceX, posY + (float)drawable.y * spaceY);
        this->_sprites[drawable.draw].setTextureRect(sf::IntRect(drawable.rect.left, drawable.rect.top, drawable.rect.width, drawable.rect.height));
        this->_sprites[drawable.draw].setScale(scaleFactorX, scaleFactorY);
        this->_window.draw(this->_sprites[drawable.draw]);
    }
    for (auto &drawable : game.getWalls()) {
        this->_sprites[drawable.draw].setOrigin(_sprites[drawable.draw].getLocalBounds().width / 2, _sprites[drawable.draw].getLocalBounds().height / 2);
        this->_sprites[drawable.draw].setPosition(posX + (float)drawable.x * spaceX, posY + (float)drawable.y * spaceY);
        this->_sprites[drawable.draw].setTextureRect(sf::IntRect(drawable.rect.left, drawable.rect.top, drawable.rect.width, drawable.rect.height));
        this->_sprites[drawable.draw].setScale(scaleFactorX, scaleFactorY);
        this->_window.draw(this->_sprites[drawable.draw]);
    }
    for (auto &drawable : game.getGoals()) {
        this->_sprites[drawable.draw].setOrigin(_sprites[drawable.draw].getLocalBounds().width / 2, _sprites[drawable.draw].getLocalBounds().height / 2);
        this->_sprites[drawable.draw].setPosition(posX + (float)drawable.x * spaceX, posY + (float)drawable.y * spaceY);
        this->_sprites[drawable.draw].setTextureRect(sf::IntRect(drawable.rect.left, drawable.rect.top, drawable.rect.width, drawable.rect.height));
        this->_sprites[drawable.draw].setScale(scaleFactorX, scaleFactorY);
        this->_window.draw(this->_sprites[drawable.draw]);
    }
    for (auto &crate : game.getCrates()) {
        this->_sprites[crate.draw].setOrigin(_sprites[crate.draw].getLocalBounds().width / 2, _sprites[crate.draw].getLocalBounds().height / 2);
        this->_sprites[crate.draw].setPosition(posX + (float)crate.moves.front().x * spaceX, posY + (float)crate.moves.front().y * spaceY);
        this->_sprites[crate.draw].setTextureRect(sf::IntRect(crate.rect.left, crate.rect.top, crate.rect.width, crate.rect.height));
        this->_sprites[crate.draw].setScale(scaleFactorX, scaleFactorY);
        this->_window.draw(this->_sprites[crate.draw]);
    }
    this->_sprites['P'].setOrigin(_sprites['P'].getLocalBounds().width / 2, _sprites['P'].getLocalBounds().height / 2);
    this->_sprites['P'].setPosition(posX + (float)game.getPlayer().moves.front().x * spaceX, posY + (float)game.getPlayer().moves.front().y * spaceY);
    this->_sprites['P'].setTextureRect(sf::IntRect(game.getPlayer().rect.left, game.getPlayer().rect.top, game.getPlayer().rect.width, game.getPlayer().rect.height));
    this->_sprites['P'].setScale(scaleFactorX, scaleFactorY);
    this->_window.draw(this->_sprites['P']);
}

