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
    float getSpeed();
    void mssleep(int ms);

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
    std::string type;
    float speed;

    void loadSprite();

};

#endif // CHARACTER_H
