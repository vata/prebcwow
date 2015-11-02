#include "StdAfx.h"

using namespace std;

DatabaseMysql::DatabaseMysql() : Database(), mMysql(0)
{
}

DatabaseMysql::~DatabaseMysql()
{
    if (mMysql)
        mysql_close(mMysql);
}

bool DatabaseMysql::Initialize(const char *infoString)
{
	

    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);

	if (!mysqlInit)
    {
//        sLog.Log(L_CRITICAL, "Could not initialize Mysql\n");
        sLog.outError( "Could not initialize Mysql" );
        return false;
    }

	vector<string> tokens = StrSplit(infoString, ";");
    std::string params[4] = { "", "", "", "" };

	vector<string>::iterator iter;

    std::string host, user, password, database;
    iter = tokens.begin();

    if(iter != tokens.end())
        host = *iter++;
    if(iter != tokens.end())
        user = *iter++;
    if(iter != tokens.end())
        password = *iter++;
    if(iter != tokens.end())
        database = *iter++;

    mMysql = mysql_real_connect(mysqlInit, host.c_str(), user.c_str(),
                                    password.c_str(), database.c_str(), 0, 0, 0);
	
    if (mMysql)
        sLog.outDetail( "Connected to MySQL database at %s\n",
            host.c_str());
    else
        sLog.outError( "Could not connect to MySQL database at %s: %s\n",
            host.c_str(),mysql_error(mysqlInit));


    if(mMysql)
        return true;
    else
        return false;
}

QueryResult* DatabaseMysql::Query(const char *sql)
{
    if (!mMysql)
        return 0;

    //sLog.outDetail( (std::string("SQL: ") + sql).c_str() );

    if (mysql_query(mMysql, sql))
        return 0;

    MYSQL_RES *result = mysql_store_result(mMysql);

    uint64 rowCount = mysql_affected_rows(mMysql);
    uint32 fieldCount = mysql_field_count(mMysql);

//    uint64 rowCount = mysql_num_rows(result);
//    uint32 fieldCount = mysql_num_fields(result);

    // Did the query succeed? And did it return any result set?
    if (result == 0)
    {
        if (fieldCount == 0)
            return 0; // no results
        else
        {
//            sLog.Log(L_ERROR, "Query result storage failed in query \"%s\"\n", sql);
            return 0;
        }
    }
    else
    {
		if (rowCount == 0) {
			mysql_free_result (result);
            return 0;
		}
    }

    QueryResultMysql *queryResult = new QueryResultMysql(result, rowCount, fieldCount);
    if(!queryResult)
    {
//        sLog.Log(L_ERROR, "Out of memory on query result allocation in query \"%s\"\n", sql);
		mysql_free_result (result);
        return 0;
    }

    queryResult->NextRow();

    return queryResult;
}


bool DatabaseMysql::Execute(const char *sql)
{
    if (!mMysql)
        return false;

    //sLog.outDetail( (std::string("SQL: ") + sql).c_str() );

    if (mysql_query(mMysql, sql))
        return false;

    return true;
}

bool DatabaseMysql::PExecute(const char * format,...)
{
    if (!mMysql||!format)
        return false;
	va_list ap;
	char szQuery [512];
	va_start(ap, format);
	vsprintf( szQuery, format, ap );
	va_end(ap);

    if (mysql_query(mMysql, szQuery))
        return false;

    return true;
}