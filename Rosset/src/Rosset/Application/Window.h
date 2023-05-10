#pragma once

#include "Rosset/Config/RsConfig.h"

#include "Rosset/Events/Event.h"

namespace Rosset {
    class RS_API Window
    {
    public:
        struct WindowProperties
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;

            WindowProperties(const std::string& title = "Rosset",
                unsigned int width = 1280,
                unsigned int height = 720)
                : Title(title), Width(width), Height(height) {}
        };

        using EventCallbackFn = std::function<void(Event&)>;

        static Window* Create(const WindowProperties& properties = WindowProperties());

        virtual ~Window() {};

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual void SetVsync(bool Enabled) = 0;
        virtual bool IsVsync() const = 0;
    };
}
