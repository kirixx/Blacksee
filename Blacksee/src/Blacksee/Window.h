#pragma once

#include "Blacksee/Core.h"
#include <string>

namespace Blacksee
{
    struct WindowProperties
    {
        std::string Title;
        uint32_t    Width;
        uint32_t    Height;

        WindowProperties(std::string_view Title = "Blacksee Engine", 
                         uint32_t Width = 1280, uint32_t Height = 720)
            :Title(Title)
            ,Width(Width)
            ,Height(Height)
        {

        }
    };

    class Window
    {
    public:
        virtual void InitWindowCallbacks() = 0;
        virtual ~Window() {};
        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeidth() const = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
        

        static Window* Create(const WindowProperties& winprops = WindowProperties());
    };
}