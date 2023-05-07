#pragma once

#include "Rosset/Config/RsConfig.h"

namespace Rosset {

    class RS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}
