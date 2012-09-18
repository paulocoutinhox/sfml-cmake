#ifndef ENGINE_H
#define ENGINE_H

#include "Character.h"
#include "JSCharacter.h"
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

    void start();
    void run();
    void runInThread();
    static void loadScript(Engine *engine);

private:
    Character *robot1;
    Character *robot2;

    v8::Handle<v8::Object> jsPlayer1;
    v8::Handle<v8::Object> jsPlayer2;

    v8::HandleScope handleScope;
    v8::Persistent<v8::Context> context;
    v8::Context::Scope *scope;

    sf::Mutex mutex;

    bool useThread;

    sf::RenderWindow *window;

    static v8::Handle<v8::String> readFile(const std::string& name);

    void initializeGraphics();
    void checkEvents();
    void initializePlayers();
    void initializeV8();
    void initializeV8Binding();

};

#endif // ENGINE_H
