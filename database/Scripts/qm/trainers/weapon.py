#
# Default Weapon Master trainer module
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

    # Select between different dialogs for each weapon trainer

    txtid = self.SelectIntByEntry(co.DEFAULT_GOSSIP_MESSAGE, 11869, 6279, 13084, 6295, 11865, 6293, 2704, 6275, 11866, 6291, 11868, 6233, 11867, 6289)

    player.AddGossipItem( 3, "I'd like some weapon trainig.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
    player.AddGossipItem( 0, "What can other weapon master teach?", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO)
    player.SendGossipMenu(self, txtid ) # Weapon Master Info



# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self)

    if action == co.GOSSIP_ACTION_INFO :
        txtid = self.SelectIntByEntry(co.DEFAULT_GOSSIP_MESSAGE, 11869, 6281, 13084, 6296, 11865, 6294, 2704, 6277, 11866, 6292, 11868, 6235, 11867, 6290)
        player.SendGossipMenu(self, txtid)

# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )