#
# Default Demon Trainers/Vendors Module
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

    if player.GetClass() == co.CLASS_WARLOCK :
        player.AddGossipItem( 3, "I require demon training", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)

        if self.HasSellTables():
            player.AddGossipItem( 1, "Trade with me", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)

        player.SendGossipMenu(self, 5835) # Demon training positive
    else:
        player.SendGossipMenu(self, 5722) # Demon training negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self)

    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)

# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )
