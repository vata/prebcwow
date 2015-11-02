// Copyright (C) 2004 WoW Daemon
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef WOWSERVER_LOG_H
#define WOWSERVER_LOG_H

//#include "Common.h"
#include "Singleton.h"

extern uint8 loglevel;
extern uint8 logchat;

class Log : public Singleton< Log > {
public:
  void outChat(uint32 lang, const char *name, const char *type, const char *msg);
  void outString( const char * str, ... );
  void outError( const char * err, ... );
  void outBasic( const char * str, ... );
  void outDetail( const char * str, ... );
  void outDebug( const char * str, ... );
  void outMenu( const char * str, ... );
  void outColor(uint32 color);
  void outTime(uint32 color = 500);

};


#define sLog Log::getSingleton()

#endif

