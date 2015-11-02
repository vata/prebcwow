#include "StdAfx.h"

// You need a line like this for every DBC store. If you use createDBCStore (no Indexed), the lines will be ordered the way they are in the file
// SpellEntry is the file struct entry (for Spell.dbc here).
implementIndexedDBCStore (SpellStore, SpellEntry)
implementDBCStore (DurationStore, SpellDuration)
implementDBCStore (RangeStore, SpellRange)
implementIndexedDBCStore (EmoteStore, EmoteEntry)
implementIndexedDBCStore (RadiusStore, SpellRadius)
implementDBCStore (CastTimeStore, SpellCastTime)
implementIndexedDBCStore (WorldMapAreaStore, WorldMapArea)
implementIndexedDBCStore(AreaTableStore,AreaTableEntry)
implementDBCStore(WorldMapOverlayStore,WorldMapOverlayEntry)
implementIndexedDBCStore (TalentStore, TalentEntry)
implementIndexedDBCStore (ItemRandomPropertiesStore, ItemRandomPropertiesEntry)
implementIndexedDBCStore (SpellItemEnchantmentStore, SpellItemEnchantmentEntry)
implementDBCStore (SkillStore, skilllinespell)
implementIndexedDBCStore (FactionStore, FactionEntry)
implementIndexedDBCStore (TaxiPathStore, TaxiPathEntry)
implementIndexedDBCStore (TaxiPathNodeStore, TaxiPathNodeEntry)
implementIndexedDBCStore (ChatChannelsStore, ChatChannelsEntry)

float
GetRadius(SpellRadius *radius)
{
	if(radius)
        return radius->Radius;
	else
        return 0;
}

uint32
GetCastTime(SpellCastTime *time)
{
	if(time)
        return time->CastTime;
	else
		return 0;
}

float
GetRange(SpellRange *range)
{
	if(range)
        return range->Range;
	else
		return 0;
}


float
GetMaxRange(SpellRange *range)
{
	if(range)
        return range->Range;
	else
		return 0;
}

float
GetMinRange(SpellRange *range)
{
	if(range)
        return range->minRange;
	else
		return 0;
}

uint32
GetDuration(SpellDuration *dur)
{
	if(dur)
        return dur->Duration1;
	else
		return 0;
}
