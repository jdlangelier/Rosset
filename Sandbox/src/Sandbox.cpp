#include <Rosset.h>

class SampleLayer : public Rosset::Layer
{
public:
    SampleLayer()
        : Layer("SampleLayer")
    {
    }

    void OnUpdate() override
    {
        if (Rosset::Input::IsKeyPressed(RS_KEY_TAB))
        {
            RS_APP_TRACE("Tab key is pressed!");
        }
    }

    void OnEvent(Rosset::Event& event) override
    {
    }
};

class Sandbox : public Rosset::Application
{
public:
    Sandbox()
    {
        PushLayer(new SampleLayer());
        PushOverlay(new Rosset::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};

Rosset::Application* Rosset::CreateApplication()
{
    return new Sandbox();
}
