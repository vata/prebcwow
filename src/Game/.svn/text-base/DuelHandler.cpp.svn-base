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
WorldSession::HandleDuelAccepted( WorldPacket& recvPacket )
{
	sLog.outDebug ("WORLD: Received CMSG_DUEL_ACCEPTED");

	uint64 guid;
	Player
		*cPlayer = GetPlayer(),
		*oPlayer = cPlayer->GetDuelOpponent();
	WorldPacket data;

	recvPacket >> guid;

	data.Initialize(SMSG_DUEL_COUNTDOWN);
	data << (uint64)3000;
	SendPacket(&data);
	oPlayer->GetSession()->SendPacket(&data);
	cPlayer->m_Duel_timer = 3000;

	cPlayer->SetInDuel(true);
	oPlayer->SetInDuel(true);
}

void
WorldSession::HandleDuelCancelled( WorldPacket& recvPacket )
{
	sLog.outDebug ("WORLD: Received CMSG_DUEL_CANCELLED");

	uint64 guid;
	WorldPacket data;
	Player
		*cPlayer = GetPlayer(),
		*oPlayer = cPlayer->GetDuelOpponent();
	GameObject *pDuelArb = cPlayer->GetDuelFlag();

	recvPacket >> guid;

	if(pDuelArb)
	{
		data.Initialize(SMSG_DUEL_COMPLETE);
		data << (uint8)0;
		cPlayer->GetSession()->SendPacket(&data);
		oPlayer->GetSession()->SendPacket(&data);

		data.Initialize(SMSG_GAMEOBJECT_DESPAWN_ANIM);
		data << (uint64)guid;
		pDuelArb->SendMessageToSet(&data, true);

		data.Initialize(SMSG_DESTROY_OBJECT);
		data << (uint64)guid;
		pDuelArb->SendMessageToSet(&data, true);
	    
		pDuelArb->RemoveFromMap();
		delete pDuelArb;

		cPlayer->SetUInt64Value(PLAYER_DUEL_ARBITER, 0);
		oPlayer->SetUInt64Value(PLAYER_DUEL_ARBITER, 0);
		cPlayer->SetDuelFlag(NULL);
		oPlayer->SetDuelFlag(NULL);
	}
}
