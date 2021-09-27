/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

// Add player scripts
//class MyPlayer : public PlayerScript
//{
//public:
//    MyPlayer() : PlayerScript("MyPlayer") { }
//
//    void OnUpdateZone(Player* player) override
//    {
//        if (sConfigMgr->GetOption<bool>("MyModule.Enable", true))
//        {
//            if (!player->GetMap()->IsRaid())
//            {
////                player->RemoveAura(75447);
//                ChatHandler(player->GetSession()).SendSysMessage("Test module working.");
//            }
//        }
//    }
//};

class MyPlayer : public PlayerScript
{
public:
    MyPlayer() : PlayerScript("MyPlayer") { }

    void OnUpdateZone(Player* player) override
    {
         ChatHandler(player->GetSession()).SendSysMessage("Test module working.");
    }
};

// Add all scripts in one
void AddMyPlayerScripts()
{
    new MyPlayer();
}
