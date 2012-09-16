#include "Character.h"

Character::Character()
{
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
    sprite->setPosition(90, 90);
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
