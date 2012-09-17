#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "v8wrap.h"
#include <math.h>

#if __APPLE__
    #include "ResourcePath.hpp"
#else
    std::string resourcePath(void) { return ""; }
#endif

class Character
{

public:
    Character();
    void setType(std::string type);
    sf::Sprite *getSprite();

    void walkForward();
    void mssleep(int ms);
    void rotateLeft();
    void rotateRight();
    float getSpeed();

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
    std::string type;
    float speed;
    int direction;

    void loadSprite();
    int getAngleForDirection(int direction);

};

#endif // CHARACTER_H
