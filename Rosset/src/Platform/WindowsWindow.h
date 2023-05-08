#pragma once

#include "Rosset/Application/Window.h"

#include "GLFW/glfw3.h"

namespace Rosset {
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& properties);
        virtual ~WindowsWindow();

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline bool IsVSync() const override { return m_Data.VSync; }
        
        void OnUpdate() override;
        void SetVSync(bool enabled) override;

    private:
        void Init(const WindowProperties& properties);
        void Shutdown();

    private:
        GLFWwindow* m_pWindow;

        struct WindowData
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool VSync;
        };

        WindowData m_Data;

        static bool m_bGLFW_INITIALIZED;
    };
}
