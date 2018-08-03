#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "statemanager.hpp"
#include "assetmanager.hpp"

struct gameData
{
    StateManager states;
    sf::RenderWindow window;
    AssetManager assets;
};

typedef std::shared_ptr<gameData> gameDataRef;

class Game
{
    public:
        Game(int width, int height, std::string title);

    private:
        void run();

        // Updates run at 60 per second
        const float dt = 1.f / 60.f;
        sf::Clock clock;

        gameDataRef data = std::make_shared<gameData>();
};