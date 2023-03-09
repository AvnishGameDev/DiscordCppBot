#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)
#include "dpp/dpp.h"
#pragma warning(pop)

class Command
{
public:
    Command(const std::string& inName, const std::string& inDesc, const dpp::parameter_registration_t& inParams, dpp::snowflake inGuildID = 0)
    {
        name = inName;
        description = inDesc;
        params = inParams;
        guildID = inGuildID;
    }

    Command(const std::string& inName, const std::string& inDesc, dpp::snowflake inGuildID = 0)
    {
        name = inName;
        description = inDesc;
        guildID = inGuildID;
    }

    virtual void OnExecute(const std::string& command, const dpp::parameter_list_t& parameters, dpp::command_source src)
    {
        
    }
    
    std::string name;
    std::string description;
    dpp::parameter_registration_t params;
    dpp::snowflake guildID = 0;

    dpp::cluster* bot;
};