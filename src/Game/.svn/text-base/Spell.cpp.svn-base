/* 
 * Copyright (C) 2006 CrFusion
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
#include "../Shared/PacketBuilder.h"
#include "../Spells/Spells.h"
#include "Tools.h"

#define SPELL_CHANNEL_UPDATE_INTERVAL 1000

extern SpEffect EffectHandlers[TOTAL_SPELL_EFFECTS];

SpellCastTargets::SpellCastTargets()
{
	m_unitTarget = NULL;
    m_itemTarget = NULL;
    m_GOTarget	 = NULL;
    m_srcX = m_srcY = m_srcZ = m_destX = m_destY = m_destZ = 0;
    m_strTarget = "";
}

SpellCastTargets::~SpellCastTargets()
{}

void
SpellCastTargets::read ( WorldPacket* data, Unit* caster )
{
	*data >> m_targetMask;

	if(m_targetMask & TARGET_FLAG_SELF)
		m_unitTarget = caster;

	if(m_targetMask & TARGET_FLAG_UNIT)
		m_unitTarget = objmgr.GetUnit(caster, readGUID(data));
	
	if(m_targetMask & TARGET_FLAG_OBJECT)
		m_GOTarget = objmgr.GetObject<GameObject>(readGUID(data));

	if(m_targetMask & TARGET_FLAG_ITEM)
		m_itemTarget = ((Player*)caster)->GetItemByGUID(readGUID(data));

	if(m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
		*data >> m_srcX >> m_srcY >> m_srcZ;

	if(m_targetMask & TARGET_FLAG_DEST_LOCATION)
		*data >> m_destX >> m_destY >> m_destZ;

	if(m_targetMask & TARGET_FLAG_STRING)
		*data >> m_strTarget;
}

void
SpellCastTargets::write ( WorldPacket * data)
{
	*data << m_targetMask;

	if(m_targetMask & TARGET_FLAG_SELF)
        *data << (m_unitTarget ? m_unitTarget->GetGUID(): (uint64)0);

    if(m_targetMask & TARGET_FLAG_UNIT)
        *data << (m_unitTarget ? m_unitTarget->GetGUID(): (uint64)0);

    if(m_targetMask & TARGET_FLAG_OBJECT)
        *data << (m_GOTarget ? m_GOTarget->GetGUID(): (uint64)0);

    if(m_targetMask & TARGET_FLAG_ITEM)
        *data << (m_itemTarget ? m_itemTarget->GetGUID(): (uint64)0);

	if(m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
		*data << m_srcX << m_srcY << m_srcZ;

	if(m_targetMask & TARGET_FLAG_DEST_LOCATION)
		*data << m_destX << m_destY << m_destZ;

	if(m_targetMask & TARGET_FLAG_STRING)
		*data << m_strTarget;
}

Spell::Spell( Unit* Caster, SpellEntry *info, bool triggered, Affect* aff )
{
	ASSERT( Caster != NULL && info != NULL );

    int32 temptime;
	m_spellInfo = info;
	m_caster = Caster;
	m_spellState = SPELL_STATE_NULL;

	m_castPositionX = m_castPositionY = m_castPositionZ;
	TriggerSpellId = 0;
	m_targetCount = 0;
	m_triggeredSpell = triggered;
	m_AreaAura = false;
	m_currdynObjID = 0;
	m_CastItem = NULL;
	m_triggeredByAffect = aff;

	SpellMap::iterator itr;
	SpellEntry* spellInfo;
    Player* pCaster;

    temptime = GetCastTime(sCastTime.LookupEntry(m_spellInfo->CastingTimeIndex)); 

    if( Caster->GetTypeId() == TYPEID_PLAYER && m_spellInfo )
    {
        pCaster = (Player*)m_caster;
		for (itr = pCaster->spellBegin(); itr != pCaster->spellEnd(); ++itr)
		{
			if (itr->first != m_spellInfo->Id)
			{    
				spellInfo = sSpellStore.LookupEntry(itr->first);
				if(spellInfo && spellInfo->SpellIconID == m_spellInfo->SpellIconID && spellInfo->EffectMiscValue[0] ==10)
				{
                     temptime += (spellInfo->EffectBasePoints[0]+1);
				}
			}
		}    
	}
    
	m_timer = temptime<0?0:temptime;
}

void
Spell::FillTargetMap()
{
	std::list<Unit*> tmpUnitMap;
	std::list<Item*> tmpItemMap;
	std::list<GameObject*> tmpGOMap;

	for(uint32 i=0; i<3; ++i)
	{ 
		SetTargetMap(i,m_spellInfo->EffectImplicitTargetA[i],tmpUnitMap,tmpItemMap,tmpGOMap);
		SetTargetMap(i,m_spellInfo->EffectImplicitTargetB[i],tmpUnitMap,tmpItemMap,tmpGOMap);
       
		m_targetUnits[i] = tmpUnitMap;
		m_targetItems[i] = tmpItemMap;
		m_targetGOs[i]   = tmpGOMap;
		
		tmpUnitMap.clear();
		tmpItemMap.clear();
		tmpGOMap.clear();
	}
}

void
Spell::SetTargetMap(uint32 i,uint32 cur,std::list<Unit*> &TagUnitMap,std::list<Item*> &TagItemMap,std::list<GameObject*> &TagGOMap)
{
  switch(cur)
  {
	 case EFF_TARGET_SELF:
     {
     	TagUnitMap.push_back(m_caster);
     }break;
     case EFF_TARGET_PET:   
     {
		Unit* tmpUnit = objmgr.GetObject<Creature>(m_caster->GetUInt32Value(UNIT_FIELD_PETNUMBER));
        TagUnitMap.push_back(tmpUnit);
     }break;
     case EFF_TARGET_SINGLE_ENEMY:   
     {
           TagUnitMap.push_back(m_targets.m_unitTarget);
     }break;
     case EFF_TARGET_ALL_ENEMY_IN_AREA: // TEMP FIX :)
     case EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT:           
     {
		Object *cObj = NULL;
		for (MapRangeIterator itr (m_caster); cObj = itr.Advance(); )
		{
			if (cObj->isNotUnit() && cObj->isNotPlayer()) 
				continue;
			if (((Unit*)cObj)->isDead())
				continue;

			float rad = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
			if (
				_SquareDistance (m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,
				cObj->GetPositionX(), cObj->GetPositionY(), cObj->GetPositionZ())< rad*rad
				&& ((Unit *)cObj)->isHostileToMe(m_caster)
			   )
			{
				TagUnitMap.push_back (((Unit*)cObj));
			}
		}
     }break;
     case EFF_TARGET_ALL_PARTY_AROUND_CASTER:  
     {
	      Group* pGroup = objmgr.GetGroupByLeader(playerCaster->GetGroupLeader());
	      if(pGroup)
	        for(uint32 p=0; p < pGroup->GetMembersCount(); ++p)
	        {
				Unit* Target = objmgr.GetObject<Player>(pGroup->GetMemberGUID(p));
				if(!Target || Target->GetGUID() == m_caster->GetGUID())
	               continue;
				if(_CalcDistance(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),Target->GetPositionX(),Target->GetPositionY(),Target->GetPositionZ()) < GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i])))
					if(!Target->isDead())
						TagUnitMap.push_back(Target);
	        }
	      else
	        TagUnitMap.push_back(m_caster);
     }break;
     case EFF_TARGET_SINGLE_FRIEND:  
	 case EFF_TARGET_SINGLE_FRIEND_2:
     {
        TagUnitMap.push_back(m_targets.m_unitTarget);
     }break;
     case EFF_TARGET_ALL_ENEMIES_AROUND_CASTER: 
     {
		Object *cObj = NULL;
		for (MapRangeIterator itr (m_caster); cObj = itr.Advance(); )
		{
			if (cObj->isNotUnit() && cObj->isNotPlayer()) 
				continue;
			if (((Unit*)cObj)->isDead())
				continue;

			float rad = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
			if (
				_SquareDistance (m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,
				cObj->GetPositionX(), cObj->GetPositionY(), cObj->GetPositionZ())< rad*rad
				&& ((Unit *)cObj)->isHostileToMe(m_caster)
			   )
			{
				TagUnitMap.push_back (((Unit*)cObj));
			}
		}
     }break;
     case EFF_TARGET_GAMEOBJECT: 
     {
        TagGOMap.push_back(m_targets.m_GOTarget);
     }break;
     case EFF_TARGET_IN_FRONT_OF_CASTER: 
     {
		Object *cObj;
		for (MapRangeIterator itr (m_caster); cObj = itr.Advance(); )
		{
			if (cObj->isNotUnit() && cObj->isNotPlayer())
				continue;
			if (((Unit*)cObj)->isDead())
				continue;

			if (((Unit *)cObj)->isHostileToMe(m_caster) &&
				m_caster->isInFront ((Unit *)cObj,
				GetRadius (sSpellRadius.LookupEntry (m_spellInfo->EffectRadiusIndex[i])))
				)
			{
				TagUnitMap.push_back (((Unit*)cObj));
			}
		}
     }break;
     case EFF_TARGET_DUEL: 
     {
         TagUnitMap.push_back(m_targets.m_unitTarget);
     }break;
     case EFF_TARGET_GAMEOBJECT_ITEM: 
     {
		 if(m_targets.m_GOTarget)
			 TagGOMap.push_back(m_targets.m_GOTarget);
         if(m_targets.m_unitTarget)
            TagUnitMap.push_back(m_targets.m_unitTarget);
         if(m_targets.m_itemTarget)
            TagItemMap.push_back(m_targets.m_itemTarget);
     }break;
     case EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED: // (Blizzard/Rain of Fire/volley)
     {
		Object *cObj = NULL;
		for (MapRangeIterator itr (m_caster); cObj = itr.Advance(); )
		{
			if (cObj->isNotUnit() && cObj->isNotPlayer()) 
				continue;
			if (((Unit*)cObj)->isDead())
				continue;

			float rad = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
			if (
				_SquareDistance (m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,
				cObj->GetPositionX(), cObj->GetPositionY(), cObj->GetPositionZ())< rad*rad
				&& ((Unit *)cObj)->isHostileToMe(m_caster)
			   )
			{
				TagUnitMap.push_back (((Unit*)cObj));
			}
		}
     }break;
     case EFF_TARGET_MINION: 
     {
		Unit* tmpUnit = objmgr.GetObject<Creature>(m_caster->GetUInt64Value(UNIT_FIELD_SUMMON));
		if(tmpUnit)
			TagUnitMap.push_back(tmpUnit);
     }break;
     case EFF_TARGET_SINGLE_PARTY: 
     {
		 Player* cPlr = ((Player*)m_targets.m_unitTarget);
		 if(cPlr->IsInGroup() && cPlr->GetGroupLeader() == playerCaster->GetGroupLeader())
			TagUnitMap.push_back(m_targets.m_unitTarget);
     }break;
     case EFF_TARGET_CHAIN: 
     {
		if(!m_targets.m_unitTarget) 
			break;
         
		Group* pGroup = objmgr.GetGroupByLeader(((Player*)m_caster)->GetGroupLeader());
		for(uint32 p=0; p<pGroup->GetMembersCount(); ++p)
		{
            if(m_targets.m_unitTarget->GetGUID() == pGroup->GetMemberGUID(p))
                break;
		}
		for(uint32 p=0; p<pGroup->GetMembersCount(); ++p)
		{
			Unit* Target = objmgr.GetObject<Player>(pGroup->GetMemberGUID(p));

			if(!Target || Target->GetGUID() == m_caster->GetGUID())
				continue;
			if(_CalcDistance(Target->GetPositionX(),Target->GetPositionY(),Target->GetPositionZ(),m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ()) < GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i])) && Target->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE) == m_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE))
				TagUnitMap.push_back(Target);
		}
     }break;
     case EFF_TARGET_CURRENT_SELECTION:          
     {
		Object *cObj = NULL;
		for (MapRangeIterator itr (m_targets.m_unitTarget); cObj = itr.Advance(); )
		{
			if (cObj->isNotUnit() && cObj->isNotPlayer()) 
				continue;
			if (((Unit*)cObj)->isDead())
				continue;

			float rad = GetRadius(sSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
			if (
				_SquareDistance (m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,
				cObj->GetPositionX(), cObj->GetPositionY(), cObj->GetPositionZ())< rad*rad
				&& ((Unit *)cObj)->isHostileToMe(m_caster)
			   )
			{
				TagUnitMap.push_back (((Unit*)cObj));
			}
		}
     }break;
     default:
     {
     }break;
  }             
}

void
Spell::writeSpellGoTargets( WorldPacket * data )
{
   bool add = true;
   
   std::list<Unit*>::iterator i,j;
   std::list<GameObject*>::iterator m,n;

   for(int k=0; k<3; ++k)
   {
	   for ( i = m_targetUnits[k].begin(); i != m_targetUnits[k].end(); ++i )
	   {
	      for(j = UniqueTargets.begin(); j != UniqueTargets.end(); ++j )
	      {
	         if((*j) == (*i))
	         { 
	         	add = false;
	         	break;
	         }
	      }
	      if(*i && add)
	        UniqueTargets.push_back(*i);
	      add = true;
	   }
		 for ( m = m_targetGOs[k].begin(); m != m_targetGOs[k].end(); ++m )
	   {
	      for(n = UniqueGOsTargets.begin(); n != UniqueGOsTargets.end(); ++n )
	      {
	         if((*n) == (*m))
	         {
	          add = false;
	         	break;
	         }
	      }
	      if(*m && add)
	        UniqueGOsTargets.push_back(*m);
	      add = true;
	   }  
	 }

   m_targetCount = UniqueTargets.size() + UniqueGOsTargets.size();
   *data << m_targetCount;

   for ( std::list<Unit*>::iterator ui = UniqueTargets.begin(); ui != UniqueTargets.end(); ++ui )
			*data << (*ui)->GetGUID();
   
   for ( std::list<GameObject*>::iterator uj = UniqueGOsTargets.begin(); uj != UniqueGOsTargets.end(); ++uj )
			*data << (*uj)->GetGUID();
}

void
Spell::prepare(SpellCastTargets * targets)
{
	uint32 uCastTime = 0;
	for(uint32 i = 0; i < sCastTime.GetNumRows(); ++i)
	{
		if(sCastTime.LookupEntry(i)->ID == m_spellInfo->CastingTimeIndex)
		{
			uCastTime = sCastTime.LookupEntry(i)->CastTime;
			break;
		}
	}

	uint8 result = 0;

	WorldPacket data;

	m_targets = *targets;

	SendSpellStart();

	m_timer = uCastTime;

	m_spellState = SPELL_STATE_PREPARING;

	m_castPositionX = m_caster->GetPositionX();
	m_castPositionY = m_caster->GetPositionY();
	m_castPositionZ = m_caster->GetPositionZ();

	result = CanCast();
	if (result == 0)
		result = (uint8)Call_Spell_CanCast (m_spellInfo->Id, m_caster, m_caster);

	if (result != 0)
	{
		if(m_triggeredByAffect){
			SendChannelUpdate(0);
			m_triggeredByAffect->SetDuration(0);
		}
		finish();
	}

	if(m_triggeredSpell)
		cast();
	else
		m_caster->castSpell( this );
}


void
Spell::cancel()
{
	WorldPacket data;

	if(m_spellState == SPELL_STATE_PREPARING)
	{
		SendInterrupted(0);
		SendCastResult(CAST_FAIL_INTERRUPTED);
	}
	else if(m_spellState = SPELL_STATE_CASTING)
	{
		m_caster->RemoveAffectById(m_spellInfo->Id);
		SendChannelUpdate(0);
	}

	finish();
	m_spellState = SPELL_STATE_FINISHED;
}


void
Spell::cast()
{
	WorldPacket data;

	bool meleeSpell = false;

	// Quite strange way to detect instant spells indeed :) Should redo this crap. /kvak
	for(uint32 i=0; i<=2; ++i){
		if(	m_spellInfo->Effect[i] == EFFECT_WEAPON_DAMAGE_ADD_NOSCHOOL ||
			m_spellInfo->Effect[i] == EFFECT_WEAPON_DAMAGE_ADD)
				meleeSpell = true;
	}

	if (!meleeSpell)
	{
		uint8 castResult = CanCast();
		if (castResult == 0)
		{
			TakePower();
			//RemoveItems();
			FillTargetMap();
			SendCastResult(castResult);
			SendSpellGo();
			SendLogExecute();

			if(m_spellInfo->ChannelInterruptFlags != 0){
				m_spellState = SPELL_STATE_CASTING;
				SendChannelStart(GetDuration(sSpellDuration.LookupEntry(m_spellInfo->DurationIndex)));
			}

			std::list<Unit*>::iterator iunit;
			std::list<Item*>::iterator iitem;
			std::list<GameObject*>::iterator igo;
		
			for(uint32 j=0; j<3; ++j)
			{
				if(m_spellInfo->Effect[j] == EFFECT_PERSISTENT_AREA_AURA)
					HandleEffects(m_caster,NULL,NULL,j);
					
				for(iunit= m_targetUnits[j].begin();iunit != m_targetUnits[j].end(); ++iunit)
					HandleEffects((*iunit),NULL,NULL,j);
				for(iitem= m_targetItems[j].begin();iitem != m_targetItems[j].end(); ++iitem)
					HandleEffects(NULL,(*iitem),NULL,j);
				for(igo= m_targetGOs[j].begin();igo != m_targetGOs[j].end(); ++igo)
					HandleEffects(NULL,NULL,(*igo),j);
			}

			for(iunit= UniqueTargets.begin();iunit != UniqueTargets.end(); ++iunit)
				HandleAddAffect((*iunit));
		}

		if(m_spellState != SPELL_STATE_CASTING)
			finish();

		if(castResult == 0)
			TriggerSpell();
	} else {
		m_caster->m_meleeSpell = true;
		m_spellState = SPELL_STATE_IDLE;
	}
}


void
Spell::update(uint32 difftime)
{
	if((m_castPositionX != m_caster->GetPositionX() ||
		m_castPositionY != m_caster->GetPositionY() ||
		m_castPositionZ != m_caster->GetPositionZ() ) &&
		(m_timer != 0))
	{
		SendInterrupted(0);
		SendCastResult(CAST_FAIL_INTERRUPTED);
		if(m_spellState == SPELL_STATE_CASTING){
			m_caster->RemoveAffectById(m_spellInfo->Id);
			SendChannelUpdate(0);
			for(int i = 0; i < 3; ++i)
			{
				if(m_spellInfo->Effect[i] == EFFECT_PERSISTENT_AREA_AURA)
				{
					if(m_spellInfo->Id == m_caster->GetUInt32Value(UNIT_CHANNEL_SPELL))
					{
						DynamicObject* dynObj = objmgr.GetObject<DynamicObject>(m_caster->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT));
						if(dynObj)
						{
							dynObj->RemoveFromMap();
							objmgr.RemoveObject_Free(dynObj);
						}
						else
						{
							sLog.outDebug("Dynamic Spellobject could not be found!");
						}
					}
				}
			}
		}
		finish();
		m_spellState = SPELL_STATE_FINISHED;
	}
	switch(m_spellState)
	{
	case SPELL_STATE_PREPARING:
	{
		if(m_timer)
		{
			if(difftime >= m_timer)
				m_timer = 0;
			else
				m_timer -= difftime;
		}
		if(m_timer == 0)
			cast();
	} break;
	case SPELL_STATE_CASTING:
	{
		if(m_timer > 0)
		{
			if(difftime >= m_timer)
				m_timer = 0;
			else
				m_timer -= difftime;

			m_intervalTimer += difftime;
		}
		if(m_timer == 0)
		{
			SendChannelUpdate(0);
			finish();
		}
	} break;
	default:
	{ } break;
	}
}


void
Spell::finish()
{
	WorldPacket data;

	m_spellState = SPELL_STATE_FINISHED;
	m_caster->m_meleeSpell = false;
	//m_caster->m_canMove = true;
	if(m_currdynObjID!=0)
	{
		DynamicObject* obj = NULL;

		if( m_caster )
			obj = objmgr.GetObject<DynamicObject>(m_currdynObjID);
		if(obj)
		{
			data.Initialize(SMSG_GAMEOBJECT_DESPAWN_ANIM);
			data << obj->GetGUID();
			m_caster->SendMessageToSet(&data, true);	

			data.Initialize(SMSG_DESTROY_OBJECT);
			data << obj->GetGUID();
			m_caster->SendMessageToSet(&data, true);	

			obj->RemoveFromWorld();
			obj->RemoveFromMap();
			delete obj;
		}
		m_currdynObjID = 0;
	}
	//((Player*)m_caster)->setRegenTimer(5000);
}


void
Spell::SendCastResult(uint8 result)
{
	if (m_caster->isNotPlayer())
		return;

	WorldPacket data;

	data.Initialize(SMSG_CAST_RESULT);
	data << m_spellInfo->Id;
	if(result != 0)
		data << uint8(2);
	data << result;
	((Player*)m_caster)->GetSession()->SendPacket(&data);
}


void
Spell::SendSpellStart()
{
	WorldPacket data;
	uint16 cast_flags;

	cast_flags = 2;

	data.Initialize(SMSG_SPELL_START);
	data << m_caster->GetGUID() << m_caster->GetGUID();
	data << m_spellInfo->Id;
	data << cast_flags;
	data << uint32(m_timer);

	m_targets.write( &data );
	((Player*)m_caster)->SendMessageToSet(&data, true);
}


void
Spell::SendSpellGo()
{
	// Start Spell
	WorldPacket data;
	uint16 flags;

	// FIXME: not sure about that, check disasm
	flags = m_targets.m_targetMask;
	if(flags == 0)
		flags = 2;

	data.Initialize(SMSG_SPELL_GO);
	data << m_caster->GetGUID() << m_caster->GetGUID();
	data << m_spellInfo->Id;
	data << flags;
	//data << uint16(0x0500);
	writeSpellGoTargets(&data);

	data << (uint8)0;  // number of misses
	m_targets.write( &data );
	m_caster->SendMessageToSet(&data, true);
}

void
Spell::SendLogExecute()
{
	WorldPacket data;
	data.Initialize(SMSG_SPELLLOGEXECUTE);
	/* For 1.9.x
	if(m_caster->GetTypeId() == TYPEID_PLAYER)
  		data << uint8(0xFF) << m_caster->GetGUID();
	else
  		data << m_caster->GetGUID();
	data << uint32(0x00000001);
	data << uint32(0x0000071);
	data << uint32(000000001);
	if(m_targets.m_unitTarget)
	{
		if(m_targets.m_unitTarget->GetTypeId() == TYPEID_PLAYER)
			data << uint8(0xFF) << m_targets.m_unitTarget->GetGUID();
		else
			data << m_targets.m_unitTarget->GetGUID();
	}
	else if(m_targets.m_itemTarget)
		data << m_targets.m_itemTarget->GetGUID();
	else if(m_targets.m_GOTarget)
		data << m_targets.m_GOTarget->GetGUID();
	*/
	data << m_caster->GetGUID();
	data << m_spellInfo->Id << uint32(0x00000001);
	data << uint64(0x0000000100000021LL);
	data << m_targets.m_unitTarget;
	m_caster->SendMessageToSet(&data,true);

	if (m_caster->isPlayer()) {
		// After successful cast reset last cast time to NOW
		((Player *)m_caster)->m_lastCastTime = GetPreciseTime();
	}
};


// TODO: make result flag list
void
Spell::SendInterrupted(uint8 result)
{
	WorldPacket data;

	data.Initialize(SMSG_SPELL_FAILURE);

	data << m_caster->GetGUID();
	data << m_spellInfo->Id;
	data << result;

	m_caster->SendMessageToSet(&data, true);
}


void
Spell::SendChannelUpdate(uint32 time)
{
	if (m_caster->isNotPlayer())
		return;

	WorldPacket data;

	data.Initialize( MSG_CHANNEL_UPDATE );
	data << time;

	((Player*)m_caster)->GetSession()->SendPacket( &data );

	if(time == 0){
		m_caster->SetUInt32Value(UNIT_FIELD_CHANNEL_OBJECT,0);
		m_caster->SetUInt32Value(UNIT_FIELD_CHANNEL_OBJECT+1,0);
		m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL,0);
	}
}


void
Spell::SendChannelStart(uint32 duration)
{
	Unit* target = objmgr.GetObject<Creature>(((Player*)m_caster)->GetSelection());
	if(!target)
	{
		for(int i = 0; i < 3; ++i)
		{
			if(m_spellInfo->Effect[i] == EFFECT_PERSISTENT_AREA_AURA)
			{
				target = objmgr.GetObject<Player>(((Player*)m_caster)->GetSelection());
				if(!target)
					target = m_caster;
			}
		}
	}
	if (m_caster->isPlayer()){
		// Send Channel Start
		WorldPacket data;
		data.Initialize( MSG_CHANNEL_START );
		data << m_spellInfo->Id;
		data << duration;
		((Player*)m_caster)->GetSession()->SendPacket( &data );
	}

	m_timer = duration;
	if(target)
	{
		m_caster->SetUInt32Value(UNIT_FIELD_CHANNEL_OBJECT,target->GetGUIDLow());
		m_caster->SetUInt32Value(UNIT_FIELD_CHANNEL_OBJECT+1,target->GetGUIDHigh());
	}
	m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL,m_spellInfo->Id);
}

void
Spell::SendResurrectRequest(Player* target)
{
    WorldPacket data;
    data.Initialize(SMSG_RESURRECT_REQUEST);
  // 1.9.x data << uint8(0xFF) << m_caster->GetGUID();
    data << m_caster->GetGUID();
    data << uint32(0) << uint8(0);

    target->GetSession()->SendPacket(&data);
    return;
}

void
Spell::TakePower()
{
   uint16 powerField;
   uint32 currentPower;

   uint8 powerType = (uint8)(m_caster->GetUInt32Value(UNIT_FIELD_BYTES_0) >> 24);
   if(powerType == 0)        
      powerField = UNIT_FIELD_POWER1;
   else if(powerType == 1)   
      powerField = UNIT_FIELD_POWER2;
   else if(powerType == 3)   
      powerField = UNIT_FIELD_POWER4;

   currentPower = m_caster->GetUInt32Value(powerField);

   if(currentPower < m_spellInfo->manaCost)
      m_caster->SetUInt32Value(powerField, 0);
   else
      m_caster->SetUInt32Value(powerField, currentPower - m_spellInfo->manaCost);
}


void
Spell::HandleEffects(Unit* target, uint32 i)
{
	//
	//--- Check some personal target requirements ------------
	//

	if (RequiresCasterBehindTarget (m_spellInfo->Id))
	{
		// Should be not in front, and not targeted by victim
		if ((unitTarget != NULL && (unitTarget->isInFront (m_caster, 99) || 
			unitTarget->GetTarget() == m_caster->GetGUID())) ||
			(playerTarget != NULL && (playerTarget->isInFront (m_caster, 99) || 
			playerTarget->GetTarget() == m_caster->GetGUID())))
		{
			SendCastResult (CAST_FAIL_NOT_BEHIND_TARGET);
			return;
		}
	}
	if (AbilityRequiresComboPoints (m_spellInfo->Id))
	{
		if(!m_caster->GetComboPoints())
		{
            SendCastResult (CAST_FAIL_COMBO_POINTS_REQUIRED);
			return;
		}
	}
	if(m_caster->isPlayer()){
	    playerCaster = (Player*)m_caster;
    }else{
		if( m_caster->GetUInt64Value(UNIT_FIELD_SUMMONEDBY)!=0 )
            playerCaster = objmgr.GetObject<Player>(m_caster->GetUInt64Value(UNIT_FIELD_SUMMONEDBY));
	}
	if( playerCaster )
	{
		unitTarget = objmgr.GetUnit(playerCaster, playerCaster->GetSelection());
		gameObjTarget = objmgr.GetObject<GameObject>(playerCaster->GetSelection());
		playerTarget = objmgr.GetObject<Player>(playerCaster->GetSelection());
	}

	damage = CalculateDamage((uint8)i);
	sLog.outDebug( "SPELL: Spell FX id is %u", m_spellInfo->Effect[i]); 

	uint8 eff=	m_spellInfo->Effect[i];
	if(eff<TOTAL_SPELL_EFFECTS)
		(*this.*EffectHandlers [eff])(i);
	else {
		if (m_CastItem)
			Effect_Enchant_Item_Temporary(i);
		else {
			sLog.outError("SPELL: unknown effect %d spell id %i\n",
			m_spellInfo->Effect[i], m_spellInfo->Id);
		}
	}
}

void
Spell::HandleEffects(Unit *pUnitTarget,Item *pItemTarget,GameObject *pGOTarget,uint32 i)
{
	unitTarget = pUnitTarget;
	itemTarget = pItemTarget;
	gameObjTarget = pGOTarget;
	
	damage = CalculateDamage((uint8)i);
    
	sLog.outDebug( "WORLD: Spell FX id is %u", m_spellInfo->Effect[i]); 

	uint8 eff =	m_spellInfo->Effect[i];
	if(eff<TOTAL_SPELL_EFFECTS)
		(*this.*EffectHandlers[eff])(i);
	else
	{
		if (m_CastItem)
			Effect_Enchant_Item_Temporary(i);
		else
			sLog.outError("SPELL: unknown effect %d spell id %i\n",
							m_spellInfo->Effect[i], m_spellInfo->Id);
	}
}

void
Spell::HandleAddAffect(Unit* Target)
{
	if(!Target) return;
	if(Target->isDead()) return;

	if(Target->tmpAffect != 0)
	{
		Target->AddAffect(Target->tmpAffect);
		Target->tmpAffect = 0;
	}
}

void
Spell::TriggerSpell()
{
	if(TriggerSpellId != 0){
		// check for spell id
		SpellEntry *spellInfo = sSpellStore.LookupEntry(TriggerSpellId);

		if(!spellInfo)
		{
			sLog.outError("WORLD: unknown spell id %i\n", TriggerSpellId);
			return;
		}

		Spell spell(m_caster, spellInfo,false, 0);

		SpellCastTargets targets;
		targets.m_unitTarget = m_targets.m_unitTarget;

		spell.prepare(&targets);
	}
}

uint8
Spell::CanCast()
{
	uint8 castResult = 0;
	castResult = CheckItems();
	float fSpellRange=0;
	Unit* target = m_targets.m_unitTarget;
	fSpellRange = GetMaxRange(sSpellRange.LookupEntry(m_spellInfo->rangeIndex));
	
	if (target){
		if (!castResult && m_caster != m_targets.m_unitTarget && 
			!m_caster->isInFront (m_targets.m_unitTarget, fSpellRange))
		{	// Target needs to be in Front of you
			castResult = CAST_FAIL_TARGET_NEED_TO_BE_INFRONT;
		}

		if (!castResult && _CalcDistance (m_caster->GetPositionX(),
			m_caster->GetPositionY(),
			m_caster->GetPositionZ(),
			target->GetPositionX(),
			target->GetPositionY(),
			target->GetPositionZ()) > fSpellRange) 
		{	// Target out of Range
			castResult = CAST_FAIL_OUT_OF_RANGE;
		}
	}

	if (!castResult && m_targets.m_destX != 0 && m_targets.m_destY != 0  && m_targets.m_destZ != 0 ){
		if (_CalcDistance (m_caster->GetPositionX(),
			m_caster->GetPositionY(),
			m_caster->GetPositionZ(),
			m_targets.m_destX,
			m_targets.m_destY,
			m_targets.m_destZ) > fSpellRange)
		{	// Target out of Range
			castResult = CAST_FAIL_OUT_OF_RANGE;
		}
	}

	if (m_caster->isDead()) castResult = CAST_FAIL_CANT_CAST_AS_GHOST;
	if (m_caster->m_silenced) castResult = CAST_FAIL_SILENCED;
	if (m_caster->isStunned()) castResult = CAST_FAIL_CANT_DO_WHILE_STUNNED;

	if((castResult != 0) && //Look if this is a Trainer teaching a player a spell:
		m_spellInfo->Effect[0] == EFFECT_LEARN_SPELL && 
			(m_spellInfo->EffectImplicitTargetA[0] == 0 &&
			m_spellInfo->EffectImplicitTargetA[1] == 0 &&
			m_spellInfo->EffectImplicitTargetA[2] == 0 &&
			m_spellInfo->EffectImplicitTargetB[0] == 0 &&
			m_spellInfo->EffectImplicitTargetB[1] == 0 &&
			m_spellInfo->EffectImplicitTargetB[2] == 0
			)
		)
	{
		castResult = 0;
	}

	if(m_caster->m_silenced)
		castResult = CAST_FAIL_SILENCED;

	if (castResult != 0) 
		SendCastResult(castResult);

	return castResult;
}

void
Spell::DelaySpell(uint32 delay)
{
	if((m_spellState == SPELL_STATE_PREPARING) && (m_timer) && (m_timer > 0))
	{
		m_timer += delay;
	}
}

uint32
Spell::CalculateDamage(uint8 i)
{
   uint32 value = 0;
   float bppl = (m_spellInfo->EffectRealPointsPerLevel[i]*m_spellInfo->EffectRealPointsPerLevel[i]);
   float rppl = (m_spellInfo->EffectDicePerLevel[i]*m_spellInfo->EffectDicePerLevel[i]);
   float basePointsPerLevel = sqrt(bppl);
   float randomPointsPerLevel = sqrt(rppl);
   uint32 basePoints = uint32(sqrt((float)(m_spellInfo->EffectBasePoints[i]*(float)m_spellInfo->EffectBasePoints[i]))+(m_caster->GetLevel()*basePointsPerLevel));
   uint32 randomPoints = uint32(sqrt((float)(m_spellInfo->EffectDieSides[i]*(float)m_spellInfo->EffectDieSides[i]))+(m_caster->GetLevel()*randomPointsPerLevel));
   uint32 comboDamage = uint32(sqrt((float)m_spellInfo->EffectPointsPerComboPoint[i]*(float)m_spellInfo->EffectPointsPerComboPoint[i]));
   uint8 comboPoints=0; 
   if(m_caster->isPlayer())
       comboPoints = ((m_caster->GetUInt32Value(PLAYER_FIELD_BYTES) & 0xFF00) >> 8);

   if(randomPoints <= 1)
      value = basePoints+1;
   else
      value = basePoints+rand()%randomPoints;

   if(comboDamage > 0)
   {
      for(uint32 j=0;j<comboPoints; ++j)
         value += comboDamage;
	  if(m_caster->isPlayer())
        m_caster->SetUInt32Value(PLAYER_FIELD_BYTES,((m_caster->GetUInt32Value(PLAYER_FIELD_BYTES) & ~(0xFF << 8)) | (0x00 << 8)));
   }

   

   return value;
}

uint8
Spell::CheckItems()
{
   if (!m_caster->isPlayer())
       return uint8(0);

   Player* pCaster = (Player*)m_caster;
   Item* itm;
   uint32 tmpReagentCount[8];

   
   for(uint32 i=0;i<8; ++i)
      tmpReagentCount[i] = m_spellInfo->ReagentCount[i];

   for(uint32 i=0;i<8; ++i)
   {
      if(m_spellInfo->Reagent[i] == 0)
         continue;
      for(uint32 j=0;j<INVENTORY_SLOT_ITEM_END; ++j)
      {
         itm = pCaster->GetItemBySlot(j);
         if(!itm)
           continue;
         if(itm->GetProto()->ItemId == m_spellInfo->Reagent[i] && tmpReagentCount[i] > 0)
           if(itm->GetUInt32Value(ITEM_FIELD_STACK_COUNT) > tmpReagentCount[i])
               tmpReagentCount[i] = 0;
           else
               tmpReagentCount[i] -= itm->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
      }
      if(tmpReagentCount[i] != 0)
         return uint8(CAST_FAIL_CANT_USE_WHILE_PACIFIED);
    }

    
    uint32 totems = 2;
    for(uint32 i=0;i<2; ++i)
    {
       if(m_spellInfo->Totem[i] != 0)
       {
          for(uint32 j=0;j<INVENTORY_SLOT_ITEM_END; ++j)
          {
             itm = pCaster->GetItemBySlot(j);
             if(itm->GetProto()->ItemId == m_spellInfo->Totem[i])
             {
               totems -= 1;
               continue;
             }
          }
       }else
         totems -= 1;
     }
     if(totems != 0)
        return uint8(0x70);

   return uint8(0);
}

void
Spell::RemoveItems()
{
   if (!m_caster->isPlayer())
      return;

   Player* pCaster = (Player*)m_caster;
   Item* itm;

   for(uint32 i=0;i<8; ++i)
   {
      if(m_spellInfo->Reagent[i] == 0)
         continue;
      for(uint8 j=0; j<INVENTORY_SLOT_ITEM_END; ++j)
      {
         itm = pCaster->GetItemBySlot(j);
         if(!itm)
           continue;
         if(itm->GetProto()->ItemId == m_spellInfo->Reagent[i])
           pCaster->RemoveItemFromSlot(j);
		   //pCaster->RemoveItemFromSlot(0,j,true);
         itm = NULL;
      }
   }
}
