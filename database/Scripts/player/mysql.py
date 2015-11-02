#
# MYSQL CONNECTOR for WoW Server
#
# Author      :  Kosuha
# Modified by :  Cain Wong
# Version     :  v.1.1
# Features    :  - Allow all properties retrieve from the given entry id
#                - Allow specified properties to retrieve from the given entry id (Not Tested Yet)
#
# MYSQL CONNECTOR is used to bypass Core and receive information directly
#                 from MySQL server for AI/XP/DR and other Python scripts.
#                 Please download and install MySQL support files from: http://sourceforge.net/projects/mysql-python
#
import MySQLdb
from MySQLdb.constants import FIELD_TYPE

# ------------------------------- MySQL Database Connector  -------------------------------#
def connect_db():
    global db, c            # Defines global use of DB and C constants in MySQL module

    host="62.85.76.21"      
    user="test"
    passwd="test"
    db="wow_server"

    db=MySQLdb.connect(host, user, passwd, db)
    c=db.cursor()           # Defines Cursor for MySQL DB

# ------------------------------- Creature MySQL Parser -------------------------------------#
# Notes: the idea for this parser is to get data in a Single (1) Querry. Of course for easier use we can querry DB for each field, but it will greately
#            increase DB load and will possible slow down overall performance of Server. The result of this function it tuple with all needed fields for Creature.

def creature(entry):        # Connects to MySQL DB of WoW Server and collects all data in 1 query for requested 1 creature (ID=entry).

    connect_db()            # Initialises connection to DB

    c.execute("""Select
    creatures_templ.creature_id,
    creatures_templ.name,
    creatures_templ.bounding_radius,
    creatures_templ.attack_min,
    creatures_templ.attack_max,
    creatures_templ.combat_reach,
    creatures_templ.level_min,
    creatures_templ.level_max,
    creatures_templ.damage_min,
    creatures_templ.damage_max,
    creatures_templ.faction,
    creatures_templ.flags1,
    creatures_templ.guild,
    creatures_templ.maxhealth,
    creatures_templ.maxmana,
    creatures_templ.model,
    creatures_templ.npcflags,
    creatures_templ.speed,
    creatures_templ.size,
    creatures_templ.`type`,
    creatures_templ.family,
    creatures_templ.elite,
    creatures_templ.class,
    creatures_templ.mount
    From creatures_templ
    Where
    creatures_templ.creature_id = %s""", (entry,))

    return c.fetchone()

    # Results can be obtained by extracting needed value from Tuple.
    # c.fetchone() [1] = name
    # c.fetchone() [2] = bounding_radius
    # and etc.
    # Do not modify this parser and extract data from tuple in otside script.


# Connects to MySQL DB of WoW Server and collects specified data in 1 query for requested 1 creature (ID=entry).
# Use the ListVar = ['name', ...] to intial the list before passing the ListVar to this function or directly pass the list to the calling function.
def creature_props(entry, props):

    connect_db()            # Initialises connection to DB

    tbl = ',creatures_templ.'
    sqlstr = tbl + tbl.join (props)

    c.execute("""Select
    creatures_templ.creature_id
    %s
    From creatures_templ
    Where
    creatures_templ.creature_id = %s""", (sqlstr, entry))

    return c.fetchone()

    # Results can be obtained by extracting needed value from Tuple.
    # c.fetchone() [1] = name
    # c.fetchone() [2] = bounding_radius
    # and etc.
    # Do not modify this parser and extract data from tuple in otside script.
