from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_ArcaneIntellect:
    """ Test spell
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_ArcaneIntellect: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_ArcaneIntellect: SpellEffect called!"
        target.SetMaxMana (target.GetMaxMana() + 1)

#--- END ---