#include "assetmanager.hpp"

void AssetManager::loadTexture(std::string name, std::string filePath)
{
    // Create temp texture object
    sf::Texture tex;

    // Attempt to load file
    if (tex.loadFromFile(filePath))
    {
        std::cout << "Adding texture " << name << std::endl;
        this->textures[name] = tex;
    }
    else
    {
        std::cout << "Couldn't load texture " << name << std::endl;
    }
}

const sf::Texture& AssetManager::getTexture(std::string name)
{
    return this->textures[name];
}

void AssetManager::disposeTexture(std::string name)
{
    std::cout << "Disposing texture " << name << std::endl;
    this->textures.erase(name);
}

void AssetManager::loadFont(std::string name, std::string filePath)
{
    // Create temp font object
    sf::Font font;

    // Attempt to load font from file
    if (font.loadFromFile(filePath))
    {
        std::cout << "Adding font " << name << std::endl;
        this->fonts[name] = font;
    }
    else
    {
        std::cout << "Couldn't load font " << name << std::endl;
    }
}

const sf::Font& AssetManager::getFont(std::string name)
{
    return this->fonts[name];
}

void AssetManager::disposeFont(std::string name)
{
    std::cout << "Disposing font " << name << std::endl;
    this->fonts.erase(name);
}