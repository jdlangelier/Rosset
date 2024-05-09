#pragma once

#include "Rosset/Application/Window.h"

struct GLFWwindow;

namespace Rosset {
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& properties);
        virtual ~WindowsWindow();

        virtual void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
        virtual unsigned int GetWidth() const override { return m_Data.Width; }
        virtual unsigned int GetHeight() const override { return m_Data.Height; }
        virtual bool IsVsync() const override { return m_Data.Vsync; }
        
        virtual void OnUpdate() override;
        virtual void SetVsync(bool bEnabled) override;

        virtual void* GetNativeWindow() const override { return m_Window; }

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
