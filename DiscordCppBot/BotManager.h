#pragma once

#pragma warning(push)
#pragma warning(disable: 4251)
#include "dpp/dpp.h"
#pragma warning(push)

class BotManager
{
public:
    BotManager(dpp::cluster* inBot);
    
    void OnReady(const dpp::ready_t& ready);

private:
    dpp::cluster* bot;
};
