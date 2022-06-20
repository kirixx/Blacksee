#pragma once

#include "Core.h"

namespace Blacksee
{
    class BLACKSEE_API Application
    {
    public:
        Application();
        virtual ~Application();
        
        void run();

    };

    // To be defined in a client
    Application* createApplication();
}