#pragma once

#include "Rosset/Config/RsConfig.h"

#define EVENT_TYPE_FUNCTIONS(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CATEGORY_FUNCTIONS(category) virtual int GetCategoryFlags() const override { return category; }

namespace Rosset
{
    enum EventType
    {
        WindowResize = 1,
        WindowClose,
        KeyPress,
        KeyRelease,
        KeyCharacter,
        MouseMove,
        MouseScroll,
        MouseButtonPress,
        MouseButtonRelease
    };

    enum EventCategory
    {
        CategoryApplication = BIT(0),
        CategoryInput       = BIT(1),
        CategoryKeyboard    = BIT(2),
        CategoryMouse       = BIT(3)
    };

    class Event
    {
        friend class EventDispatcher;

    public:
        bool IsHandled() { return m_IsHandled; }
        void SetHandled() { m_IsHandled = true; }

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    private:
        bool m_IsHandled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event)
            : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_IsHandled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
