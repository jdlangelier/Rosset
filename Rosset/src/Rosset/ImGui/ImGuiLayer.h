#pragma once

#include "Rosset/Layers/Layer.h"

namespace Rosset {
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
        float m_Time = 0.0f;
    };
}
