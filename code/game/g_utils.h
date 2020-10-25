//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/g_utils.h                                      $
// $Revision:: 8                                                              $
//   $Author:: Ericf                                                          $
//     $Date:: 26.03.01 11:44a                                                $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/g_utils.h                                           $
// 
// 8     26.03.01 11:44a Ericf
// Changed naming for fire modes, no longer PRIMARY and ALTERNATE, but now
// MODE1 and MODE2 for future expansion to more than 2 mode weapons
// 
// 7     1/30/01 2:15p Steven
// Area based damage stuff.
// 
// 6     1/16/01 2:11p Steven
// Script C merge.
// 
// 5     12/11/00 3:44p Sketcher
// Added an Alert Event.  Also, added a BroadcastAlert() and its companion
// G_BroadcastAlert()
// 
// 4     12/11/00 3:18p Steven
// Made str passing const references.
// 
// 3     12/11/00 9:35a Steven
// Changed passing of most vectors to const reference.
// 
// 2     12/08/00 11:53a Sketcher
// It is now possible to send a soundtype with a sound when it is broadcast.
// However, at this time nothing happens if you do.  
//
// 35    10/06/00 4:51p Aldie
// Intermission code
//
// 34    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 33    9/01/00 7:09p Aldie
// More fakk arena work
//
// 32    8/30/00 4:35p Aldie
// Added some functionality to get dm working
//
// 31    8/04/00 3:54p Markd
// Added StartCinematic and StopCinematic
//
// 30    7/29/00 11:23p Aldie
// Added g_clearfade
//
// 29    7/29/00 4:00p Aldie
// Added autofadein for skipping cinematics
//
// 28    7/23/00 6:03p Markd
// added fadeout and fadesound to dieing and level change
//
// 27    7/13/00 12:33p Steven
// Improved G_TraceEntities.
//
// 26    7/10/00 11:54p Markd
// added exit level code
//
// 25    7/07/00 6:35p Steven
// Added mission failed stuff.
//
// 24    7/02/00 6:46p Markd
// added spawn thread to PlayerStart
//
// 23    6/14/00 11:18a Markd
// cleaned up code using Intel compiler
//
// 22    6/13/00 6:46p Aldie
// Added some damage debug info.  Added an ignoreEnt for explosion events
//
// 21    6/03/00 3:46p Aldie
// Added in g_debugtargets for debugging targetnames and targets
//
// 20    6/01/00 7:02p Markd
// removed activeWeapon variable
//
// 19    5/25/00 4:28p Markd
// fixed up archive functions
//
// 18    4/15/00 4:24p Markd
// Fixed player turning
//
// 17    3/04/00 11:48a Markd
// Added light style support
//
// 16    2/23/00 6:21p Aldie
// More inventory changes
//
// 15    2/17/00 6:26p Aldie
// Fixed naming conventions for weapon hand and also added various attachtotag
// functionality for weapons that attach to different tags depending on which
// hand they are wielded in.
//
// 14    1/22/00 5:07p Steven
// Added a trace entites function.
//
// 13    1/20/00 7:11p Jimdose
// removed angmod
//
// 12    1/11/00 6:41p Markd
// Removed fulltrace code from the game
//
// 11    1/10/00 5:34p Markd
// Added DeAllocateDebugLines
//
// 10    1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 9     12/17/99 8:27p Jimdose
// got rid of unused vars and functions
//
// 8     12/17/99 6:35p Jimdose
// changed spawnarg code
// added Level class for spawning and map control
// got rid of unused or superflous variables
// changed setjmp/longjmp calls to try/throw/catch exception handling
//
// 7     11/12/99 11:21a Markd
// Added Debug Circles and DebugPyramids
//
// 6     10/28/99 6:33p Markd
// Added fakeplayer ability, also added CloneEntity
//
// 5     10/14/99 5:08p Markd
// removed a lot of G_GetMoveDir calls from the initialization code
//
// 4     9/28/99 5:15p Markd
// Fixed more merge bugs with sharing class, vector and listener between three
// modules
//
// 3     9/28/99 4:26p Markd
// merged listener, class and vector between 3 projects
//
// 2     9/22/99 4:47p Markd
// fixed more G_GetEntity, G_FindClass and G_GetNextEntity bugs
//
// 1     9/10/99 10:54a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 13    9/02/99 5:41p Markd
// made CacheResource utility functions changed code every where else
//
// 12    8/18/99 3:28p Jimdose
// added cylindrical collision detection
//
// 11    7/29/99 11:41a Markd
// Added precache and global support
//
// DESCRIPTION:
//

#ifndef __G_UTILS_H__
#define __G_UTILS_H__

class Archiver;

void        G_ArchiveEdict( Archiver &arc, gentity_t *edict );

#include "entity.h"

void        G_AllocDebugLines( void );
void        G_DeAllocDebugLines( void );

void		   G_TouchTriggers (Entity *ent);
void			G_TouchSolids (Entity *ent);

Entity      *G_FindClass( Entity *ent, const char *classname );
Entity		*G_NextEntity( Entity *ent );

void        G_CalcBoundsOfMove( const Vector &start, const Vector &end, const Vector &mins, const Vector &maxs, Vector *minbounds, Vector *maxbounds );

void        G_ShowTrace( trace_t *trace, gentity_t *passent, const char *reason );
trace_t		G_Trace( const Vector &start, const Vector &mins, const Vector &maxs, const Vector &end, Entity *passent, int contentmask, qboolean cylindrical, const char *reason, qboolean fulltrace = false );
trace_t     G_Trace( vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, gentity_t *passent, int contentmask, qboolean cylindrical, const char *reason, qboolean fulltrace = false );
trace_t		G_FullTrace( const Vector &start, const Vector &mins, const Vector &maxs, const Vector &end, Entity *passent, int contentmask, qboolean cylindrical, const char *reason );
trace_t     G_FullTrace( vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, gentity_t *passent, int contentmask, qboolean cylindrical, const char *reason );
void			G_TraceEntities(	const Vector &start, const Vector &mins, const Vector &maxs, const Vector &end, Container<Entity *>*victimlist, int contentmask );

void			SelectSpawnPoint( Vector &org, Vector &angles, str &thread );

Entity      *G_FindTarget( Entity *ent, const char *name );
Entity		*G_NextEntity( Entity *ent );

qboolean	   M_CheckBottom( Entity *ent );

Vector		G_GetMovedir( float angle );
qboolean	   KillBox( Entity *ent );
qboolean	   IsNumeric( const char *str );

Entity		*findradius( Entity *startent, const Vector &org, float rad );
Entity		*findclientsinradius( Entity *startent, const Vector &org, float rad );

Vector		G_CalculateImpulse( const Vector &start, const Vector &end, float speed, float gravity );
Vector      G_PredictPosition( const Vector &start, const Vector &target, const Vector &targetvelocity, float speed );

qboolean    G_LoadAndExecScript( const char *filename, const char *label = NULL, qboolean quiet = qfalse );
CThread     *ExecuteThread( str thread_name, qboolean start = true );

int         MOD_string_to_int( const str &immune_string );
qboolean    MOD_matches( int incoming_damage, int damage_type );

int			Soundtype_string_to_int( const str &soundtype_string );

void G_MissionFailed( void );
void G_FadeOut( float delaytime );
void G_FadeSound( float delaytime );
void G_RestartLevelWithDelay( float delaytime );
void G_AutoFadeIn( void );
void G_ClearFade( void );
void G_StartCinematic( void );
void G_StopCinematic( void );
int G_NumClients( void );

// copy the entity exactly including all its children
void        CloneEntity( Entity * dest, Entity * src );

qboolean    OnSameTeam( Entity *ent1, Entity *ent2 );

//
// caching commands
//
void CacheResource( const char * stuff, Entity * ent = NULL );
int modelIndex( const char *mdl );

void G_SetTrajectory( gentity_t *ent, vec3_t org );
void G_SetConstantLight
   (
   int * constantlight,
   float * red,
   float * green,
   float * blue,
   float * radius,
   int   * lightstyle = NULL
   );

void ChangeMusic
	(
   const char *current,
   const char *fallback,
   qboolean force
	);

void ChangeMusicVolume
	(
   float volume,
   float fade_time
   );

void RestoreMusicVolume
	(
   float fade_time
   );

void ChangeSoundtrack
	(
   const char * soundtrack
	);

void RestoreSoundtrack
	(
   void
	);

void G_BroadcastSound( Entity *ent, const Vector &origin, float radius = SOUND_RADIUS, int soundType = SOUNDTYPE_GENERAL);
void G_BroadcastAlert( Entity *ent, const Vector &orignin, const Vector &enemy, float radius = SOUND_RADIUS );

//==================================================================
//
// Inline functions
//
//==================================================================

/*
=================
G_GetEntity

Takes an index to an entity and returns pointer to it.
=================
*/

inline Entity *G_GetEntity
	(
	int entnum
	)

	{
   if ( ( entnum < 0 ) || ( entnum >= globals.max_entities ) )
		{
		gi.Error( ERR_DROP, "G_GetEntity: %d out of valid range.", entnum );
		}

   return ( Entity * )g_entities[ entnum ].entity;
	}

/*
=================
G_Random

Returns a number from 0<= num < 1

random()
=================
*/

inline float G_Random
	(
	void
	)

	{
	return ( ( float )( rand() & 0x7fff ) ) / ( ( float )0x8000 );
	}

/*
=================
G_Random

Returns a number from 0 <= num < n

random()
=================
*/

inline float G_Random
	(
	float n
	)

	{
	return G_Random() * n;
	}

/*
=================
G_CRandom

Returns a number from -1 <= num < 1

crandom()
=================
*/

inline float G_CRandom
	(
	void
	)

	{
	return G_Random( 2 ) - 1;
	}

/*
=================
G_CRandom

Returns a number from -n <= num < n

crandom()
=================
*/

inline float G_CRandom
	(
	float n
	)

	{
	return G_CRandom() * n;
	}

/*
=================
G_FixSlashes

Converts all backslashes in a string to forward slashes.
Used to make filenames consistant.
=================
*/

inline str G_FixSlashes
   (
   const char *filename
   )

   {
	int i;
	int len;
	str text;

   if ( filename )
      {
	   // Convert all forward slashes to back slashes
	   text = filename;
	   len = text.length();
	   for( i = 0; i < len; i++ )
		   {
		   if ( text[ i ] == '\\' )
			   {
			   text[ i ] = '/';
			   }
		   }
      }

   return text;
   }

typedef enum
   {
   WEAPON_RIGHT,
   WEAPON_LEFT,
   WEAPON_DUAL,
   WEAPON_ANY,
   WEAPON_ERROR
   } weaponhand_t;

typedef enum teamtype_t
   {
   TEAM_NONE,
   TEAM_RED,
   TEAM_BLUE,
   TEAM_ONEONONE
   };

#define NUM_ACTIVE_WEAPONS WEAPON_ANY

typedef enum
   {
   FIRE_MODE1,
   FIRE_MODE2,
	FIRE_MODE3,
   MAX_FIREMODES,
   FIRE_ERROR
   } firemode_t;

firemode_t     WeaponModeNameToNum( const str &mode );
const char     *WeaponHandNumToName( weaponhand_t hand );
weaponhand_t   WeaponHandNameToNum( const str &side );
void           G_DebugTargets( Entity *e, const str &from );
void           G_DebugDamage( float damage, Entity *victim, Entity *attacker, Entity *inflictor );

#endif /* g_utils.h */
