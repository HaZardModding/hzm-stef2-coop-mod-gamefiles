//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/worldspawn.cpp                                 $
// $Revision:: 14                                                             $
//   $Author:: Steven                                                         $
//     $Date:: 7/26/01 8:15a                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/worldspawn.cpp                                      $
// 
// 14    7/26/01 8:15a Steven
// Added rain with no splashes.
// 
// 13    7/12/01 2:37p Steven
// Fixed some farplane culling.
// 
// 12    7/12/01 11:32a Steven
// Fixed a farplane issue.
// 
// 11    7/02/01 10:12a Steven
// Weather stuff.
// 
// 10    6/12/01 8:40a Steven
// Added farplane fog stuff.
// 
// 9     6/04/01 1:28p Steven
// Fixed wind event.
// 
// 8     6/01/01 7:56a Steven
// Added wind stuff.
// 
// 7     5/29/01 1:28p Steven
// Lightmap optimizations and dynamic lightmaps.
// 
// 6     5/03/01 4:37p Steven
// Worked on water, slime, & lava screen blend stuff.
// 
// 5     5/01/01 1:56p Steven
// Entity fade out stuff.
// 
// 4     3/30/01 1:39p Steven
// Added global terrain option.
// 
// 3     1/16/01 2:11p Steven
// Script C merge.
// 
// 2     12/11/00 3:17p Steven
// Made str passing const references.
//
// 26    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 25    9/12/00 7:03p Aldie
// Complete overhaul of the deathmatch stuff I wrote 2 weeks ago.  More to
// come.  Intermediate checkin
//
// 24    9/01/00 7:09p Aldie
// More fakk arena work
//
// 23    7/29/00 4:47p Markd
// made "null" skipthreads act as clear
//
// 22    7/25/00 11:32p Aldie
// Made some changes to the memory system and fixed a memory allocation bug in
// Z_TagMalloc.  Also changed a lot of classes to subclass from Class.
//
// 21    7/18/00 2:11p Aldie
// Added a reset for sv_cinematic
//
// 20    7/11/00 10:57p Markd
// fixed map naming problem
//
// 19    6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 18    6/12/00 9:23p Markd
// Added refeshable image support, rewrote screenshots, added loadsave
// functionality
//
// 17    5/29/00 1:16p Markd
// 3rd round of saved games
//
// 16    3/31/00 11:45a Markd
// Added skyportal toggling support
//
// 15    2/21/00 7:03p Markd
// Added skyalpha support
//
// 14    1/27/00 4:05p Markd
// Fixed up sunflare and allowed it to function from portalskys
//
// 13    1/10/00 10:28a Markd
// added world targetname to worldspawn
//
// 12    1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 11    12/17/99 6:35p Jimdose
// changed spawnarg code
// added Level class for spawning and map control
// got rid of unused or superflous variables
// changed setjmp/longjmp calls to try/throw/catch exception handling
//
// 10    12/11/99 3:37p Markd
// q3a gold checkin, first time
//
// 9     11/12/99 6:52p Markd
// fixed up sound manager saving and loading
//
// 8     11/05/99 5:55p Markd
// Added user-interface to camera system
//
// 7     9/30/99 1:49p Aldie
// Documentation of commands
//
// 6     9/28/99 7:13p Markd
// working on documenting worldspawn
//
// 5     9/27/99 5:45p Markd
// began documentation and cleanup phase after merge
//
// 4     9/20/99 4:50p Markd
// fixed memory allocation for snapshot entities, put in farplane culling on
// entities being sent over the net
//
// 3     9/16/99 11:19a Markd
// Continuing merge of code, not functional yet but closer
//
// 2     9/15/99 6:57p Aldie
// Update to get game working
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 14    8/30/99 8:55p Markd
// Fixed farplane stuff and potential configstring bugs in code
//
// 13    8/17/99 5:08p Markd
// Changed all FS_ReadFile's to FS_ReadFileEx's in game code
//
// 12    8/15/99 4:42p Markd
// Put in far clipping plane support into worldspawn
//
// 11    6/11/99 1:23p Phook
//
// 10    6/11/99 12:58p Phook
// Changed from SINED comments to QUAKED
//
// DESCRIPTION:
// Base class for worldspawn objects.  This should be subclassed whenever
// a DLL has new game behaviour that needs to be initialized before any other
// entities are created, or before any entity thinks each frame.  Also controls
// spawning of clients.
//

#include "g_local.h"
#include "entity.h"
#include "scriptmaster.h"
#include "worldspawn.h"
#include "gravpath.h"
#include "earthquake.h"
#include "specialfx.h"
#include "soundman.h"
#include "dm_manager.h"

extern void CreateMissionComputer( void );

WorldPtr  world;

#define DEFAULT_ENTITY_FADE_DIST  3000

/*****************************************************************************/
/*QUAKED worldspawn (0 0 0) ? CINEMATIC

Only used for the world.

"soundtrack" the soundtrack to use on the map
"gravity"	 800 is default gravity
"skipthread" thread that is activated to skip this level (if cinematic)
"nextmap"    map to goto when player exits
"message"	 text to print at user logon
"script"	    script to run on start of map
"watercolor" view color when underwater
"wateralpha" view alpha when underwater
"lavacolor"  view alpha when in lava
"lavaalpha"  view alpha when in lava
"farplane_color" color to fade to when the far clip plane is on
"farplane_cull" whether or not the far plane should cull, default is yes
"farplane_fog" whether or not to use fog with farplane
"farplane"   distance from the viewer that the far clip plane is
"ambientlight" ambient lighting to be applied to all entities
"ambient"    ambient lighting to be applied to all entities, use _color to specify color
"suncolor"   color of the sun in the level
"sunlight"   intensity of the sun in the level
"sundirection" direction of the sun in the level
"sunflare"   worldspace position of the sun flare
"sunflare_inportalsky" whether or not the flare is in the portal sky
"lightmapdensity" default lightmap density to be used for all surfaces
"skyalpha"   initial value of the sky's alpha, defaults to 1

******************************************************************************/

#define CINEMATIC 1

Event EV_World_SetSoundtrack
   (
   "soundtrack",
   EV_DEFAULT,
   "s",
   "MusicFile",
   "Set music soundtrack for this level."
   );
Event EV_World_SetGravity
   (
   "gravity",
   EV_DEFAULT,
   "f",
   "worldGravity",
   "Set the gravity for the whole world."
   );
Event EV_World_SetSkipThread
   (
   "skipthread",
   EV_DEFAULT,
   "s",
   "skipThread",
   "Set the thread for skipping cinematics"
   );
Event EV_World_SetNextMap
   (
   "nextmap",
   EV_DEFAULT,
   "s",
   "nextMap",
   "Set the next map to change to"
   );
Event EV_World_SetMessage
   (
   "message",
   EV_DEFAULT,
   "s",
   "worldMessage",
   "Set a message for the world"
   );
Event EV_World_SetScript
   (
   "script",
   EV_DEFAULT,
   "s",
   "worldScript",
   "Set the script for this map"
   );
Event EV_World_SetWaterColor
   (
   "watercolor",
   EV_DEFAULT,
   "v",
   "waterColor",
   "Set the watercolor screen blend"
   );
Event EV_World_SetWaterAlpha
   (
   "wateralpha",
   EV_DEFAULT,
   "f",
   "waterAlpha",
   "Set the alpha of the water screen blend"
   );
Event EV_World_SetSlimeColor
   (
   "slimecolor",
   EV_DEFAULT,
   "v",
   "slimeColor",
   "Set the slimecolor screen blend"
   );
Event EV_World_SetSlimeAlpha
   (
   "slimealpha",
   EV_DEFAULT,
   "f",
   "slimeAlpha",
   "Set the alpha of the slime screen blend"
   );
Event EV_World_SetLavaColor
   (
   "lavacolor",
   EV_DEFAULT,
   "v",
   "lavaColor",
   "Set the color of lava screen blend"
   );
Event EV_World_SetLavaAlpha
   (
   "lavaalpha",
   EV_DEFAULT,
   "f",
   "lavaAlpha",
   "Set the alpha of lava screen blend"
   );
Event EV_World_SetFarPlane_Color
   (
   "farplane_color",
   EV_DEFAULT,
   "v",
   "farplaneColor",
   "Set the color of the far clipping plane fog"
   );
Event EV_World_SetFarPlane_Cull
   (
   "farplane_cull",
   EV_DEFAULT,
   "b",
   "farplaneCull",
   "Whether or not the far clipping plane should cull things out of the world"
   );
Event EV_World_SetFarPlane_Fog
   (
   "farplane_fog",
   EV_DEFAULT,
   "b",
   "farplaneFog",
   "Whether or not to use fog with far plane"
   );
Event EV_World_SetFarPlane
   (
   "farplane",
   EV_DEFAULT,
   "f",
   "farplaneDistance",
   "Set the distance of the far clipping plane"
   );
Event EV_World_SetTerrainGlobal
   (
   "terrainglobal",
   EV_DEFAULT,
   "b",
   "terrain_global_bool",
   "Turns the terrain drawing as global on or off"
   );
Event EV_World_SetTerrainGlobalMin
   (
   "terrainglobalmin",
   EV_DEFAULT,
   "f",
   "terrain_global_min",
   "Turns the terrain drawing as global on and sets the minimum"
   );
Event EV_World_SetEntityFadeDist
   (
   "entity_fade_dist",
   EV_DEFAULT,
   "f",
   "entity_fade_dist",
   "Sets the default distance to fade out entities"
   );
Event EV_World_SetLightIntensity
   (
   "light_intensity",
   EV_DEFAULT,
   "sf",
   "light_group_name light_intensity",
   "Sets the intensity of a dynamic light"
   );
Event EV_World_SetLightFade
   (
   "light_fade",
   EV_DEFAULT,
   "sff",
   "light_group_name end_light_intensity fade_time",
   "Sets a up a dynamic light to fade"
   );
Event EV_World_SetLightLightstyle
   (
   "light_lightstyle",
   EV_DEFAULT,
   "ssB",
   "light_group_name light_style stop_at_end",
   "Sets the lightstyle of a dynamic light"
   );
Event EV_World_GetLightIntensity
   (
   "getlightintensity",
   EV_DEFAULT,
   "@is",
   "light_intensity light_group_name",
   "Gets the intensity of a dynamic light"
   );
Event EV_World_SetWindIntensity
   (
   "wind_intensity",
   EV_DEFAULT,
   "f",
   "wind_intensity",
   "Sets the intensity of the wind"
   );
Event EV_World_SetWindGust
   (
   "wind_gust",
   EV_DEFAULT,
   "fff",
   "wind_intensity fade_time gust_time",
   "Creates a gust of wind"
   );
Event EV_World_SetWindFade
   (
   "wind_fade",
   EV_DEFAULT,
   "ff",
   "end_wind_intensity fade_time",
   "Fades the wind intensity to the new value"
   );
Event EV_World_SetWindMinMax
   (
   "wind_minmax",
   EV_DEFAULT,
   "ffF",
   "min_wind_intensity min_wind_intensity max_change_per_frame",
   "Sets the min & max intensity of the wind"
   );
Event EV_World_SetWeather
   (
   "weather",
   EV_DEFAULT,
   "si",
   "type intensity",
   "Sets the current weather"
   );
Event EV_World_SetAmbientLight
   (
   "ambientlight",
   EV_DEFAULT,
   "b",
   "ambientLight",
   "Set whether or not ambient light should be used"
   );
Event EV_World_SetAmbientIntensity
   (
   "ambient",
   EV_DEFAULT,
   "f",
   "ambientIntensity",
   "Set the intensity of the ambient light"
   );
Event EV_World_SetSunColor
   (
   "suncolor",
   EV_DEFAULT,
   "v",
   "sunColor",
   "Set the color of the sun"
   );
Event EV_World_SetSunLight
   (
   "sunlight",
   EV_DEFAULT,
   "b",
   "sunlight",
   "Set whether or not there should be sunlight"
   );
Event EV_World_SetSunDirection
   (
   "sundirection",
   EV_DEFAULT,
   "v",
   "sunlightDirection",
   "Set the direction of the sunlight"
   );
Event EV_World_LightmapDensity
   (
   "lightmapdensity",
   EV_DEFAULT,
   "f",
   "density",
   "Set the default lightmap density for all world surfaces"
   );
Event EV_World_SunFlare
   (
   "sunflare",
   EV_DEFAULT,
   "v",
   "position_of_sun",
   "Set the position of the sun for the purposes of the sunflare"
   );
Event EV_World_SunFlareInPortalSky
   (
   "sunflare_inportalsky",
   EV_DEFAULT,
   NULL,
   NULL,
   "Let the renderer know that the sun is in the portal sky"
   );
Event EV_World_SetSkyAlpha
   (
   "skyalpha",
   EV_DEFAULT,
   "f",
   "newAlphaForPortalSky",
   "Set the alpha on the sky"
   );

Event EV_World_SetSkyPortal
   (
   "skyportal",
   EV_DEFAULT,
   "b",
   "newSkyPortalState",
   "Whether or not to use the sky portal at all"
   );

Event EV_World_SetNumArenas
   (
   "numarenas",
   EV_DEFAULT,
   "i",
   "numarenas",
   "Set the number of arenas in the world"
   );


CLASS_DECLARATION( Entity, World, "worldspawn" )
	{
      { &EV_World_SetSoundtrack,          SetSoundtrack },
      { &EV_World_SetGravity,             SetGravity },
      { &EV_World_SetSkipThread,          SetSkipThread },
      { &EV_World_SetNextMap,             SetNextMap },
      { &EV_World_SetMessage,             SetMessage },
      { &EV_World_SetScript,              SetScript },
      { &EV_World_SetWaterColor,          SetWaterColor },
      { &EV_World_SetWaterAlpha,          SetWaterAlpha },
		{ &EV_World_SetSlimeColor,          SetSlimeColor },
      { &EV_World_SetSlimeAlpha,          SetSlimeAlpha },
      { &EV_World_SetLavaColor,           SetLavaColor },
      { &EV_World_SetLavaAlpha,           SetLavaAlpha },
      { &EV_World_SetFarPlane_Color,      SetFarPlane_Color },
      { &EV_World_SetFarPlane_Cull,       SetFarPlane_Cull },
		{ &EV_World_SetFarPlane_Fog,        SetFarPlane_Fog },
      { &EV_World_SetFarPlane,            SetFarPlane },
		{ &EV_World_SetTerrainGlobal,       SetTerrainGlobal },
		{ &EV_World_SetTerrainGlobalMin,    SetTerrainGlobalMin },
		{ &EV_World_SetEntityFadeDist,      SetEntityFadeDist },
		{ &EV_World_SetLightIntensity,      SetLightIntensity },
		{ &EV_World_SetLightFade,		      SetLightFade },
		{ &EV_World_SetLightLightstyle,     SetLightLightstyle },
		{ &EV_World_GetLightIntensity,      GetLightIntensity },
		{ &EV_World_SetWindIntensity,	      SetWindIntensity },
		{ &EV_World_SetWindGust,		      SetWindGust },
		{ &EV_World_SetWindFade,		      SetWindFade },
		{ &EV_World_SetWindMinMax,		      SetWindMinMax },
		{ &EV_World_SetWeather,			      SetWeather },
      { &EV_World_SetSkyAlpha,            SetSkyAlpha },
      { &EV_World_SetSkyPortal,           SetSkyPortal },
      { &EV_World_SetAmbientLight,        NULL },
      { &EV_World_SetAmbientIntensity,    NULL },
      { &EV_World_SetSunColor,            NULL },
      { &EV_World_SetSunLight,            NULL },
      { &EV_World_SetSunDirection,        NULL },
      { &EV_World_LightmapDensity,        NULL },
      { &EV_World_SunFlare,               NULL },
      { &EV_World_SunFlareInPortalSky,    NULL },
      { &EV_World_SetNumArenas,           SetNumArenas },
		{ NULL, NULL }
	};

World::World()
	{
	const char  *text;
	str         mapname;
	int		   i;

   assert( this->entnum == ENTITYNUM_WORLD );

	world = this;
   world_dying = qfalse;

	setMoveType( MOVETYPE_NONE );
	setSolidType( SOLID_BSP );

	// world model is always index 1
	edict->s.modelindex = 1;
   model = "*1";

	flags |= FL_THINK;

   UpdateConfigStrings();

   // Anything that modifies configstrings, or spawns things is ignored when loading savegames
   if ( LoadingSavegame )
      {
      return;
      }

   // clear out the soundtrack from the last level
	ChangeSoundtrack( "" );

   // set the default gravity
	gi.cvar_set( "sv_gravity", "800" );

   // set the default farplane parameters
   farplane_distance = 0;
   farplane_color = "0 0 0";
   farplane_cull = qtrue;
	farplane_fog = qtrue;
   UpdateFog();

	terrain_global = qfalse;
	terrain_global_min = MIN_WORLD_COORD;
	UpdateTerrain();

	entity_fade_dist = DEFAULT_ENTITY_FADE_DIST;
	UpdateEntityFadeDist();

	UpdateDynamicLights();

	UpdateWeather();

   sky_alpha = 1.0f;
   sky_portal = true;
   UpdateSky();

   //
   // see if this is a cinematic level
	//
   level.cinematic = ( spawnflags & CINEMATIC ) ? true : false;

   if ( level.cinematic )
      gi.cvar_set( "sv_cinematic", "1" );
   else
      gi.cvar_set( "sv_cinematic", "0" );

   level.nextmap = "";
   level.level_name = level.mapname;

	// Set up the mapname as the default script
   mapname = "maps/";
	mapname += level.mapname;
	for( i = mapname.length() - 1; i >= 0; i-- )
		{
		if ( mapname[ i ] == '.' )
			{
			mapname[ i ] = 0;
			break;
			}
		}

	mapname += ".scr";
	text = &mapname[ 5 ];

	// If there isn't a script with the same name as the map, then don't try to load script
	if ( gi.FS_ReadFile( mapname.c_str(), NULL, qtrue ) != -1 )
		{
      gi.DPrintf( "Adding script: '%s'\n", text );

      // just set the script, we will start it in G_Spawn
      level.SetGameScript( mapname.c_str() );
		}

	level.consoleThread = Director.CreateThread();

   SoundMan.Load();

   // Set the color for the blends.
   level.water_color       = Vector( 0, 0, 0.5 );
   level.water_alpha       = 0.4;

	level.slime_color       = Vector( 0.2, 0.4, 0.2 );
   level.slime_alpha       = 0.6;

   level.lava_color        = Vector( 0.5, 0.15, 0 );
   level.lava_alpha        = 0.6;

   //
   // reset the earthquake
   //
   level.earthquake = 0;

   //
   // set the targetname of the world
   //
   SetTargetName( "world" );
	}

void World::UpdateConfigStrings
   (
   void
   )
   {
   //
	// make some data visible to connecting client
   //
	gi.setConfigstring( CS_GAME_VERSION, GAME_VERSION );
	gi.setConfigstring( CS_LEVEL_START_TIME, va("%i", level.startTime ) );

	// make some data visible to the server
   gi.setConfigstring( CS_NAME, level.level_name.c_str() );
   };

void World::UpdateFog
   (
   void
   )
   {
   gi.SetFarPlane( farplane_distance, farplane_cull );
   gi.setConfigstring( CS_FOGINFO, va( "%d %d %.0f %.4f %.4f %.4f", farplane_cull, farplane_fog, farplane_distance, farplane_color.x, farplane_color.y, farplane_color.z ) );
   }

void World::UpdateTerrain
   (
   void
   )
   {
   //gi.SetFarPlane( farplane_distance );
   gi.setConfigstring( CS_TERRAININFO, va( "%d %.0f", terrain_global, terrain_global_min ) );
   }

void World::UpdateEntityFadeDist
   (
   void
   )
   {
   gi.setConfigstring( CS_ENTITYFADEINFO, va( "%f", entity_fade_dist ) );
   }

void World::UpdateDynamicLights
   (
   void
   )
   {
	int i;

	for ( i = 0 ; i < MAX_LIGHTING_GROUPS ; i++ )
		gi.SetDynamicLight( i, dynamic_lights[ i ].intensity );
   }

void World::UpdateWindIntensity
   (
   void
   )
   {
	gi.SetWindIntensity( wind.intensity );
   }

void World::UpdateWeather
   (
   void
   )
   {
	gi.SetWeatherInfo( weather.type, weather.intensity );
   }

void World::UpdateSky
   (
   void
   )
   {
   gi.SetSkyPortal( sky_portal );
   gi.setConfigstring( CS_SKYINFO, va( "%.4f %d", sky_alpha, sky_portal ) );
   }


void World::SetSoundtrack
   (
   Event *ev
   )

   {
   const char *text;

   text = ev->GetString( 1 );
   ChangeSoundtrack( text );
	}

void World::SetGravity
   (
   Event *ev
   )

   {
   gi.cvar_set( "sv_gravity", ev->GetString( 1 ) );
	}

void World::SetFarPlane
   (
   Event *ev
   )

   {
   farplane_distance = ev->GetFloat( 1 );
   UpdateFog();
	}

void World::SetFarPlane_Color
   (
   Event *ev
   )

   {
   farplane_color = ev->GetVector( 1 );
   UpdateFog();
	}

void World::SetFarPlane_Cull
   (
   Event *ev
   )

   {
   farplane_cull = ev->GetBoolean( 1 );
   UpdateFog();
	}

void World::SetFarPlane_Fog
   (
   Event *ev
   )

   {
   farplane_fog = ev->GetBoolean( 1 );
   UpdateFog();
	}

void World::SetTerrainGlobal
   (
   Event *ev
   )

   {
   terrain_global = ev->GetBoolean( 1 );
	terrain_global_min = MIN_WORLD_COORD;
   UpdateTerrain();
	}

void World::SetTerrainGlobalMin
   (
   Event *ev
   )

   {
	terrain_global = qtrue;
   terrain_global_min = ev->GetFloat( 1 );
   UpdateTerrain();
	}

void World::SetEntityFadeDist
   (
   Event *ev
   )

   {
	entity_fade_dist = ev->GetFloat( 1 );
   UpdateEntityFadeDist();
	}

void World::SetLightIntensity
   (
   Event *ev
   )

	{
	str light_group_name;
	int light_group_num;
	float light_intensity;

	// Get the light group

	light_group_name = ev->GetString( 1 );
	light_intensity  = ev->GetFloat( 2 );

	light_group_num = gi.GetLightingGroup( light_group_name );

	// Make sure this is a valid light group

	if ( light_group_num == -1 )
		{
		gi.WDPrintf( "Unknown light group %s\n", light_group_name );
		return;
		}

	// Set the light info

	dynamic_lights[ light_group_num ].intensity = light_intensity;
	dynamic_lights[ light_group_num ].fade_time = 0;
	dynamic_lights[ light_group_num ].lightstyle = "";
	}

void World::SetLightFade
   (
   Event *ev
   )

   {
	str light_group_name;
	int light_group_num;
	float light_end_intensity;
	float fade_time;

	// Get the light group

	light_group_name = ev->GetString( 1 );
	light_end_intensity  = ev->GetFloat( 2 );
	fade_time  = ev->GetFloat( 3 );

	light_group_num = gi.GetLightingGroup( light_group_name );

	// Make sure this is a valid light group

	if ( light_group_num == -1 )
		{
		gi.WDPrintf( "Unknown light group %s\n", light_group_name );
		return;
		}

	// Set the light info

	dynamic_lights[ light_group_num ].start_intensity = dynamic_lights[ light_group_num ].intensity;
	dynamic_lights[ light_group_num ].end_intensity = light_end_intensity;

	dynamic_lights[ light_group_num ].start_fade_time = level.time;
	dynamic_lights[ light_group_num ].fade_time = fade_time;
	}

void World::SetLightLightstyle
   (
   Event *ev
   )

   {
	str light_group_name;
	int light_group_num;
	str lightstyle;
	qboolean stop_at_end;

	// Get the light group

	light_group_name = ev->GetString( 1 );
	lightstyle  = ev->GetString( 2 );

	if ( ev->NumArgs() > 2 )
		stop_at_end = ev->GetBoolean( 3 );
	else
		stop_at_end = qfalse;

	light_group_num = gi.GetLightingGroup( light_group_name );

	// Make sure this is a valid light group

	if ( light_group_num == -1 )
		{
		gi.WDPrintf( "Unknown light group %s\n", light_group_name );
		return;
		}

	// Set the light info

	dynamic_lights[ light_group_num ].lightstyle = lightstyle;
	dynamic_lights[ light_group_num ].current_lightstyle_position = -1;
	dynamic_lights[ light_group_num ].stop_at_end = stop_at_end;
	}

void World::GetLightIntensity
   (
   Event *ev
   )

   {
	str light_group_name;
	int light_group_num;

	// Get the light group

	light_group_name = ev->GetString( 1 );

	light_group_num = gi.GetLightingGroup( light_group_name );

	// Make sure this is a valid light group

	if ( light_group_num == -1 )
		{
		gi.WDPrintf( "Unknown light group %s\n", light_group_name );
		return;
		}

	ev->ReturnFloat( dynamic_lights[ light_group_num ].intensity );
	}

void World::SetWindIntensity
   (
   Event *ev
   )

	{
	wind.intensity = ev->GetFloat( 1 );

	wind.gust_time = 0;
	wind.fade_time = 0;
	wind.min_intensity = -1;
	wind.max_intensity = -1;
	}

void World::SetWindGust
   (
   Event *ev
   )

	{
	wind.start_intensity = wind.intensity;
	wind.end_intensity = ev->GetFloat( 1 );

	wind.start_fade_time = level.time;
	wind.fade_time = ev->GetFloat( 2 );

	wind.gust_time = ev->GetFloat( 3 );

	wind.min_intensity = -1;
	wind.max_intensity = -1;
	}

void World::SetWindFade
   (
   Event *ev
   )

	{
	wind.start_intensity = wind.intensity;
	wind.end_intensity = ev->GetFloat( 1 );

	wind.start_fade_time = level.time;
	wind.fade_time = ev->GetFloat( 2 );

	wind.gust_time = 0;

	wind.min_intensity = -1;
	wind.max_intensity = -1;
	}

void World::SetWindMinMax
   (
   Event *ev
   )

	{
	wind.fade_time = 0;

	wind.gust_time = 0;

	wind.min_intensity = ev->GetFloat( 1 );
	wind.max_intensity = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		wind.max_change = ev->GetFloat( 3 );
	else
		wind.max_change = ( wind.max_intensity - wind.min_intensity ) * 0.05;
	}

void World::SetWeather
   (
   Event *ev
   )

	{
	str weather_name;

	weather_name = ev->GetString( 1 );

	if ( weather_name == "rain" )
		weather.type = WEATHER_RAIN;
	else if ( weather_name == "rain_plain" )
		weather.type = WEATHER_RAIN_PLAIN;
	else
		weather.type = WEATHER_NONE;

	weather.intensity = ev->GetFloat( 2 );

	UpdateWeather();
	}

void World::SetSkyAlpha
   (
   Event *ev
   )

   {
   sky_alpha = ev->GetFloat( 1 );
   UpdateSky();
	}

void World::SetSkyPortal
   (
   Event *ev
   )

   {
   sky_portal = ev->GetBoolean( 1 );
   UpdateSky();
	}


void World::SetSkipThread
   (
   Event *ev
   )

   {
   str label;

   label = ev->GetString( 1 );
   if ( label.length() && label.icmp( "null" ) )
      {
      skipthread = label;
      }
   else
      {
      skipthread = "";
      }
   }

void World::SetNextMap
   (
   Event *ev
   )

   {
   level.nextmap = ev->GetString( 1 );
   }

void World::SetMessage
   (
   Event *ev
   )

   {
   const char *text;

   text = ev->GetString( 1 );
	level.level_name = text;
   gi.setConfigstring( CS_NAME, text );
	}

void World::SetScript
   (
   Event *ev
   )

   {
   str text;
   str scriptname;

   text = ev->GetString( 1 );

   gi.DPrintf( "Adding script: '%s'\n", text.c_str() );
	scriptname = "maps/" + text;

   // just set the script, we will start it in G_Spawn
   level.SetGameScript( scriptname.c_str() );
	}

void World::SetWaterColor
   (
   Event *ev
   )

   {
   level.water_color = ev->GetVector( 1 );
   }

void World::SetWaterAlpha
   (
   Event *ev
   )

   {
   level.water_alpha = ev->GetFloat( 1 );
   }

void World::SetSlimeColor
   (
   Event *ev
   )

   {
   level.slime_color = ev->GetVector( 1 );
   }

void World::SetSlimeAlpha
   (
   Event *ev
   )

   {
   level.slime_alpha = ev->GetFloat( 1 );
   }

void World::SetLavaColor
   (
   Event *ev
   )

   {
   level.lava_color = ev->GetVector( 1 );
   }

void World::SetLavaAlpha
   (
   Event *ev
   )

   {
   level.lava_alpha = ev->GetFloat( 1 );
   }

void World::SetNumArenas
   (
   Event *ev
   )

   {
   level.m_numArenas = ev->GetInteger( 1 );
   }

TargetList * World::GetTargetList( const str &targetname, qboolean createnew )
	{
   TargetList * targetlist;
   int i;

   for( i = 1; i <= targetList.NumObjects(); i++ )
      {
      targetlist = targetList.ObjectAt( i );
      if ( targetname == targetlist->targetname)
         return targetlist;
      }

   if ( !createnew )
      {
      return NULL;
      }

   targetlist = new TargetList( targetname );
   targetlist->index = targetList.AddObject( targetlist );
   
   return targetlist;
	}

void World::AddTargetEntity( const str &targetname, Entity * ent )
   {
   TargetList * targetlist;

   targetlist = GetTargetList( targetname );
   targetlist->AddEntity( ent );
   }

void World::RemoveTargetEntity( const str &targetname, Entity * ent )
   {
   TargetList * targetlist;

   if ( world_dying )
      return;

   targetlist = GetTargetList( targetname );
   targetlist->RemoveEntity( ent );
   }

Entity * World::GetNextEntity( const str &targetname, Entity * ent )
   {
   TargetList * targetlist;

   targetlist = GetTargetList( targetname );
   return targetlist->GetNextEntity( ent );
   }

World::~World()
	{
   world_dying = qtrue;
   FreeTargetList();
	}

void World::FreeTargetList
   (
   void
   )

   {
   int i;
   int num;

   num = targetList.NumObjects();
   for( i = 1; i <= num; i++ )
      {
      delete targetList.ObjectAt( i );
      }

   targetList.FreeObjectList();
   }

void World::Think
   (
   void
   )

   {
	int i;
	DynamicLightInfo *dlight;

	// Do dynamic light stuff

	for ( i = 0 ; i < MAX_LIGHTING_GROUPS ; i++ )
		{
		dlight = &dynamic_lights[ i ];

		if ( dlight->fade_time )
			{
			if ( level.time > dlight->start_fade_time + dlight->fade_time )
				{
				dlight->intensity = dlight->end_intensity;
				dlight->fade_time = 0;
				}
			else
				{
				dlight->intensity = dlight->start_intensity + ( dlight->end_intensity - dlight->start_intensity ) *
						( ( level.time - dlight->start_fade_time ) / dlight->fade_time );
				}
			}
		else if ( dlight->lightstyle.length() )
			{
			dlight->current_lightstyle_position++;

			if ( dlight->current_lightstyle_position >= dlight->lightstyle.length() )
				{
				if ( dlight->stop_at_end )
					{
					dlight->lightstyle = "";
					dlight->current_lightstyle_position = -1;
					}
				else
					{
					dlight->current_lightstyle_position = 0;
					}
				}

			if ( dlight->current_lightstyle_position >= 0 )
				dlight->intensity = ( dlight->lightstyle[ dlight->current_lightstyle_position ] - 'a' ) / 25.0;
			}
		}

	UpdateDynamicLights();

	// Do wind stuff

	if ( wind.gust_time )
		{
		if ( level.time < wind.start_fade_time + wind.fade_time )
			{
			wind.intensity = wind.start_intensity + ( wind.end_intensity - wind.start_intensity ) *
					( ( level.time - wind.start_fade_time ) / wind.fade_time );
			}
		else if ( level.time < wind.start_fade_time + wind.fade_time + wind.gust_time )
			{
			wind.intensity = wind.end_intensity;
			}
		else
			{
			wind.intensity = wind.end_intensity + ( wind.start_intensity - wind.end_intensity ) *
					( ( level.time - wind.start_fade_time - wind.fade_time - wind.gust_time ) / wind.fade_time );

			if ( level.time > wind.start_fade_time + wind.fade_time + wind.gust_time + wind.fade_time )
				{
				wind.intensity = wind.start_intensity;
				wind.fade_time = 0;
				wind.gust_time = 0;
				}
			}
		}
	else if ( wind.fade_time )
		{
		if ( level.time > wind.start_fade_time + wind.fade_time )
			{
			wind.intensity = wind.end_intensity;
			wind.fade_time = 0;
			}
		else
			{
			wind.intensity = wind.start_intensity + ( wind.end_intensity - wind.start_intensity ) *
					( ( level.time - wind.start_fade_time ) / wind.fade_time );
			}
		}
	else if ( wind.min_intensity > 0 && wind.max_intensity > 0 )
		{
		wind.intensity += G_CRandom( wind.max_change );

		if ( wind.intensity > wind.max_intensity )
			wind.intensity = wind.max_intensity;

		if ( wind.intensity < wind.min_intensity )
			wind.intensity = wind.min_intensity;
		}

	UpdateWindIntensity();
   }

DynamicLightInfo::DynamicLightInfo()
	{
	intensity = 1.0;
	fade_time = 0.0;
	}

WindInfo::WindInfo()
	{
	intensity = 0.0;
	fade_time = 0.0;
	gust_time = 0.0;
	min_intensity = -1.0;
	max_intensity = -1.0;
	}

WeatherInfo::WeatherInfo()
	{
	type = WEATHER_NONE;
	intensity = 0;
	}

//
// List stuff for targets
//

CLASS_DECLARATION( Class, TargetList, NULL )
	{
		{ NULL, NULL }
	};

TargetList::TargetList()
   {
   }

TargetList::TargetList( const str &tname )
   {
   targetname = tname;
   }

TargetList::~TargetList()
   {
   }

void TargetList::AddEntity( Entity * ent )
   {
	if ( !list.ObjectInList( ent ) )
		{
		list.AddObject( ent );
      }
   }

void TargetList::RemoveEntity( Entity * ent )
   {
	if ( list.ObjectInList( ent ) )
		{
		list.RemoveObject( ent );
      }
   }

Entity * TargetList::GetNextEntity( Entity * ent )
   {
   int index;

   index = 0;
   if ( ent )
      index = list.IndexOfObject( ent );
   index++;
   if ( index > list.NumObjects() )
      return NULL;
   else
      return list.ObjectAt( index );
   }