#from Ludmilla import *
import mysql
from random import *
from const_ai import *

# Made by: Cain Wong
#
# Modified by Cain on 25-09-2005 (Not Tested Yet)
# - Remove trailing spaces
# - Remove un-needed syntax
# - Change to more complex code
# - Sort some of the IF statements
# - Remove decimal point from constants which are used in TCL language previously (only)
# - ELITE using some new added constants in const_ai.py for more understandable purpose
# - Fix problem of calculation due to the wrong usage of data type
# - Reduce statements to increase performance
# - Rename some of the remarks
#
# Modified by Kosuha on 26-09-2005
# - Add new constant to speed up the lowering XP process
#
# Note from KOSUHA:
# To run it in TEST mode, open this file with Python's IDLE, then push F5
# and in opened window type "CalcXP()". Do not forget to change data for your
# MySQL server in MySQL.py module. Parameters for this function can be changed
# in constants section.
#
# To-do: to make this file look more clean, advance XP formula.
#
#def CalcXP(self, victim):    # For use in Server Environment

def CalcXP():
    # SET GLOBAL CONSTANTS #####################
    # Define Maximum Player Level
    MAXPLAYERLVL =          60

    # Random XP gains / losses in 5% amount of XP (1 - Yes, 0 - No)
    XPRAND =                1
    RANDXPPERC =            5 # %

    # Define XP Rate
    XPRATE =                0.90               # Overall XP rate
    HPXPRATE =              0.55               # XP rate per mob HP
    MPXPRATE =              0.20               # XP rate per mob MP
    DMGXPRATE =             0.35               # XP rate per mob damage point
    MAXLVLUP =              0                  # Maximum level-up allowed for each kill
    MAXXP =                 999999             # Maximum gain XP
    STARTXP =               10                 # Start XP value (to adjust initial XP value)
    ZEROXPLVLDIFF =         7                  # Level difference between Player LVL (higher) and Mob LVL (lower) after which XP = 0
    COEF =                  1.5                # Special coeficient for lowering XP after Mob LVL becomes lower than Player LVL
    XPACCELERATOR =         0                  # XP Rate Accelerator, must be ZERO for Player Level min 20 (used to avoid linear dependence)
    #MAXGAINXPDIST =        75                  # Maximum gain XP distance/radius 

    # DEBUGGING ################################
    #
    # Logging to server screen (1 - Yes, 0 - No)
    LOG =                   1
    #
    #ENTRY =                victim.GetEntry()   # For use in Server Environment
    ENTRY =                 299  # DEBUG ONLY
    # Connector to MySQL db to Creature_tmpl table
    parser =                mysql.creature(ENTRY)

    VICTIM_CREATURE_TYPE =  parser [19]
    #PLAYERLEVEL =          self.GetLevel()     # For use in Server Environment
    PLAYERLEVEL =           50 # DEBUG ONLY
    MOBLEVEL =              parser [6]
    ELITE =                 parser [21]
    MOBHEALTH =             parser [13]
    MOBMANA =               parser [14]
    MOBMINDAMAGE =          parser [8]
    MOBMAXDAMAGE =          parser [9]
    NPCFLAGS =              parser [16]

    # INITIAL CHECKS ############################

    if ENTRY == 6491 or \
       ENTRY == 1 or \
       ENTRY == 99999999 or \
       PLAYERLEVEL >= MAXPLAYERLVL or \
       VICTIM_CREATURE_TYPE == 8: return 0
       
    # XP NULLIFY
    if (PLAYERLEVEL - MOBLEVEL) >= ZEROXPLVLDIFF: return 0
    
    # XP RATE ACCELERATOR ########################
    if PLAYERLEVEL > 20 and PLAYERLEVEL < 40:   XPACCELERATOR = 0.05
    if PLAYERLEVEL > 40 and PLAYERLEVEL < 60:   XPACCELERATOR = 0.10
    if PLAYERLEVEL > 60 and PLAYERLEVEL < 80:   XPACCELERATOR = 0.15
    if PLAYERLEVEL > 80 and PLAYERLEVEL < 100:  XPACCELERATOR = 0.20
    XPRATE = XPRATE + XPACCELERATOR
    # ######################################

    # MODIFIER ACC. CREATURE ELITE
    DXP = randrange(MOBMINDAMAGE, MOBMAXDAMAGE + 1) * DMGXPRATE
    if      ELITE == CREATURE_ELITE_ELITE:      DXP *= 1.5
    elif    ELITE == CREATURE_ELITE_RAREELITE:  DXP *= 3
    elif    ELITE == CREATURE_ELITE_WORLDBOSS:  DXP *= 10
    elif    ELITE == CREATURE_ELITE_RARE:       DXP *= 7

    # XP CALCULATOR
    HPXP =  MOBHEALTH * HPXPRATE
    MPXP =  MOBMANA * MPXPRATE
    XP =    DXP + HPXP + MPXP + STARTXP

    # MODIFIER ACC. CREATURE TYPE
    if VICTIM_CREATURE_TYPE == 1 or \
       VICTIM_CREATURE_TYPE == 6 or \
       VICTIM_CREATURE_TYPE == 7: XP *= 1
       
    if VICTIM_CREATURE_TYPE == 2 or \
       VICTIM_CREATURE_TYPE == 5 or \
       VICTIM_CREATURE_TYPE == 9 or \
       VICTIM_CREATURE_TYPE == 10: XP *= 1.5
       
    if VICTIM_CREATURE_TYPE == 3 or \
       VICTIM_CREATURE_TYPE == 4: XP *= 1.2

    # XP LOWERING MODULE
    if MOBLEVEL >= PLAYERLEVEL: XP *= XPRATE
    else:
        if PLAYERLEVEL >= MAXPLAYERLVL: PLAYERLEVEL = MAXPLAYERLVL - 1
        PLAYDIFF = PLAYERLEVEL - MOBLEVEL
        MAXDIFF = MAXPLAYERLVL - MOBLEVEL
        if PLAYDIFF >= (ZEROXPLVLDIFF - 2): COEF = COEF * 1.5
        XP *= ((MAXDIFF - PLAYDIFF) * XPRATE / MAXDIFF)/COEF

    # Subtracts or adds random XP value in range of -5% to +4.99% of XP gained till this stage.
    RANDXPPERC = RANDXPPERC / 100
    if XPRAND: XP += uniform(XP * -RANDXPPERC, XP * RANDXPPERC)
    # ####################################################

    if XP > MAXXP: XP = MAXXP
    if XP <= 0: return 1
    
    # LVL-UP MODULE
    MAXLVLUP -= 1
    N = PLAYERLEVEL + MAXLVLUP
    A = N / 10
    X = N % 10

    # These statistics are extracted from WAD's Level-Up XP rate
    # Need to refer and change to the official stats
    if X == 1   : Cx = 0
    elif X == 2 : Cx = 0
    elif X == 3 : Cx = 0.5
    elif X == 4 : Cx = 1
    elif X == 5 : Cx = 2
    elif X == 6 : Cx = 3
    elif X == 7 : Cx = 4
    elif X == 8 : Cx = 5.5
    elif X == 9 : Cx = 7
    elif X == 0 : Cx = 9

    Tn = A * ( N - 1 )
    M = (N * ( A + 1 )) + Tn + Cx

    LVLUPXP = 400 * M
    if XP > LVLUPXP: XP = LVLUPXP

    # SERVER LOG
    if LOG:
        print "CalcXP:: | MID: %s | MLVL: %s | MTYP: %s | MELI: %s | PLVL: %s | XP: %s |" % \
              (ENTRY, MOBLEVEL, VICTIM_CREATURE_TYPE, ELITE, PLAYERLEVEL, int(XP))
    
    # Returns XP to Core
    return int(XP)

# EOF ##
