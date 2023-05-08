#include "Rosset/Config/RsConfig.h"

#include "Application.h"

namespace Rosset {

    Application::Application()
        : m_bRunning(true)
    {
        m_pWindow = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_bRunning)
        {
            m_pWindow->OnUpdate();
        }
    }
}
