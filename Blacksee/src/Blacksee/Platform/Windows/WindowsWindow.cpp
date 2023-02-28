#include "WindowsWindow.h"
#include "Blacksee/Assertion.h"
namespace Blacksee
{
    static bool s_GLFWInitialised = false;
    Window* Window::Create(const WindowProperties& winprops)
    {
        return new WindowsWindow(winprops);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& winprops)
        : _Properties(winprops)
    {
        Init(winprops);
    }

    void WindowsWindow::Init(const WindowProperties& winprops)
    {
        BS_CORE_INFO("Creating Window {0} ({1}, {2})", winprops.Title, winprops.Width, winprops.Height);

        if (!s_GLFWInitialised)
        {
            int success = glfwInit();
            ASSERT(success, "Could not initialise GLFW!");

            s_GLFWInitialised = true;
        }

        _Window = glfwCreateWindow(winprops.Width, winprops.Height, winprops.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, &_Properties);
        SetVSync(true);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        glfwSwapInterval(enabled);
        _Properties.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return _Properties.VSync;
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(_Window);
    }

}