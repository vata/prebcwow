from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank1:
    """ Inner Fire Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank1: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank1: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 20)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank2:
    """ Inner Fire Rank 2
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank2: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank2: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 35)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank3:
    """ Inner Fire Rank 3
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank3: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank3: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 50)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank4:
    """ Inner Fire Rank 4
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank4: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank4: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 70)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank5:
    """ Inner Fire Rank 5
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank5: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank5: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 90)

#------------------------------------------------------------------------------
class Spell_InnerFire_rank6:
    """ Inner Fire Rank 6
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_InnerFire_rank6: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_InnerFire_rank6: SpellEffect called!"

        caster.SetAttackPower(caster.GetAttackPower() + 110)

#------------------------------------------------------------------------------

#--- END ---