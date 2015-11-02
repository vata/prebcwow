#
# AI Behavior Module
#
# To disable some handler, comment it out or rename, so loader doesn't find it by name
#

from Ludmilla import *
import const_ai as co
reload(co)
from random import *

FOLLOW_PATH_FORTH = 2
FOLLOW_PATH_BACK  = 3

#------------------------------------------------------------------------------
#attack_emotes = [EMOTE_ONESHOT_RUDE, EMOTE_ONESHOT_ROAR, EMOTE_ONESHOT_POINT]
attack_messages = ["I can fight too!",
    "I show you!"]

def OnAttacked (self, attacker):
    """ Param: (Unit npc, Unit npc2)
        Function is called when npc is attacked by npc2, just before attack
        reaction game function called. If OnAttacked returns 0 or None, then
        normal reaction for current aiclass is called (attack back or flee).
    """
    # looks stupid :) self.Emote (choice (attack_emotes))
    if randrange (100) < 10:
        self.Say (attacker, choice (attack_messages), co.LANG_UNIVERSAL)

#------------------------------------------------------------------------------
runaway_messages = ["I must go to work!", "Whoops, its dinner time!",
    "See you later!", "Got to go!", "Have a nice day!"]

def OnTakeDamage (self, attacker):
    """ Function is called when NPC 'self' takes damage in combat from npc or
        player 'attacker'
        Param: (Unit attacker, Unit attacker)
    """
    if 100.0 * self.GetHealth() / self.GetMaxHealth() <= 20:
        if randrange (100) < 15:
            self.Say (attacker, choice (runaway_messages), co.LANG_UNIVERSAL)
        # self.Emote is good to

        # Trigger 10 second flee mode when creature ignores damage with 15
        # meters help radius. If no help found, return back and attack.
        #
    self.Flee (attacker, 10, 15)


#------------------------------------------------------------------------------
working_messages = ["Here you are my treasure!", "Gooold!", "Working, Working..."]

def OnThink (self, val):
    if val <= 3:
        self.Emote (co.EMOTE_STATE_WORK_NOSHEATHE_MINING)
        val+=1
        self.NextThink (1000,val)
    else:
        val=1
        if randrange (100) < 5:
            self.Say (self, choice (working_messages), co.LANG_UNIVERSAL)
            
        self.NextThink (6000,val)

#------------------------------------------------------------------------------
def OnInitNpc (self):
    #self.MovementType (FOLLOW_PATH_FORTH)
    self.NextThink (10000,1)
    #OnThink (self, 1)

#--- END ---
