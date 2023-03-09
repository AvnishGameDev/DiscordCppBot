#pragma once

#include "Command.h"

#pragma warning(push)
#pragma warning(disable: 4251)
#include "dpp/dpp.h"
#pragma warning(pop)

class CommandManager
{
public:
    CommandManager(dpp::cluster* bot)
    {
        handler = new dpp::commandhandler(bot);
        handler->add_prefix("!").add_prefix("/");
    }

    ~CommandManager()
    {
        for (auto c : commands)
        {
            delete c;
        }
        commands.clear();
    }

    template <class T>
    void AddCommand()
    {
        commands.emplace_back(new T());
    }
    
    void RegisterCommands()
    {
        for (auto c : commands)
        {
            c->bot = handler->owner;
            handler->add_command(
                c->name,
                c->params,
                [c](const std::string& command, const dpp::parameter_list_t& parameters, dpp::command_source src)
                {
                    c->OnExecute(command, parameters, src);
                },
                c->description,
                c->guildID
            );
        }
        
        handler->register_commands();
    }

private:

    std::vector<Command*> commands;
    dpp::commandhandler* handler{nullptr};
};