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

#ifndef QUAD_MAPMANAGER_H
#define QUAD_MAPMANAGER_H

#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include "zthread/Mutex.h"
#include "Common.h"
#include "Map.h"
#include "GridStates.h"

class Transport;

class QUAD_DLL_DECL MapManager : public Quad::Singleton<MapManager, Quad::ClassLevelLockable<MapManager, ZThread::Mutex> >
{

    friend class Quad::OperatorNew<MapManager>;
    typedef UNORDERED_MAP<uint32, Map*> MapMapType;
    typedef std::pair<UNORDERED_MAP<uint32, Map*>::iterator, bool>  MapMapPair;

    public:

        Map* GetMap(uint32, const WorldObject* obj);
        Map* FindMap(uint32 mapid) { return _findMap(mapid); }
        Map* FindMap(uint32 mapid, uint32 instanceId);

        // only const version for outer users
        Map const* GetBaseMap(uint32 id) const { return const_cast<MapManager*>(this)->_GetBaseMap(id); }
        void DeleteInstance(uint32 mapid, uint32 instanceId);

        uint16 GetAreaFlag(uint32 mapid, float x, float y, float z) const
        {
            Map const* m = GetBaseMap(mapid);
            return m->GetAreaFlag(x, y, z);
        }
        uint32 GetAreaId(uint32 mapid, float x, float y, float z) const
        {
            return Map::GetAreaIdByAreaFlag(GetAreaFlag(mapid, x, y, z),mapid);
        }
        uint32 GetZoneId(uint32 mapid, float x, float y, float z) const
        {
            return Map::GetZoneIdByAreaFlag(GetAreaFlag(mapid, x, y, z),mapid);
        }
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid, uint32 mapid, float x, float y, float z)
        {
            Map::GetZoneAndAreaIdByAreaFlag(zoneid,areaid,GetAreaFlag(mapid, x, y, z),mapid);
        }

        void Initialize(void);
        void Update(uint32);

        void SetGridCleanUpDelay(uint32 t)
        {
            if( t < MIN_GRID_DELAY )
                i_gridCleanUpDelay = MIN_GRID_DELAY;
            else
                i_gridCleanUpDelay = t;
        }

        void SetMapUpdateInterval(uint32 t)
        {
            if( t > MIN_MAP_UPDATE_DELAY )
                t = MIN_MAP_UPDATE_DELAY;

            i_timer.SetInterval(t);
            i_timer.Reset();
        }

        //void LoadGrid(int mapid, float x, float y, const WorldObject* obj, bool no_unload = false);
        void UnloadAll();

        static bool ExistMapAndVMap(uint32 mapid, float x, float y);
        static bool IsValidMAP(uint32 mapid);

        static bool IsValidMapCoord(uint32 mapid, float x,float y)
        {
            return IsValidMAP(mapid) && Quad::IsValidMapCoord(x,y);
        }

        static bool IsValidMapCoord(uint32 mapid, float x,float y,float z)
        {
            return IsValidMAP(mapid) && Quad::IsValidMapCoord(x,y,z);
        }

        static bool IsValidMapCoord(uint32 mapid, float x,float y,float z,float o)
        {
            return IsValidMAP(mapid) && Quad::IsValidMapCoord(x,y,z,o);
        }

        static bool IsValidMapCoord(WorldLocation const& loc)
        {
            return IsValidMapCoord(loc.mapid,loc.x,loc.y,loc.z,loc.o);
        }

        void DoDelayedMovesAndRemoves();

        void LoadTransports();

        typedef std::set<Transport *> TransportSet;
        TransportSet m_Transports;

        typedef std::map<uint32, TransportSet> TransportMap;
        TransportMap m_TransportsByMap;

        bool CanPlayerEnter(uint32 mapid, Player* player);
        void RemoveBonesFromMap(uint32 mapid, uint64 guid, float x, float y);
        uint32 GenerateInstanceId() { return ++i_MaxInstanceId; }
        void InitMaxInstanceId();

        /* statistics */
        uint32 GetNumInstances();
        uint32 GetNumPlayersInInstances();

    private:
        // debugging code, should be deleted some day
        void checkAndCorrectGridStatesArray();              // just for debugging to find some memory overwrites
        GridState* i_GridStates[MAX_GRID_STATE];            // shadow entries to the global array in Map.cpp
        int i_GridStateErrorCount;
    private:
        MapManager();
        ~MapManager();

        MapManager(const MapManager &);
        MapManager& operator=(const MapManager &);

        Map* _GetBaseMap(uint32 id);
        Map* _findMap(uint32 id) const
        {
            MapMapType::const_iterator iter = i_maps.find(id);
            return (iter == i_maps.end() ? NULL : iter->second);
        }

        typedef Quad::ClassLevelLockable<MapManager, ZThread::Mutex>::Lock Guard;
        uint32 i_gridCleanUpDelay;
        MapMapType i_maps;
        IntervalTimer i_timer;

        uint32 i_MaxInstanceId;
};
#endif

