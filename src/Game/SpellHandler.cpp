#include "StdAfx.h"

// Copyright (C) 2004 WoW Daemon
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#include "../Shared/PacketBuilder.h"

void
WorldSession::HandleUseItemOpcode(WorldPacket& recvPacket)
{
    sLog.outDetail("WORLD: got use Item packet, data length = %i",recvPacket.size());

    uint8 bagIndex, slot, tmp3;
    uint32 spellId;
    Player* pUser = GetPlayer();

    recvPacket >> bagIndex >> slot >> tmp3;

    Item* pItem = new Item;
    pItem = pUser->GetItemBySlot(slot); // bagIndex, slot);
    ItemPrototype *iProto = pItem->GetProto();
    spellId = iProto->SpellId[0];

    // Check for Spell ID
    SpellEntry *spellInfo = sSpellStore.LookupEntry( spellId );
    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown spell id %i\n", spellId);
        return;
    }
	
	if(pUser->isDead())
	{
		WorldPacket data;
		Make_INVENTORY_CHANGE_FAILURE (&data, EQUIP_ERR_YOU_ARE_DEAD, pItem, pItem);
		SendPacket( &data );
		return;
	}

	// Check if Player is skilled enough to use Item
	if (!pUser->CanUseItem(iProto)) return;

	// Check if Player is in Combat
	if (pUser->isInCombat()) {
		// Check if used allowed Item class
		if (iProto->Class == ITEM_CLASS_CONSUMABLE	|| 
			iProto->Class == ITEM_CLASS_TRADE_GOODS	||
			iProto->Class == ITEM_CLASS_RECIPE		||
			iProto->Class == ITEM_CLASS_KEY			||
			iProto->Class == ITEM_CLASS_MISC		)
		{
			WorldPacket data;
			Make_INVENTORY_CHANGE_FAILURE (&data, EQUIP_ERR_CANT_DO_IN_COMBAT, pItem, pItem);
			SendPacket(&data);
			return;
		}
	}

	// Activate Spell
    Spell *spell = new Spell(pUser, spellInfo,false, 0);
    WPAssert(spell);

	SpellCastTargets targets;
    targets.read(&recvPacket, pUser);
    spell->m_CastItem = pItem;
    spell->prepare(&targets);

	// Decrease item count in Inventory or destroy item if Item count = 1 before use
	uint32 ItemCount = pItem->GetCount();
	uint32 ItemClass = iProto->Class;
	uint32 ItemId    = iProto->ItemId;

	if (ItemClass == ITEM_CLASS_CONSUMABLE) {
		if (ItemCount > 1) {
			pItem->SetCount(ItemCount-1);
		} else {
			pUser->RemoveItemFromSlot(slot); // (bagIndex , slot);
			pItem->DeleteFromDB();
			delete pItem;
		}
	}
}

void
WorldSession::HandleCastSpellOpcode(WorldPacket& recvPacket)
{
    uint32 spellId;
	Player* pUser = GetPlayer();
    recvPacket >> spellId;

	sLog.outDetail("WORLD: got cast spell packet, spellId - %i, data length = %i\n",
		spellId, recvPacket.size());
	recvPacket.print_storage();


    SpellEntry *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown spell id %i\n", spellId);
        return;
    }

	Spell *spell = new Spell(pUser, spellInfo, false, 0);
    WPAssert(spell);

    SpellCastTargets targets;
    targets.read(&recvPacket, pUser);

    spell->prepare(&targets);
}

void
WorldSession::HandleCancelCastOpcode(WorldPacket& recvPacket){
    uint32 spellId;
    recvPacket >> spellId;

    if(GetPlayer()->m_currentSpell)
        GetPlayer()->m_currentSpell->cancel();
}

void
WorldSession::HandleCancelChannellingOpcode(WorldPacket& recvPacket){
	sLog.outDebug("CancelChannelling called!");
	uint32 spellId;
    recvPacket >> spellId;
	sLog.outDebug("CancelChannelling recieved! length:%u , info1:%u", recvPacket.size(), spellId);

	SpellEntry *spellInfo = sSpellStore.LookupEntry( spellId );
	if (!spellInfo)
		return;
	for(int i = 0; i < 3; ++i)
	{
		if(spellInfo->Effect[i] == EFFECT_PERSISTENT_AREA_AURA)
		{
			if(spellId == GetPlayer()->GetUInt32Value(UNIT_CHANNEL_SPELL))
			{
				DynamicObject* dynObj = objmgr.GetObject<DynamicObject>(GetPlayer()->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT));
				if(dynObj)
				{
					dynObj->RemoveFromMap();
					objmgr.RemoveObject_Free(dynObj);
				}
				else
				{
					sLog.outError("Dynamic Spellobject could not be found!");
				}
			}
		}
	}
}

void
WorldSession::HandleCancelAuraOpcode( WorldPacket& recvPacket){
    uint32 spellId;
    recvPacket >> spellId;
    GetPlayer()->RemoveAffectById(spellId);
}

void
WorldSession::HandleCancelAutorepeatSpellOpcode(WorldPacket& recvPacket){

	sLog.outDebug("WORLD: CMSG_CANCEL_AUTO_REPEAT_SPELL");

    if(GetPlayer()->m_currentSpell)
GetPlayer()->m_currentSpell->cancel();
}

#define OPEN_CHEST 11437
#define OPEN_SAFE 11535
#define OPEN_CAGE 11792
#define OPEN_BOOTY_CHEST 5107
#define OPEN_STRONGBOX 8517

void
WorldSession::HandleGameObjectUseOpcode( WorldPacket & recv_data )
{
    WorldPacket data;
    uint64 guid;
	uint32 spellId = OPEN_CHEST;
	const GameobjectTemplate *info;
    recv_data >> guid;

	sLog.outDebug("WORLD: CMSG_GAMEOBJ_USE: [GUID %d]", guid);   

    GameObject *obj = objmgr.GetObject<GameObject>(guid);
	if (!obj) return;

	switch(obj->GetUInt32Value(GAMEOBJECT_TYPE_ID))
	{
	case 22:
		info = obj->m_GoTpl;
		if(info)
		{
			spellId = info->Sound[0];
			guid=GetPlayer()->GetGUID();
		}
	  break;
	default:
         sLog.outDebug( "Unkonw Object Type %d\n", obj->GetUInt32Value(GAMEOBJECT_TYPE_ID));  
	   break;
    }
    SpellEntry *spellInfo = sSpellStore.LookupEntry( spellId );

    if(!spellInfo)
    {
        sLog.outError("WORLD: unknown spell id %i\n", spellId);
        return;
    }

    Spell *spell = new Spell(GetPlayer(), spellInfo, false, 0);
    WPAssert(spell);

    SpellCastTargets targets;
    targets.m_unitTarget = GetPlayer();
    targets.m_GOTarget = obj;
    spell->prepare(&targets);


	GetPlayer()->SetLootGUID(guid);
    
	data.Initialize(SMSG_LOOT_RESPONSE);
	if( obj->FillLoot(&data) ) {

		SendPacket(&data);
		sLog.outDebug("WORLD: CMSG_GAMEOBJ_USE: [GUID %d] : LOOT COMPLETED.", guid);  
	
	}

}