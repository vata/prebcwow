//******************************************************************************
class CConsoleCmds // direct console commands processor
{
public:						// Public methods:

	// Get pending input and process it
	void Do();

	// Constructor
	CConsoleCmds();

	// Simple destructor
	~CConsoleCmds();

protected:					// Protected methods:

	// Process one command
	void ProcessCmd(char *cmd);

	// ver[sion]
	static void TranslateVersion(char *args);
	// quit | exit
	static void TranslateQuit(char *args);
	// realm[list]
	static void TranslateRealm(char *args);
	// rel[oad]
	static void TranslateReload(char *args);
	// broad[cast]
	static void TranslateBroad(char *args);
	// help | ?
	static void TranslateHelp(char *command);

	// Protected data:
	// Pending input
	char * cmd;

	// Current position in cmd buffer
	int pos;

	// Platform independent asynchronous console functions
	CAConsole AConsole;
};
//******************************************************************************
