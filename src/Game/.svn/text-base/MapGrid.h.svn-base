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
#ifndef __MAP_GRID_H
#define __MAP_GRID_H

class MapCell;

class MapGrid
{
public:
	MapGrid() : isLoaded(false) {
		for(int32 i=0; i<5; ++i)
			for(int32 j=0; j<5; ++j)
				_ContainedCells[i][j] = NULL;
	};

	bool isLoaded;
	int GridX;
	int GridY;
	uint32 MapId;
	MapMgr* CurrMapmgr;
	MapCell * _ContainedCells[4][4];
	// Map of the cells that are contained in the grid
	// x  1  2  3  4
	// 1  o  o  o  o
	// 2  o  o  o  o
	// 3  o  o  o  o
	// 4  o  o  o  o

	inline bool HasObjects () {
		for(int i=0; i<5; ++i)
			for(int j=0; j<5; ++j)
				if(_ContainedCells[i][j]->NbObjects()>0) return true;
				else continue;

		return false;
	}
	inline bool HasPlayers () {
		for(int i=0; i<5; ++i)
			for(int j=0; j<5; ++j)
				if(_ContainedCells[i][j]->NbPlayers()>0) return true;
				else continue;

		return false;
	}

	
	inline bool HasObject (Object *obj) {
		for(int i=0; i<5; ++i)
			for(int j=0; j<5; ++j)
				if(_ContainedCells[i][j]->HasObject(obj))
					return true;

		return false;
	}
	inline bool HasPlayer (Player *plr) {
		for(int i=0; i<5; ++i)
			for(int j=0; j<5; ++j)
				if(_ContainedCells[i][j]->HasPlayer(plr))
					return true;

		return false;
	}
	
};

#endif