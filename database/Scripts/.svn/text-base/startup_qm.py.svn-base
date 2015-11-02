# This module is dedicated for Quest, Gossip, Item, GO, AreaTriggers processing and
# initialization.
#
# Author: <PavkaM>

from Ludmilla import *
import qm.def_npctext as dnpct
print ""
print " o Setting up QM system"

import qm.default_proc
reload (qm.default_proc)

#
# Note, these are the default QM handlers.
# If a specific handler was not found for a NPC,
# Item, GO or Trigger, the defaults are loaded.
# The Id = 0 is the default.
#

print "   -> Registering Default Modules"

import qm.default_proc
reload (qm.default_proc)

RegisterGossipModule      (0, "qm.default_proc", 0)
RegisterItemHandlerModule (0, "qm.default_proc", 0)
RegisterGOHandlerModule   (0, "qm.default_proc", 0)
RegisterAreaTriggerModule (0, "qm.default_proc", 0)

print "   -> Registering Innkeeper Modules"

import qm.innkeepers.default
reload (qm.innkeepers.default)

for i in (6791, 6807, 6930, 7714, 7731, 7736, 7737, 7744, 7733, 8931, 8999, 9356, 9501, 11103, 11106, 11116):
    RegisterGossipModule      (i, "qm.innkeepers.default", 0)

for i in (11118, 12196, 1247, 1464, 2352, 2388, 3934, 6272, 6727, 6734, 6735, 6737, 6738, 6739, 6741, 6746, 6790):
    RegisterGossipModule      (i, "qm.innkeepers.default", 0)

for i in (6736,  6806,  295,  6928,  6740,  6747,  6929,  511, 5688):
    RegisterGossipModule      (i, "qm.innkeepers.default", 0)



print "   -> Registering SpiritHealer Modules"

import qm.other.spirithealers
reload (qm.other.spirithealers)

for i in (6491, 2289, 2290, 2292, 2293, 2294, 2295, 2296, 2297):
    RegisterGossipModule      (i, "qm.other.spirithealers", 0)


print "   -> Registering Trainer Modules"

# --------------------------------------------------> Class Trainers

import qm.trainers.byclass.warrior
reload (qm.trainers.byclass.warrior)

for i in (911, 912, 913, 914, 985, 1229, 1901, 2119, 2131, 3041, 3042, 3043, 3059, 3063, 3153, 3169, \
          3353, 3354, 3408, 3593, 3598, 4087, 4089, 4593, 4594, 4595, 5113, 5114, 5479, 5480, 7315, 8141):
    RegisterGossipModule      (i, "qm.trainers.byclass.warrior", 0)

import qm.trainers.byclass.warlock
reload (qm.trainers.byclass.warlock)

for i in (459, 460, 461, 906, 988, 2126, 2127, 3156, 3172, 3324, 3325, 3326, 4563, 4564, 4565, 5171, \
          5172, 5173, 5495, 5496, 5612):
    RegisterGossipModule      (i, "qm.trainers.byclass.warlock", 0)


import qm.trainers.byclass.shaman
reload (qm.trainers.byclass.shaman)

for i in (986, 3030, 3031, 3032, 3062, 3066, 3157, 3173, 3344, 3403, 13417):
    RegisterGossipModule      (i, "qm.trainers.byclass.shaman", 0)


import qm.trainers.byclass.rogue
reload (qm.trainers.byclass.rogue)

for i in (915, 916, 917, 918, 1234, 1411, 2122, 2130, 3155, 3170, 3327, 3328, 3401, 3594, 3599, 4163, \
          4214, 4215, 4582, 4583, 4584, 5165, 5166, 5167, 13283):
    RegisterGossipModule      (i, "qm.trainers.byclass.rogue", 0)


import qm.trainers.byclass.priest
reload (qm.trainers.byclass.priest)

for i in (375, 376, 377, 837, 1226, 2123, 2129, 3044, 3045, 3046, 3595, 3600, 3706, 3707, 4090, 4091, 4092, 4606, 4607, \
          4608, 5141, 5142, 5143, 5484, 5489, 5994, 6014, 6018, 11397, 11401, 11406):
    RegisterGossipModule      (i, "qm.trainers.byclass.priest", 0)

import qm.trainers.byclass.paladin
reload (qm.trainers.byclass.paladin)

for i in (925, 926, 927, 928, 1232, 5147, 5148, 5149, 5491, 5492, 8140):
    RegisterGossipModule      (i, "qm.trainers.byclass.paladin", 0)

import qm.trainers.byclass.druid
reload (qm.trainers.byclass.druid)

for i in (3033, 3034, 3036, 3060, 3064, 3597, 3602, 4217, 4218, 4219, 5504, 5505, 5506, 8142, 9465, 12042):
    RegisterGossipModule      (i, "qm.trainers.byclass.druid", 0)


import qm.trainers.byclass.mage
reload (qm.trainers.byclass.mage)

for i in (198, 328, 331, 944, 1228, 2124, 2128, 3047, 3048, 3049, 4566, 4567, 4568, 5144, 5145, 5146, 5497, \
          5498, 5880, 5882, 5883, 5884, 5885, 7311, 7312):
    RegisterGossipModule      (i, "qm.trainers.byclass.mage", 0)


import qm.trainers.byclass.hunter
reload (qm.trainers.byclass.hunter)

for i in (895, 987, 1231, 1404, 3038, 3039, 3040, 3061, 3065, 3154, 3171, 3352, 3406, 3407, 3596, 3601, 3963, 4138, \
          4146, 4205, 5115, 5116, 5117, 5501, 5515, 5516, 5517, 8308, 10930):
    RegisterGossipModule      (i, "qm.trainers.byclass.hunter", 0)
    
# --------------------------------------------------> Tradeskill Trainers

import qm.trainers.bytradeskill.alchemy
reload (qm.trainers.bytradeskill.alchemy)

for i in (1215, 1246, 1386, 1470, 2132, 2391, 2837, 3009, 3184, 3347, 3603, 3964, 4160, 4609, 4611, 4900, 5177, 5499, 5500, 7948, 11041, 11042, 11044, 11046, 11047):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.alchemy", 0)
    
import qm.trainers.bytradeskill.blacksmithing
reload (qm.trainers.bytradeskill.blacksmithing)

for i in (514, 957, 1241, 1383, 2836, 2998, 3136, 3174, 3355, 3478, 3557, 4258, 4596, 4605, 5511, 6299, 10266, 10276, 10277, 10278):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.blacksmithing", 0)
    

import qm.trainers.bytradeskill.cooking
reload (qm.trainers.bytradeskill.cooking)

for i in (1355, 1382, 1430, 1699, 3026, 3067, 3087, 3399, 4210, 4552, 5159, 5482, 6286, 8306):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.cooking", 0)
    

import qm.trainers.bytradeskill.enchanting
reload (qm.trainers.bytradeskill.enchanting)

for i in (1317, 3011, 3345, 3606, 4213, 4616, 5157, 5695, 7949, 11065, 11066, 11067, 11068, 11070, 11071, 11072, 11073, 11074):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.enchanting", 0)

    
import qm.trainers.bytradeskill.engineering
reload (qm.trainers.bytradeskill.engineering)

for i in (1676, 1702, 2857, 3290, 3412, 3494, 4586, 5174, 5518, 5519, 7406, 7944, 8736, 10993, 11017, 11025, 11026, 11028, 11029, 11031, 11037):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.engineering", 0)


import qm.trainers.bytradeskill.firstaid
reload (qm.trainers.bytradeskill.firstaid)

for i in (2327, 2798, 3181, 3373, 4211, 4591, 5150, 5759, 5939, 5943, 6094):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.firstaid", 0)


import qm.trainers.bytradeskill.herbalism
reload (qm.trainers.bytradeskill.herbalism)

for i in (5502, 5566):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.herbalism", 0)    

import qm.trainers.bytradeskill.leatherworking
reload (qm.trainers.bytradeskill.leatherworking)

for i in (223, 1385, 1466, 1632, 3007, 3008, 3069, 3365, 3549, 3605, 3703, 3967, 4212, 4588, 5127, 5564, 5784, 5811, 7867, 7868, 7870, 7871, 11081, 11083, 11084, 11096, 11097, 11098):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.leatherworking", 0) 
    
import qm.trainers.bytradeskill.tailoring
reload (qm.trainers.bytradeskill.tailoring)

for i in (1103, 1300, 1346, 1703, 2399, 2627, 2855, 3004, 3363, 3484, 3523, 3704, 4159, 4193, 4576, 4578, 5153, 5567, 9584, 11048, 11049, 11050, 11051, 11052):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.tailoring", 0)

import qm.trainers.bytradeskill.mining
reload (qm.trainers.bytradeskill.mining)

for i in (1681, 5513):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.mining", 0) 

import qm.trainers.bytradeskill.fishing
reload (qm.trainers.bytradeskill.fishing)

for i in (1651, 1680, 1683, 2834, 3028, 3179, 3332, 3607, 4156, 4573, 5161, 5493, 5690, 5938, 5941, 12032, 14740):
    RegisterGossipModule      (i, "qm.trainers.bytradeskill.fishing", 0)

import qm.trainers.bytradeskill.skinning
reload (qm.trainers.bytradeskill.skinning)

RegisterGossipModule      (1292, "qm.trainers.bytradeskill.skinning", 0)     
    
# --------------------------------------------------> Riding Instructors

import qm.trainers.riding.raptor
reload (qm.trainers.riding.raptor)

RegisterGossipModule      (7953, "qm.trainers.riding.raptor", 0)

import qm.trainers.riding.nightsaber
reload (qm.trainers.riding.nightsaber)

RegisterGossipModule      (4753, "qm.trainers.riding.nightsaber", 0)

import qm.trainers.riding.undeadhorse
reload (qm.trainers.riding.undeadhorse)

RegisterGossipModule      (4773, "qm.trainers.riding.undeadhorse", 0)
    
import qm.trainers.riding.wolf
reload (qm.trainers.riding.wolf)

RegisterGossipModule      (4752, "qm.trainers.riding.wolf", 0)


import qm.trainers.riding.kodo
reload (qm.trainers.riding.kodo)

RegisterGossipModule      (3690, "qm.trainers.riding.kodo", 0)

import qm.trainers.riding.horse
reload (qm.trainers.riding.horse)

RegisterGossipModule      (4732, "qm.trainers.riding.horse", 0)

#import qm.trainers.riding.ram
#reload (qm.trainers.riding.ram)
#RegisterGossipModule      (4772, "qm.trainers.riding.ram", 0)


# --------------------------------------------------> Other Trainers

import qm.trainers.weapon
reload (qm.trainers.weapon)

for i in (11869, 13084, 11865, 2704, 11866, 11867, 11868, 11870):
    RegisterGossipModule      (i, "qm.trainers.weapon", 0)

import qm.trainers.demon
reload (qm.trainers.demon)

for i in (5749, 5750, 5753, 5815, 6027, 6328, 6382, 12776, 12807, 6376, 6374, 6373, 5520):
    RegisterGossipModule      (i, "qm.trainers.demon", 0)

import qm.trainers.portal
reload (qm.trainers.portal)

for i in (2485, 2489, 2492, 4165, 5957, 5958):
    RegisterGossipModule      (i, "qm.trainers.portal", 0)

import qm.trainers.pet
reload (qm.trainers.pet)

for i in (543, 2878, 2879, 3306, 3545, 3620, 3622, 3624, 3688, 4320, 10086, 10088, 10089, 10090):
    RegisterGossipModule      (i, "qm.trainers.pet", 0)     
    
# --------------------------------------------------> Mount Vendors

print "   -> Registering Vendor Modules"

import qm.vendors.mount.undeadhorse
reload (qm.vendors.mount.undeadhorse)

RegisterGossipModule      (4731, "qm.vendors.mount.undeadhorse", 0)

import qm.vendors.mount.tiger
reload (qm.vendors.mount.tiger)

RegisterGossipModule      (4730, "qm.vendors.mount.tiger", 0)

import qm.vendors.mount.wolf
reload (qm.vendors.mount.wolf)

RegisterGossipModule      (3362, "qm.vendors.mount.wolf", 0)

import qm.vendors.mount.raptor
reload (qm.vendors.mount.raptor)

RegisterGossipModule      (7952, "qm.vendors.mount.raptor", 0)

import qm.vendors.mount.kodo
reload (qm.vendors.mount.kodo)

RegisterGossipModule      (3685, "qm.vendors.mount.kodo", 0)


# --------------------------------------------------> Guardians

print "   -> Registering Guardians/DirectionGiver Modules"

import qm.guardians.ogrimmargrunt
reload (qm.guardians.ogrimmargrunt)

RegisterGossipModule      (3296, "qm.guardians.ogrimmargrunt", 0)


print "   -> Setting up Default NPC Texts"
dnpct.InitializeNPCTextTable()

print " o QM System ready to be used"
print ""

#--- END ---

