#pragma once

#include <iostream>
#include <fstream>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char str;
struct Config {
	  str dbHost[15];
	  str dbUser[20];
	  str dbPass[20];
	  str dbName[20];
	  str rName[25];
	  str rAddr[40];
	  str rPort[5];
const char* rMotd;
	  bool rSql;
      int logLvl;
	  int pLimit;
	  str cFileName[20];
};