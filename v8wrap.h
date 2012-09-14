/***
The zlib/libpng License
Copyright (c) 2012 Steven Christy and other contributors

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

#ifndef __v8wrap__H__
#define __v8wrap__H__
//---------------------------------------------------------------------------
#ifdef _WIN32
#  include <windows.h>
#endif
#include <cstdlib>
#include <cstring>
#include <string>
#include <v8.h>
#include <vector>
//---------------------------------------------------------------------------
namespace v8wrap
{
//---------------------------------------------------------------------------
#define PT_UNKNOWN      0
#define PT_NUMBER       1
#define PT_BOOLEAN      2
#define PT_CLASS        4
#define PT_POINTER      8
#define PT_OBJECT      16
#define PT_STRING      32
#define PT_ARRAY       64
#define PT_FUNCTION   128
#define PT_DATE       256
//---------------------------------------------------------------------------
#define MAX_JSBINDING_PARAMS  32
//---------------------------------------------------------------------------
struct ParamEntry
{
	unsigned Type;
	const char  *Name;
};
//---------------------------------------------------------------------------
struct FunctionEntry
{
	int Index;
	unsigned ArgCnt;
	ParamEntry Params[MAX_JSBINDING_PARAMS];
};
//---------------------------------------------------------------------------
// Template class for matching JavaScript parameters to C++ method calls.
//---------------------------------------------------------------------------
template <int T> class Match
{
public:
	v8::Handle<v8::Value> Params[T];
	int Entry;

	Match(const FunctionEntry *Funcs, int FuncCnt, const v8::Arguments &args)
	{
		unsigned Param[T];
		unsigned Cnt = args.Length();

		Entry = -1;

		if ( Cnt > T )
		{
			return;
		}

		for ( unsigned P = 0; P < Cnt; P++ )
		{
			unsigned &curp = Param[P];
			curp = 0;
			if ( args[P]->IsBoolean() ) curp = PT_BOOLEAN;
			else if ( args[P]->IsNumber() ) curp = PT_NUMBER;
			else if ( args[P]->IsString() ) curp = PT_STRING;
			else if ( args[P]->IsObject() )
			{
				if ( args[P]->ToObject()->InternalFieldCount() > 0 )
				{
					curp = PT_CLASS;
				}
				else
				{
					curp = PT_OBJECT;
				}
			}
			else if ( args[P]->IsFunction() ) curp = PT_FUNCTION;
			else if ( args[P]->IsExternal() ) curp = PT_POINTER;
			else if ( args[P]->IsArray() ) curp = PT_ARRAY;
			else if ( args[P]->IsDate() ) curp = PT_DATE;
		}

		if ( Cnt == 1 && (Param[0] & PT_OBJECT) ) 
		{
			// Match an object containing our parameters by name.
			v8::Handle<v8::Object> Obj = args[0]->ToObject();
			for ( unsigned x = 0; x < (unsigned)FuncCnt; x++ )
			{
				ParamEntry *PE = (ParamEntry *)&Funcs[x].Params[0];

				if ( Funcs[x].ArgCnt == 0 ) continue; // An object (even if empty) cannot match an empty paramter list.

				bool Match = true;
				for ( unsigned y = 0; y < Funcs[x].ArgCnt; y++ )
				{
					unsigned &curp = Param[y];
					v8::Handle<v8::String> s = v8::String::New(PE->Name);

					if ( !Obj->Has(s) ) 
					{
						Match = false;
						break;
					}

					v8::Local<v8::Value> arg = Obj->Get(s);
										
					curp = 0;
					if ( arg->IsBoolean() ) curp = PT_BOOLEAN;
					else if ( arg->IsNumber() ) curp = PT_NUMBER;
					else if ( arg->IsString() ) curp = PT_STRING;
					else if ( arg->IsObject() ) 
					{
						if ( arg->ToObject()->InternalFieldCount() > 0 )
						{
							curp = PT_CLASS;
						}
						else
						{
							curp = PT_OBJECT;
						}
					}
					else if ( arg->IsFunction() ) curp = PT_FUNCTION;
					else if ( arg->IsExternal() ) curp = PT_POINTER;
					else if ( arg->IsArray() ) curp = PT_ARRAY;
					else if ( arg->IsDate() ) curp = PT_DATE;

					if ( !(PE->Type & curp) )
					{
						Match = false;
						break;
					}

					Params[y] = arg;
					PE++;
				}

				if ( Match ) 
				{
					Entry = Funcs[x].Index;
					return;
				}
			}			
			return;
		}

		for ( unsigned x = 0; x < (unsigned)FuncCnt; x++ )
		{
			// Traditional match based on parameter order and type.
			if ( Funcs[x].ArgCnt != Cnt ) continue;
		
			ParamEntry *PE = (ParamEntry *)&Funcs[x].Params[0];
			bool Match = true;
			for ( unsigned y = 0; y < Cnt; y++ )
			{
				if ( !(PE->Type & Param[y]) )
				{
					Match = false;
					break;
				}
				PE++;
			}
			if ( Match ) 
			{
				Entry = Funcs[x].Index;
				for ( unsigned y = 0; y < Cnt; y++ )
				{
					Params[y] = args[y];
				}
				return;
			}
		}

	}
};
//---------------------------------------------------------------------------
template <class DerivedT, typename T> class V8ClassTemplate
{
private:

public:
	static v8::Persistent<v8::FunctionTemplate> PFT;
	static v8::Persistent<v8::ObjectTemplate> POT;
	typedef T MyClass;

	static void Dispose(v8::Persistent<v8::Value> object, void* parameter) 
	{
		T *obj = (T*)v8::External::Unwrap(object->ToObject()->GetInternalField(0));
		
		if ( obj && object->ToObject()->GetInternalField(1)->IsTrue() ) DerivedT::Delete(obj);

		object.Dispose();
	}

	static inline void MakeReference( v8::Handle<v8::Object> Value, T *inst, bool MakeWeak = true )
	{
		Value->SetInternalField(0, v8::External::New(inst));
		Value->SetInternalField(1, v8::Boolean::New(MakeWeak));
		Value->SetInternalField(2, v8::External::New((void *)DerivedT::Bases));

		if ( MakeWeak ) v8::Persistent<v8::Object>::New(Value).MakeWeak(NULL, Dispose);
	}

	static inline T *SafeUnwrap(v8::Handle<v8::Object> object)
	{
		T *Result = NULL;
		int clen = strlen(DerivedT::ClassName);
		const char *Bases = ((const char *)v8::External::Unwrap(object->GetInternalField(2)));	
		int l = 0;
		bool safe = false;
		
		while ( (l=strlen(Bases)) != 0 ) {
			if ( l == clen && strcmp(Bases, DerivedT::ClassName) == 0 ) {
				safe = true;
				break;
			}
			Bases += (l+1);
		}
		
		if ( safe ) Result = ((T*)v8::External::Unwrap(object->GetInternalField(0)));	
		return Result;
	}
};
//---------------------------------------------------------------------------
template <class DerivedT, typename T> v8::Persistent<v8::FunctionTemplate> V8ClassTemplate<DerivedT, T>::PFT;
template <class DerivedT, typename T> v8::Persistent<v8::ObjectTemplate> V8ClassTemplate<DerivedT, T>::POT;
//---------------------------------------------------------------------------
template <class T> class V8NamespaceTemplate
{
private:

public:
	static v8::Persistent<v8::ObjectTemplate> POT;

};
//---------------------------------------------------------------------------
template <class T> v8::Persistent<v8::ObjectTemplate> V8NamespaceTemplate<T>::POT;
//---------------------------------------------------------------------------
#ifdef SFML_SYSTEM_WINDOWS
template <class T> void AutoCastToCPP(v8::Handle<T> Value, ::sf::WindowHandle &p1) {
	p1 = (::sf::WindowHandle) v8::External::Unwrap(Value);
}
#endif
//---------------------------------------------------------------------------
void AutoCastToCPP(v8::Handle<v8::Value> Value, short *&p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned int *&p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, void *&p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, long long int &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned char &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, short unsigned int &p );
void AutoCastToCPP(v8::Handle<v8::Value> Value, char &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, wchar_t &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned char *&p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, unsigned int &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, int &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, double &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, float &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, bool &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, std::string &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, std::wstring &p);
void AutoCastToCPP(v8::Handle<v8::Value> Value, long unsigned int &p );
//---------------------------------------------------------------------------
template <typename T> T CastToCPP(v8::Handle<v8::Value> Value)
{
	T Result;
	AutoCastToCPP(Value, Result);
	return Result;
}
//---------------------------------------------------------------------------
v8::Handle<v8::Value> CastToJS(long unsigned int p);
v8::Handle<v8::Value> CastToJS(int p);
v8::Handle<v8::Value> CastToJS(unsigned int p);
v8::Handle<v8::Value> CastToJS(long long int p);
v8::Handle<v8::Value> CastToJS(unsigned char p);
v8::Handle<v8::Value> CastToJS(double p);
v8::Handle<v8::Value> CastToJS(float p);
v8::Handle<v8::Value> CastToJS(bool p);
v8::Handle<v8::Value> CastToJS(char *p);
v8::Handle<v8::Value> CastToJS(wchar_t *p);
v8::Handle<v8::Value> CastToJS(const std::string &p); 
v8::Handle<v8::Value> CastToJS(const std::wstring &p);
v8::Handle<v8::Value> CastToJS(void *p);
v8::Handle<v8::Value> CastToJS(long long int *p);
v8::Handle<v8::Value> CastToJS(short *p);
v8::Handle<v8::Value> CastToJS(unsigned int *p);
v8::Handle<v8::Value> CastToJS(unsigned char *p);
v8::Handle<v8::Value> CastToJS(float *p);
v8::Handle<v8::Value> CastToJS(const unsigned int *p);
v8::Handle<v8::Value> CastToJS(const unsigned char *p);
v8::Handle<v8::Value> CastToJS(const void *p);
v8::Handle<v8::Value> CastToJS(const float *p);
//---------------------------------------------------------------------------
template <typename T> v8::Handle<v8::Value> CastToJS( const std::vector<T> &vec )
{
	v8::Handle<v8::Array> Result = v8::Array::New(vec.size());
	for ( unsigned x = 0; x < vec.size(); x++ ) {
		v8::Handle<v8::Value> Ele = CastToJS( vec[x] );
		Result->Set(v8::Integer::New(x), Ele);
	}
	return Result;
}
//---------------------------------------------------------------------------
extern const char *sUseNew;
extern const char *sNotCreated;
extern const char *sInvalidArgs;
extern const char *sAbstractClass;
//---------------------------------------------------------------------------
}
#endif
//---------------------------------------------------------------------------
