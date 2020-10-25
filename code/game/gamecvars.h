//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/gamecvars.h                                    $
// $Revision:: 11                                                             $
//     $Date:: 5/22/01 2:49p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/gamecvars.h                                         $
// 
// 11    5/22/01 2:49p Ericf
// Got rid of g_editmode cvar due to the new tool socket code
// 
// 10    4/30/01 2:47p Ericf
// Ladders and AG47 View Code
// 
// 9     4/24/01 3:42p Steven
// Added sv_showsplines.
// 
// 8     4/24/01 9:46a Steven
// Added a debug cvar.
// 
// 7     4/18/01 3:27p Steven
// Added g_showplayerweapon to display some weapon info.
// 
// 6     4/16/01 11:52a Ericf
// Edit mode code, first update
//
// 23    10/02/00 11:55a Aldie
// Added sv_nextmap
//
// 22    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 21    9/26/00 6:58p Aldie
// Another dm update - lots of stuff added
//
// 20    9/20/00 6:58p Aldie
// Another temporary checkin for deathmatch stuff
//
// 19    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 18    8/30/00 4:35p Aldie
// Added some functionality to get dm working
//
// 17    7/22/00 3:02p Steven
// Added boss health bar stuff.
//
// 16    7/17/00 3:40p Steven
// Removed sv_gore stuff.
//
// 15    7/17/00 3:26p Aldie
// Fix for flashbangs, changed detail variable, and added forcetorsostate
//
// 14    7/14/00 10:04p Aldie
// Added g_logstats cvar
//
// 13    7/14/00 9:52p Markd
// added global volume dampener on ambient sound effects for cinematics
//
// 12    7/12/00 6:34p Aldie
// Added in crosshair scaling for long distances
//
// 11    6/13/00 6:46p Aldie
// Added some damage debug info.  Added an ignoreEnt for explosion events
//
// 10    6/03/00 3:46p Aldie
// Added in g_debugtargets for debugging targetnames and targets
//
// 9     5/10/00 10:37a Steven
// Added com_blood.
//
// 8     5/08/00 3:19p Aldie
// Added initial crosshair work
//
// 7     3/15/00 2:04p Markd
// fixed up camera node system and added new debug oriented circle
//
// 6     3/06/00 8:07p Markd
// cleaned up unused cvar's
//
// 5     2/09/00 8:02p Aldie
// Added loopfire weapons
//
// 4     2/01/00 8:13p Aldie
// More autoaim work
//
// 3     1/19/00 7:46p Aldie
// Fixed func_spawns of various types and removed some unused misc classes
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// DESCRIPTION:
//

#ifndef __GAMECVARS_H__
#define __GAMECVARS_H__

#include "g_local.h"

extern	cvar_t	*developer;
extern	cvar_t	*deathmatch;
extern	cvar_t	*dmflags;
extern	cvar_t	*skill;
extern	cvar_t	*fraglimit;
extern	cvar_t	*timelimit;
extern	cvar_t	*password;
extern	cvar_t	*filterban;
extern	cvar_t	*flood_msgs;
extern	cvar_t	*flood_persecond;
extern	cvar_t	*flood_waitdelay;
extern	cvar_t	*maxclients;
extern	cvar_t	*maxentities;
extern	cvar_t	*nomonsters;
extern	cvar_t	*precache;
extern	cvar_t	*dedicated;
extern	cvar_t	*detail;
extern	cvar_t	*com_blood;
extern   cvar_t   *whereami;
extern   cvar_t   *bosshealth;

extern	cvar_t	*sv_maxvelocity;
extern	cvar_t	*sv_rollspeed;
extern	cvar_t	*sv_rollangle;
extern	cvar_t	*sv_cheats;
extern	cvar_t	*sv_showbboxes;
extern	cvar_t	*sv_showcameras;
extern	cvar_t	*sv_showsplines;
extern	cvar_t	*sv_showentnums;
extern	cvar_t	*sv_waterfriction;
extern	cvar_t	*sv_traceinfo;
extern	cvar_t	*sv_drawtrace;
extern	cvar_t	*sv_fps;
extern   cvar_t   *sv_cinematic;
extern   cvar_t   *sv_maplist;
extern   cvar_t   *sv_nextmap;

// New server cvars
extern cvar_t	*sv_maxspeed;
extern cvar_t	*sv_stopspeed;
extern cvar_t	*sv_friction;
extern cvar_t	*sv_gravity;
extern cvar_t	*sv_waterspeed;
extern cvar_t	*sv_wateraccelerate;
extern cvar_t	*sv_jumpheight;
extern cvar_t	*sv_edgefriction;
extern cvar_t	*sv_airmaxspeed;
extern cvar_t	*sv_airaccelerate;
extern cvar_t	*sv_crouchspeed;
extern cvar_t	*sv_noclipspeed;
extern cvar_t	*sv_accelerate;

extern	cvar_t	*csys_posx;
extern	cvar_t	*csys_posy;
extern	cvar_t	*csys_posz;
extern	cvar_t	*csys_x;
extern	cvar_t	*csys_y;
extern	cvar_t	*csys_z;
extern	cvar_t	*csys_draw;

extern	cvar_t	*g_showmem;
extern	cvar_t	*g_timeents;
extern	cvar_t	*g_showaxis;
extern	cvar_t	*g_showgravpath;
extern	cvar_t	*g_showplayerstate;
extern	cvar_t	*g_showplayeranim;
extern	cvar_t	*g_showplayerweapon;
extern   cvar_t   *g_showbullettrace;
extern	cvar_t	*g_legswingspeed;
extern	cvar_t	*g_legclampangle;
extern	cvar_t	*g_legclamptolerance;
extern	cvar_t	*g_legtolerance;
extern	cvar_t	*g_numdebuglines;
extern	cvar_t	*g_playermodel;
extern	cvar_t	*g_statefile;
extern	cvar_t	*g_showautoaim;
extern   cvar_t   *g_debugtargets;
extern   cvar_t   *g_debugdamage;
extern	cvar_t	*s_debugmusic;
extern	cvar_t	*g_logstats;
extern   cvar_t   *g_gametype;
extern   cvar_t   *g_teamdamage;
extern   cvar_t   *g_allowvote;
extern	cvar_t	*g_showaccuracymod;
extern   cvar_t   *g_debug;

// possibly temporary
extern	cvar_t	*g_onhorse;

void CVAR_Init( void );

#endif /* !__GAMECVARS_H__ */