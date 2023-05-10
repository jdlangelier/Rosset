#pragma once

#include "Rosset/Config/RsConfig.h"

#include "Rosset/Application/Window.h"
#include "Rosset/Events/Event.h"
#include "Rosset/Events/ApplicationEvent.h"

namespace Rosset {

    class RS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& event);

    private:
        bool OnWindowClose(WindowClosedEvent event);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;
    };

    Application* CreateApplication();
}
