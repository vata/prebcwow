#
# This module initializes the default NPCTexts for all NPCs.
# If a NPC has a default text please add it here
#
# Author: <PavkaM>

from Ludmilla import *
import const_ai as co
reload(co)
from random import *


def InitializeNPCTextTable():
    # Adding all default NPC texts ( Exported from WAD's creature.scp )
    
    RegisterDefaultNPCText(  223, 5295)  # Dan Golthas
    RegisterDefaultNPCText(  233, 2414)  # Farmer Saldean
    RegisterDefaultNPCText(  332, 5994)  # Master Mathias Shaw
    RegisterDefaultNPCText(  352, 1256)  # Dungar Longdrink
    RegisterDefaultNPCText(  440,  878)  # Blackrock Grunt
    RegisterDefaultNPCText(  460, 5693)  # Alamar Grimm
    RegisterDefaultNPCText(  491, 5010)  # Quartermaster Lewis
    RegisterDefaultNPCText(  523, 5009)  # Thor
    RegisterDefaultNPCText(  658, 4937)  # Sten Stoutarm
    RegisterDefaultNPCText(  716, 6535)  # Barnil Stonepot
    RegisterDefaultNPCText(  836, 1914)  # Durnan Furcutter
    RegisterDefaultNPCText(  837, 4436)  # Branstock Khalder
    RegisterDefaultNPCText(  895, 5000)  # Thorgas Grimson
    RegisterDefaultNPCText(  906, 2193)  # Maximillian Crowe
    RegisterDefaultNPCText(  912, 1215)  # Thran Khorman
    RegisterDefaultNPCText(  916, 4834)  # Solm Hargrin
    RegisterDefaultNPCText(  925, 3976)  # Brother Sammuel
    RegisterDefaultNPCText(  926, 3975)  # Bromos Grummner
    RegisterDefaultNPCText(  928, 3976)  # Lord Grayson Shadowbreaker
    RegisterDefaultNPCText(  944,  561)  # Marryk Nurribit
    RegisterDefaultNPCText(  963, 2287)  # Deputy Rainer
    RegisterDefaultNPCText( 1019,  923)  # Elder Razormaw
    RegisterDefaultNPCText( 1243, 4990)  # Hegnar Rumbleshot
    RegisterDefaultNPCText( 1247, 1853)  # Innkeeper Belm
    RegisterDefaultNPCText( 1284,  580)  # Archbishop Benedictus
    RegisterDefaultNPCText( 1300, 5418)  # Lawrence Schneider
    RegisterDefaultNPCText( 1309, 1231)  # Wynne Larson
    RegisterDefaultNPCText( 1310, 1231)  # Evan Larson
    RegisterDefaultNPCText( 1315, 1231)  # Allan Hafgan
    RegisterDefaultNPCText( 1317, 5207)  # Lucan Cordell
    RegisterDefaultNPCText( 1318, 1231)  # Jessara Cordell
    RegisterDefaultNPCText( 1319, 1238)  # Bryan Cross
    RegisterDefaultNPCText( 1325, 1258)  # Jasper Fel
    RegisterDefaultNPCText( 1340, 2289)  # Mountaineer Kadrell
    RegisterDefaultNPCText( 1346, 5564)  # Georgio Bolero
    RegisterDefaultNPCText( 1347, 1234)  # Alexandra Bolero
    RegisterDefaultNPCText( 1351, 1242)  # Brother Cassius
    RegisterDefaultNPCText( 1368, 1231)  # Justin
    RegisterDefaultNPCText( 1382, 7017)  # Mudduk
    RegisterDefaultNPCText( 1387, 5561)  # Thysta
    RegisterDefaultNPCText( 1416, 7055)  # Grimand Elmore
    RegisterDefaultNPCText( 1445, 1250)  # Jesse Halloran
    RegisterDefaultNPCText( 1465, 1231)  # Drac Roughcut
    RegisterDefaultNPCText( 1470, 5693)  # Ghak Healtouch
    RegisterDefaultNPCText( 1496, 4093)  # Deathguard Dillinger
    RegisterDefaultNPCText( 1569, 4934)  # Shadow Priest Sarvis
    RegisterDefaultNPCText( 1572, 5580)  # Thorgrum Borrelson
    RegisterDefaultNPCText( 1573, 5582)  # Gryth Thurden
    RegisterDefaultNPCText( 1632, 5258)  # Adele Fielder
    RegisterDefaultNPCText( 1652, 4097)  # Deathguard Burgess
    RegisterDefaultNPCText( 1694, 4253)  # Loslor Rudge
    RegisterDefaultNPCText( 1699, 7021)  # Gremlock Pilsnor
    RegisterDefaultNPCText( 1703, 4999)  # Uthrar Threx
    RegisterDefaultNPCText( 1738, 4097)  # Deathguard Terrence
    RegisterDefaultNPCText( 1742, 4096)  # Deathguard Bartholomew
    RegisterDefaultNPCText( 1743, 4074)  # Deathguard Lawrence
    RegisterDefaultNPCText( 1744, 4097)  # Deathguard Mort
    RegisterDefaultNPCText( 1746, 4097)  # Deathguard Cyrus
    RegisterDefaultNPCText( 2079, 4936)  # Conservator Ilthalaine
    RegisterDefaultNPCText( 2119, 1219)  # Dannal Stern
    RegisterDefaultNPCText( 2122,  581)  # David Trias
    RegisterDefaultNPCText( 2123, 4442)  # Dark Cleric Duesten
    RegisterDefaultNPCText( 2124,  562)  # Isabella
    RegisterDefaultNPCText( 2126, 5720)  # Maximillion
    RegisterDefaultNPCText( 2127, 5719)  # Rupert Boch
    RegisterDefaultNPCText( 2128,  563)  # Cain Firesong
    RegisterDefaultNPCText( 2129, 4439)  # Dark Cleric Beryl
    RegisterDefaultNPCText( 2130, 4796)  # Marion Call
    RegisterDefaultNPCText( 2131, 4984)  # Austil de Mon
    RegisterDefaultNPCText( 2132, 5043)  # Carolai Anise
    RegisterDefaultNPCText( 2169, 6957)  # Blackwood Totemic
    RegisterDefaultNPCText( 2209, 4074)  # Deathguard Gavin
    RegisterDefaultNPCText( 2210, 4097)  # Deathguard Royann
    RegisterDefaultNPCText( 2226, 5453)  # Karos Razok
    RegisterDefaultNPCText( 2327, 1220)  # Shaina Fuller
    RegisterDefaultNPCText( 2352,  820)  # Innkeeper Anderson
    RegisterDefaultNPCText( 2388,  821)  # Innkeeper Shay
    RegisterDefaultNPCText( 2393, 6595)  # Christoph Jeffcoat
    RegisterDefaultNPCText( 2425, 4476)  # Varimathras
    RegisterDefaultNPCText( 2489, 5168)  # Milstaff Stormeye
    RegisterDefaultNPCText( 2492, 5885)  # Lexington Mortaim
    RegisterDefaultNPCText( 2704, 6277)  # Hanashi
    RegisterDefaultNPCText( 2788, 3293)  # Apprentice Kryten
    RegisterDefaultNPCText( 2798, 7024)  # Pand Stonebinder
    RegisterDefaultNPCText( 2834, 6793)  # Myizz Luckycatch
    RegisterDefaultNPCText( 2858, 5454)  # Gringer
    RegisterDefaultNPCText( 2859, 5479)  # Gyll
    RegisterDefaultNPCText( 2916, 6383)  # Historian Karnik
    RegisterDefaultNPCText( 2941, 7122)  # Lanie Reed
    RegisterDefaultNPCText( 2980, 4935)  # Grull Hawkwind
    RegisterDefaultNPCText( 2995, 5500)  # Tal
    RegisterDefaultNPCText( 3009, 5080)  # Bena Winterhoof
    RegisterDefaultNPCText( 3022, 4056)  # Sunn Ragetotem
    RegisterDefaultNPCText( 3031, 5005)  # Tigor Skychaser
    RegisterDefaultNPCText( 3041, 1218)  # Torm Ragetotem
    RegisterDefaultNPCText( 3043, 1218)  # Ker Ragetotem
    RegisterDefaultNPCText( 3045, 4439)  # Malakai Cross
    RegisterDefaultNPCText( 3052,  523)  # Skorn Whitecloud
    RegisterDefaultNPCText( 3057, 7013)  # Cairne Bloodhoof
    RegisterDefaultNPCText( 3059, 4973)  # Harutt Thunderhorn
    RegisterDefaultNPCText( 3060, 5717)  # Gart Mistrunner
    RegisterDefaultNPCText( 3061, 4997)  # Lanka Farshot
    RegisterDefaultNPCText( 3062, 5006)  # Meela Dawnstrider
    RegisterDefaultNPCText( 3063, 1218)  # Krang Stonehoof
    RegisterDefaultNPCText( 3064, 4785)  # Gennia Runetotem
    RegisterDefaultNPCText( 3065, 4998)  # Yaw Sharpmane
    RegisterDefaultNPCText( 3144, 3573)  # Eitrigg
    RegisterDefaultNPCText( 3149, 3133)  # Nez'raz
    RegisterDefaultNPCText( 3150, 2753)  # Hin Denburg
    RegisterDefaultNPCText( 3153, 1040)  # Frang
    RegisterDefaultNPCText( 3156, 5715)  # Nartok
    RegisterDefaultNPCText( 3171, 4888)  # Thotar
    RegisterDefaultNPCText( 3174, 3409)  # Dwukk
    RegisterDefaultNPCText( 3184, 5034)  # Miao'zan
    RegisterDefaultNPCText( 3212, 4072)  # Brave Ironhorn
    RegisterDefaultNPCText( 3216, 4513)  # Neeru Fireblade
    RegisterDefaultNPCText( 3274, 5495)  # Kolkar Pack Runner
    RegisterDefaultNPCText( 3305, 7123)  # Grisha
    RegisterDefaultNPCText( 3306, 5838)  # Keldas
    RegisterDefaultNPCText( 3309, 2275)  # Karus
    RegisterDefaultNPCText( 3310, 5516)  # Doras
    RegisterDefaultNPCText( 3314, 5516)  # Urtharo
    RegisterDefaultNPCText( 3315, 5005)  # Tor'phan
    RegisterDefaultNPCText( 3318, 2275)  # Koma
    RegisterDefaultNPCText( 3320, 2275)  # Soran
    RegisterDefaultNPCText( 3322, 2275)  # Kaja
    RegisterDefaultNPCText( 3332, 5793)  # Lumak
    RegisterDefaultNPCText( 3333, 4879)  # Shankys
    RegisterDefaultNPCText( 3341,  942)  # Gann Stonespire
    RegisterDefaultNPCText( 3342, 2275)  # Shan'ti
    RegisterDefaultNPCText( 3344, 5005)  # Kardris Dreamseeker
    RegisterDefaultNPCText( 3345, 2280)  # Godan
    RegisterDefaultNPCText( 3352, 4866)  # Ormak Grimshot
    RegisterDefaultNPCText( 3355, 1606)  # Saru Steelfury
    RegisterDefaultNPCText( 3362, 3893)  # Ogunaro Wolfrunner
    RegisterDefaultNPCText( 3365, 5354)  # Karolek
    RegisterDefaultNPCText( 3368, 5005)  # Borstan
    RegisterDefaultNPCText( 3387, 2275)  # Jorn Skyseer
    RegisterDefaultNPCText( 3412, 5158)  # Nogg
    RegisterDefaultNPCText( 3413, 1571)  # Sovik
    RegisterDefaultNPCText( 3428,  519)  # Korran
    RegisterDefaultNPCText( 3429, 3559)  # Thork
    RegisterDefaultNPCText( 3430, 3658)  # Mangletooth
    RegisterDefaultNPCText( 3431, 3334)  # Grenthar
    RegisterDefaultNPCText( 3432, 3553)  # Mankrik
    RegisterDefaultNPCText( 3448, 4933)  # Tonga Runetotem
    RegisterDefaultNPCText( 3457, 5516)  # Razormane Stalker
    RegisterDefaultNPCText( 3478, 3471)  # Traugh
    RegisterDefaultNPCText( 3483, 5496)  # Jahan Hawkwing
    RegisterDefaultNPCText( 3484, 5440)  # Kil'hala
    RegisterDefaultNPCText( 3489, 5515)  # Zargh
    RegisterDefaultNPCText( 3494, 5696)  # Tinkerwiz
    RegisterDefaultNPCText( 3516, 2285)  # Arch Druid Fandral Staghelm
    RegisterDefaultNPCText( 3520, 1258)  # Ol' Emma
    RegisterDefaultNPCText( 3523, 5431)  # Bowen Brisboise
    RegisterDefaultNPCText( 3549, 5283)  # Shelene Rhobart
    RegisterDefaultNPCText( 3557, 3418)  # Guillaume Sorouy
    RegisterDefaultNPCText( 3593, 5725)  # Alyissia
    RegisterDefaultNPCText( 3594, 4795)  # Frahun Shadewhisper
    RegisterDefaultNPCText( 3595, 4438)  # Shanda
    RegisterDefaultNPCText( 3596, 4863)  # Ayanna Everstride
    RegisterDefaultNPCText( 3597, 4783)  # Mardant Strongoak
    RegisterDefaultNPCText( 3598, 5725)  # Kyra Windblade
    RegisterDefaultNPCText( 3599,  934)  # Jannok Breezesong
    RegisterDefaultNPCText( 3605, 5264)  # Nadyia Maneweaver
    RegisterDefaultNPCText( 3606, 5190)  # Alanna Raveneye
    RegisterDefaultNPCText( 3615, 5495)  # Devrak
    RegisterDefaultNPCText( 3620, 5838)  # Harruk
    RegisterDefaultNPCText( 3622, 5839)  # Grokor
    RegisterDefaultNPCText( 3624, 5839)  # Zudd
    RegisterDefaultNPCText( 3685, 4862)  # Harb Clawhoof
    RegisterDefaultNPCText( 3688, 5839)  # Reban Freerunner
    RegisterDefaultNPCText( 3690, 4874)  # Kar Stormsinger
    RegisterDefaultNPCText( 3691, 6553)  # Raene Wolfrunner
    RegisterDefaultNPCText( 3838, 5474)  # Vesprystus
    RegisterDefaultNPCText( 3841, 5473)  # Caylais Moonfeather
    RegisterDefaultNPCText( 3850,  798)  # Sorcerer Ashcrombe
    RegisterDefaultNPCText( 3934, 7177)  # Innkeeper Boorand Plainswind
    RegisterDefaultNPCText( 3967, 5364)  # Aayndia Floralwind
    RegisterDefaultNPCText( 4143, 4795)  # Sparkleshell Snapper
    RegisterDefaultNPCText( 4146, 4863)  # Jocaste
    RegisterDefaultNPCText( 4151, 4795)  # Saltstone Crystalhide
    RegisterDefaultNPCText( 4159, 5541)  # Me'lynn
    RegisterDefaultNPCText( 4160, 5098)  # Ainethil
    RegisterDefaultNPCText( 4200, 5476)  # Laird
    RegisterDefaultNPCText( 4202, 5473)  # Gerenzo Wrenchwhistle
    RegisterDefaultNPCText( 4211, 7028)  # Dannelor
    RegisterDefaultNPCText( 4256, 5581)  # Golnir Bouldertoe
    RegisterDefaultNPCText( 4314, 7175)  # Gorkas
    RegisterDefaultNPCText( 4374, 5474)  # Strashaz Hydra
    RegisterDefaultNPCText( 4419,  932)  # Race Master Kronkrider
    RegisterDefaultNPCText( 4429,  778)  # Goblin Pit Crewman
    RegisterDefaultNPCText( 4430,  780)  # Gnome Pit Crewman
    RegisterDefaultNPCText( 4488, 5821)  # Parqual Fintallas
    RegisterDefaultNPCText( 4489, 5820)  # Braug Dimspirit
    RegisterDefaultNPCText( 4551, 5454)  # Michael Garrett
    RegisterDefaultNPCText( 4552, 7019)  # Eunice Burch
    RegisterDefaultNPCText( 4556, 5455)  # Gordon Wendham
    RegisterDefaultNPCText( 4559, 5582)  # Timothy Weldon
    RegisterDefaultNPCText( 4563, 5674)  # Kaal Soulreaper
    RegisterDefaultNPCText( 4564, 5719)  # Luther Pickman
    RegisterDefaultNPCText( 4565, 5674)  # Richard Kerwin
    RegisterDefaultNPCText( 4566,  563)  # Kaelystia Hatebringer
    RegisterDefaultNPCText( 4567,  563)  # Pierce Shackleton
    RegisterDefaultNPCText( 4568,  563)  # Anastasia Hartwell
    RegisterDefaultNPCText( 4573, 6961)  # Armand Cromwell
    RegisterDefaultNPCText( 4576, 5566)  # Josef Gregorian
    RegisterDefaultNPCText( 4578, 5918)  # Josephine Lister
    RegisterDefaultNPCText( 4582, 4796)  # Carolyn Ward
    RegisterDefaultNPCText( 4583, 4796)  # Miles Dexter
    RegisterDefaultNPCText( 4584, 4796)  # Gregory Charles
    RegisterDefaultNPCText( 4586, 5139)  # Graham Van Talen
    RegisterDefaultNPCText( 4591, 7025)  # Mary Edras
    RegisterDefaultNPCText( 4593, 4984)  # Christoph Walker
    RegisterDefaultNPCText( 4594, 4984)  # Angela Curthas
    RegisterDefaultNPCText( 4595, 4984)  # Baltus Fowler
    RegisterDefaultNPCText( 4599, 4476)  # Sarah Killian
    RegisterDefaultNPCText( 4606, 4439)  # Aelthalyste
    RegisterDefaultNPCText( 4607, 4439)  # Father Lankester
    RegisterDefaultNPCText( 4608, 4439)  # Father Lazarus
    RegisterDefaultNPCText( 4609, 5090)  # Doctor Marsh
    RegisterDefaultNPCText( 4611, 5099)  # Doctor Herbert Halsey
    RegisterDefaultNPCText( 4613, 6159)  # Christopher Drakul
    RegisterDefaultNPCText( 4616, 5228)  # Lavinia Crowe
    RegisterDefaultNPCText( 4631, 5753)  # Wharfmaster Lozgil
    RegisterDefaultNPCText( 4702, 4449)  # Ancient Kodo
    RegisterDefaultNPCText( 4731, 4869)  # Zachariah Post
    RegisterDefaultNPCText( 4752, 2275)  # Kildar
    RegisterDefaultNPCText( 4772, 5858)  # Ultham Ironhorn
    RegisterDefaultNPCText( 4773, 4873)  # Velma Warnam
    RegisterDefaultNPCText( 4792,  580)  # "Swamp Eye" Jarl
    RegisterDefaultNPCText( 4900, 5050)  # Alchemist Narett
    RegisterDefaultNPCText( 4926, 1819)  # Krog
    RegisterDefaultNPCText( 4945, 2138)  # Goblin Drag Car
    RegisterDefaultNPCText( 4946,  778)  # Gnome Drag Car
    RegisterDefaultNPCText( 4949, 4522)  # Thrall
    RegisterDefaultNPCText( 4981, 1235)  # Ben Trias
    RegisterDefaultNPCText( 4984, 5276)  # Argos Nightwhisper
    RegisterDefaultNPCText( 5082, 3666)  # Vincent Hyal
    RegisterDefaultNPCText( 5099, 6286)  # Soleil Stonemantle
    RegisterDefaultNPCText( 5113, 5724)  # Kelv Sternhammer
    RegisterDefaultNPCText( 5115, 5000)  # Daera Brightspear
    RegisterDefaultNPCText( 5138, 5838)  # Gwina Stonebranch
    RegisterDefaultNPCText( 5144,  823)  # Bink
    RegisterDefaultNPCText( 5150, 7026)  # Nissa Firestone
    RegisterDefaultNPCText( 5153, 5119)  # Jormund Stonebrow
    RegisterDefaultNPCText( 5353, 1996)  # Itharius
    RegisterDefaultNPCText( 5411, 2954)  # Krinkle Goodsteel
    RegisterDefaultNPCText( 5484, 4434)  # Brother Benjamin
    RegisterDefaultNPCText( 5491, 3976)  # Arthur the Faithful
    RegisterDefaultNPCText( 5492, 3976)  # Katherine the Pure
    RegisterDefaultNPCText( 5495, 5693)  # Ursula Deline
    RegisterDefaultNPCText( 5498,  539)  # Elsharin
    RegisterDefaultNPCText( 5500, 5020)  # Tel'Athir
    RegisterDefaultNPCText( 5501, 3546)  # Kaerbrus
    RegisterDefaultNPCText( 5503, 1233)  # Eldraeith
    RegisterDefaultNPCText( 5505, 4784)  # Theridran
    RegisterDefaultNPCText( 5515, 5000)  # Einris Brightspear
    RegisterDefaultNPCText( 5516, 5000)  # Ulfir Ironbeard
    RegisterDefaultNPCText( 5519, 5171)  # Billibub Cogspinner
    RegisterDefaultNPCText( 5564, 5324)  # Simon Tanner
    RegisterDefaultNPCText( 5565, 1238)  # Jillian Tanner
    RegisterDefaultNPCText( 5594, 1471)  # Alchemist Pestlezugg
    RegisterDefaultNPCText( 5688, 1853)  # Innkeeper Renee
    RegisterDefaultNPCText( 5695, 5233)  # Vance Undergloom
    RegisterDefaultNPCText( 5725, 4097)  # Deathguard Lundmark
    RegisterDefaultNPCText( 5749, 5836)  # Kayla Smithe
    RegisterDefaultNPCText( 5750, 5835)  # Gina Lang
    RegisterDefaultNPCText( 5753, 5835)  # Martha Strain
    RegisterDefaultNPCText( 5759, 7028)  # Nurse Neela
    RegisterDefaultNPCText( 5769, 2574)  # Arch Druid Hamuul Runetotem
    RegisterDefaultNPCText( 5811, 2275)  # Kamari
    RegisterDefaultNPCText( 5817, 5005)  # Shimra
    RegisterDefaultNPCText( 5901, 1916)  # Islen Waterseer
    RegisterDefaultNPCText( 5939, 7024)  # Vira Younghoof
    RegisterDefaultNPCText( 5941, 6961)  # Lau'Tiki
    RegisterDefaultNPCText( 5994, 3793)  # Zayus
    RegisterDefaultNPCText( 6020, 3793)  # Slimeshell Makrura
    RegisterDefaultNPCText( 6119,  766)  # Tog Rustsprocket
    RegisterDefaultNPCText( 6252, 3586)  # Acolyte Magaz
    RegisterDefaultNPCText( 6254, 3587)  # Acolyte Wytula
    RegisterDefaultNPCText( 6272,  820)  # Innkeeper Janene
    RegisterDefaultNPCText( 6289, 5433)  # Rand Rhobart
    RegisterDefaultNPCText( 6301, 5121)  # Gorbold Steelhand
    RegisterDefaultNPCText( 6376, 5835)  # Wren Darkspring
    RegisterDefaultNPCText( 6491,  580)  # Spirit Healer
    RegisterDefaultNPCText( 6546, 3590)  # Tabetha
    RegisterDefaultNPCText( 6548, 2354)  # Magus Tirth
    RegisterDefaultNPCText( 6566,  581)  # Estelle Gendry
    RegisterDefaultNPCText( 6568, 1933)  # Vizzklick
    RegisterDefaultNPCText( 6739,  821)  # Innkeeper Bates
    RegisterDefaultNPCText( 6741,  821)  # Innkeeper Norman
    RegisterDefaultNPCText( 6746,  822)  # Innkeeper Pala
    RegisterDefaultNPCText( 6747,  822)  # Innkeeper Kauth
    RegisterDefaultNPCText( 6790,  820)  # Innkeeper Trelayne
    RegisterDefaultNPCText( 6791,  825)  # Innkeeper Wiley
    RegisterDefaultNPCText( 6826, 2253)  # Talvash del Kissel
    RegisterDefaultNPCText( 6928, 1853)  # Innkeeper Grosk
    RegisterDefaultNPCText( 6929,  938)  # Innkeeper Gryshka
    RegisterDefaultNPCText( 6930, 7210)  # Innkeeper Karakul
    RegisterDefaultNPCText( 7166, 1041)  # Wrenix's Gizmotronic Apparatus
    RegisterDefaultNPCText( 7172, 1094)  # Lore Keeper of Norgannon
    RegisterDefaultNPCText( 7230, 1640)  # Shayis Steelfury
    RegisterDefaultNPCText( 7231, 1635)  # Kelgruk Bloodaxe
    RegisterDefaultNPCText( 7298, 5046)  # Demnul Farmountain
    RegisterDefaultNPCText( 7363, 1303)  # Kum'isha the Collector
    RegisterDefaultNPCText( 7406, 2136)  # Oglethorpe Obnoticus
    RegisterDefaultNPCText( 7564, 2055)  # Marin Noggenfogger
    RegisterDefaultNPCText( 7572, 1391)  # Fallen Hero of the Horde
    RegisterDefaultNPCText( 7604, 1516)  # Sergeant Bly
    RegisterDefaultNPCText( 7683, 1734)  # Alessandro Luca
    RegisterDefaultNPCText( 7733, 3566)  # Innkeeper Fizzgrimble
    RegisterDefaultNPCText( 7737, 7212)  # Innkeeper Greul
    RegisterDefaultNPCText( 7744,  823)  # Innkeeper Thulfram
    RegisterDefaultNPCText( 7771, 2038)  # Marvon Rivetseeker
    RegisterDefaultNPCText( 7772, 2054)  # Kalin Windflight
    RegisterDefaultNPCText( 7773, 2053)  # Marli Wishrunner
    RegisterDefaultNPCText( 7775, 2433)  # Gregan Brewspewer
    RegisterDefaultNPCText( 7776, 3545)  # Talo Thornhoof
    RegisterDefaultNPCText( 7783, 1796)  # Loramus Thalipedes
    RegisterDefaultNPCText( 7804, 1759)  # Trenton Lighthammer
    RegisterDefaultNPCText( 7825, 6979)  # Oran Snakewrithe
    RegisterDefaultNPCText( 7852, 2639)  # Pratt McGrubben
    RegisterDefaultNPCText( 7853, 2282)  # Scooty
    RegisterDefaultNPCText( 7854, 2638)  # Jangdor Swiftstrider
    RegisterDefaultNPCText( 7868, 3804)  # Sarah Tanner
    RegisterDefaultNPCText( 7871, 3806)  # Se'Jib
    RegisterDefaultNPCText( 7875, 7402)  # Hadoken Swiftstrider
    RegisterDefaultNPCText( 7944, 2137)  # Tinkmaster Overspark
    RegisterDefaultNPCText( 7949, 1759)  # Xylinnia Starshine
    RegisterDefaultNPCText( 7954, 4878)  # Binjy Featherwhistle
    RegisterDefaultNPCText( 7955, 3945)  # Milli Featherwhistle
    RegisterDefaultNPCText( 8115, 1924)  # Witch Doctor Uzer'i
    RegisterDefaultNPCText( 8125, 5798)  # Dirge Quikcleave
    RegisterDefaultNPCText( 8126, 2138)  # Nixx Sprocketspring
    RegisterDefaultNPCText( 8142, 5717)  # Jannos Lighthoof
    RegisterDefaultNPCText( 8153, 5335)  # Narv Hidecrafter
    RegisterDefaultNPCText( 8356, 3415)  # Chesmu
    RegisterDefaultNPCText( 8380, 2293)  # Captain Vanessa Beltis
    RegisterDefaultNPCText( 8399, 1994)  # Nyrill
    RegisterDefaultNPCText( 8479, 1955)  # Kalaran Windblade
    RegisterDefaultNPCText( 8509, 2279)  # Squire Maltrake
    RegisterDefaultNPCText( 8576, 2033)  # Ag'tor Bloodfist
    RegisterDefaultNPCText( 8579, 2140)  # Yeh'kinya
    RegisterDefaultNPCText( 8587, 2036)  # Jediga
    RegisterDefaultNPCText( 8673, 5516)  # Auctioneer Thathung
    RegisterDefaultNPCText( 8736, 5177)  # Buzzek Bracketswing
    RegisterDefaultNPCText( 8738, 2133)  # Vazario Linkgrease
    RegisterDefaultNPCText( 8931,  820)  # Innkeeper Heather
    RegisterDefaultNPCText( 8962, 2273)  # Hilary
    RegisterDefaultNPCText( 9021, 2482)  # Kharan Mighthammer
    RegisterDefaultNPCText( 9047, 2314)  # Jenal
    RegisterDefaultNPCText( 9076, 2333)  # Ghede
    RegisterDefaultNPCText( 9087, 2353)  # Bashana Runetotem
    RegisterDefaultNPCText( 9117, 2817)  # J.D. Collie
    RegisterDefaultNPCText( 9270, 3096)  # Williden Marshal
    RegisterDefaultNPCText( 9271, 3095)  # Hol'anyee Marshal
    RegisterDefaultNPCText( 9272, 3380)  # Spark Nilminer
    RegisterDefaultNPCText( 9273, 3793)  # Petra Grossen
    RegisterDefaultNPCText( 9298, 4634)  # Donova Snowden
    RegisterDefaultNPCText( 9459, 2494)  # Cyrus Therepentous
    RegisterDefaultNPCText( 9467, 2496)  # Miblon Snarltooth
    RegisterDefaultNPCText( 9501,  822)  # Innkeeper Adegwa
    RegisterDefaultNPCText( 9528, 3046)  # Arathandris Silversky
    RegisterDefaultNPCText( 9544, 6594)  # Yuka Screwspigot
    RegisterDefaultNPCText( 9558, 2640)  # Grimble
    RegisterDefaultNPCText( 9559, 2641)  # Grizzlowe
    RegisterDefaultNPCText( 9561,  580)  # Jalinda Sprig
    RegisterDefaultNPCText( 9563, 2713)  # Ragged John
    RegisterDefaultNPCText( 9564, 2642)  # Frezza
    RegisterDefaultNPCText( 9566, 2644)  # Zapetta
    RegisterDefaultNPCText( 9598, 2726)  # Arei
    RegisterDefaultNPCText( 9618, 2734)  # Karna Remtravel
    RegisterDefaultNPCText( 9619, 2816)  # Torwa Pathfinder
    RegisterDefaultNPCText( 9620, 4960)  # Dreka'Sur
    RegisterDefaultNPCText( 9836, 2993)  # Mathredis Firestar
    RegisterDefaultNPCText( 9997, 3546)  # Spraggle Frock
    RegisterDefaultNPCText(10058,  938)  # Greth
    RegisterDefaultNPCText(10088, 5838)  # Xao'tsu
    RegisterDefaultNPCText(10136, 3193)  # Chemist Fuely
    RegisterDefaultNPCText(10182, 6533)  # Rexxar
    RegisterDefaultNPCText(10219, 5943)  # Gwennyth Bly'Leggonde
    RegisterDefaultNPCText(10266, 3412)  # Ug'thok
    RegisterDefaultNPCText(10267, 3296)  # Tinkee Steamboil
    RegisterDefaultNPCText(10306, 6957)  # Trull Failbane
    RegisterDefaultNPCText(10307, 3375)  # Witch Doctor Mau'ari
    RegisterDefaultNPCText(10378, 7315)  # Omusa Thunderhorn
    RegisterDefaultNPCText(10431, 4841)  # Gregor Greystone
    RegisterDefaultNPCText(10578, 3795)  # Bom'bay
    RegisterDefaultNPCText(10637, 3673)  # Malyfous Darkhammer
    RegisterDefaultNPCText(10667, 3585)  # Chromie
    RegisterDefaultNPCText(10668, 3558)  # Beaten Corpse
    RegisterDefaultNPCText(10778, 3668)  # Janice Felstone
    RegisterDefaultNPCText(10781, 3653)  # Royal Overseer Bauhaus
    RegisterDefaultNPCText(10782, 2134)  # Royal Factor Bathrilor
    RegisterDefaultNPCText(10837, 3753)  # High Executor Derrington
    RegisterDefaultNPCText(10838, 3754)  # Commander Ashlam Valorfist
    RegisterDefaultNPCText(10839, 4134)  # Argent Officer Garush
    RegisterDefaultNPCText(10840, 4135)  # Argent Officer Pureheart
    RegisterDefaultNPCText(10856, 4174)  # Argent Quartermaster Hasana
    RegisterDefaultNPCText(10857, 4193)  # Argent Quartermaster Lightspark
    RegisterDefaultNPCText(10879, 6957)  # Harbinger Balthazad
    RegisterDefaultNPCText(10880, 6957)  # Warcaller Gorlach
    RegisterDefaultNPCText(10922, 3807)  # Greta Mosshoof
    RegisterDefaultNPCText(10976,  580)  # Jeziba
    RegisterDefaultNPCText(10993, 5130)  # Twizwick Sprocketgrind
    RegisterDefaultNPCText(11016, 3865)  # Captured Arko'narin
    RegisterDefaultNPCText(11017, 5173)  # Roxxik
    RegisterDefaultNPCText(11019, 3864)  # Jessir Moonbow
    RegisterDefaultNPCText(11025, 5135)  # Mukdrak
    RegisterDefaultNPCText(11029, 5195)  # Trixie Quikswitch
    RegisterDefaultNPCText(11031, 5162)  # Franklin Lloyd
    RegisterDefaultNPCText(11035, 4450)  # Betina Bigglezink
    RegisterDefaultNPCText(11037, 5121)  # Jenna Lemkenilli
    RegisterDefaultNPCText(11038, 3935)  # Caretaker Alen
    RegisterDefaultNPCText(11041, 5027)  # Milla Fairancora
    RegisterDefaultNPCText(11044, 5048)  # Doctor Martin Felben
    RegisterDefaultNPCText(11047, 5042)  # Kray
    RegisterDefaultNPCText(11048, 5434)  # Victor Ward
    RegisterDefaultNPCText(11049, 5556)  # Rhiannon Davis
    RegisterDefaultNPCText(11050, 5438)  # Trianna
    RegisterDefaultNPCText(11053, 3996)  # High Priestess MacDonnell
    RegisterDefaultNPCText(11055, 3939)  # Shadow Priestess Vandis
    RegisterDefaultNPCText(11056, 3981)  # Alchemist Arbington
    RegisterDefaultNPCText(11057, 3978)  # Apothecary Dithers
    RegisterDefaultNPCText(11063, 4716)  # Carlin Redpath
    RegisterDefaultNPCText(11064, 3873)  # Darrowshire Spirit
    RegisterDefaultNPCText(11065, 5674)  # Thonys Pillarstone
    RegisterDefaultNPCText(11067, 5193)  # Malcomb Wynn
    RegisterDefaultNPCText(11068, 5181)  # Betty Quin
    RegisterDefaultNPCText(11071, 5196)  # Mot Dawnstrider
    RegisterDefaultNPCText(11073, 5253)  # Annora
    RegisterDefaultNPCText(11083, 5274)  # Darianna
    RegisterDefaultNPCText(11097, 5403)  # Drakk Stonehand
    RegisterDefaultNPCText(11098, 5407)  # Hahrana Ironhide
    RegisterDefaultNPCText(11103,  824)  # Innkeeper Lyshaerya
    RegisterDefaultNPCText(11118,  825)  # Innkeeper Vizzie
    RegisterDefaultNPCText(11137,  820)  # Xai'ander
    RegisterDefaultNPCText(11191, 7245)  # Lilith the Lithe
    RegisterDefaultNPCText(11192, 7243)  # Kilram
    RegisterDefaultNPCText(11193, 7247)  # Seril Scourgebane
    RegisterDefaultNPCText(11216, 4041)  # Eva Sarkhoff
    RegisterDefaultNPCText(11317, 4891)  # Jinar'Zillen
    RegisterDefaultNPCText(11407, 4443)  # Var'jun
    RegisterDefaultNPCText(11536, 4213)  # Quartermaster Miranda Breechlock
    RegisterDefaultNPCText(11554, 4394)  # Grazle
    RegisterDefaultNPCText(11556, 4396)  # Salfa
    RegisterDefaultNPCText(11625, 4813)  # Cork Gizelton
    RegisterDefaultNPCText(11626, 4815)  # Rigger Gizelton
    RegisterDefaultNPCText(11798, 4916)  # Bunthen Plainswind
    RegisterDefaultNPCText(11800, 4913)  # Silva Fil'naveth
    RegisterDefaultNPCText(11801, 6154)  # Rabine Saturna
    RegisterDefaultNPCText(11820, 6193)  # Locke Okarr
    RegisterDefaultNPCText(11835, 4474)  # Theodore Griffs
    RegisterDefaultNPCText(11860, 5443)  # Maggran Earthbinder
    RegisterDefaultNPCText(11868, 6233)  # Sayoc
    RegisterDefaultNPCText(11869, 6281)  # Ansekhwa
    RegisterDefaultNPCText(11872, 4633)  # Myranda the Hag
    RegisterDefaultNPCText(11939, 6153)  # Umber
    RegisterDefaultNPCText(11946, 7415)  # Drek'Thar
    RegisterDefaultNPCText(12031, 4959)  # Mai'Lahii
    RegisterDefaultNPCText(12032, 6961)  # Lui'Mala
    RegisterDefaultNPCText(12042, 4783)  # Loganaar
    RegisterDefaultNPCText(12097, 6257)  # Frostwolf Quartermaster
    RegisterDefaultNPCText(12136, 4693)  # Snurk Bucksquick
    RegisterDefaultNPCText(12137, 4694)  # Squibby Overspeck
    RegisterDefaultNPCText(12238, 6336)  # Zaetar's Spirit
    RegisterDefaultNPCText(12245, 4857)  # Vendor-Tron 1000
    RegisterDefaultNPCText(12246, 4856)  # Super-Seller 680
    RegisterDefaultNPCText(12340, 5212)  # Drulzegar Skraghook
    RegisterDefaultNPCText(12355, 4973)  # Gray Riding Kodo
    RegisterDefaultNPCText(12657, 5481)  # Don Pompa
    RegisterDefaultNPCText(12696, 5529)  # Senani Thunderheart
    RegisterDefaultNPCText(12716, 5579)  # Decedra Willham
    RegisterDefaultNPCText(12736, 5654)  # Je'neu Sancrea
    RegisterDefaultNPCText(12757, 5613)  # Karang Amakkar
    RegisterDefaultNPCText(12802, 6957)  # Chimaerok Devourer
    RegisterDefaultNPCText(12863, 6033)  # Warsong Runner
    RegisterDefaultNPCText(12866, 5713)  # Myriam Moonsinger
    RegisterDefaultNPCText(12867, 6574)  # Kuray'bin
    RegisterDefaultNPCText(12920, 6413)  # Doctor Gregory Victor
    RegisterDefaultNPCText(12944, 5834)  # Lokhtos Darkbargainer
    RegisterDefaultNPCText(12997, 5894)  # Monty
    RegisterDefaultNPCText(13176, 6066)  # Smith Regzar
    RegisterDefaultNPCText(13179, 6107)  # Wing Commander Guse
    RegisterDefaultNPCText(13220, 6155)  # Layo Starstrike
    RegisterDefaultNPCText(13236, 6093)  # Primalist Thurloga
    RegisterDefaultNPCText(13278, 6108)  # Duke Hydraxis
    RegisterDefaultNPCText(13283, 4835)  # Lord Tony Romano
    RegisterDefaultNPCText(13697, 6575)  # Cavindra
    RegisterDefaultNPCText(13698, 6334)  # Keeper Marandis
    RegisterDefaultNPCText(13699, 6335)  # Selendra
    RegisterDefaultNPCText(13716, 6373)  # Celebras the Redeemed
    RegisterDefaultNPCText(13717, 6353)  # Centaur Pariah
    RegisterDefaultNPCText(13776, 7434)  # Corporal Teeka Bloodsnarl
    RegisterDefaultNPCText(13840, 6475)  # Warmaster Laggrond
    RegisterDefaultNPCText(14374, 6917)  # Scholar Runethorn
    RegisterDefaultNPCText(14387, 6933)  # Lothos Riftwaker
    RegisterDefaultNPCText(14508, 7074)  # Short John Mithril
    RegisterDefaultNPCText(14527, 7041)  # Simone the Inconspicuous
    RegisterDefaultNPCText(14531, 7045)  # Artorius the Amiable
    RegisterDefaultNPCText(14624, 7115)  # Master Smith Burninate
    RegisterDefaultNPCText(14626, 7120)  # Taskmaster Scrange
    RegisterDefaultNPCText(14627, 7117)  # Hansel Heavyhands
    RegisterDefaultNPCText(14628, 7095)  # Evonice Sootsmoker
    RegisterDefaultNPCText(14634, 7094)  # Lookout Captain Lolo Longstriker
    RegisterDefaultNPCText(14729, 7189)  # Ralston Farnsley
    RegisterDefaultNPCText(14731, 7211)  # Lard
    RegisterDefaultNPCText(14736, 7238)  # Primal Torntusk
    RegisterDefaultNPCText(14737, 7239)  # Smith Slagtree
    RegisterDefaultNPCText(14738, 7237)  # Otho Moji'ko
    RegisterDefaultNPCText(14739, 7240)  # Mystic Yayo'jin
    RegisterDefaultNPCText(14740, 7241)  # Katoom the Angler
    RegisterDefaultNPCText(14741, 7242)  # Huntsman Markhor
    RegisterDefaultNPCText(14742, 7249)  # Zap Farflinger
    RegisterDefaultNPCText(14743, 7253)  # Jhordy Lapforge
    RegisterDefaultNPCText(14753, 7295)  # Illiyana Moonblaze
    RegisterDefaultNPCText(14754, 7294)  # Kelm Hargunth
    RegisterDefaultNPCText(14757, 7257)  # Elder Torntusk

