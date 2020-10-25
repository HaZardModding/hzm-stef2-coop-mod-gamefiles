//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/worldspawn.h                                   $
// $Revision:: 11                                                             $
//   $Author:: Steven                                                         $
//     $Date:: 7/02/01 10:12a                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/worldspawn.h                                        $
// 
// 11    7/02/01 10:12a Steven
// Weather stuff.
// 
// 10    6/18/01 11:10a Sketcher
// Moved PerObjectScripting stuff to Entity, where it belongs
// 
// 9     6/12/01 8:40a Steven
// Added farplane fog stuff.
// 
// 8     6/01/01 7:56a Steven
// Added wind stuff.
// 
// 7     5/29/01 1:28p Steven
// Lightmap optimizations and dynamic lightmaps.
// 
// 6     5/03/01 4:38p Steven
// Worked on water, slime, & lava screen blend stuff.
// 
// 5     5/01/01 1:58p Steven
// Entity fade out stuff.
// 
// 4     3/30/01 1:40p Steven
// Added global terrain option.
// 
// 3     1/16/01 2:12p Steven
// Script C merge.
// 
// 2     12/11/00 3:19p Steven
// Made str passing const references.
//
// 12    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 11    9/12/00 7:03p Aldie
// Complete overhaul of the deathmatch stuff I wrote 2 weeks ago.  More to
// come.  Intermediate checkin
//
// 10    9/01/00 7:09p Aldie
// More fakk arena work
//
// 9     7/25/00 11:32p Aldie
// Made some changes to the memory system and fixed a memory allocation bug in
// Z_TagMalloc.  Also changed a lot of classes to subclass from Class.
//
// 8     7/11/00 10:57p Markd
// fixed map naming problem
//
// 7     5/27/00 2:56p Markd
// Save games 2nd pass
//
// 6     5/24/00 3:14p Markd
// first phase of save/load games
//
// 5     3/31/00 11:45a Markd
// Added skyportal toggling support
//
// 4     2/21/00 7:03p Markd
// Added skyalpha support
//
// 3     12/17/99 6:35p Jimdose
// changed spawnarg code
// added Level class for spawning and map control
// got rid of unused or superflous variables
// changed setjmp/longjmp calls to try/throw/catch exception handling
//
// 2     9/28/99 7:13p Markd
// working on documenting worldspawn
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 6     8/15/99 4:42p Markd
// Put in far clipping plane support into worldspawn
//
// DESCRIPTION:
// Base class for worldspawn objects.  This should be subclassed whenever
// a DLL has new game behaviour that needs to be initialized before any other
// entities are created, or before any entity thinks each frame.  Also controls
// spawning of clients.
//

class TargetList;
class DynamicLightInfo;
class WindInfo;
class World;

#ifndef __WORLDSPAWN_H__
#define __WORLDSPAWN_H__

#include "entity.h"
#include "../qcommon/qfiles.h"

class TargetList : public Class
	{
   public:
      CLASS_PROTOTYPE( TargetList );
      Container<Entity *>  list;
      str                  targetname;
		int                  index;

		TargetList();
      TargetList( const str &tname );
		~TargetList();
      void     AddEntity( Entity * ent );
      void     RemoveEntity( Entity * ent );
      Entity   *GetNextEntity( Entity * ent );

		virtual void	Archive( Archiver &arc );
	};

class DynamicLightInfo
	{
   public:
		float		intensity;

		float		start_intensity;
		float		end_intensity;

		float		start_fade_time;
		float		fade_time;

		str		lightstyle;
		int		current_lightstyle_position;
		qboolean	stop_at_end;

		DynamicLightInfo();
		virtual void	Archive( Archiver &arc );
	};

inline void DynamicLightInfo::Archive
	(
	Archiver &arc
	)

	{
   arc.ArchiveFloat( &intensity );
	arc.ArchiveFloat( &start_intensity );
	arc.ArchiveFloat( &end_intensity );

	arc.ArchiveFloat( &start_fade_time );
	arc.ArchiveFloat( &fade_time );

	arc.ArchiveString( &lightstyle );
	arc.ArchiveInteger( &current_lightstyle_position );
	arc.ArchiveBoolean( &stop_at_end );
	}

class WindInfo
	{
   public:
		float		intensity;

		float		start_intensity;
		float		end_intensity;

		float		min_intensity;
		float		max_intensity;

		float		start_fade_time;
		float		fade_time;

		float		gust_time;

		float		max_change;

		WindInfo();
		virtual void	Archive( Archiver &arc );
	};

inline void WindInfo::Archive
	(
	Archiver &arc
	)

	{
   arc.ArchiveFloat( &intensity );
	arc.ArchiveFloat( &start_intensity );
	arc.ArchiveFloat( &end_intensity );

	arc.ArchiveFloat( &min_intensity );
	arc.ArchiveFloat( &max_intensity );

	arc.ArchiveFloat( &start_fade_time );
	arc.ArchiveFloat( &fade_time );

	arc.ArchiveFloat( &gust_time );

	arc.ArchiveFloat( &max_change );
	}

class WeatherInfo
	{
   public:
		weather_t	type;
		int			intensity;

		WeatherInfo();
		virtual void	Archive( Archiver &arc );
	};

inline void WeatherInfo::Archive
	(
	Archiver &arc
	)

	{
	arc.ArchiveInteger( (int *)&type );
   arc.ArchiveInteger( &intensity );
	}

class World : public Entity
	{
   private:
      Container<TargetList *> targetList;
      qboolean                world_dying;
	public:
      CLASS_PROTOTYPE( World );

		               World();
		               ~World();

      str            skipthread;
      float          farplane_distance;
      Vector         farplane_color;
      qboolean       farplane_cull;
		qboolean       farplane_fog;

		qboolean			terrain_global;
		float				terrain_global_min;

		float				entity_fade_dist;

		DynamicLightInfo	dynamic_lights[ MAX_LIGHTING_GROUPS ];

		WindInfo			wind;

		WeatherInfo		weather;

      float          sky_alpha;
      qboolean       sky_portal;

      void           FreeTargetList( void );
      //TargetList     *GetTargetList( const str &targetname );
		TargetList     *GetTargetList( const str &targetname, qboolean createnew = qtrue );
      TargetList     *GetTargetList( int index );
      void           AddTargetEntity( const str &targetname, Entity * ent );
      void           RemoveTargetEntity( const str &targetname, Entity * ent );
      Entity         *GetNextEntity( const str &targetname, Entity * ent );
      void           SetSoundtrack( Event *ev );
      void           SetGravity( Event *ev );
      void           SetSkipThread( Event *ev );
      void           SetNextMap( Event *ev );
      void           SetMessage( Event *ev );
      void           SetScript( Event *ev );
      void           SetWaterColor( Event *ev );
      void           SetWaterAlpha( Event *ev );
		void           SetSlimeColor( Event *ev );
      void           SetSlimeAlpha( Event *ev );
      void           SetLavaColor( Event *ev );
      void           SetLavaAlpha( Event *ev );
      void           SetFarPlane_Color( Event *ev );
      void           SetFarPlane_Cull( Event *ev );
		void           SetFarPlane_Fog( Event *ev );
      void           SetFarPlane( Event *ev );
		void           SetTerrainGlobal( Event *ev );
		void           SetTerrainGlobalMin( Event *ev );
		void           SetEntityFadeDist( Event *ev );
      void           SetSkyAlpha( Event *ev );
      void           SetSkyPortal( Event *ev );
      void           SetNumArenas( Event *ev );
      void           UpdateConfigStrings( void );
      void           UpdateFog( void );
		void           UpdateTerrain( void );
		void           UpdateEntityFadeDist( void );
		void           UpdateDynamicLights( void );
		void           UpdateWindIntensity( void );
		void           UpdateWeather( void );
      void           UpdateSky( void );

		void           SetLightIntensity( Event *ev );
		void           SetLightFade( Event *ev );
		void           SetLightLightstyle( Event *ev );
		void           GetLightIntensity( Event *ev );

		void           SetWindIntensity( Event *ev );
		void           SetWindGust( Event *ev );
		void           SetWindFade( Event *ev );
		void           SetWindMinMax( Event *ev );
		void           SetWeather( Event *ev );

		void				Think( void );

      virtual void   Archive( Archiver &arc );
	};

inline void World::Archive
	(
	Archiver &arc
	)

	{
	int i;

   if ( arc.Loading() )
      {
      FreeTargetList();
      }

   Entity::Archive( arc );

   arc.ArchiveString( &skipthread );
   arc.ArchiveFloat( &farplane_distance );
   arc.ArchiveVector( &farplane_color );
   arc.ArchiveBoolean( &farplane_cull );
	arc.ArchiveBoolean( &farplane_fog );
	arc.ArchiveBoolean( &terrain_global );
	arc.ArchiveFloat( &terrain_global_min );
	arc.ArchiveFloat( &entity_fade_dist );
   arc.ArchiveFloat( &sky_alpha );
   arc.ArchiveBoolean( &sky_portal );

	for( i = 0 ; i < MAX_LIGHTING_GROUPS ; i++ )
		dynamic_lights[ i ].Archive( arc );

	wind.Archive( arc );

	weather.Archive( arc );

   if ( arc.Loading() )
      {
      UpdateConfigStrings();
      UpdateFog();
		UpdateTerrain();
      UpdateSky();
		UpdateDynamicLights();
		UpdateWindIntensity();
		UpdateWeather();
      }
	}

inline void TargetList::Archive(	Archiver &arc )
{
	int num, i;

	Class::Archive( arc );

	if ( arc.Saving() )
		num = list.NumObjects();

	arc.ArchiveInteger( &num );

	if ( arc.Loading() ) {
		list.ClearObjectList();
		list.Resize( num );
	}

	for ( i = 1; i <= num; i++ )
		arc.ArchiveObjectPointer( ( Class ** )list.AddressOfObjectAt( i ) );

	arc.ArchiveString( &targetname );
	arc.ArchiveInteger( &index );
}

inline TargetList *World::GetTargetList
   (
   int index
   )
   
   {
   return targetList.ObjectAt( index );
   }

typedef SafePtr<World> WorldPtr;
extern WorldPtr world;

#endif /* worldspawn.h */