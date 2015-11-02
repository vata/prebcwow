#
# Default Gossip/Item/GO/AreTrigger Processor. This is the basic point
# of all QM System. We will edit and improve this file as 80% of all interaction
# in game is standartized.
#
# Author: <PavkaM>

from Ludmilla import *
import const_ai as co
reload(co)
from random import *


#######################################################################################
#                  Default Processor for NPC(Gossip) Behaviour.                       #
#######################################################################################

def OnHello (self, player):

    # Adding quests to menu, if there are quests
    if self.IsQuestGiver() :
        player.AddNPCQuests( self )

    if self.HasSellTables() :
        player.AddGossipItem( 1, "Trade with me", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRADE)
        
    if self.IsTrainer() :
        player.AddGossipItem( 1, "Train me!", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TRAIN)
                
    if self.IsTaxi() :
        player.AddGossipItem( 2, "Ride me up baby", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TAXI)

    if self.IsGuildMaster() :
        player.AddGossipItem( 3, "I wanna my guild", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_GUILD)

    if self.IsBattleMaster() :
        player.AddGossipItem( 4, "I want smash fuckers", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_BATTLE)

    if self.IsBanker() :
        player.AddGossipItem( 5, "I love money :)", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_BANK)

    if self.IsInnkeeper() :
        player.AddGossipItem( 6, "Make this inn my home", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INN)

    if self.IsSpiritHealer() :
        player.AddGossipItem( 7, "Bring me back to life", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_HEAL)

    if self.IsTabardVendor() :
        player.AddGossipItem( 1, "I want a nice design", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_TABARD)

    if self.IsAuctioner() :
        player.AddGossipItem( 2, "Auction!", co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_AUCTION)

    player.SendGossipMenu(self, co.DEFAULT_GOSSIP_MESSAGE)

    
# -------------------------------------------
    


    
def OnQuestAccept (self, player, questid):
    # no default handler for this ...
    return


# -------------------------------------------


    
def OnGossipSelect (self, player, sender, action):
    # Serving default menus
    
    if action == co.GOSSIP_ACTION_TRADE :
        player.SendVendorList(self)
        
    if action == co.GOSSIP_ACTION_TRAIN :
        player.SendTrainerList(self)
        
    if action == co.GOSSIP_ACTION_TAXI :
        player.SendTaxiList(self)
        
    if action == co.GOSSIP_ACTION_GUILD :
        player.SendGuildManager(self)
        
    if action == co.GOSSIP_ACTION_BATTLE :
        player.SendBattleFieldsList(self)
        
    if action == co.GOSSIP_ACTION_BANK :
        player.SendBankManager(self)
        
    if action == co.GOSSIP_ACTION_INN :
        player.SetBindPoint(self)
        
    if action == co.GOSSIP_ACTION_HEAL :
        player.Resurrect(self)
        
    if action == co.GOSSIP_ACTION_TABARD :
        player.SendTabardList(self)
        
    if action == co.GOSSIP_ACTION_AUCTION :
        player.SendAuctionsList(self)
        
    
def OnQuestSelect (self, player, questid):
    
    # We will send the quest details for this quest to player
    
    self.SendQuestDetails( player, questid )


# ------------------------------------------



    
def OnQuestComplete (self, player, questid):
    # Check if the quest selected is complete.
    # If yes, give reward, else require items.

    if player.CanCompleteQuest(self, questid):
        self.SendQuestReward(player, questid)
    else:
        self.SendRequiredItems(player, questid, 0)


# ------------------------------------------




def OnChooseReward (self, player, questid, rewardid):
    # Check if there are follow-ups and give if available

    FollowUpQuest = self.GetFollowingQuest(player, questid)
    if FollowUpQuest != 0 :
        self.SendQuestDetails(player, FollowUpQuest)
    else :
        self.CloseGossipWindow(player)
        
    
def OnDialogStatus (self, player):
    # Let's see if this NPC has some "jobs" besides quest-giving

    DefStatus = co.DIALOG_STATUS_NONE

    if self.IsVendor() or \
       self.IsTrainer() or \
       self.IsTaxi() or \
       self.IsGuildMaster() or \
       self.IsBattleMaster() or \
       self.IsBanker() or \
       self.IsInnkeeper() or \
       self.IsSpiritHealer() or \
       self.IsTabardVendor() or \
       self.IsAuctioner() : DefStatus = co.DIALOG_STATUS_CHAT

    # Now, if NPC has some other "jobs" we will have a chat by default, if
    # the quests don't have something special to say.

    FinalStatus = self.NPCQuestDialogStatus( self, DefStatus )
        # Let's get the final Dialog status depending on "jobs" and quests.

    return FinalStatus


# --------------------------------------





#######################################################################################
#                  Default Processor for Item Behaviour.                              #
#######################################################################################


def OnItemQuestSelect (item, player, questid):
    # We will check if the user can take the following quest
    # checks include race/class/prereqs and etc.

    if player.CanTakeQuest(questid) :
        item.SendQuestDetails(player, questid)


# --------------------------------------


def OnItemQuestAccept (item, player, questid, rewardid):
    # no default handler required ...
    return


# -------------------------------------------



#######################################################################################
#                  Default Processor for GO Behaviour.                                #
#######################################################################################


def OnGOSelect (gameobject, player):
    # Default internal hadler. You rarely will need to use
    # another handler.

    gameobject.ManageQuests(player);


# --------------------------------------

def OnGOQuestAccept (gameobject, player, questid):
    # no default handler required ...
    return

# -------------------------------------------



def OnGOChooseReward (gameobject, player, questid, rewardid):
    # no default handler required ...
    return

# -------------------------------------------


    
#######################################################################################
#                  Default Processor for AreaTrigger Behaviour.                       #
#######################################################################################


def OnAreaTrigger (player, triggerid, questid):
    #
    # Simply complete the exploration objective
    # if the trigger point is a Quest one.
    #
    
    if questid != 0 :
        if player.HasQuest(questid) :
            player.FinishExplorationObjective(questid)

        
# --------------------------------------
