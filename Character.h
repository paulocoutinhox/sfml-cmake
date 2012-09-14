#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

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

private:
    sf::Sprite *sprite;
    std::string type;
    void loadSprite();

};

#endif // CHARACTER_H
