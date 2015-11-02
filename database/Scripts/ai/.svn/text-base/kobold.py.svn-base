#
# AI Behavior Module
#
# To disable some handler, comment it out or rename, so loader doesn't find it by name
#
from Ludmilla import *
import const_ai as co
reload(co)
from random import *

#------------------------------------------------------------------------------
attack_messages = ["You no take candle!", "Yiieeeee! Me run!"]

def OnAttacked (self, attacker):
    """ Param: (Unit npc, Unit npc2)
        Function is called when npc is attacked by npc2, just before attack
        reaction game function called. If OnAttacked returns 0 or None, then
        normal reaction for current aiclass is called (attack back or flee).
    """
    if randrange (100) < 10:
        self.Say (attacker, choice (attack_messages), co.LANG_UNIVERSAL)
    #npc.Emote (EMOTE_STATE_DEAD)

    #self.Equip (0, 1523)
    #self.Equip (1, 1523)

#------------------------------------------------------------------------------
runaway_messages = ["Sorry, I got to go!", "Whoops, its dinner time!",
    "See you later!", "Got to go!", "Have a nice day!"]

def OnTakeDamage (self, attacker):
    """ Function is called when NPC 'self' takes damage in combat from npc or
        player 'attacker'
        Param: (Unit attacker, Unit attacker)
    """
    if 100.0 * self.GetHealth() / self.GetMaxHealth() <= 10.0:
        if randrange (100) < 10:
            self.Say (attacker, choice (runaway_messages), co.LANG_UNIVERSAL)
        # self.Emote is good to

        # Trigger 7 second flee mode when creature ignores damage
        self.Flee (attacker, 7, 10)

#--- END ---
