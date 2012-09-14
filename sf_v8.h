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
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#ifndef NO_SFML_NETWORK
    #include <SFML/Network.hpp>
#endif
#include <SFML/System.hpp>
//----------------------------------------
#include <v8.h>
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Font &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Font &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Font &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Font *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Font *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SocketSelector &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SocketSelector &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SocketSelector &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::SocketSelector *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SocketSelector *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::View &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::View &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::View &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::View *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::View *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderWindow &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::RenderWindow *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderWindow *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::Response &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::Response &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::Response *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::Response::Status JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::Response::Status &CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::DirectoryResponse &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::DirectoryResponse &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::DirectoryResponse &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::DirectoryResponse *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::DirectoryResponse *&CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Ftp::ListingResponse &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp::ListingResponse &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::ListingResponse &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::ListingResponse *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::ListingResponse *&CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Ftp &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Ftp::TransferMode JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Ftp::TransferMode &CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderTexture &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::RenderTexture *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderTexture *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundStream::Chunk &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundStream::Chunk &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream::Chunk &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundStream::Chunk *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream::Chunk *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundStream &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundStream *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundStream *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Http::Request &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http::Request &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Request *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Request::Method JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Request::Method &CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Http::Response &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http::Response &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Response *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Http::Response::Status JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http::Response::Status &CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Http &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Http *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Http *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::CircleShape &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::CircleShape &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::CircleShape &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::CircleShape *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::CircleShape *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector3i &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector3i &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3i &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vector3i *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3i *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::VertexArray &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::VertexArray &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VertexArray &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::VertexArray *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VertexArray *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Packet &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Packet &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Packet &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Packet *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Packet *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Text &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Text &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Text *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Text::Style JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Text::Style &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vertex &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vertex &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vertex &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vertex *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vertex *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Shader::CurrentTextureType &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shader::CurrentTextureType &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::CurrentTextureType &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Shader::CurrentTextureType *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::CurrentTextureType *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shader &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Shader *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Shader::Type JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shader::Type &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::InputStream &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::InputStream &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::InputStream *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::InputStream *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::IntRect &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::IntRect &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IntRect &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::IntRect *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IntRect *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::String &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::String &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::String &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::String *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::String *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::RenderStates &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderStates &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderStates &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::RenderStates *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderStates *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::VideoMode &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::VideoMode &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VideoMode &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::VideoMode *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::VideoMode *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundBufferRecorder &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundBufferRecorder *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBufferRecorder *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Socket &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Socket *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Socket *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Socket::Status JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Socket::Status &CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Sound &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Sound &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sound &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Sound *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sound *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Music &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Music *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Music *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Shape &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shape &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Shape *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Shape *&CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::UdpSocket &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::UdpSocket *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::UdpSocket *&CPP);
}
//----------------------------------------
#endif
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::IpAddress &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::IpAddress &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IpAddress &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::IpAddress *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::IpAddress *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::FloatRect &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::FloatRect &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::FloatRect &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::FloatRect *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::FloatRect *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::NonCopyable &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::NonCopyable *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::NonCopyable *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf8 &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf8 &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf8 &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Utf8 *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf8 *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2f &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2f &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2f &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vector2f *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2f *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2i &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2i &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2i &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vector2i *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2i *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector2u &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector2u &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2u &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vector2u *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector2u *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Vector3f &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Vector3f &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3f &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Vector3f *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Vector3f *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Transformable &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Transformable &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transformable &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Transformable *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transformable *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Clock &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Clock &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Clock &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Clock *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Clock *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Mouse &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Mouse &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Mouse *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Mouse::Button JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Mouse::Button &CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::TcpSocket &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::TcpSocket *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::TcpSocket *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundRecorder &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundRecorder *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundRecorder *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Color &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Color &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Color &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Color *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Color *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Texture &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Texture &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Texture *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Texture::CoordinateType JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Texture::CoordinateType &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::ContextSettings &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::ContextSettings &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ContextSettings &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::ContextSettings *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ContextSettings *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Context &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Context *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Context *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundBuffer &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundBuffer &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBuffer &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundBuffer *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundBuffer *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Image &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Image &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Image &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Image *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Image *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Sprite &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Sprite &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sprite &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Sprite *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Sprite *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::ConvexShape &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::ConvexShape &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ConvexShape &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::ConvexShape *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::ConvexShape *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Window &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::Window *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Window *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Time &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Time &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Time &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Time *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Time *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Glyph &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Glyph &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Glyph &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Glyph *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Glyph *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Transform &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Transform &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transform &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Transform *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Transform *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Joystick &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Joystick &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Joystick *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Joystick::Axis JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Joystick::Axis &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RenderTarget &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::RenderTarget *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RenderTarget *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Listener &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Listener &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Listener &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Listener *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Listener *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::SoundSource &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::SoundSource &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::SoundSource *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::SoundSource::Status JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::SoundSource::Status &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::SizeEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::SizeEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::SizeEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::SizeEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::SizeEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::KeyEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::KeyEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::KeyEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::KeyEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::KeyEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::TextEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::TextEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::TextEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::TextEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::TextEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseMoveEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseMoveEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseMoveEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseMoveEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseMoveEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseButtonEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseButtonEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseButtonEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseButtonEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseButtonEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::MouseWheelEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::MouseWheelEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseWheelEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::MouseWheelEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::MouseWheelEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickConnectEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickConnectEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickConnectEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickConnectEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickConnectEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickMoveEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickMoveEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickMoveEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickMoveEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickMoveEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event::JoystickButtonEvent &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event::JoystickButtonEvent &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickButtonEvent &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event::JoystickButtonEvent *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::JoystickButtonEvent *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Event &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Event &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Event *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Event::EventType JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Event::EventType &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::GlResource &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::GlResource &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::GlResource &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::GlResource *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::GlResource *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::RectangleShape &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::RectangleShape &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RectangleShape &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::RectangleShape *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::RectangleShape *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf16 &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf16 &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf16 &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Utf16 *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf16 *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Utf32 &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Utf32 &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf32 &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Utf32 *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Utf32 *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(const ::sf::Keyboard &JS);
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Keyboard &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Keyboard *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::Keyboard::Key JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Keyboard::Key &CPP);
}
//----------------------------------------
#ifndef NO_SFML_NETWORK
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::TcpListener &JS);
inline v8::Handle<v8::Value> CastToJS(::sf::TcpListener *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::TcpListener *&CPP);
}
//----------------------------------------
#endif
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS2(const ::sf::Drawable &JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Drawable &CPP);
inline v8::Handle<v8::Value> CastToJS(::sf::Drawable *JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::Drawable *&CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::PrimitiveType JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::PrimitiveType &CPP);
}
//----------------------------------------
namespace v8wrap {
inline v8::Handle<v8::Value> CastToJS(::sf::BlendMode JS);
inline void AutoCastToCPP(v8::Handle<v8::Value> Value, ::sf::BlendMode &CPP);
}
//----------------------------------------
#include "v8wrap.h"
//----------------------------------------
namespace sf_v8 {
class sf_Font : public v8wrap::V8ClassTemplate< sf_Font, ::sf::Font > {
    static v8::Handle<v8::Value> Method_loadFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlyph(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getKerning(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLineSpacing(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDefaultFont(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_SocketSelector : public v8wrap::V8ClassTemplate< sf_SocketSelector, ::sf::SocketSelector > {
    static v8::Handle<v8::Value> Method_add(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_remove(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_wait(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isReady(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_View : public v8wrap::V8ClassTemplate< sf_View, ::sf::View > {
    static v8::Handle<v8::Value> Method_setCenter(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setViewport(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_reset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getCenter(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getViewport(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_zoom(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_RenderWindow : public v8wrap::V8ClassTemplate< sf_RenderWindow, ::sf::RenderWindow > {
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_capture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_create(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_close(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isOpen(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSettings(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pollEvent(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_waitEvent(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTitle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setIcon(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVisible(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVerticalSyncEnabled(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMouseCursorVisible(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setKeyRepeatEnabled(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFramerateLimit(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setJoystickThreshold(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setActive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_display(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSystemHandle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDefaultView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getViewport(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_convertCoords(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_draw(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pushGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_popGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_resetGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Ftp_Response : public v8wrap::V8ClassTemplate< sf_Ftp_Response, ::sf::Ftp::Response > {
    static v8::Handle<v8::Value> Method_isOk(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMessage(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Ftp_DirectoryResponse : public v8wrap::V8ClassTemplate< sf_Ftp_DirectoryResponse, ::sf::Ftp::DirectoryResponse > {
    static v8::Handle<v8::Value> Method_getDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isOk(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMessage(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Ftp_ListingResponse : public v8wrap::V8ClassTemplate< sf_Ftp_ListingResponse, ::sf::Ftp::ListingResponse > {
    static v8::Handle<v8::Value> Method_getFilenames(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isOk(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMessage(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Ftp : public v8wrap::V8ClassTemplate< sf_Ftp, ::sf::Ftp > {
    static v8::Handle<v8::Value> Method_connect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_disconnect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_login(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_keepAlive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getWorkingDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDirectoryListing(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_changeDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_parentDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_createDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_deleteDirectory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_renameFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_deleteFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_download(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_upload(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_RenderTexture : public v8wrap::V8ClassTemplate< sf_RenderTexture, ::sf::RenderTexture > {
    static v8::Handle<v8::Value> Method_create(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setSmooth(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isSmooth(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setActive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_display(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDefaultView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getViewport(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_convertCoords(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_draw(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pushGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_popGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_resetGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_SoundStream_Chunk : public v8wrap::V8ClassTemplate< sf_SoundStream_Chunk, ::sf::SoundStream::Chunk > {
    static v8::Handle<v8::Value> Getter_samples(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_samples(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_sampleCount(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_sampleCount(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_SoundStream : public v8wrap::V8ClassTemplate< sf_SoundStream, ::sf::SoundStream > {
    static v8::Handle<v8::Value> Method_play(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pause(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_stop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getChannelCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleRate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Http_Request : public v8wrap::V8ClassTemplate< sf_Http_Request, ::sf::Http::Request > {
    static v8::Handle<v8::Value> Method_setField(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMethod(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setUri(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setHttpVersion(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setBody(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Http_Response : public v8wrap::V8ClassTemplate< sf_Http_Response, ::sf::Http::Response > {
    static v8::Handle<v8::Value> Method_getField(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMajorHttpVersion(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMinorHttpVersion(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getBody(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Http : public v8wrap::V8ClassTemplate< sf_Http, ::sf::Http > {
    static v8::Handle<v8::Value> Method_setHost(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_sendRequest(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_CircleShape : public v8wrap::V8ClassTemplate< sf_CircleShape, ::sf::CircleShape > {
    static v8::Handle<v8::Value> Method_setRadius(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRadius(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vector3i : public v8wrap::V8ClassTemplate< sf_Vector3i, ::sf::Vector3i > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_z(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_z(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_VertexArray : public v8wrap::V8ClassTemplate< sf_VertexArray, ::sf::VertexArray > {
    static v8::Handle<v8::Value> Method_getVertexCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_resize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_append(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPrimitiveType(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPrimitiveType(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Packet : public v8wrap::V8ClassTemplate< sf_Packet, ::sf::Packet > {
    static v8::Handle<v8::Value> Method_append(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getData(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDataSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_endOfPacket(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_Text : public v8wrap::V8ClassTemplate< sf_Text, ::sf::Text > {
    static v8::Handle<v8::Value> Method_setString(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFont(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setCharacterSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setStyle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getString(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFont(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getCharacterSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStyle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_findCharacterPos(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vertex : public v8wrap::V8ClassTemplate< sf_Vertex, ::sf::Vertex > {
    static v8::Handle<v8::Value> Getter_position(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_position(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_color(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_color(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_texCoords(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_texCoords(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Shader_CurrentTextureType : public v8wrap::V8ClassTemplate< sf_Shader_CurrentTextureType, ::sf::Shader::CurrentTextureType > {
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Shader : public v8wrap::V8ClassTemplate< sf_Shader, ::sf::Shader > {
    static v8::Handle<v8::Value> Method_loadFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setParameter(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_bind(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_unbind(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isAvailable(const v8::Arguments &args);
    static v8::Handle<v8::Value> Getter_CurrentTexture(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_CurrentTexture(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_InputStream : public v8wrap::V8ClassTemplate< sf_InputStream, ::sf::InputStream > {
    static v8::Handle<v8::Value> Method_read(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_seek(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_tell(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_IntRect : public v8wrap::V8ClassTemplate< sf_IntRect, ::sf::IntRect > {
    static v8::Handle<v8::Value> Method_contains(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_intersects(const v8::Arguments &args);
    static v8::Handle<v8::Value> Getter_left(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_left(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_top(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_top(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_String : public v8wrap::V8ClassTemplate< sf_String, ::sf::String > {
    static v8::Handle<v8::Value> Method_toAnsiString(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_toWideString(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isEmpty(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_erase(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_insert(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_find(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getData(const v8::Arguments &args);
    static v8::Handle<v8::Value> Getter_InvalidPos(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_InvalidPos(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_RenderStates : public v8wrap::V8ClassTemplate< sf_RenderStates, ::sf::RenderStates > {
    static v8::Handle<v8::Value> Getter_blendMode(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_blendMode(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_transform(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_transform(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_texture(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_texture(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_shader(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_shader(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_VideoMode : public v8wrap::V8ClassTemplate< sf_VideoMode, ::sf::VideoMode > {
    static v8::Handle<v8::Value> Method_isValid(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDesktopMode(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFullscreenModes(const v8::Arguments &args);
    static v8::Handle<v8::Value> Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_bitsPerPixel(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_bitsPerPixel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_SoundBufferRecorder : public v8wrap::V8ClassTemplate< sf_SoundBufferRecorder, ::sf::SoundBufferRecorder > {
    static v8::Handle<v8::Value> Method_getBuffer(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_start(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_stop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleRate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isAvailable(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_Socket : public v8wrap::V8ClassTemplate< sf_Socket, ::sf::Socket > {
    static v8::Handle<v8::Value> Method_setBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_Sound : public v8wrap::V8ClassTemplate< sf_Sound, ::sf::Sound > {
    static v8::Handle<v8::Value> Method_play(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pause(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_stop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setBuffer(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getBuffer(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_resetBuffer(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Music : public v8wrap::V8ClassTemplate< sf_Music, ::sf::Music > {
    static v8::Handle<v8::Value> Method_openFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_openFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_openFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDuration(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_play(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pause(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_stop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getChannelCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleRate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getStatus(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPlayingOffset(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLoop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Shape : public v8wrap::V8ClassTemplate< sf_Shape, ::sf::Shape > {
    static v8::Handle<v8::Value> Method_setTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_UdpSocket : public v8wrap::V8ClassTemplate< sf_UdpSocket, ::sf::UdpSocket > {
    static v8::Handle<v8::Value> Method_getLocalPort(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_bind(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_unbind(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_send(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_receive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_IpAddress : public v8wrap::V8ClassTemplate< sf_IpAddress, ::sf::IpAddress > {
    static v8::Handle<v8::Value> Method_toString(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_toInteger(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalAddress(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPublicAddress(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_FloatRect : public v8wrap::V8ClassTemplate< sf_FloatRect, ::sf::FloatRect > {
    static v8::Handle<v8::Value> Method_contains(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_intersects(const v8::Arguments &args);
    static v8::Handle<v8::Value> Getter_left(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_left(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_top(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_top(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_NonCopyable : public v8wrap::V8ClassTemplate< sf_NonCopyable, ::sf::NonCopyable > {
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Utf8 : public v8wrap::V8ClassTemplate< sf_Utf8, ::sf::Utf8 > {
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vector2f : public v8wrap::V8ClassTemplate< sf_Vector2f, ::sf::Vector2f > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_subtract(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_divide(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vector2i : public v8wrap::V8ClassTemplate< sf_Vector2i, ::sf::Vector2i > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_subtract(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_divide(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vector2u : public v8wrap::V8ClassTemplate< sf_Vector2u, ::sf::Vector2u > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_subtract(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_divide(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Vector3f : public v8wrap::V8ClassTemplate< sf_Vector3f, ::sf::Vector3f > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_z(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_z(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Transformable : public v8wrap::V8ClassTemplate< sf_Transformable, ::sf::Transformable > {
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Clock : public v8wrap::V8ClassTemplate< sf_Clock, ::sf::Clock > {
    static v8::Handle<v8::Value> Method_getElapsedTime(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_restart(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Mouse : public v8wrap::V8ClassTemplate< sf_Mouse, ::sf::Mouse > {
    static v8::Handle<v8::Value> Method_isButtonPressed(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_TcpSocket : public v8wrap::V8ClassTemplate< sf_TcpSocket, ::sf::TcpSocket > {
    static v8::Handle<v8::Value> Method_getLocalPort(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRemoteAddress(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRemotePort(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_connect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_disconnect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_send(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_receive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_SoundRecorder : public v8wrap::V8ClassTemplate< sf_SoundRecorder, ::sf::SoundRecorder > {
    static v8::Handle<v8::Value> Method_start(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_stop(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleRate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isAvailable(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Color : public v8wrap::V8ClassTemplate< sf_Color, ::sf::Color > {
    static v8::Handle<v8::Value> Getter_r(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_r(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_g(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_g(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_b(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_b(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_a(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_a(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Texture : public v8wrap::V8ClassTemplate< sf_Texture, ::sf::Texture > {
    static v8::Handle<v8::Value> Method_create(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromImage(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_copyToImage(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_update(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_bind(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setSmooth(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isSmooth(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRepeated(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isRepeated(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMaximumSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_ContextSettings : public v8wrap::V8ClassTemplate< sf_ContextSettings, ::sf::ContextSettings > {
    static v8::Handle<v8::Value> Getter_depthBits(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_depthBits(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_stencilBits(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_stencilBits(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_antialiasingLevel(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_antialiasingLevel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_majorVersion(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_majorVersion(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_minorVersion(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_minorVersion(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Context : public v8wrap::V8ClassTemplate< sf_Context, ::sf::Context > {
    static v8::Handle<v8::Value> Method_setActive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_SoundBuffer : public v8wrap::V8ClassTemplate< sf_SoundBuffer, ::sf::SoundBuffer > {
    static v8::Handle<v8::Value> Method_loadFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromSamples(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_saveToFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSamples(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSampleRate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getChannelCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDuration(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Image : public v8wrap::V8ClassTemplate< sf_Image, ::sf::Image > {
    static v8::Handle<v8::Value> Method_create(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromMemory(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_loadFromStream(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_saveToFile(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_createMaskFromColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPixel(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPixel(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPixelsPtr(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_flipHorizontally(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_flipVertically(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Sprite : public v8wrap::V8ClassTemplate< sf_Sprite, ::sf::Sprite > {
    static v8::Handle<v8::Value> Method_setTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_ConvexShape : public v8wrap::V8ClassTemplate< sf_ConvexShape, ::sf::ConvexShape > {
    static v8::Handle<v8::Value> Method_setPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Window : public v8wrap::V8ClassTemplate< sf_Window, ::sf::Window > {
    static v8::Handle<v8::Value> Method_create(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_close(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isOpen(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSettings(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pollEvent(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_waitEvent(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTitle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setIcon(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVisible(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVerticalSyncEnabled(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMouseCursorVisible(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setKeyRepeatEnabled(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFramerateLimit(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setJoystickThreshold(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setActive(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_display(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSystemHandle(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Time : public v8wrap::V8ClassTemplate< sf_Time, ::sf::Time > {
    static v8::Handle<v8::Value> Method_asSeconds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_asMilliseconds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_asMicroseconds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_add(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_subtract(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_divide(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Glyph : public v8wrap::V8ClassTemplate< sf_Glyph, ::sf::Glyph > {
    static v8::Handle<v8::Value> Getter_advance(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_advance(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_bounds(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_bounds(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_textureRect(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_textureRect(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Transform : public v8wrap::V8ClassTemplate< sf_Transform, ::sf::Transform > {
    static v8::Handle<v8::Value> Method_getMatrix(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverse(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_transformPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_transformRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_combine(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_translate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
    static v8::Handle<v8::Value> Operator_multiply(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Joystick : public v8wrap::V8ClassTemplate< sf_Joystick, ::sf::Joystick > {
    static v8::Handle<v8::Value> Method_isConnected(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getButtonCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_hasAxis(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isButtonPressed(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getAxisPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_update(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_RenderTarget : public v8wrap::V8ClassTemplate< sf_RenderTarget, ::sf::RenderTarget > {
    static v8::Handle<v8::Value> Method_clear(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDefaultView(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getViewport(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_convertCoords(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_draw(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_pushGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_popGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_resetGLStates(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Listener : public v8wrap::V8ClassTemplate< sf_Listener, ::sf::Listener > {
    static v8::Handle<v8::Value> Method_setGlobalVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setDirection(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getDirection(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_SoundSource : public v8wrap::V8ClassTemplate< sf_SoundSource, ::sf::SoundSource > {
    static v8::Handle<v8::Value> Method_setPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPitch(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getVolume(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isRelativeToListener(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getMinDistance(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getAttenuation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_SizeEvent : public v8wrap::V8ClassTemplate< sf_Event_SizeEvent, ::sf::Event::SizeEvent > {
    static v8::Handle<v8::Value> Getter_width(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_width(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_height(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_height(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_KeyEvent : public v8wrap::V8ClassTemplate< sf_Event_KeyEvent, ::sf::Event::KeyEvent > {
    static v8::Handle<v8::Value> Getter_code(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_code(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_alt(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_alt(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_control(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_control(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_shift(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_shift(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_system(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_system(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_TextEvent : public v8wrap::V8ClassTemplate< sf_Event_TextEvent, ::sf::Event::TextEvent > {
    static v8::Handle<v8::Value> Getter_unicode(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_unicode(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_MouseMoveEvent : public v8wrap::V8ClassTemplate< sf_Event_MouseMoveEvent, ::sf::Event::MouseMoveEvent > {
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_MouseButtonEvent : public v8wrap::V8ClassTemplate< sf_Event_MouseButtonEvent, ::sf::Event::MouseButtonEvent > {
    static v8::Handle<v8::Value> Getter_button(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_button(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_MouseWheelEvent : public v8wrap::V8ClassTemplate< sf_Event_MouseWheelEvent, ::sf::Event::MouseWheelEvent > {
    static v8::Handle<v8::Value> Getter_delta(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_delta(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_x(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_x(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_JoystickConnectEvent : public v8wrap::V8ClassTemplate< sf_Event_JoystickConnectEvent, ::sf::Event::JoystickConnectEvent > {
    static v8::Handle<v8::Value> Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_JoystickMoveEvent : public v8wrap::V8ClassTemplate< sf_Event_JoystickMoveEvent, ::sf::Event::JoystickMoveEvent > {
    static v8::Handle<v8::Value> Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_axis(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_axis(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_position(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_position(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event_JoystickButtonEvent : public v8wrap::V8ClassTemplate< sf_Event_JoystickButtonEvent, ::sf::Event::JoystickButtonEvent > {
    static v8::Handle<v8::Value> Getter_joystickId(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickId(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_button(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_button(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Event : public v8wrap::V8ClassTemplate< sf_Event, ::sf::Event > {
    static v8::Handle<v8::Value> Getter_type(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_type(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_size(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_size(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_key(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_key(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_text(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_text(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_mouseMove(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_mouseMove(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_mouseButton(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_mouseButton(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_mouseWheel(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_mouseWheel(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_joystickMove(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickMove(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_joystickButton(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickButton(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Getter_joystickConnect(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static void Setter_joystickConnect(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_GlResource : public v8wrap::V8ClassTemplate< sf_GlResource, ::sf::GlResource > {
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_RectangleShape : public v8wrap::V8ClassTemplate< sf_RectangleShape, ::sf::RectangleShape > {
    static v8::Handle<v8::Value> Method_setSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getSize(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPointCount(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPoint(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTexture(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTextureRect(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getFillColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineColor(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOutlineThickness(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getLocalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getGlobalBounds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getPosition(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getRotation(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getScale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getOrigin(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_move(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_rotate(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_scale(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_getInverseTransform(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Utf16 : public v8wrap::V8ClassTemplate< sf_Utf16, ::sf::Utf16 > {
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Utf32 : public v8wrap::V8ClassTemplate< sf_Utf32, ::sf::Utf32 > {
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf_Keyboard : public v8wrap::V8ClassTemplate< sf_Keyboard, ::sf::Keyboard > {
    static v8::Handle<v8::Value> Method_isKeyPressed(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_copy(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
#ifndef NO_SFML_NETWORK
class sf_TcpListener : public v8wrap::V8ClassTemplate< sf_TcpListener, ::sf::TcpListener > {
    static v8::Handle<v8::Value> Method_getLocalPort(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_listen(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_close(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_accept(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_setBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_isBlocking(const v8::Arguments &args);
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
#endif
//----------------------------------------
class sf_Drawable : public v8wrap::V8ClassTemplate< sf_Drawable, ::sf::Drawable > {
    static v8::Handle<v8::Value> Object_delete(const v8::Arguments &args);
public:
    static const char *Bases;
    static const char *ClassName;
    static v8::Handle<v8::Value> Create(const v8::Arguments &args);
    static void Delete(MyClass *inst);
    static void InitPOT(v8::Handle<v8::ObjectTemplate> target);
    static void InitPFT(v8::Handle<v8::ObjectTemplate> target);
    static void Register(v8::Handle<v8::FunctionTemplate> target);
    static void Register(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
class sf: public v8wrap::V8NamespaceTemplate<sf> {
    static v8::Handle<v8::Value> Method_microseconds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_milliseconds(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_err(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_sleep(const v8::Arguments &args);
    static v8::Handle<v8::Value> Method_seconds(const v8::Arguments &args);
public:
    static v8::Handle<v8::Object> Init();
};
//----------------------------------------
class sf_Style: public v8wrap::V8NamespaceTemplate<sf_Style> {
public:
    static void Init(v8::Handle<v8::ObjectTemplate> target);
};
//----------------------------------------
}
//----------------------------------------
