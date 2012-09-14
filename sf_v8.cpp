/***
SFML-V8-Binding Project
The zlib/libpng License
Copyright (c) 2012 Steven Christy

This software is provided 'as-is', without any express or implied warranty. In no event will
the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial
applications, and to alter it and redistribute it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote
the original software. If you use this software in a product, an acknowledgment in the product
documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as
being the original software.

3. This notice may not be removed or altered from any source distribution.
***/

//----------------------------------------
// Created: 2012-07-01 17:32:52
//----------------------------------------
#include "sf_v8.h"
//----------------------------------------
using namespace v8wrap;
//----------------------------------------
namespace sf_v8 {
const char *sf_Font::Bases = "sf::Font\0\0";
const char *sf_Font::ClassName = "sf::Font";
v8::Handle<v8::Value> sf_Font::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_loadFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->loadFromFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_loadFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "sizeinbytes" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_loadFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "stream" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_getGlyph(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "codepoint" }, { PT_NUMBER, "charactersize" }, { PT_BOOLEAN, "bold" }}}
    };
    int FuncSize = 1;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Uint32 p0 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            bool p2 = CastToCPP< bool >(ParamMatch.Params[2]);
            result = CastToJS(inst->getGlyph(p0,p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_getKerning(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "first" }, { PT_NUMBER, "second" }, { PT_NUMBER, "charactersize" }}}
    };
    int FuncSize = 1;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Uint32 p0 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[0]);
            ::sf::Uint32 p1 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            result = CastToJS(inst->getKerning(p0,p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_getLineSpacing(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "charactersize" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getLineSpacing(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_getTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "charactersize" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getTexture(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Font::Method_getDefaultFont(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS2(::sf::Font::getDefaultFont());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Font::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Font::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Font::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Font"), FO);
}
//----------------------------------------
void sf_Font::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("loadFromFile", v8::FunctionTemplate::New(Method_loadFromFile));
    target->Set("loadFromMemory", v8::FunctionTemplate::New(Method_loadFromMemory));
    target->Set("loadFromStream", v8::FunctionTemplate::New(Method_loadFromStream));
    target->Set("getGlyph", v8::FunctionTemplate::New(Method_getGlyph));
    target->Set("getKerning", v8::FunctionTemplate::New(Method_getKerning));
    target->Set("getLineSpacing", v8::FunctionTemplate::New(Method_getLineSpacing));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
}
//----------------------------------------
void sf_Font::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("getDefaultFont"), v8::FunctionTemplate::New(Method_getDefaultFont));
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_SocketSelector::Bases = "sf::SocketSelector\0\0";
const char *sf_SocketSelector::ClassName = "sf::SocketSelector";
v8::Handle<v8::Value> sf_SocketSelector::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Method_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "socket" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Socket* p0 = CastToCPP< ::sf::Socket* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->add(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Method_remove(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "socket" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Socket* p0 = CastToCPP< ::sf::Socket* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->remove(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Method_clear(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->clear();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Method_wait(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "timeout" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->wait());
            break;
        }
        case 2: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->wait(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SocketSelector::Method_isReady(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "socket" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Socket* p0 = CastToCPP< ::sf::Socket* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->isReady(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_SocketSelector::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SocketSelector::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SocketSelector::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SocketSelector"), FO);
}
//----------------------------------------
void sf_SocketSelector::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("add", v8::FunctionTemplate::New(Method_add));
    target->Set("remove", v8::FunctionTemplate::New(Method_remove));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("wait", v8::FunctionTemplate::New(Method_wait));
    target->Set("isReady", v8::FunctionTemplate::New(Method_isReady));
}
//----------------------------------------
void sf_SocketSelector::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#endif
const char *sf_View::Bases = "sf::View\0\0";
const char *sf_View::ClassName = "sf::View";
v8::Handle<v8::Value> sf_View::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "rectangle" }}},
    { 3, 2, {{ PT_CLASS, "center" }, { PT_CLASS, "size" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::FloatRect* p0 = CastToCPP< ::sf::FloatRect* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_setCenter(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "center" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setCenter(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setCenter(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_setSize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }}},
    { 2, 1, {{ PT_CLASS, "size" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setSize(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setSize(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_setViewport(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "viewport" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::FloatRect* p0 = CastToCPP< ::sf::FloatRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setViewport(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_reset(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rectangle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::FloatRect* p0 = CastToCPP< ::sf::FloatRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->reset(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getCenter(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getCenter());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getViewport(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getViewport());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_zoom(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "factor" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->zoom(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_View::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_View::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_View::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_View::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("View"), FO);
}
//----------------------------------------
void sf_View::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setCenter", v8::FunctionTemplate::New(Method_setCenter));
    target->Set("setSize", v8::FunctionTemplate::New(Method_setSize));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setViewport", v8::FunctionTemplate::New(Method_setViewport));
    target->Set("reset", v8::FunctionTemplate::New(Method_reset));
    target->Set("getCenter", v8::FunctionTemplate::New(Method_getCenter));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getViewport", v8::FunctionTemplate::New(Method_getViewport));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("zoom", v8::FunctionTemplate::New(Method_zoom));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_View::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_RenderWindow::Bases = "sf::RenderWindow\0sf::Window\0\0";
const char *sf_RenderWindow::ClassName = "sf::RenderWindow";
v8::Handle<v8::Value> sf_RenderWindow::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }}},
    { 3, 3, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }}},
    { 4, 4, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }, { PT_CLASS, "settings" }}},
    { 5, 1, {{ PT_NUMBER, "handle" }}},
    { 6, 2, {{ PT_NUMBER, "handle" }, { PT_CLASS, "settings" }}}
    };
    int FuncSize = 6;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(*p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(*p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
                ::sf::ContextSettings* p3 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[3]);
                if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,p1,p2,*p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 6: {
                ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
                ::sf::ContextSettings* p1 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_capture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->capture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_create(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }}},
    { 2, 3, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }}},
    { 3, 4, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }, { PT_CLASS, "settings" }}},
    { 4, 1, {{ PT_NUMBER, "handle" }}},
    { 5, 2, {{ PT_NUMBER, "handle" }, { PT_CLASS, "settings" }}}
    };
    int FuncSize = 5;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            inst->create(*p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
            inst->create(*p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
            ::sf::ContextSettings* p3 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(*p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
            inst->create(p0);
            result = v8::Undefined();
            break;
        }
        case 5: {
            ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
            ::sf::ContextSettings* p1 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_close(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->close();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_isOpen(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isOpen());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getSettings(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getSettings());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_pollEvent(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "event" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Event* p0 = CastToCPP< ::sf::Event* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->pollEvent(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_waitEvent(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "event" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Event* p0 = CastToCPP< ::sf::Event* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->waitEvent(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setSize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "size" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2u* p0 = CastToCPP< ::sf::Vector2u* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setSize(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setTitle(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "title" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            inst->setTitle(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setIcon(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_POINTER, "pixels" }}}
    };
    int FuncSize = 1;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned char* p2 = CastToCPP< unsigned char* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setIcon(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setVisible(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "visible" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setVisible(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setVerticalSyncEnabled(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "enabled" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setVerticalSyncEnabled(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setMouseCursorVisible(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "visible" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setMouseCursorVisible(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setKeyRepeatEnabled(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "enabled" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setKeyRepeatEnabled(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setFramerateLimit(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "limit" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->setFramerateLimit(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setJoystickThreshold(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "threshold" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setJoystickThreshold(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setActive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_BOOLEAN, "active" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->setActive());
            break;
        }
        case 2: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            result = CastToJS(inst->setActive(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_display(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->display();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getSystemHandle(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSystemHandle());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_clear(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->clear();
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->clear(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_setView(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setView(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getDefaultView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getDefaultView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_getViewport(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->getViewport(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_convertCoords(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "point" }}},
    { 2, 2, {{ PT_CLASS, "point" }, { PT_CLASS, "view" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0));
            break;
        }
        case 2: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::View* p1 = CastToCPP< ::sf::View* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_draw(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "drawable" }}},
    { 2, 2, {{ PT_CLASS, "drawable" }, { PT_CLASS, "states" }}},
    { 3, 3, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }}},
    { 4, 4, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }, { PT_CLASS, "states" }}}
    };
    int FuncSize = 4;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::RenderStates* p1 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            inst->draw(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            ::sf::RenderStates* p3 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_pushGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pushGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_popGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->popGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderWindow::Method_resetGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->resetGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_RenderWindow::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_RenderWindow::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_RenderWindow::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("RenderWindow"), FO);
}
//----------------------------------------
void sf_RenderWindow::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("capture", v8::FunctionTemplate::New(Method_capture));
    target->Set("create", v8::FunctionTemplate::New(Method_create));
    target->Set("close", v8::FunctionTemplate::New(Method_close));
    target->Set("isOpen", v8::FunctionTemplate::New(Method_isOpen));
    target->Set("getSettings", v8::FunctionTemplate::New(Method_getSettings));
    target->Set("pollEvent", v8::FunctionTemplate::New(Method_pollEvent));
    target->Set("waitEvent", v8::FunctionTemplate::New(Method_waitEvent));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setSize", v8::FunctionTemplate::New(Method_setSize));
    target->Set("setTitle", v8::FunctionTemplate::New(Method_setTitle));
    target->Set("setIcon", v8::FunctionTemplate::New(Method_setIcon));
    target->Set("setVisible", v8::FunctionTemplate::New(Method_setVisible));
    target->Set("setVerticalSyncEnabled", v8::FunctionTemplate::New(Method_setVerticalSyncEnabled));
    target->Set("setMouseCursorVisible", v8::FunctionTemplate::New(Method_setMouseCursorVisible));
    target->Set("setKeyRepeatEnabled", v8::FunctionTemplate::New(Method_setKeyRepeatEnabled));
    target->Set("setFramerateLimit", v8::FunctionTemplate::New(Method_setFramerateLimit));
    target->Set("setJoystickThreshold", v8::FunctionTemplate::New(Method_setJoystickThreshold));
    target->Set("setActive", v8::FunctionTemplate::New(Method_setActive));
    target->Set("display", v8::FunctionTemplate::New(Method_display));
    target->Set("getSystemHandle", v8::FunctionTemplate::New(Method_getSystemHandle));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("setView", v8::FunctionTemplate::New(Method_setView));
    target->Set("getView", v8::FunctionTemplate::New(Method_getView));
    target->Set("getDefaultView", v8::FunctionTemplate::New(Method_getDefaultView));
    target->Set("getViewport", v8::FunctionTemplate::New(Method_getViewport));
    target->Set("convertCoords", v8::FunctionTemplate::New(Method_convertCoords));
    target->Set("draw", v8::FunctionTemplate::New(Method_draw));
    target->Set("pushGLStates", v8::FunctionTemplate::New(Method_pushGLStates));
    target->Set("popGLStates", v8::FunctionTemplate::New(Method_popGLStates));
    target->Set("resetGLStates", v8::FunctionTemplate::New(Method_resetGLStates));
}
//----------------------------------------
void sf_RenderWindow::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_Ftp_Response::Bases = "sf::Ftp::Response\0\0";
const char *sf_Ftp_Response::ClassName = "sf::Ftp::Response";
v8::Handle<v8::Value> sf_Ftp_Response::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "code" }}},
    { 3, 2, {{ PT_NUMBER, "code" }, { PT_STRING, "message" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::Ftp::Response::Status p0 = CastToCPP< ::sf::Ftp::Response::Status >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Ftp::Response::Status p0 = CastToCPP< ::sf::Ftp::Response::Status >(ParamMatch.Params[0]);
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_Response::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_Response::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_Response::Method_isOk(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isOk());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_Response::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_Response::Method_getMessage(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMessage());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Ftp_Response::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Ftp_Response::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Ftp_Response::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Response"), FO);
}
//----------------------------------------
void sf_Ftp_Response::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("isOk", v8::FunctionTemplate::New(Method_isOk));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("getMessage", v8::FunctionTemplate::New(Method_getMessage));
}
//----------------------------------------
void sf_Ftp_Response::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("RestartMarkerReply"), v8::Number::New(110), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReadySoon"), v8::Number::New(120), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionAlreadyOpened"), v8::Number::New(125), v8::ReadOnly);
    target->Set(v8::String::New("OpeningDataConnection"), v8::Number::New(150), v8::ReadOnly);
    target->Set(v8::String::New("Ok"), v8::Number::New(200), v8::ReadOnly);
    target->Set(v8::String::New("PointlessCommand"), v8::Number::New(202), v8::ReadOnly);
    target->Set(v8::String::New("SystemStatus"), v8::Number::New(211), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryStatus"), v8::Number::New(212), v8::ReadOnly);
    target->Set(v8::String::New("FileStatus"), v8::Number::New(213), v8::ReadOnly);
    target->Set(v8::String::New("HelpMessage"), v8::Number::New(214), v8::ReadOnly);
    target->Set(v8::String::New("SystemType"), v8::Number::New(215), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReady"), v8::Number::New(220), v8::ReadOnly);
    target->Set(v8::String::New("ClosingConnection"), v8::Number::New(221), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionOpened"), v8::Number::New(225), v8::ReadOnly);
    target->Set(v8::String::New("ClosingDataConnection"), v8::Number::New(226), v8::ReadOnly);
    target->Set(v8::String::New("EnteringPassiveMode"), v8::Number::New(227), v8::ReadOnly);
    target->Set(v8::String::New("LoggedIn"), v8::Number::New(230), v8::ReadOnly);
    target->Set(v8::String::New("FileActionOk"), v8::Number::New(250), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryOk"), v8::Number::New(257), v8::ReadOnly);
    target->Set(v8::String::New("NeedPassword"), v8::Number::New(331), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToLogIn"), v8::Number::New(332), v8::ReadOnly);
    target->Set(v8::String::New("NeedInformation"), v8::Number::New(350), v8::ReadOnly);
    target->Set(v8::String::New("ServiceUnavailable"), v8::Number::New(421), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionUnavailable"), v8::Number::New(425), v8::ReadOnly);
    target->Set(v8::String::New("TransferAborted"), v8::Number::New(426), v8::ReadOnly);
    target->Set(v8::String::New("FileActionAborted"), v8::Number::New(450), v8::ReadOnly);
    target->Set(v8::String::New("LocalError"), v8::Number::New(451), v8::ReadOnly);
    target->Set(v8::String::New("InsufficientStorageSpace"), v8::Number::New(452), v8::ReadOnly);
    target->Set(v8::String::New("CommandUnknown"), v8::Number::New(500), v8::ReadOnly);
    target->Set(v8::String::New("ParametersUnknown"), v8::Number::New(501), v8::ReadOnly);
    target->Set(v8::String::New("CommandNotImplemented"), v8::Number::New(502), v8::ReadOnly);
    target->Set(v8::String::New("BadCommandSequence"), v8::Number::New(503), v8::ReadOnly);
    target->Set(v8::String::New("ParameterNotImplemented"), v8::Number::New(504), v8::ReadOnly);
    target->Set(v8::String::New("NotLoggedIn"), v8::Number::New(530), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToStore"), v8::Number::New(532), v8::ReadOnly);
    target->Set(v8::String::New("FileUnavailable"), v8::Number::New(550), v8::ReadOnly);
    target->Set(v8::String::New("PageTypeUnknown"), v8::Number::New(551), v8::ReadOnly);
    target->Set(v8::String::New("NotEnoughMemory"), v8::Number::New(552), v8::ReadOnly);
    target->Set(v8::String::New("FilenameNotAllowed"), v8::Number::New(553), v8::ReadOnly);
    target->Set(v8::String::New("InvalidResponse"), v8::Number::New(1000), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionFailed"), v8::Number::New(1001), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionClosed"), v8::Number::New(1002), v8::ReadOnly);
    target->Set(v8::String::New("InvalidFile"), v8::Number::New(1003), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_Ftp_DirectoryResponse::Bases = "sf::Ftp::DirectoryResponse\0sf::Ftp::Response\0\0";
const char *sf_Ftp_DirectoryResponse::ClassName = "sf::Ftp::DirectoryResponse";
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "response" }}}
    };
    int FuncSize = 1;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                ::sf::Ftp::Response* p0 = CastToCPP< ::sf::Ftp::Response* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Method_getDirectory(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getDirectory());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Method_isOk(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isOk());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_DirectoryResponse::Method_getMessage(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMessage());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Ftp_DirectoryResponse::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Ftp_DirectoryResponse::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Ftp_DirectoryResponse::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("DirectoryResponse"), FO);
}
//----------------------------------------
void sf_Ftp_DirectoryResponse::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getDirectory", v8::FunctionTemplate::New(Method_getDirectory));
    target->Set("isOk", v8::FunctionTemplate::New(Method_isOk));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("getMessage", v8::FunctionTemplate::New(Method_getMessage));
}
//----------------------------------------
void sf_Ftp_DirectoryResponse::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("RestartMarkerReply"), v8::Number::New(110), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReadySoon"), v8::Number::New(120), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionAlreadyOpened"), v8::Number::New(125), v8::ReadOnly);
    target->Set(v8::String::New("OpeningDataConnection"), v8::Number::New(150), v8::ReadOnly);
    target->Set(v8::String::New("Ok"), v8::Number::New(200), v8::ReadOnly);
    target->Set(v8::String::New("PointlessCommand"), v8::Number::New(202), v8::ReadOnly);
    target->Set(v8::String::New("SystemStatus"), v8::Number::New(211), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryStatus"), v8::Number::New(212), v8::ReadOnly);
    target->Set(v8::String::New("FileStatus"), v8::Number::New(213), v8::ReadOnly);
    target->Set(v8::String::New("HelpMessage"), v8::Number::New(214), v8::ReadOnly);
    target->Set(v8::String::New("SystemType"), v8::Number::New(215), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReady"), v8::Number::New(220), v8::ReadOnly);
    target->Set(v8::String::New("ClosingConnection"), v8::Number::New(221), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionOpened"), v8::Number::New(225), v8::ReadOnly);
    target->Set(v8::String::New("ClosingDataConnection"), v8::Number::New(226), v8::ReadOnly);
    target->Set(v8::String::New("EnteringPassiveMode"), v8::Number::New(227), v8::ReadOnly);
    target->Set(v8::String::New("LoggedIn"), v8::Number::New(230), v8::ReadOnly);
    target->Set(v8::String::New("FileActionOk"), v8::Number::New(250), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryOk"), v8::Number::New(257), v8::ReadOnly);
    target->Set(v8::String::New("NeedPassword"), v8::Number::New(331), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToLogIn"), v8::Number::New(332), v8::ReadOnly);
    target->Set(v8::String::New("NeedInformation"), v8::Number::New(350), v8::ReadOnly);
    target->Set(v8::String::New("ServiceUnavailable"), v8::Number::New(421), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionUnavailable"), v8::Number::New(425), v8::ReadOnly);
    target->Set(v8::String::New("TransferAborted"), v8::Number::New(426), v8::ReadOnly);
    target->Set(v8::String::New("FileActionAborted"), v8::Number::New(450), v8::ReadOnly);
    target->Set(v8::String::New("LocalError"), v8::Number::New(451), v8::ReadOnly);
    target->Set(v8::String::New("InsufficientStorageSpace"), v8::Number::New(452), v8::ReadOnly);
    target->Set(v8::String::New("CommandUnknown"), v8::Number::New(500), v8::ReadOnly);
    target->Set(v8::String::New("ParametersUnknown"), v8::Number::New(501), v8::ReadOnly);
    target->Set(v8::String::New("CommandNotImplemented"), v8::Number::New(502), v8::ReadOnly);
    target->Set(v8::String::New("BadCommandSequence"), v8::Number::New(503), v8::ReadOnly);
    target->Set(v8::String::New("ParameterNotImplemented"), v8::Number::New(504), v8::ReadOnly);
    target->Set(v8::String::New("NotLoggedIn"), v8::Number::New(530), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToStore"), v8::Number::New(532), v8::ReadOnly);
    target->Set(v8::String::New("FileUnavailable"), v8::Number::New(550), v8::ReadOnly);
    target->Set(v8::String::New("PageTypeUnknown"), v8::Number::New(551), v8::ReadOnly);
    target->Set(v8::String::New("NotEnoughMemory"), v8::Number::New(552), v8::ReadOnly);
    target->Set(v8::String::New("FilenameNotAllowed"), v8::Number::New(553), v8::ReadOnly);
    target->Set(v8::String::New("InvalidResponse"), v8::Number::New(1000), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionFailed"), v8::Number::New(1001), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionClosed"), v8::Number::New(1002), v8::ReadOnly);
    target->Set(v8::String::New("InvalidFile"), v8::Number::New(1003), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_Ftp_ListingResponse::Bases = "sf::Ftp::ListingResponse\0sf::Ftp::Response\0\0";
const char *sf_Ftp_ListingResponse::ClassName = "sf::Ftp::ListingResponse";
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 0, 0, {}}
    };
    int FuncSize = 0;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Method_getFilenames(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getFilenames());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Method_isOk(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isOk());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp_ListingResponse::Method_getMessage(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMessage());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Ftp_ListingResponse::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Ftp_ListingResponse::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Ftp_ListingResponse::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("ListingResponse"), FO);
}
//----------------------------------------
void sf_Ftp_ListingResponse::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getFilenames", v8::FunctionTemplate::New(Method_getFilenames));
    target->Set("isOk", v8::FunctionTemplate::New(Method_isOk));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("getMessage", v8::FunctionTemplate::New(Method_getMessage));
}
//----------------------------------------
void sf_Ftp_ListingResponse::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("RestartMarkerReply"), v8::Number::New(110), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReadySoon"), v8::Number::New(120), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionAlreadyOpened"), v8::Number::New(125), v8::ReadOnly);
    target->Set(v8::String::New("OpeningDataConnection"), v8::Number::New(150), v8::ReadOnly);
    target->Set(v8::String::New("Ok"), v8::Number::New(200), v8::ReadOnly);
    target->Set(v8::String::New("PointlessCommand"), v8::Number::New(202), v8::ReadOnly);
    target->Set(v8::String::New("SystemStatus"), v8::Number::New(211), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryStatus"), v8::Number::New(212), v8::ReadOnly);
    target->Set(v8::String::New("FileStatus"), v8::Number::New(213), v8::ReadOnly);
    target->Set(v8::String::New("HelpMessage"), v8::Number::New(214), v8::ReadOnly);
    target->Set(v8::String::New("SystemType"), v8::Number::New(215), v8::ReadOnly);
    target->Set(v8::String::New("ServiceReady"), v8::Number::New(220), v8::ReadOnly);
    target->Set(v8::String::New("ClosingConnection"), v8::Number::New(221), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionOpened"), v8::Number::New(225), v8::ReadOnly);
    target->Set(v8::String::New("ClosingDataConnection"), v8::Number::New(226), v8::ReadOnly);
    target->Set(v8::String::New("EnteringPassiveMode"), v8::Number::New(227), v8::ReadOnly);
    target->Set(v8::String::New("LoggedIn"), v8::Number::New(230), v8::ReadOnly);
    target->Set(v8::String::New("FileActionOk"), v8::Number::New(250), v8::ReadOnly);
    target->Set(v8::String::New("DirectoryOk"), v8::Number::New(257), v8::ReadOnly);
    target->Set(v8::String::New("NeedPassword"), v8::Number::New(331), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToLogIn"), v8::Number::New(332), v8::ReadOnly);
    target->Set(v8::String::New("NeedInformation"), v8::Number::New(350), v8::ReadOnly);
    target->Set(v8::String::New("ServiceUnavailable"), v8::Number::New(421), v8::ReadOnly);
    target->Set(v8::String::New("DataConnectionUnavailable"), v8::Number::New(425), v8::ReadOnly);
    target->Set(v8::String::New("TransferAborted"), v8::Number::New(426), v8::ReadOnly);
    target->Set(v8::String::New("FileActionAborted"), v8::Number::New(450), v8::ReadOnly);
    target->Set(v8::String::New("LocalError"), v8::Number::New(451), v8::ReadOnly);
    target->Set(v8::String::New("InsufficientStorageSpace"), v8::Number::New(452), v8::ReadOnly);
    target->Set(v8::String::New("CommandUnknown"), v8::Number::New(500), v8::ReadOnly);
    target->Set(v8::String::New("ParametersUnknown"), v8::Number::New(501), v8::ReadOnly);
    target->Set(v8::String::New("CommandNotImplemented"), v8::Number::New(502), v8::ReadOnly);
    target->Set(v8::String::New("BadCommandSequence"), v8::Number::New(503), v8::ReadOnly);
    target->Set(v8::String::New("ParameterNotImplemented"), v8::Number::New(504), v8::ReadOnly);
    target->Set(v8::String::New("NotLoggedIn"), v8::Number::New(530), v8::ReadOnly);
    target->Set(v8::String::New("NeedAccountToStore"), v8::Number::New(532), v8::ReadOnly);
    target->Set(v8::String::New("FileUnavailable"), v8::Number::New(550), v8::ReadOnly);
    target->Set(v8::String::New("PageTypeUnknown"), v8::Number::New(551), v8::ReadOnly);
    target->Set(v8::String::New("NotEnoughMemory"), v8::Number::New(552), v8::ReadOnly);
    target->Set(v8::String::New("FilenameNotAllowed"), v8::Number::New(553), v8::ReadOnly);
    target->Set(v8::String::New("InvalidResponse"), v8::Number::New(1000), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionFailed"), v8::Number::New(1001), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionClosed"), v8::Number::New(1002), v8::ReadOnly);
    target->Set(v8::String::New("InvalidFile"), v8::Number::New(1003), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_Ftp::Bases = "sf::Ftp\0\0";
const char *sf_Ftp::ClassName = "sf::Ftp";
v8::Handle<v8::Value> sf_Ftp::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_connect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "server" }}},
    { 2, 2, {{ PT_CLASS, "server" }, { PT_NUMBER, "port" }}},
    { 3, 3, {{ PT_CLASS, "server" }, { PT_NUMBER, "port" }, { PT_CLASS, "timeout" }}}
    };
    int FuncSize = 3;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IpAddress* p0 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->connect(*p0));
            break;
        }
        case 2: {
            ::sf::IpAddress* p0 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->connect(*p0,p1));
            break;
        }
        case 3: {
            ::sf::IpAddress* p0 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
            ::sf::Time* p2 = CastToCPP< ::sf::Time* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->connect(*p0,p1,*p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_disconnect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->disconnect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_login(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_STRING, "name" }, { PT_STRING, "password" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->login());
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->login(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_keepAlive(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->keepAlive());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_getWorkingDirectory(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getWorkingDirectory());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_getDirectoryListing(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_STRING, "directory" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->getDirectoryListing());
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->getDirectoryListing(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_changeDirectory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "directory" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->changeDirectory(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_parentDirectory(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->parentDirectory());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_createDirectory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "name" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->createDirectory(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_deleteDirectory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "name" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->deleteDirectory(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_renameFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "file" }, { PT_STRING, "newname" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->renameFile(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_deleteFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "name" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->deleteFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_download(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "remotefile" }, { PT_STRING, "localpath" }}},
    { 2, 3, {{ PT_STRING, "remotefile" }, { PT_STRING, "localpath" }, { PT_NUMBER, "mode" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->download(p0,p1));
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Ftp::TransferMode p2 = CastToCPP< ::sf::Ftp::TransferMode >(ParamMatch.Params[2]);
            result = CastToJS(inst->download(p0,p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Ftp::Method_upload(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "localfile" }, { PT_STRING, "remotepath" }}},
    { 2, 3, {{ PT_STRING, "localfile" }, { PT_STRING, "remotepath" }, { PT_NUMBER, "mode" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->upload(p0,p1));
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Ftp::TransferMode p2 = CastToCPP< ::sf::Ftp::TransferMode >(ParamMatch.Params[2]);
            result = CastToJS(inst->upload(p0,p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Ftp::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Ftp::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Ftp::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Ftp"), FO);
}
//----------------------------------------
void sf_Ftp::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("connect", v8::FunctionTemplate::New(Method_connect));
    target->Set("disconnect", v8::FunctionTemplate::New(Method_disconnect));
    target->Set("login", v8::FunctionTemplate::New(Method_login));
    target->Set("keepAlive", v8::FunctionTemplate::New(Method_keepAlive));
    target->Set("getWorkingDirectory", v8::FunctionTemplate::New(Method_getWorkingDirectory));
    target->Set("getDirectoryListing", v8::FunctionTemplate::New(Method_getDirectoryListing));
    target->Set("changeDirectory", v8::FunctionTemplate::New(Method_changeDirectory));
    target->Set("parentDirectory", v8::FunctionTemplate::New(Method_parentDirectory));
    target->Set("createDirectory", v8::FunctionTemplate::New(Method_createDirectory));
    target->Set("deleteDirectory", v8::FunctionTemplate::New(Method_deleteDirectory));
    target->Set("renameFile", v8::FunctionTemplate::New(Method_renameFile));
    target->Set("deleteFile", v8::FunctionTemplate::New(Method_deleteFile));
    target->Set("download", v8::FunctionTemplate::New(Method_download));
    target->Set("upload", v8::FunctionTemplate::New(Method_upload));
}
//----------------------------------------
void sf_Ftp::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Binary"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Ascii"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Ebcdic"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
#endif
const char *sf_RenderTexture::Bases = "sf::RenderTexture\0sf::RenderTarget\0\0";
const char *sf_RenderTexture::ClassName = "sf::RenderTexture";
v8::Handle<v8::Value> sf_RenderTexture::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_create(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }}},
    { 2, 3, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_BOOLEAN, "depthbuffer" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->create(p0,p1));
            break;
        }
        case 2: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            bool p2 = CastToCPP< bool >(ParamMatch.Params[2]);
            result = CastToJS(inst->create(p0,p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_setSmooth(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "smooth" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setSmooth(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_isSmooth(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isSmooth());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_setActive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_BOOLEAN, "active" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->setActive());
            break;
        }
        case 2: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            result = CastToJS(inst->setActive(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_display(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->display();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_clear(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->clear();
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->clear(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_setView(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setView(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_getView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_getDefaultView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getDefaultView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_getViewport(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->getViewport(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_convertCoords(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "point" }}},
    { 2, 2, {{ PT_CLASS, "point" }, { PT_CLASS, "view" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0));
            break;
        }
        case 2: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::View* p1 = CastToCPP< ::sf::View* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_draw(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "drawable" }}},
    { 2, 2, {{ PT_CLASS, "drawable" }, { PT_CLASS, "states" }}},
    { 3, 3, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }}},
    { 4, 4, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }, { PT_CLASS, "states" }}}
    };
    int FuncSize = 4;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::RenderStates* p1 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            inst->draw(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            ::sf::RenderStates* p3 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_pushGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pushGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_popGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->popGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTexture::Method_resetGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->resetGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_RenderTexture::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_RenderTexture::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_RenderTexture::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("RenderTexture"), FO);
}
//----------------------------------------
void sf_RenderTexture::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("create", v8::FunctionTemplate::New(Method_create));
    target->Set("setSmooth", v8::FunctionTemplate::New(Method_setSmooth));
    target->Set("isSmooth", v8::FunctionTemplate::New(Method_isSmooth));
    target->Set("setActive", v8::FunctionTemplate::New(Method_setActive));
    target->Set("display", v8::FunctionTemplate::New(Method_display));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("setView", v8::FunctionTemplate::New(Method_setView));
    target->Set("getView", v8::FunctionTemplate::New(Method_getView));
    target->Set("getDefaultView", v8::FunctionTemplate::New(Method_getDefaultView));
    target->Set("getViewport", v8::FunctionTemplate::New(Method_getViewport));
    target->Set("convertCoords", v8::FunctionTemplate::New(Method_convertCoords));
    target->Set("draw", v8::FunctionTemplate::New(Method_draw));
    target->Set("pushGLStates", v8::FunctionTemplate::New(Method_pushGLStates));
    target->Set("popGLStates", v8::FunctionTemplate::New(Method_popGLStates));
    target->Set("resetGLStates", v8::FunctionTemplate::New(Method_resetGLStates));
}
//----------------------------------------
void sf_RenderTexture::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_SoundStream_Chunk::Bases = "sf::SoundStream::Chunk\0\0";
const char *sf_SoundStream_Chunk::ClassName = "sf::SoundStream::Chunk";
v8::Handle<v8::Value> sf_SoundStream_Chunk::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream_Chunk::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream_Chunk::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream_Chunk::Getter_samples(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::SoundStream::Chunk *inst = static_cast< ::sf::SoundStream::Chunk * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->samples);
}

void sf_SoundStream_Chunk::Setter_samples(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream_Chunk::Getter_sampleCount(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::SoundStream::Chunk *inst = static_cast< ::sf::SoundStream::Chunk * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->sampleCount);
}

void sf_SoundStream_Chunk::Setter_sampleCount(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::SoundStream::Chunk *inst = static_cast< ::sf::SoundStream::Chunk * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->sampleCount = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_SoundStream_Chunk::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundStream_Chunk::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundStream_Chunk::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Chunk"), FO);
}
//----------------------------------------
void sf_SoundStream_Chunk::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("samples"), Getter_samples, Setter_samples);
    target->SetAccessor(v8::String::New("sampleCount"), Getter_sampleCount, Setter_sampleCount);
}
//----------------------------------------
void sf_SoundStream_Chunk::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_SoundStream::Bases = "sf::SoundStream\0sf::SoundSource\0\0";
const char *sf_SoundStream::ClassName = "sf::SoundStream";
v8::Handle<v8::Value> sf_SoundStream::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_play(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->play();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_pause(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pause();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_stop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->stop();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getChannelCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getChannelCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getSampleRate(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleRate());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setPlayingOffset(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "timeoffset" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPlayingOffset(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getPlayingOffset(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPlayingOffset());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setLoop(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "loop" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setLoop(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getLoop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLoop());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setPitch(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "pitch" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setPitch(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setVolume(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "volume" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setVolume(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            inst->setPosition(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setRelativeToListener(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "relative" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setRelativeToListener(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setMinDistance(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "distance" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setMinDistance(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_setAttenuation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "attenuation" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setAttenuation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getPitch(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPitch());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getVolume(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getVolume());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_isRelativeToListener(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isRelativeToListener());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getMinDistance(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMinDistance());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundStream::Method_getAttenuation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getAttenuation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_SoundStream::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundStream::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundStream::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SoundStream"), FO);
}
//----------------------------------------
void sf_SoundStream::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("play", v8::FunctionTemplate::New(Method_play));
    target->Set("pause", v8::FunctionTemplate::New(Method_pause));
    target->Set("stop", v8::FunctionTemplate::New(Method_stop));
    target->Set("getChannelCount", v8::FunctionTemplate::New(Method_getChannelCount));
    target->Set("getSampleRate", v8::FunctionTemplate::New(Method_getSampleRate));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("setPlayingOffset", v8::FunctionTemplate::New(Method_setPlayingOffset));
    target->Set("getPlayingOffset", v8::FunctionTemplate::New(Method_getPlayingOffset));
    target->Set("setLoop", v8::FunctionTemplate::New(Method_setLoop));
    target->Set("getLoop", v8::FunctionTemplate::New(Method_getLoop));
    target->Set("setPitch", v8::FunctionTemplate::New(Method_setPitch));
    target->Set("setVolume", v8::FunctionTemplate::New(Method_setVolume));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRelativeToListener", v8::FunctionTemplate::New(Method_setRelativeToListener));
    target->Set("setMinDistance", v8::FunctionTemplate::New(Method_setMinDistance));
    target->Set("setAttenuation", v8::FunctionTemplate::New(Method_setAttenuation));
    target->Set("getPitch", v8::FunctionTemplate::New(Method_getPitch));
    target->Set("getVolume", v8::FunctionTemplate::New(Method_getVolume));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("isRelativeToListener", v8::FunctionTemplate::New(Method_isRelativeToListener));
    target->Set("getMinDistance", v8::FunctionTemplate::New(Method_getMinDistance));
    target->Set("getAttenuation", v8::FunctionTemplate::New(Method_getAttenuation));
}
//----------------------------------------
void sf_SoundStream::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Stopped"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Paused"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Playing"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_Http_Request::Bases = "sf::Http::Request\0\0";
const char *sf_Http_Request::ClassName = "sf::Http::Request";
v8::Handle<v8::Value> sf_Http_Request::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_STRING, "uri" }}},
    { 3, 2, {{ PT_STRING, "uri" }, { PT_NUMBER, "method" }}},
    { 4, 3, {{ PT_STRING, "uri" }, { PT_NUMBER, "method" }, { PT_STRING, "body" }}}
    };
    int FuncSize = 4;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                ::sf::Http::Request::Method p1 = CastToCPP< ::sf::Http::Request::Method >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                ::sf::Http::Request::Method p1 = CastToCPP< ::sf::Http::Request::Method >(ParamMatch.Params[1]);
                ::std::string p2 = CastToCPP< ::std::string >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Method_setField(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "field" }, { PT_STRING, "value" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            inst->setField(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Method_setMethod(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "method" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Http::Request::Method p0 = CastToCPP< ::sf::Http::Request::Method >(ParamMatch.Params[0]);
            inst->setMethod(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Method_setUri(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "uri" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            inst->setUri(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Method_setHttpVersion(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "major" }, { PT_NUMBER, "minor" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            inst->setHttpVersion(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Request::Method_setBody(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "body" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            inst->setBody(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Http_Request::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Http_Request::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Http_Request::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Request"), FO);
}
//----------------------------------------
void sf_Http_Request::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setField", v8::FunctionTemplate::New(Method_setField));
    target->Set("setMethod", v8::FunctionTemplate::New(Method_setMethod));
    target->Set("setUri", v8::FunctionTemplate::New(Method_setUri));
    target->Set("setHttpVersion", v8::FunctionTemplate::New(Method_setHttpVersion));
    target->Set("setBody", v8::FunctionTemplate::New(Method_setBody));
}
//----------------------------------------
void sf_Http_Request::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Get"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Post"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Head"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_Http_Response::Bases = "sf::Http::Response\0\0";
const char *sf_Http_Response::ClassName = "sf::Http::Response";
v8::Handle<v8::Value> sf_Http_Response::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Method_getField(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "field" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->getField(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Method_getMajorHttpVersion(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMajorHttpVersion());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Method_getMinorHttpVersion(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMinorHttpVersion());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http_Response::Method_getBody(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getBody());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Http_Response::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Http_Response::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Http_Response::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Response"), FO);
}
//----------------------------------------
void sf_Http_Response::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getField", v8::FunctionTemplate::New(Method_getField));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("getMajorHttpVersion", v8::FunctionTemplate::New(Method_getMajorHttpVersion));
    target->Set("getMinorHttpVersion", v8::FunctionTemplate::New(Method_getMinorHttpVersion));
    target->Set("getBody", v8::FunctionTemplate::New(Method_getBody));
}
//----------------------------------------
void sf_Http_Response::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Ok"), v8::Number::New(200), v8::ReadOnly);
    target->Set(v8::String::New("Created"), v8::Number::New(201), v8::ReadOnly);
    target->Set(v8::String::New("Accepted"), v8::Number::New(202), v8::ReadOnly);
    target->Set(v8::String::New("NoContent"), v8::Number::New(204), v8::ReadOnly);
    target->Set(v8::String::New("ResetContent"), v8::Number::New(205), v8::ReadOnly);
    target->Set(v8::String::New("PartialContent"), v8::Number::New(206), v8::ReadOnly);
    target->Set(v8::String::New("MultipleChoices"), v8::Number::New(300), v8::ReadOnly);
    target->Set(v8::String::New("MovedPermanently"), v8::Number::New(301), v8::ReadOnly);
    target->Set(v8::String::New("MovedTemporarily"), v8::Number::New(302), v8::ReadOnly);
    target->Set(v8::String::New("NotModified"), v8::Number::New(304), v8::ReadOnly);
    target->Set(v8::String::New("BadRequest"), v8::Number::New(400), v8::ReadOnly);
    target->Set(v8::String::New("Unauthorized"), v8::Number::New(401), v8::ReadOnly);
    target->Set(v8::String::New("Forbidden"), v8::Number::New(403), v8::ReadOnly);
    target->Set(v8::String::New("NotFound"), v8::Number::New(404), v8::ReadOnly);
    target->Set(v8::String::New("RangeNotSatisfiable"), v8::Number::New(407), v8::ReadOnly);
    target->Set(v8::String::New("InternalServerError"), v8::Number::New(500), v8::ReadOnly);
    target->Set(v8::String::New("NotImplemented"), v8::Number::New(501), v8::ReadOnly);
    target->Set(v8::String::New("BadGateway"), v8::Number::New(502), v8::ReadOnly);
    target->Set(v8::String::New("ServiceNotAvailable"), v8::Number::New(503), v8::ReadOnly);
    target->Set(v8::String::New("GatewayTimeout"), v8::Number::New(504), v8::ReadOnly);
    target->Set(v8::String::New("VersionNotSupported"), v8::Number::New(505), v8::ReadOnly);
    target->Set(v8::String::New("InvalidResponse"), v8::Number::New(1000), v8::ReadOnly);
    target->Set(v8::String::New("ConnectionFailed"), v8::Number::New(1001), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_Http::Bases = "sf::Http\0\0";
const char *sf_Http::ClassName = "sf::Http";
v8::Handle<v8::Value> sf_Http::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_STRING, "host" }}},
    { 3, 2, {{ PT_STRING, "host" }, { PT_NUMBER, "port" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http::Method_setHost(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "host" }}},
    { 2, 2, {{ PT_STRING, "host" }, { PT_NUMBER, "port" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            inst->setHost(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
            inst->setHost(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Http::Method_sendRequest(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "request" }}},
    { 2, 2, {{ PT_CLASS, "request" }, { PT_CLASS, "timeout" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Http::Request* p0 = CastToCPP< ::sf::Http::Request* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->sendRequest(*p0));
            break;
        }
        case 2: {
            ::sf::Http::Request* p0 = CastToCPP< ::sf::Http::Request* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Time* p1 = CastToCPP< ::sf::Time* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->sendRequest(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Http::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Http::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Http::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Http"), FO);
}
//----------------------------------------
void sf_Http::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setHost", v8::FunctionTemplate::New(Method_setHost));
    target->Set("sendRequest", v8::FunctionTemplate::New(Method_sendRequest));
}
//----------------------------------------
void sf_Http::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#endif
const char *sf_CircleShape::Bases = "sf::CircleShape\0sf::Shape\0sf::Drawable\0\0";
const char *sf_CircleShape::ClassName = "sf::CircleShape";
v8::Handle<v8::Value> sf_CircleShape::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "radius" }}},
    { 3, 2, {{ PT_NUMBER, "radius" }, { PT_NUMBER, "pointcount" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setRadius(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "radius" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRadius(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getRadius(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRadius());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setPointCount(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "count" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->setPointCount(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getPointCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPointCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "index" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getPoint(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "texture" }}},
    { 2, 2, {{ PT_CLASS, "texture" }, { PT_BOOLEAN, "resetrect" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTexture(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p1 = CastToCPP< bool >(ParamMatch.Params[1]);
            inst->setTexture(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setTextureRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rect" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IntRect* p0 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTextureRect(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setFillColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setFillColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setOutlineColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOutlineColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setOutlineThickness(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "thickness" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setOutlineThickness(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getTextureRect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTextureRect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getFillColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getFillColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getOutlineColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOutlineColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getOutlineThickness(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getOutlineThickness());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_CircleShape::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_CircleShape::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_CircleShape::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_CircleShape::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("CircleShape"), FO);
}
//----------------------------------------
void sf_CircleShape::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setRadius", v8::FunctionTemplate::New(Method_setRadius));
    target->Set("getRadius", v8::FunctionTemplate::New(Method_getRadius));
    target->Set("setPointCount", v8::FunctionTemplate::New(Method_setPointCount));
    target->Set("getPointCount", v8::FunctionTemplate::New(Method_getPointCount));
    target->Set("getPoint", v8::FunctionTemplate::New(Method_getPoint));
    target->Set("setTexture", v8::FunctionTemplate::New(Method_setTexture));
    target->Set("setTextureRect", v8::FunctionTemplate::New(Method_setTextureRect));
    target->Set("setFillColor", v8::FunctionTemplate::New(Method_setFillColor));
    target->Set("setOutlineColor", v8::FunctionTemplate::New(Method_setOutlineColor));
    target->Set("setOutlineThickness", v8::FunctionTemplate::New(Method_setOutlineThickness));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("getTextureRect", v8::FunctionTemplate::New(Method_getTextureRect));
    target->Set("getFillColor", v8::FunctionTemplate::New(Method_getFillColor));
    target->Set("getOutlineColor", v8::FunctionTemplate::New(Method_getOutlineColor));
    target->Set("getOutlineThickness", v8::FunctionTemplate::New(Method_getOutlineThickness));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_CircleShape::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Vector3i::Bases = "sf::Vector3i\0\0";
const char *sf_Vector3i::ClassName = "sf::Vector3i";
v8::Handle<v8::Value> sf_Vector3i::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                int p0 = CastToCPP< int >(ParamMatch.Params[0]);
                int p1 = CastToCPP< int >(ParamMatch.Params[1]);
                int p2 = CastToCPP< int >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3i::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3i::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3i::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Vector3i::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3i::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Vector3i::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3i::Getter_z(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->z);
}

void sf_Vector3i::Setter_z(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3i *inst = static_cast< ::sf::Vector3i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->z = CastToCPP< int >(value);
}
//----------------------------------------
void sf_Vector3i::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vector3i::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vector3i::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vector3i"), FO);
}
//----------------------------------------
void sf_Vector3i::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
    target->SetAccessor(v8::String::New("z"), Getter_z, Setter_z);
}
//----------------------------------------
void sf_Vector3i::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_VertexArray::Bases = "sf::VertexArray\0sf::Drawable\0\0";
const char *sf_VertexArray::ClassName = "sf::VertexArray";
v8::Handle<v8::Value> sf_VertexArray::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "type" }}},
    { 3, 2, {{ PT_NUMBER, "type" }, { PT_NUMBER, "vertexcount" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::PrimitiveType p0 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::PrimitiveType p0 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_getVertexCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getVertexCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_clear(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->clear();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_resize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "vertexcount" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->resize(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_append(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "vertex" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->append(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_setPrimitiveType(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "type" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::PrimitiveType p0 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[0]);
            inst->setPrimitiveType(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_getPrimitiveType(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPrimitiveType());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_VertexArray::Method_getBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_VertexArray::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_VertexArray::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_VertexArray::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("VertexArray"), FO);
}
//----------------------------------------
void sf_VertexArray::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getVertexCount", v8::FunctionTemplate::New(Method_getVertexCount));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("resize", v8::FunctionTemplate::New(Method_resize));
    target->Set("append", v8::FunctionTemplate::New(Method_append));
    target->Set("setPrimitiveType", v8::FunctionTemplate::New(Method_setPrimitiveType));
    target->Set("getPrimitiveType", v8::FunctionTemplate::New(Method_getPrimitiveType));
    target->Set("getBounds", v8::FunctionTemplate::New(Method_getBounds));
}
//----------------------------------------
void sf_VertexArray::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_Packet::Bases = "sf::Packet\0\0";
const char *sf_Packet::ClassName = "sf::Packet";
v8::Handle<v8::Value> sf_Packet::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Method_append(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "sizeinbytes" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            inst->append(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Method_clear(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->clear();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Method_getData(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getData());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Method_getDataSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getDataSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Packet::Method_endOfPacket(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->endOfPacket());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Packet::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Packet::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Packet::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Packet"), FO);
}
//----------------------------------------
void sf_Packet::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("append", v8::FunctionTemplate::New(Method_append));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("getData", v8::FunctionTemplate::New(Method_getData));
    target->Set("getDataSize", v8::FunctionTemplate::New(Method_getDataSize));
    target->Set("endOfPacket", v8::FunctionTemplate::New(Method_endOfPacket));
}
//----------------------------------------
void sf_Packet::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#endif
const char *sf_Text::Bases = "sf::Text\0sf::Drawable\0\0";
const char *sf_Text::ClassName = "sf::Text";
v8::Handle<v8::Value> sf_Text::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "string" }}},
    { 3, 2, {{ PT_CLASS, "string" }, { PT_CLASS, "font" }}},
    { 4, 3, {{ PT_CLASS, "string" }, { PT_CLASS, "font" }, { PT_NUMBER, "charactersize" }}}
    };
    int FuncSize = 4;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Font* p1 = CastToCPP< ::sf::Font* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Font* p1 = CastToCPP< ::sf::Font* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(*p0,*p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setString(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "string" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setString(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setFont(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "font" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Font* p0 = CastToCPP< ::sf::Font* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setFont(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setCharacterSize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "size" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->setCharacterSize(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setStyle(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "style" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Uint32 p0 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[0]);
            inst->setStyle(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getString(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getString());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getFont(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getFont());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getCharacterSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getCharacterSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getStyle(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStyle());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_findCharacterPos(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "index" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->findCharacterPos(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Text::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Text::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Text::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Text::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Text"), FO);
}
//----------------------------------------
void sf_Text::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setString", v8::FunctionTemplate::New(Method_setString));
    target->Set("setFont", v8::FunctionTemplate::New(Method_setFont));
    target->Set("setCharacterSize", v8::FunctionTemplate::New(Method_setCharacterSize));
    target->Set("setStyle", v8::FunctionTemplate::New(Method_setStyle));
    target->Set("setColor", v8::FunctionTemplate::New(Method_setColor));
    target->Set("getString", v8::FunctionTemplate::New(Method_getString));
    target->Set("getFont", v8::FunctionTemplate::New(Method_getFont));
    target->Set("getCharacterSize", v8::FunctionTemplate::New(Method_getCharacterSize));
    target->Set("getStyle", v8::FunctionTemplate::New(Method_getStyle));
    target->Set("getColor", v8::FunctionTemplate::New(Method_getColor));
    target->Set("findCharacterPos", v8::FunctionTemplate::New(Method_findCharacterPos));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_Text::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Regular"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Bold"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Italic"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("Underlined"), v8::Number::New(4), v8::ReadOnly);
}
//----------------------------------------
const char *sf_Vertex::Bases = "sf::Vertex\0\0";
const char *sf_Vertex::ClassName = "sf::Vertex";
v8::Handle<v8::Value> sf_Vertex::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "theposition" }}},
    { 3, 2, {{ PT_CLASS, "theposition" }, { PT_CLASS, "thecolor" }}},
    { 4, 2, {{ PT_CLASS, "theposition" }, { PT_CLASS, "thetexcoords" }}},
    { 5, 3, {{ PT_CLASS, "theposition" }, { PT_CLASS, "thecolor" }, { PT_CLASS, "thetexcoords" }}}
    };
    int FuncSize = 5;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Color* p1 = CastToCPP< ::sf::Color* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Color* p1 = CastToCPP< ::sf::Color* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Vector2f* p2 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[2]);
                if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1,*p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vertex::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vertex::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vertex::Getter_position(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->position);
}

void sf_Vertex::Setter_position(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->position = CastToCPP< ::sf::Vector2<float> >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vertex::Getter_color(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->color);
}

void sf_Vertex::Setter_color(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->color = CastToCPP< ::sf::Color >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vertex::Getter_texCoords(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->texCoords);
}

void sf_Vertex::Setter_texCoords(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vertex *inst = static_cast< ::sf::Vertex * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->texCoords = CastToCPP< ::sf::Vector2<float> >(value);
}
//----------------------------------------
void sf_Vertex::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vertex::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vertex::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vertex"), FO);
}
//----------------------------------------
void sf_Vertex::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("position"), Getter_position, Setter_position);
    target->SetAccessor(v8::String::New("color"), Getter_color, Setter_color);
    target->SetAccessor(v8::String::New("texCoords"), Getter_texCoords, Setter_texCoords);
}
//----------------------------------------
void sf_Vertex::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Shader_CurrentTextureType::Bases = "sf::Shader::CurrentTextureType\0\0";
const char *sf_Shader_CurrentTextureType::ClassName = "sf::Shader::CurrentTextureType";
v8::Handle<v8::Value> sf_Shader_CurrentTextureType::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader_CurrentTextureType::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader_CurrentTextureType::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Shader_CurrentTextureType::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Shader_CurrentTextureType::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Shader_CurrentTextureType::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("CurrentTextureType"), FO);
}
//----------------------------------------
void sf_Shader_CurrentTextureType::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Shader_CurrentTextureType::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Shader::Bases = "sf::Shader\0\0";
const char *sf_Shader::ClassName = "sf::Shader";
v8::Handle<v8::Value> sf_Shader::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_loadFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "filename" }, { PT_NUMBER, "type" }}},
    { 2, 2, {{ PT_STRING, "vertexshaderfilename" }, { PT_STRING, "fragmentshaderfilename" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Shader::Type p1 = CastToCPP< ::sf::Shader::Type >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromFile(p0,p1));
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromFile(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_loadFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "shader" }, { PT_NUMBER, "type" }}},
    { 2, 2, {{ PT_STRING, "vertexshader" }, { PT_STRING, "fragmentshader" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Shader::Type p1 = CastToCPP< ::sf::Shader::Type >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_loadFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_CLASS, "stream" }, { PT_NUMBER, "type" }}},
    { 2, 2, {{ PT_CLASS, "vertexshaderstream" }, { PT_CLASS, "fragmentshaderstream" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Shader::Type p1 = CastToCPP< ::sf::Shader::Type >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromStream(*p0,p1));
            break;
        }
        case 2: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::InputStream* p1 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_setParameter(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_STRING, "name" }, { PT_NUMBER, "x" }}},
    { 2, 3, {{ PT_STRING, "name" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 3, 4, {{ PT_STRING, "name" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 4, 5, {{ PT_STRING, "name" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }, { PT_NUMBER, "w" }}},
    { 5, 2, {{ PT_STRING, "name" }, { PT_CLASS, "vector" }}},
    { 6, 2, {{ PT_STRING, "name" }, { PT_CLASS, "vector" }}},
    { 7, 2, {{ PT_STRING, "name" }, { PT_CLASS, "color" }}},
    { 8, 2, {{ PT_STRING, "name" }, { PT_CLASS, "transform" }}},
    { 9, 2, {{ PT_STRING, "name" }, { PT_CLASS, "texture" }}},
    { 10, 2, {{ PT_STRING, "name" }, { PT_CLASS, "" }}}
    };
    int FuncSize = 10;
    Match<5> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setParameter(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            inst->setParameter(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            float p3 = CastToCPP< float >(ParamMatch.Params[3]);
            inst->setParameter(p0,p1,p2,p3);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            float p3 = CastToCPP< float >(ParamMatch.Params[3]);
            float p4 = CastToCPP< float >(ParamMatch.Params[4]);
            inst->setParameter(p0,p1,p2,p3,p4);
            result = v8::Undefined();
            break;
        }
        case 5: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 6: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Vector3f* p1 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 7: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Color* p1 = CastToCPP< ::sf::Color* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 8: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Transform* p1 = CastToCPP< ::sf::Transform* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 9: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Texture* p1 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 10: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::Shader::CurrentTextureType* p1 = CastToCPP< ::sf::Shader::CurrentTextureType* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setParameter(p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_bind(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->bind();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_unbind(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->unbind();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Method_isAvailable(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::Shader::isAvailable());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shader::Getter_CurrentTexture(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    return CastToJS(::sf::Shader::CurrentTexture);
}

void sf_Shader::Setter_CurrentTexture(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Shader::CurrentTexture = CastToCPP< ::sf::Shader::CurrentTextureType >(value);
}
//----------------------------------------
void sf_Shader::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Shader::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Shader::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Shader"), FO);
}
//----------------------------------------
void sf_Shader::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("loadFromFile", v8::FunctionTemplate::New(Method_loadFromFile));
    target->Set("loadFromMemory", v8::FunctionTemplate::New(Method_loadFromMemory));
    target->Set("loadFromStream", v8::FunctionTemplate::New(Method_loadFromStream));
    target->Set("setParameter", v8::FunctionTemplate::New(Method_setParameter));
    target->Set("bind", v8::FunctionTemplate::New(Method_bind));
    target->Set("unbind", v8::FunctionTemplate::New(Method_unbind));
    target->SetAccessor(v8::String::New("CurrentTexture"), Getter_CurrentTexture, Setter_CurrentTexture);
}
//----------------------------------------
void sf_Shader::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isAvailable"), v8::FunctionTemplate::New(Method_isAvailable));
    target->Set(v8::String::New("Vertex"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Fragment"), v8::Number::New(1), v8::ReadOnly);
}
//----------------------------------------
const char *sf_InputStream::Bases = "sf::InputStream\0\0";
const char *sf_InputStream::ClassName = "sf::InputStream";
v8::Handle<v8::Value> sf_InputStream::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_InputStream::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_InputStream::Method_read(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Int64 p1 = CastToCPP< ::sf::Int64 >(ParamMatch.Params[1]);
            result = CastToJS(inst->read(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_InputStream::Method_seek(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "position" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Int64 p0 = CastToCPP< ::sf::Int64 >(ParamMatch.Params[0]);
            result = CastToJS(inst->seek(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_InputStream::Method_tell(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->tell());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_InputStream::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_InputStream::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_InputStream::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_InputStream::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("InputStream"), FO);
}
//----------------------------------------
void sf_InputStream::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("read", v8::FunctionTemplate::New(Method_read));
    target->Set("seek", v8::FunctionTemplate::New(Method_seek));
    target->Set("tell", v8::FunctionTemplate::New(Method_tell));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
}
//----------------------------------------
void sf_InputStream::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_IntRect::Bases = "sf::IntRect\0\0";
const char *sf_IntRect::ClassName = "sf::IntRect";
v8::Handle<v8::Value> sf_IntRect::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 4, {{ PT_NUMBER, "rectleft" }, { PT_NUMBER, "recttop" }, { PT_NUMBER, "rectwidth" }, { PT_NUMBER, "rectheight" }}},
    { 3, 2, {{ PT_CLASS, "position" }, { PT_CLASS, "size" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                int p0 = CastToCPP< int >(ParamMatch.Params[0]);
                int p1 = CastToCPP< int >(ParamMatch.Params[1]);
                int p2 = CastToCPP< int >(ParamMatch.Params[2]);
                int p3 = CastToCPP< int >(ParamMatch.Params[3]);
                MyClass *inst = new MyClass(p0,p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Vector2<int>* p0 = CastToCPP< ::sf::Vector2<int>* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Vector2<int>* p1 = CastToCPP< ::sf::Vector2<int>* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Method_contains(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "point" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            int p0 = CastToCPP< int >(ParamMatch.Params[0]);
            int p1 = CastToCPP< int >(ParamMatch.Params[1]);
            result = CastToJS(inst->contains(p0,p1));
            break;
        }
        case 2: {
            ::sf::Vector2<int>* p0 = CastToCPP< ::sf::Vector2<int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->contains(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Method_intersects(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rectangle" }}},
    { 2, 2, {{ PT_CLASS, "rectangle" }, { PT_CLASS, "intersection" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Rect<int>* p0 = CastToCPP< ::sf::Rect<int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->intersects(*p0));
            break;
        }
        case 2: {
            ::sf::Rect<int>* p0 = CastToCPP< ::sf::Rect<int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Rect<int>* p1 = CastToCPP< ::sf::Rect<int>* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->intersects(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Getter_left(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->left);
}

void sf_IntRect::Setter_left(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->left = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Getter_top(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->top);
}

void sf_IntRect::Setter_top(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->top = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->width);
}

void sf_IntRect::Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->width = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IntRect::Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->height);
}

void sf_IntRect::Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::IntRect *inst = static_cast< ::sf::IntRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->height = CastToCPP< int >(value);
}
//----------------------------------------
void sf_IntRect::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_IntRect::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_IntRect::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("IntRect"), FO);
}
//----------------------------------------
void sf_IntRect::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("contains", v8::FunctionTemplate::New(Method_contains));
    target->Set("intersects", v8::FunctionTemplate::New(Method_intersects));
    target->SetAccessor(v8::String::New("left"), Getter_left, Setter_left);
    target->SetAccessor(v8::String::New("top"), Getter_top, Setter_top);
    target->SetAccessor(v8::String::New("width"), Getter_width, Setter_width);
    target->SetAccessor(v8::String::New("height"), Getter_height, Setter_height);
}
//----------------------------------------
void sf_IntRect::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_String::Bases = "sf::String\0\0";
const char *sf_String::ClassName = "sf::String";
v8::Handle<v8::Value> sf_String::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "ansichar" }}},
    { 3, 1, {{ PT_NUMBER, "widechar" }}},
    { 4, 1, {{ PT_NUMBER, "utf32char" }}},
    { 5, 1, {{ PT_STRING, "ansistring" }}},
    { 6, 1, {{ PT_STRING, "ansistring" }}},
    { 7, 1, {{ PT_STRING, "widestring" }}},
    { 8, 1, {{ PT_STRING, "widestring" }}},
    { 9, 1, {{ PT_POINTER, "utf32string" }}}
    };
    int FuncSize = 9;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                char p0 = CastToCPP< char >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                wchar_t p0 = CastToCPP< wchar_t >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::Uint32 p0 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                std::string p0 = CastToCPP< std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0.c_str());
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 6: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 7: {
                std::wstring p0 = CastToCPP< std::wstring >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0.c_str());
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 8: {
                ::std::wstring p0 = CastToCPP< ::std::wstring >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 9: {
                unsigned int* p0 = CastToCPP< unsigned int* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_toAnsiString(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->toAnsiString());
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_toWideString(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->toWideString());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_clear(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->clear();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_isEmpty(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isEmpty());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_erase(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "position" }}},
    { 2, 2, {{ PT_NUMBER, "position" }, { PT_NUMBER, "count" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->erase(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            inst->erase(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_insert(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "position" }, { PT_CLASS, "str" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            ::sf::String* p1 = CastToCPP< ::sf::String* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->insert(p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_find(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "str" }}},
    { 2, 2, {{ PT_CLASS, "str" }, { PT_NUMBER, "start" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->find(*p0));
            break;
        }
        case 2: {
            ::sf::String* p0 = CastToCPP< ::sf::String* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->find(*p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Method_getData(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getData());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_String::Getter_InvalidPos(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    return CastToJS(::sf::String::InvalidPos);
}

void sf_String::Setter_InvalidPos(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
}
//----------------------------------------
void sf_String::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_String::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_String::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("String"), FO);
}
//----------------------------------------
void sf_String::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->Set("toAnsiString", v8::FunctionTemplate::New(Method_toAnsiString));
    target->Set("toWideString", v8::FunctionTemplate::New(Method_toWideString));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("isEmpty", v8::FunctionTemplate::New(Method_isEmpty));
    target->Set("erase", v8::FunctionTemplate::New(Method_erase));
    target->Set("insert", v8::FunctionTemplate::New(Method_insert));
    target->Set("find", v8::FunctionTemplate::New(Method_find));
    target->Set("getData", v8::FunctionTemplate::New(Method_getData));
    target->SetAccessor(v8::String::New("InvalidPos"), Getter_InvalidPos, Setter_InvalidPos);
}
//----------------------------------------
void sf_String::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_RenderStates::Bases = "sf::RenderStates\0\0";
const char *sf_RenderStates::ClassName = "sf::RenderStates";
v8::Handle<v8::Value> sf_RenderStates::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "theblendmode" }}},
    { 3, 1, {{ PT_CLASS, "thetransform" }}},
    { 4, 1, {{ PT_CLASS, "thetexture" }}},
    { 5, 1, {{ PT_CLASS, "theshader" }}},
    { 6, 4, {{ PT_NUMBER, "theblendmode" }, { PT_CLASS, "thetransform" }, { PT_CLASS, "thetexture" }, { PT_CLASS, "theshader" }}}
    };
    int FuncSize = 6;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::BlendMode p0 = CastToCPP< ::sf::BlendMode >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Transform* p0 = CastToCPP< ::sf::Transform* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                ::sf::Shader* p0 = CastToCPP< ::sf::Shader* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 6: {
                ::sf::BlendMode p0 = CastToCPP< ::sf::BlendMode >(ParamMatch.Params[0]);
                ::sf::Transform* p1 = CastToCPP< ::sf::Transform* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Texture* p2 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[2]);
                if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Shader* p3 = CastToCPP< ::sf::Shader* >(ParamMatch.Params[3]);
                if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0,*p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Getter_blendMode(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->blendMode);
}

void sf_RenderStates::Setter_blendMode(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->blendMode = CastToCPP< ::sf::BlendMode >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Getter_transform(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->transform);
}

void sf_RenderStates::Setter_transform(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->transform = CastToCPP< ::sf::Transform >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Getter_texture(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS2(*inst->texture);
}

void sf_RenderStates::Setter_texture(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderStates::Getter_shader(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::RenderStates *inst = static_cast< ::sf::RenderStates * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS2(*inst->shader);
}

void sf_RenderStates::Setter_shader(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
}
//----------------------------------------
//----------------------------------------
void sf_RenderStates::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_RenderStates::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_RenderStates::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("RenderStates"), FO);
}
//----------------------------------------
void sf_RenderStates::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("blendMode"), Getter_blendMode, Setter_blendMode);
    target->SetAccessor(v8::String::New("transform"), Getter_transform, Setter_transform);
    target->SetAccessor(v8::String::New("texture"), Getter_texture, Setter_texture);
    target->SetAccessor(v8::String::New("shader"), Getter_shader, Setter_shader);
}
//----------------------------------------
void sf_RenderStates::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Default"), CastToJS2(::sf::RenderStates::Default));
}
//----------------------------------------
const char *sf_VideoMode::Bases = "sf::VideoMode\0\0";
const char *sf_VideoMode::ClassName = "sf::VideoMode";
v8::Handle<v8::Value> sf_VideoMode::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_NUMBER, "modewidth" }, { PT_NUMBER, "modeheight" }}},
    { 3, 3, {{ PT_NUMBER, "modewidth" }, { PT_NUMBER, "modeheight" }, { PT_NUMBER, "modebitsperpixel" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Method_isValid(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isValid());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->width);
}

void sf_VideoMode::Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->width = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->height);
}

void sf_VideoMode::Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->height = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Getter_bitsPerPixel(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->bitsPerPixel);
}

void sf_VideoMode::Setter_bitsPerPixel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::VideoMode *inst = static_cast< ::sf::VideoMode * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->bitsPerPixel = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Method_getDesktopMode(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::VideoMode::getDesktopMode());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_VideoMode::Method_getFullscreenModes(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::VideoMode::getFullscreenModes());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_VideoMode::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_VideoMode::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_VideoMode::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("VideoMode"), FO);
}
//----------------------------------------
void sf_VideoMode::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("isValid", v8::FunctionTemplate::New(Method_isValid));
    target->SetAccessor(v8::String::New("width"), Getter_width, Setter_width);
    target->SetAccessor(v8::String::New("height"), Getter_height, Setter_height);
    target->SetAccessor(v8::String::New("bitsPerPixel"), Getter_bitsPerPixel, Setter_bitsPerPixel);
}
//----------------------------------------
void sf_VideoMode::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("getDesktopMode"), v8::FunctionTemplate::New(Method_getDesktopMode));
    target->Set(v8::String::New("getFullscreenModes"), v8::FunctionTemplate::New(Method_getFullscreenModes));
}
//----------------------------------------
const char *sf_SoundBufferRecorder::Bases = "sf::SoundBufferRecorder\0sf::SoundRecorder\0\0";
const char *sf_SoundBufferRecorder::ClassName = "sf::SoundBufferRecorder";
v8::Handle<v8::Value> sf_SoundBufferRecorder::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Method_getBuffer(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getBuffer());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Method_start(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "samplerate" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->start();
            result = v8::Undefined();
            break;
        }
        case 2: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->start(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Method_stop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->stop();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Method_getSampleRate(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleRate());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBufferRecorder::Method_isAvailable(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::SoundBufferRecorder::isAvailable());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_SoundBufferRecorder::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundBufferRecorder::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundBufferRecorder::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SoundBufferRecorder"), FO);
}
//----------------------------------------
void sf_SoundBufferRecorder::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getBuffer", v8::FunctionTemplate::New(Method_getBuffer));
    target->Set("start", v8::FunctionTemplate::New(Method_start));
    target->Set("stop", v8::FunctionTemplate::New(Method_stop));
    target->Set("getSampleRate", v8::FunctionTemplate::New(Method_getSampleRate));
}
//----------------------------------------
void sf_SoundBufferRecorder::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isAvailable"), v8::FunctionTemplate::New(Method_isAvailable));
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_Socket::Bases = "sf::Socket\0\0";
const char *sf_Socket::ClassName = "sf::Socket";
v8::Handle<v8::Value> sf_Socket::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sNotCreated)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_Socket::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Socket::Method_setBlocking(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "blocking" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setBlocking(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Socket::Method_isBlocking(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isBlocking());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Socket::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Socket::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Socket::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Socket"), FO);
}
//----------------------------------------
void sf_Socket::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setBlocking", v8::FunctionTemplate::New(Method_setBlocking));
    target->Set("isBlocking", v8::FunctionTemplate::New(Method_isBlocking));
}
//----------------------------------------
void sf_Socket::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Done"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("NotReady"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Disconnected"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("Error"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("AnyPort"), v8::Number::New(0), v8::ReadOnly);
}
//----------------------------------------
#endif
const char *sf_Sound::Bases = "sf::Sound\0sf::SoundSource\0\0";
const char *sf_Sound::ClassName = "sf::Sound";
v8::Handle<v8::Value> sf_Sound::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "buffer" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::SoundBuffer* p0 = CastToCPP< ::sf::SoundBuffer* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_play(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->play();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_pause(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pause();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_stop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->stop();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setBuffer(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "buffer" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::SoundBuffer* p0 = CastToCPP< ::sf::SoundBuffer* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setBuffer(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setLoop(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "loop" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setLoop(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setPlayingOffset(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "timeoffset" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPlayingOffset(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getBuffer(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getBuffer());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getLoop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLoop());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getPlayingOffset(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPlayingOffset());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_resetBuffer(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->resetBuffer();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setPitch(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "pitch" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setPitch(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setVolume(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "volume" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setVolume(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            inst->setPosition(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setRelativeToListener(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "relative" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setRelativeToListener(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setMinDistance(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "distance" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setMinDistance(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_setAttenuation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "attenuation" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setAttenuation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getPitch(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPitch());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getVolume(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getVolume());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_isRelativeToListener(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isRelativeToListener());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getMinDistance(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMinDistance());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sound::Method_getAttenuation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getAttenuation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Sound::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Sound::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Sound::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Sound"), FO);
}
//----------------------------------------
void sf_Sound::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("play", v8::FunctionTemplate::New(Method_play));
    target->Set("pause", v8::FunctionTemplate::New(Method_pause));
    target->Set("stop", v8::FunctionTemplate::New(Method_stop));
    target->Set("setBuffer", v8::FunctionTemplate::New(Method_setBuffer));
    target->Set("setLoop", v8::FunctionTemplate::New(Method_setLoop));
    target->Set("setPlayingOffset", v8::FunctionTemplate::New(Method_setPlayingOffset));
    target->Set("getBuffer", v8::FunctionTemplate::New(Method_getBuffer));
    target->Set("getLoop", v8::FunctionTemplate::New(Method_getLoop));
    target->Set("getPlayingOffset", v8::FunctionTemplate::New(Method_getPlayingOffset));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("resetBuffer", v8::FunctionTemplate::New(Method_resetBuffer));
    target->Set("setPitch", v8::FunctionTemplate::New(Method_setPitch));
    target->Set("setVolume", v8::FunctionTemplate::New(Method_setVolume));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRelativeToListener", v8::FunctionTemplate::New(Method_setRelativeToListener));
    target->Set("setMinDistance", v8::FunctionTemplate::New(Method_setMinDistance));
    target->Set("setAttenuation", v8::FunctionTemplate::New(Method_setAttenuation));
    target->Set("getPitch", v8::FunctionTemplate::New(Method_getPitch));
    target->Set("getVolume", v8::FunctionTemplate::New(Method_getVolume));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("isRelativeToListener", v8::FunctionTemplate::New(Method_isRelativeToListener));
    target->Set("getMinDistance", v8::FunctionTemplate::New(Method_getMinDistance));
    target->Set("getAttenuation", v8::FunctionTemplate::New(Method_getAttenuation));
}
//----------------------------------------
void sf_Sound::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Stopped"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Paused"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Playing"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
const char *sf_Music::Bases = "sf::Music\0sf::SoundStream\0sf::SoundSource\0\0";
const char *sf_Music::ClassName = "sf::Music";
v8::Handle<v8::Value> sf_Music::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_openFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->openFromFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_openFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "sizeinbytes" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->openFromMemory(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_openFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "stream" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->openFromStream(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getDuration(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getDuration());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_play(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->play();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_pause(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pause();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_stop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->stop();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getChannelCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getChannelCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getSampleRate(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleRate());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getStatus(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getStatus());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setPlayingOffset(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "timeoffset" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPlayingOffset(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getPlayingOffset(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPlayingOffset());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setLoop(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "loop" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setLoop(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getLoop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLoop());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setPitch(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "pitch" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setPitch(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setVolume(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "volume" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setVolume(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            inst->setPosition(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setRelativeToListener(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "relative" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setRelativeToListener(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setMinDistance(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "distance" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setMinDistance(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_setAttenuation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "attenuation" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setAttenuation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getPitch(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPitch());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getVolume(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getVolume());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_isRelativeToListener(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isRelativeToListener());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getMinDistance(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMinDistance());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Music::Method_getAttenuation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getAttenuation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Music::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Music::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Music::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Music"), FO);
}
//----------------------------------------
void sf_Music::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("openFromFile", v8::FunctionTemplate::New(Method_openFromFile));
    target->Set("openFromMemory", v8::FunctionTemplate::New(Method_openFromMemory));
    target->Set("openFromStream", v8::FunctionTemplate::New(Method_openFromStream));
    target->Set("getDuration", v8::FunctionTemplate::New(Method_getDuration));
    target->Set("play", v8::FunctionTemplate::New(Method_play));
    target->Set("pause", v8::FunctionTemplate::New(Method_pause));
    target->Set("stop", v8::FunctionTemplate::New(Method_stop));
    target->Set("getChannelCount", v8::FunctionTemplate::New(Method_getChannelCount));
    target->Set("getSampleRate", v8::FunctionTemplate::New(Method_getSampleRate));
    target->Set("getStatus", v8::FunctionTemplate::New(Method_getStatus));
    target->Set("setPlayingOffset", v8::FunctionTemplate::New(Method_setPlayingOffset));
    target->Set("getPlayingOffset", v8::FunctionTemplate::New(Method_getPlayingOffset));
    target->Set("setLoop", v8::FunctionTemplate::New(Method_setLoop));
    target->Set("getLoop", v8::FunctionTemplate::New(Method_getLoop));
    target->Set("setPitch", v8::FunctionTemplate::New(Method_setPitch));
    target->Set("setVolume", v8::FunctionTemplate::New(Method_setVolume));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRelativeToListener", v8::FunctionTemplate::New(Method_setRelativeToListener));
    target->Set("setMinDistance", v8::FunctionTemplate::New(Method_setMinDistance));
    target->Set("setAttenuation", v8::FunctionTemplate::New(Method_setAttenuation));
    target->Set("getPitch", v8::FunctionTemplate::New(Method_getPitch));
    target->Set("getVolume", v8::FunctionTemplate::New(Method_getVolume));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("isRelativeToListener", v8::FunctionTemplate::New(Method_isRelativeToListener));
    target->Set("getMinDistance", v8::FunctionTemplate::New(Method_getMinDistance));
    target->Set("getAttenuation", v8::FunctionTemplate::New(Method_getAttenuation));
}
//----------------------------------------
void sf_Music::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Stopped"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Paused"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Playing"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
const char *sf_Shape::Bases = "sf::Shape\0sf::Drawable\0\0";
const char *sf_Shape::ClassName = "sf::Shape";
v8::Handle<v8::Value> sf_Shape::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "texture" }}},
    { 2, 2, {{ PT_CLASS, "texture" }, { PT_BOOLEAN, "resetrect" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTexture(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p1 = CastToCPP< bool >(ParamMatch.Params[1]);
            inst->setTexture(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setTextureRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rect" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IntRect* p0 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTextureRect(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setFillColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setFillColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setOutlineColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOutlineColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setOutlineThickness(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "thickness" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setOutlineThickness(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getTextureRect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTextureRect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getFillColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getFillColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getOutlineColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOutlineColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getOutlineThickness(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getOutlineThickness());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getPointCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPointCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "index" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getPoint(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Shape::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Shape::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Shape::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Shape::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Shape"), FO);
}
//----------------------------------------
void sf_Shape::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setTexture", v8::FunctionTemplate::New(Method_setTexture));
    target->Set("setTextureRect", v8::FunctionTemplate::New(Method_setTextureRect));
    target->Set("setFillColor", v8::FunctionTemplate::New(Method_setFillColor));
    target->Set("setOutlineColor", v8::FunctionTemplate::New(Method_setOutlineColor));
    target->Set("setOutlineThickness", v8::FunctionTemplate::New(Method_setOutlineThickness));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("getTextureRect", v8::FunctionTemplate::New(Method_getTextureRect));
    target->Set("getFillColor", v8::FunctionTemplate::New(Method_getFillColor));
    target->Set("getOutlineColor", v8::FunctionTemplate::New(Method_getOutlineColor));
    target->Set("getOutlineThickness", v8::FunctionTemplate::New(Method_getOutlineThickness));
    target->Set("getPointCount", v8::FunctionTemplate::New(Method_getPointCount));
    target->Set("getPoint", v8::FunctionTemplate::New(Method_getPoint));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_Shape::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_UdpSocket::Bases = "sf::UdpSocket\0sf::Socket\0\0";
const char *sf_UdpSocket::ClassName = "sf::UdpSocket";
v8::Handle<v8::Value> sf_UdpSocket::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_getLocalPort(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalPort());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_bind(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "port" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            short unsigned int p0 = CastToCPP< short unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->bind(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_unbind(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->unbind();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_send(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 4, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }, { PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }}},
    { 2, 3, {{ PT_CLASS, "packet" }, { PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }}}
    };
    int FuncSize = 2;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::IpAddress* p2 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p3 = CastToCPP< short unsigned int >(ParamMatch.Params[3]);
            result = CastToJS(inst->send(p0,p1,*p2,p3));
            break;
        }
        case 2: {
            ::sf::Packet* p0 = CastToCPP< ::sf::Packet* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::IpAddress* p1 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p2 = CastToCPP< short unsigned int >(ParamMatch.Params[2]);
            result = CastToJS(inst->send(*p0,*p1,p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_receive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 5, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }, { PT_NUMBER, "received" }, { PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }}},
    { 2, 3, {{ PT_CLASS, "packet" }, { PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }}}
    };
    int FuncSize = 2;
    Match<5> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            size_t p2 = CastToCPP< size_t >(ParamMatch.Params[2]);
            ::sf::IpAddress* p3 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p4 = CastToCPP< short unsigned int >(ParamMatch.Params[4]);
            result = CastToJS(inst->receive(p0,p1,p2,*p3,p4));
            ParamMatch.Params[2] = CastToJS(p2);
            ParamMatch.Params[4] = CastToJS(p4);
            break;
        }
        case 2: {
            ::sf::Packet* p0 = CastToCPP< ::sf::Packet* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::IpAddress* p1 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p2 = CastToCPP< short unsigned int >(ParamMatch.Params[2]);
            result = CastToJS(inst->receive(*p0,*p1,p2));
            ParamMatch.Params[2] = CastToJS(p2);
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_setBlocking(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "blocking" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setBlocking(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_UdpSocket::Method_isBlocking(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isBlocking());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_UdpSocket::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_UdpSocket::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_UdpSocket::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("UdpSocket"), FO);
}
//----------------------------------------
void sf_UdpSocket::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getLocalPort", v8::FunctionTemplate::New(Method_getLocalPort));
    target->Set("bind", v8::FunctionTemplate::New(Method_bind));
    target->Set("unbind", v8::FunctionTemplate::New(Method_unbind));
    target->Set("send", v8::FunctionTemplate::New(Method_send));
    target->Set("receive", v8::FunctionTemplate::New(Method_receive));
    target->Set("setBlocking", v8::FunctionTemplate::New(Method_setBlocking));
    target->Set("isBlocking", v8::FunctionTemplate::New(Method_isBlocking));
}
//----------------------------------------
void sf_UdpSocket::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("MaxDatagramSize"), v8::Number::New(65507), v8::ReadOnly);
    target->Set(v8::String::New("Done"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("NotReady"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Disconnected"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("Error"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("AnyPort"), v8::Number::New(0), v8::ReadOnly);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
const char *sf_IpAddress::Bases = "sf::IpAddress\0\0";
const char *sf_IpAddress::ClassName = "sf::IpAddress";
v8::Handle<v8::Value> sf_IpAddress::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_STRING, "address" }}},
    { 3, 1, {{ PT_STRING, "address" }}},
    { 4, 4, {{ PT_NUMBER, "byte0" }, { PT_NUMBER, "byte1" }, { PT_NUMBER, "byte2" }, { PT_NUMBER, "byte3" }}},
    { 5, 1, {{ PT_NUMBER, "address" }}}
    };
    int FuncSize = 5;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                std::string p0 = CastToCPP< std::string >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0.c_str());
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::Uint8 p0 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[0]);
                ::sf::Uint8 p1 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[1]);
                ::sf::Uint8 p2 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[2]);
                ::sf::Uint8 p3 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[3]);
                MyClass *inst = new MyClass(p0,p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                ::sf::Uint32 p0 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Method_toString(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->toString());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Method_toInteger(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->toInteger());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Method_getLocalAddress(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::IpAddress::getLocalAddress());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_IpAddress::Method_getPublicAddress(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "timeout" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(::sf::IpAddress::getPublicAddress());
            break;
        }
        case 2: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(::sf::IpAddress::getPublicAddress(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
void sf_IpAddress::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_IpAddress::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_IpAddress::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("IpAddress"), FO);
}
//----------------------------------------
void sf_IpAddress::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("toString", v8::FunctionTemplate::New(Method_toString));
    target->Set("toInteger", v8::FunctionTemplate::New(Method_toInteger));
}
//----------------------------------------
void sf_IpAddress::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("getLocalAddress"), v8::FunctionTemplate::New(Method_getLocalAddress));
    target->Set(v8::String::New("getPublicAddress"), v8::FunctionTemplate::New(Method_getPublicAddress));
    target->Set(v8::String::New("None"), CastToJS2(::sf::IpAddress::None));
    target->Set(v8::String::New("LocalHost"), CastToJS2(::sf::IpAddress::LocalHost));
    target->Set(v8::String::New("Broadcast"), CastToJS2(::sf::IpAddress::Broadcast));
}
//----------------------------------------
#endif
const char *sf_FloatRect::Bases = "sf::FloatRect\0\0";
const char *sf_FloatRect::ClassName = "sf::FloatRect";
v8::Handle<v8::Value> sf_FloatRect::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 4, {{ PT_NUMBER, "rectleft" }, { PT_NUMBER, "recttop" }, { PT_NUMBER, "rectwidth" }, { PT_NUMBER, "rectheight" }}},
    { 3, 2, {{ PT_CLASS, "position" }, { PT_CLASS, "size" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                float p1 = CastToCPP< float >(ParamMatch.Params[1]);
                float p2 = CastToCPP< float >(ParamMatch.Params[2]);
                float p3 = CastToCPP< float >(ParamMatch.Params[3]);
                MyClass *inst = new MyClass(p0,p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Vector2<float>* p0 = CastToCPP< ::sf::Vector2<float>* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::Vector2<float>* p1 = CastToCPP< ::sf::Vector2<float>* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Method_contains(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "point" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            result = CastToJS(inst->contains(p0,p1));
            break;
        }
        case 2: {
            ::sf::Vector2<float>* p0 = CastToCPP< ::sf::Vector2<float>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->contains(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Method_intersects(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rectangle" }}},
    { 2, 2, {{ PT_CLASS, "rectangle" }, { PT_CLASS, "intersection" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Rect<float>* p0 = CastToCPP< ::sf::Rect<float>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->intersects(*p0));
            break;
        }
        case 2: {
            ::sf::Rect<float>* p0 = CastToCPP< ::sf::Rect<float>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Rect<float>* p1 = CastToCPP< ::sf::Rect<float>* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->intersects(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Getter_left(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->left);
}

void sf_FloatRect::Setter_left(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->left = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Getter_top(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->top);
}

void sf_FloatRect::Setter_top(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->top = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->width);
}

void sf_FloatRect::Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->width = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_FloatRect::Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->height);
}

void sf_FloatRect::Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::FloatRect *inst = static_cast< ::sf::FloatRect * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->height = CastToCPP< float >(value);
}
//----------------------------------------
void sf_FloatRect::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_FloatRect::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_FloatRect::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("FloatRect"), FO);
}
//----------------------------------------
void sf_FloatRect::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("contains", v8::FunctionTemplate::New(Method_contains));
    target->Set("intersects", v8::FunctionTemplate::New(Method_intersects));
    target->SetAccessor(v8::String::New("left"), Getter_left, Setter_left);
    target->SetAccessor(v8::String::New("top"), Getter_top, Setter_top);
    target->SetAccessor(v8::String::New("width"), Getter_width, Setter_width);
    target->SetAccessor(v8::String::New("height"), Getter_height, Setter_height);
}
//----------------------------------------
void sf_FloatRect::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_NonCopyable::Bases = "sf::NonCopyable\0\0";
const char *sf_NonCopyable::ClassName = "sf::NonCopyable";
v8::Handle<v8::Value> sf_NonCopyable::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sNotCreated)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_NonCopyable::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_NonCopyable::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_NonCopyable::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_NonCopyable::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("NonCopyable"), FO);
}
//----------------------------------------
void sf_NonCopyable::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_NonCopyable::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Utf8::Bases = "sf::Utf8\0\0";
const char *sf_Utf8::ClassName = "sf::Utf8";
v8::Handle<v8::Value> sf_Utf8::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf8::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf8::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Utf8::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Utf8::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Utf8::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Utf8"), FO);
}
//----------------------------------------
void sf_Utf8::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Utf8::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Vector2f::Bases = "sf::Vector2f\0\0";
const char *sf_Vector2f::ClassName = "sf::Vector2f";
v8::Handle<v8::Value> sf_Vector2f::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                float p1 = CastToCPP< float >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            (*inst) *= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<float>* p0 = CastToCPP< ::sf::Vector2<float>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Operator_subtract(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<float>* p0 = CastToCPP< ::sf::Vector2<float>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) -= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Operator_divide(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            (*inst) /= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2f *inst = static_cast< ::sf::Vector2f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Vector2f::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2f *inst = static_cast< ::sf::Vector2f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2f::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2f *inst = static_cast< ::sf::Vector2f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Vector2f::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2f *inst = static_cast< ::sf::Vector2f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< float >(value);
}
//----------------------------------------
void sf_Vector2f::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vector2f::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vector2f::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vector2f"), FO);
}
//----------------------------------------
void sf_Vector2f::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->Set("_subtract", v8::FunctionTemplate::New(Operator_subtract));
    target->Set("_divide", v8::FunctionTemplate::New(Operator_divide));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Vector2f::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Vector2i::Bases = "sf::Vector2i\0\0";
const char *sf_Vector2i::ClassName = "sf::Vector2i";
v8::Handle<v8::Value> sf_Vector2i::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                int p0 = CastToCPP< int >(ParamMatch.Params[0]);
                int p1 = CastToCPP< int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            int p0 = CastToCPP< int >(ParamMatch.Params[0]);
            (*inst) *= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<int>* p0 = CastToCPP< ::sf::Vector2<int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Operator_subtract(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<int>* p0 = CastToCPP< ::sf::Vector2<int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) -= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Operator_divide(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            int p0 = CastToCPP< int >(ParamMatch.Params[0]);
            (*inst) /= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2i *inst = static_cast< ::sf::Vector2i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Vector2i::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2i *inst = static_cast< ::sf::Vector2i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2i::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2i *inst = static_cast< ::sf::Vector2i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Vector2i::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2i *inst = static_cast< ::sf::Vector2i * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< int >(value);
}
//----------------------------------------
void sf_Vector2i::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vector2i::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vector2i::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vector2i"), FO);
}
//----------------------------------------
void sf_Vector2i::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->Set("_subtract", v8::FunctionTemplate::New(Operator_subtract));
    target->Set("_divide", v8::FunctionTemplate::New(Operator_divide));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Vector2i::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Vector2u::Bases = "sf::Vector2u\0\0";
const char *sf_Vector2u::ClassName = "sf::Vector2u";
v8::Handle<v8::Value> sf_Vector2u::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            (*inst) *= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<unsigned int>* p0 = CastToCPP< ::sf::Vector2<unsigned int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Operator_subtract(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2<unsigned int>* p0 = CastToCPP< ::sf::Vector2<unsigned int>* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) -= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Operator_divide(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            (*inst) /= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2u *inst = static_cast< ::sf::Vector2u * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Vector2u::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2u *inst = static_cast< ::sf::Vector2u * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector2u::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector2u *inst = static_cast< ::sf::Vector2u * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Vector2u::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector2u *inst = static_cast< ::sf::Vector2u * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_Vector2u::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vector2u::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vector2u::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vector2u"), FO);
}
//----------------------------------------
void sf_Vector2u::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->Set("_subtract", v8::FunctionTemplate::New(Operator_subtract));
    target->Set("_divide", v8::FunctionTemplate::New(Operator_divide));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Vector2u::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Vector3f::Bases = "sf::Vector3f\0\0";
const char *sf_Vector3f::ClassName = "sf::Vector3f";
v8::Handle<v8::Value> sf_Vector3f::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                float p1 = CastToCPP< float >(ParamMatch.Params[1]);
                float p2 = CastToCPP< float >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3f::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3f::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3f::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Vector3f::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3f::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Vector3f::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< float >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Vector3f::Getter_z(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->z);
}

void sf_Vector3f::Setter_z(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Vector3f *inst = static_cast< ::sf::Vector3f * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->z = CastToCPP< float >(value);
}
//----------------------------------------
void sf_Vector3f::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Vector3f::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Vector3f::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Vector3f"), FO);
}
//----------------------------------------
void sf_Vector3f::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
    target->SetAccessor(v8::String::New("z"), Getter_z, Setter_z);
}
//----------------------------------------
void sf_Vector3f::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Transformable::Bases = "sf::Transformable\0\0";
const char *sf_Transformable::ClassName = "sf::Transformable";
v8::Handle<v8::Value> sf_Transformable::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transformable::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Transformable::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Transformable::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Transformable::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Transformable"), FO);
}
//----------------------------------------
void sf_Transformable::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_Transformable::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Clock::Bases = "sf::Clock\0\0";
const char *sf_Clock::ClassName = "sf::Clock";
v8::Handle<v8::Value> sf_Clock::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Clock::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Clock::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Clock::Method_getElapsedTime(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getElapsedTime());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Clock::Method_restart(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->restart());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Clock::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Clock::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Clock::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Clock"), FO);
}
//----------------------------------------
void sf_Clock::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getElapsedTime", v8::FunctionTemplate::New(Method_getElapsedTime));
    target->Set("restart", v8::FunctionTemplate::New(Method_restart));
}
//----------------------------------------
void sf_Clock::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Mouse::Bases = "sf::Mouse\0\0";
const char *sf_Mouse::ClassName = "sf::Mouse";
v8::Handle<v8::Value> sf_Mouse::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Mouse::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Mouse::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Mouse::Method_isButtonPressed(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "button" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Mouse::Button p0 = CastToCPP< ::sf::Mouse::Button >(ParamMatch.Params[0]);
            result = CastToJS(::sf::Mouse::isButtonPressed(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Mouse::Method_getPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "relativeto" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(::sf::Mouse::getPosition());
            break;
        }
        case 2: {
            ::sf::Window* p0 = CastToCPP< ::sf::Window* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(::sf::Mouse::getPosition(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Mouse::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "position" }}},
    { 2, 2, {{ PT_CLASS, "position" }, { PT_CLASS, "relativeto" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Mouse::setPosition(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Window* p1 = CastToCPP< ::sf::Window* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Mouse::setPosition(*p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Mouse::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Mouse::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Mouse::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Mouse"), FO);
}
//----------------------------------------
void sf_Mouse::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Mouse::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isButtonPressed"), v8::FunctionTemplate::New(Method_isButtonPressed));
    target->Set(v8::String::New("getPosition"), v8::FunctionTemplate::New(Method_getPosition));
    target->Set(v8::String::New("setPosition"), v8::FunctionTemplate::New(Method_setPosition));
    target->Set(v8::String::New("Left"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Right"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Middle"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("XButton1"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("XButton2"), v8::Number::New(4), v8::ReadOnly);
    target->Set(v8::String::New("ButtonCount"), v8::Number::New(5), v8::ReadOnly);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_TcpSocket::Bases = "sf::TcpSocket\0sf::Socket\0\0";
const char *sf_TcpSocket::ClassName = "sf::TcpSocket";
v8::Handle<v8::Value> sf_TcpSocket::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_getLocalPort(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalPort());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_getRemoteAddress(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRemoteAddress());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_getRemotePort(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRemotePort());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_connect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }}},
    { 2, 3, {{ PT_CLASS, "remoteaddress" }, { PT_NUMBER, "remoteport" }, { PT_CLASS, "timeout" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IpAddress* p0 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->connect(*p0,p1));
            break;
        }
        case 2: {
            ::sf::IpAddress* p0 = CastToCPP< ::sf::IpAddress* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            short unsigned int p1 = CastToCPP< short unsigned int >(ParamMatch.Params[1]);
            ::sf::Time* p2 = CastToCPP< ::sf::Time* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->connect(*p0,p1,*p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_disconnect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->disconnect();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_send(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }}},
    { 2, 1, {{ PT_CLASS, "packet" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->send(p0,p1));
            break;
        }
        case 2: {
            ::sf::Packet* p0 = CastToCPP< ::sf::Packet* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->send(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_receive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }, { PT_NUMBER, "received" }}},
    { 2, 1, {{ PT_CLASS, "packet" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            size_t p2 = CastToCPP< size_t >(ParamMatch.Params[2]);
            result = CastToJS(inst->receive(p0,p1,p2));
            ParamMatch.Params[2] = CastToJS(p2);
            break;
        }
        case 2: {
            ::sf::Packet* p0 = CastToCPP< ::sf::Packet* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->receive(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_setBlocking(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "blocking" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setBlocking(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpSocket::Method_isBlocking(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isBlocking());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_TcpSocket::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_TcpSocket::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_TcpSocket::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("TcpSocket"), FO);
}
//----------------------------------------
void sf_TcpSocket::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getLocalPort", v8::FunctionTemplate::New(Method_getLocalPort));
    target->Set("getRemoteAddress", v8::FunctionTemplate::New(Method_getRemoteAddress));
    target->Set("getRemotePort", v8::FunctionTemplate::New(Method_getRemotePort));
    target->Set("connect", v8::FunctionTemplate::New(Method_connect));
    target->Set("disconnect", v8::FunctionTemplate::New(Method_disconnect));
    target->Set("send", v8::FunctionTemplate::New(Method_send));
    target->Set("receive", v8::FunctionTemplate::New(Method_receive));
    target->Set("setBlocking", v8::FunctionTemplate::New(Method_setBlocking));
    target->Set("isBlocking", v8::FunctionTemplate::New(Method_isBlocking));
}
//----------------------------------------
void sf_TcpSocket::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Done"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("NotReady"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Disconnected"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("Error"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("AnyPort"), v8::Number::New(0), v8::ReadOnly);
}
//----------------------------------------
#endif
const char *sf_SoundRecorder::Bases = "sf::SoundRecorder\0\0";
const char *sf_SoundRecorder::ClassName = "sf::SoundRecorder";
v8::Handle<v8::Value> sf_SoundRecorder::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundRecorder::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundRecorder::Method_start(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "samplerate" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->start();
            result = v8::Undefined();
            break;
        }
        case 2: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->start(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundRecorder::Method_stop(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->stop();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundRecorder::Method_getSampleRate(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleRate());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundRecorder::Method_isAvailable(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::SoundRecorder::isAvailable());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_SoundRecorder::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundRecorder::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundRecorder::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SoundRecorder"), FO);
}
//----------------------------------------
void sf_SoundRecorder::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("start", v8::FunctionTemplate::New(Method_start));
    target->Set("stop", v8::FunctionTemplate::New(Method_stop));
    target->Set("getSampleRate", v8::FunctionTemplate::New(Method_getSampleRate));
}
//----------------------------------------
void sf_SoundRecorder::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isAvailable"), v8::FunctionTemplate::New(Method_isAvailable));
}
//----------------------------------------
const char *sf_Color::Bases = "sf::Color\0\0";
const char *sf_Color::ClassName = "sf::Color";
v8::Handle<v8::Value> sf_Color::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 3, {{ PT_NUMBER, "red" }, { PT_NUMBER, "green" }, { PT_NUMBER, "blue" }}},
    { 3, 4, {{ PT_NUMBER, "red" }, { PT_NUMBER, "green" }, { PT_NUMBER, "blue" }, { PT_NUMBER, "alpha" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::Uint8 p0 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[0]);
                ::sf::Uint8 p1 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[1]);
                ::sf::Uint8 p2 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Uint8 p0 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[0]);
                ::sf::Uint8 p1 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[1]);
                ::sf::Uint8 p2 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[2]);
                ::sf::Uint8 p3 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[3]);
                MyClass *inst = new MyClass(p0,p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) *= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Getter_r(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->r);
}

void sf_Color::Setter_r(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->r = CastToCPP< unsigned char >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Getter_g(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->g);
}

void sf_Color::Setter_g(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->g = CastToCPP< unsigned char >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Getter_b(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->b);
}

void sf_Color::Setter_b(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->b = CastToCPP< unsigned char >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Color::Getter_a(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->a);
}

void sf_Color::Setter_a(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Color *inst = static_cast< ::sf::Color * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->a = CastToCPP< unsigned char >(value);
}
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
void sf_Color::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Color::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Color::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Color"), FO);
}
//----------------------------------------
void sf_Color::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->SetAccessor(v8::String::New("r"), Getter_r, Setter_r);
    target->SetAccessor(v8::String::New("g"), Getter_g, Setter_g);
    target->SetAccessor(v8::String::New("b"), Getter_b, Setter_b);
    target->SetAccessor(v8::String::New("a"), Getter_a, Setter_a);
}
//----------------------------------------
void sf_Color::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Black"), CastToJS2(::sf::Color::Black));
    target->Set(v8::String::New("White"), CastToJS2(::sf::Color::White));
    target->Set(v8::String::New("Red"), CastToJS2(::sf::Color::Red));
    target->Set(v8::String::New("Green"), CastToJS2(::sf::Color::Green));
    target->Set(v8::String::New("Blue"), CastToJS2(::sf::Color::Blue));
    target->Set(v8::String::New("Yellow"), CastToJS2(::sf::Color::Yellow));
    target->Set(v8::String::New("Magenta"), CastToJS2(::sf::Color::Magenta));
    target->Set(v8::String::New("Cyan"), CastToJS2(::sf::Color::Cyan));
    target->Set(v8::String::New("Transparent"), CastToJS2(::sf::Color::Transparent));
}
//----------------------------------------
const char *sf_Texture::Bases = "sf::Texture\0\0";
const char *sf_Texture::ClassName = "sf::Texture";
v8::Handle<v8::Value> sf_Texture::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_create(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->create(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_loadFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}},
    { 2, 2, {{ PT_STRING, "filename" }, { PT_CLASS, "area" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->loadFromFile(p0));
            break;
        }
        case 2: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            ::sf::IntRect* p1 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromFile(p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_loadFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }}},
    { 2, 3, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }, { PT_CLASS, "area" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
        case 2: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::IntRect* p2 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromMemory(p0,p1,*p2));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_loadFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "stream" }}},
    { 2, 2, {{ PT_CLASS, "stream" }, { PT_CLASS, "area" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0));
            break;
        }
        case 2: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::IntRect* p1 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_loadFromImage(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "image" }}},
    { 2, 2, {{ PT_CLASS, "image" }, { PT_CLASS, "area" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromImage(*p0));
            break;
        }
        case 2: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::IntRect* p1 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromImage(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_copyToImage(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->copyToImage());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_update(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_POINTER, "pixels" }}},
    { 2, 5, {{ PT_POINTER, "pixels" }, { PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 3, 1, {{ PT_CLASS, "image" }}},
    { 4, 3, {{ PT_CLASS, "image" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 5, 1, {{ PT_CLASS, "window" }}},
    { 6, 3, {{ PT_CLASS, "window" }, { PT_NUMBER, "x" }, { PT_NUMBER, "y" }}}
    };
    int FuncSize = 6;
    Match<5> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned char* p0 = CastToCPP< unsigned char* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->update(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            unsigned char* p0 = CastToCPP< unsigned char* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            unsigned int p3 = CastToCPP< unsigned int >(ParamMatch.Params[3]);
            unsigned int p4 = CastToCPP< unsigned int >(ParamMatch.Params[4]);
            inst->update(p0,p1,p2,p3,p4);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->update(*p0);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            inst->update(*p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 5: {
            ::sf::Window* p0 = CastToCPP< ::sf::Window* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->update(*p0);
            result = v8::Undefined();
            break;
        }
        case 6: {
            ::sf::Window* p0 = CastToCPP< ::sf::Window* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            inst->update(*p0,p1,p2);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_bind(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "coordinatetype" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->bind();
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture::CoordinateType p0 = CastToCPP< ::sf::Texture::CoordinateType >(ParamMatch.Params[0]);
            inst->bind(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_setSmooth(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "smooth" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setSmooth(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_isSmooth(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isSmooth());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_setRepeated(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "repeated" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setRepeated(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_isRepeated(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isRepeated());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Texture::Method_getMaximumSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::Texture::getMaximumSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Texture::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Texture::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Texture::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Texture"), FO);
}
//----------------------------------------
void sf_Texture::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("create", v8::FunctionTemplate::New(Method_create));
    target->Set("loadFromFile", v8::FunctionTemplate::New(Method_loadFromFile));
    target->Set("loadFromMemory", v8::FunctionTemplate::New(Method_loadFromMemory));
    target->Set("loadFromStream", v8::FunctionTemplate::New(Method_loadFromStream));
    target->Set("loadFromImage", v8::FunctionTemplate::New(Method_loadFromImage));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("copyToImage", v8::FunctionTemplate::New(Method_copyToImage));
    target->Set("update", v8::FunctionTemplate::New(Method_update));
    target->Set("bind", v8::FunctionTemplate::New(Method_bind));
    target->Set("setSmooth", v8::FunctionTemplate::New(Method_setSmooth));
    target->Set("isSmooth", v8::FunctionTemplate::New(Method_isSmooth));
    target->Set("setRepeated", v8::FunctionTemplate::New(Method_setRepeated));
    target->Set("isRepeated", v8::FunctionTemplate::New(Method_isRepeated));
}
//----------------------------------------
void sf_Texture::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("getMaximumSize"), v8::FunctionTemplate::New(Method_getMaximumSize));
    target->Set(v8::String::New("Normalized"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Pixels"), v8::Number::New(1), v8::ReadOnly);
}
//----------------------------------------
const char *sf_ContextSettings::Bases = "sf::ContextSettings\0\0";
const char *sf_ContextSettings::ClassName = "sf::ContextSettings";
v8::Handle<v8::Value> sf_ContextSettings::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "depth" }}},
    { 3, 2, {{ PT_NUMBER, "depth" }, { PT_NUMBER, "stencil" }}},
    { 4, 3, {{ PT_NUMBER, "depth" }, { PT_NUMBER, "stencil" }, { PT_NUMBER, "antialiasing" }}},
    { 5, 4, {{ PT_NUMBER, "depth" }, { PT_NUMBER, "stencil" }, { PT_NUMBER, "antialiasing" }, { PT_NUMBER, "major" }}},
    { 6, 5, {{ PT_NUMBER, "depth" }, { PT_NUMBER, "stencil" }, { PT_NUMBER, "antialiasing" }, { PT_NUMBER, "major" }, { PT_NUMBER, "minor" }}}
    };
    int FuncSize = 6;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<5> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                unsigned int p3 = CastToCPP< unsigned int >(ParamMatch.Params[3]);
                MyClass *inst = new MyClass(p0,p1,p2,p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 6: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                unsigned int p3 = CastToCPP< unsigned int >(ParamMatch.Params[3]);
                unsigned int p4 = CastToCPP< unsigned int >(ParamMatch.Params[4]);
                MyClass *inst = new MyClass(p0,p1,p2,p3,p4);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Getter_depthBits(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->depthBits);
}

void sf_ContextSettings::Setter_depthBits(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->depthBits = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Getter_stencilBits(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->stencilBits);
}

void sf_ContextSettings::Setter_stencilBits(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->stencilBits = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Getter_antialiasingLevel(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->antialiasingLevel);
}

void sf_ContextSettings::Setter_antialiasingLevel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->antialiasingLevel = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Getter_majorVersion(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->majorVersion);
}

void sf_ContextSettings::Setter_majorVersion(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->majorVersion = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ContextSettings::Getter_minorVersion(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->minorVersion);
}

void sf_ContextSettings::Setter_minorVersion(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::ContextSettings *inst = static_cast< ::sf::ContextSettings * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->minorVersion = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_ContextSettings::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_ContextSettings::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_ContextSettings::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("ContextSettings"), FO);
}
//----------------------------------------
void sf_ContextSettings::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("depthBits"), Getter_depthBits, Setter_depthBits);
    target->SetAccessor(v8::String::New("stencilBits"), Getter_stencilBits, Setter_stencilBits);
    target->SetAccessor(v8::String::New("antialiasingLevel"), Getter_antialiasingLevel, Setter_antialiasingLevel);
    target->SetAccessor(v8::String::New("majorVersion"), Getter_majorVersion, Setter_majorVersion);
    target->SetAccessor(v8::String::New("minorVersion"), Getter_minorVersion, Setter_minorVersion);
}
//----------------------------------------
void sf_ContextSettings::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Context::Bases = "sf::Context\0\0";
const char *sf_Context::ClassName = "sf::Context";
v8::Handle<v8::Value> sf_Context::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 3, {{ PT_CLASS, "settings" }, { PT_NUMBER, "width" }, { PT_NUMBER, "height" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<3> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::ContextSettings* p0 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
                unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(*p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Context::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Context::Method_setActive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "active" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            result = CastToJS(inst->setActive(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Context::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Context::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Context::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Context"), FO);
}
//----------------------------------------
void sf_Context::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setActive", v8::FunctionTemplate::New(Method_setActive));
}
//----------------------------------------
void sf_Context::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_SoundBuffer::Bases = "sf::SoundBuffer\0\0";
const char *sf_SoundBuffer::ClassName = "sf::SoundBuffer";
v8::Handle<v8::Value> sf_SoundBuffer::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_loadFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->loadFromFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_loadFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "sizeinbytes" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_loadFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "stream" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_loadFromSamples(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 4, {{ PT_POINTER, "samples" }, { PT_NUMBER, "samplecount" }, { PT_NUMBER, "channelcount" }, { PT_NUMBER, "samplerate" }}}
    };
    int FuncSize = 1;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            short int* p0 = CastToCPP< short int* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            unsigned int p3 = CastToCPP< unsigned int >(ParamMatch.Params[3]);
            result = CastToJS(inst->loadFromSamples(p0,p1,p2,p3));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_saveToFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->saveToFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_getSamples(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSamples());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_getSampleCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_getSampleRate(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSampleRate());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_getChannelCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getChannelCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundBuffer::Method_getDuration(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getDuration());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_SoundBuffer::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundBuffer::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundBuffer::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SoundBuffer"), FO);
}
//----------------------------------------
void sf_SoundBuffer::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("loadFromFile", v8::FunctionTemplate::New(Method_loadFromFile));
    target->Set("loadFromMemory", v8::FunctionTemplate::New(Method_loadFromMemory));
    target->Set("loadFromStream", v8::FunctionTemplate::New(Method_loadFromStream));
    target->Set("loadFromSamples", v8::FunctionTemplate::New(Method_loadFromSamples));
    target->Set("saveToFile", v8::FunctionTemplate::New(Method_saveToFile));
    target->Set("getSamples", v8::FunctionTemplate::New(Method_getSamples));
    target->Set("getSampleCount", v8::FunctionTemplate::New(Method_getSampleCount));
    target->Set("getSampleRate", v8::FunctionTemplate::New(Method_getSampleRate));
    target->Set("getChannelCount", v8::FunctionTemplate::New(Method_getChannelCount));
    target->Set("getDuration", v8::FunctionTemplate::New(Method_getDuration));
}
//----------------------------------------
void sf_SoundBuffer::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Image::Bases = "sf::Image\0\0";
const char *sf_Image::ClassName = "sf::Image";
v8::Handle<v8::Value> sf_Image::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_create(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }}},
    { 2, 3, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_CLASS, "color" }}},
    { 3, 3, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_POINTER, "pixels" }}}
    };
    int FuncSize = 3;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            inst->create(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::Color* p2 = CastToCPP< ::sf::Color* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(p0,p1,*p2);
            result = v8::Undefined();
            break;
        }
        case 3: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned char* p2 = CastToCPP< unsigned char* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_loadFromFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->loadFromFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_loadFromMemory(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_POINTER, "data" }, { PT_NUMBER, "size" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            void* p0 = CastToCPP< void* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->loadFromMemory(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_loadFromStream(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "stream" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::InputStream* p0 = CastToCPP< ::sf::InputStream* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->loadFromStream(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_saveToFile(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "filename" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            result = CastToJS(inst->saveToFile(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_createMaskFromColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}},
    { 2, 2, {{ PT_CLASS, "color" }, { PT_NUMBER, "alpha" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->createMaskFromColor(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Uint8 p1 = CastToCPP< ::sf::Uint8 >(ParamMatch.Params[1]);
            inst->createMaskFromColor(*p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_copy(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_CLASS, "source" }, { PT_NUMBER, "destx" }, { PT_NUMBER, "desty" }}},
    { 2, 4, {{ PT_CLASS, "source" }, { PT_NUMBER, "destx" }, { PT_NUMBER, "desty" }, { PT_CLASS, "sourcerect" }}},
    { 3, 5, {{ PT_CLASS, "source" }, { PT_NUMBER, "destx" }, { PT_NUMBER, "desty" }, { PT_CLASS, "sourcerect" }, { PT_BOOLEAN, "applyalpha" }}}
    };
    int FuncSize = 3;
    Match<5> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            inst->copy(*p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            ::sf::IntRect* p3 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->copy(*p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::Image* p0 = CastToCPP< ::sf::Image* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned int p2 = CastToCPP< unsigned int >(ParamMatch.Params[2]);
            ::sf::IntRect* p3 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p4 = CastToCPP< bool >(ParamMatch.Params[4]);
            inst->copy(*p0,p1,p2,*p3,p4);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_setPixel(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::Color* p2 = CastToCPP< ::sf::Color* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPixel(p0,p1,*p2);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_getPixel(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(inst->getPixel(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_getPixelsPtr(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPixelsPtr());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_flipHorizontally(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->flipHorizontally();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Image::Method_flipVertically(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->flipVertically();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Image::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Image::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Image::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Image"), FO);
}
//----------------------------------------
void sf_Image::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("create", v8::FunctionTemplate::New(Method_create));
    target->Set("loadFromFile", v8::FunctionTemplate::New(Method_loadFromFile));
    target->Set("loadFromMemory", v8::FunctionTemplate::New(Method_loadFromMemory));
    target->Set("loadFromStream", v8::FunctionTemplate::New(Method_loadFromStream));
    target->Set("saveToFile", v8::FunctionTemplate::New(Method_saveToFile));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("createMaskFromColor", v8::FunctionTemplate::New(Method_createMaskFromColor));
    target->Set("copy", v8::FunctionTemplate::New(Method_copy));
    target->Set("setPixel", v8::FunctionTemplate::New(Method_setPixel));
    target->Set("getPixel", v8::FunctionTemplate::New(Method_getPixel));
    target->Set("getPixelsPtr", v8::FunctionTemplate::New(Method_getPixelsPtr));
    target->Set("flipHorizontally", v8::FunctionTemplate::New(Method_flipHorizontally));
    target->Set("flipVertically", v8::FunctionTemplate::New(Method_flipVertically));
}
//----------------------------------------
void sf_Image::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Sprite::Bases = "sf::Sprite\0sf::Drawable\0\0";
const char *sf_Sprite::ClassName = "sf::Sprite";
v8::Handle<v8::Value> sf_Sprite::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "texture" }}},
    { 3, 2, {{ PT_CLASS, "texture" }, { PT_CLASS, "rectangle" }}}
    };
    int FuncSize = 3;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<2> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::sf::IntRect* p1 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "texture" }}},
    { 2, 2, {{ PT_CLASS, "texture" }, { PT_BOOLEAN, "resetrect" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTexture(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p1 = CastToCPP< bool >(ParamMatch.Params[1]);
            inst->setTexture(*p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setTextureRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rectangle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IntRect* p0 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTextureRect(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getTextureRect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTextureRect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Sprite::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Sprite::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Sprite::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Sprite::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Sprite"), FO);
}
//----------------------------------------
void sf_Sprite::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setTexture", v8::FunctionTemplate::New(Method_setTexture));
    target->Set("setTextureRect", v8::FunctionTemplate::New(Method_setTextureRect));
    target->Set("setColor", v8::FunctionTemplate::New(Method_setColor));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("getTextureRect", v8::FunctionTemplate::New(Method_getTextureRect));
    target->Set("getColor", v8::FunctionTemplate::New(Method_getColor));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_Sprite::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_ConvexShape::Bases = "sf::ConvexShape\0sf::Shape\0sf::Drawable\0\0";
const char *sf_ConvexShape::ClassName = "sf::ConvexShape";
v8::Handle<v8::Value> sf_ConvexShape::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_NUMBER, "pointcount" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setPointCount(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "count" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->setPointCount(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getPointCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPointCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "index" }, { PT_CLASS, "point" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPoint(p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "index" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getPoint(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "texture" }}},
    { 2, 2, {{ PT_CLASS, "texture" }, { PT_BOOLEAN, "resetrect" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTexture(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p1 = CastToCPP< bool >(ParamMatch.Params[1]);
            inst->setTexture(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setTextureRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rect" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IntRect* p0 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTextureRect(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setFillColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setFillColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setOutlineColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOutlineColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setOutlineThickness(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "thickness" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setOutlineThickness(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getTextureRect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTextureRect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getFillColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getFillColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getOutlineColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOutlineColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getOutlineThickness(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getOutlineThickness());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_ConvexShape::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_ConvexShape::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_ConvexShape::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_ConvexShape::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("ConvexShape"), FO);
}
//----------------------------------------
void sf_ConvexShape::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setPointCount", v8::FunctionTemplate::New(Method_setPointCount));
    target->Set("getPointCount", v8::FunctionTemplate::New(Method_getPointCount));
    target->Set("setPoint", v8::FunctionTemplate::New(Method_setPoint));
    target->Set("getPoint", v8::FunctionTemplate::New(Method_getPoint));
    target->Set("setTexture", v8::FunctionTemplate::New(Method_setTexture));
    target->Set("setTextureRect", v8::FunctionTemplate::New(Method_setTextureRect));
    target->Set("setFillColor", v8::FunctionTemplate::New(Method_setFillColor));
    target->Set("setOutlineColor", v8::FunctionTemplate::New(Method_setOutlineColor));
    target->Set("setOutlineThickness", v8::FunctionTemplate::New(Method_setOutlineThickness));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("getTextureRect", v8::FunctionTemplate::New(Method_getTextureRect));
    target->Set("getFillColor", v8::FunctionTemplate::New(Method_getFillColor));
    target->Set("getOutlineColor", v8::FunctionTemplate::New(Method_getOutlineColor));
    target->Set("getOutlineThickness", v8::FunctionTemplate::New(Method_getOutlineThickness));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_ConvexShape::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Window::Bases = "sf::Window\0\0";
const char *sf_Window::ClassName = "sf::Window";
v8::Handle<v8::Value> sf_Window::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 2, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }}},
    { 3, 3, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }}},
    { 4, 4, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }, { PT_CLASS, "settings" }}},
    { 5, 1, {{ PT_NUMBER, "handle" }}},
    { 6, 2, {{ PT_NUMBER, "handle" }, { PT_CLASS, "settings" }}}
    };
    int FuncSize = 6;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<4> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                MyClass *inst = new MyClass(*p0,p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 3: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
                MyClass *inst = new MyClass(*p0,p1,p2);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 4: {
                ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
                ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
                ::sf::ContextSettings* p3 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[3]);
                if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0,p1,p2,*p3);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 5: {
                ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
                MyClass *inst = new MyClass(p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 6: {
                ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
                ::sf::ContextSettings* p1 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[1]);
                if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(p0,*p1);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_create(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }}},
    { 2, 3, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }}},
    { 3, 4, {{ PT_CLASS, "mode" }, { PT_STRING, "title" }, { PT_NUMBER, "style" }, { PT_CLASS, "settings" }}},
    { 4, 1, {{ PT_NUMBER, "handle" }}},
    { 5, 2, {{ PT_NUMBER, "handle" }, { PT_CLASS, "settings" }}}
    };
    int FuncSize = 5;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            inst->create(*p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
            inst->create(*p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::VideoMode* p0 = CastToCPP< ::sf::VideoMode* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::std::string p1 = CastToCPP< ::std::string >(ParamMatch.Params[1]);
            ::sf::Uint32 p2 = CastToCPP< ::sf::Uint32 >(ParamMatch.Params[2]);
            ::sf::ContextSettings* p3 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(*p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
            inst->create(p0);
            result = v8::Undefined();
            break;
        }
        case 5: {
            ::sf::WindowHandle p0 = CastToCPP< ::sf::WindowHandle >(ParamMatch.Params[0]);
            ::sf::ContextSettings* p1 = CastToCPP< ::sf::ContextSettings* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->create(p0,*p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_close(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->close();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_isOpen(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isOpen());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_getSettings(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getSettings());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_pollEvent(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "event" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Event* p0 = CastToCPP< ::sf::Event* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->pollEvent(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_waitEvent(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "event" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Event* p0 = CastToCPP< ::sf::Event* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->waitEvent(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setSize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "size" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2u* p0 = CastToCPP< ::sf::Vector2u* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setSize(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setTitle(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_STRING, "title" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::std::string p0 = CastToCPP< ::std::string >(ParamMatch.Params[0]);
            inst->setTitle(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setIcon(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "width" }, { PT_NUMBER, "height" }, { PT_POINTER, "pixels" }}}
    };
    int FuncSize = 1;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            unsigned char* p2 = CastToCPP< unsigned char* >(ParamMatch.Params[2]);
            if ( p2 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setIcon(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setVisible(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "visible" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setVisible(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setVerticalSyncEnabled(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "enabled" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setVerticalSyncEnabled(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setMouseCursorVisible(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "visible" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setMouseCursorVisible(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setKeyRepeatEnabled(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "enabled" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setKeyRepeatEnabled(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setFramerateLimit(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "limit" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            inst->setFramerateLimit(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setJoystickThreshold(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "threshold" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setJoystickThreshold(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_setActive(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_BOOLEAN, "active" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            result = CastToJS(inst->setActive());
            break;
        }
        case 2: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            result = CastToJS(inst->setActive(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_display(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->display();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Window::Method_getSystemHandle(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSystemHandle());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Window::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Window::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Window::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Window"), FO);
}
//----------------------------------------
void sf_Window::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("create", v8::FunctionTemplate::New(Method_create));
    target->Set("close", v8::FunctionTemplate::New(Method_close));
    target->Set("isOpen", v8::FunctionTemplate::New(Method_isOpen));
    target->Set("getSettings", v8::FunctionTemplate::New(Method_getSettings));
    target->Set("pollEvent", v8::FunctionTemplate::New(Method_pollEvent));
    target->Set("waitEvent", v8::FunctionTemplate::New(Method_waitEvent));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("setSize", v8::FunctionTemplate::New(Method_setSize));
    target->Set("setTitle", v8::FunctionTemplate::New(Method_setTitle));
    target->Set("setIcon", v8::FunctionTemplate::New(Method_setIcon));
    target->Set("setVisible", v8::FunctionTemplate::New(Method_setVisible));
    target->Set("setVerticalSyncEnabled", v8::FunctionTemplate::New(Method_setVerticalSyncEnabled));
    target->Set("setMouseCursorVisible", v8::FunctionTemplate::New(Method_setMouseCursorVisible));
    target->Set("setKeyRepeatEnabled", v8::FunctionTemplate::New(Method_setKeyRepeatEnabled));
    target->Set("setFramerateLimit", v8::FunctionTemplate::New(Method_setFramerateLimit));
    target->Set("setJoystickThreshold", v8::FunctionTemplate::New(Method_setJoystickThreshold));
    target->Set("setActive", v8::FunctionTemplate::New(Method_setActive));
    target->Set("display", v8::FunctionTemplate::New(Method_display));
    target->Set("getSystemHandle", v8::FunctionTemplate::New(Method_getSystemHandle));
}
//----------------------------------------
void sf_Window::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Time::Bases = "sf::Time\0\0";
const char *sf_Time::ClassName = "sf::Time";
v8::Handle<v8::Value> sf_Time::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}},
    { 2, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Int64 p0 = CastToCPP< ::sf::Int64 >(ParamMatch.Params[0]);
            (*inst) *= (p0);
            result = args.This();
            break;
        }
        case 2: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            (*inst) *= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Operator_add(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) += (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Operator_subtract(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) -= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Operator_divide(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "right" }}},
    { 2, 1, {{ PT_NUMBER, "right" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Int64 p0 = CastToCPP< ::sf::Int64 >(ParamMatch.Params[0]);
            (*inst) /= (p0);
            result = args.This();
            break;
        }
        case 2: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            (*inst) /= (p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Method_asSeconds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->asSeconds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Method_asMilliseconds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->asMilliseconds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Time::Method_asMicroseconds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->asMicroseconds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
//----------------------------------------
void sf_Time::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Time::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Time::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Time"), FO);
}
//----------------------------------------
void sf_Time::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("_add", v8::FunctionTemplate::New(Operator_add));
    target->Set("_subtract", v8::FunctionTemplate::New(Operator_subtract));
    target->Set("_divide", v8::FunctionTemplate::New(Operator_divide));
    target->Set("asSeconds", v8::FunctionTemplate::New(Method_asSeconds));
    target->Set("asMilliseconds", v8::FunctionTemplate::New(Method_asMilliseconds));
    target->Set("asMicroseconds", v8::FunctionTemplate::New(Method_asMicroseconds));
}
//----------------------------------------
void sf_Time::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Zero"), CastToJS2(::sf::Time::Zero));
}
//----------------------------------------
const char *sf_Glyph::Bases = "sf::Glyph\0\0";
const char *sf_Glyph::ClassName = "sf::Glyph";
v8::Handle<v8::Value> sf_Glyph::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Glyph::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Glyph::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Glyph::Getter_advance(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->advance);
}

void sf_Glyph::Setter_advance(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->advance = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Glyph::Getter_bounds(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->bounds);
}

void sf_Glyph::Setter_bounds(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->bounds = CastToCPP< ::sf::Rect<int> >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Glyph::Getter_textureRect(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->textureRect);
}

void sf_Glyph::Setter_textureRect(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Glyph *inst = static_cast< ::sf::Glyph * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->textureRect = CastToCPP< ::sf::Rect<int> >(value);
}
//----------------------------------------
void sf_Glyph::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Glyph::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Glyph::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Glyph"), FO);
}
//----------------------------------------
void sf_Glyph::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("advance"), Getter_advance, Setter_advance);
    target->SetAccessor(v8::String::New("bounds"), Getter_bounds, Setter_bounds);
    target->SetAccessor(v8::String::New("textureRect"), Getter_textureRect, Setter_textureRect);
}
//----------------------------------------
void sf_Glyph::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Transform::Bases = "sf::Transform\0\0";
const char *sf_Transform::ClassName = "sf::Transform";
v8::Handle<v8::Value> sf_Transform::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 9, {{ PT_NUMBER, "a00" }, { PT_NUMBER, "a01" }, { PT_NUMBER, "a02" }, { PT_NUMBER, "a10" }, { PT_NUMBER, "a11" }, { PT_NUMBER, "a12" }, { PT_NUMBER, "a20" }, { PT_NUMBER, "a21" }, { PT_NUMBER, "a22" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<9> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                float p0 = CastToCPP< float >(ParamMatch.Params[0]);
                float p1 = CastToCPP< float >(ParamMatch.Params[1]);
                float p2 = CastToCPP< float >(ParamMatch.Params[2]);
                float p3 = CastToCPP< float >(ParamMatch.Params[3]);
                float p4 = CastToCPP< float >(ParamMatch.Params[4]);
                float p5 = CastToCPP< float >(ParamMatch.Params[5]);
                float p6 = CastToCPP< float >(ParamMatch.Params[6]);
                float p7 = CastToCPP< float >(ParamMatch.Params[7]);
                float p8 = CastToCPP< float >(ParamMatch.Params[8]);
                MyClass *inst = new MyClass(p0,p1,p2,p3,p4,p5,p6,p7,p8);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Operator_multiply(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "right" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Transform* p0 = CastToCPP< ::sf::Transform* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            (*inst) *= (*p0);
            result = args.This();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_getMatrix(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMatrix());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_getInverse(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getInverse());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_transformPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "point" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            result = CastToJS(inst->transformPoint(p0,p1));
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->transformPoint(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_transformRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rectangle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::FloatRect* p0 = CastToCPP< ::sf::FloatRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->transformRect(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_combine(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "transform" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Transform* p0 = CastToCPP< ::sf::Transform* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->combine(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_translate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            result = CastToJS(inst->translate(p0,p1));
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->translate(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}},
    { 2, 3, {{ PT_NUMBER, "angle" }, { PT_NUMBER, "centerx" }, { PT_NUMBER, "centery" }}},
    { 3, 2, {{ PT_NUMBER, "angle" }, { PT_CLASS, "center" }}}
    };
    int FuncSize = 3;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            result = CastToJS(inst->rotate(p0));
            break;
        }
        case 2: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            result = CastToJS(inst->rotate(p0,p1,p2));
            break;
        }
        case 3: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->rotate(p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Transform::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "scalex" }, { PT_NUMBER, "scaley" }}},
    { 2, 4, {{ PT_NUMBER, "scalex" }, { PT_NUMBER, "scaley" }, { PT_NUMBER, "centerx" }, { PT_NUMBER, "centery" }}},
    { 3, 1, {{ PT_CLASS, "factors" }}},
    { 4, 2, {{ PT_CLASS, "factors" }, { PT_CLASS, "center" }}}
    };
    int FuncSize = 4;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            result = CastToJS(inst->scale(p0,p1));
            break;
        }
        case 2: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            float p3 = CastToCPP< float >(ParamMatch.Params[3]);
            result = CastToJS(inst->scale(p0,p1,p2,p3));
            break;
        }
        case 3: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->scale(*p0));
            break;
        }
        case 4: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Vector2f* p1 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->scale(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
//----------------------------------------
void sf_Transform::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Transform::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Transform::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Transform"), FO);
}
//----------------------------------------
void sf_Transform::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("_multiply", v8::FunctionTemplate::New(Operator_multiply));
    target->Set("getMatrix", v8::FunctionTemplate::New(Method_getMatrix));
    target->Set("getInverse", v8::FunctionTemplate::New(Method_getInverse));
    target->Set("transformPoint", v8::FunctionTemplate::New(Method_transformPoint));
    target->Set("transformRect", v8::FunctionTemplate::New(Method_transformRect));
    target->Set("combine", v8::FunctionTemplate::New(Method_combine));
    target->Set("translate", v8::FunctionTemplate::New(Method_translate));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
}
//----------------------------------------
void sf_Transform::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Identity"), CastToJS2(::sf::Transform::Identity));
}
//----------------------------------------
const char *sf_Joystick::Bases = "sf::Joystick\0\0";
const char *sf_Joystick::ClassName = "sf::Joystick";
v8::Handle<v8::Value> sf_Joystick::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_isConnected(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "joystick" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(::sf::Joystick::isConnected(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_getButtonCount(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "joystick" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(::sf::Joystick::getButtonCount(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_hasAxis(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "joystick" }, { PT_NUMBER, "axis" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            ::sf::Joystick::Axis p1 = CastToCPP< ::sf::Joystick::Axis >(ParamMatch.Params[1]);
            result = CastToJS(::sf::Joystick::hasAxis(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_isButtonPressed(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "joystick" }, { PT_NUMBER, "button" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            result = CastToJS(::sf::Joystick::isButtonPressed(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_getAxisPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "joystick" }, { PT_NUMBER, "axis" }}}
    };
    int FuncSize = 1;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            ::sf::Joystick::Axis p1 = CastToCPP< ::sf::Joystick::Axis >(ParamMatch.Params[1]);
            result = CastToJS(::sf::Joystick::getAxisPosition(p0,p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Joystick::Method_update(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        ::sf::Joystick::update();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Joystick::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Joystick::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Joystick::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Joystick"), FO);
}
//----------------------------------------
void sf_Joystick::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Joystick::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isConnected"), v8::FunctionTemplate::New(Method_isConnected));
    target->Set(v8::String::New("getButtonCount"), v8::FunctionTemplate::New(Method_getButtonCount));
    target->Set(v8::String::New("hasAxis"), v8::FunctionTemplate::New(Method_hasAxis));
    target->Set(v8::String::New("isButtonPressed"), v8::FunctionTemplate::New(Method_isButtonPressed));
    target->Set(v8::String::New("getAxisPosition"), v8::FunctionTemplate::New(Method_getAxisPosition));
    target->Set(v8::String::New("update"), v8::FunctionTemplate::New(Method_update));
    target->Set(v8::String::New("Count"), v8::Number::New(8), v8::ReadOnly);
    target->Set(v8::String::New("ButtonCount"), v8::Number::New(32), v8::ReadOnly);
    target->Set(v8::String::New("AxisCount"), v8::Number::New(8), v8::ReadOnly);
    target->Set(v8::String::New("X"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Y"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Z"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("R"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("U"), v8::Number::New(4), v8::ReadOnly);
    target->Set(v8::String::New("V"), v8::Number::New(5), v8::ReadOnly);
    target->Set(v8::String::New("PovX"), v8::Number::New(6), v8::ReadOnly);
    target->Set(v8::String::New("PovY"), v8::Number::New(7), v8::ReadOnly);
}
//----------------------------------------
const char *sf_RenderTarget::Bases = "sf::RenderTarget\0\0";
const char *sf_RenderTarget::ClassName = "sf::RenderTarget";
v8::Handle<v8::Value> sf_RenderTarget::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_clear(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 2;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            inst->clear();
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->clear(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_setView(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setView(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_getView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_getDefaultView(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getDefaultView());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_getViewport(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "view" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::View* p0 = CastToCPP< ::sf::View* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->getViewport(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_convertCoords(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "point" }}},
    { 2, 2, {{ PT_CLASS, "point" }, { PT_CLASS, "view" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0));
            break;
        }
        case 2: {
            ::sf::Vector2i* p0 = CastToCPP< ::sf::Vector2i* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::View* p1 = CastToCPP< ::sf::View* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->convertCoords(*p0,*p1));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_draw(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "drawable" }}},
    { 2, 2, {{ PT_CLASS, "drawable" }, { PT_CLASS, "states" }}},
    { 3, 3, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }}},
    { 4, 4, {{ PT_CLASS, "vertices" }, { PT_NUMBER, "vertexcount" }, { PT_NUMBER, "type" }, { PT_CLASS, "states" }}}
    };
    int FuncSize = 4;
    Match<4> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Drawable* p0 = CastToCPP< ::sf::Drawable* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::RenderStates* p1 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[1]);
            if ( p1 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(*p0,*p1);
            result = v8::Undefined();
            break;
        }
        case 3: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            inst->draw(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 4: {
            ::sf::Vertex* p0 = CastToCPP< ::sf::Vertex* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            unsigned int p1 = CastToCPP< unsigned int >(ParamMatch.Params[1]);
            ::sf::PrimitiveType p2 = CastToCPP< ::sf::PrimitiveType >(ParamMatch.Params[2]);
            ::sf::RenderStates* p3 = CastToCPP< ::sf::RenderStates* >(ParamMatch.Params[3]);
            if ( p3 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->draw(p0,p1,p2,*p3);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_pushGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->pushGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_popGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->popGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RenderTarget::Method_resetGLStates(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->resetGLStates();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_RenderTarget::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_RenderTarget::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_RenderTarget::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("RenderTarget"), FO);
}
//----------------------------------------
void sf_RenderTarget::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("clear", v8::FunctionTemplate::New(Method_clear));
    target->Set("setView", v8::FunctionTemplate::New(Method_setView));
    target->Set("getView", v8::FunctionTemplate::New(Method_getView));
    target->Set("getDefaultView", v8::FunctionTemplate::New(Method_getDefaultView));
    target->Set("getViewport", v8::FunctionTemplate::New(Method_getViewport));
    target->Set("convertCoords", v8::FunctionTemplate::New(Method_convertCoords));
    target->Set("draw", v8::FunctionTemplate::New(Method_draw));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("pushGLStates", v8::FunctionTemplate::New(Method_pushGLStates));
    target->Set("popGLStates", v8::FunctionTemplate::New(Method_popGLStates));
    target->Set("resetGLStates", v8::FunctionTemplate::New(Method_resetGLStates));
}
//----------------------------------------
void sf_RenderTarget::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Listener::Bases = "sf::Listener\0\0";
const char *sf_Listener::ClassName = "sf::Listener";
v8::Handle<v8::Value> sf_Listener::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_setGlobalVolume(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "volume" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            ::sf::Listener::setGlobalVolume(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_getGlobalVolume(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::Listener::getGlobalVolume());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            ::sf::Listener::setPosition(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Listener::setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::Listener::getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_setDirection(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "direction" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            ::sf::Listener::setDirection(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::Listener::setDirection(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Listener::Method_getDirection(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::Listener::getDirection());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_Listener::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Listener::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Listener::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Listener"), FO);
}
//----------------------------------------
void sf_Listener::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Listener::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("setGlobalVolume"), v8::FunctionTemplate::New(Method_setGlobalVolume));
    target->Set(v8::String::New("getGlobalVolume"), v8::FunctionTemplate::New(Method_getGlobalVolume));
    target->Set(v8::String::New("setPosition"), v8::FunctionTemplate::New(Method_setPosition));
    target->Set(v8::String::New("getPosition"), v8::FunctionTemplate::New(Method_getPosition));
    target->Set(v8::String::New("setDirection"), v8::FunctionTemplate::New(Method_setDirection));
    target->Set(v8::String::New("getDirection"), v8::FunctionTemplate::New(Method_getDirection));
}
//----------------------------------------
const char *sf_SoundSource::Bases = "sf::SoundSource\0\0";
const char *sf_SoundSource::ClassName = "sf::SoundSource";
v8::Handle<v8::Value> sf_SoundSource::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sNotCreated)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setPitch(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "pitch" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setPitch(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setVolume(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "volume" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setVolume(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 3, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }, { PT_NUMBER, "z" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<3> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            float p2 = CastToCPP< float >(ParamMatch.Params[2]);
            inst->setPosition(p0,p1,p2);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector3f* p0 = CastToCPP< ::sf::Vector3f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setRelativeToListener(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "relative" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setRelativeToListener(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setMinDistance(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "distance" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setMinDistance(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_setAttenuation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "attenuation" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setAttenuation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_getPitch(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPitch());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_getVolume(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getVolume());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_isRelativeToListener(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isRelativeToListener());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_getMinDistance(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getMinDistance());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_SoundSource::Method_getAttenuation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getAttenuation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_SoundSource::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_SoundSource::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_SoundSource::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SoundSource"), FO);
}
//----------------------------------------
void sf_SoundSource::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setPitch", v8::FunctionTemplate::New(Method_setPitch));
    target->Set("setVolume", v8::FunctionTemplate::New(Method_setVolume));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRelativeToListener", v8::FunctionTemplate::New(Method_setRelativeToListener));
    target->Set("setMinDistance", v8::FunctionTemplate::New(Method_setMinDistance));
    target->Set("setAttenuation", v8::FunctionTemplate::New(Method_setAttenuation));
    target->Set("getPitch", v8::FunctionTemplate::New(Method_getPitch));
    target->Set("getVolume", v8::FunctionTemplate::New(Method_getVolume));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("isRelativeToListener", v8::FunctionTemplate::New(Method_isRelativeToListener));
    target->Set("getMinDistance", v8::FunctionTemplate::New(Method_getMinDistance));
    target->Set("getAttenuation", v8::FunctionTemplate::New(Method_getAttenuation));
}
//----------------------------------------
void sf_SoundSource::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Stopped"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Paused"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Playing"), v8::Number::New(2), v8::ReadOnly);
}
//----------------------------------------
const char *sf_Event_SizeEvent::Bases = "sf::Event::SizeEvent\0\0";
const char *sf_Event_SizeEvent::ClassName = "sf::Event::SizeEvent";
v8::Handle<v8::Value> sf_Event_SizeEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_SizeEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_SizeEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_SizeEvent::Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::SizeEvent *inst = static_cast< ::sf::Event::SizeEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->width);
}

void sf_Event_SizeEvent::Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::SizeEvent *inst = static_cast< ::sf::Event::SizeEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->width = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_SizeEvent::Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::SizeEvent *inst = static_cast< ::sf::Event::SizeEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->height);
}

void sf_Event_SizeEvent::Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::SizeEvent *inst = static_cast< ::sf::Event::SizeEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->height = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_Event_SizeEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_SizeEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_SizeEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("SizeEvent"), FO);
}
//----------------------------------------
void sf_Event_SizeEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("width"), Getter_width, Setter_width);
    target->SetAccessor(v8::String::New("height"), Getter_height, Setter_height);
}
//----------------------------------------
void sf_Event_SizeEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_KeyEvent::Bases = "sf::Event::KeyEvent\0\0";
const char *sf_Event_KeyEvent::ClassName = "sf::Event::KeyEvent";
v8::Handle<v8::Value> sf_Event_KeyEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Getter_code(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->code);
}

void sf_Event_KeyEvent::Setter_code(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->code = CastToCPP< ::sf::Keyboard::Key >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Getter_alt(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->alt);
}

void sf_Event_KeyEvent::Setter_alt(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->alt = CastToCPP< bool >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Getter_control(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->control);
}

void sf_Event_KeyEvent::Setter_control(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->control = CastToCPP< bool >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Getter_shift(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->shift);
}

void sf_Event_KeyEvent::Setter_shift(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->shift = CastToCPP< bool >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_KeyEvent::Getter_system(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->system);
}

void sf_Event_KeyEvent::Setter_system(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::KeyEvent *inst = static_cast< ::sf::Event::KeyEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->system = CastToCPP< bool >(value);
}
//----------------------------------------
void sf_Event_KeyEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_KeyEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_KeyEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("KeyEvent"), FO);
}
//----------------------------------------
void sf_Event_KeyEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("code"), Getter_code, Setter_code);
    target->SetAccessor(v8::String::New("alt"), Getter_alt, Setter_alt);
    target->SetAccessor(v8::String::New("control"), Getter_control, Setter_control);
    target->SetAccessor(v8::String::New("shift"), Getter_shift, Setter_shift);
    target->SetAccessor(v8::String::New("system"), Getter_system, Setter_system);
}
//----------------------------------------
void sf_Event_KeyEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_TextEvent::Bases = "sf::Event::TextEvent\0\0";
const char *sf_Event_TextEvent::ClassName = "sf::Event::TextEvent";
v8::Handle<v8::Value> sf_Event_TextEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_TextEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_TextEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_TextEvent::Getter_unicode(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::TextEvent *inst = static_cast< ::sf::Event::TextEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->unicode);
}

void sf_Event_TextEvent::Setter_unicode(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::TextEvent *inst = static_cast< ::sf::Event::TextEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->unicode = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_Event_TextEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_TextEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_TextEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("TextEvent"), FO);
}
//----------------------------------------
void sf_Event_TextEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("unicode"), Getter_unicode, Setter_unicode);
}
//----------------------------------------
void sf_Event_TextEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_MouseMoveEvent::Bases = "sf::Event::MouseMoveEvent\0\0";
const char *sf_Event_MouseMoveEvent::ClassName = "sf::Event::MouseMoveEvent";
v8::Handle<v8::Value> sf_Event_MouseMoveEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseMoveEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseMoveEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseMoveEvent::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseMoveEvent *inst = static_cast< ::sf::Event::MouseMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Event_MouseMoveEvent::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseMoveEvent *inst = static_cast< ::sf::Event::MouseMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseMoveEvent::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseMoveEvent *inst = static_cast< ::sf::Event::MouseMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Event_MouseMoveEvent::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseMoveEvent *inst = static_cast< ::sf::Event::MouseMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< int >(value);
}
//----------------------------------------
void sf_Event_MouseMoveEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_MouseMoveEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_MouseMoveEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("MouseMoveEvent"), FO);
}
//----------------------------------------
void sf_Event_MouseMoveEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Event_MouseMoveEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_MouseButtonEvent::Bases = "sf::Event::MouseButtonEvent\0\0";
const char *sf_Event_MouseButtonEvent::ClassName = "sf::Event::MouseButtonEvent";
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Getter_button(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->button);
}

void sf_Event_MouseButtonEvent::Setter_button(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->button = CastToCPP< ::sf::Mouse::Button >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Event_MouseButtonEvent::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseButtonEvent::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Event_MouseButtonEvent::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseButtonEvent *inst = static_cast< ::sf::Event::MouseButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< int >(value);
}
//----------------------------------------
void sf_Event_MouseButtonEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_MouseButtonEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_MouseButtonEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("MouseButtonEvent"), FO);
}
//----------------------------------------
void sf_Event_MouseButtonEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("button"), Getter_button, Setter_button);
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Event_MouseButtonEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_MouseWheelEvent::Bases = "sf::Event::MouseWheelEvent\0\0";
const char *sf_Event_MouseWheelEvent::ClassName = "sf::Event::MouseWheelEvent";
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Getter_delta(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->delta);
}

void sf_Event_MouseWheelEvent::Setter_delta(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->delta = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->x);
}

void sf_Event_MouseWheelEvent::Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->x = CastToCPP< int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_MouseWheelEvent::Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->y);
}

void sf_Event_MouseWheelEvent::Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::MouseWheelEvent *inst = static_cast< ::sf::Event::MouseWheelEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->y = CastToCPP< int >(value);
}
//----------------------------------------
void sf_Event_MouseWheelEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_MouseWheelEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_MouseWheelEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("MouseWheelEvent"), FO);
}
//----------------------------------------
void sf_Event_MouseWheelEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("delta"), Getter_delta, Setter_delta);
    target->SetAccessor(v8::String::New("x"), Getter_x, Setter_x);
    target->SetAccessor(v8::String::New("y"), Getter_y, Setter_y);
}
//----------------------------------------
void sf_Event_MouseWheelEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_JoystickConnectEvent::Bases = "sf::Event::JoystickConnectEvent\0\0";
const char *sf_Event_JoystickConnectEvent::ClassName = "sf::Event::JoystickConnectEvent";
v8::Handle<v8::Value> sf_Event_JoystickConnectEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickConnectEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickConnectEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickConnectEvent::Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickConnectEvent *inst = static_cast< ::sf::Event::JoystickConnectEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickId);
}

void sf_Event_JoystickConnectEvent::Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickConnectEvent *inst = static_cast< ::sf::Event::JoystickConnectEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickId = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_Event_JoystickConnectEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_JoystickConnectEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_JoystickConnectEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("JoystickConnectEvent"), FO);
}
//----------------------------------------
void sf_Event_JoystickConnectEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("joystickId"), Getter_joystickId, Setter_joystickId);
}
//----------------------------------------
void sf_Event_JoystickConnectEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_JoystickMoveEvent::Bases = "sf::Event::JoystickMoveEvent\0\0";
const char *sf_Event_JoystickMoveEvent::ClassName = "sf::Event::JoystickMoveEvent";
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickId);
}

void sf_Event_JoystickMoveEvent::Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickId = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Getter_axis(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->axis);
}

void sf_Event_JoystickMoveEvent::Setter_axis(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->axis = CastToCPP< ::sf::Joystick::Axis >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickMoveEvent::Getter_position(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->position);
}

void sf_Event_JoystickMoveEvent::Setter_position(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickMoveEvent *inst = static_cast< ::sf::Event::JoystickMoveEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->position = CastToCPP< float >(value);
}
//----------------------------------------
void sf_Event_JoystickMoveEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_JoystickMoveEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_JoystickMoveEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("JoystickMoveEvent"), FO);
}
//----------------------------------------
void sf_Event_JoystickMoveEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("joystickId"), Getter_joystickId, Setter_joystickId);
    target->SetAccessor(v8::String::New("axis"), Getter_axis, Setter_axis);
    target->SetAccessor(v8::String::New("position"), Getter_position, Setter_position);
}
//----------------------------------------
void sf_Event_JoystickMoveEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event_JoystickButtonEvent::Bases = "sf::Event::JoystickButtonEvent\0\0";
const char *sf_Event_JoystickButtonEvent::ClassName = "sf::Event::JoystickButtonEvent";
v8::Handle<v8::Value> sf_Event_JoystickButtonEvent::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickButtonEvent::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickButtonEvent::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickButtonEvent::Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickButtonEvent *inst = static_cast< ::sf::Event::JoystickButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickId);
}

void sf_Event_JoystickButtonEvent::Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickButtonEvent *inst = static_cast< ::sf::Event::JoystickButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickId = CastToCPP< unsigned int >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event_JoystickButtonEvent::Getter_button(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event::JoystickButtonEvent *inst = static_cast< ::sf::Event::JoystickButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->button);
}

void sf_Event_JoystickButtonEvent::Setter_button(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event::JoystickButtonEvent *inst = static_cast< ::sf::Event::JoystickButtonEvent * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->button = CastToCPP< unsigned int >(value);
}
//----------------------------------------
void sf_Event_JoystickButtonEvent::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event_JoystickButtonEvent::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event_JoystickButtonEvent::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("JoystickButtonEvent"), FO);
}
//----------------------------------------
void sf_Event_JoystickButtonEvent::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("joystickId"), Getter_joystickId, Setter_joystickId);
    target->SetAccessor(v8::String::New("button"), Getter_button, Setter_button);
}
//----------------------------------------
void sf_Event_JoystickButtonEvent::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Event::Bases = "sf::Event\0\0";
const char *sf_Event::ClassName = "sf::Event";
v8::Handle<v8::Value> sf_Event::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_type(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->type);
}

void sf_Event::Setter_type(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->type = CastToCPP< ::sf::Event::EventType >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_size(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->size);
}

void sf_Event::Setter_size(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->size = CastToCPP< ::sf::Event::SizeEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_key(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->key);
}

void sf_Event::Setter_key(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->key = CastToCPP< ::sf::Event::KeyEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_text(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->text);
}

void sf_Event::Setter_text(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->text = CastToCPP< ::sf::Event::TextEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_mouseMove(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->mouseMove);
}

void sf_Event::Setter_mouseMove(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->mouseMove = CastToCPP< ::sf::Event::MouseMoveEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_mouseButton(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->mouseButton);
}

void sf_Event::Setter_mouseButton(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->mouseButton = CastToCPP< ::sf::Event::MouseButtonEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_mouseWheel(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->mouseWheel);
}

void sf_Event::Setter_mouseWheel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->mouseWheel = CastToCPP< ::sf::Event::MouseWheelEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_joystickMove(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickMove);
}

void sf_Event::Setter_joystickMove(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickMove = CastToCPP< ::sf::Event::JoystickMoveEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_joystickButton(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickButton);
}

void sf_Event::Setter_joystickButton(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickButton = CastToCPP< ::sf::Event::JoystickButtonEvent >(value);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Event::Getter_joystickConnect(v8::Local<v8::String> property, const v8::AccessorInfo& info) {
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    return CastToJS(inst->joystickConnect);
}

void sf_Event::Setter_joystickConnect(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info) {
    v8::HandleScope scope;
    ::sf::Event *inst = static_cast< ::sf::Event * >(v8::External::Unwrap(info.Holder()->GetInternalField(0)));
    inst->joystickConnect = CastToCPP< ::sf::Event::JoystickConnectEvent >(value);
}
//----------------------------------------
void sf_Event::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Event::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Event::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Event"), FO);
}
//----------------------------------------
void sf_Event::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->SetAccessor(v8::String::New("type"), Getter_type, Setter_type);
    target->SetAccessor(v8::String::New("size"), Getter_size, Setter_size);
    target->SetAccessor(v8::String::New("key"), Getter_key, Setter_key);
    target->SetAccessor(v8::String::New("text"), Getter_text, Setter_text);
    target->SetAccessor(v8::String::New("mouseMove"), Getter_mouseMove, Setter_mouseMove);
    target->SetAccessor(v8::String::New("mouseButton"), Getter_mouseButton, Setter_mouseButton);
    target->SetAccessor(v8::String::New("mouseWheel"), Getter_mouseWheel, Setter_mouseWheel);
    target->SetAccessor(v8::String::New("joystickMove"), Getter_joystickMove, Setter_joystickMove);
    target->SetAccessor(v8::String::New("joystickButton"), Getter_joystickButton, Setter_joystickButton);
    target->SetAccessor(v8::String::New("joystickConnect"), Getter_joystickConnect, Setter_joystickConnect);
}
//----------------------------------------
void sf_Event::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Closed"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("Resized"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("LostFocus"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("GainedFocus"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("TextEntered"), v8::Number::New(4), v8::ReadOnly);
    target->Set(v8::String::New("KeyPressed"), v8::Number::New(5), v8::ReadOnly);
    target->Set(v8::String::New("KeyReleased"), v8::Number::New(6), v8::ReadOnly);
    target->Set(v8::String::New("MouseWheelMoved"), v8::Number::New(7), v8::ReadOnly);
    target->Set(v8::String::New("MouseButtonPressed"), v8::Number::New(8), v8::ReadOnly);
    target->Set(v8::String::New("MouseButtonReleased"), v8::Number::New(9), v8::ReadOnly);
    target->Set(v8::String::New("MouseMoved"), v8::Number::New(10), v8::ReadOnly);
    target->Set(v8::String::New("MouseEntered"), v8::Number::New(11), v8::ReadOnly);
    target->Set(v8::String::New("MouseLeft"), v8::Number::New(12), v8::ReadOnly);
    target->Set(v8::String::New("JoystickButtonPressed"), v8::Number::New(13), v8::ReadOnly);
    target->Set(v8::String::New("JoystickButtonReleased"), v8::Number::New(14), v8::ReadOnly);
    target->Set(v8::String::New("JoystickMoved"), v8::Number::New(15), v8::ReadOnly);
    target->Set(v8::String::New("JoystickConnected"), v8::Number::New(16), v8::ReadOnly);
    target->Set(v8::String::New("JoystickDisconnected"), v8::Number::New(17), v8::ReadOnly);
    target->Set(v8::String::New("Count"), v8::Number::New(18), v8::ReadOnly);
}
//----------------------------------------
const char *sf_GlResource::Bases = "sf::GlResource\0\0";
const char *sf_GlResource::ClassName = "sf::GlResource";
v8::Handle<v8::Value> sf_GlResource::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sNotCreated)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_GlResource::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_GlResource::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_GlResource::Delete(MyClass *inst) {
}
//----------------------------------------
void sf_GlResource::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_GlResource::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("GlResource"), FO);
}
//----------------------------------------
void sf_GlResource::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_GlResource::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_RectangleShape::Bases = "sf::RectangleShape\0sf::Shape\0sf::Drawable\0\0";
const char *sf_RectangleShape::ClassName = "sf::RectangleShape";
v8::Handle<v8::Value> sf_RectangleShape::Create(const v8::Arguments &args) {
    const FunctionEntry Func[] = {
    { 1, 0, {}},
    { 2, 1, {{ PT_CLASS, "size" }}}
    };
    int FuncSize = 2;
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    if ( args.IsConstructCall() ) {
        v8::Handle<v8::Object> JSinst = POT->NewInstance();
        JSinst->SetPrototype(args.This()->GetPrototype());
        Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
            case 1: {
                MyClass *inst = new MyClass();
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
            case 2: {
                ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
                if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
                MyClass *inst = new MyClass(*p0);
                MakeReference(JSinst, inst);
                result = JSinst;
                break;
            }
        }
    } else {
        result = v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setSize(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "size" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setSize(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getSize(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getSize());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getPointCount(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getPointCount());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getPoint(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "index" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            unsigned int p0 = CastToCPP< unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->getPoint(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setTexture(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "texture" }}},
    { 2, 2, {{ PT_CLASS, "texture" }, { PT_BOOLEAN, "resetrect" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTexture(p0);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Texture* p0 = CastToCPP< ::sf::Texture* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            bool p1 = CastToCPP< bool >(ParamMatch.Params[1]);
            inst->setTexture(p0,p1);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setTextureRect(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "rect" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::IntRect* p0 = CastToCPP< ::sf::IntRect* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setTextureRect(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setFillColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setFillColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setOutlineColor(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "color" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Color* p0 = CastToCPP< ::sf::Color* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOutlineColor(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setOutlineThickness(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "thickness" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setOutlineThickness(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getTexture(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(*inst->getTexture());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getTextureRect(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTextureRect());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getFillColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getFillColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getOutlineColor(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOutlineColor());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getOutlineThickness(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getOutlineThickness());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getLocalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getGlobalBounds(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getGlobalBounds());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setPosition(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "position" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setPosition(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setPosition(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setRotation(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->setRotation(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setScale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factors" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setScale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setScale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_setOrigin(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "x" }, { PT_NUMBER, "y" }}},
    { 2, 1, {{ PT_CLASS, "origin" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->setOrigin(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->setOrigin(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getPosition(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getPosition());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getRotation(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getRotation());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getScale(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getScale());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getOrigin(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getOrigin());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_move(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "offsetx" }, { PT_NUMBER, "offsety" }}},
    { 2, 1, {{ PT_CLASS, "offset" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->move(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->move(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_rotate(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "angle" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            inst->rotate(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_scale(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 2, {{ PT_NUMBER, "factorx" }, { PT_NUMBER, "factory" }}},
    { 2, 1, {{ PT_CLASS, "factor" }}}
    };
    int FuncSize = 2;
    Match<2> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            float p1 = CastToCPP< float >(ParamMatch.Params[1]);
            inst->scale(p0,p1);
            result = v8::Undefined();
            break;
        }
        case 2: {
            ::sf::Vector2f* p0 = CastToCPP< ::sf::Vector2f* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            inst->scale(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_RectangleShape::Method_getInverseTransform(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS2(inst->getInverseTransform());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_RectangleShape::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_RectangleShape::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_RectangleShape::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("RectangleShape"), FO);
}
//----------------------------------------
void sf_RectangleShape::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("setSize", v8::FunctionTemplate::New(Method_setSize));
    target->Set("getSize", v8::FunctionTemplate::New(Method_getSize));
    target->Set("getPointCount", v8::FunctionTemplate::New(Method_getPointCount));
    target->Set("getPoint", v8::FunctionTemplate::New(Method_getPoint));
    target->Set("setTexture", v8::FunctionTemplate::New(Method_setTexture));
    target->Set("setTextureRect", v8::FunctionTemplate::New(Method_setTextureRect));
    target->Set("setFillColor", v8::FunctionTemplate::New(Method_setFillColor));
    target->Set("setOutlineColor", v8::FunctionTemplate::New(Method_setOutlineColor));
    target->Set("setOutlineThickness", v8::FunctionTemplate::New(Method_setOutlineThickness));
    target->Set("getTexture", v8::FunctionTemplate::New(Method_getTexture));
    target->Set("getTextureRect", v8::FunctionTemplate::New(Method_getTextureRect));
    target->Set("getFillColor", v8::FunctionTemplate::New(Method_getFillColor));
    target->Set("getOutlineColor", v8::FunctionTemplate::New(Method_getOutlineColor));
    target->Set("getOutlineThickness", v8::FunctionTemplate::New(Method_getOutlineThickness));
    target->Set("getLocalBounds", v8::FunctionTemplate::New(Method_getLocalBounds));
    target->Set("getGlobalBounds", v8::FunctionTemplate::New(Method_getGlobalBounds));
    target->Set("setPosition", v8::FunctionTemplate::New(Method_setPosition));
    target->Set("setRotation", v8::FunctionTemplate::New(Method_setRotation));
    target->Set("setScale", v8::FunctionTemplate::New(Method_setScale));
    target->Set("setOrigin", v8::FunctionTemplate::New(Method_setOrigin));
    target->Set("getPosition", v8::FunctionTemplate::New(Method_getPosition));
    target->Set("getRotation", v8::FunctionTemplate::New(Method_getRotation));
    target->Set("getScale", v8::FunctionTemplate::New(Method_getScale));
    target->Set("getOrigin", v8::FunctionTemplate::New(Method_getOrigin));
    target->Set("move", v8::FunctionTemplate::New(Method_move));
    target->Set("rotate", v8::FunctionTemplate::New(Method_rotate));
    target->Set("scale", v8::FunctionTemplate::New(Method_scale));
    target->Set("getTransform", v8::FunctionTemplate::New(Method_getTransform));
    target->Set("getInverseTransform", v8::FunctionTemplate::New(Method_getInverseTransform));
}
//----------------------------------------
void sf_RectangleShape::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Utf16::Bases = "sf::Utf16\0\0";
const char *sf_Utf16::ClassName = "sf::Utf16";
v8::Handle<v8::Value> sf_Utf16::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf16::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf16::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Utf16::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Utf16::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Utf16::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Utf16"), FO);
}
//----------------------------------------
void sf_Utf16::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Utf16::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Utf32::Bases = "sf::Utf32\0\0";
const char *sf_Utf32::ClassName = "sf::Utf32";
v8::Handle<v8::Value> sf_Utf32::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf32::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Utf32::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Utf32::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Utf32::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Utf32::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Utf32"), FO);
}
//----------------------------------------
void sf_Utf32::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Utf32::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
const char *sf_Keyboard::Bases = "sf::Keyboard\0\0";
const char *sf_Keyboard::ClassName = "sf::Keyboard";
v8::Handle<v8::Value> sf_Keyboard::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_Keyboard::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = CastToJS(copy);
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Keyboard::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_Keyboard::Method_isKeyPressed(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "key" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Keyboard::Key p0 = CastToCPP< ::sf::Keyboard::Key >(ParamMatch.Params[0]);
            result = CastToJS(::sf::Keyboard::isKeyPressed(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Keyboard::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Keyboard::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Keyboard::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Keyboard"), FO);
}
//----------------------------------------
void sf_Keyboard::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_copy", v8::FunctionTemplate::New(Object_copy));
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Keyboard::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("isKeyPressed"), v8::FunctionTemplate::New(Method_isKeyPressed));
    target->Set(v8::String::New("A"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("B"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("C"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("D"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("E"), v8::Number::New(4), v8::ReadOnly);
    target->Set(v8::String::New("F"), v8::Number::New(5), v8::ReadOnly);
    target->Set(v8::String::New("G"), v8::Number::New(6), v8::ReadOnly);
    target->Set(v8::String::New("H"), v8::Number::New(7), v8::ReadOnly);
    target->Set(v8::String::New("I"), v8::Number::New(8), v8::ReadOnly);
    target->Set(v8::String::New("J"), v8::Number::New(9), v8::ReadOnly);
    target->Set(v8::String::New("K"), v8::Number::New(10), v8::ReadOnly);
    target->Set(v8::String::New("L"), v8::Number::New(11), v8::ReadOnly);
    target->Set(v8::String::New("M"), v8::Number::New(12), v8::ReadOnly);
    target->Set(v8::String::New("N"), v8::Number::New(13), v8::ReadOnly);
    target->Set(v8::String::New("O"), v8::Number::New(14), v8::ReadOnly);
    target->Set(v8::String::New("P"), v8::Number::New(15), v8::ReadOnly);
    target->Set(v8::String::New("Q"), v8::Number::New(16), v8::ReadOnly);
    target->Set(v8::String::New("R"), v8::Number::New(17), v8::ReadOnly);
    target->Set(v8::String::New("S"), v8::Number::New(18), v8::ReadOnly);
    target->Set(v8::String::New("T"), v8::Number::New(19), v8::ReadOnly);
    target->Set(v8::String::New("U"), v8::Number::New(20), v8::ReadOnly);
    target->Set(v8::String::New("V"), v8::Number::New(21), v8::ReadOnly);
    target->Set(v8::String::New("W"), v8::Number::New(22), v8::ReadOnly);
    target->Set(v8::String::New("X"), v8::Number::New(23), v8::ReadOnly);
    target->Set(v8::String::New("Y"), v8::Number::New(24), v8::ReadOnly);
    target->Set(v8::String::New("Z"), v8::Number::New(25), v8::ReadOnly);
    target->Set(v8::String::New("Num0"), v8::Number::New(26), v8::ReadOnly);
    target->Set(v8::String::New("Num1"), v8::Number::New(27), v8::ReadOnly);
    target->Set(v8::String::New("Num2"), v8::Number::New(28), v8::ReadOnly);
    target->Set(v8::String::New("Num3"), v8::Number::New(29), v8::ReadOnly);
    target->Set(v8::String::New("Num4"), v8::Number::New(30), v8::ReadOnly);
    target->Set(v8::String::New("Num5"), v8::Number::New(31), v8::ReadOnly);
    target->Set(v8::String::New("Num6"), v8::Number::New(32), v8::ReadOnly);
    target->Set(v8::String::New("Num7"), v8::Number::New(33), v8::ReadOnly);
    target->Set(v8::String::New("Num8"), v8::Number::New(34), v8::ReadOnly);
    target->Set(v8::String::New("Num9"), v8::Number::New(35), v8::ReadOnly);
    target->Set(v8::String::New("Escape"), v8::Number::New(36), v8::ReadOnly);
    target->Set(v8::String::New("LControl"), v8::Number::New(37), v8::ReadOnly);
    target->Set(v8::String::New("LShift"), v8::Number::New(38), v8::ReadOnly);
    target->Set(v8::String::New("LAlt"), v8::Number::New(39), v8::ReadOnly);
    target->Set(v8::String::New("LSystem"), v8::Number::New(40), v8::ReadOnly);
    target->Set(v8::String::New("RControl"), v8::Number::New(41), v8::ReadOnly);
    target->Set(v8::String::New("RShift"), v8::Number::New(42), v8::ReadOnly);
    target->Set(v8::String::New("RAlt"), v8::Number::New(43), v8::ReadOnly);
    target->Set(v8::String::New("RSystem"), v8::Number::New(44), v8::ReadOnly);
    target->Set(v8::String::New("Menu"), v8::Number::New(45), v8::ReadOnly);
    target->Set(v8::String::New("LBracket"), v8::Number::New(46), v8::ReadOnly);
    target->Set(v8::String::New("RBracket"), v8::Number::New(47), v8::ReadOnly);
    target->Set(v8::String::New("SemiColon"), v8::Number::New(48), v8::ReadOnly);
    target->Set(v8::String::New("Comma"), v8::Number::New(49), v8::ReadOnly);
    target->Set(v8::String::New("Period"), v8::Number::New(50), v8::ReadOnly);
    target->Set(v8::String::New("Quote"), v8::Number::New(51), v8::ReadOnly);
    target->Set(v8::String::New("Slash"), v8::Number::New(52), v8::ReadOnly);
    target->Set(v8::String::New("BackSlash"), v8::Number::New(53), v8::ReadOnly);
    target->Set(v8::String::New("Tilde"), v8::Number::New(54), v8::ReadOnly);
    target->Set(v8::String::New("Equal"), v8::Number::New(55), v8::ReadOnly);
    target->Set(v8::String::New("Dash"), v8::Number::New(56), v8::ReadOnly);
    target->Set(v8::String::New("Space"), v8::Number::New(57), v8::ReadOnly);
    target->Set(v8::String::New("Return"), v8::Number::New(58), v8::ReadOnly);
    target->Set(v8::String::New("Back"), v8::Number::New(59), v8::ReadOnly);
    target->Set(v8::String::New("Tab"), v8::Number::New(60), v8::ReadOnly);
    target->Set(v8::String::New("PageUp"), v8::Number::New(61), v8::ReadOnly);
    target->Set(v8::String::New("PageDown"), v8::Number::New(62), v8::ReadOnly);
    target->Set(v8::String::New("End"), v8::Number::New(63), v8::ReadOnly);
    target->Set(v8::String::New("Home"), v8::Number::New(64), v8::ReadOnly);
    target->Set(v8::String::New("Insert"), v8::Number::New(65), v8::ReadOnly);
    target->Set(v8::String::New("Delete"), v8::Number::New(66), v8::ReadOnly);
    target->Set(v8::String::New("Add"), v8::Number::New(67), v8::ReadOnly);
    target->Set(v8::String::New("Subtract"), v8::Number::New(68), v8::ReadOnly);
    target->Set(v8::String::New("Multiply"), v8::Number::New(69), v8::ReadOnly);
    target->Set(v8::String::New("Divide"), v8::Number::New(70), v8::ReadOnly);
    target->Set(v8::String::New("Left"), v8::Number::New(71), v8::ReadOnly);
    target->Set(v8::String::New("Right"), v8::Number::New(72), v8::ReadOnly);
    target->Set(v8::String::New("Up"), v8::Number::New(73), v8::ReadOnly);
    target->Set(v8::String::New("Down"), v8::Number::New(74), v8::ReadOnly);
    target->Set(v8::String::New("Numpad0"), v8::Number::New(75), v8::ReadOnly);
    target->Set(v8::String::New("Numpad1"), v8::Number::New(76), v8::ReadOnly);
    target->Set(v8::String::New("Numpad2"), v8::Number::New(77), v8::ReadOnly);
    target->Set(v8::String::New("Numpad3"), v8::Number::New(78), v8::ReadOnly);
    target->Set(v8::String::New("Numpad4"), v8::Number::New(79), v8::ReadOnly);
    target->Set(v8::String::New("Numpad5"), v8::Number::New(80), v8::ReadOnly);
    target->Set(v8::String::New("Numpad6"), v8::Number::New(81), v8::ReadOnly);
    target->Set(v8::String::New("Numpad7"), v8::Number::New(82), v8::ReadOnly);
    target->Set(v8::String::New("Numpad8"), v8::Number::New(83), v8::ReadOnly);
    target->Set(v8::String::New("Numpad9"), v8::Number::New(84), v8::ReadOnly);
    target->Set(v8::String::New("F1"), v8::Number::New(85), v8::ReadOnly);
    target->Set(v8::String::New("F2"), v8::Number::New(86), v8::ReadOnly);
    target->Set(v8::String::New("F3"), v8::Number::New(87), v8::ReadOnly);
    target->Set(v8::String::New("F4"), v8::Number::New(88), v8::ReadOnly);
    target->Set(v8::String::New("F5"), v8::Number::New(89), v8::ReadOnly);
    target->Set(v8::String::New("F6"), v8::Number::New(90), v8::ReadOnly);
    target->Set(v8::String::New("F7"), v8::Number::New(91), v8::ReadOnly);
    target->Set(v8::String::New("F8"), v8::Number::New(92), v8::ReadOnly);
    target->Set(v8::String::New("F9"), v8::Number::New(93), v8::ReadOnly);
    target->Set(v8::String::New("F10"), v8::Number::New(94), v8::ReadOnly);
    target->Set(v8::String::New("F11"), v8::Number::New(95), v8::ReadOnly);
    target->Set(v8::String::New("F12"), v8::Number::New(96), v8::ReadOnly);
    target->Set(v8::String::New("F13"), v8::Number::New(97), v8::ReadOnly);
    target->Set(v8::String::New("F14"), v8::Number::New(98), v8::ReadOnly);
    target->Set(v8::String::New("F15"), v8::Number::New(99), v8::ReadOnly);
    target->Set(v8::String::New("Pause"), v8::Number::New(100), v8::ReadOnly);
    target->Set(v8::String::New("KeyCount"), v8::Number::New(101), v8::ReadOnly);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
const char *sf_TcpListener::Bases = "sf::TcpListener\0sf::Socket\0\0";
const char *sf_TcpListener::ClassName = "sf::TcpListener";
v8::Handle<v8::Value> sf_TcpListener::Create(const v8::Arguments &args) {
    if ( args.IsConstructCall() ) {
        if ( args.Length() == 0 ) {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        } else {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
        }
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sUseNew)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_getLocalPort(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->getLocalPort());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_listen(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "port" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            short unsigned int p0 = CastToCPP< short unsigned int >(ParamMatch.Params[0]);
            result = CastToJS(inst->listen(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_close(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->close();
        return v8::Undefined();
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_accept(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "socket" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::TcpSocket* p0 = CastToCPP< ::sf::TcpSocket* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            result = CastToJS(inst->accept(*p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_setBlocking(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_BOOLEAN, "blocking" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            bool p0 = CastToCPP< bool >(ParamMatch.Params[0]);
            inst->setBlocking(p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf_TcpListener::Method_isBlocking(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        return CastToJS(inst->isBlocking());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
void sf_TcpListener::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_TcpListener::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_TcpListener::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("TcpListener"), FO);
}
//----------------------------------------
void sf_TcpListener::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
    target->Set("getLocalPort", v8::FunctionTemplate::New(Method_getLocalPort));
    target->Set("listen", v8::FunctionTemplate::New(Method_listen));
    target->Set("close", v8::FunctionTemplate::New(Method_close));
    target->Set("accept", v8::FunctionTemplate::New(Method_accept));
    target->Set("setBlocking", v8::FunctionTemplate::New(Method_setBlocking));
    target->Set("isBlocking", v8::FunctionTemplate::New(Method_isBlocking));
}
//----------------------------------------
void sf_TcpListener::Register(v8::Handle<v8::FunctionTemplate> target) {
    target->Set(v8::String::New("Done"), v8::Number::New(0), v8::ReadOnly);
    target->Set(v8::String::New("NotReady"), v8::Number::New(1), v8::ReadOnly);
    target->Set(v8::String::New("Disconnected"), v8::Number::New(2), v8::ReadOnly);
    target->Set(v8::String::New("Error"), v8::Number::New(3), v8::ReadOnly);
    target->Set(v8::String::New("AnyPort"), v8::Number::New(0), v8::ReadOnly);
}
//----------------------------------------
#endif
const char *sf_Drawable::Bases = "sf::Drawable\0\0";
const char *sf_Drawable::ClassName = "sf::Drawable";
v8::Handle<v8::Value> sf_Drawable::Create(const v8::Arguments &args) {
    return v8::ThrowException(v8::Exception::Error(v8::String::New(sAbstractClass)));
}
//----------------------------------------
v8::Handle<v8::Value> sf_Drawable::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak ) {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}
//----------------------------------------
void sf_Drawable::Delete(MyClass *inst) {
    delete inst;
}
//----------------------------------------
void sf_Drawable::InitPOT(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}
//----------------------------------------
void sf_Drawable::InitPFT(v8::Handle<v8::ObjectTemplate> target) {
    if ( PFT.IsEmpty() ) {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Drawable"), FO);
}
//----------------------------------------
void sf_Drawable::Register(v8::Handle<v8::ObjectTemplate> target) {
    target->Set("_delete", v8::FunctionTemplate::New(Object_delete));
    target->Set("className", v8::String::New(ClassName));
}
//----------------------------------------
void sf_Drawable::Register(v8::Handle<v8::FunctionTemplate> target) {
}
//----------------------------------------
v8::Handle<v8::Value> sf::Method_microseconds(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Int64 p0 = CastToCPP< ::sf::Int64 >(ParamMatch.Params[0]);
            result = CastToJS(::sf::microseconds(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf::Method_milliseconds(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Int32 p0 = CastToCPP< ::sf::Int32 >(ParamMatch.Params[0]);
            result = CastToJS(::sf::milliseconds(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf::Method_err(const v8::Arguments &args) {
    if ( args.Length() == 0 ) {
        return CastToJS(::sf::err());
    } else {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs)));
    }
}
//----------------------------------------
v8::Handle<v8::Value> sf::Method_sleep(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_CLASS, "duration" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            ::sf::Time* p0 = CastToCPP< ::sf::Time* >(ParamMatch.Params[0]);
            if ( p0 == NULL ) return scope.Close(v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))));
            ::sf::sleep(*p0);
            result = v8::Undefined();
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Value> sf::Method_seconds(const v8::Arguments &args) {
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    const FunctionEntry Func[] = {
    { 1, 1, {{ PT_NUMBER, "" }}}
    };
    int FuncSize = 1;
    Match<1> ParamMatch(&Func[0], FuncSize, args);
    switch ( ParamMatch.Entry ) {
        default: result = v8::ThrowException(v8::Exception::Error(v8::String::New(sInvalidArgs))); break;
        case 1: {
            float p0 = CastToCPP< float >(ParamMatch.Params[0]);
            result = CastToJS(::sf::seconds(p0));
            break;
        }
    }
    return scope.Close(result);
}
//----------------------------------------
v8::Handle<v8::Object> sf::Init() {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->Set(v8::String::New("microseconds"), v8::FunctionTemplate::New(Method_microseconds));
        POT->Set(v8::String::New("milliseconds"), v8::FunctionTemplate::New(Method_milliseconds));
        POT->Set(v8::String::New("err"), v8::FunctionTemplate::New(Method_err));
        POT->Set(v8::String::New("sleep"), v8::FunctionTemplate::New(Method_sleep));
        POT->Set(v8::String::New("seconds"), v8::FunctionTemplate::New(Method_seconds));
        POT->Set(v8::String::New("Points"), v8::Number::New(0), v8::ReadOnly);
        POT->Set(v8::String::New("Lines"), v8::Number::New(1), v8::ReadOnly);
        POT->Set(v8::String::New("LinesStrip"), v8::Number::New(2), v8::ReadOnly);
        POT->Set(v8::String::New("Triangles"), v8::Number::New(3), v8::ReadOnly);
        POT->Set(v8::String::New("TrianglesStrip"), v8::Number::New(4), v8::ReadOnly);
        POT->Set(v8::String::New("TrianglesFan"), v8::Number::New(5), v8::ReadOnly);
        POT->Set(v8::String::New("Quads"), v8::Number::New(6), v8::ReadOnly);
        POT->Set(v8::String::New("BlendAlpha"), v8::Number::New(0), v8::ReadOnly);
        POT->Set(v8::String::New("BlendAdd"), v8::Number::New(1), v8::ReadOnly);
        POT->Set(v8::String::New("BlendMultiply"), v8::Number::New(2), v8::ReadOnly);
        POT->Set(v8::String::New("BlendNone"), v8::Number::New(3), v8::ReadOnly);
        sf_Font::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_SocketSelector::InitPOT(POT);
#endif
        sf_View::InitPOT(POT);
        sf_RenderWindow::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_Ftp_Response::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp_DirectoryResponse::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp_ListingResponse::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp::InitPOT(POT);
#endif
        sf_RenderTexture::InitPOT(POT);
        sf_SoundStream_Chunk::InitPOT(POT);
        sf_SoundStream::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_Http_Request::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Http_Response::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Http::InitPOT(POT);
#endif
        sf_CircleShape::InitPOT(POT);
        sf_Vector3i::InitPOT(POT);
        sf_VertexArray::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_Packet::InitPOT(POT);
#endif
        sf_Text::InitPOT(POT);
        sf_Vertex::InitPOT(POT);
        sf_Shader_CurrentTextureType::InitPOT(POT);
        sf_Shader::InitPOT(POT);
        sf_InputStream::InitPOT(POT);
        sf_IntRect::InitPOT(POT);
        sf_String::InitPOT(POT);
        sf_RenderStates::InitPOT(POT);
        sf_VideoMode::InitPOT(POT);
        sf_SoundBufferRecorder::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_Socket::InitPOT(POT);
#endif
        sf_Sound::InitPOT(POT);
        sf_Music::InitPOT(POT);
        sf_Shape::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_UdpSocket::InitPOT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_IpAddress::InitPOT(POT);
#endif
        sf_FloatRect::InitPOT(POT);
        sf_NonCopyable::InitPOT(POT);
        sf_Utf8::InitPOT(POT);
        sf_Vector2f::InitPOT(POT);
        sf_Vector2i::InitPOT(POT);
        sf_Vector2u::InitPOT(POT);
        sf_Vector3f::InitPOT(POT);
        sf_Transformable::InitPOT(POT);
        sf_Clock::InitPOT(POT);
        sf_Mouse::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_TcpSocket::InitPOT(POT);
#endif
        sf_SoundRecorder::InitPOT(POT);
        sf_Color::InitPOT(POT);
        sf_Texture::InitPOT(POT);
        sf_ContextSettings::InitPOT(POT);
        sf_Context::InitPOT(POT);
        sf_SoundBuffer::InitPOT(POT);
        sf_Image::InitPOT(POT);
        sf_Sprite::InitPOT(POT);
        sf_ConvexShape::InitPOT(POT);
        sf_Window::InitPOT(POT);
        sf_Time::InitPOT(POT);
        sf_Glyph::InitPOT(POT);
        sf_Transform::InitPOT(POT);
        sf_Joystick::InitPOT(POT);
        sf_RenderTarget::InitPOT(POT);
        sf_Listener::InitPOT(POT);
        sf_SoundSource::InitPOT(POT);
        sf_Event_SizeEvent::InitPOT(POT);
        sf_Event_KeyEvent::InitPOT(POT);
        sf_Event_TextEvent::InitPOT(POT);
        sf_Event_MouseMoveEvent::InitPOT(POT);
        sf_Event_MouseButtonEvent::InitPOT(POT);
        sf_Event_MouseWheelEvent::InitPOT(POT);
        sf_Event_JoystickConnectEvent::InitPOT(POT);
        sf_Event_JoystickMoveEvent::InitPOT(POT);
        sf_Event_JoystickButtonEvent::InitPOT(POT);
        sf_Event::InitPOT(POT);
        sf_GlResource::InitPOT(POT);
        sf_RectangleShape::InitPOT(POT);
        sf_Utf16::InitPOT(POT);
        sf_Utf32::InitPOT(POT);
        sf_Keyboard::InitPOT(POT);
#ifndef NO_SFML_NETWORK
        sf_TcpListener::InitPOT(POT);
#endif
        sf_Drawable::InitPOT(POT);
        sf_Font::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_SocketSelector::InitPFT(POT);
#endif
        sf_View::InitPFT(POT);
        sf_RenderWindow::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_Ftp_Response::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp_DirectoryResponse::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp_ListingResponse::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Ftp::InitPFT(POT);
#endif
        sf_RenderTexture::InitPFT(POT);
        sf_SoundStream_Chunk::InitPFT(POT);
        sf_SoundStream::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_Http_Request::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Http_Response::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_Http::InitPFT(POT);
#endif
        sf_CircleShape::InitPFT(POT);
        sf_Vector3i::InitPFT(POT);
        sf_VertexArray::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_Packet::InitPFT(POT);
#endif
        sf_Text::InitPFT(POT);
        sf_Vertex::InitPFT(POT);
        sf_Shader_CurrentTextureType::InitPFT(POT);
        sf_Shader::InitPFT(POT);
        sf_InputStream::InitPFT(POT);
        sf_IntRect::InitPFT(POT);
        sf_String::InitPFT(POT);
        sf_RenderStates::InitPFT(POT);
        sf_VideoMode::InitPFT(POT);
        sf_SoundBufferRecorder::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_Socket::InitPFT(POT);
#endif
        sf_Sound::InitPFT(POT);
        sf_Music::InitPFT(POT);
        sf_Shape::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_UdpSocket::InitPFT(POT);
#endif
#ifndef NO_SFML_NETWORK
        sf_IpAddress::InitPFT(POT);
#endif
        sf_FloatRect::InitPFT(POT);
        sf_NonCopyable::InitPFT(POT);
        sf_Utf8::InitPFT(POT);
        sf_Vector2f::InitPFT(POT);
        sf_Vector2i::InitPFT(POT);
        sf_Vector2u::InitPFT(POT);
        sf_Vector3f::InitPFT(POT);
        sf_Transformable::InitPFT(POT);
        sf_Clock::InitPFT(POT);
        sf_Mouse::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_TcpSocket::InitPFT(POT);
#endif
        sf_SoundRecorder::InitPFT(POT);
        sf_Color::InitPFT(POT);
        sf_Texture::InitPFT(POT);
        sf_ContextSettings::InitPFT(POT);
        sf_Context::InitPFT(POT);
        sf_SoundBuffer::InitPFT(POT);
        sf_Image::InitPFT(POT);
        sf_Sprite::InitPFT(POT);
        sf_ConvexShape::InitPFT(POT);
        sf_Window::InitPFT(POT);
        sf_Time::InitPFT(POT);
        sf_Glyph::InitPFT(POT);
        sf_Transform::InitPFT(POT);
        sf_Joystick::InitPFT(POT);
        sf_RenderTarget::InitPFT(POT);
        sf_Listener::InitPFT(POT);
        sf_SoundSource::InitPFT(POT);
        sf_Event_SizeEvent::InitPFT(POT);
        sf_Event_KeyEvent::InitPFT(POT);
        sf_Event_TextEvent::InitPFT(POT);
        sf_Event_MouseMoveEvent::InitPFT(POT);
        sf_Event_MouseButtonEvent::InitPFT(POT);
        sf_Event_MouseWheelEvent::InitPFT(POT);
        sf_Event_JoystickConnectEvent::InitPFT(POT);
        sf_Event_JoystickMoveEvent::InitPFT(POT);
        sf_Event_JoystickButtonEvent::InitPFT(POT);
        sf_Event::InitPFT(POT);
        sf_GlResource::InitPFT(POT);
        sf_RectangleShape::InitPFT(POT);
        sf_Utf16::InitPFT(POT);
        sf_Utf32::InitPFT(POT);
        sf_Keyboard::InitPFT(POT);
#ifndef NO_SFML_NETWORK
        sf_TcpListener::InitPFT(POT);
#endif
        sf_Drawable::InitPFT(POT);
        sf_Style::Init(POT);
    }
    return POT->NewInstance();
}
//----------------------------------------
void sf_Style::Init(v8::Handle<v8::ObjectTemplate> target) {
    if ( POT.IsEmpty() ) {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->Set(v8::String::New("None"), v8::Number::New(0), v8::ReadOnly);
        POT->Set(v8::String::New("Titlebar"), v8::Number::New(1), v8::ReadOnly);
        POT->Set(v8::String::New("Resize"), v8::Number::New(2), v8::ReadOnly);
        POT->Set(v8::String::New("Close"), v8::Number::New(4), v8::ReadOnly);
        POT->Set(v8::String::New("Fullscreen"), v8::Number::New(8), v8::ReadOnly);
        POT->Set(v8::String::New("Default"), v8::Number::New(7), v8::ReadOnly);
    }
    target->Set(v8::String::New("Style"), POT->NewInstance());
}
//----------------------------------------
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Font &JS)
{
    ::sf::Font *Ptr = new ::sf::Font(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Font::POT->NewInstance();
    sf_v8::sf_Font::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Font &JS)
{
    ::sf::Font *Ptr = (::sf::Font *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Font::POT->NewInstance();
    sf_v8::sf_Font::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Font &CPP)
{
    ::sf::Font *Ptr = sf_v8::sf_Font::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Font *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Font::POT->NewInstance();
    sf_v8::sf_Font::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Font *&CPP)
{
    CPP = sf_v8::sf_Font::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SocketSelector &JS)
{
    ::sf::SocketSelector *Ptr = new ::sf::SocketSelector(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_SocketSelector::POT->NewInstance();
    sf_v8::sf_SocketSelector::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::SocketSelector &JS)
{
    ::sf::SocketSelector *Ptr = (::sf::SocketSelector *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SocketSelector::POT->NewInstance();
    sf_v8::sf_SocketSelector::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SocketSelector &CPP)
{
    ::sf::SocketSelector *Ptr = sf_v8::sf_SocketSelector::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::SocketSelector *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SocketSelector::POT->NewInstance();
    sf_v8::sf_SocketSelector::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SocketSelector *&CPP)
{
    CPP = sf_v8::sf_SocketSelector::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::View &JS)
{
    ::sf::View *Ptr = new ::sf::View(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_View::POT->NewInstance();
    sf_v8::sf_View::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::View &JS)
{
    ::sf::View *Ptr = (::sf::View *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_View::POT->NewInstance();
    sf_v8::sf_View::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::View &CPP)
{
    ::sf::View *Ptr = sf_v8::sf_View::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::View *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_View::POT->NewInstance();
    sf_v8::sf_View::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::View *&CPP)
{
    CPP = sf_v8::sf_View::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderWindow &JS)
{
    ::sf::RenderWindow *Ptr = (::sf::RenderWindow *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderWindow::POT->NewInstance();
    sf_v8::sf_RenderWindow::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::RenderWindow *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderWindow::POT->NewInstance();
    sf_v8::sf_RenderWindow::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderWindow *&CPP)
{
    CPP = sf_v8::sf_RenderWindow::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::Response &JS)
{
    ::sf::Ftp::Response *Ptr = new ::sf::Ftp::Response(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_Response::POT->NewInstance();
    sf_v8::sf_Ftp_Response::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::Response &JS)
{
    ::sf::Ftp::Response *Ptr = (::sf::Ftp::Response *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_Response::POT->NewInstance();
    sf_v8::sf_Ftp_Response::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response &CPP)
{
    ::sf::Ftp::Response *Ptr = sf_v8::sf_Ftp_Response::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::Response *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_Response::POT->NewInstance();
    sf_v8::sf_Ftp_Response::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response *&CPP)
{
    CPP = sf_v8::sf_Ftp_Response::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::Response::Status JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response::Status &CPP)
{
    CPP = static_cast< ::sf::Ftp::Response::Status >(Value->IntegerValue());
}

}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::DirectoryResponse &JS)
{
    ::sf::Ftp::DirectoryResponse *Ptr = new ::sf::Ftp::DirectoryResponse(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_DirectoryResponse::POT->NewInstance();
    sf_v8::sf_Ftp_DirectoryResponse::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::DirectoryResponse &JS)
{
    ::sf::Ftp::DirectoryResponse *Ptr = (::sf::Ftp::DirectoryResponse *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_DirectoryResponse::POT->NewInstance();
    sf_v8::sf_Ftp_DirectoryResponse::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::DirectoryResponse &CPP)
{
    ::sf::Ftp::DirectoryResponse *Ptr = sf_v8::sf_Ftp_DirectoryResponse::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::DirectoryResponse *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_DirectoryResponse::POT->NewInstance();
    sf_v8::sf_Ftp_DirectoryResponse::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::DirectoryResponse *&CPP)
{
    CPP = sf_v8::sf_Ftp_DirectoryResponse::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::ListingResponse &JS)
{
    ::sf::Ftp::ListingResponse *Ptr = new ::sf::Ftp::ListingResponse(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_ListingResponse::POT->NewInstance();
    sf_v8::sf_Ftp_ListingResponse::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::ListingResponse &JS)
{
    ::sf::Ftp::ListingResponse *Ptr = (::sf::Ftp::ListingResponse *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_ListingResponse::POT->NewInstance();
    sf_v8::sf_Ftp_ListingResponse::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::ListingResponse &CPP)
{
    ::sf::Ftp::ListingResponse *Ptr = sf_v8::sf_Ftp_ListingResponse::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::ListingResponse *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp_ListingResponse::POT->NewInstance();
    sf_v8::sf_Ftp_ListingResponse::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::ListingResponse *&CPP)
{
    CPP = sf_v8::sf_Ftp_ListingResponse::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp &JS)
{
    ::sf::Ftp *Ptr = (::sf::Ftp *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp::POT->NewInstance();
    sf_v8::sf_Ftp::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Ftp *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Ftp::POT->NewInstance();
    sf_v8::sf_Ftp::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp *&CPP)
{
    CPP = sf_v8::sf_Ftp::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::TransferMode JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::TransferMode &CPP)
{
    CPP = static_cast< ::sf::Ftp::TransferMode >(Value->IntegerValue());
}

}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderTexture &JS)
{
    ::sf::RenderTexture *Ptr = (::sf::RenderTexture *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderTexture::POT->NewInstance();
    sf_v8::sf_RenderTexture::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::RenderTexture *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderTexture::POT->NewInstance();
    sf_v8::sf_RenderTexture::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderTexture *&CPP)
{
    CPP = sf_v8::sf_RenderTexture::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundStream::Chunk &JS)
{
    ::sf::SoundStream::Chunk *Ptr = new ::sf::SoundStream::Chunk(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundStream_Chunk::POT->NewInstance();
    sf_v8::sf_SoundStream_Chunk::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundStream::Chunk &JS)
{
    ::sf::SoundStream::Chunk *Ptr = (::sf::SoundStream::Chunk *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundStream_Chunk::POT->NewInstance();
    sf_v8::sf_SoundStream_Chunk::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream::Chunk &CPP)
{
    ::sf::SoundStream::Chunk *Ptr = sf_v8::sf_SoundStream_Chunk::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundStream::Chunk *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundStream_Chunk::POT->NewInstance();
    sf_v8::sf_SoundStream_Chunk::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream::Chunk *&CPP)
{
    CPP = sf_v8::sf_SoundStream_Chunk::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundStream &JS)
{
    ::sf::SoundStream *Ptr = (::sf::SoundStream *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundStream::POT->NewInstance();
    sf_v8::sf_SoundStream::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundStream *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundStream::POT->NewInstance();
    sf_v8::sf_SoundStream::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream *&CPP)
{
    CPP = sf_v8::sf_SoundStream::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Http::Request &JS)
{
    ::sf::Http::Request *Ptr = new ::sf::Http::Request(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Request::POT->NewInstance();
    sf_v8::sf_Http_Request::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http::Request &JS)
{
    ::sf::Http::Request *Ptr = (::sf::Http::Request *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Request::POT->NewInstance();
    sf_v8::sf_Http_Request::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request &CPP)
{
    ::sf::Http::Request *Ptr = sf_v8::sf_Http_Request::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Http::Request *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Request::POT->NewInstance();
    sf_v8::sf_Http_Request::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request *&CPP)
{
    CPP = sf_v8::sf_Http_Request::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Request::Method JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request::Method &CPP)
{
    CPP = static_cast< ::sf::Http::Request::Method >(Value->IntegerValue());
}

}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Http::Response &JS)
{
    ::sf::Http::Response *Ptr = new ::sf::Http::Response(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Response::POT->NewInstance();
    sf_v8::sf_Http_Response::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http::Response &JS)
{
    ::sf::Http::Response *Ptr = (::sf::Http::Response *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Response::POT->NewInstance();
    sf_v8::sf_Http_Response::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response &CPP)
{
    ::sf::Http::Response *Ptr = sf_v8::sf_Http_Response::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Http::Response *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Http_Response::POT->NewInstance();
    sf_v8::sf_Http_Response::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response *&CPP)
{
    CPP = sf_v8::sf_Http_Response::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Response::Status JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response::Status &CPP)
{
    CPP = static_cast< ::sf::Http::Response::Status >(Value->IntegerValue());
}

}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http &JS)
{
    ::sf::Http *Ptr = (::sf::Http *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Http::POT->NewInstance();
    sf_v8::sf_Http::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Http *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Http::POT->NewInstance();
    sf_v8::sf_Http::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http *&CPP)
{
    CPP = sf_v8::sf_Http::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::CircleShape &JS)
{
    ::sf::CircleShape *Ptr = new ::sf::CircleShape(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_CircleShape::POT->NewInstance();
    sf_v8::sf_CircleShape::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::CircleShape &JS)
{
    ::sf::CircleShape *Ptr = (::sf::CircleShape *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_CircleShape::POT->NewInstance();
    sf_v8::sf_CircleShape::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::CircleShape &CPP)
{
    ::sf::CircleShape *Ptr = sf_v8::sf_CircleShape::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::CircleShape *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_CircleShape::POT->NewInstance();
    sf_v8::sf_CircleShape::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::CircleShape *&CPP)
{
    CPP = sf_v8::sf_CircleShape::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector3i &JS)
{
    ::sf::Vector3i *Ptr = new ::sf::Vector3i(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3i::POT->NewInstance();
    sf_v8::sf_Vector3i::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector3i &JS)
{
    ::sf::Vector3i *Ptr = (::sf::Vector3i *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3i::POT->NewInstance();
    sf_v8::sf_Vector3i::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3i &CPP)
{
    ::sf::Vector3i *Ptr = sf_v8::sf_Vector3i::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vector3i *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3i::POT->NewInstance();
    sf_v8::sf_Vector3i::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3i *&CPP)
{
    CPP = sf_v8::sf_Vector3i::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::VertexArray &JS)
{
    ::sf::VertexArray *Ptr = new ::sf::VertexArray(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_VertexArray::POT->NewInstance();
    sf_v8::sf_VertexArray::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::VertexArray &JS)
{
    ::sf::VertexArray *Ptr = (::sf::VertexArray *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_VertexArray::POT->NewInstance();
    sf_v8::sf_VertexArray::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VertexArray &CPP)
{
    ::sf::VertexArray *Ptr = sf_v8::sf_VertexArray::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::VertexArray *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_VertexArray::POT->NewInstance();
    sf_v8::sf_VertexArray::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VertexArray *&CPP)
{
    CPP = sf_v8::sf_VertexArray::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Packet &JS)
{
    ::sf::Packet *Ptr = new ::sf::Packet(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Packet::POT->NewInstance();
    sf_v8::sf_Packet::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Packet &JS)
{
    ::sf::Packet *Ptr = (::sf::Packet *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Packet::POT->NewInstance();
    sf_v8::sf_Packet::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Packet &CPP)
{
    ::sf::Packet *Ptr = sf_v8::sf_Packet::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Packet *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Packet::POT->NewInstance();
    sf_v8::sf_Packet::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Packet *&CPP)
{
    CPP = sf_v8::sf_Packet::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Text &JS)
{
    ::sf::Text *Ptr = new ::sf::Text(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Text::POT->NewInstance();
    sf_v8::sf_Text::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Text &JS)
{
    ::sf::Text *Ptr = (::sf::Text *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Text::POT->NewInstance();
    sf_v8::sf_Text::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text &CPP)
{
    ::sf::Text *Ptr = sf_v8::sf_Text::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Text *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Text::POT->NewInstance();
    sf_v8::sf_Text::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text *&CPP)
{
    CPP = sf_v8::sf_Text::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Text::Style JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text::Style &CPP)
{
    CPP = static_cast< ::sf::Text::Style >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vertex &JS)
{
    ::sf::Vertex *Ptr = new ::sf::Vertex(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vertex::POT->NewInstance();
    sf_v8::sf_Vertex::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vertex &JS)
{
    ::sf::Vertex *Ptr = (::sf::Vertex *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vertex::POT->NewInstance();
    sf_v8::sf_Vertex::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vertex &CPP)
{
    ::sf::Vertex *Ptr = sf_v8::sf_Vertex::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vertex *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vertex::POT->NewInstance();
    sf_v8::sf_Vertex::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vertex *&CPP)
{
    CPP = sf_v8::sf_Vertex::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Shader::CurrentTextureType &JS)
{
    ::sf::Shader::CurrentTextureType *Ptr = new ::sf::Shader::CurrentTextureType(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Shader_CurrentTextureType::POT->NewInstance();
    sf_v8::sf_Shader_CurrentTextureType::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shader::CurrentTextureType &JS)
{
    ::sf::Shader::CurrentTextureType *Ptr = (::sf::Shader::CurrentTextureType *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Shader_CurrentTextureType::POT->NewInstance();
    sf_v8::sf_Shader_CurrentTextureType::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::CurrentTextureType &CPP)
{
    ::sf::Shader::CurrentTextureType *Ptr = sf_v8::sf_Shader_CurrentTextureType::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Shader::CurrentTextureType *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Shader_CurrentTextureType::POT->NewInstance();
    sf_v8::sf_Shader_CurrentTextureType::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::CurrentTextureType *&CPP)
{
    CPP = sf_v8::sf_Shader_CurrentTextureType::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shader &JS)
{
    ::sf::Shader *Ptr = (::sf::Shader *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Shader::POT->NewInstance();
    sf_v8::sf_Shader::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Shader *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Shader::POT->NewInstance();
    sf_v8::sf_Shader::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader *&CPP)
{
    CPP = sf_v8::sf_Shader::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Shader::Type JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::Type &CPP)
{
    CPP = static_cast< ::sf::Shader::Type >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::InputStream &JS)
{
    ::sf::InputStream *Ptr = (::sf::InputStream *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_InputStream::POT->NewInstance();
    sf_v8::sf_InputStream::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::InputStream &CPP)
{
    ::sf::InputStream *Ptr = sf_v8::sf_InputStream::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::InputStream *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_InputStream::POT->NewInstance();
    sf_v8::sf_InputStream::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::InputStream *&CPP)
{
    CPP = sf_v8::sf_InputStream::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::IntRect &JS)
{
    ::sf::IntRect *Ptr = new ::sf::IntRect(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_IntRect::POT->NewInstance();
    sf_v8::sf_IntRect::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::IntRect &JS)
{
    ::sf::IntRect *Ptr = (::sf::IntRect *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_IntRect::POT->NewInstance();
    sf_v8::sf_IntRect::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IntRect &CPP)
{
    ::sf::IntRect *Ptr = sf_v8::sf_IntRect::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::IntRect *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_IntRect::POT->NewInstance();
    sf_v8::sf_IntRect::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IntRect *&CPP)
{
    CPP = sf_v8::sf_IntRect::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::String &JS)
{
    ::sf::String *Ptr = new ::sf::String(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_String::POT->NewInstance();
    sf_v8::sf_String::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::String &JS)
{
    ::sf::String *Ptr = (::sf::String *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_String::POT->NewInstance();
    sf_v8::sf_String::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::String &CPP)
{
    ::sf::String *Ptr = sf_v8::sf_String::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::String *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_String::POT->NewInstance();
    sf_v8::sf_String::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::String *&CPP)
{
    CPP = sf_v8::sf_String::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::RenderStates &JS)
{
    ::sf::RenderStates *Ptr = new ::sf::RenderStates(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderStates::POT->NewInstance();
    sf_v8::sf_RenderStates::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderStates &JS)
{
    ::sf::RenderStates *Ptr = (::sf::RenderStates *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderStates::POT->NewInstance();
    sf_v8::sf_RenderStates::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderStates &CPP)
{
    ::sf::RenderStates *Ptr = sf_v8::sf_RenderStates::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::RenderStates *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderStates::POT->NewInstance();
    sf_v8::sf_RenderStates::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderStates *&CPP)
{
    CPP = sf_v8::sf_RenderStates::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::VideoMode &JS)
{
    ::sf::VideoMode *Ptr = new ::sf::VideoMode(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_VideoMode::POT->NewInstance();
    sf_v8::sf_VideoMode::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::VideoMode &JS)
{
    ::sf::VideoMode *Ptr = (::sf::VideoMode *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_VideoMode::POT->NewInstance();
    sf_v8::sf_VideoMode::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VideoMode &CPP)
{
    ::sf::VideoMode *Ptr = sf_v8::sf_VideoMode::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::VideoMode *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_VideoMode::POT->NewInstance();
    sf_v8::sf_VideoMode::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VideoMode *&CPP)
{
    CPP = sf_v8::sf_VideoMode::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundBufferRecorder &JS)
{
    ::sf::SoundBufferRecorder *Ptr = (::sf::SoundBufferRecorder *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundBufferRecorder::POT->NewInstance();
    sf_v8::sf_SoundBufferRecorder::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundBufferRecorder *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundBufferRecorder::POT->NewInstance();
    sf_v8::sf_SoundBufferRecorder::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBufferRecorder *&CPP)
{
    CPP = sf_v8::sf_SoundBufferRecorder::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Socket &JS)
{
    ::sf::Socket *Ptr = (::sf::Socket *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Socket::POT->NewInstance();
    sf_v8::sf_Socket::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Socket *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Socket::POT->NewInstance();
    sf_v8::sf_Socket::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Socket *&CPP)
{
    CPP = sf_v8::sf_Socket::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Socket::Status JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Socket::Status &CPP)
{
    CPP = static_cast< ::sf::Socket::Status >(Value->IntegerValue());
}

}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Sound &JS)
{
    ::sf::Sound *Ptr = new ::sf::Sound(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Sound::POT->NewInstance();
    sf_v8::sf_Sound::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Sound &JS)
{
    ::sf::Sound *Ptr = (::sf::Sound *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Sound::POT->NewInstance();
    sf_v8::sf_Sound::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sound &CPP)
{
    ::sf::Sound *Ptr = sf_v8::sf_Sound::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Sound *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Sound::POT->NewInstance();
    sf_v8::sf_Sound::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sound *&CPP)
{
    CPP = sf_v8::sf_Sound::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Music &JS)
{
    ::sf::Music *Ptr = (::sf::Music *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Music::POT->NewInstance();
    sf_v8::sf_Music::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Music *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Music::POT->NewInstance();
    sf_v8::sf_Music::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Music *&CPP)
{
    CPP = sf_v8::sf_Music::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shape &JS)
{
    ::sf::Shape *Ptr = (::sf::Shape *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Shape::POT->NewInstance();
    sf_v8::sf_Shape::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shape &CPP)
{
    ::sf::Shape *Ptr = sf_v8::sf_Shape::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Shape *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Shape::POT->NewInstance();
    sf_v8::sf_Shape::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shape *&CPP)
{
    CPP = sf_v8::sf_Shape::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::UdpSocket &JS)
{
    ::sf::UdpSocket *Ptr = (::sf::UdpSocket *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_UdpSocket::POT->NewInstance();
    sf_v8::sf_UdpSocket::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::UdpSocket *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_UdpSocket::POT->NewInstance();
    sf_v8::sf_UdpSocket::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::UdpSocket *&CPP)
{
    CPP = sf_v8::sf_UdpSocket::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::IpAddress &JS)
{
    ::sf::IpAddress *Ptr = new ::sf::IpAddress(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_IpAddress::POT->NewInstance();
    sf_v8::sf_IpAddress::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::IpAddress &JS)
{
    ::sf::IpAddress *Ptr = (::sf::IpAddress *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_IpAddress::POT->NewInstance();
    sf_v8::sf_IpAddress::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IpAddress &CPP)
{
    ::sf::IpAddress *Ptr = sf_v8::sf_IpAddress::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::IpAddress *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_IpAddress::POT->NewInstance();
    sf_v8::sf_IpAddress::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IpAddress *&CPP)
{
    CPP = sf_v8::sf_IpAddress::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::FloatRect &JS)
{
    ::sf::FloatRect *Ptr = new ::sf::FloatRect(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_FloatRect::POT->NewInstance();
    sf_v8::sf_FloatRect::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::FloatRect &JS)
{
    ::sf::FloatRect *Ptr = (::sf::FloatRect *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_FloatRect::POT->NewInstance();
    sf_v8::sf_FloatRect::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::FloatRect &CPP)
{
    ::sf::FloatRect *Ptr = sf_v8::sf_FloatRect::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::FloatRect *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_FloatRect::POT->NewInstance();
    sf_v8::sf_FloatRect::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::FloatRect *&CPP)
{
    CPP = sf_v8::sf_FloatRect::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::NonCopyable &JS)
{
    ::sf::NonCopyable *Ptr = (::sf::NonCopyable *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_NonCopyable::POT->NewInstance();
    sf_v8::sf_NonCopyable::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::NonCopyable *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_NonCopyable::POT->NewInstance();
    sf_v8::sf_NonCopyable::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::NonCopyable *&CPP)
{
    CPP = sf_v8::sf_NonCopyable::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf8 &JS)
{
    ::sf::Utf8 *Ptr = new ::sf::Utf8(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf8::POT->NewInstance();
    sf_v8::sf_Utf8::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf8 &JS)
{
    ::sf::Utf8 *Ptr = (::sf::Utf8 *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf8::POT->NewInstance();
    sf_v8::sf_Utf8::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf8 &CPP)
{
    ::sf::Utf8 *Ptr = sf_v8::sf_Utf8::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Utf8 *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf8::POT->NewInstance();
    sf_v8::sf_Utf8::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf8 *&CPP)
{
    CPP = sf_v8::sf_Utf8::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2f &JS)
{
    ::sf::Vector2f *Ptr = new ::sf::Vector2f(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2f::POT->NewInstance();
    sf_v8::sf_Vector2f::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2f &JS)
{
    ::sf::Vector2f *Ptr = (::sf::Vector2f *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2f::POT->NewInstance();
    sf_v8::sf_Vector2f::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2f &CPP)
{
    ::sf::Vector2f *Ptr = sf_v8::sf_Vector2f::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vector2f *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2f::POT->NewInstance();
    sf_v8::sf_Vector2f::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2f *&CPP)
{
    CPP = sf_v8::sf_Vector2f::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2i &JS)
{
    ::sf::Vector2i *Ptr = new ::sf::Vector2i(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2i::POT->NewInstance();
    sf_v8::sf_Vector2i::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2i &JS)
{
    ::sf::Vector2i *Ptr = (::sf::Vector2i *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2i::POT->NewInstance();
    sf_v8::sf_Vector2i::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2i &CPP)
{
    ::sf::Vector2i *Ptr = sf_v8::sf_Vector2i::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vector2i *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2i::POT->NewInstance();
    sf_v8::sf_Vector2i::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2i *&CPP)
{
    CPP = sf_v8::sf_Vector2i::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2u &JS)
{
    ::sf::Vector2u *Ptr = new ::sf::Vector2u(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2u::POT->NewInstance();
    sf_v8::sf_Vector2u::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2u &JS)
{
    ::sf::Vector2u *Ptr = (::sf::Vector2u *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2u::POT->NewInstance();
    sf_v8::sf_Vector2u::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2u &CPP)
{
    ::sf::Vector2u *Ptr = sf_v8::sf_Vector2u::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vector2u *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector2u::POT->NewInstance();
    sf_v8::sf_Vector2u::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2u *&CPP)
{
    CPP = sf_v8::sf_Vector2u::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector3f &JS)
{
    ::sf::Vector3f *Ptr = new ::sf::Vector3f(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3f::POT->NewInstance();
    sf_v8::sf_Vector3f::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector3f &JS)
{
    ::sf::Vector3f *Ptr = (::sf::Vector3f *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3f::POT->NewInstance();
    sf_v8::sf_Vector3f::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3f &CPP)
{
    ::sf::Vector3f *Ptr = sf_v8::sf_Vector3f::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Vector3f *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Vector3f::POT->NewInstance();
    sf_v8::sf_Vector3f::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3f *&CPP)
{
    CPP = sf_v8::sf_Vector3f::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Transformable &JS)
{
    ::sf::Transformable *Ptr = new ::sf::Transformable(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Transformable::POT->NewInstance();
    sf_v8::sf_Transformable::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Transformable &JS)
{
    ::sf::Transformable *Ptr = (::sf::Transformable *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Transformable::POT->NewInstance();
    sf_v8::sf_Transformable::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transformable &CPP)
{
    ::sf::Transformable *Ptr = sf_v8::sf_Transformable::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Transformable *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Transformable::POT->NewInstance();
    sf_v8::sf_Transformable::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transformable *&CPP)
{
    CPP = sf_v8::sf_Transformable::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Clock &JS)
{
    ::sf::Clock *Ptr = new ::sf::Clock(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Clock::POT->NewInstance();
    sf_v8::sf_Clock::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Clock &JS)
{
    ::sf::Clock *Ptr = (::sf::Clock *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Clock::POT->NewInstance();
    sf_v8::sf_Clock::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Clock &CPP)
{
    ::sf::Clock *Ptr = sf_v8::sf_Clock::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Clock *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Clock::POT->NewInstance();
    sf_v8::sf_Clock::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Clock *&CPP)
{
    CPP = sf_v8::sf_Clock::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Mouse &JS)
{
    ::sf::Mouse *Ptr = new ::sf::Mouse(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Mouse::POT->NewInstance();
    sf_v8::sf_Mouse::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Mouse &JS)
{
    ::sf::Mouse *Ptr = (::sf::Mouse *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Mouse::POT->NewInstance();
    sf_v8::sf_Mouse::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse &CPP)
{
    ::sf::Mouse *Ptr = sf_v8::sf_Mouse::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Mouse *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Mouse::POT->NewInstance();
    sf_v8::sf_Mouse::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse *&CPP)
{
    CPP = sf_v8::sf_Mouse::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Mouse::Button JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse::Button &CPP)
{
    CPP = static_cast< ::sf::Mouse::Button >(Value->IntegerValue());
}

}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::TcpSocket &JS)
{
    ::sf::TcpSocket *Ptr = (::sf::TcpSocket *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_TcpSocket::POT->NewInstance();
    sf_v8::sf_TcpSocket::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::TcpSocket *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_TcpSocket::POT->NewInstance();
    sf_v8::sf_TcpSocket::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::TcpSocket *&CPP)
{
    CPP = sf_v8::sf_TcpSocket::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundRecorder &JS)
{
    ::sf::SoundRecorder *Ptr = (::sf::SoundRecorder *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundRecorder::POT->NewInstance();
    sf_v8::sf_SoundRecorder::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundRecorder *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundRecorder::POT->NewInstance();
    sf_v8::sf_SoundRecorder::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundRecorder *&CPP)
{
    CPP = sf_v8::sf_SoundRecorder::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Color &JS)
{
    ::sf::Color *Ptr = new ::sf::Color(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Color::POT->NewInstance();
    sf_v8::sf_Color::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Color &JS)
{
    ::sf::Color *Ptr = (::sf::Color *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Color::POT->NewInstance();
    sf_v8::sf_Color::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Color &CPP)
{
    ::sf::Color *Ptr = sf_v8::sf_Color::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Color *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Color::POT->NewInstance();
    sf_v8::sf_Color::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Color *&CPP)
{
    CPP = sf_v8::sf_Color::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Texture &JS)
{
    ::sf::Texture *Ptr = new ::sf::Texture(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Texture::POT->NewInstance();
    sf_v8::sf_Texture::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Texture &JS)
{
    ::sf::Texture *Ptr = (::sf::Texture *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Texture::POT->NewInstance();
    sf_v8::sf_Texture::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture &CPP)
{
    ::sf::Texture *Ptr = sf_v8::sf_Texture::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Texture *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Texture::POT->NewInstance();
    sf_v8::sf_Texture::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture *&CPP)
{
    CPP = sf_v8::sf_Texture::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Texture::CoordinateType JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture::CoordinateType &CPP)
{
    CPP = static_cast< ::sf::Texture::CoordinateType >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::ContextSettings &JS)
{
    ::sf::ContextSettings *Ptr = new ::sf::ContextSettings(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_ContextSettings::POT->NewInstance();
    sf_v8::sf_ContextSettings::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::ContextSettings &JS)
{
    ::sf::ContextSettings *Ptr = (::sf::ContextSettings *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_ContextSettings::POT->NewInstance();
    sf_v8::sf_ContextSettings::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ContextSettings &CPP)
{
    ::sf::ContextSettings *Ptr = sf_v8::sf_ContextSettings::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::ContextSettings *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_ContextSettings::POT->NewInstance();
    sf_v8::sf_ContextSettings::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ContextSettings *&CPP)
{
    CPP = sf_v8::sf_ContextSettings::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Context &JS)
{
    ::sf::Context *Ptr = (::sf::Context *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Context::POT->NewInstance();
    sf_v8::sf_Context::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Context *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Context::POT->NewInstance();
    sf_v8::sf_Context::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Context *&CPP)
{
    CPP = sf_v8::sf_Context::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundBuffer &JS)
{
    ::sf::SoundBuffer *Ptr = new ::sf::SoundBuffer(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundBuffer::POT->NewInstance();
    sf_v8::sf_SoundBuffer::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundBuffer &JS)
{
    ::sf::SoundBuffer *Ptr = (::sf::SoundBuffer *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundBuffer::POT->NewInstance();
    sf_v8::sf_SoundBuffer::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBuffer &CPP)
{
    ::sf::SoundBuffer *Ptr = sf_v8::sf_SoundBuffer::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundBuffer *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundBuffer::POT->NewInstance();
    sf_v8::sf_SoundBuffer::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBuffer *&CPP)
{
    CPP = sf_v8::sf_SoundBuffer::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Image &JS)
{
    ::sf::Image *Ptr = new ::sf::Image(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Image::POT->NewInstance();
    sf_v8::sf_Image::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Image &JS)
{
    ::sf::Image *Ptr = (::sf::Image *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Image::POT->NewInstance();
    sf_v8::sf_Image::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Image &CPP)
{
    ::sf::Image *Ptr = sf_v8::sf_Image::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Image *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Image::POT->NewInstance();
    sf_v8::sf_Image::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Image *&CPP)
{
    CPP = sf_v8::sf_Image::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Sprite &JS)
{
    ::sf::Sprite *Ptr = new ::sf::Sprite(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Sprite::POT->NewInstance();
    sf_v8::sf_Sprite::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Sprite &JS)
{
    ::sf::Sprite *Ptr = (::sf::Sprite *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Sprite::POT->NewInstance();
    sf_v8::sf_Sprite::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sprite &CPP)
{
    ::sf::Sprite *Ptr = sf_v8::sf_Sprite::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Sprite *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Sprite::POT->NewInstance();
    sf_v8::sf_Sprite::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sprite *&CPP)
{
    CPP = sf_v8::sf_Sprite::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::ConvexShape &JS)
{
    ::sf::ConvexShape *Ptr = new ::sf::ConvexShape(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_ConvexShape::POT->NewInstance();
    sf_v8::sf_ConvexShape::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::ConvexShape &JS)
{
    ::sf::ConvexShape *Ptr = (::sf::ConvexShape *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_ConvexShape::POT->NewInstance();
    sf_v8::sf_ConvexShape::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ConvexShape &CPP)
{
    ::sf::ConvexShape *Ptr = sf_v8::sf_ConvexShape::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::ConvexShape *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_ConvexShape::POT->NewInstance();
    sf_v8::sf_ConvexShape::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ConvexShape *&CPP)
{
    CPP = sf_v8::sf_ConvexShape::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Window &JS)
{
    ::sf::Window *Ptr = (::sf::Window *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Window::POT->NewInstance();
    sf_v8::sf_Window::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::Window *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Window::POT->NewInstance();
    sf_v8::sf_Window::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Window *&CPP)
{
    CPP = sf_v8::sf_Window::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Time &JS)
{
    ::sf::Time *Ptr = new ::sf::Time(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Time::POT->NewInstance();
    sf_v8::sf_Time::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Time &JS)
{
    ::sf::Time *Ptr = (::sf::Time *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Time::POT->NewInstance();
    sf_v8::sf_Time::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Time &CPP)
{
    ::sf::Time *Ptr = sf_v8::sf_Time::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Time *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Time::POT->NewInstance();
    sf_v8::sf_Time::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Time *&CPP)
{
    CPP = sf_v8::sf_Time::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Glyph &JS)
{
    ::sf::Glyph *Ptr = new ::sf::Glyph(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Glyph::POT->NewInstance();
    sf_v8::sf_Glyph::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Glyph &JS)
{
    ::sf::Glyph *Ptr = (::sf::Glyph *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Glyph::POT->NewInstance();
    sf_v8::sf_Glyph::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Glyph &CPP)
{
    ::sf::Glyph *Ptr = sf_v8::sf_Glyph::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Glyph *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Glyph::POT->NewInstance();
    sf_v8::sf_Glyph::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Glyph *&CPP)
{
    CPP = sf_v8::sf_Glyph::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Transform &JS)
{
    ::sf::Transform *Ptr = new ::sf::Transform(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Transform::POT->NewInstance();
    sf_v8::sf_Transform::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Transform &JS)
{
    ::sf::Transform *Ptr = (::sf::Transform *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Transform::POT->NewInstance();
    sf_v8::sf_Transform::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transform &CPP)
{
    ::sf::Transform *Ptr = sf_v8::sf_Transform::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Transform *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Transform::POT->NewInstance();
    sf_v8::sf_Transform::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transform *&CPP)
{
    CPP = sf_v8::sf_Transform::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Joystick &JS)
{
    ::sf::Joystick *Ptr = new ::sf::Joystick(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Joystick::POT->NewInstance();
    sf_v8::sf_Joystick::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Joystick &JS)
{
    ::sf::Joystick *Ptr = (::sf::Joystick *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Joystick::POT->NewInstance();
    sf_v8::sf_Joystick::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick &CPP)
{
    ::sf::Joystick *Ptr = sf_v8::sf_Joystick::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Joystick *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Joystick::POT->NewInstance();
    sf_v8::sf_Joystick::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick *&CPP)
{
    CPP = sf_v8::sf_Joystick::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Joystick::Axis JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick::Axis &CPP)
{
    CPP = static_cast< ::sf::Joystick::Axis >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderTarget &JS)
{
    ::sf::RenderTarget *Ptr = (::sf::RenderTarget *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderTarget::POT->NewInstance();
    sf_v8::sf_RenderTarget::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::RenderTarget *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_RenderTarget::POT->NewInstance();
    sf_v8::sf_RenderTarget::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderTarget *&CPP)
{
    CPP = sf_v8::sf_RenderTarget::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Listener &JS)
{
    ::sf::Listener *Ptr = new ::sf::Listener(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Listener::POT->NewInstance();
    sf_v8::sf_Listener::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Listener &JS)
{
    ::sf::Listener *Ptr = (::sf::Listener *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Listener::POT->NewInstance();
    sf_v8::sf_Listener::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Listener &CPP)
{
    ::sf::Listener *Ptr = sf_v8::sf_Listener::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Listener *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Listener::POT->NewInstance();
    sf_v8::sf_Listener::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Listener *&CPP)
{
    CPP = sf_v8::sf_Listener::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundSource &JS)
{
    ::sf::SoundSource *Ptr = new ::sf::SoundSource(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundSource::POT->NewInstance();
    sf_v8::sf_SoundSource::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundSource &JS)
{
    ::sf::SoundSource *Ptr = (::sf::SoundSource *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundSource::POT->NewInstance();
    sf_v8::sf_SoundSource::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource &CPP)
{
    ::sf::SoundSource *Ptr = sf_v8::sf_SoundSource::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::SoundSource *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_SoundSource::POT->NewInstance();
    sf_v8::sf_SoundSource::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource *&CPP)
{
    CPP = sf_v8::sf_SoundSource::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::SoundSource::Status JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource::Status &CPP)
{
    CPP = static_cast< ::sf::SoundSource::Status >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::SizeEvent &JS)
{
    ::sf::Event::SizeEvent *Ptr = new ::sf::Event::SizeEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_SizeEvent::POT->NewInstance();
    sf_v8::sf_Event_SizeEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::SizeEvent &JS)
{
    ::sf::Event::SizeEvent *Ptr = (::sf::Event::SizeEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_SizeEvent::POT->NewInstance();
    sf_v8::sf_Event_SizeEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::SizeEvent &CPP)
{
    ::sf::Event::SizeEvent *Ptr = sf_v8::sf_Event_SizeEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::SizeEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_SizeEvent::POT->NewInstance();
    sf_v8::sf_Event_SizeEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::SizeEvent *&CPP)
{
    CPP = sf_v8::sf_Event_SizeEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::KeyEvent &JS)
{
    ::sf::Event::KeyEvent *Ptr = new ::sf::Event::KeyEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_KeyEvent::POT->NewInstance();
    sf_v8::sf_Event_KeyEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::KeyEvent &JS)
{
    ::sf::Event::KeyEvent *Ptr = (::sf::Event::KeyEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_KeyEvent::POT->NewInstance();
    sf_v8::sf_Event_KeyEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::KeyEvent &CPP)
{
    ::sf::Event::KeyEvent *Ptr = sf_v8::sf_Event_KeyEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::KeyEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_KeyEvent::POT->NewInstance();
    sf_v8::sf_Event_KeyEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::KeyEvent *&CPP)
{
    CPP = sf_v8::sf_Event_KeyEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::TextEvent &JS)
{
    ::sf::Event::TextEvent *Ptr = new ::sf::Event::TextEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_TextEvent::POT->NewInstance();
    sf_v8::sf_Event_TextEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::TextEvent &JS)
{
    ::sf::Event::TextEvent *Ptr = (::sf::Event::TextEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_TextEvent::POT->NewInstance();
    sf_v8::sf_Event_TextEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::TextEvent &CPP)
{
    ::sf::Event::TextEvent *Ptr = sf_v8::sf_Event_TextEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::TextEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_TextEvent::POT->NewInstance();
    sf_v8::sf_Event_TextEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::TextEvent *&CPP)
{
    CPP = sf_v8::sf_Event_TextEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseMoveEvent &JS)
{
    ::sf::Event::MouseMoveEvent *Ptr = new ::sf::Event::MouseMoveEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseMoveEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseMoveEvent &JS)
{
    ::sf::Event::MouseMoveEvent *Ptr = (::sf::Event::MouseMoveEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseMoveEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseMoveEvent &CPP)
{
    ::sf::Event::MouseMoveEvent *Ptr = sf_v8::sf_Event_MouseMoveEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseMoveEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseMoveEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseMoveEvent *&CPP)
{
    CPP = sf_v8::sf_Event_MouseMoveEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseButtonEvent &JS)
{
    ::sf::Event::MouseButtonEvent *Ptr = new ::sf::Event::MouseButtonEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseButtonEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseButtonEvent &JS)
{
    ::sf::Event::MouseButtonEvent *Ptr = (::sf::Event::MouseButtonEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseButtonEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseButtonEvent &CPP)
{
    ::sf::Event::MouseButtonEvent *Ptr = sf_v8::sf_Event_MouseButtonEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseButtonEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseButtonEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseButtonEvent *&CPP)
{
    CPP = sf_v8::sf_Event_MouseButtonEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseWheelEvent &JS)
{
    ::sf::Event::MouseWheelEvent *Ptr = new ::sf::Event::MouseWheelEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseWheelEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseWheelEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseWheelEvent &JS)
{
    ::sf::Event::MouseWheelEvent *Ptr = (::sf::Event::MouseWheelEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseWheelEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseWheelEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseWheelEvent &CPP)
{
    ::sf::Event::MouseWheelEvent *Ptr = sf_v8::sf_Event_MouseWheelEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseWheelEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_MouseWheelEvent::POT->NewInstance();
    sf_v8::sf_Event_MouseWheelEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseWheelEvent *&CPP)
{
    CPP = sf_v8::sf_Event_MouseWheelEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickConnectEvent &JS)
{
    ::sf::Event::JoystickConnectEvent *Ptr = new ::sf::Event::JoystickConnectEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickConnectEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickConnectEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickConnectEvent &JS)
{
    ::sf::Event::JoystickConnectEvent *Ptr = (::sf::Event::JoystickConnectEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickConnectEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickConnectEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickConnectEvent &CPP)
{
    ::sf::Event::JoystickConnectEvent *Ptr = sf_v8::sf_Event_JoystickConnectEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickConnectEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickConnectEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickConnectEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickConnectEvent *&CPP)
{
    CPP = sf_v8::sf_Event_JoystickConnectEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickMoveEvent &JS)
{
    ::sf::Event::JoystickMoveEvent *Ptr = new ::sf::Event::JoystickMoveEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickMoveEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickMoveEvent &JS)
{
    ::sf::Event::JoystickMoveEvent *Ptr = (::sf::Event::JoystickMoveEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickMoveEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickMoveEvent &CPP)
{
    ::sf::Event::JoystickMoveEvent *Ptr = sf_v8::sf_Event_JoystickMoveEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickMoveEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickMoveEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickMoveEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickMoveEvent *&CPP)
{
    CPP = sf_v8::sf_Event_JoystickMoveEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickButtonEvent &JS)
{
    ::sf::Event::JoystickButtonEvent *Ptr = new ::sf::Event::JoystickButtonEvent(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickButtonEvent::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickButtonEvent &JS)
{
    ::sf::Event::JoystickButtonEvent *Ptr = (::sf::Event::JoystickButtonEvent *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickButtonEvent::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickButtonEvent &CPP)
{
    ::sf::Event::JoystickButtonEvent *Ptr = sf_v8::sf_Event_JoystickButtonEvent::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickButtonEvent *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event_JoystickButtonEvent::POT->NewInstance();
    sf_v8::sf_Event_JoystickButtonEvent::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickButtonEvent *&CPP)
{
    CPP = sf_v8::sf_Event_JoystickButtonEvent::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event &JS)
{
    ::sf::Event *Ptr = new ::sf::Event(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Event::POT->NewInstance();
    sf_v8::sf_Event::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event &JS)
{
    ::sf::Event *Ptr = (::sf::Event *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Event::POT->NewInstance();
    sf_v8::sf_Event::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event &CPP)
{
    ::sf::Event *Ptr = sf_v8::sf_Event::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Event *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Event::POT->NewInstance();
    sf_v8::sf_Event::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event *&CPP)
{
    CPP = sf_v8::sf_Event::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Event::EventType JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::EventType &CPP)
{
    CPP = static_cast< ::sf::Event::EventType >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::GlResource &JS)
{
    ::sf::GlResource *Ptr = new ::sf::GlResource(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_GlResource::POT->NewInstance();
    sf_v8::sf_GlResource::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::GlResource &JS)
{
    ::sf::GlResource *Ptr = (::sf::GlResource *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_GlResource::POT->NewInstance();
    sf_v8::sf_GlResource::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::GlResource &CPP)
{
    ::sf::GlResource *Ptr = sf_v8::sf_GlResource::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::GlResource *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_GlResource::POT->NewInstance();
    sf_v8::sf_GlResource::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::GlResource *&CPP)
{
    CPP = sf_v8::sf_GlResource::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::RectangleShape &JS)
{
    ::sf::RectangleShape *Ptr = new ::sf::RectangleShape(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_RectangleShape::POT->NewInstance();
    sf_v8::sf_RectangleShape::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::RectangleShape &JS)
{
    ::sf::RectangleShape *Ptr = (::sf::RectangleShape *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_RectangleShape::POT->NewInstance();
    sf_v8::sf_RectangleShape::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RectangleShape &CPP)
{
    ::sf::RectangleShape *Ptr = sf_v8::sf_RectangleShape::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::RectangleShape *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_RectangleShape::POT->NewInstance();
    sf_v8::sf_RectangleShape::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RectangleShape *&CPP)
{
    CPP = sf_v8::sf_RectangleShape::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf16 &JS)
{
    ::sf::Utf16 *Ptr = new ::sf::Utf16(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf16::POT->NewInstance();
    sf_v8::sf_Utf16::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf16 &JS)
{
    ::sf::Utf16 *Ptr = (::sf::Utf16 *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf16::POT->NewInstance();
    sf_v8::sf_Utf16::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf16 &CPP)
{
    ::sf::Utf16 *Ptr = sf_v8::sf_Utf16::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Utf16 *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf16::POT->NewInstance();
    sf_v8::sf_Utf16::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf16 *&CPP)
{
    CPP = sf_v8::sf_Utf16::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf32 &JS)
{
    ::sf::Utf32 *Ptr = new ::sf::Utf32(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf32::POT->NewInstance();
    sf_v8::sf_Utf32::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf32 &JS)
{
    ::sf::Utf32 *Ptr = (::sf::Utf32 *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf32::POT->NewInstance();
    sf_v8::sf_Utf32::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf32 &CPP)
{
    ::sf::Utf32 *Ptr = sf_v8::sf_Utf32::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Utf32 *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Utf32::POT->NewInstance();
    sf_v8::sf_Utf32::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf32 *&CPP)
{
    CPP = sf_v8::sf_Utf32::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Keyboard &JS)
{
    ::sf::Keyboard *Ptr = new ::sf::Keyboard(JS);
    v8::Handle<v8::Object> Result = sf_v8::sf_Keyboard::POT->NewInstance();
    sf_v8::sf_Keyboard::MakeReference(Result, Ptr);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS2(const ::sf::Keyboard &JS)
{
    ::sf::Keyboard *Ptr = (::sf::Keyboard *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Keyboard::POT->NewInstance();
    sf_v8::sf_Keyboard::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard &CPP)
{
    ::sf::Keyboard *Ptr = sf_v8::sf_Keyboard::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Keyboard *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Keyboard::POT->NewInstance();
    sf_v8::sf_Keyboard::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard *&CPP)
{
    CPP = sf_v8::sf_Keyboard::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Keyboard::Key JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard::Key &CPP)
{
    CPP = static_cast< ::sf::Keyboard::Key >(Value->IntegerValue());
}

}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::TcpListener &JS)
{
    ::sf::TcpListener *Ptr = (::sf::TcpListener *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_TcpListener::POT->NewInstance();
    sf_v8::sf_TcpListener::MakeReference(Result, Ptr, false);
    return Result;
}

inline v8::Handle<v8::Value> CastToJS(::sf::TcpListener *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_TcpListener::POT->NewInstance();
    sf_v8::sf_TcpListener::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::TcpListener *&CPP)
{
    CPP = sf_v8::sf_TcpListener::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Drawable &JS)
{
    ::sf::Drawable *Ptr = (::sf::Drawable *)&JS;
    v8::Handle<v8::Object> Result = sf_v8::sf_Drawable::POT->NewInstance();
    sf_v8::sf_Drawable::MakeReference(Result, Ptr, false);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Drawable &CPP)
{
    ::sf::Drawable *Ptr = sf_v8::sf_Drawable::SafeUnwrap(Value->ToObject());
    if ( Ptr )
    {
    CPP = *Ptr;
    }
}

inline v8::Handle<v8::Value> CastToJS(::sf::Drawable *JS)
{
    v8::Handle<v8::Object> Result = sf_v8::sf_Drawable::POT->NewInstance();
    sf_v8::sf_Drawable::MakeReference(Result, JS);
    return Result;
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Drawable *&CPP)
{
    CPP = sf_v8::sf_Drawable::SafeUnwrap(Value->ToObject());
}
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::PrimitiveType JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::PrimitiveType &CPP)
{
    CPP = static_cast< ::sf::PrimitiveType >(Value->IntegerValue());
}

}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::BlendMode JS)
{
    return v8::Number::New(static_cast<int>(JS));
}

inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::BlendMode &CPP)
{
    CPP = static_cast< ::sf::BlendMode >(Value->IntegerValue());
}

}
//----------------------------------------
