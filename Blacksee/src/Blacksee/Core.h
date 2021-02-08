#pragma once

#ifdef BS_PLATFORM_WINDOWS
    #ifdef BS_BUILD_DLL
        #define BLACK_SEE_API __declspec(dllexport)
    #else
        #define BLACK_SEE_API __declspec(dllimport)
    #endif
#else
    #error Blacksee only support Windows for now
#endif