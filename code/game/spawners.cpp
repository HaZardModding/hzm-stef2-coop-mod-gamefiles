//-----------------------------------------------------------------------------
//
//  $Logfile:: /Code/DLLs/game/spawners.cpp                                  $
// $Revision:: 15                                                             $
//   $Author:: Sketcher                                                       $
//     $Date:: 6/28/02 10:37a                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Code/DLLs/game/spawners.cpp                                       $
// 
// 15    6/28/02 10:37a Sketcher
// Added _velocity to spawner to be passed on to the spawn
// 
// 14    6/26/02 10:47a Bschofield
// 
// - Added FOV support to func_spawnchain
// 
// 13    5/16/02 1:32p Steven
// Made sure modellist in spawn was clearing before adding new ones.
// 
// 12    5/13/02 2:49p Squirrel
// - added precompiled header support for Game.dsp
// 
// 11    5/10/02 6:41p Kharward
// Added a spawnnow event to force a func_spawn to spawn an entity and return
// it to the script.
// 
// 10    5/07/02 12:50p Ericf
// func_spawn now has a startanim, defaults to idle.
// 
// 9     4/26/02 2:45p Ericf
// Fixed an event reference bug
// 
// 8     4/26/02 2:25p Bschofield
// 
// - Repaired QUAKED entries
// 
// 7     4/23/02 3:21p Bschofield
// 
// -Added 8 optional parameters to Model. If the func_spawn has more than one
// model specified when it is told to spawn it chooses on of the models at
// random.
// 
// 6     3/13/02 3:42p Bschofield
// 
// - Removed string based Vector constuction, Vector operators and made all
// string based Vector construction explicit.
// 
// 5     2/18/02 1:35p Steven
// Event EV_TIKIONLY, EV_SCRIPTONLY, and EV_CODEONLY changes.
// 
// 4     1/29/02 9:18a Steven
// Added spawneffect to func_spawns.
// 
// 3     1/07/02 1:56p Steven
// Added a way to hide entities when spawned in by func spawners.
// 
// 2     10/08/01 7:53a Steven
// Lint first pass.
//
// 18    7/22/00 10:35p Markd
// added _spawnChance and _spawnItem to func_spawns
//
// 17    7/10/00 11:54p Markd
// added exit level code
//
// 16    7/06/00 2:22p Steven
// Fixed spawners getting their angles set correctly.
//
// 15    6/30/00 6:28p Steven
// Fixed a crash bug in Spawn::DoSpawn.
//
// 14    6/26/00 9:01p Markd
// fixed angle overriding angles in func_spawn
//
// 13    6/26/00 8:39p Markd
// Added func_randomspawn
//
// 12    6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 11    6/10/00 5:51p Aldie
// Fix G_DebugTargets function call
//
// 10    6/03/00 3:46p Aldie
// Added in g_debugtargets for debugging targetnames and targets
//
// 9     5/20/00 2:04p Aldie
// Fixed target with all the spawners
//
// 8     5/19/00 7:19p Aldie
// Added _spawnTarget command
//
// 7     4/29/00 12:07p Markd
// fixed precaching of func_spawners
//
// 6     4/15/00 3:38p Aldie
// Added "idle" animation to func_spawner
//
// 5     4/06/00 3:03p Markd
// fixed func_spawn's to pass on angles and scale
//
// 4     3/27/00 3:06p Aldie
// Fixed a warning
//
// 3     3/27/00 3:04p Aldie
// Took out some code that sends EV_Activate events to spawned ents
//
// 2     3/18/00 2:43p Aldie
// Changed some func_spawn functionality
//
// DESCRIPTION:
// Various spawning entities

/*****************************************************************************/
/*QUAKED func_spawn(0 0.25 0.5) (-8 -8 -8) (8 8 8)
"modelName" The name of the TIKI file you wish to spawn. (Required)
"spawnTargetName" This will be the targetname of the spawned model. (default is null)
"spawnTarget" This will be the target of the spawned model. (default is null)
"pickupThread" passed on to the spawned model
"key"       The item needed to activate this. (default nothing)
"attackMode" Attacking mode of the spawned actor (default 0)
******************************************************************************/

#include "_pch_cpp.h"
//#include "g_local.h"
#include "spawners.h"

Event EV_Spawn_ModelName
	(
	"modelname",
	EV_SCRIPTONLY,
   "sSSSSSSSS",
   "model_name1 model_name2 model_name3 model_name4 model_name5 model_name6 model_name7 model_name8 model_name9",
   "Sets up to nine model names for this spawn entity."
	);
Event EV_Spawn_SpawnTargetName
	(
	"spawntargetname",
	EV_SCRIPTONLY,
   "s",
   "spawntargetname",
   "Sets spawn target name for this spawn entity."
	);
Event EV_Spawn_SpawnTarget
	(
	"spawntarget",
	EV_SCRIPTONLY,
   "s",
   "spawntarget",
   "Sets spawn target for this spawn entity."
	);
Event EV_Spawn_SpawnNow
	(
	"spawnnow",
	EV_SCRIPTONLY,
	"@e",
	"return_entity",
	"Spawns the entity and returns it."
	);
Event EV_Spawn_AttackMode
	(
	"attackmode",
	EV_SCRIPTONLY,
   "i",
   "attackmode",
   "Sets the _attackMode for this spawn entity."
	);

Event EV_Spawn_PickupThread
	(
	"pickupthread",
	EV_SCRIPTONLY,
   "s",
   "threadName",
   "Sets the pickup thread for the spawned entity."
	);

Event EV_Spawn_AddSpawnItem
	(
	"spawn_spawnitem",
	EV_SCRIPTONLY,
	"s",
	"spawn_item_name",
	"Adds this named item to what will be spawned when this spawned entity is killed, if it is an actor."
	);
Event EV_Spawn_SetSpawnChance
	(
	"spawn_spawnchance",
	EV_SCRIPTONLY,
	"f",
	"spawn_chance",
	"Sets the chance that this spawned entity will spawn something when killed, if it is an actor."
	);

Event EV_Spawn_SetStartHidden
	(
	"starthidden",
	EV_SCRIPTONLY,
	"B",
	"hidden_bool",
	"Sets whether or not the entity starts hidden."
	);

Event EV_Spawn_SetSpawnEffect
	(
	"spawneffectname",
	EV_SCRIPTONLY,
	"s",
	"effectname",
	"Displays this effect on spawn."
	);

Event EV_Spawn_SetAnimName
	(
	"startanim",
	EV_SCRIPTONLY,
	"s",
	"animname",
	"Animation to spawn the actor with"
	);

Event EV_Spawn_SetSpawnVelocity
	(
	"setspawnvelocity",
	EV_SCRIPTONLY,
	"v",
	"velocity",
	"Sets the velocity to spawn with"
	);

CLASS_DECLARATION( ScriptSlave, Spawn, "func_spawn" )
{
	{ &EV_Activate,					DoSpawn },
	{ &EV_Spawn_ModelName,			ModelName },
	{ &EV_Spawn_SpawnTargetName,	SpawnTargetName },
	{ &EV_Spawn_AttackMode,			AttackMode },
	{ &EV_Spawn_SpawnTarget,		SpawnTarget },
	{ &EV_Spawn_PickupThread,		SetPickupThread },
	{ &EV_SetAngle,					SetAngleEvent },
	{ &EV_Spawn_AddSpawnItem,		SetSpawnItem },
	{ &EV_Spawn_SetSpawnChance,		SetSpawnChance },
	{ &EV_Spawn_SetStartHidden,		SetStartHidden },
	{ &EV_Spawn_SetSpawnEffect,		SetSpawnEffect },
	{ &EV_Spawn_SetAnimName,		SetAnimName },
	{ &EV_Spawn_SpawnNow,			SpawnNow },
	{ &EV_Spawn_SetSpawnVelocity,	SetSpawnVelocity },
	{ NULL, NULL }
};

void Spawn::SetAngleEvent( Event *ev )
{
	Entity::SetAngleEvent( ev );
}

void Spawn::SetPickupThread( Event *ev )
{
	_pickupThread = ev->GetString( 1 );
}

void Spawn::SetAnimName( Event *ev )
{
	_animName = ev->GetString( 1 );
}

void Spawn::SetSpawnVelocity( Event *ev )
{
	_velocity = ev->GetVector( 1 );
}

void Spawn::ModelName( Event *ev )
{
	assert( ev->NumArgs() > 0 );

	_modelNames.ClearObjectList();

	for (int i = 1; i <= ev->NumArgs(); i++)
	{
		str *modelname = new str( ev->GetString( i ) );
		_modelNames.AddObject( modelname );
		CacheResource( *modelname, this );
	}
}

void Spawn::SpawnTargetName( Event *ev )
{
	_spawnTargetName = ev->GetString( 1 );
}

void Spawn::SpawnTarget( Event *ev )
{
	_spawnTarget = ev->GetString( 1 );
}

void Spawn::AttackMode( Event *ev )
{
	_spawnTarget = ev->GetInteger( 1 );
}

void Spawn::SetSpawnItem( Event *ev )
{
	_spawnItem = ev->GetString( 1 );
}

void Spawn::SetSpawnChance( Event *ev ) 
{
	_spawnChance = ev->GetFloat( 1 );
}

void Spawn::SetStartHidden( Event *ev ) 
{
	if ( ev->NumArgs() > 0 )
		_startHidden = ev->GetBoolean( 1 );
	else
		_startHidden = true;
}

void Spawn::SetSpawnEffect( Event *ev ) 
{
	_effectName = ev->GetString( 1 );
}

Spawn::Spawn()
{
	setSolidType( SOLID_NOT );
	setMoveType( MOVETYPE_NONE );
	hideModel();
	
	_spawnChance = 0;
	_attackMode = 0;
	_startHidden = false;
	_animName = "idle";
	_velocity = Vector(0, 0, -1);
}

Spawn::~Spawn()
{
	for( int i = _modelNames.NumObjects(); i > 0; i-- )
	{
		delete _modelNames.ObjectAt( i );
	}
}

void Spawn::SetArgs( SpawnArgs &args )
{
	args.setArg( "origin",	va( "%f %f %f", origin[ 0 ], origin[ 1 ], origin[ 2 ] ) );
	args.setArg( "angle",	va( "%f", angles[ 1 ] ) );
	args.setArg( "angles",	va( "%f %f %f", angles[ 0 ], angles[ 1 ], angles[ 2 ] ) );
	

	if ( _modelNames.NumObjects() > 0 )
	{
		int randomModelIndex = ceil(G_Random() * _modelNames.NumObjects() );
		randomModelIndex = iClamp( randomModelIndex, 1, _modelNames.NumObjects() );
		args.setArg( "model",	*_modelNames.ObjectAt( randomModelIndex ) );
	}
	
	args.setArg( "attackMode", va( "%i",_attackMode ) );
	args.setArg( "scale",      va( "%f",edict->s.scale ) );
	if ( _spawnTargetName.length() )
	{
		args.setArg( "targetname", _spawnTargetName.c_str() );
	}
	if ( _spawnTarget.length() )
	{
		args.setArg( "target",     _spawnTarget.c_str() );
	}
	if ( _pickupThread.length() )
	{
		args.setArg( "pickupThread", _pickupThread.c_str() );
	}
	if ( _spawnItem.length() )
	{
		args.setArg( "spawnItem", _spawnItem.c_str() );
		args.setArg( "spawnChance", va( "%f", _spawnChance ) );
	}
	if ( _startHidden )
		args.setArg( "hide", "" );
	
	if ( _effectName.length() )
		args.setArg( "displayeffect", _effectName.c_str() );
}

void Spawn::DoSpawn( Event *ev )
{
	Entity *spawn;
	SpawnArgs args;
	
	if ( _modelNames.NumObjects() == 0 )
	{
		warning("Spawn", "No models set" );
	}
	
	SetArgs( args );
	
	spawn = args.Spawn();
	
	if ( spawn )
	{
		spawn->velocity = _velocity;
		
		Event *e = new Event( EV_Anim );
		e->AddString( _animName );
		spawn->PostEvent( e, EV_SPAWNARG );
		
		if ( g_debugtargets->integer )
		{
			G_DebugTargets( spawn, "Spawn::DoSpawn" );
		}
	}
}


//===============================================================
// Name:		SpawnNow
// Class:		Spawn
//
// Description: Spawns a new entity immediately, per the properties
//				already set on this object.
// 
// Parameters:	Event* -- return value is the spawned entity.
//
// Returns:		None
// 
//===============================================================
void Spawn::SpawnNow
(
	Event *ev
)
{
	Entity *spawn;
	SpawnArgs args;
	
	if ( _modelNames.NumObjects() == 0 )
	{
		warning("Spawn", "No models set" );
	}
	
	SetArgs( args );
	
	spawn = args.Spawn();
	
	if ( spawn )
	{
		// make sure spawned entity starts falling if necessary
		spawn->velocity = Vector(0, 0, -1);
		
		Event *e = new Event( EV_Anim );
		e->AddString( _animName );
		spawn->PostEvent( e, EV_SPAWNARG );
		
		if ( g_debugtargets->integer )
		{
			G_DebugTargets( spawn, "Spawn::DoSpawn" );
		}
	}
	
	ev->ReturnEntity( spawn );
}



/*****************************************************************************/
/*QUAKED func_randomspawn(0 0.25 0.5) (-8 -8 -8) (8 8 8) START_OFF
Randomly spawns an entity.  The time between spawns is determined by min_time and max_time
The entity can be turned off and on by triggering it
"modelName"   The name of the TIKI file you wish to spawn. (Required)
"key"         The item needed to activate this. (default nothing)
"min_time" The minimum time between spawns (default 0.2 seconds)
"max_time" The maximum time between spawns (default 1 seconds)
START_OFF - spawn is off by default
******************************************************************************/

Event EV_RandomSpawn_MinTime
	(
	"min_time",
	EV_SCRIPTONLY,
   "f",
   "minTime",
   "Minimum time between random spawns."
	);

Event EV_RandomSpawn_MaxTime
	(
	"max_time",
	EV_SCRIPTONLY,
   "f",
   "maxTime",
   "Maximum time between random spawns."
	);

Event EV_RandomSpawn_Think
	(
	"_randomspawn_think",
	EV_CODEONLY,
   NULL,
   NULL,
   "The function that actually spawns things in."
	);

CLASS_DECLARATION( Spawn, RandomSpawn, "func_randomspawn" )
	{
      { &EV_Activate,                   ToggleSpawn },
      { &EV_RandomSpawn_MinTime,        MinTime },
      { &EV_RandomSpawn_MaxTime,        MaxTime },
      { &EV_RandomSpawn_Think,          Think },
      { NULL, NULL }
	};

RandomSpawn::RandomSpawn()
   {
   min_time = 0.2f;
   max_time = 1.0f;
   if ( !LoadingSavegame && !( spawnflags & 1 ) )
      {
      PostEvent( EV_RandomSpawn_Think, min_time + ( G_Random( max_time - min_time ) ) );
      }
   }

void RandomSpawn::MinTime
   (
   Event *ev
   )

   {
   min_time = ev->GetFloat( 1 );
   }

void RandomSpawn::MaxTime
   (
   Event *ev
   )

   {
   max_time = ev->GetFloat( 1 );
   }

void RandomSpawn::ToggleSpawn
   (
   Event *ev
   )

   {
   if ( EventPending( EV_RandomSpawn_Think ) )
      {
      // if currently on, turn it off
      CancelEventsOfType( EV_RandomSpawn_Think );
      }
   else
      {
      Think( NULL );
      }
   }

void RandomSpawn::Think( Event *ev )
   {
   CancelEventsOfType( EV_RandomSpawn_Think );

   //
   // spawn our entity
   //
   DoSpawn( NULL );

   //
   // post the next time
   //
   PostEvent( EV_RandomSpawn_Think, min_time + ( G_Random( max_time - min_time ) ) );
   }

/*****************************************************************************/
/*QUAKED func_respawn(0 0.25 0.5) (-8 -8 -8) (8 8 8)
When the thing that is spawned is killed, this func_respawn will get
triggered.
"modelName"   The name of the TIKI file you wish to spawn. (Required)
"key"         The item needed to activate this. (default nothing)
******************************************************************************/

CLASS_DECLARATION( Spawn, ReSpawn, "func_respawn" )
	{
      { NULL, NULL }
	};

void ReSpawn::DoSpawn( Event *ev )
   {
   Entity      *spawn;
   SpawnArgs   args;

   SetArgs( args );

   // This will trigger the func_respawn when the thing dies
   args.setArg( "targetname", TargetName() );
   args.setArg( "target", TargetName() );

   spawn = args.Spawn();
   if ( spawn )
      {
      // make sure spawned entity starts falling if necessary
	   spawn->velocity = Vector(0, 0, -1);
      }
   }

/*****************************************************************************/
/*QUAKED func_spawnoutofsight(0 0.25 0.5) (-8 -8 -8) (8 8 8)
Will only spawn something out of sight of its targets.
"modelName"   The name of the TIKI file you wish to spawn. (Required)
"spawnTargetName" This will be the targetname of the spawned model. (default is null)
"spawnTarget" This will be the target of the spawned model. (default is null)
"key"         The item needed to activate this. (default nothing)
******************************************************************************/

CLASS_DECLARATION( Spawn, SpawnOutOfSight, "func_spawnoutofsight" )
	{
      { NULL, NULL }
	};

void SpawnOutOfSight::DoSpawn
	(
	Event *ev
	)

   {
   int         i;
   Entity	   *ent;
   gentity_t   *ed;
   trace_t     trace;
   qboolean    seen = false;

   // Check to see if I can see any players before spawning
 	for( i = 0; i < game.maxclients; i++ )
      {
      ed = &g_entities[ i ];
		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}

		ent = ed->entity;
	   if ( ( ent->health < 0.0f ) || ( ent->flags & FL_NOTARGET ) )
			{
			continue;
			}

      trace = G_Trace( origin, vec_zero, vec_zero, ent->centroid, this, MASK_OPAQUE, false, "SpawnOutOfSight::DoSpawn" );
      if ( trace.fraction == 1.0f )
         {
         seen = true;
         break;
         }
      }

   if ( seen )
      {
      return;
      }

   Spawn::DoSpawn( ev );
   }


/*****************************************************************************/
/*QUAKED func_spawnchain(0 0.25 0.5) (-8 -8 -8) (8 8 8)
Tries to spawn something out of the sight of players.  If it fails, it will
trigger its targets.
"modelName"   The name of the TIKI file you wish to spawn. (Required)
"spawnTargetName" This will be the targetname of the spawned model. (default is null)
"spawnTarget" This will be the target of the spawned model. (default is null)
"key"         The item needed to activate this. (default nothing)
******************************************************************************/

CLASS_DECLARATION( Spawn, SpawnChain, "func_spawnchain" )
	{
      { NULL, NULL }
	};

void SpawnChain::DoSpawn( Event *ev )
{
	qboolean    seen = false;

	// Check to see if this can see any players before spawning
	for( int i = 0; i < game.maxclients; i++ )
	{
		gentity_t *ed = &g_entities[ i ];
		if ( ed->inuse && ed->entity )
		{
			const Vector playerPosition( ed->centroid );
			
			Vector directionFromEntityToMe( origin - playerPosition );
			directionFromEntityToMe.normalize();
			
			const Vector viewAngles( ed->client->ps.viewangles );
			Vector entityForward;
			viewAngles.AngleVectors( &entityForward );
			entityForward.z = 0.0f;
			entityForward.normalize();
			
			const float entityFOV( DEG2RAD(ed->client->ps.fov) );
		
			assert( fCloseEnough( directionFromEntityToMe.length(), 1.0f, fEpsilon() ) );
			assert( fCloseEnough( entityForward.length(), 1.0f, fEpsilon() ) );

			const float angleToMe( acos( Vector::Dot( directionFromEntityToMe, entityForward ) ) );
			// Check to see if I am in the field of view of the entity
			if ( angleToMe <  entityFOV/2.0f )
			{
				Entity *entity = ed->entity;
				if ( ( entity->health >= 0.0f ) && !( entity->flags & FL_NOTARGET ) )
				{
					trace_t trace = G_Trace( origin, vec_zero, vec_zero, entity->centroid, this, MASK_OPAQUE, false, "SpawnChain::DoSpawn" );
					if ( trace.fraction == 1.0f )
					{
						seen = true;
						break;
					}
				}
			}
		}
	}
	
	// Couldn't spawn anything, so activate targets
	if ( seen )
	{
		const char  *name = Target();
		if ( name && strcmp( name, "" ) )
		{
			Entity *entity = NULL;
			do
			{
				entity = G_FindTarget( entity, name );
				if ( !entity )
				{
					break;
				}
				Event *event = new Event( EV_Activate );
				event->AddEntity( world );
				entity->PostEvent( event, 0.0f );
            } while ( 1 );
		}
		return;
	}
	
	Spawn::DoSpawn( ev );
}
