#include "BotManager.h"
#include "CommandManager.h"
#include "Commands/TestCommand.h"

#pragma warning(push)
#pragma warning(disable: 4251)
#include "dpp/dpp.h"
#pragma warning(pop)

const std::string BOT_TOKEN = "MTA4MjMwNDU5ODYxMTU5MTMwOA.Gwj3tc.GJq3uUGdvLwtls1Nlz2C_WSesMCQEOqFGjMCp0";

int main()
{
    dpp::cluster bot{BOT_TOKEN};
    bot.intents = dpp::i_all_intents;

    CommandManager cmdManager{&bot};
    
    BotManager manager{&bot};
    
    bot.on_log(dpp::utility::cout_logger());

    cmdManager.AddCommand<TestCommand>();
    
    bot.on_ready([&manager, &cmdManager](const dpp::ready_t& e)
    {
        manager.OnReady(e);
        cmdManager.RegisterCommands();
    });

    /* Main App */
    
    bot.start(dpp::st_wait);
}