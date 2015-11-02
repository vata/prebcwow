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
#include "MapMgr.h"

//-----------------------------------------------------------------------------
MapRangeIterator::MapRangeIterator (Object *center)
{
	MapCell* cCell = center->GetMapCell();
	MapCell* aCell = NULL;
	for(ObjectSetIterator itr = cCell->Begin(); itr != cCell->End(); ++itr)
	{
		Objects.insert(*itr);
	}
	for(uint32 i=0; i<8; ++i)
	{
		aCell = cCell->_AdjacentCells[i];
		for(ObjectSetIterator itr = aCell->Begin(); itr != aCell->End(); ++itr)
		{
			Objects.insert(*itr);
		}
	}
	Objects.erase(center);
	cObject = Objects.begin();
}

//-----------------------------------------------------------------------------
PlayerRangeIter::PlayerRangeIter(Object* center)
{
	MapCell* cCell = center->GetMapCell();
	MapCell* aCell = NULL;
	for(PlayerSetIter itr = cCell->PlrBegin(); itr != cCell->PlrEnd(); ++itr)
	{
		Players.insert(*itr);
	}
	for(uint32 i=0; i<8; ++i)
	{
		aCell = cCell->_AdjacentCells[i];
		for(PlayerSetIter itr = aCell->PlrBegin(); itr != aCell->PlrEnd(); ++itr)
			Players.insert(*itr);
	}
	if(center->isPlayer())
		Players.erase((Player*)center);
	cPlayer = Players.begin();
}

//-----------------------------------------------------------------------------
MapMgr::MapMgr(uint32 mapId) : _mapId(mapId)
{
	/*******************************************************
	 * PLEASE DO NOT DELETE _ANY_ COMMENT IN THIS FUNCTION *
	 *******************************************************/

	switch (mapId) {
	case 0:	// EASTERN KINGDOMS
		_minX = -16000; _minY = -19200;
		_maxX =   7500; _maxY =  16000;
		break;
	case 1:	// KALIMDOR
		_minX = -11800; _minY = -19800;
		_maxX =  12800; _maxY =  17000;
		break;
	default:	
		_minX = -8000; _minY = -8000;
		_maxX =  8000; _maxY =  8000;
		break;
	}
	
	_sizeCellsX = _sizeCellsY = MAPMGR_CELL_SIZE;
	/*_sizeGridsX = _sizeGridsY = MAPMGR_GRID_SIZE;*/

	_numCellsX = (abs(_minX) + _maxX) / _sizeCellsX + 1;
	_numCellsY = (abs(_minY) + _maxY) / _sizeCellsY + 1;
	/*_numGridsX = (abs(_minX) + _maxX) / _sizeGridsX + 1;
	_numGridsY = (abs(_minY) + _maxY) / _sizeGridsY + 1;
	_numCellsX = _numGridsX * 4; // Grids are 4*4 Cells :)
	_numCellsY = _numGridsY * 4; //         " "*/

    _cells = new MapCell*[_numCellsX];
    ASSERT(_cells);
    for (int32 i=0; i < _numCellsX; ++i)
    {
        _cells[i] = new MapCell[_numCellsY];
        ASSERT(_cells[i]);
    }

	for (uint32 x=0; x<_numCellsX; ++x)
	{
		for (uint32 y=0; y<_numCellsY; ++y)
		{
			MapCell *cCell = &(_cells[x][y]);

			cCell->CellX   = x;
			cCell->CellY   = y;
			cCell->MapId   = mapId;
			cCell->CurrMapmgr = this;
			
			if(x==0 || y==0 || x==_numCellsX || y==_numCellsY)
			{
				cCell->isMapEdge = true;
				continue;
			}
			cCell->_AdjacentCells[0] = &(_cells[x-1][y+1]);
			cCell->_AdjacentCells[1] = &(_cells[x][y+1]);
			cCell->_AdjacentCells[2] = &(_cells[x+1][y+1]);
			cCell->_AdjacentCells[3] = &(_cells[x+1][y]);
			cCell->_AdjacentCells[4] = &(_cells[x+1][y-1]);
			cCell->_AdjacentCells[5] = &(_cells[x][y-1]);
			cCell->_AdjacentCells[6] = &(_cells[x-1][y-1]);
			cCell->_AdjacentCells[7] = &(_cells[x-1][y]);
		}
	}

/*	_grids = new MapGrid*[_numGridsX];
    ASSERT(_grids);
	for (int32 i=0; i < _numGridsX; ++i)
	{
		_grids[i] = new MapGrid[_numGridsY];
		ASSERT(_grids[i]);
	}

	for (int32 x=0; x<_numGridsX; ++x)
	{
		for (int32 y=0; y<_numGridsY; ++y)
		{
			MapGrid *cGrid = &(_grids[x][y]);

			cGrid->GridX   = x;
			cGrid->GridY   = y;
			cGrid->MapId   = mapId;
			cGrid->CurrMapmgr = this;

			for (int32 xx=x, i=0; xx < x*4+1; ++xx, ++i)
				for (int32 yy=y, j=0; yy < y*4+1; ++yy, ++j)
				{
					MapCell* cCell = &(_cells[xx][yy]);
					cCell->CurrMapGrid = cGrid;
					cGrid->_ContainedCells[i][j] = cCell;
				}
		}
	}*/
    _timers[MMUPDATE_FIELDS].SetInterval(200);
    _timers[MMUPDATE_GAMEOBJECTS].SetInterval(400);

	uint32
		_totalCells = _numCellsX * _numCellsY,
		/*_totalGrids = _numGridsX * _numGridsY,*/
		_totalCellsSize = uint32(_totalCells*sizeof(MapCell))/*,
		_totalGridsSize = uint32(_totalGrids*sizeof(MapGrid))*/;

	sLog.outString ("");
	sLog.outString ("Created MapMgr id=%d cellsX=%d cellsY=%d (total %d) sizeof_1=%d",
		 mapId, _numCellsX, _numCellsY, _totalCells, uint32(sizeof(MapCell)));
	/*sLog.outString ("               gridsX=%d gridsY=%d (total %d) sizeof_1=%d",
				_numGridsX, _numGridsY, _totalGrids, uint32(sizeof(MapGrid)));*/
	sLog.outString ("        >=[Map %d uses %d bytes of memory]",
				mapId, (_totalCellsSize/*+_totalGridsSize*/));
}

//-----------------------------------------------------------------------------
MapMgr::~MapMgr()
{
    if(_cells)
    {
        for (int32 i = 0; i < _numCellsX; ++i)
        {
            delete [] _cells[i];
        }

        delete _cells;
    }
	/* if(_grids)
	{
		for (int32 i = 0; i < _numGridsX; ++i)
		{
			delete [] _cells[i];
		}

		delete _grids;
	}*/
}

//-----------------------------------------------------------------------------
// When player first enters some area - he awakens all sleeping mobs and gameobjects
// and gathers all updates about them. Also player registers in area cells.
//
// When non player object or mob enters area - nothing happens, it just registers in
// current area cells
//
void MapMgr::AddObject(Object *obj)
{
    ASSERT (obj != NULL);
    ASSERT (obj->GetMapId() == _mapId);
	ASSERT (_cells != NULL);

    // That object types are not map objects. TODO: add AI groups here?
    if(obj->GetTypeId() == TYPEID_ITEM || obj->GetTypeId() == TYPEID_CONTAINER)
    {
        // mark object as updatable and exit
        obj->AddToWorld();
        return;
    }


	//-------------------------
	// registrations
	//-------------------------
	MapCell	&cell = _cells[obj->MapCellX()][obj->MapCellY()];
	cell.AddObject(obj);
	obj->SetMapCell(&cell);
	obj->AddToWorld();

	UpdateData data;
	UpdateData playerData;
	WorldPacket packet;

	int32	cellX = int32(obj->GetPositionX() - _minX) / _sizeCellsX;
	int32	cellY = int32(obj->GetPositionY() - _minY) / _sizeCellsY;

    int32 endX = cellX < _numCellsX ? cellX + 1 : _numCellsX;
    int32 endY = cellY < _numCellsY ? cellY + 1 : _numCellsY;
    int32 startX = cellX > 0 ? cellX - 1 : 0;
    int32 startY = cellY > 0 ? cellY - 1 : 0;
    int32 posX, posY;

	if(obj->isPlayer())
	{
		// If current cell was sleeping before player arrived, then awake all mobs
		// in cell registering them in update list
		//
		for (posX = startX; posX <= endX; ++posX ) {
			for (posY = startY; posY <= endY; ++posY ) {
				_PlayerEnteredCell ((Player *)obj, _cells[posX][posY], data, playerData, packet);
			}
		}
	}
	else {
		// Non player monsters when entering area just scan it for players and
		// register with them.
		//
		for (posX = startX; posX <= endX; ++posX)
			for (posY = startY; posY <= endY; ++posY)
				_MobEnteredCell (obj, _cells[posX][posY], playerData, packet);
	}

	// Now add player own update block and send to him
	//
	if (obj->isPlayer())
	{
		playerData.Clear();
		obj->BuildCreateUpdateBlockForPlayer( &playerData, (Player *)obj );

		playerData.BuildPacket( &packet );
		((Player *)obj)->GetSession()->SendPacket( &packet );
	}
}

//-----------------------------------------------------------------------------
// When player leaves some area and he was last in this area - we unregister everything
// non-player (except walking NPCs) in this area from updates to conserve CPU resources.
// Also player unregisters from local area cells.
//
// When non player leaves area - he just unregisters from local area cells.
//
void MapMgr::RemoveObject(Object *obj)
{
    // That object types are not map objects. TODO: add AI groups here?
	uint8 type_id = obj->GetTypeId();
    if (type_id == TYPEID_ITEM || type_id == TYPEID_CONTAINER) // || type_id == TYPEID_GAMEOBJECT)
    {
        // remove updatable flag and exit
        obj->RemoveFromWorld();
        return;
    }

	//----------------
	obj->RemoveFromWorld();

    // remove us from updated objects list
	//
	_updatedObjects.erase (obj);
	if (! obj->isPlayer() && ! obj->IsPathWalker())
		HibernateGuid (obj->GetGUID());

	// Unregister from map area cell
	//
    MapCell *objCell = obj->GetMapCell();

    obj->SetMapCell(0);
	objCell->RemoveObject(obj);

	// Check own in_range set for possible players around, and send them news
	// about departure from this area
	//
	Object *o;
	for (MapRangeIterator iter (obj); o = iter.Advance(); )
    {
		if (o->isPlayer() && o != obj)
			obj->DestroyForPlayer( (Player *)o );
    }

	// When last player leaves the area, we remove mobs from all surrounding cells
	// from update list
	//

	// Calculate cell indexes that located around our current cell
	// 
	uint32 x = (uint32)(obj->GetPositionX() - _minX) / _sizeCellsX;
	uint32 y = (uint32)(obj->GetPositionY() - _minY) / _sizeCellsY;
	UpdateData data;
	WorldPacket packet;

	if (obj->isPlayer())
	{
		/*uint32 endX = x < _sizeX ? x + 1 : _sizeX;
		uint32 endY = y < _sizeY ? y + 1 : _sizeY;
		uint32 startX = x > 0 ? x - 1 : 0;
		uint32 startY = y > 0 ? y - 1 : 0;
		uint32 posX, posY;

		for (posX = startX; posX <= endX; ++posX )
			for (posY = startY; posY <= endY; ++posY )*/
		for (int i = -1; i <= 1; ++i)
			for (int j = -1; j <= 1; ++j)
				_PlayerLeftCell ((Player *)obj, _cells[x+i][y+j], data, packet);

		if (data.HasData())
		{
			data.BuildPacket( &packet );
			((Player*)obj)->GetSession()->SendPacket( &packet );
		}
	}
}

//-----------------------------------------------------------------------------
// Helper function called to do common mob actions upon entering new cell.
// Mob locates players around and contacts them via InRangeObject field
//
void
MapMgr::_MobLeftCell (Object *obj, MapCell &cell, UpdateData &data, WorldPacket &packet)
{
	for (PlayerSetIter Pi = cell.PlrBegin(); Pi != cell.PlrEnd(); ++Pi)
	{
		if ((*Pi)->CanSee ((Unit *)obj))
		{
			data.Clear();
			obj->BuildOutOfRangeUpdateBlock (&data);
			data.BuildPacket (&packet);
			(*Pi)->GetSession()->SendPacket (&packet);
		}
	}
}

//-----------------------------------------------------------------------------
// Helper function called to do common mob actions upon entering new cell.
// Mob locates players around and contacts them via InRangeObject field
//
void
MapMgr::_MobEnteredCell (Object *obj, MapCell &cell, UpdateData &data, WorldPacket &packet)
{
	for (PlayerSetIter Pi = cell.PlrBegin(); Pi != cell.PlrEnd(); ++Pi)
	{
		if ((*Pi)->CanSee ((Unit *)obj))
		{
			data.Clear();
			obj->BuildCreateUpdateBlockForPlayer (&data, (*Pi));
			data.BuildPacket (&packet);
			(*Pi)->GetSession()->SendPacket (&packet);

			ActivateGuid (obj->GetGUID());
		}
	}
}

//-----------------------------------------------------------------------------
// Helper function called by ChangeObjectLocation for every cell that lost one
// player and now one step closer to total hibernation. When no players walk around
// this cell - all mobs here put into sleep.
// 
void
MapMgr::_PlayerLeftCell (Player *player, MapCell &cell,
							  UpdateData &playerData, WorldPacket &packet)
{
	playerData.Clear();
	UpdateData data;

	for (ObjectSetIterator ci = cell.Begin(); ci != cell.End(); ++ci)
	{
		Object *unreg = *ci;

		if ((Object *)player == unreg) continue;

		unreg->BuildOutOfRangeUpdateBlock (&playerData);

		// if this was player too: send him update about us leaving
		if (unreg->isPlayer()) {
			data.Clear();
			player->BuildOutOfRangeUpdateBlock (&data);
			data.BuildPacket (&packet);
			((Player *)unreg)->GetSession()->SendPacket (&packet);
		}
	}

	if (playerData.HasData()) {
		WorldPacket pkt;
		playerData.BuildPacket( &pkt );
		player->GetSession()->SendPacket (&pkt);
	}
}
//-----------------------------------------------------------------------------
// Helper function called by ChangeObjectLocation for every cell where player
// enters. If no players were in this cell before, then we need to wake up all sleeping
// mobs here by adding them to update list.
// 
void
MapMgr::_PlayerEnteredCell (Player *player, MapCell &cell,
								 UpdateData &data, UpdateData &playerData, WorldPacket &packet)
{
	playerData.Clear();

	// And now look for other players and stuff to get some update packets
	//
	for (ObjectSetIterator ci = cell.Begin(); ci != cell.End(); ++ci)
	{
		Object *reg = *ci;

		if ((Object *)player != reg)
		{
			if (player->CanSee (reg))
			{
				reg->BuildCreateUpdateBlockForPlayer (&playerData, player);
			}

			// When player meet player - send update to other side too
			// <- this is possible fix to #132 when player logs in to zone with players
			if (reg->isPlayer()) 
			{
				if (reg->CanSee (player))
				{
					UpdateData udata;
					udata.Clear();
					player->BuildCreateUpdateBlockForPlayer (&udata, (Player *)reg);
					udata.BuildPacket (&packet);
					((Player *)reg)->GetSession()->SendPacket (&packet);
				}
			} else {
				ActivateGuid (reg->GetGUID());
			}
		}
	}

	if (playerData.HasData()) {
		playerData.BuildPacket (&packet);
		player->GetSession()->SendPacket (&packet);
	}
}

//-----------------------------------------------------------------------------
// When player moves between cells he has to be deleted from that cell's player
// list and object list. If there are no other players in there, we just set all
// npcs to sleeping state, unregistering them from updates.
//
// When npc moves between cells... nothing happens.
//
void
MapMgr::ChangeObjectLocation (Object *obj, int32 oldX, int32 oldY)
{
	if(obj->GetTypeId() == TYPEID_ITEM || obj->GetTypeId() == TYPEID_CONTAINER)
        return;

    WorldPacket packet;
    UpdateData data;
    UpdateData playerData;

	bool isPlayer = obj->isPlayer();

	// Now we calculate if motion vector crossed any cell boundary, so we leave
	// opposite cells and hibernate mobs there, and enter new cells in front of us,
	// activating mobs there.
	//
	int32	newX = (int32)obj->GetPositionX();
	int32	newY = (int32)obj->GetPositionY();

	// If changed cell - move object to next cell
	MapCell * newCell = & (_cells[obj->MapCellX()][obj->MapCellY()]);

	if (newCell != NULL && obj->GetMapCell() != NULL && newCell != obj->GetMapCell())
	{
		ASSERT (obj->GetMapCell()->HasObject (obj));
		obj->GetMapCell()->RemoveObject (obj);
		if(isPlayer)
			obj->GetMapCell()->RemovePlayer ( ((Player*)obj) );
	} else {
		newCell = NULL;
	}

	oldX -= _minX; oldY -= _minY;
	newX -= _minX; newY -= _minY;

	int32	lowBound = oldY - oldY % _sizeCellsY;
	int32	topBound = lowBound + _sizeCellsY;
	int32	leftBound = oldX - oldX % _sizeCellsX;
	int32	rightBound = leftBound + _sizeCellsX;

	int32	cellX = oldX / _sizeCellsX;
	int32	cellY = oldY / _sizeCellsY;

	if (newY > topBound) {
		if (newX > rightBound) {
			if (isPlayer) {
				// Top Right
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY+1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY+1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+1][cellY+2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX-1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX-1][cellY+1], data, packet);

				_MobEnteredCell (obj, _cells[cellX+2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY+1], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX+1][cellY+2], data, packet);
			}
		}
		else
		if (newX < leftBound) {
			if (isPlayer) {
				// Top Left
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY+1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY+1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-1][cellY+2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX+1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY+1], data, packet);

				_MobEnteredCell (obj, _cells[cellX-2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY+1], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX-1][cellY+2], data, packet);
			}
		}
		else // X not changed
		{
			if (isPlayer) {
				// Top
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY-1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX]  [cellY-1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY-1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX-1][cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY+2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+1][cellY+2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX-1][cellY-1], data, packet);
				_MobLeftCell (obj, _cells[cellX]  [cellY-1], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY-1], data, packet);

				_MobEnteredCell (obj, _cells[cellX-1][cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY+2], data, packet);
				_MobEnteredCell (obj, _cells[cellX+1][cellY+2], data, packet);
			}
		}
	} else
	if (newY < lowBound) {
		if (newX > rightBound) {
			if (isPlayer) {
				// Bottom Right
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY-1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY-1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+1][cellY-2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX-1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX-1][cellY-1], data, packet);

				_MobEnteredCell (obj, _cells[cellX+2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY-1], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX+1][cellY-2], data, packet);
			}
		}
		else
		if (newX < leftBound) {
			if (isPlayer) {
				// Bottom Left
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY-1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY-1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-1][cellY-2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX+1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY-1], data, packet);

				_MobEnteredCell (obj, _cells[cellX-2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY-1], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX-1][cellY-2], data, packet);
			}
		}
		else // X not changed
		{
			if (isPlayer) {
				// Bottom
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY+1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX]  [cellY+1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY+1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX-1][cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX]  [cellY-2], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+1][cellY-2], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX-1][cellY+1], data, packet);
				_MobLeftCell (obj, _cells[cellX]  [cellY+1], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY+1], data, packet);

				_MobEnteredCell (obj, _cells[cellX-1][cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX]  [cellY-2], data, packet);
				_MobEnteredCell (obj, _cells[cellX+1][cellY-2], data, packet);
			}
		}
	} else {
		if (newX > rightBound) {
			if (isPlayer) {
				// Right
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY-1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX-1][cellY+1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY+1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX+2][cellY-1], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX-1][cellY+1], data, packet);
				_MobLeftCell (obj, _cells[cellX-1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX-1][cellY-1], data, packet);

				_MobEnteredCell (obj, _cells[cellX+2][cellY+1], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX+2][cellY-1], data, packet);
			}
		}
		if (newX < leftBound) {
			if (isPlayer) {
				// Left
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY+1], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY], playerData, packet);
				_PlayerLeftCell ((Player *)obj, _cells[cellX+1][cellY-1], playerData, packet);

				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY+1], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY], data, playerData, packet);
				_PlayerEnteredCell ((Player *)obj, _cells[cellX-2][cellY-1], data, playerData, packet);
			} else {
				_MobLeftCell (obj, _cells[cellX+1][cellY+1], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY], data, packet);
				_MobLeftCell (obj, _cells[cellX+1][cellY-1], data, packet);

				_MobEnteredCell (obj, _cells[cellX-2][cellY+1], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY], data, packet);
				_MobEnteredCell (obj, _cells[cellX-2][cellY-1], data, packet);
			}
		}
	}

	if (newCell != NULL)
	{
		obj->SetMapCell (newCell);
		ASSERT (newCell->HasObject (obj) == FALSE);
		newCell->AddObject (obj);
		if(isPlayer)
			newCell->AddPlayer ( ((Player*)obj) );
	}
}

//-----------------------------------------------------------------------------
void
MapMgr::_UpdateObjects()
{
    UpdateData *data;
    stdext::hash_map<Player*, UpdateData*> updates;
    stdext::hash_map<Player*, UpdateData*>::iterator i;

    ObjectSetIterator iobj, iobjend;
	Player *player;
	Item   *item;

	/*	ObjectMgr::GameObjectMap::iterator giter;
		for( giter = objmgr.Begin<GameObject>(); giter != objmgr.End<GameObject>( ); ++ giter )
            giter->second->Update( (uint32)diff );*/

	// Scan every updated object in the world
	//
    for ( iobj = _updatedObjects.begin(), iobjend = _updatedObjects.end();
        iobj != iobjend; ++iobj )
    {
		uint8 type_id = (*iobj)->GetTypeId();

		// If this is player - then build update packet for himself
		//
		if ((*iobj)->isPlayer())
		{
			player = (Player *)*iobj;

			i = updates.find (player);
			if (i == updates.end())
			{
				data = new UpdateData;
				ASSERT(data);

				updates[player] = data;
			}
			else 
				data = i->second;

			player->BuildValuesUpdateBlockForPlayer (data, player);
		}

		// Build update packets for Items and Containers
		//
        if (type_id == TYPEID_ITEM || 
			type_id == TYPEID_CONTAINER)
        {
			item = (Item *)*iobj;

            i = updates.find (item->GetOwner());
            if (i == updates.end())
            {
                data = new UpdateData;
                ASSERT(data);

                updates[item->GetOwner()] = data;
            }
            else
                data = i->second;

            item->BuildValuesUpdateBlockForPlayer (data, item->GetOwner());
        }

		// Iterate over all surrounding objects looking for players and
		// appending update info for them to packets
		//
		Player *o =NULL;
		for (PlayerRangeIter iplr (*iobj); o = iplr.Advance(); )
        {
			// Search for already registered update packet for player
			// and append next object update there or create new UpdateData
			//
            i = updates.find( o );
            if (i == updates.end())
            {
                data = new UpdateData;
                ASSERT(data);

                updates[o] = data;
            }
            else
                data = i->second;

            (*iobj)->BuildValuesUpdateBlockForPlayer( data, o );
        }

		// Mark that update data already fetched and sent - clear update fields.
        (*iobj)->ClearUpdateMask();
    }

	// Send all update packets to players
	//
	for ( i = updates.begin(); i != updates.end(); ++i )
    {
		WorldPacket packet;
        UpdateData *up_data = i->second;

		if (up_data->HasData()) 
		{
			up_data->BuildPacket( &packet );
		
			// Send next update from list
		    ((Player*)(i->first))->SendMessageToSet( &packet, true );
		}

		// Free heap-allocated update data object
        delete up_data;
    }

    updates.clear();
    _updatedObjects.clear();
}

//-----------------------------------------------------------------------------
void
MapMgr::Update(time_t diff)
{
    for(int i = 0; i < MMUPDATE_COUNT; ++i)
        _timers[i].Update(diff);

    if (_timers[MMUPDATE_FIELDS].Passed())
    {
        _timers[MMUPDATE_FIELDS].Reset();

        _UpdateObjects();
    }
	if (_timers[MMUPDATE_GAMEOBJECTS].Passed())
	{
		_timers[MMUPDATE_GAMEOBJECTS].Reset();

		/* TODO:
			* Update All GameObjects */
	}
}

//-----------------------------------------------------------------------------
void
MapMgr::ScanForFriends (Creature *caller, float scanRadius, ObjectSet &friends)
{
	Object *o;
	for (MapRangeIterator itr (caller); o = itr.Advance(); ) 
	{
		if (o->isUnit() == false) continue;

		// ignore self - implemented in Advance()
		// if ((Object *)caller == o) continue;

		Creature * cr = (Creature *)o;
		float	distSq = caller->GetDistanceSq (cr);

		// Check if helpful family member can hear me
		if (distSq > scanRadius * scanRadius) continue;

		// We won't worry our combating enemies. Only idle enemies will get aggro.
		if (cr->isInCombat()) continue;

		// Check if first word of creature name is like my
		// TEMP-LOCKED OPTION: Think enough comparing only factions
		//if (caller->RelatedByFirstName (cr) == false) continue;

		// Family member must have my faction, to be useful
		if (caller->GetFaction() != cr->GetFaction()) continue;

		// YES! My Friend!!!
		friends.insert (cr);
	}
}

//-----------------------------------------------------------------------------
void
MapMgr::UpdateActiveObjects (uint32 diff) 
{
	if(!HasActiveObjects())
		return;

	Unit *obj;
	
	GuidVector	badGuids;
	badGuids.reserve (512);

	GuidVector	activeGuids;
	activeGuids.reserve (512);

	for (GuidSetIterator i = _activeGuids.begin(); i != _activeGuids.end(); ++i) 
	{
		activeGuids.push_back (*i);
	}

	Guid guid;
	for (int i = activeGuids.size()-1; i >= 0; --i)
	{
		guid = activeGuids[i];
		obj = (Unit *)objmgr.GetObject<Creature> (guid);
		
		// if Guid was invalid - delete it after this loop
		if (obj == NULL) {
			badGuids.push_back (guid);
			continue;
		}

		ASSERT (obj->isUnit());

		obj->Update( (uint32)diff );
	}

	for (int j = 0; j < (int)badGuids.size(); ++j)
		_activeGuids.erase (badGuids[j]);
}
