#pragma once

//#ifdef BS_PLATFORM_WINDOWS
//    #define NOINLINE __declspec(noinline)
//    #ifdef BS_BUILD_DLL
//        #define BLACKSEE_API __declspec(dllexport)
//    #else
//        #define BLACKSEE_API __declspec(dllimport)
//    #endif
//#else
//    #error Blacksee only support Windows for now
//#endif
#define NOINLINE __declspec(noinline)
#define BS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }