/*
 * Copyright (C) 2009 QuadCore <http://github.com/QuaDCore/QuaDCore/tree/master>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/** \file
    \ingroup logon
*/

#include "Common.h"
#include "LogonList.h"
#include "Policies/SingletonImp.h"
#include "Database/DatabaseEnv.h"

INSTANTIATE_SINGLETON_1( LogonList );

extern DatabaseType LoginDatabase;

LogonList::LogonList( ) : m_UpdateInterval(0), m_NextUpdateTime(time(NULL))
{
}

/// Load the logon list from the database
void LogonList::Initialize(uint32 updateInterval)
{
    m_UpdateInterval = updateInterval;

    ///- Get the content of the logonlist table in the database
    UpdateLogons(true);
}

void LogonList::UpdateLogon( uint32 ID, const std::string& name, const std::string& address, uint32 port, uint8 icon, uint8 color, uint8 timezone, AccountTypes allowedSecurityLevel, float popu)
{
    ///- Create new if not exist or update existed
    Logon& logon = m_logons[name];

    logon.m_ID      = ID;
    logon.name      = name;
    logon.icon      = icon;
    logon.color     = color;
    logon.timezone  = timezone;
    logon.allowedSecurityLevel = allowedSecurityLevel;
    logon.populationLevel        = popu;

    ///- Append port to IP address.
    std::ostringstream ss;
    ss << address << ":" << port;
    logon.address   = ss.str();
}

void LogonList::UpdateIfNeed()
{
    // maybe disabled or updated recently
    if(!m_UpdateInterval || m_NextUpdateTime > time(NULL))
        return;

    m_NextUpdateTime = time(NULL) + m_UpdateInterval;

    // Clears Logon list
    m_logons.clear();

    // Get the content of the logonlist table in the database
    UpdateLogons(false);
}

void LogonList::UpdateLogons(bool init)
{
    sLog.outDetail("Updating Logon List...");

    QueryResult *result = LoginDatabase.Query( "SELECT id, name, address, port, icon, color, timezone, allowedSecurityLevel, population FROM logonlist WHERE color <> 3 ORDER BY name" );

    ///- Circle through results and add them to the logon map
    if(result)
    {
        do
        {
            Field *fields = result->Fetch();

            uint8 allowedSecurityLevel = fields[7].GetUInt8();

            UpdateLogon(fields[0].GetUInt32(), fields[1].GetCppString(),fields[2].GetCppString(),fields[3].GetUInt32(),fields[4].GetUInt8(), fields[5].GetUInt8(), fields[6].GetUInt8(), (allowedSecurityLevel <= SEC_ADMINISTRATOR ? AccountTypes(allowedSecurityLevel) : SEC_ADMINISTRATOR), fields[8].GetFloat() );
            if(init)
                sLog.outString("Added logon \"%s\".", fields[1].GetString());
        } while( result->NextRow() );
        delete result;
    }
}
