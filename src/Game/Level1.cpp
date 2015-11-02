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
//  GM Chat Commands
//

bool
ChatHandler::HandleAnnounceCommand(const char* args)
{
    if(!*args) return false;

    char pAnnounce[256];
    sprintf((char*)pAnnounce, LANG_CMD_BROADC, args);   // Adds Server:
    sWorld.SendWorldText(pAnnounce);

    return true;
}

bool
ChatHandler::HandleAnnounceWideCommand(const char* args)
{
    if(!*args)
        return false;

	sWorld.SendWorldWideText(args);
}

bool
ChatHandler::HandleGMOnCommand(const char* args)
{
    uint32 newbytes = m_session->GetPlayer( )->GetUInt32Value(PLAYER_BYTES_2) | 0x8;
    m_session->GetPlayer()->SetUInt32Value( PLAYER_BYTES_2, newbytes);
	m_session->GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAG_GM);

    return true;
}

bool
ChatHandler::HandleGMOffCommand(const char* args)
{
    uint32 newbytes = m_session->GetPlayer( )->GetUInt32Value(PLAYER_BYTES_2) & ~(0x8);
    m_session->GetPlayer( )->SetUInt32Value( PLAYER_BYTES_2, newbytes);
	m_session->GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAG_GM);

    return true;
}

bool
ChatHandler::Command_Where (const char* args)
{
    Object *obj;

    uint64 guid = m_session->GetPlayer()->GetSelection();
    if (guid != 0)
    {
        if(!(obj = (Object*)objmgr.GetObject<Player>(guid)) && !(obj = (Object*)objmgr.GetObject<Creature>(guid)))
        {
            m_session->SystemMessage (LANG_CMD_SSELEC);
            return true;
        }
    }
    else
        obj = (Object*)m_session->GetPlayer();

	float deg = (obj->GetOrientation()/3.141593*180);
	m_session->SystemMessage("|c8fff6420Map: |c8fff9920%d; |c8fff6420X: |c8fff9920%.2f; |c8fff6420Y: |c8fff9920%.2f; |c8fff6420Z: |c8fff9920%.2f\n|c8fff6420Orientation: |c8fff9920%f |c8fff6420rads | |c8fff9920%f |c8fff6420degr\n|c8fff6420ZoneId: |c8fff9920%d",
		obj->GetMapId(), obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(),
		obj->GetOrientation(), deg, obj->GetZoneId());
    return true;
}

bool
ChatHandler::HandleSummonCommand(const char* args)
{
    if(!*args)
        return false;

    Player *chr = objmgr.GetPlayer(args);

    if (chr)
    {
        // send message to user
		m_session->SystemMessage(LANG_CMD_SUMMON, chr->GetName());

        // send message to player
		chr->GetSession()->SystemMessage(LANG_CMD_BSUMMON, m_session->GetPlayer()->GetName());

        chr->TeleportFar (m_session->GetPlayer()->GetMapId(),
            m_session->GetPlayer()->GetPositionX(),
            m_session->GetPlayer()->GetPositionY(),
            m_session->GetPlayer()->GetPositionZ());
    }
    else
    {
		m_session->SystemMessage(LANG_CMD_NOPLR, args);
    }

    return true;
}

bool
ChatHandler::HandleAppearCommand(const char* args)
{
    if(!*args)
        return false;

    Player *chr = objmgr.GetPlayer(args);
    if (chr)
    {
		m_session->SystemMessage(LANG_CMD_TPTO, chr->GetName());
        m_session->GetPlayer()->TeleportFar (chr->GetMapId(),
			chr->GetPositionX(), chr->GetPositionY(), chr->GetPositionZ());
    }
    else
        m_session->SystemMessage (LANG_CMD_NOPLR, args);

    return true;
}

bool
ChatHandler::HandleRecallCommand(const char* args)
{
    if(!*args) return false;

	Player * plr = m_session->GetPlayer();

    if (strncmp((char*)args,"sunr",5)==0)		plr->TeleportFar (1, -180.949f, -296.467f, 11.5384f);
    else if (strncmp((char*)args,"thun",5)==0)	plr->TeleportFar (1, -1196.22f, 29.0941f, 176.949f);
    else if (strncmp((char*)args,"cross",6)==0)	plr->TeleportFar (1, -443.128f, -2598.87f, 96.2114f);
    else if (strncmp((char*)args,"ogri",5)==0)	plr->TeleportFar (1, 1676.21f, -4315.29f, 61.5293f);
    else if (strncmp((char*)args,"neth",5)==0)	plr->TeleportFar (0, -10996.9f, -3427.67f, 61.996f);
    else if (strncmp((char*)args,"thel",5)==0)	plr->TeleportFar (0, -5395.57f, -3015.79f, 327.58f);
    else if (strncmp((char*)args,"storm",6)==0)	plr->TeleportFar (0, -8913.23f, 554.633f, 93.7944f);
    else if (strncmp((char*)args,"iron",5)==0)	plr->TeleportFar (0, -4981.25f, -881.542f, 501.66f);
    else if (strncmp((char*)args,"under",6)==0)	plr->TeleportFar (0, 1586.48f, 239.562f, -52.149f);
	else if (strncmp((char*)args,"darn",5)==0)	plr->TeleportFar (1, 9933.94f, 2500.98f, 1317.82f);
    else 
		return false;

    return true;
}

bool
ChatHandler::Command_Modify_HP(const char* args)
{
    // change level of char
    char* pHp = strtok((char*)args, " ");
    if (!pHp)
        return false;

    int32 hp = atoi(pHp);
	int32 hpm = m_session->GetPlayer()->GetMaxHealth();

    char* pHpMax = strtok(NULL, " ");
    if (pHpMax)
        hpm = atoi(pHpMax);
	if(hpm<hp)
		hpm=hp;

    if (hp <= 0 || hpm <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_HEALTH, chr->GetName(), hp, hpm);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_HEALTHR, m_session->GetPlayer()->GetName(), hp, hpm);

    chr->SetUInt32Value( UNIT_FIELD_MAXHEALTH, hpm );
    chr->SetUInt32Value( UNIT_FIELD_HEALTH, hp );

    return true;
}

bool
ChatHandler::Command_Modify_Mana(const char* args)
{
    char* pmana = strtok((char*)args, " ");
    if (!pmana)
        return false;

    int32 mana = atoi(pmana);
	int32 manam = m_session->GetPlayer()->GetMaxMana();

    char* pmanaMax = strtok(NULL, " ");
    if (pmanaMax)
		manam = atoi(pmanaMax);
	if (manam<mana)
		manam=mana;


    if (mana <= 0 || manam <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }


    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_MANA, chr->GetName(), mana, manam);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_MANAR, m_session->GetPlayer()->GetName(), mana, manam);

    chr->SetUInt32Value( UNIT_FIELD_MAXPOWER1, manam );
    chr->SetUInt32Value( UNIT_FIELD_POWER1, mana );

    return true;
}

bool
ChatHandler::Command_Modify_Energy (const char* args)
{
    char* pmana = strtok((char*)args, " ");
    if (!pmana)
        return false;

    int32 mana = atoi(pmana);
	int32 manam = m_session->GetPlayer()->GetMaxEnergy();

    char* pmanaMax = strtok(NULL, " ");
    if (pmanaMax)
		manam = atoi(pmanaMax);
	if (manam<mana)
		manam=mana;


    if (mana <= 0 || manam <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }
    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_ENER, chr->GetName(), mana, manam);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_ENERR, m_session->GetPlayer()->GetName(), mana, manam);

    chr->SetUInt32Value( UNIT_FIELD_MAXPOWER4, manam );
    chr->SetUInt32Value( UNIT_FIELD_POWER4, mana );

    return true;
}

bool
ChatHandler::Command_Modify_Rage(const char* args)
{
    char* pmana = strtok((char*)args, " ");
    if (!pmana)
        return false;

    int32 mana = atoi(pmana);
	int32 manam = m_session->GetPlayer()->GetMaxRage();

    char* pmanaMax = strtok(NULL, " ");
    if (pmanaMax)
        manam = atoi(pmanaMax);
	if (manam<mana)
		manam=mana;


    if (mana <= 0 || manam <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }
    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_RAGE, chr->GetName(), mana, manam);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_RAGER, m_session->GetPlayer()->GetName(), mana, manam);

    chr->SetUInt32Value( UNIT_FIELD_MAXPOWER2, manam );
    chr->SetUInt32Value( UNIT_FIELD_POWER2, mana );

    return true;
}

bool
ChatHandler::Command_Modify_Level (const char* args)
{
    if(!*args) return false;

    int32 lvl = atoi((char*)args);
    if(lvl > 255 || lvl < 1)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL_LV);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }
    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_LVL, chr->GetName(), lvl, lvl);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_LVLR, m_session->GetPlayer()->GetName(), lvl, lvl);
    chr->SetLevel ((uint8)lvl);

    return true;
}

bool
ChatHandler::Command_Modify_Item (const char* args)
{
    if(!*args) return false;

    int32 item = atoi((char*)args);
    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_ADDITEM, item, chr->GetName());

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_RVDITEM, m_session->GetPlayer()->GetName(), item);

	chr->AddItemToBackpack( item );

    return true;
}

bool
ChatHandler::Command_Modify_qItems (const char* args)
{
    if(!*args)
        return false;

    int32 quest_id = atoi((char*)args);
    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_ADDQITEM, quest_id, chr->GetName());

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_RVDQITEM, m_session->GetPlayer()->GetName(), quest_id);

	Quest *pQuest = objmgr.GetQuest( quest_id );
	if (!pQuest) return false;
	if ( pQuest->m_questItemId[0] > 0 )	chr->AddItemToBackpack( pQuest->m_questItemId[0], pQuest->m_questItemCount[0] );
	if ( pQuest->m_questItemId[1] > 0 )	chr->AddItemToBackpack( pQuest->m_questItemId[1], pQuest->m_questItemCount[1] );
	if ( pQuest->m_questItemId[2] > 0 )	chr->AddItemToBackpack( pQuest->m_questItemId[2], pQuest->m_questItemCount[2] );
	if ( pQuest->m_questItemId[3] > 0 )	chr->AddItemToBackpack( pQuest->m_questItemId[3], pQuest->m_questItemCount[3] );

    return true;
}

bool
ChatHandler::Command_Modify_qKill (const char* args)
{
    if(!*args)
        return false;

    int32 quest_id = atoi((char*)args);

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }


	Quest *pQuest = objmgr.GetQuest( quest_id );
	if (!pQuest) return false;
	if ( pQuest->m_questMobId[0] > 0 )	chr->KilledMonster( pQuest->m_questMobId[0], 0 );
	if ( pQuest->m_questMobId[1] > 0 )	chr->KilledMonster( pQuest->m_questMobId[1], 0 );
	if ( pQuest->m_questMobId[2] > 0 )	chr->KilledMonster( pQuest->m_questMobId[2], 0 );
	if ( pQuest->m_questMobId[3] > 0 )	chr->KilledMonster( pQuest->m_questMobId[3], 0 );

    return true;
}

bool
ChatHandler::HandleTaxiCheatCommand(const char* args)
{
	if (!*args) return false;

    int flag = hex_or_decimal ((char*)args);
    Player *chr = getSelectedChar(m_session);
    if (chr == NULL)
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
    if (flag != 0)
		m_session->SystemMessage(LANG_CMD_ALLTPG, chr->GetName());
    else
		m_session->SystemMessage(LANG_CMD_NOTPG, chr->GetName());

    // send message to player
    if (flag != 0)
    {
		m_session->SystemMessage(LANG_CMD_ALLTPR,
            m_session->GetPlayer()->GetName());
    }
    else
    {
		m_session->SystemMessage(LANG_CMD_NOTPR, 
            m_session->GetPlayer()->GetName());
    }

    for (uint8 i=0; i<8; ++i)
    {
        if (flag != 0)
            m_session->GetPlayer()->SetTaximask(i, 0xFFFFFFFF);
		else
            m_session->GetPlayer()->SetTaximask(i, 0);
    }

    return true;
}

bool
ChatHandler::Command_Modify_Speed (const char* args)
{
    if (!*args) return false;

    WorldPacket data;
    float Speed = (float)atof((char*)args);
    if (Speed > 128.0f || Speed <= 1.0f)	// 1/7...3x run speed
    {
		m_session->SystemMessage(LANG_CMD_MOD_SPEED_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL)
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_SPEED_G, chr->GetName(), Speed);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_SPEED_R, m_session->GetPlayer()->GetName(), Speed);

    data.Initialize( SMSG_FORCE_RUN_SPEED_CHANGE );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID + 1 );
    data << (float)Speed;
    chr->SendMessageToSet( &data, true );

    return true;
}

bool
ChatHandler::Command_Modify_Swim (const char* args)
{
    if (!*args) return false;

    WorldPacket data;
    float Swim = (float)atof((char*)args);

    if (Swim > 50 || Swim <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL) // Ignatich: what should NOT happen but just in case...
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_SWIM_G, chr->GetName(), Swim);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_SWIM_R, m_session->GetPlayer()->GetName(), Swim);

    data.Initialize( SMSG_FORCE_SWIM_SPEED_CHANGE );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID + 1 );
    data << (float)Swim;
    chr->SendMessageToSet( &data, true );

    return true;
}

bool
ChatHandler::Command_Modify_Size (const char* args)
{
    if (!*args) return false;

    float Scale = (float)atof((char*)args);
    if (Scale > 3 || Scale <= 0)
    {
		m_session->SystemMessage(LANG_CMD_INCVAL);
        return true;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL)
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_SIZE_G, chr->GetName(), Scale);

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_SIZE_R, m_session->GetPlayer()->GetName(), Scale);

    chr->SetFloatValue(OBJECT_FIELD_SCALE_X, Scale);

    return true;
}

bool
ChatHandler::Command_NPC_Size (const char* args)
{
	if (!*args) return false;

	float Scale = (float)atof((char*)args);
	if (Scale > 128 || Scale <= 0.01)
	{
		m_session->SystemMessage (LANG_CMD_NPC_SIZE_INC);
		return true;
	}

	// Find GUID for current selection
	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	Creature *pCreature = objmgr.GetObject<Creature>(guid);

	if (pCreature == NULL) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	m_session->SystemMessage (LANG_CMD_NPC_SIZE_G, Scale);
	pCreature->SetFloatValue(OBJECT_FIELD_SCALE_X, Scale);
	pCreature->RemoveFromMap();
	pCreature->PlaceOnMap();

	return true;
}

bool
ChatHandler::Command_NPC_Info (const char* args)
{
	// Find GUID for current selection
	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	Creature *pCreature = objmgr.GetObject<Creature>(guid);

	if (pCreature == NULL) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	uint32 Entry = pCreature->GetEntry();
	uint32 LGuid = pCreature->GetGUIDLow();
	float Scale = pCreature->GetFloatValue (OBJECT_FIELD_SCALE_X);
	uint32 Level = pCreature->GetLevel();
	uint32 Faction = pCreature->GetUInt32Value (UNIT_FIELD_FACTIONTEMPLATE);
	uint32 NPCFlags = pCreature->GetUInt32Value (UNIT_NPC_FLAGS);
	uint32 Model = pCreature->GetUInt32Value (UNIT_FIELD_DISPLAYID);
	uint32 MountModel = pCreature->GetUInt32Value (UNIT_FIELD_MOUNTDISPLAYID);

	m_session->SystemMessage (LANG_CMD_NPC_INFO, LGuid, Entry, Level, Scale, pCreature->m_movementType,
		Faction, NPCFlags, Model, MountModel, pCreature->m_spawnTime[0],
		pCreature->m_spawnTime[1], pCreature->m_spawnDist);
	m_session->SystemMessage (LANG_CMD_NPC_INFOL,
		pCreature->GetMapId(), pCreature->GetPositionX(), pCreature->GetPositionY(),
		pCreature->GetPositionZ());
	
	return true;
}

bool
ChatHandler::Command_Modify_Mount (const char* args)
{
    if(!*args) return false;

    WorldPacket data;
    uint16 mId = 1147;
    float speed = (float)30;
    uint32 num = 0;

    num = atoi((char*)args);
    switch(num)
    {
    case 1: mId=1147;   //GRYPHON
        break;
    case 2: mId=479;    //HYPOGRYPH
        break;
    case 3: mId=235;    //EVIL HORSE
        break;
    case 4: mId=236;    //WHITE HORSE
        break;
    case 5: mId=237;    //PALOMINO HORSE
        break;
    case 6: mId=238;    //PINTO HORSE
        break;
    case 7: mId=239;    //BLACK HORSE
        break;
    case 8: mId=908;    //CHESNUT HORSE
        break;
    case 9: mId=1531;   //ZEBRA
        break;
    case 10: mId=2346;   //NIGHTMARE HORSE
        break;
    case 11: mId=5050;   //UNDEAD STEED
        break;
    case 12: mId=2784;   //BLACK RAMS
        break;
    case 13: mId=2787;   //BLUE RAMS
        break;
    case 14: mId=2785;   //BROWN RAMS
        break;
    case 15: mId=2736;   //GREY RAMS
        break;
    case 16: mId=2786;   //WHITE RAMS
        break;
    case 17: mId=180;    //ORANGE RAPTOR
        break;
    case 18: mId=322;    //DARK GREEN RAPTOR
        break;
    case 19: mId=675;    //BLUE RAPTOR
        break;
    case 20: mId=787;    //YELLOW RAPTOR
        break;
    case 21: mId=960;    //PURPLE RAPTOR
        break;
    case 22: mId=1960;   //RED RAPTOR
        break;
    case 23: mId=1337;   //DARK GREY RAPTOR
        break;
    case 24: mId=1041;   //BROWN STRIDER
        break;
    case 25: mId=1220;   //GREY STRIDER
        break;
    case 26: mId=1221;   //IVORY STRIDER
        break;
    case 27: mId=1961;   //PING STRIDER
        break;
    case 28: mId=1281;   //PURPLE STRIDER
        break;
    case 29: mId=1040;   //TEAL STRIDER
        break;
    case 30: mId=321;    //BLACK TIGER
        break;
    case 31: mId=1056;   //BROWN TIGER
        break;
    case 32: mId=3029;   //DARK TIGER
        break;
    case 33: mId=320;    //RED TIGER
        break;
    case 34: mId=748;    //SNOW TIGER
        break;
    case 35: mId=616;    //WHITE TIGER
        break;
    case 36: mId=632;    //YELLOW TIGER
        break;
    case 37: mId=2187;   //STRIPED UNICORN
        break;
    case 38: mId=2185;   //EVIL UNICORN
        break;
    case 39: mId=2186;   //IVORY UNICORN
        break;
    case 40: mId=2189;   //BLAC STRIPES UNICORN
        break;
    case 41: mId=207;    //DARK BLACK WOLF
        break;
    case 42: mId=246;    //REDDISH BROWN WOLF
        break;
    case 43: mId=247;    //BROWN WOLF
        break;
    case 44: mId=720;    //LIGHT BLUE WOLF
        break;
    case 45: mId=2320;   //GREY WOLF
        break;
    case 46: mId=2327;   //DARK GREY WOLF
        break;
    case 47: mId=2328;   //DARK BROWN WOLF
        break;
    case 48: mId=295;    //WYVERN
        break;
    default:        //NO ERROR OF MOUNT ;)
		mId=atoi(args);
		if (!mId)
		{
			m_session->SystemMessage("There is no such mount.");
			return true;
		}
		break;
    }

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL)
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }


    // send message to user
	m_session->SystemMessage(LANG_CMD_MOD_MOUNT_G, chr->GetName());

    // send message to player
	chr->GetSession()->SystemMessage(LANG_CMD_MOD_MOUNT_R, m_session->GetPlayer()->GetName());

    chr->SetUInt32Value( UNIT_FIELD_FLAGS , 0x001000 );
    chr->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , mId);
    chr->SetUInt32Value( UNIT_FIELD_FLAGS , 0x003000 );

    data.Initialize( SMSG_FORCE_RUN_SPEED_CHANGE );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID + 1 );
    data << speed;
    WPAssert(data.size() == 12);
    chr->SendMessageToSet( &data, true );

    data.Initialize( SMSG_FORCE_SWIM_SPEED_CHANGE );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID );
    data << chr->GetUInt32Value( OBJECT_FIELD_GUID + 1 );
    data << speed;
    WPAssert(data.size() == 12);
    chr->SendMessageToSet( &data, true );

    return true;
}

bool
ChatHandler::Command_Modify_Money (const char* args)
{
    if (!*args)
        return false;

    int32 gold = atoi((char*)args);

    Player *chr = getSelectedChar(m_session);
    if (chr == NULL)
    {
		m_session->SystemMessage(LANG_CMD_NOCHAR);
        return true;
    }

    uint32 moneyuser =(m_session->GetPlayer()->GetMoney());
    if(gold < 0)
    {
        int32 newmoney = moneyuser + gold;
        sLog.outDetail("USER1: %i, ADD: %i, DIF: %i\n", moneyuser, gold, newmoney); //INFO
        if(newmoney < 0 )
        {
            // send message to user
			m_session->SystemMessage(LANG_CMD_MOD_TALLMONEY_G, chr->GetName(), moneyuser);

            // send message to player
			chr->GetSession()->SystemMessage(LANG_CMD_MOD_TALLMONEY_R, m_session->GetPlayer()->GetName(), moneyuser);

            // update value
            chr->SetMoney (0);
        }
        else
        {
            // send message to user
			m_session->SystemMessage(LANG_CMD_MOD_TMONEY_G, abs(gold), chr->GetName());

            // send message to player
			chr->GetSession()->SystemMessage(LANG_CMD_MOD_TMONEY_R, m_session->GetPlayer()->GetName(), abs(gold));
        }
    }
    else
    {
        // send message to user
		m_session->SystemMessage(LANG_CMD_MOD_GMONEY_G, gold, chr->GetName());

        // send message to player
		chr->GetSession()->SystemMessage(LANG_CMD_MOD_GMONEY_R, m_session->GetPlayer()->GetName(), gold);
    }

    chr->SetMoney (moneyuser+gold);
	
	return true;
}

#ifdef _DEBUG       

bool
ChatHandler::Command_Test (const char* args)
{
	for (int i = PLAYER_XP; i <= PLAYER_FIELD_POSSTAT4; ++i)
	{
		m_session->GetPlayer()->SetUInt32Value (i, i - PLAYER_XP + 1);
	}
	return true;
}

#endif

bool
ChatHandler::Command_NPC_Kill (const char* args)
{
	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_SHSELCR);
		return true;
	}

	// Bang!
	m_session->GetPlayer()->DealDamage (pCreature, pCreature->GetMaxHealth());
	return true;
}

bool
ChatHandler::Command_NPC_Respawn (const char* args)
{
	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid == 0) {
		m_session->SystemMessage (LANG_CMD_NOSELNPC);
		return true;
	}

	Creature * pCreature = objmgr.GetObject<Creature>(guid);
	if(!pCreature) {
		m_session->SystemMessage (LANG_CMD_SHSELCR);
		return true;
	}

	// Respawn!
	pCreature->m_deathState = JUST_DIED;
	pCreature->m_deathTimer = 0;
	pCreature->Update (100);
	pCreature->m_respawnTimer = 50;
	pCreature->Update (100);
	pCreature->SetUInt32Value (UNIT_DYNAMIC_FLAGS, 0);	// not lootable anymore

	return true;
}

bool
ChatHandler::Command_GameObject_Add(const char* args)
{
	if(!*args) return false;

	return true;
}

bool
ChatHandler::Command_GameObject_Del(const char* args)
{
	if(!*args) return false;

	return true;

}

bool
ChatHandler::Command_GameObject_ChangeId(const char* args)
{
	if(!*args) return false;

	return true;
}
