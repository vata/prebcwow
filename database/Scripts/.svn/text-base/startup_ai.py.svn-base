#
# This module is executed on Ludmilla startup
#

from Ludmilla import *

#----------------------------------------------------------
print "*** Setting up XP and DR modules..."

# XP Module
#from player.xp import *
print "XP module : SUCCESS"

# DR "Damage Reduction" Module
#from player.dr import *
print "DR module : SUCCESS"


#----------------------------------------------------------
print "*** Setting up creature specific AI scripts..."

import ai.kobold
reload (ai.kobold)
for i in (6, 40, 257, 475, 476, 1202, 1236):
    RegisterAIModule (i, "ai.kobold")

import ai.kobold_laborer
reload (ai.kobold_laborer)
RegisterAIModule (80, "ai.kobold_laborer")

import ai.defias
reload (ai.defias)
for i in (38, 94, 95, 116, 121):
    RegisterAIModule (i, "ai.defias")

import ai.peasant
reload (ai.peasant)
RegisterAIModule (11260, "ai.peasant")

#### STORMWIND ####

print "STORMWIND..."

import ai.stormwind_general_marcus
reload (ai.stormwind_general_marcus)
RegisterAIModule (466, "ai.stormwind_general_marcus")

import ai.stormwind_guard
reload (ai.stormwind_guard)
for i in (68, 1423, 1756, 1642):
    RegisterAIModule (i, "ai.stormwind_guard")

import ai.stormwind_renato_gallina
reload (ai.stormwind_renato_gallina)
RegisterAIModule (1432, "ai.stormwind_renato_gallina")

#### GROUP ####

import ai.gryphon_master
reload (ai.gryphon_master)
for i in (352, 523):
    RegisterAIModule (i, "ai.gryphon_master")

#--- END ---
