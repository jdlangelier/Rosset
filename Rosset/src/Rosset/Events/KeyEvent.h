#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset
{
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_nKeyCode; }

        EVENT_CATEGORY_FUNCTIONS(CategoryKeyboard | CategoryInput)

    protected:
        KeyEvent(int nKeyCode)
            : m_nKeyCode(nKeyCode) {}

        int m_nKeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int nKeyCode, int nRepeatCount)
            : KeyEvent(nKeyCode),
              m_nRepeatCount(nRepeatCount) {}

        inline int GetRepeatCount() const { return m_nRepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_nKeyCode << " (" << m_nRepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyPressed)

    private:
        int m_nRepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int nKeyCode)
            : KeyEvent(nKeyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_nKeyCode;
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyReleased)
    };
}
