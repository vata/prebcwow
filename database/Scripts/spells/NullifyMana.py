from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_NullifyMana:
    """ Nullify Mana
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_NullifyMana: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_NullifyMana: SpellEffect called!"
        
        if target.GetMana() > 5:
              target.SetMana(target.GetMana() - 5)
              caster.SetMana(caster.GetMana() + 5)

        if target.GetMana() < 5:
              caster.SetMana(caster.GetMana() + target.GetMana())
              target.SetMana(0)

#------------------------------------------------------------------------------

#--- END ---