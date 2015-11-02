#include "StdAfx.h"
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

SpEffect EffectHandlers[TOTAL_SPELL_EFFECTS] = {
	&Spell::Effect_None,					// NONE
	&Spell::Effect_Instakill,				// INSTAKILL
	&Spell::Effect_SchoolDamage,			// SCHOOL_DAMAGE
	&Spell::Effect_None,					// DUMMY
	&Spell::Effect_Not_Supported,			// PORTAL_TELEPORT
	&Spell::Effect_TeleportUnit,			// TELEPORT_UNITS
	&Spell::Effect_ApplyAura,				// APPLY_AURA
	&Spell::Effect_Not_Supported,			// ENVIRONMENTAL_DAMAGE
	&Spell::Effect_PowerDrain,				// POWER_DRAIN
	&Spell::Effect_Not_Supported,			// HEALTH_LEECH
	&Spell::Effect_Heal,					// HEAL
	&Spell::Effect_Not_Supported,			// BIND
	&Spell::Effect_Not_Supported,			// PORTAL
	&Spell::Effect_Not_Supported,			// RITUAL_BASE
	&Spell::Effect_Not_Supported,			// RITUAL_SPECIALIZE
	&Spell::Effect_Not_Supported,			// RITUAL_ACTIVATE_PORTAL
	&Spell::Effect_Not_Supported,			// QUEST_COMPLETE
	&Spell::Effect_Weapon_Damage_Add_Noschool,	// WEAPON_DAMAGE_ADD_NOSCHOOL
	&Spell::Effect_Resurrect,				// RESURRECT
	&Spell::Effect_Not_Supported,			// EXTRA_ATTACKS
	&Spell::Effect_Not_Supported,			// DODGE
	&Spell::Effect_Not_Supported,			// EVADE
	&Spell::Effect_Not_Supported,			// PARRY
	&Spell::Effect_Not_Supported,			// BLOCK
	&Spell::Effect_Create_Item,				// CREATE_ITEM
	&Spell::Effect_Not_Supported,			// WEAPON
	&Spell::Effect_Not_Supported,			// DEFENSE
	&Spell::Effect_Persistent_Area_Aura,	// PERSISTENT_AREA_AURA
	&Spell::Effect_Not_Supported,			// SUMMON
	&Spell::Effect_Leap,					// LEAP
	&Spell::Effect_Energize,				// ENERGIZE
	&Spell::Effect_Weapon_Dmg_Percent,		// WEAPON_DMG_PERCENT
	&Spell::Effect_Not_Supported,			// TRIGGER_MISSILE
	&Spell::Effect_Open_Lock,				// OPEN_LOCK
	&Spell::Effect_None,					// SUMMON_MOUNT_OBSOLETE
	&Spell::Effect_Apply_Area_Aura,			// APPLY_AREA_AURA
	&Spell::Effect_Learn_Spell,				// LEARN_SPELL
	&Spell::Effect_Not_Supported,			// SPELL_DEFENSE
	&Spell::Effect_Not_Supported,			// DISPEL
	&Spell::Effect_Language,			// LANGUAGE
	&Spell::Effect_Not_Supported,			// DUAL_WIELD
	&Spell::Effect_Summon_Wild,				// SUMMON_WILD
	&Spell::Effect_Not_Supported,			// SUMMON_GUARDIAN
	&Spell::Effect_Not_Supported,			// TELEPORT_UNITS_FACE_CASTER
	&Spell::Effect_Not_Supported,			// SKILL_STEP
	&Spell::Effect_Not_Supported,			// SPAWN
	&Spell::Effect_None,					// -
	&Spell::Effect_Not_Supported,			// SPELL_CAST_UI
	&Spell::Effect_Not_Supported,			// STEALTH
	&Spell::Effect_Not_Supported,			// DETECT
	&Spell::Effect_Not_Supported,			// TRANS_DOOR
	&Spell::Effect_Not_Supported,			// FORCE_CRITICAL_HIT
	&Spell::Effect_Not_Supported,			// GUARANTEE_HIT
	&Spell::Effect_Enchant_Item_Permanent,	// ENCHANT_ITEM_PERMANENT
	&Spell::Effect_Enchant_Item_Temporary,	// ENCHANT_ITEM_TEMPORARY
	&Spell::Effect_Not_Supported,			// TAME_CREATURE
	&Spell::Effect_Summon_Pet,				// SUMMON_PET
	&Spell::Effect_Not_Supported,			// LEARN_PET_SPELL
	&Spell::Effect_Weapon_Damage_Add,		// WEAPON_DAMAGE_ADD
	&Spell::Effect_OpenLockItem,			// OPEN_LOCK_ITEM
	&Spell::Effect_Not_Supported,			// PROFICIENCY
	&Spell::Effect_Not_Supported,			// SEND_EVENT
	&Spell::Effect_PowerDrain,				// POWER_BURN
	&Spell::Effect_Not_Supported,			// THREAT
	&Spell::Effect_Trigger_Spell,			// TRIGGER_SPELL
	&Spell::Effect_Not_Supported,			// HEALTH_FUNNEL
	&Spell::Effect_Not_Supported,			// POWER_FUNNEL
	&Spell::Effect_Heal_Max_Health,			// HEAL_MAX_HEALTH
	&Spell::Effect_Interrupt_Cast,			// INTERRUPT_CAST
	&Spell::Effect_Not_Supported,			// DISTRACT
	&Spell::Effect_Not_Supported,			// PULL
	&Spell::Effect_Not_Supported,			// PICKPOCKET
	&Spell::Effect_Not_Supported,			// ADD_FARSIGHT
	&Spell::Effect_Not_Supported,			// SUMMON_POSSESSED
	&Spell::Effect_Not_Supported,			// SUMMON_TOTEM
	&Spell::Effect_Not_Supported,			// HEAL_MECHANICAL
	&Spell::Effect_Not_Supported,			// SUMMON_OBJECT_WILD
	&Spell::Effect_Script_Effect,			// SCRIPT_EFFECT
	&Spell::Effect_Not_Supported,			// ATTACK
	&Spell::Effect_Not_Supported,			// SANCTUARY
	&Spell::Effect_Add_Combo_Points,		// ADD_COMBO_POINTS
	&Spell::Effect_Not_Supported,			// CREATE_HOUSE
	&Spell::Effect_Not_Supported,			// BIND_SIGHT
	&Spell::Effect_SendDuelRequest,			// DUEL
	&Spell::Effect_Not_Supported,			// STUCK
	&Spell::Effect_Not_Supported,			// SUMMON_PLAYER
	&Spell::Effect_Not_Supported,			// ACTIVATE_OBJECT
	&Spell::Effect_Summon_Totem,			// SUMMON_TOTEM_SLOT1
	&Spell::Effect_Summon_Totem,			// SUMMON_TOTEM_SLOT2
	&Spell::Effect_Summon_Totem,			// SUMMON_TOTEM_SLOT3
	&Spell::Effect_Summon_Totem,			// SUMMON_TOTEM_SLOT4
	&Spell::Effect_Not_Supported,			// THREAT_ALL
	&Spell::Effect_Enchant_Held_Item,		// ENCHANT_HELD_ITEM
	&Spell::Effect_Not_Supported,			// SUMMON_PHANTASM
	&Spell::Effect_Not_Supported,			// SELF_RESURRECT
	&Spell::Effect_Not_Supported,			// SKINNING
	&Spell::Effect_Not_Supported,			// CHARGE
	&Spell::Effect_Not_Supported,			// SUMMON_CRITTER
	&Spell::Effect_Not_Supported,			// KNOCK_BACK
	&Spell::Effect_Not_Supported,			// DISENCHANT
	&Spell::Effect_Not_Supported,			// INEBRIATE - for alcohol items.
	&Spell::Effect_Trigger_Spell,			// FEED_PET
	&Spell::Effect_Not_Supported,			// DISMISS_PET
	&Spell::Effect_Not_Supported,			// REPUTATION
	&Spell::Effect_Summon_Object,			// SUMMON_OBJECT_SLOT1
	&Spell::Effect_Summon_Object,			// SUMMON_OBJECT_SLOT2
	&Spell::Effect_Summon_Object,			// SUMMON_OBJECT_SLOT3
	&Spell::Effect_Summon_Object,			// SUMMON_OBJECT_SLOT4
	&Spell::Effect_Not_Supported,			// DISPEL_MECHANIC
	&Spell::Effect_Not_Supported,			// SUMMON_DEAD_PET
	&Spell::Effect_Not_Supported,			// DESTROY_ALL_TOTEMS
	&Spell::Effect_Not_Supported,			// DURABILITY_DAMAGE
	&Spell::Effect_Not_Supported,			// SUMMON_DEMON
	&Spell::Effect_Resurrect_Flat,			// RESURRECT_FLAT
	&Spell::Effect_Not_Supported,			// ATTACK_ME
	&Spell::Effect_Not_Supported,			// DURABILITY_DMG_PERCENT
	&Spell::Effect_Not_Supported,			// SKIN_PLAYER_CORPSE
	&Spell::Effect_Not_Supported,			// FFECT_SPIRIT_HEAL
	&Spell::Effect_Not_Supported,			// SKILL
	&Spell::Effect_Not_Supported,			// AURA_NEW
	&Spell::Effect_Not_Supported,			// TELEPORT_GRAVEYARD
	&Spell::Effect_SchoolDamage				// ADITIONNAL_DAMAGE
};

void
Spell::Effect_SendDuelRequest(uint32 i)
{
	if(m_caster->isNotPlayer() || !playerTarget) return;
	if(m_caster->isHostileToMe(playerTarget)) return;
	if(m_caster->isStealth())
	{
		SendCastResult (CAST_FAIL_CANT_START_DUEL_STEALTHED);
		return;
	}
	if(playerTarget->isDueling())
	{
		SendCastResult (CAST_FAIL_TARGET_IS_DUELING);
		return;
	}
	if(sWorld.isInstanceMapId(m_caster->GetMapId()))
	{
		SendCastResult (CAST_FAIL_NO_DUELING_HERE);
		return;
	}

	WorldPacket data;

	GameObject* pDuelArb = new GameObject();
	float C_x = m_caster->GetPositionX(),
		  C_y = m_caster->GetPositionY(),
		  C_o = m_caster->GetOrientation(),
		  T_x = playerTarget->GetPositionX(),
		  T_y = playerTarget->GetPositionY(),
		  Arb_o = (C_o+1.570796),
		  Arb_x = (C_x+ 5*cos(Arb_o)),
		  Arb_y = (C_y+ 5*sin(Arb_o));

	pDuelArb->Create(
		objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT),
		21680,
		m_caster->GetMapId(),
		Arb_x,
		Arb_y,
		m_caster->GetPositionZ(),
		m_caster->GetOrientation()
	);
	objmgr.AddObject(pDuelArb);
	pDuelArb->PlaceOnMap();
	uint64 ArbGuid = pDuelArb->GetGUID();

	data.Initialize(SMSG_GAMEOBJECT_SPAWN_ANIM);
	data << (uint64)ArbGuid;
	pDuelArb->SendMessageToSet(&data, false);

	data.Initialize(SMSG_DUEL_REQUESTED);
	data << (uint64)ArbGuid << (uint64)playerCaster->GetGUID();
	playerTarget->GetSession()->SendPacket(&data);

	playerCaster->SetDuelFlag(pDuelArb);
	playerTarget->SetDuelFlag(pDuelArb);
	playerCaster->SetDuelSender(playerCaster);
	playerTarget->SetDuelSender(playerCaster);
	playerCaster->SetUInt64Value(PLAYER_DUEL_ARBITER, ArbGuid);
	playerTarget->SetUInt64Value(PLAYER_DUEL_ARBITER, ArbGuid);
	playerCaster->m_Duel_timer = -1;
	playerTarget->m_Duel_timer = -1;
	playerCaster->SetInDuel(false);
	playerTarget->SetInDuel(false);
}

void
Spell::Effect_TeleportUnit(uint32 i)
{
	switch(m_spellInfo->Id)
	{
	case 665:
	case 3561:
	case 17334: playerTarget->TeleportFar(0, -8960.140625, 516.265686, 96.356819); break;
	case 3577:
	case 3563:  playerTarget->TeleportFar(0, 1819.708374, 238.789505, 60.532143); break;
	case 3565:
	case 3578:  playerTarget->TeleportFar(1, 9951.792969, 2145.915771, 1327.724854); break;
	case 3566:
	case 3579:  playerTarget->TeleportFar(1, -1391.0, 140.0, 22.478); break;
	case 3567:
	case 3580:
	case 4996:  playerTarget->TeleportFar(1, 1552.499268, -4420.658691, 8.948024); break;
	case 556:
	case 8690:  playerTarget->TeleportToBindpoint(); break;
	case 12509:
	case 12510: playerTarget->TeleportFar(1, 4232.007813, -7802.841309, 4.689385); break;
	case 18960:
	case 19027: playerTarget->TeleportFar(1, 7980.842285, -2501.763428, 487.576508); break;
	case 3581:
	case 3562:
	case 17607: playerTarget->TeleportFar(0, -5032, -819, 495); break;

	case 446:   playerTarget->TeleportFar(0, -10531.167969, 296.656219, 30.964926); break;
	case 17611: playerTarget->TeleportFar(0, 1819.708374, 238.789505, 60.532143); break;
	case 427:   playerTarget->TeleportFar(0, 2889.91, -811.148, 160.332); break;
	case 5000:  playerTarget->TeleportFar(0, 1819.708374, 238.789505, 60.532143); break;
	case 21098: playerTarget->TeleportFar(0, -9473.583984, 62.798809, 56.068027); break;
	case 1936:  playerTarget->TeleportFar(0, -6132, 384, 395.5); break;
	case 33:    playerTarget->TeleportFar(0, -13923.823242, 1313.069580, 6); break;
	case 34:    playerTarget->TeleportFar(0, -13828.068359, 1299.230347, 7); break;
	case 35:    playerTarget->TeleportFar(0, -14002.620117, 1271.615479, 3); break;
	case 428:   playerTarget->TeleportFar(0, -11025.184570, 1497.860596, 43.195259); break;
	case 442:   playerTarget->TeleportFar(0, -8929, -116, 83); break;
	case 444:   playerTarget->TeleportFar(0, -11409.933594, 1968.416504, 10.427084); break;
	case 445:   playerTarget->TeleportFar(0, -10413.885742, -1136.884888, 24.128809); break;
	case 4998:  playerTarget->TeleportFar(0, -12342, 266, 4); break;
	case 4997:  playerTarget->TeleportFar(0, -14438.113281, 482.592377, 28.869307); break;
	case 6348:  playerTarget->TeleportFar(0, -3907.5, -620.2, 4.9); break;
	case 11409: playerTarget->TeleportFar(0, -14319.114258, 444.477905, 23.054321); break;

	case 17608: playerTarget->TeleportFar(1, 9951.792969, 2145.915771, 1327.724854); break;
	case 17609: playerTarget->TeleportFar(1, 1552.499268, -4420.658691, 8.948024); break;
	case 6349:  playerTarget->TeleportFar(1, 6410.009766, 527.034973, 14.057800); break; 
	case 6483:  playerTarget->TeleportFar(1, 5483.899902, -749.880981, 334.621002); break;
	case 12520: playerTarget->TeleportFar(1, 9892.57, 982.424, 1313.83); break; 
	case 17160: playerTarget->TeleportFar(1, 6107.62, -4181.60, 852.32); break;
	case 17610: playerTarget->TeleportFar(1, -1391.0, 140.0, 22.478); break;
	case 6719:  playerTarget->TeleportFar(1, -3993.8, -4727.2, 4.8); break; 
	case 31:    playerTarget->TeleportFar(1, -994.248169, -3830.104004, 7); break;
	case 4999:  playerTarget->TeleportFar(1, -1000.142395, -3824.600830, 6.277908); break;

	case 8735:  playerTarget->TeleportFar(48, -151.89, 106.96, -39.87); break;
	case 11362: playerTarget->TeleportFar(90, -330, -2, -151); break;
	case 20618: /*Teleports an ennemy in a burning coal field*/ break;
	case 21463: {
		Unit* Target = NULL;
		Target = objmgr.GetObject<Creature>(playerTarget->GetSelection());
		if(Target == NULL)
            Target = objmgr.GetObject<Player>(playerTarget->GetSelection());
		playerTarget->TeleportNear(Target->GetPositionX(), Target->GetPositionY(), Target->GetPositionZ());
	} break;
	case 443: {
		switch(playerTarget->GetRace()) {
			case 1:
			case 3:
			case 5:
			case 7: playerTarget->TeleportFar(449, 0.54, 5.50, -0.26); break;
			case 2:
			case 4:
			case 6:
			case 8: playerTarget->TeleportFar(450, 222.27, 75.00, 25.72); break;
		}
	} break;
	default: sLog.outDebug("SpellEffects|Teleport_Units|No destination for spellId=%d", m_spellInfo->Id);
			return;
	}
	sLog.outDebug("SpellEffects|TP_Units|Player teleported using spellId=%d", m_spellInfo->Id);
}

void
Spell::Effect_SchoolDamage(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;
	uint32 baseDamage = m_spellInfo->EffectBasePoints[i];

	if (m_caster->GetPowerIndex() == POWER_TYPE_ENERGY && // Energy
		AbilityRequiresComboPoints (m_spellInfo->Id) &&
		m_caster->GetUInt64Value (PLAYER__FIELD_COMBO_TARGET) != 0)
	{
		baseDamage = int32 (m_spellInfo->EffectPointsPerComboPoint[i] * m_caster->GetComboPoints());
		m_caster->SetComboPoints(0);
		m_caster->SetUInt64Value (PLAYER__FIELD_COMBO_TARGET, 0);
	} 

	uint32 randomDamage = rand()%m_spellInfo->EffectDieSides[i];
	uint32 damage = baseDamage+randomDamage;

	m_caster->SpellNonMeleeDamageLog(unitTarget, m_spellInfo->Id, damage);
}

void
Spell::Effect_ApplyAura(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	if(unitTarget->tmpAffect == 0){
		Affect* aff = new Affect (m_spellInfo, duration, m_caster->GetGUID());
		unitTarget->tmpAffect = aff;
	}

	uint32  value = 0,
			type = 0,
			damage = 0;
		
	if(m_spellInfo->EffectBasePoints[i] < 0){
		unitTarget->tmpAffect->SetNegative();
		type = 1;
	}

	uint32 sBasePoints = (uint32)fabs ( (float)m_spellInfo->EffectBasePoints[i] +
	m_caster->GetLevel() * m_spellInfo->EffectRealPointsPerLevel[i] );

	// Periodic Trigger Damage
	if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_PERIODIC_DAMAGE) {
		damage = m_spellInfo->EffectBasePoints[i]+rand()%m_spellInfo->EffectDieSides[i]+1;
		unitTarget->tmpAffect->SetDamagePerTick ((uint16)damage, m_spellInfo->EffectAmplitude[i]);
		unitTarget->tmpAffect->SetNegative();
	} else {
		// Periodic Trigger Spell
		if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_PERIODIC_TRIGGER_SPELL)
			unitTarget->tmpAffect->SetPeriodicTriggerSpell(m_spellInfo->EffectTriggerSpell[i],m_spellInfo->EffectAmplitude[i]);
		else {
			if(m_spellInfo->EffectDieSides[i] != 0)
				value = sBasePoints+rand()%m_spellInfo->EffectDieSides[i];
			else
				value = sBasePoints;
			if(m_spellInfo->EffectDieSides[i] <= 1)
				value += 1;
			unitTarget->tmpAffect->AddMod ((uint8)m_spellInfo->EffectApplyAuraName[i],
				value, m_spellInfo->EffectMiscValue[i] ,type);
		}
	}
}

void
Spell::Effect_PowerDrain(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	uint32 Drain;
	uint32 baseDrain = m_spellInfo->EffectBasePoints[i];
	uint32 randomDrain = rand()%m_spellInfo->EffectDieSides[i];
	Drain = baseDrain+randomDrain;

	uint32 TcurPower = unitTarget->GetUInt32Value(UNIT_FIELD_POWER1);
	uint32 CcurPower = m_caster->GetUInt32Value(UNIT_FIELD_POWER1);
	if(TcurPower < Drain)
		unitTarget->SetUInt32Value(UNIT_FIELD_POWER1,0);
	else
	{
		unitTarget->SetUInt32Value(UNIT_FIELD_POWER1, TcurPower-Drain);
		m_caster->SetUInt32Value  (UNIT_FIELD_POWER1, CcurPower+Drain);
	}
}

void
Spell::Effect_Heal(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;
	if(unitTarget->isPlayer()){
		if(((Player*)unitTarget)->isDueling())
		{
			SendCastResult(CAST_FAIL_TARGET_IS_DUELING);
			return;
		}
	}

	uint32 baseHealing = m_spellInfo->EffectBasePoints[i];
	uint32 randomHealing = rand()%m_spellInfo->EffectDieSides[i];
	uint32 heal = baseHealing+randomHealing;

	uint32 curHealth = unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 maxHealth = unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
	if(curHealth+heal > maxHealth)
		unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, maxHealth);
	else
		unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, curHealth+heal);
}

void
Spell::Effect_Weapon_Damage_Add_Noschool(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	uint32 baseDamage = m_spellInfo->EffectBasePoints[i];
	uint32 randomDamage = rand()%m_spellInfo->EffectDieSides[i];
	uint32 damage = baseDamage+randomDamage;
		
	m_caster->m_addDmgOnce = damage;
	m_caster->m_addDmgOnceSpell = m_spellInfo->Id;
}

void
Spell::Effect_Weapon_Dmg_Percent(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	m_caster->m_amplifyDmgOnce = float(m_spellInfo->EffectBasePoints[i]) * 0.01f;
	m_caster->m_amplifyDmgOnceSpell = m_spellInfo->Id;
}

void
Spell::Effect_Create_Item(uint32 i)
{
	// NEEDS TO BE REDONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Player* pUnit = (Player*)m_caster;
	uint8 slot = 0;
	for(uint8 i=INVENTORY_SLOT_ITEM_START; i<INVENTORY_SLOT_ITEM_END; ++i){// check if there is a free slot for the item to conjure
		if(pUnit->GetItemBySlot(i) == 0)
				slot = i;
		if(slot == 0){
			SendCastResult(CAST_FAIL_MUST_HAVE_XXXX_IN_MAINHAND); // ZeHaM: Wtf has this got to do with adding an item ?? o_O
			return;
		}

		Item* pItem;
		uint8 curSlot;
		for(uint32 i=0;i<8; ++i){
			for(uint32 j=0; j<m_spellInfo->ReagentCount[i]; ++j){
				if(j>10)// little protection to prevent loops in here
					break;
				if(m_spellInfo->Reagent[i] == 0)
					continue;
				curSlot = (uint8)pUnit->GetSlotByItemID(m_spellInfo->Reagent[i]);
				if(curSlot == 0)
					continue;
				pItem = new Item;
				pItem = pUnit->GetItemBySlot(curSlot);
				
				// if there are more then 1 in stack then just reduce it by 1
				if(pItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT) > 1){ 
					pItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT,pItem->GetUInt32Value(ITEM_FIELD_STACK_COUNT)-1);
				}else{// otherwise delete it from player and db
					pUnit->RemoveItemFromSlot(curSlot);
					pItem->DeleteFromDB();
				}
				pItem = NULL;
				curSlot = 0;
			}
		}

		pItem = NULL;
		Item* newItem;
		for(i=0; i<2; ++i){// now create the Items
			if(m_spellInfo->EffectItemType[i] == 0)
				continue;

			slot = 0;
			// check if there is a free slot for the item to conjure
			for (uint8 i = INVENTORY_SLOT_ITEM_START; i<INVENTORY_SLOT_ITEM_END; ++i){
				if(pUnit->GetItemBySlot(i) == 0)
					slot = i;
			}
			if(slot == 0){
				SendCastResult(0x18);
				return;
			}
			newItem = new Item;
			newItem->Create(objmgr.GenerateLowGuid(HIGHGUID_ITEM),m_spellInfo->EffectItemType[i],pUnit);
			pUnit->AddItemToSlot(slot,newItem);
			newItem = NULL;
		}
	}
}

void
Spell::Effect_Persistent_Area_Aura(uint32 i)
{
	if(m_AreaAura == true) return;
	m_AreaAura = true;
	// Spawn dyn GameObject
	DynamicObject* dynObj = new DynamicObject();
	dynObj->Create(objmgr.GenerateLowGuid(HIGHGUID_DYNAMICOBJECT), m_caster,
			m_spellInfo, m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,
			duration);
	uint32 damage = m_spellInfo->EffectBasePoints[i]+1;

	dynObj->PeriodicTriggerDamage (damage, m_spellInfo->EffectAmplitude[i],
			GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i])));

	objmgr.AddObject(dynObj);
	dynObj->PlaceOnMap();
	m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, dynObj->GetGUID());
	m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, m_spellInfo->Id);
}

void
Spell::Effect_Summon_Pet(uint32 i)
{
	WorldPacket data;
	if(m_caster->GetUInt64Value(UNIT_FIELD_SUMMON) != 0)//If there is already a summon
	{
		Creature *OldSummon = objmgr.GetObject<Creature>(m_caster->GetUInt64Value(UNIT_FIELD_SUMMON));
		if(!OldSummon)
		{
				m_caster->SetUInt64Value(UNIT_FIELD_SUMMON, 0);
				sLog.outError("Warning!Old Summon could not be found!");
		} else {
				data.clear();
				data.Initialize(SMSG_DESTROY_OBJECT);
				data << OldSummon->GetGUID();
				OldSummon->SendMessageToSet (&data, true);

			if (OldSummon->GetMapCell()) 
				OldSummon->GetMapCell()->RemoveObject (OldSummon);

			OldSummon->RemoveFromMap();
			OldSummon->RemoveFromWorld();
			OldSummon->DeleteFromDB();

			objmgr.RemoveObject_Free(OldSummon);
		}
	}

	//Create new summon
	Creature *NewSummon = new Creature();
	CreatureTemplate *SummonInfo = objmgr.GetCreatureTemplate(m_spellInfo->EffectMiscValue[i]);
	if(SummonInfo == NULL)
	{
		sLog.outError("No Minion found for CreatureTemplate %u", m_spellInfo->EffectMiscValue[i]);
		return;
	}
	NewSummon->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), SummonInfo->Name.c_str(), m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation());
	NewSummon->SetLevel(m_caster->GetLevel());
	NewSummon->SetUInt32Value(UNIT_FIELD_DISPLAYID, SummonInfo->Model);
	NewSummon->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, SummonInfo->Model);
	NewSummon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID());
	NewSummon->SetUInt32Value(UNIT_NPC_FLAGS , 0);
	NewSummon->SetUInt32Value(UNIT_FIELD_HEALTH , 28 + 30 * m_caster->GetLevel());
	NewSummon->SetUInt32Value(UNIT_FIELD_MAXHEALTH , 28 + 30 * m_caster->GetLevel());
	NewSummon->SetFaction(m_caster->GetFaction());
	NewSummon->SetScale( SummonInfo->Size );
	NewSummon->SetUInt32Value(UNIT_FIELD_BYTES_0,2048); 
	NewSummon->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NONE);
	NewSummon->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME, SummonInfo->Attack[0]); 
	NewSummon->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME+1, SummonInfo->Attack[1]); 
	NewSummon->SetUInt32Value(UNIT_FIELD_BOUNDINGRADIUS, SummonInfo->BoundingRadius); 
	NewSummon->SetUInt32Value(UNIT_FIELD_COMBATREACH, SummonInfo->CombatReach); 
	NewSummon->SetMinDamage((float)SummonInfo->Damage[0]); 
	NewSummon->SetMaxDamage((float)SummonInfo->Damage[1]);
	NewSummon->SetUInt32Value(UNIT_FIELD_BYTES_1,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_PETNUMBER, NewSummon->GetGUIDLow()); 
	NewSummon->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP,5); 
	NewSummon->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP,1000); 
	NewSummon->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id); 
	NewSummon->SetUInt32Value(UNIT_FIELD_STAT0,22);
	NewSummon->SetUInt32Value(UNIT_FIELD_STAT1,22); //////////TODO: GET THE RIGHT INFORMATIONS FOR THIS!!!
	NewSummon->SetUInt32Value(UNIT_FIELD_STAT2,25); 
	NewSummon->SetUInt32Value(UNIT_FIELD_STAT3,28); 
	NewSummon->SetUInt32Value(UNIT_FIELD_STAT4,27); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+0,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+1,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+2,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+3,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+4,0); 
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+5,0);
	NewSummon->SetUInt32Value(UNIT_FIELD_RESISTANCES+6,0);
	NewSummon->SetUInt32Value(UNIT_FIELD_ATTACK_POWER,24);
	NewSummon->SetUInt32Value(UNIT_FIELD_BASE_MANA, SummonInfo->MaxMana); 
	NewSummon->SetUInt32Value(OBJECT_FIELD_ENTRY, SummonInfo->Entry);
	NewSummon->SetPosition(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation());
	NewSummon->SetZoneId(m_caster->GetZoneId());

	NewSummon->SaveToDB();

	objmgr.AddObject( NewSummon );
	NewSummon->PlaceOnMap();
	NewSummon->AddToWorld();

	m_caster->SetUInt64Value(UNIT_FIELD_SUMMON, NewSummon->GetGUID());
	sLog.outDebug("New Pet has guid %u", NewSummon->GetGUID());

	if(objmgr.GetObject<Player>(m_caster->GetGUID()) )//if the caster is a player
	{
		data.clear();
		data.Initialize(SMSG_PET_SPELLS);
		data << (uint64)NewSummon->GetGUID() << uint32(0x00000101) << uint32(0x00000000) << uint32(0x07000001) << uint32(0x07000002);
		data << uint32(0x02000000) << uint32(0x07000000) << uint32(0x04000000) << uint32(0x03000000) << uint32(0x06000002) << uint32(0x05000000);
		data << uint32(0x06000000) << uint32(0x06000001) << uint8(0x02)/*Number of spells*/ << uint32(3110)/*SpellID1*/ << uint32(6307)/*SpellID2*/;
		((Player*)m_caster)->GetSession()->SendPacket(&data);
	}
}

void
Spell::Effect_Energize(uint32 i)
{
	
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;
	uint32 POWER_TYPE;

	switch(m_spellInfo->EffectMiscValue[i])
	{
	case 0: POWER_TYPE = UNIT_FIELD_POWER1; break;
	case 1: POWER_TYPE = UNIT_FIELD_POWER2; break;
	case 2: POWER_TYPE = UNIT_FIELD_POWER3; break;
	case 3: POWER_TYPE = UNIT_FIELD_POWER4; break;
	case 4: POWER_TYPE = UNIT_FIELD_POWER5; break;
	}

	uint32 energize;
	uint32 baseEnergize = m_spellInfo->EffectBasePoints[i];
	uint32 randomEnergize = rand()%m_spellInfo->EffectDieSides[i];
	energize = baseEnergize+randomEnergize;
	if(POWER_TYPE == UNIT_FIELD_POWER2)
	energize = energize*10;

	uint32 curEnergy = unitTarget->GetUInt32Value (POWER_TYPE);
	uint32 maxEnergy = unitTarget->GetUInt32Value (POWER_TYPE+6);
		
	if(curEnergy+energize > maxEnergy)
		unitTarget->SetUInt32Value (POWER_TYPE, maxEnergy);
	else
		unitTarget->SetUInt32Value (POWER_TYPE, curEnergy+energize);
}

void
Spell::Effect_Open_Lock(uint32 i)
{
	WorldPacket data;
	if(!gameObjTarget || !playerTarget) return;

	data.clear();
	data.Initialize(SMSG_LOOT_RESPONSE);
	gameObjTarget->FillLoot(&data);
//	playerTarget->SetLootGUID(m_targets.m_unitTarget);
	playerTarget->GetSession()->SendPacket(&data);
}

void
Spell::Effect_Apply_Area_Aura(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	if(m_spellInfo->Attributes == 0x09050000){   // Pally Auras
		Affect* aff = new Affect(m_spellInfo,6000,m_caster->GetGUID());
			
		aff->AddMod ((uint8)m_spellInfo->EffectApplyAuraName[i],
			m_spellInfo->EffectBasePoints[i]+rand()%m_spellInfo->EffectDieSides[i],
			m_spellInfo->EffectMiscValue[i], 0);

		unitTarget->SetAura(aff);
	}
}

void
Spell::Effect_Learn_Spell(uint32 i)
{
	if(!playerTarget) return;
	WorldPacket data;
	uint32 spellToLearn = m_spellInfo->EffectTriggerSpell[i];

	/*  Crashes needs to be fixed
	std::list<spells>::iterator iter;
	for(iter = playerTarget->getSpellList().begin();iter != playerTarget->getSpellList().end();++iter){
		if((*iter).spellId == spellToLearn)
			break;
	}
	if(iter != playerTarget->getSpellList().end())
	return;
	*/

	// Learn animation
	if(playerTarget->AddSpell(spellToLearn))
	{
		data.Initialize (SMSG_LEARNED_SPELL);
		data << (uint32)spellToLearn;
		playerTarget->GetSession()->SendPacket( &data );

		Make_SMSG_SPELL_GO (&data, 476, m_caster, playerTarget);
		m_caster->SendMessageToSet (&data, true);
	}
}

void
Spell::Effect_Summon_Wild(uint32 i)
{
	if(!playerTarget) return;

	CreatureTemplate *ct;
	ct = objmgr.GetCreatureTemplate(m_spellInfo->EffectMiscValue[i]);

	if(!ct){
		printf("unknown entry ID. return\n");
		return;
	}
	
	uint32 level = m_caster->GetLevel();
	Creature* spawnCreature = new Creature();
	spawnCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT),ct->Name.c_str(),m_caster->GetMapId(),m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),m_caster->GetOrientation());
	spawnCreature->SetUInt32Value(UNIT_FIELD_DISPLAYID, ct->Model);
	spawnCreature->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ct->Model);
	spawnCreature->SetUInt32Value(UNIT_NPC_FLAGS , 0);
	spawnCreature->SetUInt32Value(UNIT_FIELD_HEALTH, 28 + 30*level);
	spawnCreature->SetUInt32Value(UNIT_FIELD_MAXHEALTH, 28 + 30*level);
	spawnCreature->SetUInt32Value(UNIT_FIELD_LEVEL , level);
	spawnCreature->SetUInt32Value(OBJECT_FIELD_TYPE, ct->Type);
	
	objmgr.AddObject(spawnCreature);
	spawnCreature->PlaceOnMap();
}

void
Spell::Effect_Enchant_Item_Permanent(uint32 i)
{
	Player* p_caster = (Player*)m_caster;
	uint32 field = 99;
	if(m_CastItem)
		field = 1;
	else
		field = 3;
	if(!m_CastItem){
		for(uint8 i=0; i<INVENTORY_SLOT_ITEM_END; ++i){
			if(p_caster->GetItemBySlot(i) != 0)
				if(p_caster->GetItemBySlot(i)->GetEntry() == m_targets.m_itemTarget->GetEntry())
					m_CastItem = p_caster->GetItemBySlot(i);
		}
	}
	//m_CastItem->Enchant(m_spellInfo->EffectMiscValue[i],0);
}

void
Spell::Effect_Enchant_Item_Temporary(uint32 i)
{
	Player* p_caster = (Player*)m_caster;
	//uint32 duration = GetDuration(sSpellDuration.LookupEntry(m_spellInfo->DurationIndex));
	uint32 field = 99;
	if(m_CastItem)
		field = 1;
	else
		field = 3;
	if(!m_CastItem){
		for(uint8 i=0; i<INVENTORY_SLOT_ITEM_END; ++i){
			if(p_caster->GetItemBySlot(i) != 0)
				if(p_caster->GetItemBySlot(i)->GetEntry() == m_targets.m_itemTarget->GetEntry())
					m_CastItem = p_caster->GetItemBySlot(i);
		}
	}
	//m_CastItem->Enchant(m_spellInfo->EffectMiscValue[i],duration,field);
}

void
Spell::Effect_Weapon_Damage_Add(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;

	uint32 baseDamage = m_spellInfo->EffectBasePoints[i];
	uint32 randomDamage = rand() % m_spellInfo->EffectDieSides[i];
	uint32 damage = baseDamage + randomDamage;
	unitTarget->m_addDmgOnce = damage;
}

void
Spell::Effect_Trigger_Spell(uint32 i)
{
	TriggerSpellId = m_spellInfo->EffectTriggerSpell[i];
}

void
Spell::Effect_Heal_Max_Health(uint32 i)
{
	if(!unitTarget) return;
	if(!unitTarget->isAlive()) return;
	if(playerTarget){
        if(playerTarget->isDueling())
		{
			SendCastResult(CAST_FAIL_TARGET_IS_DUELING);
			return;
		}
	}

	uint32 heal;
	heal = m_caster->GetUInt32Value(UNIT_FIELD_MAXHEALTH);

	uint32 curHealth = unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 maxHealth = unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
	if(curHealth+heal > maxHealth)
		unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH,maxHealth);
	else
		unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH,curHealth+heal);
}

void
Spell::Effect_Interrupt_Cast(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive()) return;
	unitTarget->InterruptSpell();
}

void
Spell::Effect_Add_Combo_Points(uint32 i)
{
	if(!unitTarget) return;
	uint8 comboPoints = m_caster->GetComboPoints(); //((m_caster->GetUInt32Value(PLAYER_FIELD_BYTES) & 0xFF00) >> 8);
	if(m_caster->GetUInt64Value(PLAYER__FIELD_COMBO_TARGET) != unitTarget->GetGUID()){
		m_caster->SetUInt64Value(PLAYER__FIELD_COMBO_TARGET,unitTarget->GetGUID());
		//m_caster->SetUInt32Value(PLAYER_FIELD_BYTES,((m_caster->GetUInt32Value(PLAYER_FIELD_BYTES) & ~(0xFF << 8)) | (0x01 << 8)));
		m_caster->SetComboPoints (1);
	} else {
		if(comboPoints < 5){
			comboPoints += 1;
			//m_caster->SetUInt32Value(PLAYER_FIELD_BYTES,((m_caster->GetUInt32Value(PLAYER_FIELD_BYTES) & ~(0xFF << 8)) | (comboPoints << 8)));
			m_caster->SetComboPoints (comboPoints);
		}
	}
}

void
Spell::Effect_Summon_Totem(uint32 i)
{
	WorldPacket data;
	uint64 guid = 0;
	// delete old summoned totem
	if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT1){
		guid = m_caster->m_TotemSlot1;
		m_caster->m_TotemSlot1 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT2){
		guid = m_caster->m_TotemSlot2;
		m_caster->m_TotemSlot2 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT3){
		guid = m_caster->m_TotemSlot3;
		m_caster->m_TotemSlot3 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT4){
		guid = m_caster->m_TotemSlot4;
		m_caster->m_TotemSlot4 = 0;
	}

	if(guid != 0)
	{
		Creature* Totem;
		Totem = objmgr.GetObject<Creature>(guid);
		if(Totem){
			Totem->RemoveFromMap();
			objmgr.RemoveObject_Free(Totem);	// Check if here bug with that _Free or not ?
		}
	}

	// spawn a new one
	Creature* pTotem = new Creature();
		
	// need to set it via m_spellInfo
	uint16 display_id = (uint16)m_spellInfo->EffectMiscValue[i];
	char* name = "need to fix this";

	// uint32 guidlow, uint16 display_id, uint8 state, uint32 obj_field_entry, uint8 scale, uint16 type, uint16 faction,  float x, float y, float z, float ang
	pTotem->Create(objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), name, m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation() );
	pTotem->SetUInt32Value(OBJECT_FIELD_TYPE,33);
	pTotem->SetLevel (m_caster->GetLevel());
	objmgr.AddObject(pTotem);
	pTotem->PlaceOnMap();

	data.Initialize(SMSG_GAMEOBJECT_SPAWN_ANIM);
	data << pTotem->GetGUID();
	m_caster->SendMessageToSet(&data,true);

	if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT1)
		m_caster->m_TotemSlot1 = pTotem->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT2)
		m_caster->m_TotemSlot2 = pTotem->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT3)
		m_caster->m_TotemSlot3 = pTotem->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_TOTEM_SLOT4)
		m_caster->m_TotemSlot4 = pTotem->GetGUID();
}

void
Spell::Effect_Enchant_Held_Item(uint32 i)
{

}

void
Spell::Effect_Summon_Object(uint32 i)
{
	WorldPacket data;
	uint64 guid = 0;
	// delete old summoned object
	if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT1){
		guid = m_caster->m_TotemSlot1;
		m_caster->m_TotemSlot1 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT2){
		guid = m_caster->m_TotemSlot2;
		m_caster->m_TotemSlot2 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT3){
		guid = m_caster->m_TotemSlot3;
		m_caster->m_TotemSlot3 = 0;
	} else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT4){
		guid = m_caster->m_TotemSlot4;
		m_caster->m_TotemSlot4 = 0;
	}

	if(guid != 0)
	{
		GameObject* obj;
		obj = objmgr.GetObject<GameObject>(guid);
		if(obj){
			obj->RemoveFromMap();
			objmgr.RemoveObject_Free(obj);	// check for possible bug with _Free()
		}
	}

	// spawn a new one
	GameObject* pGameObj = new GameObject();
	uint16 display_id = (uint16)m_spellInfo->EffectMiscValue[i];

	// uint32 guidlow, uint16 display_id, uint8 state, uint32 obj_field_entry, uint8 scale, uint16 type, uint16 faction,  float x, float y, float z, float ang
	pGameObj->Create(objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), display_id, 1, m_spellInfo->EffectMiscValue[i], 1, 6, 6, m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation() );
	pGameObj->SetUInt32Value(OBJECT_FIELD_TYPE,33);
	pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL,m_caster->GetLevel());
	objmgr.AddObject(pGameObj);
	pGameObj->PlaceOnMap();

	data.Initialize(SMSG_GAMEOBJECT_SPAWN_ANIM);
	data << pGameObj->GetGUID();
	m_caster->SendMessageToSet(&data,true);

	if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT1)
		m_caster->m_TotemSlot1 = pGameObj->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT2)
		m_caster->m_TotemSlot2 = pGameObj->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT3)
		m_caster->m_TotemSlot3 = pGameObj->GetGUID();
	else if(m_spellInfo->Effect[i] == EFFECT_SUMMON_OBJECT_SLOT4)
		m_caster->m_TotemSlot4 = pGameObj->GetGUID();
}

void
Spell::Effect_Resurrect_Flat(uint32 i)
{
	if(!playerTarget) return;
	if(playerTarget->isAlive()) return;
	if(!playerTarget->IsInWorld()) return;
	
	uint32 health = m_spellInfo->EffectBasePoints[i];
	uint32 mana = m_spellInfo->EffectMiscValue[i];
	playerTarget->setResurrect(m_caster->GetGUID(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), health, mana);
	SendResurrectRequest(playerTarget);
}

void
Spell::Effect_Instakill(uint32 i)
{
	if(!unitTarget) return;
	unitTarget->UnitDeath(m_caster, false);
}

void
Spell::Effect_Leap(uint32 i)
{
	
    if( m_spellInfo->rangeIndex == 1)  //self range
    {
        float fx,fy;
		WorldPacket data;

        float dis = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
        fx = m_caster->GetPositionX() + dis * cos(m_caster->GetOrientation());
        fy = m_caster->GetPositionY() + dis * sin(m_caster->GetOrientation());

        data.Initialize(MSG_MOVE_TELEPORT_ACK);
        data << m_caster->GetGUID();
        data <<uint32(0x800000); 
        data << uint16(0x67EE);
        data << uint16(0xD1EB);
        data << fx;
        data << fy;
        data << m_caster->GetPositionZ()+10; //TODO:Use client Height map fix Z position
        data << m_caster->GetOrientation();
        data << uint32(0x0);
        m_caster->SendMessageToSet( &data, true );
    }
}

void
Spell::Effect_Resurrect(uint32 i)
{
	if(!playerTarget) return;
	if(playerTarget->isAlive()) return;
	if(!playerTarget->IsInWorld()) return;

	uint32 health = m_spellInfo->EffectBasePoints[i];
	uint32 mana = m_spellInfo->EffectMiscValue[i];
	playerTarget->setResurrect(m_caster->GetGUID(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), health, mana);
	SendResurrectRequest(playerTarget);
}

void
Spell::Effect_Script_Effect(uint32 i)
{
	uint32 spellId = m_spellInfo->Id;
	switch(spellId)
	{
	case 5699:	playerTarget->AddItemToSlot(playerTarget->FindFreeItemSlot(INVTYPE_SLOT_ITEM), 5509); break;
	case 6201:  playerTarget->AddItemToSlot(playerTarget->FindFreeItemSlot(INVTYPE_SLOT_ITEM), 5512); break;
	case 6202:  playerTarget->AddItemToSlot(playerTarget->FindFreeItemSlot(INVTYPE_SLOT_ITEM), 5511); break;
	case 11729:  playerTarget->AddItemToSlot(playerTarget->FindFreeItemSlot(INVTYPE_SLOT_ITEM), 5510); break;
	case 11730:  playerTarget->AddItemToSlot(playerTarget->FindFreeItemSlot(INVTYPE_SLOT_ITEM), 9421); break;
	/*case 5143:	break;
	case 5144:	break;
	case 5145:	break;
	case 8416:	break;
	case 8417:	break;
	case 10211:	break;
	case 10212:	break;
	case 17512:	break;
	case 19750:	break;
	case 19940:	break;
	case 19941:	break;
	case 19942:	break;
	case 19943:	break;
	case 20231:	break;
	case 20417:	break;
	case 20418:	break;
	case 21543:	break;*/
	default:
		sLog.outDebug("SpellEffects|Script_Effect|No scripted spelleffect for spellId=%d", spellId);
		break;
	}
}

void
Spell::Effect_Transmitted(uint32 i)
{
    float fx,fy;
	WorldPacket data;

    float dis = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
    fx = m_caster->GetPositionX() + dis * cos(m_caster->GetOrientation());
    fy = m_caster->GetPositionY() + dis * sin(m_caster->GetOrientation());

	GameObject* pGameObj = new GameObject();
	uint32 name_id = m_spellInfo->EffectMiscValue[i];
	
	pGameObj->Create(
		objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT),
		name_id,m_caster->GetMapId(), 
		fx, fy, m_caster->GetPositionZ(), 
		m_caster->GetOrientation(), 0, 0, 0, 0);

		
	pGameObj->SetUInt32Value(OBJECT_FIELD_ENTRY, m_spellInfo->EffectMiscValue[i] );
	pGameObj->SetUInt32Value(OBJECT_FIELD_TYPE, 33 );
	pGameObj->SetUInt32Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUIDLow() );
	pGameObj->SetUInt32Value(GAMEOBJECT_ROTATION+1, 0x3F63BB3C );  
	pGameObj->SetUInt32Value(GAMEOBJECT_ROTATION+2, 0xBEE9E017 );
	pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL, m_caster->GetLevel() );

	pGameObj->PlaceOnMap();
	pGameObj->AddToWorld();

    data.Initialize(SMSG_GAMEOBJECT_SPAWN_ANIM);
    data << (uint64)pGameObj->GetGUID();
    m_caster->SendMessageToSet(&data,true);
}

void
Spell::Effect_OpenLockItem(uint32 i)
{
	WorldPacket data;

	if(!gameObjTarget || !m_caster)
	{
		if(!gameObjTarget)
			sLog.outDebug( "WORLD: Open Secret Safe - No GameObject Target!"); 
		if(!m_caster)
			sLog.outDebug( "WORLD: Open Secret Safe - No Player Caster!"); 
		return;
	}

	data.Initialize(SMSG_LOOT_RESPONSE);
	gameObjTarget->FillLoot(&data);
	((Player*)m_caster)->SetLootGUID(m_targets.m_unitTarget->GetGUID());
	((Player*)m_caster)->GetSession()->SendPacket(&data);
}

void
Spell::Effect_Language(uint32 i)
{
	uint32 langId = m_spellInfo->EffectMiscValue[i];
	/* TODO:
		Set player's language to langId for some time */
}