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

/////////////////////////////////////////////////
//  Normal User Chat Commands
//

bool
ChatHandler::ShowHelpForCommand(ChatCommand *table, const char* cmd)
{
    for(uint32 i = 0; table[i].Name != NULL; ++i)
    {
        if(!hasStringAbbr(table[i].Name, cmd))
            continue;
        if(m_session->GetSecurity() < table[i].SecurityLevel)
            continue;

        if(table[i].ChildCommands != NULL)
        {
            cmd = strtok(NULL, " ");
            if(cmd && ShowHelpForCommand(table[i].ChildCommands, cmd))
                return true;
        }

        if(table[i].Help == "")
        {
			m_session->SystemMessage(LANG_CMD_NOHELP);
            return true;
        }

        SendMultilineMessage(table[i].Help.c_str());

        return true;
    }

    return false;
}

bool
ChatHandler::HandleHelpCommand(const char* args)
{
    ChatCommand *table = getCommandTable();

    if(!*args)
        return false;

    char* cmd = strtok((char*)args, " ");
    if(!cmd)
        return false;

    if(!ShowHelpForCommand(getCommandTable(), cmd))
        m_session->SystemMessage(LANG_CMD_UNK, cmd);

    return true;
}

bool
ChatHandler::Command_Commands (const char* args)
{
    ChatCommand *table = getCommandTable();

	m_session->SystemMessage (LANG_CMD_AVAIL);

	std::string	msg;

    for(uint32 i = 0; table[i].Name != NULL; ++i)
    {
        if(*args && !hasStringAbbr(table[i].Name, (char*)args))
            continue;
        if(m_session->GetSecurity() < table[i].SecurityLevel)
            continue;

		// Format command help
		msg += "|cffcccccc";
		msg += table[i].Name;

		ChatCommand * child = table[i].ChildCommands;
		if (child != NULL) {
			msg += " (|cffccccff";

			for (uint32 q = 0; child[q].Name != NULL; q++)
			{
				msg += child[q].Name;
				if (child[q+1].Name != NULL)
					msg += ", ";

				// Flush too long lines
				if (msg.size() > 200) {
					m_session->SystemMessage ((char *)msg.c_str());
					msg = "|cffccccff";
				}
			}
			msg += "|cffcccccc)";
		}

		if (table[i+1].Name != NULL)
			msg += ", ";

		// Flush too long lines
		if (msg.size() > 254) {
			m_session->SystemMessage ((char *)msg.c_str());
			msg = "|cffcccccc";
		}
    }

	// Flush the rest
	if (msg.size()) {
		msg += ".";
		m_session->SystemMessage ((char *)msg.c_str());
	}
	m_session->SystemMessage (LANG_CMD_MHELP);
    return true;
}

bool
ChatHandler::HandleVersionCommand(const char* args)
{
	m_session->SystemMessage(FULLSERVERNAME);
	return true;
}

bool
ChatHandler::HandleAcctCommand(const char* args)
{
	m_session->SystemMessage(LANG_CMD_ACLVL, m_session->GetSecurity());
    return true;
}

bool
ChatHandler::HandleStartCommand(const char* args)
{
    Player *chr = m_session->GetPlayer();
    chr->SetUInt32Value(PLAYER_FARSIGHT, 0x01);

	switch (chr->GetRace())
	{
		case RACE_HUMAN:		m_session->GetPlayer()->TeleportFar (0, -8949.95, -132.493, 83.5312); break;
		case RACE_ORC:			m_session->GetPlayer()->TeleportFar (1, -618.518, -4251.67, 38.718); break;
		case RACE_DWARF:		m_session->GetPlayer()->TeleportFar (0, -6240.32, 331.033, 382.758); break;
		case RACE_NIGHT_ELF:	m_session->GetPlayer()->TeleportFar (1, 10311.3, 832.463, 1326.41); break;
		case RACE_UNDEAD:		m_session->GetPlayer()->TeleportFar (0, 1676.35, 1677.45, 121.67); break;
		case RACE_TAUREN:		m_session->GetPlayer()->TeleportFar (1, -2917.58, -257.98, 52.9968); break;
		case RACE_GNOME:		m_session->GetPlayer()->TeleportFar (0, -6240.32, 331.033, 382.758); break;
		case RACE_TROLL:		m_session->GetPlayer()->TeleportFar (1, -618.518, -4251.67, 38.718); break;
	}

	return true;
}

bool
ChatHandler::HandleInfoCommand(const char* args)
{
    uint32 clientsNum = sWorld.GetSessionCount();
	m_session->SystemMessage(LANG_CMD_ONCOUNT, (int) clientsNum);

    return true;
}

bool
ChatHandler::HandleNYICommand(const char* args)
{
	m_session->SystemMessage(LANG_CMD_NOTIMPL);

    return true;
}

bool
ChatHandler::HandleMountCommand(const char* args)
{
    uint8	theLevel = m_session->GetPlayer()->GetLevel(),
			theRace = m_session->GetPlayer()->GetRace(); // get level
    uint16 mId=1147;
    uint32 num=0;
    float speed = (float)8;

    if (theLevel < 10 )
    {
		m_session->SystemMessage(LANG_CMD_MOUNTLV);
        return true;
    }
    else
    {
        char* pMount = strtok((char*)args, " ");
        if( pMount )
        {
            num = atoi(pMount);
            switch(num)
            {
            case 1: break; //nothing to do, min lvl mount lvl 10, lol
            case 2:
                if(theLevel<15) num=1;
                break;
            case 3:
                if(theLevel<20)
                    if(theLevel<15) num=1;
					else num=2;
                break;
            default:
                return true;
            }
        }
        else
        {
            if(theLevel>19)
                num=3;
            else
                if(theLevel>14)
                    num=2;
                else
                    num=1;
        }
        if (num > 2 )
        {
            switch(theRace)
            {
            case 1: //HUMAN
                mId=1147;
                break;
            case 2: //ORC
                mId=295;
                break;
            case 3: //DWARF
                mId=1147;
                break;
            case 4: //NIGHT ELF
                mId=479;
                break;
            case 5: //UNDEAD
                mId=1147; //need to change
                break;
            case 6: //TAUREN
                mId=295;
                break;
            case 7: //GNOME
                mId=1147;
                break;
            case 8: //TROLL
                mId=479;
                break;
            }
        }
        else if (num > 1 )
        {
            switch(theRace)
            {
            case 1: //HUMAN
                mId=1531;
                break;
            case 2: //ORC
                mId=207; //need to change
                break;
            case 3: //DWARF
                mId=2786;
                break;
            case 4: //NIGHT ELF
                mId=720;
                break;
            case 5: //UNDEAD
                mId=2346;
                break;
            case 6: //TAUREN
                mId=180;
                break;
            case 7: //GNOME
                mId=1147; //need to change
                break;
            case 8: //TROLL
                mId=1340;
                break;
            }
        }
        else
        {
            switch(theRace)
            {
            case 1: //HUMAN
                mId=236;
                break;
            case 2: //ORC
                mId=207;
                break;
            case 3: //DWARF
                mId=2186;
                break;
            case 4: //NIGHT ELF
                mId=632;
                break;
            case 5: //UNDEAD
                mId=5050;
                break;
            case 6: //TAUREN
                mId=1220;
                break;
            case 7: //GNOME
                mId=748; //need to change
                break;
            case 8: //TROLL
                mId=2320;
                break;
            }
        }
    }

    m_session->GetPlayer( )->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , mId);
    m_session->GetPlayer( )->SetUInt32Value( UNIT_FIELD_FLAGS , UNIT_FLAG_MOUNTED );

    if (theLevel < 60)	speed = 1.60f;
    else				speed = 2.00f;

	m_session->GetPlayer( )->SetSpeedMod (speed);
	m_session->SystemMessage(LANG_CMD_MOUNTIN, num, (int)speed);

    return true;
}

bool
ChatHandler::HandleDismountCommand(const char* args)
{
    WorldPacket data;

    m_session->GetPlayer( )->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID , 0);
    m_session->GetPlayer( )->RemoveFlag( UNIT_FIELD_FLAGS, 0x002000 );

    // Remove the "player locked" flag, to allow movement
    if (m_session->GetPlayer( )->GetUInt32Value(UNIT_FIELD_FLAGS) & UNIT_FLAG_LOCKED )
        m_session->GetPlayer( )->RemoveFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_LOCKED );

    float dmspeed = 7.5f; // Exact value of normal player speed

    data.Initialize( SMSG_FORCE_RUN_SPEED_CHANGE );
    data << m_session->GetPlayer( )->GetUInt32Value( OBJECT_FIELD_GUID );
    data << m_session->GetPlayer( )->GetUInt32Value( OBJECT_FIELD_GUID + 1 );
    data << dmspeed;
    WPAssert(data.size() == 12);

    m_session->GetPlayer( )->SendMessageToSet( &data, true );

    return true;
}

bool
ChatHandler::HandleSaveCommand(const char* args)
{
    m_session->GetPlayer()->SaveToDB();
	m_session->SystemMessage(LANG_CMD_PLRSAVE);
    return true;
}

bool
ChatHandler::HandleGMListCommand(const char* args)
{
    bool first = true;
    ObjectMgr::PlayerMap::const_iterator itr;
    for (itr = objmgr.Begin<Player>(); itr != objmgr.End<Player>(); itr++)
    {
        if(itr->second->GetSession()->GetSecurity())
        {
            if(first)
            {
				m_session->SystemMessage(LANG_CMD_GMONL);
				first = false;
            }
           m_session->SystemMessage((char*)itr->second->GetName());
        }
    }

    if(first)
		m_session->SystemMessage(LANG_CMD_GMOFFL);

    return true;
}

bool
ChatHandler::HandleStatsCommand(const char* args)
{
	QueryResult *chresult = sDatabase.Query("SELECT COUNT(*) FROM characters");
    QueryResult *acresult = sDatabase.Query("SELECT COUNT(*) FROM accounts");
    Field *chfield = chresult->Fetch();
    Field *acfield = acresult->Fetch();
	int CharCount = chfield[0].GetUInt32();
	int AcctCount = acfield[0].GetUInt32();

	m_session->SystemMessage(LANG_WORLD_SRVSTATS, sWorld.GetUptime(), AcctCount, CharCount);
    return true;
}
