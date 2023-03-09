#pragma once

#include "Event.h"

class EventManager
{
public:

    template <class T>
    void AddEvent()
    {
        events.push_back(new T());
    }

    void BindEvents(dpp::cluster* bot)
    {
        for (auto e : events)
        {
            e->Bind(bot);
        }
    }

private:

    std::vector<Event*> events;
};