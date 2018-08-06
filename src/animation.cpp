#include "animation.hpp"

Animation::Animation() : texture(NULL) {}

void Animation::addFrame(sf::IntRect rect)
{
    this->frames.push_back(rect);
}

void Animation::setSpriteSheet(const sf::Texture& texture)
{
    this->texture = &texture;
}

const sf::Texture* Animation::getSpriteSheet() const
{
    return this->texture;
}

std::size_t Animation::getSize() const
{
    return this->frames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t n) const
{
    return this->frames[n];
}