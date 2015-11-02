// Copyright (C) 2004 WoW Daemon
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef WOWSERVER_COMMON_H
#define WOWSERVER_COMMON_H

#ifndef __ALLOW_STUPID_WARNING_FLOOD__
#pragma warning(disable:4005)
#pragma warning(disable:4018)
#pragma warning(disable:4099)
#pragma warning(disable:4101)
#pragma warning(disable:4305)
#pragma warning(disable:4311)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4561)
#pragma warning(disable:4715)
#pragma warning(disable:4800)
#pragma warning(disable:4996)
#endif 

/* Server Translation Sytem
	ENG - English
	FRA - Français
*/
#define SERVER_LANGUAGE ENG

#if SERVER_LANGUAGE == ENG
#	include "languages/eng.h"
#elif SERVER_LANGUAGE == FRA
#	include "languages/fra.h"
#endif

// Realm_Rules types
#define REALMRULE_NORMAL	0
#define REALMRULE_PVP		1
#define REALMRULE_PVE		4 /* NOT GOOD ! */
#define REALMRULE_RPNRM		6
#define REALMRULE_RPPVP		8


// Only clients with this version will be allowed to view the realmlist.
// Higher versions will be rejected, lower versions will be patched if possible.

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <set>
#include <list>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <zthread/FastMutex.h>
#include <zthread/LockedQueue.h>
#include <zthread/Runnable.h>
#include <zthread/Thread.h>
#include "MemoryLeaks.h"
#include "Portable.h"

#define GUID_HIPART(x) (*(((uint32*)&(x))+1))
#define GUID_LOPART(x) (*((uint32*)&(x)))

#define atol(a) strtoul( a, NULL, 10)

#define STRINGIZE(a) #a

//set up universal countof for arrays
template <typename T, size_t N>
char ( &_ArraySizeHelper( T (&array)[N] ))[N];
#define countof( array ) (sizeof( _ArraySizeHelper( array ) ))


// fix buggy MSVC's for variable scoping to be reliable =S
#define for if(true) for

#endif

