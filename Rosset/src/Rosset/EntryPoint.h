#pragma once

extern Rosset::Application* Rosset::CreateApplication();

#ifdef RS_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
    Rosset::Log::Init();
    RS_ENGINE_WARN("Logger!");
    RS_APP_INFO("Client!");

    auto app = Rosset::CreateApplication();
    app->Run();
    delete app;
}
#endif
