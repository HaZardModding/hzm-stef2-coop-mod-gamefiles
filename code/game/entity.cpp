//-----------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/entity.cpp                 $
// $Revision:: 58                                                            $
//   $Author:: Steven                                                   $
//     $Date:: 8/29/01 6:04p                                   $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/entity.cpp                      $
// 
// 58    8/29/01 6:04p Steven
// Added a return type for the setup proc.
// 
// 57    8/23/01 2:44p Steven
// Removed all rff stuff.
// 
// 56    8/17/01 2:47p Sketcher
// Working on allowing pitch changes to traceatk
// 
// 55    8/17/01 2:04p Sketcher
// Fixed some errors with Vehicle and traceattack
// 
// 54    8/13/01 10:39a Sketcher
// added stuff to let NPC's detect the player in FOV
// only 
// 
// 53    7/26/01 3:02p Sketcher
// Moved EV_OnlyShootable from Actor to Entity
// 
// 52    7/23/01 6:30p Sketcher
// modified ProjectileAtk
// 
// 51    7/23/01 4:17p Sketcher
// Added a ShootMode Type for the Night Train stuff
// 
// 50    7/23/01 2:37p Sketcher
// First Pass at horse vehicle.  Still needs lots of
// cleanup
// 
// 49    7/16/01 8:58a Steven
// Added projectile/trace attack from entities.
// 
// 48    6/29/01 12:12p Sketcher
// Added selfDetonate event and
// setEntityExplosionModel event
// 
// 47    6/29/01 9:43a Sketcher
// Made modifications so that actors know when to
// reload
// 
// 46    6/21/01 2:44p Steven
// Attach model fixes.
// 
// 45    6/20/01 1:48p Steven
// Added gethealth.
// 
// 44    6/20/01 7:39a Sketcher
// AI Work for the Townie
// 
// 43    6/14/01 10:41a Sketcher
// More work on splitting actor legs and torso
// 
// 42    6/11/01 8:18a Steven
// Fixed event documentation.
// 
// 41    6/11/01 8:08a Steven
// Added attach angles offset.
// 
// 40    2.05.01 3:43p Kharward
// Updated the edict structure to correctly pass the
// clientNum.  It is initialized to ENTITYNUM_NONE
// for non-player entities.
// 
// 39    5/02/01 2:04p Steven
// Merged in Strange Company stuff.
// 
// 38    2.05.01 11:31a Kharward
// Added back in the code to set the viewangles of
// the entity structure that gets passed to the
// client if the current entity is a player.
// 
// 37    5/01/01 1:55p Steven
// Added bone damage stuff.
// 
// 36    4/30/01 3:37p Sketcher
// Ahem.... RE!!!!!!!!! Added Surface-Based sound
// radii for footsteps.  
// 
// 35    4/23/01 6:42p Steven
// Added a getorigin to entity.
// 
// 34    4/16/01 1:08p Ericf
// Added "autocache" event (which is the same as
// cache, but only generated automatically by the
// tiki editor)
// 
// 33    4/12/01 3:11p Sketcher
// modified the SpawnActorAtTag to offset above the
// tag rather than along the direction vector
// 
// 32    4/05/01 5:48p Ericf
// Fixed assert bug
// 
// 31    3/28/01 3:24p Steven
// Added warning printfs.
// 
// 30    3/19/01 9:46a Sketcher
// Added Redemption effects, Redemption Health, and
// Redemptive Scalar
// 
// 29    15.03.01 12:04p Ericf
// Added the redemptive damage parameter to Damage
// function
// 
// 28    15.03.01 11:43a Ericf
//
// 27    15.03.01 11:35a Ericf
// Added a parameter to the Damage funciton
// 
// 20    1/30/01 2:14p Steven
// Area based damage stuff.
// 
// 19    16.01.01 1:47p Ericf
// View/World model stuff
// 
// 18    1/09/01 11:08a Steven
// Increased world size.
// 
// 17    12/11/00 3:44p Sketcher
// Added an Alert Event.  Also, added a
// BroadcastAlert() and its companion
// G_BroadcastAlert()
// 
// 16    12/11/00 3:16p Steven
// Made str passing const references.
// 
// 15    12/11/00 1:52p Sketcher
// Added the SetMaxHealth function
// 
// 14    12/11/00 12:15p Sketcher
// Added Resistances, and checks to make sure that
// any resistance over 100, does not add more than
// the max health of the creature.  
// 
// 13    12/11/00 9:33a Steven
// Changed passing of most vectors to const
// reference.
// 
// 12    12/08/00 11:53a Sketcher
// It is now possible to send a soundtype with a
// sound when it is broadcast.  However, at this time
// nothing happens if you do.  
// 
// 11    12/08/00 9:07a Steven
// Moved bind stuff to a pluggable module and removed
// move_time.
// 
// 10    11/30/00 12:57p Steven
// Removed an unused variable.
// 
// 9     11/29/00 3:02p Steven
// Fixed saving/loading of animate and mover stuff.
// 
// 8     11/29/00 12:56p Steven
// Made mover a pluggable module.
// 
// 7     11/22/00 11:57a Steven
// Test
// 
// 6     11/22/00 11:56a Steven
// This is a test
//
// DESCRIPTION:
// Base class for all enities that are controlled by Sin.  If you have any
// object that should be called on a periodic basis and it is not an entity,
// then you have to have an dummy entity that calls it.
//
// An entity in Sin is any object that is not part of the world.  Any non-world
// object that is visible in Sin is an entity, although it is not required that
// all entities be visible to the player.  Some objects are basically just virtual
// constructs that act as an instigator of certain actions, for example, some
// triggers are invisible and cannot be touched, but when activated by other
// objects can cause things to happen.
//
// All entities are capable of receiving messages from Sin or from other entities.
// Messages received by an entity may be ignored, passed on to their superclass,
// or acted upon by the entity itself.  The programmer must decide on the proper
// action for the entity to take to any message.  There will be many messages
// that are completely irrelevant to an entity and should be ignored.  Some messages
// may require certain states to exist and if they are received by an entity when
// it these states don't exist may indicate a logic error on the part of the
// programmer or map designer and should be reported as warnings (if the problem is
// not severe enough for the game to be halted) or as errors (if the problem should
// not be ignored at any cost).
//

#include "entity.h"
#include "worldspawn.h"
#include "scriptmaster.h"
#include "sentient.h"
#include "misc.h"
#include "specialfx.h"
#include "object.h"
#include "player.h"
#include "weaputils.h"
#include "soundman.h"
#include "../qcommon/qfiles.h"


// Player events
Event EV_ClientMove
	(
	"client_move",
   EV_DEFAULT,
	NULL,
	NULL,
	"The movement packet from the client is processed by this event."
	);
Event EV_ClientEndFrame
	(
	"client_endframe",
	EV_DEFAULT,
	NULL,
	NULL,
	"Called at the end of each frame for each client."
	);

// Generic entity events
Event EV_Classname
	(
	"classname" ,
	EV_DEFAULT,
	"s",
	"nameOfClass",
	"Determines what class to use for this entity,\n"
	"this is pre-processed from the BSP at the start\n"
	"of the level."
	);
Event EV_SpawnFlags
	(
	"spawnflags",
	EV_DEFAULT,
	"i",
	"flags",
	"spawnflags from the BSP, these are set inside the editor"
	);
Event EV_SetTeam
	(
	"team",
	EV_DEFAULT,
	"s",
	"moveTeam",
	"used to make multiple entities move together."
	);
Event EV_Trigger
	(
	"trigger",
	EV_DEFAULT,
	"s",
	"name",
	"Trigger the specified target or entity."
	);
Event EV_Activate
	(
	"doActivate",
	EV_DEFAULT,
	"e",
	"activatingEntity",
	"General trigger event for all entities"
	);
Event EV_Use
	(
	"doUse",
	EV_DEFAULT,
	"e",
	"activatingEntity",
	"sent to entity when it is used by another entity"
	);

Event EV_FadeNoRemove
	(
	"fade",
	EV_DEFAULT,
	"F[0,]F[0,1]",
	"fadetime target_alpha",
	"Fade the entity's alpha, reducing it by 0.03\n"
	"every FRAMETIME, until it has faded out, does not remove the entity"
	);

Event EV_FadeOut
	(
	"_fadeout",
	EV_DEFAULT,
	NULL,
	NULL,
	"Fade the entity's alpha and scale out, reducing it by 0.03\n"
	"every FRAMETIME, until it has faded out, removes the entity\n"
   "Once the entity has been completely faded, the entity is removed."
	);

Event EV_Fade
	(
	"fadeout",
	EV_DEFAULT,
	"F[0,]F[0,1]",
	"fadetime target_alpha",
	"Fade the entity's alpha and scale out, reducing it by 0.03\n"
	"every FRAMETIME, until it has faded out. If fadetime or\n"
   "target_alpha are defined, they will override the defaults.\n"
   "Once the entity has been completely faded, the entity is removed."
	);
Event EV_FadeIn
	(
	"fadein",
	EV_DEFAULT,
   "F[0,]F[0,1]",
   "fadetime target_alpha",
	"Fade the entity's alpha and scale in, increasing it by 0.03\n"
	"every FRAMETIME, until it has faded completely in to 1.0.\n"
   "If fadetime or target_alpha are defined, they will override\n"
   "the default values."
	);
 Event EV_Killed
	(
	"killed",
	EV_DEFAULT,
	"eiei",
	"attacker damage inflictor meansofdeath",
	"event which is sent to an entity once it as been killed"
	);
Event EV_GotKill
	(
	"gotkill" ,
	EV_DEFAULT,
	"eieib",
	"victim damage inflictor meansofdeath gib",
	"event sent to attacker when an entity dies"
	);
Event EV_Pain
	(
	"pain",
	EV_DEFAULT,
	"iei",
	"damage attacker meansofdeath",
	"used to inflict pain to an entity"
	);
Event EV_Damage
	(
	"_damage",
	EV_DEFAULT,
	"ieevvviii",
	"damage inflictor attacker position direction normal knockback damageflags meansofdeath",
	"general damage event used by all entities"
	);
Event EV_Stun
	(
	"_stun",
	EV_DEFAULT,
	"f",
	"time",
	"Stun this entity for the specified time"
	);
Event EV_Kill
	(
	"kill",
	EV_CONSOLE,
	NULL,
	NULL,
	"console based command to kill yourself if stuck."
	);
Event EV_Gib
	(
	"gib",
	EV_DEFAULT,
	"iIFS",
	"number power scale gibmodel",
	"causes entity to spawn a number of gibs"
	);
Event EV_Hurt
	(
	"hurt",
	EV_DEFAULT,
	"iSV",
	"damage means_of_death direction",
	"Inflicts damage if the entity is damageable.  If the number of damage\n"
	"points specified in the command argument is greater or equal than the\n"
	"entity's current health, it will be killed or destroyed."
	);

Event EV_TakeDamage
	(
	"takedamage",
	EV_DEFAULT,
	NULL,
	NULL,
	"makes entity take damage."
	);
Event EV_NoDamage
	(
	"nodamage",
	EV_DEFAULT,
	NULL,
	NULL,
	"entity does not take damage."
	);

Event EV_Stationary
	(
	"stationary",
	EV_DEFAULT,
	NULL,
	NULL,
	"entity does not move, causes no physics to be run on it."
	);

// Physics events
Event EV_MoveDone
	(
	"movedone",
	EV_DEFAULT,
	"e",
	"finishedEntity",
	"Sent to commanding thread when done with move ."
	);
Event EV_Touch
	(
	"doTouch",
	EV_DEFAULT,
	"e",
	"touchingEntity",
	"sent to entity when touched."
	);
Event EV_Blocked
	(
	"doBlocked",
	EV_DEFAULT,
	"e",
	"obstacle",
	"sent to entity when blocked."
	);
Event EV_UseBoundingBox
	(
	"usebbox",
	EV_DEFAULT,
	NULL,
	NULL,
	"do not perform perfect collision, use bounding box instead."
	);
Event EV_Gravity
	(
	"gravity",
	EV_DEFAULT,
	"f",
	"gravityValue",
	"Change the gravity on this entity"
	);
Event EV_Stop
	(
	"stopped",
	EV_DEFAULT,
	NULL,
	NULL,
	"sent when entity has stopped bouncing for MOVETYPE_TOSS."
	);

Event EV_ProcessInitCommands
	(
	"processinit",
	EV_DEFAULT,
	"i",
	"modelIndex",
	"process the init section of this entity, this is an internal command,\n"
	"it is not meant to be called from script."
	);
Event EV_Attach
	(
	"attach",
	EV_DEFAULT,
	"esIVV",
	"parent tagname use_angles offset angles_offset",
	"attach this entity to the parent's legs tag called tagname"
	);
Event EV_AttachModel
	(
	"attachmodel",
	EV_DEFAULT,
	"ssFSBFFFFVV",
	"modelname tagname scale targetname detach_at_death removetime fadeintime fadeoutdelay fadetime offset angles_offset",
	"attach a entity with modelname to this entity to tag called tagname.\n"
	"scale           - scale of attached entities\n"
	"targetname      - targetname for attached entities\n"
	"detach_at_death - when entity dies, should this model be detached.\n"
	"removetime      - when the entity should be removed, if not specified, never.\n"
   "fadeintime      - time to fade the model in over.\n"
   "fadeoutdelay    - time to wait until we fade the attached model out\n"
   "fadeoutspeed    - time the model fades out over\n"
	"offset		     - vector offset for the model from the specified tag\n"
	"angles_offset   - angles offset for the model from the specified tag"
	);
Event EV_RemoveAttachedModel
	(
	"removeattachedmodel",
	EV_DEFAULT,
	"s",
	"tagname",
	"Removes the model attached to this entity at the specified tag."
	);
Event EV_Detach
	(
	"detach",
	EV_DEFAULT,
	NULL,
	NULL,
	"detach this entity from its parent."
	);

Event EV_IncreaseShotCount
   (
	"increaseshotcount",
	EV_DEFAULT,
	NULL,
	NULL,
	"boosts the shotsFired on this entity's parent if it is an actor"
	);

// script stuff
Event EV_Model
	(
	"model",
	EV_DEFAULT,
	"e",
	"modelName",
	"set the model to modelName."
	);
Event EV_Hide
	(
	"hide",
	EV_DEFAULT,
	NULL,
	NULL,
	"hide the entity, opposite of show."
	);
Event EV_Show
	(
	"show",
	EV_DEFAULT,
	NULL,
	NULL,
	"show the entity, opposite of hide."
	);
Event EV_BecomeSolid
	(
	"solid",
	EV_DEFAULT,
	NULL,
	NULL,
	"make solid."
	);
Event EV_BecomeNonSolid
	(
	"notsolid",
	EV_DEFAULT,
	NULL,
	NULL,
	"make non-solid."
	);
Event EV_Ghost
	(
	"ghost",
	EV_DEFAULT,
	NULL,
	NULL,
	"make non-solid but still send to client regardless of hide status."
	);
Event EV_TouchTriggers
	(
	"touchtriggers",
	EV_DEFAULT,
   NULL,
   NULL,
   "this entity should touch triggers."
	);
Event EV_Sound
	(
	"playsound",
	EV_DEFAULT,
	"sIFS",
	"soundName channel volume min_distance",
	"play a sound coming from this entity.\n"
	"default channel, CHAN_BODY."
	);
Event EV_StopSound
	(
	"stopsound",
	EV_DEFAULT,
	"I",
	"channel",
	"stop the current sound on the specified channel.\n"
	"default channel, CHAN_BODY."
	);
Event EV_Bind
	(
	"bind",
	EV_DEFAULT,
	"e",
	"parent",
	"bind this entity to the specified entity."
	);
Event EV_Unbind
	(
	"unbind",
	EV_DEFAULT,
	NULL,
	NULL,
	"unbind this entity."
	);
Event EV_JoinTeam
	(
	"joinTeam",
	EV_DEFAULT,
	"e",
	"teamMember",
	"join a bind team."
	);
Event EV_QuitTeam
	(
	"quitTeam",
	EV_DEFAULT,
	NULL,
	NULL,
	"quit the current bind team"
	);
Event EV_SetHealth
   (
   "health",
   EV_CHEAT,
   "i",
   "newHealth",
   "set the health of the entity to newHealth"
   );
Event EV_GetHealth
   (
   "gethealth",
   EV_CHEAT,
   "@f",
   "currentHealth",
   "Gets the health of the entity"
   );
Event EV_SetMaxHealth
	(
	"maxhealth",
	EV_CHEAT,
	"i",
	"newMaxHealth",
	"set the max_health of the entity to newMaxHealth"
	);
Event EV_SetScale
   (
   "scale",
   EV_DEFAULT,
   "f",
   "newScale",
   "set the scale of the entity"
   );
Event EV_SetSize
   (
   "setsize",
   EV_DEFAULT,
   "vv",
   "mins maxs",
   "Set the bounding box of the entity to mins and maxs."
   );
Event EV_SetMins
   (
   "_setmins",
   EV_DEFAULT,
   "v",
   "mins",
   "Set the mins of the bounding box of the entity to mins."
   );
Event EV_SetMaxs
   (
   "_setmaxs",
   EV_DEFAULT,
   "v",
   "maxs",
   "Set the maxs of the bounding box of the entity to maxs."
   );
Event EV_SetAlpha
   (
   "alpha",
   EV_DEFAULT,
   "f",
   "newAlpha",
   "Set the alpha of the entity to alpha."
   );
Event EV_SetOrigin
   (
   "origin",
   EV_DEFAULT,
   "v",
   "newOrigin",
   "Set the origin of the entity to newOrigin."
   );
Event EV_GetOrigin
   (
   "getorigin",
   EV_DEFAULT,
   "@v",
   "returnval",
   "Gets the origin of the entity."
   );
Event EV_SetTargetName
   (
   "targetname",
   EV_DEFAULT,
   "s",
   "targetName",
   "set the targetname of the entity to targetName."
   );
Event EV_SetTarget
   (
   "target",
   EV_DEFAULT,
   "s",
   "targetname_to_target",
   "target another entity with targetname_to_target."
   );
Event EV_SetKillTarget
   (
   "killtarget",
   EV_DEFAULT,
   "s",
   "targetName",
   "when dying kill entities with this targetName."
   );
Event EV_SetAngles
   (
   "angles",
   EV_DEFAULT,
   "v[0,360][0,360][0,360]",
   "newAngles",
   "set the angles of the entity to newAngles."
   );
Event EV_SetAngle
   (
   "angle",
   EV_DEFAULT,
   "f",
   "newAngle",
   "set the angles of the entity using just one value.\n"
   "Sets the yaw of the entity or an up and down\n"
   "direction if newAngle is [0-359] or -1 or -2"
   );
Event EV_RegisterAlias
   (
   "alias",
   EV_CACHE,
   "ssSSSSSS",
   "alias realname parameter1 parameter2 parameter3 parameter4 parameter5 paramater6",
   "create an alias for the given realname\n"
   "Valid parameters are as follows:\n"
   "global - all instances act as one\n"
   "stop - once used, don't use again\n"
   "timeout [seconds] - once used wait [seconds] until using again\n"
   "maxuse [times] - can only be used [times] times.\n"
   "weight [weight] - random weighting"
   );
Event EV_RegisterAliasAndCache
   (
   "aliascache",
   EV_CACHE,
   "ssSSSSSS",
   "alias realname parameter1 parameter2 parameter3 parameter4 parameter5 paramater6",
   "create an alias for the given realname and cache the resource\n"
   "Valid parameters are as follows:\n"
   "global - all instances act as one\n"
   "stop - once used, don't use again\n"
   "timeout [seconds] - once used wait [seconds] until using again\n"
   "maxuse [times] - can only be used [times] times.\n"
   "weight [weight] - random weighting"
   );
Event EV_Cache
   (
   "cache",
   EV_CACHE,
   "s",
   "resourceName",
   "pre-cache the given resource."
   );
Event EV_AutoCache
   (
   "autocache",
   EV_CACHE,
   "s",
   "resourceName",
   "pre-cache the given resource."
   );
Event EV_SetMass
   (
   "mass",
   EV_DEFAULT,
   "f",
   "massAmount",
   "set the mass of this entity."
   );

Event EV_LoopSound
   (
   "loopsound",
   EV_DEFAULT,
   "sFS",
   "soundName volume minimum_distance",
   "play a looped-sound with a certain volume and minimum_distance\n"
   "which is attached to the current entity."
   );
Event EV_StopLoopSound
   (
   "stoploopsound",
   EV_DEFAULT,
   NULL,
   NULL,
   "Stop the looped-sound on this entity."
   );

Event EV_SurfaceModelEvent
   (
   "surface",
   EV_DEFAULT,
   "sSSSSSS",
   "surfaceName parameter1 parameter2 parameter3 parameter4 parameter5 parameter6",
   "change a legs surface parameter for the given surface.\n"
   "+ sets the flag, - clears the flag\n"
   "Valid surface commands are:\n"
   "skin1 - set the skin1 offset bit\n"
   "skin2 - set the skin2 offset bit\n"
   "nodraw - don't draw this surface"
   );

Event EV_SetAnimOnAttachedModel
   (
	"setanimonattachedmodel",
	EV_DEFAULT,
	"ss",
	"anim_name tag_name",
	"sets the anim on an attached actor at the specified tag"
	);

Event EV_SetEntityExplosionModel
   (
   "setentityexplosionmodel",
	EV_DEFAULT,
	"s",
	"model_name",
	"sets this entitys explosion model which is used in selfDetonate"
	);

// AI sound events
Event EV_BroadcastSound
   (
   "soundevent",
   EV_DEFAULT,
   "FS",
   "soundRadius soundtype",
   "Let the AI know that this entity made a sound,\n"
   "radius determines how far the sound reaches."
   );
Event EV_HeardSound
   (
   "heardsound",
   EV_DEFAULT,
   "evi",
   "noisyEntity noisyLocation soundtype",
   "sent to entities when another makes a sound, not for script use\n"
   );

// Conditionals
Event EV_IfSkill
   (
   "ifskill",
   EV_DEFAULT,
   "isSSSSS",
   "skillLevel command argument1 argument2 argument3 argument4 argument5",
   "if the current skill level is skillLevel than execute command"
   );

// Lighting
Event EV_SetLight
   (
   "light",
   EV_DEFAULT,
   "ffff",
   "red green blue radius",
   "Create a dynmaic light on this entity."
   );

Event EV_LightOn
   (
   "lightOn",
   EV_DEFAULT,
   NULL,
   NULL,
   "Turn the configured dynmaic light on this entity on."
   );
Event EV_LightOff
   (
   "lightOff",
   EV_DEFAULT,
   NULL,
   NULL,
   "Turn the configured dynamic light on this entity off."
   );
Event EV_LightStyle
   (
   "lightStyle",
   EV_DEFAULT,
   "i",
   "lightStyleIndex",
   "What light style to use for this dynamic light on this entity."
   );
Event EV_LightRed
   (
   "lightRed",
   EV_DEFAULT,
   "f",
   "red",
   "Set the red component of the dynmaic light on this entity."
   );
Event EV_LightGreen
   (
   "lightGreen",
   EV_DEFAULT,
   "f",
   "red",
   "Set the red component of the dynmaic light on this entity."
   );
Event EV_LightBlue
   (
   "lightBlue",
   EV_DEFAULT,
   "f",
   "red",
   "Set the red component of the dynmaic light on this entity."
   );
Event EV_LightRadius
   (
   "lightRadius",
   EV_DEFAULT,
   "f",
   "red",
   "Set the red component of the dynmaic light on this entity."
   );

// Entity flag specific
Event EV_EntityFlags
   (
   "flags",
   EV_DEFAULT,
   "SSSSSS",
   "parameter1 parameter2 parameter3 parameter4 parameter5 parameter6",
   "Change the current entity flags.\n"
   "Valid flags are as follows:\n"
   "+ sets a flag, - clears a flag\n"
   "blood - should it bleed\n"
   "explode - should it explode when dead\n"
   "die_gibs - should it spawn gibs when dead\n"
   "god - makes the entity invincible\n"
   );
Event EV_EntityRenderEffects
   (
   "rendereffects",
   EV_DEFAULT,
   "SSSSSS",
   "parameter1 parameter2 parameter3 parameter4 parameter5 parameter6",
   "Change the current render effects flags.\n"
   "Valid flags are as follows:\n"
   "+ sets a flag, - clears a flag\n"
   "dontdraw - send the entity to the client, but don't draw\n"
   "betterlighting - do sphere based vertex lighting on the entity\n"
   "lensflare - add a lens glow to the entity at its origin\n"
   "viewlensflare - add a view dependent lens glow to the entity at its origin\n"
   "lightoffset - use the dynamic color values as a light offset to the model\n"
   "skyorigin - this entity is the portal sky origin\n"
   "minlight - this entity always has some lighting on it\n"
   "fullbright - this entity is always fully lit\n"
   "additivedynamiclight - the dynamic light should have an additive effect\n"
   "lightstyledynamiclight - the dynamic light uses a light style, use the\n"
   "'lightstyle' command to set the index of the light style to be used"
   );
Event EV_EntityEffects
   (
   "effects",
   EV_DEFAULT,
   "SSSSSS",
   "parameter1 parameter2 parameter3 parameter4 parameter5 parameter6",
   "Change the current entity effects flags.\n"
   "Valid flags are as follows:\n"
   "+ sets a flag, - clears a flag\n"
   "everyframe - process commands every time entity is rendered"
   );
Event EV_EntitySVFlags
   (
   "svflags",
   EV_DEFAULT,
   "SSSSSS",
   "parameter1 parameter2 parameter3 parameter4 parameter5 parameter6",
   "Change the current server flags.\n"
   "Valid flags are as follows:\n"
   "+ sets a flag, - clears a flag\n"
   "broadcast - always send this entity to the client"
   );

// Special Effects
Event EV_Censor
   (
   "censor",
   EV_DEFAULT,
   NULL,
   NULL,
   "used to ban certain contact when in parentmode\n"
   );
Event EV_Explosion
   (
   "explosionattack",
   EV_DEFAULT,
   "sS",
   "explosionModel tagName",
   "Spawn an explosion optionally from a specific tag"
   );

Event EV_SelfDetonate
   (
	"selfdetonate",
	EV_DEFAULT,
	NULL,
	NULL,
	"spawns and explosion and removes this entity"
	);

Event EV_ShaderEvent
   (
   "shader",
   EV_DEFAULT,
   "sfF",
   "shaderCommand argument1 argument2",
   "change a specific shader parameter for the entity.\n"
   "Valid shader commands are:\n"
   "translation [trans_x] [trans_y] - change the texture translation\n"
   "offset [offset_x] [offset_y] - change the texture offset\n"
   "rotation [rot_speed] - change the texture rotation speed\n"
   "frame [frame_num] - change the animated texture frame\n"
   "wavebase [base] - change the base parameter of the wave function\n"
   "waveamp [amp] - change the amp parameter of the wave function\n"
   "wavebase [phase] - change the phase parameter of the wave function\n"
   "wavefreq [freq] - change the frequency parameter of the wave function\n"
   );

Event EV_ScriptShaderEvent
   (
   "scriptshader",
   EV_DEFAULT,
   "sfF",
   "shaderCommand argument1 argument2",
   "alias for shader command, change a specific shader parameter for the entity.\n"
   "Valid shader commands are:\n"
   "translation [trans_x] [trans_y] - change the texture translation\n"
   "offset [offset_x] [offset_y] - change the texture offset\n"
   "rotation [rot_speed] - change the texture rotation speed\n"
   "frame [frame_num] - change the animated texture frame\n"
   "wavebase [base] - change the base parameter of the wave function\n"
   "waveamp [amp] - change the amp parameter of the wave function\n"
   "wavebase [phase] - change the phase parameter of the wave function\n"
   "wavefreq [freq] - change the frequency parameter of the wave function\n"
   );

Event EV_KillAttach
   (
   "killattach",
   EV_DEFAULT,
   NULL,
   NULL,
   "kill all the attached entities."
   );
Event EV_DropToFloor
	(
	"droptofloor",
	EV_DEFAULT,
	"F",
	"maxRange",
	"drops the entity to the ground, if maxRange is not specified 8192 is used."
	);
Event EV_AddToSoundManager
	(
	"_addtosoundmanager",
	EV_DEFAULT,
	NULL,
	NULL,
	"adds the current entity to the sound manager."
	);
Event EV_SetControllerAngles
	(
	"setcontrollerangles",
	EV_DEFAULT,
	"iv",
	"num angles",
	"Sets the control angles for the specified bone."
	);
Event EV_DeathSinkStart
	(
	"deathsinkstart",
	EV_DEFAULT,
	NULL,
	NULL,
	"Makes the entity sink into the ground and then get removed (this starts it)."
	);
Event EV_DeathSink
	(
	"deathsinkeachframe",
	EV_DEFAULT,
	NULL,
	NULL,
	"Makes the entity sink into the ground and then get removed (this gets called each frame)."
	);
Event EV_DamageType
	(
	"damage_type",
	EV_DEFAULT,
	"s",
   "meansofdeathstring",
	"Set the type of damage that this entity can take"
	);
Event EV_LookAtMe
	(
	"lookatme",
	EV_DEFAULT,
	NULL,
   NULL,
	"Makes the player look at this object if close."
	);
Event EV_DetachAllChildren
	(
	"detachallchildren",
	EV_DEFAULT,
	NULL,
   NULL,
	"Detach all the children from the entity."
	);
Event EV_Morph
	(
	"morph",
	EV_DEFAULT,
	"sFFB",
   "morph_target_name final_percent morph_time return_to_zero",
	"Morphs to the specified morph target"
	);
Event EV_Unmorph
	(
	"unmorph",
	EV_DEFAULT,
	"s",
   "morph_target_name",
	"Unmorphs the specified morph target"
	);
Event EV_MorphControl
	(
	"morphcontrol",
	EV_DEFAULT,
	NULL,
   NULL,
	"Does all of the morph work each frame"
	);

Event EV_SetObjectProgram
   (
   "setobjectprogram",
	EV_DEFAULT,
	"s",
	"program",
	"sets this objects program"
	);

Event EV_ExecuteObjectProgram
   (
   "executeobjectprogram",
	EV_DEFAULT,
	"f",
	"time",
	"executes this objects program at the specified time"
	);

Event EV_ProjectileAtk
   (
   "projectileattack",
	EV_DEFAULT,
	"sS",
	"projectile_name tag_name",
	"Launches a projectile"
	);
Event EV_TraceAtk
   (
   "traceattack",
	EV_DEFAULT,
	"ffSFS",
	"damage range means_of_death knockback tag_name",
	"Does a trace attack"
	);

Event EV_OnlyShootable
	(
	"only_shootable",
	EV_DEFAULT,
	NULL,
	NULL,
	"Makes the actor solid only to projectiles."
	);

CLASS_DECLARATION( Listener, Entity, NULL )
	{
		{ &EV_Damage,				         DamageEvent },
		{ &EV_DamageType,			         DamageType },
      { &EV_Kill, 				         Kill },
	   { &EV_FadeNoRemove,  	         FadeNoRemove },
	   { &EV_FadeOut,				         FadeOut },
	   { &EV_FadeIn,  			         FadeIn },
	   { &EV_Fade,				            Fade },
	   { &EV_Hide,					         EventHideModel },
	   { &EV_Show,					         EventShowModel },
	   { &EV_BecomeSolid,		         BecomeSolid },
	   { &EV_BecomeNonSolid,	         BecomeNonSolid },
	   { &EV_Ghost,	                  Ghost },
	   { &EV_TouchTriggers,	            TouchTriggersEvent },
		{ &EV_Sound,				         Sound },
	   { &EV_StopSound,			         StopSound },
	   { &EV_SetHealth,			         SetHealth },
		{ &EV_GetHealth,			         GetHealth },
		{ &EV_SetMaxHealth,					SetMaxHealth	},
	   { &EV_SetSize,				         SetSize },
	   { &EV_SetMins,				         SetMins },
	   { &EV_SetMaxs,				         SetMaxs },
		{ &EV_SetScale,			         SetScale },
	   { &EV_SetAlpha,			         SetAlpha },
	   { &EV_SetOrigin,			         SetOrigin },
		{ &EV_GetOrigin,			         GetOrigin },
	   { &EV_SetTargetName,		         SetTargetName },
	   { &EV_SetTarget,			         SetTarget },
	   { &EV_SetKillTarget,		         SetKillTarget },
	   { &EV_SetAngles,			         SetAngles },
	   { &EV_SetAngle,			         SetAngleEvent },
      { &EV_SetMass,                   SetMassEvent },
	   { &EV_RegisterAlias,	            RegisterAlias },
	   { &EV_RegisterAliasAndCache,     RegisterAliasAndCache },
	   { &EV_Cache,                     Cache },
		{ &EV_AutoCache,                 Cache },
		{ &EV_LoopSound,						LoopSound },
		{ &EV_StopLoopSound,					StopLoopSound },
		{ &EV_Model,				         SetModelEvent },
      { &EV_SetLight,			         SetLight },
      { &EV_LightOn,				         LightOn },
      { &EV_LightOff,		            LightOff },
      { &EV_LightRed,		            LightRed },
      { &EV_LightGreen,		            LightGreen },
      { &EV_LightBlue,		            LightBlue },
      { &EV_LightRadius,	            LightRadius },
      { &EV_LightStyle,	               LightStyle },
      { &EV_EntityFlags,	            Flags },
      { &EV_EntityEffects,	            Effects },
      { &EV_EntitySVFlags,	            SVFlags },
      { &EV_EntityRenderEffects,	      RenderEffects },
      { &EV_BroadcastSound,            BroadcastSound },
		{ &EV_SurfaceModelEvent,         SurfaceModelEvent },
      { &EV_ProcessInitCommands,       ProcessInitCommandsEvent },
      { &EV_Attach,                    AttachEvent },
      { &EV_AttachModel,               AttachModelEvent },
		{ &EV_RemoveAttachedModel,       RemoveAttachedModelEvent },
      { &EV_Detach,                    DetachEvent },
		{ &EV_IncreaseShotCount,         IncreaseShotCount		},
      { &EV_TakeDamage,                TakeDamageEvent },
      { &EV_NoDamage,                  NoDamageEvent },
      { &EV_Gravity,                   Gravity },
	   { &EV_UseBoundingBox,            UseBoundingBoxEvent },
	   { &EV_Hurt,                      HurtEvent },
	   { &EV_IfSkill,                   IfSkillEvent },
      { &EV_Classname,                 ClassnameEvent },
      { &EV_SpawnFlags,                SpawnFlagsEvent },
      { &EV_SetTeam,                   SetTeamEvent },
      { &EV_Trigger,                   TriggerEvent },
      { &EV_Censor,                    Censor },
		{ &EV_Stationary,                StationaryEvent },
		{ &EV_Explosion,                 Explosion },
		{ &EV_ShaderEvent,               Shader },
		{ &EV_ScriptShaderEvent,         Shader },
		{ &EV_KillAttach,						KillAttach },
		{ &EV_DropToFloor,					DropToFloorEvent },
	   { &EV_Bind,				         	BindEvent },
	   { &EV_Unbind,				         EventUnbind },
	   { &EV_JoinTeam,         			JoinTeam },
	   { &EV_QuitTeam,			         EventQuitTeam },
	   { &EV_AddToSoundManager,         AddToSoundManager },
		{ &EV_SetControllerAngles,       SetControllerAngles },
		{ &EV_DeathSinkStart,				DeathSinkStart },
		{ &EV_DeathSink,						DeathSink },
		{ &EV_LookAtMe,						LookAtMe },
      { &EV_DetachAllChildren,         DetachAllChildren },
		{ &EV_Morph,							MorphEvent },
		{ &EV_Unmorph,							UnmorphEvent },
		{ &EV_MorphControl,					MorphControl },
		{ &EV_SetAnimOnAttachedModel,    SetAnimOnAttachedModel		},
		{ &EV_SetEntityExplosionModel,   SetEntityExplosionModel		},
		{ &EV_SetObjectProgram,          SetObjectProgram		},		
		{ &EV_ExecuteObjectProgram,      ExecuteProgram },
		{ &EV_SelfDetonate,              SelfDetonate		},

		{ &EV_Anim,								PassToAnimate },
		{ &EV_SetFrame,						PassToAnimate },
		{ &EV_StopAnimating,					PassToAnimate },
		{ &EV_Torso_StopAnimating,			PassToAnimate },
		{ &EV_NewAnim,							PassToAnimate },

		{ &EV_ProjectileAtk,					ProjectileAtk },
		{ &EV_TraceAtk,						TraceAtk },
		{ &EV_OnlyShootable,             OnlyShootable		},

		{ NULL, NULL }
	};

Entity::Entity()
	{
	Setup();
	}

Entity::Entity( int create_flag )
	{
	Setup();

	if ( create_flag & ENTITY_CREATE_FLAG_ANIMATE )
		animate = new Animate( this );

	if ( create_flag & ENTITY_CREATE_FLAG_MOVER )
		mover = new Mover( this );
	}

void Entity::Setup()
	{
	// Pluggable modules

	animate    = NULL;
	mover      = NULL;
	bind_info  = NULL;
	morph_info = NULL;

   edict = level.AllocEdict( this );
	client = edict->client;
	entnum = edict->s.number;
	edict->s.clientNum = ENTITYNUM_NONE ;

   // spawning variables
	spawnflags = level.spawnflags;
   level.spawnflags = 0;

	// rendering variables
	setAlpha( 1.0f );
	setScale( 1.0f );

	// physics variables
   total_delta             = "0 0 0";
	mass							= 0;
	gravity						= 1.0;
	groundentity				= NULL;
   groundcontents          = 0;
	velocity						= vec_zero;
	avelocity					= vec_zero;
   edict->clipmask         = MASK_SOLID;

   // bind variables
	edict->s.bindparent = ENTITYNUM_NONE;

   // this is an generic entity
   edict->s.eType = ET_GENERAL;

   setContents( 0 );

   edict->s.parent      = ENTITYNUM_NONE;
   edict->s.pos.trType  = TR_LERP;
   edict->ownerNum      = ENTITYNUM_NONE;

	setOrigin( vec_zero );
   origin.copyTo( edict->s.origin2 );

   setAngles( vec_zero );

	setMoveType( MOVETYPE_NONE );
	setSolidType( SOLID_NOT );

	// Character state
	health		= 0;
	max_health	= 0;
	deadflag		= DEAD_NO;
	flags			= 0;

	// underwater variables
	watertype		= 0;
	waterlevel		= 0;

	// Pain and damage variables
	takedamage				= DAMAGE_NO;
   damage_type          = -1;

   // Surface variables
   numsurfaces    = 0;

   // Light variables
   lightRadius    = 0;

	look_at_me = false;

	explosionModel = "";
	}

Entity::~Entity()
	{
   Container<Entity *> bindlist;
   Entity *ent;
   int num;
   int i;

	if ( bind_info )
		{
		// unbind any entities that are bound to me
		// can't unbind within this loop, so make an array
		// and unbind them outside of it.
		num = 0;

		for( ent = bind_info->teamchain; ent; ent = ent->bind_info->teamchain )
			{
			if ( ent->bind_info->bindmaster == this )
				{
				bindlist.AddObject( ent );
				}
			}

		num = bindlist.NumObjects();
		for( i = 1; i <= num; i++ )
			{
			bindlist.ObjectAt( i )->unbind();
			}

		bindlist.FreeObjectList();

		unbind();
		quitTeam();

		detach();

		//
		// go through and set our children
		//
		num = bind_info->numchildren;
		for( i = 0; ( i < MAX_MODEL_CHILDREN ) && num; i++ )
			{
			if ( bind_info->children[ i ] == ENTITYNUM_NONE )
				{
				continue;
				}
			ent = G_GetEntity( bind_info->children[ i ] );
			if ( ent )
				{
				ent->PostEvent( EV_Remove, 0 );
				}
			num--;
			}
		}

   if ( targetname.length() && world )
      {
		world->RemoveTargetEntity( targetname, this );
      }

   level.FreeEdict( edict );

	// Pluggable modules

	if ( animate )
		delete animate;

	if ( mover )
		delete mover;

	if ( bind_info )
		delete bind_info;

	if ( morph_info )
		delete morph_info;

	// Note, the ObjectProgram deletion is handled elsewhere
	}

void Entity::SetEntNum
   (
   int num
   )

   {
   if ( edict )
      {
      level.FreeEdict( edict );
      }

   level.spawn_entnum = num;
   level.AllocEdict( this );
	client = edict->client;
	entnum = edict->s.number;
   }

void Entity::ClassnameEvent
	(
	Event *ev
   )

   {
	strncpy( edict->entname, ev->GetString( 1 ), sizeof( edict->entname ) - 1 );
	}

void Entity::SpawnFlagsEvent
	(
	Event *ev
   )

   {
	// spawning variables
	spawnflags = ev->GetInteger( 1 );
   if ( spawnflags & SPAWNFLAG_DETAIL )
		{
      edict->s.renderfx |= RF_DETAIL;
		}
	}

void Entity::SetTarget
	(
	const char *text
	)

	{
   if ( text )
		{
      target = text;
		}
	else
		{
		target = "";
		}
	}

void Entity::SetTargetName
	(
	const char *text
	)

	{
   if ( targetname.length() && world )
      {
      world->RemoveTargetEntity( targetname, this );
      }

   if ( text )
		{
      if ( text[ 0 ] == '$' )
         text++;
      targetname = text;
		}
	else
		{
		targetname = "";
		}

   if ( targetname.length() && world )
		{
      //
      // make sure we don't re-targetname the world entity
      //
      if (
            ( this != world ) ||
            ( targetname == str( "world" ) )
         )
         {
         world->AddTargetEntity( targetname, this );
         }
      else
         {
         // this is bad
         assert( 0 );
         gi.WDPrintf( "world was re-targeted with targetname %s\n", targetname.c_str() );
         targetname = "world";
         }

		}
	}

void Entity::SetKillTarget
	(
	const char *text
	)

	{
   if ( text )
		{
      killtarget = text;
		}
	else
		{
		killtarget = "";
		}
	}

void Entity::setModel
	(
	const char *mdl
	)

	{
   str temp;

   if ( LoadingSavegame && ( this == world ) )
      {
      // don't set model on the world
      return;
      }

	if ( !mdl )
		{
		mdl = "";
		}

   // Prepend 'models/' to make things easier
   temp = "";
	if ( ( strlen( mdl ) > 0 ) && !strchr( mdl, '*' ) && strnicmp( "models/", mdl, 7 ) && !strstr( mdl, ".spr" ) )
		{
		temp = "models/";
		}
   temp += mdl;

   // we use a temp string so that if model was passed into here, we don't
   // accidentally free up the string that we're using in the process.
   model = temp;

	gi.setmodel( edict, model.c_str() );

   if ( gi.IsModel( edict->s.modelindex ) )
      {
  	   Event *ev;

      numsurfaces = gi.NumSurfaces( edict->s.modelindex );

      if ( !LoadingSavegame )
         {
		   CancelEventsOfType( EV_ProcessInitCommands );

         ev = new Event( EV_ProcessInitCommands );
         ev->AddInteger( edict->s.modelindex );
         PostEvent( ev, EV_PROCESS_INIT );
         }
      else
         {
         ProcessInitCommands( edict->s.modelindex, qtrue );
         }
      }
   else if ( strstr( mdl, ".spr" ) )
      {
      edict->s.eType = ET_SPRITE;
      }

	// Sanity check to see if we're expecting a B-Model
	assert( !( ( edict->solid == SOLID_BSP ) && !edict->s.modelindex ) );
	if ( ( edict->solid == SOLID_BSP ) && !edict->s.modelindex )
		{
      const char *name;

      name = getClassID();
      if ( !name )
         {
         name = getClassname();
         }
      gi.WDPrintf( "%s with SOLID_BSP and no model - '%s'(%d)\n", name, targetname.c_str(), entnum );

      // Make it non-solid so that the collision code doesn't kick us out.
      setSolidType( SOLID_NOT );
      }

	mins = edict->mins;
	maxs = edict->maxs;
   size = maxs - mins;
   edict->radius = size.length() * 0.5f;
	edict->radius2 = edict->radius * edict->radius;

   //
   // see if we have a mins and maxs set for this model
   //
   //FIXME
   //We only did this on startup, but with the spawnargs as events it would have to
   //be here.  Do we still need this?  It may cause strange effects.
   if ( gi.IsModel( edict->s.modelindex ) && !mins.length() && !maxs.length() )
      {
      vec3_t tempmins, tempmaxs;
      gi.CalculateBounds( edict->s.modelindex, edict->s.scale, tempmins, tempmaxs );
      setSize( tempmins, tempmaxs );
      }
	}

// Added to set the weapon view model
void Entity::setViewModel
	(
	const char *mdl
	)

	{
   str temp;

   if ( LoadingSavegame && ( this == world ) )
      {
      // don't set model on the world
      return;
      }

	if ( !mdl )
		{
		mdl = "";
		}

   // Prepend 'models/' to make things easier
   temp = "";
	if ( ( strlen( mdl ) > 0 ) && !strchr( mdl, '*' ) && strnicmp( "models/", mdl, 7 ) && !strstr( mdl, ".spr" ) )
		{
		temp = "models/";
		}
   temp += mdl;

   // we use a temp string so that if model was passed into here, we don't
   // accidentally free up the string that we're using in the process.
   model = temp;

	gi.setviewmodel( edict, model.c_str() );

   if ( gi.IsModel( edict->s.viewmodelindex ) )
      {
  	   Event *ev;

      numsurfaces = gi.NumSurfaces( edict->s.viewmodelindex );

      if ( !LoadingSavegame )
         {
		   CancelEventsOfType( EV_ProcessInitCommands );

         ev = new Event( EV_ProcessInitCommands );
         ev->AddInteger( edict->s.viewmodelindex );
         PostEvent( ev, EV_PROCESS_INIT );
         }
      else
         {
         ProcessInitCommands( edict->s.viewmodelindex, qtrue );
         }
      }
   else if ( strstr( mdl, ".spr" ) )
      {
      edict->s.eType = ET_SPRITE;
      }

	// Sanity check to see if we're expecting a B-Model
	assert( !( ( edict->solid == SOLID_BSP ) && !edict->s.viewmodelindex ) );
	if ( ( edict->solid == SOLID_BSP ) && !edict->s.viewmodelindex )
		{
      const char *name;

      name = getClassID();
      if ( !name )
         {
         name = getClassname();
         }
      gi.WDPrintf( "%s with SOLID_BSP and no model - '%s'(%d)\n", name, targetname.c_str(), entnum );

      // Make it non-solid so that the collision code doesn't kick us out.
      setSolidType( SOLID_NOT );
      }

	mins = edict->mins;
	maxs = edict->maxs;
   size = maxs - mins;
   edict->radius = size.length() * 0.5f;
	edict->radius2 = edict->radius * edict->radius;

   //
   // see if we have a mins and maxs set for this model
   //
   //FIXME
   //We only did this on startup, but with the spawnargs as events it would have to
   //be here.  Do we still need this?  It may cause strange effects.
   if ( gi.IsModel( edict->s.viewmodelindex ) && !mins.length() && !maxs.length() )
      {
      vec3_t tempmins, tempmaxs;
      gi.CalculateBounds( edict->s.viewmodelindex, edict->s.scale, tempmins, tempmaxs );
      setSize( tempmins, tempmaxs );
      }
	}

void Entity::ProcessInitCommands
	(
	int index,
   qboolean cache
	)

	{
   tiki_cmd_t cmds;

   if ( LoadingSavegame && !cache )
      {
      // Don't process init commands when loading a savegame since
      // it will cause items to be added to inventories unnecessarily.
      // All variables affected by the init commands will be set
      // by the unarchive functions.
      //
      // we do want to process the cache commands though regardless
      return;
      }

   if ( gi.InitCommands( index, &cmds ) )
      {
      int i, j, savedindex;
   	Event		*event;

      // because the model has not necessarily been spawned yet, we need to set
      // this entity to have this index so that precaches go where they are supposed
      // to, this should have no bad effects, since we are only doing it in the
      // cache phase of spawning
      if ( index != edict->s.modelindex )
         {
         savedindex = edict->s.modelindex;
         edict->s.modelindex = index;
         }
      else
         {
         savedindex = -1;
         }
      for( i = 0; i < cmds.num_cmds; i++ )
         {
      	event = new Event( cmds.cmds[ i ].args[ 0 ] );
         if ( !cache || ( event->GetFlags() & EV_CACHE ) )
            {
            for( j = 1; j < cmds.cmds[ i ].num_args; j++ )
               {
      		   event->AddToken( cmds.cmds[ i ].args[ j ] );
               }
            ProcessEvent( event );
            }
         else
            {
            delete event;
            }
         }
      // restore the modelindex, see above
      if ( savedindex != -1 )
         {
         edict->s.modelindex = savedindex;
         }
      }
	}

void Entity::ProcessInitCommandsEvent
	(
	Event *ev
	)

	{
   int index;

   index = ev->GetInteger( 1 );
   ProcessInitCommands( index, qfalse );
	}

void Entity::EventHideModel
	(
	Event *ev
	)

	{
	hideModel();
	}

void Entity::EventShowModel
	(
	Event *ev
	)

	{
	showModel();
	}

void Entity::SetTeamEvent
	(
	Event *ev
	)

	{
	if ( !bind_info )
		bind_info = CreateBindInfo();

   bind_info->moveteam = ev->GetString( 1 );
	}

void Entity::TriggerEvent
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
			event->SetSource( ev->GetSource() );
			event->SetThread( ev->GetThread() );
			event->SetLineNumber( ev->GetLineNumber() );
         event->AddEntity( this );
		   ent->ProcessEvent( event );
         }
      }
	else if ( name[ 0 ] == '*' )   // Check for entnum commands
      {
		if ( !IsNumeric( &name[ 1 ] ) )
			{
			ev->Error( "Expecting numeric value for * command, but found '%s'\n", &name[ 1 ] );
			}
		else
         {
         ent = G_GetEntity( atoi( &name[ 1 ] ) );
         if ( ent )
            {
            event = new Event( EV_Activate );
			   event->SetSource( ev->GetSource() );
			   event->SetThread( ev->GetThread() );
			   event->SetLineNumber( ev->GetLineNumber() );
            event->AddEntity( this );
            ent->ProcessEvent( event );
            }
         else
            {
            ev->Error( "Entity not found for * command\n" );
            }
         }
      return;
      }
	else
		{
		ev->Error( "Invalid entity reference '%s'.\n", name );
		}
	}

void Entity::setAlpha
	(
	float alpha
	)

	{
	if ( alpha > 1.0f )
		{
		alpha = 1.0f;
		}
	if ( alpha < 0 )
		{
		alpha = 0;
		}
   edict->s.alpha = alpha;
	}

void Entity::setScale
	(
	float scale
	)

	{
   edict->s.scale = scale;
	}

void Entity::setSolidType
	(
	solid_t type
	)

	{
	if (
         ( !LoadingSavegame ) &&
         ( type == SOLID_BSP ) &&
         ( this != world ) &&
         (
            !model.length() ||
            (
               ( model[ 0 ] != '*' ) &&
               ( !strstr( model.c_str(), ".bsp" ) )
            )
         )
      )
		{
      error( "setSolidType", "SOLID_BSP entity at x%.2f y%.2f z%.2f with no BSP model", origin[ 0 ], origin[ 1 ], origin[ 2 ] );
		}
	edict->solid = type;

   //
   // set the appropriate contents type
   if ( edict->solid == SOLID_BBOX )
      {
      if ( !getContents() )
   	   setContents( CONTENTS_SOLID );
      }
   else if ( edict->solid == SOLID_NOT )
      {
      if ( getContents() == CONTENTS_SOLID )
   	   setContents( 0 );
      }
   else if ( edict->solid == SOLID_BSP )
      {
      if ( !getContents() )
   	   setContents( CONTENTS_SOLID );
      }

	link();

	edict->svflags &= ~SVF_NOCLIENT;
	if ( hidden() )
		{
		edict->svflags |= SVF_NOCLIENT;
		}
	}

void Entity::setSize
	(
	Vector min,
	Vector max
	)

	{
   Vector delta;

   if ( flags & FL_ROTATEDBOUNDS )
      {
      vec3_t tempmins, tempmaxs;

      //
      // rotate the mins and maxs for the model
      //
	   min.copyTo( tempmins );
	   max.copyTo( tempmaxs );

      CalculateRotatedBounds2( edict->s.mat, tempmins, tempmaxs );

      mins = Vector( tempmins );
      maxs = Vector( tempmaxs );
	   size = max - min;

	   mins.copyTo( edict->mins );
	   maxs.copyTo( edict->maxs );
      edict->radius = size.length() * 0.5;
		edict->radius2 = edict->radius * edict->radius;
      }
   else
      {
      if ( ( min == edict->mins ) && ( max == edict->maxs ) )
         {
         return;
         }

	   mins = min;
	   maxs = max;
	   size = max - min;

	   mins.copyTo( edict->mins );
	   maxs.copyTo( edict->maxs );

      //
      // get the full mins and maxs for this model
      //
      if ( gi.IsModel( edict->s.modelindex ) )
         {
         vec3_t fullmins, fullmaxs;
         Vector delta;

         gi.CalculateBounds( edict->s.modelindex, edict->s.scale, fullmins, fullmaxs );

         delta = Vector( fullmaxs ) - Vector( fullmins );
         edict->radius = delta.length() * 0.5;
			edict->radius2 = edict->radius * edict->radius;
         }
      else
         {
         edict->radius = size.length() * 0.5;
			edict->radius2 = edict->radius * edict->radius;
         }
      }

	link();
	}

Vector Entity::getLocalVector
	(
	const Vector &vec
	)

	{
	Vector pos;

	pos[ 0 ] = vec * orientation[ 0 ];
	pos[ 1 ] = vec * orientation[ 1 ];
	pos[ 2 ] = vec * orientation[ 2 ];

	return pos;
	}

void Entity::link
	(
	void
	)

	{
	gi.linkentity( edict );
	absmin = edict->absmin;
	absmax = edict->absmax;
	centroid = ( absmin + absmax ) * 0.5;
	centroid.copyTo( edict->centroid );

   // If this has a parent, then set the areanum the same
   // as the parent's
   if ( edict->s.parent != ENTITYNUM_NONE )
      {
      edict->areanum = g_entities[ edict->s.parent ].areanum;
      }
	}

void Entity::addOrigin
	(
	const Vector &add
	)

   {
   setOrigin( localorigin + add );
   }

void Entity::setOrigin
	(
   void
	)

   {
   setOrigin( localorigin );
   }

void Entity::setOrigin
	(
	const Vector &org
	)

	{
   Entity * ent;
   int i,num;

	if ( bind_info && bind_info->bindmaster )
		{
      localorigin = org;

		if ( bind_info->bind_use_my_angles )
			MatrixTransformVector( localorigin, orientation, origin );
		else
			MatrixTransformVector( localorigin, bind_info->bindmaster->orientation, origin );

      origin += bind_info->bindmaster->origin;
      origin.copyTo( edict->s.netorigin );
		}
   // If entity has a parent, then set the origin as the
   // centroid of the parent, and set edict->s.netorigin
   // as the local origin of the entity which will be used
   // to position this entity on the client.
   else if ( edict->s.parent != ENTITYNUM_NONE )
      {
		orientation_t orient;

      VectorClear( edict->s.netorigin );
      ent = ( Entity * )G_GetEntity( edict->s.parent );

      //ent->GetTag(( edict->s.tag_num & TAG_MASK, &origin );
		ent->GetTag( edict->s.tag_num & TAG_MASK, &orient );

		MatrixTransformVector( edict->s.attach_offset, orient.axis, origin );

		//origin += edict->s.attach_offset;
		origin += orient.origin;

      localorigin = vec_zero;
      }
	else
		{
      origin = org;
      localorigin = org;
      origin.copyTo( edict->s.netorigin );
		}

   origin.copyTo( edict->s.origin );
   origin.copyTo( edict->currentOrigin );

	link();

#if 0
   if ( this->isClient() )
      {
      i = CurrentAnim();
      j = CurrentFrame();

      G_DrawCoordSystem( origin, orientation[0], orientation[1], orientation[2], 30 );
      gi.Printf( "%s:legs anim:%s frame %i\n", this->getClassname(), gi.Anim_NameForNum( edict->s.modelindex, i ), j );
      }
#endif

	if ( bind_info )
		{
		// Go through and set our children

		num = bind_info->numchildren;
		for( i = 0; ( i < MAX_MODEL_CHILDREN ) && num; i++ )
			{
			if ( bind_info->children[ i ] == ENTITYNUM_NONE )
				{
				continue;
				}
			ent = ( Entity * )G_GetEntity( bind_info->children[ i ] );
			ent->setOrigin();
			num--;
			}
		}
	}

void Entity::GetRawTag
	(
   int    tagnum,
   orientation_t * orient,
	bodypart_t part
	)

	{
   int anim;
   int frame;

   anim = CurrentAnim(part);
   frame = CurrentFrame(part);

   *orient = gi.Tag_Orientation( edict->s.modelindex, anim, frame, tagnum & TAG_MASK, edict->s.scale, edict->s.bone_tag, edict->s.bone_quat );
   }

qboolean Entity::GetRawTag
	(
	const char *name,
   orientation_t * orient,
	bodypart_t part
	)
	{
   int      tagnum;

   tagnum = gi.Tag_NumForName( edict->s.modelindex, name );

   if ( tagnum < 0 )
      return false;

   GetRawTag( tagnum, orient, part );
   return true;
   }

void Entity::GetTag
	(
   int    tagnum,
   orientation_t * orient
	)

	{
   orientation_t  or;
   int            i;

   GetRawTag( tagnum, &or );

   VectorCopy( origin, orient->origin );

   for ( i = 0 ; i < 3 ; i++ )
      {
		VectorMA( orient->origin, or.origin[i], orientation[i], orient->origin );
	   }
   MatrixMultiply( or.axis, orientation, orient->axis );
   }

qboolean Entity::GetTag
	(
	const char *name,
   orientation_t * orient
	)
	{
   int      tagnum;

   tagnum = gi.Tag_NumForName( edict->s.modelindex, name );

   if ( tagnum < 0 )
      return false;

   GetTag( tagnum, orient );
   return true;
   }

void Entity::GetTag
	(
   int    tagnum,
	Vector *pos,
	Vector *forward,
	Vector *left,
	Vector *up
	)

	{
   orientation_t or;

   GetTag( tagnum, &or );

	if ( pos )
		{
		*pos = Vector( or.origin );
		}
	if ( forward )
		{
		*forward = Vector( or.axis[ 0 ] );
		}
	if ( left )
		{
		*left = Vector( or.axis[ 1 ] );
		}
	if ( up )
		{
		*up = Vector( or.axis[ 2 ] );
		}
   }

qboolean Entity::GetTag
	(
	const char *name,
	Vector *pos,
	Vector *forward,
	Vector *left,
	Vector *up
	)

	{
   int      tagnum;

   tagnum = gi.Tag_NumForName( edict->s.modelindex, name );

   if ( tagnum < 0 )
      return false;

   GetTag( tagnum, pos, forward, left, up );
   return true;
   }

void Entity::addAngles
   (
   const Vector &add
   )

   {
   if ( bind_info && bind_info->bindmaster )
      {
      setAngles( localangles + add );
      }
   else
      {
      setAngles( angles + add );
      }
   }

void Entity::setAngles
	(
   void
   )

   {
   if ( bind_info && bind_info->bindmaster )
      {
      setAngles( localangles );
      }
   else
      {
      setAngles( angles );
      }
   }


void Entity::setAngles
	(
	const Vector &ang
	)

	{
   Entity * ent;
   int num,i;

	angles[ 0 ] = AngleMod( ang[ 0 ] );
	angles[ 1 ] = AngleMod( ang[ 1 ] );
	angles[ 2 ] = AngleMod( ang[ 2 ] );

   localangles = angles;
   if ( bind_info && bind_info->bindmaster )
      {
      float	mat[3][3];
		AnglesToAxis( localangles, mat );
		R_ConcatRotations( mat, bind_info->bindmaster->orientation, orientation );
      MatrixToEulerAngles( orientation, angles );
      }
   else
      {
      AnglesToAxis( angles, orientation );
      }

   angles.copyTo( edict->s.netangles );
   angles.copyTo( edict->s.angles );
   angles.copyTo( edict->currentAngles );
	// Fill the edicts matrix
	VectorCopy( orientation[ 0 ], edict->s.mat[ 0 ] );
	VectorCopy( orientation[ 1 ], edict->s.mat[ 1 ] );
	VectorCopy( orientation[ 2 ], edict->s.mat[ 2 ] );

	if (this->isSubclassOf( Player ) )
	{
		Player *player = (Player*)this ;
		player->GetVAngles().copyTo( edict->s.viewangles );
	}
	else
	{
		edict->s.viewangles[0] = 0.0f ;
		edict->s.viewangles[1] = 0.0f ;
		edict->s.viewangles[2] = 0.0f ;
	}

	if ( bind_info )
		{
		// Go through and set our children

		num = bind_info->numchildren;

		for( i = 0 ; (i < MAX_MODEL_CHILDREN) && num ; i++ )
			{
			if ( bind_info->children[i] == ENTITYNUM_NONE )
				continue;
			ent = ( Entity * )G_GetEntity( bind_info->children[i] );
			ent->setAngles();
			num--;
			}
		}
	}

qboolean Entity::droptofloor
	(
	float maxfall
	)

	{
	trace_t	trace;
	Vector	end;
   Vector   start;

   //start = origin + Vector( "0 0 1" );
	start = origin;
   end = origin;
	end[ 2 ]-= maxfall;

	trace = G_Trace( start, mins, maxs, end, this, edict->clipmask, false, "Entity::droptofloor" );
	if ( trace.fraction == 1 || trace.startsolid || trace.allsolid || !trace.ent )
		{
		groundentity = world->edict;
		return false;
		}

	setOrigin( trace.endpos );

	groundentity = trace.ent;

	return true;
	}

void Entity::DamageType
   (
   Event *ev
   )

   {
   str damage;
   damage = ev->GetString( 1 );
   if ( damage == "all" )
      {
      damage_type = -1;
      }
   else
      {
      damage_type = MOD_string_to_int( damage );
      }
   }

void Entity::Damage
   (
   Entity *inflictor,
   Entity *attacker,
   float damage,
   const Vector &position,
   const Vector &direction,
   const Vector &normal,
   int knockback,
   int dflags,
   int meansofdeath,
	int surface_number,
	int bone_number,
	float redemptivedamage
   )

   {
	Event	*ev;

   // if our damage types do not match, return
   if ( !MOD_matches( meansofdeath, damage_type ) )
      {
      return;
      }

	if ( !attacker )
		{
		attacker = world;
		}
	if ( !inflictor )
		{
		inflictor = world;
		}

	ev = new Event( EV_Damage );
	ev->AddFloat( damage );
	ev->AddEntity ( inflictor );
	ev->AddEntity ( attacker );
   ev->AddVector ( position );
   ev->AddVector ( direction );
   ev->AddVector ( normal );
   ev->AddInteger( knockback );
   ev->AddInteger( dflags );
   ev->AddInteger( meansofdeath );
	ev->AddInteger( surface_number );
	ev->AddInteger( bone_number );
	if ( redemptivedamage != 0.0f )
		ev->AddFloat( redemptivedamage );
   ProcessEvent  ( ev );
   }

void Entity::DamageEvent
	(
	Event *ev
	)

	{
	Entity	*inflictor;
	Entity	*attacker;
	int		damage;
	Vector	dir;
	Vector	momentum;
	Event		*event;
	float		m;

	if ( ( takedamage == DAMAGE_NO ) || ( movetype == MOVETYPE_NOCLIP ) )
		{
		return;
		}

	damage		= ev->GetInteger( 1 );
	inflictor	= ev->GetEntity( 2 );
	attacker		= ev->GetEntity( 3 );

	// figure momentum add
	if ( ( inflictor != world ) &&
		( movetype != MOVETYPE_NONE ) &&
		( movetype != MOVETYPE_STATIONARY ) &&
		( movetype != MOVETYPE_BOUNCE ) &&
		( movetype != MOVETYPE_PUSH ) &&
		( movetype != MOVETYPE_STOP ) )
		{
      dir = origin - ( inflictor->origin + ( inflictor->mins + inflictor->maxs ) * 0.5 );
		dir.normalize();

		if ( mass < 50)
			{
			m = 50;
			}
		else
			{
			m = mass;
			}

		momentum = dir * damage * ( 1700.0 / m );
		velocity += momentum;
		}

	// check for godmode or invincibility
	if ( flags & FL_GODMODE )
		{
		return;
		}

	// team play damage avoidance
	//if ( ( global->teamplay == 1 ) && ( edict->team > 0 ) && ( edict->team == attacker->edict->team ) )
	//	{
	//	return;
	//	}

   if ( !deathmatch->integer && isSubclassOf( Player ) )
      {
      damage *= 0.15;
      }

   if ( deadflag )
      {
      // Check for gib.
      if ( inflictor->isSubclassOf( Projectile ) )
         {
         Event *gibEv;

         health -= damage;

         gibEv = new Event( EV_Gib );
         gibEv->AddEntity( this );
         gibEv->AddFloat( health );
         ProcessEvent( gibEv );
         }
      return;
      }

	// do the damage
	health -= damage;
	if ( health <= 0 )
		{
      if ( attacker )
         {
		   event = new Event( EV_GotKill );
		   event->AddEntity( this );
		   event->AddInteger( damage );
		   event->AddEntity( inflictor );
         event->AddInteger( ev->GetInteger( 9 ) );
         event->AddInteger( 0 );
		   attacker->ProcessEvent( event );
         }

		event = new Event( EV_Killed );
		event->AddEntity( attacker );
		event->AddInteger( damage );
		event->AddEntity( inflictor );
		ProcessEvent( event );
		return;
		}

	event = new Event( EV_Pain );
	event->AddFloat( damage );
	event->AddEntity( attacker );
	ProcessEvent( event );
	}

void Entity::Stun
   (
   float time
   )

   {
   Event *ev = new Event( EV_Stun );
   ev->AddFloat( time );
   ProcessEvent( ev );
   }

/*
============
CanDamage

Returns true if the inflictor can directly damage the target.  Used for
explosions and melee attacks.
============
*/
qboolean Entity::CanDamage
	(
	Entity *target,
	Entity *skip_ent
	)

	{
	trace_t	trace;
	Vector	pos;
	Entity	*skip_entity;

	if ( skip_ent )
		skip_entity = skip_ent;
	else
		skip_entity = this;

   trace = G_Trace( origin, vec_origin, vec_origin, target->centroid, skip_entity, MASK_SHOT, false, "Entity::CanDamage 1" );
	if ( trace.fraction == 1 || trace.ent == target->edict )
		{
		return true;
		}
	pos = target->centroid + Vector( 15, 15, 0 );
   trace = G_Trace( origin, vec_origin, vec_origin, pos, skip_entity, MASK_SHOT, false, "Entity::CanDamage 3" );
	if ( trace.fraction == 1 || trace.ent == target->edict )
		{
		return true;
		}
	pos = target->centroid + Vector( -15, 15, 0 );
   trace = G_Trace( origin, vec_zero, vec_zero, pos, skip_entity, MASK_SHOT, false, "Entity::CanDamage 4" );
	if ( trace.fraction == 1 || trace.ent == target->edict )
		{
		return true;
		}
	pos = target->centroid + Vector( 15, -15, 0 );
   trace = G_Trace( origin, vec_zero, vec_zero, pos, skip_entity, MASK_SHOT, false, "Entity::CanDamage 5" );
	if ( trace.fraction == 1 || trace.ent == target->edict )
		{
		return true;
		}
  	pos = target->centroid + Vector( -15, -15, 0 );
   trace = G_Trace( origin, vec_zero, vec_zero, pos, skip_entity, MASK_SHOT, false, "Entity::CanDamage 6" );
	if ( trace.fraction == 1 || trace.ent == target->edict )
		{
		return true;
		}

	return false;
	}

qboolean Entity::IsTouching
	(
	Entity *e1
	)

	{
	if ( e1->absmin.x > absmax.x )
		{
		return false;
		}
	if ( e1->absmin.y > absmax.y )
		{
		return false;
		}
	if ( e1->absmin.z > absmax.z )
		{
		return false;
		}
	if ( e1->absmax.x < absmin.x )
		{
		return false;
		}
	if ( e1->absmax.y < absmin.y )
		{
		return false;
		}
	if ( e1->absmax.z < absmin.z )
		{
		return false;
		}

	return true;
	}

void Entity::FadeNoRemove
	(
	Event *ev
	)

	{
   float rate;
   float target;
   float myalpha;

   if ( ev->NumArgs() > 1 )
      {
      target = ev->GetFloat( 2 );
      }
   else
      {
      target = 0;
      }

   if ( ev->NumArgs() > 0 )
      {
      rate = ev->GetFloat( 1 );
      assert( rate );
      if ( rate > 0 )
         rate = FRAMETIME / rate;
      }
   else
      {
      rate = 0.03;
      }

   myalpha = edict->s.alpha;
   myalpha -= rate;

   if ( myalpha < target )
      myalpha = target;

   setAlpha( myalpha );

   if ( myalpha > target )
      {
      PostEvent( *ev, FRAMETIME );
      }

   G_SetConstantLight( &edict->s.constantLight, &myalpha, &myalpha, &myalpha, 0 );
	}

void Entity::FadeOut
	(
	Event *ev
	)

	{
   float myscale;
   float myalpha;

   myscale = edict->s.scale;
   myscale -= 0.03f;
   myalpha = edict->s.alpha;
   myalpha -= 0.03f;
   if ( myscale < 0 )
      myscale = 0;
   if ( myalpha < 0 )
      myalpha = 0;

	if ( myscale <= 0 && myalpha <= 0 )
		{
	   PostEvent( EV_Remove, 0 );
		}
   else
      {
	   PostEvent( *ev, FRAMETIME );
      }

   setScale( myscale );
   setAlpha( myalpha );
	}

void Entity::FadeIn
	(
	Event *ev
	)

	{
   float rate;
   float target;
   float myalpha;

   if ( ev->NumArgs() > 1 )
      {
      target = ev->GetFloat( 2 );
      }
   else
      {
      target = 1;
      }

   if ( ev->NumArgs() > 0 )
      {
      rate = ev->GetFloat( 1 );
      assert( rate );
      if ( rate > 0 )
         rate = FRAMETIME / rate;
      }
   else
      {
      rate = 0.03;
      }


   myalpha = edict->s.alpha;
   myalpha += rate;

   if ( myalpha > target )
      myalpha = target;

   if ( myalpha < target )
		{
   	PostEvent( *ev, FRAMETIME );
		}
   setAlpha( myalpha );
	}

void Entity::Fade
	(
	Event *ev
	)

	{
   float rate;
   float target;
   float myalpha;

   if ( ev->NumArgs() > 1 )
      {
      target = ev->GetFloat( 2 );
      }
   else
      {
      target = 0;
      }

   if ( ev->NumArgs() > 0 )
      {
      rate = ev->GetFloat( 1 );
      assert( rate );
      if ( rate > 0 )
         rate = FRAMETIME / rate;
      }
   else
      {
      rate = 0.03;
      }

   myalpha = edict->s.alpha;
   myalpha -= rate;

   if ( myalpha <= 0 )
		{
	   PostEvent( EV_Remove, 0 );
      return;
		}

   if ( myalpha < target )
      myalpha = target;

   if ( myalpha > target )
      {
      PostEvent( *ev, FRAMETIME );
      }

   setAlpha( myalpha );
   G_SetConstantLight( &edict->s.constantLight, &myalpha, &myalpha, &myalpha, 0 );
	}

void Entity::SetMassEvent
	(
	Event *ev
	)

	{
   mass = ev->GetFloat( 1 );
	}

void Entity::CheckGround
	(
   void
	)

	{
	Vector	point;
	trace_t	trace;

	if ( flags & ( FL_SWIM | FL_FLY ) )
		{
		return;
		}

	if ( velocity.z > 100 )
		{
		groundentity = NULL;
		return;
		}

	// if the hull point one-quarter unit down is solid the entity is on ground
   point = origin;
	point.z -= 0.25;
   trace = G_Trace( origin, mins, maxs, point, this, edict->clipmask, false, "Entity::CheckGround" );

	// check steepness
	if ( ( trace.plane.normal[ 2 ] <= 0.7 ) && !trace.startsolid )
		{
		groundentity = NULL;
		return;
		}

	groundentity = trace.ent;
	groundplane = trace.plane;
	groundcontents = trace.contents;

	if ( !trace.startsolid && !trace.allsolid )
		{
		setOrigin( trace.endpos );
		velocity.z = 0;
		}
	}

void Entity::BecomeSolid
	(
	Event *ev
	)

	{
	if ( ( model.length() ) && ( ( model[ 0 ] == '*' ) || ( strstr( model.c_str(), ".bsp" ) ) ) )
		{
		setSolidType( SOLID_BSP );
		}
	else
		{
		setSolidType( SOLID_BBOX );
		}
	}

void Entity::BecomeNonSolid
	(
	Event *ev
	)

	{
	setSolidType( SOLID_NOT );
	}

void Entity::Ghost
	(
	Event *ev
	)

	{
   // Make not solid, but send still send over whether it is hidden or not
	setSolidType( SOLID_NOT );
   edict->svflags &= ~SVF_NOCLIENT;
	}

void Entity::LoopSound
	(
	Event *ev
	)

	{
	str sound_name;
	float volume   = DEFAULT_VOL;
	float min_dist = DEFAULT_MIN_DIST;
	str min_dist_string;


	if (ev->NumArgs() < 1)
		return;

	// Get parameters

	sound_name = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		volume = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		{
		min_dist_string = ev->GetString( 3 );

		if ( min_dist_string == LEVEL_WIDE_STRING )
			min_dist = LEVEL_WIDE_MIN_DIST;
		else
			min_dist = ev->GetFloat( 3 );
		}

	// Add this sound to loop

	LoopSound( sound_name.c_str(), volume, min_dist );
	}

void Entity::LoopSound( const str &sound_name, float volume, float min_dist )
	{
	const char *name = NULL;
	str random_alias;


	// Get the real sound to be played

	if ( sound_name.length() > 0 )
		{
		// Get the real sound to play

		name = gi.GlobalAlias_FindRandom( sound_name.c_str() );

		if ( !name )
			{
			random_alias = GetRandomAlias( sound_name ).c_str();

			if ( random_alias.length() > 0 )
				name = random_alias.c_str();
			}

		if ( !name )
			name = sound_name.c_str();

		// Add the looping sound to the entity

      edict->s.loopSound        = gi.soundindex( name );
		edict->s.loopSoundVolume  = volume;
		edict->s.loopSoundMinDist = min_dist;
		}
	}

void Entity::StopLoopSound( Event *ev )
	{
   StopLoopSound();
	}

void Entity::StopLoopSound( void )
	{
   edict->s.loopSound = 0;
	}

void Entity::Sound( Event *ev )
	{
	str sound_name;
	float volume;
   int channel;
   float min_dist;
   int i;
	str min_dist_string;


   // Set defaults

   volume   = DEFAULT_VOL;
	min_dist = DEFAULT_MIN_DIST;
   channel  = CHAN_BODY;

	// Get sound parameters

   for ( i = 1 ; i <= ev->NumArgs() ; i++ )
      {
      switch (i-1)
         {
         case 0:
            sound_name = ev->GetString( i );
            break;
         case 1:
            channel = ev->GetInteger( i );
            break;
			case 2:
            volume = ev->GetFloat( i );
            break;
         case 3:
				min_dist_string = ev->GetString( i );

				if ( min_dist_string == LEVEL_WIDE_STRING )
					min_dist = LEVEL_WIDE_MIN_DIST;
				else
					min_dist = ev->GetFloat( i );
            break;
         default:
            break;
         }
      }

	Sound( sound_name, channel, volume, min_dist, NULL );
	}

void Entity::StopSound
	(
	Event *ev
	)

	{
   if (ev->NumArgs() < 1)
      StopSound( CHAN_BODY );
   else
      StopSound( ev->GetInteger( 1 ) );
	}

void Entity::StopSound
	(
	int channel
	)

	{
	gi.StopSound( entnum, channel );
	}

void Entity::SetLight
	(
	Event *ev
	)

	{
   float r, g, b;

   if ( ev->NumArgs() == 1 )
      {
      Vector tmp;

      tmp = ev->GetVector( 1 );
      r = tmp.x;
      g = tmp.y;
      b = tmp.z;
      }
   else
      {
      r = ev->GetFloat( 1 );
      g = ev->GetFloat( 2 );
      b = ev->GetFloat( 3 );
      lightRadius  = ev->GetFloat( 4 );
      }

   G_SetConstantLight( &edict->s.constantLight, &r, &g, &b, &lightRadius );
   }

void Entity::LightOn
	(
	Event *ev
	)

	{
   G_SetConstantLight( &edict->s.constantLight, NULL, NULL, NULL, &lightRadius );
   }

void Entity::LightOff
	(
	Event *ev
	)

	{
   float radius = 0;

   G_SetConstantLight( &edict->s.constantLight, NULL, NULL, NULL, &radius );
   }

void Entity::LightRed
	(
	Event *ev
	)

	{
   float r;

   r = ev->GetFloat( 1 );
   G_SetConstantLight( &edict->s.constantLight, &r, NULL, NULL, NULL );
   }

void Entity::LightGreen
	(
	Event *ev
	)

	{
   float g;

   g = ev->GetFloat( 1 );
   G_SetConstantLight( &edict->s.constantLight, NULL, &g, NULL, NULL );
   }

void Entity::LightBlue
	(
	Event *ev
	)

	{
   float b;

   b = ev->GetFloat( 1 );
   G_SetConstantLight( &edict->s.constantLight, NULL, NULL, &b, NULL );
   }

void Entity::LightRadius
	(
	Event *ev
	)

	{
   lightRadius = ev->GetFloat( 1 );
   G_SetConstantLight( &edict->s.constantLight, NULL, NULL, NULL, &lightRadius );
   }

void Entity::LightStyle
	(
	Event *ev
	)

	{
   int style;

   style = ev->GetInteger( 1 );
   G_SetConstantLight( &edict->s.constantLight, NULL, NULL, NULL, NULL, &style );
   }

void Entity::SetHealth
	(
	Event *ev
	)

	{
	health = ev->GetFloat( 1 );
   if( max_health < health )
		{
		max_health = health;
		}
	
	}

void Entity::GetHealth
	(
	Event *ev
	)

	{
	ev->ReturnFloat( health );
	}

void Entity::SetMaxHealth 
	(
	Event *ev
	)
	{
	max_health = ev->GetFloat( 1 );
	}

void Entity::SetSize
	(
	Event *ev
	)

	{
	Vector min, max;

   min = ev->GetVector( 1 );
   max = ev->GetVector( 2 );
   setSize( min, max );
   }

void Entity::SetMins
	(
	Event *ev
	)

	{
	Vector min;

   min = ev->GetVector( 1 );
   setSize( min, maxs );
   }

void Entity::SetMaxs
	(
	Event *ev
	)

	{
	Vector max;

   max = ev->GetVector( 1 );
   setSize( mins, max );
   }

void Entity::SetScale
	(
	Event *ev
	)

	{
	setScale( ev->GetFloat( 1 ) );
   }

void Entity::SetAlpha
	(
	Event *ev
	)

	{
	setAlpha( ev->GetFloat( 1 ) );
   }

void Entity::SetOrigin
	(
	Event *ev
	)

	{
	setOrigin( ev->GetVector( 1 ) );
	}

void Entity::GetOrigin
	(
	Event *ev
	)

	{
	ev->ReturnVector( origin );
	}

void Entity::SetTargetName
	(
	Event *ev
	)

	{
	SetTargetName( ev->GetString( 1 ) );
	}

void Entity::SetTarget
	(
	Event *ev
	)

	{
	SetTarget( ev->GetString( 1 ) );
	}

void Entity::SetKillTarget
	(
	Event *ev
	)

	{
	SetKillTarget( ev->GetString( 1 ) );
	}

void Entity::SetAngles
	(
	Event *ev
	)

	{
	setAngles( ev->GetVector( 1 ) );
	}

Vector Entity::GetControllerAngles
	(
	int num
	)

	{
	Vector controller_angles;

   assert( ( num >= 0 ) && ( num < NUM_BONE_CONTROLLERS ) );

   if ( ( num < 0 ) || ( num >= NUM_BONE_CONTROLLERS ) )
      {
      error( "GetControllerAngles", "Bone controller index out of range (%d)\n", num );
      return vec_zero;
      }

	controller_angles = edict->s.bone_angles[ num ];

   return controller_angles;
   }

void Entity::SetControllerAngles
	(
	int num,
   vec3_t angles
	)

	{
   assert( ( num >= 0 ) && ( num < NUM_BONE_CONTROLLERS ) );

   if ( ( num < 0 ) || ( num >= NUM_BONE_CONTROLLERS ) )
      {
      error( "SetControllerAngles", "Bone controller index out of range (%d)\n", num );
      return;
      }

   VectorCopy( angles, edict->s.bone_angles[ num ] );
   EulerToQuat( edict->s.bone_angles[ num ], edict->s.bone_quat[ num ] );
   }

void Entity::SetControllerAngles
	(
	Event *ev
	)

	{
	int num;
   Vector angles;

	if ( ev->NumArgs() < 2 )
		return;

	num = ev->GetInteger( 1 );
	angles = ev->GetVector( 2 );

	SetControllerAngles( num, angles );
   }

void Entity::SetControllerTag
	(
	int num,
   int tag_num
	)

	{
   assert( ( num >= 0 ) && ( num < NUM_BONE_CONTROLLERS ) );

   if ( ( num < 0 ) || ( num >= NUM_BONE_CONTROLLERS ) )
      {
      error( "SetControllerTag", "Bone controller index out of range (%d)\n", num );
      return;
      }

   edict->s.bone_tag[ num ] = tag_num;
   }

void Entity::RegisterAlias
	(
	Event *ev
	)

	{
	char parameters[100];
	int i;

	// Get the parameters for this alias command

	parameters[0] = 0;

	for( i = 3 ; i <= ev->NumArgs() ; i++ )
	{
		strcat( parameters, ev->GetString( i ) );
		strcat( parameters, " ");
	}

   gi.Alias_Add( edict->s.modelindex, ev->GetString( 1 ), ev->GetString( 2 ),  parameters );
	}

void Entity::Cache
	(
	Event *ev
	)

	{
   CacheResource( ev->GetString( 1 ), this );
   }

void Entity::RegisterAliasAndCache
	(
	Event *ev
	)

	{
	RegisterAlias(ev);

   CacheResource( ev->GetString( 2 ), this );
	}

void Entity::Sound
	(
	const str &sound_name,
   int   channel,
	float volume,
   float min_dist,
	Vector *sound_origin
	)
	{
	const char *name = NULL;
	vec3_t org;
	str random_alias;


	if ( sound_name.length() > 0 )
		{
		// Get the real sound to play

		name = gi.GlobalAlias_FindRandom( sound_name.c_str() );

		if ( !name )
			{
			random_alias = GetRandomAlias( sound_name ).c_str();

			if ( random_alias.length() > 0 )
				name = random_alias.c_str();
			}

		if ( !name )
			name = sound_name.c_str();

		// Play the sound

		if ( name != NULL )
			{
			if ( sound_origin != NULL)
				{
				sound_origin->copyTo( org );
				entnum = ENTITYNUM_NONE;
				}
			else
				{
				VectorCopy( edict->s.origin, org );
				}

			gi.Sound( &org, entnum, channel, name, volume, min_dist );
			}
		}
	else
		{
		warning( "Sound", "Null sample pointer" );
		}
	}

qboolean Entity::attach
	(
   int parent_entity_num,
   int tag_num,
	qboolean use_angles,
	Vector offset,
	Vector angles_offset
	)

	{
   int i;
   Entity * parent;

   if ( entnum == parent_entity_num )
      {
      warning("attach","Trying to attach to oneself." );
      return false;
      }

   if ( edict->s.parent != ENTITYNUM_NONE )
      detach();

   //
   // make sure this is a modelanim entity so that the attach works properly
   //
   if ( edict->s.eType == ET_GENERAL )
      {
      edict->s.eType = ET_MODELANIM;
      }

   //
   // get the parent
   //
   parent = ( Entity * )G_GetEntity( parent_entity_num );

	if ( !parent->bind_info )
		parent->bind_info = CreateBindInfo();

   if (parent->bind_info->numchildren < MAX_MODEL_CHILDREN)
      {
      //
      // find a free spot in the parent
      //
      for ( i=0; i < MAX_MODEL_CHILDREN; i++ )
         if ( parent->bind_info->children[i] == ENTITYNUM_NONE )
            {
            break;
            }
      edict->s.parent = parent_entity_num;
      setSolidType( SOLID_NOT );
      parent->bind_info->children[i] = entnum;
      parent->bind_info->numchildren++;
      edict->s.tag_num = tag_num;
		edict->s.attach_use_angles = use_angles;
		offset.copyTo( edict->s.attach_offset );
		angles_offset.copyTo( edict->s.attach_angles_offset );
      setOrigin();
      return true;
      }
   return false;
	}

void Entity::KillAttach
	(
	Event *ev
	)

	{
   int i;
	Entity *child = NULL;


	if ( bind_info )
		{
		// Kill all of this entities children

		for ( i = 0 ; i < MAX_MODEL_CHILDREN; i++ )
			{
			if ( bind_info->children[i] != ENTITYNUM_NONE )
				{
				// Remove child
				child = ( Entity * )G_GetEntity( bind_info->children[i] );

				if ( child )
					child->ProcessEvent( EV_Remove );

				// Remove child from this entity
				bind_info->children[i] = ENTITYNUM_NONE;
				}
			}

		bind_info->numchildren = 0;
		}
	}

void Entity::detach
	(
	void
	)

	{
   int i;
   int num;
   Entity * parent;

   if ( edict->s.parent == ENTITYNUM_NONE )
      return;

   parent = ( Entity * )G_GetEntity( edict->s.parent );

   if (!parent)
      return;

	if ( parent->bind_info)
		{
		for ( i=0,num = parent->bind_info->numchildren; i < MAX_MODEL_CHILDREN; i++ )
			{
			if ( parent->bind_info->children[i] == ENTITYNUM_NONE )
				{
				continue;
				}
			if (parent->bind_info->children[i] == entnum)
				{
				parent->bind_info->children[i] = ENTITYNUM_NONE;
				parent->bind_info->numchildren--;
				break;
				}
			num--;
			if (!num)
				break;
			}
		}

   edict->s.parent = ENTITYNUM_NONE;
   setOrigin( origin );
	}

void Entity::Flags( Event *ev )
   {
   const char *flag;
   int mask;
   int action;
   int i;

   for ( i = 1; i <= ev->NumArgs(); i++ )
      {
      action = FLAG_IGNORE;
      flag = ev->GetString( i );
      switch( flag[0] )
         {
         case '+':
            action = FLAG_ADD;
            flag++;
            break;
         case '-':
            action = FLAG_CLEAR;
            flag++;
            break;
         default:
            ev->Error( "Entity::Flags", "First character is not '+' or '-', assuming '+'\n" );
            action = FLAG_ADD;
            break;
         }

      //
      // WARNING: please change the Event decleration,
      // to match this function, if flags are added or
      // deleted the event must be updated.
      //
      if ( !stricmp( flag, "blood" ) )
         mask = FL_BLOOD;
      else if ( !stricmp( flag, "explode" ) )
         mask = FL_DIE_EXPLODE;
      else if ( !stricmp( flag, "die_gibs" ) )
         mask = FL_DIE_GIBS;
      else if ( !stricmp( flag, "autoaim" ) )
         mask = FL_AUTOAIM;
      else if ( !stricmp( flag, "god" ) )
         mask = FL_GODMODE;
      else
         {
         mask = 0;
         action = FLAG_IGNORE;
         ev->Error( "Unknown flag '%s'", flag );
         }
      switch (action)
         {
         case FLAG_ADD:
            flags |= mask;
            break;
         case FLAG_CLEAR:
            flags &= ~mask;
            break;
         case FLAG_IGNORE:
            break;
         }
      }
   if ( !com_blood->integer )
      {
      if ( flags & (FL_BLOOD|FL_DIE_GIBS) )
         {
         flags &= ~FL_BLOOD;
         flags &= ~FL_DIE_GIBS;
         }
      }
   }


void Entity::Effects( Event *ev )
   {
   const char *flag;
   int mask=0;
   int action;
   int i;

   for ( i = 1; i <= ev->NumArgs(); i++ )
      {
      action = 0;
      flag = ev->GetString( i );
      switch( flag[0] )
         {
         case '+':
            action = FLAG_ADD;
            flag++;
            break;
         case '-':
            action = FLAG_CLEAR;
            flag++;
            break;
         default:
            ev->Error( "Entity::Effects", "First character is not '+' or '-', assuming '+'\n" );
            action = FLAG_ADD;
            break;
         }

      //
      // WARNING: please change the Event decleration,
      // to match this function, if flags are added or
      // deleted the event must be updated.
      //
      if ( !stricmp( flag, "everyframe" ) )
         mask = EF_EVERYFRAME;
      else
         {
         action = FLAG_IGNORE;
         ev->Error( "Unknown token %s.", flag );
         }

      switch (action)
         {
         case FLAG_ADD:
            edict->s.eFlags |= mask;
            break;
         case FLAG_CLEAR:
            edict->s.eFlags &= ~mask;
            break;
         case FLAG_IGNORE:
            break;
         }
      }
   }

void Entity::RenderEffects( Event *ev )
   {
   const char *flag;
   int mask=0;
   int action;
   int i;

   for ( i = 1; i <= ev->NumArgs(); i++ )
      {
      action = 0;
      flag = ev->GetString( i );
      switch( flag[0] )
         {
         case '+':
            action = FLAG_ADD;
            flag++;
            break;
         case '-':
            action = FLAG_CLEAR;
            flag++;
            break;
         default:
            ev->Error( "Entity::RenderEffects", "First character is not '+' or '-', assuming '+'\n" );
            action = FLAG_ADD;
            break;
         }

      //
      // WARNING: please change the Event decleration,
      // to match this function, if flags are added or
      // deleted the event must be updated.
      //
      if ( !stricmp( flag, "dontdraw" ) )
         mask = RF_DONTDRAW;
      else if ( !stricmp( flag, "betterlighting" ) )
         mask = RF_EXTRALIGHT;
      else if ( !stricmp ( flag, "lensflare" ) )
         mask = RF_LENSFLARE;
      else if ( !stricmp ( flag, "viewlensflare" ) )
         mask = RF_VIEWLENSFLARE;
      else if ( !stricmp ( flag, "lightoffset" ) )
         mask = RF_LIGHTOFFSET;
      else if ( !stricmp( flag, "skyorigin" ) )
         mask = RF_SKYORIGIN;
      else if ( !stricmp( flag, "fullbright" ) )
         mask = RF_FULLBRIGHT;
      else if ( !stricmp( flag, "minlight" ) )
         mask = RF_MINLIGHT;
      else if ( !stricmp( flag, "additivedynamiclight" ) )
         mask = RF_ADDITIVE_DLIGHT;
      else if ( !stricmp( flag, "lightstyledynamiclight" ) )
         mask = RF_LIGHTSTYLE_DLIGHT;
      else if ( !stricmp( flag, "shadow" ) )
         mask = RF_SHADOW;
      else if ( !stricmp( flag, "preciseshadow" ) )
         mask = RF_SHADOW_PRECISE;
      else if ( !stricmp( flag, "invisible" ) )
         mask = RF_INVISIBLE;
      else
         {
         action = FLAG_IGNORE;
         ev->Error( "Unknown token %s.", flag );
         }

      switch (action)
         {
         case FLAG_ADD:
            edict->s.renderfx |= mask;
            break;
         case FLAG_CLEAR:
            edict->s.renderfx &= ~mask;
            break;
         case FLAG_IGNORE:
            break;
         }
      }
   }

void Entity::SVFlags
   (
   Event *ev
   )

   {
   const char *flag;
   int mask=0;
   int action;
   int i;

   for ( i = 1; i <= ev->NumArgs(); i++ )
      {
      action = 0;
      flag = ev->GetString( i );
      switch( flag[0] )
         {
         case '+':
            action = FLAG_ADD;
            flag++;
            break;
         case '-':
            action = FLAG_CLEAR;
            flag++;
            break;
         default:
            ev->Error( "Entity::SVFlags", "First character is not '+' or '-', assuming '+'\n" );
            action = FLAG_ADD;
            break;
         }

      //
      // WARNING: please change the Event decleration,
      // to match this function, if flags are added or
      // deleted the event must be updated.
      //
      if ( !stricmp( flag, "broadcast" ) )
         mask = SVF_BROADCAST;
      else if ( !stricmp( flag, "sendonce" ) )
         mask = SVF_SENDONCE;
      else
         {
         action = FLAG_IGNORE;
         ev->Error( "Unknown token %s.", flag );
         }

      switch (action)
         {
         case FLAG_ADD:
            edict->svflags |= mask;
            break;
         case FLAG_CLEAR:
            edict->svflags &= ~mask;
            break;
         case FLAG_IGNORE:
            break;
         }
      }

   if ( edict->svflags & SVF_SENDONCE )
      {
      // Turn this entity into an event if the SENDONCE flag is sent
      edict->s.eType = ET_EVENTS;
      }
   }

void Entity::BroadcastSound
	(
	float rad,
	int soundType	//Defaults to SOUNDTYPE_GENERAL
	)

	{
	if ( !( this->flags & FL_NOTARGET ) )
		{
      G_BroadcastSound( this, centroid, rad, soundType );
      }
	}

void Entity::BroadcastSound
	(
	Event *ev
	)

	{
   float rad		  = SOUND_RADIUS;
	int soundTypeIdx = SOUNDTYPE_GENERAL;
	str soundTypeStr = "";
		
	if ( !( this->flags & FL_NOTARGET ) )
		{
		
		if (ev->NumArgs() > 0 )	//<-- At least 1 Parameter
			{
			rad = ev->GetFloat( 1 );

			if(ev->NumArgs() > 1 )	//<-- At least 2 Parameters
				{
				soundTypeStr = ev->GetString( 2 );			
				soundTypeIdx = Soundtype_string_to_int( soundTypeStr );	
				}
			}
		
		if (soundTypeIdx == SOUNDTYPE_FOOTSTEPS_RUN || soundTypeIdx == SOUNDTYPE_FOOTSTEPS_WALK )
			rad = ModifyFootstepSoundRadius( rad , soundTypeIdx );


		BroadcastSound( rad, soundTypeIdx );
      }
	}

float Entity::ModifyFootstepSoundRadius
   (
	float radius,
	int soundTypeIdx
	)

	{
	trace_t	trace;
	Vector	end;
   Vector   start;

   start = origin; 
   end = origin;
	end[2]-= 1000;
	int surftype;

	trace = G_Trace( start, mins, maxs, end, this, edict->clipmask, false, "Entity::ModifyFootstepsRadius" );
	surftype = trace.surfaceFlags & MASK_SURF_TYPE;
	
	switch ( surftype )
		{
      case SURF_TYPE_WOOD:
	        radius *= 2.5;
			  break;

      case SURF_TYPE_METAL:
			  radius *= 5;
	        break;

      case SURF_TYPE_ROCK:
			  break;

      case SURF_TYPE_DIRT:
           radius *= .5;
			  break;

      case SURF_TYPE_GRILL:
           radius *= 2.5;
			  break;

      case SURF_TYPE_ORGANIC:
           radius *= .5;
			  break;

      case SURF_TYPE_SQUISHY:
           radius *= .5;
			  break;
      }
	
	//Tone Radius Down for Walking
	if (soundTypeIdx == SOUNDTYPE_FOOTSTEPS_WALK )
		radius *= .75;

	return radius;
	}

void Entity::Think
	(
	void
	)

	{
	}

void Entity::SetWaterType
   (
   void
   )

   {
   qboolean isinwater;

   watertype = gi.pointcontents( origin, 0 );
	isinwater = watertype & MASK_WATER;

	if ( isinwater )
		{
		waterlevel = 1;
		}
	else
		{
		waterlevel = 0;
		}
   }

void Entity::DamageSkin
   (
   trace_t * trace,
   float damage
   )

   {
   /* FIXME : Do we need damage skins?
   int surface;

   // FIXME handle different bodyparts
   surface = trace->intersect.surface;
   if ( !edict->s.surfaces[ surface ] )
		{
      edict->s.surfaces[ surface ]++;
		}
   */
   }

void Entity::Kill
	(
	Event *ev
	)

	{
	health = 0;
   Damage( this, this, 10, origin, vec_zero, vec_zero, 0, 0, MOD_SUICIDE );
	}


void Entity::SurfaceCommand
	(
   const char * surf_name,
   const char * token
	)

	{
	const char * current_surface_name;
   int surface_num;
   int mask;
   int action;
   qboolean do_all = false;
	qboolean mult = false;


	if ( surf_name[ strlen( surf_name ) - 1 ] == '*' )
		{
		mult = true;
		surface_num = 0;
		}
	else if ( str( surf_name ) != str( "all" ) )
      {
      surface_num = gi.Surface_NameToNum( edict->s.modelindex, surf_name );

      if (surface_num < 0)
         {
		   warning( "SurfaceCommand", "group %s not found.", surf_name );
         return;
         }
      }
   else
      {
      surface_num = 0;
      do_all = true;
      }

   action = 0;
   switch( token[0] )
      {
      case '+':
         action = FLAG_ADD;
         token++;
         break;
      case '-':
         action = FLAG_CLEAR;
         token++;
         break;
      default:
         warning( "Entity::SurfaceModelEvent", "First character is not '+' or '-', assuming '+'\n" );
         action = FLAG_ADD;
         break;
      }
   //
   // WARNING: please change the Event decleration,
   // to match this function, if flags are added or
   // deleted the event must be updated.
   //
   if (!strcmpi( token, "skin1"))
      {
      mask = MDL_SURFACE_SKINOFFSET_BIT0;
      }
   else if (!strcmpi (token, "skin2"))
      {
      mask = MDL_SURFACE_SKINOFFSET_BIT1;
      }
   else if (!strcmpi (token, "nodraw"))
      {
      mask = MDL_SURFACE_NODRAW;
      }
   else if (!strcmpi (token, "crossfade"))
      {
      mask = MDL_SURFACE_CROSSFADE_SKINS;
      }
   else
      {
      mask = 0;
      warning( "SurfaceCommand", "Unknown token %s.", token );
      action = FLAG_IGNORE;
      }
   for( ; surface_num < numsurfaces ; surface_num++ )
      {
		if ( mult )
			{
			current_surface_name = gi.Surface_NumToName( edict->s.modelindex, surface_num );

			if ( Q_stricmpn( current_surface_name, surf_name, strlen( surf_name ) - 1) != 0 )
				continue;
			}

      switch (action)
         {
         case FLAG_ADD:
            edict->s.surfaces[ surface_num ] |= mask;
            break;
         case FLAG_CLEAR:
            edict->s.surfaces[ surface_num ] &= ~mask;
            break;
         case FLAG_IGNORE:
            break;
         }

      if ( !do_all && !mult )
         break;
      }
	}

void Entity::SurfaceModelEvent
	(
	Event *ev
	)

	{
   const char * surf_name;
   const char * token;
   int i;

   surf_name = ev->GetString( 1 );

   for ( i = 2; i <= ev->NumArgs() ; i++ )
      {
      token = ev->GetString( i );
      SurfaceCommand( surf_name, token );
      }
	}

void Entity::AttachEvent
	(
	Event * ev
	)
	{
   Entity * parent;
   const char * bone;
   int tagnum;
	qboolean use_angles = qtrue;
	Vector offset;
	Vector angles_offset;

	parent = ev->GetEntity( 1 );
   bone = ev->GetString( 2 );

	if ( ev->NumArgs() > 2 )
		use_angles = ev->GetInteger( 3 );

	if ( ev->NumArgs() > 3 )
		offset = ev->GetVector( 4 );

	if ( ev->NumArgs() > 4 )
		angles_offset = ev->GetVector( 5 );

   if ( !parent )
      return;

   tagnum = gi.Tag_NumForName( parent->edict->s.modelindex, bone );
   if ( tagnum >= 0 )
      {
      attach( parent->entnum, tagnum, use_angles, offset, angles_offset );
      }
   else
      {
      warning( "AttachEvent", "Tag %s not found", bone );
      }
   }

void Entity::AttachModelEvent
	(
	Event * ev
	)
	{
   Entity * obj;
   const char * bone;
   str modelname;
   int tagnum;
	float remove_time,fade_time,fade_delay;
	Vector offset;
	Vector angles_offset;
	qboolean use_angles = true;

   obj = new Entity( ENTITY_CREATE_FLAG_ANIMATE );

	obj->bind_info = CreateBindInfo();

	modelname = ev->GetString( 1 );
   bone = ev->GetString( 2 );
   if ( ev->NumArgs() > 2 )
		{
      obj->setScale( ev->GetFloat( 3 ) );
		}
   if ( ev->NumArgs() > 3 )
		{
      obj->SetTargetName( ev->GetString( 4 ) );
		}

	if ( ev->NumArgs() > 4 )
      obj->bind_info->detach_at_death = ev->GetInteger( 5 );

	if ( ev->NumArgs() > 5 )
		{
		remove_time = ev->GetFloat( 6 );

		if ( remove_time != -1 )
			{
			Event *remove_event = new Event( EV_Remove );
			obj->PostEvent( remove_event, remove_time );
			}
		}

	if ( ev->NumArgs() > 6 )
		{
		Event *fade_event;

      fade_time = ev->GetFloat( 7 );

      if ( fade_time > 0 )
         {
   		obj->setAlpha( 0 );

	   	fade_event = new Event( EV_FadeIn );
		   fade_event->AddFloat( fade_time );
		   obj->PostEvent( fade_event, 0 );
         }
		}

 	if ( ev->NumArgs() > 7 )
		{
		Event *fade_event;

      fade_delay = ev->GetFloat( 8 );

      if ( fade_delay != -1 )
         {
         if ( ev->NumArgs() > 8 )
            fade_time = ev->GetFloat( 9 );
         else
            fade_time = 0;

	   	fade_event = new Event( EV_Fade );

         if ( fade_time > 0 )
            fade_event->AddFloat( fade_time );

		   obj->PostEvent( fade_event, fade_delay );
         }
		}

	if ( ev->NumArgs() > 9 )
		offset = ev->GetVector( 10 );

	if ( ev->NumArgs() > 10 )
		{
		angles_offset = ev->GetVector( 11 );
		use_angles = false;
		}

   obj->setModel( modelname );
	
	if ( !obj->animate )
		{
		Animate *newAnimate = 0;
		newAnimate = new Animate;
		if ( newAnimate )
			obj->animate = newAnimate;
		}
				
	int anim_num = gi.Anim_Random ( obj->edict->s.modelindex, "idle" );
	if ( anim_num != -1 && obj->animate )
		{
		obj->animate->NewAnim( anim_num );
		}

   tagnum = gi.Tag_NumForName( edict->s.modelindex, bone );
   if ( tagnum >= 0 )
      {
      if ( !obj->attach( this->entnum, tagnum, use_angles, offset, angles_offset ) )
         {
         //warning( "AttachModelEvent", "Could not attach model %s", modelname.c_str() );
         delete obj;
         return;
         }
      }
   else
      {
      warning( "AttachModelEvent", "Tag %s not found", bone );
      }
   }

void Entity::RemoveAttachedModelEvent
	(
	Event *ev
	)
	{
   const char *tag_name;
   int tag_num;
	int num;
	int i;
	Entity *ent;
	float fade_rate = 0;
	Event *fade_event;
	str model_name;

	if ( bind_info )
		{
		tag_name = ev->GetString( 1 );
		tag_num = gi.Tag_NumForName( edict->s.modelindex, tag_name );

		if ( ev->NumArgs() > 1 )
			fade_rate = ev->GetFloat( 2 );

		if ( ev->NumArgs() > 2 )
			model_name = ev->GetString( 3 );

		if ( tag_num >= 0 )
			{
			num = bind_info->numchildren;

			for ( i = 0 ; (i < MAX_MODEL_CHILDREN) && num ; i++ )
				{
				if ( bind_info->children[i] == ENTITYNUM_NONE )
					continue;

				ent = ( Entity * )G_GetEntity( bind_info->children[i] );

				if ( ent->edict->s.tag_num == tag_num )
					{
					if ( !model_name.length() || model_name == ent->model )
						{
						if ( fade_rate )
							{
							fade_event = new Event( EV_Fade );
							fade_event->AddFloat( fade_rate );
							fade_event->AddFloat( 0 );
							ent->PostEvent( fade_event, 0 );
							}

						//ent->PostEvent( EV_Remove, fade_rate );
						}
					ent->PostEvent( EV_Remove, fade_rate );
					}

				num--;
				}
			}
		}
   }

void Entity::DetachEvent
	(
	Event * ev
	)

	{
   if ( edict->s.parent == ENTITYNUM_NONE  )
		{
      return;
		}
   detach();
   }

void Entity::TakeDamageEvent
	(
	Event * ev
	)
	{
   takedamage = DAMAGE_YES;
   }

void Entity::NoDamageEvent
	(
	Event * ev
	)
	{
   takedamage = DAMAGE_NO;
   }

void Entity::Gravity
   (
   Event *ev
   )

   {
   gravity = ev->GetFloat( 1 );
   }

void Entity::UseBoundingBoxEvent
   (
   Event *ev
   )
   {
	edict->svflags |= SVF_USEBBOX;
   }

void Entity::HurtEvent
   (
   Event *ev
   )
   {
   Vector normal;
   float dmg;
	int means_of_death;
	Vector direction;

   if ( ev->NumArgs() < 1 )
      {
      dmg = 50;
      }
   else
      {
      dmg = ev->GetFloat( 1 );
      }

	if ( ev->NumArgs() > 1 )
		means_of_death = MOD_string_to_int( ev->GetString( 2 ) );
	else
		means_of_death = MOD_CRUSH;

	if ( ev->NumArgs() > 2 )
		{
		direction = ev->GetVector( 3 );
		direction.normalize();
		}
	else
		{
		direction = vec_zero;
		}

   normal = Vector( orientation[ 0 ] );
   Damage( world, world, dmg, centroid, direction, normal, dmg, 0, means_of_death );
   }

void Entity::IfSkillEvent
	(
	Event *ev
	)

	{
   float skilllevel;

	skilllevel = ev->GetFloat( 1 );

   if ( skill->value == skilllevel )
      {
	   int			argc;
	   int			numargs;
      Event       *event;
	   int			i;

	   numargs = ev->NumArgs();
	   argc = numargs - 2 + 1;

      event = new Event( ev->GetToken( 2 ) );

	   for( i = 1; i < argc; i++ )
		   {
         event->AddToken( ev->GetToken( 2 + i ) );
		   }
      ProcessEvent( event );
		}
	}

void Entity::Censor
	(
	Event *ev
	)

	{
   Vector delta;
   float oldsize;
   float newsize;

   if ( com_blood->integer )
      return;

   oldsize = size.length();
	setSolidType( SOLID_NOT );
   setModel( "censored.tik" );
   gi.CalculateBounds( edict->s.modelindex, 1, mins, maxs );
   delta = maxs - mins;
   newsize = delta.length();
   edict->s.scale = oldsize / newsize;
   mins *= edict->s.scale;
   maxs *= edict->s.scale;
   setSize( mins, maxs );
   setOrigin();
	}

void Entity::StationaryEvent
   (
   Event *ev
   )

	{
	setMoveType( MOVETYPE_STATIONARY );
	}

void Entity::Explosion
   (
   Event *ev
   )

   {
   str expmodel;
	str tag_name;
	//orientation_t orient;
	Vector explosion_origin;

	expmodel = ev->GetString( 1 );
	explosion_origin = origin;

	if ( ev->NumArgs() > 1 )
		{
		tag_name = ev->GetString( 2 );

		//if ( GetRawTag( tag_name.c_str(), &orient, legs ) )
		//	VectorAdd( orient.origin, origin, explosion_origin );

		GetTag( tag_name.c_str(), &explosion_origin );
		}

   ExplosionAttack( explosion_origin, this, expmodel );
   }

void Entity::SelfDetonate
   (
	Event *ev
	)
	{
	if ( explosionModel.length() == 0 )
		explosionModel = "fx_sml_exp.tik";

	ExplosionAttack( origin , this , explosionModel );	
	}

void Entity::Shader
	(
	Event *ev
	)

	{
   const char * token;

   if ( gi.IsModel( edict->s.modelindex ) )
      {
      ev->Error( "shader event being called on TIKI model\n" );
      }
   //
   // get sub shader command
   //
   token = ev->GetString( 1 );

   //
   // WARNING: please change the Event decleration,
   // to match this function, if flags are added or
   // deleted the event must be updated.
   //
   if (!strcmpi( token, "translation"))
      {
      float x, y;

      x = ev->GetFloat( 2 );
      y = ev->GetFloat( 3 );
      TRANSLATION_TO_PKT( x, edict->s.tag_num );
      TRANSLATION_TO_PKT( y, edict->s.skinNum );
      }
   else if (!strcmpi( token, "offset"))
      {
      float x, y;

      x = ev->GetFloat( 2 );
      y = ev->GetFloat( 3 );
      OFFSET_TO_PKT( x, edict->s.tag_num );
      OFFSET_TO_PKT( y, edict->s.skinNum );
      }
   else if (!strcmpi (token, "rotation"))
      {
      float rot;

      rot = ev->GetFloat( 2 );
      ROTATE_TO_PKT( rot, edict->s.tag_num );
      }
   else if (!strcmpi (token, "frame"))
      {
      edict->s.frame = ev->GetInteger( 2 );
      }
   else if (!strcmpi (token, "wavebase"))
      {
      float base;

      base = ev->GetFloat( 2 );
      BASE_TO_PKT( base, edict->s.surfaces[ 0 ] );
      }
   else if (!strcmpi (token, "waveamp"))
      {
      float amp;

      amp = ev->GetFloat( 2 );
      AMPLITUDE_TO_PKT( amp, edict->s.surfaces[ 1 ] );
      }
   else if (!strcmpi (token, "wavephase"))
      {
      float phase;

      phase = ev->GetFloat( 2 );
      PHASE_TO_PKT( phase, edict->s.surfaces[ 2 ] );
      }
   else if (!strcmpi (token, "wavefreq"))
      {
      float freq;

      freq = ev->GetFloat( 2 );
      FREQUENCY_TO_PKT( freq, edict->s.surfaces[ 3 ] );
      }
	}

void Entity::DropToFloorEvent
   (
   Event *ev
   )

   {
   float range;

	if ( ev->NumArgs() > 0 )
      {
      range = ev->GetFloat( 1 );
      }
   else
      {
      range = WORLD_SIZE;
      }
   if ( !droptofloor( range ) )
      {
      }
	}


//*************************************************************************
//
// BIND code
//
//*************************************************************************

qboolean Entity::isBoundTo
   (
   Entity *master
   )

   {
   Entity *ent;

	if ( bind_info )
		{
		for( ent = bind_info->bindmaster; ent != NULL; ent = ent->bind_info->bindmaster )
			{
			if ( ent == master )
				{
				return true;
				}
			}
		}

   return false;
   }

void Entity::bind
	(
	Entity *master,
	qboolean use_my_angles
	)

	{
	float  mat[ 3 ][ 3 ];
	float  local[ 3 ][ 3 ];
	Vector ang;

	assert( master );
	if ( !master )
		{
		warning( "bind", "Null master entity" );
		return;
		}

   if ( master == this )
      {
      warning( "bind", "Trying to bind to oneself." );
      return;
      }

	if ( !bind_info )
		bind_info = CreateBindInfo();

   // unbind myself from my master
   unbind();

	bind_info->bindmaster = master;
	edict->s.bindparent = master->entnum;
	bind_info->bind_use_my_angles = use_my_angles;

   // We are now separated from our previous team and are either
   // an individual, or have a team of our own.  Now we can join
   // the new bindmaster's team.  Bindmaster must be set before
   // joining the team, or we will be placed in the wrong position
   // on the team.
   joinTeam( master );

	// calculate local angles
	TransposeMatrix( bind_info->bindmaster->orientation, mat );
	R_ConcatRotations( mat, orientation, local );
	MatrixToEulerAngles( local, ang );
	setAngles( ang );

   setOrigin( getParentVector( localorigin - bind_info->bindmaster->origin ) );

   return;
   }

void Entity::unbind
	(
	void
	)

	{
   Entity *prev;
   Entity *next;
   Entity *last;
   Entity *ent;


	if ( !bind_info || !bind_info->bindmaster )
		return;

	//bindmaster = NULL;

   // Check this GAMEFIX - should it be origin?
	localorigin = Vector( edict->s.origin );
	localangles = Vector( edict->s.angles );

   if ( !bind_info->teammaster )
      {
      bind_info->bindmaster = NULL;
		edict->s.bindparent = ENTITYNUM_NONE;
      //Teammaster already has been freed
      return;
      }

   // We're still part of a team, so that means I have to extricate myself
   // and any entities that are bound to me from the old team.
   // Find the node previous to me in the team
   prev = bind_info->teammaster;

	for( ent = bind_info->teammaster->bind_info->teamchain; ent && ( ent != this ); ent = ent->bind_info->teamchain )
		{
      prev = ent;
		}

   // If ent is not pointing to me, then something is very wrong.
   assert( ent );
   if ( !ent )
      {
      error( "unbind", "corrupt team chain\n" );
      }

   // Find the last node in my team that is bound to me.
   // Also find the first node not bound to me, if one exists.
   last = this;
   for( next = bind_info->teamchain; next != NULL; next = next->bind_info->teamchain )
      {
      if ( !next->isBoundTo( this ) )
         {
         break;
         }

      // Tell them I'm now the teammaster
      next->bind_info->teammaster = this;
      last = next;
		}

   // disconnect the last member of our team from the old team
   last->bind_info->teamchain = NULL;

   // connect up the previous member of the old team to the node that
   // follow the last node bound to me (if one exists).
   if ( bind_info->teammaster != this )
      {
      prev->bind_info->teamchain = next;
      if ( !next && ( bind_info->teammaster == prev ) )
         {
         prev->bind_info->teammaster = NULL;
         }
      }
   else if ( next )
      {
      // If we were the teammaster, then the nodes that were not bound to me are now
      // a disconnected chain.  Make them into their own team.
		for( ent = next; ent->bind_info->teamchain != NULL; ent = ent->bind_info->teamchain )
         {
         ent->bind_info->teammaster = next;
			}
      next->bind_info->teammaster = next;
	   next->flags &= ~FL_TEAMSLAVE;
      }

   // If we don't have anyone on our team, then clear the team variables.
   if ( bind_info->teamchain )
      {
      // make myself my own team
      bind_info->teammaster = this;
      }
   else
      {
      // no longer a team
      bind_info->teammaster = NULL;
      }

	flags &= ~FL_TEAMSLAVE;
   bind_info->bindmaster = NULL;
	edict->s.bindparent = ENTITYNUM_NONE;
	}

void Entity::EventUnbind
	(
	Event *ev
	)

	{
	unbind();
	}

void Entity::BindEvent
	(
	Event *ev
	)

	{
	Entity *ent;

	ent = ev->GetEntity( 1 );
	if ( ent )
		{
		bind( ent );
		}
	}


Vector Entity::getParentVector
	(
	const Vector &vec
	)

	{
	Vector pos;

	if ( !bind_info || !bind_info->bindmaster )
		{
		return vec;
		}

	pos[ 0 ] = vec * bind_info->bindmaster->orientation[ 0 ];
	pos[ 1 ] = vec * bind_info->bindmaster->orientation[ 1 ];
	pos[ 2 ] = vec * bind_info->bindmaster->orientation[ 2 ];

	return pos;
	}

//
// Team methods
//

void Entity::joinTeam
	(
	Entity *teammember
	)

	{
	Entity *ent;
   Entity *master;
   Entity *prev;
   Entity *next;

	if ( !bind_info )
		bind_info = CreateBindInfo();

	if ( bind_info->teammaster && ( bind_info->teammaster != this ) )
		{
		quitTeam();
		}

	assert( teammember );
	if ( !teammember )
		{
		warning( "joinTeam", "Null entity" );
		return;
		}

	if ( !teammember->bind_info )
		teammember->bind_info = CreateBindInfo();

	master = teammember->bind_info->teammaster;
	if ( !master )
		{
		master = teammember;
		teammember->bind_info->teammaster = teammember;
      teammember->bind_info->teamchain = this;

      // make anyone who's bound to me part of the new team
      for( ent = bind_info->teamchain; ent != NULL; ent = ent->bind_info->teamchain )
         {
         ent->bind_info->teammaster = master;
         }
      }
   else
      {
      // skip past the chain members bound to the entity we're teaming up with
      prev = teammember;
	   next = teammember->bind_info->teamchain;
      if ( bind_info->bindmaster )
         {
         // if we have a bindmaster, joing after any entities bound to the entity
         // we're joining
	      while( next && (( Entity *)next)->isBoundTo( teammember ) )
		      {
            prev = next;
		      next = next->bind_info->teamchain;
		      }
         }
      else
         {
         // if we're not bound to someone, then put us at the end of the team
	      while( next )
		      {
            prev = next;
		      next = next->bind_info->teamchain;
		      }
         }

      // make anyone who's bound to me part of the new team and
      // also find the last member of my team
      for( ent = this; ent->bind_info->teamchain != NULL; ent = ent->bind_info->teamchain )
         {
         ent->bind_info->teamchain->bind_info->teammaster = master;
         }

    	prev->bind_info->teamchain = this;
      ent->bind_info->teamchain = next;
      }

   bind_info->teammaster = master;
	flags |= FL_TEAMSLAVE;
	}

void Entity::quitTeam
	(
	void
	)

	{
	Entity *ent;

	if ( !bind_info || !bind_info->teammaster )
		{
		return;
		}

	if ( bind_info->teammaster == this )
		{
      if ( !bind_info->teamchain->bind_info->teamchain )
         {
         bind_info->teamchain->bind_info->teammaster = NULL;
         }
      else
         {
		   // make next teammate the teammaster
		   for( ent = bind_info->teamchain; ent; ent = ent->bind_info->teamchain )
			   {
			   ent->bind_info->teammaster = bind_info->teamchain;
			   }
         }

      bind_info->teamchain->flags &= ~FL_TEAMSLAVE;
		}
	else
		{
		assert( flags & FL_TEAMSLAVE );
		assert( bind_info->teammaster->bind_info->teamchain );

		ent = bind_info->teammaster;
		while( ent->bind_info->teamchain != this )
			{
			// this should never happen
			assert( ent->bind_info->teamchain );

			ent = ent->bind_info->teamchain;
			}

		ent->bind_info->teamchain = bind_info->teamchain;

		if ( !bind_info->teammaster->bind_info->teamchain )
			{
			bind_info->teammaster->bind_info->teammaster = NULL;
			}
		}

	bind_info->teammaster = NULL;
	bind_info->teamchain = NULL;
	flags &= ~FL_TEAMSLAVE;
	}

void Entity::EventQuitTeam
	(
	Event *ev
	)

	{
	quitTeam();
	}


void Entity::JoinTeam
	(
	Event *ev
	)

	{
	Entity *ent;

	ent = ev->GetEntity( 1 );
	if ( ent )
		{
		joinTeam( ent );
		}
	}

void Entity::AddToSoundManager
	(
	Event *ev
	)

	{
   SoundMan.AddEntity( this );
	}

inline qboolean Entity::HitSky
	(
	trace_t *trace
	)

	{
	assert( trace );
   if ( trace->surfaceFlags & SURF_SKY )
		{
		return true;
		}
	return false;
	}

qboolean Entity::HitSky
	(
	void
	)

	{
	return HitSky( &level.impact_trace );
	}

void Entity::SetAngleEvent
	(
	Event *ev
	)
	{
   Vector movedir;

   movedir = G_GetMovedir( ev->GetFloat( 1 ) );
	setAngles( movedir.toAngles() );
   }

void Entity::NoLerpThisFrame
	(
   void
	)
	{
   edict->s.eFlags ^= EF_TELEPORT_BIT;
   }

void Entity::Postthink
	(
	void
	)

	{
	}

void Entity::TouchTriggersEvent
	(
	Event *ev
	)
	{
   flags |= FL_TOUCH_TRIGGERS;
   }

void Entity::IncreaseShotCount 
   (
	Event *ev
	)
	{
	int parent_ent_num = edict->s.parent;
	Entity *parent = ( Entity * )G_GetEntity( parent_ent_num );

	if ( !parent->isSubclassOf(Actor) )
		return;
   
	Actor* act;
	act = (Actor*)parent;

	act->shotsFired++;	
	}

void Entity::DeathSinkStart
	(
	Event *ev
	)
	{
	float time;

	// Stop the sink when we can't be seen anymore

	if ( maxs[2] >= 0 && maxs[2] < 200 )
		time = maxs[2] / 20;
	else
		time = 1;

	PostEvent( EV_Remove, time );

	// Start the sinking

	ProcessEvent( EV_DeathSink );
	}

void Entity::DeathSink
	(
	Event *ev
	)
	{
	// Sink just a little

	origin[2] -= 1;
	setOrigin( origin );

	// Make sure the sink happens again next frame

	PostEvent( EV_DeathSink, FRAMETIME );
	}

void Entity::LookAtMe
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() > 0 )
		look_at_me = ev->GetBoolean( 1 );
	else
		look_at_me = true;
	}

void Entity::VelocityModified
	(
   void
	)
	{
	}

void Entity::DetachAllChildren
	(
	Event *ev
	)

	{
   int i;

   for (i=0;i<MAX_MODEL_CHILDREN;i++)
      {
      Entity * ent;
      if ( bind_info->children[i] == ENTITYNUM_NONE )
         continue;

      ent = ( Entity * )G_GetEntity( bind_info->children[i] );
      if ( ent )
         {
         ent->PostEvent( EV_Remove, 0 );
         }
      }
	}

inline void Entity::Archive
	(
	Archiver &arc
	)

   {
   int tempInt;
	qboolean is_archived;
	qboolean true_bool = true;
	qboolean false_bool = false;

   Listener::Archive( arc );

   G_ArchiveEdict( arc, edict );

   arc.ArchiveInteger( &spawnflags );

   arc.ArchiveString( &model );
   if ( arc.Loading() && model.length() )
      {
      setModel( model );
      }

   arc.ArchiveVector( &total_delta );
   arc.ArchiveVector( &mins );
   arc.ArchiveVector( &maxs );
   arc.ArchiveVector( &absmin );
   arc.ArchiveVector( &absmax );
   arc.ArchiveVector( &centroid );
   arc.ArchiveVector( &velocity );
   arc.ArchiveVector( &avelocity );
   arc.ArchiveVector( &origin );
   arc.ArchiveVector( &angles );
   arc.ArchiveVector( &size );
   arc.ArchiveInteger( &movetype );
   arc.ArchiveInteger( &mass );
   arc.ArchiveFloat( &gravity );
   arc.ArchiveRaw( orientation, sizeof( orientation ) );

   if ( arc.Saving() )
      {
      if ( groundentity )
         {
         tempInt = groundentity - g_entities;
         }
      else
         {
         tempInt = -1;
         }
      }

   arc.ArchiveInteger( &tempInt );

   if ( arc.Loading() )
      {
      if ( tempInt == -1 )
         {
         groundentity = NULL;
         }
      else
         {
         groundentity = &g_entities[ tempInt ];
         }
      }

   arc.ArchiveRaw( &groundplane, sizeof( groundplane ) );
   arc.ArchiveInteger( &groundcontents );

   arc.ArchiveInteger( &numsurfaces );

   arc.ArchiveFloat( &lightRadius );

   arc.ArchiveVector( &localorigin );
   arc.ArchiveVector( &localangles );

   arc.ArchiveString( &target );
   arc.ArchiveString( &targetname );
   // add to target list to rebuild targetlists
   arc.ArchiveString( &killtarget );

   if ( arc.Loading() )
      {
	   // reset target stuff
	   SetTargetName( targetname.c_str() );
	   SetTarget( target.c_str() );
      }

   arc.ArchiveFloat( &health );
   arc.ArchiveFloat( &max_health );
   arc.ArchiveInteger( &deadflag );
   arc.ArchiveInteger( &flags );

   arc.ArchiveInteger( &watertype );
   arc.ArchiveInteger( &waterlevel );

   ArchiveEnum( takedamage, damage_t );

   arc.ArchiveInteger( &damage_type );

	arc.ArchiveBoolean( &look_at_me );

	//  Pluggable modules

	if ( arc.Loading() )
		{
		arc.ArchiveBoolean( &is_archived );

		if ( is_archived )
			{
			animate = new Animate( this );
			arc.ArchiveObject( animate );
			}

		arc.ArchiveBoolean( &is_archived );

		if ( is_archived )
			{
			mover = new Mover( this );
			arc.ArchiveObject( mover );
			}

		arc.ArchiveBoolean( &is_archived );

		if ( is_archived )
			{
			bind_info = CreateBindInfo();
			bind_info->Archive( arc );
			}

		arc.ArchiveBoolean( &is_archived );

		if ( is_archived )
			{
			morph_info = CreateMorphInfo();
			morph_info->Archive( arc );
			}
		}
	else
		{
		if ( animate )
			{
			arc.ArchiveBoolean( &true_bool );
			arc.ArchiveObject( animate );
			}
		else
			{
			arc.ArchiveBoolean( &false_bool );
			}

		if ( mover )
			{
			arc.ArchiveBoolean( &true_bool );
			arc.ArchiveObject( mover );
			}
		else
			{
			arc.ArchiveBoolean( &false_bool );
			}

		if ( bind_info )
			{
			arc.ArchiveBoolean( &true_bool );
			bind_info->Archive( arc );
			}
		else
			{
			arc.ArchiveBoolean( &false_bool );
			}

		if ( morph_info )
			{
			arc.ArchiveBoolean( &true_bool );
			morph_info->Archive( arc );
			}
		else
			{
			arc.ArchiveBoolean( &false_bool );
			}
		}
   }

// Animate interface

inline int Entity::CurrentFrame
	(
   bodypart_t part
	)

	{
	if ( animate )
		return animate->CurrentFrame( part );
	else
		return 0;
	}

inline int Entity::CurrentAnim
	(
   bodypart_t part
	)

	{
	if ( animate )
		return animate->CurrentAnim( part );
	else
		return 0;
	}

void Entity::PassToAnimate
	(
	Event *ev
	)

	{
	Event *new_event;

	if ( !animate )
		animate = new Animate( this );

	new_event = new Event( ev );
	animate->ProcessEvent( new_event );
	}

void Entity::SetObjectProgram
   (
	Event *ev
	)
	{
	ObjectProgram = new Program;
	
	if ( !ObjectProgram )
		return;

	ObjectProgram->Load( ev->GetString( 1 )  );


	//CThread *gamescript = 0;

	//gamescript = Director.CreateThread( "obj_main" , ObjectProgram );
	//gamescript->DelayedStart( 0 );

	}

void Entity::ExecuteProgram
   (
	Event *ev
	)
	{
	float exeTime = 0;
	
	if ( !ObjectProgram )
		return;

	if ( ev->NumArgs() > 0 )
		exeTime = ev->GetFloat( 1 );

	CThread *gamescript = 0;
	gamescript = Director.CreateThread( "obj_main" , ObjectProgram );
	gamescript->DelayedStart( exeTime );
	}

// BindInfo interface

inline BindInfo *CreateBindInfo( void )
	{
	BindInfo *new_bind_info;

	new_bind_info = new BindInfo;

	if ( !new_bind_info )
		gi.Error( ERR_DROP, "Couldn't alloc BindInfo" );

	return new_bind_info;
	}

// MorphInfo interface

void Entity::MorphEvent
	(
	Event *ev
	)
	{
	str	morph_target_name;
	int	morph_index;
	float	final_percent = 100;
	float	morph_time = 0.5;
	qboolean return_to_zero = false;
	int i;
	qboolean override = true;
	int morph_channel = MORPH_CHAN_NONE;
	qboolean channel_being_used;
	qboolean override_all = false;
	qboolean matching_channel;
	qboolean unmorph = false;

	// Get parms

	morph_target_name = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		final_percent = ev->GetFloat( 2 );
	if ( ev->NumArgs() > 2 )
		morph_time = ev->GetFloat( 3 );
	if ( ev->NumArgs() > 3 )
		return_to_zero = ev->GetBoolean( 4 );
	if ( ev->NumArgs() > 4 )
		override = ev->GetBoolean( 5 );
	if ( ev->NumArgs() > 5 )
		morph_channel = ev->GetInteger( 6 );

	// See if this is an expression

	if ( strnicmp( morph_target_name.c_str(), "exp_", 4 ) == 0 )
		{
		// Process this expression

		dtikimorphtarget_t *morph_targets;
		Event *new_event;
		const char *morph_name;
		int number_of_morph_targets;

		morph_targets = gi.GetExpression( edict->s.modelindex, morph_target_name.c_str(), &number_of_morph_targets );

		if ( morph_targets )
			{
			for ( i = 0 ; i < number_of_morph_targets ; i++ )
				{
				morph_name = gi.Morph_NameForNum( edict->s.modelindex, morph_targets[ i ].morph_index );

				if ( morph_name )
					{
					new_event = new Event( EV_Morph );
					new_event->AddString( morph_name );
					new_event->AddFloat( morph_targets[ i ].percent );
					new_event->AddFloat( morph_time );
					new_event->AddInteger( return_to_zero );
					new_event->AddInteger( override );
					new_event->AddInteger( morph_channel );
					ProcessEvent( new_event );
					}
				}

			return;
			}
		}

	// Find this morph target

	morph_index = gi.Morph_NumForName( edict->s.modelindex, morph_target_name.c_str() );

	// Check unmorphing stuff

	if ( stricmp( morph_target_name.c_str(), "morph_base" ) == 0 || 
		  stricmp( morph_target_name.c_str(), "morph_mouth_base" ) == 0 || 
		  stricmp( morph_target_name.c_str(), "morph_brows_base" ) == 0 || 
		  stricmp( morph_target_name.c_str(), "morph_eyes_base" ) == 0 )
		unmorph = true;

	if ( morph_index == -1 && !unmorph )
		return;

	if ( morph_channel == MORPH_CHAN_NONE )
		morph_channel = GetMorphChannel( morph_target_name.c_str() );

	// Make sure we have a morph controller block

	if ( !morph_info )
		morph_info = CreateMorphInfo();

	// Deal with current morphs

	channel_being_used = false;

	if ( unmorph && morph_channel == MORPH_CHAN_NONE )
		override_all = true;

	for( i = 0 ; i < NUM_MORPH_CONTROLLERS ; i++ )
		{
		if ( morph_info->controllers[ i ].index != -1 )
			{
			// See if this is a matching channel

			if ( MorphChannelMatches( morph_channel, morph_info->controllers[ i ].channel ) )
				matching_channel = true;
			else 
				matching_channel = false;

			if ( override_all || ( matching_channel && override ) )
				{
				// Override this morph

				morph_info->controllers[ i ].speed = (final_percent * FRAMETIME ) / morph_time;
				morph_info->controllers[ i ].final_percent = 0;

				StartMorphController();
				}
			else if ( matching_channel )
				{
				channel_being_used = true;
				}
			}
		}

	// If just unmorphing stuff, stop here

	if ( unmorph )
		return;

	// If not overriding and the channel is already being used, stop here

	if ( !override && channel_being_used )
		return;

	// Find a free morph controller & add this morph

	for( i = 0 ; i < NUM_MORPH_CONTROLLERS ; i++ )
		{
		if ( morph_info->controllers[ i ].index == -1 )
			{
			morph_info->controllers[ i ].index           = morph_index;
			morph_info->controllers[ i ].current_percent = 0;
			morph_info->controllers[ i ].final_percent   = final_percent;
			morph_info->controllers[ i ].speed           = (final_percent * FRAMETIME ) / morph_time;
			morph_info->controllers[ i ].return_to_zero  = return_to_zero;
			morph_info->controllers[ i ].channel         = morph_channel;

			StartMorphController();

			break;
			}
		}
	}

void Entity::UnmorphEvent
	(
	Event *ev
	)
	{
	str	morph_target_name;
	int	morph_index;
	int	i;
	float morph_time = 0.5;

	morph_target_name = ev->GetString( 1 );

	if ( ev->NumArgs() > 2 )
		morph_time = ev->GetFloat( 3 );

	// See if this is an expression

	if ( strnicmp( morph_target_name.c_str(), "exp_", 4 ) == 0 )
		{
		// Process this expression

		dtikimorphtarget_t *morph_targets;
		Event *new_event;
		const char *morph_name;
		int number_of_morph_targets;

		morph_targets = gi.GetExpression( edict->s.modelindex, morph_target_name.c_str(), &number_of_morph_targets );

		if ( morph_targets )
			{
			for ( i = 0 ; i < number_of_morph_targets ; i++ )
				{
				morph_name = gi.Morph_NameForNum( edict->s.modelindex, morph_targets[ i ].morph_index );

				if ( morph_name )
					{
					new_event = new Event( EV_Unmorph );
					new_event->AddString( morph_name );
					new_event->AddFloat( morph_time );
					ProcessEvent( new_event );
					}
				}

			return;
			}
		}

	morph_index = gi.Morph_NumForName( edict->s.modelindex, morph_target_name.c_str() );

	if ( morph_index == -1 || !morph_info )
		return;

	// Find this morph controller

	for( i = 0 ; i < NUM_MORPH_CONTROLLERS ; i++ )
		{
		if ( morph_info->controllers[ i ].index == morph_index && morph_info->controllers[ i ].final_percent != 0 )
			{
			morph_info->controllers[ i ].speed = (morph_info->controllers[ i ].final_percent * FRAMETIME ) / morph_time;
			morph_info->controllers[ i ].final_percent = 0;

			StartMorphController();

			break;
			}
		}
	}

void Entity::MorphControl
	(
	Event *ev
	)
	{
	int i;
	qboolean process_next_frame = false;
	morph_t *controller;

	for( i = 0 ; i < NUM_MORPH_CONTROLLERS ; i++ )
		{
		controller = &morph_info->controllers[ i ];

		if ( controller->index != -1 )
			{
			// Lerp the morph percent

			if ( controller->current_percent != controller->final_percent )
				{
				if ( controller->current_percent < controller->final_percent )
					{
					controller->current_percent += controller->speed;

					if ( controller->current_percent > controller->final_percent )
						controller->current_percent = controller->final_percent;
					}
				else
					{
					controller->current_percent -= controller->speed;

					if ( controller->current_percent < controller->final_percent )
						controller->current_percent = controller->final_percent;
					}
				}

			if ( controller->current_percent == 0.0 )
				{
				controller->index = -1;
				controller->current_percent = 0.0;
				}

			// Return to zero if necessary

			if ( controller->current_percent == controller->final_percent && controller->return_to_zero )
				controller->final_percent = 0.0;

			if ( controller->current_percent != controller->final_percent )
				process_next_frame = true;
			}

		// Copy to edict

		edict->s.morph_controllers[ i ].index   = controller->index;
		edict->s.morph_controllers[ i ].percent = controller->current_percent / 100;
		}

	if ( process_next_frame )
		PostEvent( EV_MorphControl, FRAMETIME );
	else
		morph_info->controller_on = false;
	}

int Entity::GetMorphChannel
	(
	const char *morph_name
	)
	{
	int morph_channel;

	if ( stricmp( morph_name, "morph_a-i" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_c-t" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_e" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_f-v" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_l-d-th" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_m-b-p" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_o" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_q-w" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_u" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_frown" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_sneer-l" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_sneer-r" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;
	else if ( stricmp( morph_name, "morph_mouth_base" ) == 0 )
		morph_channel = MORPH_CHAN_MOUTH;

	else if ( stricmp( morph_name, "morph_brows-up" ) == 0 )
		morph_channel = MORPH_CHAN_BROW;
	else if ( stricmp( morph_name, "morph_brows_base" ) == 0 )
		morph_channel = MORPH_CHAN_BROW;

	else if ( stricmp( morph_name, "morph_brow-ldn" ) == 0 )
		morph_channel = MORPH_CHAN_LEFT_BROW;

	else if ( stricmp( morph_name, "morph_brow-rdn" ) == 0 )
		morph_channel = MORPH_CHAN_RIGHT_BROW;

	else if ( stricmp( morph_name, "morph_lid-lshut" ) == 0 )
		morph_channel = MORPH_CHAN_LEFT_LID;

	else if ( stricmp( morph_name, "morph_lid-rshut" ) == 0 )
		morph_channel = MORPH_CHAN_RIGHT_LID;

	else if ( stricmp( morph_name, "morph_eyeshut" ) == 0 )
		morph_channel = MORPH_CHAN_EYES;
	else if ( stricmp( morph_name, "morph_eyes_base" ) == 0 )
		morph_channel = MORPH_CHAN_EYES;

	else 
		morph_channel = MORPH_CHAN_NONE;

	return morph_channel;
	}

void Entity::StartMorphController
	(
	void
	)
	{
	if ( !morph_info->controller_on )
		{
		morph_info->controller_on = true;
		CancelEventsOfType( EV_MorphControl );
		PostEvent( EV_MorphControl, FRAMETIME );
		}
	}


void Entity::SetAnimOnAttachedModel
   (
	const str &AnimName,
	const str &TagName
	)

	{
	int tag_num = gi.Tag_NumForName( this->edict->s.modelindex , TagName.c_str() );

	if ( bind_info )
		{
		Entity *attachment = 0;

		for ( int i = 0; i < MAX_MODEL_CHILDREN; i++ )
			{
			
			//Check for valid entities
         if( bind_info->children[i] == ENTITYNUM_NONE )
				continue;

			attachment = ( Entity * )G_GetEntity( bind_info->children[i] );
			
			if ( attachment->edict->s.tag_num == tag_num )
				{
				if ( !attachment->animate )
					{
					Animate *newAnimate = 0;
					newAnimate = new Animate;
					if ( !newAnimate )
						break;

					attachment->animate = newAnimate;
					}
				
				int anim_num = gi.Anim_Random ( attachment->edict->s.modelindex, AnimName.c_str() );
				if ( anim_num != -1 )
					{
					attachment->animate->NewAnim( anim_num );
					}

				}

			}
		}
	}

void Entity::SetAnimOnAttachedModel
   (
	Event *ev
	)
	{
	str attachmentAnim = ev->GetString( 1 );
	str TagName = ev->GetString( 2 );

	SetAnimOnAttachedModel( attachmentAnim , TagName );	
	}

void Entity::SetEntityExplosionModel
   (
	Event *ev
	)
	{
	explosionModel = ev->GetString( 1 );
	}

void Entity::ProjectileAtk
   (
	Event *ev
	)
	{
	str projectile_name;
	Vector position;
	Vector dir;

	projectile_name = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		{
		str tag_name;

		tag_name = ev->GetString( 2 );

		GetTag( tag_name.c_str(), &position, &dir );
		}
	else
		{
		position = origin;
		
		gentity_t *ed;
		Entity* enemy;
		
		enemy = NULL;
		for( int i = 0 ; i < game.maxclients; i++ )
			{
			ed = &g_entities[ i ];

			if ( !ed->inuse || !ed->entity )
				continue;

			enemy = ed->entity;
			}
		if ( enemy )
			{
			//Vector temp;
			dir = enemy->origin - origin;
			dir.normalize();
			//temp = origin - enemy->origin;
			//temp.AngleVectors( &dir );
			//dir = temp.toAngles();
			
			}
		else
			{
			angles.AngleVectors( &dir, NULL, NULL );
			}
		}

	ProjectileAttack( position, dir, this, projectile_name.c_str(), 1.0, 0 );
	}

void Entity::TraceAtk
   (
	Event *ev
	)
	{
	Vector position;
	Vector forward;
	Vector right;
	Vector up;
	float range;
	float damage;
	float knockback = 0.0;
	str means_of_death_string = "bullet";
	int means_of_death;
	//int offsetPitch = 0;

	damage = ev->GetFloat( 1 );
	range  = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		means_of_death_string = ev->GetString( 3 );

	if ( ev->NumArgs() > 3 )
		knockback = ev->GetFloat( 4 );

	if ( ev->NumArgs() > 4 )
		{
		str tag_name;

		tag_name = ev->GetString( 5 );

		GetTag( tag_name.c_str(), &position, &forward, &right, &up );
		}
	else
		{
		position = origin;
		angles.AngleVectors( &forward, &right, &up );
		}

	means_of_death = MOD_string_to_int( means_of_death_string );
	
	/*
	if ( ev->NumArgs() > 5 )
		offsetPitch = ev->GetInteger( 6 );

	if ( offsetPitch )
		{
		Vector ForAngles;
		ForAngles = forward.toAngles();

		ForAngles[YAW] = AngleNormalize180( ForAngles[YAW] );
		ForAngles[PITCH] = AngleNormalize180( ForAngles[PITCH] );
		ForAngles[ROLL] = AngleNormalize180( ForAngles[ROLL] );
		offsetPitch = AngleNormalize180(offsetPitch);

		ForAngles[PITCH] += offsetPitch;


		ForAngles[YAW] = AngleNormalize360( ForAngles[YAW] );
		ForAngles[PITCH] = AngleNormalize360( ForAngles[PITCH] );
		ForAngles[ROLL] = AngleNormalize360( ForAngles[ROLL] );

		ForAngles.AngleVectors( &forward );
		}
   */

	BulletAttack( position, forward, right, up, range, damage, 0, knockback, 0, means_of_death, vec_zero, 1, this );
	}

qboolean Entity::MorphChannelMatches
	(
	int morph_channel1,
	int morph_channel2
	)
	{
	// Nothing matches with non

	if ( morph_channel1 == MORPH_CHAN_NONE )
		return false;

	// See if they match exactly
		
	if ( morph_channel1 == morph_channel2  )
		return true;

	// Check special cases

	if ( morph_channel1 == MORPH_CHAN_BROW && ( morph_channel2 == MORPH_CHAN_LEFT_BROW || morph_channel2 == MORPH_CHAN_RIGHT_BROW ) )
		return true;

	if ( morph_channel2 == MORPH_CHAN_BROW && ( morph_channel1 == MORPH_CHAN_LEFT_BROW || morph_channel1 == MORPH_CHAN_RIGHT_BROW ) )
		return true;

	if ( morph_channel1 == MORPH_CHAN_EYES && ( morph_channel2 == MORPH_CHAN_LEFT_LID || morph_channel2 == MORPH_CHAN_RIGHT_LID ) )
		return true;

	if ( morph_channel2 == MORPH_CHAN_EYES && ( morph_channel1 == MORPH_CHAN_LEFT_LID || morph_channel1 == MORPH_CHAN_RIGHT_LID ) )
		return true;

	return false;
	}

inline MorphInfo *CreateMorphInfo( void )
	{
	MorphInfo *new_morph_info;

	new_morph_info = new MorphInfo;

	if ( !new_morph_info )
		gi.Error( ERR_DROP, "Couldn't alloc MorphInfo" );

	return new_morph_info;
	}

void Entity::OnlyShootable
   (
   Event *ev
   )

	{
	setContents( CONTENTS_SHOOTABLE_ONLY );
	link();
	}