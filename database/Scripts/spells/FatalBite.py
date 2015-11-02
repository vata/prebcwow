from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_FatalBite:
    """ Fatal Bite
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_FatalBite: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_FatalBite: SpellEffect called!"

        target.SetHealth(target.GetHealth() - 50 )
        caster.SetHealth(caster.GetHealth() + randrange(100))

#------------------------------------------------------------------------------

#--- END ---