#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset
{
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CATEGORY_FUNCTIONS(CategoryApplication)
        EVENT_TYPE_FUNCTIONS(WindowResize)

    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {};

        EVENT_CATEGORY_FUNCTIONS(CategoryApplication)
        EVENT_TYPE_FUNCTIONS(WindowClose)
    };
}
