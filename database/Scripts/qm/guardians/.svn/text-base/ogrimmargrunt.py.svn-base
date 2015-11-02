#
# Default Demon Trainers/Vendors Module
#
# Author: <PavkaM>

from Ludmilla import *
import const_ai as co
reload(co)
from random import *


def OnHello (self, player):

    player.AddGossipItem( 0, "The bank"             , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 1)
    player.AddGossipItem( 0, "The wind rider maser" , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 2)    
    player.AddGossipItem( 0, "The guild master"     , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 3)
    player.AddGossipItem( 0, "The inn"              , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 4)
    player.AddGossipItem( 0, "The mailbox"          , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 5)
    player.AddGossipItem( 0, "The auction house"    , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 6)
    player.AddGossipItem( 0, "The zeppelin master"  , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 7)
    player.AddGossipItem( 0, "The weapon master"    , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 8)
    player.AddGossipItem( 0, "The stable master"    , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 9)
    player.AddGossipItem( 0, "Officers Lounge"      , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 10)
    player.AddGossipItem( 0, "A class trainer"      , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 11)
    player.AddGossipItem( 0, "A profession trainer" , co.GOSSIP_SENDER_MAIN, co.GOSSIP_ACTION_INFO_DEF + 12)
    
    player.SendGossipMenu(self, 2593)

    
#######################################################################
#                         Menu Functions                              #
#######################################################################

def SendDefaultMenu (self, player, action):
    
    if action == co.GOSSIP_ACTION_INFO_DEF + 1 :
        player.SendPOI(2, 1622, -4376, 5, 1637, "The Bank")
        player.SendGossipMenu(self, 2554)
        
    if action == co.GOSSIP_ACTION_INFO_DEF + 2 :
        player.SendPOI(2, 1677, -4315, 5, 1637, "The wind rider maser")
        player.SendGossipMenu(self, 2555)

        
    if action == co.GOSSIP_ACTION_INFO_DEF + 3 :
        player.SendPOI(2, 1575, -4294, 3, 1637, "The guild master")
        player.SendGossipMenu(self, 2556)

        
    if action == co.GOSSIP_ACTION_INFO_DEF + 4 :
        player.SendPOI(2, 1633, -4439, 3, 1637, "The Inn")
        player.SendGossipMenu(self, 2557)

		
    if action == co.GOSSIP_ACTION_INFO_DEF + 5 :
        player.SendPOI(2, 1616, -4392, 3, 1637, "The mailbox")
        player.SendGossipMenu(self, 2558)


    if action == co.GOSSIP_ACTION_INFO_DEF + 6 :
        player.SendPOI(2, 1681, -4458, 3, 1637, "The auction house")
        player.SendGossipMenu(self, 3075)


    if action == co.GOSSIP_ACTION_INFO_DEF + 7 :
        player.SendPOI(2, 1681, -4458, 3, 1637, "Officers Lounge")
        player.SendGossipMenu(self, 3173)        


    if action == co.GOSSIP_ACTION_INFO_DEF + 8 :
        player.SendPOI(2, 2092, -4824, 3, 1637, "The weapon master")
        player.SendGossipMenu(self, 4519)


    if action == co.GOSSIP_ACTION_INFO_DEF + 9 :
        player.SendPOI(2, 2133, -4664, 3, 1637, "The stable master")
        player.SendGossipMenu(self, 5974)


    if action == co.GOSSIP_ACTION_INFO_DEF + 10 :
        player.SendGossipMenu(self, 7046)


    if action == co.GOSSIP_ACTION_INFO_DEF + 11 :
        player.AddGossipItem( 0, "A hunter trainer"     , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 1)
        player.AddGossipItem( 0, "A mage trainer"       , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 2)
        player.AddGossipItem( 0, "A priest trainer"     , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 3)
        player.AddGossipItem( 0, "A shaman trainer"     , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 4)
        player.AddGossipItem( 0, "A rogue trainer"      , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 5)
        player.AddGossipItem( 0, "A warlock"            , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 6)
        player.AddGossipItem( 0, "A warrior trainer"    , co.GOSSIP_SENDER_SEC_CLASSTRAIN, co.GOSSIP_ACTION_INFO_DEF + 7)
        
        player.SendGossipMenu(self, 2599)        


    if action == co.GOSSIP_ACTION_INFO_DEF + 12 :
        player.AddGossipItem( 0, "Alchemy"              , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 1)
        player.AddGossipItem( 0, "Blacksmithing"        , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 2)
        player.AddGossipItem( 0, "Cooking"              , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 3)
        player.AddGossipItem( 0, "Enchanting"           , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 4)
        player.AddGossipItem( 0, "Engineering"          , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 5)
        player.AddGossipItem( 0, "First Aid"            , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 6)
        player.AddGossipItem( 0, "Fishing"              , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 7)
        player.AddGossipItem( 0, "Herbalism"            , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 8)
        player.AddGossipItem( 0, "Leatherworking"       , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 9)
        player.AddGossipItem( 0, "Mining"               , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 10)
        player.AddGossipItem( 0, "Skinning"             , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 11)
        player.AddGossipItem( 0, "Tailoring"            , co.GOSSIP_SENDER_SEC_PROFTRAIN, co.GOSSIP_ACTION_INFO_DEF + 12)
        
        player.SendGossipMenu(self, 2594)


def SendClassTrainerMenu (self, player, action):

    if action == co.GOSSIP_ACTION_INFO_DEF + 1 :
        player.SendPOI(2, 2098, -4617, 3, 1637, "A hunter trainer")
        player.SendGossipMenu(self, 2559)

    if action == co.GOSSIP_ACTION_INFO_DEF + 2 :
        player.SendPOI(2, 1472, -4221, 3, 1637, "A mage trainer")
        player.SendGossipMenu(self, 2560)

    if action == co.GOSSIP_ACTION_INFO_DEF + 3 :
        player.SendPOI(2, 1457, -4181, 3, 1637, "A priest trainer")
        player.SendGossipMenu(self, 2561)

    if action == co.GOSSIP_ACTION_INFO_DEF + 4 :
        player.SendPOI(2, 1934, -4221, 3, 1637, "A shaman trainer")
        player.SendGossipMenu(self, 2562)

    if action == co.GOSSIP_ACTION_INFO_DEF + 5 :
        player.SendPOI(2, 1774, -4282, 3, 1637, "A rogue trainer")
        player.SendGossipMenu(self, 2563)
        
    if action == co.GOSSIP_ACTION_INFO_DEF + 6 :
        player.SendPOI(2, 1841, -4354, 3, 1637, "A warlock trainer")
        player.SendGossipMenu(self, 2564)
        
    if action == co.GOSSIP_ACTION_INFO_DEF + 7 :
        player.SendPOI(2, 1983, -4795, 3, 1637, "A warrior trainer")
        player.SendGossipMenu(self, 2565)

    
def SendProfTrainerMenu (self, player, action):

    if action == co.GOSSIP_ACTION_INFO_DEF + 1 :
        player.SendPOI(2, 1963, -4468, 3, 1637, "Alchemy")
        player.SendGossipMenu(self, 2497)

    if action == co.GOSSIP_ACTION_INFO_DEF + 2 :
        player.SendPOI(2, 2053, -4812, 3, 1637, "Blacksmithing")
        player.SendGossipMenu(self, 2499)

    if action == co.GOSSIP_ACTION_INFO_DEF + 3 :
        player.SendPOI(2, 1770, -4486, 3, 1637, "Cooking")
        player.SendGossipMenu(self, 2500)

    if action == co.GOSSIP_ACTION_INFO_DEF + 4 :
        player.SendPOI(2, 1916, -4433, 3, 1637, "Enchanting")
        player.SendGossipMenu(self, 2501)        

    if action == co.GOSSIP_ACTION_INFO_DEF + 5 :
        player.SendPOI(2, 2045, -4745, 3, 1637, "Engineering")
        player.SendGossipMenu(self, 2653)

    if action == co.GOSSIP_ACTION_INFO_DEF + 6 :
        player.SendPOI(2, 1484, -4158, 3, 1637, "First Aid")
        player.SendGossipMenu(self, 2502)

    if action == co.GOSSIP_ACTION_INFO_DEF + 7 :
        player.SendPOI(2, 1999, -4658, 3, 1637, "Fishing")
        player.SendGossipMenu(self, 2503)

    if action == co.GOSSIP_ACTION_INFO_DEF + 8 :
        player.SendPOI(2, 1901, -4460, 3, 1637, "Herbalism")
        player.SendGossipMenu(self, 2504)         

    if action == co.GOSSIP_ACTION_INFO_DEF + 9 :
        player.SendPOI(2, 1852, -4562, 3, 1637, "Leatherworking")
        player.SendGossipMenu(self, 2513)

    if action == co.GOSSIP_ACTION_INFO_DEF + 10 :
        player.SendPOI(2, 2028, -4705, 3, 1637, "Mining")
        player.SendGossipMenu(self, 2515)

    if action == co.GOSSIP_ACTION_INFO_DEF + 11 :
        player.SendPOI(2, 1852, -4562, 3, 1637, "Skinning")
        player.SendGossipMenu(self, 2516)         

    if action == co.GOSSIP_ACTION_INFO_DEF + 12 :
        player.SendPOI(2, 1810, -4560, 3, 1637, "Tailoring")
        player.SendGossipMenu(self, 2518)  

def OnGossipSelect (self, player, sender, action):

    # Serving default/main menu
    if sender == GOSSIP_SENDER_MAIN:
        SendDefaultMenu(self, player, action)

    # Came from the second menu already    
    if sender == GOSSIP_SENDER_SEC_CLASSTRAIN:
        SendClassTrainerMenu(self, player, action)
        
    if sender == GOSSIP_SENDER_SEC_PROFTRAIN:
        SendProfTrainerMenu(self, player, action)        
        
