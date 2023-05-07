#include "Application.h"

#include "Rosset/Events/KeyEvent.h"
#include "Rosset/Log.h"

namespace Rosset{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        KeyPressedEvent e(1, 1);
        RS_ENGINE_TRACE(e);

        while (true);
    }
}
