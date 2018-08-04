#include "game.hpp"
#include "examplestate.hpp"

Game::Game(int width, int height, std::string title)
{
    data->window.create(sf::VideoMode(width, height), title,
        sf::Style::Close | sf::Style::Titlebar);
    data->states.addState(stateRef(new ExampleState(this->data)));
    this->run();
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
            #ifdef DEBUG_MODE
                calculateUpdatesPerSecond();
            #endif

            this->data->states.getActiveState()->handleInput();
            this->data->states.getActiveState()->update(dt);

            accumulator -= dt;
        }

        #ifdef DEBUG_MODE
            calculateFramesPerSecond();
        #endif

        interpolation = accumulator / dt;
        this->data->states.getActiveState()->render(interpolation);
    }
}

#ifdef DEBUG_MODE
    void Game::calculateFramesPerSecond()
    {
        this->frames++;
        float time = this->fpsClock.getElapsedTime().asSeconds();
        if (time >= 1.f)
        {
            this->data->FPS = this->frames;

            this->fpsClock.restart();
            this->frames = 0;
        }
    }
#endif


#ifdef DEBUG_MODE
    void Game::calculateUpdatesPerSecond()
    {
        this->updates++;
        float time = this->upsClock.getElapsedTime().asSeconds();
        if (time >= 1.f)
        {
            this->data->UPS = this->updates;

            this->upsClock.restart();
            this->updates = 0;
        }
    }
#endif