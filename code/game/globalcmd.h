//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/globalcmd.h                                     $
// $Revision:: 6                                                              $
//     $Date:: 5/03/01 8:24p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/globalcmd.h                                          $
// 
// 6     5/03/01 8:24p Steven
// Fixed up some is actor dead stuff.
// 
// 5     5/03/01 5:23a Sketcher
// Since it appears the script language has no NOT, I am adding an isActorAlive
// event
// 
// 4     5/01/01 2:43p Sketcher
// Added a global script command to check if an actor is dead
// 
// 3     1/24/01 10:17a Steven
// Added centerprint back in.
// 
// 2     1/23/01 8:56a Steven
// Added level vars and game vars back in.
// 
// 1     1/16/01 2:13p Steven
// Script C merge.
// 
// 11    10/04/00 2:50p Darin
// Added 'level_ai' command
// 
// 10    9/29/00 3:39p Darin
// CPrint - centerprint from script
// 
// 9     8/28/00 11:02p Sfleming
// save/load first pass
// 
// 8     8/21/00 3:00p Darin
// Supported new Fade types, "fadeisactive" event, "drugview" event.
// 
// 5     5/04/00 6:39p Jimdose
// added  SetLightStyle, KillThreadEvent, and SetThreadName
// 
//
// DESCRIPTION:
// Global commands for scripts
//

#ifndef __GLOBALCMD_H__
#define __GLOBALCMD_H__

#include "interpreter.h"
#include "g_local.h"

extern Event EV_ProcessCommands;
extern Event EV_ScriptThread_Execute;
extern Event EV_ScriptThread_Callback;
extern Event EV_ScriptThread_ThreadCallback;
extern Event EV_ScriptThread_DeathCallback;
extern Event EV_ScriptThread_CreateThread;
extern Event EV_ScriptThread_TerminateThread;
extern Event EV_ScriptThread_ControlObject;
extern Event EV_ScriptThread_Goto;
extern Event EV_ScriptThread_Pause;
extern Event EV_ScriptThread_Wait;
extern Event EV_ScriptThread_WaitFor;
extern Event EV_ScriptThread_WaitForThread;
extern Event EV_ScriptThread_WaitForSound;
extern Event EV_ScriptThread_Print;
extern Event EV_ScriptThread_PrintInt;
extern Event EV_ScriptThread_PrintFloat;
extern Event EV_ScriptThread_PrintVector;
extern Event EV_ScriptThread_NewLine;
extern Event EV_ScriptThread_Clear;
extern Event EV_ScriptThread_Assert;
extern Event EV_ScriptThread_Break;
extern Event EV_ScriptThread_Clear;
extern Event EV_ScriptThread_Trigger;
extern Event EV_ScriptThread_Spawn;
extern Event EV_ScriptThread_Map;
extern Event EV_ScriptThread_SetCvar;
extern Event EV_ScriptThread_CueCamera;
extern Event EV_ScriptThread_CuePlayer;
extern Event EV_ScriptThread_FreezePlayer;
extern Event EV_ScriptThread_ReleasePlayer;
extern Event EV_ScriptThread_SetCinematic;
extern Event EV_ScriptThread_SetNonCinematic;
extern Event EV_ScriptThread_SetSkipThread;

class CThread : public Interpreter
   {
   private:
		float						waitUntil;
		CThread              *waitingForThread;
      str						waitingForDeath;
      qboolean             waitingForPlayer;
      TargetList           *waitingFor;
		int						waitingNumObjects;

   public:
      CLASS_PROTOTYPE( CThread );

                           CThread();

      void                 ExecuteFunc( Event *ev );
      void                 ClearWaitFor( void );
      qboolean             WaitingFor( Entity *obj );
      void                 ObjectMoveDone( Event *ev );
      void                 CreateThread( Event *ev );
      void                 TerminateThread( Event *ev );
      void                 EventPause( Event *ev );
      void                 EventWait( Event *ev );
      void                 EventWaitFor( Event *ev );
      void                 EventWaitForThread( Event *ev );
      void                 EventWaitForDeath( Event *ev );
      void                 EventWaitForSound( Event *ev );
      void                 EventWaitForDialog( Event *ev );
      void                 EventWaitForPlayer( Event *ev );
		void						CPrint( Event *ev );								// dhm
      void                 Print( Event *ev );
      void                 PrintInt( Event *ev );
      void                 PrintFloat( Event *ev );
      void                 PrintVector( Event *ev );
      void                 NewLine( Event *ev );
      void                 Assert( Event *ev );
      void                 Break( Event *ev );
      void                 ScriptCallback( Event *ev );
      void                 ThreadCallback( Event *ev );
      void                 DeathCallback( Event *ev );
      void                 DoMove( void );
      void                 TriggerEvent( Event *ev );
      void                 CacheResourceEvent( Event *ev );
      void                 RegisterAlias( Event *ev );
      void                 RegisterAliasAndCache( Event *ev );
      void                 MapEvent( Event *ev );
      void                 SetCvarEvent( Event *ev );
      void                 CueCamera( Event *ev );
      void                 CuePlayer( Event *ev );
      void                 FreezePlayer( Event *ev );
      void                 ReleasePlayer( Event *ev );
      void                 FakePlayer( Event *ev );
      void                 RemoveFakePlayer( Event *ev );
      void                 Spawn( Event *ev );
      void                 Letterbox( Event *ev );
      void                 ClearLetterbox( Event *ev );
      void                 FadeIn( Event *ev );
      void                 ClearFade( Event *ev );
      void                 FadeOut( Event *ev );
		void						FadeIsActive( Event *ev );
      void                 MusicEvent( Event *ev );
      void                 MusicVolumeEvent( Event *ev );
      void                 RestoreMusicVolumeEvent( Event *ev );
      void                 ForceMusicEvent( Event *ev );
      void                 SoundtrackEvent( Event *ev );
      void                 RestoreSoundtrackEvent( Event *ev );
      void                 SetCinematic( Event *ev );
      void                 SetNonCinematic( Event *ev );
		void						SetLevelAI( Event *ev );						// DHM
      void                 SetSkipThread( Event *ev );
      void                 PassToPathmanager( Event *ev );
      void                 StuffCommand( Event *ev );
      void                 KillEnt( Event *ev );
      void                 RemoveEnt( Event *ev );
      void                 KillClass( Event *ev );
      void                 RemoveClass( Event *ev );
      void                 GetEntityEvent( Event *ev );
      void                 RandomFloat( Event *ev );
      void                 RandomInteger( Event *ev );
      void                 CameraCommand( Event *ev );
      void                 SetLightStyle( Event *ev );
      void                 KillThreadEvent( Event *ev );
      void                 SetThreadName( Event *ev );

      CThread              *WaitingOnThread( void );
      const char				*WaitingOnDeath( void );
      qboolean             WaitingOnPlayer( void );

		void                 DelayedStart( float delay );
		void                 Start( void );

      void                 SendCommandToSlaves( const char *name, Event *ev );
      void                 Parse( const char *filename );
      void                 ProcessCommand( int argc, const char **argv );

      void						Archive( Archiver &arc );	// SMF

		void						SetFloatVar( Event *ev );
		void						SetVectorVar( Event *ev );
		void						SetStringVar( Event *ev );
		void						GetFloatVar( Event *ev );
		void						GetVectorVar( Event *ev );
		void						GetStringVar( Event *ev );

		void                 CenterPrint( Event *ev );
		void				      isActorDead( Event *ev );
		qboolean             isActorDead( const str &actor_name );

		void                 isActorAlive( Event *ev );
		qboolean             isActorAlive( const str &actor_name );
   };

typedef SafePtr<CThread> ThreadPtr;

inline void CThread::DelayedStart
	(
   float delay
	)
	{
	CancelEventsOfType( EV_ScriptThread_Execute );
   PostEvent( EV_ScriptThread_Execute, delay );
   }

inline void CThread::Start
	(
   void
	)
	{
	CancelEventsOfType( EV_ScriptThread_Execute );
   ProcessEvent( EV_ScriptThread_Execute );
   }

inline CThread *CThread::WaitingOnThread
	(
	void
	)

	{
	return waitingForThread;
	}

inline const char *CThread::WaitingOnDeath
	(
	void
	)

	{
	return waitingForDeath.c_str();
	}

inline qboolean CThread::WaitingOnPlayer
	(
	void
	)

	{
   return waitingForPlayer;
	}

#endif
