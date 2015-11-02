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

#ifndef WOWSERVER_GAMEOBJECT_H
#define WOWSERVER_GAMEOBJECT_H

#include "Object.h"
#include "QuestPacketHandler.h"
#include <vector>

struct GameobjectTemplate
{
	uint32	Entry;
	string	Name;
	uint32	Model;
	uint32	Sound[10];
	uint32	Faction;
	uint32	Flags;
	uint32	GType;
	float	Size;
	uint32  Level;
};

enum GOTypes {
	GAMEOBJECT_TYPE_DOOR			=0,
	GAMEOBJECT_TYPE_BUTTON			=1,
	GAMEOBJECT_TYPE_QUESTGIVER		=2,
	GAMEOBJECT_TYPE_CHEST			=3,
	GAMEOBJECT_TYPE_BINDER			=4,
	GAMEOBJECT_TYPE_GENERIC			=5,
	GAMEOBJECT_TYPE_TRAP			=6,
	GAMEOBJECT_TYPE_CHAIR			=7,
	GAMEOBJECT_TYPE_SPELL_FOCUS		=8,
	GAMEOBJECT_TYPE_TEXT			=9,
	GAMEOBJECT_TYPE_GOOBER			=10,
	GAMEOBJECT_TYPE_TRANSPORT		=11,
	GAMEOBJECT_TYPE_AREADAMAGE		=12,
	GAMEOBJECT_TYPE_CAMERA			=13,
	GAMEOBJECT_TYPE_MAP_OBJECT		=14,
	GAMEOBJECT_TYPE_MO_TRANSPORT	=15,
	GAMEOBJECT_TYPE_DUEL_ARBITER	=16,
	GAMEOBJECT_TYPE_FISHINGNODE		=17,
	GAMEOBJECT_TYPE_RITUAL			=18,
	GAMEOBJECT_TYPE_MAILBOX			=19,
	GAMEOBJECT_TYPE_AUCTIONHOUSE	=20,
	GAMEOBJECT_TYPE_GUARDPOST		=21,
	GAMEOBJECT_TYPE_SPELLCASTER		=22,
	GAMEOBJECT_TYPE_MEETINGSTONE	=23
};

enum GOLockTypes {
	GOBJ_LOCKTYPE_PICKLOCK				=1,
	GOBJ_LOCKTYPE_HERBALISM				=2,
	GOBJ_LOCKTYPE_MINING				=3,
	GOBJ_LOCKTYPE_DISARM_TRAP			=4,
	GOBJ_LOCKTYPE_OPEN					=5,
	GOBJ_LOCKTYPE_TREASURE				=6,
	GOBJ_LOCKTYPE_CALCIFIED_ELVEN_GEMS	=7,
	GOBJ_LOCKTYPE_CLOSE					=8,
	GOBJ_LOCKTYPE_ARM_TRAP				=9,
	GOBJ_LOCKTYPE_QUICK_OPEN			=10,
	GOBJ_LOCKTYPE_QUICK_CLOSE			=11,
	GOBJ_LOCKTYPE_OPEN_TINKERING		=12,
	GOBJ_LOCKTYPE_OPEN_KNEELING			=13,
	GOBJ_LOCKTYPE_OPEN_ATTACKING		=14,
	GOBJ_LOCKTYPE_GAHZRIDIAN			=15,
	GOBJ_LOCKTYPE_BLASTING				=16,
	GOBJ_LOCKTYPE_SLOW_OPEN				=17,
	GOBJ_LOCKTYPE_SLOW_CLOSE			=18
};

struct ObjectItem
{
    uint32 itemid;
	int amount;
	uint32 display_id;
};
typedef vector<ObjectItem> GObjectItemVector;

//-----------------------------------------------------------------------------
// GO Loot templates support data types
//-----------------------------------------------------------------------------
typedef struct {
	uint32	ItemId;
	float	Chance;
} LootGOTemplate;

typedef vector<LootGOTemplate> LootGOTemplateVector;
typedef stdext::hash_map<uint32, LootGOTemplateVector *> LootGOTemplateVectorMap;	// key -> obj_id
//-----------------------------------------------------------------------------

class GameObject : public Object
{
public:
    GameObject( );
	~GameObject()
	{
		mQuestIds.clear( );
		mInvolvedQuestIds.clear();
	}

    void Create ( uint32 guidlow, uint32 display_id, uint8 state, uint32 obj_field_entry,
        float scale, uint16 type, uint16 faction, uint32 mapid,
        float x, float y, float z, float ang );
	void Create (uint32 guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang,
		float rotation0=0, float rotation1=0, float rotation2=0, float rotation3=0);

    void Update (int32 p_time);
	void Update (uint32 p_time);
    void Despawn(uint32 time);

	// -------------

	void managePlayerQuests(Player *pPlayer);

    bool hasQuest(uint32 quest_id);
    bool hasInvolvedQuest(uint32 quest_id);

    void addQuest(uint32 quest_id) { mQuestIds.push_back(quest_id); };
    void addInvolvedQuest(uint32 quest_id) { mInvolvedQuestIds.push_back(quest_id); };

	const char* GetName() const { return m_name.c_str(); };

	// ----------------

    int		getItemAmount(int slot) { return m_ItemAmount[slot]; }
	void	setItemAmount(int slot, uint32 value) { m_ItemAmount[slot] = value; }
	uint32	getItemId(int slot) { return m_ItemList[slot]; }
    
	bool FillLoot(WorldPacket *data);
	bool hasLoot()
	{
        bool hasLoot = false;
        for(int i=0;i<10;++i)
            if(m_ItemAmount[i] && m_ItemAmount[i] != 0)
                hasLoot = true;
        return hasLoot;

    }
	
	// GO Looting
	void addItem (uint32 itemid, uint32 amount, uint32 displayid)
    {
		ObjectItem	item;
		
		item.itemid = itemid;
		item.amount = amount;
        item.display_id = displayid;

		item_list.push_back (item);
    }

    // Serialization
    void SaveToDB();
    void LoadFromDB(uint32 guid);
	void SpawnGameObjectFromDB(Field* fields);
    void DeleteFromDB();

	// GameObject special stuff
	bool isFireGO();
	
	GameobjectTemplate* m_GoTpl;

protected:
    /// Quest data
    list<uint32> mQuestIds;
    list<uint32> mInvolvedQuestIds;
	
	// GO Looting

	void _generateLoot();    

	GObjectItemVector item_list;

    void _LoadQuests();

    int32 m_RespawnTimer;
	int32 m_MiscTimer;
    uint32 m_gold;
    uint32 m_ItemList[10],m_ItemAmount[10];
    uint8 m_ItemCount;
    string m_name;
};

#endif
