#include "Engine.h"

Engine::Engine()
{
    Util::log("Engine::Engine");
    resetRandom();
    setupScreen();
    setupBackgroundColor();
}

Engine::~Engine()
{
    Util::log("Engine::~Engine");
}

void Engine::run()
{
    Util::log("Engine::run");

    initializeGraphics();

    sf::Clock timer;

    sf::Texture texture;

    if (texture.loadFromFile(resourcePath() + "images/logo.png") != true)
    {
        Util::log("Cannot load texture: logo.png");
        return;
    }

    sf::Sprite sprite(texture);
    sprite.setPosition((screenWidth / 2) - (sprite.getLocalBounds().width / 2), (screenHeight / 2) - (sprite.getLocalBounds().height / 2));

    while (window->isOpen())
    {
        checkEvents();

        if (timer.getElapsedTime() > sf::milliseconds(100))
        {
            timer.restart();
        }

        window->clear(backgroundColor);
        window->draw(sprite);
        window->display();

        sf::sleep(sf::milliseconds(1));
    }
}

void Engine::initializeGraphics()
{
    Util::log("Engine::initializeGraphics");

    sf::ContextSettings settings;
    settings.depthBits = 0;
    settings.stencilBits = 0;
    settings.antialiasingLevel = 0;

    window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight, screenBitsPerPixel), screenTitle, sf::Style::Close, settings);
}

void Engine::checkEvents()
{
    Util::log("Engine::checkEvents");

    sf::Event Event;

    while (window->pollEvent(Event))
    {
        switch (Event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
        }
    }
}

void Engine::resetRandom()
{
    srand(time(NULL));
}

void Engine::setupScreen()
{
    screenWidth        = 800;
    screenHeight       = 600;
    screenBitsPerPixel = 32;
    screenTitle        = "Sample Application";
}

void Engine::setupBackgroundColor()
{
    backgroundColor = sf::Color(0, 0, 0);
}
