#include "Rosset/Config/RsConfig.h"

// TODO: Temporarly setting the background color
#include <../ThirdParties/glad/include/glad/gl.h>

#include "Rosset/Application/Application.h"

namespace Rosset {
    Application* Application::s_Instance = nullptr;

    Application::Application()
        : m_Running(true)
    {
        RS_ENGINE_ASSERT(!s_Instance, "Application already exists!")
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(RS_BIND_EVENT_FUNCTION(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(RS_BIND_EVENT_FUNCTION(Application::OnWindowClose));

        for (auto index = m_LayerStack.end(); index != m_LayerStack.begin(); )
        {
            (*--index)->OnEvent(event);
            if (event.IsHandled())
            {
                break;
            }
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            // TODO: Temporarly setting the background color
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            m_ImGuiLayer->Begin();
            for (Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay)
    {
        m_LayerStack.PushOverlay(overlay);
    }

    bool Application::OnWindowClose(WindowCloseEvent event)
    {
        m_Running = false;
        return true;
    }
}
