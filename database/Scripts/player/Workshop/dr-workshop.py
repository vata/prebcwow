# Author: Kosuha

from drw import *
import sys

# Output to screen ? (useful for Debug if CalcXP function crashes, to see on what values it crashed)
DEBUG =     0
# Print Matrix to file
FILE =      1

# Constants to correct output to output.txt
CTYPE =     1       # VICTIM_CREATURE_TYPE, NOT USED IN DR YET
CELITE =    0       # ELITE

# Scanned Levels Range
minLVL =    1      # Min LVL for Creature & Player
maxLVL =    60     # Max LVL for Creature & Player

if FILE: logfile = open('output_dr.txt', 'w')

#fsock = open('error.log', 'w') 
#sys.stderr = fsock
   
sys.stdout.write ("Started :")

# Writes X - coordinates
lst=""
for x in range (minLVL-1,maxLVL+1):
    lst+= str(x) + ","

result = lst + "\n"
if FILE: logfile.write(result)
lst=""

# Testing Module, Generator
for PLAYERLEVEL in range(minLVL,maxLVL+1):
    for MOBLEVEL in range(minLVL,maxLVL+1):
        for VICTIM_CREATURE_TYPE in range(1,11):
            for ELITE in range(0,5):
                if VICTIM_CREATURE_TYPE == CTYPE and ELITE == CELITE:
                    lst += str((CalcDR(MOBLEVEL, PLAYERLEVEL, ELITE))) + ","
            
                CalcDR(MOBLEVEL, PLAYERLEVEL, ELITE)    
                if DEBUG: print "PLVL= %s : MLVL= %s : CTYPE= %s : CELITE= %s" % (PLAYERLEVEL, MOBLEVEL, VICTIM_CREATURE_TYPE, ELITE) 
    
    sys.stdout.write (".")
    
    # Otputs results to OUTPUT.TXT
    if FILE:
        result = str(PLAYERLEVEL)+ "," + lst + "\n"
        logfile.write(result)
        lst=""

sys.stdout.write ("Finished.")
print
print "\n" + "DR module passed test successfully!"
print "\n" + "OUTPUT.TXT file is written for:"
#print "Player LVL:", minLVL, "-", maxLVL
print "Player LVL:              %s - %s" % (minLVL, maxLVL)
print "Creature LVL:            %s - %s" % (minLVL, maxLVL)
print "VICTIM_CREATURE_TYPE (DR IS NOT USING THIS YET) =   %s" % CTYPE
print "ELITE =                  %s" % CELITE
print
if FILE: logfile.close()
        
