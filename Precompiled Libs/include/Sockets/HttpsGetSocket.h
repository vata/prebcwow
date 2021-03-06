/** \file HttpsGetSocket.h
 **	\date  2004-02-13
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
#ifndef _HTTPSGETSOCKET_H
#define _HTTPSGETSOCKET_H
#ifdef HAVE_OPENSSL

#include "HttpsSocket.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


/** This class is no longer in active development.
	\deprecated Please use HttpGetSocket with EnableSSL instead
	\sa HttpGetSocket
	\sa EnableSSL 
	\ingroup deprecated */
class HttpsGetSocket : public HttpsSocket
{
public:
	HttpsGetSocket(SocketHandler&,const std::string&,const std::string& = "");
	HttpsGetSocket(SocketHandler&,const std::string&,port_t,const std::string&,const std::string&);
	~HttpsGetSocket();

	void InitAsClient();

	void OnContent();
	void OnDelete();
	void OnSSLInitDone();

	void OnFirst();
	void OnHeader(const std::string& ,const std::string& );
	void OnHeaderComplete();
	void OnData(const char *,size_t);

	bool Complete() { return m_bComplete; }

	size_t GetContentLength() { return m_content_length; }
	size_t GetPos() { return m_content_ptr; }

	void url_this(const std::string& url_in,std::string& host,port_t& port,std::string& url,std::string& file);

protected:
	HttpsGetSocket(const HttpsGetSocket& s) : HttpsSocket(s) {}
private:
	HttpsGetSocket& operator=(const HttpsGetSocket& ) { return *this; }
	std::string m_host;
	port_t m_port;
	std::string m_url;
	std::string m_to_file;
	//
	FILE *m_fil;
	bool m_bComplete;
	//
	size_t m_content_length;
	std::string m_content_type;
	size_t m_content_ptr;
};



#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // HAVE_OPENSSL
#endif // _HTTPSGETSOCKET_H
