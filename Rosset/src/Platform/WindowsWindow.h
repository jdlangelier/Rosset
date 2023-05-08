#pragma once

#include "Rosset/Application/Window.h"

#include "GLFW/glfw3.h"

namespace Rosset {
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProperties& properties);
        virtual ~WindowsWindow();

        inline unsigned int GetWidth() const override { return m_stData.uWidth; }
        inline unsigned int GetHeight() const override { return m_stData.uHeight; }
        inline bool IsVsync() const override { return m_stData.bVsync; }
        
        void OnUpdate() override;
        void SetVsync(bool bEnabled) override;

    private:
        void Init(const WindowProperties& properties);
        void Shutdown();

    private:
        GLFWwindow* m_pWindow;

        struct WindowData
        {
            std::string strTitle;
            unsigned int uWidth;
            unsigned int uHeight;
            bool bVsync;
        };

        WindowData m_stData;

        static bool m_bGLFW_INITIALIZED;
    };
}
