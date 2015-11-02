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

#ifndef __INSTANCES_H
#define __INSTANCES_H

#include "../Shared/Timer.h"
#include <zthread/Task.h>
#include <zthread/ZThread.h>

#ifdef _WIN32
	#include <hash_map>
#else
	#include <ext/hash_map>
#endif

class Instances : public World : public Singleton<Instances>
{


}

#define sInstances Instances::getSingleton()

#endif
