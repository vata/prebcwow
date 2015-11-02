//******************************************************************************
#include "StdAfx.h"
#include "revision.h"
//==============================================================================
#define _VERHIGH 0
#define _VERREVISION SVN_REVISION
#define VERTARGET _VERTARGET

// For DB and Scripts backward compat. check.
// Set this to the maximum difference between versions
// of server and DB.
// Btw .. using revision system
#define _BACKWARD_COMPATIBILITY_DELTA 100

//==============================================================================
#define TOTHESTR(n) #n
#define MAKEVERSTR(a, b, c) TOTHESTR(a) "." TOTHESTR(b) "." TOTHESTR(c)
#define _VERSION MAKEVERSTR(_VERHIGH, _VERREVISION, _VERTARGET)

#ifdef _WIN32
	#ifdef _DEBUG
		#define _FULLVERSION _VERSION "-w32debug"
	#else
		#define _FULLVERSION _VERSION "-w32"
	#endif
#else
	#define _FULLVERSION _VERSION "-posix"
#endif

#define _SERVERNAME "CRFusion"

#define _FULLSERVERNAME _SERVERNAME " v" _FULLVERSION
//==============================================================================
char * VERSION = _VERSION;

int VERHIGH = _VERHIGH;
int VERREVISION = _VERREVISION;
int BACK_COMPAT = _BACKWARD_COMPATIBILITY_DELTA;

char * FULLVERSION = _FULLVERSION;
char * FULLSERVERNAME = _FULLSERVERNAME;
//******************************************************************************