#
# Default Raptor Handler Vendor module
#
# Author: <PavkaM>

from Ludmilla import *
import const_ai as co
reload(co)
from random import *


def OnHello (self, player):
    # Adding quests to menu, if there are quests
    if self.IsQuestGiver() :
        player.AddNPCQuests( self )

    if player.GetRace() == co.TROLL :
        player.AddGossipItem( 1, "Buy raptor", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)
        player.SendGossipMenu(self, 3896) # Raptor Handler Vendor positive
    else:
        player.SendGossipMenu(self, 5842) # Raptor Handler Vendor negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)


# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )