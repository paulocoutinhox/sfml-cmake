#include "Engine.h"

Engine::Engine()
{
    Util::log("Engine::Engine");
    resetRandom();
    setupScreen();
    setupBackgroundColor();

    showSampleContent = true;
}

Engine::~Engine()
{
    Util::log("Engine::~Engine");
}

void Engine::run()
{
    Util::log("Engine::run");

    initializeGraphics();

    sf::Sprite sampleSprite;
    sf::Texture sampleTexture;

    if (showSampleContent)
    {
        if (sampleTexture.loadFromFile(resourcePath() + "images/logo.png") != true)
        {
            Util::log("Cannot load texture: logo.png");
            return;
        }

        sampleSprite.setTexture(sampleTexture);
        sampleSprite.setPosition((screenWidth / 2) - (sampleSprite.getLocalBounds().width / 2), (screenHeight / 2) - (sampleSprite.getLocalBounds().height / 2));
    }

    while (window->isOpen())
    {
        checkEvents();

        window->clear(backgroundColor);

        if (showSampleContent)
        {
            window->draw(sampleSprite);
        }

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
