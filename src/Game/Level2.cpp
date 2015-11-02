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

///////////////////////////////////////////////
//  Admin Movement Commands
//

bool
ChatHandler::Command_NPC_GUID (const char* args)
{
    WorldPacket data;

    uint64 guid;
    guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
        FillSystemMessageData(&data, m_session, LANG_CMD_NOSEL);
        m_session->SendPacket( &data );
        return true;
    }

	m_session->SystemMessage(LANG_CMD_NPC_GUID, GUID_LOPART(guid), GUID_HIPART(guid));
    return true;
}

bool
ChatHandler::HandleInvisCommand (const char* args) 
{
	Player *p = m_session->GetPlayer();
	if (p->m_gmInvisible) {
		p->m_gmInvisible = false;
		m_session->SystemMessage (LANG_CMD_GM_INVIS_OFF);
		
		p->AddToWorld();
	} else {
		p->m_gmInvisible = true;
		m_session->SystemMessage (LANG_CMD_GM_INVIS_ON);

		WorldPacket data;
		data.Initialize(SMSG_DESTROY_OBJECT);
		data << p->GetGUID();
		p->SendMessageToSet(&data, false);
	}
	return true;
}

bool
ChatHandler::HandleItemMoveCommand(const char* args)
{
    uint8 srcslot, dstslot;

    char* pParam1 = strtok((char*)args, " ");
    if (!pParam1) return false;

    char* pParam2 = strtok(NULL, " ");
    if (!pParam2) return false;

    srcslot = (uint8)hex_or_decimal(pParam1);
    dstslot = (uint8)hex_or_decimal(pParam2);

    Item *dstitem = m_session->GetPlayer()->GetItemBySlot(dstslot);
    Item *srcitem = m_session->GetPlayer()->GetItemBySlot(srcslot);

    m_session->GetPlayer()->SwapItemSlots(srcslot, dstslot);

    return true;
}

bool
ChatHandler::Command_NPC_Add (const char* args)
{
	uint32 Entry = hex_or_decimal(args);
	if (!Entry) return false;

	CreatureTemplate *ct = objmgr.GetCreatureTemplate (Entry, false);
	if (ct != NULL)
		SpawnCreature (m_session, ct);
	else
		m_session->SystemMessage (LANG_CMD_NPC_NOSP, Entry);

	return true;
}

bool
ChatHandler::Command_NPC_Delete (const char* args)
{
	// Just in case, clear waypoint indicators
	Command_WP_Hide (NULL);

    WorldPacket data;

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
		m_session->SystemMessage (LANG_CMD_NOSEL);
        return true;
    }

    Creature *unit = objmgr.GetObject<Creature>(guid);
    if(!unit)
    {
		m_session->SystemMessage (LANG_CMD_NOSEL);
        return true;
    }

	data.Initialize (SMSG_DESTROY_OBJECT);
	data << unit->GetGUID();
	m_session->SendPacket  (&data);
	unit->SendMessageToSet (&data, true);

	
	if (unit->GetMapCell())
        unit->GetMapCell()->RemoveObject (unit);
	
	unit->RemoveFromMap();
	unit->RemoveFromWorld();

    unit->DeleteFromDB();
    objmgr.RemoveObject_Free(unit);

    return true;
}

bool
ChatHandler::Command_NPC_Sell (const char* args)
{
    WorldPacket data;

    char* pitem = strtok((char*)args, " ");
    if (!pitem) return false;

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
        m_session->SystemMessage (LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature)
	{
		m_session->SystemMessage (LANG_CMD_SHSELCR);
		return true;
	}

	if ((uint32)0 == (pCreature->GetUInt32Value (UNIT_NPC_FLAGS) & (uint32)UNIT_NPC_FLAG_VENDOR))
    {
        m_session->SystemMessage (LANG_CMD_CF_VEN);
        return true;
    }

    uint32 item = hex_or_decimal (pitem);;
    int amount = -1;

    char* pamount = strtok(NULL, " ");
    if (pamount)
        amount = atoi(pamount);

    char sql[512];
    sprintf(sql, "INSERT INTO vendors VALUES ('%u', '%i', '%i')", GUID_LOPART(guid), item, amount);
    sDatabase.Execute( sql );

    CreatureItem citem;
	citem.itemid = (int)item;
    citem.amount = amount;
    pCreature->item_list.push_back (citem);

    FillSystemMessageData(&data, m_session, LANG_CMD_ITEMADD);
    m_session->SendPacket( &data );

    return true;
}

bool
ChatHandler::Command_NPC_MType (const char* args)
{
    if(!*args)
        return false;

    int option = atoi((char*)args);

    if (option < 0 && option > 4) {
        m_session->SystemMessage (LANG_CMD_NPC_MTYPE_INC);
        return true;
    }

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0) {
        m_session->SystemMessage (LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
    if (!pCreature) {
        m_session->SystemMessage (LANG_CMD_SHSELCR);
        return true;
    }

    char sql[512];
    sprintf(sql, "UPDATE creatures SET moveType = '%i' WHERE id = '%u'", option, GUID_LOPART(guid));
    sDatabase.Execute( sql );

    //pCreature->setMoveRandomFlag (option == 0);
	pCreature->m_movementType = (Creature::MovementType)option;
    
	m_session->SystemMessage (LANG_CMD_NPC_MTYPE_SVD, option);

    return true;
}

bool
ChatHandler::Command_NPC_Run (const char* args)
{
    if(!*args) return false;
    int option = atoi((char*)args);

    if(option != 0 && option != 1) {
        m_session->SystemMessage (LANG_CMD_NPC_RUN_V);
        return true;
    }

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0) {
        m_session->SystemMessage (LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
    if(!pCreature) {
        m_session->SystemMessage (LANG_CMD_NOSELNPC);
        return true;
    }

	std::stringstream	ss;
    ss << "UPDATE creatures SET running=" << option << " WHERE id=" << GUID_LOPART(guid);
    sDatabase.Execute (ss.str().c_str());

    pCreature->setMoveRunFlag (option > 0);
    m_session->SystemMessage (LANG_CMD_NPC_RUN, option);

    return true;
}

bool
ChatHandler::Command_NPC_SpawnTime (const char* args)
{
	int time1 = 0,
		time2 = 0;

	if (*args) {
		char args1[512];
		strncpy (args1, args, sizeof (args1)-1); args1[sizeof (args1)-1] = '\x00';

		// read argument 1
		char *p = strtok (args1, " ");
		time1 = *p? atoi(p): time1;

		// read if exists - argument2, or else arg2 = arg1
		p = strtok (NULL, " ");
		time2 = p && *p? atoi(p): time1;

		// Make arg1 always <= arg2
		if (time1 > time2) {
			int t = time1; time1 = time2; time2 = t;
		}
	}
	else
		return false;

	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSEL);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	if (time1 < 1 || time1 > 1000000) {
		m_session->SystemMessage (LANG_CMD_NPC_SPTIME_INC);
		return true;
	}

	if (time2 < 1 || time2 > 1000000) {
		m_session->SystemMessage (LANG_CMD_NPC_SPTIME_INC);
		return true;
	}

	std::stringstream	ss;
	ss << "UPDATE creatures SET spawnTime1=" << time1 << ", spawnTime2=" << time2
		<< " WHERE id=" << GUID_LOPART(guid);
	sDatabase.Execute (ss.str().c_str());

	if (pCreature->m_respawnTimer > 0) {
		pCreature->ResetRespawnTimer (time1, time2);
		m_session->SystemMessage (LANG_CMD_NPC_SPTIME_CR, time1, time2);
	} else {
		pCreature->m_spawnTime[0] = time1;
		pCreature->m_spawnTime[1] = time2;
		m_session->SystemMessage (LANG_CMD_NPC_SPTIME_CH, time1, time2);
	}

	return true;
}

bool
ChatHandler::Command_NPC_SpawnDistance (const char* args)
{
	if(!*args) return false;
	float dist = (float)atof((char*)args);

	if (dist < 0 || dist > 100) {
		m_session->SystemMessage (LANG_CMD_NPC_SPDIST_INC);
		return true;
	}

	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSEL);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	std::stringstream	ss;
	ss << "UPDATE creatures SET spawnDist=" << dist << " WHERE id=" << GUID_LOPART(guid);
	sDatabase.Execute (ss.str().c_str());

	pCreature->m_spawnDist = dist;
	m_session->SystemMessage (LANG_CMD_NPC_SPDIST_CH, dist);

	return true;
}

bool
ChatHandler::Command_NPC_Level (const char* args)
{
    if (!*args) return false;

    uint8 lvl = (uint8) atoi((char*)args);
    if ( lvl < 1 || lvl > 255)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
		m_session->SystemMessage(LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
    if(!pCreature)
    {
		m_session->SystemMessage(LANG_CMD_SHSELCR);
        return true;
    }

    pCreature->SetUInt32Value(UNIT_FIELD_HEALTH, 100 + 30*lvl);
    pCreature->SetUInt32Value(UNIT_FIELD_MAXHEALTH, 100 + 30*lvl);
    pCreature->SetLevel (lvl);

    pCreature->SaveToDB();

    return true;
}

bool
ChatHandler::Command_NPC_Flags (const char* args)
{
    if (!*args) return false;

    uint32 npcFlags = (uint32) atoi((char*)args);
    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
		m_session->SystemMessage(LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
    if(!pCreature)
    {
		m_session->SystemMessage(LANG_CMD_SHSELCR);
        return true;
    }

    pCreature->SetUInt32Value(UNIT_NPC_FLAGS , npcFlags);
    pCreature->SaveToDB();

	m_session->SystemMessage(LANG_CMD_VALSVD);

    return true;
}

bool
ChatHandler::Command_NPC_Model (const char* args)
{
    if (!*args) return false;

    uint32 displayId = (uint32) atoi((char*)args);
    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid == 0)
    {
		m_session->SystemMessage(LANG_CMD_NOSEL);
        return true;
    }

    Creature * pCreature = objmgr.GetObject<Creature>(guid);
    if(!pCreature)
    {
        m_session->SystemMessage(LANG_CMD_SHSELCR);
        return true;
    }

    pCreature->SetUInt32Value(UNIT_FIELD_DISPLAYID, displayId);
	pCreature->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, displayId);
    pCreature->SaveToDB();

	m_session->SystemMessage(LANG_CMD_VALSVD);
    return true;
}

bool
ChatHandler::Command_NPC_Faction (const char* args)
{
	if (!*args) return false;

	uint32 factionId = (uint32) atoi((char*)args);
	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSEL);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_SHSELCR);
		return true;
	}

	pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE , factionId);
	pCreature->SaveToDB();

	m_session->SystemMessage(LANG_CMD_VALSVD);
	return true;
}

bool
ChatHandler::Command_NPC_ListHate (const char* args)
{
	if (!*args) return false;

	///uint32 factionId = (uint32) atoi((char*)args);

	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSEL);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_SHSELCR);
		return true;
	}

	for (TargetMap::iterator iter = pCreature->m_targets.begin();
		iter != pCreature->m_targets.end(); iter++)
	{
		Unit * u = iter->first;
		m_session->SystemMessage ("GUID %X, hate: %.1f", 
			u->GetGUIDLow(), iter->second);
	}

	return true;
}

bool
ChatHandler::Command_Account_Add (const char* args)
{
	if(!*args) return false;
	char acct[512], *login, *password, *temp;
	std::stringstream ss;
	uint32 gm_lvl;
	strncpy (acct, args, sizeof(acct)-1); acct[sizeof(acct)-1] = '\x00';

	temp = strtok(acct, " ");
	login = temp;
	temp = strtok (NULL, " ");
	password = temp;
	temp = strtok (NULL, " ");
	if(!temp)
		gm_lvl = 0;
	else
		gm_lvl = atoi((const char*)temp);

	if((m_session->GetSecurity() < 3) && (gm_lvl > 0))
	{
		m_session->SystemMessage(LANG_CMD_ACCT_ADD_E1);
		return false;
	}
	ss << "SELECT * FROM accounts WHERE login='" << login << "';";
	QueryResult *result = sDatabase.Query(ss.str().c_str());

	if(result)
	{
		m_session->SystemMessage(LANG_CMD_ACCT_ADD_E2, login);
		return false;
	}

	ss.clear();
	ss <<"INSERT INTO accounts(login, password, gm) VALUES('"<< login <<"', '"<< password <<"', "<< gm_lvl <<");";
	sDatabase.Execute(ss.str().c_str());
	m_session->SystemMessage(LANG_CMD_ACCT_ADD_OK, login, password, gm_lvl);
	return true;
}

bool
ChatHandler::Command_Account_Del (const char* args)
{




return false;

}

bool
ChatHandler::Command_Account_Ban (const char* args)
{
	if(!*args) return false;

    Player *chr = objmgr.GetPlayer((char*)args);
	if(!chr)
	{
		m_session->SystemMessage(LANG_CMD_ACCT_BAN_E1);
		return false;
	}

	std::stringstream ss;
	ss <<"UPDATE accounts SET banned=1 WHERE acct="<< chr->GetSession()->GetAccountId() <<";";
	sDatabase.Execute(ss.str().c_str());

	m_session->SystemMessage(LANG_CMD_ACCT_BAN_OK, args);
	return true;
}

bool
ChatHandler::HandleKickCommand(const char* args)
{
	Player *chr = NULL;
	if(!*args)
		chr = objmgr.GetObject<Player>(m_session->GetPlayer()->GetSelection());
	else
		chr = objmgr.GetPlayer((char*)args);
	if(!chr)
	{
		m_session->SystemMessage(LANG_CMD_KICK_ERR);
		return false;
	}
	chr->GetSession()->Kick();
	m_session->SystemMessage(LANG_CMD_KICK_OK, chr->GetName());

	return true;
}
