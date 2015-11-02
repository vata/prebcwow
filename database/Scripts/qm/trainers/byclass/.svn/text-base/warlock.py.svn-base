#
# Default Warlock Trainers Module
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

    deftext = "Train me"
    rejtext = 5836

    if self.GetEntry() == 459:
        deftext = "I am interested in warlock training."
        rejtext = 5722

    if player.GetClass() == co.CLASS_WARLOCK :
        if self.HasSellTables():
            player.AddGossipItem( 1, "Show me your selection of grimoires.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)

        player.AddGossipItem( 3, deftext, co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
        player.SendGossipMenu(self, 5835) # Warlock training positive
    else:
        player.SendGossipMenu(self, rejtext) # Warlock training negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self)


# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )
