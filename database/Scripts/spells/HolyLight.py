from Ludmilla import *
from random import *

import const_spells
co = const_spells
reload (co)

#return co.CAST_FAIL_ALREADY_FULL_HEALTH
#------------------------------------------------------------------------------
class Spell_HolyLight_rank1:
    """ HolyLight Rank 1
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank1: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank1: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (39 + randrange(8)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank2:
    """ HolyLight Rank 2
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank2: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank2: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (76 + randrange(14)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank3:
    """ HolyLight Rank 3
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank3: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank3: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (159 + randrange(28)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank4:
    """ HolyLight Rank 4
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank4: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank4: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (310 + randrange(46)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank5:
    """ HolyLight Rank 5
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank5: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank5: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (491 + randrange(62)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank6:
    """ HolyLight Rank 6
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank6: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank6: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (698 + randrange(82)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank7:
    """ HolyLight Rank 7
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank7: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank7: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (945 + randrange(108)))

#------------------------------------------------------------------------------
class Spell_HolyLight_rank8:
    """ HolyLight Rank 8
    """
    def CanCast (self, caster, target_dummy):
        print "Spell_HolyLight_rank8: CanCast called!"
        return 0

    def SpellEffect (self, caster, target):
        print "Spell_HolyLight_rank8: SpellEffect called!"
        target.SetHealth(target.GetHealth() + (1246 + randrange(142)))

#------------------------------------------------------------------------------

#--- END ---