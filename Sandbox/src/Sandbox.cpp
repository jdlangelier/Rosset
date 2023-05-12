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
        RS_APP_INFO("SampleLayer::OnUpdate");
    }

    void OnEvent(Rosset::Event& event) override
    {
        RS_APP_INFO("SampleLayer::OnEvent: {0}", event);
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
