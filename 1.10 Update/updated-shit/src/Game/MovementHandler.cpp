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

class MovementInfo
{
protected:
	friend class WorldSession;

	uint32 flags, time;
	uint64 unk1;
	float unk2, unk3, unk4, unk5;
	float unk6;
	uint32 FallTime;
	float unk8, unk9, unk10, unk11, unk12;
	public:
	float x, y, z, orientation;
	
	MovementInfo(WorldPacket &data)
	{
		data >> flags >> time;
		data >> x >> y >> z >> orientation;
		
		if (flags & 0x2000000) // Transport
		{
			data >> unk1 >> unk2 >> unk3 >> unk4 >> unk5;
		}
		if (flags & 0x200000) // Swimming
		{
			data >> unk6;
		}
		if (flags & 0x2000) // Falling
		{
			data >> FallTime >> unk8 >> unk9 >> unk10 >> unk11;
		}
		if (flags & 0x4000000)
		{
			data >> unk12;
		}
	}
	
	MovementInfo &operator >>(WorldPacket &data)
	{
		data << flags << time;
		data << x << y << z << orientation;
		
		if (flags & 0x2000000) // Transport
		{
			data << unk1 << unk2 << unk3 << unk4 << unk5;
		}
		if (flags & 0x200000) // Swimming
		{
			data << unk6;
		}
		if (flags & 0x2000) // Falling
		{
			data << FallTime << unk8 << unk9 << unk10 << unk11;
		}
		if (flags & 0x4000000)
		{
			data << unk12;
		}
		return *this;
	}
};

void WorldSession::HandleMoveHeartbeatOpcode( WorldPacket & recv_data )
{
    uint32 flags, time;
    float x, y, z, orientation;

    recv_data >> flags >> time;
    recv_data >> x >> y >> z >> orientation;

    if( GetPlayer() && !GetPlayer( )->SetPosition(x, y, z, orientation) )
    {
		GetPlayer( )->TeleportNear( GetPlayer()->GetPositionX(),
									GetPlayer()->GetPositionY(),
									GetPlayer()->GetPositionZ() );
    }

    /*WorldPacket data;
    data.Initialize( MSG_MOVE_HEARTBEAT );
    data << GetPlayer()->GetGUID();
    data << flags << time;
    data << x << y << z << orientation;
	SendPacket(&data);*/
}
/*void WorldSession::HandleMoveHeartbeatOpcode( WorldPacket & recv_data )
{
	MovementInfo mi(recv_data);

	Player *player = GetPlayer();

	if( player ) {
		if( player->m_falldetect_time != 0 ) {
			uint32	dt = mi.time - player->m_falldetect_time;
			float	dz = player->m_falldetect_z - mi.z;
			float	speed = dt? dz * 1000.0f / dt: 0;

			player->m_falldetect_speed = speed;
			//sLog.outDebug( "Fall Damage Detect: dt=%d, dz=%.1f speed=%.1f", dt, dz, speed );
		}
		player->m_falldetect_z = mi.z;
		player->m_falldetect_time = mi.time;
	}

	player->RemoveFromWorld();
	bool setpos = player->SetPosition(mi.x, mi.y, mi.z, mi.orientation);
	player->AddToWorld();
    if( player && ! setpos )
    {
        WorldPacket movedata;

        player->BuildTeleportAckMsg(&movedata, player->GetPositionX(),
            player->GetPositionY(), player->GetPositionZ(), player->GetOrientation() );

        SendPacket(&movedata);
    }

	float dx = player->GetPositionX() - player->m_motionTrackX;
	float dy = player->GetPositionY() - player->m_motionTrackY;
	float dz = player->GetPositionZ() - player->m_motionTrackZ;
	float sqDist = (dx*dx)+(dy*dy)+(dz*dz);

	if (sqDist < 40.0f * 40.0f)
		player->m_mapMgr->ChangeObjectLocation (player, player->m_motionTrackX, player->m_motionTrackY);

	player->motiontrack_ReadPosition();

	WorldPacket data;
    data.Initialize( MSG_MOVE_HEARTBEAT );

    data << GetPlayer()->GetGUID();
	mi >> data;

    GetPlayer( )->SendMessageToSet(&data, false);
}*/

void
WorldSession::HandleMoveWorldportAckOpcode( WorldPacket & recv_data )
{
    sLog.outDebug( "WORLD: got MSG_MOVE_WORLDPORT_ACK." );

    GetPlayer()->PlaceOnMap();
	GetPlayer( )->TeleportNear( GetPlayer()->GetPositionX(),
								GetPlayer()->GetPositionY(),
								GetPlayer()->GetPositionZ() );
}

void
WorldSession::HandleMovementFall( WorldPacket & recv_data )
{
    uint32 flags, time, FallTime, damage;
    float x, y, z, orientation;
    uint64 guid;

    recv_data >> flags >> time;
    recv_data >> x >> y >> z >> orientation;
    recv_data >> FallTime;
    if ( GetPlayer()->isAlive() && FallTime > 1000 )
    {
        guid = GetPlayer()->GetGUID();
        damage = (uint32)((FallTime-900)/96)+1;
        
        WorldPacket data;
        data.Initialize(SMSG_ENVIRONMENTALDAMAGELOG);
        data << guid;
        data << (uint8)DAMAGE_FALL;
        data << damage;
		GetPlayer()->TakeDamage(damage);
        SendPacket(&data);
    }
}

void
WorldSession::HandleMovementOpcodes( WorldPacket & recv_data )
{
	MovementInfo mi(recv_data);
	Player *player = GetPlayer();

    if (player)
	{
		player->RemoveFromWorld();
		bool setpos = player->SetPosition(mi.x, mi.y, mi.z, mi.orientation);
		player->AddToWorld();

		if (! setpos)
		{
	        WorldPacket movedata;
		    player->BuildTeleportAckMsg (&movedata, player->GetPositionX(),
			    player->GetPositionY(), player->GetPositionZ(), player->GetOrientation() );

			SendPacket(&movedata);
		}

		float dx = player->GetPositionX() - player->m_motionTrackX;
		float dy = player->GetPositionY() - player->m_motionTrackY;
		float dz = player->GetPositionZ() - player->m_motionTrackZ;
		float sqDist = (dx*dx)+(dy*dy)+(dz*dz);

		if (sqDist < 1600.0f) //40.0f * 40.0f
			player->m_mapMgr->ChangeObjectLocation (player, player->m_motionTrackX, player->m_motionTrackY);

		player->motiontrack_ReadPosition();

		WorldPacket data;
		data.Initialize( recv_data.GetOpcode() );
		//data << GetPlayer()->GetGUID();
        GetPlayer()->PackGuidToWP(&data);
		mi >> data;
		player->SendMessageToSet(&data, false);

		if(player->isDueling())
		{
			GameObject* dFlag = player->GetDuelFlag();
			if (dFlag)
			{
				float
					cx = (dFlag->GetPositionX() - player->GetPositionX()),
					cy = (dFlag->GetPositionY() - player->GetPositionY()),
					Fdist = (cx*cx)+(cy*cy);

				if(Fdist > 16*16)
				{
					sLog.outDebug("DUEL: Sent SMSG_DUEL_OUTOFBOUNDS");
					WorldPacket data;
					data.Initialize(SMSG_DUEL_OUTOFBOUNDS);
					data << (uint64)45000;
					SendPacket(&data);
				}
			}
		}
		if(player->isAddingWP())
		{
			if(player->isTimeToAddWP())
			{
				PathPoint currWP;
				currWP.x = player->GetPositionX();
				currWP.y = player->GetPositionY();
				currWP.z = player->GetPositionZ();
				player->m_LastAddedWP = currWP;
					
				sDatabase.PExecute("INSERT INTO creatures_mov(id,creatureId,X,Y,Z,WaitTime1,WaitTime2) VALUES(NULL, %d, %f, %f, %f, %d, %d);",
					player->m_eWP_Settings[0],
					currWP.x, currWP.y, currWP.z,
					player->m_eWP_Settings[1],
					player->m_eWP_Settings[2]);
				SystemMessage("EasyWP: WayPoint Added [%6.2f %6.2f %6.2f]");
			}
		}
    }
}

void
WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recv_data)
{
    uint32 guild, time;
    recv_data >> guild >> time;
}

void
WorldSession::HandleAreatriggerOpcode( WorldPacket & recv_data )
{
	// Most of these triggers are Inns, others are capitals.
	// total : 36 entries ATM
	static uint32 TTriggers[] = {
	71/*Sentinel Hill Inn - Westfall*/,562/*Lion's Pride - Goldshire*/,682/*Lakeshire - Redridge Mountains*/,
	707/*Darkshire Scarlet Raven - Duskwood*/,712/*Stourlager - Loch Modan*/,715/*Dolanaar - Teldrassil*/,
	716/*Auderdine - Darkshore*/,717/*Astranaar - Ashenvale*/,720/*The Sepulcher - Silverpine Forest*/,
	721/*Tarren Mill - HillbardFoothills*/,722/*Bloodhoof Village - Mulgore*/,743/*Ratchet - The Barrens*/,
	843/*Razor Hill - Durotar*/,844/*Stonard - Swamp of Sorows*/,982/*Camp Taurajo - The Barrens*/,
	1023/*Gadgetzan - Tanaris*/,1024/*Feathermoon Stronghold - Feralas*/,1025/*Camp Mojache - Feralas*/,
	2266/*Nijel's Point - Desolace*/,2267/*Shadowprey Village - Desolace*/,2286/*Freewind Post - Thousand Needles*/,
	2287/*Everlook - Winterspring*/
	};
	static QTrigger QTriggers[] =
	{
		{    87,   76},
		{    88,   62},
		{   192,   62},
		{   230,  954},
		{   238,  984},
		{   342,   76},
		{   362, 1448},
		{  1103,  578},
		{     0,    0}
	};
	Player *cPlayer =GetPlayer();
	Quest  *pQuest  =NULL;
	uint32 triggerID;
	recv_data >> triggerID;

	sLog.outDebug( "WORLD: Received CMSG_AREATRIGGER {%d}", triggerID);
	sChatHandler.GMMessage( this, "GM: Activated AreaTrigger {%d}.", triggerID );

	for(int i=0; i<8; ++i)
	{
		if(QTriggers[i].TriggerId == triggerID)
		{
			pQuest = objmgr.GetQuest( QTriggers[i].QuestId );
			break;
		}

	}

	sQScriptBackend.scriptCallAreaTrigger( GetPlayer(), pQuest, triggerID );

	std::stringstream ss;
	ss << "SELECT TargetPosX, TargetPosY, TargetPosZ, TargetOrientation, TargetMapID FROM areatrigger WHERE triggerID=" << triggerID;
	QueryResult *result = sDatabase.Query( ss.str().c_str() );
	if(result)
    {
		float TargetPosX, TargetPosY, TargetPosZ, TargetOrientation;
		uint32 TargetMapID;
		Field* fields = result->Fetch();
		TargetPosX = fields[0].GetFloat();
		TargetPosY = fields[1].GetFloat();
		TargetPosZ = fields[2].GetFloat();
		TargetOrientation = fields[3].GetFloat();
		TargetMapID = fields[4].GetUInt32();

		cPlayer->TeleportFar(TargetMapID, TargetPosX, TargetPosY, TargetPosZ, TargetOrientation);

		delete result;
		return;
	}

	for(int i=0; i<36; ++i)
	{
		if(TTriggers[i] == triggerID)
			if(!GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAG_RESTING))
				GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAG_RESTING);
	}
}
