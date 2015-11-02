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
#ifndef __MAP_CELL_H
#define __MAP_CELL_H

//class MapGrid;

class MapCell
{
public:
	MapCell() : isMapEdge(false) {
		for(int32 i=0; i<8; ++i)
			_AdjacentCells[i] = NULL;
	};

	int CellX;
	int CellY;
	uint32 MapId;
	bool isMapEdge;
	MapMgr* CurrMapmgr;
	//MapGrid * CurrMapGrid;

	PlayerSet _OnCellPlayers;
    ObjectSet _objects;
	MapCell * _AdjacentCells[8];
	// Map of the cells that are around current one
	// 0   1   2
	//   \ | /
	// 7 - o - 3
	//   / | \
	// 6   5   4

	inline uint32 NbObjects () { return _objects.size(); }
	inline uint32 NbPlayers () { return _OnCellPlayers.size(); }

    inline void AddObject (Object *obj) { _objects.insert(obj); }
    inline void RemoveObject (Object *obj) { _objects.erase(obj); }
	inline bool HasObject (Object *obj) { return !(_objects.find(obj) == _objects.end()); }

	inline ObjectSetIterator Begin() { return _objects.begin(); }
	inline ObjectSetIterator End() { return _objects.end(); }

    inline void AddPlayer (Player *plr) { _OnCellPlayers.insert(plr); }
    inline void RemovePlayer (Player *plr) { _OnCellPlayers.erase(plr); }
	inline bool HasPlayer (Player *plr) { return !(_OnCellPlayers.find(plr) == _OnCellPlayers.end()); }
	inline uint32 GetPlayerCount () { return _OnCellPlayers.size(); }

	inline PlayerSetIter PlrBegin() { return _OnCellPlayers.begin(); }
	inline PlayerSetIter PlrEnd() { return _OnCellPlayers.end(); }
};

#endif