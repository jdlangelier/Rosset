#pragma once

#include "Rosset/Config/RsConfig.h"

#include "Rosset/Events/Event.h"

namespace Rosset {
    class RS_API Window
    {
    public:
        struct WindowProperties
        {
            std::string strTitle;
            unsigned int uWidth;
            unsigned int uHeight;

            WindowProperties(const std::string& title = "Rosset",
                unsigned int width = 1280,
                unsigned int height = 720)
                : strTitle(title), uWidth(width), uHeight(height) {}
        };

        using EventCallbackFn = std::is_function<void(Event&)>;

        static Window* Create(const WindowProperties& properties = WindowProperties());

        virtual ~Window() {};

        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual void SetVsync(bool bEnabled) = 0;
        virtual bool IsVsync() const = 0;
    };
}
