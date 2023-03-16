#pragma once

#include "Core.h"
#include <memory>
#include "Blacksee/Window.h"

namespace Blacksee
{
    class CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();
        
        void Run();

    private:
        std::unique_ptr<Window> _Window;
        bool _IsRunning = true;
    };

    // To be defined in a client
    CApplication* CreateApplication();
}