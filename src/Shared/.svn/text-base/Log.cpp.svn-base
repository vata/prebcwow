#include "StdAfx.h"

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

createFileSingleton( Log );

void Log::outChat(uint32 lang, const char *name, const char *type, const char *msg) {
    if( logchat > 0 ) {
		outTime();
		printf("Chat|%s|%d|%s|[%s]\n", name, lang, type, msg );
	}
}

void Log::outTime(uint32 color) {
	if(color!=500)
		outColor(color);
    struct tm *tmPtr=NULL;
    time_t tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
	char timestr[12];
	strftime(timestr, 12 , "%H:%M:%S|", tmPtr);
	printf("%s", timestr);
}

void Log::outString( const char * str, ... ) {
    if( !str ) return;
    va_list ap;
    va_start(ap, str);
	outTime();
    vprintf( str, ap );
    printf( "\n" );
    va_end(ap);
	fflush(stdout);
}

void Log::outError( const char * err, ... ) {
    if( !err ) return;
    va_list ap;
    va_start(ap, err);
	outTime();
	outColor(10);
	fprintf( stderr, "E|" );
    vfprintf( stderr, err, ap );
    fprintf( stderr, "\n" );
    va_end(ap);
	fflush(stderr);
	outColor(2);
}

void Log::outBasic( const char * str, ... ) {
    if( !str ) return;
    if( loglevel > 0 ) {
        va_list ap;
        va_start(ap, str);
		outTime();
        vprintf( str, ap );
        printf( "\n" );
        va_end(ap);
		fflush(stdout);
    }
}

void Log::outDetail( const char * str, ... ) {
    if( !str ) return;
    if( loglevel > 1 ) {
        va_list ap;
        va_start(ap, str);
		outTime();
		outColor(4);
		printf( "2|" );
        vprintf( str, ap );
        printf( "\n" );
        va_end(ap);
		fflush(stdout);
		outColor(2);
    }
}

void Log::outDebug( const char * str, ... ) {
    if( !str ) return;
    if( loglevel > 2 ) {
        va_list ap;
        va_start(ap, str);
		outTime();
		outColor(3);
		printf( "3|" );
        vprintf( str, ap );
        printf( "\n" );
        va_end(ap);
		fflush(stdout);
		outColor(2);
    }
}

void Log::outMenu( const char * str, ... ) {
    if( !str ) return;
    va_list ap;
    va_start(ap, str);
	outTime();
    vprintf( str, ap );
    va_end(ap);
	fflush(stdout);
}

void Log::outColor(uint32 color) {
#if PLATFORM == PLATFORM_WIN32
switch(color)
{
	case 0: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // White text
		break;
	case 1: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); // Black text
		break;
	case 2: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        0 | FOREGROUND_INTENSITY); // Gray text
		break;
	case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        0 | FOREGROUND_RED | FOREGROUND_INTENSITY); // Red text
		break;
	case 4: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        0 | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Green text
		break;
	case 10: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | BACKGROUND_RED); // Error text (black on red)
		break;
	default: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        0 | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); // White text
		break;
}
#elif PLATFORM == PLATFORM_UNIX
switch(color)
{
	case 0: printf("\e[0m"); // White text
		break;
	case 1: printf(""); // Black text
		break;
	case 2: printf(""); // Gray text
		break;
	case 3: printf(""); // Red text
		break;
	case 4: printf(""); // Green text
		break;
	case 10: printf(""); // Error text (black on red)
		break;
	default: printf("\e[0m"); // White text
		break;
}
#endif
}