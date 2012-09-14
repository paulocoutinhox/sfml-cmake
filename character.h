#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "v8wrap.h"

#if __APPLE__
    #include "ResourcePath.hpp"
#else
    std::string resourcePath(void) { return ""; }
#endif

class Character : public v8wrap::V8ClassTemplate<Character, Character>
{

public:
    Character();
    Character(const std::string type);

    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);

private:
    sf::Sprite *sprite;
    std::string type;
    void loadSprite();
};

#endif // CHARACTER_H
