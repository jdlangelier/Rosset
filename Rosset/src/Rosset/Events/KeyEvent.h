#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset
{
    class KeyEvent : public Event
    {
    public:
        int GetKeyCode() const { return m_KeyCode; }

        EVENT_CATEGORY_FUNCTIONS(CategoryKeyboard | CategoryInput)

    protected:
        KeyEvent(int nKeyCode)
            : m_KeyCode(nKeyCode) {}

        int m_KeyCode;
    };

    class KeyPressEvent : public KeyEvent
    {
    public:
        KeyPressEvent(int keyCode, int repeatCount)
            : KeyEvent(keyCode),
              m_RepeatCount(repeatCount) {}

        int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyPress)

    private:
        int m_RepeatCount;
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(int nKeyCode)
            : KeyEvent(nKeyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_TYPE_FUNCTIONS(KeyRelease)
    };

    class KeyCharacterEvent : public Event
    {
    public:
        KeyCharacterEvent(unsigned int character)
            : m_Character(character) {}

        unsigned int GetCharacter() { return m_Character; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyCharacterEvent: " << m_Character;
            return ss.str();
        }

        EVENT_CATEGORY_FUNCTIONS(CategoryKeyboard | CategoryInput)
        EVENT_TYPE_FUNCTIONS(KeyCharacter)

    private:
        unsigned int m_Character;
    };
}
