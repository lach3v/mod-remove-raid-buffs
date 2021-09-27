/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

// Add player scripts
class MyPlayer : public PlayerScript
{
public:
    MyPlayer() : PlayerScript("MyPlayer") { }

    void OnMapChanged(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("MyModule.Enable", true) && !player->GetMap()->IsRaid())
        {
            player->RemoveAura(75447);
        }
    }
};
//    void OnLogin(Player* player) override
//    {
//        if (sConfigMgr->GetOption<bool>("MyModule.Enable", false))
//        {
//            void OnMapChanged(Player* player) override
//            {
//                if (!player->GetMap()->IsRaid())
//                {
//                    player->RemoveAura(75447);
//                }
//            }
//        }
//    }
//};

// Add all scripts in one
void AddMyPlayerScripts()
{
    new MyPlayer();
}
