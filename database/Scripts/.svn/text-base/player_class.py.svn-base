#  This file contains predefined race and class initialisations,
#  LudMilla calls race and class init functions on creating character
#  and on loading character (when recalculating base stats)
#
#
# v.0310 (Date: 03.10.2005) / Kosuha

# #####  SETTINGS #######
MAX_COUNT_SUPPLY =  2    # Max Supplies #1 in bagpack       (usually Water)
MAX_COUNT_SUPPLY2 = 4    # Max Supplies #2 in bagpack       (usually Bread, Apple, Musroom, Jerky)
MAX_COUNT_AMMO =    200  # Max Ammo in bagpack                 (usually Bullets, Arrows)
MAX_COUNT_WPN =     100  # Max Weapon                               (usually Throwing Knifes, Axes)
GIFT =              1    # To Disable function - 0, Enable - 1 (Default) (puts nice flower to female chars to bagpack)
WDDG_CUSTOM =       0    # To Disable function - 0 (Default), Enable - 1 (for adding custom Items to bagpack or char)
# ###################



# ############### !!! DO NOT MODIFY ANY SETTING BELOW THIS LINE, IT MAY LEAD TO SERVER INSTABILLITY !!!  ################




from const_ai import *   # Import of constants

# RACE-COMMON ################################################################################
#---------------------------------------ALLIANCE-----------------------------------------------------#

def CommonOneTimeRacialAlliance (p):
    """ One Time Racial additions common to all races of Alliance
    """

    p.AddSpell (668)            # Language: Common
    p.SetSkill (98, 300, 300)   # Language: Common
    p.AddSpell (203)            # Unarmed
    p.SetSkill (162, 1, 5)      # Unarmed
    p.AddSpell (81)             # Dodge
    p.AddSpell (0x19CB)         # Attack Melee
    p.AddSpell (3365)           # Opening
    p.AddSpell (6478)           # Opening
    p.AddSpell (9078)           # Cloth
    p.SetSkill (415, 1, 1)      # Cloth
    p.AddSpell (7266)           # Duel
    #--- Initial Items GLOBAL ---
    p.AddItemToSlot (23, 6948, 1)                   # Hearthstone

# RACE-COMMON ################################################################################
#--------------------------------------HORDE------------------------------------------------------#

def CommonOneTimeRacialHorde (p):
    """ One Time Racial additions common to all races of Horde
    """

    p.AddSpell (669)            # Language: Orcish
    p.SetSkill (109, 300, 300)  # Language: Orcish
    p.AddSpell (203)            # Unarmed
    p.SetSkill (162, 1, 5)      # Unarmed
    p.AddSpell (81)             # Dodge
    p.AddSpell (0x19CB)         # Attack Melee
    p.AddSpell (3365)           # Opening
    p.AddSpell (6478)           # Opening
    p.AddSpell (9078)           # Cloth
    p.SetSkill (415, 1, 1)      # Cloth
    p.AddSpell (7266)           # Duel
    #--- Initial Items GLOBAL ---
    p.AddItemToSlot (23, 6948, 1)                   # Hearthstone

# #############################################################################################
# ##
# ##  RACE INIT FUNCTIONS
# ##
# #############################################################################################

# ##############################  ALLIANCE ####################################################
#--------------------------------------------------------------------------------------------#

def Dwarf (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (22)
    p.SetAgility  (16)
    p.SetStamina  (23)
    p.SetIntellect(19)
    p.SetSpirit   (19)
    
    #--- Resistances ---        
    p.ModifyFrostResist(10)    # Frost Resistance 10

    if oneTimeInit:
        p.PlayerModel (53, 54)      # Male / Female
        p.StartupLocation (0, -6240.32, 331.033, 382.758, 1.0)  # Coldridge Valley
        p.SetFaction (3)            # PLAYER, Dwarf

        p.AddSpell (672)            # Language: Dwarven
        p.SetSkill (111, 300, 300)  # Language: Dwarven

        CommonOneTimeRacialAlliance (p)
        Reputation (p)
        
        #--- Racial ---
        p.AddSpell (2481)       # Find Treasure
        p.AddSpell (20594)      # Stoneform
        p.AddSpell (20595)      # Gun Specialization
        p.AddSpell (20596)      # Frost Resistance
        
#--------------------------------------------------------------------------------------------#
def Gnome (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (15)
    p.SetAgility  (23)
    p.SetStamina  (19)
    p.SetIntellect(23)
    p.SetSpirit   (20)
    
    #--- Resistances ---        
    p.ModifyArcaneResist(10)   # Arcane Resistance 10

    if oneTimeInit:
        p.PlayerModel (1563, 1564)  # Male / Female
        p.StartupLocation (0, -6240.32, 331.033, 382.758, 1.0)  # Coldridge Valley
        p.SetFaction (8)            # PLAYER, Gnome

        p.AddSpell (7340)           # Language: Gnomish
        p.SetSkill (313, 300, 300)  # Language: Gnomish

        CommonOneTimeRacialAlliance (p)
        Reputation (p)

        #--- Racial ---
        p.AddSpell (20589)      # Escape Artist
        p.AddSpell (20591)      # Expansive Mind
        p.AddSpell (20592)      # Arcane Resistance
        p.AddSpell (20593)      # Engineering Specialization
        
#--------------------------------------------------------------------------------------------#
def Human (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """    
    p.SetStrength (20)
    p.SetAgility  (20)
    p.SetStamina  (20)
    p.SetIntellect(20)
    p.SetSpirit   (21)

    if oneTimeInit:
        p.PlayerModel (49, 50)      # Male / Female
        p.StartupLocation (0, -8949.95, -132.493, 83.5312, 1.0)  # Northshire Valley
        p.SetFaction (1)            # PLAYER, Human

        CommonOneTimeRacialAlliance (p)
        Reputation (p)
        
        #--- Racial ---
        p.AddSpell (20597)      # Sword Specialization
        p.AddSpell (20598)      # The Human Spirit
        p.AddSpell (20599)      # Diplomacy
        p.AddSpell (20600)      # Perception
        p.AddSpell (20864)      # Mace Specialization

#--------------------------------------------------------------------------------------------#
def NightElf (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (17)
    p.SetAgility  (25)
    p.SetStamina  (19)
    p.SetIntellect(20)
    p.SetSpirit   (20)
    
    #--- Resistances ---        
    p.ModifyNatureResist(10)   # Nature Resistance 10
    
    if oneTimeInit: 
        p.PlayerModel (55, 56)      # Male / Female
        p.StartupLocation (1, 10311.3, 832.463, 1326.41, 1.0)  # Shadowglen
        p.SetFaction (4)            # PLAYER, Night Elf

        p.AddSpell (671)            # Language: Darnassian
        p.SetSkill (113, 300, 300)  # Language: Darnassian

        CommonOneTimeRacialAlliance (p)
        Reputation (p)

        #--- Racial ---
        p.AddSpell (20580)      # Shadowmeld
        p.AddSpell (20582)      # Quickness
        p.AddSpell (20583)      # Nature Resistance
        p.AddSpell (20585)      # Wisp Spirit

# ##############################  HORDE #######################################################
#--------------------------------------------------------------------------------------------#

def Orc (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (23)
    p.SetAgility  (17)
    p.SetStamina  (22)
    p.SetIntellect(17)
    p.SetSpirit   (23)

    if oneTimeInit:
        p.PlayerModel (51, 52)  # Male / Female
        p.StartupLocation (1, -618.518, -4251.67, 38.718, 1.0)  # Valley of Trials
        p.SetFaction (2)        # PLAYER, Orc

        CommonOneTimeRacialHorde (p)
        Reputation (p)

        #--- Racial ---
        p.AddSpell (20572)      # Blood Fury
        p.AddSpell (20573)      # Hardness
        p.AddSpell (20574)      # Axe Specialization
        p.AddSpell (20575)      # Command

#--------------------------------------------------------------------------------------------#
def Tauren (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (25)
    p.SetAgility  (15)
    p.SetStamina  (22)
    p.SetIntellect(15)
    p.SetSpirit   (22)
    
    #--- Resistances ---        
    p.ModifyNatureResist(10)   # Nature Resistance 10

    if oneTimeInit:
        p.PlayerModel (59, 60)      # Male / Female
        p.StartupLocation (1, -2917.58, -257.98, 52.9968, 1.0)  # Camp Narache
        p.SetFaction (6)            # PLAYER, Tauren

        p.AddSpell (670)            # Language: Taurane
        p.SetSkill (115, 300, 300)  # Language: Taurane

        CommonOneTimeRacialHorde (p)
        Reputation (p)

        #--- Racial ---
        p.AddSpell (20549)      # War Stomp
        p.AddSpell (20550)      # Endurance
        p.AddSpell (20551)      # Nature Resistance
        p.AddSpell (20552)      # Cultivation

#--------------------------------------------------------------------------------------------#
def Troll (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (21)
    p.SetAgility  (22)
    p.SetStamina  (21)
    p.SetIntellect(16)
    p.SetSpirit   (21)

    if oneTimeInit:
        p.PlayerModel (1478, 1479)  # Male / Female
        p.StartupLocation (1, -618.518, -4251.67, 38.718, 1.0)  # Valley of Trials
        p.SetFaction (9)            # PLAYER, Troll

        p.AddSpell (7341)           # Language: Trollish
        p.SetSkill (315, 300, 300)  # Language: Trollish

        CommonOneTimeRacialHorde (p)
        Reputation (p)
        # ActionButtons(p)

        #--- Racial ---
        p.AddSpell (20554)      # Berserking
        p.AddSpell (20555)      # Regeneration
        p.AddSpell (20557)      # Beast Slaying
        p.AddSpell (20558)      # Throwing Specialization

#--------------------------------------------------------------------------------------------#
def Undead (p, oneTimeInit):
    """ Add Racial spells, skills and bonuses
    """
    p.SetStrength (19)
    p.SetAgility  (18)
    p.SetStamina  (21)
    p.SetIntellect(18)
    p.SetSpirit   (25)
    
    #--- Resistances ---        
    p.ModifyShadowResist(10)   # Shadow Resistance 10

    if oneTimeInit:
        p.PlayerModel (57, 58)      # Male / Female
        p.StartupLocation (0, 1676.35, 1677.45, 121.67, 3.14)  # Deathknell
        p.SetFaction (5)            # PLAYER, Undead

        p.AddSpell (17737)          # Language: Gutterspeak
        p.SetSkill (673, 300, 300)  # Language: Gutterspeak

        CommonOneTimeRacialHorde (p)
        Reputation (p)

        #--- Racial ---
        p.AddSpell (5227)       # Underwater Breathing
        p.AddSpell (7744)       # Will of The Forsaken
        p.AddSpell (20577)      # Cannibalize
        p.AddSpell (20579)      # Shadow Resistance

#--------------------------------------------------------------------------------------------#
# ##############################  END RACES  ##################################################

# #############################################################################################
# ##
# ##  CLASS INIT FUNCTIONS
# ##
# #############################################################################################

    # ############################### START DRUID ############################# #

def Druid (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Druid"
    
    p.ModifyStrength (1)
    #p.ModifyAgility (0)
    #p.ModifyStamina (0)
    p.ModifyIntellect (2)
    p.ModifySpirit (2)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather

        #--- Class Skills ---
        p.SetSkill (574, 1, 1)      # Balance
        p.SetSkill (573, 1, 1)      # Restoration

        #--- Other ---
        p.AddSpell (227)            # Staves
        p.SetSkill (136, 1, 5)      # Staves
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (5176)           # Wrath Rank 1
        p.AddSpell (5185)           # Healing Touch Rank 1

        # ##### CUSTOM MODULES ###########   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ################################

        #--- Bag pack UNIFIED ---        
         
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water
        p.AddItemToSlot (25, 4536, MAX_COUNT_SUPPLY2)   # Shiny Red Apple
        
    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
        # ############################################################################

        if p.GetRace() == RACE_NIGHT_ELF:        # Night-Elf Race
        
            p.AddSpell (1180)           # Daggers
            p.SetSkill (173, 1, 5)      # Daggers
            
        #--- Initial Items ---        
            p.AddItemToSlot (3, 127, 1)     # Novice's  Shirt
            p.AddItemToSlot (4, 6123, 1)    # Novice's  Robe
            p.AddItemToSlot (6, 44, 1)      # Novice's pants
            p.AddItemToSlot (15, 3661, 1)   # Hand crafted staff

    # ############################################################################

        if p.GetRace() == RACE_TAUREN:        # Tauren Race
        
            p.AddSpell (198)           # Maces
            p.SetSkill (54, 1, 5)      # Maces
        
        #--- Initial Items ---
            p.AddItemToSlot (3, 127, 1)     # Novice's Shirt
            p.AddItemToSlot (4, 6139, 1)    # Novice's Robe
            p.AddItemToSlot (6, 6124, 1)    # Novice's Pants
            p.AddItemToSlot (7, 51, 1)      # Novice's Boots
            p.AddItemToSlot (15, 35, 1)     # Bent Staff
            
#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END DRUID #################################

#--------------------------------------------------------------------------------------------#

    # ############################### START HUNTER ##############################

def Hunter (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Hunter"

    #p.ModifyStrength (0)
    p.ModifyAgility (3)
    p.ModifyStamina (1)
    #p.ModifyIntellect (0)
    p.ModifySpirit (1)

    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather

        #--- Class Skills ---
        p.SetSkill (163, 1, 1)      # Marksmanship - Ranged Combat
        p.SetSkill (51, 1, 1)       # Survival - Outdoorsmanship

        #--- Other ---
        p.AddSpell (75)             # Auto Shot
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (2973)           # Raptor Strike Rank 1

        # ##### CUSTOM MODULES ###########   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ############################
        
        #--- Initial Items UNIFIED ---
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water

    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_NIGHT_ELF:            # Night Elf Race

            p.AddSpell (264)             # Bows
            p.SetSkill (45, 1, 5)        # Bows
            p.AddSpell (1180)            # Daggers
            p.SetSkill (173, 1, 5)       # Daggers

        #--- Initial Items ---
            p.AddItemToSlot (3, 148, 1)      # Rugged Trapper's Shirt
            p.AddItemToSlot (6, 147, 1)      # Rugged Trapper's Pants
            p.AddItemToSlot (7, 129, 1)      # Rugged Trapper's Boots
            p.AddItemToSlot (15, 2092, 1)    # Worn dagger
            p.AddItemToSlot (17, 2504, 1)    # Worn Shortbow

            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            p.AddItemToSlot (26, 2512, MAX_COUNT_AMMO)      # Rough Arrow
            p.SetAmmoSlot   (2512)                          # Loads Ammo to AMMO Slot on Character
            
            p.AddItemToSlot (19, 2101, 1)                   # Light Quiver

    # ############################################################################

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.AddSpell (196)             # Axes
            p.SetSkill (44, 1, 5)        # Axes
            p.AddSpell (266)             # Guns
            p.SetSkill (46, 6, 10)       # Guns

        #--- Initial Items ---
            p.AddItemToSlot (3, 148, 1)      # Rugged Trapper's Shirt
            p.AddItemToSlot (6, 147, 1)      # Rugged Trapper's Pants
            p.AddItemToSlot (7, 129, 1)      # Rugged Trapper's Boots
            p.AddItemToSlot (15, 37, 1)      # Worn Short Axe
            p.AddItemToSlot (17, 2508, 1)    # Old Blunderbuss

            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            p.AddItemToSlot (26, 2516, MAX_COUNT_AMMO)      # Light Shot
            p.SetAmmoSlot   (2516)                          # Loads Ammo to AMMO Slot on Character
            
            p.AddItemToSlot (19, 2102, 1)                   # Small Ammo Pouch

    # ############################################################################

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.AddSpell (196)             # Axes
            p.SetSkill (44, 6, 10)       # Axes
            p.AddSpell (264)             # Bows
            p.SetSkill (45, 1, 5)        # Bows

        #--- Initial Items ---
            p.AddItemToSlot (3, 127, 1)      # Trapper's Shirt
            p.AddItemToSlot (6, 6126, 1)     # Trapper's Pants
            p.AddItemToSlot (7, 6127, 1)     # Trapper's Boots
            p.AddItemToSlot (15, 37, 1)      # Worn Short Axe
            p.AddItemToSlot (17, 2504, 1)    # Worn Shortbow
            
            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            p.AddItemToSlot (26, 2512, MAX_COUNT_AMMO)      # Rough Arrow
            p.SetAmmoSlot   (2512)                          # Loads Ammo to AMMO Slot on Character
            
            p.AddItemToSlot (19, 2101, 1)                   # Light Quiver

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.AddSpell (196)             # Axes
            p.SetSkill (44, 1, 5)        # Axes
            p.AddSpell (264)             # Bows
            p.SetSkill (45, 1, 5)        # Bows

        #--- Initial Items ---
            p.AddItemToSlot (3, 127, 1)      # Trapper's Shirt
            p.AddItemToSlot (6, 6126, 1)     # Trapper's Pants
            p.AddItemToSlot (7, 6127, 1)     # Trapper's Boots
            p.AddItemToSlot (15, 37, 1)      # Worn Short Axe
            p.AddItemToSlot (17, 2504, 1)    # Worn Shortbow

            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap
            p.AddItemToSlot (26, 2512, MAX_COUNT_AMMO)      # Rough Arrow
            p.SetAmmoSlot   (2512)                          # Loads Ammo to AMMO Slot on Character
            
            p.AddItemToSlot (19, 2101, 1)                   # Light Quiver

    # ############################################################################

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

            p.AddSpell (196)             # Axes
            p.SetSkill (44, 1, 5)        # Axes
            p.AddSpell (266)             # Guns
            p.SetSkill (46, 1, 5)        # Guns

        #--- Initial Items ---
            p.AddItemToSlot (3, 127, 1)      # Trapper's Shirt
            p.AddItemToSlot (6, 6126, 1)     # Trapper's Pants
            p.AddItemToSlot (7, 6127, 1)     # Trapper's Boots
            p.AddItemToSlot (15, 37, 1)      # Worn Short Axe
            p.AddItemToSlot (17, 2508, 1)    # Old Blunderbuss
            
            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            p.AddItemToSlot (26, 2516, MAX_COUNT_AMMO)      # Light Shot
            p.SetAmmoSlot   (2516)                          # Loads Ammo to AMMO Slot on Character
            
            p.AddItemToSlot (19, 2102, 1)                   # Small Ammo Pouch

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END HUNTER #################################

#--------------------------------------------------------------------------------------------#

    # ############################### START MAGE ################################

def Mage (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Mage"
    
    #p.ModifyStrength (0)
    #p.ModifyAgility (0)
    #p.ModifyStamina (0)
    p.ModifyIntellect (3)
    p.ModifySpirit (2)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        #--- Class Skills ---
        p.SetSkill (6, 1, 1)        # Frost
        p.SetSkill (8, 1, 1)        # Fire

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (5009)           # Wands
        p.SetSkill (228, 1, 5)      # Wands
        p.AddSpell (5019)           # Shoot
        p.AddSpell (227)            # Staves
        p.SetSkill (136, 1, 5)      # Staves
        p.AddSpell (133)            # Fireball Rank 1
        p.AddSpell (168)            # Frost Armor Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ########################### #
        
        #--- Initial Items UNIFIED ---
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water
        
    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.AddItemToSlot (3, 6096, 1)    # Apprentice's Shirt
            p.AddItemToSlot (4, 56, 1)      # Apprentice's Robe
            p.AddItemToSlot (6, 1395, 1)    # Apprentice's Pants
            p.AddItemToSlot (7, 55, 1)      # Apprentice's Boots
            p.AddItemToSlot (15, 35, 1)     # Bent Staff

        #--- Initial Items ---
            p.AddItemToSlot (25, 2070, MAX_COUNT_SUPPLY2)   # Darnassian Bleu

    # ############################################################################

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.AddItemToSlot (3, 6096, 1)    # Apprentice's Shirt
            p.AddItemToSlot (4, 56, 1)      # Apprentice's Robe
            p.AddItemToSlot (6, 1395, 1)    # Apprentice's Pants
            p.AddItemToSlot (7, 55, 1)      # Apprentice's Boots
            p.AddItemToSlot (15, 35, 1)     # Bent Staff

        #--- Initial Items ---
            p.AddItemToSlot (25, 4536, MAX_COUNT_SUPPLY2)   # Shiny Red Apple

    # ############################################################################

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.AddItemToSlot (3, 6096, 1)    # Apprentice's Shirt
            p.AddItemToSlot (4, 56, 1)      # Apprentice's Robe
            p.AddItemToSlot (6, 1395, 1)    # Apprentice's Pants
            p.AddItemToSlot (7, 55, 1)      # Apprentice's Boots
            p.AddItemToSlot (15, 35, 1)     # Bent Staff

        #--- Initial Items ---
            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.AddItemToSlot (3, 6096, 1)    # Apprentice's Shirt
            p.AddItemToSlot (4, 56, 1)      # Apprentice's Robe
            p.AddItemToSlot (6, 1395, 1)    # Apprentice's Pants
            p.AddItemToSlot (7, 55, 1)      # Apprentice's Boots
            p.AddItemToSlot (15, 35, 1)     # Bent Staff

        #--- Initial Items ---
            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)     # Tough Jerky
            
#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END MAGE ###################################

#--------------------------------------------------------------------------------------------#

    # ############################### START PALADIN ############################

def Paladin (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Paladin"

    p.ModifyStrength (2)
    #p.ModifyAgility (0)
    p.ModifyStamina (2)
    #p.ModifyIntellect (0)
    p.ModifySpirit (1)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)

    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather
        p.AddSpell (8737)           # Mail
        p.SetSkill (413, 1, 1)      # Mail
        p.AddSpell (9116)           # Shield
        p.SetSkill (433, 1, 1)      # Shield

        #--- Class Skills ---
        p.SetSkill (594, 1, 1)      # Holy

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (107)            # Block
        p.AddSpell (635)            # Holy Light Rank 1
        p.AddSpell (21084)          # Seal of Righteousness Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ########################### #

        #--- Initial Items UNIFIED ---
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water

    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.AddSpell (198)            # Maces
            p.SetSkill (54, 6, 10)      # Maces 
            p.AddSpell (199)            # 2 Handed Maces
            p.SetSkill (160, 6, 10)     # 2 Handed Maces

        #--- Initial Items ---
            p.AddItemToSlot (3, 45, 1)      # Squire's shirt
            p.AddItemToSlot (6, 44, 1)      # Squire's pants
            p.AddItemToSlot (7, 43, 1)      # Squire's boots
            p.AddItemToSlot (15, 2361, 1)   # battleworn hammer

            p.AddItemToSlot (25, 2070, MAX_COUNT_SUPPLY2)   # Darnassian Bleu

    # ############################################################################

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.AddSpell (198)            # Maces
            p.SetSkill (54, 1, 5)       # Maces 
            p.AddSpell (199)            # 2 Handed Maces
            p.SetSkill (160, 1, 5)      # 2 Handed Maces

        #--- Initial Items ---
            p.AddItemToSlot (3, 6117, 1)    # Squire's shirt
            p.AddItemToSlot (6, 6118, 1)    # Squire's pants
            p.AddItemToSlot (7, 43, 1)      # Squire's boots
            p.AddItemToSlot (15, 2361, 1)   # battleworn hammer

            p.AddItemToSlot (25, 4540, MAX_COUNT_SUPPLY2)   # Tough Hunk of Bread

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END PALADIN ##############################

#--------------------------------------------------------------------------------------------#

    # ############################### START PRIEST #############################

def Priest (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """ 
    print "Python:: Init class: Priest"

    #p.ModifyStrength (0)
    #p.ModifyAgility (0)
    #p.ModifyStamina (0)
    p.ModifyIntellect (2)
    p.ModifySpirit (3)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)

    if oneTimeInit:
        #--- Class Skills ---
        p.SetSkill (56, 1, 1)       # Holy

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (5009)           # Wands
        p.SetSkill (228, 1, 5)      # Wands
        p.AddSpell (5019)           # Shoot
        p.AddSpell (2050)           # Lesser Heal Rank 1
        p.AddSpell (585)            # Smite Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ########################### # 

        #--- Start Items UNIFIED ---        
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water
        
    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.AddSpell (198)             # Maces
            p.SetSkill (54, 6, 10)       # Maces 

            p.AddItemToSlot (3, 53, 1)      # neophyte's shirt
            p.AddItemToSlot (4, 6098, 1)    # neophyte's robe
            p.AddItemToSlot (6, 52, 1)      # neophytes's pants
            p.AddItemToSlot (7, 51, 1)      # neophytes's boots
            p.AddItemToSlot (15, 36, 1)     # worn mace

        #--- Initial Items ---
            p.AddItemToSlot (25, 2070, MAX_COUNT_SUPPLY2)   # Darnassian Bleu

    # ############################################################################

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.AddSpell (198)             # Maces
            p.SetSkill (54, 1, 5)        # Maces 

            p.AddItemToSlot (3, 53, 1)      # neophyte's shirt
            p.AddItemToSlot (4, 6098, 1)    # neophyte's robe
            p.AddItemToSlot (6, 52, 1)      # neophytes's pants
            p.AddItemToSlot (7, 51, 1)      # neophytes's boots
            p.AddItemToSlot (15, 36, 1)     # worn mace

        #--- Initial Items ---
             
            p.AddItemToSlot (25, 2070, MAX_COUNT_SUPPLY2)   # Darnassian Bleu

    # ############################################################################

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.AddSpell (198)             # Maces
            p.SetSkill (54, 1, 5)        # Maces 

            p.AddItemToSlot (3, 53, 1)      # neophyte's shirt
            p.AddItemToSlot (4, 6098, 1)    # neophyte's robe
            p.AddItemToSlot (6, 52, 1)      # neophytes's pants
            p.AddItemToSlot (7, 51, 1)      # neophytes's boots
            p.AddItemToSlot (15, 36, 1)     # worn mace

        #--- Initial Items ---
            p.AddItemToSlot (25, 4540, MAX_COUNT_SUPPLY2)   # Tough Hunk of Bread

    # ############################################################################

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.AddSpell (198)             # Maces
            p.SetSkill (54, 1, 5)        # Maces 

            p.AddItemToSlot (3, 53, 1)      # neophyte's shirt
            p.AddItemToSlot (4, 6098, 1)    # neophyte's robe
            p.AddItemToSlot (6, 52, 1)      # neophytes's pants
            p.AddItemToSlot (7, 51, 1)      # neophytes's boots
            p.AddItemToSlot (15, 36, 1)     # worn mace

        #--- Initial Items ---
            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.AddSpell (198)             # Maces
            p.SetSkill (54, 1, 5)        # Maces 

            p.AddItemToSlot (3, 53, 1)      # neophyte's shirt
            p.AddItemToSlot (4, 6098, 1)    # neophyte's robe
            p.AddItemToSlot (6, 52, 1)      # neophytes's pants
            p.AddItemToSlot (7, 51, 1)      # neophytes's boots
            p.AddItemToSlot (15, 36, 1)     # worn mace

        #--- Initial Items ---
            p.AddItemToSlot (25, 4540, MAX_COUNT_SUPPLY2)   # Tough Hunk of Bread

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
            
    # ############################### END PRIEST ##############################

#--------------------------------------------------------------------------------------------#

    # ############################### START ROGUE #############################

def Rogue (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Rogue"

    p.ModifyStrength (1)
    p.ModifyAgility (3)
    p.ModifyStamina (1)
    #p.ModifyIntellect (0)
    #p.ModifySpirit (0)

    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather

        #--- Class Skills ---
        p.SetSkill (38, 1, 1)       # Combat
        p.SetSkill (253, 1, 1)      # Assasination

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (1180)           # Daggers
        p.SetSkill (173, 1, 5)      # Daggers
        p.AddSpell (2567)           # Thrown
        p.SetSkill (176, 1, 5)      # Thrown  
        p.AddSpell (2764)           # Throw
        p.AddSpell (1752)           # Sinister Strike Rank 1
        p.AddSpell (2098)           # Eviscerate Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ########################### #

    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.AddItemToSlot (3, 49, 1)      # Footpad's shirt
            p.AddItemToSlot (6, 48, 1)      # Footpad's Pants
            p.AddItemToSlot (7, 47, 1)      # Footpad's shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 2947, MAX_COUNT_WPN)  # Small Throwing Knife
            
        #--- Initial Items ---
            p.AddItemToSlot (24, 2070, MAX_COUNT_SUPPLY2)   # Darnassian Bleu

    # ############################################################################

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.AddItemToSlot (3, 49, 1)      # Footpad's shirt
            p.AddItemToSlot (6, 48, 1)      # Footpad's Pants
            p.AddItemToSlot (7, 47, 1)      # Footpad's shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 2947, MAX_COUNT_WPN)  # Small Throwing Knife

        #--- Initial Items ---
            p.AddItemToSlot (24, 4540, MAX_COUNT_SUPPLY2)   # Tough Hunk of Bread

    # ############################################################################

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.AddItemToSlot (3, 49, 1)      # Footpad's shirt
            p.AddItemToSlot (6, 48, 1)      # Footpad's Pants
            p.AddItemToSlot (7, 47, 1)      # Footpad's shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 3111, MAX_COUNT_WPN)  # Crude Throwing Axe

        #--- Initial Items ---
            p.AddItemToSlot (24, 4540, MAX_COUNT_SUPPLY2)    # Tough Hunk of Bread

    # ############################################################################

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.AddItemToSlot (3, 49, 1)      # Footpad's shirt
            p.AddItemToSlot (6, 48, 1)      # Footpad's Pants
            p.AddItemToSlot (7, 47, 1)      # Footpad's shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 2947, MAX_COUNT_WPN)  # Small Throwing Knife

        #--- Initial Items ---
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.AddItemToSlot (3, 2105, 1)    # Thug shirt
            p.AddItemToSlot (6, 120, 1)     # Thug Pants
            p.AddItemToSlot (7, 121, 1)     # Thug shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 2947, MAX_COUNT_WPN)  # Small Throwing Knife
            
        #--- Initial Items ---
            p.AddItemToSlot (24, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.AddItemToSlot (3, 2105, 1)    # Thug shirt
            p.AddItemToSlot (6, 120, 1)     # Thug Pants
            p.AddItemToSlot (7, 121, 1)     # Thug shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 3111, MAX_COUNT_WPN)  # Crude Throwing Axe
            
        #--- Initial Items ---
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.AddItemToSlot (3, 2105, 1)    # Thug shirt
            p.AddItemToSlot (6, 120, 1)     # Thug Pants
            p.AddItemToSlot (7, 121, 1)     # Thug shoes
            p.AddItemToSlot (15, 2092, 1)   # Worn dagger
            p.AddItemToSlot (17, 3111, MAX_COUNT_WPN)  # Crude Throwing Axe

        #--- Initial Items ---
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END ROGUE #############################

#--------------------------------------------------------------------------------------------#

    # ############################### START SHAMAN ##########################

def Shaman (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Shaman"

    p.ModifyStrength (1)
    #p.ModifyAgility (0)
    p.ModifyStamina (1)
    p.ModifyIntellect (1)
    p.ModifySpirit (2)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)

    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather
        p.AddSpell (9116)           # Shield
        p.SetSkill (433, 1, 1)      # Shield

        #--- Class Skills ---
        p.SetSkill (375, 1, 1)      # Elemental Combat
        p.SetSkill (374, 1, 1)      # Restoration

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (107)            # Block
        p.AddSpell (227)            # Staves
        p.SetSkill (136, 1, 5)      # Staves
        p.AddSpell (198)            # Maces
        p.SetSkill (54, 1, 5)       # Maces 
        p.AddSpell (403)            # Lightning Bolt Rank 1
        p.AddSpell (331)            # Healing Wave Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM) 
        # ########################### #
       
        #--- Start Outfit UNIFIED --- 
        p.AddItemToSlot (3, 154, 1)     # Primitive Mantle
        p.AddItemToSlot (6, 153, 1)     # Primitive Kilt
        p.AddItemToSlot (7, 51, 1)      # Novice's Boots
        p.AddItemToSlot (15, 36, 1)     # Worn Mace
      
        #--- Start Items UNIFIED ---        
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water
        
    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_ORC:        # Orc Race

        #--- Initial Items ---
            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

        #--- Initial Items ---
            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

        #--- Initial Items ---
            p.AddItemToSlot (26, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END SHAMAN ############################

#--------------------------------------------------------------------------------------------#

    # ############################### START WARLOCK #########################

def Warlock (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Warlock"

    #p.ModifyStrength (0)
    #p.ModifyAgility (0)
    p.ModifyStamina (1)
    p.ModifyIntellect (2)
    p.ModifySpirit (2)
    
    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        #--- Class Skills ---
        p.SetSkill (354, 1, 1)      # Demonology
        p.SetSkill (593, 1, 1)      # Destruction

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (5009)           # Wands
        p.SetSkill (228, 1, 5)      # Wands
        p.AddSpell (1180)           # Daggers
        p.SetSkill (173, 1, 5)      # Daggers
        p.AddSpell (5019)           # Shoot
        p.AddSpell (686)            # Shadow Bolt Rank 1
        p.AddSpell (687)            # Demon Skin Rank 1

        # ##### CUSTOM MODULES ########## #   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ########################### #

        #--- Start Items UNIFIED ---        
        p.AddItemToSlot (24, 159, MAX_COUNT_SUPPLY)     # Refreshing Spring Water

    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

        #--- Initial Items ---
            p.AddItemToSlot (3, 964, 1)     # acolyte's Shirt
            p.AddItemToSlot (4, 57, 1)      # acolyte's robe
            p.AddItemToSlot (6, 1396, 1)    # acolyte's pants
            p.AddItemToSlot (7, 59, 1)      # acolyte's shoes
            p.AddItemToSlot (15, 2092, 1)   # worn dagger

        #--- Initial Items ---
            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_GNOME:        # Gnome Race

        #--- Initial Items ---
            p.AddItemToSlot (3, 964, 1)     # acolyte's Shirt
            p.AddItemToSlot (4, 57, 1)      # acolyte's robe
            p.AddItemToSlot (6, 1396, 1)    # acolyte's pants
            p.AddItemToSlot (7, 59, 1)      # acolyte's shoes
            p.AddItemToSlot (15, 2092, 1)   # worn dagger

        #--- Initial Items ---
            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

        #--- Initial Items ---
            p.AddItemToSlot (3, 964, 1)     # acolyte's Shirt
            p.AddItemToSlot (4, 6129, 1)    # acolyte's robe
            p.AddItemToSlot (6, 1396, 1)    # acolyte's pants
            p.AddItemToSlot (7, 59, 1)      # acolyte's shoes
            p.AddItemToSlot (15, 2092, 1)   # worn dagger

        #--- Initial Items ---
            p.AddItemToSlot (25, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_ORC:        # Orc Race

        #--- Initial Items ---
            p.AddItemToSlot (3, 964, 1)     # acolyte's Shirt
            p.AddItemToSlot (4, 6129, 1)    # acolyte's robe
            p.AddItemToSlot (6, 1396, 1)    # acolyte's pants
            p.AddItemToSlot (7, 59, 1)      # acolyte's shoes
            p.AddItemToSlot (15, 2092, 1)   # worn dagger

            p.AddItemToSlot (25, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            
#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p) 
        
    # ############################### END WARLOCK ###########################
#--------------------------------------------------------------------------------------------#

    # ############################### START WARRIOR #########################

def Warrior (p, oneTimeInit):
    """ Add class-specific spells, skills and bonuses
    """
    print "Python:: Init class: Warrior"
    
    p.ModifyStrength (3)
    #p.ModifyAgility (0)
    p.ModifyStamina (2)
    #p.ModifyIntellect (0)
    #p.ModifySpirit (0)

    # Recalculates Health & Mana on Player Login/Creation
    Recalculate(p)
    
    if oneTimeInit:
        p.AddSpell (9077)           # Leather
        p.SetSkill (414, 1, 1)      # Leather
        p.AddSpell (8737)           # Mail
        p.SetSkill (413, 1, 1)      # Mail
        p.AddSpell (9116)           # Shield
        p.SetSkill (433, 1, 1)      # Shield

        #--- Class Skills ---
        p.SetSkill (26, 1, 1)       # Arms

        #--- Other ---
        p.SetSkill (95, 1, 5)       # Defense
        p.AddSpell (107)            # Block
        p.AddSpell (78)             # Heroic Strike
        p.AddSpell (2457)           # Battle stance
        
        # ##### CUSTOM MODULES ###########   
        CommonGift (p, GIFT)
        CommonWDDGCustomisation (p, WDDG_CUSTOM)
        # ################################
    
    # Definition of Race Specific Spells, Skills, Start Items for Specified Class
    # ############################################################################

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.AddSpell (201)            # Swords
            p.SetSkill (43, 6, 10)      # Swords
            p.AddSpell (198)            # Maces
            p.SetSkill (54, 6, 10)      # Maces 
            p.AddSpell (196)            # Axes
            p.SetSkill (44, 1, 5)       # Axes

        #--- Initial Items ---
            p.AddItemToSlot (3, 38, 1)      # recruit's shirt
            p.AddItemToSlot (6, 39, 1)      # recruit's pants
            p.AddItemToSlot (7, 40, 1)      # recruit's boots
            p.AddItemToSlot (15, 25, 1)     # worn short sword
            p.AddItemToSlot (16, 2362, 1)   # worn wooden shield
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            
    # ############################################################################

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.AddSpell (201)            # Swords
            p.SetSkill (43, 1, 5)       # Swords
            p.AddSpell (198)            # Maces
            p.SetSkill (54, 1, 5)       # Maces 
            p.AddSpell (1180)           # Daggers
            p.SetSkill (173, 1, 5)      # Daggers

        #--- Initial Items ---
            p.AddItemToSlot (3, 38, 1)      # recruit's shirt
            p.AddItemToSlot (6, 39, 1)      # recruit's pants
            p.AddItemToSlot (7, 40, 1)      # recruit's boots
            p.AddItemToSlot (15, 25, 1)     # worn short sword
            p.AddItemToSlot (16, 2362, 1)   # worn wooden shield
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            
    # ############################################################################

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.AddSpell (197)            # Two-Handed Axes
            p.SetSkill (172, 1, 5)      # Two-Handed Axes
            p.AddSpell (198)            # Maces
            p.SetSkill (54, 1, 5)       # Maces 
            p.AddSpell (196)            # Axes
            p.SetSkill (44, 1, 5)       # Axes

        #--- Initial Items ---
            p.AddItemToSlot (3, 38, 1)      # recruit's shirt
            p.AddItemToSlot (6, 39, 1)      # recruit's pants
            p.AddItemToSlot (7, 40, 1)      # recruit's boots
            p.AddItemToSlot (15, 12282, 1)  # Worn Battleaxe
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            
    # ############################################################################

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.AddSpell (201)            # Swords
            p.SetSkill (43, 1, 5)       # Swords
            p.AddSpell (198)            # Maces
            p.SetSkill (54, 1, 5)       # Maces 
            p.AddSpell (1180)           # Daggers
            p.SetSkill (173, 1, 5)      # Daggers

        #--- Initial Items ---
            p.AddItemToSlot (3, 38, 1)      # recruit's shirt
            p.AddItemToSlot (6, 39, 1)      # recruit's pants
            p.AddItemToSlot (7, 40, 1)      # recruit's boots
            p.AddItemToSlot (15, 25, 1)     # worn short sword
            p.AddItemToSlot (16, 2362, 1)   # worn wooden shield
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky
            
    # ############################################################################

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.AddSpell (201)            # Swords
            p.SetSkill (43, 1, 5)       # Swords
            p.AddSpell (202)            # Two-Handed Swords
            p.SetSkill (55, 1, 5)       # Two-Handed Swords
            p.AddSpell (1180)           # Daggers
            p.SetSkill (173, 1, 5)      # Daggers

        #--- Initial Items ---
            p.AddItemToSlot (3, 6125, 1)    # Brawler's Harness
            p.AddItemToSlot (6, 139, 1)     # Brawler's pants
            p.AddItemToSlot (7, 140, 1)     # Brawler's boots
            p.AddItemToSlot (15, 25, 1)     # worn short sword
            p.AddItemToSlot (16, 2362, 1)   # worn wooden shield
            
            p.AddItemToSlot (24, 4604, MAX_COUNT_SUPPLY2)   # Forest Mushroom Cap

    # ############################################################################

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.AddSpell (197)            # Two-Handed Axes
            p.SetSkill (172, 6, 10)     # Two-Handed Axes
            p.AddSpell (196)            # Axes
            p.SetSkill (44, 6, 10)      # Axes
            p.AddSpell (201)            # Swords
            p.SetSkill (43, 1, 5)       # Swords

        #--- Initial Items ---
            p.AddItemToSlot (3, 6125, 1)    # Brawler's Harness
            p.AddItemToSlot (6, 139, 1)     # Brawler's pants
            p.AddItemToSlot (7, 140, 1)     # Brawler's boots
            p.AddItemToSlot (15, 12282, 1)  # Worn Battleaxe
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.AddSpell (196)            # Axes
            p.SetSkill (44, 1, 5)       # Axes
            p.AddSpell (1180)           # Daggers
            p.SetSkill (173, 1, 5)      # Daggers
            p.AddSpell (2567)           # Thrown
            p.SetSkill (176, 6, 10)     # Thrown
            p.AddSpell (2764)           # Throw

        #--- Initial Items ---
            p.AddItemToSlot (3, 6125, 1)    # Brawler's Harness
            p.AddItemToSlot (6, 139, 1)     # Brawler's pants
            p.AddItemToSlot (7, 140, 1)     # Brawler's boots
            p.AddItemToSlot (15, 37, 1)     # Worn Short Axe
            p.AddItemToSlot (16, 2362, 1)   # worn wooden shield
            p.AddItemToSlot (17, 3111, MAX_COUNT_AMMO)  # Crude Throwing Axe
            
            p.AddItemToSlot (24, 117, MAX_COUNT_SUPPLY2)    # Tough Jerky

    # ############################################################################

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

            p.AddSpell (199)            # Two-Handed Maces
            p.SetSkill (160, 1, 5)      # Two-Handed Maces
            p.AddSpell (198)            # Maces
            p.SetSkill (54, 1, 5)       # Maces 
            p.AddSpell (196)            # Axes
            p.SetSkill (44, 1, 5)       # Axes

        #--- Initial Items ---
            p.AddItemToSlot (3, 6125, 1)    # Brawler's Harness
            p.AddItemToSlot (6, 139, 1)     # Brawler's pants
            p.AddItemToSlot (7, 140, 1)     # Brawler's boots
            p.AddItemToSlot (15, 2361, 1)   # Battleworn Hammer
            
            p.AddItemToSlot (25, 4540, MAX_COUNT_SUPPLY2)   # Tough Hunk of Bread

#--------------------------------------------------------------------------------------------#
        # Setting Action Buttons
        ActionButtons(p)
            
    # ############################### END WARRIOR ################################
        
# REPUTATION SETTINGS  ################################################################################
#--------------------------------------------------------------------------------------------#

# Note: All start values for Reputation are 0. Client has got defaults so we do not worry what initiall value shall be.
#          If Value for command SetReputation(Index,Value) is 17, then Reputation for the specified Area is activated for player. Like for 
#          Alliance all Cities got 17, and the same for Horde.

def Reputation (p):
    """ Initial settings for Reputation Values for every Race
    """
    print "Python:: Init Reputation"
    
    # ALLIANCE REPUTATION ################################################
    if  p.GetRace() == RACE_HUMAN or \
        p.GetRace() == RACE_DWARF or \
        p.GetRace() == RACE_NIGHT_ELF or \
        p.GetRace() == RACE_GNOME:
        # 1
        p.SetReputation(0, 2)
        p.SetReputationValue(0, 0)
        # 2
        p.SetReputation(1, 0)
        p.SetReputationValue(1, 0)
        # 3
        p.SetReputation(2, 2)
        p.SetReputationValue(2, 0)
        # 4
        p.SetReputation(3, 2)
        p.SetReputationValue(3, 0)    
        # 5
        p.SetReputation(4, 16)
        p.SetReputationValue(4, 0)    
        # 6
        p.SetReputation(5, 0)
        p.SetReputationValue(5, 0)
        # 7
        p.SetReputation(6, 2)
        p.SetReputationValue(6, 0)
        # 8
        p.SetReputation(7, 0)
        p.SetReputationValue(7, 0)
        # 9
        p.SetReputation(8, 16)
        p.SetReputationValue(8, 0)    
        # 10
        p.SetReputation(9, 0)
        p.SetReputationValue(9, 0)  
        # 11
        p.SetReputation(10, 8)
        p.SetReputationValue(10, 0)
        # 12
        p.SetReputation(11, 9)
        p.SetReputationValue(11, 0)
        # 13
        p.SetReputation(12, 14)
        p.SetReputationValue(12, 0)
        # 14
        p.SetReputation(13, 0)
        p.SetReputationValue(13, 0)    
        # Orgrimmar
        p.SetReputation(14, 6)
        p.SetReputationValue(14, 0)    
        # Darkspear Trolls
        p.SetReputation(15, 6)
        p.SetReputationValue(15, 0)
        # Thunder Bluff
        p.SetReputation(16, 6)
        p.SetReputationValue(16, 0)
        # Undercity
        p.SetReputation(17, 6)
        p.SetReputationValue(17, 0)
        # Gnomeregan Exiles
        p.SetReputation(18, 17)
        p.SetReputationValue(18, 0)
        # Stormwind
        p.SetReputation(19, 17)
        p.SetReputationValue(19, 0) 
        # Ironforge
        p.SetReputation(20, 17)
        p.SetReputationValue(20, 0)
        # Darnassus
        p.SetReputation (21, 17)
        p.SetReputationValue (21, 0)
        # 23
        p.SetReputation(22, 4)
        p.SetReputationValue(22, 0)
        # 24
        p.SetReputation(23, 4)
        p.SetReputationValue(23, 0)    
        # 25
        p.SetReputation(24, 4)
        p.SetReputationValue(24, 0)    
        # 26
        p.SetReputation(25, 4)
        p.SetReputationValue(25, 0)
        # 27
        p.SetReputation(26, 4)
        p.SetReputationValue(26, 0)
        # 28
        p.SetReputation(27, 0)
        p.SetReputationValue(27, 0)
        # 29
        p.SetReputation(28, 0)
        p.SetReputationValue(28, 0)    
        # 30
        p.SetReputation(29, 4)
        p.SetReputationValue(29, 0) 
        # 31
        p.SetReputation(30, 4)
        p.SetReputationValue(30, 0)
        # 32
        p.SetReputation(31, 4)
        p.SetReputationValue(31, 0)
        # 33
        p.SetReputation(32, 4)
        p.SetReputationValue(32, 0)
        # 34
        p.SetReputation(33, 4)
        p.SetReputationValue(33, 0)    
        # 35
        p.SetReputation(34, 4)
        p.SetReputationValue(34, 0)    
        # 36
        p.SetReputation(35, 2)
        p.SetReputationValue(35, 0)
        # 37
        p.SetReputation(36, 0)
        p.SetReputationValue(36, 0)
        # 38
        p.SetReputation(37, 0)
        p.SetReputationValue(37, 0)
        # 39
        p.SetReputation(38, 2)
        p.SetReputationValue(38, 0)    
        # 40
        p.SetReputation(39, 20)
        p.SetReputationValue(39, 0)   
        # 41
        p.SetReputation(40, 16)
        p.SetReputationValue(40, 0)
        # 42
        p.SetReputation(41, 2)
        p.SetReputationValue(41, 0)
        # 43
        p.SetReputation(42, 0)
        p.SetReputationValue(42, 0)
        # 44
        p.SetReputation(43, 16)
        p.SetReputationValue(43, 0)    
        # 45
        p.SetReputation(44, 16)
        p.SetReputationValue(44, 0)    
        # 46
        p.SetReputation(45, 16)
        p.SetReputationValue(45, 0)
        # 47
        p.SetReputation(46, 6)
        p.SetReputationValue(46, 0)
        # 48
        p.SetReputation(47, 24)
        p.SetReputationValue(47, 0)
        # 49
        p.SetReputation(48, 14)
        p.SetReputationValue(48, 0)    
        # 50
        p.SetReputation(49, 6)
        p.SetReputationValue(49, 0)  
        # 51
        p.SetReputation(50, 0)
        p.SetReputationValue(50, 0)
        # 52
        p.SetReputation(51, 0)
        p.SetReputationValue(51, 0)
        # 53
        p.SetReputation(52, 0)
        p.SetReputationValue(52, 0)
        # 54
        p.SetReputation(53, 0)
        p.SetReputationValue(53, 0)    
        # 55
        p.SetReputation(54, 0)
        p.SetReputationValue(54, 0)    
        # 56
        p.SetReputation(55, 0)
        p.SetReputationValue(55, 0)
        # 57
        p.SetReputation(56, 0)
        p.SetReputationValue(56, 0)
        # 58
        p.SetReputation(57, 0)
        p.SetReputationValue(57, 0)
        # 59
        p.SetReputation(58, 0)
        p.SetReputationValue(58, 0)    
        # 60
        p.SetReputation(59, 0)
        p.SetReputationValue(59, 0)  
        # 61
        p.SetReputation(60, 0)
        p.SetReputationValue(60, 0)
        # 62
        p.SetReputation(61, 0)
        p.SetReputationValue(61, 0)
        # 63
        p.SetReputation(62, 0)
        p.SetReputationValue(62, 0)
        # 64
        p.SetReputation(63, 0)
        p.SetReputationValue(63, 0)    

    # HORDE REPUTATION ################################################    
    if  p.GetRace() == RACE_ORC or \
        p.GetRace() == RACE_UNDEAD or \
        p.GetRace() == RACE_TAUREN or \
        p.GetRace() == RACE_TROLL:
        # 1
        p.SetReputation(0, 2)
        p.SetReputationValue(0, 0)
        # 2
        p.SetReputation(1, 0)
        p.SetReputationValue(1, 0)
        # 3
        p.SetReputation(2, 2)
        p.SetReputationValue(2, 0)
        # 4
        p.SetReputation(3, 2)
        p.SetReputationValue(3, 0)    
        # 5
        p.SetReputation(4, 16)
        p.SetReputationValue(4, 0)    
        # 6
        p.SetReputation(5, 0)
        p.SetReputationValue(5, 0)
        # 7
        p.SetReputation(6, 2)
        p.SetReputationValue(6, 0)
        # 8
        p.SetReputation(7, 0)
        p.SetReputationValue(7, 0)
        # 9
        p.SetReputation(8, 22)
        p.SetReputationValue(8, 0)    
        # 10
        p.SetReputation(9, 0)
        p.SetReputationValue(9, 0)  
        # 11
        p.SetReputation(10, 8)
        p.SetReputationValue(10, 0)
        # 12
        p.SetReputation(11, 14)
        p.SetReputationValue(11, 0)
        # 13
        p.SetReputation(12, 9)
        p.SetReputationValue(12, 0)
        # 14
        p.SetReputation(13, 0)
        p.SetReputationValue(13, 0)    
        # Orgrimmar
        p.SetReputation(14, 17)
        p.SetReputationValue(14, 0)    
        # Darkspear Trolls
        p.SetReputation(15, 17)
        p.SetReputationValue(15, 0)
        # Thunder Bluff
        p.SetReputation(16, 17)
        p.SetReputationValue(16, 0)
        # Undercity
        p.SetReputation(17, 17)
        p.SetReputationValue(17, 0)
        # Gnomeregan Exiles
        p.SetReputation(18, 6)
        p.SetReputationValue(18, 0)
        # Stormwind
        p.SetReputation(19, 6)
        p.SetReputationValue(19, 0) 
        # Ironforge
        p.SetReputation(20, 6)
        p.SetReputationValue(20, 0)
        # Darnassus
        p.SetReputation (21, 6)
        p.SetReputationValue (21, 0)
        # 23
        p.SetReputation(22, 4)
        p.SetReputationValue(22, 0)
        # 24
        p.SetReputation(23, 4)
        p.SetReputationValue(23, 0)    
        # 25
        p.SetReputation(24, 4)
        p.SetReputationValue(24, 0)    
        # 26
        p.SetReputation(25, 4)
        p.SetReputationValue(25, 0)
        # 27
        p.SetReputation(26, 4)
        p.SetReputationValue(26, 0)
        # 28
        p.SetReputation(27, 6)
        p.SetReputationValue(27, 0)
        # 29
        p.SetReputation(28, 0)
        p.SetReputationValue(28, 0)    
        # 30
        p.SetReputation(29, 4)
        p.SetReputationValue(29, 0) 
        # 31
        p.SetReputation(30, 4)
        p.SetReputationValue(30, 0)
        # 32
        p.SetReputation(31, 4)
        p.SetReputationValue(31, 0)
        # 33
        p.SetReputation(32, 4)
        p.SetReputationValue(32, 0)
        # 34
        p.SetReputation(33, 4)
        p.SetReputationValue(33, 0)    
        # 35
        p.SetReputation(34, 4)
        p.SetReputationValue(34, 0)    
        # 36
        p.SetReputation(35, 2)
        p.SetReputationValue(35, 0)
        # 37
        p.SetReputation(36, 0)
        p.SetReputationValue(36, 0)
        # 38
        p.SetReputation(37, 0)
        p.SetReputationValue(37, 0)
        # 39
        p.SetReputation(38, 0)
        p.SetReputationValue(38, 0)    
        # 40
        p.SetReputation(39, 20)
        p.SetReputationValue(39, 0)   
        # 41
        p.SetReputation(40, 2)
        p.SetReputationValue(40, 0)
        # 42
        p.SetReputation(41, 2)
        p.SetReputationValue(41, 0)
        # 43
        p.SetReputation(42, 0)
        p.SetReputationValue(42, 0)
        # 44
        p.SetReputation(43, 16)
        p.SetReputationValue(43, 0)    
        # 45
        p.SetReputation(44, 16)
        p.SetReputationValue(44, 0)    
        # 46
        p.SetReputation(45, 06)
        p.SetReputationValue(45, 0)
        # 47
        p.SetReputation(46, 16)
        p.SetReputationValue(46, 0)
        # 48
        p.SetReputation(47, 14)
        p.SetReputationValue(47, 0)
        # 49
        p.SetReputation(48, 24)
        p.SetReputationValue(48, 0)    
        # 50
        p.SetReputation(49, 16)
        p.SetReputationValue(49, 0)  
        # 51
        p.SetReputation(50, 16)
        p.SetReputationValue(50, 0)
        # 52
        p.SetReputation(51, 16)
        p.SetReputationValue(51, 0)
        # 53
        p.SetReputation(52, 16)
        p.SetReputationValue(52, 0)
        # 54
        p.SetReputation(53, 2)
        p.SetReputationValue(53, 0)    
        # 55
        p.SetReputation(54, 0)
        p.SetReputationValue(54, 0)    
        # 56
        p.SetReputation(55, 0)
        p.SetReputationValue(55, 0)
        # 57
        p.SetReputation(56, 0)
        p.SetReputationValue(56, 0)
        # 58
        p.SetReputation(57, 0)
        p.SetReputationValue(57, 0)
        # 59
        p.SetReputation(58, 0)
        p.SetReputationValue(58, 0)    
        # 60
        p.SetReputation(59, 0)
        p.SetReputationValue(59, 0)  
        # 61
        p.SetReputation(60, 0)
        p.SetReputationValue(60, 0)
        # 62
        p.SetReputation(61, 0)
        p.SetReputationValue(61, 0)
        # 63
        p.SetReputation(62, 0)
        p.SetReputationValue(62, 0)
        # 64
        p.SetReputation(63, 0)
        p.SetReputationValue(63, 0)  

#--------------------------------------------------------------------------------------------#

# #############################################################################################
# ##
# ##  HEALTH & MANA RECALCULATION
# ##  This module sets Initial Health/Mana values to Start Chars and also Recalculates Health/Mana/Rage/Energy on Player Login
# #############################################################################################

def Recalculate(p):

    print "PYTHON:: Setting Initial Values for Health/Mana/RAGE/ENERGY (1st Level) ..."

    # ############################### START DRUID  ##############################
    if p.GetClass() == CLASS_DRUID:

        if p.GetRace() == RACE_NIGHT_ELF:     # Night-Elf Race
            p.SetHealth     (53)
            p.SetMaxHealth  (53)
            p.SetMana       (100)
            p.SetMaxMana    (100)
            
        if p.GetRace() == RACE_TAUREN:        # Tauren Race
            p.SetHealth     (78)
            p.SetMaxHealth  (78)
            p.SetMana       (67)
            p.SetMaxMana    (67)

    # ############################### START HUNTER ##############################

    if p.GetClass() == CLASS_HUNTER:

        if p.GetRace() == RACE_NIGHT_ELF:    # Night Elf Race

            p.SetHealth     (46)
            p.SetMaxHealth  (46)
            p.SetMana       (85)
            p.SetMaxMana    (85)

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.SetHealth     (86)
            p.SetMaxHealth  (86)
            p.SetMana       (84)
            p.SetMaxMana    (84)

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.SetHealth     (76)
            p.SetMaxHealth  (76)
            p.SetMana       (82)
            p.SetMaxMana    (82)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (66)
            p.SetMaxHealth  (66)
            p.SetMana       (81)
            p.SetMaxMana    (81)

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

            p.SetHealth     (80)
            p.SetMaxHealth  (80)
            p.SetMana       (80)
            p.SetMaxMana    (80)

    # ############################### START MAGE ################################

    if p.GetClass() == CLASS_MAGE:

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (52)
            p.SetMaxHealth  (52)
            p.SetMana       (165)
            p.SetMaxMana    (165)

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.SetHealth     (51)
            p.SetMaxHealth  (51)
            p.SetMana       (225)
            p.SetMaxMana    (225)

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.SetHealth     (62)
            p.SetMaxHealth  (62)
            p.SetMana       (135)
            p.SetMaxMana    (135)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (62)
            p.SetMaxHealth  (62)
            p.SetMana       (119)
            p.SetMaxMana    (119)

    # ############################### START PALADIN ############################

    if p.GetClass() == CLASS_PALADIN:

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (58)
            p.SetMaxHealth  (58)
            p.SetMana       (80)
            p.SetMaxMana    (80)

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.SetHealth     (88)
            p.SetMaxHealth  (88)
            p.SetMana       (79)
            p.SetMaxMana    (79)

    # ############################### START PRIEST #############################
    
    if p.GetClass() == CLASS_PRIEST:

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (52)
            p.SetMaxHealth  (52)
            p.SetMana       (160)
            p.SetMaxMana    (160)

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.SetHealth     (51)
            p.SetMaxHealth  (51)
            p.SetMana       (160)
            p.SetMaxMana    (160)

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.SetHealth     (82)
            p.SetMaxHealth  (82)
            p.SetMana       (145)
            p.SetMaxMana    (145)

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.SetHealth     (62)
            p.SetMaxHealth  (62)
            p.SetMana       (130)
            p.SetMaxMana    (130)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (62)
            p.SetMaxHealth  (62)
            p.SetMana       (128)
            p.SetMaxMana    (128)
  
    # ############################### START ROGUE #############################

    if p.GetClass() == CLASS_ROGUE:
    
        p.SetMaxEnergy  (100)
        p.SetEnergy     (100)

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (55)
            p.SetMaxHealth  (55)

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.SetHealth     (45)
            p.SetMaxHealth  (45)

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.SetHealth     (85)
            p.SetMaxHealth  (85)

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.SetHealth     (45)
            p.SetMaxHealth  (45)

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.SetHealth     (65)
            p.SetMaxHealth  (65)

        if p.GetRace() == RACE_ORC:         # Orc Race

            p.SetHealth     (75)
            p.SetMaxHealth  (75)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (65)
            p.SetMaxHealth  (65)

    # ############################### START SHAMAN ##########################

    if p.GetClass() == CLASS_SHAMAN:

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.SetHealth     (77)
            p.SetMaxHealth  (77)
            p.SetMana       (73)
            p.SetMaxMana    (73)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (67)
            p.SetMaxHealth  (67)
            p.SetMana       (72)
            p.SetMaxMana    (72)

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

            p.SetHealth     (81)
            p.SetMaxHealth  (81)
            p.SetMana       (71)
            p.SetMaxMana    (71)

    # ############################### START WARLOCK #########################

    if p.GetClass() == CLASS_WARLOCK:

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (53)
            p.SetMaxHealth  (53)
            p.SetMana       (140)
            p.SetMaxMana    (140)

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.SetHealth     (43)
            p.SetMaxHealth  (43)
            p.SetMana       (200)
            p.SetMaxMana    (200)

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.SetHealth     (63)
            p.SetMaxHealth  (63)
            p.SetMana       (110)
            p.SetMaxMana    (110)

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.SetHealth     (73)
            p.SetMaxHealth  (73)
            p.SetMana       (109)
            p.SetMaxMana    (100)

    # ############################### START WARRIOR #########################

    if p.GetClass() == CLASS_WARRIOR:
    
        p.SetRage (0)
        p.SetMaxRage (1000)

        if p.GetRace() == RACE_HUMAN:        # Human Race

            p.SetHealth     (60)
            p.SetMaxHealth  (60)

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race

            p.SetHealth     (50)
            p.SetMaxHealth  (50)

        if p.GetRace() == RACE_DWARF:        # Dwarf Race

            p.SetHealth     (90)
            p.SetMaxHealth  (90)

        if p.GetRace() == RACE_GNOME:        # Gnome Race

            p.SetHealth     (50)
            p.SetMaxHealth  (50)

        if p.GetRace() == RACE_UNDEAD:        # Undead Race

            p.SetHealth     (70)
            p.SetMaxHealth  (70)

        if p.GetRace() == RACE_ORC:        # Orc Race

            p.SetHealth     (80)
            p.SetMaxHealth  (80)

        if p.GetRace() == RACE_TROLL:        # Troll Race

            p.SetHealth     (70)
            p.SetMaxHealth  (70)

        if p.GetRace() == RACE_TAUREN:        # Tauren Race

            p.SetHealth     (84)
            p.SetMaxHealth  (84)
            
# #############################################################################################
# ##
# ##  SETTING ACTION BUTTONS
# ##  
# #############################################################################################

def ioctlValue(i): 
    if i & 0x80000000: 
        i = -((i^0xffffffff)+1) 
    return i 

def ActionButtons(p):

    print "PYTHON:: Setting Action Buttons ..."
    
    # ## Common to all ACTION BUTTONS TEMPLATE

    data =[ 0x000019CB	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	,	0x00000000	,	0x00000000	,	0x00000000	,
            0x00000000	]						

    """
    Panel#1 72 - 83
    Panel#2 12 - 23
    
    Drink:
    Refreshing spring water (159)
    
    Food:
    Tough Jerky             (117)
    Darnassian Blue         (2070)
    Forest Mushroom Cap     (4604)
    Tough Hunk of Bread     (4540)
    Shiny Red Apple         (4536)
    """
    
    #p.SetActionButton(72, 6603) # Attack
    
    # SETTING FOOD
    if p.GetSlotByItemID(117)   != 0: data [11] =  0x75   + 0x80000000
    if p.GetSlotByItemID(2070)  != 0: data [11] =  0x816  + 0x80000000
    if p.GetSlotByItemID(4604)  != 0: data [11] =  0x11FC + 0x80000000
    if p.GetSlotByItemID(4540)  != 0: data [11] =  0x11BC + 0x80000000
    if p.GetSlotByItemID(4536)  != 0: data [11] =  0x11B8 + 0x80000000
    # SETTING DRINK
    if p.GetSlotByItemID(159)   != 0: data [10] =  0x9F   + 0x80000000
    
    # ############################### START DRUID  ##############################
    
    if p.GetClass() == CLASS_DRUID:
        data [1] = 0x00001438
        data [2] = 0x00001441

    # ############################### START HUNTER ##############################

    if p.GetClass() == CLASS_HUNTER:
        data [1] = 0x00000B9D
        data [2] = 0x0000004B

    # ############################### START MAGE ################################

    if p.GetClass() == CLASS_MAGE:
        data [1] = 0x00000085
        data [2] = 0x000000A8

    # ############################### START PALADIN ############################

    if p.GetClass() == CLASS_PALADIN:
        data [1] = 0x0000525C
        data [2] = 0x0000027B

    # ############################### START PRIEST #############################
    
    if p.GetClass() == CLASS_PRIEST:
        data [1] = 0x00000249
        data [2] = 0x00000802
  
    # ############################### START ROGUE #############################

    if p.GetClass() == CLASS_ROGUE:
        data [1] = 0x000006D8
        data [2] = 0x00000832
        data [3] = 0x00000ACC

    # ############################### START SHAMAN ##########################

    if p.GetClass() == CLASS_SHAMAN:
        data [1] = 0x00000193
        data [2] = 0x0000014B

    # ############################### START WARLOCK #########################

    if p.GetClass() == CLASS_WARLOCK:
        data [1] = 0x000002AE
        data [2] = 0x000002AF

    # ############################### START WARRIOR #########################

    if p.GetClass() == CLASS_WARRIOR:
        data [1] = 0x0000004E
    
    # Passing Data to Client
    for step in range(0,120):
        p.SetActionButton(step, ioctlValue(data[step]))
            
# #############################################################################################
# ##
# ##  RACE-COMMON & COMMON-CUSTOMISING FUNCTIONS
# ##
# #############################################################################################

# COMMON-CUSTOMISING #########################################################################
#--CommonGift------------------------------------------------------------------------------------------#

def CommonGift (p, GIFT):
    """ Gift to our Dearest Ladies
    """
    print "Python:: Init custom module COMMON GIFT"
    
    if GIFT:
        if p.GetGender() == GENDER_FEMALE:
            p.AddItemToSlot (38, 3421, 1)   # Simple Wildflowers

# COMMON-CUSTOMISING #########################################################################
#--CommonWDDGCustomisation-----------------------------------------------------------------------#

def CommonWDDGCustomisation (p, WDDG_CUSTOM):
    """ WDDG customised start items (WDDG Welcome Letter & Gift Voucher)
    """
    """ Attention !:
    Customised items shall be added starting from the end of bagpack (38 slot),
    currently items put starting from slot 37 with enabled CommonGift function,
    which puts Gift to slot 38. 
    All Races for different Classes have different number of start items.
    """ 
    print "Python:: Init custom module COMMON WDDG"

    if WDDG_CUSTOM:

        if p.GetRace() == RACE_HUMAN:        # Human Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14646, 1) # Northshire Gift Voucher - Human

        if p.GetRace() == RACE_ORC:        # Orc Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14649, 1) # Valley of Trials Gift Voucher - Orc Troll

        if p.GetRace() == RACE_DWARF:        # Dwarf Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14647, 1) # Coldridge Valley Gift Voucher - Dwarf Gnome

        if p.GetRace() == RACE_NIGHT_ELF:        # Night Elf Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14648, 1) # Shadowglen Gift Voucher - Elf

        if p.GetRace() == RACE_UNDEAD:        # Undead Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14651, 1) # Deathknell Gift Voucher - Undead

        if p.GetRace() == RACE_TAUREN:        # Tauren Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14650, 1) # Camp Narache Gift Voucher - Tauren

        if p.GetRace() == RACE_GNOME:        # Gnome Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14647, 1) # Coldridge Valley Gift Voucher - Dwarf Gnome

        if p.GetRace() == RACE_TROLL:        # Troll Race
            #p.AddItemToSlot (36, 56004, 1) # WDDG Welcome Letter
            p.AddItemToSlot (37, 14649, 1) # Valley of Trials Gift Voucher - Orc Troll

#--- EOF ---#