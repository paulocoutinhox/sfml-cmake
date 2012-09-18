#include "JSCharacter.h"

const char *JSCharacter::Bases     = "JSCharacter\0\0";
const char *JSCharacter::ClassName = "JSCharacter";

v8::Handle<v8::Value> JSCharacter::Create(const v8::Arguments &args)
{
    if (args.IsConstructCall())
    {
        if (args.Length() == 0)
        {
            v8::Handle<v8::Object> JSinst = POT->NewInstance();
            JSinst->SetPrototype(args.This()->GetPrototype());
            MyClass *inst = new MyClass();
            MakeReference(JSinst, inst);
            return JSinst;
        }
        else
        {
            return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
        }
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sUseNew)));
    }
}

void JSCharacter::Delete(MyClass *inst)
{
    delete inst;
}

void JSCharacter::InitPOT(v8::Handle<v8::ObjectTemplate> target)
{
    if ( POT.IsEmpty() )
    {
        POT = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
        POT->SetInternalFieldCount(3);
        Register(POT);
    }
}

void JSCharacter::InitPFT(v8::Handle<v8::ObjectTemplate> target)
{
    if ( PFT.IsEmpty() )
    {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
    v8::Handle<v8::Function> FO = PFT->GetFunction();
    target->Set(v8::String::New("Time"), FO);
}

void JSCharacter::Register(v8::Handle<v8::ObjectTemplate> target)
{
    target->Set("className"   , v8::String::New(ClassName));
    target->Set("_delete"     , v8::FunctionTemplate::New(Object_delete));
    target->Set("walkForward" , v8::FunctionTemplate::New(Method_walkForward));
    target->Set("mssleep"     , v8::FunctionTemplate::New(Method_mssleep));
    target->Set("rotateLeft"  , v8::FunctionTemplate::New(Method_rotateLeft));
    target->Set("rotateRight" , v8::FunctionTemplate::New(Method_rotateRight));
    target->Set("say"         , v8::FunctionTemplate::New(Method_say));
}

void JSCharacter::Register(v8::Handle<v8::FunctionTemplate> target)
{
    if (PFT.IsEmpty())
    {
        PFT = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(Create));
        PFT->SetClassName(v8::String::New(ClassName));
        Register(PFT);
    }
}

v8::Handle<v8::Value> JSCharacter::Object_copy(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result;
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    MyClass *copy = new MyClass(*inst);
    result = v8wrap::CastToJS(copy);
    return scope.Close(result);
}

v8::Handle<v8::Value> JSCharacter::Object_delete(const v8::Arguments &args)
{
    v8::HandleScope scope;
    v8::Handle<v8::Value> result = v8::Undefined();
    MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
    bool IsWeak = args.Holder()->GetInternalField(1)->IsTrue();
    if ( IsWeak )
    {
        Delete(inst); args.Holder()->SetInternalField(1, v8::Boolean::New(false)); args.Holder()->SetInternalField(0, v8::External::Wrap(NULL));
    }
    return scope.Close(result);
}

v8::Handle<v8::Value> JSCharacter::Method_mssleep(const v8::Arguments &args)
{
    if ( args.Length() == 1 )
    {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));

        const v8wrap::FunctionEntry Func[] = {
        { 1, 1, {{ PT_NUMBER, "ms" }}}
        };
        int FuncSize = 1;
        v8wrap::Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            case 1: {
                int p0 = v8wrap::CastToCPP<int>(ParamMatch.Params[0]);
                inst->mssleep(p0);
                break;
            }
            default: {
                return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
                break;
            }
        }

        return v8::Undefined();
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
    }
}

v8::Handle<v8::Value> JSCharacter::Method_rotateLeft(const v8::Arguments &args)
{
    if ( args.Length() == 0 )
    {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->rotateLeft();
        return v8::Undefined();
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
    }
}

v8::Handle<v8::Value> JSCharacter::Method_rotateRight(const v8::Arguments &args)
{
    if ( args.Length() == 0 )
    {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->rotateRight();
        return v8::Undefined();
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
    }
}

v8::Handle<v8::Value> JSCharacter::Method_walkForward(const v8::Arguments &args)
{
    if ( args.Length() == 0 )
    {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));
        inst->walkForward();
        return v8::Undefined();
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
    }
}

v8::Handle<v8::Value> JSCharacter::Method_say(const v8::Arguments &args)
{
    if ( args.Length() == 1 )
    {
        MyClass *inst = ((MyClass*)v8::External::Unwrap(args.Holder()->GetInternalField(0)));

        const v8wrap::FunctionEntry Func[] = {
        { 1, 1, {{ PT_STRING, "msg" }}}
        };
        int FuncSize = 1;
        v8wrap::Match<1> ParamMatch(&Func[0], FuncSize, args);
        switch ( ParamMatch.Entry ) {
            case 1: {
                std::string p0 = v8wrap::CastToCPP<std::string>(ParamMatch.Params[0]);
                inst->say(p0);
                break;
            }
            default: {
                return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
                break;
            }
        }

        return v8::Undefined();
    }
    else
    {
        return v8::ThrowException(v8::Exception::Error(v8::String::New(v8wrap::sInvalidArgs)));
    }
}
