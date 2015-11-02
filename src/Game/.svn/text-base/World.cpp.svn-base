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
#include "../Shared/FactionTemplates.h"

initialiseSingleton( World );


World::World()
{
	m_ShutdownTimer = 0;
    m_playerLimit = 0;
	m_RealmRules = REALMRULE_NORMAL;
	m_uptime = 0;
	m_Last_tick = time(NULL);
	m_Warden_Timer = 720;
}


World::~World()
{
	mPrices.clear();
}


WorldSession* World::FindSession(uint32 id)
{
	ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);

    SessionMap::const_iterator itr = m_sessions.find(id);

    if(itr != m_sessions.end())
        return itr->second;
    else
        return NULL;
}


void
World::AddSession(WorldSession* s)
{
	ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);

    ASSERT(s);
    m_sessions[s->GetAccountId()] = s;
}


void
World::SetInitialWorldSettings()
{
    // clear logfile
    if (sConfig.GetBoolDefault ("WorldServLogFile", false))
    {
        FILE *pFile = fopen("world.log", "w+");
        fclose(pFile);
    }

    srand((unsigned int)time(NULL));

    m_lastTick = time(NULL);

    // TODO: clean this
    time_t tiempo;
    char hour[3];
    char minute[3];
    char second[3];
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    strftime( hour, 3, "%H", tmPtr );
    strftime( minute, 3, "%M", tmPtr );
    strftime( second, 3, "%S", tmPtr );
    m_gameTime = (3600*atoi(hour))+(atoi(minute)*60)+(atoi(second)); // server starts at current hour :)

    // TODO: clean this
    // fill in emotes table
    // it appears not every emote has an animation
	mPrices[1]	= 10;
	mPrices[4]	= 80;
	mPrices[6]	= 150;
	mPrices[8]	= 200;
	mPrices[10]	= 300;
	mPrices[12]	= 800;
	mPrices[14]	= 900;
	mPrices[16]	= 1800;
	mPrices[18]	= 2200;
	mPrices[20]	= 2300;
	mPrices[22]	= 3600;
	mPrices[24]	= 4200;
	mPrices[26]	= 6700;
	mPrices[28]	= 7200;
	mPrices[30]	= 8000;
	mPrices[32]	= 11000;
	mPrices[34]	= 14000;
	mPrices[36]	= 16000;
	mPrices[38]	= 18000;
	mPrices[40]	= 20000;
	mPrices[42]	= 27000;
	mPrices[44]	= 32000;
	mPrices[46]	= 37000;
	mPrices[48]	= 42000;
	mPrices[50]	= 47000;
	mPrices[52]	= 52000;
	mPrices[54]	= 57000;
	mPrices[56]	= 62000;
	mPrices[58]	= 67000;
	mPrices[60]	= 72000;

	new ChannelMgr;

	initMT();	// init random generator
	initFactionTemplates();

	// DO NOT CHANGE order of loading, they depend each on another
	//
	sLog.outColor(4);
	sLog.outString("");
	sLog.outString("   .");
	sLog.outString("   ³");
	sLog.outString(" úÄÅÄÄÄÄÄÄÄÄÄúú");
	sLog.outString("   ³    Team-Cr 2006 Proudly Presents:                                   .");
	sLog.outString("   ³       CrFusion, a WoW(c) Server Simulator for Win32 and Unix        ³");
	sLog.outString("   ³         Based on all the bests emu sources :)                       ³");
	sLog.outString("                                                               úúÄÄÄÄÄÄÄÄÅÄÄ.");
	sLog.outString("                                                                         :");
	sLog.outString("  ÅÄÄÄÄÄÄÄÄú                 úGreetingsú                          úÄÄÄÄÅ");
	sLog.outString("  ³    úMiscú                                                          ³");
	sLog.outString("  ³ Greetz to SECTiON-8                                                ³");
	sLog.outString("  ³ All the Team-Cr crew                                               ³");
	sLog.outString("  ³ All the BlackStorm crew                                            ³");
	sLog.outString("  ÅÄÄÄÄú                                                      úÄÄÄÄÄÄÄÄÅ");
	sLog.outString("");
	sLog.outColor(3);
	sLog.outString ("             ::Opening DBC storages::");
	sLog.outColor(0);
	sLog.outString("[------------------- DBC --------------------------]");
	sLog.outColor(2);
	sLog.outString(" >> SkillLineAbility.dbc");
		new SkillStore("dbc/SkillLineAbility.dbc");
	sLog.outString(" >> EmotesText.dbc");
		new EmoteStore("dbc/EmotesText.dbc");
	sLog.outString(" >> Spell.dbc");
		new SpellStore("dbc/Spell.dbc");
	sLog.outString(" >> SpellRange.dbc");
		new RangeStore("dbc/SpellRange.dbc");
	sLog.outString(" >> SpellCastTimes.dbc");
		new CastTimeStore("dbc/SpellCastTimes.dbc");
	sLog.outString( " >> SpellDuration.dbc");
		new DurationStore("dbc/SpellDuration.dbc");
	sLog.outString( " >> SpellRadius.dbc");
		new RadiusStore("dbc/SpellRadius.dbc");
	sLog.outString( " >> Talent.dbc");
		new TalentStore("dbc/Talent.dbc");
	sLog.outString( " >> AreaTable.dbc");
		new AreaTableStore("dbc/AreaTable.dbc");
	sLog.outString( " >> WorldMapArea.dbc");
		new WorldMapAreaStore ("dbc/WorldMapArea.dbc");
	objmgr.LoadWorldMapArea();
	sLog.outString( " >> WorldMapOverlay.dbc");
		new WorldMapOverlayStore("dbc/WorldMapOverlay.dbc");
	sLog.outString( " >> ItemRandomProperties.dbc");
		new ItemRandomPropertiesStore("dbc/ItemRandomProperties.dbc");
	sLog.outString( " >> SpellItemEnchantment.dbc");
		new SpellItemEnchantmentStore("dbc/SpellItemEnchantment.dbc");
	sLog.outString( " >> Faction.dbc");
		new FactionStore("dbc/Faction.dbc");
	sLog.outString( " >> TaxiPath.dbc");
		new TaxiPathStore("dbc/TaxiPath.dbc");
		objmgr.LoadTaxiNodes();
		objmgr.LoadTaxiPath();
	sLog.outString( " >> TaxiPathNode.dbc");
		new TaxiPathNodeStore("dbc/TaxiPathNode.dbc");
		objmgr.LoadTaxiPathNodes();
	sLog.outString( " >> ChatChannels.dbc");
		new ChatChannelsStore("dbc/ChatChannels.dbc");
	sLog.outColor(0);
	sLog.outString("[--------------------------------------------------]");
	sLog.outColor(4);
	sLog.outString("           ::DBC storages: Done!" );
	sLog.outString("");
	sLog.outString("           ::Precaching MySQL DB tables::" );
	sLog.outColor(0);
	sLog.outString("[-------------------  Items -----------------------]");
	sLog.outColor(2);
	objmgr.LoadItemPrototypes();
	sLog.outString("");
	sLog.outColor(0);
	sLog.outString("[-------------------  Creatures -------------------]");
	sLog.outColor(2);
	objmgr.LoadCreatureTemplates();
	objmgr.LoadTrainerSpells();
	objmgr.LoadSellTemplates();
	objmgr.LoadWorldLoots();
	objmgr.LoadLootTemplates();
	objmgr.LoadStaticLootTemplates();
	sLog.outString("");
	sLog.outColor(0);
	sLog.outString("[-------------------  Gameobjects -----------------]");
	sLog.outColor(2);
	objmgr.LoadGameobjectTemplates();
	objmgr.LoadGOLootTemplates();
	sLog.outString("");
	sLog.outColor(0);
	sLog.outString("[--------------------------------------------------]");
	sLog.outColor(3);
	sLog.outString("           ::MySQL DB tables: Done!" );
	sLog.outString("");

	sLog.outColor(4);
	sLog.outString("       ::Precaching Item Instances..." );
	objmgr.LoadAuctions();
	objmgr.LoadAuctionItems();
	objmgr.LoadMailedItems();
	sLog.outString("");

	sLog.outString("       ::Precaching Quests..." );
	objmgr.LoadQuests();
	sLog.outString("");

	sLog.outString("       ::Precaching World..." );
	objmgr.LoadWorldSpawns();
	objmgr.LoadGameobjects();
	sLog.outString("");

	sLog.outString("       ::Loading Corpses..." );
    objmgr.LoadCorpses();
	sLog.outString("");

    sLog.outString("       ::Loading Guilds..." );
    objmgr.LoadGuilds();
	sLog.outString("");

    sLog.outString("       ::Precaching Graveyards..." );
    objmgr.LoadGraveyards();
	sLog.outString("");

	sLog.outString("       ::Analysing Spells for Trainers..." );
	objmgr.LoadTrainerTeachSpells();
    objmgr.SetHighestGuids();
	sLog.outString("");
	
	sLog.outString("       ::Setting Update Timers...");
	sDatabase.Execute ("UPDATE characters SET online = 0");
    m_timers[WUPDATE_OBJECTS].SetInterval  ((time_t)sConfig.GetIntDefault("UpdateTimer_Objects", 400));
    m_timers[WUPDATE_SESSIONS].SetInterval ((time_t)sConfig.GetIntDefault("UpdateTimer_Sessions", 180)); 
	m_timers[WUPDATE_AUCTIONS].SetInterval ((time_t)sConfig.GetIntDefault("UpdateTimer_Auctions", 3500));

	m_RealmRules = (uint8)sConfig.GetIntDefault( "RealmRules", REALMRULE_NORMAL);
	std::string strules;
	switch(m_RealmRules)
	{
	case REALMRULE_NORMAL:	strules = LANG_WORLD_REALMR_NRM; break;
	case REALMRULE_PVP:		strules = LANG_WORLD_REALMR_PVP; break;
	case REALMRULE_PVE:		strules = LANG_WORLD_REALMR_PVE; break;
	case REALMRULE_RPNRM:	strules = LANG_WORLD_REALMR_RPN; break;
	case REALMRULE_RPPVP:	strules = LANG_WORLD_REALMR_RPP; break;
	}
	sLog.outColor(4);
	sLog.outString ("");
	sLog.outString ("       ::Server Rules: %s", strules.c_str());
	sLog.outString ("");
	sLog.outString ("     .:[Server Loading Done]:.");
	sLog.outString ("");

	//-----------------------------------------------------------------
	sLog.outString(" ::[Populating world with stuff...]");
	sLog.outString("  ::WORLD: Placing Player Corpses" );
    for (ObjectMgr::CorpseMap::const_iterator i = objmgr.Begin<Corpse>(); i != objmgr.End<Corpse>(); ++i)
        i->second->PlaceOnMap();
	sLog.outString("  ::WORLD: SetInitialWorldSettings done" );
	sLog.outColor(2);
}


void
World::Update(time_t diff)
{
    _UpdateGameTime();
    for(int i = 0; i < WUPDATE_COUNT; ++i)
        m_timers[i].Update(diff);


	// TODO: make sure that all objects get their updates, not just characters and creatures
    if (m_timers[WUPDATE_OBJECTS].Passed())
    {
        m_timers[WUPDATE_OBJECTS].Reset();

		ObjectMgr::PlayerMap::iterator chriter;
        for( chriter = objmgr.Begin<Player>(); chriter != objmgr.End<Player>( ); ++ chriter )
            chriter->second->Update( (uint32)diff );

		// Update creatures and gameobjects in active map cells
		//
		MapMgr	*mapm;
		for (int mapid = 0; mapid<=1; ++mapid) 
		{
			if(isMapId(mapid))
			{
				mapm = sWorld.GetMap (mapid);
				mapm->UpdateActiveObjects ((uint32)diff);
			}
		}

		// Update dynamic objects (spell visual effects)
		//
		ObjectMgr::DynamicObjectMap::iterator diter;
        for( diter = objmgr.Begin<DynamicObject>(); diter != objmgr.End<DynamicObject>( ); ++ diter )
            diter->second->Update( (uint32)diff );
    }


	if (m_timers[WUPDATE_SESSIONS].Passed())
	{
		m_timers[WUPDATE_SESSIONS].Reset();

		SessionMap::iterator itr, next;
		for (itr = m_sessions.begin(); itr != m_sessions.end(); itr = next)
		{
			next = itr;
			++next;

			if(!itr->second->Update((uint32)diff))
			{
				ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);
				delete itr->second;
				m_sessions.erase(itr);
			}
		}
	}


	if (m_timers[WUPDATE_AUCTIONS].Passed())
	{
		m_timers[WUPDATE_AUCTIONS].Reset();
		ObjectMgr::AuctionEntryMap::iterator itr,next;
		for (itr = objmgr.GetAuctionsBegin(); itr != objmgr.GetAuctionsEnd();itr = next)
		{
			next = itr;
			++next;
			if (time(NULL) > (itr->second->time))
			{
				if (itr->second->bidder == 0)
				{
					Mail *m = new Mail;
					m->reciever = itr->second->owner;
					m->body = "";
					m->sender = itr->second->owner;
					m->checked = 0;
					m->COD = 0;
					m->messageID = objmgr.GenerateMailID();
					m->money = 0;
					m->time = time(NULL) + (29 * 3600);
					m->subject = "Your item failed to sell";
					m->item = itr->second->item;
					Item *it = objmgr.GetAItem(m->item);
					objmgr.AddMItem(it);

					std::stringstream ss;
					ss << "INSERT INTO mailed_items (guid, data) VALUES ("
						<< it->GetGUIDLow() << ", '";
					for(uint16 i = 0; i < it->GetValuesCount(); ++i )
					{
						ss << it->GetUInt32Value(i) << " ";
					}
					ss << "' )";
					sDatabase.Execute( ss.str().c_str() );

					std::stringstream md;
					md << "DELETE FROM mail WHERE mailID = " << m->messageID;
					sDatabase.Execute( md.str().c_str( ) );

					std::stringstream mi;
					mi << "INSERT INTO mail (mailId,sender,reciever,subject,body,item,"
						"time,money,COD,checked) VALUES ( " << m->messageID << ", "
						<< m->sender << ", " << m->reciever << ",' " << m->subject.c_str()
						<< "' ,' " << m->body.c_str() << "', " << m->item << ", "
						<< (uint32)m->time << ", " << m->money << ", " << 0 << ", "
						<< m->checked << " )";
					sDatabase.Execute( mi.str().c_str( ) );

					uint64 rcpl;
					GUID_LOPART(rcpl) = m->reciever;
					GUID_HIPART(rcpl) = 0;
					std::string pname;
					objmgr.GetPlayerNameByGUID(rcpl,pname);
					Player *rpl = objmgr.GetPlayer(pname.c_str());
					if (rpl)
					{
						rpl->AddMail(m);
					}
					std::stringstream delinvq;
					std::stringstream id;
					std::stringstream bd;
					delinvq << "DELETE FROM auctionhouse WHERE itemowner = " << m->reciever;
					sDatabase.Execute( delinvq.str().c_str( ) );

					id << "DELETE FROM auctioned_items WHERE guid = " << m->item;
					sDatabase.Execute( id.str().c_str( ) );

					bd << "DELETE FROM bids WHERE Id = " << itr->second->Id;
					sDatabase.Execute( bd.str().c_str( ) );

					objmgr.RemoveAuction(itr->second->Id);
				}
				else
				{
					Mail *m = new Mail;
					m->reciever = itr->second->owner;
					m->body = "";
					m->sender = itr->second->bidder;
					m->checked = 0;
					m->COD = 0;
					m->messageID = objmgr.GenerateMailID();
					m->money = itr->second->bid;
					m->time = time(NULL) + (29 * 3600);
					m->subject = "Your item sold!";
					m->item = 0;

					std::stringstream md;
					md << "DELETE FROM mail WHERE mailID = " << m->messageID;
					sDatabase.Execute( md.str().c_str( ) );

					std::stringstream mi;
					mi << "INSERT INTO mail (mailId,sender,reciever,subject,body,item,"
						"time,money,COD,checked) VALUES ( " << m->messageID << ", " << m->sender
						<< ", " << m->reciever << ",' " << m->subject.c_str() << "' ,' "
						<< m->body.c_str() << "', " << m->item << ", " << (uint32)m->time
						<< ", " << m->money << ", " << 0 << ", " << m->checked << " )";
					sDatabase.Execute( mi.str().c_str( ) );

					uint64 rcpl;
					GUID_LOPART(rcpl) = m->reciever;
					GUID_HIPART(rcpl) = 0;
					std::string pname;
					objmgr.GetPlayerNameByGUID(rcpl,pname);
					Player *rpl = objmgr.GetPlayer(pname.c_str());
					if (rpl)
					{
						rpl->AddMail(m);
					}

					Mail *mn = new Mail;
					mn->reciever = itr->second->bidder;
					mn->body = "";
					mn->sender = itr->second->owner;
					mn->checked = 0;
					mn->COD = 0;
					mn->messageID = objmgr.GenerateMailID();
					mn->money = 0;
					mn->time = time(NULL) + (29 * 3600);
					mn->subject = "Your won an item!";
					mn->item = itr->second->item;
					Item *it = objmgr.GetAItem(itr->second->item);
					objmgr.AddMItem(it);

					std::stringstream ss;
					ss << "INSERT INTO mailed_items (guid, data) VALUES ("
						<< it->GetGUIDLow() << ", '";
					for(uint16 i = 0; i < it->GetValuesCount(); ++i )
					{
						ss << it->GetUInt32Value(i) << " ";
					}
					ss << "' )";
					sDatabase.Execute( ss.str().c_str() );

					std::stringstream mdn;

					mdn << "DELETE FROM mail WHERE mailID = " << mn->messageID;
					sDatabase.Execute( mdn.str().c_str( ) );

					std::stringstream min;

					min << "INSERT INTO mail (mailId,sender,reciever,subject,body,"
						"item,time,money,COD,checked) VALUES ( "
						<< mn->messageID << ", " << mn->sender << ", " << mn->reciever
						<< ",' " << mn->subject.c_str() << "' ,' " << mn->body.c_str()
						<< "', " << mn->item << ", " << (uint32)mn->time << ", "
						<< mn->money << ", " << 0 << ", " << mn->checked << " )";

					sDatabase.Execute( min.str().c_str( ) );

					uint64 rcpl1;
					GUID_LOPART(rcpl1) = mn->reciever;
					GUID_HIPART(rcpl1) = 0;

					std::string pname1;
					objmgr.GetPlayerNameByGUID(rcpl1,pname1);
					Player *rpl1 = objmgr.GetPlayer(pname1.c_str());
					if (rpl1)
					{
						rpl1->AddMail(mn);
					}
					objmgr.RemoveAItem(itr->second->item);
					objmgr.RemoveAuction(itr->second->Id);
				}
			}
		}
	}

	if (m_Warden_Timer <= 0)
	{
		m_Warden_Timer = 720;
		ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);
		WorldPacket WardenPkt;

		sLog.outDetail("Initializing Full Warden Scan");
		WardenPkt.Initialize(SMSG_WARDEN_DATA);

		SessionMap::iterator itr;
		for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
		{
			itr->second->SendPacket(&WardenPkt);
		}
	}
	for (MapMgrMap::iterator iter = m_maps.begin(); iter != m_maps.end(); ++iter)
	{
		iter->second->Update(diff);
	}

	// When everything is safe, wipe recycles
	objmgr.WipeRecycles();
}


void
World::SendGlobalMessage(WorldPacket *packet, WorldSession *self)
{
	ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);

    SessionMap::iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second != self)
        {
            itr->second->SendPacket(packet);
        }
    }
}


void
World::SendPacketToZone(WorldPacket *packet, uint32 zoneId)
{
	ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);
    SessionMap::iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
		Player* cPlayer = itr->second->GetPlayer();
        if (!cPlayer || !cPlayer->IsInWorld())	continue;
		if (cPlayer->GetZoneId() == zoneId)
			itr->second->SendPacket(packet);
		cPlayer=NULL;
    }
}


void
World::SendWorldText(const char* text, WorldSession *self)
{
    WorldPacket data;
    sChatHandler.FillSystemMessageData(&data, 0, text);
    SendGlobalMessage(&data, self);
}


void
World::SendWorldWideText(const char* text, WorldSession *self)
{
	WorldPacket data;
	data.Initialize(SMSG_AREA_TRIGGER_MESSAGE);
	data << (uint32)0 << text << (uint8)0x00;
    SendGlobalMessage(&data, self);
}


void
World::SendWorldString(std::string text)
{
	WorldSession *self = 0;
    WorldPacket data;
	sChatHandler.FillSystemMessageData(&data, 0, text.c_str());
    SendGlobalMessage(&data, self);
}


MapMgr*
World::GetMap(uint32 id)
{
    MapMgrMap::iterator iter = m_maps.find(id);
    if (iter != m_maps.end())
        return iter->second;

    MapMgr *newMap = new MapMgr(id);
    ASSERT(newMap);

    m_maps[id] = newMap;

    return newMap;
}


bool
World::isMapId(uint32 id)
{
	switch(id)
	{
		case 0: //Azeroth
		case 1: //Kalimdor
		case 13: //test
		case 25: //ScottTest
		case 29: //Test
		case 30: //PVPZone01
		case 33: //Shadowfang
		case 34: //Stormwind Jail
		case 35: //Stormwind Prison
		case 36: //Deadmines Instance
		case 37: //Azshara Crater
		case 42: //Collin
		case 43: //Wailing Caverns
		case 44: //Monastery
		case 47: //Razorfen Kraul Instance
		case 48: //Blackfathom
		case 70: //Uldaman
		case 90: //Gnomeragon Instance
		case 109: //Sunken Temple
		case 129: //Razorfen Downs
		case 169: //Emerald Dream
		case 189: //Monastery Instances
		case 209: //Tanaris Instance
		case 229: //Blackrock Spire
		case 230: //Blackrock Depths
		case 249: //Onyxia's Lair Instance
		case 289: //School of Necromancy
		case 269: //Caverns Of Time
		case 309: //Zul'gurub
		case 329: //Stratholme
		case 349: //Mauradon
		case 369: //Deeprun Tram
		case 389: //Orgrimmar Instance
		case 409: //Molten Core
		case 429: //Dire Maul
		case 449: //Alliance PVP Barracks
		case 450: //Horde PVP Barracks
		case 451: //development
		case 469: //Blackwing's Lair
		case 489: //Warsong Gulch
		case 509: //Ahn'Qiraj
		case 529: //Arathi basin
			return true;
		default: return false;
	}
}


bool
World::isInstanceMapId(uint32 id)
{
	switch(id)
	{
		case 33: //Shadowfang
		case 34: //Stormwind Jail
		case 35: //Stormwind Prison
		case 36: //Deadmines Instance
		case 43: //Wailing Caverns
		case 44: //Monastery
		case 47: //Razorfen Kraul Instance
		case 48: //Blackfathom
		case 70: //Uldaman
		case 90: //Gnomeragon Instance
		case 109: //Sunken Temple
		case 129: //Razorfen Downs
		case 169: //Emerald Dream
		case 189: //Monastery Instances
		case 209: //Tanaris Instance
		case 229: //Blackrock Spire
		case 230: //Blackrock Depths
		case 249: //Onyxia's Lair Instance
		case 289: //School of Necromancy
		case 269: //Caverns Of Time
		case 309: //Zul'gurub
		case 329: //Stratholme
		case 349: //Mauradon
		case 369: //Deeprun Tram
		case 389: //Orgrimmar Instance
		case 409: //Molten Core
		case 429: //Dire Maul
		case 469: //Blackwing's Lair
		case 509: //Ahn'Qiraj
			return true;
		default: return false;
	}
}


bool
World::isPvPMapId(uint32 id)
{
	switch(id)
	{
		case 30: //PVPZone01
		case 37: //Azshara Crater
		case 489: //Warsong Gulch
		case 529: //Arathi Basin
			return true; 
		default: return false;
	}
}


uint32
World::GetRealmRules()
{
	return m_RealmRules;
}


void
World::ShutdownServ(uint32 time)
{
	m_ShutdownTimer = time;
}


void
World::ShuttingDownMsg()
{
	if(m_ShutdownTimer <= 0)
		raise(SIGINT);
	char msg[256];
	std::stringstream ss;
	WorldPacket data;

	sprintf((char*)msg, "[Server] Shutdown in %d seconds", m_ShutdownTimer);
	SendWorldWideText( msg );

	data.Initialize(SMSG_SERVER_MESSAGE);
	ss << m_ShutdownTimer << " Second(s).";
	data << uint32(1) << ss.str().c_str() << (uint8)0x00;
	SendGlobalMessage( &data );

	data.clear();
	ss.clear();

	sLog.outColor(3);
	sLog.outString("[Server] Shutdown in %d seconds...\n", m_ShutdownTimer);
	sLog.outColor(2);
}
