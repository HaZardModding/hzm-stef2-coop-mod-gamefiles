//-----------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/actor.h                                             $
// $Revision:: 87                                                             $
//   $Author:: Sketcher                                                       $
//     $Date:: 9/12/01 3:01p                                                  $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/actor.h                                                  $
// 
// 87    9/12/01 3:01p Sketcher
// Initial clean up work.  Stripped out "commented out" code and anything else
// I could easily identify as clutter.
// 
// 86    8/29/01 6:06p Steven
// Fixed setSize so virtual would work correctly.
// 
// 85    8/14/01 3:48p Sketcher
// Fixed bugs in Actor to Actor damage and added more flying behaviors
// 
// 84    8/13/01 10:39a Sketcher
// added stuff to let NPC's detect the player in FOV only 
// 
// 83    7/26/01 3:02p Sketcher
// Moved EV_OnlyShootable from Actor to Entity
// 
// 82    7/23/01 4:17p Sketcher
// Added a ShootMode Type for the Night Train stuff
// 
// 81    7/18/01 8:52a Sketcher
// Added an OnDamage script event for Actors
// 
// 80    7/10/01 8:56a Sketcher
// Added Firstpass of Waypoints
// 
// 79    7/09/01 11:17a Sketcher
// ActorGameComponent now Inherits from Listener
// 
// 78    7/02/01 2:37p Sketcher
// Modified JumpTo to take in a vertical speed
// 
// 77    6/29/01 9:43a Sketcher
// Made modifications so that actors know when to reload
// 
// 76    6/27/01 10:47a Sketcher
// Added a new SetAnimOnAttachedModel function that lets the event handler act
// as an interface
// 
// 75    6/27/01 8:31a Sketcher
// Fixed a problem with death anims
// 
// 74    6/26/01 11:00a Sketcher
// Added a FallToDeath Behavior and Event Interface
// 
// 73    6/22/01 1:30p Sketcher
// Added stuff to help actors use horses
// 
// 72    6/20/01 7:39a Sketcher
// AI Work for the Townie
// 
// 71    6/18/01 11:10a Sketcher
// Added more functionality and bridging to ActorGameComponents
// 
// 70    6/15/01 3:34p Sketcher
// Initial Pass at Per Object Scripting
// 
// 69    6/14/01 10:41a Sketcher
// More work on splitting actor legs and torso
// 
// 68    6/13/01 2:05p Sketcher
// I split the torso and leg animations for actor.  However, for it to work,
// the base.skl file must have the legbones marked as LEGBONE
// 
// 67    6/11/01 1:33p Sketcher
// Cleaned up Actor -- Added a think strategy pattern and a game component
// class
// 
// 66    6/05/01 3:51p Sketcher
// Added a new ParentRange conditional
// 
// 65    6/02/01 10:20a Sketcher
// Added a spawnactoraboveenemy event
// 
// 64    5/31/01 9:28a Steven
// Added regional damage stuff.
// 
// 63    5/30/01 6:03p Sketcher
// Actor now knows when its melee attack hit the world
// 
// 62    5/30/01 9:03a Sketcher
// Actors can now respond to hitscan weapons BEFORE they take damage
// 
// 61    5/29/01 8:18a Sketcher
// Working on allowing actors to respond defensively to hitscan weapons...
// Ahhh yeah!!!
// 
// 60    5/24/01 10:41a Sketcher
// Added additional Flag int and turret mode flag
// 
// 59    5/23/01 7:32a Sketcher
// Made changes to throw object and actor
// 
// 58    5/12/01 1:35p Sketcher
// Added a canWalkForward conditional, which is not yet working as intended
// 
// 57    5/11/01 1:25p Sketcher
// More stuff for quetzal... Added an AttachEnemy event
// 
// 56    5/04/01 12:04p Steven
// Added last_used_time.
// 
// 55    5/03/01 8:24p Steven
// Fixed up some is actor dead stuff.
// 
// 54    5/03/01 4:48a Sketcher
// Realized that the Valid Target flag put us over the 64 limit, so I changed
// it to a qboolean
// 
// 53    5/03/01 3:21a Sketcher
// Added the validtarget flag for actors, so that when other actors are set to
// targettype 2, they can exclude specific actors from possible targets
// 
// 52    5/03/01 2:53a Sketcher
// Added and turnon and turnoff current enemy AI for the stupid quetzal bird
// 
// 51    5/03/01 2:30a Sketcher
// Added more captured stuff for queztal
// 
// 50    5/01/01 2:43p Sketcher
// Added a global script command to check if an actor is dead
// 
// 49    5/01/01 1:56p Steven
// Added bone damage stuff.
// 
// 48    5/01/01 11:19a Sketcher
// Added an ActorFlag for swapping damage skins
// 
// 47    4/24/01 9:04a Sketcher
// Added an AIActivate Thread
// 
// 46    4/24/01 8:37a Sketcher
// Made Changes in NotifyOthersAtDeath 
// 
// 45    4/20/01 1:20p Sketcher
// projectiles can now "stick" into walls
// 
// 44    4/16/01 11:30a Steven
// Improved pathfinding.
// 
// 43    4/12/01 3:11p Sketcher
// modified the SpawnActorAtTag to offset above the tag rather than along the
// direction vector
// 
// 42    4/10/01 9:35a Sketcher
// Added stuff to check if other actors are dead from script
// 
// 41    4/05/01 7:04p Sketcher
// Quetzal stuff
// 
// 40    4/05/01 3:21p Steven
// Made actors blink every once in a while.
// 
// 39    4/05/01 11:42a Sketcher
// Changed FlyNodePath stuff from 0 based to 1 based
// 
// 38    4/04/01 9:31a Sketcher
// Added events to set the eyewatch constraints
// 
// 37    4/04/01 7:40a Sketcher
// Intermediate Checkin
// 
// 36    4/03/01 4:10p Sketcher
// added radiusdialog stuff
// 
// 35    4/02/01 3:58p Sketcher
// eyewatch is now working
// 
// 34    4/02/01 2:11p Sketcher
// Added an OnUse for Actors that allows a thread to be run when they are
// used.  Also added an EyeWatch Behavior set - though this part is not yet
// fully implemented
// 
// 33    4/02/01 9:24a Steven
// Added dependsint and fixed depends & dependsnot.
// 
// 32    3/30/01 9:48a Sketcher
// 
// 31    3/22/01 10:25a Sketcher
// Fixed some problems with the alertevent
// 
// 30    3/19/01 9:46a Sketcher
// Added Redemption effects, Redemption Health, and Redemptive Scalar
// 
// 29    3/15/01 10:13a Sketcher
// Once Again, I have added armor, and I think this time source will check
// things in correctly
// * 
// * 28    3/15/01 9:54a Sketcher
// * Crossing my fingers for source chafe again
// * 
// * 27    3/15/01 9:43a Sketcher
// * Trying Sourcesafe again
// * 
// * 26    3/15/01 9:35a Sketcher
// * Stupid Source Safe messed up the comments last time, I hope this check in
// * works
// 
// 16    2/06/01 2:19p Sketcher
// More Flying Behavior Changes
// 
// 15    1/29/01 10:49a Sketcher
// Made Changes for Idle State
// 
// 14    1/23/01 10:37a Sketcher
// Added Code to allow for Saving and Loading of Heuristic File
// 
// 13    1/16/01 2:11p Steven
// Script C merge.
// 
// 12    1/16/01 1:46p Sketcher
// Working on Adding a PlayerValidTarget toggle
// 
// 11    1/10/01 9:43a Sketcher
// Updated Enemy Management
// 
// 10    12/12/00 1:21p Sketcher
// Variables can now be set (and to a limited degree checked) from the state
// machine
// 
// 9     12/11/00 3:44p Sketcher
// Added an Alert Event.  Also, added a BroadcastAlert() and its companion
// G_BroadcastAlert()
// 
// 8     12/11/00 1:56p Steven
// Changed passing of most strings to const reference.
// 
// 7     12/11/00 1:55p Sketcher
// Added a SetActorFlag event
// 
// 6     12/11/00 12:24p Sketcher
// Working on adding a SetActorFlags Event
// 
// 5     12/11/00 12:15p Sketcher
// Added Resistances, and checks to make sure that any resistance over 100,
// does not add more than the max health of the creature.  
// 
// 4     12/11/00 9:34a Steven
// Changed passing of most vectors to const reference.
// 
// 3     12/07/00 1:49p Sketcher
// FOV is now based on a creature's headbone (If they have one) rather than
// the origin.  
//
// 142   7/27/00 10:55p Steven
// Added always give water stuff.
//
// 141   7/25/00 9:26p Steven
// Added damage allowed stuff.
//
// 140   7/24/00 6:08p Steven
// Added ignore pain from actors.
//
// 139   7/23/00 5:12p Steven
// Added check animname.
//
// 138   7/22/00 3:02p Steven
// Added boss health bar stuff.
//
// 137   7/22/00 1:22p Steven
// Added water level archiving.
//
// 136   7/22/00 1:18p Steven
// Added water level stuff.
//
// 135   7/17/00 3:16p Steven
// added increment/decrement num spawns stuff
//
// 134   7/17/00 2:57p Steven
// Made EV_Actor_SetTargetable extern.
//
// 133   7/15/00 3:11p Steven
// Added no pain sounds stuff.
//
// 132   7/13/00 3:43p Steven
// Added simple pathfinding and have moved stuff.
//
// 131   7/13/00 12:33p Steven
// Added ignore sounds stuff.
//
// 130   7/12/00 3:36p Steven
// Made lots of optimizations to actors.
//
// 129   7/06/00 4:44p Steven
// Made sure if no behavior was loaded to set the currentBehavior to "".
//
// 128   7/06/00 12:59p Steven
// Made a way to stimuli an attack without it attacking the entity that caused
// it pain and made spawned actors fade out almost immediately.
//
// 127   7/06/00 9:24a Steven
// Added damage angles stuff.
//
// 126   7/06/00 7:47a Steven
// Added enemy on ground  check.
//
// 125   7/05/00 5:17p Steven
// Added part of the code to make the player fail the level if she kills an
// innocent.
//
// 124   7/05/00 2:27p Steven
// Fixed reposting of events.
//
// 123   7/02/00 5:55p Steven
// Added SetIdleStateName.
//
// 122   7/02/00 5:09p Steven
// Some SpawnActor work.
//
// 121   7/02/00 1:10p Steven
// Added a RunThread event.
//
// 120   7/01/00 6:19p Steven
// Added falling stuff.
//
// 119   6/30/00 5:05p Steven
// Added on fire check.
//
// 118   6/30/00 11:40a Steven
// Added a blocked check.
//
// 117   6/30/00 10:20a Steven
// Added some stuck/off ground stuff.
//
// 116   6/29/00 5:21p Steven
// Added min and max height for in range stuff.
//
// 115   6/28/00 3:12p Steven
// Fixed a loadgame bug where I referenced statemap without checking to see if
// it wasn't NULL.
//
// 114   6/26/00 4:52p Steven
// Fixed loading of the current state and forced each actor to sleep or to
// wakeup.
//
// 113   6/24/00 7:01p Steven
// Fixed a loading statemap issue.
//
// 112   6/24/00 11:22a Steven
// Fixed a loadgame issue with statemaps.
//
// 111   6/22/00 5:33p Steven
// Added StopDialog.
//
// 110   6/22/00 3:53p Steven
// Fixed some saving/loading issues.
//
// 109   6/20/00 7:00p Steven
// Changed saved_anim_event and last_anim_event to strings from event pointers.
//
// 108   6/20/00 12:17p Steven
// Added SetMask stuff.
//
// 107   6/19/00 6:21p Steven
// Added die completely, bleed after death, next pain sound time, and touched
// stuff.
//
// 106   6/17/00 4:03p Steven
// Added GetStateAnims stuff.
//
// 105   6/15/00 6:55p Steven
// Added moving head while talking stuff.
//
// 104   6/10/00 1:50p Steven
// Added statemap caching.
//
// 103   6/08/00 1:44p Steven
// Added minimum melee height and immortal events.
//
// 102   6/07/00 5:33p Steven
// Added ignore monster clip stuff.
//
// 101   6/06/00 2:51p Steven
// Added no path stuff.
//
// 100   6/03/00 6:53p Steven
// Added blind stuff.
//
// 99    6/03/00 5:23p Steven
// Added saving of dialog stuff.
//
// 98    6/01/00 3:18p Steven
// Added changetype and checkinwater.
//
// 97    5/31/00 3:55p Steven
// Another actor save game pass.
//
// 96    5/30/00 7:06p Markd
// saved games 4th pass
//
// 95    5/27/00 3:32p Markd
// 2nd pass save games
//
// 94    5/27/00 2:32p Steven
// Added targetable stuff, attack actor stuff, and check player range.
//
// 93    5/26/00 6:21p Steven
// Added attackable by actors stuff, should attack entity, and goto prev stage.
//
// 92    5/24/00 3:13p Markd
// first phase of save/load games
//
// 91    5/23/00 6:43p Steven
// Moved small gib stuff to sentient.
//
// 90    5/23/00 10:18a Steven
// Made actors take a little time before doing babble dialog (half second or
// so) and added more items to actor random item spawns.
//
// 89    5/20/00 4:46p Steven
// Added send command and fixed saving of noise stuff.
//
// 88    5/19/00 3:43p Steven
// Added a noclip check.
//
// 87    5/19/00 11:24a Steven
// Some cleanup and added in saving of actors.
//
// 86    5/11/00 11:12a Steven
// Added pushing stuff and chargewater attack.
//
// 85    5/10/00 10:36a Steven
// Added can walk on others stuff, feet width stuff, last_origin, and
// next_find_enemy_time.
//
// 84    5/04/00 2:07p Steven
// More finishing move stuff.
//
// 83    5/04/00 12:46p Steven
// Finishing move stuff.
//
// 82    5/01/00 2:47p Steven
// Added allow fall and added volume and minimum distance to PlayDialog stuff.
//
// 81    4/28/00 5:38p Steven
// Added a last known enemy position variable.
//
// 80    4/24/00 2:44p Steven
// Fixed the initial state not getting initialized correctly.
//
// 79    4/21/00 5:40p Steven
// Added bounce off stuff and added spawn item stuff.
//
// 78    4/20/00 11:35a Steven
// Added stun stuff.
//
// 77    4/15/00 11:50a Steven
// Added spawnbloodygibs, added setmaxgibs and cleaned up some blood stuff.
//
// 76    4/14/00 3:58p Steven
// Added a staysolid event.
//
// 75    4/13/00 5:33p Steven
// Added a deathsink event, made it so only actors with deathsink turned on
// sink into ground after death and added a nomask event for the ghosts.
//
// 74    4/12/00 6:59p Steven
// Added an addhealth event.
//
// 73    4/11/00 6:37p Steven
// Added deathshrink stuff.
//
// 72    4/11/00 3:07p Steven
// Cleaned up a bunch of spawn stuff and merged SpawnGib and SpawnGibAtTag.
//
// 71    4/08/00 3:58p Steven
// Added fading out stuff, attackmode stuff and SpawnGibAtTag.
//
// 70    4/06/00 2:57p Steven
// Added death size event.
//
// 69    4/04/00 6:54p Steven
// Added ResetHeadEvent.
//
// 68    4/01/00 4:33p Steven
// Added chackname.
//
// 67    4/01/00 2:39p Steven
// Added checkcanflytoenemy.
//
// 66    4/01/00 11:10a Steven
// Added checkenemydead.
//
// 65    3/31/00 5:33p Steven
// Made EV_ActorOnlyShootable extern.
//
// 64    3/31/00 1:01p Steven
// Added GetRandomEnemy (for recruiter).
//
// 63    3/30/00 2:03p Steven
// Added SpawnBlood and added usegravity.
//
// 62    3/28/00 6:48p Steven
// Added optional tag_name to TestAttack.
//
// 61    3/24/00 6:31p Steven
// Started adding a better CheckBottom.
//
// 60    3/22/00 10:35a Steven
// Added SpawnNamedGib and GotoStage.
//
// 59    3/20/00 6:07p Steven
// Moved max_mouth_angle stuff to sentient, added setmouthangle, and got rid of
// idle_thread_label.
//
// 58    3/18/00 4:15p Steven
// Added an allowhangback event and added a check for allowhangback.
//
// 57    3/18/00 3:13p Steven
// Added a flag to keep track if the actor has been started yet or not.
//
// 56    3/18/00 1:16p Steven
// Added FireBullet to actor and added pain_angles stuff.
//
// 55    3/17/00 11:52a Steven
// Added jumping stuff.
//
// 54    3/14/00 12:07p Steven
// Added walkwatch stuff.
//
// 53    3/13/00 2:32p Steven
// Added a can_shoot_enemy check.
//
// 52    3/11/00 4:11p Steven
// Added have thing stuff.
//
// 51    3/11/00 2:16p Steven
// Added stun stuff (so the AI knows when the player is incapable of doing
// anything :)
//
// 50    3/11/00 11:35a Steven
// Moved all actor booleans to 1 actor flags variable.
//
// 49    3/08/00 6:41p Steven
// Fixed up checkcanseeenemy.
//
// 48    3/07/00 4:56p Steven
// Added bounce off stuff.
//
// 47    3/07/00 11:49a Steven
// Added checkenemyinfov.
//
// 46    3/04/00 11:49a Steven
// Added a stuck flag and added a check for it.
//
// 45    3/03/00 5:25p Steven
// Added fast_bullet stuff.
//
// 44    3/02/00 11:01a Steven
// Added checkenemyrelativeyaw.
//
// 43    2/25/00 7:03p Steven
// Added a way for actors to notify others of their kind when they are killed.
//
// 42    2/24/00 5:25p Steven
// Fixed up some of the removing anim done event stuff.
//
// 41    2/23/00 11:44a Steven
// Moved utility behaviors into actor.
//
// 40    2/21/00 6:24p Steven
// Added a torso tag and added an endthread event.
//
// 39    2/18/00 6:54p Steven
// Added warpto command.
//
// 38    2/17/00 5:42p Steven
// Lots of movement and path finding improvements.
//
// 37    2/16/00 10:41a Steven
// Added small pain stuff.
//
// 36    2/14/00 3:32p Steven
// Added checks so an actor can tell what weapons the player is using.
//
// 35    2/11/00 6:40p Steven
// Added pickup/throw stuff, added damage once stuff, and added small pain
// stuff.
//
// 34    2/09/00 10:34a Steven
// Added events to allow an actor's clipmask to be changed.
//
// 33    2/08/00 11:59a Steven
// Added stuff to let actor know he had blocked a hit.
//
// 32    2/08/00 11:38a Steven
// Some general cleanup, added a state name to idle event, added a state name
// to playdialog event, and added a checkheld check.
//
// 31    2/04/00 1:56p Steven
// Added a lot on the different modes (AI, script, idle and talk).
//
// 30    2/02/00 1:34p Steven
// Added head watching stuff and fixed checkmovingactorrange.
//
// 29    1/27/00 2:50p Steven
// Added checkincomingmeleeattackstart and checkincomingprojectilestart.
//
// 28    1/25/00 11:09a Steven
// Renamed health_less check to health.
//
// 27    1/24/00 6:56p Steven
// Added limiting number of spawned stuff by an actor.
//
// 26    1/21/00 6:44p Steven
// Added tempstate ability.
//
// 25    1/19/00 7:46p Aldie
// Fixed func_spawns of various types and removed some unused misc classes
//
// 24    1/19/00 12:10p Steven
// Added a set mouth angle event and cleaned up dialog stuff a little.
//
// 23    1/17/00 10:20p Jimdose
// Rewrote state system initialization.  Made conditionals defined with array.
// Made Evaluate functions early exit
//
// 22    1/14/00 5:01p Steven
// Added stage stuff.
//
// 21    1/13/00 7:08p Steven
// Lots and lots of cleanup.
//
// 20    1/05/00 7:25p Jimdose
// made angle functions all use the same coordinate system
// AngleVectors now returns left instead of right
// no longer need to invert pitch
//
// 19    12/22/99 5:11p Steven
// Added incoming melee and incoming projectiles checks, fixed CanWalkTo a
// little and readded turn speed stuff.
//
// 18    12/20/99 6:50p Steven
// Moved jumpxy to sentient.
//
// 17    12/19/99 8:21p Markd
// removed prioritystack.h from the header since it isn't used anymore
//
// 16    12/17/99 8:26p Jimdose
// got rid of unused vars and functions
//
// 15    12/17/99 6:11p Steven
// Added actor jump event.
//
// 14    11/19/99 4:54p Steven
// Added some deathfade stuff back in.
//
// 13    11/19/99 4:20p Steven
// Updated some of the actor saving stuff.
//
// 12    11/19/99 11:31a Steven
// Added commands so actors could tell each other to do things.
//
// 11    11/12/99 6:23p Steven
// Made state flags available to other part entities.
//
// 10    10/28/99 6:33p Markd
// Added fakeplayer ability, also added CloneEntity
//
// 9     10/27/99 10:30a Steven
// Added only shootable contents stuff.
//
// 8     10/21/99 5:24p Steven
// General AI work.
//
// 7     10/19/99 7:11p Steven
// Lots of AI work.
//
// 6     10/11/99 7:51p Steven
// Major cleanup, made it so scripting and ai could co-exist, and fixed some
// actor bugs.
//
// 5     10/07/99 5:34p Steven
// Some stimuli work.
//
// 4     10/01/99 1:39p Steven
// Event formatting.
//
// 3     9/27/99 4:42p Steven
// Fixed an animation/behavior issue dealing with the actor state machine.
//
// 2     9/20/99 5:22p Steven
// Added a canwalkto method.
//
// 1     9/10/99 10:53a Jimdose
//
// 1     9/08/99 3:15p Aldie
//
// 18    8/28/99 11:46a Steven
// Added some spinning plant stuff.
//
// 17    8/24/99 11:27a Steven
// More general AI work.
//
// 16    8/16/99 10:32a Steven
// More general AI work.
//
// 15    8/11/99 5:57p Steven
// More general AI work.
//
// 14    8/05/99 9:15a Steven
// New AI stuff.
//
//
// DESCRIPTION:
// Base class for character AI.
//

//==============================
// Forward Declarations
//==============================
class Actor;
class FindCoverMovement;
class FindFleeMovement;
class FindEnemyMovement;

#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "g_local.h"
#include "weapon.h"
#include "sentient.h"
#include "container.h"
#include "stack.h"
#include "navigate.h"
#include "behavior.h"
#include "scriptmaster.h"
#include "characterstate.h"
#include "actorstrategies.h"
#include "actorgamecomponents.h"

extern Event EV_Actor_Start;
extern Event EV_Actor_Dead;
extern Event EV_Actor_LookAt;
extern Event EV_Actor_TurnTo;
extern Event EV_Actor_FinishedBehavior;
extern Event EV_Actor_FinishedHeadBehavior;
extern Event EV_Actor_FinishedEyeBehavior;
extern Event EV_Actor_NotifyBehavior;
extern Event EV_Actor_NotifyHeadBehavior;
extern Event EV_Actor_NotifyEyeBehavior;
extern Event EV_Actor_FinishedMove;
extern Event EV_Actor_FinishedAnim;
extern Event EV_Actor_WalkTo;
extern Event EV_Actor_FallToDeath;
extern Event EV_Actor_RunTo;
extern Event EV_Actor_Anim;
extern Event EV_Actor_AttackFinished;
extern Event EV_Actor_Attack;
extern Event EV_Actor_AttackPlayer;
extern Event EV_Actor_AIOn;
extern Event EV_Actor_AIOff;
extern Event EV_Actor_AIDeaf;
extern Event EV_Actor_AIDumb;
extern Event EV_ActorIncomingProjectile;
extern Event EV_Anim_Done;
extern Event EV_ActorOnlyShootable;
extern Event EV_Actor_BounceOff;
extern Event EV_Actor_Push;
extern Event EV_Actor_Statemap;
extern Event EV_Actor_SetTargetable;

// Game Specific Events


// General Defines
#define MAX_ALIAS_NAME_LENGTH 32
#define MAX_INACTIVE_TIME     30.0

// Bones used by actor
#define ACTOR_MOUTH_TAG  0
#define ACTOR_HEAD_TAG   1
#define ACTOR_TORSO_TAG  2
#define ACTOR_LEYE_TAG   3
#define ACTOR_REYE_TAG   4

// Dialog stuff
#define MAX_DIALOG_PARAMETERS_LENGTH   100
#define MAX_DIALOG_PARM_LENGTH         64
#define MAX_DIALOG_PARMS               10
#define DIALOG_PARM_TYPE_NONE          0
#define DIALOG_PARM_TYPE_PLAYERHAS     1
#define DIALOG_PARM_TYPE_PLAYERHASNOT  2
#define DIALOG_PARM_TYPE_HAS           3
#define DIALOG_PARM_TYPE_HASNOT        4
#define DIALOG_PARM_TYPE_DEPENDS       5
#define DIALOG_PARM_TYPE_DEPENDSNOT    6
#define DIALOG_PARM_TYPE_DEPENDSINT    7

typedef struct
{
	byte type;
	char parm[ MAX_DIALOG_PARM_LENGTH ];
	char parm2[ MAX_DIALOG_PARM_LENGTH ];
} DialogParm_t;

typedef struct DialogNode_s
   {
	char alias_name[ MAX_ALIAS_NAME_LENGTH ];
	int random_flag;
	int number_of_parms;
	float random_percent;
	DialogParm_t parms[ MAX_DIALOG_PARMS ];
   struct DialogNode_s *next;
   } DialogNode_t;

typedef enum{
	DIALOG_TYPE_ANXIOUS,
	DIALOG_TYPE_NORMAL,
	DIALOG_TYPE_IGNORE,
	} DialogMode_t;

typedef enum{
	WEAPON_TYPE_PISTOL,
	WEAPON_TYPE_RIFLE,
	WEAPON_TYPE_SHOTGUN,
	WEAPON_TYPE_KNIFE,

	WEAPON_TYPE_NONE
	} WeaponType_t;

typedef enum{
	SHOOTMODE_TYPE_DUCK,
	SHOOTMODE_TYPE_SNIPE,

	SHOOTMODE_TYPE_NONE
	} ShootModeType_t;

//This weak-ass enum is here to allow for fly strafing.
typedef enum{
	FLY_FORWARD,
	FLY_RIGHT,
	FLY_LEFT,
	FLY_BACK
	} FlightDirectionType_t;

// State Var stuff
typedef struct
{
	str varName;
	str varValue;
} StateVar;



// Actor Type
typedef enum
	{
   IS_INANIMATE,
	IS_MONSTER,
	IS_ENEMY,
	IS_CIVILIAN,
	IS_FRIEND,
   IS_ANIMAL,	
	NUM_ACTORTYPES
	} actortype_t;



// Target Type
typedef enum
   {
	ATTACK_ANY,
	ATTACK_PLAYER_ONLY,
	ATTACK_ACTORS_ONLY,
	ATTACK_SCRIPTED_ONLY,
	ATTACK_LEVEL_INTERACTION
	} targetType_t;

// Paranoia State
typedef enum
   {
	PARANOIA_NORMAL,
	PARANOIA_AWAKE,
	PARANOIA_ALERT
	} paranoiaType_t;

// Stimuli types
#define STIMULI_ALL    -1
#define STIMULI_NONE    0
#define STIMULI_SIGHT   (1<<0)
#define STIMULI_SOUND   (1<<1)
#define STIMULI_PAIN    (1<<2)
#define STIMULI_SCRIPT  (1<<3)



// State flags
#define STATE_FLAG_IN_PAIN			(1<<0)
#define STATE_FLAG_MELEE_HIT		(1<<1)
#define STATE_FLAG_TOUCHED			(1<<2)
#define STATE_FLAG_ACTIVATED		(1<<3)
#define STATE_FLAG_USED				(1<<4)
#define STATE_FLAG_TWITCH			(1<<5)
#define STATE_FLAG_BLOCKED_HIT	(1<<6)
#define STATE_FLAG_SMALL_PAIN		(1<<7)
#define STATE_FLAG_OTHER_DIED		(1<<8)
#define STATE_FLAG_STUCK			(1<<9)
#define STATE_FLAG_NO_PATH			(1<<10)


// Actor modes
#define ACTOR_MODE_NONE			0
#define ACTOR_MODE_IDLE			1
#define ACTOR_MODE_AI			2
#define ACTOR_MODE_SCRIPT		3
#define ACTOR_MODE_TALK			4


// Pain types
#define PAIN_SMALL  0
#define PAIN_BIG    1


// Part stuff
typedef struct
{
	EntityPtr ent;
	unsigned int state_flags;
} part_t;



// Actor flags
typedef enum{
	ACTOR_FLAG_NOISE_HEARD,
	ACTOR_FLAG_INVESTIGATING,
	ACTOR_FLAG_DEATHGIB,
	ACTOR_FLAG_DEATHFADE,
	ACTOR_FLAG_NOCHATTER,
	ACTOR_FLAG_INACTIVE,
	ACTOR_FLAG_ANIM_DONE,
	ACTOR_FLAG_STATE_DONE_TIME_VALID,
	ACTOR_FLAG_AI_ON,
	ACTOR_FLAG_LAST_CANSEEENEMY,
	ACTOR_FLAG_LAST_CANSEEENEMY_NOFOV,
	ACTOR_FLAG_DIALOG_PLAYING,
	ACTOR_FLAG_RADIUS_DIALOG_PLAYING,
	ACTOR_FLAG_ALLOW_TALK,
	ACTOR_FLAG_DAMAGE_ONCE_ON,
	ACTOR_FLAG_DAMAGE_ONCE_DAMAGED,
	ACTOR_FLAG_BOUNCE_OFF,
	ACTOR_FLAG_NOTIFY_OTHERS_AT_DEATH,
	ACTOR_FLAG_HAS_THING1,
	ACTOR_FLAG_HAS_THING2,
	ACTOR_FLAG_HAS_THING3,
	ACTOR_FLAG_HAS_THING4,
	ACTOR_FLAG_LAST_ATTACK_HIT,
	ACTOR_FLAG_STARTED,
	ACTOR_FLAG_ALLOW_HANGBACK,
	ACTOR_FLAG_USE_GRAVITY,
	ACTOR_FLAG_SPAWN_FAILED,
	ACTOR_FLAG_FADING_OUT,
	ACTOR_FLAG_DEATHSHRINK,
	ACTOR_FLAG_DEATHSINK,
	ACTOR_FLAG_STAYSOLID,
	ACTOR_FLAG_STUNNED,
	ACTOR_FLAG_ALLOW_FALL,
	ACTOR_FLAG_FINISHED,
	ACTOR_FLAG_IN_LIMBO,
	ACTOR_FLAG_CAN_WALK_ON_OTHERS,
	ACTOR_FLAG_PUSHABLE,
	ACTOR_FLAG_LAST_TRY_TALK,
	ACTOR_FLAG_ATTACKABLE_BY_ACTORS,
	ACTOR_FLAG_TARGETABLE,
	ACTOR_FLAG_ATTACK_ACTORS,
	ACTOR_FLAG_IMMORTAL,
	ACTOR_FLAG_TURNING_HEAD,
	ACTOR_FLAG_MOVING_EYES,
	ACTOR_FLAG_DIE_COMPLETELY,
	ACTOR_FLAG_BLEED_AFTER_DEATH,
	ACTOR_FLAG_IGNORE_STUCK_WARNING,
	ACTOR_FLAG_IGNORE_OFF_GROUND_WARNING,
	ACTOR_FLAG_ALLOWED_TO_KILL,
	ACTOR_FLAG_TOUCH_TRIGGERS,
	ACTOR_FLAG_IGNORE_WATER,
	ACTOR_FLAG_NEVER_IGNORE_SOUNDS,
	ACTOR_FLAG_SIMPLE_PATHFINDING,
	ACTOR_FLAG_HAVE_MOVED,
	ACTOR_FLAG_NO_PAIN_SOUNDS,
	ACTOR_FLAG_UPDATE_BOSS_HEALTH,
	ACTOR_FLAG_IGNORE_PAIN_FROM_ACTORS,
	ACTOR_FLAG_DAMAGE_ALLOWED,
	ACTOR_FLAG_ALWAYS_GIVE_WATER,
	ACTOR_FLAG_AT_COVER_NODE,
	ACTOR_FLAG_WAIT_FOR_NEW_ENEMY,
	ACTOR_FLAG_TAKE_DAMAGE,
	ACTOR_FLAG_USE_DAMAGESKINS,
	ACTOR_FLAG_CAPTURED,
	ACTOR_FLAG_TURRET_MODE,
	ACTOR_FLAG_INCOMING_HITSCAN,
	ACTOR_FLAG_RESPONDING_TO_HITSCAN,
	ACTOR_FLAG_MELEE_HIT_WORLD,
	ACTOR_FLAG_TORSO_ANIM_DONE,
	ACTOR_FLAG_WEAPON_READY,	
	
	ACTOR_FLAG_MAX
	} ActorFlags;


//Global
Actor *GetActor( const str &actor_name );
typedef SafePtr<Actor> ActorPtr;

class Actor : public Sentient
	{
	public:
		
		// Animations
		str								newanim;
		int								newanimnum;
		str								animname;
		Event								*newanimevent;

		str                        newTorsoAnim;
		int                        newTorsoAnimNum;
		str                        TorsoAnimName;
		Event                      *newTorsoAnimEvent;		

		// Movement
      stepmoveresult_t           lastmove;
      float                      forwardspeed;
		PathPtr							path;
		Vector							move;
		Vector							movedir;
		float								movespeed;
		Vector							movevelocity;
		float								totallen;
		float								turnspeed;
		Vector							animdir;
		Vector							divedir;
		Vector							startpos;
		
		// Target Types
		actortype_t                actortype;
		targetType_t					targetType;
		qboolean                   validTarget;

		// Behaviors		
		BehaviorPtr						behavior;
		str								currentBehavior;

		BehaviorPtr						headBehavior;
		str								currentHeadBehavior;

		BehaviorPtr                eyeBehavior;
		str                        currentEyeBehavior;

		BehaviorPtr                torsoBehavior;
		str                        currentTorsoBehavior;
		
		// Enemy Mangement
		EntityPtr						currentEnemy;

		// Throw ObjectStuff
		EntityPtr                  currentThrowObject;
		qboolean                   haveThrowObject;

		
		// Flags
		unsigned int					actor_flags1;
		unsigned int					actor_flags2;
		unsigned int               actor_flags3;
		
		// Sound Stuff for "hearing"
		Vector							noise_position;
		int								soundType;
		float								noise_time;
		
		// Vision Stuff for "seeing"
		float								fov;
		float								fovdot;
		float								vision_distance;

		// Some Dialog and Babble Stuff
		float								chattime;
		float								nextsoundtime;
		DialogMode_t					DialogMode;
		float                      radiusDialogRange;
		DialogNode_t					*dialog_list;
		float								dialog_done_time;
		str								dialog_state_name;
		str								dialog_old_state_name;
		

		// Thread Management
		ThreadPtr						scriptthread;
		ThreadPtr						actorthread;
      str                        kill_thread;
		str                        escape_thread;
		str                        captured_thread;
		str                        activate_thread;
		str                        onuse_thread_name;
		str                        ondamage_thread;
		str                        alert_thread;
		
		// Pain and Miscellaneous Damage
      float                      pain_threshold;
		float					         next_drown_time;
		float					         air_finished;
		int								pain_type;
		Vector							pain_angles;
		int								bullet_hits;
		
		// State map and "Thinking" stuff
		str								statemap_name;
		StateMap							*statemap;
		State								*currentState;
		float								state_time;
		int								times_done;
		float								state_done_time;
		int								stimuli;
		int								permanent_stimuli;
		str								idle_thread;
		float								last_enemy_sight_time;
		float								next_enemy_try_sight_time;
		float								next_try_sleep_time;
		float								last_time_active;

		
		// Eye Angle stuff
		float                      maxEyeYawAngle;
		float                      minEyeYawAngle;
		float                      maxEyePitchAngle;
		float                      minEyePitchAngle;
		
		// Saved Items (from switching to talk mode and stuff)
		int								saved_mode;
		BehaviorPtr						saved_behavior;
		BehaviorPtr						saved_headBehavior;
		BehaviorPtr						saved_eyeBehavior;
		BehaviorPtr                saved_torsoBehavior;
		ThreadPtr						saved_scriptthread;
		ThreadPtr						saved_actorthread;
		str								saved_anim_name;
		str								saved_state_name;
		str								saved_anim_event_name;


		// Part Stuff
		str								part_name;
		Container<part_t>				parts;
		

		// Incoming Attack Stuff
		EntityPtr						incoming_proj;
		float								incoming_time;
		qboolean							incoming_bullet;

		// Basic Data about the Actor
		str								name;
		float								max_inactive_time;
      Vector                     eyeoffset;
      float                      last_jump_time;
		str								enemytype;
		float                      actorrange_time;
		float								last_height;
		EntityPtr						last_ent;
		float                      canseeenemy_time;
		int								stage;
		int								num_of_spawns;
		ActorPtr							spawnparent;
		Vector							watch_offset;
		Vector							last_attack_pos;
		Vector							last_attack_enemy_pos;
		EntityPtr						last_attack_entity_hit;
		Vector							last_attack_entity_hit_pos;
		int								mode;
		Vector							last_known_enemy_pos;
		float								feet_width;
		Vector							last_origin;
		float								next_find_enemy_time;
		float								minimum_melee_height;
		float								damage_angles;
		float								real_head_pitch;
		float								next_pain_sound_time;
		float								last_ground_z;
		float								water_level;
		str								emotion;
		float								next_blink_time;
		float                      actor_to_actor_damage_modifier;		

		float								last_used_time;
		float                      hitscan_response_chance;
		int                        shotsFired;
		int                        ondamage_threshold;
		
		//Paranoia
		float                      paranoia;
		float                      paranoiaTime;
		paranoiaType_t             paranoiaType;

      // Weapon Stuff
		WeaponType_t               weaponType;
		int                        maxClipSize;
		ShootModeType_t            shootmode;

		// General Stuff (stuff I can't think of a group for)
		Container<StateVar *>		stateVarList;
		EntityPtr						trigger;
		
		
		unsigned int					state_flags;
		str								command;
		
		
		str								idle_state_name;
		float								next_player_near;		


		str								last_anim_event_name;
		str                        last_torso_anim_event_name;

		EntityPtr						pickup_ent;

		float								stunned_end_time;

		Container<str>					spawn_items;
		float								spawn_chance;

		str								bounce_off_effect;
		Container<int>					can_be_finsihed_by_mods;

		
		float								max_boss_health;

		qboolean                   haveAttached;

		static Condition<Actor>    Conditions[];

		Container<Conditional *>	conditionals;


		// Strategies
		ActorThink*                thinkStrategy;

		// GameComponent		
		ActorGameComponent*			gameComponent;
		
		// SplineStuff
		float                      currentSplineTime;

		
      CLASS_PROTOTYPE( Actor );

      // Initialization functions
											Actor();
											~Actor();
		void								Start( Event *ev );

      void                       Sleep( void );
      void                       Sleep( Event *ev );
      void                       Wakeup( void );
      void                       Wakeup( Event *ev );
		void								SetTargetType ( Event *ev );		
		void                       InitGameComponent( void );

      // Vision functions
		qboolean							WithinVisionDistance( Entity *ent	);
		qboolean							InFOV( const Vector &pos, float check_fov, float check_fovdot );
		qboolean							InFOV( const Vector &pos );
		qboolean							InFOV( Entity *ent );
		qboolean							CanSeeFOV( Entity *ent );
		qboolean							CanSeeFrom( const Vector &pos, Entity *ent );
		qboolean							CanSee( Entity *ent );
      qboolean                   EnemyCanSeeMeFrom( const Vector &pos );
		qboolean							CanSeeEnemyFrom( const Vector &pos );
		qboolean							CanReallySee( Entity *ent );

      // Combat functions
		void                       MeleeEvent( Event *ev );
		void                       ChargeWater( Event *ev );
		void                       DamageOnceStart( Event *ev );
		void                       DamageOnceStop( Event *ev );
		void                       DamageAllowed( Event *ev );
		virtual qboolean				CanShootFrom( const Vector &pos, Entity *ent, qboolean usecurrentangles );
		virtual qboolean			   CanShoot( Entity *ent, qboolean usecurrentangles );
		void								FireProjectile( Event *ev );
		void								FireBullet( Event *ev );
		void								SaveAttack( const Vector &orig, const Vector &dir );
		qboolean							TestAttack( const str &tag_name );
		void								IncomingProjectile( Event *ev );
		qboolean							EntityHasFireType( Entity *ent, firetype_t fire_type	);
		void								DamageEnemy( Event *ev );
		void								DamageSelf( Event *ev );
		void								TurnTowardsEnemy( Event *ev );
		void								TurnTowardsPlayer( Event *ev );
		void								AttackModeEvent( Event *ev );
		qboolean							ShouldAttackEntity( Entity *ent );
		void								SetAttackableByActors( Event *ev );
		void								SetAttackActors( Event *ev );
		void								MinimumMeleeHeight( Event *ev );
		void								SetDamageAngles( Event *ev );
		void								SetImmortal( Event *ev );
		void                       SetTakeDamage( Event *ev );
		qboolean							IsImmortal( void );
		qboolean                   TakeDamage( void );
		void                       SetEnemyAttached ( Event *ev );
		void                       ReloadWeapon( Event *ev );


		// Enemy management
		void                       ClearEnemies( void );
		void								ClearCurrentEnemy( Event *ev ) { currentEnemy = NULL;	}
  		qboolean							HasEnemies( void );
		qboolean							IsEnemy( Entity *ent );
		void								MakeEnemy( Entity *ent, qboolean force = false );
		void                       MakeEnemy( Event *ev );
		qboolean							Likes( Entity *ent );
		qboolean							Hates( Entity *ent );
		void								FindEnemy( void );
		Entity							*FindNearestEnemy( void );
		void								GetNearestEnemy( Event *ev );
		void								GetRandomEnemy( Event *ev );
		void                       MakeThrowObjectEnemy( Event *ev );		

		// Targeting functions
		qboolean							CloseToEnemy( const Vector &pos, float howclose );
		qboolean							EntityInRange( Entity *ent, float range, float min_height, float max_height );
		void                       EyeOffset( Event *ev );

      // Actor type script commands
		void								FriendEvent( Event *ev );
		void								CivilianEvent( Event *ev );
		void								EnemyEvent( Event *ev );
      void								InanimateEvent( Event *ev );
		void								MonsterEvent( Event *ev );
		void								AnimalEvent( Event *ev );
		void								SetEnemyType( Event *ev );
		
		void								SetOnUseThread( Event *ev );
		void                       ClearOnUseThread( Event *ev );
		void                       SetRadiusDialogRange( Event *ev );
		void                       SetDialogMode( Event *ev );		
		void                       SetActivateThread( Event *ev );
		void                       SetAlertThread( Event *ev );
		void                       SetValidTarget( Event *ev );
		void                       AttachCurrentEnemy( Event *ev );
		void                       AttachActor( Event *ev );
		void                       PickupThrowObject( Event *ev );
		void                       TossThrowObject( Event *ev );
		void                       SetTurretMode( Event *ev );
		void                       SetOnDamageThread( Event *ev );

		// State machine functions
		void								SetIdleStateName( Event *ev	);
		void								SetState( const char *state_name );
		void								InitState( void );
		void								LoadStateMap( Event *ev	);
		void								ProcessActorStateMachine( void );

      // Thread management	
		void								RunThread( Event *ev );
		void                       RunThread( const str &thread_name );
		void								SetThread( const str &filename, const str &label );		
		void                       RunDamageThread( void );
		void                       RunAlertThread( Event *ev );		

      // Behavior management
		void								SendMoveDone( CThread *script_thread );
		void								EndBehavior( void );
		void								EndHeadBehavior( void );
		void                       EndEyeBehavior( void );
		void                       EndTorsoBehavior( void );
		void								SetBehavior( Behavior *newbehavior, Event *argevent = NULL, CThread *thread = NULL );
		void								SetHeadBehavior( Behavior *newbehavior, Event *argevent = NULL, CThread *thread = NULL );
		void                       SetEyeBehavior( Behavior *newbehavior, Event *argevent = NULL, CThread *thread = NULL );
		void                       SetTorsoBehavior( Behavior *newbehavior, Event *argevent = NULL, CThread *thread = NULL );
		void								FinishedBehavior( Event *ev );
		void								FinishedHeadBehavior( Event *ev );
		void                       FinishedEyeBehavior( Event *ev );
		void                       FinishedTorsoBehavior( Event *ev );
		void								NotifyBehavior( Event *ev );
		void								NotifyHeadBehavior( Event *ev );
		void                       NotifyEyeBehavior( Event *ev );
		void                       NotifyTorsoBehavior( Event *ev );
		void								EndAllBehaviors( void );

      // Path and node management
		PathNode							*NearestNodeInPVS( const Vector &pos );
		void								SetPath( Path *newpath );
		void								ReserveNodeEvent( Event *ev );
		void								ReleaseNodeEvent( Event *ev );

      // Animation control functions
		void								RemoveAnimDoneEvent( void );
		void								ChangeAnim( void );
      qboolean							SetAnim( const str &anim, Event *ev = NULL, bodypart_t part = legs );
		qboolean							SetAnim( const str &anim, Event &ev, bodypart_t part = legs );
		void								AnimDone( Event *ev );
		void                       TorsoAnimDone( Event *ev );
	
      // Script commands
		void								IdleEvent( Event *ev );
		void								LookAt( Event *ev );
		void								TurnToEvent( Event *ev );
		void                       HeadAndEyeWatchEvent ( Event *ev );
		void								HeadWatchEvent( Event *ev );		
		void								ResetHeadEvent( Event *ev );
		void                       EyeWatchEvent( Event *ev );
		void                       ResetEyeEvent( Event *ev );
		void                       ResetTorsoEvent( Event *ev );
		void                       FallToDeathEvent( Event *ev );
		void								WalkTo( Event *ev );
		void								WalkWatch( Event *ev );	
		void								RunTo( Event *ev );
		void								WarpTo( Event *ev );
		void								PickupEnt( Event *ev );
		void								ThrowEnt( Event *ev );
      void								AttackEntity( Event *ev );
      void                       AttackPlayer( Event *ev );
		void								JumpToEvent( Event *ev );      
		void								Anim( Event *ev );
		void                       RepostEvent( Event *ev, Event &event_type );
		void                       GiveActorWeapon( Event *ev );
		void                       RemoveActorWeapon( Event *ev );		
	   void                       FollowWayPoints( Event *ev );

      // Script conditionals
		void								IfEnemyVisibleEvent( Event *ev );
		void								IfNearEvent( Event *ev );
		void								IfCanHideAtEvent( Event *ev );
		void								IfEnemyWithinEvent( Event *ev );

      // Sound reaction functions
		void								NoPainSounds( Event *ev );
		void								HeardSound( Event *ev );
		qboolean							IgnoreSounds( void );
		void								NeverIgnoreSounds( Event *ev );
		void								BroadcastAlert( float pos = SOUND_RADIUS );
		void								BroadcastAlert( Event *ev );
		void                       BroadcastAlert( float pos, int soundtype );
											
      // Pain and death related functions
		void								Pain( Event *ev );
		void								StunEvent( Event *ev );
		void								CheckStun( void );
		void								Dead( Event *ev );
		void								Killed( Event *ev );
      void                       KilledEffects( Entity *attacker );
		void								SetDieCompletely( Event *ev );
		void								SetBleedAfterDeath( Event *ev );
      void                       RemoveUselessBody( Event *ev );
		void                       SetPainThresholdEvent( Event *ev );
      void                       SetKillThreadEvent( Event *ev );
		void                       DeathFadeEvent( Event *ev );
		void                       DeathShrinkEvent( Event *ev );
		void                       DeathSinkEvent( Event *ev );
		void                       StaySolidEvent( Event *ev );
		void								SpawnGib( Event *ev );
		void								SpawnGibAtTag( Event *ev );
		void								RealSpawnGib( qboolean use_tag, Event *ev );
		void								SpawnNamedGib( Event *ev );
		float								SpawnGetTime( float vel, const Vector &orig, const Vector &gib_mins, const Vector &gib_maxs );
		void								SpawnBlood( Event *ev );
		void								Suicide( Event *ev );
		void								SetDeathSize( Event *ev );
		void								FadeEvent( Event *ev );
		qboolean                   RespondToHitscan( void );		

      // Movement functions
		void								SimplePathfinding( Event *ev );
		void								SetCanWalkOnOthers( Event *ev );
		void								SetFeetWidth( Event *ev );
      void								ForwardSpeedEvent( Event *ev );
      void								SwimEvent( Event *ev );
		void								FlyEvent( Event *ev );
		void								NotLandEvent( Event *ev );
      qboolean							CanMoveTo( const Vector &pos );
		qboolean							CanWalkTo( const Vector &pos, float bounding_box_extra = 0, int entnum = ENTITYNUM_NONE );
		qboolean							CanWalkToFrom( const Vector &origin, const Vector &pos, float bounding_box_extra = 0, int entnum = ENTITYNUM_NONE );
		void								Accelerate( const Vector &steering );
		void								CalcMove( void );
		void								setAngles( const Vector &ang );
		stepmoveresult_t				WaterMove( void );
		stepmoveresult_t				AirMove( void );
		stepmoveresult_t				TryMove( void );
		void								Push( Event *ev );
		qboolean							Push( const Vector &dir );
		void								Pushable( Event *ev );
      void                       CheckWater( void );
		float								JumpTo( PathNode * goal, float speed , float vertical_speed = 0);
      float                      JumpTo( Entity * goal, float speed , float vertical_speed = 0 );
      float                      JumpTo( const Vector &targ, float speed , float vertical_speed = 0 );

      // Debug functions
      void                       ShowInfo( void );

		// Stimuli functions
		void								Stimuli( int stimuli, Entity *ent, qboolean force = false );
		void								Stimuli( int stimuli, const Vector &pos );
		void								Stimuli( int stimuli, const Vector &pos, int sound_Type );
		void								StimuliNoAttack( int stimuli );
		void								Deaf( Event *ev );
		void								PermanentDeaf( Event *ev );
		void								PermanentBlind( Event *ev );
		qboolean							IsBlind( void );
		void								Dumb( Event *ev );
		void								SetIdleThread( Event *ev );
		bool								RespondToStimuli( int new_stimuli );
		void								ActivateAI( void );
		void								TurnAIOn( Event *ev );
		void                       TurnAIOn( void );
		void								TurnAIOff( Event *ev );
		void                       TurnAIOff( void );		

		// Parts functions

		void								RegisterParts( Event *ev );
		void								RegisterSelf( Event *ev );
		void								PartName( Event *ev );
		Actor								*FindPartActor( const char *name );
		void								SendCommand( Event *ev );

		// Dialog functions
		qboolean							DialogExists( str aliasName );
		void								AddDialog ( Event *ev );
		DialogNode_t					*NewDialogNode(void);
		void								AddDialogParms( DialogNode_t *dialog_node, Event *ev );
		void								PlayDialog( Sentient *user, float volume = -1.0, float min_dist = -1.0,
											const char *dialog_name = NULL, const char *state_name = NULL );
		void								FreeDialogList( void );
		void								DialogDone( Event *ev );
		void								PlayDialog( Event *ev );
		void                       PlayRadiusDialog( Sentient *user, const str &dialog_alias );
		void								StopDialog( Event *ev );
		void                       StopDialog( void );
		void								HeadTwitch( Event *ev );
		void								HeadTwitchEveryFrame( Event *ev );
		float								GetDialogRemainingTime( void );
		void								SetMouthAngle( Event *ev );
		void                       DialogAnimDone( Event *ev );

		// Mode functions
		qboolean							ModeAllowed( int new_mode );
		void								StartMode( int new_mode );
		void								EndMode( void );
		void								SaveMode( void );
		void								RestoreMode( void );

		// Finishing functions
		qboolean							CanBeFinished( void );
		qboolean							CanBeFinishedBy( int meansofdeath );
		void								SetCanBeFinishedBy( Event *ev );
		void								Finish( int meansofdeath );
		void								StartLimbo( void );
		qboolean							InLimbo( void );

      // General functions
		void								AlwaysGiveWater( Event *ev );
		void								IgnorePainFromActors( Event *ev );
		void								UpdateBossHealth( Event *ev );
		void								SetMaxBossHealth( Event *ev );
		void								SetWaterLevel( Event *ev );
		void								IncrementNumSpawns( Event *ev );
		void								DecrementNumSpawns( Event *ev );
		void								TouchTriggers( Event *ev );
		void								IgnoreWater( Event *ev );
		void								SetNotAllowedToKill( Event *ev );
		void								IgnorePlacementWarning( Event *ev );
		void								SetTargetable( Event *ev );
		qboolean							CanTarget( void );
		void								AddSpawnItem( Event *ev );
		void								SetSpawnChance( Event *ev );
		void								ClearSpawnItems( Event *ev );
		void								SpawnItems( void );
		void								SpawnItem( const str &spawn_item_name );
		qboolean							CanJump( void );
		void								SetUseGravity( Event *ev );
		void								SetAllowFall( Event *ev );
		void								SetUseMovement( Event *ev );
		void								SetHaveThing( Event *ev );
		void                       SetHaveThing( int thing_number,qboolean thing_bool );
		void                       SetActorFlag( str flag_name, qboolean flag_value );
		void								SetActorFlag( int flag, qboolean flag_value );
		void								SetActorFlag( Event *ev );
		qboolean							GetActorFlag( int flag );
		void								SetBounceOff( Event *ev );
		void								BounceOffEvent( Event *ev );
		void								SetBounceOffEffect( Event *ev );
		void								NotifyOthersAtDeath( Event *ev );
		void								NotifyOthersOfDeath( void );
		void								GotoNextStage( Event *ev );
		void								GotoPrevStage( Event *ev );
		void								GotoStage( Event *ev );
		void								Pickup( Event *ev );
		void								Throw( Event *ev );
		void								SetWatchOffset( Event *ev );
		void								SetMaxInactiveTime( Event *ev );
		void                       SetTurnSpeed( Event *ev );
		void					         SetHealth( Event *ev );
		void								SetMaxHealth( Event *ev );
		void					         AddHealth( Event *ev );
		void								SetVar( Event *ev );
		virtual void					setSize( Vector min, Vector max );
		void                       SetFov( Event *ev );
      void                       SetVisionDistance( Event *ev );
		void                       NoChatterEvent( Event *ev );
		virtual void					Chatter( const char *sound, float chance = 10, float volume = 1.0f, int channel = CHAN_VOICE );
      void								ActivateEvent( Event *ev );
		void								UseEvent( Event *ev );
		void								Think( void );
		void								Active( Event *ev );
		bool								IsEntityAlive( Entity *ent );
		void								Name( Event *ev );
		void								SetupTriggerField( Event *ev );
		void								TriggerTouched( Event *ev );
		qboolean							GetClosestTag( const str &tag_name, int number_of_tags, const Vector &target, Vector *orig );
		void								AddStateFlag( unsigned int flag );
		void								ClearStateFlags( void );		
		void								SpawnActorAtTag( Event *ev );
		void								SpawnActorAtLocation( Event *ev );
		void                       SpawnActorAboveEnemy( Event *ev );
		void								SpawnActor( const str &model_name, const Vector &orig, const Vector &ang, int	how_many, qboolean attack, float width, float height, qboolean force = false );
		void								TryTalkToPlayer( void );
		void								AllowTalk( Event *ev );
		void								AllowHangBack( Event *ev );
		void								SolidMask( Event *ev );
		void								IgnoreMonsterClip( Event *ev );
		void								NotSolidMask( Event *ev );
		void								NoMask( Event *ev );
		void								SetMask( Event *ev );
		void                       SetWeaponReady( Event *ev );
		int								ActorFlag_string_to_int( str actorflagstr );
		void								ArmorDamage( Event *ev );
		
		//Paranoia Stuff
		void                       increaseParanoia( Event *ev );
		void                       increaseParanoia(int amount);
		void                       decreaseParanoia( Event *ev );
		void                       decreaseParanoia(int amount);
		void                       updateParanoia( int stimuli );
		void                       updateParanoiaType( Event *ev );
		void                       updateParanoiaType( unsigned int pType );
		

		void                       SetActorToActorDamageModifier( Event *ev );

		qboolean							CheckBottom( void );

		void								ChangeType( Event *ev );

		void								GetStateAnims( Container<const char *> *c );

		void								Touched( Event *ev );

		void								SetEmotion( Event *ev );
		void								TryBlink( void );

		void                       ReturnProjectile ( Event *ev );

		void                       SetEyeAngles( Event *ev );

		void								checkActorDead( Event *ev );
		qboolean							checkActorDead( Actor *act );
		
		qboolean							checkplayerrange ( float range , float height = 0 );		

		void                       SetFlagOnEnemy( Event *ev );
		void                       TurnOnEnemyAI( Event *ev );
		void                       TurnOffEnemyAI( Event *ev );
		void                       SetHitscanResponse( Event *ev );
		
		void                       SetShootMode( Event *ev );
		void                       HandleGameSpecificEvent( Event *ev );		

		FlightDirectionType_t      FlightDirection;
		Vector                     FlightDir;

      // State machine conditions
      qboolean                   returntrue( Conditional &condition );
		qboolean                   checkanimname( Conditional &condition );
      qboolean                   checkinactive( Conditional &condition );
      qboolean                   checkanimdone( Conditional &condition );
		qboolean                   checktorsoanimdone( Conditional &condition );
      qboolean                   checkdead( Conditional &condition );
      qboolean                   checkhaveenemy( Conditional &condition );
		qboolean                   checkenemydead( Conditional &condition );
		qboolean                   checkenemydead( void );
		qboolean                   checkenemynoclip( Conditional &condition );
      qboolean                   checkcanseeenemy( Conditional &condition );
		qboolean                   checkcanshootenemy( Conditional &condition );
		qboolean                   checkenemyinfov( Conditional &condition );
		qboolean                   checkenemyonground( Conditional &condition );
		qboolean                   checkenemyrelativeyaw( Conditional &condition );
		qboolean							checkenemyyawrange( Conditional &condition );
      qboolean                   checkcanjumptoenemy( Conditional &condition );
		qboolean                   checkcanflytoenemy( Conditional &condition );
      qboolean                   checkinpain( Conditional &condition );
		qboolean                   checksmallpain( Conditional &condition );
		qboolean                   checkpainyaw( Conditional &condition );
		qboolean                   checkpainpitch( Conditional &condition );
		qboolean                   checkstunned( Conditional &condition );
		qboolean                   checkfinished( Conditional &condition );
      qboolean                   checkmeleehit( Conditional &condition );
		qboolean                   checkblockedhit( Conditional &condition );
		qboolean                   checkblocked( Conditional &condition );
		qboolean                   checkonfire( Conditional &condition );
		qboolean                   checkotherdied( Conditional &condition );
		qboolean                   checkstuck( Conditional &condition );
		qboolean                   checknopath( Conditional &condition );
      qboolean                   checkbehaviordone( Conditional &condition );
		qboolean							checkheadbehaviordone( Conditional &condition );
		qboolean                   checkeyebehaviordone( Conditional &condtion );
		qboolean                   checktorsobehaviordone( Conditional &condition );
      qboolean                   checktimedone( Conditional &condition );
      qboolean                   checkdone( Conditional &condition );
      qboolean                   checkenemyrange( Conditional &condition );
		qboolean                   checkplayerrange( Conditional &condition );
		qboolean                   checkparentrange ( Conditional &condition );
      qboolean                   checkmovingactorrange( Conditional &condition );
      qboolean                   checkchance( Conditional &condition );
      qboolean                   checkstatetime( Conditional &condition );
      qboolean                   checktimesdone( Conditional &condition );
      qboolean                   checkmeansofdeath( Conditional &condition );
      qboolean                   checknoiseheard( Conditional &condition );
      qboolean                   checkpartstate( Conditional &condition );
      qboolean                   checkpartflag( Conditional &condition );
		qboolean                   checkpartdead( Conditional &condition );
		qboolean							checknumspawns( Conditional &condition );
      qboolean                   checkcommand( Conditional &condition );
      qboolean                   checktouched( Conditional &condition );
      qboolean                   checkactivated( Conditional &condition );
      qboolean                   checkused( Conditional &condition );
      qboolean                   checktwitch( Conditional &condition );
      qboolean                   checkhealth( Conditional &condition );
      qboolean                   checkonground( Conditional &condition );
		qboolean                   checkinwater( Conditional &condition );
      qboolean                   checkincomingmeleeattack( Conditional &condition );
      qboolean                   checkincomingprojectile( Conditional &condition );
		qboolean                   checkenemystunned( Conditional &condition );
      qboolean                   checkenemyinpath( Conditional &condition );
      qboolean                   checkstage( Conditional &condition );
		qboolean                   checkheld( Conditional &condition );
		qboolean                   checkenemymelee( Conditional &condition );
		qboolean                   checkenemyranged( Conditional &condition );
		qboolean							checkenemyredemptive( Conditional &condition );
		qboolean							checkenemyredemptive();
		qboolean                   checkhasthing( Conditional &condition );
		qboolean                   checkatcovernode( Conditional &condition );
		qboolean                   checkallowhangback( Conditional &condition );
		qboolean                   checkname( Conditional &condition );
		qboolean							checkVar( Conditional &condtion );
		qboolean							checkNodeExists( Conditional &condition );
		qboolean							checkCoverNodes( Conditional &condition );
		qboolean							checkSurfaceDamaged( Conditional &condition );
		qboolean							checkBoneDamaged( Conditional &condition );
		qboolean							checkRegionDamaged( Conditional &condition );
		qboolean                   checkCaptured( Conditional &condition );
		qboolean                   checkEnemyAttached( Conditional &condition );
		qboolean                   checkCanWalkForward( Conditional &condition );
		qboolean                   checkHasThrowObject( Conditional &condition );
		qboolean                   checkEnemyIsThrowObject( Conditional &condition );
		qboolean                   checkTurretMode( Conditional &condition );
		qboolean                   checkMeleeHitWorld( Conditional &condition );
		qboolean                   checkGameSpecific( Conditional &condition );
		qboolean                   checkWeaponReady( Conditional &condition );	
		qboolean                   checkNeedToReload( Conditional &condition );
		qboolean                   checkCurrentWeaponType( Conditional &condition );
		qboolean                   checkShootMode( Conditional &condition );
		qboolean                   checkParanoia( Conditional &condition );
		qboolean                   checkParanoiaType( Conditional &condition );
		
		// Redemption Checks
		qboolean                   checkPersonality( Conditional &condition );

	   virtual void               Archive( Archiver &arc );
	};

#define SAVE_FLAG_NEW_ANIM						(1<<0)
#define SAVE_FLAG_FORWARD_SPEED				(1<<1)
#define SAVE_FLAG_BEHAVIOR						(1<<2)
#define SAVE_FLAG_PATH							(1<<3)
#define SAVE_FLAG_NOISE							(1<<4)
#define SAVE_FLAG_SCRIPT_THREAD				(1<<5)
#define SAVE_FLAG_ACTOR_THREAD				(1<<6)
#define SAVE_FLAG_KILL_THREAD					(1<<7)
#define SAVE_FLAG_STATE							(1<<8)
#define SAVE_FLAG_IDLE_THREAD					(1<<7)
#define SAVE_FLAG_PARTS							(1<<10)
#define SAVE_FLAG_TRIGGER						(1<<11)
#define SAVE_FLAG_STATE_FLAGS					(1<<12)
#define SAVE_FLAG_COMMAND						(1<<13)
#define SAVE_FLAG_STAGE							(1<<14)
#define SAVE_FLAG_NUM_OF_SPAWNS				(1<<15)
#define SAVE_FLAG_SPAWN_PARENT				(1<<16)
#define SAVE_FLAG_DIALOG						(1<<17)
#define SAVE_FLAG_SAVED_STUFF					(1<<18)
#define SAVE_FLAG_LAST_ANIM_EVENT			(1<<19)
#define SAVE_FLAG_PICKUP_ENT					(1<<20)
#define SAVE_FLAG_PAIN							(1<<21)
#define SAVE_FLAG_SPAWN_ITEMS					(1<<22)

inline void Actor::Archive
	(
	Archiver &arc
	)
   {
	//unsigned int save_flags;
	str temp_state_name;
	//qboolean temp_bool;
	qboolean behavior_bool;
	qboolean hBehavior_bool;
	qboolean eBehavior_bool;

   Sentient::Archive( arc );

	arc.ArchiveString( &newanim );
	arc.ArchiveEventPointer( &newanimevent );
	arc.ArchiveInteger( &newanimnum );

	arc.ArchiveInteger( (int *)&lastmove );
	arc.ArchiveFloat( &forwardspeed );

	arc.ArchiveInteger( (int *)&actortype );

	arc.ArchiveString( &animname );

	if ( arc.Saving() )
		{
		if ( behavior )
			{
			behavior_bool = true;
			arc.ArchiveBoolean( &behavior_bool );
			arc.ArchiveObject( behavior );
			}
		else
			{
			behavior_bool = false;
			arc.ArchiveBoolean( &behavior_bool );
			}

		if ( headBehavior )
			{
			hBehavior_bool = true;
			arc.ArchiveBoolean( &hBehavior_bool );
			arc.ArchiveObject( headBehavior );			
			}
		else
			{
			hBehavior_bool = false;
			arc.ArchiveBoolean( &hBehavior_bool );			
			}		

		if ( eyeBehavior )
			{
			eBehavior_bool = true;
			arc.ArchiveBoolean( &eBehavior_bool );
			arc.ArchiveObject( eyeBehavior );
			}
		}
   else
		{
		arc.ArchiveBoolean( &behavior_bool );

		if ( behavior_bool )
			{
			behavior = ( Behavior * )arc.ReadObject();
			currentBehavior = behavior->getClassname();
			}
		else
			{
			behavior = NULL;
			currentBehavior = "";
			}

		arc.ArchiveBoolean( &hBehavior_bool );

		if ( hBehavior_bool )
			{
			headBehavior = ( Behavior * )arc.ReadObject();
			currentHeadBehavior = headBehavior->getClassname();
			}

		arc.ArchiveBoolean( &eBehavior_bool );

		if ( eBehavior_bool )
			{
			eyeBehavior = ( Behavior * )arc.ReadObject();
			currentEyeBehavior = eyeBehavior->getClassname();
			}
		}

	arc.ArchiveSafePointer( &path );

	arc.ArchiveSafePointer( &currentEnemy );

	arc.ArchiveUnsigned( &actor_flags1 );
	arc.ArchiveUnsigned( &actor_flags2 );

	arc.ArchiveVector ( &noise_position );
	arc.ArchiveFloat( &noise_time );

	arc.ArchiveFloat( &fov );
	arc.ArchiveFloat( &fovdot );
	arc.ArchiveFloat( &vision_distance );

	arc.ArchiveVector ( &startpos );

	arc.ArchiveVector ( &move );
	arc.ArchiveVector ( &movedir );
	arc.ArchiveFloat ( &movespeed );
	arc.ArchiveVector ( &movevelocity );
	arc.ArchiveFloat ( &totallen );
	arc.ArchiveFloat ( &turnspeed );
	arc.ArchiveVector ( &animdir );

	arc.ArchiveFloat ( &chattime );
	arc.ArchiveFloat ( &nextsoundtime );

	arc.ArchiveSafePointer( &scriptthread );
	arc.ArchiveSafePointer( &actorthread );

	arc.ArchiveFloat( &pain_threshold );

	arc.ArchiveFloat( &next_drown_time );
	arc.ArchiveFloat( &air_finished );

	arc.ArchiveString( &kill_thread );
	arc.ArchiveVector( &eyeoffset );
	arc.ArchiveFloat( &last_jump_time );

	if ( arc.Saving() )
		{

		arc.ArchiveString( &statemap_name );

		if ( currentState )
			temp_state_name = currentState->getName();

		arc.ArchiveString( &temp_state_name );
		}
	else
		{
		arc.ArchiveString( &statemap_name );

		if ( statemap_name.length() )
			{
			Event *event;

			event = new Event( EV_Actor_Statemap );
			event->AddString( statemap_name.c_str() );
			event->AddString( "" );
			event->AddInteger( 1 );
			ProcessEvent( event );
			}

		arc.ArchiveString( &temp_state_name );

		if ( statemap )
			currentState = statemap->FindState( temp_state_name.c_str() );
		}

	arc.ArchiveFloat( &state_time );
	arc.ArchiveInteger( &times_done );
	arc.ArchiveFloat( &state_done_time );
	arc.ArchiveInteger( &stimuli );
	arc.ArchiveInteger( &permanent_stimuli );
	arc.ArchiveString( &idle_thread );
	arc.ArchiveFloat( &last_enemy_sight_time );
	arc.ArchiveFloat( &next_enemy_try_sight_time );
	arc.ArchiveFloat( &next_try_sleep_time );
	arc.ArchiveFloat( &last_time_active );

	arc.ArchiveFloat( &max_inactive_time );

	arc.ArchiveString( &name );
	arc.ArchiveString( &part_name );

	{
	part_t part;
	int current_part;
	int number_of_parts;
	part_t *part_ptr;

   if ( arc.Saving() )
      {
		number_of_parts = parts.NumObjects();
      }
   else
      {
      parts.ClearObjectList();
      }

	arc.ArchiveInteger( &number_of_parts );

	if ( arc.Loading() )
		parts.Resize( number_of_parts );

	for( current_part = 1; current_part <= number_of_parts ; current_part++ )
		{
      if ( arc.Saving() )
         {
			part = parts.ObjectAt( current_part );
			part_ptr = &part;
         }
		else
         {
			parts.AddObject( part );
   		part_ptr = parts.AddressOfObjectAt( current_part );
         }

			arc.ArchiveSafePointer( &part_ptr->ent );
			arc.ArchiveUnsigned( &part_ptr->state_flags );
		}
	}

	arc.ArchiveSafePointer( &trigger );
	
	arc.ArchiveString( &onuse_thread_name );
	arc.ArchiveString( &enemytype );

	arc.ArchiveUnsigned( &state_flags );
	arc.ArchiveString( &command );

	arc.ArchiveSafePointer( &incoming_proj );
	arc.ArchiveFloat( &incoming_time );

	arc.ArchiveFloat( &actorrange_time );
	arc.ArchiveFloat( &last_height );
	arc.ArchiveSafePointer( &last_ent );

   arc.ArchiveFloat( &canseeenemy_time );

   arc.ArchiveInteger( &stage );

   arc.ArchiveInteger( &num_of_spawns );

	arc.ArchiveSafePointer( &spawnparent );

//	DialogNode_t					*dialog_list;

	// Save dialog stuff

	if ( arc.Saving() )
		{
		DialogNode_t *dialog_node;
		byte more;
		str alias_name;
		str parm;
		int current_parm;

		dialog_node = dialog_list;

		while( dialog_node )
			{
			more = true;
			arc.ArchiveByte( &more );

			alias_name = dialog_node->alias_name;

			arc.ArchiveString( &alias_name );
			arc.ArchiveInteger( &dialog_node->random_flag );
			arc.ArchiveFloat( &dialog_node->random_percent );
			arc.ArchiveInteger( &dialog_node->number_of_parms );

			for( current_parm = 0 ; current_parm < dialog_node->number_of_parms ; current_parm++ )
				{
				arc.ArchiveByte( &dialog_node->parms[ current_parm ].type );

				parm = dialog_node->parms[ current_parm ].parm;

				arc.ArchiveString( &parm );
				}

			dialog_node = dialog_node->next;
			}

		more = false;
		arc.ArchiveByte( &more );
		}
	else
		{
		byte more;
		DialogNode_t *new_dialog_node;
		DialogNode_t *current_dialog_node = NULL;
		str alias_name;
		str parm;
		int current_parm;

		arc.ArchiveByte( &more );

		while( more )
			{
			new_dialog_node = NewDialogNode();

			if ( current_dialog_node )
				current_dialog_node->next = new_dialog_node;
			else
				dialog_list = new_dialog_node;

			current_dialog_node = new_dialog_node;
			new_dialog_node->next = NULL;

			arc.ArchiveString( &alias_name );
			strcpy( new_dialog_node->alias_name, alias_name.c_str() );

			arc.ArchiveInteger( &new_dialog_node->random_flag );
			arc.ArchiveFloat( &new_dialog_node->random_percent );
			arc.ArchiveInteger( &new_dialog_node->number_of_parms );

			for( current_parm = 0 ; current_parm < new_dialog_node->number_of_parms ; current_parm++ )
				{
				arc.ArchiveByte( &new_dialog_node->parms[ current_parm ].type );

				arc.ArchiveString( &parm );
				strcpy( new_dialog_node->parms[ current_parm ].parm, parm.c_str() );
				}

			arc.ArchiveByte( &more );
			}
		}

	arc.ArchiveFloat( &dialog_done_time );
	arc.ArchiveString( &dialog_state_name );
	arc.ArchiveString( &dialog_old_state_name );

	arc.ArchiveVector( &watch_offset );

	arc.ArchiveInteger( &mode );
	arc.ArchiveString( &idle_state_name );
	arc.ArchiveFloat( &next_player_near );

	arc.ArchiveInteger( &saved_mode );

	if ( arc.Saving() )
		{
		if ( saved_behavior )
			{
			behavior_bool = true;
			arc.ArchiveBoolean( &behavior_bool );
			arc.ArchiveObject( saved_behavior );
			}
		else
			{
			behavior_bool = false;
			arc.ArchiveBoolean( &behavior_bool );
			}

		if ( saved_headBehavior )
			{
			hBehavior_bool = true;
			arc.ArchiveBoolean( &hBehavior_bool );
			arc.ArchiveObject( saved_headBehavior );
			}
		else
			{
			hBehavior_bool = false;
			arc.ArchiveBoolean( &hBehavior_bool );
			}
		
		if ( saved_eyeBehavior )
			{
			eBehavior_bool = true;
			arc.ArchiveBoolean( &eBehavior_bool );
			arc.ArchiveObject( saved_eyeBehavior );
			}
		}
   else
		{
		arc.ArchiveBoolean( &behavior_bool );

		if ( behavior_bool )
			saved_behavior = ( Behavior * )arc.ReadObject();
		else
			saved_behavior = NULL;

		arc.ArchiveBoolean( &hBehavior_bool );

		if ( hBehavior_bool )
			saved_headBehavior = ( Behavior * )arc.ReadObject();
		else
			saved_headBehavior = NULL;

		arc.ArchiveBoolean( &eBehavior_bool );

		if ( eBehavior_bool )
			saved_eyeBehavior = ( Behavior * )arc.ReadObject();
		else
			saved_eyeBehavior = NULL;
		}

	arc.ArchiveSafePointer( &saved_scriptthread );
	arc.ArchiveSafePointer( &saved_actorthread );
	arc.ArchiveString( &saved_anim_name );
	arc.ArchiveString( &saved_state_name );
	arc.ArchiveString( &saved_anim_event_name );

	arc.ArchiveString( &last_anim_event_name );

	arc.ArchiveSafePointer( &pickup_ent );

	arc.ArchiveInteger( &pain_type );
	arc.ArchiveVector( &pain_angles );
	arc.ArchiveInteger( &bullet_hits );

	arc.ArchiveFloat( &stunned_end_time );

	spawn_items.Archive( arc );

	arc.ArchiveFloat( &spawn_chance );

	arc.ArchiveString( &bounce_off_effect );

	arc.ArchiveVector( &last_attack_pos );
	arc.ArchiveVector( &last_attack_enemy_pos );
	arc.ArchiveSafePointer( &last_attack_entity_hit );
	arc.ArchiveVector( &last_attack_entity_hit_pos );

	arc.ArchiveVector( &last_known_enemy_pos );

	can_be_finsihed_by_mods.Archive( arc );

	arc.ArchiveFloat( &feet_width );

	arc.ArchiveVector( &last_origin );

	arc.ArchiveFloat( &next_find_enemy_time );

	arc.ArchiveFloat( &minimum_melee_height );
	arc.ArchiveFloat( &damage_angles );

	arc.ArchiveFloat( &real_head_pitch );

	arc.ArchiveFloat( &next_pain_sound_time );

	arc.ArchiveFloat( &last_ground_z );

	arc.ArchiveFloat( &water_level );

	arc.ArchiveFloat( &max_boss_health );

	arc.ArchiveString( &emotion );

	arc.ArchiveFloat( &next_blink_time );

	arc.ArchiveFloat( &last_used_time );

	if ( flags & FL_THINK )
		Wakeup();
	else
		Sleep();

   }

// Set destination to node with duck or cover set.  Class will find a path to that node, or a closer one.
class FindCoverMovement : public StandardMovement
	{
	public:
		Actor			*self;

	inline qboolean validpath
		(
		PathNode *node,
		int i
		)

		{
		pathway_t *path;
		PathNode *n;

		path = &node->Child[ i ];

		if ( !StandardMovement::validpath( node, i ) )
			{
			return false;
			}

		n = AI_GetNode( path->node );
      if ( !n || self->CloseToEnemy( n->origin, 128 ) )
			{
			return false;
			}

		return true;
		}

	inline qboolean done
		(
		PathNode *node,
		PathNode *end
		)

		{
		if ( node == end )
			{
			return true;
			}

		//if ( node->reject )
		if ( node->reject || !( node->nodeflags & ( AI_DUCK | AI_COVER ) ) )
			{
			return false;
			}

		if ( self )
			{
         node->reject = self->CanSeeEnemyFrom( node->origin );
			return !node->reject;
			}

		return false;
		}
	};

// Set destination to node with flee set.  Class will find a path to that node, or a closer one.
class FindFleeMovement : public StandardMovement
	{
	public:
		Actor			*self;

	inline qboolean validpath
		(
		PathNode *node,
		int i
		)

		{
		pathway_t *path;
		PathNode *n;

		path = &node->Child[ i ];

		if ( !StandardMovement::validpath( node, i ) )
			{
			return false;
			}

		n = AI_GetNode( path->node );
      if ( !n || self->CloseToEnemy( n->origin, 128 ) )
			{
			return false;
			}

		return true;
		}

	inline qboolean done
		(
		PathNode *node,
		PathNode *end
		)

		{
		if ( node == end )
			{
			return true;
			}

		//if ( node->reject )
		if ( node->reject || !( node->nodeflags & AI_FLEE ) )
			{
			return false;
			}

		if ( self )
			{
         node->reject = self->CanSeeEnemyFrom( node->origin );
			return !node->reject;
			}

		return false;
		}
	};

class FindEnemyMovement : public StandardMovement
	{
	public:
		Actor			*self;

	inline qboolean done
		(
		PathNode *node,
		PathNode *end
		)

		{
		if ( node == end )
			{
			return true;
			}

		if ( node->reject )
			{
			return false;
			}

		if ( self )
			{
			if ( self->currentEnemy )
   			{
            node->reject = !self->CanShootFrom( node->origin, self->currentEnemy, false );
			   }
			else
			   {
				node->reject = false;
			   }

         return !node->reject;
			}

		return false;
		}
	};

typedef PathFinder<FindCoverMovement> FindCoverPath;
typedef PathFinder<FindFleeMovement> FindFleePath;
typedef PathFinder<FindEnemyMovement> FindEnemyPath;

void AI_TargetPlayer( void );
Player *GetPlayer(int index);

#endif /* actor.h */