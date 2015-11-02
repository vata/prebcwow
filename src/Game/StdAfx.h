#pragma once

#include <signal.h>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <limits.h>
#include <iostream>
#include <fstream>

#include <zthread/Task.h>
#include <zthread/ZThread.h>

#if PLATFORM__ == PLATFORM_WIN32
#  include <zlib/zlib.h>
#else
#  include <zlib.h>
#endif

#include "../CRFusion/Version/version.h"

#include "../Shared/Common.h"
#include "../Shared/WorldPacket.h"
#include "../Shared/PacketBuilder.h"
#include "../Shared/Log.h"
#include "../Shared/Util.h"
#include "../Shared/ByteBuffer.h"

#include "../Shared/Config/ConfigEnv.h"

#define HAVE_OPENSSL
#define _THREADSAFE_SOCKETS
#undef IPPROTO_IPV6
#include <Sockets/Utility.h>
#include <Sockets/TcpSocket.h>

#include "../Shared/Database/DatabaseEnv.h"
#include "../Shared/Database/DBCStores.h"
#include "../Shared/Database/Field.h"
#include "../Shared/FactionTemplates.h"

#include "../Shared/OurDefs.h"

#include "../Shared/Auth/BigNumber.h"
#include "../Shared/Auth/Sha1.h"
#include "../Shared/MersenneTwister.h"

#include "../Game/WorldSession.h"
#include "../Game/Player.h"
#include "../Game/Unit.h"
#include "../Game/World.h"

#include "../Spells/Spells.h"

#include "Affect.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "Corpse.h"
#include "Creature.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Group.h"
#include "Guild.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "Mail.h"
#include "MapCell.h"
//#include "MapGrid.h"
#include "MapMgr.h"
#include "MiscHandler.h"
#include "NPCHandler.h"
#include "NameTables.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Path.h"
#include "Player.h"
#include "Quest.h"
#include "Spell.h"
#include "Stats.h"
#include "Unit.h"
#include "UpdateData.h"
#include "UpdateFields.h"
#include "UpdateMask.h"
#include "World.h"
#include "WorldSession.h"
#include "QuestPacketHandler.h"
#include "QuestScriptBackend.h"

// Auto-Generated definition files
#include "Skill_Auto.h"

#ifdef WIN32
#	define CRTDBG_MAP_ALLOC
#	include <stdlib.h>
#	include <crtdbg.h>
#endif

#include "../Scripts/Scripts.h"

