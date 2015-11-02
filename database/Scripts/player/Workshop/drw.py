#from Ludmilla import *
from random import *
#import mysql

# Damage Reduction (DR) Calculation
#
# Made by: Cain Wong
#
# Modified by Cain on 25-09-2005
# - Remove trailing spaces
#
# Transferred to Python: KOSUHA
# - added DB connection, cleaned up code

def CalcDR (MOBLEVEL, PLAYERLEVEL, ELITE):

        # DEBUGGING ################################
        #
        # Logging to server screen (1 - Yes, 0 - No)
        LOG =       0
        
        #parser =    mysql.creature(ENTRY) # Initialise DB connection
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

        #MOBLEVEL =    victim.GetLevel()
        #PLAYERLEVEL =    self.GetLevel()
        #ENTRY =     victim.GetEntry()
        #ELITE =     victim.GetElite()
        ENTRY =     299
        #ELITE =     parser [21]
        #ARMOR =     self.GetArmor()
        ARMOR =     40

        if PLAYERLEVEL >= GMLVL: return 1.0

        if PLAYERLEVEL > MAXLVL: PLAYERLEVEL = MAXLVL

        DR = ARMOR / ((85.0 * MOBLEVEL) + ARMOR + 400.0)

        if DR > MAXDR: DR = MAXDR

        if ENTRY == 1: return DR

        if MOBLEVEL > MAXLVL: MOBLEVEL = MAXLVL

        EXTRA = PLAYERLEVEL - (MOBLEVEL + 1.0)

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
                  (ENTRY, MOBLEVEL, PLAYERLEVEL, DR)
        
        # Returns DR to Core
        return DR

# EOF ##