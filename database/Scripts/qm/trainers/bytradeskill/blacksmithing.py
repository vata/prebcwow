#
# Default Blacksmithing Trainers Module
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
        player.AddGossipItem( 1, "I need blacksmithing supplies.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)

    player.AddGossipItem( 3, "Train me.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
    player.SendGossipMenu(self, 1118) 

# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self, "Care to learn how to turn the ore that you find into weapons and metal armor?")

    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)

# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )