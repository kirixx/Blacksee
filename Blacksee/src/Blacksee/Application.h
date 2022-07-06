#pragma once

#include "Core.h"

namespace Blacksee
{
    class BLACKSEE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();
        
        void Run();

    };

    // To be defined in a client
    CApplication* CreateApplication();
}