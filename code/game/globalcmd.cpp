//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/globalcmd.cpp                                   $
// $Revision:: 9                                                              $
//     $Date:: 5/04/01 9:47a                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/globalcmd.cpp                                        $
// 
// 9     5/04/01 9:47a Steven
// Fixed isactordead & isactoralive, forgot to change event documentation.
// 
// 8     5/03/01 8:24p Steven
// Fixed up some is actor dead stuff.
// 
// 7     5/03/01 5:23a Sketcher
// Since it appears the script language has no NOT, I am adding an isActorAlive
// event
// 
// 6     5/01/01 3:00p Sketcher
// Sigh... Forgot to add the event for the new isActorDead check I added...
// Well, it's in now.
// 
// 5     5/01/01 2:43p Sketcher
// Added a global script command to check if an actor is dead
// 
// 4     3/28/01 3:25p Steven
// Added warning printfs.
// 
// 3     1/24/01 10:17a Steven
// Added centerprint back in.
// 
// 2     1/23/01 8:54a Steven
// Added level vars and game vars back in.
// 
// 1     1/16/01 2:13p Steven
// Script C merge.
// 
// 24    11/07/00 1:46p Darin
// Force Alice to STAND states at cinematic starts
// 
// 23    10/26/00 7:08a Darin
// Fix CThread archive function
// 
// 22    10/18/00 5:18p Darin
// Fix crash in WaitForDialog
// 
// 21    10/04/00 2:50p Darin
// Added 'level_ai' command
// 
// 20    9/29/00 3:39p Darin
// CPrint - centerprint from script
// 
// 19    8/28/00 11:02p Sfleming
// save/load first pass
// 
// 18    8/27/00 11:37a Darin
// Fix letterbox timing
// 
// 17    8/21/00 3:00p Darin
// Supported new Fade types, "fadeisactive" event, "drugview" event.
// 
// 16    8/09/00 5:40p Pmack
// added paranoia check and error message to Letterbox command
// 
// 15    8/09/00 12:00a Darin
// Fix letterbox and fade commands
// 
// 14    8/07/00 4:52p Pmack
// merged with gold fakk2 code
// 
// 11    5/19/00 3:17p Jimdose
// added deadtime support
// 
// 10    5/08/00 2:22p Jimdose
// updated fadein/fadeout commands
// 
// 9     5/04/00 6:39p Jimdose
// added  SetLightStyle, KillThreadEvent, and SetThreadName
// 
// 8     4/06/00 7:22p Jimdose
// made EV_ScriptThread_Trigger use a string instead of entity as an argument
// 
// 7     4/05/00 3:56p Jimdose
// Fakk2 merge
// 
// 5     4/04/00 2:32p Jimdose
// changed getentity to allow '*' prefixed entnums
// 
// 4     3/31/00 3:44p Jimdose
// expanded the number of args EV_ScriptThread_Print could take
// 
//
// DESCRIPTION:
// Global commands for scripts
//

#include "globalcmd.h"
#include "scriptmaster.h"
#include "player.h"
#include "actor.h"

Event EV_ProcessCommands
	( 
	"processCommands",
	EV_DEFAULT,
	NULL,
	NULL,
	"Not used."
	);
Event EV_Script_NewOrders
	(	
	"newOrders",
	EV_DEFAULT,
	NULL,
	NULL,
	"Inform script that it is about to get new orders."
	);
Event EV_ScriptThread_Execute
	( 
	"execute",
	EV_DEFAULT,
	NULL,
	NULL,
	"Execute the thread."
	);
Event EV_ScriptThread_Callback
	( 
	"script_callback",
	EV_DEFAULT,
	"ese",
	"slave name other",
	"Script callback."
	);
Event EV_ScriptThread_ThreadCallback
	( 
	"thread_callback",
	EV_DEFAULT,
	NULL,
	NULL,
	"Thread callback."
	);
Event EV_ScriptThread_DeathCallback
	( 
	"death_callback",
	EV_DEFAULT,
	NULL,
	NULL,
	"Death callback."
	);
Event EV_ScriptThread_CreateThread
	( 
	"thread",
	EV_DEFAULT,
	"@is",
	"threadnumber label",
	"Creates a thread starting at label."
	);
Event EV_ScriptThread_TerminateThread
	( 
	"terminate",
	EV_DEFAULT,
	"i",
	"thread_number",
	"Terminates the specified thread or the current one if none specified."
	);
Event EV_ScriptThread_ControlObject
	( 
	"control",
	EV_DEFAULT,
	"e",
	"object",
	"Not used."
	);
Event EV_ScriptThread_Goto
	( 
	"goto",
	EV_DEFAULT,
	"s",
	"label",
	"Goes to the specified label."
	);
Event EV_ScriptThread_Pause
	( 
	"pause",
	EV_DEFAULT,
	NULL,
	NULL,
	"Pauses the thread."
	);
Event EV_ScriptThread_Wait
	( 
	"wait",
	EV_DEFAULT,
	"f",
	"wait_time",
	"Wait for the specified amount of time."
	);
Event EV_ScriptThread_WaitFor
	( 
	"waitfor",
	EV_DEFAULT,
	"e",
	"ent",
	"Wait for the specified entity."
	);
Event EV_ScriptThread_WaitForThread
	( 
	"waitForThread",
	EV_DEFAULT,
	"i",
	"thread_number",
	"Wait for the specified thread."
	);
Event EV_ScriptThread_WaitForDeath
	( 
	"waitForDeath",
	EV_DEFAULT,
	"s",
	"name",
	"Wait for death."
	);
Event EV_ScriptThread_WaitForSound
	( 
	"waitForSound",
	EV_DEFAULT,
	"sf",
	"sound_name delay",
	"Wait for end of the named sound plus an optional delay."
	);
Event EV_ScriptThread_WaitForDialog
	( 
	"waitForDialog",
	EV_DEFAULT,
	"eF",
	"actor additional_delay",
	"Wait for end of the dialog for the specified actor.\n"
   "If additional_delay is specified, than the actor will\n"
   "wait the dialog length plus the delay."
	);
Event EV_ScriptThread_WaitForPlayer
	( 
	"waitForPlayer",
	EV_DEFAULT,
	NULL,
	NULL,
	"Wait for player to be ready."
	);
Event EV_ScriptThread_CPrint
	(
	"cprint",
	EV_DEFAULT,
	"s",
	"string",
	"Prints a string."
	);
Event EV_ScriptThread_Print
	(
	"print",
	EV_DEFAULT,
	"sSSSSSSSSSSSSSSS",
	"string string string string string string string string string string string string string string string string",
	"Prints a string."
	);
Event EV_ScriptThread_PrintInt
	( 
	"printint",
	EV_DEFAULT,
	"i",
	"integer",
	"Print integer."
	);
Event EV_ScriptThread_PrintFloat
	( 
	"printfloat",
	EV_DEFAULT,
	"f",
	"float",
	"Prints a float."
   );
Event EV_ScriptThread_PrintVector
	( 
	"printvector",
	EV_DEFAULT,
	"v",
	"vector",
	"Prints a vector."
	);
Event EV_ScriptThread_NewLine
	( 
	"newline",
	EV_DEFAULT,
	NULL,
	NULL,
	"Prints a newline."
	);
Event EV_ScriptThread_Assert
	( 
	"assert",
	EV_DEFAULT,
	"f",
	"value",
	"Assert if value is 0."
	);
Event EV_ScriptThread_Break
	( 
	"break",
	EV_DEFAULT,
	NULL,
	NULL,
	"Asserts so that we can break back into the debugger from script."
	);
Event EV_ScriptThread_Clear
	( 
	"clear",
	EV_DEFAULT,
	"s",
	"var_group",
	"Clears the specified var group."
	);
Event EV_ScriptThread_Trigger
	( 
	"trigger",
	EV_DEFAULT,
	"s",
	"entname",
	"Trigger the specified target."
	);
Event EV_ScriptThread_Spawn
	( 
	"spawn", 
	EV_CHEAT,
	"@esSSSSSSSS",
	"entity entityname keyname1 value1 keyname2 value2 keyname3 value3 keyname4 value4",
	"Spawn the specified entity."
	);
Event EV_ScriptThread_Map
	( 
	"map",
	EV_DEFAULT,
	"s",
	"map_name",
	"Starts the specified map."
	);
Event EV_ScriptThread_SetCvar
	( 
	"setcvar",
	EV_DEFAULT,
	"ss",
	"cvar_name value",
	"Sets the value of the specified cvar."
	);
Event EV_ScriptThread_CueCamera
	( 
	"cuecamera",
	EV_DEFAULT,
	"eF",
	"entity switchTime",
	"Cue the camera. If switchTime is specified, then the camera\n"
   "will switch over that length of time."
	);
Event EV_ScriptThread_CuePlayer
	( 
	"cueplayer",
	EV_DEFAULT,
   "F",
   "switchTime",
	"Go back to the normal camera. If switchTime is specified,\n"
   "then the camera will switch over that length of time."
	);
Event EV_ScriptThread_FreezePlayer
	( 
	"freezeplayer",
	EV_DEFAULT,
	NULL,
	NULL,
	"Freeze the player."
	);
Event EV_ScriptThread_ReleasePlayer
	( 
	"releaseplayer",
	EV_DEFAULT,
	NULL,
	NULL,
	"Release the player."
	);
Event EV_ScriptThread_FakePlayer
	( 
	"fakeplayer",
	EV_DEFAULT,
	NULL,
   NULL,
	"Will create a fake version of the player, hide the real one and\n"
   "call the fake one 'fakeplayer'."
	);
Event EV_ScriptThread_RemoveFakePlayer
	( 
	"removefakeplayer",
	EV_DEFAULT,
   NULL,
   NULL,
	"Will delete the fake version of the player, un-hide the real one and\n"
   "return to the normal game"
	);

Event EV_ScriptThread_KillEnt
	( 
	"killent", 
	EV_CHEAT,
	"i",
	"ent_num",
	"Kill the specified entity."
	);
Event EV_ScriptThread_KillClass
	( 
	"killclass", 
	EV_CHEAT,
	"sI",
	"class_name except",
	"Kills everything in the specified class except for the specified entity (optional)."
	);
Event EV_ScriptThread_RemoveEnt
	( 
	"removeent", 
	EV_CHEAT,
	"i",
	"ent_num",
	"Removes the specified entity."
	);
Event EV_ScriptThread_RemoveClass
	( 
	"removeclass", 
	EV_CHEAT,
	"sI",
	"class_name except",
	"Removes everything in the specified class except for the specified entity (optional)."
	);

// client/server flow control
Event EV_ScriptThread_StuffCommand
	( 
	"stuffcmd",
	EV_DEFAULT,
	"SSSSSS",
	"arg1 arg2 arg3 arg4 arg5 arg6",
	"Server only command."
	);

//
// world stuff
//
Event EV_ScriptThread_RegisterAlias
	( 
	"alias",
	EV_DEFAULT,
	"ssSSSS",
	"alias_name real_name arg1 arg2 arg3 arg4",
	"Sets up an alias."
	);
Event EV_ScriptThread_RegisterAliasAndCache
	(
	"aliascache",
	EV_DEFAULT,
	"ssSSSS",
	"alias_name real_name arg1 arg2 arg3 arg4",
	"Sets up an alias and caches the resourse."
	);
Event EV_ScriptThread_SetCinematic
	( 
	"cinematic",
	EV_DEFAULT,
	NULL,
	NULL,
	"Turns on cinematic."
	);
Event EV_ScriptThread_SetNonCinematic
	( 
	"noncinematic",
	EV_DEFAULT,
	NULL,
	NULL,
	"Turns off cinematic."
	);
// DHM
Event EV_ScriptThread_SetLevelAI
	( 
	"level_ai",
	EV_DEFAULT,
	"b",
	"on_or_off",
	"Turns on or off Level-wide AI for monsters."
	);
// dhm
Event EV_ScriptThread_SetSkipThread
	( 
	"skipthread",
	EV_DEFAULT,
	"s",
	"thread_name",
	"Set the thread to skip."
	);

// Precache specific
Event EV_ScriptThread_Precache_Cache
	( 
	"cache",
	EV_DEFAULT,
	"s",
	"resource_name",
	"Cache the specified resource."
	);

// DHM
// drugged up warping FOV controls
Event EV_ScriptThread_DrugView
	( 
	"drugview",
	EV_DEFAULT,
	"b",
	"on_or_off",
	"1 to turn FOV warping on, 0 to turn off."
	);

// fades for movies
Event EV_ScriptThread_FadeIn
	( 
	"cam_fadein",
	EV_DEFAULT,
	"fffffI",
	"time red green blue alpha mode",
	"Sets up fadein in values."
	);
Event EV_ScriptThread_FadeOut
	( 
	"cam_fadeout",
	EV_DEFAULT,
	"fffffI",
	"time red green blue alpha mode",
	"Sets up fadeout values."
	);
// DHM
Event EV_ScriptThread_FadeIsActive
	(
	"fadeisactive",
	EV_DEFAULT,
	"@i",
	"Result",
	"Returns 1 if a fade is in progress."
	);
// dhm
Event EV_ScriptThread_GetEntity
	( 
	"getentity",
	EV_DEFAULT,
	"@es",
	"entity entityname",
	"Returns the entity with the specified targetname."
	);

// music command
Event EV_ScriptThread_MusicEvent
	( 
	"music",
	EV_DEFAULT,
	"sS",
	"current fallback",
	"Sets the current and fallback (optional) music moods."
	);
Event EV_ScriptThread_ForceMusicEvent
	( 
	"forcemusic",
	EV_DEFAULT,
	"sS",
	"current fallback",
	"Forces the current and fallback (optional) music moods."
	);
Event EV_ScriptThread_MusicVolumeEvent
	( 
	"musicvolume",
	EV_DEFAULT,
	"ff",
	"volume fade_time",
	"Sets the volume and fade time of the music."
	);
Event EV_ScriptThread_RestoreMusicVolumeEvent
	( 
	"restoremusicvolume",
	EV_DEFAULT,
	"f",
	"fade_time",
	"Restores the music volume to its previous value."
	);
Event EV_ScriptThread_SoundtrackEvent
	( 
	"soundtrack",
	EV_DEFAULT,
	"s",
	"soundtrack_name",
	"Changes the soundtrack."
	);
Event EV_ScriptThread_RestoreSoundtrackEvent
	( 
	"restoresoundtrack",
	EV_DEFAULT,
	NULL,
	NULL,
	"Restores the soundtrack to the previous one."
	);
Event EV_ScriptThread_ClearFade
   (
   "clearfade",
   EV_DEFAULT,
   NULL,
   NULL,
   "Clear the fade from the screen"
   );
Event EV_ScriptThread_Letterbox
	( 
	"letterbox",
	EV_DEFAULT,
	"f",
	"time",
	"Puts the game in letterbox mode."
	);
Event EV_ScriptThread_ClearLetterbox
	( 
	"clearletterbox",
	EV_DEFAULT,
	"f",
   "time",
	"Clears letterbox mode."
	);
Event EV_ScriptThread_SetDialogScript
   ( 
   "setdialogscript" ,
   EV_DEFAULT,
   "s",
   "dialog_script",
   "Set the script to be used when dialog:: is used"
   );
Event EV_ScriptThread_RandomFloat
	( 
	"randomfloat",
	EV_DEFAULT,
	"@ff",
	"returnval max_float",
	"Sets the float to a random number."
	);
Event EV_ScriptThread_RandomInteger
	( 
	"randomint",
	EV_DEFAULT,
	"@ii",
	"returnval max_int",
	"Sets the integer to a random number."
	);
Event EV_ScriptThread_CameraCommand
	( 
	"cam",
	EV_DEFAULT,
	"sSSSSSS",
	"command arg1 arg2 arg3 arg4 arg5 arg6",
	"Processes a camera command."
	);
Event EV_ScriptThread_SetLightStyle
   ( 
   "setlightstyle" ,
   EV_DEFAULT,
   "is",
   "lightstyleindex lightstyledata",
   "Set up the lightstyle with lightstyleindex to the specified data"
   );
Event EV_ScriptThread_KillThreadEvent
   ( 
   "killthread",
   EV_DEFAULT,
   "s",
   "threadName",
   "kills all threads starting with the specified name"
   );
Event EV_ScriptThread_SetThreadNameEvent
   ( 
   "threadname",
   EV_DEFAULT,
   "s",
   "threadName",
   "sets the name of the thread"
   );
Event EV_ScriptThread_SetFloatVar
	( 
	"setfloatvar",
	EV_DEFAULT,
	"sf",
	"variable_name float_value",
	"Sets a level or game variable."
	);
Event EV_ScriptThread_SetVectorVar
	( 
	"setvectorvar",
	EV_DEFAULT,
	"sv",
	"variable_name vector_value",
	"Sets a level or game variable."
	);
Event EV_ScriptThread_SetStringVar
	( 
	"setstringvar",
	EV_DEFAULT,
	"ss",
	"variable_name string_value",
	"Sets a level or game variable."
	);
Event EV_ScriptThread_GetFloatVar
	( 
	"getfloatvar",
	EV_DEFAULT,
	"@fs",
	"float_value variable_name",
	"Gets a level or game variable."
	);
Event EV_ScriptThread_GetVectorVar
	( 
	"getvectorvar",
	EV_DEFAULT,
	"@vs",
	"vector_value variable_name",
	"Gets a level or game variable."
	);
Event EV_ScriptThread_GetStringVar
	( 
	"getstringvar",
	EV_DEFAULT,
	"@ss",
	"string_value variable_name",
	"Gets a level or game variable."
	);

Event EV_ScriptThread_CenterPrint
   (
   "centerprint",
   EV_DEFAULT,
   "s",
   "stuffToPrint",
   "prints the included message in the middle of all player's screens"
   );

Event EV_ScriptThread_IsActorDead
   (
	"isactordead",
	EV_DEFAULT,
	"s",
	"actor_name",
	"Checks if an Actor is dead or not"
	);

Event EV_ScriptThread_IsActorAlive
   (
	"isactoralive",
	EV_DEFAULT,
	"s",
	"actor_name",
	"Checks if an Actor is alive or not"
	);

CLASS_DECLARATION( Interpreter, CThread, NULL )
   {
	   { &EV_ScriptThread_Execute,			         ExecuteFunc },
	   { &EV_MoveDone,							         ObjectMoveDone },
	   { &EV_ScriptThread_Callback,			         ScriptCallback },
		{ &EV_ScriptThread_ThreadCallback,           ThreadCallback },
      { &EV_ScriptThread_DeathCallback,            DeathCallback },
	   { &EV_ScriptThread_CreateThread,		         CreateThread },
		{ &EV_ScriptThread_TerminateThread,	         TerminateThread },
	   { &EV_ScriptThread_Pause,				         EventPause },
	   { &EV_ScriptThread_Wait,				         EventWait },
	   { &EV_ScriptThread_WaitFor,			         EventWaitFor },
	   { &EV_ScriptThread_WaitForThread,	         EventWaitForThread },
      { &EV_ScriptThread_WaitForDeath, 	         EventWaitForDeath },
      { &EV_ScriptThread_WaitForSound, 	         EventWaitForSound },
		{ &EV_ScriptThread_WaitForDialog, 	         EventWaitForDialog },
      { &EV_ScriptThread_WaitForPlayer, 	         EventWaitForPlayer },
		{ &EV_ScriptThread_CPrint,				         CPrint },							// DHM
	   { &EV_ScriptThread_Print,				         Print },
	   { &EV_ScriptThread_PrintInt,			         PrintInt },
	   { &EV_ScriptThread_PrintFloat,		         PrintFloat },
	   { &EV_ScriptThread_PrintVector,		         PrintVector },
	   { &EV_ScriptThread_NewLine,			         NewLine },
		{ &EV_ScriptThread_Assert,				         Assert },
		{ &EV_ScriptThread_Break,				         Break },
		{ &EV_ScriptThread_Trigger,			         TriggerEvent },
		{ &EV_ScriptThread_StuffCommand,		         StuffCommand },
      { &EV_ScriptThread_Spawn,  			         Spawn },
	   { &EV_ScriptThread_Precache_Cache,	         CacheResourceEvent },
	   { &EV_ScriptThread_RegisterAlias,	         RegisterAlias },
	   { &EV_ScriptThread_RegisterAliasAndCache,	   RegisterAliasAndCache },
		{ &EV_ScriptThread_Map,					         MapEvent },
		{ &EV_ScriptThread_SetCvar,			         SetCvarEvent },
		{ &EV_ScriptThread_CueCamera,			         CueCamera },
		{ &EV_ScriptThread_CuePlayer,			         CuePlayer },
		{ &EV_ScriptThread_FreezePlayer,		         FreezePlayer },
		{ &EV_ScriptThread_ReleasePlayer,	         ReleasePlayer },
      { &EV_ScriptThread_FadeIn,       	         FadeIn },
      { &EV_ScriptThread_FadeOut,       	         FadeOut },
		{ &EV_ScriptThread_FadeIsActive,					FadeIsActive },					// DHM
      { &EV_ScriptThread_ClearFade,       	      ClearFade },
      { &EV_ScriptThread_Letterbox,       	      Letterbox },
      { &EV_ScriptThread_ClearLetterbox,   	      ClearLetterbox },
      { &EV_ScriptThread_MusicEvent,     	         MusicEvent },
      { &EV_ScriptThread_ForceMusicEvent,          ForceMusicEvent },
		{ &EV_ScriptThread_MusicVolumeEvent,     	   MusicVolumeEvent },
		{ &EV_ScriptThread_RestoreMusicVolumeEvent,  RestoreMusicVolumeEvent },
      { &EV_ScriptThread_SoundtrackEvent,          SoundtrackEvent },
		{ &EV_ScriptThread_RestoreSoundtrackEvent,   RestoreSoundtrackEvent },
      { &EV_ScriptThread_SetCinematic,             SetCinematic },
      { &EV_ScriptThread_SetNonCinematic,          SetNonCinematic },
		{ &EV_ScriptThread_SetLevelAI,					SetLevelAI },
      { &EV_ScriptThread_SetSkipThread,            SetSkipThread },
		{ &EV_ScriptThread_KillEnt,			         KillEnt },
		{ &EV_ScriptThread_RemoveEnt,			         RemoveEnt },
		{ &EV_ScriptThread_KillClass,			         KillClass },
		{ &EV_ScriptThread_RemoveClass,		         RemoveClass },
		{ &EV_ScriptThread_FakePlayer,		         FakePlayer },
		{ &EV_ScriptThread_RemoveFakePlayer,		   RemoveFakePlayer },
      { &EV_AI_RecalcPaths,                        PassToPathmanager },
      { &EV_AI_CalcPath,                           PassToPathmanager },
      { &EV_AI_DisconnectPath,                     PassToPathmanager },
      { &EV_ScriptThread_GetEntity,                GetEntityEvent },
      { &EV_ScriptThread_RandomFloat,              RandomFloat },
      { &EV_ScriptThread_RandomInteger,            RandomInteger },
      { &EV_ScriptThread_CameraCommand,            CameraCommand },
      { &EV_ScriptThread_SetLightStyle,            SetLightStyle },
      { &EV_ScriptThread_KillThreadEvent,          KillThreadEvent },
      { &EV_ScriptThread_SetThreadNameEvent,       SetThreadName },
		{ &EV_ScriptThread_SetFloatVar,					SetFloatVar },
		{ &EV_ScriptThread_SetVectorVar,					SetVectorVar },
		{ &EV_ScriptThread_SetStringVar,					SetStringVar },
		{ &EV_ScriptThread_GetFloatVar,					GetFloatVar },
		{ &EV_ScriptThread_GetVectorVar,					GetVectorVar },
		{ &EV_ScriptThread_GetStringVar,					GetStringVar },
		{ &EV_ScriptThread_CenterPrint,              CenterPrint },
		{ &EV_ScriptThread_IsActorDead,					isActorDead		},
		{ &EV_ScriptThread_IsActorAlive,             isActorAlive		},
      { NULL, NULL }
   };

CThread::CThread()
   {
   ClearWaitFor();
   }

void CThread::ExecuteFunc
	(
	Event *ev
	)

   {
	ClearWaitFor();

   Interpreter::Execute( ev );
   }

void CThread::ClearWaitFor
	(
	void
	)

	{
	waitUntil = 0;
	waitingFor = NULL;
	waitingNumObjects = 0;
	waitingForThread = NULL;
   waitingForDeath = "";
   waitingForPlayer = false;
	}

qboolean CThread::WaitingFor
	(
	Entity *obj
	)

	{
	assert( obj );

	return ( waitingFor && waitingFor->list.ObjectInList( obj ) );
	}

void CThread::ObjectMoveDone
	(
	Event *ev
	)

	{
	Entity *obj;

	obj = ev->GetEntity( 1 );
	assert( obj );

	if ( WaitingFor( obj ) )
		{
      waitingNumObjects--;
      if ( waitingNumObjects <= 0 )
         {
		   ClearWaitFor();
         DelayedStart( 0 );
         }
		}
	}

void CThread::CreateThread
	(
	Event *ev
	)

	{
   CThread *pThread;

	pThread = Director.CreateThread( ev->GetToken( 1 ) );
   if ( pThread )
      {
      // start right away
      pThread->Start();

      ev->ReturnInteger( pThread->ThreadNum() );
      }
	}

void CThread::TerminateThread
	(
	Event *ev
	)

	{
   int threadnum;
   CThread *thread;

   threadnum = ev->GetInteger( 1 );
   thread = Director.GetThread( threadnum );
   Director.KillThread( threadnum );
	}

void CThread::EventPause
	(
	Event *ev
	)

	{
   DoMove();

	ClearWaitFor();

	doneProcessing = true;
	}

void CThread::EventWait
	(
	Event *ev
	)

	{
	DoMove();

	ClearWaitFor();

	waitUntil = ev->GetFloat( 1 ) + level.time;

	DelayedStart( ev->GetFloat( 1 ) );
	doneProcessing = true;
	}

void CThread::EventWaitFor
   (
   Event *ev
   )

   {
   Entity      *ent;
   const char  *tname;
   TargetList  *tlist;
   int         i;

   ClearWaitFor();
   doneProcessing = true;

   ent = ev->GetEntity( 1 );
   if ( ent )
      {
      tname = ent->TargetName();

      //
      // set the number of objects that belong to this targetname
      //
      tlist = world->GetTargetList( str( tname ) );
      waitingFor = tlist;
      waitingNumObjects = tlist->list.NumObjects();

      //
      // make sure all these objects are in the update list
      //
      for( i = 1; i <= waitingNumObjects; i++ )
         {
         ent = tlist->list.ObjectAt( i );

         // add the object to the update list to make sure we tell it to do a move
         if ( !updateList.ObjectInList( ent->entnum ) )
            {
            updateList.AddObject( ent->entnum );
            }
         }

      if ( waitingNumObjects <= 0 )
         {
         waitingNumObjects = 1;
         ev->Error( "no objects of targetname %s found.\n", tname );
         }
      }

   DoMove();
   }

void CThread::EventWaitForThread
	(
	Event *ev
	)

	{
	doneProcessing = true;

	ClearWaitFor();
	waitingForThread = Director.GetThread( ev->GetInteger( 1 ) );
	if ( !waitingForThread )
		{
		ev->Error( "Thread %d not running", ev->GetInteger( 1 ) );
		return;
		}

	DoMove();
	}

void CThread::EventWaitForDeath
	(
	Event *ev
	)

	{
   doneProcessing = true;

	ClearWaitFor();
	waitingForDeath = ev->GetString(1);
	if ( !waitingForDeath.length() )
		{
		ev->Error( "Null name" );
		return;
		}

	DoMove();
	}

void CThread::EventWaitForSound
	(
	Event *ev
	)

	{
   str sound;
   float delay;

	ClearWaitFor();

	DoMove();

   delay = 0;
	sound = ev->GetString( 1 );

   delay = gi.SoundLength( sound.c_str() );

	if ( delay < 0 )
      {
		gi.WDPrintf( "Lip file not found for dialog %s\n", sound.c_str() );
      }

	if ( ev->NumArgs() > 1 )
      {
      delay += ev->GetFloat( 2 );
      }

   DelayedStart( delay );
	doneProcessing = true;
	}

void CThread::EventWaitForDialog
	(
	Event *ev
	)

	{
	float delay;
   Actor *act;
	Entity *ent;

	ent = ev->GetEntity( 1 );

	if ( !ent )
	{
		gi.WDPrintf( "WaitForDialog: Can't find entity\n" );
		return;
	}

	if ( ent->isSubclassOf( Actor ) )
		{
		act = ( Actor * )ent;

		delay = act->GetDialogRemainingTime( );
      if ( ev->NumArgs() > 1 )
         {
         delay += ev->GetFloat( 2 );
         }
		DelayedStart( delay );
		doneProcessing = true;
		}
	}

void CThread::EventWaitForPlayer
	(
	Event *ev
	)

	{
   if ( !Director.PlayerReady() )
      {
      doneProcessing = true;

	   ClearWaitFor();
	   waitingForPlayer = true;

	   DoMove();
      }
	}

// DHM
void CThread::CPrint
	(
	Event *ev
	)

	{
	gi.centerprintf( &g_entities[ 0 ], ev->GetString( 1 ) );
	}
// dhm

void CThread::Print
	(
	Event *ev
	)

	{
   int i;
   int n;

   n = ev->NumArgs();
   for( i = 1; i <= n; i++ )
      {
      gi.DPrintf( "%s", ev->GetString( i ) );
      }
	}

void CThread::PrintInt
	(
	Event *ev
	)

	{
   gi.DPrintf( "%d", ev->GetInteger( 1 ) );
	}

void CThread::PrintFloat
	(
	Event *ev
	)

	{
   gi.DPrintf( "%.2f", ev->GetFloat( 1 ) );
	}

void CThread::PrintVector
	(
	Event *ev
	)

	{
   Vector vec;

   vec = ev->GetVector( 1 );
   gi.DPrintf( "(%.2f %.2f %.2f)", vec.x, vec.y, vec.z );
	}

void CThread::NewLine
	(
	Event *ev
	)

	{
   gi.DPrintf( "\n" );
	}

void CThread::Assert
	(
	Event *ev
	)

	{
	assert( ev->GetFloat( 1 ) );
	}

void CThread::Break
	(
	Event *ev
	)

	{
   // Break into the debugger
#ifdef _WIN32
	__asm int 3
#else
   assert( 0 );
#endif
	}

void CThread::ScriptCallback
	(
	Event *ev
	)

	{
	const char  *name;
	Entity	   *other;
	Entity	   *slave;

	if ( threadDying )
		{
		return;
		}

	slave = ev->GetEntity( 1 );
	name = ev->GetString( 2 );
	other = ev->GetEntity( 3 );

	if ( !Goto( name ) )
		{
		ev->Error( "Label '%s' not found", name );
		}
	else
		{
		// kill any execute events (in case our last command was "wait")
		ClearWaitFor();

      // start right away
      Start();
		}
	}

void CThread::ThreadCallback
	(
	Event *ev
	)

	{
	CThread *thread;

	if ( threadDying )
		{
		return;
		}

	thread = ev->GetThread();
	if ( thread && ( thread == waitingForThread ) )
		{
		ClearWaitFor();
      Start();
		}
	}

void CThread::DeathCallback
	(
	Event *ev
	)

	{
	if ( threadDying )
		{
		return;
		}

	ClearWaitFor();
   DelayedStart( 0 );
   }

void CThread::DoMove
   (
   void
   )

   {
   int      entnum;
   Entity   *ent;
   Event    *event;
   int      count;
   int      i;

   count = updateList.NumObjects();

   for( i = 1; i <= count; i++ )
      {
      entnum = ( int )updateList.ObjectAt( i );
      ent = G_GetEntity( entnum );
      if ( ent && ( ent->ValidEvent( EV_ProcessCommands ) ) )
         {
         event = new Event( EV_ProcessCommands );
         event->SetThread( this );
         ent->PostEvent( event, 0 );
         }
      else
         {
         // try to remove this from the update list
         if ( waitingNumObjects > 0 )
            {
            waitingNumObjects--;
            }
         }
      }

   updateList.ClearObjectList();
   }

void CThread::TriggerEvent
	(
	Event *ev
	)

	{
	const char	*name;
	Event		   *event;
	Entity	   *ent;
   TargetList  *tlist;
   int         i;
   int         num;

	name = ev->GetString( 1 );

	// Check for object commands
	if ( name && name[ 0 ] == '$' )
		{
      tlist = world->GetTargetList( str( name + 1 ) );
      num = tlist->list.NumObjects();
      for ( i = 1; i <= num; i++ )
         {
         ent = tlist->list.ObjectAt( i );

		   assert( ent );

         event = new Event( EV_Activate );
			event->SetSource( EV_FROM_SCRIPT );
			event->SetThread( this );
			event->SetLineNumber( ev->GetLineNumber() );
         event->AddEntity( world );
		   ent->ProcessEvent( event );
         }
      }
	else if ( name[ 0 ] == '*' )   // Check for entnum commands
      {
		if ( !IsNumeric( &name[ 1 ] ) )
			{
			RunError( "Expecting numeric value for * command, but found '%s'\n", &name[ 1 ] );
			}
		else
         {
         ent = G_GetEntity( atoi( &name[ 1 ] ) );
         if ( ent )
            {
            event = new Event( EV_Activate );
				event->SetSource( EV_FROM_SCRIPT );
				event->SetThread( this );
				event->SetLineNumber( ev->GetLineNumber() );
            event->AddEntity( world );
            ent->ProcessEvent( event );
            }
         else
            {
            RunError( "Entity not found for * command\n" );
            }
         }
      return;
      }
	else
		{
		RunError( "Invalid entity reference '%s'.\n", name );
		}
	}

void CThread::CacheResourceEvent
	(
   Event * ev
	)

	{
   if ( !precache->integer )
      {
      return;
      }

   CacheResource( ev->GetString( 1 ), world );
	}

void CThread::RegisterAlias
	(
	Event *ev
	)

	{
	str parameters;
	int i;

	// Get the parameters for this alias command
	for( i = 3; i <= ev->NumArgs(); i++ )
	   {
      parameters += ev->GetString( i );
      parameters += " ";
	   }

   gi.GlobalAlias_Add( ev->GetString( 1 ), ev->GetString( 2 ),  parameters.c_str() );
	}

void CThread::RegisterAliasAndCache
	(
	Event *ev
	)

	{
	RegisterAlias( ev );

   if ( !precache->integer )
      {
      return;
      }

   CacheResource( ev->GetString( 2 ) );
	}

void CThread::MapEvent
	(
	Event *ev
	)

	{
	G_BeginIntermission( ev->GetString( 1 ) );
	doneProcessing = true;
	}

void CThread::SetCvarEvent
	(
	Event *ev
	)

	{
	str name;

	name = ev->GetString( 1 );
	if ( name != "" )
		{
		gi.cvar_set( name.c_str(), ev->GetString( 2 ) );
		}
	}

void CThread::CueCamera
	(
	Event *ev
	)

	{
   float    switchTime;
	Entity   *ent;

   if ( ev->NumArgs() > 1 )
      {
      switchTime = ev->GetFloat( 2 );
      }
   else
      {
      switchTime = 0;
      }

	ent = ev->GetEntity( 1 );
	if ( ent )
		{
		SetCamera( ent, switchTime );
		}
	else
		{
		ev->Error( "Camera named %s not found", ev->GetString( 1 ) );
		}
	}

void CThread::CuePlayer
	(
	Event *ev
	)

	{
   float switchTime;

   if ( ev->NumArgs() > 0 )
      {
      switchTime = ev->GetFloat( 1 );
      }
   else
      {
      switchTime = 0;
      }

	SetCamera( NULL, switchTime );
	}

void CThread::FreezePlayer
	(
	Event *ev
	)

	{
	level.playerfrozen = true;
	}

void CThread::ReleasePlayer
	(
	Event *ev
	)

	{
	level.playerfrozen = false;
	}

void CThread::FakePlayer
	(
	Event *ev
	)

	{
   Player *player;

   player = ( Player * )g_entities[ 0 ].entity;
   if ( player && player->edict->inuse && player->edict->client )
      {
      player->FakePlayer(qfalse);
      }
	}

void CThread::RemoveFakePlayer
	(
	Event *ev
	)

	{
   Player *player;

   player = ( Player * )g_entities[ 0 ].entity;
   if ( player && player->edict->inuse && player->edict->client )
      {
      player->RemoveFakePlayer();
      }
	}

void CThread::Spawn
	(
	Event *ev
	)

	{
	Entity		   *ent;
   Entity         *tent;
   const char	   *name;
	ClassDef		   *cls;
   int			   n;
	int			   i;
   const char     *targetname;
	const char	   *value;

   if ( ev->NumArgs() < 1 )
		{
		ev->Error( "Usage: spawn entityname [keyname] [value]..." );
		return;
		}

   // create a new entity
   SpawnArgs args;

   name = ev->GetString( 1 );

   if ( name )
      {
      cls = getClassForID( name );
      if ( !cls )
         {
         cls = getClass( name );
         }

      if ( !cls )
         {
         str n;

         n = name;
         if ( !strstr( n.c_str(), ".tik" ) )
            {
            n += ".tik";
            }
         args.setArg( "model", n.c_str() );
         }
      else
         {
         args.setArg( "classname", name );
         }
      }

   if ( ev->NumArgs() > 2 )
		{
		n = ev->NumArgs();
		for( i = 2; i <= n; i += 2 )
			{
			args.setArg( ev->GetString( i ), ev->GetString( i + 1 ) );
			}
		}

   cls = args.getClassDef();
   if ( !cls )
      {
		ev->Error( "'%s' is not a valid entity name", name );
		return;
		}

   // If there is a spawntarget set, then use that entity's origin and angles
   targetname = args.getArg( "spawntarget" );

   if ( targetname )
      {
      tent = G_FindTarget( NULL, targetname );
      if ( tent )
         {
         args.setArg( "origin", va( "%f %f %f", tent->origin[ 0 ], tent->origin[ 1 ], tent->origin[ 2 ] ) );
         args.setArg( "angle", va( "%f", tent->angles[1] ) );
         }
      else
         {
		   ev->Error( "Can't find targetname %s", targetname );
         }
      }

   //
   // make sure to setup spawnflags properly
   //
   level.spawnflags = 0;
	value = args.getArg( "spawnflags" );
	if ( value )
      {
      level.spawnflags = atoi( value );
      }

   ent = args.Spawn();

   ev->ReturnEntity( ent );
   }

//FIXME
//Move this to someplace Level class.
static float last_fraction = 1.0f/8.0f;

void CThread::Letterbox
   (
   Event *ev
   )

   {
   float time;

	// PGM - don't crash, just give an error message
   if ( ev->NumArgs() < 1 )
	{
		warning ("CThread::Letterbox", "time parameter required!\n");
		return;
	}
	// PGM

   last_fraction = 1.0f/8.0f;

   time = ev->GetFloat( 1 );

   if ( ev->NumArgs() > 1 )
      {
      last_fraction = ev->GetFloat( 2 );
      }

	// DHM - this is now handled server side
   //gi.SendServerCommand( NULL, va( "letterbox %0.2f 1 %0.2f",time,last_fraction ) );
	level.m_letterbox_time_start = time;
	level.m_letterbox_dir = letterbox_in;

	level.m_letterbox_time = time;
	level.m_letterbox_fraction = last_fraction;
   }

void CThread::ClearLetterbox
   (
   Event *ev
   )

   {
   float time;

   time = ev->GetFloat( 1 );

	// DHM - this is now handled server side
   //gi.SendServerCommand( NULL, va( "letterbox %0.2f -1 %0.2f",time,last_fraction ) );
	level.m_letterbox_time_start = time;
	level.m_letterbox_dir = letterbox_out;

	level.m_letterbox_time = time;
	level.m_letterbox_fraction = last_fraction;
   }

void CThread::FadeIn
	(
	Event *ev
	)

   {
	level.m_fade_time_start = ev->GetFloat( 1 );
   level.m_fade_time       = ev->GetFloat( 1 );
   level.m_fade_color[0]   = ev->GetFloat( 2 );
   level.m_fade_color[1]   = ev->GetFloat( 3 );
   level.m_fade_color[2]   = ev->GetFloat( 4 );
   level.m_fade_alpha      = ev->GetFloat( 5 );
   level.m_fade_type       = fadein;
   level.m_fade_style      = alphablend;

   if ( ev->NumArgs() > 5 )
      {
      level.m_fade_style   = (fadestyle_t)ev->GetInteger( 6 );
      }
   }

void CThread::ClearFade
   (
   Event *ev
   )

   {
	// DHM - this is now handled server side
   //gi.SendServerCommand( NULL, "clearfade" );
   level.m_fade_time = -1;
   level.m_fade_type = fadein;
   }

void CThread::FadeOut
	(
	Event *ev
	)
   {
   level.m_fade_time_start = ev->GetFloat( 1 );
   level.m_fade_time       = ev->GetFloat( 1 );
   level.m_fade_color[0]   = ev->GetFloat( 2 );
   level.m_fade_color[1]   = ev->GetFloat( 3 );
   level.m_fade_color[2]   = ev->GetFloat( 4 );
   level.m_fade_alpha      = ev->GetFloat( 5 );
   level.m_fade_type       = fadeout;
   level.m_fade_style      = alphablend;

   if ( ev->NumArgs() > 5 )
      {
      level.m_fade_style   = (fadestyle_t)ev->GetInteger( 6 );
      }
   }

// DHM

void CThread::FadeIsActive
	(
	Event *ev
	)
	{
	if ( level.m_fade_time > 0 )
		ev->ReturnInteger( 1 );
	else
		ev->ReturnInteger( 0 );
	}

// dhm

void CThread::MusicEvent
	(
	Event *ev
	)
   {
   const char *current;
   const char *fallback;

   current = ev->GetString( 1 );

   fallback = NULL;
   if ( ev->NumArgs() > 1 )
      {
      fallback = ev->GetString( 2 );
      }

   ChangeMusic( current, fallback, false );
   }

void CThread::MusicVolumeEvent
	(
	Event *ev
	)
   {
   float volume;
   float fade_time;

   volume    = ev->GetFloat( 1 );
   fade_time = ev->GetFloat( 2 );

   ChangeMusicVolume( volume, fade_time );
   }

void CThread::RestoreMusicVolumeEvent
	(
	Event *ev
	)
   {
   float fade_time;

   fade_time = ev->GetFloat( 1 );

   RestoreMusicVolume( fade_time );
   }

void CThread::ForceMusicEvent
	(
	Event *ev
	)
   {
   const char *current;
   const char *fallback;

   current = ev->GetString( 1 );
   fallback = NULL;
   if ( ev->NumArgs() > 1 )
      {
      fallback = ev->GetString( 2 );
      }

   ChangeMusic( current, fallback, true );
   }

void CThread::SoundtrackEvent
	(
	Event *ev
	)
   {
   ChangeSoundtrack( ev->GetString( 1 ) );
   }

void CThread::RestoreSoundtrackEvent
	(
	Event *ev
	)
   {
   RestoreSoundtrack();
   }

void CThread::SetCinematic
   (
   Event *ev
   )

   {
	G_StartCinematic();

	/* Player *alice;
	alice = (Player *)G_GetEntity( 0 );
	alice->ForceState( "STAND", "STAND" ); */
   }

void CThread::SetNonCinematic
   (
   Event *ev
   )

   {
	G_StopCinematic();
   //level.cinematic = false;
   }

// DHM

void CThread::SetLevelAI
	(
	Event *ev
	)

	{
	qboolean ai = qfalse;

	if ( ev->NumArgs() > 0 )
		ai = ev->GetBoolean( 1 );

	if ( ai )
		level.ai_on = qtrue;
	else
		level.ai_on = qfalse;
	}

// dhm

void CThread::SetSkipThread
   (
   Event *ev
   )

   {
   world->skipthread = ev->GetString( 1 );
   }

void CThread::PassToPathmanager
   (
   Event *ev
   )

   {
   PathManager.ProcessEvent( ev );
   }

void CThread::StuffCommand
   (
   Event *ev
   )

   {
   int i;
   str command;

   for( i = 1; i <= ev->NumArgs(); i++ )
      {
      command += ev->GetString( i );
      command += " ";
      }

   if ( command.length() )
      {
      gi.SendConsoleCommand( command.c_str() );
      }
   }

void CThread::KillEnt
	(
   Event * ev
   )
   {
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
		ev->Error( "No args passed in" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      ev->Error( "Value out of range.  Possible values range from 0 to %d.\n", globals.max_entities );
		return;
		}

	ent = G_GetEntity( num );
   ent->Damage( world, world, ent->max_health + 25, vec_zero, vec_zero, vec_zero, 0, 0, 0 );
   }

void CThread::RemoveEnt
	(
   Event * ev
   )
   {
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
		ev->Error( "No args passed in" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      ev->Error( "Value out of range.  Possible values range from 0 to %d.\n", globals.max_entities );
		return;
		}

	ent = G_GetEntity( num );
   ent->PostEvent( Event( EV_Remove ), 0 );
   }

void CThread::KillClass
	(
   Event * ev
   )
   {
   int except;
   str classname;
   gentity_t * from;
	Entity *ent;

	if ( ev->NumArgs() < 1 )
		{
		ev->Error( "No args passed in" );
		return;
		}

   classname = ev->GetString( 1 );

   except = 0;
   if ( ev->NumArgs() == 2 )
      {
      except = ev->GetInteger( 1 );
      }

   for ( from = &g_entities[ game.maxclients ]; from < &g_entities[ globals.num_entities ]; from++ )
		{
		if ( !from->inuse )
			{
			continue;
			}

		assert( from->entity );

      ent = from->entity;

      if ( ent->entnum == except )
         {
         continue;
         }

   	if ( ent->inheritsFrom( classname.c_str() ) )
         {
         ent->Damage( world, world, ent->max_health + 25, vec_zero, vec_zero, vec_zero, 0, 0, 0 );
         }
      }
   }

void CThread::RemoveClass
	(
   Event * ev
   )
   {
   int except;
   str classname;
   gentity_t * from;
	Entity *ent;

	if ( ev->NumArgs() < 1 )
		{
		ev->Error( "No args passed in" );
		return;
		}

   classname = ev->GetString( 1 );

   except = 0;
   if ( ev->NumArgs() == 2 )
      {
      except = ev->GetInteger( 1 );
      }

   for ( from = &g_entities[ game.maxclients ]; from < &g_entities[ globals.num_entities ]; from++ )
		{
		if ( !from->inuse )
			{
			continue;
			}

		assert( from->entity );

      ent = from->entity;

      if ( ent->entnum == except )
         continue;

   	if ( ent->inheritsFrom( classname.c_str() ) )
         {
         ent->PostEvent( Event( EV_Remove ), 0 );
         }
      }
   }

void CThread::GetEntityEvent
	(
   Event *ev
   )

   {
   TargetList *tlist;

	str name( ev->GetString( 1 ) );
   if ( name[ 0 ] == '*' )
      {
      ev->ReturnEntity( G_GetEntity( atoi( &name[ 1 ] ) ) );
      return;
      }
   tlist = world->GetTargetList( name, qfalse );

   //FIXME
   //ev->ReturnInteger( ( int )tlist );
   if ( tlist )
      {
      ev->ReturnEntity( tlist->GetNextEntity( NULL ) );
      }
   else
      {
      ev->ReturnEntity( NULL );
      }
   }

void CThread::RandomFloat
	(
	Event *ev
	)

	{
   ev->ReturnFloat( G_Random( ev->GetFloat( 1 ) ) );
	}

void CThread::RandomInteger
	(
	Event *ev
	)

	{
   ev->ReturnInteger( G_Random( ev->GetInteger( 1 ) ) );
	}

void CThread::CameraCommand
	(
   Event * ev
   )

   {
   Event *e;
	const char *cmd;
   int   i;
   int   n;

   if ( !ev->NumArgs() )
      {
      ev->Error( "Usage: cam [command] [arg 1]...[arg n]" );
      return;
      }

	cmd = ev->GetString( 1 );
  	if ( Event::Exists( cmd ) )
		{
		e = new Event( cmd );
		e->SetSource( EV_FROM_SCRIPT );
		e->SetThread( this );
		e->SetLineNumber( ev->GetLineNumber() );

      n = ev->NumArgs();
		for( i = 2; i <= n; i++ )
			{
			e->AddToken( ev->GetToken( i ) );
			}

      CameraMan.ProcessEvent( e );
      }
   else
      {
      ev->Error( "Unknown camera command '%s'.\n", cmd );
      }
   }

void CThread::SetLightStyle
	(
	Event *ev
	)
   {
   gi.SetLightStyle( ev->GetInteger( 1 ), ev->GetString( 2 ) );
   }

void CThread::KillThreadEvent
   (
   Event *ev
   )

   {
   Director.KillThread( ev->GetString( 1 ) );
   }

void CThread::SetThreadName
	(
   Event *ev
	)

	{
   threadName = ev->GetString( 1 );
	}

void CThread::Parse
   (
   const char *filename
   )

   {
   str      token;
   Script   script;
   int      eventnum;
   Event    *ev;

   script.LoadFile( filename );
   while( script.TokenAvailable( true ) )
      {
      token = script.GetToken( true );
      if ( token == "end" )
         {
         break;
         }

      eventnum = Event::FindEvent( token );
      if ( !eventnum )
         {
         gi.WDPrintf( "Unknown command '%s' in %s\n", token.c_str(), filename );
         script.SkipToEOL();
         }
      else
         {
         ev = new Event( eventnum );
         while( script.TokenAvailable( false ) )
            {
            ev->AddToken( script.GetToken( false ) );
            }

         ProcessEvent( ev );
         }
      }
   }

void CThread::SendCommandToSlaves
	(
	const char *name,
	Event *ev
	)

	{
	Event		   *sendevent;
	Entity	   *ent;
   TargetList  *tlist;
   int         i;
   int         num;

   if ( name && name[ 0 ] )
      {
      updateList.ClearObjectList();

      tlist = world->GetTargetList( str( name + 1 ) );
      num = tlist->list.NumObjects();
      for ( i = 1; i <= num; i++ )
         {
         ent = tlist->list.ObjectAt( i );

		   assert( ent );

		   sendevent = new Event( *ev );

			if ( !updateList.ObjectInList( ent->entnum ) )
			   {
			   updateList.AddObject( ent->entnum );

			   // Tell the object that we're about to send it some orders
			   ent->ProcessEvent( EV_Script_NewOrders );
			   }

		   // Send the command
		   ent->ProcessEvent( sendevent );
         }

      if ( !num )
         {
         warning( "SendCommandToSlaves", "Could not find target %s in world.\n", name );
         }
      }

   //
   // free up the event
   //
   delete ev;
	}

void CThread::ProcessCommand
	(
	int argc,
	const char **argv
	)

	{
	str		command;
	str		name;
	Event		*event;
	Entity	*ent;

	if ( argc < 1 )
		{
		return;
		}

	name = argv[ 0 ];
	if ( argc > 1 )
		{
		command = argv[ 1 ];
		}

	// Check for object commands
	if ( name[ 0 ] == '$' )
		{
      if ( Event::FindEvent( command.c_str() ) )
			{
			event = new Event( command );
			event->SetSource( EV_FROM_SCRIPT );
			event->SetThread( this );
			event->SetLineNumber( 0 );
			event->AddTokens( argc - 2, &argv[ 2 ] );
			SendCommandToSlaves( name.c_str(), event );
			}
		return;
		}

   // Check for entnum commands
   if ( name[ 0 ] == '*' )
      {
		if ( !IsNumeric( &name[ 1 ] ) )
			{
			gi.WPrintf( "Expecting numeric value for * command, but found '%s'\n", &name[ 1 ] );
			}
      else if ( Event::FindEvent( command.c_str() ) )
         {
         ent = G_GetEntity( atoi( &name[ 1 ] ) );
         if ( ent )
            {
            event = new Event( command );
				event->SetSource( EV_FROM_SCRIPT );
				event->SetThread( this );
				event->SetLineNumber( 0 );
            event->AddTokens( argc - 2, &argv[ 2 ] );
            ent->ProcessEvent( event );
            }
         else
            {
            gi.WPrintf( "Entity not found for * command\n" );
            }
         }
      return;
      }

	// Handle global commands
	if ( Event::FindEvent( name.c_str() ) )
		{
		event = new Event( name );
		event->SetSource( EV_FROM_SCRIPT );
		event->SetThread( this );
		event->SetLineNumber( 0 );
		event->AddTokens( argc - 1, &argv[ 1 ] );
		if ( !ProcessEvent( event ) )
			{
			gi.WPrintf( "Invalid global command '%s'\n", name.c_str() );
			}
		}
	}

inline void CThread::Archive( Archiver &arc )	// SMF
{
	int num;

	Interpreter::Archive( arc );

	arc.ArchiveFloat( &waitUntil );

	// save waiting for thread
	if ( waitingForThread )
		num = 1;
	else
		num = 0;

	arc.ArchiveInteger( &num );

	if ( num )
		arc.ArchiveObjectPointer( ( Class ** )&waitingForThread );

	arc.ArchiveString( &waitingForDeath );
	arc.ArchiveBoolean( &waitingForPlayer );

	if ( waitingFor )
		num = 1;
	else
		num = 0;

	arc.ArchiveInteger( &num );

	if ( num )
		arc.ArchiveObjectPointer( ( Class ** )&waitingFor );

	arc.ArchiveInteger( &waitingNumObjects );
}

void CThread::SetFloatVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	float value;

	var_name = ev->GetString( 1 );
	value    = ev->GetFloat( 2 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		levelVars.SetVariable( real_var_name, value );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		gameVars.SetVariable( real_var_name, value );
		}
	}

void CThread::SetVectorVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	Vector value;

	var_name = ev->GetString( 1 );
	value    = ev->GetVector( 2 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		levelVars.SetVariable( real_var_name, value );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		gameVars.SetVariable( real_var_name, value );
		}
	}

void CThread::SetStringVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	str value;

	var_name = ev->GetString( 1 );
	value    = ev->GetString( 2 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		levelVars.SetVariable( real_var_name, value );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		gameVars.SetVariable( real_var_name, value );
		}
	}

void CThread::GetFloatVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	ScriptVariable *var = NULL;

	var_name = ev->GetString( 1 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = levelVars.GetVariable( real_var_name );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = gameVars.GetVariable( real_var_name );
		}

	if ( var )
		ev->ReturnFloat( var->floatValue() );
	else
		{
		gi.WDPrintf( "%s variable not found", var_name.c_str() );
		ev->ReturnFloat( 0.0 );
		}
	}

void CThread::GetVectorVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	ScriptVariable *var = NULL;

	var_name = ev->GetString( 1 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = levelVars.GetVariable( real_var_name );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = gameVars.GetVariable( real_var_name );
		}

	if ( var )
		ev->ReturnVector( var->vectorValue() );
	else
		{
		gi.WDPrintf( "%s variable not found", var_name.c_str() );
		ev->ReturnVector( vec_zero );
		}
	}

void CThread::GetStringVar
	(
   Event *ev
	)

	{
	str var_name;
	const char *real_var_name;
	ScriptVariable *var = NULL;

	var_name = ev->GetString( 1 );

	if ( strncmp( var_name.c_str(), "level.", 6 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = levelVars.GetVariable( real_var_name );
		}
	else if ( strncmp( var_name.c_str(), "game.", 5 ) == 0 )
		{
		real_var_name = var_name.c_str() + 6;
		var = gameVars.GetVariable( real_var_name );
		}

	if ( var )
		ev->ReturnString( var->stringValue() );
	else
		{
		gi.WDPrintf( "%s variable not found", var_name.c_str() );
		ev->ReturnString( "\n" );
		}
	}

void CThread::CenterPrint
   (
   Event *ev
   )

   {
   int         j;
   gentity_t   *other;

	for( j = 0; j < game.maxclients; j++ )
		{
      other = &g_entities[ j ];
		if ( other->inuse && other->client )
			{
         gi.centerprintf( other, ev->GetString( 1 ) );
			}
      }
   }

void CThread::isActorDead
   (
	Event *ev
	)

	{
	ev->ReturnInteger( isActorDead( ev->GetString( 1 ) ) );
	}

qboolean CThread::isActorDead
   (
   const str &actor_name
	)

	{
	Actor *act;

	act = GetActor( actor_name );

	if ( !act || act->deadflag || act->health <= 0 )
		return true;

	return false;
	}

void CThread::isActorAlive
   (
	Event *ev
	)

	{
	ev->ReturnInteger( isActorAlive( ev->GetString( 1 ) ) );
	}

qboolean CThread::isActorAlive
   (
	const str &actor_name
	)

	{
	Actor *act;

	act = GetActor( actor_name );

	if ( !act || act->deadflag || act->health <= 0 )
		return false;

	return true;
	}