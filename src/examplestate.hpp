#pragma once

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "game.hpp"

class ExampleState : public State
{
    public:
        ExampleState(gameDataRef data);

        void init();

        // No pause() or resume() as this
        // is a very simple example of a state

        void handleInput();
        void update(float delta) {};
        void render(float delta);

    private:
        gameDataRef _data;

        sf::Sprite sprite;
        sf::Text text;
        sf::CircleShape shape;
};