#include "Engine.h"

Engine::Engine()
{
    Util::log("Engine::Engine");
    srand(time(NULL));
    useThread = true;
}

Engine::~Engine()
{
    Util::log("Engine::~Engine");
}

void Engine::start()
{
    Util::log("Engine::start");

    initializeV8();
    initializePlayers();
    initializeV8Binding();

    if (useThread)
    {
        runInThread();
    }
    else
    {
        run();
    }
}

void Engine::run()
{
    Util::log("Engine::run");

    initializeGraphics();

    while (window->isOpen())
    {
        checkEvents();

        Engine::loadScript(this);

        window->clear(sf::Color(255, 255, 255));
        window->draw(*robot1->getSprite());
        window->draw(*robot2->getSprite());
        window->display();

        sf::sleep(sf::milliseconds(1));
    }
}

void Engine::runInThread()
{
    Util::log("Engine::runInThread");

    initializeGraphics();
    sf::Thread threadPlayer(&Engine::loadScript, this);

    sf::Clock timer;

    while (window->isOpen())
    {
        checkEvents();

        window->clear(sf::Color(255, 255, 255));

        if (timer.getElapsedTime() > sf::milliseconds(100))
        {
            threadPlayer.launch();
            timer.restart();
        }

        window->draw(*robot1->getSprite());
        window->draw(*robot2->getSprite());
        window->display();

        sf::sleep(sf::milliseconds(1));
    }
}

void Engine::loadScript(Engine *engine)
{
    Util::log("Engine::loadScript");

    v8::Locker locker;

    v8::Handle<v8::String> source;
    v8::Handle<v8::Script> script;
    v8::Handle<v8::Value> result;

    // robot 1
    source = readFile(resourcePath() + "/js/" + engine->robot1->getType() + ".js");
    script = v8::Script::Compile(source);
    result = script->Run();

    // robot 2
    source = readFile(resourcePath() + "/js/" + engine->robot2->getType() + ".js");
    script = v8::Script::Compile(source);
    result = script->Run();

    Util::log("Engine::loadScript::end");
}

v8::Handle<v8::String> Engine::readFile(const std::string& name)
{
    Util::log("Engine::readFile");

    FILE* file = fopen(name.c_str(), "rb");
    if (file == NULL) return v8::Handle<v8::String>();

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    char* chars = new char[size + 1];
    chars[size] = '\0';

    for (int i = 0; i < size;)
    {
        int read = fread(&chars[i], 1, size - i, file);
        i += read;
    }

    fclose(file);
    v8::Handle<v8::String> result = v8::String::New(chars, size);
    delete[] chars;
    return result;
}

void Engine::initializeGraphics()
{
    Util::log("Engine::initializeGraphics");

    sf::ContextSettings settings;
    settings.depthBits = 0;
    settings.stencilBits = 0;
    settings.antialiasingLevel = 0;

    window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "SFML Sample Application", sf::Style::Close, settings);
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

void Engine::initializePlayers()
{
    Util::log("Engine::initializePlayers");

    robot1 = new Character();
    robot1->setType("robot1");

    robot2 = new Character();
    robot2->setType("robot2");

    robot1->getSprite()->move(Util::randomInt(0, 750), Util::randomInt(0, 500));
    robot2->getSprite()->move(Util::randomInt(0, 750), Util::randomInt(0, 500));
}

void Engine::initializeV8()
{
    Util::log("Engine::initializeV8");

    context = v8::Context::New();
    scope   = new v8::Context::Scope(context);
}

void Engine::initializeV8Binding()
{
    Util::log("Engine::initializeV8Binding");

    JSCharacter::InitPOT(JSCharacter::POT);

    jsPlayer1 = JSCharacter::POT->NewInstance();
    JSCharacter::MakeReference(jsPlayer1, robot1);
    context->Global()->Set(v8::String::New("robot1"), jsPlayer1);

    jsPlayer2 = JSCharacter::POT->NewInstance();
    JSCharacter::MakeReference(jsPlayer2, robot2);
    context->Global()->Set(v8::String::New("robot2"), jsPlayer2);
}
