#pragma once
/* 
 * Copyright (C) 2006 CrFusion Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

//////////////////////////////////////////////////////////////////////
//  Chat
//
//  Receives all messages with a chat-related opcode.
//////////////////////////////////////////////////////////////////////
#ifndef WOWSERVER_CHAT_H
#define WOWSERVER_CHAT_H

#include "Creature.h"
#include "../Game/WorldSession.h"
#include "../Game/Player.h"
#include "../Game/Unit.h"

class ChatHandler;
class WorldSession;
class Player;
class Unit;

enum ChatMsgNew
{
	CHAT_MSG_SAY								=0,
	CHAT_MSG_PARTY								=1,
	CHAT_MSG_RAID								=2,
	CHAT_MSG_GUILD								=3,
	CHAT_MSG_OFFICER							=4,
	CHAT_MSG_YELL								=5,
	CHAT_MSG_WHISPER							=6,
	CHAT_MSG_WHISPER_INFORM						=7,
	CHAT_MSG_EMOTE								=8,
	CHAT_MSG_TEXT_EMOTE							=9,
	CHAT_MSG_SYSTEM								=10,
	CHAT_MSG_MONSTER_SAY						=11,
	CHAT_MSG_MONSTER_YELL						=12,
	CHAT_MSG_MONSTER_EMOTE						=13,
	CHAT_MSG_CHANNEL							=14,
	CHAT_MSG_CHANNEL_JOIN						=15,
	CHAT_MSG_CHANNEL_LEAVE						=16,
	CHAT_MSG_CHANNEL_LIST						=17,
	CHAT_MSG_CHANNEL_NOTICE						=18,
	CHAT_MSG_CHANNEL_NOTICE_USER				=19,
	CHAT_MSG_AFK								=20,
	CHAT_MSG_DND								=21,
	CHAT_MSG_IGNORED							=22,
	CHAT_MSG_SKILL								=23,
	CHAT_MSG_LOOT								=24,
	CHAT_COMBAT_MISC_INFO						=25,
	CHAT_MONSTER_WHISPER						=26,
	CHAT_COMBAT_SELF_HITS						=27,
	CHAT_COMBAT_SELF_MISSES						=28,
	CHAT_COMBAT_PET_HITS						=29,
	CHAT_COMBAT_PET_MISSES						=30,
	CHAT_COMBAT_PARTY_HITS						=31,
	CHAT_COMBAT_PARTY_MISSES					=32,
	CHAT_COMBAT_FRIENDLYPLAYER_HITS				=33,
	CHAT_COMBAT_FRIENDLYPLAYER_MISSES			=34,
	CHAT_COMBAT_HOSTILEPLAYER_HITS				=35,
	CHAT_COMBAT_HOSTILEPLAYER_MISSES			=36,
	CHAT_COMBAT_CREATURE_VS_SELF_HITS			=37,
	CHAT_COMBAT_CREATURE_VS_SELF_MISSES			=38,
	CHAT_COMBAT_CREATURE_VS_PARTY_HITS			=39,
	CHAT_COMBAT_CREATURE_VS_PARTY_MISSES		=40,
	CHAT_COMBAT_CREATURE_VS_CREATURE_HITS		=41,
	CHAT_COMBAT_CREATURE_VS_CREATURE_MISSES		=42,
	CHAT_COMBAT_FRIENDLY_DEATH					=43,
	CHAT_COMBAT_HOSTILE_DEATH					=44,
	CHAT_COMBAT_XP_GAIN							=45,
	CHAT_SPELL_SELF_DAMAGE						=46,
	CHAT_SPELL_SELF_BUFF						=47,
	CHAT_SPELL_PET_DAMAGE						=48,
	CHAT_SPELL_PET_BUFF							=49,
	CHAT_SPELL_PARTY_DAMAGE						=50,
	CHAT_SPELL_PARTY_BUFF						=51,
	CHAT_SPELL_FRIENDLYPLAYER_DAMAGE			=52,
	CHAT_SPELL_FRIENDLYPLAYER_BUFF				=53,
	CHAT_SPELL_HOSTILEPLAYER_DAMAGE				=54,
	CHAT_SPELL_HOSTILEPLAYER_BUFF				=55,
	CHAT_SPELL_CREATURE_VS_SELF_DAMAGE			=56,
	CHAT_SPELL_CREATURE_VS_SELF_BUFF			=57,
	CHAT_SPELL_CREATURE_VS_PARTY_DAMAGE			=58,
	CHAT_SPELL_CREATURE_VS_PARTY_BUFF			=59,
	CHAT_SPELL_CREATURE_VS_CREATURE_DAMAGE		=60,
	CHAT_SPELL_CREATURE_VS_CREATURE_BUFF		=61,
	CHAT_SPELL_TRADESKILLS						=62,
	CHAT_SPELL_DAMAGESHIELDS_ON_SELF			=63,
	CHAT_SPELL_DAMAGESHIELDS_ON_OTHERS			=64,
	CHAT_SPELL_AURA_GONE_SELF					=65,
	CHAT_SPELL_AURA_GONE_PARTY					=66,
	CHAT_SPELL_AURA_GONE_OTHER					=67,
	CHAT_SPELL_ITEM_ENCHANTMENTS				=68,
	CHAT_SPELL_BREAK_AURA						=69,
	CHAT_SPELL_PERIODIC_SELF_DAMAGE				=70,
	CHAT_SPELL_PERIODIC_SELF_BUFFS				=71,
	CHAT_SPELL_PERIODIC_PARTY_DAMAGE			=72,
	CHAT_SPELL_PERIODIC_PARTY_BUFFS				=73,
	CHAT_SPELL_PERIODIC_FRIENDLYPLAYER_DAMAGE	=74,
	CHAT_SPELL_PERIODIC_FRIENDLYPLAYER_BUFFS	=75,
	CHAT_SPELL_PERIODIC_HOSTILEPLAYER_DAMAGE	=76,
	CHAT_SPELL_PERIODIC_HOSTILEPLAYER_BUFFS		=77,
	CHAT_SPELL_PERIODIC_CREATURE_DAMAGE			=78,
	CHAT_SPELL_PERIODIC_CREATURE_BUFFS			=79,
	CHAT_SPELL_FAILED_LOCALPLAYER				=80,
	CHAT_COMBAT_HONOR_GAIN						=81,
	CHAT_BG_SYSTEM_NEUTRAL						=82,
	CHAT_BG_SYSTEM_ALLIANCE						=83,
	CHAT_BG_SYSTEM_HORDE						=84
};

class ChatCommand
{
public:
    const char *       Name;
    uint16             SecurityLevel;
    bool (ChatHandler::*Handler)(const char* args) ;
    std::string        Help;
    ChatCommand *      ChildCommands;
};

class ChatHandler : public Singleton<ChatHandler>
{
public:
    ChatHandler();
    ~ChatHandler();

    void FillMessageData( WorldPacket *data, WorldSession* session, uint32 type,
		uint32 language, const char* channelName, const char* message,
		Guid someguid=0) const;

    void
		FillSystemMessageData( WorldPacket *data, WorldSession* session, const char* message ) const
    {
        FillMessageData( data, session, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, message );
    }

	void
		GMMessage( WorldSession* session, const char * str, ... ) 
	{
		if (( !str ) || (!session->GetSecurity())) return;
		{
			char *lstpx = new char[2048];
			WorldPacket data;

			va_list ap;
			va_start(ap, str);
			vsprintf(lstpx, str, ap );

			FillSystemMessageData( &data, session, lstpx );
			session->SendPacket( &data );

			delete lstpx;
			va_end(ap);
		}
	}

    int ParseCommands(const char* text, WorldSession *session);

protected:
    Creature *SpawnCreature (WorldSession *session, CreatureTemplate *ct, uint32 mapId,
        float x, float y, float z, float o);
    Creature *SpawnCreature (WorldSession *session, CreatureTemplate *ct);
    /*void SpawnCreature(WorldSession *session, const char* pName, uint32 displayId, uint32 npcFlags, uint32 factionId, uint32 level);
    void SpawnCreature (WorldSession *session, CreatureTemplate *ct);*/
    //void smsg_NewWorld(WorldSession *session, uint32 mapid, float x, float y, float z);
    //void MovePlayer(WorldSession *session, float x, float y, float z);

    bool hasStringAbbr(const char* s1, const char* s2);
    void SendMultilineMessage(const char *str);

    bool ExecuteCommandInTable(ChatCommand *table, const char* text);
    bool ShowHelpForCommand(ChatCommand *table, const char* cmd);

    ChatCommand* getCommandTable();

    // Level 0 commands
    bool HandleHelpCommand(const char* args);
    bool Command_Commands (const char* args);
	bool HandleVersionCommand(const char* args);
    bool HandleNYICommand(const char* args);
    bool HandleAcctCommand(const char* args);
    bool HandleStartCommand(const char* args);
    bool HandleInfoCommand(const char* args);
    bool HandleMountCommand(const char* args);
    bool HandleDismountCommand(const char* args);
    bool HandleSaveCommand(const char* args);
    bool HandleGMListCommand(const char* args);
	bool HandleStatsCommand(const char* args);
	bool HandleKickCommand(const char* args);

    // Level 1 commands
    bool HandleSummonCommand(const char* args);
    bool HandleAppearCommand(const char* args);
    bool HandleRecallCommand(const char* args);
    bool HandleAnnounceCommand(const char* args);
	bool HandleAnnounceWideCommand(const char* args);
    bool HandleGMOnCommand(const char* args);
    bool HandleGMOffCommand(const char* args);
    bool Command_Where (const char* args);
    bool HandleTaxiCheatCommand(const char* args);

	bool Command_GameObject_Add(const char* args);
	bool Command_GameObject_Del(const char* args);
	bool Command_GameObject_ChangeId(const char* args);

    bool Command_Modify_HP (const char* args);
    bool Command_Modify_Mana (const char* args);
    bool Command_Modify_Rage (const char* args);
    bool Command_Modify_Energy (const char* args);
    bool Command_Modify_Money (const char* args);
    bool Command_Modify_Level (const char* args);
    bool Command_Modify_qItems (const char* args);
    bool Command_Modify_qKill (const char* args);
    bool Command_Modify_Item   (const char* args);
    bool Command_Modify_Speed (const char* args);
    bool Command_Modify_Swim (const char* args);
    bool Command_Modify_Size (const char* args);
    bool Command_Modify_Mount (const char* args);
    
    // Level 2 commands
    bool HandleProgCommand (const char* args);
    bool HandleItemMoveCommand (const char* args);
	bool Command_Account_Add (const char* args);
	bool Command_Account_Del (const char* args);
	bool Command_Account_Ban (const char* args);

    // Level 3 commands
	bool PlayerFlag(const char* args);
	bool Warden(const char* args);
	bool ShutDown(const char* args);
	bool CancelShutdown (const char* args);
	bool HardwareSurvey(const char* args);
    bool HandleSecurityCommand (const char* args);
    bool HandleWorldPortCommand (const char* args);
    bool HandleAddSpiritCommand (const char* args);
    bool HandleMoveCommand (const char* args);
    bool Command_Modify_Spell (const char* args);
    bool Command_Modify_Skill (const char* args);
    bool HandleUnlearnCommand (const char* args);
    bool HandleObjectCommand (const char* args);
    bool HandleAnimCommand (const char* args);
    bool HandleStandStateCommand (const char* args);
    bool HandleDieCommand (const char* args);
    bool HandleReviveCommand (const char* args);
    bool HandleMorphCommand (const char* args);
    bool HandleAuraCommand (const char* args);
    bool HandleAddSHCommand (const char* args);
    bool HandleSpawnTransportCommand (const char* args);
    bool HandleInvisCommand (const char* args);

    //------------------------------------------------------------------
    // Waypoints Control Commands
    //------------------------------------------------------------------
    WaypointIndicatorList   m_wpIndicators;
    
    WaypointIndicator *SpawnWaypointIndicator (float x, float y, float z, uint32 index);
    void _recreateCreatureWaypointIndicators (Creature *cr);
    void _resaveWaypoints (Creature *cr);

    bool Command_WP_Info (const char *args);
    bool Command_WP_Show (const char *args);
    bool Command_WP_Hide (const char *args);
    bool Command_WP_Come (const char *args);
    bool Command_WP_Delete (const char *args);
    bool Command_WP_Clear (const char *args);
    bool Command_WP_Add (const char *args);
    bool Command_WP_Wait (const char *args);

    //------------------------------------------------------------------
    // NPC Control commands
    //------------------------------------------------------------------
    bool Command_NPC_Add (const char* args);
    bool Command_NPC_Turn (const char *args);
	bool Command_NPC_Come (const char *args);
    bool Command_NPC_MType (const char* args);
    bool Command_NPC_Level (const char* args);
    bool Command_NPC_Sell (const char* args);
    bool Command_NPC_Delete (const char* args);
    bool Command_NPC_Model (const char* args);
    bool Command_NPC_Faction (const char* args);
    bool Command_NPC_Flags (const char* args);
    bool Command_NPC_Size (const char* args);
    bool Command_NPC_Info (const char* args);
    bool Command_NPC_Run (const char* args);
    bool Command_NPC_GUID (const char* args);
    bool Command_NPC_SpawnTime (const char* args);
    bool Command_NPC_SpawnDistance (const char* args);
	bool Command_NPC_ListHate (const char* args);
	bool Command_NPC_Kill (const char* args);
	bool Command_NPC_Respawn (const char* args);

    //------------------------------------------------------------------
    // Debug and developers access only
    //------------------------------------------------------------------
    bool Command_ImportWorld (const char* args);
	bool Command_ImportGameobj (const char* args);
	bool Command_GoGUID (const char* args);
#ifdef _DEBUG
    bool Command_Test (const char* args);
#endif
    bool Command_Debug_Flags (const char* args);
    bool Command_Debug_DynamicFlags (const char* args);
    bool Command_Debug_Bytes0 (const char* args);
    bool Command_Debug_Bytes1 (const char* args);
    bool Command_Debug_Bytes2 (const char* args);
	bool Command_Debug_ReloadScripts (const char* args);
	bool Command_Debug_Errors (const char* args);
	bool Command_Debug_QInv (const char* args);
	bool Command_Debug_QFailed (const char* args);

    Player* getSelectedChar(WorldSession *client);
	Object* getSelectedObj(WorldSession *client);

public: //? maybe making this public is wrong?
    WorldSession *m_session;
};


#define sChatHandler ChatHandler::getSingleton()


#endif
