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

/// \addtogroup logon
/// @{
/// \file

#ifndef _LOGONLIST_H
#define _LOGONLIST_H

#include "Common.h"

/// Storage object for a logon
struct Logon
{
    std::string address;
    std::string name;
    uint8 icon;
    uint8 color;
    uint8 timezone;
    uint32 m_ID;
    AccountTypes allowedSecurityLevel;
    float populationLevel;
};

/// Storage object for the list of logons on the server
class LogonList
{
    public:
        typedef std::map<std::string, Logon> LogonMap;

        LogonList();
        ~LogonList() {}

        void Initialize(uint32 updateInterval);

        void UpdateIfNeed();

        LogonMap::const_iterator begin() const { return m_logons.begin(); }
        LogonMap::const_iterator end() const { return m_logons.end(); }
        uint32 size() const { return m_logons.size(); }
    private:
        void UpdateLogons(bool init);
        void UpdateLogon( uint32 ID, const std::string& name, const std::string& address, uint32 port, uint8 icon, uint8 color, uint8 timezone, AccountTypes allowedSecurityLevel, float popu);
    private:
        LogonMap m_logons;                                  ///< Internal map of logons
        uint32   m_UpdateInterval;
        time_t   m_NextUpdateTime;
};
#endif
/// @}
