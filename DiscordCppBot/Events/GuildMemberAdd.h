#pragma once

#include "../Event.h"

class GuildMemberAdd : public Event
{
public:
    
    GuildMemberAdd() : Event("onGuildMemberAdd")
    {
        
    }

    void Bind(dpp::cluster* inBot) override
    {
        Event::Bind(inBot);
        
        bot->on_guild_member_add(std::bind(&GuildMemberAdd::OnExecute, this, std::placeholders::_1));
    }
    
    void OnExecute(dpp::guild_member_add_t e)
    {
        if (e.added.get_user()->is_bot()) return;

        dpp::embed embed = dpp::embed()
        .set_color(0x00FFFF)
        .set_title(e.added.get_user()->username + " just joined!")
        .set_description("Welcome " + e.added.get_user()->username + " to AvnishGameDev's server!")
        .set_footer(
            dpp::embed_footer()
            .set_icon(e.added.get_avatar_url())
            .set_text("AvnishGameDev's Server")
            )
        .set_thumbnail(e.added.get_avatar_url())
        .set_image("https://cdn.discordapp.com/attachments/852966209376092212/973099219290320946/standard_3.gif")
        .set_timestamp(time(0));

        dpp::message m{1077104188804313112, embed};
        bot->message_create_sync(m);
    }
};