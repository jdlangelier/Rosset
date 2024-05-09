#pragma once

#include "Rosset/Application/Input.h"

namespace Rosset{
    class WindowsInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keyCode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePosition() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}