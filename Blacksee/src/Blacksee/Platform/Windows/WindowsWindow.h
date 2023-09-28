#pragma once

#include "Blacksee/Window.h"
#include "GLFW/glfw3.h"

namespace Blacksee
{
    class WindowsWindow final : public Window
    {

    public:
        WindowsWindow(const WindowProperties& winprops);
        virtual ~WindowsWindow();

        void OnUpdate() override;
        ;
        inline uint32_t GetWidth() const override { return _WindowData.Width; }
        inline uint32_t GetHeidth() const override { return _WindowData.Height; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        void Init(const WindowProperties& winprops);
        void Shutdown();

        virtual void InitWindowCallbacks() override;

        GLFWwindow* _Window;

        struct WindowData
        {
            std::string  Title;
            unsigned int Width;
            unsigned int Height;
            bool         Vsync;
        };

        WindowData _WindowData;

    };
}
