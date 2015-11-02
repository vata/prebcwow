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

void
WorldSession::HandleNameQueryOpcode( WorldPacket & recv_data )
{
    WorldPacket data;
    uint64 guid;

    recv_data >> guid;

    uint32 race = 0, gender = 0, cl = 0;
	std::string name = "<Error - No Name>";

    Player *pChar = objmgr.GetObject<Player>(guid);
    if (pChar == NULL)
    {
        if (!objmgr.GetPlayerNameByGUID(guid, name))
            sLog.outError( "No player name found for this guid" );

        // TODO: load race, class, sex, etc from db
    }
    else
    {
        race = pChar->GetRace();
        gender = pChar->GetGender();
        cl = pChar->GetClass();
        name = pChar->GetName();
    }

    sLog.outDebug( "Received CMSG_NAME_QUERY for: %s", name.c_str() );

    data.Initialize( SMSG_NAME_QUERY_RESPONSE );

    data << guid;
    data << name;
    data << race << gender << cl;

    SendPacket( &data );
}


void
WorldSession::HandleQueryTimeOpcode( WorldPacket & recv_data )
{
    WorldPacket data;
    data.Initialize( SMSG_QUERY_TIME_RESPONSE );
    data << (uint32)time(NULL);
    SendPacket( &data );
}


void
WorldSession::HandleCreatureQueryOpcode( WorldPacket & recv_data )
{
	WorldPacket data;
	uint32 entry;
	uint64 guid;
	CreatureTemplate *ci;

	recv_data >> entry;
	recv_data >> guid;
    
	Creature *unit = objmgr.GetObject<Creature>(guid);

	if (unit == NULL)
	{
		sLog.outDebug( "WORLD: HandleCreatureQueryOpcode - (%u) NO SUCH UNIT! (GUID: %u)", uint32(GUID_LOPART(guid)), guid );
        data.Initialize( SMSG_CREATURE_QUERY_RESPONSE );
        data << (uint32)0;
        data << (uint32)0;
        data << (uint32)0;
        data << (uint32)0;    
        data << (uint32)0;            
        data << (uint32)0;    
        data << (uint32)0;          
	    data << (uint32)0;     
	    data << (uint32)0;  
        data << (uint32)0;     
        data << (uint32)0;       
        data << (uint16)0;
        SendPacket( &data ); 		
		return;
	}

	ci = unit->GetCreatureTemplate();

	if (!ci)
	{
		sLog.outDebug( "WORLD: HandleCreatureQueryOpcode - (%u) NO CREATUREINFO! (GUID: %u)", uint32(GUID_LOPART(guid)), guid );
        data.Initialize( SMSG_CREATURE_QUERY_RESPONSE );
        data << (uint32)0;
        data << (uint32)0;
        data << (uint32)0;
        data << (uint32)0;    
        data << (uint32)0;            
        data << (uint32)0;    
        data << (uint32)0;          
	    data << (uint32)0;     
	    data << (uint32)0;  
        data << (uint32)0;     
        data << (uint32)0;       
        data << (uint16)0;
        SendPacket( &data ); 		
		return;
	}

	sLog.outDetail("WORLD: CMSG_CREATURE_QUERY '%s' - Entry: %u - GUID: %u.", ci->Name.c_str(), entry, guid);
    data.Initialize( SMSG_CREATURE_QUERY_RESPONSE );
    data << (uint32)entry;
    data << ci->Name.c_str();
    data << uint8(0) << uint8(0) << uint8(0);
	data << ci->Guild.c_str();    
	
	data << ci->Flags1;
	data << uint32(ci->Type);
	data << (uint32)ci->Family;
	data << (uint32)ci->Rank;
	data << (uint32)ci->Elite;
    data << (uint32)0; 
	data << ci->Model;

	data << (uint16)ci->Civilian;

	SendPacket( &data ); 


 /*   WorldPacket data;
    uint32 entry;
    uint64 guid;
    CreatureTemplate *ct;

    recv_data >> entry;
    recv_data >> guid;

    ct = objmgr.GetCreatureTemplate (entry);
    sLog.outDetail("WORLD: CMSG_CREATURE_QUERY '%s'", ct->Name.c_str());

    data.Initialize( SMSG_CREATURE_QUERY_RESPONSE );
    data << (uint32)entry;
    data << ct->Name.c_str();
    data << uint8(0) << uint8(0) << uint8(0);
    data << ct->Guild.c_str();	// Creature Guild
	data << ((Unit*)ct)->GetUInt32Value(UNIT_NPC_FLAGS);			// NPC Flags
	if ((ct->Type & 2) > 0)
        data << uint32(7);
	else
        data << uint32(0);
    data << ct->Type;			// Creature Type
    data << (uint32)ct->Family; // Family
    data << (uint32)ct->Elite;  // Elite Type
	data << (uint32)0;			// unknown (move before or after unknowns 3 and 4) don't know where exactly
    data << ct->Model;			// DisplayID
	
	data << (uint32)0;
	data << (uint32)0;
	data << (uint32)0;
	data << (uint32)0;

    SendPacket( &data );*/
}


void
WorldSession::HandleGameObjectQueryOpcode( WorldPacket & recv_data )
{
	WorldPacket data;
    data.Initialize( SMSG_GAMEOBJECT_QUERY_RESPONSE );
    uint32 entryID;
    uint64 guid;

    recv_data >> entryID;
    recv_data >> guid;

    sLog.outDetail("WORLD: CMSG_GAMEOBJECT_QUERY '%u'", guid);

    GameObject* gameObj = objmgr.GetObject<GameObject>(guid);
	GameobjectTemplate *goT = objmgr.GetGameobjectTemplate (entryID);
    if( goT == NULL )
    {
        sLog.outDebug( "Missing game object info for entry %d", entryID);    
        return; 
    }

    data << (uint32)(entryID);
	data << (uint32)goT->GType;
	data << (uint32)goT->Model;
	data << goT->Name.c_str();
    data << uint32(0);
	data << uint8(0);
    
	data << uint32(goT->Sound[0]); // sound0
    data << uint32(goT->Sound[1]); // sound1
    data << uint32(goT->Sound[2]); // sound2
    data << uint32(goT->Sound[3]); // sound3
    data << uint32(goT->Sound[4]); // sound4
    data << uint32(goT->Sound[5]); // sound5
    data << uint32(goT->Sound[6]); // sound6
    data << uint32(goT->Sound[7]); // sound7
    data << uint32(goT->Sound[8]); // sound8
    data << uint32(goT->Sound[9]); // sound9
	data << uint32(goT->Sound[10]);// sound10
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    data << uint32(0);
    
    data << uint16(0);
    data << uint8(gameObj->GetUInt32Value(GAMEOBJECT_STATE));

    SendPacket( &data );
}


void
WorldSession::HandleCorpseQueryOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received MSG_CORPSE_QUERY");
    Corpse *pCorpse;
    WorldPacket data;

    pCorpse = GetPlayer()->m_pCorpse; // objmgr.GetCorpseByOwner(GetPlayer());
    if(pCorpse)
    {
		data.Initialize(MSG_CORPSE_QUERY);
		data << uint8(0x01);
		data << uint32(0x00000001);
		data << GetPlayer()->m_pCorpse->GetPositionX();
		data << GetPlayer()->m_pCorpse->GetPositionY();
		data << GetPlayer()->m_pCorpse->GetPositionZ();
		data << uint32(0x00000001);
		SendPacket(&data);
    }
}


void
WorldSession::HandleNpcTextQueryOpcode( WorldPacket & recv_data )
{
    WorldPacket data;
    uint32 textID;
    uint32 uField0, uField1;
	std::string GossipStr;

    recv_data >> textID;
    sLog.outDetail("WORLD: CMSG_NPC_TEXT_QUERY ID '%u'", textID );

    recv_data >> uField0 >> uField1;
    GetPlayer()->SetUInt32Value(UNIT_FIELD_TARGET, uField0);
    GetPlayer()->SetUInt32Value(UNIT_FIELD_TARGET + 1, uField1);

	std::stringstream ss;
	ss <<"SELECT * FROM npc_text WHERE ID="<< textID <<";";
	QueryResult *pGossip = sDatabase.Query(ss.str().c_str());
	
	if (pGossip)  {
		Field *Fields = pGossip->Fetch();
		uint32 Field = 0;
		data.Initialize( SMSG_NPC_TEXT_UPDATE );
		data << textID;

		for (int i=0; i<8; ++i)
		{
			data << Fields[ ++Field ].GetFloat();
			data << Fields[ ++Field ].GetString();

			if ( Fields[ Field+1 ].GetString() == "" )
			{
				data << Fields[ Field ].GetString();
				++Field;
			}
			else
				data << Fields[ ++Field ].GetString();

			data << Fields[ ++Field ].GetUInt32();

			for (int i=0; i<3; ++i)
			{
				data << Fields[ ++Field ].GetUInt32();
				data << Fields[ ++Field ].GetUInt32();
			}
		}

		SendPacket( &data );
		sLog.outDebug( "WORLD: Sent SMSG_NPC_TEXT_UPDATE" );
	}
}


void
WorldSession::HandlePageQueryOpcode( WorldPacket & recv_data )
{
    WorldPacket data;
    uint32 pageID;

    recv_data >> pageID;
    sLog.outDetail("WORLD: Received CMSG_PAGE_TEXT_QUERY for pageID '%u'", pageID);
	
	std::stringstream ss;

	while (pageID)
	{
		data.Initialize( SMSG_PAGE_TEXT_QUERY_RESPONSE );
		data << pageID;

		ss.clear();
		ss <<"SELECT text, nextpage FROM page_texts WHERE ID="<< pageID <<";";
		QueryResult *txtPage = sDatabase.Query( ss.str().c_str() );
		if (!txtPage) {
			std::stringstream res;
			res <<"PageText n°"<< pageID <<" seems to be missing from the DataBase.$B$BPlease inform the developers using a GM Ticket :)$B$BThanks.";
			data << res.str().c_str();
			data << uint32(0);
			pageID = 0;
		} else {
			data << (*txtPage)[0].GetString(); // Text
			pageID = (*txtPage)[1].GetUInt32(); // NextPage ID
			data << pageID;
		}
		SendPacket( &data );
	}
}
