#pragma once

#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "animation.hpp"

class AssetManager
{
    public:
        void loadTexture(std::string name, std::string filePath);
        const sf::Texture& getTexture(std::string name);
        void disposeTexture(std::string name);

        void loadFont(std::string name, std::string filePath);
        const sf::Font& getFont(std::string name);
        void disposeFont(std::string name);

        void loadShader(std::string name, std::string vertexPath = "", std::string fragmentPath = "");
        sf::Shader& getShader(std::string name);
        void disposeShader(std::string name);

        void loadSound(std::string name, std::string filePath);
        const sf::Sound& getSound(std::string name);
        void disposeSound(std::string name);

        void loadAnimation(std::string name, std::string filePath);
        Animation& getAnimation(std::string name);
        void disposeAnimation(std::string name);

        void loadMusic(std::string name, std::string filePath);
        sf::Music& getMusic(std::string name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
        std::map<std::string, sf::Shader> shaders;
        std::map<std::string, sf::SoundBuffer> soundBuffers;
        std::map<std::string, sf::Sound> sounds;
        std::map<std::string ,sf::Texture> spriteSheets;
        std::map<std::string, Animation> animations;
        std::map<std::string, sf::Music> songs;
};