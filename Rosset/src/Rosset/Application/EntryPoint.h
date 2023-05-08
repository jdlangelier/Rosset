#pragma once

#include "Rosset/Application/Application.h"
#include "Rosset/Utils/Log.h"

extern Rosset::Application* Rosset::CreateApplication();

#ifdef RS_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
    Rosset::Log::Init();
    RS_ENGINE_WARN("Logger!");
    RS_APP_INFO("Client!");

    auto pApp = Rosset::CreateApplication();
    pApp->Run();
    delete pApp;
}
#endif
