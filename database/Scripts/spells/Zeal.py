from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_Zeal_rank1:
    """ Zeal Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_Zeal_rank1: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_Zeal_rank1: SpellEffect called!"

        caster.SetMinDamage(caster.GetMinDamage() + 10)
        caster.SetMaxDamage(caster.GetMaxDamage() + 10)


#------------------------------------------------------------------------------

#--- END ---