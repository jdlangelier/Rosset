#include "Rosset/Config/RsConfig.h"

#include "Platform/WindowsWindow.h"

namespace Rosset {
    bool WindowsWindow::m_bGLFW_INITIALIZED = false;

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

        if (!m_bGLFW_INITIALIZED)
        {
            int nRes = glfwInit();
            RS_ENGINE_ASSERT(nRes, "Could not initialize GLFW!");

            m_bGLFW_INITIALIZED = true;
        }

        m_pWindow = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_pWindow);
        glfwSetWindowUserPointer(m_pWindow, &m_Data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_pWindow);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_pWindow);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        m_Data.VSync = enabled;
    }
}
