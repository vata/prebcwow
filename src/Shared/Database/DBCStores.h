#pragma once
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
#ifndef __SPELLSTORE_H
#define __SPELLSTORE_H

#include "../Common.h"
#include "DataStore.h"
#include "../Timer.h"

typedef struct
{
    uint32 TalentID;
    uint32 TalentTree;
    uint32 unk1;
    uint32 unk2;
    uint32 RankID[4];
    uint32 unk[11];
} TalentEntry;

typedef struct
{
	uint32 AuctionID;
	uint32 amt;
} bidentry;

typedef struct 
{
	uint32 auctioneer;
	uint32 item;
	uint32 owner;
	uint32 bid;
	uint32 buyout;
	time_t time;
	uint32 bidder;
	uint32 Id;
} AuctionEntry;

typedef struct
{
	uint32 Id;
	std::string name;
	uint32 emoteId;
	uint32 fmtMaleOnSomeone;
	uint32 fmtMaleOnYou;
	uint32 fmtYouOnMale;
	uint32 unk1;
	uint32 fmtMale;
	uint32 unk2;
	uint32 fmtYou;
	uint32 unk3;
	uint32 fmtFemaleOnSomeone;
	uint32 fmtFemaleOnYou;
	uint32 unk4[2];
	uint32 fmtFemale;
	uint32 unk5[3];
} EmoteEntry;

typedef struct
{
	uint32 Id;
	uint32 skilline;
	uint32 spell;
	uint32 unk1;
	uint32 unk2;
	uint32 unk3;
	uint32 unk4;
	uint32 unk5;
	uint32 minrank;
	uint32 next;
	uint32 grey;
	uint32 green;
	uint32 unk10;
	uint32 unk11;
	uint32 unk12;
} skilllinespell;

// Struct for the entry in Spell.dbc
typedef struct
{
	// Thanks to MaNGoS again ;)
	uint32 Id;                                    
    uint32 School;
    uint32 Category;
    uint32 field4;
    uint32 isDispelable;
	uint32 field6;	// added
    uint32 Attributes;
    uint32 AttributesEx;
    uint32 field9;
    uint32 field10;
	uint32 field11; // added
    uint32 Targets;                               
    uint32 TargetCreatureType;                    
    uint32 RequiresSpellFocus;     
	uint32 field15; //add by vendy
    uint32 CasterAuraState;                       
    //uint32 TargetAuraState; //delete by vendy                      
    uint32 CastingTimeIndex;                  
    uint32 RecoveryTime;
    uint32 CategoryRecoveryTime;
    uint32 InterruptFlags;
    uint32 AuraInterruptFlags;
    uint32 ChannelInterruptFlags;                 
    uint32 procFlags;
    uint32 procChance;
    uint32 procCharges;
    uint32 maxLevel;
    uint32 baseLevel;
    uint32 spellLevel;
    uint32 DurationIndex;
    uint32 powerType;
    uint32 manaCost;
    uint32 manaCostPerlevel;                      
    uint32 manaPerSecond;
    uint32 manaPerSecondPerLevel;
    uint32 rangeIndex;
    float speed;
    uint32 modalNextSpell;
    uint32 field38;                              
    uint32 Totem[2];                              
    uint32 Reagent[8];                            
    uint32 ReagentCount[8];                       
    uint32 EquippedItemClass;                     
    uint32 EquippedItemSubClass;                  
    uint32 Effect[3]; // 59 - 61                           
    uint32 EffectDieSides[3];                     
    uint32 EffectBaseDice[3];                     
    float EffectDicePerLevel[3];                
    float EffectRealPointsPerLevel[3];            
    int32 EffectBasePoints[3];
	uint32 field77[3]; // added
    uint32 EffectImplicitTargetA[3]; // 80 - 82
    uint32 EffectImplicitTargetB[3]; // 83 - 85
    uint32 EffectRadiusIndex[3];                  
    uint32 EffectApplyAuraName[3];                
    uint32 EffectAmplitude[3];                    
    uint32 Effectunknown[3];                      
    uint32 EffectChainTarget[3];                  
    uint32 EffectItemType[3];                     
    uint32 EffectMiscValue[3];                    
    uint32 EffectTriggerSpell[3];                 
    float EffectPointsPerComboPoint[3];           
    uint32 SpellVisual;                           
    uint32 field114;                              
    uint32 SpellIconID;                          
    uint32 activeIconID;                          
	uint32 spellPriority;                         
    uint32 Name;
    uint32 NameAlt1;
    uint32 NameAlt2;
    uint32 NameAlt3;
    uint32 NameAlt4;
    uint32 NameAlt5;
    uint32 NameAlt6;
    uint32 NameAlt7;
    uint32 NameFlags;
    uint32 Rank;
    uint32 RankAlt1;
    uint32 RankAlt2;
    uint32 RankAlt3;
    uint32 RankAlt4;
    uint32 RankAlt5;
    uint32 RankAlt6;
    uint32 RankAlt7;
    uint32 RankFlags;
    uint32 Description;
    uint32 DescriptionAlt1;
    uint32 DescriptionAlt2;
    uint32 DescriptionAlt3;
    uint32 DescriptionAlt4;
    uint32 DescriptionAlt5;
    uint32 DescriptionAlt6;
    uint32 DescriptionAlt7;
    uint32 DescriptionFlags;
    uint32 BuffDescription;
    uint32 BuffDescriptionAlt1;
    uint32 BuffDescriptionAlt2;
    uint32 BuffDescriptionAlt3;
    uint32 BuffDescriptionAlt4;
    uint32 BuffDescriptionAlt5;
    uint32 BuffDescriptionAlt6;
    uint32 BuffDescriptionAlt7;
    uint32 ManaCostPercentage;
    uint32 StartRecoveryCategory;
    uint32 StartRecoveryTime;
    uint32 field156;
    uint32 field157;
	uint32 field158; // added
    uint32 SpellFamilyName;
    int32 field160;
    uint32 field161;
	uint32 field162;
    uint32 field163; // added
	uint32 field164; // added
	uint32 field165; // added
	uint32 field166; // added
	uint32 field167; // added
/*  Old WDDG Crap
	uint32 Id;
    uint32 School;
    uint32 Category;
    uint32 field4;
    uint32 isDispelable;		// 5 # Dispel
    uint32 Attributes;			// 6
    uint32 AttributesEx;		// 7
    uint32 field8;
    uint32 field9;
    uint32 Targets;				// 10

	uint32 __crap_01;
	uint32 __crap_02;
    uint32 TargetCreatureType;	// 13
    uint32 RequiresSpellFocus;	// 14
    uint32 CasterAuraState;		// 15
    uint32 TargetAuraState;		// 16
	//uint32 __crap_01; WTF was this???? that's really crap, isn't it? neither working with 1.5.0 nor with 1.6.0
	//uint32 __crap_02;
    uint32 CastingTimeIndex;			// 17
    uint32 RecoveryTime;				// 18
    uint32 CategoryRecoveryTime;		// 19 # Cooldown
    uint32 InterruptFlags;				// 20

    uint32 AuraInterruptFlags;
    uint32 ChannelInterruptFlags;
	//uint32 __crap_01;
	//uint32 __crap_02;
    uint32 procFlags;
    uint32 procChance;
    uint32 procCharges;
    uint32 maxLevel;
    uint32 baseLevel;
    uint32 spellLevel;
    uint32 DurationIndex;				// 29
    uint32 powerType;					// 30

    uint32 manaCost;
    uint32 manaCostPerlevel;
    uint32 manaPerSecond;
    uint32 manaPerSecondPerLevel;
    uint32 rangeIndex;
    float speed;
    uint32 modalNextSpell;
    uint32 field36;
    //uint32 field37;
    uint32 Totem1;						// NO I THINK IT IS "TOOL1 and below TOOL2"
    uint32 Totem2;						// 40

    uint32 Reagent[8];					// 41-48
    uint32 ReagentCount[8];				// 49-56
    uint32 EquippedItemClass;			// 57
    uint32 EquippedItemSubClass;		// 58
    uint32 Effect[3];					// 59-61
    uint32 EffectDieSides[3];			// 62-64
    uint32 EffectBaseDice[3];			// 65-67
    uint32 EffectDicePerLevel[3];		// 68-70
    int32  EffectRealPointsPerLevel[3];	// 71-73
	int32  EffectBasePoints[3];			// 74-76
	int32  unk180[3];					// 77-79 NEW IN 1.8.0
    uint32 EffectImplicitTargetA[3];	// 80-82
    uint32 EffectImplicitTargetB[3];	// 83-85
    uint32 EffectRadiusIndex[3];		// 86-88 // was 2!
    uint32 EffectApplyAuraName[3];		// 89-91 shall be FLOAT (was uint32)
    float  EffectAmplitude[3];			// 92-94
    uint32 Effectunknown[3];			// 95-97
    uint32 EffectChainTarget[3];		// 98-100

    uint32 EffectItemType[3];			// 101-102
    uint32 EffectMiscValue[3];			// 103-105
    uint32 EffectTriggerSpell[3];		// 106-108
    float Effectunknown2[3];			// 109-111

    uint32 SpellVisual;					// 112
    uint32 field110;					// 113
    uint32 SpellIconID;					// 114
    uint32 activeIconID;				// 115
    uint32 spellPriority;				// 116
	std::string Name;					// 117
    uint32 NameAlt1;
    uint32 NameAlt2;
    uint32 NameAlt3;					// 120

    uint32 NameAlt4;					
    uint32 NameAlt5;
    uint32 NameAlt6;
    uint32 NameAlt7;
    uint32 NameFlags;
    uint32 Rank;						
    uint32 RankAlt1;
    uint32 RankAlt2;
    uint32 RankAlt3;
    uint32 RankAlt4;					// 130

    uint32 RankAlt5;					
    uint32 RankAlt6;
    uint32 RankAlt7;
    uint32 RankFlags;
    uint32 Description;
    uint32 DescriptionAlt1;
    uint32 DescriptionAlt2;
    uint32 DescriptionAlt3;
    uint32 DescriptionAlt4;
    uint32 DescriptionAlt5;				// 140

    uint32 DescriptionAlt6;			
    uint32 DescriptionAlt7;
    uint32 DescriptionFlags;
    uint32 BuffDescription;
    uint32 BuffDescriptionAlt1;
    uint32 BuffDescriptionAlt2;
    uint32 BuffDescriptionAlt3;
    uint32 BuffDescriptionAlt4;
    uint32 BuffDescriptionAlt5;
    uint32 BuffDescriptionAlt6;			// 150

    uint32 BuffDescriptionAlt7;		
	uint32 BuffDescriptionFlags;
    uint32 ManaCostPercentage;
    uint32 StartRecoveryCategory;
    uint32 StartRecoveryTime;
    uint32 field156;
    uint32 field157;
    uint32 SpellClass;		// warrior 4, paladin 10, hunter 9, rogue 8, priest 6, shaman 11, mage 3, warlock 5, druid 7
    uint32 field159;
	uint32 field160;				// 160

	uint32 field161;
	uint32 field162;
	uint32 field163;
	uint32 field164;
	uint32 field165;
	uint32 field166;
	uint32 field167;*/
} SpellEntry;

typedef struct
{
	uint32 Id;			// Trainer NPC GUID
	uint32 skilline01;	// 1st skill line that trainer teaches
	uint32 skilline02;	// 2nd skill line that trainer teaches
	uint32 skilline03;	// 3rd skill line that trainer teaches
	uint32 skilline04;	// 4th skill line that trainer teaches
	uint32 skilline05;	// 5th skill line that trainer teaches
	uint32 skilline06;	// 6th skill line that trainer teaches
	uint32 skilline07;	// 7th skill line that trainer teaches
	uint32 skilline08;	// 8th skill line that trainer teaches
	uint32 skilline09;	// 9th skill line that trainer teaches
	uint32 skilline10;	// 10th skill line that trainer teaches
	uint32 skilline11;	// 11th skill line that trainer teaches
	uint32 skilline12;	// 12th skill line that trainer teaches
	uint32 skilline13;	// 13th skill line that trainer teaches
	uint32 skilline14;	// 14th skill line that trainer teaches
	uint32 skilline15;	// 15th skill line that trainer teaches
	uint32 skilline16;	// 16th skill line that trainer teaches
	uint32 skilline17;	// 17th skill line that trainer teaches
	uint32 skilline18;	// 18th skill line that trainer teaches
	uint32 skilline19;	// 19th skill line that trainer teaches
	uint32 skilline20;	// 20th skill line that trainer teaches
	uint32 maxlvl;
	uint32 charclass;
} Trainerspell;

typedef struct
{
    uint32 ID;
    uint32 CastTime;
	uint32 unk1;
	uint32 unk2;
} SpellCastTime;

typedef struct
{
    uint32 ID;
    float Radius;
	float unk1;
	float Radius2;
} SpellRadius;

typedef struct
{
    uint32 ID;
    float minRange;
	float Range;
	uint32 unks[18];
} SpellRange;

typedef struct
{
    uint32 ID;
    uint32 Duration1;
    uint32 Duration2;
    uint32 Duration3;
} SpellDuration;

typedef struct 
{
	uint32	ID;
	uint32	mapId;
	uint32	zoneId;
	uint32	zoneName;
	float	y1, y2;
	float	x1, x2;
} WorldMapArea;

typedef struct
{
	uint32 ID;
	uint32 map;
	uint32 zone;
	uint32 exploreFlag;
	uint32 type;
	uint32 unk1;
	uint32 faction;
	uint32 ukn4;
	uint32 ukn5;
	uint32 ukn6;
	uint32 ukn7;
	uint32 blank1[2];
	std::string name;
	uint32 blank2[5];
	uint32 ukn8;
	uint32 AroundCapitalFact; // 4.Horde | 2.Alliance | 0.Not around any capital
} AreaTableEntry;

typedef struct
{
    uint32 ID;
	uint32 worldMapAreaID;
	uint32 areaTableID;
	uint32 unk1;
	uint32 unk2;
	uint32 unk3;
	uint32 unk4;
	uint32 unk5;
	std::string name;
	uint32 areaW; //in pixels 2x
	uint32 areaH; //in pixels 2x
	uint32 unk6;  //I think columns #12, #13, #14 and #15
	uint32 unk7;  //are some kind of positions, but i did not
	uint32 unk8;  //discover what exactly.
	uint32 unk9;
	uint32 drawX; //in pixels
	uint32 drawY; //in pixels
} WorldMapOverlayEntry;

typedef struct
{
    uint32 ID;
	std::string name;	// Text Data
	uint32 SpellItemEnchantmentID_1;
	uint32 SpellItemEnchantmentID_2;
	uint32 SpellItemEnchantmentID_3;
	uint32 unk4;
	uint32 unk5;
	uint32 unk6;
	uint32 unk7;
	std::string suffix;  // Text Data
	uint32 unk8;
	uint32 unk9;
	uint32 unk10;
	uint32 unk11;
	uint32 unk12;
	uint32 unk13;
} ItemRandomPropertiesEntry;

typedef struct
{
    uint32 ID;
	uint32 SpellDispelType_ID;
	uint32 unk1;
	uint32 unk2;
	uint32 unk3;
	uint32 unk4;
	uint32 unk5;
	uint32 unk6;
	uint32 unk7;
	uint32 unk8;
	uint32 unk9;
	uint32 unk10;
	uint32 unk11;
	uint32 unk12;
	uint32 unk13;
	std::string Description;  // Text Data
	uint32 unk14;
	uint32 unk15;
	uint32 unk16;
	uint32 unk17;
	uint32 unk18;
	uint32 unk19;
	uint32 SpellAura_ID;
	uint32 unk20;
} SpellItemEnchantmentEntry;

typedef struct
{
    uint32 ID;
	uint32 Faction_Id;

	uint32 unk2;
	uint32 unk3;
	uint32 unk4;
	uint32 unk5;
	uint32 unk6;
	uint32 unk7;
	uint32 unk8;
	uint32 unk9;

	uint32 unk10;
	uint32 unk11;
	uint32 unk12;
	uint32 unk13;
	uint32 unk14;
	uint32 unk15;
	uint32 unk16;
	uint32 unk17;
	uint32 unk18;
	uint32 unk19;

	uint32 unk20;
	std::string Name;
	uint32 unk22;
	uint32 unk23;
	uint32 unk24;
	uint32 unk25;
	uint32 unk26;
	uint32 unk27;
	uint32 unk28;
	uint32 unk29;

	uint32 unk30;
	uint32 unk31;
	uint32 unk32;
	uint32 unk33;
	uint32 unk34;
	uint32 unk35;
	uint32 unk36;
	uint32 unk37;

} FactionEntry;

typedef struct {
	uint32 Id;
	uint32 from;
	uint32 to;
	uint32 price;
} TaxiPathEntry;

typedef struct {
	uint32 id;
	uint32 pathId;
	uint32 index;
	uint32 mapId;
	float x;
	float y;
	float z;
	uint32 blank;
	uint32 blank1;
} TaxiPathNodeEntry;

typedef struct {
	uint32 id;
	uint32 unk0;
	uint32 blank[3];
	std::string pattern;
	uint32 blank2[8];
	std::string name;
	uint32 blank3[6];
} ChatChannelsEntry;

//-----------------------------------------------------------------------------
float GetRadius(SpellRadius *radius);
uint32 GetCastTime(SpellCastTime *time);
float GetRange(SpellRange *range);
float GetMinRange(SpellRange *range);
float GetMaxRange(SpellRange *range);
uint32 GetDuration(SpellDuration *dur);

//-----------------------------------------------------------------------------
// You need two lines like this for every new DBC store
defineIndexedDBCStore (SpellStore, SpellEntry);
defineDBCStore (DurationStore, SpellDuration);
defineDBCStore (RangeStore, SpellRange);	//Not indexed because of some errors
defineIndexedDBCStore (EmoteStore, EmoteEntry);
defineIndexedDBCStore (RadiusStore, SpellRadius);
defineDBCStore (CastTimeStore, SpellCastTime);
defineIndexedDBCStore (WorldMapAreaStore, WorldMapArea);
defineIndexedDBCStore(AreaTableStore,AreaTableEntry);
defineDBCStore(WorldMapOverlayStore,WorldMapOverlayEntry);
defineIndexedDBCStore(TalentStore,TalentEntry);
defineDBCStore (SkillStore, skilllinespell);
defineIndexedDBCStore (ItemRandomPropertiesStore, ItemRandomPropertiesEntry);
defineIndexedDBCStore (SpellItemEnchantmentStore, SpellItemEnchantmentEntry);
defineIndexedDBCStore (FactionStore, FactionEntry);
defineIndexedDBCStore (TaxiPathStore, TaxiPathEntry);
defineIndexedDBCStore (TaxiPathNodeStore, TaxiPathNodeEntry);
defineIndexedDBCStore (ChatChannelsStore, ChatChannelsEntry);
//-----------------------------------------------------------------------------
#define sSpellStore SpellStore::getSingleton()
#define sSkillStore SkillStore::getSingleton()
#define sEmoteStore EmoteStore::getSingleton()
#define sSpellDuration DurationStore::getSingleton()
#define sSpellRange RangeStore::getSingleton()
#define sSpellRadius RadiusStore::getSingleton()
#define sCastTime CastTimeStore::getSingleton()
#define sWorldMapArea WorldMapAreaStore::getSingleton()
#define sAreaTableStore AreaTableStore::getSingleton()
#define sWorldMapOverlayStore WorldMapOverlayStore::getSingleton()
#define sTalentStore TalentStore::getSingleton()
#define sItemRandomPropertiesStore ItemRandomPropertiesStore::getSingleton()
#define sSpellItemEnchantmentStore SpellItemEnchantmentStore::getSingleton()
#define sFactionStore FactionStore::getSingleton()
#define sTaxiPathStore TaxiPathStore::getSingleton()
#define sTaxiPathNodeStore TaxiPathNodeStore::getSingleton()
#define sChatChannelsStore ChatChannelsStore::getSingleton()

#endif
