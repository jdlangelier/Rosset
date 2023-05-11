#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset {
    class MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float posX, float posY)
            : m_PosX(posX), m_PosY(posY) {}

        float GetX() const { return m_PosX; }
        float GetY() const { return m_PosY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent: " << m_PosX << ", " << m_PosY;
            return ss.str();
        }

        EVENT_CATEGORY_FUNCTIONS(CategoryInput | CategoryMouse)
        EVENT_TYPE_FUNCTIONS(MouseMove)

    private:
        float m_PosX;
        float m_PosY;
    };

    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float offsetX, float offsetY)
            : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

        float GetXOffset() const { return m_OffsetX; }
        float GetYOffset() const { return m_OffsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: " << m_OffsetX << ", " << m_OffsetY;
            return ss.str();
        }

        EVENT_CATEGORY_FUNCTIONS(CategoryInput | CategoryMouse)
        EVENT_TYPE_FUNCTIONS(MouseScroll)

    private:
        float m_OffsetX;
        float m_OffsetY;
    };

    class MouseButtonEvent : public Event
    {
    public:
        int GetMouseButton() const { return m_Button; }

        EVENT_CATEGORY_FUNCTIONS(CategoryInput | CategoryMouse)

    protected:
        MouseButtonEvent(int button)
            : m_Button(button) {}

    protected:
        int m_Button;
    };

    class MouseButtonPressEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressEvent: " << m_Button;
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(MouseButtonPress)
    };

    class MouseButtonReleaseEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleaseEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleaseEvent: " << m_Button;
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(MouseButtonRelease)
    };
}
