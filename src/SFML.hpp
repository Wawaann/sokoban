
#ifndef SFML_H
    #define SFML_H

    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>

    #include <iostream>
    #include <map>

    #include "Game.hpp"

    class SFML {
        public:
            SFML();
            ~SFML() = default;

            void init(const std::map<char, std::string>& gameAssets);

            void getEvent(Game &game);

            void update();

            void clear();

            void display(Game &game);

            int getWidth() const { return (int)_videoMode.width; }

            int getHeight() const { return (int)_videoMode.height; }

        private:
            sf::RenderWindow            _window;
            sf::VideoMode               _videoMode;
            sf::Event                   _event = sf::Event();
            std::map<char, sf::Texture> _textures;
            std::map<char, sf::Sprite>  _sprites;
    };

#endif // SFML_H