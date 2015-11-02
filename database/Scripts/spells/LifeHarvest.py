from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_LifeHarvest:
    """ Life Harvest
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_LifeHarvest: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_LifeHarvest: SpellEffect called!"
        
        if target.GetHealth() > 15:
              caster.SetHealth(caster.GetHealth() + 15)
        else:
              caster.SetHealth(caster.GetHealth() + target.GetHealth())

        target.SetHealth(target.GetHealth() - 15)

#------------------------------------------------------------------------------



#--- END ---