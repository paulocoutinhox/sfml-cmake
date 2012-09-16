#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "v8wrap.h"

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

private:
    sf::Sprite *sprite;
    sf::Texture *texture;
    std::string type;
    void loadSprite();

};

#endif // CHARACTER_H
