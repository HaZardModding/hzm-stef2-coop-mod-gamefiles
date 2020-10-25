//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/gamecvars.cpp                                  $
// $Revision:: 13                                                             $
//     $Date:: 5/22/01 6:24p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/gamecvars.cpp                                       $
// 
// 13    5/22/01 6:24p Ericf
// Changed default jumpheight from 300 to 350
// 
// 12    5/22/01 2:49p Ericf
// Got rid of g_editmode cvar due to the new tool socket code
// 
// 11    4/30/01 2:47p Ericf
// Ladders and AG47 View Code
// 
// 10    4/24/01 3:41p Steven
// Added sv_showsplines.
// 
// 9     4/24/01 9:46a Steven
// Added a debug cvar.
// 
// 8     4/18/01 3:26p Steven
// Added g_showplayerweapon to display some weapon info.
// 
// 7     4/16/01 11:52a Ericf
// Edit mode code, first update
// 
// 2     26.01.01 1:20p Ericf
// Defaulted to Johnny state files now
//
// 37    10/02/00 11:54a Aldie
// Added sv_nextmap
//
// 36    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 35    9/26/00 6:58p Aldie
// Another dm update - lots of stuff added
//
// 34    9/22/00 3:46p Aldie
// Added gamespy support to fakk
//
// 33    9/21/00 3:51p Aldie
// added ranked server cvar
//
// 32    9/20/00 6:58p Aldie
// Another temporary checkin for deathmatch stuff
//
// 31    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 30    8/30/00 4:35p Aldie
// Added some functionality to get dm working
//
// 29    7/27/00 4:16p Aldie
// Changed logstats to 0
//
// 28    7/23/00 5:02p Markd
// made boss health a non-cvar
//
// 27    7/22/00 3:01p Steven
// Added boss health bar stuff.
//
// 26    7/21/00 2:31p Markd
// changed default value of "detail"
//
// 25    7/17/00 3:40p Steven
// Removed sv_gore stuff.
//
// 24    7/17/00 3:26p Aldie
// Fix for flashbangs, changed detail variable, and added forcetorsostate
//
// 23    7/14/00 10:04p Aldie
// Added g_logstats cvar
//
// 22    7/14/00 9:52p Markd
// added global volume dampener on ambient sound effects for cinematics
//
// 21    7/13/00 10:19p Aldie
// Increased default of g_crosshair_maxscale
//
// 20    7/12/00 6:34p Aldie
// Added in crosshair scaling for long distances
//
// 19    7/05/00 7:22p Markd
//
// 18    7/05/00 7:00p Markd
// Changed julie's model to julie_flightsuit.tik
//
// 17    6/13/00 6:46p Aldie
// Added some damage debug info.  Added an ignoreEnt for explosion events
//
// 16    6/03/00 3:46p Aldie
// Added in g_debugtargets for debugging targetnames and targets
//
// 15    5/10/00 10:32a Steven
// Added com_blood stuff and removed parentmode and sv_gibs.
//
// 14    5/08/00 3:19p Aldie
// Added initial crosshair work
//
// 13    4/30/00 4:41p Markd
// fixed turning speeed when running
//
// 12    4/15/00 4:24p Markd
// Fixed player turning
//
// 11    3/18/00 3:55p Markd
// working on player turning
//
// 10    3/15/00 2:04p Markd
// fixed up camera node system and added new debug oriented circle
//
// 9     3/14/00 5:12p Markd
// removed unused cvars
//
// 8     3/06/00 8:07p Markd
// cleaned up unused cvar's
//
// 7     2/09/00 8:02p Aldie
// Added loopfire weapons
//
// 6     2/01/00 8:13p Aldie
// More autoaim work
//
// 5     1/19/00 7:46p Aldie
// Fixed func_spawns of various types and removed some unused misc classes
//
// 4     1/19/00 9:51a Markd
// Changed Player model back to julie
//
// 3     1/18/00 7:49p Jimdose
// changed player model
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// DESCRIPTION:
// Definitions for any cvars used by the game.
//

#include "gamecvars.h"

cvar_t	*developer;
cvar_t	*deathmatch;
cvar_t	*dmflags;
cvar_t	*skill;
cvar_t	*fraglimit;
cvar_t	*timelimit;
cvar_t	*password;
cvar_t	*filterban;
cvar_t	*flood_msgs;
cvar_t	*flood_persecond;
cvar_t	*flood_waitdelay;
cvar_t	*maxclients;
cvar_t	*maxentities;
cvar_t	*nomonsters;
cvar_t	*precache;
cvar_t	*dedicated;
cvar_t	*detail;
cvar_t   *com_blood;
cvar_t   *whereami;

cvar_t   *bosshealth;

cvar_t	*sv_maxvelocity;
cvar_t	*sv_rollspeed;
cvar_t	*sv_rollangle;
cvar_t	*sv_cheats;
cvar_t	*sv_showbboxes;
cvar_t   *sv_showcameras;
cvar_t	*sv_showentnums;
cvar_t	*sv_showsplines;
cvar_t	*sv_waterfriction;
cvar_t	*sv_traceinfo;
cvar_t	*sv_drawtrace;
cvar_t   *sv_fps;
cvar_t   *sv_cinematic;
cvar_t   *sv_maplist;
cvar_t   *sv_nextmap;

// New server cvars
cvar_t	*sv_maxspeed;
cvar_t	*sv_stopspeed;
cvar_t	*sv_friction;
cvar_t	*sv_gravity;
cvar_t	*sv_waterspeed;
cvar_t	*sv_wateraccelerate;
cvar_t	*sv_jumpheight;
cvar_t	*sv_edgefriction;
cvar_t	*sv_airmaxspeed;
cvar_t	*sv_airaccelerate;
cvar_t	*sv_crouchspeed;
cvar_t	*sv_noclipspeed;
cvar_t	*sv_accelerate;

cvar_t	*csys_posx;
cvar_t	*csys_posy;
cvar_t	*csys_posz;
cvar_t	*csys_x;
cvar_t	*csys_y;
cvar_t	*csys_z;
cvar_t	*csys_draw;

cvar_t   *g_showmem;
cvar_t   *g_timeents;
cvar_t   *g_showaxis;
cvar_t   *g_showgravpath;
cvar_t   *g_showplayerstate;
cvar_t   *g_showplayeranim;
cvar_t   *g_showplayerweapon;
cvar_t   *g_legswingspeed;
cvar_t   *g_legclampangle;
cvar_t   *g_legclamptolerance;
cvar_t   *g_legtolerance;
cvar_t   *g_numdebuglines;
cvar_t   *g_playermodel;
cvar_t   *g_statefile;
cvar_t   *g_showbullettrace;
cvar_t   *s_debugmusic;
cvar_t   *g_showautoaim;
cvar_t   *g_debugtargets;
cvar_t   *g_debugdamage;
cvar_t   *g_logstats;
cvar_t   *g_gametype;
cvar_t   *g_rankedserver;
cvar_t   *g_teamdamage;
cvar_t   *g_allowvote;
cvar_t	*g_showaccuracymod;
cvar_t	*g_debug;

// Possibly temporary
cvar_t	*g_onhorse;

void CVAR_Init
   (
   void
   )

   {
	developer			   = gi.cvar( "developer",             "0",     0 );
   precache 			   = gi.cvar( "sv_precache",           "1",     0 );
	dedicated			   = gi.cvar( "dedicated",             "0",     CVAR_INIT );
	deathmatch			   = gi.cvar( "deathmatch",            "0",     CVAR_SERVERINFO|CVAR_LATCH );
	skill					   = gi.cvar( "skill",                 "1",     CVAR_SERVERINFO|CVAR_LATCH );
	maxclients			   = gi.cvar( "sv_maxclients",         "1",     0 );
	maxentities			   = gi.cvar( "maxentities",           "1024",  CVAR_LATCH );
	password             = gi.cvar( "password",              "",      CVAR_USERINFO );
	filterban            = gi.cvar( "filterban",             "1",     0 );
	dmflags				   = gi.cvar( "dmflags",               "0",     CVAR_SERVERINFO );
	fraglimit			   = gi.cvar( "fraglimit",             "0",     CVAR_SERVERINFO );
	timelimit			   = gi.cvar( "timelimit",             "0",     CVAR_SERVERINFO );
	nomonsters			   = gi.cvar( "nomonsters",            "0",     CVAR_SERVERINFO );
	flood_msgs           = gi.cvar( "flood_msgs",            "4",     0 );
	flood_persecond      = gi.cvar( "flood_persecond",       "4",     0 );
	flood_waitdelay      = gi.cvar( "flood_waitdelay",       "10",    0 );
   detail               = gi.cvar( "detail",                "1",     CVAR_ARCHIVE );
   com_blood            = gi.cvar( "com_blood",             "1",     CVAR_USERINFO|CVAR_SERVERINFO|CVAR_ARCHIVE );
	whereami             = gi.cvar( "whereami",              "0",     0 );

	bosshealth           = gi.cvar( "bosshealth",            "0",     0 );

   sv_rollspeed		   = gi.cvar( "sv_rollspeed",          "200",   0 );
	sv_rollangle		   = gi.cvar( "sv_rollangle",          "2",     0 );
	sv_maxvelocity		   = gi.cvar( "sv_maxvelocity",        "2000",  0 );
	sv_gravity			   = gi.cvar( "sv_gravity",            "800",   0 );
   sv_traceinfo		   = gi.cvar( "sv_traceinfo",          "0",     0 );
	sv_drawtrace		   = gi.cvar( "sv_drawtrace",          "0",     0 );
	sv_showbboxes		   = gi.cvar( "sv_showbboxes",         "0",     0 );
	sv_showcameras		   = gi.cvar( "sv_showcameras",        "0",     0 );
	sv_showsplines		   = gi.cvar( "sv_showsplines",        "0",     0 );
	sv_showentnums		   = gi.cvar( "sv_showentnums",        "0",     0 );
	sv_friction			   = gi.cvar( "sv_friction",           "6",     CVAR_SERVERINFO );
	sv_stopspeed		   = gi.cvar( "sv_stopspeed",          "50",    CVAR_SERVERINFO );
	sv_waterfriction	   = gi.cvar( "sv_waterfriction",      "1",     CVAR_SERVERINFO );
	sv_waterspeed		   = gi.cvar( "sv_waterspeed",         "300",   CVAR_SERVERINFO );
	sv_cheats			   = gi.cvar( "cheats",                "0",     CVAR_SERVERINFO|CVAR_LATCH );
   sv_fps               = gi.cvar( "sv_fps",                "20",    CVAR_SERVERINFO );
   sv_cinematic         = gi.cvar( "sv_cinematic",          "0",     CVAR_SERVERINFO|CVAR_ROM );
   sv_maplist           = gi.cvar( "sv_maplist",            "",      CVAR_ARCHIVE );
   sv_nextmap           = gi.cvar( "nextmap",               "",      0 );
	sv_maxspeed				= gi.cvar( "sv_maxspeed",				"350",	0 );
	sv_wateraccelerate	= gi.cvar( "sv_wateraccelerate",		"6",		0 );
	sv_jumpheight			= gi.cvar( "sv_jumpheight",			"350",	0 );
	sv_edgefriction		= gi.cvar( "sv_edgefriction",			"8",		0 );
	sv_airmaxspeed			= gi.cvar( "sv_airmaxspeed",			"350",	0 );
	sv_airaccelerate		= gi.cvar( "sv_airaccelerate",		"2",		0 );
	sv_crouchspeed			= gi.cvar( "sv_crouchspeed",			"200",	0 );
	sv_noclipspeed			= gi.cvar( "sv_noclipspeed",			"400",	0 );
	sv_accelerate			= gi.cvar( "sv_accelerate",			"10",		0 );

   g_showmem            = gi.cvar( "g_showmem",             "0",     0 );
   g_timeents           = gi.cvar( "g_timeents",            "0",     0 );
   g_showaxis           = gi.cvar( "g_showaxis",            "0",     0 );
   g_showgravpath       = gi.cvar( "g_drawgravpath",        "0",     0 );
   g_showplayerstate    = gi.cvar( "g_showplayerstate",     "0",     0 );
   g_showplayeranim     = gi.cvar( "g_showplayeranim",      "0",     0 );
	g_showplayerweapon   = gi.cvar( "g_showplayerweapon",    "0",     0 );
   g_showbullettrace    = gi.cvar( "g_showbullettrace",     "0",     0 );
	g_showaccuracymod		= gi.cvar( "g_showaccuracymod",		"0",		0 );

   g_legswingspeed      = gi.cvar( "g_legswingspeed",       "200",   0 );
   g_legclampangle      = gi.cvar( "g_legclampangle",       "90",    0 );
   g_legclamptolerance  = gi.cvar( "g_legclamptolerance",   "100",    0 );
   g_legtolerance       = gi.cvar( "g_legtolerance",        "40",    0 );

   g_numdebuglines      = gi.cvar( "g_numdebuglines",       "4096",  CVAR_LATCH );
   g_playermodel        = gi.cvar( "g_playermodel",         "johnny", 0 );
   g_statefile          = gi.cvar( "g_statefile",           "global/johnny", 0 );
   g_showautoaim        = gi.cvar( "g_showautoaim",         "0",     0 );
   g_debugtargets       = gi.cvar( "g_debugtargets",        "0",     0 );
   g_debugdamage        = gi.cvar( "g_debugdamage",         "0",     0 );
   g_logstats           = gi.cvar( "g_logstats",            "0",     0 );
	g_gametype           = gi.cvar( "g_gametype",            "0",     CVAR_SERVERINFO|CVAR_LATCH );
	g_rankedserver  	   = gi.cvar( "g_rankedserver",        "0",     0 );
   g_teamdamage    	   = gi.cvar( "g_teamdamage",          "0",     0 );
   g_allowvote    	   = gi.cvar( "g_allowvote",           "1",     0 );
	g_onhorse				= gi.cvar( "g_onhorse",					"0",		0 );

	csys_posx			   = gi.cvar( "csys_posx",	            "0",     0 );
	csys_posy			   = gi.cvar( "csys_posy",	            "0",     0 );
	csys_posz			   = gi.cvar( "csys_posz",	            "0",     0 );
	csys_x				   = gi.cvar( "csys_x",		            "0",     0 );
	csys_y				   = gi.cvar( "csys_y",		            "0",     0 );
	csys_z				   = gi.cvar( "csys_z",		            "0",     0 );
	csys_draw			   = gi.cvar( "csys_draw",             "0",     0 );

   s_debugmusic         = gi.cvar( "s_debugmusic",          "0",     0 );

	g_debug					= gi.cvar( "g_debug",					"0",     0 );

   if ( DM_ACTIVE )
      {
      gi.cvar_set( "deathmatch", "1" );
      }

   switch ( g_gametype->integer )
      {
      case GT_SINGLE_PLAYER:
         gi.cvar_set( "g_gametypestring", "singleplayer" );
         break;
      case GT_ARENA:
         gi.cvar_set( "g_gametypestring", "arena" );
         break;
      default:
         gi.cvar_set( "g_gametypestring", "none" );
      }
   }