/** \file SocketThread.cpp
 **	\date  2004-05-05
 **	\author grymse@alhem.net
**/
/*
Copyright (C) 2004,2005  Anders Hedstrom

This library is made available under the terms of the GNU GPL.

If you would like to use this library in a closed-source application,
a separate license agreement is available. For information about 
the closed-source license agreement for the C++ sockets library,
please visit http://www.alhem.net/Sockets/license.html and/or
email license@alhem.net.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifdef _WIN32
#pragma warning(disable:4786)
#endif
#include "SocketHandler.h"
#include "SocketThread.h"

//#define DEB(x) x; fflush(stdout);
#define DEB(x)

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


SocketThread::SocketThread(Socket& p)
:Thread(false)
,m_socket(p)
{
	// Creator will release
DEB(	printf("SocketThread()\n");)
}


SocketThread::~SocketThread()
{
DEB(	printf("~SocketThread()\n");)
}


void SocketThread::Run()
{
	SocketHandler h;
	h.SetSlave();
	h.Add(&m_socket);
DEB(	printf("slave: OnDetached()\n");)
	m_socket.OnDetached();
DEB(	printf("slave: first select\n");)
	h.Select(1,0);
	while (h.GetCount()) //m_socket.Ready() && IsRunning())
	{
DEB(		printf("slave: select\n");)
		h.Select(1,0);
	}
	// m_socket now deleted oops
DEB(	printf("slave: SetDetach( false )\n");)
//	m_socket.SetDetach(false);
}


#ifdef SOCKETS_NAMESPACE
}
#endif

