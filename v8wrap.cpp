/***
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

#include "v8wrap.h"
//---------------------------------------------------------------------------
namespace v8wrap 
{
//---------------------------------------------------------------------------
const char *sUseNew = "Object must be constructed using the new keyword.";
const char *sNotCreated = "Unable to construct object with the parameters given.";
const char *sInvalidArgs = "The arguments to passed to this function are not valid.";
const char *sAbstractClass = "Cannot create instance of abstract class.";
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, short *&p)
{
	if ( Value->IsExternal() )
	{
		p = static_cast<short *>(v8::External::Unwrap(Value));
	}
	else
	{
		p = NULL;
	}
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned int *&p)
{
	if ( Value->IsExternal() )
	{
		p = static_cast<unsigned int *>(v8::External::Unwrap(Value));
	}
	else
	{
		p = NULL;
	}
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, void *&p)
{
	if ( Value->IsExternal() )
	{
		p = static_cast<void *>(v8::External::Unwrap(Value));
	}
	else
	{
		p = NULL;
	}
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, long long int &p)
{
	p = static_cast<int64_t>(Value->NumberValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, short unsigned int &p )
{
	p = static_cast<short unsigned int>(Value->IntegerValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, wchar_t &p)
{
	p = static_cast<wchar_t>(Value->IntegerValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, char &p)
{
	p = static_cast<char>(Value->IntegerValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned char *&p)
{
	if ( Value->IsExternal() )
	{
		p = static_cast<unsigned char *>(v8::External::Unwrap(Value));
	}
	else
	{
		p = NULL;
	}
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned char &p)
{
	p = static_cast<unsigned char>(Value->IntegerValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, int &p)
{
	p = static_cast<int>(Value->NumberValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned int &p)
{
	p = static_cast<unsigned int>(Value->NumberValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, double &p)
{
	p = static_cast<double>(Value->NumberValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, float &p)
{
	p = static_cast<float>(Value->NumberValue());
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, bool &p)
{
	p = Value->IsTrue();
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, std::string &p)
{
	p = *v8::String::Utf8Value(Value);
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, std::wstring &p)
{
	v8::Handle<v8::String> Str = Value->ToString();
	p.resize(Str->Length());
	Str->Write((uint16_t*)p.data(), 0, -1, v8::String::NO_NULL_TERMINATION);
}
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, long unsigned int &p )
{
	p = static_cast<long unsigned int>(Value->NumberValue());
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(int p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(unsigned int p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(long unsigned int p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(long long int p)
{
	return v8::Number::New((double)p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(unsigned char p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(double p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(float p)
{
	return v8::Number::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(bool p)
{
	return v8::Boolean::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(char *p)
{
	if ( p == NULL )
		return v8::Null();
	else
		return v8::String::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(wchar_t *p)
{
	if ( p == NULL )
		return v8::Null();
	else
		return v8::String::New((uint16_t*)p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(int16_t *p)
{
	return v8::External::New((void *)p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const std::string &p)
{
	return v8::String::New(p.c_str());
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const std::wstring &p)
{
	return v8::String::New((uint16_t*)p.c_str());
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(void *p)
{
	return v8::External::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(unsigned int *p)
{
	return v8::External::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(unsigned char *p)
{
	return v8::External::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(float *p)
{
	return v8::External::New(p);
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const unsigned int *p)
{
	return v8::External::New(const_cast<unsigned int*>(p));
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const unsigned char *p)
{
	return v8::External::New(const_cast<unsigned char*>(p));
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const void *p)
{
	return v8::External::New(const_cast<void*>(p));
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(const float *p)
{
	return v8::External::New(const_cast<float*>(p));
}
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
