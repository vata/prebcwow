from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_LayOnHands_rank1:
    """ LifeTap Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LayOnHands_rank1: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_LayOnHands_rank1: SpellEffect called!"
        target.SetHealth(caster.GetMaxHealth())
        caster.SetMana (0)

#------------------------------------------------------------------------------

class Spell_LayOnHands_rank2:
    """ LifeTap Rank 2
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LayOnHands_rank2: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_LayOnHands_rank2: SpellEffect called!"
        target.SetHealth(caster.GetMaxHealth())
        target.SetMana(target.GetMana() + 250)
        caster.SetMana (0)

#------------------------------------------------------------------------------

class Spell_LayOnHands_rank3:
    """ LifeTap Rank 3
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LayOnHands_rank3: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_LayOnHands_rank3: SpellEffect called!"
        target.SetHealth(caster.GetMaxHealth())
        target.SetMana(target.GetMana() + 250)
        caster.SetMana (0)

#------------------------------------------------------------------------------

#--- END ---