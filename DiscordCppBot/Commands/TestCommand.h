#pragma once

#include "../Command.h"

class TestCommand : public Command
{
public:
    
    TestCommand() : Command("TestCommand", "Test Description1234")
    {
        params.push_back({"testparam", dpp::param_info(dpp::pt_string, false, "testdesc")});
    }

    void OnExecute(const std::string& command, const dpp::parameter_list_t& parameters, dpp::command_source src) override
    {
        src.interaction_event->reply(dpp::ir_channel_message_with_source, dpp::message("It Works! testparam: " + std::get<std::string>(parameters[0].second), dpp::mt_reply));
    }
};