#pragma once

#include "Core.h"

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
