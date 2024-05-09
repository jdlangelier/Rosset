#pragma once

namespace Rosset {
    class Input
    {
    public:
        static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
                static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
        static bool GetMouseX() { return s_Instance->GetMouseXImpl(); }
        static bool GetMouseY() { return s_Instance->GetMouseYImpl(); }

    protected:
        virtual bool IsKeyPressedImpl(int keyCode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> GetMousePosition() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        static Input* s_Instance;
    };
}
