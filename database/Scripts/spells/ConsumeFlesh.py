from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_ConsumeFlesh:
    """ Consume Flesh
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ConsumeFlesh: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ConsumeFlesh: SpellEffect called!"

        target.SetHealth(target.GetHealth() - 30 )
        caster.SetHealth(caster.GetHealth() + randrange(45))

#------------------------------------------------------------------------------

#--- END ---