#include "character.h"

const char *Character::Bases     = "Character\0\0";
const char *Character::ClassName = "Character\0\0";

Character::Character()
{

}

Character::Character(const std::string type)
{
    this->type = type;
    loadSprite();
}

void Character::loadSprite()
{
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "images/" + type + ".png"))
    {
        throw new std::exception();
    }
    sprite = new sf::Sprite(texture);
}

v8::Handle<v8::Value> Character::Create(const v8::Arguments &args)
{
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sUseNew)));
    }
}

void Character::Delete(MyClass *inst)
{
    delete inst;
}

void Character::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}

void Character::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Time"), FO);
}

void Character::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("className", v8::String::New(ClassName));
}

void Character::Register(v8::Handle<v8::FunctionTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
}
