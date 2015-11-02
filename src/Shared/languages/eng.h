#ifndef SERVER_LANGUAGE_H
#define SERVER_LANGUAGE_H

#define TOSTR(n) #n

/******************************
 ** Commands related strings **
 ******************************/
#define MAKEMODGSTR(a) "You changed " TOSTR(a) " of %s to %i/%i."
#define MAKEMODRSTR(a) "%s changed your " TOSTR(a) " to %i/%i."
#define MAKESMODGSTR(a) "You set the " TOSTR(a) " speed of %s to %2.2f."
#define MAKESMODRSTR(a) "%s set your " TOSTR(a) " speed to %2.2f."

#	define LANG_CMD_MOD_HEALTH MAKEMODGSTR(Health)
#	define LANG_CMD_MOD_HEALTHR MAKEMODRSTR(Health)
#	define LANG_CMD_MOD_MANA MAKEMODGSTR(Mana)
#	define LANG_CMD_MOD_MANAR MAKEMODRSTR(Mana)
#	define LANG_CMD_MOD_ENER MAKEMODGSTR(Energy)
#	define LANG_CMD_MOD_ENERR MAKEMODRSTR(Energy)
#	define LANG_CMD_MOD_RAGE MAKEMODGSTR(Rage)
#	define LANG_CMD_MOD_RAGER MAKEMODRSTR(Rage)
#	define LANG_CMD_MOD_LVL MAKEMODGSTR(Level)
#	define LANG_CMD_MOD_LVLR MAKEMODRSTR(Level)
#	define LANG_CMD_MOD_SPEED_INCVAL "Incorrect value for speed (1..128 range allowed)."
#	define LANG_CMD_MOD_SPEED_G MAKESMODGSTR(move)
#	define LANG_CMD_MOD_SPEED_R MAKESMODRSTR(move)
#	define LANG_CMD_MOD_SWIM_G MAKESMODGSTR(swim)
#	define LANG_CMD_MOD_SWIM_R MAKESMODRSTR(swim)
#	define LANG_CMD_MOD_SIZE_G "You set the size of %s %2.2f."
#	define LANG_CMD_MOD_SIZE_R "%s sets your size to %2.2f."
#	define LANG_CMD_MOD_MOUNT_G "You give a mount to %s."
#	define LANG_CMD_MOD_MOUNT_R "%s gave you a mount."
#	define LANG_CMD_MOD_TALLMONEY_G "You took all money from %s (%d copper)."
#	define LANG_CMD_MOD_TALLMONEY_R "%s took all of your money (%d copper)."
#	define LANG_CMD_MOD_TMONEY_G "You take %i copper to %s."
#	define LANG_CMD_MOD_TMONEY_R "%s took from you %i copper."
#	define LANG_CMD_MOD_GMONEY_G "You give %i copper to %s."
#	define LANG_CMD_MOD_GMONEY_R "%s gave you %i copper."
#	define LANG_CMD_MOD_SPELL_INCS "You should select player to teach spell."
#	define LANG_CMD_MOD_SPELL_ALRD "Can't teach already known spell %d"
#	define LANG_CMD_MOD_SPELL_INCU "Can't unlearn unknown spell %d"
#	define LANG_CMD_MOD_SPELL_OKU "Unlearned spell %d"

#	define LANG_CMD_NPC_SIZE_INC "Incorrect size, must be between 0.01 and 128."
#	define LANG_CMD_NPC_SIZE_G "You set the size of NPC to %3.2f."
#	define LANG_CMD_NPC_INFO "Selected NPC GUID=%X, Entry=%d, Lvl=%d, Size=%.2f, "\
		"MoveType=%d, Faction=%d, NPCFlags=%X, Model=%d, Mount=%d, SpawnTime=%d..%d sec, "\
		"SpawnDist=%.1f m"
#	define LANG_CMD_NPC_INFOL "Location: map=%d, X=%.1f, Y=%.1f, Z=%.1f"
#	define LANG_CMD_NPC_GUID "NPC guid is: lowpart=%u, highpart=%X"
#	define LANG_CMD_NPC_NOSP "Can't spawn creature %d, template doesn't exist."
#	define LANG_CMD_NPC_MTYPE_INC "Incorrect value, use 0-random roam, 1-walk forth, 2-walk back, 3-loop forth, 4-loop back"
#	define LANG_CMD_NPC_MTYPE_SVD "New movement type %d saved."
#	define LANG_CMD_NPC_RUN_V "Incorrect value, use 0 or 1."
#	define LANG_CMD_NPC_RUN "Creature run state changed to %d."
#	define LANG_CMD_NPC_SPTIME_INC "Incorrect value for parameter, use anything from 1 second to 1 million seconds"
#	define LANG_CMD_NPC_SPTIME_CR "Spawn time changed to %d..%d, spawn timer reset."
#	define LANG_CMD_NPC_SPTIME_CH "Spawn time changed to %d..%d."
#	define LANG_CMD_NPC_SPDIST_INC "Bad value for distance, use values from 0 to 100 or change NPC roam type."
#	define LANG_CMD_NPC_SPDIST_CH "Creature roaming (spawning) distance changed to %.1f m"

#	define LANG_CMD_ACCT_ADD_E1 "Error: You need to be admin to create GM accounts !"
#	define LANG_CMD_ACCT_ADD_E2 "Error: Account [%s] already exists in database !"
#	define LANG_CMD_ACCT_ADD_OK "Done. Account [%s] with password [%s] and gm level [%d] added to the database."
#	define LANG_CMD_ACCT_BAN_E1 "Error: This character doesn't exist !"
#	define LANG_CMD_ACCT_BAN_OK "Done. %s's account is now banned from the server."

#	define LANG_CMD_NONE "There is no such command."
#	define LANG_CMD_NOHELP "There is no help for that command."
#	define LANG_CMD_UNK "Unknown command: %s"
#	define LANG_CMD_AVAIL "Available commands:"
#	define LANG_CMD_MHELP "Subcommands grouped by color and brackets. "\
		"Use |cffccccff.help cmd|r, or |cffccccff.help cmd subcmd|r to read short "\
		"command descriptions."
#	define LANG_CMD_ACLVL "Your access level is: %i"
#	define LANG_CMD_ONCOUNT "Number of users connected: %i"
#	define LANG_CMD_MOUNTLV "You must be at least level 10 to mount."
#	define LANG_CMD_MOUNTIN "You got a level %i mount at %i speed."
#	define LANG_CMD_PLRSAVE "Player saved."
#	define LANG_CMD_GMONL "Following GMs are currently online:"
#	define LANG_CMD_GMOFFL "There are no currently online GMs."
#	define LANG_CMD_BROADC "Server: %s"
#	define LANG_CMD_SUMMON "You are summoning %s."
#	define LANG_CMD_BSUMMON "You are being summoned by %s."
#	define LANG_CMD_TPTO "Teleporting to %s's location."

#	define LANG_CMD_NOPLR "Player (%s) does not exist or is not logged in."
#	define LANG_CMD_NOTIMPL "Not implemented."
#	define LANG_CMD_SSELEC "You should select a character or a creature."
#	define LANG_CMD_INCVAL "Incorrect values."
#	define LANG_CMD_NOCHAR "No character selected."
#	define LANG_CMD_INCVAL_LV "Incorrect value, keep Level in range 1..255."
#	define LANG_CMD_NOSELNPC "No selection, select NPC first."
#	define LANG_CMD_SHSELCR "You should select a creature."
#	define LANG_CMD_NOSEL "No selection."
#	define LANG_CMD_CF_VEN "Selected creature must have VENDOR NPC flag."
#	define LANG_CMD_BADMAP "Error: You tried to worldport in an inexistant map."
#	define LANG_CMD_GOBADGUID ".GOGUID %I64X - Unit, GameObj, Player or Corpse doesn't exist"
#	define LANG_CMD_KICK_ERR "Error: The player you wanted to kick doesn't exist or isn't logged in"
#	define LANG_CMD_KICK_OK "Done. %s was successfully kicked from this server."

#	define LANG_CMD_VALSVD "Value saved."
#	define LANG_CMD_ITEMADD "Item added."
#	define LANG_CMD_ADDITEM "Added item  %i to player %s."
#	define LANG_CMD_RVDITEM "%s added item %i to your backpack."
#	define LANG_CMD_ADDQITEM "Added items for Quest %i to %s."
#	define LANG_CMD_RVDQITEM "%s added items for Quest %i to your backpack."
#	define LANG_CMD_ALLTPG "%s knows all flight locations now."
#	define LANG_CMD_ALLTPR "%s opened for you all flight locations."
#	define LANG_CMD_NOTPG "%s has forgotten all his flight locations now."
#	define LANG_CMD_NOTPR "%s deleted all your known flight locations."
#	define LANG_CMD_GM_INVIS_ON "You are now invisible."
#	define LANG_CMD_GM_INVIS_OFF "You are now visible."
#	define LANG_CMD_GM_LEVEL_G "You change security level of %s to %i."
#	define LANG_CMD_GM_LEVEL_R "%s changed your security level to %i."


/**************************
 ** OpCodes Used Strings **
 **************************/
#	define LANG_OPCODE_NPVPSERV "PvP is not allowed on %s servers."

/*************************************
 ** World Strings + Console logging **
 *************************************/
#	define LANG_WORLD_NOBIND "CrFusion cannot bind to that port"
#	define LANG_WORLD_RSERVP "Logon Server started on port %d"
#	define LANG_WORLD_WSERVP "World Server started on port %d"
#	define LANG_WORLD_REALMR_PVP "PvP"
#	define LANG_WORLD_REALMR_PVE "PvE"
#	define LANG_WORLD_REALMR_RPN "PvE Normal"
#	define LANG_WORLD_REALMR_RPP "PvE PvP"
#	define LANG_WORLD_REALMR_NRM "Normal"
#	define LANG_WORLD_ENTERED "has entered the world."
#	define LANG_WORLD_SRVSTATS "|c8fff6420[Server Stats]|r\n|c8fff9920Uptime: %d\nTotal Accounts: %d\nTotal Chars: %d"

#endif