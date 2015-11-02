#
# Default Paladin Trainers Module
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

    defstatic = "Train me"
    defnpc    = 1637
    if self.GetEntry() == 925:
        defstatic = "I would like to train further in the ways of the Light."
        defnpc    = 3976

    
    if player.GetClass() == co.CLASS_PALADIN :
        player.AddGossipItem( 3, defstatic, co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
        player.SendGossipMenu(self, 1637) # Paladin training positive
    else:
        player.SendGossipMenu(self, 1635) # Paladin training negative

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self, "Hello, paladin!  Ready for some training?")


# -------------------------------------------


def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )