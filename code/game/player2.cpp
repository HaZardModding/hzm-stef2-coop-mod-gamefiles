//-----------------------------------------------------------------------------
//
//  $Logfile:: /fakk2_code/fakk2/fgame/player.cpp                             $
// $Revision:: 63                                                             $
//   $Author:: Jimdose                                                        $
//     $Date:: 8/06/99 6:52p                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /fakk2_code/fakk2/fgame/player.cpp                                  $
// 
// 63    8/06/99 6:52p Jimdose
// changed format of state machine callback functions
// 
// 62    8/06/99 6:39p Aldie
// Started moving over to new weapons system
// 
// 61    8/04/99 6:02p Jimdose
// now respond to the movetype command from the state machine
// 
// 60    8/03/99 3:36p Aldie
// Made the crossbow the default weapon
// 
// 59    7/30/99 7:53p Markd
// Added jumping ability to the player
// 
// 58    7/29/99 5:33p Markd
// Fixed weird compiler bug
// 
// 57    7/23/99 3:27p Aldie
// 
// 56    7/19/99 7:55p Markd
// removed unused leftsword, lefttorch, torch loadings
// 
// 55    7/07/99 4:06p Jimdose
// changed julie2.st to julie.st
// 
// 54    7/07/99 2:53p Jimdose
// added new keys for controlling the player
// added ResetState and LoadState
// 
// 53    7/06/99 8:53p Jimdose
// only trace down stepsize from move when on ground
// 
// 52    7/06/99 8:33p Jimdose
// removed unused player code
// added state machine for player animation
// 
// 51    6/25/99 5:24p Markd
// changed the player animations and movement speed
//
// DESCRIPTION:
// Class definition of the player.
//
#include "g_local.h"
#include "entity.h"
#include "player.h"
#include "worldspawn.h"
#include "weapon.h"
#include "trigger.h"
#include "scriptmaster.h"
#include "vehicle.h"
#include "path.h"
#include "navigate.h"
#include "misc.h"
#include "earthquake.h"
#include "gravpath.h"
#include "armor.h"
#include "inventoryitem.h"
#include "gibs.h"
#include "deadbody.h"
#include "actor.h"
#include "object.h"
#include "characterstate.h"

//Forward
//Back
//TurnRight
//TurnLeft
//Moveleft (strafe)
//Moveright (strafe)
//Moveup (Jump)
//Movedown (Duck)
//Action (Use)
//Sneak (Toggle or Momentary)
//Speed/Walk (Toggle or Momentary)
//Fire Left hand
//Fire Right hand

const Vector power_color( 0.0, 1.0, 0.0 );
const Vector acolor( 1.0, 1.0, 1.0 );
const Vector bcolor( 1.0, 0.0, 0.0 );

Event EV_Player_GodCheat( "superfuzz", EV_CHEAT );
Event EV_Player_NoTargetCheat( "wallflower", EV_CHEAT );
Event EV_Player_NoClipCheat( "nocollision", EV_CHEAT );
Event EV_Player_GiveAllCheat( "wuss", EV_CHEAT );
Event EV_Player_EndLevel( "endlevel" );

Event EV_Player_DevGodCheat( "god", EV_CHEAT );
Event EV_Player_DevNoTargetCheat( "notarget", EV_CHEAT );
Event EV_Player_DevNoClipCheat( "noclip", EV_CHEAT );

Event EV_Player_PrevWeapon( "weapprev", EV_CONSOLE );
Event EV_Player_NextWeapon( "weapnext", EV_CONSOLE );
Event EV_Player_PrevItem( "invprev", EV_CONSOLE );
Event EV_Player_NextItem( "invnext", EV_CONSOLE );
Event EV_Player_UseInventoryItem( "invuse", EV_CONSOLE );
Event EV_Player_GiveCheat( "give", EV_CHEAT );
Event EV_Player_Take( "take" );
Event EV_Player_UseItem( "use", EV_CONSOLE );
Event EV_Player_GameVersion( "gameversion", EV_CONSOLE );
Event EV_Player_Fov( "fov" );
Event EV_Player_Kill( "playerkill", EV_CONSOLE );
Event EV_Player_Dead( "dead" );
Event EV_Player_SpawnEntity( "spawn", EV_CHEAT );
Event EV_Player_SpawnActor( "actor", EV_CHEAT );
Event EV_Player_AttackDone( "attackdone" );
Event EV_Player_AddPathNode( "addnode", EV_CHEAT );
Event EV_Player_Respawn( "respawn" );
Event EV_Player_TestThread( "testthread", EV_CHEAT );
Event EV_Player_PowerupTimer( "poweruptimer" );
Event EV_Player_UpdatePowerupTimer( "updatepoweruptime" );
Event EV_Player_SetFlashColor( "setflashcolor" );
Event EV_Player_ClearFlashColor( "clearflashcolor" );
Event EV_Player_Skin( "skin" );
Event EV_Player_ResetState( "resetstate", EV_CHEAT );
Event EV_Player_WhatIs( "whatis", EV_CHEAT );
Event EV_Player_ActorInfo( "actorinfo", EV_CHEAT );
Event EV_Player_Taunt( "taunt", EV_CONSOLE );
Event EV_Player_KillEnt( "killent", EV_CONSOLE );
Event EV_Player_KillClass( "killclass", EV_CONSOLE );
Event EV_Player_RemoveEnt( "removeent", EV_CONSOLE );
Event EV_Player_RemoveClass( "removeclass", EV_CONSOLE );
Event EV_Player_ActivateNewWeapon( "activatenewweapon" );
Event EV_Player_DeactivateWeapon( "deactivateweapon" );
Event EV_Player_AttackEnd( "attackend" );
Event EV_Player_Jump( "jump" );

#define UPRIGHT_SPEED		320.0f
#define CROUCH_SPEED			110.0f
#define ACCELERATION			10.0f
#define TAUNT_TIME			1.0f

/*
==============================================================================

PLAYER

==============================================================================
*/

cvar_t * s_debugmusic;
cvar_t * whereami;

CLASS_DECLARATION( Sentient, Player, "player" )
	{
	   { &EV_ClientMove,					         ClientThink },
	   { &EV_ClientEndFrame,			         EndFrame },
		{ &EV_Vehicle_Enter,				         EnterVehicle },
		{ &EV_Vehicle_Exit,				         ExitVehicle },
                                             
      { &EV_Player_EndLevel,		            EndLevel },
                                             
	   { &EV_Player_PrevWeapon,		         EventPreviousWeapon },
	   { &EV_Player_NextWeapon,		         EventNextWeapon },
      { &EV_Player_PrevItem,	   	         EventPreviousItem },
	   { &EV_Player_NextItem,  		         EventNextItem },
		{ &EV_Player_UseItem,			         EventUseItem },
      { &EV_Player_UseInventoryItem,         EventUseInventoryItem },
	   { &EV_Player_GiveCheat,			         GiveCheat },
		{ &EV_Player_GiveAllCheat,		         GiveAllCheat },
      { &EV_Player_Take,   			         Take },
	   { &EV_Player_GodCheat,			         GodCheat },
      { &EV_Player_DevGodCheat,		         GodCheat },
	   { &EV_Player_NoTargetCheat,	         NoTargetCheat },
      { &EV_Player_DevNoTargetCheat,         NoTargetCheat },
	   { &EV_Player_NoClipCheat,		         NoclipCheat },
      { &EV_Player_DevNoClipCheat,	         NoclipCheat },
	   { &EV_Player_GameVersion,		         GameVersion },
	   { &EV_Player_Fov,					         Fov },
		{ &EV_Player_Kill,				         Kill },
      { &EV_Player_Dead,				         Dead },
		{ &EV_Player_SpawnEntity,		         SpawnEntity },
      { &EV_Player_SpawnActor,               SpawnActor },
		{ &EV_Player_Respawn,			         Respawn },
                                             
		{ &EV_Pain,							         Pain },
		{ &EV_Killed,						         Killed },
      { &EV_Gib,                             GibEvent },
		{ &EV_GotKill,						         GotKill },
                                             
		{ &EV_Player_AttackDone,		         DoneFiring },
		{ &EV_Player_TestThread,		         TestThread },

      { &EV_Player_PowerupTimer,		         SetPowerupTimer },
      { &EV_Player_UpdatePowerupTimer,		   UpdatePowerupTimer },

      { &EV_Player_ResetState,               ResetState },

		{ &EV_Player_WhatIs,							WhatIs },
      { &EV_Player_ActorInfo,                ActorInfo },
		{ &EV_Player_Taunt,							Taunt },
		{ &EV_Player_KillEnt,						KillEnt },
		{ &EV_Player_RemoveEnt,						RemoveEnt },
		{ &EV_Player_KillClass,						KillClass },
		{ &EV_Player_RemoveClass,					RemoveClass },
      { &EV_Player_SetFlashColor,    		   SetFlashColor },
      { &EV_Player_ClearFlashColor,    		ClearFlashColor },
      { &EV_Player_Skin,               		SetSkin },
      { &EV_Player_AttackEnd,               	AttackEndEvent },
  		{ &EV_Sentient_AnimLoop,			      EndAnim },
      { &EV_Player_Jump,               		Jump },
      { &EV_Player_ActivateNewWeapon,        ActivateNewWeapon },
      { &EV_Player_DeactivateWeapon,         DeactivateWeapon },

      { NULL, NULL }
	};

usercmd_t recent_ucmd;

bool returntrue
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return true;
   }

bool checkforward
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return recent_ucmd.forwardmove > 0;
   }

bool checkbackward
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return recent_ucmd.forwardmove < 0;
   }

bool checkstrafeleft
   (
   Conditional &condition,
   Entity &ent

   )

   {
   return recent_ucmd.rightmove < 0;
   }

bool checkstraferight
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return recent_ucmd.rightmove > 0;
   }

bool checkjump
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return recent_ucmd.upmove > 0;
   }

bool animdone;

bool checkanimdone
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return animdone;
   }

bool checkattackleft
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return ( recent_ucmd.buttons & BUTTON_ATTACKLEFT ) != 0;
   }

bool checkattackright
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return ( recent_ucmd.buttons & BUTTON_ATTACKRIGHT ) != 0;
   }

bool checksneak
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return ( recent_ucmd.buttons & BUTTON_SNEAK ) != 0;
   }

bool checkrun
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return ( recent_ucmd.buttons & BUTTON_RUN ) != 0;
   }

bool checkholsterweapon
   (
   Conditional &condition,
   Entity &ent
   )

   {
   return ( recent_ucmd.buttons & BUTTON_HOLSTERWEAPON ) != 0;
   }

bool checkuse
   (
   Conditional &condition,
   Entity &ent
   )
   
   {
   return ( recent_ucmd.buttons & BUTTON_USE ) != 0;
   }

bool checkuseweaponleft
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      return ( ( player.GetNewActiveWeapon() != NULL ) && ( player.GetNewActiveWeaponNumber() == WEAPON_LEFT ) );
      }
   else
      {
      return false;
      }
   }

bool checkuseweaponright
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      return ( ( player.GetNewActiveWeapon() != NULL ) && ( player.GetNewActiveWeaponNumber() == WEAPON_RIGHT ) );
      }
   else
      {
      return false;
      }
   }

bool checkleftcrossbow
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      Weapon *weapon = player.GetActiveWeapon( WEAPON_LEFT );

      return ( weapon && !strcmp( "Crossbow", weapon->edict->entname ) );
      }
   else
      {
      return false;
      }
   }

bool checkrightcrossbow
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      Weapon *weapon = player.GetActiveWeapon( WEAPON_RIGHT );

      return ( weapon && !strcmp( "Crossbow", weapon->edict->entname ) );
      }
   else
      {
      return false;
      }
   }

// Check to see if any of the active weapons need to be put away
bool checkputawayleft
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      Weapon *weapon = player.GetActiveWeapon( WEAPON_LEFT );

      if ( weapon && weapon->GetPutaway() )
         return true;
      else 
         return false;
      }
   else 
      {
      return false;
      }
   }

bool checkputawayright
   (
   Conditional &condition,
   Entity &ent
   )

   {
   if ( ent.isSubclassOf( Player ) )
      {
      Player &player = ( Player & )ent;
      
      Weapon *weapon = player.GetActiveWeapon( WEAPON_RIGHT );

      if ( weapon && weapon->GetPutaway() )
         return true;
      else 
         return false;
      }
   else 
      {
      return false;
      }
   }

Conditional CheckDefault( "default", returntrue );
Conditional CheckAttackLeft( "ATTACKLEFT", checkattackleft );
Conditional CheckAttackRight( "ATTACKRIGHT", checkattackright );
Conditional CheckSneak( "SNEAK", checksneak );
Conditional CheckRun( "RUN", checkrun );
Conditional CheckHolsterWeapon( "HOLSTERWEAPON", checkholsterweapon );
Conditional CheckUse( "USE", checkuse );
Conditional CheckForward( "FORWARD", checkforward );
Conditional CheckBackward( "BACKWARD", checkbackward );
Conditional CheckStrafeLeft( "STRAFE_LEFT", checkstrafeleft );
Conditional CheckStrafeRight( "STRAFE_RIGHT", checkstraferight );
Conditional CheckJump( "JUMP", checkjump );
Conditional CheckAnimDone( "ANIMDONE", checkanimdone );
Conditional CheckUseWeaponLeft( "USEWEAPON_LEFT", checkuseweaponleft );
Conditional CheckUseWeaponRight( "USEWEAPON_RIGHT", checkuseweaponright );
Conditional CheckWeaponCrossbowLeft( "LEFT_WEAPON_IS_CROSSBOW", checkleftcrossbow );
Conditional CheckWeaponCrossbowRight( "RIGHT_WEAPON_IS_CROSSBOW", checkrightcrossbow );
Conditional CheckWeaponPutawayLeft( "PUTAWAYLEFT", checkputawayleft );
Conditional CheckWeaponPutawayRight( "PUTAWAYRIGHT", checkputawayright );

StateMap *statemap = NULL;

Player::Player()
	{
   LoadStateTable();

   respawn_time = -1;

   camera = NULL;

	damage_blood = 0;
	damage_alpha = 0;

   action_level = 0;

	fov = atof( Info_ValueForKey( client->pers.userinfo, "fov" ) );
	if ( fov < 1 )
      {
		fov = 90;
      }
	else if ( fov > 160 )
      {
		fov = 160;
      }

	s_debugmusic = gi.cvar( "s_debugmusic", "0", 0 );
	whereami = gi.cvar( "whereami", "0", 0 );

   // Remove him from the world until we spawn him
   unlink();
	}

void Player::InitSkin
   (
   void
   )

   {
   // If this is a new level, there will be no custom skin, so go back to the original blade skin.
   if ( !LoadingSavegame && !deathmatch->integer )
      {
      int playernum = edict-g_entities-1;

      strcpy( client->pers.skin, "blade_base" );

      /* GAMEFIX
      // combine name, skin and model into a configstring
	   gi.configstring( CS_PLAYERSKINS+playernum, va( "%s\\%s\\%s",
                       client->pers.netname,
                       client->pers.model,
                       client->pers.skin ) );
                       */
      }
   }


void Player::Init
	(
	void
	)

	{
   InitClient();
   InitPhysics();
   InitPowerups();
   InitWorldEffects();
   InitMusic();
   InitView();
   InitState();
   InitEdict();
   InitModel();
   InitWeapons();
   InitSkin();

   // don't call RestoreEnt when respawning
   if ( !LoadingServer && ( deathmatch->integer || !PersistantData.RestoreEnt( this ) ) )
      {
      InitInventory();
      InitHealth();
      }

   ChooseSpawnPoint();

   if ( !deathmatch->integer )
      {
      gi.SendConsoleCommand( "con_clearfade\n" );
      }

   // make sure we put the player back into the world
   link();
	}

void Player::WritePersistantData
   (
   SpawnArgGroup &group
   )

   {
   str text;
   char t[ 3 ];
   int hi;
   int lo;
   int i;

   // encode the damage states into a text string
   t[ 2 ] = 0;
   for( i = 0; i < MAX_MODEL_SURFACES; i++ )
      {
      hi = ( edict->s.surfaces[ i ] >> 4 ) & 0xf;
      lo = edict->s.surfaces[ i ] & 0xf;
      t[ 0 ] = ( char )( 'A' + hi );
      t[ 1 ] = ( char )( 'A' + lo );
      text += t;
      }

   G_SetSpawnArg( "savemodel", savemodel.c_str() );
   G_SetSpawnArg( "saveskin", saveskin.c_str() );
   G_SetSpawnArg( "damage_groups", text.c_str() );
   G_SetFloatArg( "fov", fov );
   G_SetIntArg( "flags", flags & ( FL_GODMODE | FL_NOTARGET ) );

   Sentient::WritePersistantData( group );
   }

void Player::RestorePersistantData
   (
   SpawnArgGroup &group
   )

   {
   int i;
   int len;
   str text;
   const char *ptr;
   int hi;
   int lo;

   Sentient::RestorePersistantData( group );

   group.RestoreArgs( 1 );

   // clear the damage states
   memset( edict->s.surfaces, 0, sizeof( edict->s.surfaces ) );

   savemodel = G_GetStringArg( "savemodel" );
   saveskin = G_GetStringArg( "saveskin" );

   text = G_GetStringArg( "damage_groups" );
   len = text.length() >> 1;
   if ( len > MAX_MODEL_SURFACES )
      {
      len = MAX_MODEL_SURFACES;
      }

   // decode the damage states from text string
   ptr = text.c_str();
   for( i = 0; i < len; i++ )
      {
      hi = ( *ptr++ - 'A' ) & 0xf;
      lo = ( *ptr++ - 'A' ) & 0xf;
      edict->s.surfaces[ i ]  = ( hi << 4 ) + lo;
      }

   flags |= G_GetIntArg( "flags" );
   fov = G_GetFloatArg( "fov", 90 );

   // prevent the player from starting dead
   if ( health < 1 )
      {
      health = 1;
      }
   }

void Player::InitEdict
   (
   void
   )

   {
   // entity state stuff
   setSolidType( SOLID_BBOX );
	setMoveType( MOVETYPE_WALK );
	setSize( Vector( -16, -16, 0 ), Vector( 16, 16, STAND_HEIGHT ) );
	edict->clipmask	 = MASK_PLAYERSOLID;
	edict->svflags		&= ~SVF_DEADMONSTER;
   edict->svflags    &= ~SVF_HIDEOWNER;
   edict->owner       = NULL;

	// clear entity state values
	edict->s.eFlags		= 0;
	edict->s.frame	      = 0;
   }

void Player::InitMusic
   (
   void
   )

   {
   //
   // reset the music
   //
	client->ps.current_music_mood  = mood_normal;
	client->ps.fallback_music_mood = mood_normal;
   ChangeMusic( "normal", "normal", false );

	client->ps.music_volume           = 1.0;
	client->ps.music_volume_fade_time = 0.0;
	ChangeMusicVolume( 1.0, 0.0 );

   music_forced = false;
   }

void Player::InitClient
   (
   void
   )

   {
	client_persistant_t	saved;
	client_respawn_t		resp;

   // deathmatch wipes most client data every spawn
   if ( deathmatch->integer )
		{
		char userinfo[ MAX_INFO_STRING ];

		resp = client->resp;
		memcpy( userinfo, client->pers.userinfo, sizeof( userinfo ) );
		G_InitClientPersistant( client );
		G_ClientUserinfoChanged( edict, userinfo );
		}
	else
		{
		memset( &resp, 0, sizeof( resp ) );
		}

	// clear everything but the persistant data and fov
	saved = client->pers;
	memset( client, 0, sizeof( *client ) );
	client->pers = saved;
	client->resp = resp;

   client->ps.playernum = client - game.clients + 1;
   }

void Player::InitState
   (
   void
   )

   {
   gibbed             = false;
   lastTauntTime      = 0;

   takedamage			 = DAMAGE_AIM;
   deadflag				 = DEAD_NO;
	flags					&= ~FL_NO_KNOCKBACK;
	flags					|= ( FL_BLOOD | FL_DIE_GIBS );

   if ( parentmode->integer )
      {
      flags &= ~FL_BLOOD;
      flags &= ~FL_DIE_GIBS;
      }
   }

void Player::InitHealth
   (
   void
   )

   {
   // Don't do anything if we're loading a server game.
   // This is either a loadgame or a restart
   if ( LoadingServer )
      {
      return;
      }

   // reset the health values
   health	  = 100;
	max_health = 100;

   // clear the damage states
   memset( edict->s.surfaces, 0, sizeof( edict->s.surfaces ) );
   }

void Player::InitModel
   (
   void
   )

   {
   str model;

   // Model stuff
   edict->s.renderfx |= RF_CUSTOMSKIN;
   edict->s.skinNum   = edict->s.number - 1;

   setModel( "aldietest.tik" );
   //setModel( "julie3_legs.tik", legs );
   //setModel( "julie3_torso.tik", torso );
   //setModel( "julie3_head.tik", head );

   SetAnim( currentState->getLegAnim() );

	showModel();
   }

void Player::InitPhysics
   (
   void
   )

   {
   // Physics stuff
   onladder       = false;
   oldvelocity    = vec_zero;
	velocity       = vec_zero;
	gravity        = 1.0;
   falling        = false;
   fallsurface    = NULL;
	mass				= 200;
   memset( &last_ucmd, 0, sizeof( last_ucmd ) );
   }

void Player::InitPowerups
   (
   void
   )

   {
   // powerups
   poweruptimer       = 0;
   poweruptype        = 0;
   edict->s.renderfx &= ~( RF_ENVMAPPED );
   }

void Player::InitWorldEffects
   (
   void
   )

   {
   // world effects
   next_drown_time = 0;
	air_finished    = level.time + 20;
	old_waterlevel  = 0;
	drown_damage    = 0;
   }

void Player::InitWeapons
   (
   void
   )

   {
   // weapon stuff
   firing       = false;
   firedown     = false;
   firedowntime = 0;
	gunoffset    = Vector( 0, 0, STAND_HEIGHT );
   }

void Player::InitInventory
   (
   void
   )

   {
   // Don't do anything if we're loading a server game.
   // This is either a loadgame or a restart
   if ( LoadingServer )
      {
      return;
      }

   Weapon *weap = giveWeapon( "crossbow.tik" );
   }

void Player::InitView
   (
   void
   )

   {
   // view stuff
   camera         = NULL;
	v_angle			= vec_zero;
	oldviewangles	= vec_zero;
	viewheight	   = STAND_EYE_HEIGHT;

   // blend stuff
   damage_blend	= vec_zero;
   flash_color[0] = flash_color[1] = flash_color[2] = flash_color[3] = 0;
   }

void Player::ChooseSpawnPoint
   (
   void
   )

   {
   // set up the player's spawn location
   SelectSpawnPoint( origin, angles );
	setOrigin( origin	+ "0 0 1" );
   origin.copyTo( edict->s.origin2 );
	edict->s.renderfx |= RF_FRAMELERP;

   KillBox( this );

   // setup the orientation
	setAngles( angles );
   v_angle = angles;

	// set the delta angle
	client->ps.delta_angles[0] = ANGLE2SHORT( angles.x - client->resp.cmd_angles[0] );
	client->ps.delta_angles[1] = ANGLE2SHORT( angles.y - client->resp.cmd_angles[1] );
	client->ps.delta_angles[2] = ANGLE2SHORT( angles.z - client->resp.cmd_angles[2] );

   if ( deathmatch->integer || coop->integer )
      {
      SpawnTeleportEffect( origin, 124 );
      }
   }

Player::~Player()
	{
	edict->s.modelindex = 0;
	}

void Player::EndLevel
   (
   Event *ev
   )

   {
   InitPowerups();
   if ( health > max_health )
      {
      health = max_health;
      }

   if ( health < 1 )
      {
      health = 1;
      }
   }

void Player::Respawn
	(
	Event *ev
	)

	{
   if ( deathmatch->integer || coop->integer )
		{
      assert ( deadflag == DEAD_DEAD );

		if ( !gibbed )
         {
         CopyToBodyQueue( edict );
         }

		respawn_time = level.time;

      Init();

		// hold in place briefly
		client->ps.pm_time = 50;
      client->ps.pm_flags = PMF_TIME_TELEPORT;

		return;
		}

   // force the load game menu to come up
   level.missionfailed = true;
   level.missionfailedtime = level.time - FRAMETIME;
	}

void Player::SetDeltaAngles
   (
   void
   )

   {
   int i;

   // Use v_angle since we may be in a camera
	for( i = 0; i < 3; i++ )
      {
		client->ps.delta_angles[ i ] = ANGLE2SHORT( v_angle[ i ] );
      }
   }

void Player::Obituary
	(
	Entity *attacker,
   Entity *inflictor,
   str location,
   int meansofdeath
	)

	{
   if ( !deathmatch->integer )
      {
      return;
      }
	}

void Player::Dead
   (
   Event *ev
   )

   {
   deadflag = DEAD_DEAD;

   // stop animating
   SetFrame( 0 );

   //
   // drop anything that might be attached to us
   //
   if ( numchildren )
      {
      Entity * child;
      int i;
      //
      // detach all our children
      //
      for ( i=0; i < MAX_MODEL_CHILDREN; i++ )
         {
         if ( children[ i ] )
            {
            child = ( Entity * )G_GetEntity( children[ i ] );
            child->ProcessEvent( EV_Detach );
            }
         }
      }
   }

void Player::Killed
	(
	Event *ev
	)

	{
	Entity   *attacker;
   Entity   *inflictor;
   str      location;
   int      meansofdeath;

	attacker       = ev->GetEntity( 1 );
	inflictor      = ev->GetEntity( 3 );
   location       = ev->GetString( 4 );
	meansofdeath   = ev->GetInteger( 5 );

   Obituary( attacker, inflictor, location, meansofdeath );

   StopAnimating( all );
   CancelPendingEvents();

	deadflag	= DEAD_DYING;

	respawn_time = level.time + 1.0;

/* TODO: Fix to drop all active weapons
   if ( currentWeapon )
      {
      DropWeapon( currentWeapon );
      }
*/
   if ( coop->integer )
      {
      DropInventoryItems();
      }

	edict->clipmask = MASK_DEADSOLID;
   edict->svflags |= SVF_DEADMONSTER;

   setMoveType( MOVETYPE_NONE );

   edict->s.renderfx &= ~RF_ENVMAPPED;

	angles.x = 0;
	angles.z = 0;
	setAngles( angles );

   RandomAnimate( "killed", EV_Player_Dead );
	animOverride = true;

   //
   // change music
   //
   ChangeMusic( "failure", "normal", true );
   }

void Player::Pain
	(
	Event *ev
	)

	{
	float		damage;
	Entity	*attacker;
   int      meansofdeath;

	damage	= ev->GetFloat( 1 );
	attacker = ev->GetEntity( 2 );
	meansofdeath = ev->GetInteger( 4 );

   if ( camera )
      {
      if ( level.cinematic )
         {
         return;
         }

      SetCamera( NULL );
      }

   // increase action level of game
   action_level += damage;

	// add to the damage inflicted on a player this frame
	// the total will be turned into screen blends and view angle kicks
	// at the end of the frame
	damage_blood += damage;

   // white flash signifying no damage was taken.
   if ( ( damage <= 0 ) && ( meansofdeath != MOD_FISTS ) )
      {
      Event *ev1;

      ProcessEvent( EV_Player_ClearFlashColor );
      ev1 = new Event( EV_Player_SetFlashColor );

      // Flash the player white
      ev1->AddFloat( 1 );
      ev1->AddFloat( 1 );
      ev1->AddFloat( 1 );
      ev1->AddFloat( 0.3 );
      ProcessEvent( ev1 );
      }

   // If damage > 5 then play a pain animation, otherwise play a pain sound
	if ( !firing && !deadflag && damage > 5 )
		{
      str aname;
      int index;

      //
      // determine pain animation
      //
      aname = str("pain_") + str( ev->GetString( 3 ) );
   	index = gi.Anim_Random( edict->s.modelindex, aname.c_str() );
      if ( index == -1 )
			{
         aname = str("pain");
			}

		TempAnim( aname.c_str(), NULL );
		}
   else
      {
		Sound( "snd_pain", qfalse );
		BroadcastSound();
      }
	}

void Player::DoUse
	(
	void
	)

	{
	int		   i;
	int		   num;
   gentity_t   *touch[ MAX_GENTITIES ];
   gentity_t   *hit;
	Event		   *ev;
	Vector	   min;
	Vector	   max;
	Vector	   offset;
	trace_t	   trace;
	Vector	   start;
	Vector	   end;
	float		   t;

   start = origin + Vector( 0, 0, viewheight );
	end	= start + Vector( orientation[ 0 ] ) * 64.0f;

	trace = G_Trace( start, vec_zero, vec_zero, end, this, MASK_SOLID, "Player::DoUse" );

	t = 64 * trace.fraction - maxs[ 0 ];
	if ( t < 0 )
		{
		t = 0;
		}

	offset = Vector( orientation[ 0 ] ) * t;

	min = start + offset + "-16 -16 -16";
	max = start + offset + "16 16 16";

   num = gi.EntitiesInBox( min.vec3(), max.vec3(), touch, MAX_GENTITIES );

	// be careful, it is possible to have an entity in this
	// list removed before we get to it (killtriggered)
	for( i = 0; i < num; i++ )
		{
		hit = touch[ i ];
		if ( !hit->inuse )
			{
			continue;
			}

		assert( hit->entity );

		ev = new Event( EV_Use );
		ev->AddEntity( this );
		hit->entity->ProcessEvent( ev );
		}

   /* TODO: Are we going to use this for multiple weapons active?
   // Force a reload on a weapon
   if ( currentWeapon )
      {
      currentWeapon->ForceReload();
      }
      */
	}

void Player::CheckButtons
	(
	void
	)

	{
	// Only process buttons if you're not dying
	if ( deadflag != DEAD_NO )
		{
		return;
		}

	if ( new_buttons & BUTTON_USE )
		{
		DoUse();
		}
	}

void Player::TouchStuff
	(
	pmove_t *pm
	)

	{
   gentity_t  *other;
	Event		*event;
	int		i;
	int		j;

	if ( getMoveType() != MOVETYPE_NOCLIP )
		{
		G_TouchTriggers( this );
		}

	// touch other objects
	for( i = 0; i < pm->numtouch; i++ )
		{
		other = &g_entities[ pm->touchents[ i ] ];

		for( j = 0; j < i ; j++ )
			{
         gentity_t *ge = &g_entities[ j ];

			if ( ge == other )
				break;
			}

		if ( j != i )
			{
			// duplicated
			continue;
			}

      // Don't bother touching the world
		if ( ( !other->entity ) || ( other->entity == world ) )
			{
			continue;
			}

		event = new Event( EV_Touch );
		event->AddEntity( this );
		other->entity->ProcessEvent( event );

		event = new Event( EV_Touch );
		event->AddEntity( other->entity );
		ProcessEvent( event );
		}
	}

void Player::EnterVehicle
	(
	Event *ev
	)

	{
	Entity *ent;

	ent = ev->GetEntity( 1 );
	if ( ent && ent->isSubclassOf( Vehicle ) )
		{
      viewheight = STAND_EYE_HEIGHT;
      levelVars.SetVariable( "player_in_vehicle", 1 );
      velocity = vec_zero;
		vehicle = ( Vehicle * )ent;
      if ( vehicle->IsDrivable() )
   		setMoveType( MOVETYPE_VEHICLE );
      else
   		setMoveType( MOVETYPE_NOCLIP );
      if ( ev->NumArgs() > 1 )
         vehicleanim = ev->GetString( 2 );
      else
         vehicleanim = "drive";
		}
	}

void Player::ExitVehicle
	(
	Event *ev
	)

	{
   levelVars.SetVariable( "player_in_vehicle", 0 );
	setMoveType( MOVETYPE_WALK );
	vehicle = NULL;
	}

void Player::GetMoveInfo
	(
	pmove_t *pm
	)

	{
	if ( !deadflag )
		{
		v_angle[ 0 ] = pm->ps->viewangles[ 0 ];
		v_angle[ 1 ] = pm->ps->viewangles[ 1 ];
		v_angle[ 2 ] = pm->ps->viewangles[ 2 ];

      // Hardcoded for demo
      if ( camera )
         {
         v_angle[ PITCH ] = 0;
         }

		AnglesToMat( v_angle.vec3(), orientation );
		}

	setOrigin( Vector( pm->ps->origin[ 0 ], pm->ps->origin[ 1 ], pm->ps->origin[ 2 ] ) );
	velocity = Vector( pm->ps->velocity[ 0 ], pm->ps->velocity[ 1 ], pm->ps->velocity[ 2 ] );

   if ( ( client->ps.pm_type == PM_FREEZE ) || ( client->ps.pm_type == PM_INVEHICLE ) )
      {
      velocity = vec_zero;
      }

	setSize( pm->mins, pm->maxs );

	gunoffset	= Vector( 0, 0, pm->ps->viewheight );
	viewheight	= pm->ps->viewheight;

   // Set the ground entity
   groundentity = NULL;
   if ( pm->ps->groundEntityNum >= 0 )
      {
      groundentity = &g_entities[ pm->ps->groundEntityNum ];
      }
	}

void Player::SetMoveInfo
	(
	pmove_t *pm,
	usercmd_t *ucmd
	)

	{
   Vector move;

   // set up for pmove
	memset( pm, 0, sizeof( pmove_t ) );

   velocity.copyTo( client->ps.velocity );

	pm->ps             = &client->ps;
	pm->cmd            = *ucmd;
	pm->tracemask      = MASK_PLAYERSOLID;
	pm->trace          = gi.trace;
	pm->pointcontents  = gi.pointcontents;

   pm->ps->origin[ 0 ] = origin.x;
   pm->ps->origin[ 1 ] = origin.y;
   pm->ps->origin[ 2 ] = origin.z;

	pm->ps->velocity[ 0 ] = velocity.x;
	pm->ps->velocity[ 1 ] = velocity.y;
	pm->ps->velocity[ 2 ] = velocity.z;
	}

pmtype_t Player::GetMovePlayerMoveType
	(
	void
	)

	{
	if ( level.playerfrozen )
		{
		return PM_FREEZE;
		}
	else if ( camera )
		{
		return PM_INTERMISSION;
		}
	else if ( vehicle )
		{
      return PM_INVEHICLE;
   	}
	else if ( getMoveType() == MOVETYPE_NOCLIP )
		{
		return PM_SPECTATOR;
		}
	else if ( deadflag )
		{
		return PM_DEAD;
		}
   else if ( currentState->getMoveType() == MOVECONTROL_ANIM )
      {
      return PM_FOLLOW;
      }
   else
		{
		return PM_NORMAL;
		}
	}

void Player::CheckGround
   (
   void
   )

   {
	Vector  point;

   point = origin;
   point.z -= 2 * COORDINATE_TO_FLOAT;

	groundTrace = G_Trace( origin, mins, maxs, point, this, MASK_PLAYERSOLID, "Player::CheckGround" );

	// do something corrective if the trace starts in a solid...
	if ( groundTrace.allsolid )
      {
		//FIXME
      // add corrective movement
		return;
	   }

	// if the trace didn't hit anything, we are in free fall
	if ( groundTrace.fraction == 1.0 )
      {
		groundEntityNum = -1;
		groundPlane = false;
		walking = false;

		return;
	   }

	// slopes that are too steep will not be considered onground
	if ( groundTrace.plane.normal[2] < MIN_WALK_NORMAL ) 
      {
		// FIXME: if they can't slide down the slope, let them
		// walk (sharp crevices)
		groundEntityNum = -1;
		groundPlane = true;
		walking = false;
		return;
	   }

	// check if getting thrown off the ground
	if ( ( velocity[ 2 ] > 0 ) && ( ( velocity * groundTrace.plane.normal ) > 10 ) )
      {
		groundEntityNum = -1;
		groundPlane = false;
		walking = false;
		return;
	   }
	
	groundPlane = true;
	walking = true;

	if ( groundEntityNum == -1 )
      {
		// just hit the ground
      //FIXME
      //add landing code here if necessary
		//PM_CrashLand();
		}

	velocity[ 2 ] = 0;
	groundEntityNum = groundTrace.entityNum;
	//AddTouchEnt( groundEntityNum );
   }

void Player::ClipVelocity
   (
   Vector &in,
   Vector &normal,
   Vector &out
   )

   {
   const float OVERCLIP	= 1.0001;
	float	   backoff;
	float	   change;
	int		i;
	
	backoff = in * normal;
	if ( backoff < 0 )
      {
		backoff *= OVERCLIP;
	   }
   else
      {
		backoff *= 1 / OVERCLIP;
	   }

	for ( i = 0; i < 3; i++ ) 
      {
		change = normal[ i ] * backoff;
		out[ i ] = in[ i ] - change;
	   }
   }

#define	MAX_CLIP_PLANES	5

bool Player::SlideMove
   (
   void
   )

   {
	int		bumpcount;
   int      numbumps;
	Vector   dir;
	float		d;
   float    rub;
	int		numplanes;
	vec3_t   planes[ MAX_CLIP_PLANES ];
	Vector   primal_velocity;
	Vector   clipVelocity;
	int		i, j, k;
	trace_t	trace;
	Vector   end;
	float		time_left;
	float		into;
   float	   startDist;
   float    endDist;
	
	numbumps = 4;

	primal_velocity = velocity;
	time_left = FRAMETIME;

	// never turn against the ground plane
	if ( groundPlane )
      {
		numplanes = 1;
		VectorCopy( groundTrace.plane.normal, planes[ 0 ] );
	   }
   else 
      {
		numplanes = 0;
	   }

   startDist = ( origin * groundTrace.plane.normal ) - groundTrace.plane.dist;

	// never turn against original velocity
	VectorNormalize2( velocity.vec3(), planes[ numplanes ] );
	numplanes++;

   for ( bumpcount = 0; bumpcount < numbumps; bumpcount++ )
      {
		// calculate position we are trying to move to
      end = origin + velocity * time_left;

		// see if we can make it there
		trace = G_Trace( origin, mins, maxs, end, this, MASK_PLAYERSOLID, "Player::SlideMove" );
		if ( trace.allsolid )
         {
			// entity is completely trapped in another solid
         // don't build up falling damage, but allow sideways acceleration
			velocity[ 2 ] = 0;
			return true;
		   }

		if ( trace.fraction > 0 )
         {
			// actually covered some distance
			origin = trace.endpos;
		   }

		if ( trace.fraction == 1 )
         {
         // moved the entire distance
			break;
		   }

		// save entity for contact
		//AddTouchEnt( trace.entityNum );
		
		time_left -= time_left * trace.fraction;

		if ( numplanes >= MAX_CLIP_PLANES )
         {
			// this shouldn't really happen
			velocity = vec_zero;
			return true;
		   }

		//
		// modify velocity so it parallels all of the clip planes
		//
		VectorCopy( trace.plane.normal, planes[ numplanes ] );
		numplanes++;

		// find a plane that it enters
		for ( i = 0 ; i < numplanes ; i++ )
         {
			into = velocity * planes[ i ];
			if ( into >= 0.1 )
            {
            // move doesn't interact with the plane
				continue;
			   }

			// slide along the plane
			ClipVelocity( velocity, Vector( planes[ i ] ), clipVelocity );

			// rub some extra speed off on xy axis
			// not on Z, or you can scrub down walls
			VectorNormalize2( velocity.vec3(), dir.vec3() );
			rub = 1.0 + 0.5 * DotProduct( dir, planes[ i ] );
			clipVelocity[ 0 ] *= rub;
			clipVelocity[ 1 ] *= rub;

			// see if there is a second plane that the new move enters
			for ( j = 0 ; j < numplanes ; j++ )
            {
				if ( j == i )
               {
					continue;
				   }

				if ( DotProduct( clipVelocity, planes[j] ) >= 0.1 )
               {
               // move doesn't interact with the plane
					continue;
				   }

				// try clipping the move to the plane
				ClipVelocity( clipVelocity, Vector( planes[ j ] ), clipVelocity );

				// see if it goes back into the first clip plane
				if ( DotProduct( clipVelocity, planes[ i ] ) >= 0 )
               {
					continue;
				   }

				// slide the original velocity along the crease
				CrossProduct( planes[ i ], planes[ j ], dir.vec3() );
				dir.normalize();
				d = velocity * dir;
				clipVelocity = dir * d;

				// rub some extra speed off
				VectorNormalize2( velocity.vec3(), dir.vec3() );
				rub = 1.0 + 0.5 * DotProduct( dir, planes[ j ]);
            clipVelocity *= rub;

				// see if there is a third plane the the new move enters
				for ( k = 0 ; k < numplanes ; k++ )
               {
					if ( k == i || k == j )
                  {
						continue;
					   }

					if ( ( clipVelocity * planes[ k ] ) >= 0.1 )
                  {
                  // move doesn't interact with the plane
						continue;
					   }

					// stop dead at a tripple plane interaction
					velocity = vec_zero;
					return true;
				   }
			   }

			// if we have fixed all interactions, try another move
			velocity = clipVelocity;
			break;
		   }
	   }

	velocity = primal_velocity;
   endDist = ( origin * groundTrace.plane.normal ) - groundTrace.plane.dist;

	return ( bumpcount != 0 );
   }

void Player::StepSlideMove
   (
   void
   )
   
   {
	Vector  start_o;
   Vector  start_v;
	Vector  down_o;
   Vector  down_v;
	trace_t trace;
	Vector  up;
   Vector  down;

	start_o = origin;
	start_v = velocity;

	if ( !SlideMove() )
      {
      // we got exactly where we wanted to go first try	
		return;
	   }

	down_o = origin;
   velocity = down_v;

	up = start_o;
	up[ 2 ] += STEPSIZE;

	// test the player position if they were a stepheight higher
	trace = G_Trace( up, mins, maxs, up, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
	if ( trace.allsolid )
      {
      // can't step up
		return;
	   }

	// try slidemove from this position
	origin = up;
	velocity = start_v;

	SlideMove();

	// push down the final amount
	down = origin;
	down[ 2 ] -= STEPSIZE;

	trace = G_Trace( origin, mins, maxs, down, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
	if ( !trace.allsolid )
      {
		origin = trace.endpos;
	   }

	if ( trace.fraction < 1.0 )
      {
		ClipVelocity( velocity, Vector( trace.plane.normal ), velocity );
	   }

	// if the down trace can trace back to the original position directly, don't step
	trace = G_Trace( origin, mins, maxs, start_o, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
	if ( trace.fraction == 1.0 )
      {
		// use the original move
		origin = down_o;
		velocity = down_v;
	   }
   else
      {
      //FIXME
		// use the step move
      // allow client to smooth out the step
		//stepped = true;
		}
   }

void Player::WalkMove
   (
	usercmd_t *ucmd
   )
   
   {
//   PM_Friction ();
   if ( walking )
      {
      velocity[ 2 ] = 0;
      }
   else
      {
      velocity[ 2 ] -= sv_gravity->value * gravity * FRAMETIME;
      }

	// slide along the ground plane
	ClipVelocity ( velocity, Vector( groundTrace.plane.normal ), velocity );

	// don't do anything if standing still
	if ( !velocity[ 0 ] && !velocity[ 1 ] )
      {
		return;
	   }

	StepSlideMove();
   }

void Player::AnimMove
   (
   Vector move
   )

   {
	Vector  start;
   Vector  end;
	Vector  up;
   Vector  down;
	trace_t trace;

	start = origin;
	end = origin + move;

	// test the player position if they were a stepheight higher
	trace = G_Trace( start, mins, maxs, end, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
   origin = trace.endpos;

   if ( trace.fraction < 1 )
      {
      up = origin;
	   up[ 2 ] += STEPSIZE;

	   // test the player position if they were a stepheight higher
	   trace = G_Trace( origin, mins, maxs, up, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
	   if ( trace.fraction < 1 )
         {
         // can't step up
		   return;
	      }

	   // try slidemove from this position
	   origin = trace.endpos;
      up = end;
      up[ 2 ] = origin[ 2 ];

	   // test the player position if they were a stepheight higher
	   trace = G_Trace( origin, mins, maxs, up, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
   	origin = trace.endpos;
      }

   // push down the final amount
   down = origin;
   if ( walking )
      {
	   down[ 2 ] -= STEPSIZE;
      }

	trace = G_Trace( origin, mins, maxs, down, this, MASK_PLAYERSOLID, "Player::StepSlideMove" );
	if ( !trace.allsolid )
      {
		origin = trace.endpos;
	   }
   }

void Player::UpdateViewAngles
   (
   usercmd_t *cmd
   )
   
   {
	short	temp;
	int	i;
   Vector oang;

	if ( GetMovePlayerMoveType() == PM_INTERMISSION )
      {
      // no view changes at all
		return;
	   }

	if ( health <= 0 )
      {
      // no view changes at all
		return;
	   }

	// circularly clamp the angles with deltas
	for( i = 0; i < 3; i++ )
      {
		temp = cmd->angles[ i ] + client->ps.delta_angles[ i ];
		if ( i == PITCH )
         {
			// don't let the player look up or down more than 90 degrees
			if ( temp > 16000 )
            {
				client->ps.delta_angles[ i ] = 16000 - cmd->angles[ i ];
				temp = 16000;
			   }
         else if ( temp < -16000 )
            {
				client->ps.delta_angles[ i ] = -16000 - cmd->angles[ i ];
				temp = -16000;
			   }
		   }

		client->ps.viewangles[ i ] = SHORT2ANGLE( temp );
	   }

	v_angle[ 0 ] = client->ps.viewangles[ 0 ];
	v_angle[ 1 ] = client->ps.viewangles[ 1 ];
	v_angle[ 2 ] = client->ps.viewangles[ 2 ];

   // Hardcoded for demo
   if ( camera )
      {
      v_angle[ PITCH ] = 0;
      }

   oang = v_angle;
   oang[ PITCH ] = 0;
	AnglesToMat( oang.vec3(), orientation );
   }
#if 0
/*
==================
CG_SwingAngles
==================
*/
void CG_SwingAngles( float destination, float swingTolerance, float clampTolerance,
					float speed, float *angle, qboolean *swinging ) {
	float	swing;
	float	move;
	float	scale;

	if ( !*swinging ) {
		// see if a swing should be started
		swing = AngleSubtract( *angle, destination );
		if ( swing > swingTolerance || swing < -swingTolerance ) {
			*swinging = qtrue;
		}
	}

	if ( !*swinging ) {
		return;
	}

	// modify the speed depending on the delta
	// so it doesn't seem so linear
	swing = AngleSubtract( destination, *angle );
	scale = fabs( swing );
	if ( scale < swingTolerance * 0.5 ) {
		scale = 0.5;
	} else if ( scale < swingTolerance ) {
		scale = 1.0;
	} else {
		scale = 2.0;
	}

	// swing towards the destination angle
	if ( swing >= 0 ) {
		move = cg.frametime * scale * speed;
		if ( move >= swing ) {
			move = swing;
			*swinging = qfalse;
		}
		*angle = AngleMod( *angle + move );
	} else if ( swing < 0 ) {
		move = cg.frametime * scale * -speed;
		if ( move <= swing ) {
			move = swing;
			*swinging = qfalse;
		}
		*angle = AngleMod( *angle + move );
	}

	// clamp to no more than tolerance
	swing = AngleSubtract( destination, *angle );
	if ( swing > clampTolerance ) {
		*angle = AngleMod( destination - (clampTolerance - 1) );
	} else if ( swing < -clampTolerance ) {
		*angle = AngleMod( destination + (clampTolerance - 1) );
	}
}

/*
===============
CG_PlayerAngles

Handles seperate torso motion

  legs face direction of movement

  head always looks exactly at cent->lerpAngles
  if torso yaw > 20 degrees

  if motion < 20 degrees, show in head only for
  if < 45 degrees
===============
*/
void Player::CalcAngles
   (
   void
   ) 

   {
   Vector   legsAngles;
   Vector   torsoAngles;
   Vector   headAngles;
	float		dest;
	vec3_t	velocity;
   float    deltayaw;
   vec3_t   moveangles;
	float		speed;

	headAngles = v_angles;
	headAngles[ YAW ] = AngleMod( headAngles[ YAW ] );

   // calculate speed
	speed = total_delta.length();
   if ( ( speed > 32 ) && ( groundEntityNum != -1 ) )
      {
      cent->am.torso.yawing = qtrue;   // always center
      cent->am.torso.pitching = qtrue; // always center
      cent->am.legs.yawing = qtrue; // always center
      vectoangles( velocity, moveangles );
      }
   else
      {
      VectorCopy( headAngles, moveangles );
      }

   deltayaw = AngleSubtract( moveangles[ YAW ], headAngles[ YAW ] );

	// --------- yaw -------------
   if ( fabs( deltayaw ) <= 100 )
      {
	   legsAngles[YAW] = headAngles[YAW] + deltayaw;
   	torsoAngles[YAW] = headAngles[YAW] + 0.25 * deltayaw;
      }
   else
      {
      deltayaw = AngleSubtract( deltayaw, -180 );
	   legsAngles[YAW] = headAngles[YAW] + deltayaw;
   	torsoAngles[YAW] = headAngles[YAW] + 0.25 * deltayaw;
      }

	// torso
	CG_SwingAngles( torsoAngles[YAW], 25, 90, cg_swingSpeed->value, &cent->am.torso.yawAngle, &cent->am.torso.yawing );
	CG_SwingAngles( legsAngles[YAW], 40, 90, cg_swingSpeed->value, &cent->am.legs.yawAngle, &cent->am.legs.yawing );

	torsoAngles[YAW] = cent->am.torso.yawAngle;
	legsAngles[YAW] = cent->am.legs.yawAngle;

	// --------- pitch -------------

	// only show a fraction of the pitch angle in the torso
	if ( headAngles[PITCH] > 180 ) 
      {
		dest = (-360 + headAngles[PITCH]) * 0.75;
	   } 
   else 
      {
		dest = headAngles[PITCH] * 0.75;
	   }
	CG_SwingAngles( dest, 15, 30, 0.1, &cent->am.torso.pitchAngle, &cent->am.torso.pitching );
	torsoAngles[PITCH] = cent->am.torso.pitchAngle;

	// pull the angles back out of the hierarchial chain
	AnglesSubtract( headAngles, torsoAngles, headAngles );
	AnglesSubtract( torsoAngles, legsAngles, torsoAngles );
   VectorCopy( headAngles, hAngles );
   VectorCopy( legsAngles, lAngles );
   VectorCopy( torsoAngles, tAngles );
   }

#endif
void Player::ClientMove
	(
	usercmd_t *ucmd
	)

	{
   pmove_t pm;
   static Vector last;
   Vector move;

	client->ps.pm_type = GetMovePlayerMoveType();
   client->ps.speed = 200; // GAMEFIX
	client->ps.gravity = sv_gravity->value * gravity;

   SetMoveInfo( &pm, ucmd );
   Pmove( &pm );
   GetMoveInfo( &pm );
   if ( ( getMoveType() == MOVETYPE_NOCLIP ) || ( client->ps.pm_type == PM_NORMAL ) )
      {
      total_delta = vec_zero;
      }
   else
      {
      //UpdateViewAngles( ucmd );
      Vector oang = v_angle;
      oang[ PITCH ] = 0;
	   AnglesToMat( oang.vec3(), orientation );

      CheckGround();
      WalkMove( ucmd );
      if ( total_delta != vec_zero )
		   {
		   MatrixTransformVector( total_delta.vec3(), orientation, move.vec3() );
         AnimMove( move );
		   }
      }

   CheckGround();

	total_delta = vec_zero;

   TouchStuff( &pm );
	if ( !level.playerfrozen )
      {
	   CheckButtons();
      }

   if ( ( whereami->integer ) && ( origin != last ) )
      {
      last = origin;
      gi.DPrintf( "x %8.2f y%8.2f z %8.2f area %2d\n", origin[ 0 ], origin[ 1 ], origin[ 2 ], edict->areanum );
      }
	}

/*
==============
ClientThink

This will be called once for each client frame, which will
usually be a couple times for each server frame.
==============
*/
void Player::ClientThink
	(
	Event *ev
	)

	{
   if ( !Director.PlayerReady() )
      {
      // let any threads waiting on us know they can go ahead
      Director.PlayerSpawned();
      }

   last_ucmd   = *current_ucmd;
	new_buttons	= current_ucmd->buttons & ~buttons;
	buttons		= current_ucmd->buttons;

	if ( level.intermissiontime )
		{
		client->ps.pm_type = PM_FREEZE;

		// can exit intermission after five seconds
		if ( level.time > level.intermissiontime + 5.0 && ( new_buttons & BUTTON_ANY ) )
			{
			level.exitintermission = true;
			}

		// Save cmd angles so that we can get delta angle movements next frame
		client->resp.cmd_angles[ 0 ] = SHORT2ANGLE( current_ucmd->angles[ 0 ] );
		client->resp.cmd_angles[ 1 ] = SHORT2ANGLE( current_ucmd->angles[ 1 ] );
		client->resp.cmd_angles[ 2 ] = SHORT2ANGLE( current_ucmd->angles[ 2 ] );

		return;
		}

	if ( !vehicle || !vehicle->Drive( current_ucmd ) )
		{
      Vector temporigin( client->ps.origin );

      ClientMove( current_ucmd );
      if ( camera )
         {
         // we save off the origin so that camera's origins are not messed up
         temporigin.copyTo( client->ps.origin );
         }
		}
	else
		{
      CheckWater();
      if ( !level.playerfrozen )
         {
		   CheckButtons();
         }
		}

	// If we're dying, check for respawn
   if ( ( deadflag == DEAD_DEAD && ( level.time > respawn_time ) ) )
		{
		// wait for any button just going down
      if ( new_buttons || ( DM_FLAG( DF_FORCE_RESPAWN ) ) )
         {
         ProcessEvent( EV_Player_Respawn );
			}
		}

   //
   // check to see if we want to get out of a cinematic
   //
   if ( level.cinematic && ( world->skipthread.length() > 1 ) &&
      ( buttons & ( BUTTON_ATTACKLEFT | BUTTON_ATTACKRIGHT | BUTTON_USE ) ) )
      {
      ExecuteThread( world->skipthread );
      }

	// Save cmd angles so that we can get delta angle movements next frame
	client->resp.cmd_angles[ 0 ] = SHORT2ANGLE( current_ucmd->angles[ 0 ] );
	client->resp.cmd_angles[ 1 ] = SHORT2ANGLE( current_ucmd->angles[ 1 ] );
	client->resp.cmd_angles[ 2 ] = SHORT2ANGLE( current_ucmd->angles[ 2 ] );
	}

void Player::LoadStateTable
   (
   void
   )

   {
   delete statemap;
   statemap = new StateMap( "global/testjulie.st" );

   laststate = NULL;
   currentState = statemap->FindState( "STAND" );
   }

void Player::ResetState
   (
   Event *ev
   )

   {
   LoadStateTable();
   }

void Player::EventUseItem
	(
	Event *ev
	)

	{
	const char  *name;
   int         number=WEAPON_RIGHT;

	if ( deadflag )
      {
		return;
      }

	name = ev->GetString( 1 );

   if ( ev->NumArgs() > 1 )
      number = ev->GetInteger( 2 );

 	useWeapon( name, number );
   }

void Player::EventUseInventoryItem
	(
	Event *ev
	)

	{
	if ( deadflag )
      {
		return;
      }

   if ( !currentItem )
      {
      return;
      }

   currentItem->ProcessEvent( EV_InventoryItem_Use );
   }

void Player::ActivateNewWeapon
   (
   Event *ev
   )

   {
   // Change the weapon to the currently active weapon as specified by useWeapon
   ChangeWeapon( newActiveWeapon.weapon, newActiveWeapon.number );   
   
   // Clear out the newActiveWeapon
   newActiveWeapon.weapon = NULL;
   newActiveWeapon.number = -1;
   }

void Player::DeactivateWeapon
   (
   Event *ev
   )

   {
   // Deactivate the weapon
   int number = ev->GetInteger( 1 );

   Sentient::DeactivateWeapon( number );
   }

void Player::useWeapon
	(
	const char  *weaponname,
   int         number
	)

	{
   if ( vehicle && vehicle->HasWeapon() )
      {
      return;
      }
   else
      {
      // Check to see if we are already in the process of using a new weapon.
      if ( newActiveWeapon.weapon )
         {
         return;
         }

   	Weapon *weapon = ( Weapon * )FindItem( weaponname );

      // Check to see if player has the weapon
      if ( !weapon )
         return;

      activeWeapon = GetActiveWeapon( number );

      // Check to see if this weapon is already being used in this slot
      if ( activeWeapon == weapon )
         {
         // No need to re-use a weapon that is already active
         warning( "Player::useWeapon", "Weapon %s already being used in slot %d", weaponname, number );
         return;
         }      
         
      // Check to see if there is a weapon that is already in that spot
      if ( activeWeapon )
         {
         // Set the putaway flag to true.  The state machine will then play the correct animation to put away the active weapon
         activeWeapon->PutAway();
         }
      else if ( IsActiveWeapon( weapon ) )  // Check to see if this weapon is being used in a different slot. 
         {
         weapon->PutAway();
         }

      // Set the attach tag appropriately in the weapon
      if ( number == WEAPON_RIGHT )
         weapon->SetAttachTag( "tag_weapon" );
      else if ( number == WEAPON_LEFT )
         weapon->SetAttachTag( "tag_weapon_left" );

      // Set the newActiveWeapon as the weapon specified, the state machine will play the appropriate animation and
      // trigger when to attach it to the player's model.
	   newActiveWeapon.weapon = weapon;
      newActiveWeapon.number = number;
      }
   }

void Player::Take
	(
	Event *ev
	)

	{
   /* TODO: Rewrite this function

	const char *name;

	if ( deadflag )
		{
		return;
		}

	name = ev->GetString( 1 );
	if ( !stricmp( name, "all" ) )
		{
      if ( currentWeapon )
         {
         currentWeapon->DetachFromOwner();
         }

      SetCurrentWeapon( NULL );
      FreeInventoryOfType( "Weapon" );
      }
   else if ( checkInheritance( &Weapon::ClassInfo, name ) )
		{
		takeWeapon( name );
		}
   else if ( checkInheritance( &Ammo::ClassInfo, name ) )
		{
		EventTakeAmmo( ev );
		}
   else if ( checkInheritance( &Item::ClassInfo, name ) )
		{
      EventTakeItem( ev );
		}
	else
		{
      gi.SendServerCommand( edict, "print \"Unknown take object : %s\n", name );
		}
   */
	}

void Player::GiveCheat
	(
	Event *ev
	)

	{
	const char *name;

	if ( deadflag )
		{
		return;
		}

	name = ev->GetString( 1 );
   if ( checkInheritance( &Weapon::ClassInfo, name ) )
		{
		giveWeapon( name );
		}
   else if ( checkInheritance( &Ammo::ClassInfo, name ) )
		{
		EventGiveAmmo( ev );
		}
  	else if ( checkInheritance( &InventoryItem::ClassInfo, name ) )
		{
      if ( ev->NumArgs() != 2 )
         {
         gi.SendServerCommand( edict, "print \"Usage: give <inventory item name> <amount>\n\"" );
         return;
         }
		EventGiveInventoryItem( ev );
		}
   else if ( checkInheritance( &Item::ClassInfo, name ) )
      {
      EventGiveItem( ev );
      }
	}

void Player::GiveAllCheat
	(
	Event *ev
	)

	{
	if ( deadflag )
		{
		return;
		}

   //FIXME
   // Add FAKK weapons here
	}

void Player::GodCheat
	(
	Event *ev
	)

	{
	const char *msg;

   if ( ev->NumArgs() > 0 )
      {
      if ( ev->GetInteger( 1 ) )
         {
         flags |= FL_GODMODE;
         }
      else
         {
         flags &= ~FL_GODMODE;
         }
      }
   else
      {
   	flags ^= FL_GODMODE;
      }

   if ( ev->GetSource() == EV_FROM_CONSOLE )
      {
	   if ( !( flags & FL_GODMODE ) )
		   {
		   msg = "godmode OFF\n";
		   }
	   else
		   {
		   msg = "godmode ON\n";
		   }

      gi.SendServerCommand( edict, "print \"%s\"", msg );
      }
	}

void Player::Kill
	(
	Event *ev
	)

	{
	if ( ( level.time - respawn_time ) < 5 )
		{
		return;
		}

	flags &= ~FL_GODMODE;
	health = 0;
   Damage( this, this, 10, origin, vec_zero, vec_zero, 0, DAMAGE_NO_PROTECTION, MOD_SUICIDE, -1, -1, 1.0f );
	}

void Player::NoTargetCheat
	(
	Event *ev
	)

	{
	const char *msg;

	flags ^= FL_NOTARGET;
	if ( !( flags & FL_NOTARGET ) )
		{
		msg = "notarget OFF\n";
		}
	else
		{
		msg = "notarget ON\n";
		}

   gi.SendServerCommand( edict, "print \"%s\"", msg );
	}

void Player::NoclipCheat
	(
	Event *ev
	)

	{
	const char *msg;

	if ( vehicle )
		{
		msg = "Must exit vehicle first\n";
		}
	else if ( getMoveType() == MOVETYPE_NOCLIP )
		{
		setMoveType( MOVETYPE_WALK );
		msg = "noclip OFF\n";
		}
	else
		{
		setMoveType( MOVETYPE_NOCLIP );
		msg = "noclip ON\n";
		}

   gi.SendServerCommand( edict, "print \"%s\"", msg );
	}

void Player::SpawnEntity
	(
	Event *ev
	)

	{
	Animate		*ent;
   str         name;
	ClassDef		*cls;
   str         text;
   Vector		forward;
	Vector		right;
	Vector		up;
   Vector		delta;
	Vector		v;
	int			n;
	int			i;
   Event       *e;

   if ( ev->NumArgs() < 1 )
		{
		ev->Error( "Usage: spawn entityname [keyname] [value]..." );
		return;
		}

   name = ev->GetString( 1 );
   if ( !name.length() )
		{
		ev->Error( "Must specify an entity name" );
		return;
		}

   // create a new entity
	G_InitSpawnArguments();

   G_SetSpawnArg( "classname", name.c_str() );
   G_SetSpawnArg( "model", name.c_str() );

   cls = G_GetClassFromArgs();
   if ( !cls )
      {
      cls = &Entity::ClassInfo;
      }

   ent = ( Animate * )cls->newInstance();

   e = new Event( EV_Model );
   e->AddString( name.c_str() );
   ent->PostEvent( e, EV_SPAWNARG );

   angles.AngleVectors( &forward, &right, &up );
   v = origin + ( forward + up ) * 40;

   e = new Event( EV_SetOrigin );
   e->AddVector( v );
   ent->PostEvent( e, EV_SPAWNARG );

   delta = origin - v;
	v = delta.toAngles();

   e = new Event( "angle" );
   e->AddFloat( v[ 1 ] );
   ent->PostEvent( e, EV_SPAWNARG );

   if ( ev->NumArgs() > 2 )
		{
		n = ev->NumArgs();
		for( i = 2; i <= n; i += 2 )
			{
         e = new Event( ev->GetString( i ) );
         e->AddToken( ev->GetString( i + 1 ) );
         ent->PostEvent( e, EV_SPAWNARG );
			}
		}
   e = new Event( EV_Anim );
   e->AddString( "idle" );
   ent->PostEvent( e, EV_SPAWNARG );

	G_InitSpawnArguments();
   }

void Player::SpawnActor
	(
	Event *ev
	)

	{
	Entity   *ent;
   str      name;
   str      text;
   Vector	forward;
	Vector	right;
	Vector	up;
   Vector	delta;
	Vector	v;
	int		n;
	int		i;
	ClassDef	*cls;
   Event    *e;

   if ( ev->NumArgs() < 1 )
		{
		ev->Error( "Usage: actor [modelname] [keyname] [value]..." );
		return;
		}

   name = ev->GetString( 1 );
   if ( !name[ 0 ] )
		{
		ev->Error( "Must specify a model name" );
		return;
		}

   if ( !strstr( name.c_str(), ".tik" ) )
      {
      name += ".tik";
      }

   // create a new entity
	G_InitSpawnArguments();

   G_SetSpawnArg( "model", name.c_str() );
   cls = G_GetClassFromArgs();
   if ( !cls || cls == &Object::ClassInfo )
      {
      cls = &Actor::ClassInfo;
      }

   ent = ( Entity * )cls->newInstance();
   e = new Event( EV_Model );
   e->AddString( name.c_str() );
   ent->PostEvent( e, EV_SPAWNARG );

   angles.AngleVectors( &forward, &right, &up );
   v = origin + ( forward + up ) * 40;

   e = new Event( EV_SetOrigin );
   e->AddVector( v );
   ent->PostEvent( e, EV_SPAWNARG );

   delta = origin - v;
	v = delta.toAngles();

   e = new Event( "angle" );
   e->AddFloat( v[ 1 ] );
   ent->PostEvent( e, EV_SPAWNARG );

   if ( ev->NumArgs() > 2 )
		{
		n = ev->NumArgs();
		for( i = 2; i <= n; i += 2 )
			{
         e = new Event( ev->GetString( i ) );
         e->AddToken( ev->GetString( i + 1 ) );
         ent->PostEvent( e, EV_SPAWNARG );
			}
		}

	G_InitSpawnArguments();
   }

void Player::EventPreviousWeapon
	(
	Event *ev
	)

	{
   /* TODO: Determine if this is needed 
	if ( deadflag )
		{
		return;
		}

   if ( vehicle && vehicle->HasWeapon() )
      {
      return;
      }

	// Cycle backwards through weapons
	if ( currentWeapon && currentWeapon->AttackDone() && !currentWeapon->ChangingWeapons() )
		{
		ChangeWeapon( PreviousWeapon( currentWeapon ) );
		}
   */
	}

void Player::EventNextWeapon
	(
	Event *ev
	)

	{
	/* Determine if this is needed
   if ( deadflag )
		{
		return;
		}

   if ( vehicle && vehicle->HasWeapon() )
      {
      return;
      }

	// Cycle forwards through weapons
	if ( currentWeapon && currentWeapon->AttackDone() && !currentWeapon->ChangingWeapons() )
		{
		ChangeWeapon( NextWeapon( currentWeapon ) );
		}
   */
	}

void Player::EventNextItem
   (
   Event *ev
   )

   {
   Item *nextItem;

   if ( deadflag )
      {
      return;
      }

   nextItem = NextItem( currentItem );
   if ( nextItem )
      {
      currentItem = ( InventoryItem * )nextItem;
      }
   }

void Player::EventPreviousItem
   (
   Event *ev
   )

   {
   Item *prevItem;

   if ( deadflag )
      {
      return;
      }

   prevItem = PrevItem( currentItem );

   if ( prevItem )
      {
      currentItem = ( InventoryItem * )prevItem;
      }
   }

void Player::GameVersion
	(
	Event *ev
	)

	{
   gi.SendServerCommand( edict, "print \"%s : %s\n\"", GAMEVERSION, __DATE__ );
	}

void Player::Fov
	(
	Event *ev
	)

	{
   if ( ev->NumArgs() < 1 )
		{
      gi.SendServerCommand( edict, "print \"Fov = %d\n\"", fov );
		return;
		}

	fov = ev->GetFloat( 1 );

   if ( ( fov < 90 ) && DM_FLAG( DF_FIXED_FOV ) )
      {
      fov = 90;
      return;
      }

   if ( fov < 1 )
      {
      fov = 90;
      }
   else if ( fov > 160 )
      {
      fov = 160;
      }
	}

/*
===============
CalcRoll

===============
*/
float Player::CalcRoll
	(
	void
	)

	{
	float	sign;
	float	side;
	float	value;
	Vector r;

	angles.AngleVectors( NULL, &r, NULL );
	side = velocity * r;
	sign = side < 0 ? -4 : 4;
	side = fabs( side );

	value = sv_rollangle->value;

	if ( side < sv_rollspeed->value )
		{
		side = side * value / sv_rollspeed->value;
		}
	else
		{
		side = value;
		}

	return side * sign;
	}

void Player::GravityNodes
   (
   void
   )

   {
   Vector grav;
   Vector gravnorm;
   Vector velnorm;
   float  dot;
   qboolean force;

   //
   // Check for gravity pulling points
   //

   // no pull on ladders or during waterjumps
   if ( onladder || ( client->ps.pm_flags & PMF_TIME_WATERJUMP ) )
      {
      return;
      }

   grav = gravPathManager.CalculateGravityPull( *this, origin, &force );

   // Check for unfightable gravity.
   if ( force && grav != vec_zero )
      {
      velnorm = velocity;
      velnorm.normalize();

      gravnorm = grav;
      gravnorm.normalize();

      dot = gravnorm.x * velnorm.x + gravnorm.y * velnorm.y + gravnorm.z * velnorm.z;

      // This prevents the player from trying to swim upstream
      if ( dot < 0 )
         {
         float tempdot;
         Vector tempvec;

         tempdot = 0.2f - dot;
         tempvec = velocity * tempdot;
         velocity = velocity - tempvec;
         }
      }

   velocity = velocity + grav;
   }

/*
=============
CheckWater
=============
*/
void Player::CheckWater
   (
   void
   )

   {
	Vector  point;
	int	  cont;
	int	  sample1;
	int	  sample2;

   unlink();
   if ( vehicle )
      {
      vehicle->unlink();
      }

   //
   // get waterlevel, accounting for ducking
   //
	waterlevel = 0;
	watertype = 0;

	sample2 = viewheight - mins[ 2 ];
	sample1 = sample2 / 2;

   point[ 0 ] = origin[ 0 ];
   point[ 1 ] = origin[ 1 ];
   point[ 2 ] = origin[ 2 ] + mins[ 2 ] + 1;
	cont = gi.pointcontents( point.vec3(), 0 );

	if ( cont & MASK_WATER )
	   {
		watertype = cont;
		waterlevel = 1;

      point[ 2 ] = origin[ 2 ] + mins[ 2 ] + sample1;
		cont = gi.pointcontents( point.vec3(), 0 );
		if ( cont & MASK_WATER )
		   {
			waterlevel = 2;
         point[ 2 ] = origin[ 2 ] + mins[ 2 ] + sample2;
			cont = gi.pointcontents( point.vec3(), 0 );
			if ( cont & MASK_WATER )
            {
				waterlevel = 3;
            }
		   }
	   }

   link();
   if ( vehicle )
      {
      vehicle->link();
      }
   }

/*
=============
WorldEffects
=============
*/
void Player::WorldEffects
	(
	void
	)

	{
	if ( movetype == MOVETYPE_NOCLIP )
		{
		// don't need air
		air_finished = level.time + 20;
		return;
		}

   //
   // Check for earthquakes
   //
   if ( groundentity && ( level.earthquake > level.time ) )
      {
      velocity[ 0 ] += G_CRandom( EARTHQUAKE_STRENGTH );
      velocity[ 1 ] += G_CRandom( EARTHQUAKE_STRENGTH );
      velocity[ 2 ] += G_Random( 150 );
      }

	//
	// if just entered a water volume, play a sound
	//
	if ( !old_waterlevel && waterlevel )
		{
		if ( watertype & CONTENTS_LAVA )
			{
			Sound( "snd_burn", qfalse, CHAN_BODY );
			BroadcastSound();
			}
      else if ( ( watertype & CONTENTS_WATER ) && waterlevel < 3)
			{
			Sound( "impact_playersplash", qtrue, CHAN_BODY );
			BroadcastSound();
			}

		flags |= FL_INWATER;
		}

	//
	// if just completely exited a water volume, play a sound
	//
	if ( old_waterlevel && !waterlevel )
		{
		Sound( "impact_playerleavewater", qtrue, CHAN_BODY );
		BroadcastSound();
		flags &= ~FL_INWATER;
		}

	//
	// check for head just going under water
	//
	if ( old_waterlevel && old_waterlevel != 3 && waterlevel == 3 )
		{
		Sound( "impact_playersubmerge", qtrue, CHAN_BODY );
		BroadcastSound();
		}

	//
	// check for head just coming out of water
	//
	if ( old_waterlevel == 3 && waterlevel != 3 )
		{
		if ( air_finished < level.time )
			{
			// gasp for air
			Sound( "snd_gasp", qfalse, CHAN_VOICE );
			}
		else if ( air_finished < level.time + 11 )
			{
			// just break surface
			Sound( "snd_gasp", qfalse, CHAN_VOICE );
			}
		}

   //
   // check for lava
   //
   if ( watertype & CONTENTS_LAVA )
      {
      if ( next_drown_time < level.time )
         {
         next_drown_time = level.time + 0.2f;
         Damage( world, world, 10 * waterlevel, origin, vec_zero, vec_zero, 0, DAMAGE_NO_ARMOR, MOD_LAVA, -1, -1, 1.0f );
         }
      }

	//
	// check for drowning
	//
	if ( waterlevel == 3 )
		{
		// if out of air, start drowning
		if ( ( air_finished < level.time ) && !( flags & FL_GODMODE ) )
			{
			// drown!
			if ( next_drown_time < level.time && health > 0 )
				{
				next_drown_time = level.time + 1;

				// take more damage the longer underwater
				drown_damage += 2;
				if ( drown_damage  > 15 )
					{
					drown_damage = 15;
					}

				// play a gurp sound instead of a normal pain sound
				if ( health <= drown_damage )
					{
					Sound( "snd_drown", qfalse, CHAN_VOICE );
					BroadcastSound();
					}
				else if ( rand() & 1 )
					{
					Sound( "snd_choke", qfalse, CHAN_VOICE );
					BroadcastSound();
					}
				else
					{
					Sound( "snd_choke", qfalse, CHAN_VOICE );
					BroadcastSound();
					}

            Damage( world, world, drown_damage, origin, vec_zero, vec_zero, 0, DAMAGE_NO_ARMOR, MOD_DROWN, -1, -1, 1.0f );
				}
			}
		}
	else
		{
		air_finished = level.time + 20;
		drown_damage = 2;
		}

   GravityNodes();

	old_waterlevel = waterlevel;
	}

/*
=============
AddBlend
=============
*/
void Player::AddBlend
	(
	float r,
	float g,
	float b,
	float a
	)

	{
	float	a2;
	float a3;

	if ( a <= 0 )
		{
		return;
		}

	// new total alpha
	a2 = blend[ 3 ] + ( 1 - blend[ 3 ] ) * a;

	// fraction of color from old
	a3 = blend[ 3 ] / a2;

	blend[ 0 ] = blend[ 0 ] * a3 + r * ( 1 - a3 );
	blend[ 1 ] = blend[ 1 ] * a3 + g * ( 1 - a3 );
	blend[ 2 ] = blend[ 2 ] * a3 + b * ( 1 - a3 );
	blend[ 3 ] = a2;
	}

/*
=============
CalcBlend
=============
*/
void Player::CalcBlend
	(
	void
	)

	{
	int		contents;
	Vector	vieworg;

	blend[ 0 ] = blend[ 1 ] = blend[ 2 ] = blend[ 3 ] = 0;

	// add for contents
   vieworg = origin;
   vieworg[ 2 ] += viewheight;

	contents = gi.pointcontents( vieworg.vec3(), 0 );

	if ( contents & CONTENTS_SOLID )
		{
		// Outside of world
		AddBlend( 0.8, 0.5, 0.0, 0.2 );
		}
	else if ( contents & CONTENTS_LAVA )
		{
		AddBlend( level.lava_color[0], level.lava_color[1], level.lava_color[2], level.lava_alpha );
		}
	else if ( contents & CONTENTS_WATER )
		{
      AddBlend( level.water_color[0], level.water_color[1], level.water_color[2], level.water_alpha );
		}

   if ( contents & CONTENTS_LIGHTVOLUME )
		{
		AddBlend( level.lightvolume_color[0], level.lightvolume_color[1], level.lightvolume_color[2], level.lightvolume_alpha );
		}

   // Flashes
   AddBlend( flash_color[0], flash_color[1], flash_color[2], flash_color[3] );

	// add for damage
	if ( damage_alpha > 0 )
		{
		AddBlend( damage_blend[ 0 ], damage_blend[ 1 ], damage_blend[ 2 ], damage_alpha );
		}

	// drop the damage value
	damage_alpha -= 0.06;
	if ( damage_alpha < 0 )
		{
		damage_alpha = 0;
		}

   // Drop the flash
   flash_color[3] -= 0.06;
   if ( flash_color[3] < 0 )
		{
		flash_color[3] = 0;
		}
	}

/*
===============
P_DamageFeedback

Handles color blends and view kicks
===============
*/

void Player::DamageFeedback
	(
	void
	)

	{
	float realcount;
	float count;

	// total points of damage shot at the player this frame
	if ( !damage_blood )
		{
		// didn't take any damage
		return;
		}

	count = damage_blood;
	realcount = count;
	if ( count < 10 )
		{
		// always make a visible effect
		count = 10;
		}

	// the total alpha of the blend is always proportional to count
	if ( damage_alpha < 0 )
		{
		damage_alpha = 0;
		}

	damage_alpha += count * 0.01;
	if ( damage_alpha < 0.2 )
		{
		damage_alpha = 0.2;
		}
	if ( damage_alpha > 0.6 )
		{
		// don't go too saturated
		damage_alpha = 0.6;
		}

	// the color of the blend will vary based on how much was absorbed
	// by different armors
	damage_blend = vec_zero;
	if ( damage_blood )
		{
		damage_blend += ( damage_blood / realcount ) * bcolor;
		}

	//
	// clear totals
	//
	damage_blood = 0;
	}

void Player::GetPlayerView
   ( 
   Vector *pos, 
   Vector *angle 
   )

   {
   if ( pos )
      {
      *pos = origin;
      pos->z += viewheight;
      }

   if ( angle )
      {
      // E3 HACK for using cameras 
      *angle = Vector( client->ps.viewangles );
      }
   }

void Player::SetPlayerView
	(
	Vector position,
	float cameraoffset,
	Vector ang,
	Vector vel,
	float camerablend[ 4 ],
	float camerafov
	)

	{
	client->ps.viewangles[ 0 ] = ang[ 0 ];
	client->ps.viewangles[ 1 ] = ang[ 1 ];
	client->ps.viewangles[ 2 ] = ang[ 2 ];

	client->ps.viewheight = cameraoffset;

	client->ps.origin[ 0 ] = position[ 0 ];
	client->ps.origin[ 1 ] = position[ 1 ];
	client->ps.origin[ 2 ] = position[ 2 ];

	client->ps.velocity[ 0 ] = vel[ 0 ];
	client->ps.velocity[ 1 ] = vel[ 1 ];
	client->ps.velocity[ 2 ] = vel[ 2 ];

	client->ps.blend[ 0 ] = camerablend[ 0 ];
	client->ps.blend[ 1 ] = camerablend[ 1 ];
	client->ps.blend[ 2 ] = camerablend[ 2 ];
	client->ps.blend[ 3 ] = camerablend[ 3 ];

	client->ps.fov = camerafov;
	}

void Player::SetupView
	(
	void
	)

	{
	// If there is no camera, use the player's view
	if ( !camera )
		{
      SetPlayerView( origin, viewheight, v_angle, velocity, blend, fov );
		}
	else
		{
		float noblend[ 4 ];

		noblend[ 0 ] = 0;
		noblend[ 1 ] = 0;
		noblend[ 2 ] = 0;
		noblend[ 3 ] = 0;

      SetPlayerView( camera->origin, 0, camera->angles, camera->velocity, noblend, camera->fov );
		}
	}

/*
=================
P_FallingDamage
=================
*/
void Player::FallingDamage
	(
	void
	)

	{
	float		delta;
	float		damage;
   csurface_t *surf;

	if ( deadflag )
		{
		return;
		}

	if ( getMoveType() == MOVETYPE_NOCLIP )
		{
		return;
		}

   if ( !fallsurface )
      {
      return;
      }

   surf = fallsurface;
   fallsurface = NULL;
	delta = velocity[ 2 ] - oldvelocity[ 2 ];
	delta = delta * delta * 0.0001;

	// never take falling damage if completely underwater
	switch( waterlevel )
		{
		case 1 :
			delta *= 0.5;
			break;

		case 2 :
			delta *= 0.25;
			break;

		case 3 :
			return;
			break;
		}

	if ( delta < 3 )
		{
		return;
		}

	if ( delta > 30 )
		{
		damage = ( delta - 30 ) / 2;

		if ( surf )
			{
			// modify damage based on surface
			switch ( surf->flags & MASK_SURF_TYPE )
				{
				// Can this happen?
				case SURF_TYPE_WATER:
					break;

				// no damage
				case SURF_TYPE_FABRIC:
					damage *= 0;
					break;

				// low damage
				case SURF_TYPE_FLESH:
				case SURF_TYPE_VEGETATION:
					damage *= 0.5;
					break;

				// medium damage
				case SURF_TYPE_DIRT:
					damage *= 0.6;
					break;

				case SURF_TYPE_WOOD:
					damage *= 0.8;
					break;

				// full damage
				case SURF_TYPE_GRAVEL:
				case SURF_TYPE_GRILL:
				case SURF_TYPE_METAL:
				case SURF_TYPE_STONE:
				case SURF_TYPE_CONCRETE:
				case SURF_TYPE_DUCT:
				default:
					break;
				}
			}

		if ( ( damage >= 1 ) && ( !DM_FLAG( DF_NO_FALLING ) ) )
			{
         Damage( world, world, ( int )damage, origin, vec_zero, vec_zero, 0, DAMAGE_NO_ARMOR, MOD_FALLING, -1, -1, 1.0f );
			}
		}
	}

void Player::FinishMove
	(
	void
	)

	{
   pmtype_t pmove;

	//
	// If the origin or velocity have changed since ClientThink(),
	// update the pmove values.  This will happen when the client
	// is pushed by a bmodel or kicked by an explosion.
	//
	// If it wasn't updated here, the view position would lag a frame
	// behind the body position when pushed -- "sinking into plats"
	//
   pmove = GetMovePlayerMoveType();
   if ( ( pmove != PM_LOCKVIEW ) && ( pmove != PM_INTERMISSION ) && ( pmove != PM_FREEZE ) )
      {
      origin.copyTo( client->ps.origin );
      velocity.copyTo( client->ps.velocity );
      }

	//
	// set model angles from view angles so other things in
	// the world can tell which direction you are looking
	//
   if ( waterlevel >= 3 )
      {
      angles[ PITCH ] = v_angle[ PITCH ];
      }
   else if ( v_angle[ PITCH ] > 180 )
	   {
		angles[ PITCH ] = ( -360 + v_angle[ PITCH ] ) / 12;
	   }
	else
		{
		angles[ PITCH ] = v_angle[ PITCH ] / 12;
		}

	angles[ YAW ] = v_angle[ YAW ];
	angles[ ROLL ] = 0;

   if ( !level.playerfrozen )
      {
	   setAngles( angles );
	   AnglesToMat( v_angle.vec3(), orientation );
      }

   // burn from lava, etc
	WorldEffects();
	FallingDamage();

	// determine the view offsets
	DamageFeedback();
	CalcBlend();

	oldvelocity = velocity;
	}

void Player::UpdateStats
	(
	void
	)

	{
   //
   // Health
   //
   if ( ( health < 1 ) && ( health > 0 ) )
      {
 	   client->ps.stats[ STAT_HEALTH ] = 1;
      }
   else
      {
      client->ps.stats[ STAT_HEALTH ] = health;
      }
	}

void Player::UpdateMusic
	(
	void
	)
	{
   if ( music_forced )
      {
      client->ps.current_music_mood = music_current_mood;
      client->ps.fallback_music_mood = music_fallback_mood;
      }
   else if ( action_level > 30 )
      {
      music_current_mood = mood_normal;
      music_fallback_mood = mood_normal;
      client->ps.current_music_mood = mood_action;
      client->ps.fallback_music_mood = mood_normal;
      }
   else if ( ( action_level < 15 ) && ( client->ps.current_music_mood == mood_action ) )
      {
      music_current_mood = mood_normal;
      music_fallback_mood = mood_normal;
      client->ps.current_music_mood = music_current_mood;
      client->ps.fallback_music_mood = music_fallback_mood;
      }
   else if ( client->ps.current_music_mood != mood_action )
      {
      client->ps.current_music_mood = music_current_mood;
      client->ps.fallback_music_mood = music_fallback_mood;
      }

   if (action_level > 0)
      {
      action_level -= level.fixedframetime * 2.0f;
      if ( action_level > 80 )
         {
         action_level = 80;
         }
      }
   else
      {
      action_level = 0;
      }

   //
   // set the music
   // naturally decay the action level
   //
   if ( s_debugmusic->integer )
      {
      gi.DPrintf( "%s's action_level = %4.2f\n", client->pers.netname, action_level );
      }

	// Copy music volume and fade time to player state
	client->ps.music_volume           = music_current_volume;
	client->ps.music_volume_fade_time = music_volume_fade_time;
   }

void Player::EndAnim
   (
   Event *ev
   )

   {
   Event *ev_legs;

   animdone = true;

	ev_legs = new Event( EV_Sentient_AnimLoop );
   ev_legs->AddInteger( legs );
   SetAnimDoneEvent( ev_legs );
   }

void Player::SetAnim
	(
	const char *anim
	)

	{
   Event *ev_legs;

   assert( anim );
   assert ( !deadflag );

	if ( currentAnim == anim )
		{
   	return;
		}

   gi.DPrintf( "Anim: %s\n", anim );
   currentAnim = anim;

	ev_legs = new Event( EV_Sentient_AnimLoop );
   ev_legs->AddInteger( legs );

   RandomAnimate( currentAnim.c_str(), ev_legs );

   if ( HasTorso() )
      {
   	RandomAnimate( currentAnim.c_str(), NULL, torso );
      }

   if ( HasHead() )
      {
   	RandomAnimate( currentAnim.c_str(), NULL, head );
      }
	}

/*
=================
EndFrame

Called for each player at the end of the server frame
and right after spawning
=================
*/
void Player::EndFrame
	(
	Event *ev
	)

	{
   int count;

   recent_ucmd = last_ucmd;

   // Evaluate the current state.
   // When the state changes, we reevaluate the state so that if the
   // conditions aren't met in the new state, we don't play one frame of 
   // the animation for that state before going to the next state.
   count = 0;
   do
      {
      // 2since we could get into an infinite loop here, do a check
      // to make sure we don't.
      count++;
      if ( count > 10 )
         {
         gi.DPrintf( "Possible infinite loop in state '%s'\n", currentState->getName() );
         if ( count > 20 )
            {
            gi.Error( ERR_DROP, "Stopping due to possible infinite state loop\n" );
            break;
            }
         }

      laststate = currentState;
      currentState = currentState->Evaluate( *this );
      animdone = false;
      if ( laststate != currentState )
         {
         currentState->Evaluate( *this );
         SetAnim( currentState->getLegAnim() );
//         gi.DPrintf( "Currentstate = %s\n", currentState->getName() );
         }
      }
   while( laststate != currentState );

	FinishMove();
   UpdateStats();
   UpdateMusic();

   SetupView();
	}

void Player::DoneFiring
	(
	Event *ev
	)

	{
	firing = false;
	}

void Player::TestThread
	(
	Event *ev
	)

	{
   const char *scriptfile;
   const char *label = NULL;
   ScriptThread * thread;

	if ( ev->NumArgs() < 1 )
		{
      gi.SendServerCommand( edict, "print \"Syntax: testthread scriptfile <label>.\n\"" );
		return;
		}

   scriptfile = ev->GetString( 1 );
   if ( ev->NumArgs() > 1 )
      {
      label = ev->GetString( 2 );
      }

   thread = Director.CreateThread( scriptfile, LEVEL_SCRIPT, label );
   if ( thread )
      {
      // start right away
      thread->Start( -1 );
      }
	}

void Player::GibEvent
   (
   Event *ev
   )

   {
   qboolean hidemodel;

   hidemodel = !ev->GetInteger( 1 );

   if ( sv_gibs->integer && !parentmode->integer )
      {
      if ( hidemodel )
         {
	      gibbed = true;
         takedamage = DAMAGE_NO;
         setSolidType( SOLID_NOT );
         hideModel();
         }

      CreateGibs( this, health, 0.75f, 3 );
      }
   }

void Player::GotKill
	(
	Event *ev
	)

	{
	Entity *victim;
   Entity *inflictor;
   str     location;
   float   damage;
   int     meansofdeath;
   qboolean gibbed;

   if ( deathmatch->integer )
		{
      return;
		}

	victim = ev->GetEntity( 1 );
	damage = ev->GetInteger( 2 );
	inflictor = ev->GetEntity( 3 );
   location = ev->GetString( 4 );
	meansofdeath = ev->GetInteger( 5 );
	gibbed = ev->GetInteger( 6 );
	}

void Player::SetPowerupTimer
   (
   Event *ev
   )

   {
   Event *event;

   poweruptimer = ev->GetInteger( 1 );
   poweruptype  = ev->GetInteger( 2 );
   event = new Event( EV_Player_UpdatePowerupTimer );
   PostEvent ( event, 1 );
   }

void Player::UpdatePowerupTimer
   (
   Event *ev
   )

   {
   poweruptimer -= 1;
   if ( poweruptimer > 0 )
      {
      PostEvent( ev, 1 );
      }
   else
      {
      poweruptype = 0;
      }
   }

void Player::WhatIs
	(
	Event *ev
	)

	{
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
      gi.SendServerCommand( edict, "print \"Usage: whatis <entity number>\n\"" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      gi.SendServerCommand( edict, "print \"Value out of range.  Possible values range from 0 to %d.\n\"", globals.max_entities );
		return;
		}

	ent = G_GetEntity( num );
	if ( !ent )
		{
      gi.SendServerCommand( edict, "print \"Entity not in use.\n\"", globals.max_entities );
      }
	else
		{
      const char * animname;
      int own;

      animname = NULL;
      if ( gi.IsModel( ent->edict->s.modelindex ) )
         {
         animname = gi.Anim_NameForNum( ent->edict->s.modelindex, ent->edict->s.anim );
         }

      if ( !animname )
         {
         animname = "( N/A )";
         }

      if ( ent->edict->owner )
         {
         own = ent->edict->owner - g_entities;
         }
      else
         {
         own = 0;
         }

      gi.SendServerCommand( edict, "print \""
			"Entity #   : %d\n"
			"Class ID   : %s\n"
			"Classname  : %s\n"
			"Targetname : %s\n"
         "Modelname  : %s\n"
         "Animname   : %s\n"
			"Origin     : ( %f, %f, %f )\n"
	      "Bounds     : Mins( %.2f, %.2f, %.2f ) Maxs( %.2f, %.2f, %.2f )\n"
         "Velocity   : ( %f, %f, %f )\n"
         "SVFLAGS    : %x\n"
         "Movetype   : %i\n"
         "Solidtype  : %i\n"
         "Parent     : %i\n"
         "Health     : %.1f\n"
         "Max Health : %.1f\n"
         "Edict Owner: %i\n\"",
			num,
         ent->getClassID(),
         ent->getClassname(),
         ent->TargetName(),
         ent->model.c_str(),
         animname,
         ent->origin.x, ent->origin.y, ent->origin.z,
         ent->mins.x, ent->mins.y, ent->mins.z, ent->maxs.x, ent->maxs.y, ent->maxs.z,
         ent->velocity.x, ent->velocity.y, ent->velocity.z,
         ent->edict->svflags,
         ent->movetype,
         ent->edict->solid,
         ent->edict->s.parent,
         ent->health,
         ent->max_health,
         own
         );
		}
	}

void Player::KillEnt
	(
   Event * ev
   )

   {
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
      gi.SendServerCommand( edict, "print \"Usage: killent <entity number>\n\"" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      gi.SendServerCommand( edict, "print \"Value out of range.  Possible values range from 0 to %d.\n\"", globals.max_entities );
      return;
		}

	ent = G_GetEntity( num );
   ent->Damage( world, world, ent->max_health + 25, origin, vec_zero, vec_zero, 0, 0, 0, -1, -1, 1 );
   }

void Player::RemoveEnt
	(
   Event * ev
   )

   {
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
      gi.SendServerCommand( edict, "print \"Usage: removeent <entity number>\n\"" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      gi.SendServerCommand( edict, "print \"Value out of range.  Possible values range from 0 to %d.\n\"", globals.max_entities );
      return;
		}

	ent = G_GetEntity( num );
   ent->PostEvent( Event( EV_Remove ), 0 );
   }

void Player::KillClass
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
      gi.SendServerCommand( edict, "print \"Usage: killclass <classname> [except entity number]\n\"" );
		return;
		}

   classname = ev->GetString( 1 );

   except = 0;
   if ( ev->NumArgs() == 2 )
      {
      except = ev->GetInteger( 1 );
      }

   for ( from = this->edict + 1; from < &g_entities[ globals.num_entities ]; from++ )
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
         ent->Damage( world, world, ent->max_health + 25, origin, vec_zero, vec_zero, 0, 0, 0, -1, -1, 1 );
         }
      }
   }

void Player::RemoveClass
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
	   gi.SendServerCommand( edict, "print \"Usage: removeclass <classname> [except entity number]\n\"" );
		return;
		}

   classname = ev->GetString( 1 );

   except = 0;
   if ( ev->NumArgs() == 2 )
      {
      except = ev->GetInteger( 1 );
      }

   for ( from = this->edict + 1; from < &g_entities[ globals.num_entities ]; from++ )
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

void Player::ActorInfo
	(
	Event *ev
	)

	{
	int num;
	Entity *ent;

	if ( ev->NumArgs() != 1 )
		{
      gi.SendServerCommand( edict, "print \"Usage: actorinfo <entity number>\n\"" );
		return;
		}

	num = ev->GetInteger( 1 );
   if ( ( num < 0 ) || ( num >= globals.max_entities ) )
		{
      gi.SendServerCommand( edict, "print \"Value out of range.  Possible values range from 0 to %d.\n\"", globals.max_entities );
		return;
		}

	ent = G_GetEntity( num );
   if ( !ent || !ent->isSubclassOf( Actor ) )
		{
      gi.SendServerCommand( edict, "print \"Entity not an Actor.\n\"" );
		}
	else
		{
      ( ( Actor * )ent )->ShowInfo();
		}
	}

void Player::Taunt
	(
	Event *ev
	)

	{
   if ( level.time < lastTauntTime )
      {
      return;
      }

   BroadcastSound();
	Sound( str("snd_taunt") + ev->GetString( 1 ), qfalse, CHAN_VOICE );
   lastTauntTime = level.time + TAUNT_TIME;
	}

void Player::ChangeMusic
	(
   const char * current,
   const char * fallback,
   qboolean force
	)

   {
   int current_mood_num;
   int fallback_mood_num;

   music_forced = force;
   if ( str( current ) == "normal" )
      {
      music_forced = false;
      }

   if ( current )
      {
      current_mood_num = MusicMood_NameToNum( current );
      if ( current_mood_num < 0 )
         {
         gi.DPrintf( "current music mood %s not found", current );
         }
      else
         {
         music_current_mood = current_mood_num;
         }
      }

   if ( fallback )
      {
      fallback_mood_num = MusicMood_NameToNum( fallback );
      if ( fallback_mood_num < 0 )
         {
         gi.DPrintf( "fallback music mood %s not found", fallback );
         fallback = NULL;
         }
      else
         {
         music_fallback_mood = fallback_mood_num;
         }
      }
   }

void Player::ChangeMusicVolume
	(
   float volume,
	float fade_time
	)

   {
	music_volume_fade_time = fade_time;
	music_saved_volume     = music_current_volume;
	music_current_volume   = volume;
	}

void Player::RestoreMusicVolume
	(
   float fade_time
	)

   {
	music_volume_fade_time = fade_time;
	music_current_volume   = music_saved_volume;
	music_saved_volume     = -1.0;
	}

void Player::SetFlashColor
   (
   Event *ev
   )

   {
   if ( flash_color[ 3 ] == 0 )
      {
      flash_color[ 0 ] = flash_color[ 1 ] = flash_color[ 2 ] = 0;
      }

   flash_color[ 0 ] += ev->GetFloat( 1 );
   flash_color[ 1 ] += ev->GetFloat( 2 );
   flash_color[ 2 ] += ev->GetFloat( 3 );
   flash_color[ 3 ] += ev->GetFloat( 4 );

   if ( flash_color[ 0 ] > 1 )
      {
      flash_color[ 0 ] = 1;
      }

   if ( flash_color[ 1 ] > 1 )
      {
      flash_color[ 1 ] = 1;
      }

   if ( flash_color[ 2 ] > 1 )
      {
      flash_color[ 2 ] = 1;
      }

   if ( flash_color[ 3 ] > 1 )
      {
      flash_color[ 3 ] = 1;
      }
   }

void Player::ClearFlashColor
   (
   Event *ev
   )

   {
   flash_color[ 0 ] = 0;
   flash_color[ 1 ] = 0;
   flash_color[ 2 ] = 0;
   flash_color[ 3 ] = 0;
   }

void Player::GiveOxygen
   (
   float time
   )

   {
   air_finished = level.time + time;
   }

void Player::SetSkin
   (
   Event *ev
   )

   {
   Q_strncpyz( client->pers.skin, ev->GetString( 1 ), sizeof( client->pers.skin ) );
   }

void Player::AttackEndEvent
   (
   Event *ev
   )

   {
   if ( activeWeapon )
      {
      activeWeapon->ClientFireDone();
      activeWeapon->NextAttack( 0 );
      }
   }

void Player::Jump
   (
   Event *ev
   )

   {
   float maxheight;

   maxheight = gi.Anim_MaxHeight( edict->s.modelindex, CurrentAnim() );

   if ( maxheight > 16 )
      {
      // v^2 = 2ad
      velocity[ 2 ] += sqrt( 2 * sv_gravity->integer * maxheight );
      }
   }

ActiveWeapon::ActiveWeapon
   (
   )

   {
   weapon = NULL;
   number = -1;
   }