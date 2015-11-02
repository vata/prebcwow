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

createFileSingleton( ObjectMgr );

ObjectMgr::ObjectMgr()
{
    m_hiCharGuid = 1;
    m_hiCreatureGuid = 1;
    m_hiItemGuid = 1;
    m_hiGoGuid = 1;
    m_hiDoGuid = 1;
}

ObjectMgr::~ObjectMgr()
{
	for (CreatureTemplateMap::iterator i = mCreatureTemplates.begin( );
		i != mCreatureTemplates.end( ); ++ i ) 
	{
		delete i->second;
	}
	mCreatureTemplates.clear();

	for (GameobjectTemplateMap::iterator i = mGameobjectTemplates.begin( );
		i != mGameobjectTemplates.end( ); ++ i ) 
	{
		delete i->second;
	}
	mGameobjectTemplates.clear();		

    for( CreatureMap::iterator i = mCreatures.begin( ); i != mCreatures.end( ); ++ i ) {
        delete i->second;
    }
    mCreatures.clear( );

    for( GameObjectMap::iterator i = mGameObjects.begin( ); i != mGameObjects.end( ); ++ i ) {
        delete i->second;
    }
    mGameObjects.clear( );

    for( DynamicObjectMap::iterator i = mDynamicObjects.begin( ); i != mDynamicObjects.end( ); ++ i ) {
        delete i->second;
    }
    mDynamicObjects.clear( );

    for( CorpseMap::iterator i = mCorpses.begin( ); i != mCorpses.end( ); ++ i ) {
        delete i->second;
    }
    mCorpses.clear( );

    for( QuestMap::iterator i = mQuests.begin( ); i != mQuests.end( ); ++ i ) {
        delete i->second;
    }
    mQuests.clear( );

    for( ItemPrototypeMap::iterator i = mItemPrototypes.begin( ); i != mItemPrototypes.end( ); ++ i ) {
        delete i->second;
    }
    mItemPrototypes.clear( );

	for( TrainerspellMap::iterator i = mTrainerspells.begin( ); i != mTrainerspells.end( ); ++ i ) {
        delete i->second;
    }
    mTrainerspells.clear( );

    for( GraveyardMap::iterator i = mGraveyards.begin( ); i != mGraveyards.end( ); ++ i ) {
        delete i->second;
    }
    mGraveyards.clear( );
}

//-----------------------------------------------------------------------------
//
// Groups
//

Group*
ObjectMgr::GetGroupByLeader(const uint64 &guid) const
{
    GroupSet::const_iterator itr;
    for (itr = mGroupSet.begin(); itr != mGroupSet.end(); ++itr)
    {
        if ((*itr)->GetLeaderGUID() == guid)
        {
            return *itr;
        }
    }

    return NULL;
}

GameobjectTemplate*
ObjectMgr::GetGameobjectTemplate (uint32 id)
{
	GameobjectTemplateMap::const_iterator itr = mGameobjectTemplates.find( id );
	if( itr != mGameobjectTemplates.end( ) )
		return itr->second;

	return NULL;
}
//-----------------------------------------------------------------------------
//
// Guilds
//
Guild*
ObjectMgr::GetGuildById(const uint32 GuildId) const
{
    GuildSet::const_iterator itr;
    for (itr = mGuildSet.begin(); itr != mGuildSet.end(); ++itr)
    {
        if ((*itr)->GetId() == GuildId)
        {
            return *itr;
        }
    }

    return NULL;
}

//-----------------------------------------------------------------------------
//
// Creature names
//

CreatureTemplate*
ObjectMgr::GetCreatureTemplate (uint32 id, bool can_create)
{
    /*
	CreatureNameMap::const_iterator itr = mCreatureNames.find( id );
    if( itr != mCreatureNames.end( ) )
        return itr->second;
	*/
	CreatureTemplateMap::const_iterator itr = mCreatureTemplates.find( id );
	if( itr != mCreatureTemplates.end( ) )
		return itr->second;

    //returning unknown creature if no data found
	if (id >= WAYPOINT_NPC_ID && id <= WAYPOINT_NPC_ID + 1000) {
		// Waypoints want special reply
		// TODO: Here possible chance to leak memory?
		CreatureTemplate	*ct = new CreatureTemplate;

		memset (ct, 0, sizeof (CreatureTemplate));

		char tmp[64];
		sprintf (tmp, "Waypoint #%d", id - WAYPOINT_NPC_ID);
		ct->Name = tmp;

		ct->Entry = id;
		ct->Guild = "";
		AddCreatureTemplate (ct);
		return ct;

		/*CreatureInfo *ci = new CreatureInfo;

		char tmp[64];
		sprintf (tmp, "wp:%d", id - WAYPOINT_NPC_ID);
		ci->Name = tmp;
		ci->Id = id;
		ci->SubName = "";
		ci->unknown1 = 0;
		ci->unknown2 = 0;
		ci->unknown3 = 0;
		ci->unknown4 = 0;
		ci->DisplayID = 0;

		return ci;
		*/
	}

    /*CreatureInfo *ci=new CreatureInfo;
    ci->Name = "Unknown Being";
    ci->Id=id;
    ci->SubName = "";
    ci->Type = 0;
    ci->unknown1 = 0;
    ci->unknown2 = 0;
    ci->unknown3 = 0;
    ci->unknown4 = 0;
    ci->DisplayID = 0;
    AddCreatureName(ci);
    return ci;
	*/
	
	if (!can_create) return NULL;

	CreatureTemplate	*ct = new CreatureTemplate;
	memset (ct, 0, sizeof (CreatureTemplate));
	ct->Entry = id;
	ct->Name = "Unknown Creature";
	ct->Guild = "";
	AddCreatureTemplate (ct);
	return ct;
}

void
ObjectMgr::LoadGameobjectTemplates()
{
	GameobjectTemplate *goT;
	uint32 count = 0;
	std::stringstream query;
	query << "SELECT obj_id, name, model, sound0, sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, faction, flags, gtype, size, level FROM gameobj_def";
	
	QueryResult* result = sDatabase.Query( query.str().c_str() );
	if (!result) {
		sLog.outString("No Gameobject Templates found!");
	}
	else
	{
		do {
			Field *fields = result->Fetch();
			goT = new GameobjectTemplate;
			goT->Entry = fields[0].GetUInt32();
			if (!fields[1].GetString())
			{
				//sLog.outDebug("WARNING! Gameobject with NULL name found!");
				goT->Name = "Unnamed Gameobject";
			}
			else
			{
				goT->Name = fields[1].GetString();
			}
			goT->Model = fields[2].GetUInt32();
			for(int i = 0; i < 10; ++i)
			{
				goT->Sound[i] = fields[i+3].GetUInt32();
			}
			goT->Faction = fields[13].GetUInt32();
			goT->Flags = fields[14].GetUInt32();
			goT->GType = fields[15].GetUInt32();
			goT->Size = fields[16].GetFloat();
			goT->Level = fields[17].GetFloat();

			AddGameobjectTemplate( goT );
			++count;
		} while (result->NextRow());
		sLog.outString( "        >=[%d GameObject templates]", count );
		delete result;
	}
	return;
}

void
ObjectMgr::AddCreatureTemplate (CreatureTemplate *cinfo)
{
	ASSERT( mCreatureTemplates.find(cinfo->Entry) == mCreatureTemplates.end() );

    //verifying if info for that creature already exists(need some cleaning here some time)
	CreatureTemplateMap::iterator itr = mCreatureTemplates.find( cinfo->Entry );
    
	//if found we delete the old creature info
    if (itr != mCreatureTemplates.end())
		mCreatureTemplates.erase(itr);

	mCreatureTemplates[cinfo->Entry] = cinfo;
}

void
ObjectMgr::AddGameobjectTemplate (GameobjectTemplate *goinfo)
{
	ASSERT( mGameobjectTemplates.find(goinfo->Entry) == mGameobjectTemplates.end() );

    //verifying if info for that creature already exists(need some cleaning here some time)
	GameobjectTemplateMap::iterator itr = mGameobjectTemplates.find( goinfo->Entry );
    
	//if found we delete the old creature info
    if (itr != mGameobjectTemplates.end())
		mGameobjectTemplates.erase(itr);

	mGameobjectTemplates[goinfo->Entry] = goinfo;
}

void
ObjectMgr::LoadCreatureTemplates()
{
    CreatureTemplate *ct;
    QueryResult *result = sDatabase.Query( "SELECT `creature_id`, `name`, `guild`, "
		"`attack_min`, `attack_max`, `level_min`, `level_max`, `bounding_radius`, "
		"`combat_reach`, `damage_min`, `damage_max`, `faction`, `flags1`, `maxhealth`, "
		"`maxmana`, `npcflags`, `speed`, `size`, `type`, `family`, `elite`, `model`, "
		"`mount` FROM creatures_templ" );

	uint32 progressTotal = result->GetRowCount();
	uint32 count = 0;
	uint32 count2 = 0; 

	if (result) {
        do {
            Field *fields = result->Fetch();
            ct = new CreatureTemplate;
            ct->Entry = fields[0].GetUInt32();
            ct->Name = fields[1].GetString();
			
			if (fields[2].GetString() == NULL) {
				ct->Guild = "";
			} else
				ct->Guild = fields[2].GetString();

            ct->Attack[0] = fields[3].GetUInt32();
			ct->Attack[1] = fields[4].GetUInt32();

			ct->Level[0] = fields[5].GetUInt32();
			ct->Level[1] = fields[6].GetUInt32();
			if (ct->Level[0] < 0) ct->Level[0] = 1;
			if (ct->Level[0] > 99) ct->Level[0] = 99;
			if (ct->Level[1] < ct->Level[0]) ct->Level[1] = ct->Level[0] + 1;

			ct->BoundingRadius = fields[7].GetFloat();
			ct->CombatReach = fields[8].GetFloat();
			ct->Damage[0] = fields[9].GetUInt32();
			ct->Damage[1] = fields[10].GetUInt32();
			ct->Faction = fields[11].GetUInt32();
			ct->Flags1 = fields[12].GetUInt32();
			
			ct->MaxHealth = fields[13].GetUInt32();
			if (ct->MaxHealth < 1) ct->MaxHealth = 1;

			ct->MaxMana = fields[14].GetUInt32();

			ct->NPCFlags = fields[15].GetUInt32();
			ct->Speed = fields[16].GetFloat();

			ct->Size = fields[17].GetFloat();
			if (ct->Size < 0.1) ct->Size = 1.0;

			ct->Type = fields[18].GetUInt8();
			ct->Family = fields[19].GetUInt8();
			ct->Elite = fields[20].GetUInt8();
			ct->Model = fields[21].GetUInt32();
			ct->MountModel = fields[22].GetUInt32();

			for(int i = 0; i < 3; ++i)
			{
				ct->EquipSlot[i] = 0;
				ct->EquipModel[i] = 0;
				ct->EquipData[i] = 0;

			}
			std::stringstream s;
			s.rdbuf()->str("");
			s << "SELECT * FROM creature_equip WHERE creature_id = " << ct->Entry;
			QueryResult* result2 = sDatabase.Query(s.str().c_str());
			if(result2)
			{
				uint8 i = 0;
				do 
				{
					ct->EquipSlot [i] = (*result2)[1].GetUInt32();
					ct->EquipModel[i] = (*result2)[2].GetUInt32();

					ct->EquipData [i] = (uint32)(((*result2)[3].GetUInt32() << 0x18) + ((*result2)[4].GetUInt32() << 0x10) + ((*result2)[6].GetUInt32() << 8) + (*result2)[5].GetUInt32());

					++i;
				} while (result2->NextRow());

				delete result2;
				++count2;
			}

			AddCreatureTemplate( ct );
			++count;
			ProgressBarShow (count, progressTotal, "       ::Loading Creature templates");
        } while (result->NextRow());

        delete result;
    }

	ProgressBarHide();
	sLog.outString("        >=[%d Creature Templates]", count );
	sLog.outString("        >=[%d Equiped Creatures]", count2 );
}

Player*
ObjectMgr::GetPlayerByName(const char *name) const
{
    uint64 guid = 0;
	Player *plr;
    std::stringstream query;
    query << "SELECT guid FROM characters WHERE name = '" << name << "'";

    QueryResult *result = sDatabase.Query( query.str().c_str() );
    if(result)
    {
        guid = (*result)[0].GetUInt32();
        delete result;
    }
	plr = objmgr.GetObject<Player>(guid);
    return plr;
}

uint64
ObjectMgr::GetPlayerGUIDByName(const char *name) const
{
    uint64 guid = 0;
    std::stringstream query;
    query << "SELECT guid FROM characters WHERE name = '" << name << "'";

    QueryResult *result = sDatabase.Query( query.str().c_str() );
    if(result)
    {
        guid = (*result)[0].GetUInt32();

        delete result;
    }

    return guid;
}

bool
ObjectMgr::GetPlayerNameByGUID(const uint64 &guid, std::string &name) const
{
    std::stringstream query;
    query << "SELECT name FROM characters WHERE guid=" << GUID_LOPART(guid);

    QueryResult *result = sDatabase.Query( query.str().c_str() );
    if(result)
    {
        name = (*result)[0].GetString();
        delete result;
        return true;
    }

    return false;
}

void
ObjectMgr::LoadAuctions()
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM auctionhouse" );

    if( !result ) return;
    
	AuctionEntry *aItem;
	uint32 count = 0;

    do {
        Field *fields = result->Fetch();

        aItem = new AuctionEntry;
		aItem->auctioneer = fields[0].GetUInt32();
		aItem->item = fields[1].GetUInt32();
		aItem->owner = fields[2].GetUInt32();
		aItem->buyout = fields[3].GetUInt32();
		aItem->time = fields[4].GetUInt32();
		aItem->bidder = fields[5].GetUInt32();
		aItem->bid = fields[6].GetUInt32();
		aItem->Id = fields[7].GetUInt32();

		++count;
		AddAuction(aItem);

	} while (result->NextRow());
	delete result;

	sLog.outString( "        >=[%d Auctions]", count );
}

void
ObjectMgr::LoadItemPrototypes()
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM items" );

    if( !result )
        return;

    ItemPrototype *pItemPrototype;
    int i;
	uint32 count = 0;
	uint32 progressTotal = result->GetRowCount();

    if( result->GetFieldCount() < 124 )
    {
        sLog.outError("DB: ITEMS SQL table has incorrect number of fields.");
        delete result;
        return;
    }
	
    do
    {
        Field *fields = result->Fetch();

		if( !fields[0].GetUInt32() )
        {
			sLog.outBasic("DB: Incorrect item id found: Skipped");
            continue;
        }
		
		if( !fields[4].GetString() || !fields[8].GetUInt32() )
        {
			sLog.outBasic("DB: Incorrect item [%d] found: Skipped", fields[0].GetUInt32());
            continue;
        }

        pItemPrototype = new ItemPrototype;

        pItemPrototype->ItemId =		fields[0].GetUInt32();
        pItemPrototype->Class =			fields[2].GetUInt32();
        pItemPrototype->SubClass =		fields[3].GetUInt32();
        pItemPrototype->Name1 =			fields[4].GetString();
        pItemPrototype->Name2 =			fields[5].GetString();
        pItemPrototype->Name3 =			fields[6].GetString();
        pItemPrototype->Name4 =			fields[7].GetString();
        pItemPrototype->DisplayInfoID = fields[8].GetUInt32();
        pItemPrototype->Quality =		fields[9].GetUInt32();
        pItemPrototype->Flags =			fields[10].GetUInt32();
        pItemPrototype->BuyPrice =		fields[12].GetUInt32(); // Swapped Buy/Sell Prices
		pItemPrototype->SellPrice =		fields[11].GetUInt32();
        pItemPrototype->InventoryType = fields[13].GetUInt32();
        pItemPrototype->AllowableClass = fields[14].GetUInt32();
        pItemPrototype->AllowableRace = fields[15].GetUInt32();
        pItemPrototype->ItemLevel =		fields[16].GetUInt32();
        pItemPrototype->RequiredLevel = fields[17].GetUInt32();
        pItemPrototype->RequiredSkill = fields[18].GetUInt32();
        pItemPrototype->RequiredSkillRank = fields[19].GetUInt32();
        pItemPrototype->RequiredSpell =	fields[20].GetUInt32();
        pItemPrototype->RequiredFaction = fields[21].GetUInt32();
        pItemPrototype->RequiredFactionLvL = fields[22].GetUInt32();
        pItemPrototype->RequiredPVPRank = fields[23].GetUInt32();
        pItemPrototype->MaxCount =		fields[24].GetUInt32();
        pItemPrototype->ContainerSlots = fields[25].GetUInt32();
        for(i = 0; i < 20; i+=2) {
            pItemPrototype->ItemStatType[i/2] = fields[26+i].GetUInt32();
            pItemPrototype->ItemStatValue[i/2] = fields[27+i].GetUInt32();
        }
        for(i = 0; i < 15; i+=3) {
            pItemPrototype->DamageMin[i/3] = fields[46+i].GetFloat();
            pItemPrototype->DamageMax[i/3] = fields[47+i].GetFloat();
            pItemPrototype->DamageType[i/3] = fields[48+i].GetUInt32();
        }
        pItemPrototype->Armor = fields[61].GetUInt32();
        pItemPrototype->HolyRes = fields[62].GetUInt32();
        pItemPrototype->FireRes = fields[63].GetUInt32();
        pItemPrototype->NatureRes = fields[64].GetUInt32();
        pItemPrototype->FrostRes = fields[65].GetUInt32();
        pItemPrototype->ShadowRes = fields[66].GetUInt32();
        pItemPrototype->ArcaneRes = fields[67].GetUInt32();
        pItemPrototype->Delay = fields[68].GetUInt32();
        pItemPrototype->Block = fields[69].GetUInt32();
        for(i = 0; i < 30; i+=6) {
            pItemPrototype->SpellId[i/6] = fields[70+i].GetUInt32();
            pItemPrototype->SpellTrigger[i/6] = fields[71+i].GetUInt32();
            pItemPrototype->SpellCharges[i/6] = fields[72+i].GetUInt32();
            pItemPrototype->SpellCooldown[i/6] = fields[73+i].GetUInt32();
            pItemPrototype->SpellCategory[i/6] = fields[74+i].GetUInt32();
            pItemPrototype->SpellCategoryCooldown[i/6] = fields[75+i].GetUInt32();
        }
        pItemPrototype->Bonding = fields[100].GetUInt32();

		if (fields[101].GetString() == NULL) {
			pItemPrototype->Description = "";
		} else
			pItemPrototype->Description = fields[101].GetString();

        pItemPrototype->RandPropID = fields[102].GetUInt32();
        pItemPrototype->PageTextID = fields[103].GetUInt32();
        pItemPrototype->PageLanguage = fields[104].GetUInt32();
        pItemPrototype->PageMaterial = fields[105].GetUInt32();
        pItemPrototype->LockId = fields[106].GetUInt32();
        pItemPrototype->LockMaterial = fields[107].GetUInt32();
        pItemPrototype->Field108 = fields[108].GetUInt32();
        pItemPrototype->Field109 = fields[109].GetUInt32();
        pItemPrototype->Field110 = fields[110].GetUInt32();
        pItemPrototype->Field111 = fields[111].GetUInt32();
        pItemPrototype->MaxDurability = fields[112].GetUInt32();
        pItemPrototype->StartQuest = fields[113].GetUInt32();
        pItemPrototype->isCrafted = fields[114].GetUInt32();
        pItemPrototype->isQuested = fields[115].GetUInt32(); 
        pItemPrototype->isRaid = fields[116].GetUInt32();
        pItemPrototype->isStatic = fields[117].GetUInt32(); 
        pItemPrototype->isVendor = fields[118].GetUInt32();
        pItemPrototype->isWorld = fields[119].GetUInt32();
        pItemPrototype->common_Mob = fields[120].GetUInt32();
        pItemPrototype->common_Percent = fields[121].GetUInt32();
        pItemPrototype->Total_Percent = fields[122].GetUInt32();
		pItemPrototype->Sheath = fields[123].GetUInt32();

		++count;
		ProgressBarShow (count, progressTotal, "       ::Loading Item templates");
        AddItemPrototype(pItemPrototype);		

    } while( result->NextRow());
	ProgressBarHide();
    delete result;
	sLog.outString("        >=[%d Item Templates Loaded]", count );
}

void
ObjectMgr::LoadTrainerSpells()
{
	QueryResult *result = sDatabase.Query( "SELECT * FROM trainer" );
	if ( !result ) {sLog.outString (" ERROR: 'TRAINER' table is EMPTY / TRAINERS WILL NOT WORK"); return;}

	Trainerspell *TrainSpell;

	uint32 count = 0;

	do {
		Field *fields = result->Fetch();

		TrainSpell = new Trainerspell;
		//TrainSpell->trainerId = fields[0].GetUInt32();
		TrainSpell->Id = fields[1].GetUInt32();
		TrainSpell->skilline01 = fields[2].GetUInt32();
		TrainSpell->skilline02 = fields[3].GetUInt32();
		TrainSpell->skilline03 = fields[4].GetUInt32();
		TrainSpell->skilline04 = fields[5].GetUInt32();
		TrainSpell->skilline05 = fields[6].GetUInt32();
		TrainSpell->skilline06 = fields[7].GetUInt32();
		TrainSpell->skilline07 = fields[8].GetUInt32();
		TrainSpell->skilline08 = fields[9].GetUInt32();
		TrainSpell->skilline09 = fields[10].GetUInt32();
		TrainSpell->skilline10 = fields[11].GetUInt32();
		TrainSpell->skilline11 = fields[12].GetUInt32();
		TrainSpell->skilline12 = fields[13].GetUInt32();
		TrainSpell->skilline13 = fields[14].GetUInt32();
		TrainSpell->skilline14 = fields[15].GetUInt32();
		TrainSpell->skilline15 = fields[16].GetUInt32();
		TrainSpell->skilline16 = fields[17].GetUInt32();
		TrainSpell->skilline17 = fields[18].GetUInt32();
		TrainSpell->skilline18 = fields[19].GetUInt32();
		TrainSpell->skilline19 = fields[20].GetUInt32();
		TrainSpell->skilline20 = fields[21].GetUInt32();
		TrainSpell->maxlvl = fields[22].GetUInt32();
		TrainSpell->charclass = fields[23].GetUInt32();
		AddTrainerspell(TrainSpell);
		++count;
	}
	while (result->NextRow());
	
	sLog.outString( "        >=[%d Trainers Loaded]", count );
	delete result;
}

void
ObjectMgr::LoadTrainerTeachSpells()
{
	for(uint16 i = 0; i < 65535; ++i)
	{
		SpellEntry *ActualEntry = sSpellStore.LookupEntry(i);
		if (ActualEntry != NULL)
		{
			if(ActualEntry->EffectImplicitTargetA[0] == 0 &&
				ActualEntry->EffectImplicitTargetA[1] == 0 &&
				ActualEntry->EffectImplicitTargetA[2] == 0 &&
				ActualEntry->EffectImplicitTargetB[0] == 0 &&
				ActualEntry->EffectImplicitTargetB[1] == 0 &&
				ActualEntry->EffectImplicitTargetB[2] == 0
				)//Check if this spell is a "teach" spell for trainers
			{
				for(int j = 0; j < 3; ++j)
				{
					if(ActualEntry->Effect[j] == EFFECT_LEARN_SPELL)
					TeachSpellID[ ActualEntry->EffectTriggerSpell[j] ] = i;
				}
			}
		}
	}
}

void
ObjectMgr::LoadAuctionItems()
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM auctioned_items" );

    if( !result ) return;
    Field *fields;
	uint32 count = 0;
    
	do {
        fields = result->Fetch();
        Item* item = new Item;
        item->LoadFromDB(fields[0].GetUInt32(), 2);

		++count;
		AddAItem(item);
    }
    while( result->NextRow() );

    delete result;
	sLog.outString( "        >=[%d Auctioned Items]", count );
}

void
ObjectMgr::LoadMailedItems()
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM mailed_items" );

    if( !result ) return;

    Field *fields;
	uint32 count = 0;

    do {
        fields = result->Fetch();
        Item* item = new Item;
        item->LoadFromDB(fields[0].GetUInt32(), 3);
        
		++count;
		AddMItem(item);
    }
    while( result->NextRow() );

    delete result;
	sLog.outString( "        >=[%d Mailed Items]", count );
}

void
ObjectMgr::LoadGuilds()
{
	Guild *newguild;
	QueryResult *result = sDatabase.Query( "SELECT guildId FROM guilds" );
	uint32 count = 0;
	
	if( !result ) 
	{
		sLog.outString( "" );
		sLog.outString( "        >=[Loaded %d Guild Definitions]", count );
		return;
	}
	
	uint32 progressTotal = result->GetRowCount();
	do
	{
		Field *fields = result->Fetch();
		++count;
		
		newguild = new Guild;
		newguild->LoadGuildFromDB(fields[0].GetUInt32());

		ProgressBarShow (count, progressTotal, "       ::Loading Guilds");

		AddGuild(newguild);
	}while( result->NextRow() );

	sLog.outString( "" );
	sLog.outString( "        >=[Loaded %d Guild Definitions]", count );
}

void
ObjectMgr::LoadQuests()
{
QueryResult *result = sDatabase.Query( "SELECT * FROM quests" );

    if( !result ) return;

    Quest *pQuest;
	uint32 count = 0;
	int iCalc;

    do {
        Field *fields = result->Fetch();

        pQuest = new Quest;
		iCalc = -1;

        pQuest->m_questId    = fields[ ++iCalc ].GetUInt32();
        pQuest->m_zone       = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questFlags = fields[ ++iCalc ].GetUInt32();

        pQuest->m_title          = fields[ ++iCalc ].GetString();
        pQuest->m_details        = fields[ ++iCalc ].GetString();
        pQuest->m_objectives     = fields[ ++iCalc ].GetString();
        pQuest->m_completedText  = fields[ ++iCalc ].GetString();
        pQuest->m_incompleteText = fields[ ++iCalc ].GetString();
        pQuest->m_secondText     = fields[ ++iCalc ].GetString();

		pQuest->m_partText[0]    = fields[ ++iCalc ].GetString();
		pQuest->m_partText[1]    = fields[ ++iCalc ].GetString();
		pQuest->m_partText[2]    = fields[ ++iCalc ].GetString();
		pQuest->m_partText[3]    = fields[ ++iCalc ].GetString();
        pQuest->m_requiredLevel  = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questLevel     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_previousQuests = fields[ ++iCalc ].GetUInt32();

		int CiC;
		for ( CiC = 0; CiC < 10; ++CiC)
			{ pQuest->m_previousQuest[CiC] = fields[ ++iCalc ].GetUInt32(); }

        pQuest->m_previousQuests_Lock = fields[ ++iCalc ].GetUInt32();
		for ( CiC = 0; CiC < 10; ++CiC)
			{ pQuest->m_previousQuest_Lock[CiC] = fields[ ++iCalc ].GetUInt32(); }

        pQuest->m_lockQuests     = fields[ ++iCalc ].GetUInt32();
		for ( CiC = 0; CiC < 10; ++CiC)
			{ pQuest->m_lockQuest[CiC] = fields[ ++iCalc ].GetUInt32(); }

        pQuest->m_questItemId[0]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemId[1]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemId[2]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemId[3]     = fields[ ++iCalc ].GetUInt32();

        pQuest->m_questItemCount[0]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemCount[1]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemCount[2]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questItemCount[3]  = fields[ ++iCalc ].GetUInt32();

        pQuest->m_questMobId[0]      = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobId[1]		 = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobId[2]		 = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobId[3]		 = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobCount[0]   = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobCount[1]   = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobCount[2]   = fields[ ++iCalc ].GetUInt32();
        pQuest->m_questMobCount[3]   = fields[ ++iCalc ].GetUInt32();

        pQuest->m_choiceRewards       = fields[ ++iCalc ].GetUInt16();
        pQuest->m_choiceItemId[0]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemId[1]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemId[2]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemId[3]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemId[4]     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemId[5]     = fields[ ++iCalc ].GetUInt32();

        pQuest->m_choiceItemCount[0]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemCount[1]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemCount[2]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemCount[3]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemCount[4]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_choiceItemCount[5]  = fields[ ++iCalc ].GetUInt32();

        pQuest->m_itemRewards		  = fields[ iCalc++ ].GetUInt16();
        pQuest->m_rewardItemId[0]	  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemId[1]	  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemId[2]	  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemId[3]	  = fields[ iCalc++ ].GetUInt32();

        pQuest->m_rewardItemCount[0]  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemCount[1]  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemCount[2]  = fields[ iCalc++ ].GetUInt32();
        pQuest->m_rewardItemCount[3]  = fields[ iCalc++ ].GetUInt32();

        pQuest->m_rewardGold     = fields[ ++iCalc ].GetUInt32();
        pQuest->m_repFaction[0]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_repFaction[1]  = fields[ ++iCalc ].GetUInt32();
        pQuest->m_repValue[0]    = fields[ ++iCalc ].GetUInt32();
        pQuest->m_repValue[1]    = fields[ ++iCalc ].GetUInt32();
		pQuest->m_srcItem        = fields[ ++iCalc ].GetUInt32();
		pQuest->m_nextQuest      = fields[ ++iCalc ].GetUInt32();
		pQuest->m_learnSpell     = fields[ ++iCalc ].GetUInt32();
		pQuest->m_timeMinutes    = fields[ ++iCalc ].GetUInt32();

		pQuest->m_questType      = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questRaces     = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questClass     = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questTrSkill   = fields[ ++iCalc ].GetUInt32();
		pQuest->m_questBehavior  = fields[ ++iCalc ].GetUInt32();

		pQuest->m_LocMap		 = fields[ ++iCalc ].GetUInt32();
		pQuest->m_LocX			 = fields[ ++iCalc ].GetFloat();
		pQuest->m_LocY			 = fields[ ++iCalc ].GetFloat();
		pQuest->m_LocOpt		 = fields[ ++iCalc ].GetFloat();

		++count;
        AddQuest(pQuest);

    }
    while( result->NextRow() );

    delete result;
	sLog.outString( "        >=[%d quest definitions]", count );
}

void
ObjectMgr::LoadWorldSpawns()
{
	// Get count of all world spawns
	//
	QueryResult *result = sDatabase.Query( "SELECT COUNT(id) FROM creatures" );
	if( !result ) return;
	uint32 progressTotal = (*result)[0].GetUInt32();

	delete result;

	// First preload waypoints in memory to save on loading time
	//
	result = sDatabase.Query ("SELECT creatureId, X, Y, Z, WaitTime1, WaitTime2 FROM creatures_mov ORDER BY id");
	Field * fields;
	uint32 count = 0;

	WaypointVectorMap wpvCache;
	WaypointVector * way = NULL;
	Waypoint point;

	if (result != NULL) {
		do {
			fields = result->Fetch();

			point.recordId = fields[0].GetUInt32();
			point.x = fields[1].GetFloat();
			point.y = fields[2].GetFloat();
			point.z = fields[3].GetFloat();
			point.Wait1 = fields[4].GetUInt8();
			point.Wait2 = fields[5].GetUInt8();

			// Look for already existing vector for this GUID
			WaypointVectorMap::iterator	wpvi = wpvCache.find (point.recordId);

			if (wpvi == wpvCache.end()) {
				way = new WaypointVector();
				wpvCache[point.recordId] = way;
			} else {
				way = wpvi->second;
			}

			// Add another point
			way->push_back (point);
			++count;

		} while (result->NextRow());

		delete result;
	}

	if (count)
		sLog.outString ("        >=[%d waypoints for %d NPCs precached]", count, wpvCache.size());
	else
		sLog.outString ("        >=[No waypoints found]", count, wpvCache.size());

	//
	// Now can start loading creatures
	//
	result = sDatabase.Query( "SELECT id, positionX, positionY, positionZ, orientation, "
		"zoneId, mapId, data, name_id, moveType, running, spawnTime1, spawnTime2, spawnDist, "
		"currentWaypoint, spawnX, spawnY, spawnZ, spawnOrient FROM creatures" );
	// old one was only ID + LoadFromDB

	// log no creatures error
	if( !result ) { 
		sLog.outString( "WARNING: Spawned Creatures table is empty.");
		return; 
	}

	Creature* unit;
	count = 0;

	do {
		fields = result->Fetch();
		unit = new Creature;

		unit->SpawnCreatureFromDB(fields, &wpvCache);
		++count;
		ProgressBarShow (count, progressTotal, "Loading/Placing Creatures");
	} while ( result->NextRow() );

	delete result;
	ProgressBarHide();
	sLog.outString( "        >=[%d Spawned Creatures]", count );

	// Clean up precached waypoints - not needed any more
	//

	for (WaypointVectorMap::iterator wpvi = wpvCache.begin(); wpvi != wpvCache.end(); ++wpvi)
        delete wpvi->second;
}

Creature*
ObjectMgr::SpawnCreature2 (CreatureTemplate *ct, uint32 mapId, float x, float y, float z, float o)
{
	// Create the requested monster
	uint32 Level;
	uint32 levelDelta = ct->Level[1] - ct->Level[0];

	if (levelDelta) Level = ct->Level[0] + rand() % levelDelta;
	else Level = ct->Level[0];

	Creature *cr = new Creature();
	cr->Create (objmgr.GenerateLowGuid(HIGHGUID_UNIT), ct->Name.c_str(), mapId, x, y, z, o);

	//cr->SetZoneId (session->GetPlayer()->GetZoneId());
	cr->SetZoneId (objmgr.LookupZoneId (mapId, x, y));
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
	cr->SetUInt32Value(UNIT_FIELD_FLAGS, ct->Flags1);

	objmgr.AddObject( cr );
	cr->PlaceOnMap();
	cr->AddToWorld();

	return cr;
}

void
ObjectMgr::LoadGameobjects()
{
	// Now loading Gameobjects
	//

    QueryResult *result = sDatabase.Query("SELECT id, positionX, positionY, positionZ, orientation, zoneId, mapId, data, name_id FROM gameobjects" );

	// log no gameobjects error
	if ( !result ) { 
		sLog.outString( "WARNING: Spawned GameObjects Table is empty.");
		return; 
	}

	uint32 progressTotal = (uint32)result->GetRowCount();
    GameObject* gobj;
	int count = 0;

	do {
        Field *fields = result->Fetch();

		gobj = new GameObject();
		gobj->SpawnGameObjectFromDB(fields);
		++count;
		ProgressBarShow (count, progressTotal, "Loading/Spawning GObjects");
	} while( result->NextRow() );

    delete result;

	ProgressBarHide();
	sLog.outString( "        >=[%d GameObjects]", count );
}

void
ObjectMgr::LoadTaxiNodes()
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM taxinodes" );

    if( !result )
        return;

    TaxiNodes *pTaxiNodes;

    do
    {
        Field *fields = result->Fetch();

        pTaxiNodes = new TaxiNodes;
        pTaxiNodes->id = fields[0].GetUInt8();
        pTaxiNodes->continent = fields[1].GetUInt8();
        pTaxiNodes->x = fields[2].GetFloat();
        pTaxiNodes->y = fields[3].GetFloat();
        pTaxiNodes->z = fields[4].GetFloat();
        //pTaxiNodes->name = fields[5].GetString();
        //pTaxiNodes->flags = fields[6].GetUInt32();
        pTaxiNodes->mount = fields[7].GetUInt16();

        AddTaxiNodes(pTaxiNodes);

    } while( result->NextRow() );

    delete result;
}

void
ObjectMgr::LoadTaxiPath()
{
    TaxiPath *pTaxiPath;
	TaxiPathEntry* dbcTaxiPath = NULL;
	uint32  currTP=0;

    do
    {
		++currTP;
		dbcTaxiPath = sTaxiPathStore.LookupEntry(currTP);
		if(dbcTaxiPath == NULL)
			continue;

        pTaxiPath = new TaxiPath;
		pTaxiPath->id = dbcTaxiPath->Id;
		pTaxiPath->source = dbcTaxiPath->from;
		pTaxiPath->destination = dbcTaxiPath->to;
		pTaxiPath->price = dbcTaxiPath->price;

        AddTaxiPath(pTaxiPath);
		dbcTaxiPath = NULL;
    } while ( currTP < 428 );
}

void
ObjectMgr::LoadTaxiPathNodes()
{
    TaxiPathNodes *pTaxiPathNodes;
	TaxiPathNodeEntry *dbcTaxiPathNode = NULL;

	uint32  currTPN=0;
    do
    {
		++currTPN;
		if (dbcTaxiPathNode == NULL)
			continue;

        dbcTaxiPathNode = sTaxiPathNodeStore.LookupEntry(currTPN);

        pTaxiPathNodes = new TaxiPathNodes;
		pTaxiPathNodes->id = dbcTaxiPathNode->id;
		pTaxiPathNodes->path = dbcTaxiPathNode->pathId;
		pTaxiPathNodes->index = dbcTaxiPathNode->index;
		pTaxiPathNodes->continent = dbcTaxiPathNode->mapId;
		pTaxiPathNodes->x = dbcTaxiPathNode->x;
        pTaxiPathNodes->y = dbcTaxiPathNode->y;
        pTaxiPathNodes->z = dbcTaxiPathNode->z;

        AddTaxiPathNodes(pTaxiPathNodes);
		dbcTaxiPathNode = NULL;
    } while( currTPN < 11494 );
}

bool
ObjectMgr::GetGlobalTaxiNodeMask( uint32 curloc, uint32 *Mask )
{
    TaxiPathMap::const_iterator itr;
    TaxiPathNodesVec::iterator pathnodes_itr;
    uint8 field;

    for (itr = mTaxiPath.begin(); itr != mTaxiPath.end(); ++itr)
    {
        if( itr->second->source == curloc )
        {
            for( pathnodes_itr = vTaxiPathNodes.begin();
                pathnodes_itr != vTaxiPathNodes.end(); ++pathnodes_itr )
            {
                if ((*pathnodes_itr)->path == itr->second->id)
                {
                    field = (uint8)((itr->second->destination - 1) / 32);
                    Mask[field] |= 1 << ( (itr->second->destination - 1 ) % 32 );
                    break;
                }
            }
        }
    }

    return 1;
}

uint32 
ObjectMgr::GetNearestTaxiNode( float x, float y, float z, uint32 mapid )
{
    uint32 nearest = 0;
    float distance = -1;
    float nx, ny, nz, nd;

    TaxiNodesMap::const_iterator nodes_itr;
    TaxiPathMap::const_iterator path_itr;
    TaxiPathNodesVec::iterator pathnodes_itr;

    for (nodes_itr = mTaxiNodes.begin(); nodes_itr != mTaxiNodes.end(); ++nodes_itr)
    {
        if( nodes_itr->second->continent == mapid )
        {
            nx = nodes_itr->second->x - x;
            ny = nodes_itr->second->y - y;
            nz = nodes_itr->second->z - z;
            nd = nx * nx + ny * ny + nz * nz;
            if( nd < distance || distance < 0 )
            {
                for (path_itr = mTaxiPath.begin();
                     path_itr != mTaxiPath.end();
                     ++path_itr)
                {
                    if( path_itr->second->source == nodes_itr->second->id )
                        break;
                }

                if( path_itr == mTaxiPath.end() )
                    continue;

                for (pathnodes_itr = vTaxiPathNodes.begin();
                     pathnodes_itr != vTaxiPathNodes.end();
                     ++pathnodes_itr)
                {
                    if( (*pathnodes_itr)->path == path_itr->second->id &&
                        (*pathnodes_itr)->continent == mapid &&
                        (*pathnodes_itr)->index == 0)
                    {
                        distance = nd;
                        nearest = nodes_itr->second->id;
                        break;
                    }
                }
            }
        }
    }

    return nearest;
}

void
ObjectMgr::GetTaxiPath( uint32 source, uint32 destination, uint32 &path, uint32 &cost)
{
    TaxiPathMap::const_iterator itr;

    for (itr = mTaxiPath.begin(); itr != mTaxiPath.end(); ++itr)
    {
        if( (itr->second->source == source) && (itr->second->destination == destination) )
            path = itr->second->id;
            cost = itr->second->price;
    }
}

uint16
ObjectMgr::GetTaxiMount( uint32 id )
{
    TaxiNodesMap::const_iterator itr;

    for (itr = mTaxiNodes.begin(); itr != mTaxiNodes.end(); ++itr)
    {
        if( (itr->second->id == id) )
            return itr->second->mount;
    }

    return 0;
}

void
ObjectMgr::GetTaxiPathNodes( uint32 path, Path *pathnodes )
{
	uint16 i = 0;

	for( TaxiPathNodesVec::iterator itr = vTaxiPathNodes.begin();
		itr != vTaxiPathNodes.end(); ++itr )
	{
		if ((*itr)->path == path)
            ++i;
	}

	pathnodes->setLength( i );

	i = 0;
	for( TaxiPathNodesVec::iterator itr = vTaxiPathNodes.begin();
		itr != vTaxiPathNodes.end(); ++itr )
	{
		if ((*itr)->path == path)
		{
			pathnodes->getNodes( )[ i ].x = (*itr)->x;
			pathnodes->getNodes( )[ i ].y = (*itr)->y;
			pathnodes->getNodes( )[ i ].z = (*itr)->z;
			++i;
		}
	}
}

Corpse*
ObjectMgr::GetCorpseByOwner(Player *pOwner)
{
    CorpseMap::const_iterator itr;
    for (itr = mCorpses.begin(); itr != mCorpses.end(); ++itr)
    {
        if(!itr->second->GetUInt64Value(CORPSE_FIELD_OWNER))
            continue;
        if(itr->second->GetUInt64Value(CORPSE_FIELD_OWNER) == pOwner->GetGUID())
            return itr->second;
    }
    return NULL;
}

void
ObjectMgr::LoadCorpses()
{
    Corpse *pCorpse;

    QueryResult *result = sDatabase.Query( "SELECT * FROM Corpses" );
    if( !result ) return;
	uint32 count = 0;

    do
    {
        pCorpse = new Corpse;
        Field *fields = result->Fetch();
        pCorpse->Create(fields[0].GetUInt32());

        pCorpse->SetPosition(fields[1].GetFloat(), fields[2].GetFloat(), fields[3].GetFloat(), fields[4].GetFloat());
        pCorpse->SetZoneId(fields[5].GetUInt32());
        pCorpse->SetMapId(fields[6].GetUInt32());
        pCorpse->LoadValues( fields[7].GetString());

		++count;
        AddObject(pCorpse);

    } while( result->NextRow() );

    delete result;
	sLog.outString( "        >=[%d Player Corpses]", count );
}

void
ObjectMgr::LoadGraveyards()
{
	uint32 curr = 0;
	GraveyardTeleport *newGrave;
	static GraveyardTeleport pgrave[80] = {
		{ 2421.72f,	-2953.62,	123.47,	0,	0,	1,	0 },
		{ -9115.f,	423.f,		96.f,	0,	0,	0,	0 },
		{ -9271.f,	-2305.f,	71.f,	0,	0,	0,	0 },
		{ -10774.3,	-1189.67,	33.15,	0,	0,	0,	0 },
		{ -10546.9,	1197.24,	31.73,	0,	0,	0,	0 },
		{ -5687.f,	-515.f,		398.f,	0,	0,	0,	0 },
		{ -5351.23,	-2881.58,	340.94,	0,	0,	0,	0 },
		{ -3289.12,	-2435.99,	18.6,	0,	0,	0,	0 },
		{ -13290.f,	108.f,		25.f,	0,	0,	0,	0 },
		{ -778.f,	-4985.f,	19.f,	0,	0,	1,	0 },
		{ -592.6,	-2523.49,	91.79,	0,	0,	1,	0 },
		{ -291.f,	-4374.f,	107.f,	0,	0,	0,	0 },
		{ -732.8,	-592.5,		22.66,	0,	0,	0,	0 },
		{ 899.1,	437.56,		65.74,	0,	0,	1,	0 },
		{ -1443.49,	1973.37,	85.49,	0,	0,	1,	0 },
		{ 238.03,	-4792.52,	10.21,	0,	0,	1,	0 },
		{ 1357.1,	-4412.01,	28.38,	0,	0,	1,	0 },
		{ -2944.56,	-153.22,	65.79,	0,	0,	1,	0 },
		{ 6739.19,	209.99,		23.29,	0,	0,	1,	0 },
		{ -11110.4,	-1833.24,	71.86,	0,	0,	0,	0 },
		{ 16223.8,	16278.6,	20.89,	0,	0,	0,	0 },
		{ -4656,	-1765,		-41,	0,	0,	1,	0 },
		{ 8706,		965,		13.27,	0,	0,	1,	0 },
		{ 1035.27,	-2104.28,	122.94,	0,	0,	1,	0 },
		{ 1459.17,	-1858.67,	124.76,	0,	0,	1,	0 },
		{ 2349.61,	485.21,		33.37,	0,	0,	0,	0 },
		{ 2603.31,	-534.66,	89,		0,	0,	0,	0 },
		{ 10384.8,	811.53,		1317.54,0,	0,	1,	0 },
		{ -8935.33,-188.65,		80.42,	0,	0,	0,	0 },
		{ -4596.4,3229.43,		8.99,	0,	0,	1,	0 },
		{ -4439.97,370.15,		51.36,	0,	0,	1,	0 },
		{ 1750.34,-669.79,		44.57,	0,	0,	0,	0 },
		{ -3525.71,	-4315.45,	7,		0,	0,	1,	0 },
		{ 536.5,	-1085.72,	106.27,	0,	0,	0,	0 },
		{ 3806.54,	-1600.29,	218.83,	0,	0,	1,	0 },
		{ -7205.56,	-2436.67,	-218.16,0,	0,	1,	0 },
		{ -634.63,	-4296.03,	40.52,	0,	0,	1,	0 },
		{ -6432.26,	-278.29,	3.79,	0,	0,	1,	0 },
		{ 2942.76,	-6037.13,	5.17,	0,	0,	1,	0 },
		{ -5530.28,	-3459.28,	-45.74,	0,	0,	1,	0 },
		{ 16310.3,	16268.9,	69.44,	0,	0,	1,	0 },
		{ -7190.95,	-3944.65,	9.23,	0,	0,	1,	0 },
		{ 4291.28,	96.96,		43.08,	0,	0,	1,	0 },
		{ 7426,		-2809,		464,	0,	0,	1,	0 },
		{ -2175.19,	-342.03,	-5.51,	0,	0,	1,	0 },
		{ 9931.99,	2193.67,	1328.67,0,	0,	1,	0 },
		{ 9701.25,	945.62,		1291.36,0,	0,	1,	0 },
		{ 2633.41,	-629.74,	107.58,	0,	0,	1,	0 },
		{ 323.51,	-2227.2,	137.62,	0,	0,	0,	0 },
		{ 1880.74,	1624.73,	94.43,	0,	0,	0,	0 },
		{ -2515.99,	-1966.48,	91.78,	0,	0,	1,	0 },
		{ 1822.61,	214.67,		60.14,	0,	0,	0,	0 },
		{ 516.19,	1589.81,	127.55,	0,	0,	0,	0 },
		{ -18.68,	-981.17,	55.84,	0,	0,	0,	0 },
		{ -1472.29,	-2617.96,	49.28,	0,	0,	0,	0 },
		{ -6164.23,	336.32,		399.79,	0,	0,	0,	0 },
		{ -5680.04,	-518.92,	396.27,	0,	0,	0,	0 },
		{ -5049.45,	-809.7,		495.13,	0,	0,	0,	0 },
		{ -6808.38,	-2286.17,	280.75,	0,	0,	0,	0 },
		{ -9403.25,	-2037.69,	58.37,	0,	0,	0,	0 },
		{ -3349.7,	-857.47,	1.06,	0,	0,	0,	0 },
		{ -9339.46,	171.41,		61.56,	0,	0,	0,	0 },
		{ -9151.98,	410.94,		92.7,	0,	0,	0,	0 },
		{ -10567.8,	-3377.2,	22.25,	0,	0,	0,	0 },
		{ -14285,	288.45,		32.33,	0,	0,	0,	0 },
		{ -11542.6,	-228.64,	27.84,	0,	0,	0,	0 },
		{ 101.14,	-184.93,	127.34,	0,	0,	0,	0 },
		{ 2681.06,	-4009.75,	107.85,	0,	0,	1,	0 },
		{ -10846.6,	-2949.49,	13.23,	0,	0,	0,	0 },
		{ 4788.78,	-6845,		89.79,	0,	0,	1,	0 },
		{ -3127.69,	-3046.94,	33.83,	0,	0,	1,	0 },
		{ -7490.45,	-2132.62,	142.19,	0,	0,	0,	0 },
		{ -1072.59,	-3481.85,	62.7,	0,	0,	1,	0 },
		{ 1392,		-3701,		77.0,	0,	0,	0,	0 },
		{ 5935.47,	-1217.75,	383.2,	0,	0,	1,	0 },
		{ -6450.61,	-1113.51,	308.02,	0,	0,	0,	0 },
		{ 908.32,	-1520.29,	55.04,	0,	0,	0,	0 },
		{ 2116.79,	-5287.34,	81.13,	0,	0,	0,	0 },
		{ 6858.56,	-4663.24,	701.36,	0,	0,	1,	0 }
	};

	for(curr=0; curr < 80; ++curr)
	{
		newGrave = new GraveyardTeleport();
		newGrave->X = pgrave[curr].X;
		newGrave->Y = pgrave[curr].Y;
		newGrave->Z = pgrave[curr].Z;
		newGrave->O = pgrave[curr].O;
		newGrave->MapId = pgrave[curr].MapId;
		newGrave->ZoneId = pgrave[curr].ZoneId;
		newGrave->FactionID = pgrave[curr].FactionID;

		ASSERT( mGraveyards.find(curr) == mGraveyards.end() );
		mGraveyards [curr] = newGrave;
    }
	++curr;

	sLog.outString( "        >=[%d Graveyards]", curr );
}

void
ObjectMgr::SetHighestGuids()
{
    QueryResult *result;

    result = sDatabase.Query( "SELECT MAX(guid) FROM characters" );
    if( result ) {
        m_hiCharGuid = (*result)[0].GetUInt32()+1;
        delete result;
    }

    result = sDatabase.Query( "SELECT MAX(id) FROM creatures" );
    if( result ) {
        m_hiCreatureGuid = (*result)[0].GetUInt32()+1;
        delete result;
    }

    result = sDatabase.Query( "SELECT MAX(guid) FROM item_instances" );
    if( result ) {
        m_hiItemGuid = (*result)[0].GetUInt32()+1;
        delete result;
    }

    /*result = sDatabase.Query( "SELECT MAX(name_id) FROM creature_names" );
    if( result ) {
        m_hiNameGuid = (*result)[0].GetUInt32()+1;
        delete result;
    }*/

	result = sDatabase.Query( "SELECT MAX(Id) FROM auctionhouse" );
    if( result ) {
        m_auctionid = (*result)[0].GetUInt32()+1;
        delete result;
    } else {
		m_auctionid = 0;
	}

	result = sDatabase.Query( "SELECT MAX(mailId) FROM mail" );
    if( result ) {
        m_mailid = (*result)[0].GetUInt32()+1;
        delete result;
    } else {
		m_mailid = 0;
	}

    //FIXED: Corpses are Gameobjects. IF we add other gameobjects we need a unified table
    result = sDatabase.Query( "SELECT MAX(guid) FROM gameobjects" );
    if( result ) {
        m_hiGoGuid = (*result)[0].GetUInt32()+1;
        delete result;
	} else {
		m_hiGoGuid = 0;
	}

	result = sDatabase.Query( "SELECT MAX(guid) FROM corpses" );
	if( result ) {
		uint32 corpseguid = (*result)[0].GetUInt32()+1;
		if (corpseguid > m_hiGoGuid)
			m_hiGoGuid = corpseguid;
		delete result;
	}
}

uint32
ObjectMgr::GenerateAuctionID()
{
	++objmgr.m_auctionid;
	return objmgr.m_auctionid;
}

uint32
ObjectMgr::GenerateMailID()
{
	++objmgr.m_mailid;
	return objmgr.m_mailid;
}

uint32
ObjectMgr::GenerateLowGuid(uint32 guidhigh)
{
    uint32 guidlow = 0;

    switch(guidhigh)
    {
        case HIGHGUID_ITEM          : guidlow = objmgr.m_hiItemGuid++;     break;
        //case HIGHGUID_CONTAINER     : guidlow = objmgr.m_hiItemGuid++;     break;
        case HIGHGUID_UNIT          : guidlow = objmgr.m_hiCreatureGuid++; break;
        case HIGHGUID_PLAYER        : guidlow = objmgr.m_hiCharGuid++;     break;
        case HIGHGUID_GAMEOBJECT    : guidlow = objmgr.m_hiGoGuid++;       break;
        case HIGHGUID_CORPSE      : guidlow = objmgr.m_hiGoGuid++;       break;
        case HIGHGUID_DYNAMICOBJECT : guidlow = objmgr.m_hiDoGuid++;       break;
        default                     : ASSERT(guidlow);
    }

    return guidlow;
}

void
ObjectMgr::LoadWorldMapArea()
{
	for (int i=1; i < 382; ++i) // 381 is the last areaId for azeroth/kalimdor
	{
		WorldMapArea *wma = sWorldMapArea.LookupEntry (i);
		if (wma == NULL) continue;
		m_worldMapAreas[wma->mapId].push_back(*wma);
	}
}

uint32
ObjectMgr::LookupZoneId (uint32 mapId, float x, float y)
{
	if(mapId != 0 || mapId != 1) return 0;

	for (uint32 i = 0; i < m_worldMapAreas[mapId].size(); ++i)
	{
		WorldMapArea &wma = m_worldMapAreas[mapId][i];

		if (wma.y1 >= y &&
			wma.y2 <= y &&
			wma.x1 >= x &&
			wma.x2 <= x) 
		{
			return wma.zoneId;
		}
	}
	return 0;
}

void
ObjectMgr::LoadLootTemplates() 
{
	// Get count of all creature loots
	//
	QueryResult *result = sDatabase.Query( "SELECT COUNT(loot_id) FROM creatures_loot" );
	if( !result ) {sLog.outString (" ERROR: 'CREATURE_LOOT' table is EMPTY / CREATURES WILL NOT LOOT"); return;}
	Field *fields = result->Fetch();
	
	uint32 progressTotal = fields[0].GetUInt32();
	uint32 progressStep = progressTotal / 50;
	if (progressStep == 0) progressStep = 1;
	uint32 progressPos = 0;
	
	delete result;

	// Now load creature loots
	//
	result = sDatabase.Query( "SELECT creature_id, item_id, chance FROM creatures_loot" );
	if( !result ) return;

	uint32	count = 0;		// to count errors and stop printing warnings at 10+
	uint32	countrows = 0;

	LootTemplateVector *pvec;
	LootTemplate	loottemp;
	uint32			creatureId, itemId;
	float			chance;

	do {
		Field *fields = result->Fetch();

		creatureId = fields[0].GetUInt32();
		itemId = fields[1].GetUInt32();
		chance = fields[2].GetFloat();

#if _DEBUG
		ItemPrototype	* itemProto = GetItemPrototype (itemId);
		CreatureTemplate * creature = GetCreatureTemplate (creatureId, false);
		if (itemProto == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Item does not exist",
			//	creatureId, itemId);
			continue;
		}
		if (creature == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Creature does not exist",
			//	creatureId, itemId);
			continue;
		}
		/*if (itemProto->RequiredLevel > creature->Level[1] + 5) {
			sLog.outError ("ERR loot template creature %d item %d: Loot higher than creature level+5",
				creatureId, itemId);
			continue;
		}*/
#endif

		LootTemplateVectorMap::iterator	ivec = m_lootTemplates.find (creatureId);
		if (ivec == m_lootTemplates.end()) {
			pvec = new LootTemplateVector;
			m_lootTemplates[creatureId] = pvec;
			++count;
		} else {
			pvec = ivec->second;
		}

		loottemp.ItemId = itemId;
		loottemp.Chance = chance;

		pvec->push_back (loottemp);

		++countrows;
		ProgressBarShow (countrows, progressTotal, "       ::Loading Loot Templates");

	} while( result->NextRow() );
	ProgressBarHide();

	sLog.outString( "        >=[%d LootTemplates for %d Creatures]", countrows, count );
	delete result; // Don't forget to free pointers 
}

void
ObjectMgr::LoadStaticLootTemplates() 
{
	// Get count of all creature loots
	//
	QueryResult *result = sDatabase.Query( "SELECT COUNT(common_Mob) FROM items" );
	if( !result ) {sLog.outString (" ERROR: 'ITEMS' table HAS NO STATIC LOOTS / CREATURES WILL NOT LOOT STATIC ITEMS"); return;}
	Field *fields = result->Fetch();
	
	uint32 progressTotal = fields[0].GetUInt32();

	delete result;

	// Now load creature loots
	//
	result = sDatabase.Query( "SELECT common_Mob, item_id, common_Percent FROM items" );
	if( !result ) return;

	uint32	count = 0;		// to count errors and stop printing warnings at 10+
	uint32	countrows = 0;

	LootTemplateVector *pvec;
	LootTemplate	loottemp;
	uint32			creatureId, itemId;
	float			chance;

	do {
		Field *fields = result->Fetch();

		creatureId = fields[0].GetUInt32();
		itemId = fields[1].GetUInt32();
		chance = fields[2].GetFloat();

#if _DEBUG
		ItemPrototype	* itemProto = GetItemPrototype (itemId);
		CreatureTemplate * creature = GetCreatureTemplate (creatureId, false);
		if (itemProto == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Item does not exist",
			//	creatureId, itemId);
			continue;
		}
		if (creature == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Creature does not exist",
			//	creatureId, itemId);
			continue;
		}
		/*if (itemProto->RequiredLevel > creature->Level[1] + 5) {
			sLog.outError ("ERR loot template creature %d item %d: Loot higher than creature level+5",
				creatureId, itemId);
			continue;
		}*/
#endif

		LootTemplateVectorMap::iterator	ivec = m_lootTemplates.find (creatureId);
		if (ivec == m_lootTemplates.end()) {
			pvec = new LootTemplateVector;
			m_lootTemplates[creatureId] = pvec;
			++count;
		} else {
			pvec = ivec->second;
		}

		loottemp.ItemId = itemId;
		loottemp.Chance = chance;

		pvec->push_back (loottemp);

		++countrows;
		ProgressBarShow (countrows, progressTotal, "Load Static Loots");

	} while( result->NextRow() );
	ProgressBarHide();

	sLog.outString( "        >=[%d Static Loot templates for %d Creatures]", countrows, countrows );
	delete result; // Don't forget to free pointers 
}

void
ObjectMgr::LoadSellTemplates() 
{
	QueryResult *result = sDatabase.Query( "SELECT creature_id, item_id FROM sell_templ" );

	if( !result ) return;
	
	uint32	count = 0;
	uint32	countrows = 0;
	
	SellTemplate * pvec;
	uint32		creatureId, itemId;
	uint32		numErrors = 0;

	do {
		Field *fields = result->Fetch();

		creatureId = fields[0].GetUInt32();
		itemId = fields[1].GetUInt32();

#if _DEBUG
		ItemPrototype	* itemProto = GetItemPrototype (itemId);
		if (itemProto == NULL) {
			++numErrors;
			if (numErrors < 10)
				sLog.outError ("         >{ERR SellTpl Creature %d Item %d: Item does not exist}",
					creatureId, itemId);
			else if (numErrors == 10)
				sLog.outError ("         >{...}");
			continue;
		}
		if (itemProto->BuyPrice == 0 || itemProto->BuyPrice > 50000000) {
			char description[256];
			itemProto->Describe (description);

			++numErrors;
			if (numErrors < 10)
				sLog.outError ("         >{ERR SellTpl Creature %d: %s Bad buy price: %d}",
					creatureId, description, itemProto->BuyPrice);
			else if (numErrors == 10)
				sLog.outError ("         >{...}");
			continue;
		}
		/*
		if (itemProto->Class == 15) {
			char description[256];
			itemProto->Describe (description);

			sLog.outError ("ERR sell template creature %d: %s Junk item class. Vendors never sell junk",
				creatureId, description);
			continue;
		}
		*/
#endif

		SellTemplateMap::iterator	ivec = m_sellTemplates.find (creatureId);
		if (ivec == m_sellTemplates.end()) {
			pvec = new SellTemplate;
			m_sellTemplates[creatureId] = pvec;
			++count;
		} else {
			pvec = ivec->second;
		}

		pvec->push_back (itemId);
		++countrows;
	
	} while( result->NextRow() );

	sLog.outString( "        >=[%d items for sale at %d vendors]", countrows, count );
	delete result; // Don't forget to free pointers 
}

void
ObjectMgr::LoadGOLootTemplates() 
{
	// Get count of all GO loots
	//
	QueryResult *result = sDatabase.Query( "SELECT COUNT(objloot_id) FROM gameobj_loot" );
	if( !result ) return;
	Field *fields = result->Fetch();
	
	uint32 progressTotal = fields[0].GetUInt32();
	uint32 progressPos = 0;
	
	delete result;

	// Now load GO loots
	//
	result = sDatabase.Query( "SELECT obj_id, item_id, chance FROM gameobj_loot" );
	if( !result ) return;

	uint32	count = 0;		// to count errors and stop printing warnings at 10+
	uint32	countrows = 0;

	LootGOTemplateVector *pvec;
	LootGOTemplate	go_loottemp;
	uint32			obj_Id, itemId;
	float			chance;

	do {
		Field *fields = result->Fetch();

		obj_Id = fields[0].GetUInt32();
		itemId = fields[1].GetUInt32();
		chance = fields[2].GetFloat();

#if _DEBUG
		ItemPrototype	* itemProto = GetItemPrototype (itemId);
		GameobjectTemplate *gameObject = GetGameobjectTemplate (obj_Id);
		if (itemProto == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Item does not exist",
			//	creatureId, itemId);
			continue;
		}
		if (gameObject == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Creature does not exist",
			//	creatureId, itemId);
			continue;
		}
		/*if (itemProto->RequiredLevel > creature->Level[1] + 5) {
			sLog.outError ("ERR loot template creature %d item %d: Loot higher than creature level+5",
				creatureId, itemId);
			continue;
		}*/
#endif

		LootGOTemplateVectorMap::iterator	ivec = m_lootGOTemplates.find (obj_Id);
		if (ivec == m_lootGOTemplates.end()) {
			pvec = new LootGOTemplateVector;
			m_lootGOTemplates[obj_Id] = pvec;
			++count;
		} else {
			pvec = ivec->second;
		}

		go_loottemp.ItemId = itemId;
		go_loottemp.Chance = chance;

		pvec->push_back (go_loottemp);

		++countrows;
		ProgressBarShow (countrows, progressTotal, "Load GO Loot Templates");

	} while( result->NextRow() );
	ProgressBarHide();

	sLog.outString( "        >=[%d loot templates for %d GOs]", countrows, count );
	delete result; // Don't forget to free pointers 
}

void
ObjectMgr::LoadWorldLoots() 
{
	// Now loots
	QueryResult *result = sDatabase.Query( "SELECT monster_level, elite, item_id, chance FROM world_loot" );
	if( !result ) return;

	uint32	count = 0;		// to count errors and stop printing warnings at 10+
	uint32	countrows = 0;

	WorldLootTemplateVector *pvec;
	WorldLootTemplate	worldloottemp;
	uint32				monster_level, item_id, elite;
	float				chance;

	do {
		Field *fields = result->Fetch();

		monster_level = fields[0].GetUInt32();
		elite = fields[1].GetUInt32();
		item_id = fields[2].GetUInt32();
		chance = fields[3].GetFloat();

#if _DEBUG
		ItemPrototype	* itemProto = GetItemPrototype (item_id);
		if (itemProto == NULL) {
			// ProgressBarHide();
			//sLog.outError ("ERR loot template creature %d item %d: Item does not exist",
			//	creatureId, itemId);
			continue;
		}
		/*if (itemProto->RequiredLevel > creature->Level[1] + 5) {
			sLog.outError ("ERR loot template creature %d item %d: Loot higher than creature level+5",
				creatureId, itemId);
			continue;
		}*/
#endif

		WorldLootTemplateVectorMap::iterator	ivec = m_WorldLootTemplates.find (item_id);
		if (ivec == m_WorldLootTemplates.end()) {
			pvec = new WorldLootTemplateVector;
			m_WorldLootTemplates[item_id] = pvec;
			++count;
		} else {
			pvec = ivec->second;
		}

		worldloottemp.monster_level = monster_level;
		worldloottemp.elite = elite;
		worldloottemp.item_id = item_id;
		worldloottemp.chance = chance;

		pvec->push_back (worldloottemp);

		++countrows;
	} while( result->NextRow() );
	delete result; // Don't forget to free pointers 
	sLog.outString( "        >=[%d WorldLoot templates with %d Items]", countrows, count );
}

void
ObjectMgr::WipeRecycles()
{
	while (! mCreaturesDeleted.empty()) {
		Creature * cr = mCreaturesDeleted.begin()->second;
		
		if (cr->isInCombat())	cr->ClearHate();

		//cr->ClearInRangeSet();
		delete cr;
		mCreaturesDeleted.erase (mCreaturesDeleted.begin());
	}
	while (! mGameObjectsDeleted.empty()) {
		delete mGameObjectsDeleted.begin()->second;
		mGameObjectsDeleted.erase (mGameObjectsDeleted.begin());
	}
	while (! mDynamicObjectsDeleted.empty()) {
		delete mDynamicObjectsDeleted.begin()->second;
		mDynamicObjectsDeleted.erase (mDynamicObjectsDeleted.begin());
	}
	while (! mCorpsesDeleted.empty()) {
		delete mCorpsesDeleted.begin()->second;
		mCorpsesDeleted.erase (mCorpsesDeleted.begin());
	}
	while (! mPlayersDeleted.empty()) {
		delete mPlayersDeleted.begin()->second;
		mPlayersDeleted.erase (mPlayersDeleted.begin());
	}
}
