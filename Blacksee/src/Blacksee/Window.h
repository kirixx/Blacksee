#pragma once

#include "Blacksee/Core.h"
#include <string>

namespace Blacksee
{
    struct WindowProperties
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;
        bool VSync;

        WindowProperties(const std::string& title = "Blacksee Engine", 
                         uint32_t width = 1280, uint32_t height = 720, bool vsync = false)
        {

        }
    };

    class BLACKSEE_API Window
    {
    public:
        virtual ~Window() {};
        virtual void OnUpdate() = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeidth() const = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProperties& winprops = WindowProperties());
    };
}