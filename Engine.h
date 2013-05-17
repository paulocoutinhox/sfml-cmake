#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "Util.h"

#if __APPLE__
#include "ResourcePath.hpp"
#else
std::string resourcePath(void) { return ""; }
#endif

class Engine
{

public:
    Engine();
    ~Engine();

    void run();

private:

    int screenWidth;
    int screenHeight;
    int screenBitsPerPixel;
    std::string screenTitle;
    sf::Color backgroundColor;

    sf::RenderWindow *window;

    void initializeGraphics();
    void checkEvents();
    void resetRandom();
    void setupScreen();
    void setupBackgroundColor();

};

#endif // ENGINE_H
