#pragma once

#include "Rosset/Config/RsConfig.h"

#include "Rosset/Application/Window.h"

namespace Rosset {

    class RS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_pWindow;
        bool m_bRunning;
    };

    Application* CreateApplication();
}
