#
# This module is executed on Ludmilla startup
#

from Ludmilla import *
from const_spells import *

#----------------------------------------------------------

print "*** Setting up Spell handlers..."

# We do not play with Spell Scripts before Core gets fixed with Spell Effects and Auras
"""
#----------------------------------------------------------
print "*** Initializing the spell handlers for the Professions..."
import spells.profession
profession = spells.profession
reload (profession)

print "*** Tailoring spells..."
for i in (2385, 2386, 2387, 2389, 2392, 2393, 2394, 2395, 2396, 2397, 2399, 2401, 2402, 2403, 2406, 2963, 2964, 3755, 3757, 3758, 3813, 3839, 3840, 3841, 3842, 3843, 3844, 3845, 3847, 3848, 3849, 3850, 3851, 3852, 3854, 3855, 3856, 3857, 3858, 3859, 3860, 3861, 3862, 3863, 3864, 3865, 3866, 3868, 3869, 3870, 3871, 3872, 3873, 3914, 3915, 6521, 6686, 6688, 6690, 6692, 6693, 6695, 7623, 7624, 7629, 7630, 7633, 7636, 7639, 7643, 7892, 7893, 8465, 8467):
    RegisterSpellClass (i, profession.Spell_Professions(i, 197))

for i in (8483, 8489, 8758, 8760, 8762, 8764, 8766, 8770, 8772, 8774, 8776, 8778, 8780, 8782, 8784, 8786, 8789, 8791, 8793, 8795, 8797, 8799, 8802, 8804, 12044, 12045, 12046, 12047, 12048, 12049, 12050, 12052, 12053, 12055, 12056, 12059, 12060, 12061, 12062, 12063, 12064, 12065, 12066, 12067, 12068, 12069, 12070, 12071, 12072, 12073, 12074, 12075, 12076, 12077, 12078, 12079, 12080, 12081, 12082, 12083, 12084, 12085, 12086, 12087, 12088, 12089, 12090):
    RegisterSpellClass (i, profession.Spell_Professions(i, 197))

for i in (12091, 12092, 12093, 18401, 18402, 18403, 18404, 18405, 18406, 18407, 18408, 18409, 18410, 18411, 18412, 18413, 18414, 18415, 18416, 18417, 18418, 18419, 18420, 18421, 18422, 18423, 18424, 18434, 18436, 18437, 18438, 18439, 18440, 18441, 18442, 18444, 18445, 18446, 18447, 18448, 18449, 18450, 18451, 18452, 18453, 18454, 18455, 18456, 18457, 18458, 18560, 19435, 20848, 20849, 21945, 22759, 22813, 22866, 22867, 22868, 22869, 22870, 22902):
    RegisterSpellClass (i, profession.Spell_Professions(i, 197))

#----------------------------------------------------------

print "*** Initializing the spell handlers for Spells..."

#----------------------------------------------------------
print "*** Arcane Intellect..."

import spells.ArcaneIntellect
ArcaneIntellect = spells.ArcaneIntellect
reload (ArcaneIntellect)

RegisterSpellClass (1459, ArcaneIntellect.Spell_ArcaneIntellect_rank1()) # Rank 1
RegisterSpellClass (1460, ArcaneIntellect.Spell_ArcaneIntellect_rank2()) # Rank 2
RegisterSpellClass (1461, ArcaneIntellect.Spell_ArcaneIntellect_rank3()) # Rank 3

#----------------------------------------------------------
print "*** Life Tap..."

import spells.LifeTap
LifeTap = spells.LifeTap
reload (LifeTap)

RegisterSpellClass (1454, LifeTap.Spell_LifeTap_rank1()) # Rank 1
RegisterSpellClass (1455, LifeTap.Spell_LifeTap_rank2()) # Rank 2
RegisterSpellClass (1456, LifeTap.Spell_LifeTap_rank3()) # Rank 3

#----------------------------------------------------------
print "*** Lay On Hands..."

import spells.LayOnHands
LayOnHands = spells.LayOnHands
reload (LayOnHands)

RegisterSpellClass (633, LayOnHands.Spell_LayOnHands_rank1()) # Rank 1
RegisterSpellClass (2800, LayOnHands.Spell_LayOnHands_rank2()) # Rank 2
RegisterSpellClass (10310, LayOnHands.Spell_LayOnHands_rank3()) # Rank 3

#----------------------------------------------------------
print "*** Holy Light..."

import spells.HolyLight
HolyLight = spells.HolyLight
reload (HolyLight)

RegisterSpellClass (635, HolyLight.Spell_HolyLight_rank1()) # Rank 1
RegisterSpellClass (639, HolyLight.Spell_HolyLight_rank2()) # Rank 2
RegisterSpellClass (647, HolyLight.Spell_HolyLight_rank3()) # Rank 3
RegisterSpellClass (1026, HolyLight.Spell_HolyLight_rank4()) # Rank 4
RegisterSpellClass (1042, HolyLight.Spell_HolyLight_rank5()) # Rank 5
RegisterSpellClass (3472, HolyLight.Spell_HolyLight_rank6()) # Rank 6
RegisterSpellClass (10328, HolyLight.Spell_HolyLight_rank7()) # Rank 7
RegisterSpellClass (10329, HolyLight.Spell_HolyLight_rank8()) # Rank 8

#----------------------------------------------------------
print "*** Replenish Spirit..."

import spells.ReplenishSpirit
ReplenishSpirit = spells.ReplenishSpirit
reload (ReplenishSpirit)

RegisterSpellClass (455, ReplenishSpirit.Spell_ReplenishSpirit())

#----------------------------------------------------------
print "*** Consume Flesh..."

import spells.ConsumeFlesh
ConsumeFlesh = spells.ConsumeFlesh
reload (ConsumeFlesh)

RegisterSpellClass (3393, ConsumeFlesh.Spell_ConsumeFlesh())

#----------------------------------------------------------
print "*** Soul Rend..."

import spells.SoulRend
SoulRend = spells.SoulRend
reload (SoulRend)

RegisterSpellClass (3405, SoulRend.Spell_SoulRend())

#----------------------------------------------------------
print "*** Fatal Bite..."

import spells.FatalBite
FatalBite = spells.FatalBite
reload (FatalBite)

RegisterSpellClass (7938, FatalBite.Spell_FatalBite())

#----------------------------------------------------------
print "*** Nullify Mana..."

import spells.NullifyMana
NullifyMana = spells.NullifyMana
reload (NullifyMana)

RegisterSpellClass (7994, NullifyMana.Spell_NullifyMana())

#----------------------------------------------------------
print "*** Life Harvest..."

import spells.LifeHarvest
LifeHarvest = spells.LifeHarvest
reload (LifeHarvest)

RegisterSpellClass (3243, LifeHarvest.Spell_LifeHarvest())

#----------------------------------------------------------
print "*** Touch Of Death..."

import spells.TouchOfDeath
TouchOfDeath = spells.TouchOfDeath
reload (TouchOfDeath)

RegisterSpellClass (3108, TouchOfDeath.Spell_TouchOfDeath())

#----------------------------------------------------------
print "*** Mark of the Wild..."

import spells.MarkoftheWild
MarkoftheWild = spells.MarkoftheWild
reload (MarkoftheWild)

RegisterSpellClass (5232, MarkoftheWild.Spell_MarkoftheWild_rank2())
RegisterSpellClass (6756, MarkoftheWild.Spell_MarkoftheWild_rank3())
RegisterSpellClass (5234, MarkoftheWild.Spell_MarkoftheWild_rank4())
RegisterSpellClass (8907, MarkoftheWild.Spell_MarkoftheWild_rank5())
RegisterSpellClass (9884, MarkoftheWild.Spell_MarkoftheWild_rank6())
RegisterSpellClass (9885, MarkoftheWild.Spell_MarkoftheWild_rank7())


#RegisterAuraHandler (
"""

#--- END ---
