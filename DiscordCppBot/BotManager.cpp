#include "BotManager.h"

using namespace dpp;

BotManager::BotManager(dpp::cluster* inBot)
{
    bot = inBot;
}

void BotManager::OnReady(const dpp::ready_t& ready)
{
    bot->set_presence({presence_status::ps_online, activity_type::at_listening, "Discord C++"});
}
