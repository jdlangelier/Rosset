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

    class KeyPressEvent : public KeyEvent
    {
    public:
        KeyPressEvent(int nKeyCode, int nRepeatCount)
            : KeyEvent(nKeyCode),
              m_nRepeatCount(nRepeatCount) {}

        inline int GetRepeatCount() const { return m_nRepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << m_nKeyCode << " (" << m_nRepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyPress)

    private:
        int m_nRepeatCount;
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(int nKeyCode)
            : KeyEvent(nKeyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent: " << m_nKeyCode;
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyRelease)
    };
}
