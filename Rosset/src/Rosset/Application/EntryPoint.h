#pragma once

#include "Rosset/Application/Application.h"
#include "Rosset/Utils/Log.h"

extern Rosset::Application* Rosset::CreateApplication();

#ifdef RS_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
    Rosset::Log::Init();

    auto pApp = Rosset::CreateApplication();
    pApp->Run();
    delete pApp;
}
#endif
