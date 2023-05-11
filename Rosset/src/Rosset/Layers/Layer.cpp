#include "Rosset/Config/RsConfig.h"

#include "Rosset/Layers/Layer.h"

namespace Rosset {
    Layer::Layer(const std::string& name)
        : m_Name(name) {}

    Layer::~Layer() {}
}
