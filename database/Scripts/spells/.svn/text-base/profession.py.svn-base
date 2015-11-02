import const_spells
co = const_spells
reload (co)
from random import *

class Spell_Professions:
    def __init__(self, spellid, skillid):
        """ Constructor for the class:
            We put here the ID of the binded spell and the associated skill number
        """
        self.spellid = spellid
        self.skillid = skillid
    
    def GetRequiredSkill(self):
        """ This function return the requires skill level for the spell ID defined in
            the class. This function will be later exported outside the class.
        """
	if self.spellid in (2387, 2393, 2963, 3915, 12044):
	    return 1
        if self.spellid == 2385:
            return 10
        if self.spellid == 8776:
            return 15
        if self.spellid == 12045:
            return 20
        if self.spellid in (3914, 7623, 7624):
            return 30
        if self.spellid == 3840:
            return 35
        if self.spellid in (2389, 2392, 2394, 8465):
            return 40
        if self.spellid in (3755, 7629, 7630):
            return 50
        if self.spellid in (2397, 2964, 3841):
            return 60
        if self.spellid == 2386:
            return 65
        if self.spellid in (2395, 2396, 3842, 6686, 7633):
            return 70
        if self.spellid in (12046, 2402):
            return 75
        if self.spellid in (3757, 3845):
            return 80
        if self.spellid in (2399, 3843):
            return 85
        if self.spellid in (3758, 3847, 6521, 7636):
            return 90
        if self.spellid in (2401, 3844, 7639):
            return 95
        if self.spellid in (2403, 2406):
            return 100
        if self.spellid in (3839, 3848, 3850, 3866, 6688, 7643, 8467):
            return 110
        if self.spellid == 3939:
            return 115
        if self.spellid in (3941, 3940):
            return 120
        if self.spellid in (3947, 3946, 3945, 3944, 3942, 9269):
            return 125
        if self.spellid == 3949:
            return 130
        if self.spellid in (6458, 8243):
            return 135
        if self.spellid in (3950, 3952):
            return 140
        if self.spellid == 3953:
            return 145
        if self.spellid in (12584, 3954, 3956, 3955):
            return 150
        if self.spellid == 3957:
            return 155
        if self.spellid == 3958:
            return 160
        if self.spellid in (9273, 3959):
            return 165
        if self.spellid in (3961, 3960):
            return 170
        if self.spellid in (12590, 12586, 3963, 3962, 12585, 12587, 12719):
            return 175
        if self.spellid in (3964, 23068, 23066, 3979, 23069):
            return 180
        if self.spellid in (3965, 3966):
            return 185
        if self.spellid == 3967:
            return 190
        if self.spellid in (12589, 12603, 12599, 3968, 12621):
            return 195
        if self.spellid in (12591, 15255, 12900, 12895, 3969, 12597, 23070, 19788, 19796):
            return 200
        if self.spellid in (12760, 12718, 12595, 12594, 12899, 12717):
            return 205
        if self.spellid in (15628, 12715, 12596, 3971, 12902, 12897):
            return 210
        if self.spellid in (3972, 12903, 12615):
            return 215
        if self.spellid in (12720, 12722, 12614, 12607, 12904):
            return 220
        if self.spellid in (12754, 12616, 12905):
            return 225
        if self.spellid in (12755, 12617, 12906, 12618):
            return 230
        if self.spellid in (12716, 12619, 12907, 12758):
            return 235
        if self.spellid in (8895, 12620, 12759, 23129, 12908):
            return 240
        if self.spellid in (12622, 19567, 23071):
            return 245
        if self.spellid in (12624, 23096):
            return 250
        if self.spellid == 23080:
            return 255
        if self.spellid in (23077, 19791, 19792, 19790, 23078, 19793):
            return 260
        if self.spellid == 23079:
            return  265
        if self.spellid in (23489, 23486, 19794):
            return 270
        if self.spellid in (19795, 19814):
            return 275
        if self.spellid in (15633, 19825):
            return 280
        if self.spellid in (19800, 19815, 19799, 19819, 23081):
            return 285
        if self.spellid in (21940, 19833, 19831, 23082, 19830, 22797, 22795, 22793, 22704):
            return 300

    def CanCast (self, caster, target_dummy):
        """ We define here if the player has the required skill level to cast this spell
            and we set the failure statistic
        """
        print "CanCast for spell Id: %d" % self.spellid
        if caster.GetSkill(self.skillid) < self.GetRequiredSkill():
            print "Not casted, need skill level %d, player has level %d only in skill %d!" % (self.GetRequiredSkill(), caster.GetSkill(self.skillid), self.skillid)
            return co.CAST_FAIL_SKILL_NOT_HIGH_ENOUGH
        elif randrange(100) < (caster.GetSkill(self.skillid) * 100) / (self.GetRequiredSkill() * 2):
            """ 50% failed if skill level = reg skill (that is the minimum)
               change the 2 by 4 to get 75% failed
            """
            print "Bad luck, player failed to cast..."
            return co.CAST_FAIL_FAILED_ATTEMPT
        else:
            print "Skill Ok to cast, ReqSkill=%d for Skill %d" % (self.GetRequiredSkill(), self.skillid)
            return 0

    def SpellEffectProf (self, caster, item):
        """ We define here the skill the player gain and we have to put the name of the
            player in the Creator field of the created object
        """
        print "SpellEffectProf for spell Id %d" % self.spellid # and item %d..." % (self.spellid, item.GetID())
        item.SetCreator("Made by %s" % caster.GetName())
        # grey		skillItem < 25% skill      0% luck
        # Green		25% < skillItem < 50%     33% luck
        # Yellow	50% < skillItem < 75%     66% luck
        # Orange	75% < skillItem < 100%   100% luck
        if caster.GetSkill(self.skillid) * 25 / 100 < self.GetRequiredSkill() <= caster.GetSkill(self.skillid) * 50 / 100:
            if (randrange(100) <= 33) and (caster.GetSkill(self.skillid) < caster.GetMaxSkill(self.skillid)):
                caster.SetSkill(self.skillid), caster.GetSkill(self.skillid) + 1, caster.GetMaxSkill(self.skillid)
        elif caster.GetSkill(self.skillid) * 50 / 100 < self.GetRequiredSkill() <= caster.GetSkill(self.skillid) * 75 / 100:
            if (randrange(100) <= 66) and (caster.GetSkill(self.skillid) < caster.GetMaxSkill(self.skillid)):
                caster.SetSkill(self.skillid), caster.GetSkill(self.skillid) + 1, caster.GetMaxSkill(self.skillid)
        elif self.GetRequiredSkill() > caster.GetSkill(self.skillid) * 75 / 100:
            if caster.GetSkill(self.skillid) < caster.GetMaxSkill(self.skillid):
                caster.SetSkill(self.skillid), caster.GetSkill(self.skillid) + 1, caster.GetMaxSkill(self.skillid)
        return 0
