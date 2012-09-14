#include <SFML/Graphics.hpp>
#include "sf_v8.h"

#if __APPLE__
    #include "ResourcePath.hpp"
#else
    std::string resourcePath(void) { return ""; }
#endif

#include "character.h"

v8::Persistent<v8::Context> CreateShellContext() {
    v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();
    return v8::Context::New(NULL, global);
}

// Reads a file into a v8 string.
v8::Handle<v8::String> readFile(const std::string& name) {
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

char *get(v8::Handle<v8::String> value, const char *fallback = "") {
    if (value->IsString()) {
        v8::String::AsciiValue string(value);
        char *str = (char *) malloc(string.length() + 1);
        strcpy(str, *string);
        return str;
    }
    char *str = (char *) malloc(strlen(fallback) + 1);
    strcpy(str, fallback);
    return str;
}

int main()
{
    v8::HandleScope handleScope;
    v8::Persistent<v8::Context> context = v8::Context::New();
    v8::Context::Scope context_scope(context);

    context->Global()->Set(v8::String::New("sf"), sf_v8::sf::Init());

    /*
    // EXEMPLO - IMPRIMIR STRING
    // Create a string containing the JavaScript code
    // to execute (notice the quotation).
    v8::Handle<v8::String> source = v8::String::New(" 'Hello World!'; ");

    // Compile the Javascript code.
    v8::Handle<v8::Script> script = v8::Script::Compile(source);

    // Run the script to get the result.
    v8::Handle<v8::Value> result = script->Run();

    v8::String::AsciiValue ascii(result);
    printf("%s\n", *ascii);
    */

    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML Sample Application");

    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "images/robot1.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    Character *robot1 = new Character("robot1");
    v8::Handle<v8::Object> Result = Character::POT->NewInstance();
    Character::MakeReference(Result, robot1);
    context->Global()->Set(v8::String::New("robot1"), Result);

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        /*
        v8::Handle<v8::String> source = readFile(resourcePath() + "/js/robot1.js");
        v8::Handle<v8::Script> script = v8::Script::Compile(source);
        v8::Handle<v8::Value> result = script->Run();
        */

        window.clear(sf::Color(255, 255, 255));
        window.draw(sprite);
        window.display();
    }

    context.Dispose();

    return 0;
}
