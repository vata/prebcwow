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

def OnTakeDamage (self, attacker):
    """ Function is called when NPC 'self' takes damage in combat from npc or
        player 'attacker'
        Param: (Unit attacker, Unit attacker)
    """
    if 100.0 * self.GetHealth() / self.GetMaxHealth() < 70:
    	
	self.Say (attacker, "70 percent", co.LANG_UNIVERSAL)

	def CanCast (self, attacker):
            return 133

	self.Emote (50)

        # self.Emote is good to

        # Trigger 10 second flee mode when creature ignores damage with 15
        # meters help radius. If no help found, return back and attack.
        #
    	self.Flee (attacker, 10, 15)

#------------------------------------------------------------------------------



#--- END ---
