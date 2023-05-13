#pragma once

#include "Rosset/Layers/Layer.h"

namespace Rosset {
    class WindowResizeEvent;
    class KeyPressEvent;
    class KeyReleaseEvent;
    class KeyTypeEvent;
    class MouseMoveEvent;
    class MouseButtonPressEvent;
    class MouseButtonReleaseEvent;
    class MouseScrollEvent;

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        virtual ~ImGuiLayer();

        void OnAttach() override;
        void OnDetatch() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

    private:
        bool OnWindowResize(WindowResizeEvent& event);
        bool OnKeyPress(KeyPressEvent& event);
        bool OnKeyRelease(KeyReleaseEvent& event);
        bool OnKeyType(KeyTypeEvent& event);
        bool OnMouseMove(MouseMoveEvent& event);
        bool OnMouseButtonPress(MouseButtonPressEvent& event);
        bool OnMouseButtonRelease(MouseButtonReleaseEvent& event);
        bool OnMouseScroll(MouseScrollEvent& event);

    private:
        float m_Time = 0.0f;
    };
}
