from Ludmilla import *
from random import *
from const_ai import *

""" This module is used for Functions which return Values to core.
"""

# CalcXP used to calculate XP given by killing Creature

def CalcXP(self, victim):    # For use in Server Environment

    # SET GLOBAL CONSTANTS #####################
    # Define Maximum Player Level
    MAXPLAYERLVL =          60

    # Random XP gains / losses in 5% amount of XP (1 - Yes, 0 - No)
    XPRAND =                1                  # Toggles ON/OFF (1/0) XP randomising function            
    RANDXPPERC =            5                  # Given in Percent (%)

    # Define XP Rate
    XPRATE =                1.00               # Overall XP rate
    DMGXPRATE =             0.35               # XP rate per mob damage point/used for ELITEs only
    MAXLVLUP =              0                  # Maximum level-up allowed for each kill
    MAXXP =                 10000              # Maximum gain XP
    XPACCELERATOR =         0                  # XP Rate Accelerator, must be ZERO for Player Level min 20 (used to avoid linear dependence)

    # DEBUGGING ################################
    #
    # Logging to server screen (1 - Yes, 0 - No)
    LOG =                   1
    #
    ENTRY =                 victim.GetEntry()

    VICTIM_CREATURE_TYPE =  victim.GetNpcType()
    PLAYERLEVEL =           self.GetLevel()
    MOBLEVEL =              victim.GetLevel()
    ELITE =                 victim.GetElite()
    MOBMINDAMAGE =          victim.GetMinDamage()
    MOBMAXDAMAGE =          victim.GetMaxDamage()
    NPCFLAGS =              victim.GetNpcFlags()

    # INITIAL CHECKS ############################

    if ENTRY == 6491 or \
       ENTRY == 1 or \
       ENTRY == 99999999 or \
       PLAYERLEVEL >= MAXPLAYERLVL or \
       VICTIM_CREATURE_TYPE == 8: return 0
    #XP NULLIFY
    if (PLAYERLEVEL - MOBLEVEL) >= 6: return 0
    
    # XP CALCULATOR  ############################
    if   MOBLEVEL == PLAYERLEVEL: XP = ((PLAYERLEVEL * 5) + 45)
    elif MOBLEVEL >  PLAYERLEVEL: XP = ((PLAYERLEVEL * 5) + 45) * (1.00 + 0.05 * (MOBLEVEL-PLAYERLEVEL))
    elif MOBLEVEL <  PLAYERLEVEL:
        # need gray level "g"
        if   PLAYERLEVEL <= 5:                       g = 0
        elif PLAYERLEVEL >= 6 and PLAYERLEVEL <= 39: g = PLAYERLEVEL - 5 - int(PLAYERLEVEL/10)
        elif PLAYERLEVEL >= 40:                      g = PLAYERLEVEL - 1 - int(PLAYERLEVEL/5)
        
        if PLAYERLEVEL > g:
                # need zero difference "z"
            if   PLAYERLEVEL <= 7:                       z = 5.0
            elif PLAYERLEVEL > 7   and PLAYERLEVEL < 10: z = 6.0
            elif PLAYERLEVEL > 9   and PLAYERLEVEL < 12: z = 7.0
            elif PLAYERLEVEL > 11  and PLAYERLEVEL < 15: z = 8.0
            elif PLAYERLEVEL > 14  and PLAYERLEVEL < 20: z = 9.0
            elif PLAYERLEVEL > 19  and PLAYERLEVEL < 40: z = 9.0 + float(PLAYERLEVEL/10)
            elif PLAYERLEVEL > 39:                       z = 5.0 + float(PLAYERLEVEL/5)
                
            XP = (PLAYERLEVEL * 5 + 45) * (1 - float((PLAYERLEVEL-MOBLEVEL)/z))
        else:
            # PLAYERLEVEL <= g, mob is Gray
            XP = 0
        
    # XP RATE ACCELERATOR ########################
    if PLAYERLEVEL > 20 and PLAYERLEVEL < 40:   XPACCELERATOR = 0.05
    if PLAYERLEVEL > 40 and PLAYERLEVEL < 60:   XPACCELERATOR = 0.10
    if PLAYERLEVEL > 60 and PLAYERLEVEL < 80:   XPACCELERATOR = 0.15
    if PLAYERLEVEL > 80 and PLAYERLEVEL < 100:  XPACCELERATOR = 0.20
    XPRATE += XPACCELERATOR
    # ######################################
        
    # MODIFIER ACC. CREATURE ELITE ############################
    if      ELITE != 0:                         DXP = randrange(MOBMINDAMAGE, MOBMAXDAMAGE + 1) * DMGXPRATE
    else:                                       DXP = 0
        
    if      ELITE == CREATURE_ELITE_ELITE:      DXP *= 1.5
    elif    ELITE == CREATURE_ELITE_RAREELITE:  DXP *= 3
    elif    ELITE == CREATURE_ELITE_WORLDBOSS:  DXP *= 10
    elif    ELITE == CREATURE_ELITE_RARE:       DXP *= 7
    XP += DXP
        
    # MODIFIER ACC. CREATURE TYPE ############################
    if VICTIM_CREATURE_TYPE == 1 or \
       VICTIM_CREATURE_TYPE == 6 or \
       VICTIM_CREATURE_TYPE == 7: XP *= 1
       
    if VICTIM_CREATURE_TYPE == 2 or \
       VICTIM_CREATURE_TYPE == 5 or \
       VICTIM_CREATURE_TYPE == 9 or \
       VICTIM_CREATURE_TYPE == 10: XP *= 1.4
       
    if VICTIM_CREATURE_TYPE == 3 or \
       VICTIM_CREATURE_TYPE == 4: XP *= 1.2
     
    # APPLYING XP RATE
    if MOBLEVEL > PLAYERLEVEL: XP *= XPRATE

    # Subtracts or adds random XP value in range of -5% to +4.99% of XP gained till this stage.
    if MOBLEVEL > 15:
        RANDXPPERC = RANDXPPERC / 100
        if XPRAND: XP += uniform(XP * -RANDXPPERC, XP * RANDXPPERC)
    # ####################################################

    if XP > MAXXP: XP = MAXXP
    if XP <= 0: return 0
    
    # LVL-UP MODULE ############################
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
    
    # Round XP
    XP = int(XP) 
    
    # SERVER LOG ############################
    if LOG:
        print "CalcXP:: | MID: %s | MLVL: %s | MTYP: %s | MELI: %s | PLVL: %s | XP: %s |" % \
              (ENTRY, MOBLEVEL, VICTIM_CREATURE_TYPE, ELITE, PLAYERLEVEL, XP)
    
    # Returns XP to Core ############################
    return XP

# ###########################################################################################
    
# CalcDR used to calculate DAMAGE REDUCTION (Debug mode, will later be moved to core)
def CalcDR (self, victim):

    # DEBUGGING ################################
    #
    # Logging to server screen (1 - Yes, 0 - No)
    LOG =       1
        
    # Define constant / limitation
    MINDR =     -4.00
    MAXDR =     1.00
    GMLVL =     200
    MAXLVL =    60
    NORMDR =    0.50
    BASEDR =    -0.25

    e1MAXDR =   1.00
    e2MAXDR =   1.50
    e3MAXDR =   2.50
    e4MAXDR =   2.00

    MOBLVL =    victim.GetLevel()
    PLRLVL =    self.GetLevel()
    ENTRY =     victim.GetEntry()
    ELITE =     victim.GetElite()
    ARMOR =     self.GetArmor()

    if PLRLVL >= GMLVL: return 1.0

    if PLRLVL > MAXLVL: PLRLVL = MAXLVL

    DR = ARMOR / ((85.0 * MOBLVL) + ARMOR + 400.0)

    if DR > MAXDR: DR = MAXDR

    if ENTRY == 1: return DR

    if MOBLVL > MAXLVL: MOBLVL = MAXLVL

    EXTRA = PLRLVL - (MOBLVL + 1.0)

    if EXTRA >= 0: EXTRA = -1

    if ELITE > 0:
        if ELITE == 1:      DR = DR + (EXTRA * (e1MAXDR / MAXLVL))
        elif ELITE == 2:    DR = DR + (EXTRA * (e2MAXDR / MAXLVL))
        elif ELITE == 3:    DR = DR + (EXTRA * (e3MAXDR / MAXLVL))
        elif ELITE == 4:    DR = DR + (EXTRA * (e4MAXDR / MAXLVL))
    else:                   DR = DR + (EXTRA * (NORMDR / MAXLVL))

    DR = DR + BASEDR

    if DR > MAXDR: return MAXDR
    if DR < MINDR: return MINDR

    # SERVER LOG
    if LOG:
        print "CalcDR:: | MOBID: %s | MOBLVL: %s | PLAYLVL: %s | DR: %s |" % \
              (ENTRY, MOBLVL, PLRLVL, DR)
        
    # Returns DR to Core
    return DR
    
# ###########################################################################################
    
   
# EOF ##
