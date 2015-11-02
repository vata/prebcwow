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
#ifndef __MAPMGR_H
#define __MAPMGR_H

class Object;
class MapCell;
class MapGrid;

#define MAPMGR_CELL_SIZE 64
#define MAPMGR_GRID_SIZE 256

enum MapMgrTimers
{
    MMUPDATE_GAMEOBJECTS = 0,
    MMUPDATE_FIELDS,
    MMUPDATE_COUNT
};

//=============================================================================
// Helper Class to easy do iterations over map area around object
//=============================================================================
class MapRangeIterator
{
public:
	MapRangeIterator(Object *center);

	ObjectSet Objects;
	Object* Advance() {
		if(cObject == Objects.end())
			return NULL;
		Object* TObj = (*cObject);
		++cObject;
		return TObj;
	}
	inline ObjectSetIterator Begin() { return Objects.begin(); }
	inline ObjectSetIterator End() { return Objects.end(); }
private:
	ObjectSetIterator cObject;
};

//=============================================================================
// Helper Class to easy do iterations over map area around Players
//=============================================================================
class PlayerRangeIter
{
public:
	PlayerRangeIter(Object *center);
	PlayerSet Players;
	
	Player* Advance() {
		if(cPlayer == Players.end())
			return NULL;
		Player* TPlr = (*cPlayer);
		++cPlayer;
		return TPlr;
	}
	inline PlayerSetIter Begin() { return Players.begin(); }
	inline PlayerSetIter End() { return Players.end(); }
private:
	PlayerSetIter cPlayer;
};


class MapMgr
{
	friend class Object;
	friend class MapRangeIterator;
	friend class PlayerRangeIter;

public:
    MapMgr(uint32 mapid);
    ~MapMgr();

    typedef stdext::hash_map<uint64, Object*> ObjectMap;

	// Called for every object or unit entering map area
    void AddObject (Object *obj);

	// Called for every object or unit leaving map area
	void RemoveObject (Object *obj);

	// Called for moving players and units
	void ChangeObjectLocation (Object *obj, int32 oldX, int32 oldY);

    //! Mark object as updated
    void ObjectUpdated(Object *obj)
    {
        ASSERT(_updatedObjects.find(obj) == _updatedObjects.end());
        _updatedObjects.insert(obj);
    }
    void Update(time_t diff);
	
	// Scans area around for friendly creatures that may want to share my aggro
	void ScanForFriends (Creature *caller, float scanRadius, ObjectSet &friends);

	inline bool HasActiveObjects() {
		return ! _activeGuids.empty();
	}
	// Calls Update for every active registered object on this map, removing invalid guids
	void UpdateActiveObjects (uint32 diff);

protected:

    //! Collect and send updates to clients
    void _UpdateObjects();
	
	// Helper function called by ChangeObjectLocation when player leaves map cell
	void _PlayerLeftCell (Player *player, MapCell &empty, UpdateData &playerData, WorldPacket &packet);

	// Helper function called by ChangeObjectLocation when player enters map cell
	void _PlayerEnteredCell (Player *player, MapCell &cell, UpdateData &data,
		UpdateData &playerData, WorldPacket &packet);

	void _MobEnteredCell (Object *obj, MapCell &cell, UpdateData &playerData, WorldPacket &packet);
	void _MobLeftCell (Object *obj, MapCell &cell, UpdateData &playerData, WorldPacket &packet);

	// Set of GUID numbers of all mobs in the world surrounded by players, so these
	// mobs have CPU time for thinking. When last player leaves map cell with active
	// mob, GUID of this mob gets removed from this set and it hibernates conserving
	// CPU power and waiting for players.
	//
	GuidSet		_activeGuids;

	inline bool IsGuidActivated (Guid id) {
		return _activeGuids.find (id) != _activeGuids.end();
	}
	inline void ActivateGuid (Guid id) {
		_activeGuids.insert (id);
	}
	inline void HibernateGuid (Guid id) {
		_activeGuids.erase (id);
	}

	friend class ChatHandler;
	int32 _minX, _minY, _minZ, _maxX, _maxY, _maxZ;

private:
	int32
		_sizeCellsX,
		_sizeCellsY,
		_numCellsX,
		_numCellsY/*,
		_sizeGridsX,
		_sizeGridsY,
		_numGridsX,
		_numGridsY*/;
    MapCell **_cells;
	/*MapGrid **_grids;*/

    uint32 _mapId;

	IntervalTimer _timers[MMUPDATE_COUNT];
    ObjectSet _updatedObjects;
};

#endif