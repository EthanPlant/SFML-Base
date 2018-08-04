#include "examplestate.hpp"
#include <iostream>

ExampleState::ExampleState(gameDataRef data) : _data(data) {}

void ExampleState::init()
{
    // Load assets
    this->_data->assets.loadFont("Test", "assets/test.ttf");
    this->_data->assets.loadTexture("Test", "assets/test.png");
    this->_data->assets.loadShader("Test Shader", "assets/test.vs", "assets/test.fs");

    // Set text attributes
    this->text.setFont(this->_data->assets.getFont("Test"));
    this->text.setString("An example SFML Base Code state");
    this->text.setCharacterSize(24);
    this->text.setColor(sf::Color::White);
    this->text.setPosition(4, this->_data->window.getSize().y - 30);

    #ifdef DEBUG_MODE
        this->stats.setFont(this->_data->assets.getFont("Test"));
        this->stats.setCharacterSize(12);
        this->stats.setColor(sf::Color::White);
        this->stats.setPosition(4, 4);
    #endif

    // Set sprite attributes
    this->sprite.setTexture(this->_data->assets.getTexture("Test"));
    this->sprite.setPosition(100, 100);
    this->sprite.setOrigin(32, 32);
    this->sprite.scale(3, 3);

    // Create circle
    shape.setRadius(100.f);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(sf::Vector2f(this->_data->window.getSize()) / 2.f);
    shape.setFillColor(sf::Color::Transparent);

    // Set shader attributes
    this->_data->assets.getShader("Test Shader").setParameter("windowHeight", static_cast<float>(this->_data->window.getSize().y));
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
    #ifdef DEBUG_MODE
        std::stringstream ss;
        ss << "UPS: " << this->_data->UPS << " FPS: " << this->_data->FPS;
        this->stats.setString(ss.str());
    #endif

    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw(this->sprite);
    this->_data->window.draw(this->text);

    this->_data->assets.getShader("Test Shader").setParameter("color", sf::Color::Blue);
    this->_data->assets.getShader("Test Shader").setParameter("center", shape.getPosition());
    this->_data->assets.getShader("Test Shader").setParameter("radius", shape.getRadius());
    this->_data->assets.getShader("Test Shader").setParameter("expand", 0.25f);
    this->_data->window.draw(shape, &this->_data->assets.getShader("Test Shader"));

    #ifdef DEBUG_MODE
        this->_data->window.draw(this->stats);
    #endif

    this->_data->window.display();
}