#
# SpiritHealers default handler
#
# Author: <PavkaM>

from Ludmilla import *
import const_ai as co
reload(co)
from random import *


def OnHello (self, player):
    # Innkeeper related menus
    player.AddGossipItem( 4, "Return me to life", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_HEAL)
    player.SendGossipMenu(self, 580) # Spirit healer message

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    # Serving default menus
    
    if action == co.GOSSIP_ACTION_HEAL :
        player.Resurrect(self)

