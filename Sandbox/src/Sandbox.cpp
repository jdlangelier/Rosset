#include <Rosset.h>

class Sandbox : public Rosset::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Rosset::Application* Rosset::CreateApplication()
{
	return new Sandbox();
}
