#pragma once

#include "Core.h"

namespace bs
{
    class BLACK_SEE_API Application
    {
    public:
        Application();
        virtual ~Application();
        
        void run();

    };

    // To be defined in a client
    Application* createApplication();
}