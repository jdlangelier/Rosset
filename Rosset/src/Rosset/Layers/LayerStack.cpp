#include "Rosset/Config/RsConfig.h"

#include "Rosset/Layers/LayerStack.h"

namespace Rosset {
    LayerStack::LayerStack() :
        m_LayerInsertIndex(0)
    {
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
        {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        layer->OnAttach();
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
        overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto index = std::find(m_Layers.begin(), m_Layers.end(), layer);

        if (index != m_Layers.end())
        {
            m_Layers.erase(index);
            layer->OnDetatch();
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto index = std::find(m_Layers.begin(), m_Layers.end(), overlay);

        if (index != m_Layers.end())
        {
            overlay->OnDetatch();
            m_Layers.erase(index);
        }
    }
}
