#
# Default Enchanting Trainers Module
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

    if self.HasSellTables():
        player.AddGossipItem( 1, "I need some supplies", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)

    player.AddGossipItem( 3, "Train me.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
    player.SendGossipMenu(self, 5218) 

# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self, "Enchanting is the art of improving existing items through magic.")

    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)

# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )