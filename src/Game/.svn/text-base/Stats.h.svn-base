#pragma once
// Copyright (C) 2004 WoWD Team

#ifndef __STATS_H
#define __STATS_H

#include "Unit.h"
#include "UpdateMask.h"
#include "../Scripts/Scripts.h"

//-----------------------------------------------------------------------------
//  CalculateXpToGive
//-----------------------------------------------------------------------------
inline uint32 CalculateXpToGive(Unit *pVictim, Unit *pKiller)
{
	if(pVictim == pKiller) // Suicides and other stuff made some bugs in the scripting system
		return 0;

	//-----------------------------------------------
	// Check initial tagger, who damaged first - gets
	// creature tag and awarded with XP and loot
	//-----------------------------------------------
	Unit * tagger = pVictim->GetTagger();
	if (tagger != NULL && pKiller->GetGUID() != tagger->GetGUID())
	{
		sLog.outDebug ("CalculateXP: Killer GUID=%X is not an initial tagger GUID=%X",
			pKiller->GetGUIDLow(), tagger->GetGUIDLow());
		return 0;
	}

	// Using External XP function from Python scripts, functions.py file, CalcXP() function
	uint32 xp = Call_CalcXP (pKiller, pVictim);
	return xp;
}

// Calculates Damage Reduction
inline uint32 CalcDamageReduction (Unit *pVictim, Unit *pAttacker, uint32 damages)
{
	// Using External XP function from Python scripts, functions.py file, CalcDamageReduction() function
	return Call_CalcDR(pVictim, pAttacker, damages);
}

// Calculates Exploration XP
inline uint32 CalcExplorationXP (Unit *pUnit)
{
	return pUnit->GetLevel()*10 + 45;
}

#endif

