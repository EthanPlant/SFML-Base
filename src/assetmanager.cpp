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

void AssetManager::loadShader(std::string name, std::string vertexPath, std::string fragmentPath)
{
    // Check to make sure the GPU supports shaders
    if (sf::Shader::isAvailable())
    {
        // Create shader object in map
        this->shaders[name];

        // Only vertex provided
        if(vertexPath != "" && fragmentPath == "")
        {
            if(this->shaders[name].loadFromFile(vertexPath, sf::Shader::Vertex))
            {
                std::cout << "Adding vertex shader as" << name << std::endl;
            }
            else
            {
                std::cout << "Couldn't add vertex shader " << name << std::endl;
            }
        }
        // Only fragment provided
        else if (vertexPath == "" && fragmentPath != "")
        {
            if (this->shaders[name].loadFromFile(fragmentPath, sf::Shader::Fragment))
            {
                std::cout << "Adding fragment shader " << name << std::endl;
            }
            else
            {
                std::cout << "Couldn't add fragment shader " << name << std::endl;
            }
        }
        // Both vertex and fragment provided
        else
        {
            if (this->shaders[name].loadFromFile(vertexPath, fragmentPath))
            {
                std::cout << "Adding shader " << name << std::endl;
            }
            else
            {
                std::cout << "Couldn't add shader " << name << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Shaders not available" << std::endl;
    }
}

 sf::Shader& AssetManager::getShader(std::string name)
{
    return this->shaders[name];
}

void AssetManager::disposeShader(std::string name)
{
    std::cout << "Disposing shader " << name << std::endl;
    this->shaders.erase(name);
}

void AssetManager::loadSound(std::string name, std::string filePath)
{
    // Create temp sound abd sound buffer object
    sf::SoundBuffer sb;
    sf::Sound sound;

    // Attempt to load sound from file
    if (sb.loadFromFile(filePath))
    {
        std::cout << "Adding sound " << name << std::endl;
        this->soundBuffers[name] = sb;
        sound.setBuffer(this->soundBuffers[name]);
        this->sounds[name] = sound;
    }
    else
    {
        std::cout << "Couldn't add sound " << name << std::endl;
    }
}

const sf::Sound& AssetManager::getSound(std::string name)
{
    return this->sounds[name];
}

void AssetManager::disposeSound(std::string name)
{
    this->soundBuffers.erase(name);
    this->sounds.erase(name);
}

void AssetManager::loadAnimation(std::string name, std::string filePath)
{
    // Create temp spritesheet and animation objects
    Animation animation;
    sf::Texture spriteSheet;

    // Attempt to laod spritesheet from file
    if (spriteSheet.loadFromFile(filePath))
    {
        std::cout << "Adding animation " << name << std::endl;
        // Store spritesheet and set it to animation
        this->spriteSheets[name] = spriteSheet;
        animation.setSpriteSheet(this->spriteSheets[name]);
        // Store animation
        this->animations[name] = animation;
    }
}

Animation& AssetManager::getAnimation(std::string name)
{
    return this->animations[name];
}

void AssetManager::disposeAnimation(std::string name)
{
    // Erase both spritesheet and animation
    this->animations.erase(name);
    this->spriteSheets.erase(name);
}

void AssetManager::loadMusic(std::string name, std::string filePath)
{
    this->songs[name];
    if (this->songs[name].openFromFile(filePath))
    {
        std::cout << "Adding music " << name << std::endl;
    }
}

sf::Music& AssetManager::getMusic(std::string name)
{
    return this->songs[name];
}