#pragma once

#include "Rosset/Core.h"

#include <string>
#include <functional>

#define EVENT_TYPE_FUNCTIONS(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CATEGORY_FUNCTIONS(category) virtual int GetCategoryFlags() const override { return category; }

namespace Rosset
{
    enum EventType
    {
        KeyPressed = 1,
        KeyReleased
    };

    enum EventCategory
    {
        Input       = BIT(0),
        Keyboard    = BIT(1)
    };

    class RS_API Event
    {
#if 0
        friend class EventDispatcher;
#endif
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    protected:
        bool m_bIsHandled = false;
    };
#if 0
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
                m_Event.m_bIsHandled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };
#endif

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
