#include "game.hpp"

Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title,
        sf::Style::Close | sf::Style::Titlebar);
    // TODO create state
    run();
}

void Game::run()
{
    float newTime, frameTime, interpolation;
    float currentTime = this->clock.getElapsedTime().asSeconds();
    float accumulator = 0.f;

    while(this->data->window.isOpen())
    {
        this->data->states.processStateChanges();

        newTime = this->clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt)
        {
            this->data->states.getActiveState()->handleInput();
            this->data->states.getActiveState()->update(dt);

            accumulator -= dt;
        }

        interpolation = accumulator / dt;
        this->data->states.getActiveState()->render(interpolation);
    }
}