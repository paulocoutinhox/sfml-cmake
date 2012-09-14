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

void Character::loadSprite()
{
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "images/" + type + ".png"))
    {
        throw new std::exception();
    }
    sprite = new sf::Sprite(texture);
    sprite->setPosition(100, 200);
}
