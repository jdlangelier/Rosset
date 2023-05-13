#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset {
    class Layer {
    public:
        Layer(const std::string& name);
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetatch() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        const std::string& GetName() const { return m_Name; }
    private:
        std::string m_Name;
    };
}
