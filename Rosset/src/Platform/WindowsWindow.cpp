#include "Rosset/Config/RsConfig.h"

#include "Platform/WindowsWindow.h"

#include "Rosset/Events/ApplicationEvent.h"

namespace Rosset {
    bool WindowsWindow::m_GLFW_INITIALIZED = false;

    static void GLFW_ERROR_CALLBACK(int error, const char* description)
    {
        RS_ENGINE_ERROR("GLFW ERROR ({0}): {1}", error, description);
        RS_ASSERT(false, "GLFW ERROR ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProperties& properties)
    {
        return new WindowsWindow(properties);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& properties)
    {
        Init(properties);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProperties& properties)
    {
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;

        RS_ENGINE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

        if (!m_GLFW_INITIALIZED)
        {
            int nRes = glfwInit();
            RS_ENGINE_ASSERT(nRes, "Could not initialize GLFW!");

            glfwSetErrorCallback(GLFW_ERROR_CALLBACK);
            m_GLFW_INITIALIZED = true;
        }

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVsync(true);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowClosedEvent event;
                data.EventCallback(event);
            });
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVsync(bool Enabled)
    {
        if (Enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        m_Data.Vsync = Enabled;
    }
}