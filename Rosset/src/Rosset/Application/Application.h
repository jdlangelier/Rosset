#pragma once

#include "Rosset/Config/RsConfig.h"

#include "Rosset/Application/Window.h"
#include "Rosset/Events/Event.h"
#include "Rosset/Events/ApplicationEvent.h"
#include "Rosset/Layers/LayerStack.h"

namespace Rosset {

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

    private:
        bool OnWindowClose(WindowCloseEvent event);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;
        LayerStack m_LayerStack;
    };

    Application* CreateApplication();
}
