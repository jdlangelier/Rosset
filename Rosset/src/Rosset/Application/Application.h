#pragma once

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

        static Application& Get() { return *s_Instance; }

        void Run();
        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        Window& GetWindow() { return *m_Window; };

    private:
        bool OnWindowClose(WindowCloseEvent event);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };

    Application* CreateApplication();
}
