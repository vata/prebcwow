# Main SConstruct
#
# Use 'scons -Q' to compile Server with all dependencies
#

SConscript('src/Game/SConstruct', build_dir = 'build/_libgame')
SConscript('src/Shared/SConstruct', build_dir = 'build/_libshared')
SConscript('src/Shared/Auth/SConstruct', build_dir = 'build/_libauth')
SConscript('src/Shared/Config/SConstruct', build_dir = 'build/_libconfig')
SConscript('src/Shared/Database/SConstruct', build_dir = 'build/_libdatabase')
SConscript('src/Spells/SConstruct', build_dir = 'build/_libspells')
SConscript('src/Scripts/SConstruct', build_dir = 'build/_libscripts')
SConscript('src/RealmList/SConstruct', build_dir = 'build/_librealmlist')
SConscript('src/CRFusion/ConsoleCommands/SConstruct', build_dir = 'build/_libconscomm')
SConscript('src/CRFusion/Version/SConstruct', build_dir = 'build/_libversion')

SConscript('src/CRFusion/SConstruct', build_dir = 'build/_CRFusion')