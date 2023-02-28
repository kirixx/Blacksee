#pragma once

#include "Blacksee/Window.h"
#include "GLFW/glfw3.h"

namespace Blacksee
{
    class WindowsWindow : public Window
    {

    public:
        WindowsWindow(const WindowProperties& winprops);
        virtual ~WindowsWindow();

        void OnUpdate() override;
        ;
        inline uint32_t GetWidth() const override { return _Properties.Width; }
        inline uint32_t GetHeidth() const override { return _Properties.Height; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProperties& winprops);
        virtual void Shutdown();

        GLFWwindow* _Window;

        WindowProperties _Properties;
    };
}
