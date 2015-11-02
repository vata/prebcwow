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

#ifndef __WORLD_H
#define __WORLD_H

#include "../Shared/Timer.h"
#include <zthread/Task.h>
#include <zthread/ZThread.h>

#ifdef _WIN32
	#include <hash_map>
#else
	#include <ext/hash_map>
#endif

class Object;
class Player;
class WorldPacket;
class WorldSession;
class MapMgr;

enum WorldTimers
{
    WUPDATE_OBJECTS = 0,
    WUPDATE_SESSIONS = 1,
	WUPDATE_AUCTIONS = 2,
    WUPDATE_COUNT = 3
};

class World : public Singleton<World>
{
public:
    World();
    ~World();

    WorldSession* FindSession (uint32 id);
    void AddSession(WorldSession *s);

    size_t GetSessionCount()
	{
		ZThread::Guard<ZThread::Mutex> guard(m_sessions_lock);
		return m_sessions.size();
	}
    uint32 GetPlayerLimit() const { return m_playerLimit; }
    void SetPlayerLimit(uint32 limit) { m_playerLimit = limit; }

    void SetMotd(const char *motd) { m_motd = motd; }
    const char* GetMotd() const { return m_motd.c_str(); }

    time_t GetGameTime() const { return m_gameTime; }
	uint32 GetUptime() const { return m_uptime; }

    void SetInitialWorldSettings();

    void SendWorldText(const char *text, WorldSession *self = 0);
	void SendWorldWideText(const char* text, WorldSession *self = 0);
	void SendWorldString(std::string text);
    void SendGlobalMessage(WorldPacket *packet, WorldSession *self = 0);
	void SendPacketToZone(WorldPacket *packet, uint32 zoneId);

	void ShutdownServ(uint32 time);
	void ShuttingDownMsg();

    // update the world server every frame
    void Update(time_t diff);

    // get map manager
    MapMgr* GetMap(uint32 id);
	bool isMapId(uint32 id);
	bool isInstanceMapId(uint32 id);
	bool isPvPMapId(uint32 id);

	uint32 GetRealmRules();

	// map spell prices
    typedef std::map< uint32, uint32> SpellPricesMap;
    SpellPricesMap mPrices;

protected:
    time_t _UpdateGameTime()
    {
        // Update Server time
        time_t thisTime = time(NULL);
		uint32 now = time(NULL),
			elapsed = (now - m_Last_tick);

		if(m_lastTick == NULL)
			m_lastTick = thisTime;
		if(m_ShutdownTimer > 0 && m_ShutdownTimer != now)
		{
			m_ShutdownTimer -= (now - m_Last_tick);
			ShuttingDownMsg();
		}

        m_gameTime += (thisTime - m_lastTick);
		m_uptime += elapsed;
		m_Warden_Timer -= elapsed;

        m_lastTick = thisTime;
		m_Last_tick = now;

        return m_gameTime;
    }

private:
    //! Timers
    IntervalTimer m_timers[WUPDATE_COUNT];

	typedef stdext::hash_map<uint32, WorldSession*> SessionMap;
	ZThread::Mutex m_sessions_lock;
	SessionMap m_sessions;

	typedef stdext::hash_map<uint32, MapMgr*> MapMgrMap;
	MapMgrMap m_maps;

    uint32 m_playerLimit;
    std::string m_motd;

	uint32 m_ShutdownTimer;
    time_t m_gameTime;
    time_t m_lastTick;
	uint32 m_Last_tick;
	uint32 m_uptime;
	uint32 m_Warden_Timer;
	uint8  m_RealmRules;
};

#define sWorld World::getSingleton()

#endif
