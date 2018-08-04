#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

#include "statemanager.hpp"
#include "assetmanager.hpp"
#include "DEFINATIONS.hpp"

struct gameData
{
    StateManager states;
    sf::RenderWindow window;
    AssetManager assets;
    #ifdef DEBUG_MODE
        int FPS, UPS;
    #endif
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
        #ifdef DEBUG_MODE
            void calculateFramesPerSecond();
            void calculateUpdatesPerSecond();

            sf::Clock fpsClock;
            sf::Clock upsClock;
            int updates;
            int frames;
        
        #endif

        gameDataRef data = std::make_shared<gameData>();
};