from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_ArcaneIntellect_rank1:
    """ Arcane Intellect Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ArcaneIntellect_rank1: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ArcaneIntellect_rank1: SpellEffect called!"
        #target.SetMaxMana (target.GetMaxMana() + 1)
        target.SetIntellect (target.GetIntellect() + 2)

#------------------------------------------------------------------------------

class Spell_ArcaneIntellect_rank2:
    """ Arcane Intellect Rank 2
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ArcaneIntellect_rank2: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ArcaneIntellect_rank2: SpellEffect called!"
        #target.SetMaxMana (target.GetMaxMana() + 3.5)
        target.SetIntellect (target.GetIntellect() + 7)

#------------------------------------------------------------------------------

class Spell_ArcaneIntellect_rank3:
    """ Arcane Intellect Rank 3
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ArcaneIntellect_rank3: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ArcaneIntellect_rank3: SpellEffect called!"
        #target.SetMaxMana (target.GetMaxMana() + 7.5)
        target.SetIntellect (target.GetIntellect() + 15)

#--- END ---