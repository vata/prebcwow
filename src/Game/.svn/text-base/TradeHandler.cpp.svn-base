#include "StdAfx.h"
/* 
 * Copyright (C) 2005 MaNGOS <http://www.magosproject.org/>
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

void WorldSession::HandleIgnoreTradeOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug( "\nWORLD: Ignore Trade %u", GetPlayer()->GetGUID());
    recvPacket.print_storage();
}

void WorldSession::HandleBusyTradeOpcode(WorldPacket& recvPacket)
{
    sLog.outDebug( "\nWORLD: Busy Trade %u", GetPlayer()->GetGUID());
    recvPacket.print_storage();
}

void WorldSession::ClearTrade()
{
    GetPlayer()->tradeGold = 0;
    GetPlayer()->acceptTrade = false;
    for(int i=0; i<7; ++i)
        GetPlayer()->tradeItems[i] = -1;
}

void WorldSession::UpdateTrade()
{
    WorldPacket data;
    Player *pThis = GetPlayer();
    Item *item = NULL;

    if( !pThis->pTrader ) return;

    data.Initialize(SMSG_TRADE_STATUS_EXTENDED);
    data << (uint8 ) 1;
    data << (uint32) 7;
    data << (uint32) 0;
    data << (uint32) GetPlayer()->tradeGold;
    data << (uint32) 0;
    for(int i=0; i<7; ++i)
    {
        item = (pThis->tradeItems[i] >= 0 ? pThis->GetItemBySlot( (uint8) pThis->tradeItems[i] ) : NULL);
        
        data << (uint8) i;
        if(item)
        {
			item->UpdateStats();

			data << (uint32) item->GetEntry();
			data << (uint32) item->GetProto()->BuyPrice; // for testing purpose, otherwise 0
			data << (uint32) item->GetCount();
        }
        else
        {
            data << (uint32) 0;
            data << (uint32) 0;
            data << (uint32) 0;
        }        
        for(int j=0; j<12; ++j)
            data << (uint32) 0;
    }
    pThis->pTrader->GetSession()->SendPacket(&data);

}

void WorldSession::HandleAcceptTradeOpcode(WorldPacket& recvPacket)
{
    if ( !GetPlayer()->pTrader ) return;
    GetPlayer()->acceptTrade = true;

    WorldPacket data;
    Item *myItems[6] = { NULL, NULL, NULL, NULL, NULL, NULL };
    Item *hisItems[6] = { NULL, NULL, NULL, NULL, NULL, NULL };
    int i, myCount = 0, hisCount = 0, myFreeSlots = 0, hisFreeSlots = 0;
    
    if ( GetPlayer()->pTrader->acceptTrade )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)4;
        GetPlayer()->pTrader->GetSession()->SendPacket(&data);
		myFreeSlots = GetPlayer()->CountFreeBagSlot();
        hisFreeSlots = GetPlayer()->pTrader->CountFreeBagSlot();        

        for(i=0; i<6; ++i)
        {
            if( GetPlayer()->tradeItems[i] >= INVENTORY_SLOT_ITEM_START ) ++myCount;
            if( GetPlayer()->pTrader->tradeItems[i] >= INVENTORY_SLOT_ITEM_START ) ++hisCount;
        }

        if( (myCount + myFreeSlots) < hisCount )
        {    
			GetPlayer()->GetSession()->SystemMessage("You do not have enough free slots");
			GetPlayer()->pTrader->GetSession()->SystemMessage("Your partner do not have enough free bag slots");

            GetPlayer()->GetSession()->HandleUnacceptTradeOpcode(recvPacket);
            GetPlayer()->pTrader->GetSession()->HandleUnacceptTradeOpcode(recvPacket);
            return;
        }
		else if( (hisCount + hisFreeSlots) < myCount )
        {
            GetPlayer()->GetSession()->SystemMessage("Your partner do not have enough free bag slots");
            GetPlayer()->pTrader->GetSession()->SystemMessage("You do not have enough free slots");

            GetPlayer()->GetSession()->HandleUnacceptTradeOpcode(recvPacket);
            GetPlayer()->pTrader->GetSession()->HandleUnacceptTradeOpcode(recvPacket);
            return;
        }
        

		if((GetPlayer()->tradeGold != 0) || (GetPlayer()->pTrader->tradeGold !=0))
		{
			GetPlayer()->setGold( -((int) GetPlayer()->tradeGold) );            
			GetPlayer()->setGold( GetPlayer()->pTrader->tradeGold );

			GetPlayer()->pTrader->setGold( -((int) GetPlayer()->pTrader->tradeGold) );            
			GetPlayer()->pTrader->setGold( GetPlayer()->tradeGold );
		}

		for(i=0; i<6; ++i)
		{
			if( GetPlayer()->tradeItems[i] ) // >= 0
				myItems[i] = GetPlayer()->RemoveItemFromSlot( (uint8)GetPlayer()->tradeItems[i] );
			if( GetPlayer()->pTrader->tradeItems[i] ) // >= 0
				hisItems[i] = GetPlayer()->pTrader->RemoveItemFromSlot( (uint8) GetPlayer()->pTrader->tradeItems[i] );
			if(hisItems[i]) {
				hisItems[i]->SetUInt64Value( ITEM_FIELD_GIFTCREATOR, GetPlayer()->pTrader->GetGUID());
				uint8 Slot = GetPlayer()->FindFreeItemSlot(INVTYPE_SLOT_ITEM);
				GetPlayer()->AddItemToSlot(Slot, hisItems[i]);
			}
			if(myItems[i]) {
				myItems[i]->SetUInt64Value( ITEM_FIELD_GIFTCREATOR, GetPlayer()->GetGUID());
				uint8 Slot = GetPlayer()->pTrader->FindFreeItemSlot(INVTYPE_SLOT_ITEM);
				GetPlayer()->pTrader->AddItemToSlot(Slot, myItems[i]);
			}
		}

        ClearTrade();
        
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)8;
        GetPlayer()->pTrader->GetSession()->SendPacket(&data);
        SendPacket(&data);

        GetPlayer()->pTrader->pTrader = GetPlayer()->pTrader = NULL;
    }
    else
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)4;
        GetPlayer()->pTrader->GetSession()->SendPacket(&data);
    }

}

void WorldSession::HandleUnacceptTradeOpcode(WorldPacket& recvPacket)
{
    WorldPacket data;

    
    data.Initialize(SMSG_TRADE_STATUS);
    data << (uint32)7;
    GetPlayer()->pTrader->GetSession()->SendPacket(&data);

    GetPlayer()->acceptTrade = false;
}

void WorldSession::HandleBeginTradeOpcode(WorldPacket& recvPacket)
{
    WorldPacket data;

    
    data.Initialize(SMSG_TRADE_STATUS);
    data << (uint32)2; 
    GetPlayer()->pTrader->GetSession()->SendPacket(&data);
    GetPlayer()->pTrader->GetSession()->ClearTrade();

    
    data.Initialize(SMSG_TRADE_STATUS);
    data << (uint32)2; 
    SendPacket(&data);
    ClearTrade();
}

void WorldSession::HandleCancelTradeOpcode(WorldPacket& recvPacket)
{
    WorldPacket data;

    if( GetPlayer()->pTrader )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)3; 
        GetPlayer()->pTrader->GetSession()->SendPacket(&data);
    }
    
    GetPlayer()->pTrader = NULL;
    ClearTrade();
}

void WorldSession::HandleInitiateTradeOpcode(WorldPacket& recvPacket)
{
    WorldPacket data;
    uint64 guid;


    if( !GetPlayer()->isAlive() )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)17; 
        SendPacket(&data);
        return;        
    }

    if( isLogingOut() )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)19; 
        SendPacket(&data);
        return;        
    }

    recvPacket >> guid;

    Player* pOther = objmgr.GetObject<Player>(guid);

    if(!pOther)
    {
        
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)6; 
        SendPacket(&data);
        return;        
    }
    
    if( pOther->pTrader )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)0; 
        SendPacket(&data);
        return;    
    }
    
    if( !pOther->isAlive() )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)18; 
        SendPacket(&data);
        return;        
    }
    
    if( pOther->GetSession()->isLogingOut() )
    {
        data.Initialize(SMSG_TRADE_STATUS);
        data << (uint32)20; 
        SendPacket(&data);
        return;        
    }
    


    GetPlayer()->pTrader = pOther; 
    pOther->pTrader = GetPlayer();  

    
    data.Initialize(SMSG_TRADE_STATUS);
    data << (uint32) 1; 
    data << (uint64) GetPlayer()->GetGUID();
    GetPlayer()->pTrader->GetSession()->SendPacket(&data);
}

void WorldSession::HandleSetTradeGoldOpcode(WorldPacket& recvPacket)
{
    uint32 gold;
    recvPacket >> gold;

    GetPlayer()->tradeGold = gold;
    UpdateTrade();
}

void WorldSession::HandleSetTradeItemOpcode(WorldPacket& recvPacket)
{
    uint8 tradeSlot;
    uint8 trash;
    uint8 bagSlot;

    recvPacket >> tradeSlot;
    recvPacket >> trash;
    recvPacket >> bagSlot;

    GetPlayer()->tradeItems[tradeSlot] = (int) bagSlot;

    UpdateTrade();
}

void WorldSession::HandleClearTradeItemOpcode(WorldPacket& recvPacket)
{
    uint8 slot;
    recvPacket >> slot;
    
    GetPlayer()->tradeItems[slot] = -1;

    UpdateTrade();
}