//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/gamecmds.h                                     $
// $Revision:: 3                                                              $
//     $Date:: 1/23/01 8:56a                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/gamecmds.h                                          $
// 
// 3     1/23/01 8:56a Steven
// Added level vars and game vars back in.
// 
// 2     1/16/01 2:11p Steven
// Script C merge.
//
// 5     7/10/00 9:27p Markd
// added ammo variables for how much ammo the player has.  Added levelvars and
// gamevars commands
//
// 4     4/26/00 7:55p Markd
// Added more documentation code into various systems
//
// 3     1/28/00 5:43p Markd
// Added script command to the game
//
// 2     1/06/00 11:10p Jimdose
// cleaning up unused code
//
// DESCRIPTION:
//

#ifndef __GAMECMDS_H__
#define __GAMECMDS_H__

#include "g_local.h"

extern "C" void      G_ClientCommand( gentity_t *ent );
extern "C" qboolean  G_ConsoleCommand( void );

void     G_InitConsoleCommands( void );

qboolean G_ProcessClientCommand( gentity_t *ent );

void     G_Say( gentity_t *ent, qboolean team, qboolean arg0 );
qboolean G_CameraCmd( gentity_t *ent );
qboolean G_SoundCmd( gentity_t *ent );
qboolean G_SayCmd( gentity_t *ent );
qboolean G_EventListCmd( gentity_t *ent );
qboolean G_PendingEventsCmd( gentity_t *ent );
qboolean G_EventHelpCmd( gentity_t *ent );
qboolean G_DumpEventsCmd( gentity_t *ent );
qboolean G_ClassEventsCmd( gentity_t *ent );
qboolean G_DumpClassEventsCmd( gentity_t *ent );
qboolean G_DumpAllClassesCmd( gentity_t *ent );
qboolean G_ClassListCmd( gentity_t *ent );
qboolean G_ClassTreeCmd( gentity_t *ent );
qboolean G_ShowVarCmd( gentity_t *ent );
qboolean G_RestartCmd( gentity_t *ent );
qboolean G_ScriptCmd( gentity_t *ent );
qboolean G_LevelVarsCmd( gentity_t *ent );
qboolean G_GameVarsCmd( gentity_t *ent );

#endif /* !__GAMECMDS_H__ */