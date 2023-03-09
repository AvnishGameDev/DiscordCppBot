#pragma once

#include "../Command.h"

class ClearCommand : public Command
{
public:
    
    ClearCommand() : Command("clear", "clears messages")
    {
        params.push_back({"number", dpp::param_info(dpp::pt_integer, true, "number of messages to clear, default: 100")});
    }

    void OnExecute(const std::string& command, const dpp::parameter_list_t& parameters, dpp::command_source src) override
    {
        int64_t num;
        if (parameters.empty())
            num = 100;
        else
            num = std::get<int64_t>(parameters[0].second);

        if (num < 1 || num > 100)
        {
            dpp::message msg{"number must be between 0 and 100"};
            msg.set_flags(dpp::m_ephemeral);
            src.interaction_event->reply(dpp::ir_channel_message_with_source, msg);
            return;
        }
        
        dpp::message replyMsg1{"Clearing Messages", dpp::mt_reply};
        replyMsg1.set_flags(dpp::m_ephemeral);
        src.interaction_event->reply(dpp::ir_deferred_channel_message_with_source, replyMsg1);
        
        const auto chnl = bot->channels_get_sync(src.guild_id).find(src.channel_id)->second;
        dpp::message_map msgsMap = bot->messages_get_sync(src.channel_id, 0, 0, 0, num);

        std::vector<dpp::snowflake> msgIDs;
        for (auto m : msgsMap)
        {
            msgIDs.emplace_back(m.first);
        }

        if (num > 1 && msgIDs.size() > 1)
            bot->message_delete_bulk_sync(msgIDs, src.channel_id);
        else
            bot->message_delete_sync(msgIDs[0], src.channel_id);

        dpp::message replyMsg2{"Cleared " + std::to_string(msgIDs.size()) + " message(s)", dpp::mt_reply};
        replyMsg2.set_flags(dpp::m_ephemeral);
        src.interaction_event->edit_response(replyMsg2);
    }
};