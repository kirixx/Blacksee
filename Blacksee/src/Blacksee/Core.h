#pragma once

#ifdef BS_PLATFORM_WINDOWS
    #define NOINLINE __declspec(noinline)
    #ifdef BS_BUILD_DLL
        #define BLACKSEE_API __declspec(dllexport)
    #else
        #define BLACKSEE_API __declspec(dllimport)
    #endif
#else
    #error Blacksee only support Windows for now
#endif