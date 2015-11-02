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

#include "../LogonServer/LogonSocket.h"
#include "../LogonServer/LogonSocketMgr.h"
#include "../LogonServer/RealmList.h"

#include "../Game/Server/WS/WorldSocket.h"
#include "../Game/Server/WS/WorldSocketMgr.h"

createFileSingleton( Master );

volatile bool Master::m_stopEvent = false;


void
Master::_OnSignal(int s)
{
    switch (s)
    {
    case SIGINT:
        Master::m_stopEvent = true;
        break;
    case SIGTERM:
        Master::m_stopEvent = true;
        break;
    case SIGABRT:
        Master::m_stopEvent = true;
        break;
#ifdef _WIN32
    case SIGBREAK:
        Master::m_stopEvent = true;
        break;
#endif
    }

    signal(s, _OnSignal);
}


Master::Master()
{
}



Master::~Master()
{
}



bool
Master::Run()
{
	sLog.outColor(0);
	sLog.outString( "    ::[  Welcome on %s  ]::", FULLSERVERNAME);
    sLog.outString( "Press Ctrl-C or type 'quit' at anytime to safely exit server.\n" );

	LogonSocket::Patcher.LoadPatcheIDs();

	_StartDB();

    loglevel = (uint8)sConfig.GetIntDefault("LogLevel", DEFAULT_LOG_LEVEL);
    logchat  = (uint8)sConfig.GetIntDefault("LogChat", DEFAULT_LOG_LEVEL);
	uint32 autosavetime = (uint32)sConfig.GetIntDefault("AutoSaveTime", DEFAULT_SAVE_TIME);

    new World;

    sWorld.SetPlayerLimit( sConfig.GetIntDefault("PlayerLimit", DEFAULT_PLAYER_LIMIT) );
    sWorld.SetMotd( sConfig.GetStringDefault("Motd", "Welcome on this CrFusion Realm" ).c_str() );
	sWorld.SetInitialWorldSettings();

// Network:
	sLog.outColor(0);

	// Settings for LogonServer and WorldServer:
	std::string host;
	host = sConfig.GetStringDefault( "Host", DEFAULT_HOST );
	sLog.outString( "Server Listen at: %s", host.c_str() );

	port_t lsport = sConfig.GetIntDefault( "LogonServerPort", DEFAULT_LOGONSERVER_PORT );
	port_t wsport = sConfig.GetIntDefault( "WorldServerPort", DEFAULT_WORLDSERVER_PORT );

	// Load realmlist from SQL Table or Conf:
	bool sqlrealm = sConfig.GetBoolDefault( "SqlRealmList", false );
	
	if(sqlrealm)
		sRealmList.LoadRealms();
	else
	{
		// Format: Realm_Name, Realm_IP:Port, Icon (0 = Normal, 1 = PVP), Color (0 = Yellow, 1 = Red), TimeZone (1 - 4)
		std::string rmname = sConfig.GetStringDefault( "RealmName", "[CRFusion Realm]" );
		std::string rmhost = sConfig.GetStringDefault( "RealmAddr", host.c_str() );
		port_t rmport      = sConfig.GetIntDefault( "RealmPort",  wsport );
		int popcoeff       = sConfig.GetIntDefault( "RealmMaxChar", 250 );

		QueryResult* result = sDatabase.Query( "SELECT COUNT(*) FROM characters" );
		Field *fields = result->Fetch();
		int poptotal = fields[0].GetUInt32();

		std::stringstream addr;
		addr << rmhost << ":" << rmport;

		Realm *TmpRealm = new Realm ( );
		TmpRealm->address = addr.str().c_str();
		TmpRealm->name = rmname.c_str();
		TmpRealm->timezone = sConfig.GetIntDefault( "RealmZone",  1 );
		TmpRealm->icon = sWorld.GetRealmRules();
		TmpRealm->color = sConfig.GetIntDefault( "RealmColor", 0 );
		TmpRealm->population = (poptotal/popcoeff);

		sRealmList.AddRealm ( TmpRealm );
	}

	SocketHandler h;
    ListenSocket<WorldSocket> worldListenSocket(h);
    ListenSocket<LogonSocket> authListenSocket (h);

    if (worldListenSocket.Bind(wsport) || authListenSocket.Bind(lsport))
    {
        delete World::getSingletonPtr();
        _StopDB();
        sLog.outString(LANG_WORLD_NOBIND);
        exit(1);
    }

    h.Add(&worldListenSocket);
    h.Add(&authListenSocket);

	sLog.outString (LANG_WORLD_RSERVP, lsport);
	sLog.outString (LANG_WORLD_WSERVP, wsport);

// World:

    _HookSignals();

    ZThread::Thread t(new WorldRunnable);
	t.setPriority ((ZThread::Priority)2);

    uint32 realCurrTime, realPrevTime;
    realCurrTime = realPrevTime = getMSTime();
	sLog.outColor(3);
	sLog.outString ("     ::[- Server Ready! -]::");
	sLog.outColor(2);

	CConsoleCmds ConsoleCmds;
	
	while (!Master::m_stopEvent)
    {
        // uint32 exceeded
        if (realPrevTime > realCurrTime)
            realPrevTime = 0;

        realCurrTime = getMSTime();
        sWorldSocketMgr.Update( realCurrTime - realPrevTime );
		sLogonSocketMgr.Update( realCurrTime - realPrevTime );
        realPrevTime = realCurrTime;

        h.Select(0, 75000); // 75 ms

		ConsoleCmds.Do();
    }

    _UnhookSignals();

    t.wait();
    delete World::getSingletonPtr();

    _StopDB();

	sLog.outColor(3);
    sLog.outString( "Halting process..." );
    return 0;
}


bool
Master::_StartDB()
{
    ASSERT(new DatabaseMysql);

    std::string dbstring;

    if(!sConfig.GetString("DatabaseInfo", &dbstring))
    {
        sLog.outError("Database not specified");
        return false;
    }

	sLog.outString(" ::Database:");
    istringstream dbconf( dbstring );
    string current;
	int curr = 1;
	while ( std::getline( dbconf, current, ';' ) )
    {
		switch(curr)
		{
		case 1:
			sLog.outString("  |>Host: %s", current.c_str());
			break;
		case 2:
			sLog.outString("  |>User: %s", current.c_str());
			break;
		case 3:
			sLog.outString("  |>Pass: %s", current.c_str());
			break;
		case 4:
			sLog.outString("  |>Name: %s", current.c_str());
			break;
		}
        curr++;
    }

    if(!sDatabase.Initialize(dbstring.c_str()))
    {
		sLog.outError(" ::Cannot connect to database");
        return false;
    }
	else
	{
		sLog.outString(" ::Done.");
	}
    return true;
}


void
Master::_StopDB()
{
    delete Database::getSingletonPtr();
}


void
Master::_HookSignals()
{
    signal(SIGINT, _OnSignal);
    signal(SIGTERM, _OnSignal);
    signal(SIGABRT, _OnSignal);
#ifdef _WIN32
    signal(SIGBREAK, _OnSignal);
#endif
}


void
Master::_UnhookSignals()
{
    signal(SIGINT, 0);
    signal(SIGTERM, 0);
    signal(SIGABRT, 0);
#ifdef _WIN32
    signal(SIGBREAK, 0);
#endif

}

