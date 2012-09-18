#include "Character.h"

Character::Character()
{
    speed     = 2.0f;
    direction = 1;
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
    direction--;

    if (direction > 8)
    {
        direction = 1;
    }
    else if (direction < 1)
    {
        direction = 8;
    }

    sprite->setRotation(getAngleForDirection(direction));
}

void Character::rotateRight()
{
    direction++;

    if (direction > 8)
    {
        direction = 1;
    }
    else if (direction < 1)
    {
        direction = 8;
    }

    sprite->setRotation(getAngleForDirection(direction));
}

void Character::loadSprite()
{
    texture = new sf::Texture();
    texture->setSmooth(true);
    if (!texture->loadFromFile(resourcePath() + "images/" + type + ".png"))
    {
        throw new std::exception();
    }
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(100, 200);
    sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
}

int Character::getAngleForDirection(int direction)
{
    int angle = 0;

    switch(direction)
    {
        case 1: {
            angle = 0;
            break;
        }
        case 2: {
            angle = 45;
            break;
        }
        case 3: {
            angle = 90;
            break;
        }
        case 4: {
            angle = 135;
            break;
        }
        case 5: {
            angle = 180;
            break;
        }
        case 6: {
            angle = 225;
            break;
        }
        case 7: {
            angle = 270;
            break;
        }
        case 8: {
            angle = 315;
            break;
        }
    }

    return angle;
}
