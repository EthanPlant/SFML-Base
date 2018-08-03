#include "examplestate.hpp"
#include <iostream>

ExampleState::ExampleState(gameDataRef data) : _data(data) {}

void ExampleState::init()
{
    // Load assets
    this->_data->assets.loadFont("Test", "assets/test.ttf");
    this->_data->assets.loadTexture("Test", "assets/test.png");

    // Set text attributes
    this->text.setFont(this->_data->assets.getFont("Test"));
    this->text.setString("An example SFML Base Code state");
    this->text.setCharacterSize(24);
    this->text.setColor(sf::Color::Black);
    this->text.setPosition(4, this->_data->window.getSize().y - 30);

    // Set sprite attributes
    this->sprite.setTexture(this->_data->assets.getTexture("Test"));
    this->sprite.setPosition(30, 30);
    this->sprite.scale(3, 3);
}

void ExampleState::handleInput()
{
    sf::Event e;
    while (this->_data->window.pollEvent(e))
    {
        switch (e.type)
        {
            // We have to handle the close event no matter what
            case sf::Event::Closed:
                this->_data->window.close();
                break;
        }
    }
}

void ExampleState::render(float delta)
{
    this->_data->window.clear(sf::Color::White);
    this->_data->window.draw(this->sprite);
    this->_data->window.draw(this->text);
    this->_data->window.display();
}