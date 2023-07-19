#include <iostream>
#include <memory>
#include <filesystem>

#include "SFML.hpp"
#include "Game.hpp"

bool compareFilePaths(const std::string& filePath1, const std::string& filePath2)
{
    // Extraire les numéros de fichiers des chemins
    std::string fileName1 = std::filesystem::path(filePath1).stem().string();
    std::string fileName2 = std::filesystem::path(filePath2).stem().string();

    // Extraire les numéros de fichiers après le préfixe "map_"
    int fileNumber1 = std::stoi(fileName1.substr(4));
    int fileNumber2 = std::stoi(fileName2.substr(4));

    // Comparer les numéros de fichiers pour le tri croissant
    return fileNumber1 < fileNumber2;
}

std::vector<std::string> getFilePaths(const std::string& folderPath)
{
    std::vector<std::string> filePaths;

    if (!std::filesystem::is_directory(folderPath))
    {
        std::cout << "Erreur : Le dossier spécifié n'existe pas." << std::endl;
        return filePaths;
    }

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            filePaths.push_back(entry.path().string());
        }
    }

    std::sort(filePaths.begin(), filePaths.end(), compareFilePaths);

    return filePaths;
}

int main(int argc, char** argv) {
    if (argc != 1) {
        std::cerr << "Usage: ./sokoban" << std::endl;
        return 1;
    }

    std::cout << "Welcome to Sokoban!" << std::endl;

    std::unique_ptr<SFML> sfml = std::make_unique<SFML>();
    std::unique_ptr<Game> game = std::make_unique<Game>(getFilePaths("./map"));

    game->init(sfml->getWidth(), sfml->getHeight());
    sfml->init(game->getGameAssets());

    while (game->getState()) {
        sfml->getEvent(*game);
        game->update();
        sfml->display(*game);
        sfml->update();
        sfml->clear();
    }

    return 0;
}
