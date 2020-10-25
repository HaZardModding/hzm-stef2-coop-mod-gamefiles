//-----------------------------------------------------------------------------
//
//  $Logfile:: /Code/DLLs/game/spawners.h                                    $
// $Revision:: 9                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 6/28/02 10:37a                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Code/DLLs/game/spawners.h                                         $
// 
// 9     6/28/02 10:37a Sketcher
// Added _velocity to spawner to be passed on to the spawn
// 
// 8     5/10/02 6:41p Kharward
// Added a spawnnow event to force a func_spawn to spawn an entity and return
// it to the script.
// 
// 7     5/07/02 12:50p Ericf
// func_spawn now has a startanim, defaults to idle.
// 
// 6     4/23/02 3:21p Bschofield
// 
// -Added 8 optional parameters to Model. If the func_spawn has more than one
// model specified when it is told to spawn it chooses on of the models at
// random.
// 
// 5     3/10/02 12:56p Steven
// Save game stuff.
// 
// 4     1/29/02 9:38a Steven
// Added effect to func_spawn.
// 
// 3     1/07/02 1:56p Steven
// Added a way to hide entities when spawned in by func spawners.
// 
// 2     10/08/01 8:23a Steven
// Lint first pass.
//
// 10    7/22/00 10:35p Markd
// added spawnchance and spawnitem to func_spawns
//
// 9     7/10/00 11:54p Markd
// added exit level code
//
// 8     7/06/00 2:22p Steven
// Fixed spawners getting their angles set correctly.
//
// 7     6/26/00 8:39p Markd
// Added func_randomspawn
//
// 6     6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 5     5/27/00 2:56p Markd
// Save games 2nd pass
//
// 4     5/24/00 3:14p Markd
// first phase of save/load games
//
// 3     5/19/00 7:20p Aldie
// Added spawntarget
//
// 2     3/18/00 2:43p Aldie
// Changed some func_spawn functionality
//
// DESCRIPTION:
// Various spawning entities

#ifndef __SPAWNWERS_H__
#define __SPAWNWERS_H__

#include "g_local.h"
#include "scriptslave.h"

class Spawn : public ScriptSlave 
{
private:
	Container<str *>	_modelNames;
	str					_spawnTargetName;
	str					_spawnTarget;
	str					_pickupThread;
	str					_spawnItem;
	float				_spawnChance;
	int					_attackMode;
	qboolean			_startHidden;
	str					_effectName;
	str					_animName;
	Vector				_velocity;

	void				SetAngleEvent( Event *ev );
	void				SetPickupThread( Event *ev );
	void				ModelName( Event *ev );
	void				SpawnTargetName( Event *ev );
	void				SpawnTarget( Event *ev );
	void				AttackMode( Event *ev );
	void				SetSpawnItem( Event *ev );
	void				SetSpawnChance( Event *ev );
	void				SetStartHidden( Event *ev );
	void				SetSpawnEffect( Event *ev );
	void				SetAnimName( Event *ev );
	void				SpawnNow( Event *ev );
	void				SetSpawnVelocity( Event *ev );
		
protected:
	virtual 			~Spawn();
	void				SetArgs( SpawnArgs &args );
	virtual void		DoSpawn( Event *ev );
	
public:
	CLASS_PROTOTYPE( Spawn );
	
	
	Spawn();
	   virtual void   Archive( Archiver &arc );
};

inline void Spawn::Archive
(
	Archiver &arc
	)
{
	ScriptSlave::Archive( arc );
	if ( arc.Saving() )
	{
		int numberOfModels = _modelNames.NumObjects();
		arc.ArchiveInteger( &numberOfModels );
		for (int i = 1; i <= numberOfModels; i++)
		{
			arc.ArchiveString( _modelNames.ObjectAt( i ) );
		}
	}
	else
	{
		int numberOfModels;
		arc.ArchiveInteger( &numberOfModels );
		str *currentModelName;
		for (int i = 1; i <= numberOfModels; i++)
		{
			currentModelName = new str();
			arc.ArchiveString( currentModelName );
			_modelNames.AddObject( currentModelName );
		}
	}
	
	arc.ArchiveString(	&_spawnTargetName );
	arc.ArchiveString(	&_spawnTarget );
	arc.ArchiveString(	&_pickupThread );
	arc.ArchiveString(	&_spawnItem );
	arc.ArchiveFloat(	&_spawnChance );
	arc.ArchiveInteger( &_attackMode );
	arc.ArchiveBoolean( &_startHidden );
	arc.ArchiveString(	&_effectName );
	arc.ArchiveString(	&_animName );
	arc.ArchiveVector ( &_velocity );
}

class RandomSpawn : public Spawn
	{
   private:
      float    min_time;
      float    max_time;

      void           MinTime( Event *ev );
      void           MaxTime( Event *ev );
      void           ToggleSpawn( Event *ev );
      void           Think( Event *ev );

	public:
      CLASS_PROTOTYPE( RandomSpawn );


							RandomSpawn();
	   virtual void   Archive( Archiver &arc );
	};

inline void RandomSpawn::Archive
	(
	Archiver &arc
	)
   {
   Spawn::Archive( arc );

   arc.ArchiveFloat( &min_time );
   arc.ArchiveFloat( &max_time );
   }

class ReSpawn : public Spawn
	{
   protected:
		virtual void	DoSpawn( Event *ev );
 	public:
      CLASS_PROTOTYPE( ReSpawn );
	};

class SpawnOutOfSight : public Spawn
	{
   protected:
		virtual void	DoSpawn( Event *ev );
 	public:
      CLASS_PROTOTYPE( SpawnOutOfSight );
	};

class SpawnChain : public Spawn
	{
   protected:
		virtual void	DoSpawn( Event *ev );
 	public:
      CLASS_PROTOTYPE( SpawnChain );
	};

#endif //__SPAWNWERS_H__
