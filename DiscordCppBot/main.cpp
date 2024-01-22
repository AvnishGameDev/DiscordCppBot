#include "BotManager.h"
#include "CommandManager.h"
#include "Commands/TestCommand.h"

#pragma warning(push)
#pragma warning(disable: 4251)
#include "EventManager.h"
#include "Commands/ClearCommand.h"
#include "dpp/dpp.h"
#include "Events/GuildMemberAdd.h"
#pragma warning(pop)

const std::string BOT_TOKEN = ""; // Add your token here.

int main()
{
    dpp::cluster bot{BOT_TOKEN};
    bot.intents = dpp::i_all_intents;

    CommandManager cmdManager{&bot};
    
    BotManager manager{&bot};

    EventManager eventManager;
    
    bot.on_log(dpp::utility::cout_logger());

    cmdManager.AddCommand<TestCommand>();
    cmdManager.AddCommand<ClearCommand>();

    eventManager.AddEvent<GuildMemberAdd>();
    
    bot.on_ready([&bot, &manager, &cmdManager, &eventManager](const dpp::ready_t& e)
    {
        manager.OnReady(e);
        cmdManager.RegisterCommands();
        eventManager.BindEvents(&bot);
    });
    
    /* Main App */
    
    bot.start(dpp::st_wait);
}
