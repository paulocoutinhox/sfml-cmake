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
    static void loadScript(v8::Persistent<v8::Context> &context);

private:
    Character *robot1;
    Character *robot2;

    sf::Thread *thread;

    v8::HandleScope handleScope;
    v8::Persistent<v8::Context> context;
    v8::Context::Scope *scope;

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
