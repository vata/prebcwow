#
# Default Mage Trainers Module
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

    if player.GetClass() == co.CLASS_MAGE :
        player.AddGossipItem( 3, "Train me", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
        player.SendGossipMenu(self, 558) # Shaman Mage positive
    else:
        player.SendGossipMenu(self, 539) # Shaman Mage negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self)


# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )