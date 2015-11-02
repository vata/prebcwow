from Ludmilla import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_SoulRend:
    """ Soul Rend
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_SoulRend: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_SoulRend: SpellEffect called!"
                
        if target.GetMana() < 150:
              caster.SetMana(caster.GetMana() + target.GetMana())
              target.SetMana(0)
        else:
              target.SetMana(target.GetMana() - 150)
              caster.SetMana(caster.GetMana() + 150)

#------------------------------------------------------------------------------

#--- END ---