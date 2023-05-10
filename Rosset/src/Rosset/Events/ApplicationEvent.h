#pragma once

#include "Rosset/Events/Event.h"

namespace Rosset
{
    class WindowClosedEvent : public Event
    {
    public:
        WindowClosedEvent() {};

        EVENT_CATEGORY_FUNCTIONS(CategoryApplication)
        EVENT_TYPE_FUNCTIONS(WindowClosed)
    };
}
