#include "Rosset/Config/RsConfig.h"

#include "Rosset/Application/Application.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Rosset {

    Application::Application()
        : m_Running(true)
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& event)
    {
        RS_ENGINE_TRACE("{0}", event);

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowClosedEvent event)
    {
        m_Running = false;
        return true;
    }
}
