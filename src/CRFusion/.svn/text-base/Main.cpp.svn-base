/* 
 * Copyright (C) 2006 CrFusion Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include "StdAfx.h"

#ifdef _WIN32
#	ifdef _DEBUG
#		pragma comment(lib, "zlib1d.lib")		// zlib1d.dll
#		pragma comment(lib, "ZThread.lib")		// ZThread.dll
#		pragma comment(lib, "python24_d.lib")	// python24_d.dll
#		pragma comment(lib, "PyCXX.lib")		// static lib
#		pragma comment(lib, "dotconfpp.lib")	// static lib
#		pragma comment(lib, "libeay32.lib")	// libeay32.dll
#		pragma comment(lib, "ssleay32.lib")	// ssleay32.dll
#		pragma comment(lib, "Sockets.lib")		// static lib
#		pragma comment(lib, "sqlite3.lib")		// sqlite3.dll
#		pragma comment(lib, "libmysql.lib")	// libmysql.dll
#	else
#		pragma comment(lib, "zlib.lib")		// static lib
#		pragma comment(lib, "ZThread.lib")		// static lib
#		pragma comment(lib, "python24.lib")	// static lib
#		pragma comment(lib, "PyCXX.lib")		// static lib
#		pragma comment(lib, "dotconfpp.lib")	// static lib
#		pragma comment(lib, "libeay32.lib")	// static lib
#		pragma comment(lib, "ssleay32.lib")	// static lib
#		pragma comment(lib, "Sockets.lib")		// static lib
#		pragma comment(lib, "sqlite3.lib")		// static lib
#		pragma comment(lib, "libmysql.lib")	// libmysql.dll
#	endif
#endif

uint8 loglevel = DEFAULT_LOG_LEVEL;
uint8 logchat  = DEFAULT_LOG_LEVEL;
bool sql_logchat = false;
uint32 autosavetime = DEFAULT_SAVE_TIME;

int main(int argc, char **argv)
{
    std::string cfg_file = "CrFusion.conf";

	/* Todo:
		Args scanning */

    if (!sConfig.SetSource(cfg_file.c_str()))
		sLog.outError("\nCould not find a configuration file named [%s] (case sensitive on Linux).", cfg_file.c_str());

	sMaster.Run();
	return 0;
}
