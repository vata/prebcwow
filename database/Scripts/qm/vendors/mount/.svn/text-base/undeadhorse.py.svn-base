#
# Default Undead Horse Vendor module
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

    if player.GetRace() == co.RACE_UNDEAD :
        player.AddGossipItem( 1, "Buy undead horse", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)
        player.SendGossipMenu(self, 4869) # Undead Horse Vendor positive
    else:
        player.SendGossipMenu(self, 624) # Undead Horse Vendor negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)


# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )