#pragma once

#include "Rosset/Application/Window.h"

struct GLFWwindow;

namespace Rosset {
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& properties);
        virtual ~WindowsWindow();

        inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline bool IsVsync() const override { return m_Data.Vsync; }
        
        void OnUpdate() override;
        void SetVsync(bool bEnabled) override;

    private:
        void Init(const WindowProperties& properties);
        void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool Vsync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

        static bool m_GLFW_INITIALIZED;
    };
}
