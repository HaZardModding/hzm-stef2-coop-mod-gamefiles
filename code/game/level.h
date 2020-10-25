//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/level.h                                        $
// $Revision:: 4                                                              $
//     $Date:: 5/03/01 4:38p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/level.h                                             $
// 
// 4     5/03/01 4:38p Steven
// Worked on water, slime, & lava screen blend stuff.
// 
// 3     1/30/01 2:41p Sketcher
// The Heuristics system will now set a skill level value for the level
// 
// 2     1/16/01 2:12p Steven
// Script C merge.
//
// 21    10/06/00 4:51p Aldie
// Intermission code
//
// 20    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 19    9/26/00 6:58p Aldie
// Another dm update - lots of stuff added
//
// 18    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 17    9/12/00 7:03p Aldie
// Complete overhaul of the deathmatch stuff I wrote 2 weeks ago.  More to
// come.  Intermediate checkin
//
// 16    9/01/00 7:09p Aldie
// More fakk arena work
//
// 15    7/28/00 6:59p Steven
// Added some player died stuff.
//
// 14    7/27/00 3:52p Aldie
// Changed over letterboxing and fades to the game code.  They are sent over in
// player stats and fields now.
//
// 13    7/10/00 11:54p Markd
// added exit level code
//
// 12    7/07/00 6:35p Steven
// Added mission failed stuff.
//
// 11    6/28/00 3:27p Steven
// Added level wide ai_on.
//
// 10    5/24/00 3:14p Markd
// first phase of save/load games
//
// 9     4/11/00 2:46p Markd
// Implemented Automatic camera support
//
// 8     3/21/00 5:05p Markd
// improved earthquakes a lot with a visual effect
//
// 7     2/29/00 5:51p Jimdose
// added alternate spawnpoint support
//
// 6     2/26/00 12:58p Jimdose
// added PlayerRestart
//
// 5     1/28/00 5:43p Markd
// Added script command to the game
//
// 4     1/13/00 5:19p Jimdose
// removed clearsavegames
//
// 3     1/12/00 6:14p Jimdose
// added spawnflags to Level
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 1     12/17/99 6:33p Jimdose
//
// DESCRIPTION:
//

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "g_local.h"
#include "container.h"

class CThread;
class Camera;
//
// this structure is cleared as each map is entered
// it is read/written to the level.sav file for savegames
//

#define	VOTE_TIME	30000	// 30 seconds before vote times out

enum fadetype_t      { fadein, fadeout };
enum fadestyle_t     { alphablend, additive };
enum letterboxdir_t  { letterbox_in, letterbox_out };

class Level : public Class
	{
	public:
      const char     *current_map;
      const char     *current_entities;

      int			   spawn_entnum;
      int            spawnflags;

      int			   framenum;
      int            inttime;                // level time in millisecond integer form
	   float			   time;
      float          frametime;
      float          fixedframetime;         // preset frame time based on sv_fps
   	int			   startTime;				   // level.time the map was started

	   str            level_name;	            // the descriptive name (Outer Base, etc)
	   str            mapname;		            // the server name (base1, etc)
      str            spawnpoint;             // targetname of spawnpoint
	   str            nextmap;		            // go here when fraglimit is hit

      qboolean       restart;                // set true when game loop should restart

      // used for cinematics
      qboolean       playerfrozen;

	   // intermission state
	   float			   intermissiontime;			// time the intermission was started
	   int			   exitintermission;

	   gentity_s	   *next_edict;				// Used to keep track of the next edict to process in G_RunFrame

	   int			   total_secrets;
	   int			   found_secrets;

		str            game_script;

	   // FIXME - remove this later when it is passed in the event.
      trace_t        impact_trace;

      float          earthquake;
      float          earthquake_magnitude;

      qboolean       cinematic;

		qboolean       ai_on;

		qboolean       mission_failed;
		qboolean       died_already;

      qboolean       near_exit;

      // Blending color for water, light volumes,lava
      Vector         water_color;
		float          water_alpha;

		Vector         slime_color;
		float          slime_alpha;

      Vector         lava_color;
      float          lava_alpha;

      str            current_soundtrack;
      str            saved_soundtrack;

      CThread			*consoleThread;

      Vector         m_fade_color;
      float          m_fade_alpha;
      float          m_fade_time;
      float          m_fade_time_start;
      fadetype_t     m_fade_type;
      fadestyle_t    m_fade_style;

      float          m_letterbox_fraction;
      float          m_letterbox_time;
      float          m_letterbox_time_start;
      letterboxdir_t m_letterbox_dir;

      //
      // list of automatic_cameras on the level
      //
      Container<Camera *>	automatic_cameras;

      // Arena Deathmatch information
      int            m_numArenas;
      float          m_voteTime;
      int            m_voteYes;
      int            m_voteNo;
      int            m_numVoters;
      str            m_voteString;
      Vector         m_intermission_origin;
      Vector         m_intermission_angle;

		CLASS_PROTOTYPE( Level );

                     Level();

      void           Init( void );
      void           CleanUp( void );

      void           ResetEdicts( void );
      gentity_t      *AllocEdict( Entity *ent );
      void           FreeEdict( gentity_t *ed );
      void           InitEdict( gentity_t *e );

      void           Start( void );
      void           Restart( void );
      void           PlayerRestart( void );
      void           Precache( void );
      void			   FindTeams( void );

      void           SpawnEntities( const char *mapname, const char *entities, int levelTime );
      void           NewMap( const char *mapname, const char *entities, int levelTime );

      qboolean       inhibitEntity( int spawnflags );
      void           setSkill( int value );
		int            getSkill( void );
      void           setTime( int levelTime, int frameTime );
		void			   SetGameScript( const char *scriptname );
      void           AddAutomaticCamera( Camera * cam );
      void           CheckVote( void );
	   virtual void   Archive( Archiver &arc );
	};

extern Level level;

#endif /* !__LEVEL_H__ */