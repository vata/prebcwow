//******************************************************************************
#include "StdAfx.h"
#include "RealmList.h"
//==============================================================================
createFileSingleton( RealmList );
//==============================================================================
RealmList::~RealmList( )
{
	for( RealmMap::iterator i = _realms.begin(); i != _realms.end(); ++i )
		delete i->second;

	_realms.clear( );
}
//------------------------------------------------------------------------------
void RealmList::LoadRealms( void )
{
    QueryResult *result = sDatabase.Query( "SELECT * FROM realms ORDER BY id ASC" );
	int count = 0;
    do
    {
     Field *fields = result->Fetch();

	 Realm *cTmpRealm = new Realm ( );
	 cTmpRealm->name       = fields[1].GetString();
	 
	 const char * name = cTmpRealm->name.c_str();
	 RemoveRealm( name );
	 cTmpRealm->address    = fields[2].GetString();
	 cTmpRealm->icon       = fields[3].GetUInt8();
	 cTmpRealm->color      = fields[4].GetUInt8();
	 cTmpRealm->timezone   = fields[5].GetUInt8();
	 cTmpRealm->population = fields[7].GetFloat();

	 AddRealm( cTmpRealm );
	 ++count;
    } while(result->NextRow());
	sLog.outDetail(" ::[%d Realms Loaded In RealmList]", count);
}
//------------------------------------------------------------------------------
void RealmList::AddRealm( Realm *TmpRealm )
{	
	const char * name = TmpRealm->name.c_str();
	RemoveRealm( name );
	_realms[ name ] = new Realm( );
	_realms[ name ]->address = TmpRealm->address;
	_realms[ name ]->icon = TmpRealm->icon;
	_realms[ name ]->color = TmpRealm->color;
	_realms[ name ]->timezone = TmpRealm->timezone;
	_realms[ name ]->population = TmpRealm->population;
}
//------------------------------------------------------------------------------
void RealmList::SetRealm( const char * name, uint8 icon, uint8 color, uint8 timezone )
{
	if( _realms.find( name ) != _realms.end( ) )
	{
		_realms[ name ]->icon = icon;
		_realms[ name ]->color = color;
		_realms[ name ]->timezone = timezone;
	}
}
//------------------------------------------------------------------------------
void RealmList::RemoveRealm( const char * name )
{
	if( _realms.find( name ) != _realms.end( ) )
	{
		delete _realms[ name ];
		_realms.erase( name );
	}
}
//******************************************************************************
