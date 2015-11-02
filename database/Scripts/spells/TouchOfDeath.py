from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_TouchOfDeath:
    """ Touch Of Death
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_TouchOfDeath: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_TouchOfDeath: SpellEffect called!"
        
        health = 65 + randrange(10)
        target.SetHealth (target.GetHealth() - health)
        caster.SetHealth (caster.GetHealth() + randrange(health / 2))
	
        
#--- END ---