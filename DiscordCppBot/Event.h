#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)
#include "dpp/dpp.h"
#pragma warning(pop)

class Event
{
public:
    
    Event(const std::string& inName) : name(inName)
    {
        
    }

    virtual void Bind(dpp::cluster* inBot)
    {
        bot = inBot;
    }
    
    std::string name;
    dpp::cluster* bot;
};