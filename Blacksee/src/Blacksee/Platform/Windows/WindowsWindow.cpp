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
        glfwSetWindowUserPointer(_Window, &_WindowData);
        SetVSync(true);
    }

    void WindowsWindow::InitWindowCallbacks()
    {
        glfwSetWindowSizeCallback(_Window, [](GLFWwindow* Window, int Width, int Height)
        {
            WindowData& Data = *static_cast<WindowData*>(glfwGetWindowUserPointer(Window));
            Data.Width = Width;
            Data.Height = Height;
        });
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
        _WindowData.Vsync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return _WindowData.Vsync;
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(_Window);
    }
}