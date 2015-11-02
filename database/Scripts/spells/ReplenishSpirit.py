from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_ReplenishSpirit:
    """ Replenish Spirit
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ReplenishSpirit: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ReplenishSpirit: SpellEffect called!"
        target.SetMana(target.GetMaxMana())

#------------------------------------------------------------------------------

#--- END ---