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
        m_stData.strTitle = properties.strTitle;
        m_stData.uWidth = properties.uWidth;
        m_stData.uHeight = properties.uHeight;

        RS_ENGINE_INFO("Creating window {0} ({1}, {2})", m_stData.strTitle, m_stData.uWidth, m_stData.uHeight);

        if (!m_bGLFW_INITIALIZED)
        {
            int nRes = glfwInit();
            RS_ENGINE_ASSERT(nRes, "Could not initialize GLFW!");

            m_bGLFW_INITIALIZED = true;
        }

        m_pWindow = glfwCreateWindow((int)m_stData.uWidth, (int)m_stData.uHeight, m_stData.strTitle.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_pWindow);
        glfwSetWindowUserPointer(m_pWindow, &m_stData);
        SetVsync(true);
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

    void WindowsWindow::SetVsync(bool bEnabled)
    {
        if (bEnabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        m_stData.bVsync = bEnabled;
    }
}
