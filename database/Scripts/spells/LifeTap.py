from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_LifeTap_rank1:
    """ LifeTap Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LifeTap_rank1: CanCast called!"

        if caster.GetHealth() > 14:
              return 0
        else:
              return co.CAST_FAIL_FAILED_ATTEMPT 

    def SpellEffect (self, caster, target):
        print "Spell_LifeTap_rank1: SpellEffect called!"
        
        caster.SetHealth(caster.GetHealth() - 14)
        caster.SetMana (caster.GetMana() + 20)

#------------------------------------------------------------------------------

class Spell_LifeTap_rank2:
    """ LifeTap Rank 2
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LifeTap_rank2: CanCast called!"

        if caster.GetHealth() > 49:
              return 0
        else:
              return co.CAST_FAIL_FAILED_ATTEMPT 

    def SpellEffect (self, caster, target):
        print "Spell_LifeTap_rank2: SpellEffect called!"

        caster.SetHealth(caster.GetHealth() - 49)
        caster.SetMana (caster.GetMana() + 65)


#------------------------------------------------------------------------------

class Spell_LifeTap_rank3:
    """ LifeTap Rank 3
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LifeTap_rank3: CanCast called!"

        if caster.GetHealth() > 104:
              return 0
        else:
              return co.CAST_FAIL_FAILED_ATTEMPT 

    def SpellEffect (self, caster, target):
        print "Spell_LifeTap_rank3: SpellEffect called!"

        caster.SetHealth(caster.GetHealth() - 104)
        caster.SetMana (caster.GetMana() + 130)

#------------------------------------------------------------------------------

#--- END ---