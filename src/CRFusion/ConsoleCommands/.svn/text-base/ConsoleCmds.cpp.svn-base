//******************************************************************************
#include "StdAfx.h"
//==============================================================================
							// Public methods:
//------------------------------------------------------------------------------
// Get pending input and process it
void CConsoleCmds::Do()
{
	char c = 0;
nextcmd:
	// Read in single line from "stdin":
	for(c=0; (pos<80) && (c!=13 && c!=10); ++pos)
	{
		if ( (c=AConsole.GetChar()) != EOF )
		{
			putchar(c);
			cmd[pos] = (char)c;
		}
		else
			return;
	}

	if (c==13 || c==10)
	{
		if (c != '\n')
			sLog.outString("");

		cmd[pos-1] = 0;
		ProcessCmd(cmd);
		cmd[0] = 0;
		pos = 0;

		sLog.outString("");

		goto nextcmd;
	}

	if (pos == 80)
	{
		sLog.outError("console command line overflow");
		cmd[0] = 0;
		pos = 0;
	}
}
//------------------------------------------------------------------------------
// Constructor
CConsoleCmds::CConsoleCmds()
{
	cmd = new char[80];
	if (cmd == NULL)
		sLog.outError("new() returns NULL");
	cmd[0] = 0;
	pos = 0;
}
//------------------------------------------------------------------------------
// Simple destructor
CConsoleCmds::~CConsoleCmds()
{
	if (cmd != NULL)
		delete[] cmd;
}
//------------------------------------------------------------------------------
							// Protected methods:
//------------------------------------------------------------------------------
// Process one command
void CConsoleCmds::ProcessCmd(char *cmd)
{
	typedef void (*PTranslater)(char *str);
	struct SCmd
	{
		char *name;
		PTranslater tr;
	};
	
	SCmd cmds[] =
	{
		{"version"       , CConsoleCmds::TranslateVersion} , {"ver"   , CConsoleCmds::TranslateVersion},
		{"quit"          , CConsoleCmds::TranslateQuit}    , {"exit"  , CConsoleCmds::TranslateQuit},
		{"help"          , CConsoleCmds::TranslateHelp}    , {"?"     , CConsoleCmds::TranslateHelp},
		{"reload"        , CConsoleCmds::TranslateReload}  , {"rel"   , CConsoleCmds::TranslateReload},
		{"realmlist"     , CConsoleCmds::TranslateRealm}   , {"realm" , CConsoleCmds::TranslateRealm},
		{"broad"         , CConsoleCmds::TranslateBroad}   , {"broadcast", CConsoleCmds::TranslateBroad}, 
	};

	cmd = strtok(cmd, " ");
	char* command = cmd;
	cmd = strtok(NULL, " ");
	for (int i = 0; i < sizeof(cmds)/sizeof(SCmd); ++i)
		if (stricmp(command, cmds[i].name) == 0)
		{
			(*(cmds[i].tr)) (cmd);
			return;
		}

	sLog.outError("Unknown console command (use \"help\" for command list).");
}
//------------------------------------------------------------------------------
// ver[sion]
void CConsoleCmds::TranslateVersion(char *args)
{
	sLog.outString(FULLSERVERNAME);
}
//------------------------------------------------------------------------------
// quit | exit
void CConsoleCmds::TranslateQuit(char *args)
{
	if(args == NULL)
	{
		sWorld.SendWorldText("|c8fff6420[Server]|r |c8fff9920Shutting down...|r");
		raise(SIGINT);
		return;
	}
	sWorld.ShutdownServ( atoi(args) );
}
//------------------------------------------------------------------------------
// rel[oad]
void CConsoleCmds::TranslateReload(char *args)
{
	sWorld.SendWorldText("|c8fff6420[Server]|r |c8fff9920Reloading Scripts...|r");
	sLog.outString("::[Starting Script Reload]");
	RestartScripting();
	sWorld.SendWorldText("|c8fff6420[Server]|r |c8fff9920Scripts Reloaded|r");
	sLog.outString("::[Script Reload Done]");
}
//------------------------------------------------------------------------------
// realm[list]
void CConsoleCmds::TranslateRealm(char *args)
{
	sRealmList.LoadRealms();
}
//------------------------------------------------------------------------------
// broad[cast]
void CConsoleCmds::TranslateBroad(char *args)
{
	sWorld.SendWorldText(args);
	sWorld.SendWorldWideText(args);
	sLog.outString("::Message [%s] Broadcasted !", args);
}
//------------------------------------------------------------------------------
// help | ?
void CConsoleCmds::TranslateHelp(char *args)
{
	if(args == NULL)
	{
		sLog.outColor(4);
		sLog.outString("/***- CONSOLE COMMANDS LIST -***\\");
		sLog.outString("ver[sion]:    Print version");
		sLog.outString("quit, exit:   Close program");
		sLog.outString("re[load]:     Reload Python Scripts");
		sLog.outString("realm[list]:  Reload RealmList");
		sLog.outString("broad[cast] <txt>: Broadcasts <txt> to online players");
		sLog.outString("help, ?:      Print this text");
		sLog.outString("=Use help <cmd> to get help on any command=");
		sLog.outString("\\***- CONSOLE COMMANDS LIST -***/");
		sLog.outColor(2);
		return;
	}
}
//******************************************************************************
