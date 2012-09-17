#include "Character.h"

Character::Character()
{
    speed = 2.0f;
}

void Character::setType(std::string type)
{
    this->type = type;
    loadSprite();
}

sf::Sprite *Character::getSprite()
{
    return sprite;
}

void Character::walkForward()
{
    float angleRADS = (3.1415926536/180) * (sprite->getRotation());

    float x = speed * cos(angleRADS);
    float y = speed * sin(angleRADS);

    sprite->move(x, y);
}

float Character::getSpeed()
{
    return speed;
}

void Character::mssleep(int ms)
{
    sf::Time time = sf::milliseconds(ms);
    sf::sleep(time);
}

void Character::rotateLeft()
{
    sprite->setRotation(sprite->getRotation() - 1.0f);
}

void Character::rotateRight()
{
    sprite->setRotation(sprite->getRotation() + 1.0f);
}

void Character::loadSprite()
{
    texture = new sf::Texture();
    if (!texture->loadFromFile(resourcePath() + "images/" + type + ".png"))
    {
        throw new std::exception();
    }
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(100, 200);
}
