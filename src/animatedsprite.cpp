#include "animatedsprite.hpp"

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool looped) :
    animation(NULL), frameTime(frameTime), currentFrame(0), paused(paused), looped(looped), texture(NULL)
{}

void AnimatedSprite::setAnimation(const Animation& animation)
{
    this->animation = &animation;
    this->texture = this->animation->getSpriteSheet();
    this->currentFrame = 0;
    setFrame(currentFrame);
}

void AnimatedSprite::setFrameTime(sf::Time time)
{
    this->frameTime = time;
}

void AnimatedSprite::play()
{
    this->paused = false;
}

void AnimatedSprite::play(const Animation& animation)
{
    if (getAnimation() != this->animation)
    {
        setAnimation(animation);
    }
    play();
}

void AnimatedSprite::pause()
{
    this->paused = true;
}

void AnimatedSprite::stop()
{
    this->paused = true;
    this->currentFrame = 0;
    setFrame(this->currentFrame);
}

void AnimatedSprite::setLooped(bool looped)
{
    this->looped = looped;
}

void AnimatedSprite::setColour(const sf::Color& colour)
{
    this->vertices[0].color = colour;
    this->vertices[1].color = colour;
    this->vertices[2].color = colour;
    this->vertices[3].color = colour;
}

const Animation* AnimatedSprite::getAnimation() const
{
    return this->animation;
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
    sf::IntRect rect = this->animation->getFrame(this->currentFrame);

    float width = static_cast<float>(std::abs(rect.width));
    float height = static_cast<float>(std::abs(rect.height));

    return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

bool AnimatedSprite::isLooped() const
{
    return this->looped;
}


bool AnimatedSprite::isPlaying() const
{
    return !this->paused;
}

sf::Time AnimatedSprite::getFrameTime() const
{
    return this->frameTime;
}

void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime)
{
    if (this->animation)
    {
        sf::IntRect rect = this->animation->getFrame(newFrame);

        this->vertices[0].position = sf::Vector2f(0.f, 0.f);
        this->vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
        this->vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
        this->vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

        float left = static_cast<float>(rect.left) + 0.0001f;
        float right = static_cast<float>(rect.width);
        float top = static_cast<float>(rect.top);
        float bottom = top + static_cast<float>(rect.height);
    }

    if (resetTime)
    {
        this->currentTime = sf::Time::Zero;
    }
}

void AnimatedSprite::update(sf::Time deltaTime)
{
    if (!this->paused && this->animation)
    {
        this->currentTime += deltaTime;

        if (this->currentTime >= this->frameTime)
        {
            this->currentTime = sf::microseconds(this->currentTime.asMicroseconds() % this->frameTime.asMicroseconds());

            if (this->currentFrame + 1 < this->animation->getSize())
            {
                this->currentFrame++;
            }
            else
            {
                this->currentFrame = 0;

                if (!this->looped)
                {
                    this->paused = true;
                }
            }

            setFrame(this->currentFrame, false);
        }
    }
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (this->animation && this->texture)
    {
        states.transform *= getTransform();
        states.texture = this->texture;
        target.draw(this->vertices, 4, sf::Quads, states);
    }
}