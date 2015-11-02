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

#include "StdAfx.h"

createFileSingleton( ChatHandler );

ChatHandler::ChatHandler()
{

}

ChatHandler::~ChatHandler()
{

}

ChatCommand*
ChatHandler::getCommandTable()
{
    static bool first_call = true;

	/***********
	* Plevels: *
	* 0-Player *
	* 1-HalfGm *
	* 2-Gm     *
	* 3-Admin  *
	* 4-SAdmin *
	************/

	//------------------------------------------------------------------
	// Commands to deal with accounts
	// called as .ACCOUNT xxxx
	//------------------------------------------------------------------
    static ChatCommand accountCommandTable[] = {
        { "add",      2, &ChatHandler::Command_Account_Add,      "Adds an account to the server",               NULL },
        { "del",      3, &ChatHandler::Command_Account_Del,      "Deletes an account from the server",          NULL },
        { "ban",      2, &ChatHandler::Command_Account_Ban,      "Bans an account from the server",             NULL },
		{ NULL, 0, NULL, "", NULL }
	};

	//------------------------------------------------------------------
	// Commands to deal with gameobjects
	// called as .GAMEOBJECT xxxx  (or .GO)
	//------------------------------------------------------------------
    static ChatCommand goCommandTable[] = {
        { "add",       1, &ChatHandler::Command_GameObject_Add,      "Adds a GameObject to the world",                  NULL },
        { "del",       1, &ChatHandler::Command_GameObject_Del,      "Deletes the nearest GameObject from the world",   NULL },
        { "changeid",  1, &ChatHandler::Command_GameObject_ChangeId, "Changes the Entry ID of the nearest GameObject",  NULL },
		{ NULL, 0, NULL, "", NULL }
	};

	//------------------------------------------------------------------
	// Commands to modify players
	// called as .MODIFY xxxx  (or .MOD)
	//------------------------------------------------------------------
    static ChatCommand modifyCommandTable[] = {
        { "qitems",      1, &ChatHandler::Command_Modify_qItems,  "Adds the required items for a given quest",   NULL },
        { "qkill",       1, &ChatHandler::Command_Modify_qKill,   "Adds a fake kill for quest",   NULL },
        { "item",        1, &ChatHandler::Command_Modify_Item,    "Adds an item to backpack",   NULL },
        { "hp",          1, &ChatHandler::Command_Modify_HP,      "",   NULL },
        { "mana",        1, &ChatHandler::Command_Modify_Mana,    "",   NULL },
        { "rage",        1, &ChatHandler::Command_Modify_Rage,    "",   NULL },
        { "energy",      1, &ChatHandler::Command_Modify_Energy,  "",   NULL },
        { "money",       1, &ChatHandler::Command_Modify_Money,   "",   NULL },
		{ "gold",        1, &ChatHandler::Command_Modify_Money,   "",   NULL },
        { "level",       1, &ChatHandler::Command_Modify_Level,   "",   NULL },
        { "speed",       1, &ChatHandler::Command_Modify_Speed,   "",   NULL },
        { "swim",        1, &ChatHandler::Command_Modify_Swim,    "",   NULL },
        { "size",        1, &ChatHandler::Command_Modify_Size,    "",   NULL },
        { "mount",       1, &ChatHandler::Command_Modify_Mount,   "",   NULL },
        //{ "bit",         1, &ChatHandler::HandleModifyBitCommand,     "",   NULL },
        //{ "bwalk",       1, &ChatHandler::HandleModifyBWalkCommand,   "",   NULL },
        //{ "aspeed",      1, &ChatHandler::HandleModifyASpedCommand,   "",   NULL },
		{ "spell",		1, &ChatHandler::Command_Modify_Spell,
			"MOD SPELL id - Teaches selected player a spell (to remove spell set 'id' negative)", NULL },
		{ "skill",		1, &ChatHandler::Command_Modify_Skill,
			"MOD SKILL id level - Teaches selected player a skill (to remove skill set 'id' negative)", NULL },
		{ NULL, 0, NULL, "", NULL }
	};

	//------------------------------------------------------------------
	// Commands to create and edit waypoints in the world
	// called as .WP xxxx
	//------------------------------------------------------------------
	static ChatCommand waypointsCommandTable[] = {
		{ "add", 2, &ChatHandler::Command_WP_Add,
			"WP ADD - Add waypoint for selected mob (or another waypoint) at your location. "
			"If you type .WP ADD N - then waypoint will be inserted at position N", NULL },
		{ "info", 3, &ChatHandler::Command_WP_Info,
			"WP INFO - Displays brief information about current mob",   NULL },
		{ "show", 3, &ChatHandler::Command_WP_Show,
			"WP SHOW - Shows all waypoints for selected mob, indicators for previous mob are cleared",   NULL },
		{ "hide", 3, &ChatHandler::Command_WP_Hide,
			"WP HIDE - Hides waypoint indicators",   NULL },
		{ "come", 3, &ChatHandler::Command_WP_Come,
			"WP COME (MOVE) - Moves selected waypoint to player location",   NULL },
		{ "move", 3, &ChatHandler::Command_WP_Come,
			"WP MOVE (COME) - Moves selected waypoint to player location",   NULL },
		{ "del", 3, &ChatHandler::Command_WP_Delete,
			"WP DEL[ETE] - Deletes selected waypoint",   NULL },
		{ "delete", 3, &ChatHandler::Command_WP_Delete,
			"WP DEL[ETE] - Deletes selected waypoint",   NULL },
		{ "clear", 3, &ChatHandler::Command_WP_Clear,
			"WP CLEAR - Deletes all waypoints for mob. You should select mob, not waypoint.",   NULL },
		{ "wait", 3, &ChatHandler::Command_WP_Wait,
			"WP WAIT - Sets wait times for selected waypoint, can be used as .WP WAIT N - for wait "
			"always for N, and as .WP WAIT N M - for random wait time between N and M.", NULL },
		{ NULL, 0, NULL, "", NULL }
	};

	//------------------------------------------------------------------
	// Commands to create and edit NPCs and NPC spawns in the world
	// called as .NPC xxxx
	//------------------------------------------------------------------
	static char *_npc_delete_help = "NPC DEL or DELETE - Deletes selected NPC and his waypoints from "
		"the world instantly.";
	static char *_spawntime_help = "NPC SPTIME or SPT - Allows changing spawntime for "
		"selected mob. Requires 1 or 2 numbers expressed in seconds. 2 numbers represent "
		"random wait time in range from T1 to T2 seconds.";
	static char *_spawndist_help = "NPC SPDIST or SPD - Allows changing spawn distance for "
		"selected mob. Requires single parameter expressed in game units (metres).";
	
	static ChatCommand npcCommandTable[] = {
		{ "add",	1,	&ChatHandler::Command_NPC_Add,
			"NPC ADD - Spawns new NPC at current position using NPC template with given Id", NULL },
		{ "level",  2,  &ChatHandler::Command_NPC_Level,
			"NPC LEVEL - Sets level for selected NPC",   NULL },
		{ "mtype",  1,	&ChatHandler::Command_NPC_MType,
			"NPC MTYPE - Choose movement type for NPC: 0 - random roam, 1 and 2 - walking along the "
			"path forth and back, 3 - looping over the path forth, 4 - looping back",   NULL },
		{ "turn",	1, &ChatHandler::Command_NPC_Turn,
			"NPC TURN - Turns NPC facing to you and remembers this angle until spawn time "
			"or when mob returns to original location", NULL },
		{ "come",	1, &ChatHandler::Command_NPC_Come,
			"NPC COME - Sets NPC spawn point to player position and orientation", NULL },
		{ "sell",   2, &ChatHandler::Command_NPC_Sell,
			"NPC SELL - Adds item to selected vendor sell list", NULL },
		{ "del", 1, &ChatHandler::Command_NPC_Delete, _npc_delete_help, NULL },
		{ "delete", 1, &ChatHandler::Command_NPC_Delete, _npc_delete_help, NULL },
		{ "model",  2, &ChatHandler::Command_NPC_Model,
			"NPC MODEL - Changes display model for selected NPC (permanent for this spawn)",   NULL },
		{ "faction", 1, &ChatHandler::Command_NPC_Faction,
			"NPC FACTION - Changes faction template for selected NPC (permanent for this spawn)",   NULL },
		{ "flags",  1, &ChatHandler::Command_NPC_Flags,
			"NPC FLAGS - Changes NPC flags for selected NPC",   NULL },
		{ "size", 1, &ChatHandler::Command_NPC_Size, "NPC SIZE - Changes size of selected NPC",   NULL },
		{ "info", 1, &ChatHandler::Command_NPC_Info, "NPC INFO - Displays brief info for selected NPC",   NULL },
		{ "listhate", 1, &ChatHandler::Command_NPC_ListHate,
			"NPC LISTHATE - Briefly shows hate list contents for mob",   NULL },
		{ "run", 1, &ChatHandler::Command_NPC_Run, "NPC RUN - Sets walk or run mode for selected NPC",   NULL },
		{ "guid", 1, &ChatHandler::Command_NPC_GUID, "NPC GUID - Displays GUID of selected mob",   NULL },
		{ "sptime", 2, &ChatHandler::Command_NPC_SpawnTime, _spawntime_help,  NULL },
		{ "spt", 2, &ChatHandler::Command_NPC_SpawnTime, _spawntime_help,  NULL },
		{ "spdist", 2, &ChatHandler::Command_NPC_SpawnDistance, _spawndist_help,  NULL },
		{ "spd", 2, &ChatHandler::Command_NPC_SpawnDistance, _spawndist_help,  NULL },
		{ "kill",	1,	&ChatHandler::Command_NPC_Kill,
			"NPC KILL - Kills targeted NPC in place", NULL },
		{ "respawn", 1,	&ChatHandler::Command_NPC_Respawn,
			"NPC KILL - Makes targeted NPC or NPC corpse instantly respawn once", NULL },
		{ NULL, 0, NULL, "", NULL }
		};

	//------------------------------------------------------------------
	// For debugging purposes, don't use
	//------------------------------------------------------------------
	static ChatCommand debugCommandTable[] = {
#ifdef _DEBUG
		{ "test", 0,	&ChatHandler::Command_Test,
			"DEBUG TEST - Test command" },
#endif
		{ "flags", 1,	&ChatHandler::Command_Debug_Flags,
			"DEBUG FLAGS - Sets FLAGS update field of selected NPC",  NULL },
		{ "dynamicflags", 1, &ChatHandler::Command_Debug_DynamicFlags,
			"DEBUG DYNAMICFLAGS - Sets DYNAMICFLAGS update field of selected NPC",  NULL },
		{ "bytes0", 1,	&ChatHandler::Command_Debug_Bytes0,
			"DEBUG BYTES0 - Sets BYTES0 update field of selected NPC",  NULL },
		{ "bytes1", 1,	&ChatHandler::Command_Debug_Bytes1,
			"DEBUG BYTES1 - Sets BYTES1 update field of selected NPC",  NULL },
		{ "bytes2", 1,	&ChatHandler::Command_Debug_Bytes2,
			"DEBUG BYTES2 - Sets BYTES2 update field of selected NPC",  NULL },
		{ "qinv", 1,	&ChatHandler::Command_Debug_QInv,
			"QUEST INVALID - Blah",  NULL },
		{ "qfailed", 1,	&ChatHandler::Command_Debug_QFailed,
			"QUEST INVALID - Blah",  NULL },
		{ "error", 1, &ChatHandler::Command_Debug_Errors,
			"DEBUG ERROR - Outputs Error Message in Red acc. given err. code",  NULL },
		{ "reload", 1, &ChatHandler::Command_Debug_ReloadScripts,
			"DEBUG RELOAD - Reloads all Python scripts attached to server" },
		{ NULL, 0, NULL, "", NULL }

	};

	static ChatCommand importCommandTable[] = {
		{ "world", 3, &ChatHandler::Command_ImportWorld,
			"IMPORT WORLD - Imports text file named world_spawns.txt with creatures. "
			"Make sure you cleared tables Creatures and Creatures_mov. "
			"(Developers only! May crash server or screw world database!)", NULL },
		{ "gameobj", 3, &ChatHandler::Command_ImportGameobj,
			"IMPORT GAMEOBJ - Imports text file named world_gameobj.txt with gameobjects. "
			"Make sure you cleared table Gameobjects. "
			"(Developers only! May crash server or screw world database!)", NULL },
		{ NULL, 0, NULL, "", NULL }
	};

	//------------------------------------------------------------------
    // General commands
	//------------------------------------------------------------------
    static ChatCommand commandTable[] = {
        { "acct",        0, &ChatHandler::HandleAcctCommand,                             "",                NULL },
        { "anim",        3, &ChatHandler::HandleAnimCommand,                             "",                NULL },
        { "announce",    1, &ChatHandler::HandleAnnounceCommand,
			                      "ANNOUNCE (BROADCAST) - Broadcast message to all players",                NULL },
		{ "broadcast",   1, &ChatHandler::HandleAnnounceCommand,
			                      "BROADCAST (ANNOUNCE) - Broadcast message to all players",                NULL },
        { "bwide",       1, &ChatHandler::HandleAnnounceWideCommand,
			                   "BWIDE - Broadcast message to all players widescreen format",                NULL },
        { "goname",      1, &ChatHandler::HandleAppearCommand,
			                                "GONAME - Teleport yourself to player location",                NULL },
        { "aura",        3, &ChatHandler::HandleAuraCommand,                             "",                NULL },
        { "commands",    0, &ChatHandler::Command_Commands,
			              "COMMANDS - Display all available commands for your access level",                NULL },
		{ "version",	0,	&ChatHandler::HandleVersionCommand,		"VER[SION] - Print server version",		NULL },
		{ "ver",		0,	&ChatHandler::HandleVersionCommand,		"VER[SION] - Print server version",		NULL },
        { "die",         1, &ChatHandler::HandleDieCommand,
			                                                         "DIE - Kills yourself",                NULL },
        { "revive",      1, &ChatHandler::HandleReviveCommand,
			"REVIVE/RESURRECT - Instantly resurrect, when dead use whisper or channel chat",                NULL },
        { "resurrect",      1, &ChatHandler::HandleReviveCommand,
			"RESURRECT/REVIVE - Instantly resurrect, when dead use whisper or channel chat",                NULL },
        { "dismount",    0, &ChatHandler::HandleDismountCommand,
			                   "DISMOUNT - Dismounts you and restores your movement speeds",                NULL },
        { "gmlist",      0, &ChatHandler::HandleGMListCommand,
			"GMLIST - Shows list of all online GM on server",                                               NULL },
        { "gmoff",       1, &ChatHandler::HandleGMOffCommand,                            "",                NULL },
        { "gmon",        1, &ChatHandler::HandleGMOnCommand,                             "",                NULL },
		{ "invis",       2, &ChatHandler::HandleInvisCommand,
			             "INVIS - Toggles GM Invisibility which hides you to all th players",               NULL },
		{ "where",       0, &ChatHandler::Command_Where, "WHERE - Shows your location in the world",        NULL },
        { "help",        0, &ChatHandler::HandleHelpCommand,
			"HELP - Use .COMMANDS to list available commands and use .HELP XXX to get help on command XXX", NULL },
        { "info",        1, &ChatHandler::HandleInfoCommand,
			"INFO - Brief information on selected mob",                                                     NULL },
        { "itemmove",    2, &ChatHandler::HandleItemMoveCommand,
			"ITEMMOVE - Swaps two slots in your inventory",                                                 NULL },
        { "kick",        2, &ChatHandler::HandleKickCommand,
			                   "KICK - Forces named player to disconnect (Not Implemented)",                NULL },
        { "morph",       3, &ChatHandler::HandleMorphCommand,
			                               "MORPH - Changes your display model to anything",                NULL },
        { "setmodel",    2, &ChatHandler::HandleMorphCommand,
                                           "MORPH - Changes your display model to anything",                NULL },
        { "mount",       0, &ChatHandler::HandleMountCommand,
			              "MOUNT - Mounts yourself on specified mount, DISMOUNT to get off",                NULL },
		{ "go",          1, &ChatHandler::HandleMoveCommand,
			                                 "GO - Moves yourself inside current world map",                NULL },
		{ "addgo",       1, &ChatHandler::HandleObjectCommand,
			"ADDGO - Creates gameobject at your location. Use <.addgo NN> to create and test safely, and <.addgo NN true> to create and save in DB",   NULL },
        { "recall",      1, &ChatHandler::HandleRecallCommand,
			"RECALL - Quick jump to known world locations - sunr, thun, cross, ogri, neth, thel, storm, iron, under, darn",   NULL },
        { "save",        0, &ChatHandler::HandleSaveCommand,                             "",                NULL },
        { "security",    3, &ChatHandler::HandleSecurityCommand,                         "",                NULL },
        { "standstate",  3, &ChatHandler::HandleStandStateCommand,                       "",                NULL },
        { "hearth",       0, &ChatHandler::HandleStartCommand,
			         "HEARTH - Teleport yourself to hearth location (usually player start)",                NULL },
        { "namego",      1, &ChatHandler::HandleSummonCommand,
			                               "NAMEGO - Summons named player to your location",                NULL },
        { "taxicheat",   1, &ChatHandler::HandleTaxiCheatCommand,
			                   "TAXICHEAT - Opens all flight locations for selected player",                NULL },
        { "worldgo",     3, &ChatHandler::HandleWorldPortCommand,
			      "WORLDGO map x y z - Moves yourself to specified map and xyz coordinates",                NULL },
		{ "wp",			2, NULL,"WP - has subcommands to deal with waypoints in the world",waypointsCommandTable },
		{ "npc",		1, NULL, "NPC - has subcommands to deal with NPCs in the world",         npcCommandTable },
		{ "import",		3, NULL, "IMPORT - set of data importing commands",                   importCommandTable },
		{ "debug",      3, NULL, "Access to development-time only commands",                   debugCommandTable },
		{ "gameobject", 1, NULL, "GO/GAMEOBJECT - has subcommands to deal with GOs in the world", goCommandTable },
        { "modify",     1, NULL, "MODIFY/MOD - Commands to edit values/stats of players",     modifyCommandTable },
        { "account",    1, NULL, "ACCOUNT - Commands to edit, add, bann accounts",           accountCommandTable },
		{ "goguid",     3, &ChatHandler::Command_GoGUID, 
			        "GOGUID - Teleports yourself to location of object with specified GUID",                NULL },
		{ "warden",     3, &ChatHandler::Warden,                                         "",                NULL },
		{ "shutdown",   3, &ChatHandler::ShutDown,                                       "",                NULL },
		{ "cshutdown",  3, &ChatHandler::CancelShutdown,                                 "",                NULL },
		{ "pflag",      3, &ChatHandler::PlayerFlag,                                     "",                NULL },
		{ "stats",      0, &ChatHandler::HandleStatsCommand,                             "",                NULL },
		{ NULL, 0, NULL, "", NULL }
    };

    if(first_call)
    {
        std::stringstream s;
        for(uint32 i = 0; commandTable[i].Name != NULL; ++i)
        {
            s.rdbuf()->str("");
            s << "SELECT security, help FROM commands WHERE name = '" << commandTable[i].Name  << "'";
            QueryResult* result = sDatabase.Query(s.str().c_str());
            if (result)
            {
                commandTable[i].SecurityLevel = (uint16)(*result)[1].GetUInt32();
                commandTable[i].Help = (*result)[1].GetString();
                delete result;
            }
            if(commandTable[i].ChildCommands != NULL)
            {
                ChatCommand *ptable = commandTable[i].ChildCommands;
                for(uint32 j = 0; ptable[j].Name != NULL; j++)
                {
                    s.rdbuf()->str("");
                    s << "SELECT security, help FROM commands WHERE name = '" << commandTable[i].Name << " "
                        << ptable[j].Name << "'";

                    QueryResult* result = sDatabase.Query(s.str().c_str());
                    if (result)
                    {
                        ptable[i].SecurityLevel = (uint16)(*result)[1].GetUInt32();
                        ptable[i].Help = (*result)[1].GetString();
                        delete result;
                    }
                }
            }
        }

        first_call = false;
    }

    return commandTable;
}

bool
ChatHandler::hasStringAbbr(const char* s1, const char* s2)
{
    for(;;)
    {
        if( !*s2 )
            return true;
        else if( !*s1 )
            return false;
        else if( tolower( *s1 ) != tolower( *s2 ) )
            return false;
        s1++; s2++;
    }
}

void
ChatHandler::SendMultilineMessage(const char *str)
{
    char buf[256];
    WorldPacket data;

    const char* line = str;
    const char* pos = line;
    while((pos = strchr(line, '\n')) != NULL)
    {
        strncpy(buf, line, pos-line);
        buf[pos-line]=0;

        FillSystemMessageData(&data, m_session, buf);
        m_session->SendPacket(&data);

        line = pos+1;
    }

    FillSystemMessageData(&data, m_session, line);
    m_session->SendPacket(&data);
}

bool
ChatHandler::ExecuteCommandInTable(ChatCommand *table, const char* text)
{
    std::string cmd = "";

    // skip command
    while (*text != ' ' && *text != '\0')
    {
        cmd += *text;
        text++;
    }

    while (*text == ' ') text++; // skip whitespace

    if(!cmd.length())
        return false;

    for(uint32 i = 0; table[i].Name != NULL; ++i)
    {
        if(!hasStringAbbr(table[i].Name, cmd.c_str()))
            continue;

        if(m_session->GetSecurity() < table[i].SecurityLevel)
            continue;

        if(table[i].ChildCommands != NULL)
        {
            if(!ExecuteCommandInTable(table[i].ChildCommands, text))
            {
                if(table[i].Help != "")
                    SendMultilineMessage(table[i].Help.c_str());
                else
                {
                    WorldPacket data;
                    FillSystemMessageData(&data, m_session, LANG_CMD_NONE);
                    m_session->SendPacket(&data);
                }
			} else {
				std::stringstream ss;
				ss <<"INSERT INTO cmd_logs(date, account, loc, command, arguments, targetInfo) VALUES("
					<< time(NULL) <<","
					<< m_session->GetAccountId() <<",'"
					<< m_session->GetPlayer()->GetMapId()	  <<" "
					<< m_session->GetPlayer()->GetPositionX() <<" "
					<< m_session->GetPlayer()->GetPositionY() <<" "
					<< m_session->GetPlayer()->GetPositionZ() <<"','"
					<< cmd  <<"',\""
					<< text <<"\",\""
					<< "<none>" <<"\");"; // Todo: Get informations from target (player/mob);

					sDatabase.Execute(ss.str().c_str());
			}

            return true;
        }

        if(!(this->*(table[i].Handler))(text))
        {
            if(table[i].Help != "")
                SendMultilineMessage(table[i].Help.c_str());
            else
            {
                WorldPacket data;
                FillSystemMessageData(&data, m_session, "Incorrect syntax.");
                m_session->SendPacket(&data);
            }
        }

        return true;
    }

    return false;
}

int
ChatHandler::ParseCommands(const char* text, WorldSession *session)
{
    m_session = session;

    ASSERT(text);
//    ASSERT(*text);

    if(text[0] != '!' && text[0] != '.') // let's not confuse users
        return 0;

    text++;

    if(!ExecuteCommandInTable(getCommandTable(), text))
    {
        WorldPacket data;
        FillSystemMessageData(&data, m_session, LANG_CMD_NONE);
        m_session->SendPacket(&data);
    }

    return 1;
}

void
ChatHandler::FillMessageData (WorldPacket *data, WorldSession* session,
								   uint32 type, uint32 language, const char *channelName,
								   const char *message, Guid someguid) const
{
    //Packet structure
    //uint8      type;
    //uint32     language;
    //uint64     guid;
    //uint32      len_of_text;
    //char       text[];         // not sure ? i think is null terminated .. not null terminated
    //uint8      afk_state;

    uint32 messageLength = strlen((char*)message) + 1;

    data->Initialize(SMSG_MESSAGECHAT);
    *data << (uint8)type;
    *data << language;

	uint64 senderGuid, receiverGuid = 0;

	switch (type) {
		case CHAT_MSG_SYSTEM: {
			*data << (uint64)0;
			break; }

		case CHAT_MSG_CHANNEL: {
		    ASSERT(channelName);
			*data << channelName;
			senderGuid = session ? session->GetPlayer()->GetGUID() : 0;
			*data << senderGuid;
			break; }
		
		case CHAT_MSG_YELL:
		case CHAT_MSG_PARTY:
		case CHAT_MSG_SAY: {
			//*data << (uint64)0;
			senderGuid = session ? session->GetPlayer()->GetGUID() : 0;
			*data << senderGuid << senderGuid;
			break; }
		case CHAT_MSG_WHISPER:
		case CHAT_MSG_WHISPER_INFORM: {
			if (someguid == 0)
			{
				senderGuid = session ? session->GetPlayer()->GetGUID() : 0;
				*data << senderGuid;
			} else {
				*data << someguid;
			}
			break; }

		case CHAT_MSG_EMOTE: {
			senderGuid = session ? session->GetPlayer()->GetGUID() : 0;
			//receiverGuid = 0;
			//*data << receiverGuid;
			*data << senderGuid;
			break; }
	}
/*
    if (type == CHAT_MSG_SAY || type == CHAT_MSG_CHANNEL || type == CHAT_MSG_WHISPER) 
	{
    }
    else if (type == CHAT_MSG_WHISPER_INFORM) {
        guid = session ? session->GetPlayer()->GetGUID() : 0; // FIXME: may be receiver?
    }
    *data << guid;
*/

	*data << uint32(messageLength);
	*data << message;
	
	uint8 afk = 0;
	if(type == CHAT_MSG_AFK && session != 0)
		afk = session->GetPlayer()->ToggleAFK();
    *data << afk;
}

Creature*
ChatHandler::SpawnCreature (WorldSession *session, CreatureTemplate *ct) 
{
	Player *chr = session->GetPlayer();
	float x = chr->GetPositionX();
	float y = chr->GetPositionY();
	float z = chr->GetPositionZ();
	float o = chr->GetOrientation();

	Creature *cr = SpawnCreature (session, ct, chr->GetMapId(), x, y, z, o);
	//cr->SetZoneId (chr->GetZoneId());

	cr->SaveToDB();
	return cr;
}

Creature*
ChatHandler::SpawnCreature (WorldSession *session, CreatureTemplate *ct, uint32 mapId, float x, float y, float z, float o)
{
	WorldPacket data;

	// Create the requested monster
	uint32 Level;
	uint32 levelDelta = ct->Level[1] - ct->Level[0];

	if (levelDelta) Level = ct->Level[0] + rand() % levelDelta;
	else Level = ct->Level[0];

	Creature *cr = new Creature();
	cr->Create (objmgr.GenerateLowGuid(HIGHGUID_UNIT), ct->Name.c_str(), mapId, x, y, z, o);

	cr->SetZoneId (session->GetPlayer()->GetZoneId());
	//cr->SetZoneId (objmgr.LookupZoneId (mapId, x, y));
	cr->SetUInt32Value (OBJECT_FIELD_ENTRY, ct->Entry);
	cr->SetFloatValue (OBJECT_FIELD_SCALE_X, ct->Size);
	cr->SetUInt32Value (UNIT_FIELD_DISPLAYID, ct->Model);
	cr->SetUInt32Value (UNIT_FIELD_NATIVEDISPLAYID, ct->Model);
	cr->SetUInt32Value (UNIT_NPC_FLAGS, ct->NPCFlags);
	cr->SetUInt32Value (UNIT_FIELD_FACTIONTEMPLATE , ct->Faction);
	cr->SetHealth (ct->MaxHealth);
	cr->SetMaxHealth (ct->MaxHealth);
	cr->SetLevel ((uint8)Level);
	cr->SetFloatValue (UNIT_FIELD_COMBATREACH, ct->CombatReach);
	cr->SetMinDamage ((float)ct->Damage[0]);
	cr->SetMaxDamage ((float)ct->Damage[1]);
	cr->SetUInt32Value (UNIT_FIELD_BASEATTACKTIME, ct->Attack[0]);
	cr->SetUInt32Value (UNIT_FIELD_BASEATTACKTIME+1, ct->Attack[1]);
	cr->SetFloatValue (UNIT_FIELD_BOUNDINGRADIUS, ct->BoundingRadius);

	objmgr.AddObject( cr );
	cr->PlaceOnMap();
	cr->AddToWorld();

	return cr;
}

Player*
ChatHandler::getSelectedChar(WorldSession *client)
{
    uint64 guid;
    Player *chr;

    guid = client->GetPlayer()->GetSelection();
    if (guid == 0)
        chr = client->GetPlayer(); // autoselect
    else
        chr = objmgr.GetObject<Player>(guid);

    return chr;
}

Object*
ChatHandler::getSelectedObj(WorldSession *client)
{
    uint64 guid;
    Object *obj;

    guid = client->GetPlayer()->GetSelection();
    obj = objmgr.GetObject<DynamicObject>(guid);

    return obj;
}
