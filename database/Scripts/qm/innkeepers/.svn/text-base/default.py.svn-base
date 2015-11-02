#
# Default handler for all Innkeepers in the world. If you need special 
# treatments please use another script file for them.
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

    # Innkeeper related menus
    player.AddGossipItem( 5, "Make this inn your home.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INN)
    player.AddGossipItem( 0, "What can you do at an inn ?", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INN_INFO)

    if self.HasSellTables() :
        player.AddGossipItem( 1, "I want to browse your goods.", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)


    txtid = self.SelectIntByEntry(820, 11118, 825, 6791, 825, 7714, 825, 11103, 824, 1464, 823, 7744, 823, 9501, 822, 6746, \
				  822, 6741, 821, 6739, 821, 2388, 821, 5688, 821, 7733, 3566, 6930, 7210, 7737, 7212, 6929, \
				  938, 295, 1853, 1247, 1853, 3934, 7177)


    player.SendGossipMenu(self, txtid) # Inn Greet Message

    
# -------------------------------------------

def OnGossipSelect (self, player, sender, action):
    # Serving default menus
    
    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)
        
    if action == co.GOSSIP_ACTION_INN :
        player.SetBindPoint(self)

    if action == co.GOSSIP_ACTION_INN_INFO :
        player.AddGossipItem( 4, "Make this inn your home.", co.GOSSIP_SENDER_INN_INFO, co.GOSSIP_ACTION_INN)
        player.SendGossipMenu(self, 1853) # Default inn info
        
    
def OnDialogStatus (self, player):
    return self.NPCQuestDialogStatus( self, co.DIALOG_STATUS_CHAT )
