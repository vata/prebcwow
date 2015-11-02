#include "stdafx.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	std::memset(&std::cin, EOF, sizeof std::cin);
	cout << "  ::[Welcome to the CRFusion Simulator ConfMaker]::\n\n" << endl;
	Config *Conf = new Config();

	printf(":: DataBase connection info.\n >=Host: ");
	fscanf(stdin, "%s", &Conf->dbHost);
	printf(" >=User: ");
	fscanf(stdin, "%s", &Conf->dbUser);
	printf(" >=Pass: ");
	fscanf(stdin, "%s", &Conf->dbPass);
	printf(" >=DataBase Name: ");
	fscanf(stdin, "%s", &Conf->dbName);
	printf("\n\n");

	printf(":: Realm Configuration\n");
	printf(" >Do you want to use SQL RealmList ? (0 no / 1 yes)\n");
	fscanf(stdin, "%s", &Conf->rSql);

	if(Conf->rSql==true)
	{
		printf(" >=Realm Address\n  :");
		fscanf(stdin, "%s", &Conf->rAddr);

		printf(" >=Realm Port\n  :");
		fscanf(stdin, "%s", &Conf->rPort);
	}
	printf("\n:: Logging Levels #0 = Minimum; 1 = Error; 2 = Detailed; 3 = Full/Debug\n");
Logging:
	printf(" >=LogLevel: ");
	fscanf(stdin, "%d", &Conf->logLvl);
	if(Conf->logLvl > 3)
	{
		printf("Bad Option (0 to 3).\n");
		goto Logging;
	}
	printf("\n:: Server Player Limit (excluding GMs): ");
	fscanf(stdin, "%d", &Conf->pLimit);

	printf("\n:: Server MotD: 'Welcome on %s. Have a nice day :)' #Can be changed manually#\n", Conf->rName);
	//printf("\n:: Server Motd:");
	//fscanf(stdin, "%.*s", &Conf->rMotd);

	printf("\n:: Config FileName: ");
	fscanf(stdin, "%s", &Conf->cFileName);

	ofstream cFile (Conf->cFileName, ios::trunc);
	if(!cFile.is_open())
		printf("\n!: The file \"%s\" couldn't be opened.", Conf->cFileName);
	else
	{
		cFile<<"# This Config File was Generated by ConfMaker for CRFusion Server.\n"
			// Writing DataBase informations
		<< "DatabaseInfo = \"" << Conf->dbHost <<";"
		<< Conf->dbUser <<";"
		<< Conf->dbPass <<";"
		<< Conf->dbName <<"\"\n"
			// Writing Realm Informations
		<< "SqlRealmList = " << Conf->rSql << "\n";
		if(Conf->rSql==true)
		{
			cFile<< "RealmName = \"" << Conf->rName <<"\"\n"
			<< "RealmAddr = " << Conf->rAddr <<"\n"
			<< "RealmPort = " << Conf->rPort <<"\n";
		}
			// Writing Log Level Informations
		cFile<< "LogLevel = "  << Conf->logLvl <<"\n"
			// Writing Player Limit
		<< "PlayerLimit = " << Conf->pLimit <<"\n"
			// Writing MotD
		<< "Motd = \"" << "Welcome on " << Conf->rName << ". Have a nice day :)" <<"\"\n";
		//<< "Motd = \"" << Conf->rMotd <<"\"\n";
	  printf("\n# Config File Successfully Generated :)\n");
	}
	system("PAUSE");
}