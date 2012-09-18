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

    sf::Texture texture;

    if (!texture.loadFromFile(resourcePath() + "images/robot1.png"))
    {
        throw std::exception();
    }

    sf::Sprite *sprite = new sf::Sprite(texture);

    while (window->isOpen())
    {
        checkEvents();

        window->clear(sf::Color(255, 255, 255));
        window->draw(*sprite);
        window->display();

        sleep(1);
    }

    delete sprite;
}

void Engine::runInThread()
{
    Util::log("Engine::runInThread");

    initializeGraphics();

    sf::Thread thread(&Engine::loadScript, context);

    while (window->isOpen())
    {
        checkEvents();

        window->clear(sf::Color(255, 255, 255));

        thread.launch();

        window->draw(*robot1->getSprite());
        window->draw(*robot2->getSprite());
        window->display();

        sf::sleep(sf::milliseconds(1));
    }
}

void Engine::loadScript(v8::Persistent<v8::Context> &context)
{
    Util::log("Engine::loadScript");

    v8::Locker locker;

    v8::Context::Scope scope(context);

    v8::Handle<v8::String> source = readFile(resourcePath() + "/js/robot1.js");
    v8::Handle<v8::Script> script = v8::Script::Compile(source);
    v8::Handle<v8::Value> result  = script->Run();

    sf::sleep(sf::milliseconds(100));

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
    robot2->setType("robot1");

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

    v8::Handle<v8::Object> Result1 = JSCharacter::POT->NewInstance();
    JSCharacter::MakeReference(Result1, robot1);
    context->Global()->Set(v8::String::New("robot1"), Result1);

    v8::Handle<v8::Object> Result2 = JSCharacter::POT->NewInstance();
    JSCharacter::MakeReference(Result2, robot2);
    context->Global()->Set(v8::String::New("robot2"), Result2);
}
