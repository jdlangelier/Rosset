#pragma once

extern Rosset::Application* Rosset::CreateApplication();

#ifdef RS_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	auto app = Rosset::CreateApplication();
	app->Run();
	delete app;
}
#endif
