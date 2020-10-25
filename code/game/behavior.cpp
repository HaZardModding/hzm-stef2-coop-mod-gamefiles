//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/behavior.cpp                                   $
// $Revision:: 68                                                             $
//   $Author:: Sketcher                                                       $
//     $Date:: 8/17/01 2:04p                                                  $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/behavior.cpp                                       $
// 
// 68    8/17/01 2:04p Sketcher
// Fixed some errors with Vehicle and traceattack
// 
// 67    8/16/01 1:43p Sketcher
// Added behaviors for the helicopter
// 
// 66    8/14/01 3:48p Sketcher
// Fixed bugs in Actor to Actor damage and added more flying behaviors
// 
// 65    7/24/01 4:41p Sketcher
// More Vehicle Changes
// 
// 64    7/12/01 10:18a Sketcher
// More Waypoint Modifications
// 
// 63    7/12/01 8:15a Sketcher
// Modified Waypoint stuff to make better use of target
// 
// 62    7/11/01 11:19a Sketcher
// Added Waypoints
// 
// 61    7/10/01 8:56a Sketcher
// Added Firstpass of Waypoints
// 
// 60    7/03/01 12:07p Sketcher
// Fixed a Null Pointer problem
// 
// 59    7/02/01 2:37p Sketcher
// Modified JumpTo to take in a vertical speed
// 
// 58    6/27/01 8:31a Sketcher
// Fixed a problem with death anims
// 
// 57    6/26/01 11:00a Sketcher
// Added a FallToDeath Behavior and Event Interface
// 
// 56    6/25/01 1:21p Sketcher
// Working on new FallToDeath Behavior
// 
// 55    6/22/01 1:30p Sketcher
// Added stuff to help actors use horses
// 
// 54    6/21/01 1:48p Sketcher
// More Tweaks To EyeWatch
// 
// 53    6/20/01 7:39a Sketcher
// AI Work for the Townie
// 
// 52    6/15/01 8:03a Sketcher
// Modified TorsoTurn 
// 
// 51    6/14/01 10:41a Sketcher
// More work on splitting actor legs and torso
// 
// 50    6/04/01 9:02p Sketcher
// Added a multishock behavior, which right now only takes 2 tags, and is
// kind of weak, I need to make it more robust
// 
// 49    6/02/01 12:36p Sketcher
// Added a ShockDown behavior
// 
// 48    6/02/01 9:30a Sketcher
// Added some functionality to Shock Attack
// 
// 47    5/30/01 6:03p Sketcher
// Added FlyCharge
// 
// 46    5/24/01 7:34a Sketcher
// Fixed up actor spline stuff
// 
// 45    5/22/01 7:33a Sketcher
// Added a VerticalTakeOff behavior to let actors fly straight up
// 
// 44    5/12/01 1:35p Sketcher
// Improved FlyClimb
// 
// 43    5/11/01 1:55p Sketcher
// Fixed some initialized but unused  variables I had left in
// 
// 42    5/11/01 1:25p Sketcher
// More stuff for quetzal... Added an AttachEnemy event
// 
// 41    5/01/01 1:54p Steven
// Got rid of digest.
// 
// 40    4/30/01 2:58p Sketcher
// Have a good start on flying actors following spline paths
// 
// 39    4/24/01 8:37a Sketcher
// Made Changes in NotifyOthersAtDeath 
// 
// 38    4/13/01 9:18a Steven
// Made the idle behavior request a notification when the anim is done.
// 
// 37    4/10/01 9:35a Sketcher
// Added stuff to check if other actors are dead from script
// 
// 36    4/05/01 3:23p Sketcher
// more flynodepath stuff
// 
// 35    4/05/01 2:38p Sketcher
// working on flynodestuff
// 
// 34    4/05/01 11:42a Sketcher
// Changed FlyNodePath stuff from 0 based to 1 based
// 
// 33    4/04/01 9:31a Sketcher
// Added events to set the eyewatch constraints
// 
// 32    4/04/01 8:37a Steven
// Fixed a talking/radius issue.
// 
// 31    4/03/01 4:10p Sketcher
// added radiusdialog stuff
// 
// 30    4/02/01 3:58p Sketcher
// eyewatch is now working
// 
// 29    4/02/01 2:11p Sketcher
// Added an OnUse for Actors that allows a thread to be run when they are
// used.  Also added an EyeWatch Behavior set - though this part is not yet
// fully implemented
// 
// 28    4/02/01 2:07p Steven
// Took out camera watching talking npcs.
// 
// 27    3/28/01 3:24p Steven
// Added warning printfs.
// 
// 26    3/27/01 4:31p Sketcher
// Added a rotatetoenemy behavior
// 
// 25    3/26/01 9:23a Sketcher
// 
// 17    2/07/01 1:23p Sketcher
// More Changes to FlyToPoint
// 
// 16    2/06/01 2:19p Sketcher
// More Flying Behavior Changes
// 
// 15    1/31/01 1:25p Steven
// Fixed the idle behavior animation problem.
// 
// 14    1/30/01 2:41p Sketcher
// Tweaked FlyToPoint Function to help prevent flying creatures from
// "jittering"
// 
// 13    1/29/01 10:49a Sketcher
// Made Changes for Idle State
// 
// 12    1/26/01 1:20p Sketcher
// Added Additional Fly-type behaviors and modifed FlyCircle
// 
// 11    1/24/01 2:40p Sketcher
// 
// 10    1/23/01 10:36a Sketcher
// Added Hover Behavior
// 
// 9     1/16/01 2:07p Sketcher
// adding behaviors for Quetzal creature
// 
// 8     1/15/01 4:14p Sketcher
// Added a Teleport to Player Behavior, and added a parameter to FlyCircle()
// to optionally shut off the YAW and ROLL changes
// 
// 7     1/11/01 2:24p Sketcher
// Initial Work (Data Structure Mostly) for Dynamic Tuning 
// 
// 6     12/11/00 9:32a Steven
// Changed passing of most vectors to const reference.
// 
// 5     12/07/00 1:49p Sketcher
// FOV is now based on a creature's headbone (If they have one) rather than
// the origin.  
//
// 144   7/30/00 2:21p Aldie
// Fixed a problem in TurnTo allowing it to go forever.
//
// 143   7/29/00 1:25p Steven
// Took out teleport sound effects (are in effects now).
//
// 142   7/28/00 9:18p Steven
// Made a couple more fixes to Teleport.
//
// 141   7/28/00 6:56p Steven
// Added in some teleport effects to TeleportToPosition.
//
// 140   7/28/00 1:23p Steven
// Fixed entities origin while being dragged by the tr'angular and made player
// make lots of pain sounds when being eaten by a sucknblaugh.
//
// 139   7/27/00 10:53p Steven
// Made tr'angular do damage over time and made dropping victim much more
// robust.
//
// 138   7/27/00 10:31a Steven
// Added some effects when the spad body is hit by the ShockWater attack.
//
// 137   7/26/00 6:44p Steven
// Added some more animations to not break out of for talk.
//
// 136   7/24/00 8:35p Steven
// Added another animation not to interrupt.
//
// 135   7/23/00 12:27p Steven
// Changed sucknlaugh to pull entities to its centroid instead of its origin
// and fixed some TeleportToPosition problems.
//
// 134   7/22/00 8:36p Steven
// Made ghosts do a little bit more damage.
//
// 133   7/21/00 3:44p Steven
// Fixed burrowattack stuff, improved teleports a lot, and made anything that
// gets digested extinguish fire.
//
// 132   7/20/00 6:22p Steven
// Made jarts hurt anything that will take damage.
//
// 131   7/19/00 5:08p Steven
// Added electric water means of death.
//
// 130   7/18/00 4:26p Steven
// Modified which anims can not be interrupted by talking stuff a little and
// made flyclimb be able to set the speed.
//
// 129   7/17/00 4:42p Steven
// Added some more animations the talk behavior will not interrupt.
//
// 128   7/17/00 2:55p Steven
// Fixed it so Jart attack sets directio and position correctly so it can be
// blocked and made ghosts attackable longer and let players target them
// during this time.
//
// 127   7/16/00 4:36p Steven
// Added new fire means of death.
//
// 126   7/16/00 2:35p Steven
// Improved camera stuff when watching a talking actor.
//
// 125   7/13/00 7:29p Steven
// Made entity go back to solid again after being released from the
// tr'angular.
//
// 124   7/13/00 3:43p Steven
// Added next_think_time to GetCloseToEnemy for simple path finding.
//
// 123   7/12/00 11:26a Steven
// Added another animation that talk will not get out of, added a
// return_to_original_location bool to investigate, and made ghost stay solid
// longer.
//
// 122   7/11/00 7:08p Steven
// Made ghosts a little bit slower and not do as much damage.
//
// 121   7/11/00 9:12a Steven
// Made it so turnto doesn't rely on movedir being correct.
//
// 120   7/07/00 8:06a Steven
// Improved the investigation behavior to always look towards the noise
// position.
//
// 119   7/05/00 2:27p Steven
// Improved fleeing behavior a lot.
//
// 118   7/02/00 5:56p Steven
// Fixed FlyDive a little if hit something in movement and then it has moved
// out of the way when we try the trace.
//
// 117   7/02/00 5:08p Steven
// Made it so anything in the way when a actor teleports to a specific
// location gets telefragged.
//
// 116   7/02/00 2:45p Steven
// Fixed player getting removed when the sucknblaugh eats her.
//
// 115   7/02/00 1:11p Steven
// Changed TeleportToPosition to use named pathnodes instead of hardcoded
// positions.
//
// 114   6/30/00 3:08p Markd
// fixed rise animation issues
//
// 113   6/30/00 10:45a Markd
// added MOVETYPE_STATIONARY and revamped some physics
//
// 112   6/30/00 10:35a Steven
// Added max_pains to Pain behavior.
//
// 111   6/28/00 4:55p Aldie
// Added a MOD
//
// 110   6/26/00 5:50p Markd
// re-did some renderfx commands, fixed anti-sb juice stuff
//
// 109   6/23/00 4:54p Steven
// Removed a chatter function call.
//
// 108   6/21/00 5:28p Steven
// Improved the Digest behavior (fixed range a little, made gibs look better
// when spit out, and made it chew a little longer).
//
// 107   6/21/00 4:22p Steven
// Took out some chatter stuff from the idle behavior and moved the direction
// to fly in the Circle behavior to the args.
//
// 106   6/15/00 6:55p Steven
// Added moving head while talking stuff.
//
// 105   6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 104   6/13/00 3:06p Steven
// Fixed a problem in the Shock behavior where a beam was being referenced
// after it had been freed.
//
// 103   6/07/00 5:34p Steven
// Made it so actor would only try to return from investigating for so long,
// added TeleportToPosition and Levitate behaviors.
//
// 102   6/06/00 2:36p Steven
// Made GetCloseToEnemy not be able to use_nearest_node.
//
// 101   6/05/00 3:41p Steven
// Adde GotoDeadEnemy.
//
// 100   6/05/00 12:16p Markd
// fixed sound bug
//
// 99    6/03/00 5:23p Steven
// Made digest behavior spit out gibs instead of the dead creature.
//
// 98    6/01/00 5:47p Steven
// Made ghost attack hit a little easier.
//
// 97    5/27/00 2:31p Steven
// Added FlyCloseToPlayer, added a direction to the shock attack, made the
// actor turn immediately towards the enemy after a teleport, and improved the
// ghost attack a little.
//
// 96    5/24/00 4:08p Steven
// Added a forever variable to the HeadWatch behavior.
//
// 95    5/20/00 4:46p Steven
// Improved the Shock behavior.
//
// 94    5/11/00 11:11a Steven
// Improved the shock attack behaviors a little.
//
// 93    5/06/00 3:00p Steven
// Added speed to FlyCloseToEnemy and fixed actor's getting stuck on top of
// the player.
//
// 92    5/05/00 6:23p Steven
// Made it so fire would not cause constant pain in the pain behavior.
//
// 91    5/05/00 2:14p Steven
// Took out one of the sounds in GhostAttack.
//
// 90    5/04/00 4:13p Steven
// Fixed the BurrowAttack not hitting triggers and hard coded the BurrowAttack
// to start at a certain height to prevent height errors.
//
// 89    5/03/00 12:10p Steven
// Made it so the ghost bounces off shields if blocked.
//
// 88    5/03/00 11:27a Steven
// Added some sounds to the ghost attack and added the spooky ghost attack.
//
// 87    5/02/00 5:14p Steven
// Fixed the ghost attack so that MeleeAttack could tell what direction the
// attack was coming from.
//
// 86    5/02/00 3:14p Steven
// Added player watching actors that talk to her.
//
// 85    4/28/00 5:40p Steven
// Added use_last_known_pos to TurnToEnemy and BurrowAttack and made it so the
// burrowattack could hit solid entities as long as it isn't the world.
//
// 84    4/25/00 6:19p Steven
// Made it so the digest attack wouldn't eat stationary sentients and tweaked
// the range a little.
//
// 83    4/25/00 4:21p Steven
// Fixed the ghost spinning in circles around their attack target.
//
// 82    4/25/00 10:53a Steven
// Fixed a place where the ghost would fade all of the way back in.
//
// 81    4/25/00 10:12a Steven
// Lots of improvements to the GhostAttack behavior.
//
// 80    4/24/00 3:12p Steven
// Added allow fail to chase.
//
// 79    4/20/00 3:37p Steven
// Fixed a bug in HeadWatch, was never getting the current_head_angles
// correctly.
//
// 78    4/20/00 11:34a Steven
// Changed a range in the ShockWater behavior.
//
// 77    4/15/00 5:42p Steven
// Made it so the amount of time the sucknblaugh chews on its victim is
// determined by its weight.
//
// 76    4/15/00 3:39p Steven
// Made it so the pain animation will randomly choose between all available
// pain animations not just the first 2.
//
// 75    4/13/00 5:34p Steven
// Added the Teleport behavior and the GhostAttack behavior.
//
// 74    4/12/00 2:39p Steven
// Fixed TorsoTurn turning in circles forever problem (always trying to catch
// up to target).
//
// 73    4/11/00 4:01p Steven
// Added attack_min_height to MeleeAttack.
//
// 72    4/08/00 3:53p Steven
// Made headwatch snap head back to the forward position if lost the entity we
// were watching or if resetting the head and the behavior is stopped, took
// out the walking in PickupEntity, and set the actors animation to idle after
// done throwing an entity.
//
// 71    4/05/00 6:18p Steven
// Added dirt to where the Vymish Mama's burrow legs come out of the ground.
//
// 70    4/04/00 6:55p Steven
// Made it so HeadWatch doesn't snap to forward at end and if it doesn't have
// an entity to watch moves head back to forward position using max_speed.
//
// 69    4/01/00 2:39p Steven
// Made it so actor can fly clockwise or counter-clockwise in FlyCircle.
//
// 68    4/01/00 2:00p Steven
// Added a forever flag to GetCloseToEnemy.
//
// 67    3/31/00 5:32p Steven
// Made some changes to the Digest behavior so that I could get projectils and
// bullets to bounce off of the Sucknblaugh.
//
// 66    3/31/00 4:58p Steven
// Changed TurnToEnemy so that if actor is really close don't bother turning
// any more.
//
// 65    3/30/00 2:03p Steven
// More work on TorsoTurn.
//
// 64    3/28/00 6:49p Steven
// Lots of improvements to TorsoTurn.
//
// 63    3/24/00 6:33p Steven
// Fixed an animation issue, made lots of optimizations to flying behaviors
// and ChooseRandomDirection.
//
// 62    3/20/00 6:08p Steven
// Made sure GetCloseToEnemy gets animdone events (so actor is informed).
//
// 61    3/17/00 11:49a Steven
// Added jumping stuff.
//
// 60    3/14/00 12:06p Steven
// Added walkwatch stuff.
//
// 59    3/11/00 11:36a Steven
// Moved all actor booleans to 1 actor flags variable and made the stopping
// condition for TurnToEnemy a little better.
//
// 58    3/08/00 6:42p Steven
// Worked on the TorsoTurn behavior some more.
//
// 57    3/07/00 5:23p Steven
// Tweaked BurrowAttack a little to not spawn in so many dirt and water
// effects.
//
// 56    3/07/00 11:51a Steven
// Made lots of tweaks to the CircleEnemy behavior.
//
// 55    3/04/00 11:49a Steven
// Improved the FlyCircle, FlyDive, and FlyClimb behaviors.
//
// 54    3/03/00 5:26p Steven
// Added fast_bullet stuff.
//
// 53    3/02/00 11:02a Steven
// Added some tweaks to the digest behavior.
//
// 52    2/26/00 11:22a Steven
// Added partial immobile flag.
//
// 51    2/24/00 7:07p Steven
// Made talk so it would not stand up if already sitting and made it so the
// actor always tries to face whoever its talking to.
//
// 50    2/24/00 5:26p Steven
// Added a max speed parm to head watch and made sure playanim removes any
// anim done events still around when it ends.
//
// 49    2/23/00 5:19p Steven
// Improved the Wander behavior and improved the ChooseRandomDirection
// function.
//
// 48    2/23/00 11:57a Steven
// Moved utility behaviors to actor and improved BurrowAttack attack.
//
// 47    2/21/00 7:00p Steven
// Added a TorsoTurn behavior.
//
// 46    2/21/00 11:09a Steven
// Fixed some TurnTo issues.
//
// 45    2/17/00 5:42p Steven
// Moved NearestNode stuff out of Investigate to Actor.
//
// 44    2/16/00 6:04p Steven
// Tweaked the investigate behavior a lot.
//
// 43    2/16/00 10:43a Steven
// Added a Pain behavior, made an option for FlyWander to make the actor try
// to fly upwards, and improved the Investigate behavior.
//
// 42    2/11/00 6:41p Steven
// Improved headwatch a little and added pickup/throw.
//
// 41    2/09/00 6:48p Steven
// Made it so an actor would stay in talk mode until the player went far
// enough away.
//
// 40    2/07/00 6:45p Steven
// Made it so the FlyCloseToEnemy behavior doesn't choose a new goal so often.
//
// 39    2/04/00 1:55p Steven
// Added the talk behavior.
//
// 38    2/02/00 1:38p Steven
// Added turning animations to TurnTo, added the HeadWatch behavior, cleaned
// up flying code a little more, and improved the Suicide, DragEnemy, and
// ShockWater behaviors.
//
// 37    1/29/00 5:28p Steven
// Improoved the BurrowAttack and DragEnemy behaviors.
//
// 36    1/27/00 2:53p Steven
// Improved a lot of the flying code.
//
// 35    1/26/00 9:51a Steven
// Added a usefult debug message to GotoPathNode.
//
// 34    1/22/00 12:42p Jimdose
// got rid of calls to vec3()
//
// 33    1/21/00 6:45p Steven
// Made flee use chase instead of FollowPath.
//
// 32    1/19/00 7:08p Steven
// Fixed speed of flying creatures and tweaked BurrowAttack behavior a little.
//
// 31    1/19/00 12:11p Steven
// Fixed AimAndShoot behavior and improved the TurnToEnemy and BurrowAttack
// behaviors.
//
// 30    1/14/00 7:36p Steven
// Improved TurnToEnemy behavior a little.
//
// 29    1/14/00 5:06p Markd
// Removed surface num, tri_num and damage_multiplier from multiple functions
// and events
//
// 28    1/14/00 5:02p Steven
// Added gotonextstage and burrowattack behaviors.
//
// 27    1/13/00 7:07p Steven
// Lots and lots of cleanup.
//
// 26    1/07/00 8:12p Jimdose
// cleaning up unused code
//
// 25    1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 24    1/06/00 6:49p Steven
// Cleaned up GetCloseToEnemy.
//
// 23    1/05/00 7:25p Jimdose
// made angle functions all use the same coordinate system
// AngleVectors now returns left instead of right
// no longer need to invert pitch
//
// 22    1/05/00 6:43p Steven
// Fixed the start and end point being backwards in a trace command.
//
// 21    1/05/00 3:07p Jimdose
// fixed inverted pitch in Aim::Evaluate
//
// 20    12/22/99 5:13p Steven
// Fixed some animation issues, some general clean up, and removed
// FemaleLympAttack.
//
// 19    12/17/99 5:51p Steven
// Made some temporary fixes to aiming behaviors and added the following
// behaviors : TurnTowardsEnemy, FlyCircle, FlyDive, and FlyClimb.
//
// 18    12/01/99 3:43p Steven
// Added a land behavior for flying creatures.
//
// 17    11/24/99 11:05a Steven
// More work on flying.
//
// 16    11/19/99 2:05p Steven
// Took out some unused code.
//
// 15    11/19/99 11:33a Steven
// Added new behaviors: CircleEnemy, ShockWater, Shock, and CircleAttack.
//
// 14    11/12/99 6:24p Steven
// Made state flags available to other part entities.
//
// 13    11/10/99 6:11p Steven
// Added the FlyCloseToEnemy behavior.
//
// 12    10/28/99 6:06p Steven
// Improved the drag behavior.
//
// 11    10/27/99 10:27a Steven
// Added GetNearestEnemy behavior and added more to the DragEnemy behavior.
//
// 10    10/19/99 7:52p Markd
// Removed three part model system
//
// 9     10/19/99 7:10p Steven
// Lots of AI work.
//
// 8     10/11/99 7:50p Steven
// Cleanup.
//
// 7     10/01/99 4:52p Markd
// Made Warning level 4 work on all projects
//
// 6     9/29/99 11:52a Markd
// removed some unused enums and variables form shared headers between cgame
// and game
//
// 5     9/28/99 7:24p Steven
// Event formatting.
//
// 4     9/22/99 4:47p Markd
// fixed more G_GetEntity, G_FindClass and G_GetNextEntity bugs
//
// 3     9/21/99 7:51p Markd
// Fixed a lot of entitynum_none issues
//
// 2     9/16/99 11:18a Markd
// Continuing merge of code, not functional yet but closer
//
// 1     9/10/99 10:53a Jimdose
//
// 1     9/08/99 3:15p Aldie
//
// 26    9/02/99 11:33p Jimdose
// fixed bug with sucknblaughs targeting
//
// 25    9/02/99 4:22p Steven
// Changed when sucknblaugh is solid and when it is not and fixed some aiming
// issues in AimAndShoot behavior.
//
// 24    9/01/99 8:16p Steven
// Fixed a typo and setting the anim back to idle after the AimAndShoot
// behavior.
//
// 23    8/31/99 9:21p Steven
// Added fall anim to jump behavior and tweaked digest behavior a little.
//
// 22    8/31/99 2:43p Steven
// Fixed some spin behavior bugs.
//
// 21    8/28/99 7:05p Steven
// Made it so the speed of the spinning for the spinner plant was a parameter.
//
// 20    8/28/99 11:42a Steven
// Added some spinning plant stuff.
//
// 19    8/27/99 5:05p Steven
// Worked on digest behavior, added spin, and optimized some of the movement.
//
// 18    8/24/99 11:25a Steven
// Made it so Sucknblaughs don't eat dead creatures.
//
// 17    8/18/99 3:29p Jimdose
// added cylindrical collision detection
//
// 16    8/18/99 3:22p Steven
// Added to Digest behavior.
//
// 15    8/17/99 4:59p Steven
// New digest behavior for the Sucknblaugh plant.
//
// 14    8/16/99 10:29a Steven
// More general work on AI.
//
// 13    8/11/99 7:24p Steven
// Redid the AimAndShoot behavior temporarily.
//
// 12    8/11/99 5:56p Steven
// More general AI work.
//
// 11    8/06/99 6:39p Aldie
// Started removing concept of currentWeapon
//
// 10    8/05/99 9:14a Steven
// New AI stuff.
//
// 9     7/07/99 11:25a Steven
// Added some stuff on the sector pathfinding approach.
//
//
// DESCRIPTION:
// Behaviors used by the AI.
//

#include "g_local.h"
#include "behavior.h"
#include "actor.h"
#include "doors.h"
#include "object.h"
#include "explosion.h"
#include "weaputils.h"
#include "player.h"

Event EV_Behavior_Args
	(
	"args",
	EV_DEFAULT,
	"SSSSSS",
	"token1 token2 token3 token4 token5 token6",
	"Gives the current behavior arguments."
	);
Event EV_Behavior_AnimDone
	(
	"animdone",
	EV_DEFAULT,
	NULL,
	NULL,
	"Tells the behavior that the current animation is done, "
	"it is not meant to be called from script."
	);

Vector ChooseRandomDirection( Actor &self, const Vector &previousdir, float *time, int disallowcontentsmask, qboolean usepitch );

/****************************************************************************

  Behavior Class Definition

****************************************************************************/

CLASS_DECLARATION( Listener, Behavior, NULL )
	{
		{ NULL, NULL }
	};

Behavior::Behavior()
	{
	}

void Behavior::ShowInfo
	(
	Actor &self
	)

	{
   if ( movegoal )
      {
      gi.Printf( "movegoal: ( %f, %f, %f ) - '%s'\n",
         movegoal->origin.x, movegoal->origin.y, movegoal->origin.z, movegoal->targetname.c_str() );
      }
   else
      {
      gi.Printf( "movegoal: NULL\n" );
      }
	}

void Behavior::Begin
	(
	Actor &self
	)

	{
	}

qboolean	Behavior::Evaluate
	(
	Actor &self
	)

	{
	return false;
	}

void Behavior::End
	(
	Actor &self
	)

	{
	}



/****************************************************************************
*****************************************************************************

  General behaviors

*****************************************************************************
****************************************************************************/



/****************************************************************************

  Idle Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Idle, NULL )
	{
		{ NULL, NULL }
	};

void Idle::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nnexttwitch : %f\n", nexttwitch );
	}

void Idle::Begin
	(
	Actor &self
	)

	{
	nexttwitch = level.time + 10 + G_Random( 30 );
	self.SetAnim( "idle", EV_Actor_NotifyBehavior );
	}

qboolean	Idle::Evaluate
	(
	Actor &self
	)

	{
	if ( self.currentEnemy )
		{
		return true;
		}

	if ( nexttwitch < level.time )
		{
		self.chattime += 10;
		self.AddStateFlag( STATE_FLAG_TWITCH );
		return true;
		}
	else
		{
		//self.Chatter( "snd_idle", 1 );		
		}

	return true;
	}

void Idle::End
	(
	Actor &self
	)

	{
	
	}

/****************************************************************************

  Pain Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Pain, NULL )
	{
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

void Pain::SetPainAnim
	(
	Actor &self,
	int new_pain_type,
	int new_anim_number
	)

	{
	str anim_name;

	// Determine which pain type to play

	if ( new_pain_type == PAIN_SMALL )
		anim_name = "pain_small";
	else
		anim_name = "pain";

	// Try to find the correct anim to play

	anim_name += new_anim_number;

	if ( !self.animate->HasAnim( anim_name.c_str() ) )
		{
		if ( new_pain_type == PAIN_SMALL )
			anim_name = "pain_small1";
		else
			anim_name = "pain1";

		pain_anim_number = 1;
		}

	anim_done = false;

	// Play the animation if we can

	if ( !self.animate->HasAnim( anim_name.c_str() ) )
		anim_done = true;
	else
		self.SetAnim( anim_name.c_str(), EV_Actor_NotifyBehavior );
	}

int Pain::GetNumberOfPainAnims
	(
	Actor &self,
	int new_pain_type
	)

	{
	str anim_name;
	str real_anim_name;
	int i;


	// Determine base animation name

	if ( new_pain_type == PAIN_SMALL )
		anim_name = "pain_small";
	else
		anim_name = "pain";

	// Find how many pain animations we have

	for( i = 1 ; i < 10 ; i++ )
		{
		real_anim_name = anim_name + i;

		if ( !self.animate->HasAnim( real_anim_name.c_str() ) )
			return( i - 1 );
		}

	return 9;
	}

void Pain::Begin
	(
	Actor &self
	)

	{
	str anim_name;
	int num_pain_anims;

	num_pain_anims = GetNumberOfPainAnims( self, self.pain_type );

	pain_anim_number = G_Random( num_pain_anims ) + 1;

	// Figure out which type of pain to do

	if ( self.pain_type == PAIN_SMALL )
		SetPainAnim( self, PAIN_SMALL, pain_anim_number );
	else
		SetPainAnim( self, PAIN_BIG, pain_anim_number );

	current_pain_type = self.pain_type;
	number_of_pains   = 1;

	// Make sure we don't have pain any more

	self.state_flags &= ~STATE_FLAG_SMALL_PAIN;
	self.state_flags &= ~STATE_FLAG_IN_PAIN;

	max_pains = G_Random( 4 ) + 4;
	}

void Pain::AnimDone
	(
	Event *ev
	)
	{
	anim_done = true;
	}

qboolean	Pain::Evaluate
	(
	Actor &self
	)

	{
	str anim_name;

	if ( self.state_flags & STATE_FLAG_SMALL_PAIN )
		{
		// See if we should play another pain animation

		if ( self.means_of_death != MOD_FIRE && self.means_of_death != MOD_ON_FIRE && self.means_of_death != MOD_FIRE_BLOCKABLE )
			{
			if ( self.pain_type == PAIN_SMALL && current_pain_type == PAIN_SMALL && number_of_pains < max_pains )
				{
				pain_anim_number++;

				number_of_pains++;

				SetPainAnim( self, PAIN_SMALL, pain_anim_number );
				}
			else if ( self.pain_type == PAIN_BIG )
				{
				pain_anim_number++;

				current_pain_type = PAIN_BIG;

				SetPainAnim( self, PAIN_BIG, pain_anim_number );
				}
			}

		// Reset pain stuff

		self.state_flags &= ~STATE_FLAG_SMALL_PAIN;
		self.state_flags &= ~STATE_FLAG_IN_PAIN;
		}

	// If the pain animation has finished, then we are done

	if ( anim_done )
		return false;

	return true;
	}

void Pain::End
	(
	Actor &self
	)

	{
	self.bullet_hits = 0;
	}

/****************************************************************************

  Watch Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Watch, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

Watch::Watch()
	{
	turn_speed = 360;
	}

void Watch::SetArgs
	(
	Event *ev
	)

	{
	turn_speed = ev->GetFloat( 1 );
	}

void Watch::Begin
	(
	Actor &self
	)

	{
	ent_to_watch = self.currentEnemy;

	old_turn_speed = self.turnspeed;
	self.turnspeed = turn_speed;
	seek.Begin( self );
	}

qboolean	Watch::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;

	if ( !ent_to_watch )
		return false;

	if ( self.IsEntityAlive( ent_to_watch ) )
		{
		self.angles.AngleVectors( &dir );

		seek.SetTargetPosition( ent_to_watch->centroid );
		seek.SetTargetVelocity( vec_zero );
		seek.SetPosition( self.centroid );
		seek.SetDir( dir );
		seek.Evaluate( self );

		self.Accelerate( seek.steeringforce );
		}

	return true;
	}

void Watch::End
	(
	Actor &self
	)

	{
	self.turnspeed = old_turn_speed;
	seek.End( self );
	}

/****************************************************************************

  Turn Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Turn, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

Turn::Turn()
	{
	turn_speed = 5;
	}

void Turn::SetArgs
	(
	Event *ev
	)

	{
	turn_speed = ev->GetFloat( 1 );
	}

void Turn::Begin
	(
	Actor &self
	)

	{
	}

qboolean	Turn::Evaluate
	(
	Actor &self
	)

	{
	self.angles[YAW] += turn_speed;

	self.setAngles( self.angles );

	return true;
	}

void Turn::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  Aim Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Aim, NULL )
	{
		{ NULL, NULL }
	};

void Aim::SetTarget
	(
	Entity *ent
	)

	{
	target = ent;
	}

void Aim::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nseek:\n" );
   seek.ShowInfo( self );
   if ( target )
      {
      gi.Printf( "\ntarget : #%d '%s'\n", target->entnum, target->targetname.c_str() );
      }
   else
      {
      gi.Printf( "\ntarget : NULL\n" );
      }
	}

void Aim::Begin
	(
	Actor &self
	)

	{
	seek.Begin( self );
	}

qboolean	Aim::Evaluate
	(
	Actor &self
	)

	{
   Vector dir;
   Vector ang;
   Vector pos;

	if ( !target )
		{
		return false;
		}

   //
   // get my gun pos
   //

	// Fixme ?
   //pos = self.GunPosition();
   //ang = self.MyGunAngles( pos, false );
	pos = self.centroid;
	ang = self.angles;
   ang.AngleVectors( &dir, NULL, NULL );

   seek.SetTargetPosition( target->centroid );
	seek.SetTargetVelocity( target->velocity );
	seek.SetPosition( self.centroid );
   seek.SetDir( dir );
	seek.SetMaxSpeed( 1400 + skill->value * 600 );
	seek.Evaluate( self );

	// Fixme?
	/* if ( ( fabs( seek.steeringforce.y ) > 5 ) && ( self.enemyRange > RANGE_MELEE ) )
		{
		seek.steeringforce.y *= 2;
		} */

	self.Accelerate( seek.steeringforce );
	if ( seek.steeringforce.y < 0.25f )
		{
		// dead on
		return false;
		}

	return true;
	}

void Aim::End
	(
	Actor &self
	)

	{
	seek.End( self );
	}

/****************************************************************************

  TurnTo Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TurnTo, NULL )
	{
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

TurnTo::TurnTo()
	{
	dir = Vector( 1, 0, 0 );
	mode = 0;
	ent = NULL;
   yaw = 0;
	anim_done = true;
	}

void TurnTo::SetDirection
	(
	float yaw
	)

	{
	Vector ang;

	ang = Vector( 0, yaw, 0 );
	this->yaw = anglemod( yaw );
	ang.AngleVectors( &dir, NULL, NULL );
	dir *= 100;
	mode = 1;
	}

void TurnTo::SetTarget
	(
	Entity *ent
	)

	{
	this->ent = ent;
	mode = 2;
	}

void TurnTo::AnimDone
	(
	Event *ev
	)

	{
	anim_done = true;
	}

void TurnTo::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nseek:\n" );
   seek.ShowInfo( self );

   if ( ent )
      {
      gi.Printf( "\nent: #%d '%s'\n", ent->entnum, ent->targetname.c_str() );
      }
   else
      {
      gi.Printf( "\nent: NULL\n" );
      }

   gi.Printf( "dir: ( %f, %f, %f )\n", dir.x, dir.y, dir.z );
   gi.Printf( "yaw: %f\n", yaw );
   gi.Printf( "mode: %d\n", mode );
	}

void TurnTo::Begin
	(
	Actor &self
	)

	{
	self.SetAnim( "idle" );
	seek.Begin( self );
	}

qboolean	TurnTo::Evaluate
	(
	Actor &self
	)

	{
	Vector delta;
	float ang;
	str anim_name;
	Vector forward;


	switch( mode )
		{
		case 1 :
			ang = angledist( yaw - self.angles.yaw() );
			if ( fabs( ang ) < 1 )
				{
				self.Accelerate( Vector( 0, ang, 0 ) );

				// If turned all the way wait for animation to finish

				if ( anim_done || self.animname == "idle" )
					return false;
				else
					return true;
				}

         seek.SetTargetPosition( self.origin + dir );
			seek.SetTargetVelocity( vec_zero );
			break;

		case 2 :
			if ( !ent )
				{
				return false;
				}

         delta = ent->origin - self.origin;
			yaw = delta.toYaw();

         seek.SetTargetPosition( ent->origin );
			seek.SetTargetVelocity( vec_zero );
			break;

		default :
			return false;
		}

   seek.SetPosition( self.origin );

	self.angles.AngleVectors( &forward );
	seek.SetDir( forward );
	//seek.SetDir( self.movedir );

	seek.SetMaxSpeed( self.movespeed );
	seek.Evaluate( self );

	if ( seek.steeringforce[YAW] > 1 )
		{
		anim_name = "turn_left";
		anim_done = false;
		}
	else if ( seek.steeringforce[YAW] < -1 )
		{
		anim_name = "turn_right";
		anim_done = false;
		}
	else if ( anim_done )
		{
		anim_name = "idle";
		}
	else
		{
		anim_name = self.animname;
		}

	if ( gi.Anim_NumForName( self.edict->s.modelindex, anim_name.c_str() ) != -1 )
		{
		if ( anim_name != self.animname )
			self.SetAnim( anim_name.c_str(), EV_Actor_NotifyBehavior );
		}
	else
		{
		anim_done = true;
		}

	self.Accelerate( seek.steeringforce );

	return true;
	}

void TurnTo::End
	(
	Actor &self
	)

	{
	seek.End( self );
	self.SetAnim( "idle" );
	}


/****************************************************************************

  RotateToEnemy Class Definition -- Primarily a convience wrapper for TurnTo

****************************************************************************/
CLASS_DECLARATION( Behavior, RotateToEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void RotateToEnemy::SetArgs
   (
	Event *ev
	)

	{
	if (ev->NumArgs() > 0 )
		anim = ev->GetString(1);
	else
		anim = "idle";

	if (ev->NumArgs() > 1 )
		turnSpeed = ev->GetFloat(2);
	else
		turnSpeed = 10;
	}

void RotateToEnemy::Begin
   (
	Actor &self
	)

	{
	if (!self.currentEnemy) return;
	
	//self.SetAnim(anim);
	}

qboolean RotateToEnemy::Evaluate
   (
	Actor &self
	)

	{
	if (!self.currentEnemy) return false;
	
	Vector dir = self.currentEnemy->origin - self.origin;
	float yaw_diff = AngleNormalize360( self.origin.toYaw() - dir.toYaw() );
	
	if (yaw_diff < 180 )
		self.angles[YAW]+=turnSpeed;

	if (yaw_diff > 180 )
		self.angles[YAW]-=turnSpeed;

	self.setAngles(self.angles);

	if (self.InFOV(self.currentEnemy) )
		return false;
	else
		return true;
	}

void RotateToEnemy::End
   (
	Actor &self
	)

	{

	}

/****************************************************************************

  HeadWatch Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, HeadWatch, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HeadWatch::HeadWatch()
	{
	max_speed = 10;
	forever = true;
	usingEyes = false;
	}

void HeadWatch::SetArgs
	(
	Event *ev
	)

	{
	ent_to_watch = ev->GetEntity( 1 );

	if ( ev->NumArgs() > 1 )
		max_speed = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		forever = ev->GetBoolean( 3 );
	}


void HeadWatch::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HeadWatch::Begin
	(
	Actor &self
	)

	{
	self.SetControllerTag( ACTOR_HEAD_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" ) );

	current_head_angles = self.GetControllerAngles( ACTOR_HEAD_TAG );

	self.SetActorFlag( ACTOR_FLAG_TURNING_HEAD, true );
	}

qboolean	HeadWatch::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;	
	Vector tag_pos;
	Vector watch_tag_pos;
	Vector angles_diff;
	Vector watch_position;
	Actor *act = NULL;
	Vector change;
	

	if ( ent_to_watch )
		{
		tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" );

		if ( tag_num < 0 )
			return false;

		self.GetTag( "Bip01 Head", &tag_pos );

		if ( ent_to_watch->isSubclassOf( Actor ) )
			act = (Actor *)(Entity *)ent_to_watch;

		if ( act && act->watch_offset != vec_zero )
			{
			MatrixTransformVector( act->watch_offset, ent_to_watch->orientation, watch_position );
			watch_position += ent_to_watch->origin;
			}
		else
			{			
			tag_num = gi.Tag_NumForName( ent_to_watch->edict->s.modelindex, "Bip01 Head" );
			
			if ( tag_num < 0 )
				watch_position = ent_to_watch->centroid;
			else
				{
				ent_to_watch->GetTag( "Bip01 Head", &watch_tag_pos );
				watch_position = watch_tag_pos;
				}
			}

		dir = watch_position - tag_pos;
		angles = dir.toAngles();

		angles_diff = angles - self.angles;
		}
	else
		{
		angles_diff = vec_zero;
		}

	angles_diff[YAW]   = AngleNormalize180( angles_diff[YAW] );
	angles_diff[PITCH] = AngleNormalize180( angles_diff[PITCH] );

	if (usingEyes)
		{
		if (angles_diff[YAW] > (self.minEyeYawAngle + (self.minEyeYawAngle * .5 )) && angles_diff[YAW] < (self.maxEyeYawAngle + (self.maxEyeYawAngle * .5 )))
			angles_diff[YAW] = 0;
		if (angles_diff[PITCH] > self.minEyePitchAngle && angles_diff[PITCH] < self.maxEyePitchAngle )
		   angles_diff[PITCH] = 0;
		}

	// Make sure we don't turn neck too far
	
	if ( angles_diff[YAW] < -80 )
		angles_diff[YAW] = -80;
	else if ( angles_diff[YAW] > 80 )
		angles_diff[YAW] = 80;

	if ( angles_diff[PITCH] < -45 )
		angles_diff[PITCH] = -45;
	else if ( angles_diff[PITCH] > 45 )
		angles_diff[PITCH] = 45;



	angles_diff[ROLL] = 0;

	// Make sure we don't change our head angles too much at once

	change = angles_diff - current_head_angles;

	if ( change[YAW] > max_speed )
		angles_diff[YAW] = current_head_angles[YAW] + max_speed;
	else if ( change[YAW] < -max_speed )
		angles_diff[YAW] = current_head_angles[YAW] - max_speed;

	if ( change[PITCH] > max_speed )
		angles_diff[PITCH] = current_head_angles[PITCH] + max_speed;
	else if ( change[PITCH] < -max_speed )
		angles_diff[PITCH] = current_head_angles[PITCH] - max_speed;

	self.SetControllerAngles( ACTOR_HEAD_TAG, angles_diff );
	self.real_head_pitch = angles_diff[PITCH];

	current_head_angles = angles_diff;
	//self.eyeposition = current_head_angles;
	
	if ( !ent_to_watch && current_head_angles == vec_zero )
		return false;

	if ( !forever && change[YAW] < max_speed && change[YAW] > -max_speed && change[PITCH] < max_speed && change[PITCH] > -max_speed )
		return false;

	return true;
	}

void HeadWatch::useEyes 
   (
	qboolean moveEyes
	)

	{
	usingEyes = moveEyes;
	}

void HeadWatch::End
	(
	Actor &self
	)

	{
	// Snap head back into position if we have lost our target or we are doing a resethead

	//if ( ent_to_watch )
	//	{
		self.SetControllerAngles( ACTOR_HEAD_TAG, vec_zero );
		self.real_head_pitch = 0;
	//	}

	self.SetActorFlag( ACTOR_FLAG_TURNING_HEAD, false );
	}



/****************************************************************************

  HeadWatchEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, HeadWatchEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HeadWatchEnemy::HeadWatchEnemy()
	{
	max_speed = 10;
	forever = true;
	usingEyes = false;
	threshold = 0;
	}

void HeadWatchEnemy::SetArgs
	(
	Event *ev
	)

	{
	max_speed = ev->GetFloat( 1 );

	if ( ev->NumArgs() > 1 )
		forever = ev->GetBoolean( 2 );

	if ( ev->NumArgs() > 2 )
		threshold = ev->GetFloat( 3 );
	}


void HeadWatchEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HeadWatchEnemy::Begin
	(
	Actor &self
	)

	{
	self.SetControllerTag( ACTOR_HEAD_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" ) );

	current_head_angles = self.GetControllerAngles( ACTOR_HEAD_TAG );

	self.SetActorFlag( ACTOR_FLAG_TURNING_HEAD, true );

	ent_to_watch = self.currentEnemy;
	}

qboolean	HeadWatchEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;	
	Vector tag_pos;
	Vector watch_tag_pos;
	Vector angles_diff;
	Vector watch_position;
	Actor *act = NULL;
	Vector change;
	
	
	if ( ent_to_watch )
		{
		tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" );

		if ( tag_num < 0 )
			return false;

		self.GetTag( "Bip01 Head", &tag_pos );

		if ( ent_to_watch->isSubclassOf( Actor ) )
			act = (Actor *)(Entity *)ent_to_watch;

		if ( act && act->watch_offset != vec_zero )
			{
			MatrixTransformVector( act->watch_offset, ent_to_watch->orientation, watch_position );
			watch_position += ent_to_watch->origin;
			}
		else
			{			
			tag_num = gi.Tag_NumForName( ent_to_watch->edict->s.modelindex, "Bip01 Head" );
			
			if ( tag_num < 0 )
				watch_position = ent_to_watch->centroid;
			else
				{
				ent_to_watch->GetTag( "Bip01 Head", &watch_tag_pos );
				watch_position = watch_tag_pos;
				}
			}

		dir = watch_position - tag_pos;
		angles = dir.toAngles();

		angles_diff = angles - self.angles;
		}
	else
		{
		angles_diff = vec_zero;
		}

	angles_diff[YAW]   = AngleNormalize180( angles_diff[YAW] );
	angles_diff[PITCH] = AngleNormalize180( angles_diff[PITCH] );

	float yaw_change = angles_diff[YAW];
	float pitch_change = angles_diff[PITCH];
	if ( threshold && yaw_change < threshold && yaw_change > -threshold && pitch_change < threshold && pitch_change > -threshold )
		{
		if ( forever )
			return true;
		else
			return false;
		}

	if (usingEyes)
		{
		if (angles_diff[YAW] > (self.minEyeYawAngle + (self.minEyeYawAngle * .5 )) && angles_diff[YAW] < (self.maxEyeYawAngle + (self.maxEyeYawAngle * .5 )))
			angles_diff[YAW] = 0;
		if (angles_diff[PITCH] > self.minEyePitchAngle && angles_diff[PITCH] < self.maxEyePitchAngle )
		   angles_diff[PITCH] = 0;
		}

	// Make sure we don't turn neck too far
	
	if ( angles_diff[YAW] < -80 )
		angles_diff[YAW] = -80;
	else if ( angles_diff[YAW] > 80 )
		angles_diff[YAW] = 80;

	if ( angles_diff[PITCH] < -45 )
		angles_diff[PITCH] = -45;
	else if ( angles_diff[PITCH] > 45 )
		angles_diff[PITCH] = 45;



	angles_diff[ROLL] = 0;

	// Make sure we don't change our head angles too much at once

	change = angles_diff - current_head_angles;

	if ( change[YAW] > max_speed )
		angles_diff[YAW] = current_head_angles[YAW] + max_speed;
	else if ( change[YAW] < -max_speed )
		angles_diff[YAW] = current_head_angles[YAW] - max_speed;

	if ( change[PITCH] > max_speed )
		angles_diff[PITCH] = current_head_angles[PITCH] + max_speed;
	else if ( change[PITCH] < -max_speed )
		angles_diff[PITCH] = current_head_angles[PITCH] - max_speed;

	self.SetControllerAngles( ACTOR_HEAD_TAG, angles_diff );
	self.real_head_pitch = angles_diff[PITCH];

	current_head_angles = angles_diff;
	//self.eyeposition = current_head_angles;
	
	if ( !ent_to_watch && current_head_angles == vec_zero )
		return false;

	if ( !forever && change[YAW] < max_speed && change[YAW] > -max_speed && change[PITCH] < max_speed && change[PITCH] > -max_speed )
		return false;

	return true;
	}

void HeadWatchEnemy::useEyes 
   (
	qboolean moveEyes
	)

	{
	usingEyes = moveEyes;
	}

void HeadWatchEnemy::End
	(
	Actor &self
	)

	{
	// Snap head back into position if we have lost our target or we are doing a resethead

	//if ( ent_to_watch )
	//	{
		self.SetControllerAngles( ACTOR_HEAD_TAG, vec_zero );
		self.real_head_pitch = 0;
	//	}

	self.SetActorFlag( ACTOR_FLAG_TURNING_HEAD, false );
	}
	
	
/****************************************************************************

  EyeWatch Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, EyeWatch, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

EyeWatch::EyeWatch()
	{
	ent_to_watch = NULL;
	max_speed = 10;
	forever = true;
	threshold = 0;
	}

void EyeWatch::SetArgs
	(
	Event *ev
	)

	{
	
	ent_to_watch = ev->GetEntity( 1 );

	if ( ev->NumArgs() > 1 )
		max_speed = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		forever = ev->GetBoolean( 3 );

	if ( ev->NumArgs() > 3 )
		threshold = ev->GetFloat( 4 );
	}


void EyeWatch::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void EyeWatch::Begin
	(
	Actor &self
	)

	{
	self.SetControllerTag( ACTOR_LEYE_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Face eyeballL" ) );
	self.SetControllerTag( ACTOR_REYE_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Face eyeballR" ) );
	

	current_left_eye_angles = self.GetControllerAngles( ACTOR_LEYE_TAG );
	current_right_eye_angles = self.GetControllerAngles( ACTOR_REYE_TAG );

	self.SetActorFlag( ACTOR_FLAG_MOVING_EYES, true );
	}

qboolean	EyeWatch::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;		
	Vector tag_pos;
	Vector watch_tag_pos;
	Vector angles_diff;
	Vector watch_position;
	Actor *act = NULL;
	Vector change;

	if ( ent_to_watch )
		{
		tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" );
		
		if ( tag_num < 0 )
			return false;

		self.GetTag( "Bip01 Head", &tag_pos );

		if ( ent_to_watch->isSubclassOf( Actor ) )
			act = (Actor *)(Entity *)ent_to_watch;

		if ( act && act->watch_offset != vec_zero )
			{
			MatrixTransformVector( act->watch_offset, ent_to_watch->orientation, watch_position );
			watch_position += ent_to_watch->origin;
			}
		else
			{			
			tag_num = gi.Tag_NumForName( ent_to_watch->edict->s.modelindex, "Bip01 Head" );
			
			if ( tag_num < 0 )
				watch_position = ent_to_watch->centroid;
			else
				{
				ent_to_watch->GetTag( "Bip01 Head", &watch_tag_pos );
				watch_position = watch_tag_pos;
				}
			}

		dir = watch_position - tag_pos;
		if ( dir.length() < 32 )
			{
			if ( !forever )
				return false;
			else 
			   return true;
			}

		angles = dir.toAngles();

		angles_diff = angles - self.angles;		
		}
	else
		{
		angles_diff = vec_zero;		
		}

	angles_diff[YAW]   = AngleNormalize180( angles_diff[YAW] );	
	
	// Make sure we don't turn eyes too far
	if ( angles_diff[YAW] < self.minEyeYawAngle )
		angles_diff[YAW] = self.minEyeYawAngle ;
	else if ( angles_diff[YAW] > self.maxEyeYawAngle  )
		angles_diff[YAW] = self.maxEyeYawAngle;

	if ( angles_diff[PITCH] < self.minEyePitchAngle  )
		angles_diff[PITCH] = self.minEyePitchAngle ;
	else if ( angles_diff[PITCH] > self.maxEyePitchAngle  )
		angles_diff[PITCH] = self.maxEyePitchAngle;

	angles_diff[ROLL] = 0;


	// Make sure we don't change our eye angles too much at once

	change = angles_diff - current_left_eye_angles;	

	
	// check left eye -- both eyes will be the same
	if ( change[YAW] > max_speed )
		angles_diff[YAW] = current_left_eye_angles[YAW] + max_speed;
	else if ( change[YAW] < -max_speed )
		angles_diff[YAW] = current_left_eye_angles[YAW] - max_speed;

	if ( change[PITCH] > max_speed )
		angles_diff[PITCH] = current_left_eye_angles[PITCH] + max_speed;
	else if ( change[PITCH] < -max_speed )
		angles_diff[PITCH] = current_left_eye_angles[PITCH] - max_speed;

	self.SetControllerAngles( ACTOR_LEYE_TAG, angles_diff );
	self.SetControllerAngles( ACTOR_REYE_TAG, angles_diff );
	//self.real_head_pitch = angles_diff[PITCH];

	current_left_eye_angles = angles_diff;
	current_right_eye_angles = angles_diff;
	//self.eyeposition = current_head_angles;
	
	if ( !ent_to_watch && current_left_eye_angles == vec_zero )
		return false;


	if ( !forever && change[YAW] < max_speed && change[YAW] > -max_speed &&
		change[PITCH] < max_speed && change[PITCH] > -max_speed )
		return false;

	return true;
	}

void EyeWatch::End
	(
	Actor &self
	)

	{
	// Snap head back into position if we have lost our target or we are doing a resethead

	//if ( !ent_to_watch )
	//	{
		self.SetControllerAngles( ACTOR_LEYE_TAG, vec_zero );
		self.SetControllerAngles( ACTOR_REYE_TAG, vec_zero );

		//self.real_head_pitch = 0;
	//	}

	self.SetActorFlag( ACTOR_FLAG_MOVING_EYES, false );
	}




/****************************************************************************

  EyeWatchEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, EyeWatchEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

EyeWatchEnemy::EyeWatchEnemy()
	{
	ent_to_watch = NULL;
	max_speed = 10;
	forever = true;
	threshold = 0;
	}

void EyeWatchEnemy::SetArgs
	(
	Event *ev
	)

	{
	
	max_speed = ev->GetFloat( 1 );

	if ( ev->NumArgs() > 1 )
		forever = ev->GetBoolean( 2 );

	if ( ev->NumArgs() > 2 )
		threshold = ev->GetFloat( 3 );
	}


void EyeWatchEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void EyeWatchEnemy::Begin
	(
	Actor &self
	)

	{
	self.SetControllerTag( ACTOR_LEYE_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Face eyeballL" ) );
	self.SetControllerTag( ACTOR_REYE_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Face eyeballR" ) );
	

	current_left_eye_angles = self.GetControllerAngles( ACTOR_LEYE_TAG );
	current_right_eye_angles = self.GetControllerAngles( ACTOR_REYE_TAG );

	self.SetActorFlag( ACTOR_FLAG_MOVING_EYES, true );
	}

qboolean	EyeWatchEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;		
	Vector tag_pos;
	Vector watch_tag_pos;
	Vector angles_diff;
	Vector watch_position;
	Actor *act = NULL;
	Vector change;

	ent_to_watch = self.currentEnemy;

	if ( ent_to_watch )
		{
		tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Head" );
		
		if ( tag_num < 0 )
			return false;

		self.GetTag( "Bip01 Head", &tag_pos );

		if ( ent_to_watch->isSubclassOf( Actor ) )
			act = (Actor *)(Entity *)ent_to_watch;

		if ( act && act->watch_offset != vec_zero )
			{
			MatrixTransformVector( act->watch_offset, ent_to_watch->orientation, watch_position );
			watch_position += ent_to_watch->origin;
			}
		else
			{			
			tag_num = gi.Tag_NumForName( ent_to_watch->edict->s.modelindex, "Bip01 Head" );
			
			if ( tag_num < 0 )
				watch_position = ent_to_watch->centroid;
			else
				{
				ent_to_watch->GetTag( "Bip01 Head", &watch_tag_pos );
				watch_position = watch_tag_pos;
				}
			}

		dir = watch_position - tag_pos;
		angles = dir.toAngles();

		angles_diff = angles - self.angles;		
		}
	else
		{
		angles_diff = vec_zero;		
		}

	angles_diff[YAW]   = AngleNormalize180( angles_diff[YAW] );	
	
	
	float yaw_change = angles_diff[YAW];
	float pitch_change = angles_diff[PITCH];
	if ( threshold && yaw_change < threshold && yaw_change > -threshold && pitch_change < threshold && pitch_change > -threshold )
		{
		if ( forever )
			return true;
		else
			return false;
		}

	
	// Make sure we don't turn eyes too far
	if ( angles_diff[YAW] < self.minEyeYawAngle )
		angles_diff[YAW] = self.minEyeYawAngle ;
	else if ( angles_diff[YAW] > self.maxEyeYawAngle  )
		angles_diff[YAW] = self.maxEyeYawAngle;

	if ( angles_diff[PITCH] < self.minEyePitchAngle  )
		angles_diff[PITCH] = self.minEyePitchAngle ;
	else if ( angles_diff[PITCH] > self.maxEyePitchAngle  )
		angles_diff[PITCH] = self.maxEyePitchAngle;

	angles_diff[ROLL] = 0;


	// Make sure we don't change our eye angles too much at once

	change = angles_diff - current_left_eye_angles;	

	
	// check left eye -- both eyes will be the same
	if ( change[YAW] > max_speed )
		angles_diff[YAW] = current_left_eye_angles[YAW] + max_speed;
	else if ( change[YAW] < -max_speed )
		angles_diff[YAW] = current_left_eye_angles[YAW] - max_speed;

	if ( change[PITCH] > max_speed )
		angles_diff[PITCH] = current_left_eye_angles[PITCH] + max_speed;
	else if ( change[PITCH] < -max_speed )
		angles_diff[PITCH] = current_left_eye_angles[PITCH] - max_speed;

	self.SetControllerAngles( ACTOR_LEYE_TAG, angles_diff );
	self.SetControllerAngles( ACTOR_REYE_TAG, angles_diff );
	//self.real_head_pitch = angles_diff[PITCH];

	current_left_eye_angles = angles_diff;
	current_right_eye_angles = angles_diff;
	//self.eyeposition = current_head_angles;
	
	if ( !ent_to_watch && current_left_eye_angles == vec_zero )
		return false;


	if ( !forever && change[YAW] < max_speed && change[YAW] > -max_speed &&
		change[PITCH] < max_speed && change[PITCH] > -max_speed )
		return false;

	return true;
	}

void EyeWatchEnemy::End
	(
	Actor &self
	)

	{
	// Snap head back into position if we have lost our target or we are doing a resethead

	//if ( !ent_to_watch )
	//	{
		self.SetControllerAngles( ACTOR_LEYE_TAG, vec_zero );
		self.SetControllerAngles( ACTOR_REYE_TAG, vec_zero );

		//self.real_head_pitch = 0;
	//	}

	self.SetActorFlag( ACTOR_FLAG_MOVING_EYES, false );
	}

/****************************************************************************

  HeadAndEyeWatch Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, HeadAndEyeWatch, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HeadAndEyeWatch::HeadAndEyeWatch()
	{
	}

void HeadAndEyeWatch::SetArgs
	(
	Event *ev
	)

	{
	headWatch.SetArgs(ev);
	eyeWatch.SetArgs(ev);

	headWatch.useEyes(true);
	}


void HeadAndEyeWatch::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );	
	headWatch.ShowInfo(self);
	eyeWatch.ShowInfo(self);
	}

void HeadAndEyeWatch::Begin
	(
	Actor &self
	)

	{
	headWatch.Begin(self);
	eyeWatch.Begin(self);
	}

qboolean	HeadAndEyeWatch::Evaluate
	(
	Actor &self
	)

	{
   // if headWatch returns 0 and eyeWatch returns 0 -- returns 0
	// if headWatch returns 1 and eyeWatch returns 0 -- returns 0
	// if headWatch returns 0 and eyeWatch returns 1 -- returns 0
	// if headWatch returns 1 and eyeWatch returns 1 -- returns 1
	return ( headWatch.Evaluate(self) && eyeWatch.Evaluate(self) );
	}

void HeadAndEyeWatch::End
	(
	Actor &self
	)

	{
	headWatch.End(self);
	eyeWatch.End(self);
	}


/****************************************************************************

  TorsoTurn Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TorsoTurn, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void TorsoTurn::SetArgs
	(
	Event *ev
	)

	{
	turn_towards_enemy = ev->GetInteger( 1 );
	speed              = ev->GetFloat( 2 );
	forever            = ev->GetInteger( 3 );		

	if ( ev->NumArgs() > 3 )
		tag_name = ev->GetString( 4 );

	if ( ev->NumArgs() > 4 )
		tolerance = ev->GetFloat( 5 );
	else
		tolerance = 0;

	if ( ev->NumArgs() > 5 )
		offset = ev->GetFloat( 6 );
	else
		offset = 0;
	
	if ( ev->NumArgs() > 6 )
		use_pitch = ev->GetBoolean( 7 );
	else
		use_pitch = true;
	}


void TorsoTurn::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void TorsoTurn::Begin
	(
	Actor &self
	)

	{
	Vector controller_angles;

	self.SetControllerTag( ACTOR_TORSO_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Spine1" ) );

	controller_angles = self.GetControllerAngles( ACTOR_TORSO_TAG );

	current_yaw   = controller_angles[YAW];
	current_pitch = controller_angles[PITCH];
	}

qboolean	TorsoTurn::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;
	float yaw_diff;
	float pitch_diff;
	Vector new_angles;
	float yaw_change;
	float pitch_change;
	Vector tag_pos;
	Vector tag_forward;
	Vector tag_angles;
   
	

	tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Spine1" );

	if ( tag_num < 0 )
		return false;

	// Determine the angle we want to go to

	if ( turn_towards_enemy )
		{
		if ( !self.currentEnemy )
			return false;

		if ( tag_name.length() )
			{
			self.GetTag( tag_name.c_str(), &tag_pos, &tag_forward );
			tag_angles = tag_forward.toAngles();
			dir = self.currentEnemy->centroid - tag_pos;
			}
		else
			{
			dir = self.currentEnemy->centroid - self.centroid;
			}
		
	
	

		angles = dir.toAngles();
		
	
		
		angles[YAW] += offset;

		yaw_diff   = AngleNormalize180( angles[YAW] - self.angles[YAW] );
		pitch_diff = AngleNormalize180( angles[PITCH] - self.angles[PITCH] );
		}
	else
		{
		yaw_diff   = 0;
		pitch_diff = 0;
		}

	// Determine the angle change

	yaw_change   = AngleNormalize180( yaw_diff - current_yaw );
	pitch_change = AngleNormalize180( pitch_diff - current_pitch );

	if ( tolerance && yaw_change < tolerance && yaw_change > -tolerance && pitch_change < tolerance && pitch_change > -tolerance )
		{
		if ( forever )
			return true;
		else
			return false;
		}

	// Make sure we don't change our torso angles too much at once

	if ( yaw_change > speed )
		yaw_diff = current_yaw + speed;
	else if ( yaw_change < -speed )
		yaw_diff = current_yaw - speed;

	if ( pitch_change > speed )
		pitch_diff = current_pitch + speed;
	else if ( yaw_change < -speed )
		pitch_diff = current_pitch - speed;

	// Determine our new angles

	new_angles[YAW]   = yaw_diff;
	
	if ( use_pitch )
		new_angles[PITCH] = pitch_diff;
	else
		new_angles[PITCH] = 0;
	
	new_angles[ROLL]  = 0;

	// Make sure we don't turn too far

	if ( new_angles[YAW] > 100 || new_angles[YAW] <   -100  )
		{
		if (!forever ) 
			return false;
		else
			{
 	 	   self.angles[YAW] = new_angles[YAW];
		   self.angles[ROLL] = 0;
		   self.setAngles( self.angles );
			return true;
			}
		   
		}
		

	if ( new_angles[PITCH] > 45 || new_angles[PITCH] < -45 )
		{
		if (!forever ) 
			return false;
		else
			return true;
		}


	// Set our new angles

	self.SetControllerAngles( ACTOR_TORSO_TAG, new_angles );

	current_yaw = yaw_diff;
	current_pitch = pitch_diff;

	// See if we are turned the correct direction now

	if ( !forever && (yaw_change < speed) && (yaw_change > -speed) && (pitch_change < speed) && (pitch_change > -speed) )
		return false;

	return true;
	}

void TorsoTurn::End
	(
	Actor &self
	)

	{
	self.SetControllerAngles( ACTOR_TORSO_TAG, vec_zero );		
	}





/****************************************************************************

  TorsoWatchEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TorsoWatchEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void TorsoWatchEnemy::SetArgs
	(
	Event *ev
	)

	{
	
	invert = false;

	speed              = ev->GetFloat( 1 );
	forever            = ev->GetInteger( 2 );		
	threshold          = ev->GetFloat( 3 );

	if ( ev->NumArgs() > 3 )
		offset = ev->GetFloat( 4 );
	else
		offset = 0;
	
	if ( ev->NumArgs() > 4 )
		use_pitch = ev->GetBoolean( 5 );
	else
		use_pitch = true;
	
	if ( ev->NumArgs() > 5 )
		invert = ev->GetBoolean( 6 );

	if ( ev->NumArgs() > 6 )
		reset = ev->GetBoolean ( 7 );
	else
		reset = true;
	
	}


void TorsoWatchEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void TorsoWatchEnemy::Begin
	(
	Actor &self
	)

	{
	Vector controller_angles;

	self.SetControllerTag( ACTOR_TORSO_TAG, gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Spine1" ) );

	controller_angles = self.GetControllerAngles( ACTOR_TORSO_TAG );

	current_yaw   = controller_angles[YAW];
	current_pitch = controller_angles[PITCH];
	}

qboolean	TorsoWatchEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	int tag_num;
	float yaw_diff;
	float pitch_diff;
	Vector new_angles;
	float yaw_change;
	float pitch_change;
	Vector tag_pos;
	Vector tag_forward;
	Vector tag_angles;
   
	

	tag_num = gi.Tag_NumForName( self.edict->s.modelindex, "Bip01 Spine1" );

	if ( tag_num < 0 )
		return false;

	// Determine the angle we want to go to

	if ( !self.currentEnemy )
			return false;

	dir = self.currentEnemy->centroid - self.centroid;	
	
	if (invert)
		dir *= -1;


	angles = dir.toAngles();
			
	angles[YAW] += offset;

	yaw_diff   = AngleNormalize180( angles[YAW] - self.angles[YAW] );
	pitch_diff = AngleNormalize180( angles[PITCH] - self.angles[PITCH] );
	

	// Determine the angle change

	yaw_change   = AngleNormalize180( yaw_diff - current_yaw );
	pitch_change = AngleNormalize180( pitch_diff - current_pitch );

	if ( threshold && yaw_change < threshold && yaw_change > -threshold && pitch_change < threshold && pitch_change > -threshold )
		{
		if ( forever )
			return true;
		else
			return false;
		
		}

	// Make sure we don't change our torso angles too much at once

	if ( yaw_change > speed )
		yaw_diff = current_yaw + speed;
	else if ( yaw_change < -speed )
		yaw_diff = current_yaw - speed;

	if ( pitch_change > speed )
		pitch_diff = current_pitch + speed;
	else if ( yaw_change < -speed )
		pitch_diff = current_pitch - speed;

	// Determine our new angles

	new_angles[YAW]   = yaw_diff;
	
	if ( use_pitch )
		{
		new_angles[PITCH] = pitch_diff;
		if ( invert )
			new_angles[PITCH] *= -1;
		}
		
	else
		new_angles[PITCH] = 0;
	
	new_angles[ROLL]  = 0;

	// Make sure we don't turn too far

	if ( new_angles[YAW] > 100 || new_angles[YAW] <   -100  )
		{
		if (!forever ) 
			return false;
		else
			{
			if ( new_angles[YAW] < -100 )
				new_angles[YAW] = -100;

			if ( new_angles[YAW] > -100 )
				new_angles[YAW] = 100;

			return true;

			}
		   
		}
		

	if ( new_angles[PITCH] > 60 || new_angles[PITCH] < -60 )
		{
		if (!forever ) 
			return false;
		else
			return true;
		}


	// Set our new angles

	self.SetControllerAngles( ACTOR_TORSO_TAG, new_angles );

	current_yaw = yaw_diff;
	current_pitch = pitch_diff;

	// See if we are turned the correct direction now

	if ( !forever && (yaw_change < speed) && (yaw_change > -speed) && (pitch_change < speed) && (pitch_change > -speed) )
		return false;

	return true;
	}

void TorsoWatchEnemy::End
	(
	Actor &self
	)

	{
	if ( reset )
		self.SetControllerAngles( ACTOR_TORSO_TAG, vec_zero );		
	}
/****************************************************************************

  GotoPathNode Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, GotoPathNode, NULL )
	{
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

GotoPathNode::GotoPathNode()
	{
	usevec = false;
	movegoal = NULL;
	goal = vec_zero;
	goalent = NULL;
	}

void GotoPathNode::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->IsVectorAt( 2 ) )
		{
		goal = ev->GetVector( 2 );
		usevec = true;
		}
	else
		{
      usevec = false;
		movegoal = AI_FindNode( ev->GetString( 2 ) );
		if ( !movegoal )
			{
			goalent = ev->GetEntity( 2 );
			}
		}

	if ( ev->NumArgs() > 2 )
		entity_to_watch = ev->GetEntity( 3 );
	}

void GotoPathNode::AnimDone
	(
	Event *ev
	)

	{
	turnto.ProcessEvent( EV_Behavior_AnimDone );
	}

void GotoPathNode::SetGoal
	(
	PathNode *node
	)

	{
	usevec = false;
	movegoal = node;
	}

void GotoPathNode::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nturnto:\n" );
   turnto.ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );

   gi.Printf( "\nstate: %d\n", state );
   gi.Printf( "usevec: %d\n", usevec );
   gi.Printf( "time: %f\n", time );
   gi.Printf( "anim: %s\n", anim.c_str() );

   if ( goalent )
      {
      gi.Printf( "\ngoalent: #%d '%s'\n", goalent->entnum, goalent->targetname.c_str() );
      }
   else
      {
      gi.Printf( "\ngoalent: NULL\n" );
      }

   gi.Printf( "goal: ( %f, %f, %f )\n", goal.x, goal.y, goal.z );
	}

void GotoPathNode::Begin
	(
	Actor &self
	)

	{
	Event *ev;

	state = 0;
	chase.Begin( self );
	turnto.Begin( self );
	if ( goalent )
		{
		chase.SetTarget( goalent );
		}
	else if ( movegoal )
      {
      chase.SetGoal( movegoal );
      }
   else
		{
		chase.SetGoalPos( goal );
		}

   // don't check for new paths as often
   chase.SetPathRate( 4 );

	chase.AllowFail( true );

	if ( anim.length() )
		{
		self.SetAnim( anim );
		}

	// Setup head watch stuff

	head_watch.Begin( self );

	ev = new Event( EV_Behavior_Args );
	ev->AddEntity( entity_to_watch );
	head_watch.ProcessEvent( ev );
	}

qboolean	GotoPathNode::Evaluate
	(
	Actor &self
	)

	{
	float yaw;

	if ( !usevec && !goalent && !movegoal )
		{
		gi.DPrintf( "GotoPathNode::No goal\n" );
		return false;
		}

	if ( entity_to_watch )
		head_watch.Evaluate( self );

	switch( state )
		{
		case 0 :
			if ( chase.Evaluate( self ) )
				{
				break;
				}

			state = 1;
			self.SetAnim( "idle" );

			// cascade down to case 1
		case 1 :
			if ( !movegoal )
				{
				return false;
				}

			if ( movegoal->setangles )
				{
            yaw = movegoal->angles.yaw();
				turnto.SetDirection( yaw );
				if ( turnto.Evaluate( self ) )
					{
					break;
					}
				}

			if ( movegoal->animname == "" )
				{
            self.SetAnim( "idle" );
				return false;
				}

			self.SetAnim( movegoal->animname, EV_Actor_FinishedBehavior );
			state = 2;
			break;

		case 2 :
			break;
		}

	return true;
	}

void GotoPathNode::End
	(
	Actor &self
	)

	{
	chase.End( self );
	head_watch.End( self );
	}

/****************************************************************************

  Flee Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Flee, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void Flee::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void Flee::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void Flee::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
		{
		self.SetAnim( anim );
		}

	chase.Begin( self );
	FindFleeNode( self );
	}

void Flee::FindFleeNode
	(
	Actor &self
	)
	{
	int i;
	PathNode *start_node;
	pathway_t *path;
	PathNode *current_node;
	int max_nodes_to_look_at;
	int nodes_looked_at;
	qboolean found;


	// Get closest node

	start_node = PathManager.NearestNode( self.origin, &self );

	// Find a random node that is connected to this node

	found = false;

	if ( start_node )
		{
		max_nodes_to_look_at = G_Random( 5 ) + 10;
		nodes_looked_at = 0;
		current_node = start_node;

		while( !found )
			{
			nodes_looked_at++;

			if ( nodes_looked_at >= max_nodes_to_look_at && current_node != start_node )
				{
				found = true;
				flee_node = current_node;
				}

			if ( current_node->numChildren == 0 )
				break;

			path = &current_node->Child[ (int)G_Random( current_node->numChildren ) ];
			current_node = AI_GetNode( path->node );
			}
		}

	if ( !found )
		{
		// If still not found, use old method

		for( i = 0; i < 5; i++ )
			{
			flee_node = AI_GetNode( ( int )G_Random( ai_maxnode + 1 ) );
			if ( flee_node )
				break;
			}
		}
	}

qboolean	Flee::Evaluate
	(
	Actor &self
	)

	{
	// Make sure we have somewhere to flee to

	if ( !flee_node )
		return false;

	chase.SetGoal( flee_node );

	// Make a racket

	self.Chatter( "snd_panic", 3 );

	// Try to get to flee node

	if ( !chase.Evaluate( self ) )
		{
		// See if we are done fleeing

		if ( !self.currentEnemy || !self.CanSee( self.currentEnemy ) )
			{
			return false;
			}

		// Find a new spot to flee to

		FindFleeNode( self );
		}

	return true;
	}

void Flee::End
	(
	Actor &self
	)

	{
	chase.End( self );
	}

/****************************************************************************

  PlayAnim Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, PlayAnim, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void PlayAnim::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void PlayAnim::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nanim: %s\n", anim.c_str() );
	}

void PlayAnim::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
		{
		if ( !self.SetAnim( anim, EV_Actor_FinishedBehavior ) )
         {
         self.PostEvent( EV_Actor_FinishedBehavior, 0 );
         }
		}
	}

qboolean	PlayAnim::Evaluate
	(
	Actor &self
	)

	{
	return true;
	}

void PlayAnim::End
	(
	Actor &self
	)

	{
	self.RemoveAnimDoneEvent();
	}

/****************************************************************************

  Talk Class Definition

****************************************************************************/

#define TALK_MODE_TURN_TO		0
#define TALK_MODE_TALK			1
#define TALK_MODE_WAIT			2
#define TALK_MODE_TURN_BACK	3

CLASS_DECLARATION( Behavior, Talk, NULL )
	{
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

void Talk::SetUser
	(
	Sentient *user
	)

	{
	ent_listening = user;
	}

void Talk::AnimDone
	(
	Event *ev
	)

	{
	turnto.ProcessEvent( EV_Behavior_AnimDone );
	}

void Talk::Begin
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	const char *anim_name;


	anim_name = self.animname;

	if ( strncmp( anim_name, "sit_leanover", 12 ) == 0 )
		{
		move_allowed = false;
		}
	else if ( strncmp( anim_name, "sit", 3 ) == 0 )
		{
		move_allowed = false;
		self.SetAnim( "sit_talk" );
		}
	else if ( strncmp( anim_name, "talk_sit_stunned", 15 ) == 0 )
		{
		move_allowed = false;
		}
	else if ( strncmp( anim_name, "talk_headset", 12 ) == 0 )
		{
		move_allowed = true;
		}
	else if ( strncmp( anim_name, "stand_hypnotized", 16 ) == 0 )
		{
		move_allowed = false;
		}
	else if ( strncmp( anim_name, "talk_hipnotic", 13 ) == 0 )
		{
		move_allowed = false;
		}
	else if ( strncmp( anim_name, "rope", 4 ) == 0 )
		{
		move_allowed = false;
		}
	else
		{
		move_allowed = true;
		self.SetAnim( "talk" );
		}

	mode = TALK_MODE_TURN_TO;
	original_yaw = self.angles[YAW];

	dir    = ent_listening->centroid - self.centroid;
	angles = dir.toAngles();
	yaw    = angles[YAW];
	}

qboolean	Talk::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	//Event *event;

	if ( !ent_listening )
		mode = TALK_MODE_TURN_BACK;

	switch( mode )
		{
		case TALK_MODE_TURN_TO :
			if ( move_allowed )
				{
				turnto.SetDirection( yaw );

				if ( !turnto.Evaluate( self ) )
					{
					mode = TALK_MODE_TALK;
					self.PlayDialog( ent_listening );

					/* event = new Event( EV_Player_WatchActor );
					event->AddEntity( &self );
					ent_listening->PostEvent(  event, 0.05 ); */
					}
				}
			else
				{
				mode = TALK_MODE_TALK;
				self.PlayDialog( ent_listening );

				/* event = new Event( EV_Player_WatchActor );
				event->AddEntity( &self );
				ent_listening->PostEvent(  event, 0.05 ); */
				}
			break;
		case TALK_MODE_TALK :

			if ( move_allowed )
				{
				dir    = ent_listening->centroid - self.centroid;
				angles = dir.toAngles();
				turnto.SetDirection( angles[YAW] );
				turnto.Evaluate( self );
				}

			if ( !self.GetActorFlag( ACTOR_FLAG_DIALOG_PLAYING ) )
				{
				mode = TALK_MODE_WAIT;
				self.state_flags &= ~STATE_FLAG_USED;

				// Tell player to stop watching us

				/* event = new Event( EV_Player_StopWatchingActor );
				event->AddEntity( &self );
				ent_listening->PostEvent(  event, 0 ); */

				//ent_listening->CancelEventsOfType( EV_Player_WatchActor );
				}
			else if ( !self.GetActorFlag( ACTOR_FLAG_RADIUS_DIALOG_PLAYING ) )
				{
				if ( !self.WithinDistance( ent_listening, self.radiusDialogRange  ) )
					{
					ScriptVariable *svar = gameVars.GetVariable ( "ghostshirt50" );
					int gslevel = svar->intValue();
					str check_alias;
					if (gslevel)
						{
						check_alias = self.GetRandomAlias("radiusdialog_positive");
						if(check_alias.length())
							{
							self.PlayRadiusDialog(ent_listening, "radiusdialog_positive");
							}				
						}
					else
						{
						check_alias = self.GetRandomAlias("radiusdialog_negative");
						if(check_alias.length())
							{
							self.PlayRadiusDialog(ent_listening, "radiusdialog_negative");
							}			
						}
					}				
				}
			break;
		case TALK_MODE_WAIT :

			if ( move_allowed )
				{
				dir    = ent_listening->centroid - self.centroid;
				angles = dir.toAngles();
				turnto.SetDirection( angles[YAW] );
				turnto.Evaluate( self );
				}

			if ( !self.WithinDistance( ent_listening, 100 ) )
				mode = TALK_MODE_TURN_BACK;

			if ( self.state_flags & STATE_FLAG_USED )
				{
				mode = TALK_MODE_TURN_TO;

				dir    = ent_listening->centroid - self.centroid;
				angles = dir.toAngles();
				yaw    = angles[YAW];

				self.state_flags &= ~STATE_FLAG_USED;

				/* event = new Event( EV_Player_WatchActor );
				event->AddEntity( &self );
				ent_listening->PostEvent(  event, 0.05 ); */
				}
			break;
		case TALK_MODE_TURN_BACK :
			if ( move_allowed )
				{
				turnto.SetDirection( original_yaw );

				if ( !turnto.Evaluate( self ) )
					return false;
				}
			else
				{
				return false;
				}

			break;
		}

	return true;
	}

void Talk::End
	(
	Actor &self
	)

	{
	//Event *event;

	/* event = new Event( EV_Player_StopWatchingActor );
	event->AddEntity( &self );
	ent_listening->PostEvent(  event, 0 ); */

	//ent_listening->CancelEventsOfType( EV_Player_WatchActor );
	}

/****************************************************************************

  FindCover Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FindCover, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void FindCover::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		crouch_anim = ev->GetString( 2 );
	}

PathNode *FindCover::FindCoverNode
	(
	Actor &self
	)

	{
	int i;
	PathNode	*bestnode;
	float		bestdist;
	PathNode	*desperatebestnode;
	float		desperatebestdist;
	PathNode *node;
	FindCoverPath find;
	Path		*path;
	Vector	delta;
	float		dist;
	Vector	pos;

   pos = self.origin;

   // greater than ( 8192 * sqr(2) ) ^ 2 -- maximum squared distance
	bestdist = 999999999;
	bestnode = NULL;

   // greater than ( 8192 * sqr(2) ) ^ 2 -- maximum squared distance
	desperatebestdist = 999999999;
	desperatebestnode = NULL;

   for( i = 0; i <= ai_maxnode; i++ )
		{
		node = AI_GetNode( i );
		if ( node && ( node->nodeflags & ( AI_DUCK | AI_COVER ) ) &&
			( ( node->occupiedTime <= level.time ) || ( node->entnum == self.entnum ) ) )
			{
			// get the distance squared (faster than getting real distance)
         delta = node->origin - pos;
			dist = delta * delta;
         if ( ( dist < bestdist ) && ( !self.CanSeeEnemyFrom( node->origin ) ||//) )//||
            ( ( node->nodeflags & AI_DUCK ) && !self.CanSeeEnemyFrom( node->origin - Vector( 0, 0, 32 ) ) ) ) )
				{
				bestnode = node;
				bestdist = dist;
				}
			else if ( ( dist < desperatebestdist ) && ( desperatebestdist > ( 64 * 64 ) ) )
				{
				desperatebestnode = node;
				desperatebestdist = dist;
				}
			}
		}

	if ( !bestnode )
		{
		bestnode = desperatebestnode;
		}

	if ( bestnode )
		{
		find.heuristic.self = &self;
		find.heuristic.setSize( self.size );
		find.heuristic.entnum = self.entnum;

      path = find.FindPath( self.origin, bestnode->origin );
		if ( path )
			{
			node = path->End();

			// Mark node as occupied for a short time
			node->occupiedTime = level.time + 1.5;
			node->entnum = self.entnum;

			chase.SetGoal( node );
			chase.SetPath( path );

			return node;
			}
		}

	return NULL;
	}

void FindCover::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );

   gi.Printf( "\nstate: %d\n", state );
   gi.Printf( "anim: %s\n", anim.c_str() );
   gi.Printf( "nextsearch: %f\n", nextsearch );
	}

void FindCover::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
		{
		anim = "run";
		}

	if ( !crouch_anim.length() )
		{
		crouch_anim = "crouch_down";
		}

	movegoal = NULL;
	state = 0;
	}

qboolean	FindCover::Evaluate
	(
	Actor &self
	)

	{
	if ( !movegoal )
		{
		state = 0;
		}

	switch( state )
		{
		case 0 :
			// Checking for cover
			chase.Begin( self );
			movegoal = FindCoverNode( self );
			if ( !movegoal )
				{
            // Couldn't find any!
				return false;
				}

			// Found cover, going to it
			if ( anim.length() && ( anim != self.animname || self.newanim.length() ) )
				{
				self.SetAnim( anim );
				}

			state = 1;
			nextsearch = level.time + 1;

		case 1 :
			if ( chase.Evaluate( self ) )
				{
				if ( nextsearch < level.time )
					{
					state = 0;
					}
				return true;
				}

			// Reached cover
         if ( self.CanSeeEnemyFrom( self.origin ) )
				{
				state = 0;
				}

			if ( movegoal->nodeflags & AI_DUCK )
				{
            // ducking
				self.SetAnim( crouch_anim.c_str() );
				}
			else
				{
            // standing
				self.SetAnim( "idle" );
				}

			chase.End( self );
			return false;
			break;
		}

	return true;
	}

void FindCover::End
	(
	Actor &self
	)

	{
	chase.End( self );
	}

/****************************************************************************

  FindFlee Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FindFlee, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void FindFlee::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

PathNode *FindFlee::FindFleeNode
	(
	Actor &self
	)

	{
	int i;
	PathNode	*bestnode;
	float		bestdist;
	PathNode	*desperatebestnode;
	float		desperatebestdist;
	PathNode *node;
	FindFleePath find;
	Path		*path;
	Vector	delta;
	float		dist;
	Vector	pos;

   pos = self.origin;

   // greater than ( 8192 * sqr(2) ) ^ 2 -- maximum squared distance
	bestdist = 999999999;
	bestnode = NULL;

   // greater than ( 8192 * sqr(2) ) ^ 2 -- maximum squared distance
	desperatebestdist = 999999999;
   desperatebestnode = NULL;

	for( i = 0; i <= ai_maxnode; i++ )
		{
		node = AI_GetNode( i );
		if ( node && ( node->nodeflags & AI_FLEE ) &&
			( ( node->occupiedTime <= level.time ) || ( node->entnum == self.entnum ) ) )
			{
			// get the distance squared (faster than getting real distance)
         delta = node->origin - pos;
			dist = delta * delta;
         if ( ( dist < bestdist ) && !self.CanSeeEnemyFrom( node->origin ) )
				{
				bestnode = node;
				bestdist = dist;
				}
			else if ( ( dist < desperatebestdist ) && ( desperatebestdist > ( 64 * 64 ) ) )
				{
				desperatebestnode = node;
				desperatebestdist = dist;
				}
			}
		}

	if ( !bestnode )
		{
		bestnode = desperatebestnode;
		}

	if ( bestnode )
		{
		find.heuristic.self = &self;
		find.heuristic.setSize( self.size );
		find.heuristic.entnum = self.entnum;

      path = find.FindPath( self.origin, bestnode->origin );
		if ( path )
			{
			node = path->End();

			// Mark node as occupied for a short time
			node->occupiedTime = level.time + 1.5;
			node->entnum = self.entnum;

			chase.SetGoal( node );
			chase.SetPath( path );

			return node;
			}
		}

	return NULL;
	}

void FindFlee::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );

   gi.Printf( "\nstate: %d\n", state );
   gi.Printf( "anim: %s\n", anim.c_str() );
   gi.Printf( "nextsearch: %f\n", nextsearch );
	}

void FindFlee::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
		{
		anim = "run";
		}

	movegoal = NULL;
	state = 0;
	}

qboolean	FindFlee::Evaluate
	(
	Actor &self
	)

	{
	if ( !movegoal )
		{
		state = 0;
		}

	switch( state )
		{
		case 0 :
         // Checking for flee node
			chase.Begin( self );
			movegoal = FindFleeNode( self );
			if ( !movegoal )
				{
            // Couldn't find any!
				return false;
				}

         // Found flee node, going to it
			if ( anim.length() && ( anim != self.animname || self.newanim.length() ) )
				{
				self.SetAnim( anim );
				}

			state = 1;
			nextsearch = level.time + 1;

		case 1 :
			if ( chase.Evaluate( self ) )
				{
				if ( nextsearch < level.time )
					{
					state = 0;
					}
				return true;
				}

         // Reached cover
         if ( self.CanSeeEnemyFrom( self.origin ) )
				{
				state = 0;
				}
         else
            {
            // standing
	   		self.SetAnim( "idle" );
		   	chase.End( self );
			   return false;
            }
			break;
		}

	return true;
	}

void FindFlee::End
	(
	Actor &self
	)

	{
	chase.End( self );
	}

/****************************************************************************

  FindEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FindEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void FindEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void FindEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );

   gi.Printf( "\nstate: %d\n", state );
   gi.Printf( "nextsearch: %f\n", nextsearch );
   gi.Printf( "anim: %s\n", anim.c_str() );
	}

void FindEnemy::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
		{
		anim = "run";
		}

	movegoal = NULL;
   lastSearchNode = NULL;
	state = 0;
	}

PathNode *FindEnemy::FindClosestSightNode
	(
	Actor &self
	)

	{
	int i;
	PathNode	*bestnode;
	float		bestdist;
	PathNode *node;
	Vector	delta;
	float		dist;
	Vector	pos;

   if ( self.currentEnemy )
      {
      pos = self.currentEnemy->origin;
      }
   else
      {
      pos = self.origin;
      }

   // greater than ( 8192 * sqr(2) ) ^ 2 -- maximum squared distance
	bestdist = 999999999;
	bestnode = NULL;

	for( i = 0; i <= ai_maxnode; i++ )
		{
		node = AI_GetNode( i );
		if ( node && ( ( node->occupiedTime <= level.time ) || ( node->entnum != self.entnum ) ) )
			{
			// get the distance squared (faster than getting real distance)
         delta = node->origin - pos;
			dist = delta * delta;
         if ( ( dist < bestdist ) && self.CanSeeFrom( node->origin, self.currentEnemy ) )
				{
				bestnode = node;
				bestdist = dist;
				}
			}
		}

	return bestnode;
	}

qboolean	FindEnemy::Evaluate
	(
	Actor &self
	)

	{
	if ( !self.currentEnemy )
		{
		return false;
		}

	if ( nextsearch < level.time )
		{
      // check if we should search for the first time
      if ( !lastSearchNode )
         {
         state = 0;
         }
      else
         {
         // search less often if we're far away
			nextsearch = self.DistanceTo( self.currentEnemy ) * ( 1.0 / 512.0 );
         if ( nextsearch < 1 )
            {
            nextsearch = 1;
            }
         nextsearch += level.time;

         // don't search again if our enemy hasn't moved very far
         if ( !self.currentEnemy->WithinDistance( lastSearchPos, 256 ) )
            {
            state = 0;
            }
         }
		}

	switch( state )
		{
		case 0 :
			// Searching for enemy
			chase.Begin( self );
         lastSearchPos = self.currentEnemy->origin;
         movegoal = PathManager.NearestNode( lastSearchPos, &self );
         if ( !movegoal )
            {
            movegoal = PathManager.NearestNode( lastSearchPos, &self, false );
            }

         lastSearchNode = movegoal;
			if ( movegoal )
				{
				Path *path;
				FindEnemyPath find;
            PathNode *from;

				find.heuristic.self = &self;
				find.heuristic.setSize( self.size );
				find.heuristic.entnum = self.entnum;

            from = PathManager.NearestNode( self.origin, &self );
            if ( ( from == movegoal ) && ( self.DistanceTo( from->origin ) < 8 ) )
               {
               movegoal = NULL;
               from = NULL;
               }

            if ( from )
               {
               path = find.FindPath( from, movegoal );
				   if ( path )
					   {
					   chase.SetGoal( movegoal );
					   chase.SetPath( path );
					   }
               else
                  {
                  movegoal = NULL;
                  }
               }
				}

			if ( !movegoal )
				{
				if ( self.CanSee( self.currentEnemy ) || ( !self.currentEnemy->groundentity && !self.waterlevel ) )
					{
					chase.SetGoalPos( self.currentEnemy->origin );
					}
				else
					{
					// Couldn't find enemy
					// since we can't reach em
					// clear out enemy state
					self.ClearEnemies();
					return false;
					}
				}

         // Found enemy, going to it
			if ( anim.length() && ( anim != self.animname || self.newanim.length() ) )
				{
				self.SetAnim( anim );
				}

			state = 1;

		case 1 :
			if ( self.CanShoot( self.currentEnemy, false ) )
				{
				// Reached enemy
				chase.End( self );
				return false;
				}

			if ( !chase.Evaluate( self ) )
				{
            state = 0;
				nextsearch = 0;
				}
			break;
		}

	return true;
	}

void FindEnemy::End
	(
	Actor &self
	)

	{
	chase.End( self );
	}

/****************************************************************************

  AimAndShoot Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, AimAndShoot, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

AimAndShoot::AimAndShoot()
	{
	maxshots = 1;
	numshots = 0;
	}

void AimAndShoot::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\naim:\n" );
   aim.ShowInfo( self );

   gi.Printf( "\nmode: %d\n", mode );
   gi.Printf( "maxshots: %d\n", maxshots );
   gi.Printf( "numshots: %d\n", numshots );
   gi.Printf( "animdone: %d\n", animdone );
	}

void AimAndShoot::Begin
	(
	Actor &self
	)

	{
   enemy_health = 0;
	animdone = false;

	if ( aimanim.length() )
		{
		self.SetAnim( aimanim.c_str() );
		mode = 0;
		}
	else
		{
		self.SetAnim( "idle" );
		mode = 1;
		}
   }

void AimAndShoot::SetMaxShots
	(
	int num
	)

	{
	maxshots = (num>>1) + G_Random( num );
	}

void AimAndShoot::SetArgs
	(
	Event *ev
	)

	{
   fireanim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		maxshots = ev->GetInteger ( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		aimanim = ev->GetString ( 3 );
      }
	}

void AimAndShoot::AnimDone
	(
	Event *ev
	)

	{
	animdone = true;
	}

qboolean	AimAndShoot::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;

	switch( mode )
		{
		case 0 :
         if ( !self.currentEnemy )
            {
            return false;
            }

			if ( !self.CanShoot( self.currentEnemy, false ) )
            {
            return false;
            }

			// start Aiming
			animdone = false;
         if ( aimanim.length() )
            {
			   self.SetAnim( aimanim.c_str() );
            }

         //
         // save off time, in case we aim for too long
         //
         aim_time = level.time + 1;
			mode = 1;

		case 1 :
			// Aiming
			if ( aimanim.length() )
				{
				if ( !self.currentEnemy )
					{
					return false;
					}

				// see if we aimed for too long
				if ( aim_time < level.time )
					{
					return false;
					}

				aim.SetTarget( self.currentEnemy );

				if ( aim.Evaluate( self ) )
					{
					break;
					}
				}
			else
				{
				if ( self.IsEntityAlive( self.currentEnemy ) )
					{
					dir = self.currentEnemy->centroid - self.origin;
					angles = dir.toAngles();

					self.angles[YAW] = angles[YAW];
					self.setAngles( self.angles );
					}
				}

			// don't go into our firing animation until our weapon is ready, and we are on target
			if ( self.currentEnemy && self.CanShoot( self.currentEnemy, true ) )
				{
				animdone = false;
				self.Chatter( "snd_inmysights", 5 );
				self.SetAnim( fireanim.c_str(), EV_Actor_NotifyBehavior );
            enemy_health = self.currentEnemy->health;
				mode = 2;
				}
			else if ( !self.currentEnemy || self.currentEnemy->deadflag ||
				( self.currentEnemy->health <= 0 ) || !self.CanShoot( self.currentEnemy, false ) )
				{
				// either our enemy is dead, or we can't shoot the enemy from here
				return false;
				}
			break;

		case 2 :
			// Fire
			if ( animdone )
				{
				aim.SetTarget( self.currentEnemy );
				aim.Evaluate( self );

				self.times_done++;

            if ( !self.currentEnemy || ( self.currentEnemy->health < enemy_health ) )
               {
					self.Chatter( "snd_attacktaunt", 4 );
               }
            else
               {
					self.Chatter( "snd_missed", 7 );
               }

				animdone = false;
				numshots++;

				if ( ( numshots >= maxshots ) || !self.currentEnemy || self.currentEnemy->deadflag ||
					( self.currentEnemy->health <= 0 ) || !self.CanShoot( self.currentEnemy, false ) )
					{
					// either we're out of shots, our enemy is dead, or we can't shoot the enemy from here

					return false;
					}
				else if ( !self.CanShoot( self.currentEnemy, false ) )
					{
					// weapon not ready or not aimed at enemy, so just keep trying to get enemy in our sights
               if ( aimanim.length() )
                  {
		   			self.SetAnim( aimanim.c_str() );
                  }
               //
               // save off time, in case we aim for too long
               //
               aim_time = level.time + 1;
					mode = 1;
					}
				else
					{
					// keep firing
					self.SetAnim( fireanim.c_str(), EV_Actor_NotifyBehavior );
               enemy_health = self.currentEnemy->health;
					}
				}
			break;
		}

	return true;
	}

void AimAndShoot::End
	(
	Actor &self
	)

	{
	aim.End( self );
	//self.SetAnim( "idle" );
	}

/****************************************************************************

  AimAndMelee Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, AimAndMelee, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

AimAndMelee::AimAndMelee()
	{
	maxshots = 1;
	anim_name = "melee";
	}

void AimAndMelee::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\naim:\n" );
   aim.ShowInfo( self );

   gi.Printf( "\nmode: %d\n", mode );
   gi.Printf( "maxshots: %d\n", maxshots );
   gi.Printf( "numshots: %d\n", numshots );
   gi.Printf( "animdone: %d\n", animdone );
	}

void AimAndMelee::Begin
	(
	Actor &self
	)

	{
	mode = 0;
   numshots = 0;
	animdone = false;

	self.SetAnim( "idle" );
	}

void AimAndMelee::SetArgs
	(
	Event *ev
	)

	{
	anim_name = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		maxshots = ev->GetInteger( 2 );
      }
	}

void AimAndMelee::AnimDone
	(
	Event *ev
	)

	{
	animdone = true;
	}

qboolean	AimAndMelee::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;

	switch( mode )
		{
		case 0 :
			if ( !self.currentEnemy )
            {
            return false;
            }

			if ( self.IsEntityAlive( self.currentEnemy ) )
				{
				dir = self.currentEnemy->centroid - self.origin;
				self.angles[YAW] = dir.toYaw();
				self.setAngles( self.angles );
				}

         numshots++;
         animdone = false;

			// melee
			self.SetAnim( anim_name.c_str() , EV_Actor_NotifyBehavior );
			self.Chatter( "snd_attacktaunt", 4 );
         mode = 1;

		case 1 :
			// finish up the attack
			if ( animdone )
				{
				self.times_done++;
            if ( numshots >= maxshots )
               {
				   return false;
               }

            mode = 0;
            }
			break;
		}

	return true;
	}

void AimAndMelee::End
	(
	Actor &self
	)

	{
	aim.End( self );
	}

/****************************************************************************

  FallToDeath Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FallToDeath, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FallToDeath::FallToDeath()
   {

	}

void FallToDeath::SetArgs
	(
	Event *ev
	)
	{
   // Get the Parameters
	forwardmove = ev->GetFloat( 1 );
   sidemove    = ev->GetFloat( 2 );
   speed       = ev->GetFloat( 3 );
	startAnim   = ev->GetString( 4 );
	fallAnim    = ev->GetString( 5 );
	deathAnim   = ev->GetString( 6 );
	
	if ( ev->NumArgs() > 6 )
		impulse_time = ( ev->GetFloat( 7 ) ) + level.time;
	else
		impulse_time = 0;

	animdone = false;
	state    = 0;
	did_impulse = false;
	}

void FallToDeath::Begin
	(
	Actor &self
	)

	{
	//Initialize our shit


	self.SetAnim( startAnim.c_str() , EV_Anim_Done );
	self.ChangeAnim();
	}

qboolean	FallToDeath::Evaluate
	(
	Actor &self
	)

	{
   if ( !did_impulse && level.time >= impulse_time )
		{
		Vector( 0, self.angles.y, 0 ).AngleVectors( &yaw_forward, &yaw_left );
		self.velocity = yaw_forward * forwardmove - yaw_left * sidemove;
	   distance = self.velocity.length();
	   self.velocity *= speed / distance;
	   time = distance / speed;
	   self.velocity[ 2 ] = sv_gravity->integer * time * 0.5f;
		did_impulse = true;
		}
	

	animdone = self.GetActorFlag( ACTOR_FLAG_ANIM_DONE );
	self.SetActorFlag( ACTOR_FLAG_ANIM_DONE, false );

   switch( state )
      {
      case 0:
         if ( did_impulse )
				state = 1;
         // this is here so that we at least hit this function at least once
         // this gaves the character the chance to leave the ground, nulling out
         // self.groundentity
         break;
		case 1:
			if ( animdone )
            {
            animdone = false;
         	self.SetAnim( fallAnim.c_str(), EV_Anim_Done );
            state = 2;
            }
			if ( self.groundentity )
				state = 2;
			break;
      case 2:
         //
         // wait for the character to hit the ground
         //
	      if ( self.groundentity )
            {
            //
            // if we have an anim, we go to state 3
            //
            animdone = false;
         	self.SetAnim( deathAnim.c_str(), EV_Actor_Dead );
            state = 3;            
            }
         break;
      case 3:
         //
         // we are on the ground and waiting for our landing animation to finish
         //
         
			if ( animdone )
            {
				return false;
            }			
         break;
      }

	return true;
	}

void FallToDeath::End
	(
	Actor &self
	)

	{
	Event *ev;
	ev = new Event( EV_Killed );

	ev->AddEntity( NULL );
	ev->AddFloat( 250 );
	ev->AddEntity( NULL );
	ev->AddInteger( MOD_FALLING );
	ev->AddInteger( 1 );

	self.PostEvent( ev , 0 );	
	}

/****************************************************************************

  JumpToPathNode Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, JumpToPathNode, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void JumpToPathNode::SetArgs
	(
	Event *ev
	)
	{
	Entity *ent;


  	movegoal = AI_FindNode( ev->GetString( 1 ) );

	if ( movegoal )
		jump.SetGoal( movegoal->targetname );
	else
      {
   	ent = ev->GetEntity( 1 );

      if ( ent )
         jump.SetEntity( ent );
      }

	if ( ev->NumArgs() > 1 )
		jump.SetVerticalSpeed( ev->GetFloat( 2 ) );	


   if ( ev->NumArgs() > 2 )
	   jump.SetSpeed( ev->GetFloat( 3 ) );
	else
		jump.SetSpeed( 500 );
		
	}

void JumpToPathNode::Begin
	(
	Actor &self
	)

	{
	jump.Begin( self );
	}

qboolean	JumpToPathNode::Evaluate
	(
	Actor &self
	)

	{
	return jump.Evaluate( self );
	}

void JumpToPathNode::End
	(
	Actor &self
	)

	{
	jump.End( self );
	}

/****************************************************************************

  LeapToEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, LeapToEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void LeapToEnemy::SetArgs
	(
	Event *ev
	)

	{

	speed = ev->GetFloat( 1 );
	jump.SetSpeed(speed);	
	}

void LeapToEnemy::Begin
	(
	Actor &self
	)

	{
	Entity* ent = self.currentEnemy;	
	jump.SetEntity(ent);
	jump.Begin(self);
	}

qboolean	LeapToEnemy::Evaluate
	(
	Actor &self
	)

	{
	return jump.Evaluate(self);
	}

void LeapToEnemy::End
	(
	Actor &self
	)

	{
	jump.End(self);
	}

/****************************************************************************

  FlyToPoint Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyToPoint, NULL )
	{
		{ NULL, NULL }
	};

FlyToPoint::FlyToPoint()
	{
	turn_speed = 10.0;
	old_turn_speed = turn_speed;
	speed = 480.0;
	random_allowed = true;
	force_goal = false;
	adjustYawAndRoll = true;
	offsetOrigin = false;
	}

void FlyToPoint::SetTurnSpeed( float new_turn_speed )
	{
	turn_speed = new_turn_speed;
	}

void FlyToPoint::SetGoalPoint( const Vector &goal_point )
	{
	if ( goal_point != goal )
		avoidtime = 0;

	goal = goal_point;
	}

void FlyToPoint::SetRandomAllowed( qboolean allowed )
	{
	random_allowed = allowed;
	}

void FlyToPoint::SetSpeed( float speed_value )
	{
	speed = speed_value;
	}

void FlyToPoint::ForceGoal( void )
	{
	force_goal = true;
	}

void FlyToPoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyToPoint::Begin
	(
	Actor &self
	)

	{
   avoidtime = 0;
	old_forward_speed = self.forwardspeed;
	stuck = 0;
	use_temp_goal = false;
	}

qboolean	FlyToPoint::Evaluate
	(
	Actor &self
	)

	{
   trace_t trace;
   Vector dir;
   Vector ang;
	float time;
	float length;
	float old_yaw;
	float old_pitch;
	
	float x_offset = 0;
	float y_offset = 0;
	float z_offset = 0;


   if (offsetOrigin)
		{
   	x_offset = self.centroid.x - self.origin.x;
   	y_offset = self.centroid.y - self.origin.y;
	   z_offset = self.centroid.z - self.origin.z;
		
		self.origin.x+=x_offset;
	   self.origin.y+=y_offset;
	   //self.origin.z+=z_offset;
		}

	if ( self.lastmove != STEPMOVE_OK )
		stuck++;
	else
		stuck = 0;
	
	if ( stuck > 1 || ( avoidtime <= level.time ) )
      {
		time = G_Random( .3 ) + .3;

		use_temp_goal = false;

		if ( !force_goal )
			{
			trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyToPoint" );
						
			if ( trace.fraction < 0.5f || stuck > 2 )
				{
				old_turn_speed = self.turnspeed;
			   self.turnspeed = 60;
				temp_goal = ChooseRandomDirection( self, goal, &time, MASK_WATER, false );
				self.turnspeed = old_turn_speed;
				use_temp_goal = true;
				avoidtime = level.time + time;

				stuck = 0;
				}
			else
				{
				goal = trace.endpos;
				avoidtime = level.time + time;
				}
			}
		else
			{
			avoidtime = level.time + time;
			}
		
		if ( use_temp_goal )
			dir = temp_goal - self.origin;						
		else
			dir = goal - self.origin;			

		length = dir.length();
      dir.normalize();
		
      ang = dir.toAngles();
		
		if ( length > 150 && random_allowed && !use_temp_goal )
			{
			//ang[YAW]   += G_Random( 20 ) - 5.0;
			//ang[PITCH] += G_Random( 20 ) - 5.0;
			}

		target_angle = ang;

		target_angle[YAW]   = AngleNormalize360( target_angle[YAW] );
		target_angle[PITCH] = AngleNormalize360( target_angle[PITCH] );
      }

	if ( (self.angles[YAW] != target_angle[YAW]) || (self.angles[PITCH] != target_angle[PITCH]) )
      {
		self.forwardspeed = speed * 0.8f;
      }
	else
      {
		self.forwardspeed = speed;
      }

	old_yaw   = self.angles[YAW];
	old_pitch = self.angles[PITCH];
	
	ang[YAW]   = LerpAngle( self.angles[YAW],   target_angle[YAW],   turn_speed );
	ang[PITCH] = LerpAngle( self.angles[PITCH], target_angle[PITCH], turn_speed );
	ang[ROLL]  = 0;
	
	if( adjustYawAndRoll )
		{
	   
		if ( (AngleDelta( ang[YAW], old_yaw ) > 0) && (ang[ROLL] > 315 || ang[ROLL] <= 45) )
			{
			ang[ROLL] += 5;
			}
		else if ( (AngleDelta( ang[YAW], old_yaw ) < 0) && (ang[ROLL] < 45 || ang[ROLL] >= 315) )
			{
			ang[ROLL] -= 5;
			}
		else if ( (AngleDelta( ang[YAW], old_yaw ) == 0 ) )
			{
			if ( ang[ROLL] != 0 )
				{
				
				if ( ang[ROLL] < 5 || ang[ROLL] > 355 )
					{
					ang[ROLL] = 0;
					}
				else
					{
					if ( ang[ROLL] < 180 )
						ang[ROLL] += 5;
					else
						ang[ROLL] -= 5;
					}

				}
			}
		}

	ang[YAW]   = AngleNormalize360( ang[YAW] );
	ang[PITCH] = AngleNormalize360( ang[PITCH] );
	ang[ROLL]  = AngleNormalize360( ang[ROLL] );

	// Don't get stuck if still turning

	if ( ( AngleDelta( ang[YAW], old_yaw ) > .5 ) || ( AngleDelta( ang[YAW], old_yaw ) < -.5 ) ||
		  ( AngleDelta( ang[PITCH], old_pitch ) > .5 ) || ( AngleDelta( ang[PITCH], old_pitch ) < -.5 ) )
		{
		stuck = 0;
		}

	self.setAngles( ang );

	if (offsetOrigin)
		{
   	self.origin.x-=x_offset;
	   self.origin.y-=y_offset;
	   //self.origin.z-=z_offset;
		}

	return true;
	}

float FlyToPoint::LerpAngle( float old_angle, float new_angle, float lerp_amount )
	{
	float diff;
	float abs_diff;
	float lerp_angle;

	new_angle = AngleNormalize360( new_angle );
	old_angle = AngleNormalize360( old_angle );

	diff = new_angle - old_angle;

	if ( diff > 180 )
      {
		diff -= 360;
      }

	if ( diff < -180 )
      {
		diff += 360;
      }

	lerp_angle = old_angle;
	
	abs_diff = diff;

	if ( abs_diff < 0 )
      {
		abs_diff = -abs_diff;
      }

	if ( abs_diff < lerp_amount )
      {
		lerp_amount = abs_diff;
      }

	if ( diff < 0 )
      {
		lerp_angle -= lerp_amount;
      }
	else if ( diff > 0 )
      {
		lerp_angle += lerp_amount;
      }
	
	lerp_angle = AngleNormalize360( lerp_angle );

	return lerp_angle;
	}

void FlyToPoint::End
	(
	Actor &self
	)

	{
	self.forwardspeed = old_forward_speed;
	self.FlightDir = vec_zero;
	}

/****************************************************************************

  FlyCloseToEnemy Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCloseToEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCloseToEnemy::FlyCloseToEnemy()
	{
	speed = 0;
	turn_speed = 10.0;
	anim = "fly";
	adjustPitch = true;
	}

void FlyCloseToEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		turn_speed = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		speed = ev->GetFloat( 3 );

	if (ev->NumArgs() > 3 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 4 ) );	

	if (ev->NumArgs() > 4 )
		adjustPitch = ev->GetBoolean( 5 );
	}


void FlyCloseToEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCloseToEnemy::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );

	if ( speed )
		fly.SetSpeed( speed );

	next_goal_time = 0;
	}

qboolean	FlyCloseToEnemy::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;


   if ( !self.IsEntityAlive( self.currentEnemy ) )
      return false;

	if ( next_goal_time <= level.time )
		{
		goal = self.currentEnemy->centroid;

		if (!adjustPitch)
			{
			goal.z = self.origin.z;
			}

		//goal[0] += G_Random( 30 ) - 15.0;
		//goal[1] += G_Random( 30 ) - 15.0;
		//goal[2] += G_Random( 60 ) - 30.0;

		fly.SetGoalPoint( goal );

		next_goal_time = level.time + .5;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyCloseToEnemy::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyCloseToPlayer Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCloseToPlayer, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCloseToPlayer::FlyCloseToPlayer()
	{
	speed = 0;
	turn_speed = 10.0;
	anim = "fly";
	}

void FlyCloseToPlayer::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		turn_speed = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		speed = ev->GetFloat( 3 );
	}

void FlyCloseToPlayer::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCloseToPlayer::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
		
	if ( speed )
		fly.SetSpeed( speed );

	next_goal_time = 0;
	}

qboolean	FlyCloseToPlayer::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	Entity *player;


	player = g_entities[ 0 ].entity;


   if ( !self.IsEntityAlive( player ) )
      return false;

	if ( next_goal_time <= level.time )
		{
		goal = player->centroid;

		//goal[0] += G_Random( 30 ) - 15.0;
		//goal[1] += G_Random( 30 ) - 15.0;
		//goal[2] += G_Random( 60 ) - 30.0;

		fly.SetGoalPoint( goal );

		next_goal_time = level.time + .5;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyCloseToPlayer::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}


/****************************************************************************

  FlyCloseToParent Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCloseToParent, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCloseToParent::FlyCloseToParent()
	{
	speed = 0;
	turn_speed = 10.0;
	anim = "fly";
	}

void FlyCloseToParent::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		turn_speed = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		speed = ev->GetFloat( 3 );
	}

void FlyCloseToParent::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCloseToParent::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
		
	if ( speed )
		fly.SetSpeed( speed );

	next_goal_time = 0;
	}

qboolean	FlyCloseToParent::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	Entity *player;


	player = g_entities[ 0 ].entity;

   if ( !self.spawnparent )
		return false;
   
	if ( next_goal_time <= level.time )
		{
		Actor* act;

		act = (Actor*)self.spawnparent;
		goal = act->centroid;
		
		fly.SetGoalPoint( goal );

		next_goal_time = level.time + .5;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyCloseToParent::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}


/****************************************************************************

  FlyDescend Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FlyDescend, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyDescend::FlyDescend()
	{
	anim = "fly";
	height = 500;
	speed = 0;
	}

void FlyDescend::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		height = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		speed = ev->GetFloat( 3 );
	}

void FlyDescend::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyDescend::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );

	if ( self.currentEnemy )
		height = self.currentEnemy->origin.z;
	else
		height = self.origin.z;

	goal = self.origin;
	goal.z = height;

	fly.SetTurnSpeed( 1 );

	fly.SetGoalPoint( goal );

	next_height_check = level.time + 2.0;
	
	last_check_height = self.origin.z;
	

	if ( speed )
		fly.SetSpeed( speed );
	}

qboolean	FlyDescend::Evaluate
	(
	Actor &self
	)

	{

	if ( self.origin.z <= height )
      {
		return false;
      }

	if ( next_height_check < level.time )
		{
		if ( self.origin.z < last_check_height + 25 )
			return false;

		next_height_check = level.time + 2.0;
		last_check_height = self.origin.z;
		}

	if ( self.lastmove == STEPMOVE_OK )
		fly.SetGoalPoint( goal );

	fly.Evaluate( self );

	return true;
	}

void FlyDescend::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}



/****************************************************************************

  FlyWander Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyWander, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyWander::FlyWander()
	{
	turn_speed = 10.0;
	anim = "fly";
	change_course_time = 5.0;
	speed = 200;
	try_to_go_up = false;
	}

void FlyWander::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		speed = ev->GetFloat( 2 );
      
	if ( ev->NumArgs() > 2 )
      turn_speed = ev->GetFloat( 3 );
      
	if ( ev->NumArgs() > 3 )
      change_course_time = ev->GetFloat( 4 );
      
	if ( ev->NumArgs() > 4 )
      try_to_go_up = ev->GetFloat( 5 );
      
	if (ev->NumArgs() > 5 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 6 ) );	

	if (ev->NumArgs() > 6 )
		fly.setOffsetOrigin( ev->GetBoolean ( 7 ) );

	}

void FlyWander::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyWander::Begin
	(
	Actor &self
	)

	{
	next_change_course_time = 0;

	original_z = self.origin.z;

	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
	fly.SetSpeed( speed );
	}

qboolean	FlyWander::Evaluate
	(
	Actor &self
	)

	{
	trace_t trace;
	Vector dir;
	float length;
	int goal_try;
	Vector temp_goal;
	float max_dist = 0;


	dir = goal - self.origin;
	length = dir.length();

	if ( next_change_course_time <= level.time || length < 100 ) //self.lastmove != STEPMOVE_OK )
		{
		for( goal_try = 0 ; goal_try < 5 ; goal_try++ )
			{
			temp_goal = self.origin;

			temp_goal[0] += G_Random( 10000 ) - 5000.0;
			temp_goal[1] += G_Random( 10000 ) - 5000.0;

			if ( try_to_go_up )
				temp_goal[2] += G_Random( 1000 ) - 250.0;
			else
				temp_goal[2] += G_Random( 100 ) - 50.0;

			trace = G_Trace( self.origin, self.mins, self.maxs, temp_goal, &self, self.edict->clipmask, false, "FlyWander" );

			temp_goal = trace.endpos;

			dir = temp_goal - self.origin;
			length = dir.length();

			if ( length > max_dist )
				{
				max_dist = length;
				goal = temp_goal;

				if ( length > 1000 )
					break;
				}
			}

		fly.SetGoalPoint( goal );

		next_change_course_time = level.time + change_course_time;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyWander::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyToNode Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyToNode, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyToNode::FlyToNode()
	{
	turn_speed = 10.0;
	anim = "fly";
	speed = 200;	
	}

void FlyToNode::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		turn_speed = ev->GetFloat( 3 );
      }

	if ( ev->NumArgs() > 3 )
      {
		NodeType = ev->GetString( 4 );
      }

	if ( ev->NumArgs() > 4 )
		{
		NumberOfNodes = ev->GetInteger( 5 );
		}
	}

void FlyToNode::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyToNode::Begin
	(
	Actor &self
	)

	{
	
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
	fly.SetSpeed( speed );
	}

qboolean	FlyToNode::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	str pathnode_name;
	PathNode *goal;
	Vector teleport_position;
	Vector attack_position;

	int bestNode = 0;
	float bestDistance = -1;
	
	for(int i = 0; i <= NumberOfNodes; i++)
		{
		pathnode_name = NodeType + i;

		goal = AI_FindNode( pathnode_name );

		if( goal )
			{
			float distanceTest = self.origin.length()  - goal->origin.length();

			if(bestDistance < 0 )
				{
				bestDistance = distanceTest;
				bestNode = i;
				}
			else if (distanceTest < bestDistance )
				{
				bestDistance = distanceTest;
				bestNode = i;
				}
			}
		}
	
	pathnode_name = NodeType + bestNode;
	goal = AI_FindNode( pathnode_name );
	
	if ( !goal )
		{
		gi.WDPrintf( "Can't find position %s\n", pathnode_name.c_str() );
		return false;
		}

		fly.SetGoalPoint( goal->origin );
		fly.Evaluate( self );

	return true;
	}

void FlyToNode::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyToRandomNode Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyToRandomNode, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyToRandomNode::FlyToRandomNode()
	{
	turn_speed = 10.0;
	anim = "fly";
	speed = 200;
	CurrentNode = -1;
	NeedNextNode = true;
	}

void FlyToRandomNode::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		turn_speed = ev->GetFloat( 3 );
      }

	if ( ev->NumArgs() > 3 )
      {
		NodeType = ev->GetString( 4 );
      }

	if ( ev->NumArgs() > 4 )
		{
		NumberOfNodes = ev->GetInteger( 5 );		
		}	
	}

void FlyToRandomNode::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyToRandomNode::Begin
	(
	Actor &self
	)

	{
	
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
	fly.SetSpeed( speed );
	}

qboolean	FlyToRandomNode::Evaluate
	(
	Actor &self
	)

	{
	str pathnode_name;
	Vector dir;
	
	if(NeedNextNode)
		{
		int x = G_Random(NumberOfNodes);
	   if (x == CurrentNode)
		x++;
	
	   CurrentNode = x;

		pathnode_name = NodeType + CurrentNode;
		
	   goal = AI_FindNode( pathnode_name );

		NeedNextNode = false;
		}
   
	if ( !goal )
		{
		gi.WDPrintf( "Can't find position %s\n", pathnode_name.c_str() );
		return false;
		}

	fly.SetGoalPoint( goal->origin );
	fly.Evaluate( self );
   
	dir = self.origin - goal->origin;
	
	if (dir.length() < 100 )
		{
		NeedNextNode = true;
		}

	return true;
	}

void FlyToRandomNode::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyToNodeNearestPlayer Class Definition

****************************************************************************/
CLASS_DECLARATION( Behavior, FlyToNodeNearestPlayer, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyToNodeNearestPlayer::FlyToNodeNearestPlayer()
	{
	turn_speed = 10.0;
	anim = "fly";
	speed = 200;
	CurrentNode = -1;
	NeedNextNode = true;
	}

void FlyToNodeNearestPlayer::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		turn_speed = ev->GetFloat( 3 );
      }

	if ( ev->NumArgs() > 3 )
      {
		NodeType = ev->GetString( 4 );
      }

	if ( ev->NumArgs() > 4 )
		{
		NumberOfNodes = ev->GetInteger( 5 );		
		}	
	}

void FlyToNodeNearestPlayer::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyToNodeNearestPlayer::Begin
	(
	Actor &self
	)

	{
	
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
	fly.SetSpeed( speed );
	}

qboolean	FlyToNodeNearestPlayer::Evaluate
	(
	Actor &self
	)

	{
	str pathnode_name;
	Vector dir;
	
	
	if(NeedNextNode)
		{
		int ClosestNode = 0;
		float CheckLen = -1;
		PathNode* Pnode = 0;

		for ( int i = 1; i <= NumberOfNodes; i++ )
			{
			pathnode_name = NodeType + i;
			Pnode = AI_FindNode(pathnode_name);
	
			if ( !Pnode )
				{
				gi.WDPrintf( "Can't find Pathnode %s\n", pathnode_name.c_str() );
				return false;
				}
			
			if(self.currentEnemy)
				{
				dir = Pnode->origin - self.currentEnemy->centroid;
				}
			else
				{
				Entity* player = g_entities[0].entity;
				dir = Pnode->origin - player->centroid;
				}

			if(CheckLen < 0 )
				{
				CheckLen = dir.length();
				}
			else
				{
				if(dir.length() < CheckLen)
					{
					CheckLen = dir.length();
					ClosestNode = i;
					}
				}
			}
		
		pathnode_name = NodeType + ClosestNode;
		
	   goal = AI_FindNode( pathnode_name );

		NeedNextNode = false;
		}

	fly.SetGoalPoint( goal->origin );
	fly.Evaluate( self );
   
	dir = self.origin - goal->origin;
	
	if (dir.length() < 100 )
		{
		NeedNextNode = true;
		}

	return true;
	}

void FlyToNodeNearestPlayer::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyNodePath Class Definition

****************************************************************************/
CLASS_DECLARATION( Behavior, FlyNodePath, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyNodePath::FlyNodePath()
	{
	turn_speed = 10.0;
	anim = "fly";
	speed = 200;
	CurrentNode = -1;
	NeedNextNode = true;
	}

void FlyNodePath::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		turn_speed = ev->GetFloat( 3 );
      }

	if ( ev->NumArgs() > 3 )
      {
		NodeType = ev->GetString( 4 );
      }

	if ( ev->NumArgs() > 4 )
		{
		NumberOfNodes = ev->GetInteger( 5 );		
		}	
	}

void FlyNodePath::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyNodePath::Begin
	(
	Actor &self
	)

	{
	
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );
	fly.SetTurnSpeed( turn_speed );
	fly.SetSpeed( speed );
	}

qboolean	FlyNodePath::Evaluate
	(
	Actor &self
	)

	{
	str pathnode_name;
	Vector dir;
	
	if(NeedNextNode)
		{
	   CurrentNode++;

		if(CurrentNode > NumberOfNodes)
			CurrentNode = 0;

		pathnode_name = NodeType + CurrentNode;
		
	   goal = AI_FindNode( pathnode_name );

		NeedNextNode = false;
		}
   
	if ( !goal )
		{
		gi.WDPrintf( "Can't find position %s\n", pathnode_name.c_str() );
		return false;
		}

	fly.SetGoalPoint( goal->origin );
	fly.Evaluate( self );
   
	dir = self.origin - goal->origin;
	
	if (dir.length() < 100 )
		{
		NeedNextNode = true;
		}
	
	if ( (CurrentNode == NumberOfNodes) && NeedNextNode )
		return false;
	
	return true;
	}

void FlyNodePath::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyCircle Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCircle, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCircle::FlyCircle()
	{
	anim = "fly";	
	}

void FlyCircle::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	fly_clockwise = ev->GetBoolean( 2 );

	if (ev->NumArgs() > 2 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 3 ) );
	
	if (ev->NumArgs() > 3 )
		circle_player = ev->GetBoolean ( 4 );
	else
		circle_player = false;	
	
	if (ev->NumArgs() > 4 )
		fly.SetSpeed( ev->GetFloat( 5 ) );
	}

void FlyCircle::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCircle::Begin
	(
	Actor &self
	)

	{
	original_z = self.origin.z;

	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( 5.0 );
	}

qboolean	FlyCircle::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	trace_t trace;
	Vector dir;
	Vector angle;
	Vector left;
	qboolean too_far = false;
	Vector new_dir;
	Vector fly_dir;
	
	//Vector or;

	//or = self.currentEnemy->centroid - self.origin;
	//or = or.toAngles();

	//self.angles = or;
	//self.setAngles( or );
	
	if ( !self.IsEntityAlive( self.currentEnemy ) && !circle_player )
      {
      return false;
      }

	if ( self.lastmove == STEPMOVE_OK )
		{
		fly.SetTurnSpeed( 5.0 );

		if (circle_player)
			{
			
			Player* player = 0;
			// Make sure the player is alive and well
			for(int i = 0; i < game.maxclients; i++)
			{
			player = GetPlayer(i);		
		
			// don't target while player is not in the game or he's in notarget
			if( !player || ( player->flags & FL_NOTARGET ) )
				{
				return false;
				}
			}
						
			dir = player->centroid - self.origin;
			dir.z = 0;

			if ( dir.length() > (self.origin.z - player->centroid.z) / .5 )
				{
				too_far = true;
				}

			}
		else
			{
			dir = self.currentEnemy->centroid - self.origin;
			dir.z = 0;

			if ( dir.length() > (self.origin.z - self.currentEnemy->centroid.z) / 2 )
				{
				too_far = true;
				}

			}

		angle = dir.toAngles();

		angle.AngleVectors( NULL, &left, NULL );

		if ( fly_clockwise )
			fly_dir = left;
		else
			fly_dir = left * -1;

		dir.normalize();

		if ( too_far )
			{
			new_dir = fly_dir * 0.5 + dir * 0.5;
			new_dir.normalize();
			}
		else
			{
			new_dir = fly_dir;
			}

		//goal = self.origin + new_dir * 200;
		goal = self.origin + new_dir * 700;

		trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyCircle" );

		if ( trace.fraction < 1 )
			{
			if ( too_far )
				trace.fraction /= 2;

			new_dir = fly_dir * trace.fraction + dir * (1 - trace.fraction);
			new_dir.normalize();

			//goal = self.origin + new_dir * 200;
			goal = self.origin + new_dir * 700;
			}
		else
			{
			goal = trace.endpos;
			}

		fly.SetGoalPoint( goal );
		}
	else
		{
		fly.SetTurnSpeed( 20.0 );
		}

	fly.Evaluate( self );

	return true;
	}

void FlyCircle::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyStrafe Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyStrafe, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyStrafe::FlyStrafe()
	{
	anim = "fly";	
	}

void FlyStrafe::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	speed = ev->GetFloat( 2 );
	right = ev->GetBoolean( 3 );
	roll  = ev->GetFloat( 4 );
	
	}

void FlyStrafe::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyStrafe::Begin
	(
	Actor &self
	)

	{
	self.SetAnim( anim );
	self.forwardspeed = speed;

	if ( right )
		self.FlightDirection = FLY_RIGHT;
	else
		self.FlightDirection = FLY_LEFT;
	}

qboolean	FlyStrafe::Evaluate
	(
	Actor &self
	)

	{
 	Vector dir;
	Vector delta;

	dir = self.currentEnemy->centroid - self.origin;
	dir = dir.toAngles();

	if ( right )
		dir[ROLL] -= roll;
	else
		dir[ROLL] += roll;

	self.setAngles( dir );
	
   


	return true;
	}	
	

void FlyStrafe::End
	(
	Actor &self
	)

	{
	self.FlightDirection = FLY_FORWARD;
	}

/****************************************************************************

  FlyCircleRandomPoint Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FlyCircleRandomPoint, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCircleRandomPoint::FlyCircleRandomPoint()
	{
	anim = "fly";
	}

void FlyCircleRandomPoint::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	fly_clockwise = ev->GetBoolean( 2 );

	if ( ev->NumArgs() > 2 )
      change_course_time = ev->GetFloat( 3 );
      
	if ( ev->NumArgs() > 3 )
      try_to_go_up = ev->GetFloat( 4 );
      
	if (ev->NumArgs() > 4 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 5 ) );	

	if (ev->NumArgs() > 5 )
		fly.SetSpeed( ev->GetFloat( 6 ) );

	}

void FlyCircleRandomPoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCircleRandomPoint::Begin
	(
	Actor &self
	)

	{
	next_change_course_time = 0;

	original_z = self.origin.z;

	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( 5.0 );
	fly.ForceGoal();
	}

qboolean	FlyCircleRandomPoint::Evaluate
	(
	Actor &self
	)

	{
   trace_t trace;
	Vector dir;
	Vector angle;
	Vector left;
	qboolean too_far = false;
	Vector new_dir;
	Vector fly_dir;
   float length;
	int goal_try;
	Vector temp_goal;
	float max_dist = 0;

	if ( !self.IsEntityAlive( self.currentEnemy ) )
      {
      return false;
      }
	
	if ( self.lastmove == STEPMOVE_OK )
		{
		fly.SetTurnSpeed( 5.0 );
		
		if ( next_change_course_time <= level.time ) //self.lastmove != STEPMOVE_OK )
			{
			
			dir = goal - self.origin;
			dir.z = 0;
			length = dir.length();
			
			fly_clockwise = !fly_clockwise;

			for( goal_try = 0 ; goal_try < 5 ; goal_try++ )
				{
							
				temp_goal = self.origin;
				
				//temp_goal[0] += G_Random( 10000 ) - 2500.0;
				//temp_goal[1] += G_Random( 10000 ) - 2500.0;
								
				temp_goal[0] += G_Random( 10000 ) + 10000;
				temp_goal[1] += G_Random( 10000 ) + 10000;
				if ( try_to_go_up )
					temp_goal[2] += G_Random( 1000 ) - 250.0;
				else
					temp_goal[2] += G_Random( 100 ) - 50.0;

				trace = G_Trace( self.origin, self.mins, self.maxs, temp_goal, &self, self.edict->clipmask, false, "FlyCircleRandomPoint" );

				temp_goal = trace.endpos;

				dir = temp_goal - self.origin;
				length = dir.length();

				if ( length > max_dist )
					{
					max_dist = length;
					goal = temp_goal;

					if ( length > 1000 )
					   break;
					}

				}

			next_change_course_time = (level.time + change_course_time);
			}
		
		if ( dir.length() > (self.origin.z - goal.z ) / 2 )
			{
			too_far = true;
			}

		angle = dir.toAngles();

		angle.AngleVectors( NULL, &left, NULL );

		if ( fly_clockwise )
			fly_dir = left;
		else
			fly_dir = left * -1;

		dir.normalize();

		if ( too_far )
			{
		   new_dir = fly_dir * 0.5 + dir * 0.5;
			new_dir.normalize();
			}
		else
			{
			new_dir = fly_dir;
			}

		goal = self.origin + new_dir * 30;
		//goal = self.origin + new_dir * 100;

		
		trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyCircleRandomPoint" );

		if ( trace.fraction < 1 )
			{
			if ( too_far )
				trace.fraction /= 2;

			new_dir = fly_dir * trace.fraction + dir * (1 - trace.fraction);
			new_dir.normalize();

			//goal = self.origin + new_dir * 200;
			goal = self.origin + new_dir * 100;						
			}
		else
			{
			goal = trace.endpos;
			}

		fly.SetGoalPoint( goal );
		}
	else
		{
		fly.SetTurnSpeed( 30.0 );
		}
	
	
	fly.Evaluate( self );

	return true;

	}

void FlyCircleRandomPoint::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlyDive Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyDive, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyDive::FlyDive()
	{
	anim = "fly";
	speed = 2000;
	damage = 0;
	}

void FlyDive::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		damage = ev->GetFloat( 3 );
      }
	}

void FlyDive::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyDive::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );

	if ( !self.IsEntityAlive( self.currentEnemy ) )
      {
		return;
      }

	goal = self.currentEnemy->centroid - self.origin;
	goal.normalize();
	goal *= 10000;
	goal += self.origin;	
	
	self.divedir = self.origin;

   fly.SetGoalPoint( goal );

	fly.SetTurnSpeed( 100 );
	fly.SetSpeed( speed );
	fly.SetRandomAllowed( false );
	fly.ForceGoal();
	}

qboolean	FlyDive::Evaluate
	(
	Actor &self
	)

	{
	trace_t trace;
	Vector dir;
	Entity *hit_entity;
	qboolean stuck;


	if ( !self.IsEntityAlive( self.currentEnemy ) )
      return false;

	if ( self.origin.z < self.currentEnemy->origin.z + 50 )
		return false;

	if ( self.lastmove == STEPMOVE_STUCK || self.lastmove == STEPMOVE_BLOCKED_BY_WATER )
		{
		stuck = true;

		dir = self.movedir * 100;

		trace = G_Trace( self.origin, self.mins, self.maxs, self.origin + dir, &self, self.edict->clipmask, false, "FlyDive" );

		if ( trace.entityNum != ENTITYNUM_NONE )
			{
			hit_entity = G_GetEntity( trace.entityNum );

			// Damage entity hit
			//if ( hit_entity->isSubclassOf( Sentient ) )
			if ( hit_entity->takedamage )
				{
				//hit_entity->Damage( &self, &self, damage, Vector (0, 0, 0), Vector (0, 0, 0), Vector (0, 0, 0), 0, 0, MOD_CRUSH );
				dir.normalize();
				hit_entity->Damage( &self, &self, damage, self.centroid, dir, vec_zero, 0, 0, MOD_CRUSH );
				self.AddStateFlag( STATE_FLAG_MELEE_HIT );
				stuck = false;
				}
			}

		// Make sure we really are still stuck

		if ( trace.fraction > 0.05 )
			stuck = false;

		self.angles[PITCH] = 0;
		self.setAngles( self.angles );

		if ( stuck )
			self.AddStateFlag( STATE_FLAG_STUCK );

		return false;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyDive::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}


/****************************************************************************

  FlyCharge Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCharge, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCharge::FlyCharge()
	{
	anim = "fly";
	speed = 2000;
	damage = 0;
	}

void FlyCharge::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
      {
		speed = ev->GetFloat( 2 );
      }

	if ( ev->NumArgs() > 2 )
      {
		damage = ev->GetFloat( 3 );
      }
	}

void FlyCharge::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCharge::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
		self.SetAnim( anim );

	fly.Begin( self );

	if ( !self.IsEntityAlive( self.currentEnemy ) )
      {
		return;
      }

	goal = self.currentEnemy->centroid - self.origin;
	goal.normalize();
	goal *= 10000;
	goal += self.origin;
	goal.z = self.origin.z;
	
	self.divedir = self.origin;

   fly.SetGoalPoint( goal );

	fly.SetTurnSpeed( 100 );
	fly.SetSpeed( speed );
	fly.SetRandomAllowed( false );
	fly.ForceGoal();
	}

qboolean	FlyCharge::Evaluate
	(
	Actor &self
	)

	{
	trace_t trace;
	Vector dir;
	Entity *hit_entity;
	qboolean stuck;


	if ( !self.IsEntityAlive( self.currentEnemy ) )
      return false;

	if ( self.lastmove == STEPMOVE_STUCK || self.lastmove == STEPMOVE_BLOCKED_BY_WATER )
		{
		stuck = true;

		dir = self.movedir * 100;

		trace = G_Trace( self.origin, self.mins, self.maxs, self.origin + dir, &self, self.edict->clipmask, false, "FlyDive" );

		if ( trace.entityNum != ENTITYNUM_NONE )
			{
			hit_entity = G_GetEntity( trace.entityNum );

			// Damage entity hit
			//if ( hit_entity->isSubclassOf( Sentient ) )
			if ( hit_entity->takedamage )
				{
				//hit_entity->Damage( &self, &self, damage, Vector (0, 0, 0), Vector (0, 0, 0), Vector (0, 0, 0), 0, 0, MOD_CRUSH );
				dir.normalize();
				hit_entity->Damage( &self, &self, damage, self.centroid, dir, vec_zero, 0, 0, MOD_CRUSH );
				self.AddStateFlag( STATE_FLAG_MELEE_HIT );
				stuck = false;
				}
			}

		// Make sure we really are still stuck

		if ( trace.fraction > 0.05 )
			stuck = false;

		self.angles[PITCH] = 0;
		self.setAngles( self.angles );

		if ( stuck )
			self.AddStateFlag( STATE_FLAG_STUCK );

		return false;
		}

	fly.Evaluate( self );

	return true;
	}

void FlyCharge::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}


/****************************************************************************

  FlyClimb Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyClimb, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyClimb::FlyClimb()
	{
	anim = "fly";
	height = 500;
	speed = 0;
	collision_buffer = 0;
	}

void FlyClimb::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		height = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		speed = ev->GetFloat( 3 );

	if ( ev->NumArgs() > 3 )
		collision_buffer = ev->GetFloat( 1 );
	
	}

void FlyClimb::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyClimb::Begin
	(
	Actor &self
	)

	{
	
	Vector forward;
	trace_t trace;

	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );

	if ( self.currentEnemy )
		height = self.currentEnemy->origin.z + height;	   
	else
		height = self.origin.z + height;

	self.angles.AngleVectors( &forward );
	
	//Okay, here's what we are attempting.  We are first going to get our initial point, 
	//this will be our forward vector * height, then add the the height to the the Z.
	//Next we will trace out, to see how far along that vector we got.  We will use our 
	//trace.endpos as a goal position

	//Now, we don't want to use this goal position as a final vector, because if we ran into
	//something, then we will smack it when we get there... this would be bad, so, we run a 
	//a vector from our origin to our goal position and get the length, we then shave some off of
	//this length and multiply it by another vector and add it to the origin, this will get us
	//our final position

	goal = forward * height;
	goal.z = height;
	goal += self.origin;

	trace = G_Trace( self.centroid, self.mins, self.maxs, goal, NULL, MASK_SOLID, false, "flyclimb" );
	goal = trace.endpos;

	Vector dir;
	dir = self.origin - goal;

	float length;	

	length = dir.length();
	
	if ( collision_buffer )
		length -= collision_buffer;
	else
		length -= (length / 10);

	if (length > 0 )
		{
      goal = forward * length;
		goal.z = length;
		goal += self.origin;
		}
		

	//if ( !self.divedir.x && !self.divedir.y && !self.divedir.z )
	//	{
   //   goal = forward * height;
	//   goal.z = height;
	//   goal += self.origin;
	//	trace = G_Trace( self.centroid, self.mins, self.maxs, goal, NULL, MASK_SOLID, false, "flyclimb" );
		
		


	//	}
   //else
	//	{
   //   goal = self.divedir;
	//	goal.z = height;
	//	}
		
	   


	fly.SetTurnSpeed( 10 );

	fly.SetGoalPoint( goal );
	
	next_height_check = level.time + 2.0;
	last_check_height = self.origin.z;

	if ( speed )
		fly.SetSpeed( speed );
	}

qboolean	FlyClimb::Evaluate
	(
	Actor &self
	)

	{

	if ( self.origin.z >= height )
      {
		return false;
      }

	if ( next_height_check < level.time )
		{
		if ( self.origin.z < last_check_height + 25 )
			return false;

		next_height_check = level.time + 2.0;
		last_check_height = self.origin.z;
		}

	if ( self.lastmove == STEPMOVE_OK )
		fly.SetGoalPoint( goal );

	fly.Evaluate( self );

	return true;
	}

void FlyClimb::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  FlySplinePath Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, FlySplinePath, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlySplinePath::FlySplinePath()
	{
	ent = 0;
	clamp = true;
	ignoreAngles = false;
	splineAngles = true;	
	havePath = false;
	}

void FlySplinePath::SetArgs
	(
	Event *ev
	)

	{
   ent          = ev->GetEntity( 1 );
   ignoreAngles = ev->GetBoolean( 2 );
	splineAngles = ev->GetBoolean( 3 );
	clamp        = ev->GetBoolean( 4 );	
	}

void FlySplinePath::CreatePath
	(
	SplinePath *path,
	splinetype_t type
	)

	{
	
	SplinePath	*node;
   
	splinePath.Clear();
	splinePath.SetType( type );

	node = path;
	while( node != NULL )
		{
      splinePath.AppendControlPoint( node->origin, node->angles, node->speed );
		node = node->GetNext();

		if ( node == path )
			{
			break;
			}
		}
	
	}
void FlySplinePath::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlySplinePath::Begin
	(
	Actor &self
	)

	{
	
	if ( ent )
		havePath = true;
	else
		return;

	if ( ent->isSubclassOf( SplinePath ) )
		{

		SplinePath* path;
      
		path = (SplinePath*)(Entity*)ent;
		
		if ( clamp )			
			CreatePath( path, SPLINE_CLAMP );
		else
			CreatePath( path, SPLINE_LOOP );
		
		currentNode = path;
      
		if (currentNode->thread != "" )
			{
			if ( !ExecuteThread( currentNode->thread ) )
				{
				gi.Error( ERR_DROP, "FlySplinePath could not run thread '%s' from info_splinepath '%s'\n", 
					currentNode->thread.c_str(), currentNode->targetname.c_str() );
				}
			}
		
		if ( currentNode->triggertarget != "" )
			{
			Entity	*ent;
			Event		*event;

			ent = NULL;
			do
				{
				ent = G_FindTarget( ent, currentNode->triggertarget.c_str() );
				if ( !ent )
					{
					break;
					}
		   	event = new Event( EV_Activate );
				
				Actor* actorPtr = &self;
				Entity* entPtr = (Entity*)actorPtr;
				event->AddEntity( entPtr );
				ent->PostEvent( event, 0 );
				}
			while ( 1 );
			}
		
		}
   
	startTime = level.time + self.currentSplineTime;
	
	
	}

qboolean	FlySplinePath::Evaluate
	(
	Actor &self
	)

	{
   
	Vector goal;
	Vector dir;
	Vector angles;
	
	if(!havePath)
		return false;

	
	goal = splinePath.Eval( (level.time - startTime) );		

	if ( goal == oldGoal )
		{
		self.currentSplineTime = 0;
		return false;
		}
		

	oldGoal = goal;
	
	dir = goal - self.origin;
   angles = dir.toAngles();

	self.setOrigin(goal);
	self.setAngles(angles);

	
	return true;

	
	}

void FlySplinePath::End
	(
	Actor &self
	)

	{
   self.currentSplineTime = level.time - startTime;
   }

/****************************************************************************

  Land Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, Land, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

Land::Land()
	{
	anim = "fly";
	}

void Land::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void Land::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void Land::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	self.velocity = "0 0 -40";
	}

qboolean	Land::Evaluate
	(
	Actor &self
	)

	{
	self.angles[PITCH] = 0;
	self.angles[ROLL]  = 0;

	self.setAngles( self.angles );

	self.velocity.z -= 20;

	if ( self.velocity.z < -200 )
      {
		self.velocity.z = -200;
      }

	return !self.groundentity;
	}

void Land::End
	(
	Actor &self
	)

	{
	}


/****************************************************************************

  Vertical Takeoff Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, VerticalTakeOff, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

VerticalTakeOff::VerticalTakeOff()
	{
	anim = "fly";
	}

void VerticalTakeOff::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	speed = ev->GetFloat( 2 );
	height = ev->GetFloat( 3 );
	}

void VerticalTakeOff::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void VerticalTakeOff::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }
	
	self.velocity.x = 0;
	self.velocity.y = 0;
	self.velocity.z = speed;
	
	}

qboolean	VerticalTakeOff::Evaluate
	(
	Actor &self
	)

	{
	self.angles[PITCH] = 0;
	self.angles[ROLL]  = 0;

	self.setAngles( self.angles );

	self.velocity.z += 20;

	if ( self.velocity.z > 200 )
      {
		self.velocity.z = 200;
      }

	if( self.origin.z >= height )
		return false;
	else
		return true;
	}

void VerticalTakeOff::End
	(
	Actor &self
	)

	{
	}


/****************************************************************************

  Hover Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Hover, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

Hover::Hover()
	{
	anim = "fly";
	}

void Hover::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void Hover::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void Hover::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }
   
	fly.Begin( self );	
	}

qboolean	Hover::Evaluate
	(
	Actor &self
	)

	{
	//self.angles[PITCH] = 0;
	self.angles[ROLL]  = 0;

	self.setAngles( self.angles );
	self.forwardspeed = 0;
	//goal = self.origin;
	//fly.SetGoalPoint(goal);

	return true;
	}

void Hover::End
	(
	Actor &self
	)

	{
	fly.End(self);
	}
/****************************************************************************

  Wander Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, Wander, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void Wander::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void Wander::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nseek:\n" );
   seek.ShowInfo( self );

   //gi.Printf( "\navoid:\n" );
   //avoid.ShowInfo( self );
	}

void Wander::Begin
	(
	Actor &self
	)

	{
   avoidtime = 0;
   avoidvec = vec_zero;

	//avoid.Begin( self );
   seek.Begin( self );
   seek.SetTargetVelocity( vec_zero );
	if ( anim.length() )
		{
		self.SetAnim( anim );
		}
	}


qboolean	Wander::Evaluate
	(
	Actor &self
	)

	{
   if ( ( self.lastmove != STEPMOVE_OK ) || ( avoidtime <= level.time ) )
      {
      Vector dir;
      Vector ang;
      float time;

      time = 5;
		//self.Chatter( "snd_idle", 4 );
      avoidvec = ChooseRandomDirection( self, avoidvec, &time, 0, false );
      avoidtime = level.time + time;
      }

	if ( self.movespeed != 1 )
		seek.SetMaxSpeed( self.movespeed );
	else
		seek.SetMaxSpeed( 100 );

   seek.SetPosition( self.origin );
	seek.SetDir( self.movedir );
   seek.SetTargetPosition( avoidvec );

   if ( !seek.Evaluate( self ) )
      {
		// we have reached the goal, re-evaluate
      avoidtime = 0;
      }

   /* avoid.SetMaxSpeed( self.movespeed * 2 );
   avoid.SetPosition( self.origin );
	avoid.SetDir( self.movedir );
	avoid.Evaluate( self ); */

   //self.Accelerate( seek.steeringforce + avoid.steeringforce );

	self.Accelerate( seek.steeringforce );

	return true;
	}

void Wander::End
	(
	Actor &self
	)

	{
	//avoid.End( self );
	seek.End( self );
	}

/****************************************************************************

  GetCloseToEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, GetCloseToEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void GetCloseToEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		forever = ev->GetBoolean( 2 );
	else
		forever = true;
	}

void GetCloseToEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void GetCloseToEnemy::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
      {
		anim = "run";
      }

	if ( anim != self.animname || self.newanim.length() )
      {
		self.SetAnim( anim, EV_Actor_NotifyBehavior );
      }

	chase.UseNearestNode( false );
	chase.Begin( self );
	wander.Begin( self );

	next_think_time = 0;
	}

qboolean	GetCloseToEnemy::Evaluate
	(
	Actor &self
	)

	{
	qboolean result;

	if ( !self.currentEnemy )
		return false;

	if ( next_think_time <= level.time )
		{
		if ( self.groundentity && self.groundentity->s.number == self.currentEnemy->entnum )
			{
			wander.Evaluate( self );
			result = true;
			}
		else
			{
			chase.SetTarget( self.currentEnemy );			

			result = chase.Evaluate( self );
			}

		if ( self.GetActorFlag( ACTOR_FLAG_SIMPLE_PATHFINDING ) )
			next_think_time = level.time + 2 * FRAMETIME;
		else
			next_think_time = 0;
		}
	else
		result = true;

	if ( !forever && !result )
		return false;

	return true;
	}

void GetCloseToEnemy::End
	(
	Actor &self
	)

	{
	chase.End( self );
	wander.End( self );
	}

/****************************************************************************

  GetCloseToPlayer Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, GetCloseToPlayer, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void GetCloseToPlayer::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		forever = ev->GetBoolean( 2 );
	else
		forever = true;
	}

void GetCloseToPlayer::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void GetCloseToPlayer::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
      {
		anim = "run";
      }

	if ( anim != self.animname || self.newanim.length() )
      {
		self.SetAnim( anim, EV_Actor_NotifyBehavior );
      }

	chase.UseNearestNode( false );
	chase.Begin( self );
	wander.Begin( self );

	next_think_time = 0;
	}

qboolean	GetCloseToPlayer::Evaluate
	(
	Actor &self
	)

	{
	qboolean result;
	
	Player* player = 0;
	// Make sure the player is alive and well
	for(int i = 0; i < game.maxclients; i++)
		{
		player = GetPlayer(i);		
		
		// don't target while player is not in the game or he's in notarget
		if( !player || ( player->flags & FL_NOTARGET ) )
			{
			return false;
			}
		}

	if ( next_think_time <= level.time )
		{
		if ( self.groundentity && self.groundentity->s.number == player->entnum )
			{
			wander.Evaluate( self );
			result = true;
			}
		else
			{
			chase.SetTarget( player );			

			result = chase.Evaluate( self );
			}

		if ( self.GetActorFlag( ACTOR_FLAG_SIMPLE_PATHFINDING ) )
			next_think_time = level.time + 2 * FRAMETIME;
		else
			next_think_time = 0;
		}
	else
		result = true;

	if ( !forever && !result )
		return false;

	return true;
	}

void GetCloseToPlayer::End
	(
	Actor &self
	)

	{
	chase.End( self );
	wander.End( self );
	}

/****************************************************************************

  RetreatFromEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, RetreatFromEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void RetreatFromEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		forever = ev->GetBoolean( 2 );
	else
		forever = true;
	}

void RetreatFromEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void RetreatFromEnemy::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
      {
		anim = "run";
      }

	if ( anim != self.animname || self.newanim.length() )
      {
		self.SetAnim( anim, EV_Actor_NotifyBehavior );
      }

	chase.UseNearestNode( false );
	chase.Begin( self );
	wander.Begin( self );

	next_think_time = 0;
	}

qboolean	RetreatFromEnemy::Evaluate
	(
	Actor &self
	)

	{
	qboolean result;

	Player* player = 0;
	// Make sure the player is alive and well
	for(int i = 0; i < game.maxclients; i++)
		{
		player = GetPlayer(i);		
		
		// don't target while player is not in the game or he's in notarget
		if( !player || ( player->flags & FL_NOTARGET ) )
			{
			return false;
			}
		}

	if ( next_think_time <= level.time )
		{
		if ( self.groundentity && self.groundentity->s.number == self.currentEnemy->entnum )
			{
			wander.Evaluate( self );
			result = true;
			}
		else
			{
			
			float currentZ = self.centroid.z; 
			Vector FleeVec = (self.centroid - player->centroid) + self.centroid;
			FleeVec.z = currentZ;

			trace_t trace;
			trace = G_Trace( self.centroid, self.mins, self.maxs, FleeVec, NULL, MASK_SOLID, false, "RetreatFromEnemy" );
			
			chase.SetGoalPos( trace.endpos );

			result = chase.Evaluate( self );
			}

		if ( self.GetActorFlag( ACTOR_FLAG_SIMPLE_PATHFINDING ) )
			next_think_time = level.time + 2 * FRAMETIME;
		else
			next_think_time = 0;
		}
	else
		result = true;

	if ( !forever && !result )
		return false;

	return true;
	}

void RetreatFromEnemy::End
	(
	Actor &self
	)

	{
	chase.End( self );
	wander.End( self );
	}

/****************************************************************************

  GotoDeadEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, GotoDeadEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void GotoDeadEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	}

void GotoDeadEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void GotoDeadEnemy::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
      {
		anim = "run";
      }

	if ( anim != self.animname || self.newanim.length() )
      {
		self.SetAnim( anim, EV_Actor_NotifyBehavior );
      }

	chase.Begin( self );
	}

qboolean	GotoDeadEnemy::Evaluate
	(
	Actor &self
	)

	{
	qboolean result;

	if ( !self.currentEnemy )
		return false;

	if ( !self.currentEnemy->deadflag )
		return false;

	chase.SetGoalPos( self.currentEnemy->origin );

	result = chase.Evaluate( self );

	if ( !result )
		return false;

	return true;
	}

void GotoDeadEnemy::End
	(
	Actor &self
	)

	{
	chase.End( self );
	}

/****************************************************************************

  Investigate Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Investigate, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

#define INVESTIGATE_MODE_INVESTIGATE	0
#define INVESTIGATE_MODE_TURN1			1
#define INVESTIGATE_MODE_RETURN			2
#define INVESTIGATE_MODE_TURN2			3

Investigate::Investigate()
	{
	investigate_time = 10;
	anim = "run";
	}

void Investigate::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	if ( ev->NumArgs() > 1 )
		investigate_time = ev->GetFloat( 2 );

	if ( ev->NumArgs() > 2 )
		return_to_original_location = ev->GetBoolean( 3 );
	else
		return_to_original_location = true;
	}

void Investigate::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
   gi.Printf( "\nanim: %s\n", anim.c_str() );
   gi.Printf( "curioustime: %f\n", curioustime );
   gi.Printf( "goal: ( %f, %f, %f )\n", goal.x, goal.y, goal.z );
	}

void Investigate::Begin
	(
	Actor &self
	)

	{
	trace_t trace;
	Vector trace_start_pos;
	Vector trace_end_pos;
	PathNode *goal_node;
	Vector delta;
	float xydist;


	// Find the goal position

	trace_start_pos = self.noise_position;
	trace_end_pos   = trace_start_pos - Vector( "0 0 1000" );

	trace = G_Trace( trace_start_pos, vec_zero, vec_zero, trace_end_pos, NULL, MASK_SOLID, false, "Investigate" );

	goal = trace.endpos;

	// Find the nearest node to our goal

	goal_node = self.NearestNodeInPVS( goal );
	real_goal_position = self.noise_position;

	if ( goal_node )
		goal = goal_node->origin;

	self.SetActorFlag( ACTOR_FLAG_INVESTIGATING, true );

   // We are only interested for a short period, if we can't get there, lets go back to what we were doing

   curioustime = level.time + investigate_time;
	self.Chatter( "snd_investigate", 10 );

	chase.Begin( self );
	chase.SetGoal( goal_node );

	turnto.Begin( self );

	// Don't allow guys to change their anim if we're already close enough to the goal

	delta   = goal - self.origin;
	delta.z = 0;

	xydist = delta.length();

	if ( xydist >= 100 && anim.length() )
		{
		self.SetAnim( anim );
		}

	mode = INVESTIGATE_MODE_INVESTIGATE;

	start_pos = self.origin;
	start_yaw = self.angles[YAW];
	}

qboolean	Investigate::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	Vector delta;
	float xydist;


	switch ( mode )
		{
		case INVESTIGATE_MODE_INVESTIGATE :

			// Go to spot where the noise was heard

			if ( !chase.Evaluate( self ) )
				{
				mode = INVESTIGATE_MODE_TURN1;
				self.SetAnim( "idle" );
				}

			// See if we have investigated long enough

			if ( curioustime < level.time )
				{
				mode = INVESTIGATE_MODE_RETURN;
				curioustime = level.time + investigate_time * 2;
				}
			else
				{
				// See if have gotten close enough to the noise position

				delta   = goal - self.origin;
				delta.z = 0;

				xydist = delta.length();

				if ( xydist < 100 )
					{
					mode = INVESTIGATE_MODE_TURN1;
					self.SetAnim( "idle" );
					}
				}

			break;
		case INVESTIGATE_MODE_TURN1 :

			// Turn towards the noise position

			dir = real_goal_position - self.origin;
			angles = dir.toAngles();
			turnto.SetDirection( angles[YAW] );

			if ( !turnto.Evaluate( self ) )
				{
				mode = INVESTIGATE_MODE_RETURN;
				curioustime = level.time + investigate_time * 2;
				self.SetAnim( anim );
				}

			break;
		case INVESTIGATE_MODE_RETURN :

			if ( !return_to_original_location )
				return false;

			// Return back to our original position

			chase.SetGoalPos( start_pos );

			if ( !chase.Evaluate( self ) )
				mode = INVESTIGATE_MODE_TURN2;

			if ( curioustime < level.time )
				return false;

			break;
		case INVESTIGATE_MODE_TURN2 :

			self.SetAnim( "idle" );

			// Turn back to our original direction

			turnto.SetDirection( start_yaw );
			if ( !turnto.Evaluate( self ) )
				return false;

			break;
		}

	return true;
	}

void Investigate::End
	(
	Actor &self
	)

	{
	self.SetActorFlag( ACTOR_FLAG_INVESTIGATING, false );
	self.SetActorFlag( ACTOR_FLAG_NOISE_HEARD, false );
	chase.End( self );
	turnto.End( self );
	}

/****************************************************************************

  TurnInvestigate Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TurnInvestigate, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void TurnInvestigate::SetArgs
	(
	Event *ev
	)

	{
	left_anim  = ev->GetString( 1 );
	right_anim = ev->GetString( 2 );
	turn_speed = ev->GetFloat( 3 );
	}

void TurnInvestigate::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "goal: ( %f, %f, %f )\n", goal.x, goal.y, goal.z );
	}

void TurnInvestigate::Begin
	(
	Actor &self
	)

	{
	goal = self.noise_position;
	self.SetActorFlag( ACTOR_FLAG_INVESTIGATING, true );

	seek.Begin( self );
	seek.SetTargetPosition( goal );

	self.SetAnim( "idle" );
	}

qboolean	TurnInvestigate::Evaluate
	(
	Actor &self
	)

	{
	str turn_anim_name;
	Vector dir;

	self.angles.AngleVectors( &dir );

	seek.SetTargetVelocity( vec_zero );
	seek.SetPosition( self.centroid );
	seek.SetDir( dir );
	seek.Evaluate( self );

	// See if we have turned all of the way to the noise position

	if ( seek.steeringforce[YAW] < .5 && seek.steeringforce[YAW] > -.5 )
		return false;

	// Make sure we are not turning faster than out turn speed

	if ( seek.steeringforce[YAW] > turn_speed )
		{
		seek.steeringforce[YAW] = turn_speed;
		}

	if ( seek.steeringforce[YAW] < -turn_speed )
		{
		seek.steeringforce[YAW] = -turn_speed;
		}

	seek.steeringforce[PITCH] = 0;
	seek.steeringforce[ROLL]  = 0;

	// Set the correct animation (left or right)

	if ( seek.steeringforce[YAW] > 0 )
		turn_anim_name = left_anim;
	else
		turn_anim_name = right_anim;

	if ( turn_anim_name != self.animname )
		self.SetAnim( turn_anim_name );

	// Actually turn here

	self.Accelerate( seek.steeringforce );

	return true;
	}

void TurnInvestigate::End
	(
	Actor &self
	)

	{
	self.SetActorFlag( ACTOR_FLAG_INVESTIGATING, false );
	self.SetActorFlag( ACTOR_FLAG_NOISE_HEARD, false );
	seek.End( self );
	}

/****************************************************************************

  TurnToEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TurnToEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

void TurnToEnemy::SetArgs
	(
	Event *ev
	)

	{
	left_anim  = ev->GetString( 1 );
	right_anim = ev->GetString( 2 );
	turn_speed = ev->GetFloat( 3 );
	forever    = ev->GetBoolean( 4 );

	if ( ev->NumArgs() > 4 )
		use_last_known_position = ev->GetBoolean( 5 );
	else
		use_last_known_position = false;
	}

void TurnToEnemy::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void TurnToEnemy::Begin
	(
	Actor &self
	)

	{
	seek.Begin( self );

	self.SetAnim( "idle" );
	}

void TurnToEnemy::AnimDone
	(
	Event *ev
	)

	{
	anim_done = true;
	}


qboolean	TurnToEnemy::Evaluate
	(
	Actor &self
	)

	{
	str turn_anim_name;
	Vector dir;

	if ( !self.currentEnemy )
		return false;

	self.angles.AngleVectors( &dir );

	if ( use_last_known_position )
		seek.SetTargetPosition( self.last_known_enemy_pos );
	else
		seek.SetTargetPosition( self.currentEnemy->origin );

	seek.SetTargetVelocity( vec_zero );
	seek.SetPosition( self.centroid );
	seek.SetDir( dir );
	seek.Evaluate( self );

	// See if we have turned all of the way to the enemy position

	if ( seek.steeringforce[YAW] < .5 && seek.steeringforce[YAW] > -.5 )
		seek.steeringforce[YAW] = 0;

	// Make sure we are not turning faster than out turn speed

	if ( seek.steeringforce[YAW] > turn_speed )
		{
		seek.steeringforce[YAW] = turn_speed;
		}

	if ( seek.steeringforce[YAW] < -turn_speed )
		{
		seek.steeringforce[YAW] = -turn_speed;
		}

	seek.steeringforce[PITCH] = 0;
	seek.steeringforce[ROLL]  = 0;

	// Set the correct animation (left or right)

	if ( seek.steeringforce[YAW] > 0 )
		turn_anim_name = left_anim;
	else if ( seek.steeringforce[YAW] < 0 )
		turn_anim_name = right_anim;
	else if ( anim_done )
		turn_anim_name = "idle";
	else
		turn_anim_name = self.animname.c_str();

	if ( turn_anim_name != self.animname )
		self.SetAnim( turn_anim_name, EV_Actor_NotifyBehavior );

	// Actually turn here

	self.Accelerate( seek.steeringforce );

	// See if we have turned all of the way to the enemy position

	if ( seek.steeringforce[YAW] < turn_speed && seek.steeringforce[YAW] > -turn_speed && !forever )
		return false;

	anim_done = false;

	return true;
	}

void TurnToEnemy::End
	(
	Actor &self
	)

	{
	seek.End( self );
	}

/****************************************************************************

  PickupEntity Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, PickupEntity, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

void PickupEntity::SetArgs
	(
	Event *ev
	)

	{
	ent_to_pickup    = ev->GetEntity( 1 );
	pickup_anim_name = ev->GetString( 2 );
	}

void PickupEntity::Begin
	(
	Actor &self
	)

	{
	anim_done = false;
	self.pickup_ent = ent_to_pickup;

	self.SetAnim( pickup_anim_name.c_str(), EV_Actor_NotifyBehavior );
	}

void PickupEntity::AnimDone
	(
	Event *ev
	)

	{
	anim_done = true;
	}


qboolean	PickupEntity::Evaluate
	(
	Actor &self
	)

	{
	if ( !ent_to_pickup )
		return false;

	if ( anim_done )
		return false;

	return true;
	}

void PickupEntity::End
	(
	Actor &self
	)

	{
	self.SetAnim( "idle" );
	self.pickup_ent = NULL;
	}

/****************************************************************************

  ThrowEntity Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, ThrowEntity, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ &EV_Behavior_AnimDone,	AnimDone },
		{ NULL, NULL }
	};

void ThrowEntity::SetArgs
	(
	Event *ev
	)

	{
	throw_anim_name = ev->GetString( 1 );
	}

void ThrowEntity::Begin
	(
	Actor &self
	)

	{
	anim_done = false;
	self.SetAnim( throw_anim_name, EV_Actor_NotifyBehavior );
	}

void ThrowEntity::AnimDone
	(
	Event *ev
	)

	{
	anim_done = true;
	}


qboolean	ThrowEntity::Evaluate
	(
	Actor &self
	)

	{
	if ( anim_done )
		return false;

	return true;
	}

void ThrowEntity::End
	(
	Actor &self
	)

	{
	self.SetAnim( "idle" );
	}



/****************************************************************************
*****************************************************************************

  Behaviors for specific creatures

*****************************************************************************
****************************************************************************/



/****************************************************************************

  BurrowAttack Class Definition

****************************************************************************/

#define BURROW_MODE_MOVING  0
#define BURROW_MODE_ATTACK  1

CLASS_DECLARATION( Behavior, BurrowAttack, NULL )
	{
		{ NULL, NULL }
	};

void BurrowAttack::SetArgs
	(
	Event *ev
	)

	{
	use_last_known_position = ev->GetBoolean( 1 );
	}

void BurrowAttack::Begin
	(
	Actor &self
	)

	{
	Vector attack_dir;
	Vector start_pos;
	Vector end_pos;
	trace_t trace;

	if ( self.animname != "idle_down" )
		self.SetAnim( "idle_down" );

	// Setup our goal point

	if ( self.currentEnemy )
		{
		if ( use_last_known_position )
			goal = self.last_known_enemy_pos;
		else
			goal = self.currentEnemy->origin;

		start_pos = goal + Vector( "0 0 10" );
		end_pos = start_pos + Vector( "0 0 -250" );

		trace = G_Trace( start_pos, vec_zero, vec_zero, end_pos, NULL, MASK_DEADSOLID, false, "BurrowAttack::Begin" );

		goal = trace.endpos;
		}

	// Setup our starting point, a little ways in front of our origin

	attack_dir = goal - self.origin;

	too_close = false;

	if ( attack_dir.length() < 300 )
		too_close = true;

	attack_dir.normalize();

	attack_origin = self.origin + attack_dir * 100;

	burrow_mode = BURROW_MODE_MOVING;

	stage = self.stage;

	burrow_speed = 80;

	if ( stage == 3 )
		{
		attacks_left = 2;
		}
	else if ( stage == 4 )
		{
		attacks_left = 3 + G_Random( 3 );
		burrow_speed = 120;
		}
	}

qboolean	BurrowAttack::Evaluate
	(
	Actor &self
	)

	{
	Vector attack_dir;
	Vector new_origin;
	float total_dist;
	Vector start_pos;
	Vector end_pos;
	Entity *dirt;
	trace_t trace;
	Vector temp_angles;
	int cont;
	Vector temp_endpos;

	if ( !self.currentEnemy )
		return false;

	if ( too_close )
		return false;

	switch ( burrow_mode )
		{
		case BURROW_MODE_MOVING :

			attack_dir = goal - attack_origin;
			total_dist = attack_dir.length();
			attack_dir.normalize();

			if ( total_dist < burrow_speed )
				{
				new_origin = goal;
				}
			else
				{
				new_origin = attack_origin + attack_dir * burrow_speed;
				total_dist = burrow_speed;
				}

			// Spawn in dirt or water

			start_pos = attack_origin + attack_dir + Vector( "0 0 10" );
			end_pos = start_pos + Vector( "0 0 -250" );

			trace = G_Trace( start_pos, vec_zero, vec_zero, end_pos, NULL, MASK_DEADSOLID | MASK_WATER, false, "BurrowAttack" );

			temp_endpos = trace.endpos;
			temp_endpos -=  Vector( "0 0 5" );
			cont = gi.pointcontents( temp_endpos, 0 );

			dirt = new Entity( ENTITY_CREATE_FLAG_ANIMATE );

			dirt->setOrigin( trace.endpos );

			temp_angles = vec_zero;

			if (cont & MASK_WATER)
				dirt->setModel( "fx_splashsmall.tik" );
			else
				dirt->setModel( "fx_dirtcloud.tik" );

			dirt->setAngles( temp_angles );

			dirt->animate->RandomAnimate( "idle" );

			dirt->PostEvent( EV_Remove, 5 );

			attack_origin = new_origin;

			if ( attack_origin == goal )
				{
				// Got to our goal position, do attack

				if ( stage == 1 )
					{
					SpawnArm( self, leg1, attack_origin + Vector( " 25  25 0" ), "attack1", 0 );
					SpawnArm( self, leg2, attack_origin + Vector( " 25 -25 0" ), "attack1", 0 );
					SpawnArm( self, leg3, attack_origin + Vector( "-25  25 0" ), "attack1", 0 );
					SpawnArm( self, leg4, attack_origin + Vector( "-25 -25 0" ), "attack1", 0 );
					}
				else if ( stage == 2 )
					{
					SpawnArm( self, leg1, attack_origin + Vector( " 25   0 0" ), "attack2",   0 );
					SpawnArm( self, leg2, attack_origin + Vector( "-25  25 0" ), "attack2", 120 );
					SpawnArm( self, leg3, attack_origin + Vector( "-25 -25 0" ), "attack2", 240 );
					}
				else
					{
					SpawnArm( self, leg1, attack_origin, "attack1", 0 );
					}

				burrow_mode = BURROW_MODE_ATTACK;
				}

			break;
		case BURROW_MODE_ATTACK :

			// Wait until all of the legs are done

			if ( !leg1 && !leg2 && !leg3 && !leg4 )
				{
				if ( self.animname != "idle_down" )
					self.SetAnim( "idle_down" );

				if ( stage == 1 || stage == 2 )
					{
					return false;
					}
				else
					{
					attacks_left--;

					if ( attacks_left > 0 )
						{
						if ( use_last_known_position )
							if ( self.CanReallySee( self.currentEnemy ) )
								goal = self.currentEnemy->origin;
							else
								return false;
						else
							goal = self.currentEnemy->origin;

						burrow_mode = BURROW_MODE_MOVING;
						}
					else
						{
						return false;
						}
					}
				}

			break;
		}

	return true;
	}

void BurrowAttack::SpawnArm
	(
	Actor &self,
	EntityPtr &leg,
	const Vector &original_arm_origin,
	const char *anim_name,
	float angle
	)

	{
	Vector angles;
	trace_t trace;
	Vector start_pos;
	Vector end_pos;
	str anim_to_play;
	Entity *leg_animate_ptr;
	Vector dir;
	Entity *dirt;
	Vector arm_origin;


	// Find correct spot to spawn

	arm_origin = original_arm_origin;

	arm_origin[2] = -575;

	start_pos = arm_origin + Vector( "0 0 64" );
	end_pos = arm_origin - Vector( "0 0 100" );

	//trace = G_Trace( start_pos, Vector(-5, -5, 0), Vector(5, 5, 0), end_pos, NULL, MASK_DEADSOLID, false, "BurrowAttack" );
	trace = G_Trace( start_pos, Vector(-10, -10, 0), Vector(10, 10, 0), end_pos, NULL, MASK_DEADSOLID, false, "BurrowAttack" );

	arm_origin = trace.endpos;

	// Make sure can spawn here

	end_pos = arm_origin + Vector( "0 0 50" );

	trace = G_Trace( arm_origin, Vector(-10, -10, 0), Vector(10, 10, 0), end_pos, NULL, MASK_DEADSOLID, false, "BurrowAttack" );

	if ( trace.fraction < 1 || trace.startsolid || trace.allsolid )
		{
		if ( trace.entityNum == ENTITYNUM_WORLD || !( trace.ent && trace.ent->entity && trace.ent->entity->takedamage ) )
			return;
		}

	// Spawn some dirt

	dirt = new Entity( ENTITY_CREATE_FLAG_ANIMATE );

	dirt->setOrigin( arm_origin );
	dirt->setModel( "fx_dirtcloud.tik" );
	dirt->setAngles( vec_zero );
	dirt->animate->RandomAnimate( "idle" );
	dirt->PostEvent( EV_Remove, 5 );

	// Spawn leg

	leg = new Entity( ENTITY_CREATE_FLAG_ANIMATE );

	leg->setModel( "vmama_arm.tik" );
	leg->setOrigin( arm_origin );

	leg->ProcessPendingEvents();

	//leg->edict->clipmask	= MASK_MONSTERSOLID;
	leg->setContents( 0 );
	leg->setSolidType( SOLID_NOT );

	leg->PostEvent( EV_BecomeNonSolid, 0 );

	angles = vec_zero;
	angles[YAW] = angle;

	leg->setAngles( angles );

	anim_to_play = anim_name;

	// See if we should get stuck or not

	if ( strcmp( anim_name, "attack1" ) == 0 )
		{
		end_pos = arm_origin + Vector( "0 0 250" );

		leg_animate_ptr = leg;

		trace = G_Trace( arm_origin, Vector(-5, -5, 0), Vector(5, 5, 0), end_pos, leg_animate_ptr, MASK_DEADSOLID, false, "BurrowAttack" );

		if ( trace.fraction != 1.0 )
			{
			if ( self.animname != "struggle" )
				self.SetAnim( "struggle" );

			anim_to_play = "getstuck";
			}
		}

	// Damage entities in way

	if ( strcmp( anim_name, "attack1" ) == 0 )
		{
		start_pos = arm_origin;
		end_pos = arm_origin + Vector( "0 0 250" );

		dir = Vector ( G_CRandom( 5 ), G_CRandom( 5 ), 10 );
		}
	else
		{
		start_pos = arm_origin + Vector( "0 0 10" );

		angles.AngleVectors( &dir );

		end_pos = start_pos + dir * 250;
		}

	leg_animate_ptr = leg;

	MeleeAttack( start_pos, end_pos, 50, &self, MOD_IMPALE, 10, 0, 0, 100 );

	leg->animate->RandomAnimate( anim_to_play.c_str(), EV_Remove );
	}

void BurrowAttack::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  CircleEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, CircleEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void CircleEnemy::SetArgs
	(
	Event *ev
	)

	{
	center_part_name = ev->GetString( 1 );
	}

void CircleEnemy::Begin
	(
	Actor &self
	)

	{
	ent_to_circle = self.currentEnemy;
	last_angle_change = 0;
	}

float CircleEnemy::GetAngleDiff
	(
	Actor &self,
	Actor *center_actor,
	const Vector &origin
	)

	{
	Vector dir;
	Vector enemy_angles;
	Vector actor_angles;
	float angle_diff;

	dir = ent_to_circle->origin - center_actor->origin;
	enemy_angles = dir.toAngles();

	dir = origin - center_actor->origin;
	actor_angles = dir.toAngles();

	angle_diff = AngleDelta( actor_angles[YAW], enemy_angles[YAW] );

	return angle_diff;
	}

#define MAX_CIRCLE_ACCELERATION  .125
#define MAX_CIRCLE_VELOCITY  10

qboolean	CircleEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Actor *center_actor;
	Vector actor_angles;
	float angle_diff;
	float other_angle_diff;
	float abs_angle_diff;
	float other_abs_angle_diff = 180;
	float angle_change = MAX_CIRCLE_VELOCITY;
	float length;
	float real_angle_change;
	Actor *other;


	if ( !ent_to_circle )
		return false;

	center_actor = self.FindPartActor( center_part_name.c_str() );

	if ( !center_actor )
		return false;

	angle_diff = GetAngleDiff( self, center_actor, self.origin );

	if ( angle_diff < 0 )
		abs_angle_diff = -angle_diff;
	else
		abs_angle_diff = angle_diff;

	other = self.FindPartActor( self.part_name );

	if ( other )
		{
		other_angle_diff = GetAngleDiff( self, center_actor, other->origin );

		if ( other_angle_diff < 0 )
			other_abs_angle_diff = -other_angle_diff;
		else
			other_abs_angle_diff = other_angle_diff;
		}

	if ( abs_angle_diff < other_abs_angle_diff )
		{
		// Turn towards enemy

		if ( abs_angle_diff < angle_change )
			angle_change = abs_angle_diff;

		if ( angle_diff < 0 )
			real_angle_change = angle_change;
		else
			real_angle_change = -angle_change;
		}
	else
		{
		// Turn away from enemy

		if ( 180 - abs_angle_diff < angle_change )
			angle_change = 180 - abs_angle_diff;

		if ( angle_diff < 0 )
			real_angle_change = -angle_change;
		else
			real_angle_change = angle_change;
		}

	if ( real_angle_change < 1.0 && real_angle_change > -1.0 )
		real_angle_change = 0;

	if ( real_angle_change > 0 )
		{
		if ( real_angle_change > last_angle_change + MAX_CIRCLE_ACCELERATION )
			real_angle_change = last_angle_change + MAX_CIRCLE_ACCELERATION;
		}
	else if ( real_angle_change < 0 )
		{
		if ( real_angle_change < last_angle_change - MAX_CIRCLE_ACCELERATION )
			real_angle_change = last_angle_change - MAX_CIRCLE_ACCELERATION;
		}

	last_angle_change = real_angle_change;

	dir = self.origin - center_actor->origin;
	length = dir.length();

	actor_angles = dir.toAngles();
	actor_angles[YAW] += real_angle_change;

	// Find new position

	actor_angles.AngleVectors( &dir, NULL, NULL );

	dir *= length;
	dir.z = 0;

	self.setOrigin( center_actor->origin + dir );

	// Set the actors angle to look at the center

	dir[0] = -dir[0];
	dir[1] = -dir[1];
	dir[2] = -dir[2];

	self.angles[YAW] = dir.toYaw();
	self.setAngles( self.angles );

	return true;
	}

void CircleEnemy::End
	(
	Actor &self
	)

	{
	}
/****************************************************************************

  CircleCurrentEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, CircleCurrentEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void CircleCurrentEnemy::SetArgs
	(
	Event *ev
	)

	{
	anim = "walk";
	
	radius = 0;
	maintainDistance = true;
	clockwise = true;
	
	if (ev->NumArgs() > 0 )
		anim = ev->GetString( 1 );

	if (ev->NumArgs() > 1 )
		radius = ev->GetFloat( 2 );

	if (ev->NumArgs() > 2 )
		maintainDistance = ev->GetBoolean( 3 );

	if (ev->NumArgs() > 3 )
		clockwise = ev->GetBoolean( 4 );
	
	}

void CircleCurrentEnemy::Begin
	(
	Actor &self
	)

	{
	if (!self.currentEnemy) return;
	
	self.SetAnim(anim);
	dirToEnemy = self.origin - self.currentEnemy->origin;

	if(!radius)
		radius = dirToEnemy.length();
	
	stuck = 0;
	stuckCheck = 0;

	if (clockwise)
		{
		turnAngle = 90;
		}
	else
		turnAngle = -90;

	oldAngle = 0;
	angleAdjusted = false;
	}


qboolean	CircleCurrentEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector dirAngles;
	Vector Angles;

	float dirYaw;
	
	if (!self.currentEnemy) return false;

	dirToEnemy = self.currentEnemy->origin - self.origin;
	dirYaw = dirToEnemy.toYaw();
	
	if(!stuck)
		{
		float len = dirToEnemy.length();
		if(len > radius && maintainDistance && !angleAdjusted)
			{
			oldAngle = turnAngle;
			turnAngle*=.5;
			angleAdjusted = true;
			}

		if(len <= radius && angleAdjusted)
			{
			turnAngle = oldAngle;
			angleAdjusted = false;
			}
		}

	dirYaw+=turnAngle;

	self.angles[YAW] = dirYaw;
	
   if ( self.lastmove != STEPMOVE_OK ) 
      {
		if(stuck >= 2)
			{
			if(stuck < 3 )
				{
				turnAngle = -turnAngle;
				}
			else
				{
				self.angles[YAW] = dirYaw + angleStep;
				angleStep+=45;
				}
			}

		stuck++;
      }
	
	stuckCheck++;
	if(stuckCheck > stuck)
		{
		stuckCheck = 0;
		stuck = 0;
		angleStep = 45;
		}

	self.setAngles(self.angles);
		
	return true;
	}

void CircleCurrentEnemy::End
	(
	Actor &self
	)

	{
	
	}

/****************************************************************************

  ChaoticDodge Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, ChaoticDodge, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void ChaoticDodge::SetArgs
	(
	Event *ev
	)

	{
	anim = "walk";
	stuck = 0;
	time = .5;
	changeTime = 0;
	turnspeed = 45;
	adjusting = false;
	turnAngle = 0;
	
	if (ev->NumArgs() > 0 )
		anim = ev->GetString( 1 );

	if (ev->NumArgs() > 1 )
		time = ev->GetFloat( 2 );

	if (ev->NumArgs() > 2 )
		turnspeed = ev->GetFloat( 3 );
	
	}

void ChaoticDodge::Begin
	(
	Actor &self
	)

	{
	self.SetAnim(anim);

	}


qboolean	ChaoticDodge::Evaluate
	(
	Actor &self
	)

	{

	float dirYaw = GetNewYaw();

	float CurrentYaw = self.origin.toYaw();
		
	if ( self.lastmove != STEPMOVE_OK ) 
      {
		stuck++;
		turnAngle+=30;
		if (stuck > 3 )
			{
			self.angles[YAW]+=turnAngle;
			self.setAngles(self.angles);
			time=1;
			changeTime = level.time + time;
			stuck = 0;
			turnAngle = 0;
			}
		}

	if ( level.time <= changeTime )
		return true;
	
	dirYaw+=CurrentYaw;

	self.angles[YAW] = dirYaw;
	self.setAngles(self.angles);	
	time = G_Random ( .15 ) +.15;
	changeTime = level.time + time;
		
	return true;
	}

float ChaoticDodge::GetNewYaw
   (
	void
	)

	{
	float dirYaw = G_Random(20) + turnspeed;
	float randomSide = G_Random();
		if (randomSide < .5 )
			randomSide = 1;
		else
			randomSide = -1;
	
	dirYaw*=randomSide;
	
	return dirYaw;
	}

void ChaoticDodge::End
	(
	Actor &self
	)

	{
	
	}
/****************************************************************************

  ShockWater Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, ShockWater, NULL )
	{
		{ NULL, NULL }
	};

ShockWater::ShockWater()
	{
	left_beam   = NULL;
	right_beam  = NULL;
	center_beam = NULL;
	already_started = false;
	}

void ShockWater::Begin
	(
	Actor &self
	)

	{
	}

qboolean	ShockWater::Evaluate
	(
	Actor &self
	)

	{
	Vector left_tag_orig;
	Vector right_tag_orig;
	Vector end_pos;
	Vector center_point;
	Actor *center_actor;
	trace_t  trace;
	Entity *hit_entity;
	Vector diff_vect;
	float diff;
	Vector dir;

	if ( !self.currentEnemy )
		return false;

	if ( self.newanimnum == -1 && !already_started )
		{
		// Get tag positions
		self.GetTag( "tag_left",  &left_tag_orig );
		self.GetTag( "tag_right", &right_tag_orig );

		// Get end position
		end_pos = left_tag_orig + right_tag_orig;
		end_pos *= .5;
		end_pos[2] -= 120;

		dir = end_pos - self.origin;
		dir.z = 0;
		dir *= 0.5;

		end_pos += dir;

		// Add the left and right beams
      left_beam   = CreateBeam( NULL, "emap1", left_tag_orig, end_pos, 10, 1.5f, 0.2f );
		right_beam  = CreateBeam( NULL, "emap1", right_tag_orig, end_pos, 10, 1.5f, 0.2f );

		center_actor = self.FindPartActor( "body" );
		if ( center_actor )
         {
			center_point = center_actor->origin;
         }

		trace = G_Trace( center_point, vec_zero, vec_zero, end_pos, &self, MASK_SHOT, false, "ShockAttack" );
		if ( trace.fraction < 1.0 && trace.entityNum != center_actor->entnum )
			{
			hit_entity = G_GetEntity( trace.entityNum );
			if ( hit_entity )
            {
				center_point = hit_entity->origin;
            }
			}
		else
			{
			// Shock head
			center_actor->AddStateFlag( STATE_FLAG_IN_PAIN );

			center_actor->SpawnEffect( "fx_elecstrike.tik", center_actor->origin );
			center_actor->Sound( "sound/weapons/sword/electric/hitmix2.wav", 0, 1, 500 );
			}

      // create the center beam
      center_beam = CreateBeam( NULL, "emap1", end_pos, center_point, 20, 3.0f, 0.2f );

		// Damage player if in water
		if ( center_actor )
			{
			diff_vect = self.currentEnemy->origin - center_actor->origin;
			diff_vect[2] = 0;

			diff = diff_vect.length();
			//if ( diff < 240 && self.currentEnemy->groundentity )
			if ( diff < 350 && self.currentEnemy->groundentity )
				{
				self.currentEnemy->Damage( &self, &self, 10, Vector (0, 0, 0), Vector (0, 0, 0), Vector (0, 0, 0), 0, 0, MOD_ELECTRICWATER );
				}
			}
		already_started = true;
		}

	return true;
	}

void ShockWater::End
	(
	Actor &self
	)

	{
   delete left_beam;
	delete right_beam;
	delete center_beam;
	}

/****************************************************************************

  Shock Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Shock, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

Shock::Shock()
	{
	beam = NULL;
	damage = 10;
	already_started = false;
	random_angle = 0;
	beamShader = "emap1";
	z_offset = 100;
	}

void Shock::SetArgs
	(
	Event *ev
	)

	{
	tag_name = ev->GetString( 1 );
	beamShader = ev->GetString( 2 );

	if ( ev->NumArgs() > 3 )
      {
		damage = ev->GetInteger( 3 );
      }

	if ( ev->NumArgs() > 3 )
      {
		random_angle = ev->GetFloat( 4 );
      }
	
	if ( ev->NumArgs() > 4 )
		z_offset = ev->GetFloat( 5 );
	}

void Shock::Begin
	(
	Actor &self
	)

	{
	}

qboolean	Shock::Evaluate
	(
	Actor &self
	)

	{
	Vector tag_orig;
	Vector angles;
	Vector end_pos;
	trace_t  trace;
	Vector dir;
	float yaw_diff;


	if ( !self.currentEnemy )
		return false;

	if ( self.newanimnum == -1 && !already_started )
		{
		// Get tag position
		if ( tag_name.length() == 0 )
         {
			return false;
         }

		self.GetTag( tag_name.c_str(), &tag_orig );

		// See if the enemy is in front of us

		dir = self.currentEnemy->origin - self.origin;
		angles = dir.toAngles();

		yaw_diff = AngleNormalize180( angles[YAW] - self.angles[YAW] );

		if ( yaw_diff < 60 && yaw_diff > -60 )
			{
			// The enemy is in front of us

			angles[YAW] += G_CRandom( random_angle );

			angles.AngleVectors( &end_pos, NULL, NULL );
			end_pos *= 500;
			end_pos += tag_orig;
			end_pos.z -= z_offset;
			}
		else
			{
			// Get end position
			angles = self.angles;

			angles[YAW] += G_Random( random_angle ) - random_angle / 2;
			angles[PITCH] = 0;
			angles[ROLL] = 0;

			angles.AngleVectors( &end_pos, NULL, NULL );
			end_pos *= 500;
			end_pos += tag_orig;
			end_pos.z -= z_offset;
			}

		trace = G_Trace( tag_orig, Vector (-15, -15, -15), Vector (15, 15, 15), end_pos, &self, MASK_SHOT, false, "ShockAttack" );

		if ( trace.fraction < 1.0 && trace.entityNum == self.currentEnemy->entnum )
			{
			end_pos = self.currentEnemy->centroid;
			dir = end_pos - tag_orig;
			dir.normalize();
			self.currentEnemy->Damage( &self, &self, damage, vec_zero, dir, vec_zero, 0, 0, MOD_ELECTRIC );
			}

		// Add the beam
		beam = CreateBeam( NULL, beamShader.c_str(), tag_orig, end_pos, 20, 1.5f, 0.2f );

      already_started = true;
		}
	else if ( already_started )
		{
		self.GetTag( tag_name.c_str(), &tag_orig );

		if ( beam )
			beam->setOrigin( tag_orig );
		}

	return true;
	}

void Shock::End
	(
	Actor &self
	)

	{
	if ( beam )
		{
		beam->ProcessEvent( EV_Remove );
		beam = NULL;
		}
	}

/****************************************************************************

  MultiShock Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, MultiShock, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

MultiShock::MultiShock()
	{
	beam1 = NULL;
	beam2 = NULL;
	damage = 10;
	already_started = false;
	random_angle = 0;
	beamShader = "emap1";
	z_offset = 100;
	}

void MultiShock::SetArgs
	(
	Event *ev
	)

	{
	tag_name1 = ev->GetString( 1 );
	tag_name2 = ev->GetString( 2 );
	beamShader = ev->GetString( 3 );
	damage = ev->GetFloat( 4 );
	random_angle = ev->GetFloat( 5 );
	z_offset = ev->GetFloat( 6 );
	}
	

void MultiShock::Begin
	(
	Actor &self
	)

	{
	}

qboolean	MultiShock::Evaluate
	(
	Actor &self
	)

	{
	Vector tag1_orig;
	Vector tag2_orig;

	Vector angles;
	Vector end_pos1;
	Vector end_pos2;

	trace_t  trace;
	Vector dir;
	float yaw_diff;


	if ( !self.currentEnemy )
		return false;

	//if ( self.newanimnum == -1 && !already_started )
	if ( !already_started )
		{
		// Get tag position
		if ( tag_name1.length() == 0 )
			return false;
         
		if ( tag_name2.length() == 0 )
			return false;

		self.GetTag( tag_name1.c_str(), &tag1_orig );
		self.GetTag( tag_name2.c_str(), &tag2_orig );

		// See if the enemy is in front of us

		dir = self.currentEnemy->origin - self.origin;
		angles = dir.toAngles();

		yaw_diff = AngleNormalize180( angles[YAW] - self.angles[YAW] );

		if ( yaw_diff < 60 && yaw_diff > -60 )
			{
			// The enemy is in front of us

			angles[YAW] += G_CRandom( random_angle );

			angles.AngleVectors( &end_pos1, NULL, NULL );
			end_pos1 *= 500;
			end_pos1 += tag1_orig;
			end_pos1.z -= z_offset;

			angles.AngleVectors( &end_pos2, NULL, NULL );
			end_pos2 *= 500;
			end_pos2 += tag1_orig;
			end_pos2.z -= z_offset;
			}
		else
			{
			// Get end position
			angles = self.angles;

			angles[YAW] += G_Random( random_angle ) - random_angle / 2;
			angles[PITCH] = 0;
			angles[ROLL] = 0;

			angles.AngleVectors( &end_pos1, NULL, NULL );
			end_pos1 *= 500;
			end_pos1 += tag1_orig;
			end_pos1.z -= z_offset;
			
			angles.AngleVectors( &end_pos2, NULL, NULL );
			end_pos2 *= 500;
			end_pos2 += tag1_orig;
			end_pos2.z -= z_offset;
			}

		trace = G_Trace( tag1_orig, Vector (-15, -15, -15), Vector (15, 15, 15), end_pos1, &self, MASK_SHOT, false, "ShockAttack" );

		if ( trace.fraction < 1.0 && trace.entityNum == self.currentEnemy->entnum )
			{
			end_pos1 = self.currentEnemy->centroid;
			dir = end_pos1 - tag1_orig;
			dir.normalize();
			self.currentEnemy->Damage( &self, &self, damage, vec_zero, dir, vec_zero, 0, 0, MOD_ELECTRIC );
			}

		// Add the beam
		beam1 = CreateBeam( NULL, beamShader.c_str(), tag1_orig, end_pos1, 20, 1.5f, 0.2f );

		trace = G_Trace( tag2_orig, Vector (-15, -15, -15), Vector (15, 15, 15), end_pos2, &self, MASK_SHOT, false, "ShockAttack" );

		if ( trace.fraction < 1.0 && trace.entityNum == self.currentEnemy->entnum )
			{
			end_pos2 = self.currentEnemy->centroid;
			dir = end_pos2 - tag2_orig;
			dir.normalize();
			self.currentEnemy->Damage( &self, &self, damage, vec_zero, dir, vec_zero, 0, 0, MOD_ELECTRIC );
			}

		// Add the beam
		beam2 = CreateBeam( NULL, beamShader.c_str(), tag2_orig, end_pos2, 20, 1.5f, 0.2f );

      already_started = true;
		}
	else if ( already_started )
		{
		self.GetTag( tag_name1.c_str(), &tag1_orig );
		self.GetTag( tag_name2.c_str(), &tag2_orig );

		if ( beam1 )
			beam1->setOrigin( tag1_orig );

		if ( beam2 )
			beam2->setOrigin( tag2_orig );
		}

	return true;
	}

void MultiShock::End
	(
	Actor &self
	)

	{
	if ( beam1 )
		{
		beam1->ProcessEvent( EV_Remove );
		beam1 = NULL;
		}
	
	if ( beam2 )
		{
		beam2->ProcessEvent( EV_Remove );
		beam2 = NULL;
		}
	}

/****************************************************************************

  ShockDown Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, ShockDown, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

ShockDown::ShockDown()
	{
	beam = NULL;
	damage = 10;
	already_started = false;	
	beamShader = "emap1";	
	}

void ShockDown::SetArgs
	(
	Event *ev
	)

	{
	tag_name = ev->GetString( 1 );
	beamShader = ev->GetString( 2 );

	if ( ev->NumArgs() > 3 )
      {
		damage = ev->GetInteger( 3 );
      }

	}

void ShockDown::Begin
	(
	Actor &self
	)

	{
	}

qboolean	ShockDown::Evaluate
	(
	Actor &self
	)

	{
	Vector tag_orig;
	Vector angles;
	Vector end_pos;
	trace_t  trace;
	Vector dir;
	
	


	if ( !self.currentEnemy )
		return false;

	if ( self.newanimnum == -1 && !already_started )
		{
		// Get tag position
		if ( tag_name.length() == 0 )
         {
			return false;
         }

		self.GetTag( tag_name.c_str(), &tag_orig );

		end_pos = self.origin;
		end_pos.z -= 10000;
		
		trace = G_Trace( tag_orig, Vector (-15, -15, -15), Vector (15, 15, 15), end_pos, &self, MASK_SHOT, false, "ShockAttack" );
		end_pos = trace.endpos;

		dir = end_pos - tag_orig;
		angles = dir.toAngles();

		if ( trace.fraction < 1.0 && trace.entityNum == self.currentEnemy->entnum )
			{
			end_pos = self.currentEnemy->centroid;
			dir = end_pos - tag_orig;
			dir.normalize();
			self.currentEnemy->Damage( &self, &self, damage, vec_zero, dir, vec_zero, 0, 0, MOD_ELECTRIC );
			}

		// Add the beam
		beam = CreateBeam( NULL, beamShader.c_str(), tag_orig, end_pos, 20, 1.5f, 0.2f );

      already_started = true;
		}
	else if ( already_started )
		{
		self.GetTag( tag_name.c_str(), &tag_orig );

		if ( beam )
			beam->setOrigin( tag_orig );
		}

	return true;
	}

void ShockDown::End
	(
	Actor &self
	)

	{
	if ( beam )
		{
		beam->ProcessEvent( EV_Remove );
		beam = NULL;
		}
	}
/****************************************************************************

  CircleAttack Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, CircleAttack, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

CircleAttack::CircleAttack()
	{
	}

void CircleAttack::SetArgs
	(
	Event *ev
	)

	{
	command   = ev->GetString( 1 );
	direction = ev->GetString( 2 );
	}

Actor *CircleAttack::FindClosestPart
	(
	Actor &self,
	float angle
	)
	{
	float closest_diff = 360;
	int i;
	part_t *part;
	Entity *partent;
	Actor *partact;
	Vector dir;
	Vector angles;
	float angle_diff;
	Actor *closest_part = NULL;

	for( i = 1 ; i <= self.parts.NumObjects(); i++ )
		{
		part = &self.parts.ObjectAt( i );

		partent = part->ent;
		partact = ( Actor * )partent;

		if ( partact && partact->part_name == "smallarm" )
			{
			dir = partact->origin - self.origin;
			angles = dir.toAngles();

			angle_diff = AngleDelta( angles[ YAW ], angle );

			if ( angle_diff < 0 )
            {
				angle_diff = -angle_diff;
            }

			if ( angle_diff < closest_diff )
				{
				closest_part = partact;
				closest_diff = angle_diff;
				}
			}
		}

	return closest_part;
	}

void CircleAttack::Begin
	(
	Actor &self
	)

	{
	float random_direction;
	Actor *closest_part;

	// Pick which arm to start with
	random_direction = G_Random( 360 );

	closest_part = FindClosestPart( self, random_direction );
	if ( closest_part != NULL )
		{
		first_part   = closest_part;
		current_part = closest_part;

		closest_part->command = command;
		next_time = level.time + 0.2f;
		}

	current_direction = 1;

	if ( direction == "counterclockwise" )
      {
		current_direction = 0;
      }

	number_of_attacks = 1;
	}

qboolean	CircleAttack::Evaluate
	(
	Actor &self
	)

	{
	Entity *current_part_entity;
	Actor *current_part_actor;
	Vector dir;
	Vector angles;
	Actor *closest_part;

	if ( level.time >= next_time )
		{
		current_part_entity = current_part;
		current_part_actor = ( Actor * )current_part_entity;

		// Find the next part

		dir = current_part_actor->origin - self.origin;
		angles = dir.toAngles();

		if ( direction == "changing" )
			{
			if ( number_of_attacks >= 20 )
            {
				return false;
            }

			if ( G_Random( 1 ) < .3 )
            {
				current_direction = !current_direction;
            }
			}

		if ( current_direction == 1 )
         {
			angles[YAW] -= 360 / 8;
         }
		else
         {
			angles[YAW] += 360 / 8;
         }

		closest_part = FindClosestPart( self, angles[YAW] );

		if ( ( closest_part == first_part ) && ( direction != "changing" ) )
         {
			return false;
         }

		current_part = closest_part;

		closest_part->command = command;
		next_time = level.time + 0.2f;

		number_of_attacks++;
		}

	return true;
	}

void CircleAttack::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  DragEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, DragEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void DragEnemy::SetArgs
	(
	Event *ev
	)

	{
	tag_name = ev->GetString( 1 );
	damage   = ev->GetInteger( 2 );

	if ( ev->NumArgs() > 2 )
		drop = ev->GetBoolean( 3 );
	else
		drop = false;
	}

void DragEnemy::Begin
	(
	Actor &self
	)

	{
	Actor *body;
	Vector dir;
	Vector angles;

	ent_to_drag = self.currentEnemy;

	attached = false;

	if ( damage > 0 && !drop )
      {
		ent_to_drag->Damage( &self, &self, damage, vec_zero, vec_zero, vec_zero, 0, 0, MOD_EAT );
      }

	body = self.FindPartActor( "body" );

	if ( body )
		{
		dir = body->origin - self.origin;
		angles = dir.toAngles();

		target_yaw = angles[ YAW ];
		last_turn_time = level.time;
		}
	else
		{
		target_yaw = self.angles[ YAW ];
		}
	}

qboolean	DragEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector orig;
	str anim_name;

	if ( ent_to_drag )
		{
		if ( drop && damage > 0 )
			{
			if ( self.GetTag( tag_name.c_str(), &orig ) )
				{
				if ( ent_to_drag->isClient() )
               {
					orig[ 2 ] -= 85;
               }
				else
					{
					offset[ 2 ] = ( ent_to_drag->absmin[ 2 ] - ent_to_drag->absmax[ 2 ] ) * 0.5f;

					if ( offset[ 2 ] < -40 )
                  {
						offset[ 2 ] -= 25;
                  }
					orig += offset;
					}

				ent_to_drag->setOrigin( orig );
				}

			ent_to_drag->Damage( &self, &self, damage, vec_zero, vec_zero, vec_zero, 0, 0, MOD_EAT );
			}

		if ( ent_to_drag->deadflag )
			return false;

		anim_name = self.animate->AnimName();

		if ( ( anim_name == "raise" ) && ( self.newanim == "" ) )
			{
			if ( !attached )
				{
				Event *ev;

				if ( damage > 0 )
					{
					if ( ent_to_drag->isClient() )
                  {
						offset[ 2 ] -= 85;
                  }
					else
						{
						offset[ 2 ] = ( ent_to_drag->absmin[ 2 ] - ent_to_drag->absmax[ 2 ] ) * 0.5f;

						if ( offset[ 2 ] < -40 )
                     {
							offset[ 2 ] -= 25;
                     }
						}

					ev = new Event( EV_Attach );
					ev->AddEntity( &self );
					ev->AddString( tag_name.c_str() );
					ev->AddInteger( qfalse );
					ev->AddVector( offset );
					ent_to_drag->ProcessEvent( ev );

					ent_to_drag->flags |= FL_PARTIAL_IMMOBILE;
					}

				attached = true;
				}

			if ( target_yaw != self.angles[ YAW ] )
				{
				float yaw_diff = target_yaw - self.angles[ YAW ];

				if ( yaw_diff > 180 )
					{
					target_yaw -= 360;
					yaw_diff -= 360;
					}

				if ( yaw_diff < -180 )
					{
					target_yaw += 360;
					yaw_diff += 360;
					}

				if ( yaw_diff < 0 )
					{
					self.angles[ YAW ] -= 90 * (level.time - last_turn_time);

					if ( self.angles[ YAW ] < 0 )
                  {
						self.angles[ YAW ] += 360;
                  }

					if ( self.angles[ YAW ] < target_yaw )
                  {
						self.angles[ YAW ] = target_yaw;
                  }

					self.setAngles( self.angles );
					}
				else if ( yaw_diff > 0 )
					{
					self.angles[ YAW ] += 90 * (level.time - last_turn_time);

					if ( self.angles[ YAW ] > 360 )
                  {
						self.angles[ YAW ] -= 360;
                  }

					if ( self.angles[ YAW ] > target_yaw )
                  {
						self.angles[ YAW ] = target_yaw;
                  }

					self.setAngles( self.angles );
					}

				last_turn_time = level.time;
				}
			}
		}

	return true;
	}

void DragEnemy::End
	(
	Actor &self
	)

	{
	Vector orig;
	Event *ev;
	trace_t trace;

	if ( drop || strcmp( self.currentState->getName(), "SUICIDE" ) == 0 )
		{
		ent_to_drag->flags &= ~FL_PARTIAL_IMMOBILE;

		ev = new Event( EV_Detach );
		ent_to_drag->ProcessEvent( ev );

		ent_to_drag->setSolidType( SOLID_BBOX );

		if ( self.GetTag( tag_name.c_str(), &orig ) )
			{
			trace = G_Trace( orig - Vector( "0 0 100" ), ent_to_drag->mins, ent_to_drag->maxs, orig, ent_to_drag, ent_to_drag->edict->clipmask, false, "DragEnemy" );

			if ( trace.allsolid )
				gi.WDPrintf( "Dropping entity into a solid!\n" );

			ent_to_drag->setOrigin( trace.endpos );

			/* if ( ent_to_drag->isClient() )
            {
				offset[2] = -85;
            }
			else
				{
				offset[2] = ( ent_to_drag->absmin[2] - ent_to_drag->absmax[2] ) * 0.5;

				if ( offset[2] < -40 )
               {
					offset[2] -= 25;
               }
				}

			ent_to_drag->setOrigin( orig + offset ); */
			}
		}

	ent_to_drag->velocity = "0 0 -20";
	}


/****************************************************************************

  PickupEnemy Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, PickupEnemy, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void PickupEnemy::SetArgs
	(
	Event *ev
	)

	{
	tag_name = ev->GetString( 1 );
	damage   = ev->GetInteger( 2 );

	if ( ev->NumArgs() > 2 )
		drop = ev->GetBoolean( 3 );
	else
		drop = false;
	}

void PickupEnemy::Begin
	(
	Actor &self
	)

	{
	Actor *body;
	Vector dir;
	Vector angles;

	ent_to_drag = self.currentEnemy;

	attached = false;

	if ( damage > 0 && !drop )
      {
		ent_to_drag->Damage( &self, &self, damage, vec_zero, vec_zero, vec_zero, 0, 0, MOD_EAT );
      }

	body = self.FindPartActor( "body" );

	if ( body )
		{
		dir = body->origin - self.origin;
		angles = dir.toAngles();

		target_yaw = angles[ YAW ];
		last_turn_time = level.time;
		}
	else
		{
		target_yaw = self.angles[ YAW ];
		}
	}

qboolean	PickupEnemy::Evaluate
	(
	Actor &self
	)

	{
	Vector orig;
	str anim_name;

	if ( ent_to_drag )
		{
		if ( drop && damage > 0 )
			{
			if ( self.GetTag( tag_name.c_str(), &orig ) )
				{
				if ( ent_to_drag->isClient() )
               {
					orig[ 2 ] -= 85;
               }
				else
					{
					offset[ 2 ] = ( ent_to_drag->absmin[ 2 ] - ent_to_drag->absmax[ 2 ] ) * 0.5f;

					if ( offset[ 2 ] < -40 )
                  {
						offset[ 2 ] -= 25;
                  }
					orig += offset;
					}

				ent_to_drag->setOrigin( orig );
				}

			ent_to_drag->Damage( &self, &self, damage, vec_zero, vec_zero, vec_zero, 0, 0, MOD_EAT );
			}

		if ( ent_to_drag->deadflag )
			return false;

		anim_name = self.animate->AnimName();

		if ( !attached )
			{
			Event *ev;

			if ( damage > 0 )
				{
				if ( ent_to_drag->isClient() )
               {
					offset[ 2 ] -= 85;
               }
				else
					{
					offset[ 2 ] = ( ent_to_drag->absmin[ 2 ] - ent_to_drag->absmax[ 2 ] ) * 0.5f;

					if ( offset[ 2 ] < -40 )
                  {
			         offset[ 2 ] -= 25;
                  }
					}

				ev = new Event( EV_Attach );
				ev->AddEntity( &self );
				ev->AddString( tag_name.c_str() );
				ev->AddInteger( qfalse );
				ev->AddVector( offset );
				ent_to_drag->ProcessEvent( ev );

				ent_to_drag->flags |= FL_PARTIAL_IMMOBILE;
				}

			attached = true;
			}

		if ( target_yaw != self.angles[ YAW ] )
			{
			float yaw_diff = target_yaw - self.angles[ YAW ];

			if ( yaw_diff > 180 )
				{
				target_yaw -= 360;
				yaw_diff -= 360;
				}

			if ( yaw_diff < -180 )
				{
				target_yaw += 360;
				yaw_diff += 360;
				}

			if ( yaw_diff < 0 )
				{
				self.angles[ YAW ] -= 90 * (level.time - last_turn_time);

				if ( self.angles[ YAW ] < 0 )
               {
					self.angles[ YAW ] += 360;
               }

				if ( self.angles[ YAW ] < target_yaw )
               {
					self.angles[ YAW ] = target_yaw;
               }

				self.setAngles( self.angles );
				}
				else if ( yaw_diff > 0 )
				{
				self.angles[ YAW ] += 90 * (level.time - last_turn_time);

				if ( self.angles[ YAW ] > 360 )
               {
					self.angles[ YAW ] -= 360;
               }

					if ( self.angles[ YAW ] > target_yaw )
                  {
						self.angles[ YAW ] = target_yaw;
                  }

					self.setAngles( self.angles );
				}

				last_turn_time = level.time;
			}
		}
		

	return true;
	}

void PickupEnemy::End
	(
	Actor &self
	)

	{
	Vector orig;
	Event *ev;
	trace_t trace;

	if ( drop || strcmp( self.currentState->getName(), "SUICIDE" ) == 0 )
		{
		ent_to_drag->flags &= ~FL_PARTIAL_IMMOBILE;

		ev = new Event( EV_Detach );
		ent_to_drag->ProcessEvent( ev );

		ent_to_drag->setSolidType( SOLID_BBOX );

		if ( self.GetTag( tag_name.c_str(), &orig ) )
			{
			trace = G_Trace( orig - Vector( "0 0 100" ), ent_to_drag->mins, ent_to_drag->maxs, orig, ent_to_drag, ent_to_drag->edict->clipmask, false, "DragEnemy" );

			if ( trace.allsolid )
				gi.WDPrintf( "Dropping entity into a solid!\n" );

			ent_to_drag->setOrigin( trace.endpos );

			/* if ( ent_to_drag->isClient() )
            {
				offset[2] = -85;
            }
			else
				{
				offset[2] = ( ent_to_drag->absmin[2] - ent_to_drag->absmax[2] ) * 0.5;

				if ( offset[2] < -40 )
               {
					offset[2] -= 25;
               }
				}

			ent_to_drag->setOrigin( orig + offset ); */
			}
		}

	ent_to_drag->velocity = "0 0 -20";
	}

/****************************************************************************

  Teleport Class Definition

****************************************************************************/

#define TELEPORT_BEHIND   0
#define TELEPORT_TOLEFT   1
#define TELEPORT_TORIGHT  2
#define TELEPORT_INFRONT  3

#define TELEPORT_NUMBER_OF_POSITIONS  4

CLASS_DECLARATION( Behavior, Teleport, NULL )
	{
		{ NULL, NULL }
	};


void Teleport::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void Teleport::Begin
	(
	Actor &self
	)

	{

	}

qboolean	Teleport::TestPosition
	(
	Actor &self,
	int test_pos,
	Vector &good_position,
	qboolean	use_enemy_dir
	)
	{
	Vector test_position;
	Vector enemy_angles;
	Vector enemy_forward;
	Vector enemy_left;
	trace_t trace;


	// Get the position to test

	if ( use_enemy_dir )
		{
		// Get the enemy direction info

		enemy_angles = self.currentEnemy->angles;
		enemy_angles.AngleVectors( &enemy_forward, &enemy_left );

		test_position = self.currentEnemy->origin;

		if ( test_pos == TELEPORT_BEHIND )
			test_position -= enemy_forward * 135;
		else if ( test_pos == TELEPORT_INFRONT )
			test_position += enemy_forward * 135;
		else if ( test_pos == TELEPORT_TOLEFT )
			test_position += enemy_left * 135;
		else
			test_position -= enemy_left * 135;
		}
	else
		{
		test_position = self.currentEnemy->origin;

		if ( test_pos == TELEPORT_BEHIND )
			test_position += "-110 0 0";
		else if ( test_pos == TELEPORT_INFRONT )
			test_position += "110 0 0";
		else if ( test_pos == TELEPORT_TOLEFT )
			test_position += "0 -110 0";
		else
			test_position += "0 110 0";
		}

	//test_position += "0 0 16";
	test_position += "0 0 64";

	// Test to see if we can fit at the new position

	trace = G_Trace( test_position, self.mins, self.maxs, test_position - Vector( "0 0 1000" ), &self, self.edict->clipmask, false, "Teleport::TestPosition" );

	if ( trace.allsolid || trace.startsolid )
	//if ( trace.allsolid )
		return false;

	// Make sure we can see the enemy from this position

	//if ( !self.CanSeeEnemyFrom( trace.endpos ) )
	if ( !self.IsEntityAlive( self.currentEnemy ) || !self.CanSeeFrom( Vector( trace.endpos ), self.currentEnemy ) )
		return false;

	// This is a good position

	good_position = trace.endpos;
	return true;
	}

qboolean	Teleport::Evaluate
	(
	Actor &self
	)

	{
	int current_position;
	float random_number;
	Vector teleport_position;
	qboolean teleport_position_found;
	Vector new_position;
	int i;
	Vector dir;
	Vector angles;


	// Make sure we stll have an enemy to teleport near

	if ( !self.currentEnemy )
		return false;

	// Default the teleport position to where we are now

	teleport_position = self.origin;
	teleport_position_found = false;

	// Determine which position to try first

	random_number = G_Random();

	if ( random_number < .5 )
		current_position = TELEPORT_BEHIND;
	else if ( random_number < .7 )
		current_position = TELEPORT_TOLEFT;
	else if ( random_number < .9 )
		current_position = TELEPORT_TORIGHT;
	else
		current_position = TELEPORT_INFRONT;

	// Try positions

	for( i = 0 ; i < TELEPORT_NUMBER_OF_POSITIONS ; i++ )
		{
		// Test this position

		if ( TestPosition( self, current_position, new_position, true ) )
			{
			teleport_position = new_position;
			teleport_position_found = true;
			break;
			}

		// Try the next position

		current_position++;

		if ( current_position >= TELEPORT_NUMBER_OF_POSITIONS )
			current_position = 0;
		}

	if ( !teleport_position_found )
		{
		// Try again with not using the enemies angles

		if ( current_position >= TELEPORT_NUMBER_OF_POSITIONS )
			current_position = 0;

		for( i = 0 ; i < TELEPORT_NUMBER_OF_POSITIONS ; i++ )
			{
			// Test this position

			if ( TestPosition( self, current_position, new_position, false ) )
				{
				teleport_position = new_position;
				teleport_position_found = true;
				break;
				}

			// Try the next position

			current_position++;

			if ( current_position >= TELEPORT_NUMBER_OF_POSITIONS )
				current_position = 0;
			}
		}

	// Do teleport stuff

	if ( teleport_position_found )
		{
		self.setOrigin( teleport_position );
		self.NoLerpThisFrame();

		dir = self.currentEnemy->origin - teleport_position;
		angles = dir.toAngles();

		angles[ROLL] = 0;
		angles[PITCH] = 0;

		self.setAngles( angles );

		if ( self.currentEnemy->isSubclassOf( Player ) )
			{
			Player *player = (Player *)(Entity *)self.currentEnemy;

			player->RemoveTarget( &self );
			}
		}

	return false;
	}

void Teleport::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  TeleportToPlayer Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, TeleportToPlayer, NULL )
	{
		{ NULL, NULL }
	};


void TeleportToPlayer::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void TeleportToPlayer::Begin
	(
	Actor &self
	)

	{

	}

qboolean	TeleportToPlayer::TestPosition
	(
	Actor &self,
	int test_pos,
	Vector &good_position,
	Entity* player,
	qboolean	use_player_dir
	)
	{
	Vector test_position;
	Vector player_angles;
	Vector player_forward;
	Vector player_left;
	trace_t trace;


	// Get the position to test
	test_position = player->origin;
	
	if ( use_player_dir )
		{
		// Get the player direction info

		player_angles = player->angles;
		player_angles.AngleVectors( &player_forward, &player_left );
		
		// Check Behind the Player
		test_position -= player_forward * 75;

		}
	else
		{
		
		// Check Behind the Player
		test_position += "-60 0 0";
		}

	// Final Tweaking
	test_position += "0 0 64";

	// Test to see if we can fit at the new position

	trace = G_Trace( test_position, self.mins, self.maxs, test_position - Vector( "0 0 1000" ), &self, self.edict->clipmask, false, "Teleport::TestPosition" );

	if ( trace.allsolid || trace.startsolid )
		return false;

	// Make sure we can see the Player from this position

	if ( !self.IsEntityAlive( player ) || !self.CanSeeFrom( Vector( trace.endpos ), player ) )
		return false;

	// This is a good position

	good_position = trace.endpos;
	return true;
	}

qboolean	TeleportToPlayer::Evaluate
	(
	Actor &self
	)

	{
	int current_position;
	Vector teleport_position;
	qboolean teleport_position_found;
	Vector new_position;
	int i;
	Vector dir;
	Vector angles;
	
	Player* player = 0;
	// Make sure the player is alive and well
	for(i = 0; i < game.maxclients; i++)
		{
		player = GetPlayer(i);		
		
		// don't target while player is not in the game or he's in notarget
		if( !player || ( player->flags & FL_NOTARGET ) )
			{
			return false;
			}
		}
	
	// Default the teleport position to where we are now

	teleport_position = self.origin;
	teleport_position_found = false;

	// Always teleport BEHIND the player - - we don't want him to see us pop in.
	current_position = TELEPORT_BEHIND;

	// Test this position
	if ( TestPosition( self, current_position, new_position, player, true ) )
		{
		teleport_position = new_position;
		teleport_position_found = true;
		}
	else
		{
			if ( TestPosition( self, current_position, new_position, player, false ) )
				{
				teleport_position = new_position;
				teleport_position_found = true;
				}
		}

	// Do teleport stuff
	if ( teleport_position_found )
		{
		self.setOrigin( teleport_position );
		self.NoLerpThisFrame();

		dir = player->origin - teleport_position;
		angles = dir.toAngles();

		angles[ROLL] = 0;
		angles[PITCH] = 0;

		self.setAngles( angles );
		}

	return false;
	}

void TeleportToPlayer::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  TeleportToPosition Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, TeleportToPosition, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void TeleportToPosition::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void TeleportToPosition::SetArgs
	(
	Event *ev
	)

	{
	teleport_position_name = ev->GetString( 1 );
	number_of_teleport_positions = ev->GetInteger( 2 );
	}

void TeleportToPosition::Begin
	(
	Actor &self
	)

	{
	}

qboolean	TeleportToPosition::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	Vector angles;
	trace_t trace;
	str pathnode_name;
	PathNode *goal;
	Vector teleport_position;
	Vector attack_position;
	float half_height;
	Entity *effect;


	// Get the pathnode name to teleport to

	pathnode_name = teleport_position_name;
	pathnode_name += (int)( G_Random( number_of_teleport_positions ) + 1 );

	// Find the path node

	goal = AI_FindNode( pathnode_name );

	if ( !goal )
		{
		gi.WDPrintf( "Can't find position %s\n", pathnode_name.c_str() );
		return false;
		}

	// Set the teleport position

	teleport_position = goal->origin;

	// Kill anything at this position

	half_height = self.maxs.z / 2;
	attack_position = teleport_position;
	attack_position.z += half_height;

	MeleeAttack( attack_position, attack_position, 10000, &self, MOD_TELEFRAG, self.maxs.x, -half_height, half_height, 0 );

	// Test to see if we can fit at the new position

	trace = G_Trace( teleport_position + Vector( "0 0 64" ), self.mins, self.maxs, teleport_position - Vector( "0 0 128" ), &self, MASK_PATHSOLID, false, "TeleportToPosition" );
	//trace = G_Trace( teleport_position, self.mins, self.maxs, teleport_position, &self, MASK_PATHSOLID, false, "TeleportToPosition" );

	if ( trace.allsolid )
		{
		gi.WDPrintf( "Failed to teleport to %s\n", goal->targetname.c_str() );
		return false;
		}

	teleport_position = trace.endpos;

	// Do teleport stuff

	// Spawn in teleport effect at old position

	effect = new Entity( ENTITY_CREATE_FLAG_ANIMATE );
	effect->setModel( "fx_teleport3.tik" );
	effect->setOrigin( self.origin );
	effect->setScale( 2 );
	effect->setSolidType( SOLID_NOT );
	effect->animate->RandomAnimate( "idle", EV_Remove );
	//effect->Sound( "snd_teleport" );

	// Set new position

	self.setOrigin( teleport_position );

	// Spawn in teleport effect at new position

	effect = new Entity( ENTITY_CREATE_FLAG_ANIMATE );
	effect->setModel( "fx_teleport3.tik" );
	effect->setOrigin( self.origin );
	effect->setScale( 2 );
	effect->setSolidType( SOLID_NOT );
	effect->animate->RandomAnimate( "idle", EV_Remove );
	//effect->Sound( "snd_teleport" );

	self.NoLerpThisFrame();

	if ( self.currentEnemy )
		{
		dir = self.currentEnemy->origin - teleport_position;
		angles = dir.toAngles();

		angles[ROLL] = 0;
		angles[PITCH] = 0;

		self.setAngles( angles );

		if ( self.currentEnemy->isSubclassOf( Player ) )
			{
			Player *player = (Player *)(Entity *)self.currentEnemy;

			player->RemoveTarget( &self );
			}
		}

	return false;
	}

void TeleportToPosition::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************

  GhostAttack Class Definition

****************************************************************************/

#define GHOST_ATTACK_START  0
#define GHOST_ATTACK_END    1

#define GHOST_ATTACK_SPEED  350

CLASS_DECLARATION( Behavior, GhostAttack, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void GhostAttack::SetArgs
	(
	Event *ev
	)

	{
	real_attack = ev->GetBoolean( 1 );
	}


void GhostAttack::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void GhostAttack::Begin
	(
	Actor &self
	)

	{
	mode = GHOST_ATTACK_START;

	fly.Begin( self );
	fly.SetTurnSpeed( 25 );
	fly.SetRandomAllowed( false );
	fly.SetSpeed( GHOST_ATTACK_SPEED );

	if ( self.currentEnemy )
		attack_position = self.currentEnemy->centroid;	
	else
		attack_position = self.origin;

	if ( !real_attack )
		{
		attack_position[0] += G_CRandom( 300 );
		attack_position[1] += G_CRandom( 300 );
		attack_position[2] += G_Random( 100 );
		}

	fly.SetGoalPoint( attack_position );

	attack_dir = attack_position - self.origin;

	if ( attack_dir == vec_zero )
		attack_dir = "1 1 0";

	attack_dir.normalize();

	self.Sound( "snd_fadein", CHAN_VOICE );
	}

qboolean	GhostAttack::Evaluate
	(
	Actor &self
	)

	{
	Vector dir;
	float dist;
	float zdist;
	Vector new_pos;
	float new_alpha;
	float light_radius;
	float r, g, b;
	qboolean success;
	Vector start;
	Vector end;
	Event *event;


	if ( !self.currentEnemy )
		return false;

	if ( mode == GHOST_ATTACK_START )
		{
		// Move closer to the enemy

		fly.Evaluate( self );

		// Get the new distance info

		dir = attack_position - self.origin;

		dist = dir.length();

		zdist = dir.z;

		if ( zdist < 0 )
			zdist = -zdist;

		dir.z = 0;

		// If we are close enough change to shootable_only

		if ( real_attack && dist < 200 )
			{
			// Attackable now

			self.setSolidType( SOLID_BBOX );
			self.setContents( CONTENTS_SHOOTABLE_ONLY );

			event = new Event( EV_Actor_SetTargetable );
			event->AddInteger( 1 );
			self.ProcessEvent( event );
			}

		// If we are close enough damage enemy and goto end mode

		start = self.origin;
		end   = self.origin + attack_dir * 1;

		if ( real_attack )
			{
			success = MeleeAttack( start, end, 7.5, &self, MOD_LIFEDRAIN, 32, 0, 64, 0 );
			self.AddStateFlag( STATE_FLAG_MELEE_HIT );
			}
		else
			success = false;

		if ( success || dist <= GHOST_ATTACK_SPEED / 40 )
			{
			// Attack mode is done go to retreat mode

			if ( self.attack_blocked && self.attack_blocked_time == level.time )
				{
				Vector retreat_angles;

				dir = attack_dir * -1;

				retreat_angles = dir.toAngles();
				retreat_angles[YAW] += G_CRandom( 45 );
				retreat_angles[PITCH] += G_CRandom( 30 );
				retreat_angles.AngleVectors( &dir );

				dir *= 500;

				self.setAngles( retreat_angles );
				}
			else
				{
				dir = attack_dir;

				dir.z = 0;
				dir.normalize();
				dir *= 1000;
				dir.z = 300;
				}

			retreat_position = self.origin + dir;

			fly.SetGoalPoint( retreat_position );

			mode = GHOST_ATTACK_END;
			}

		// Fade in depending on how close we are to attack position

		if ( dist > 400 )
			new_alpha = 0;
		else
			new_alpha = ( 400 - dist ) / 400;

		if ( new_alpha > 0.4 )
			new_alpha = 0.4;

		r = new_alpha / 0.4;
		g = new_alpha / 0.4;
		b = new_alpha / 0.4;

		light_radius = 0;

		G_SetConstantLight( &self.edict->s.constantLight, &r, &g, &b, &light_radius );

		self.setAlpha( new_alpha );
		}
	else
		{
		// Move away from enemy

		fly.Evaluate( self );

		// Get the new distance info

		dir = attack_position - self.origin;
		dist = dir.length();

		if ( real_attack && dist > 200 )
			{
			// Not attackable again

			self.setSolidType( SOLID_NOT );
			self.setContents( 0 );

			event = new Event( EV_Actor_SetTargetable );
			event->AddInteger( 0 );
			self.ProcessEvent( event );
			}

		// Fade out depending on how far we are from the attack position

		if ( dist > 400 )
			new_alpha = 0;
		else
			new_alpha = ( 400 - dist ) / 400;

		if ( new_alpha > 0.4 )
			new_alpha = 0.4;

		r = new_alpha / 0.4;
		g = new_alpha / 0.4;
		b = new_alpha / 0.4;

		light_radius = 0;

		G_SetConstantLight( &self.edict->s.constantLight, &r, &g, &b, &light_radius );

		self.setAlpha( new_alpha );

		// See if we are far enough to be done

		if ( new_alpha == 0 )
			return false;
		}
	return true;
	}

void GhostAttack::End
	(
	Actor &self
	)

	{
	// Make sure we can't be shot any more

	self.setSolidType( SOLID_NOT );
	self.setContents( 0 );

	fly.End( self );
	}

/****************************************************************************

  Levitate Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, Levitate, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

void Levitate::SetArgs
	(
	Event *ev
	)

	{
	distance = ev->GetFloat( 1 );
	speed = ev->GetFloat( 2 );
	}


void Levitate::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void Levitate::Begin
	(
	Actor &self
	)

	{
	final_z = self.origin.z + distance;
	}

qboolean	Levitate::Evaluate
	(
	Actor &self
	)

	{
	trace_t trace;
	Vector start;
	Vector end;


	start = self.origin;
	end   = self.origin;

	if ( final_z < self.origin.z )
		{
		end.z -= speed;

		if ( end.z < final_z )
			end.z = final_z;
		}
	else
		{
		end.z += speed;

		if ( end.z > final_z )
			end.z = final_z;
		}

	trace = G_Trace( start, self.mins, self.maxs, end, &self, self.edict->clipmask, false, "Levitate" );

	if ( trace.fraction != 1 )
		return false;

	if ( end.z == final_z )
		return false;

	self.setOrigin( trace.endpos );

	return true;
	}

void Levitate::End
	(
	Actor &self
	)

	{
	}

/****************************************************************************
*****************************************************************************

  Utility functions

*****************************************************************************
****************************************************************************/



Vector ChooseRandomDirection
   (
   Actor &self,
   const Vector &previousdir,
   float *time,
   int disallowcontentsmask,
   qboolean usepitch
   )
   {
   //static float x[ 9 ] = { 0, 22, -22, 45, -45, 0, 22, -22, 45 };
	static float x[ 9 ] = { 0, 22, -22, 0, 22 };
   Vector dir;
   Vector ang;
   Vector bestdir;
   Vector newdir;
   Vector step;
	Vector endpos;
	Vector groundend;
   float bestfraction;
   trace_t trace;
	trace_t groundtrace;
   int i;
   int k;
   int t;
   int u;
   int contents;
   Vector centroid;
	float random_yaw;
	float movespeed;

	if ( self.movespeed != 1 )
		movespeed = self.movespeed;
	else
		movespeed = 100;

   centroid = self.centroid - self.origin;

	step = Vector( 0, 0, STEPSIZE );
   bestfraction = -1;
   bestdir = self.origin;

	random_yaw = G_Random( 360 );

   for( i = 0; i <= 8; i++ )
      {
      t = random_yaw + i * 45;

      ang.y = self.angles.y + t;

      if ( usepitch )
         {
         u = ( int )G_Random( 5 );

         //for( k = 0; k < 5; k++ )
			for( k = 0; k < 3; k++ )
            {
            ang.x = x[ k + u ];
            ang.AngleVectors( &dir, NULL, NULL );

            dir *= movespeed * (*time);
            dir += self.origin;
            trace = G_Trace( self.origin, self.mins, self.maxs, dir, &self, self.edict->clipmask, false, "ChooseRandomDirection 1" );

            if ( !trace.startsolid && !trace.allsolid )
               {
               newdir = Vector( trace.endpos );

					if ( disallowcontentsmask )
						{
						contents = gi.pointcontents( ( newdir + centroid ), 0 );

						if ( contents & disallowcontentsmask )
							continue;
						}

               if (
                     ( trace.fraction > bestfraction ) &&
                     ( newdir != bestdir ) &&
                     ( newdir != previousdir )
                  )
                  {
                  bestdir = newdir;
                  bestfraction = trace.fraction;

						if ( bestfraction > .9 )
							{
							*time *= bestfraction;

							return bestdir;
							}
                  }
               }
            }
         }
      else
         {
         ang.x = 0;
         ang.AngleVectors( &dir, NULL, NULL );

			endpos = self.origin + dir * movespeed * (*time) + step;

         trace = G_Trace( self.origin + step, self.mins, self.maxs, endpos, &self, self.edict->clipmask, false, "ChooseRandomDirection 2" );

         if ( !trace.startsolid && !trace.allsolid )
            {
            newdir = Vector( trace.endpos );

            if ( disallowcontentsmask )
               {
               contents = gi.pointcontents( ( newdir + centroid ), 0 );

					if ( contents & disallowcontentsmask )
						continue;
					}

            if (
                  ( trace.fraction > bestfraction ) &&
                  ( newdir != bestdir ) &&
                  ( newdir != previousdir )
               )
               {
					groundend = endpos - step * 2;

					groundtrace = G_Trace( endpos, self.mins, self.maxs, groundend, &self, self.edict->clipmask, false, "Chase::ChooseRandomDirection 3" );

					if ( groundtrace.fraction == 1 )
						trace.fraction /= 2;

					if ( trace.fraction > bestfraction )
						{
						bestdir = newdir;
						bestfraction = trace.fraction;

						if ( bestfraction > .9 )
							{
							*time *= bestfraction;

							return bestdir;
							}
						}
               }
            }
         }
      }

   if ( bestfraction > 0 )
      {
      *time *= bestfraction;
      }
   else
      {
      *time = 0;
      }

   return bestdir;
   }


//
// WayPoint Stuff
//
/****************************************************************************

  GotoWayPoint Class Definition

****************************************************************************/

CLASS_DECLARATION( Behavior, GotoWayPoint, NULL )
	{
		{ &EV_Behavior_Args,			       SetArgs          },
		{ NULL, NULL }
	};

void GotoWayPoint::SetArgs
	(
	Event *ev
	)

	{
	path_name = ev->GetString( 1 );
	anim = ev->GetString( 2 );
	current_waypoint_name = path_name;
	current_waypoint = NULL;
	}

void GotoWayPoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );

   gi.Printf( "\nchase:\n" );
   chase.ShowInfo( self );
	}

void GotoWayPoint::Begin
	(
	Actor &self
	)

	{
	if ( !anim.length() )
      {
		anim = "run";
      }

	if ( anim != self.animname || self.newanim.length() )
      {
		self.SetAnim( anim );
      }

	chase.UseNearestNode( false );
	chase.Begin( self );	

	next_think_time = 0;
	}

qboolean	GotoWayPoint::Evaluate
	(
	Actor &self
	)

	{
	//First Check if we are at a way point;
	Vector dest;
	Vector check;
	
	if (!current_waypoint)
		{
		current_waypoint = GetWayPoint( current_waypoint_name );
		if (!current_waypoint)
			return false;
		}
	
	dest = current_waypoint->origin;
	check = dest - self.origin;

	// Check if we're close enough
	if ( check.length() < 25 )
		{
		// Run Our Thread
		str waypointThread;
		waypointThread = current_waypoint->GetThread();

		if (waypointThread.length() )
			self.RunThread( waypointThread );

      // See if we have another point to go to
		if ( current_waypoint->target.length() == 0 )
			{
			return false;
			}

		// Check for new anim
		anim = "";
		anim = current_waypoint->GetActorAnim();
		
		if ( anim.length() )
			self.SetAnim( anim );			
		
		// Go To the Next Point
		current_waypoint_name = current_waypoint->target;
		current_waypoint = GetWayPoint( current_waypoint_name );		

		if (!current_waypoint)
			return false;

		dest = current_waypoint->origin;

		//Clear out anim strings
		anim = "";		
	
			
		}

	chase.SetTarget( current_waypoint );
	chase.Evaluate(self);
   return true;
	}

void GotoWayPoint::End
	(
	Actor &self
	)

	{
	chase.End( self );		
	}

WayPointNode* GotoWayPoint::GetWayPoint
   (
	const str &waypoint_name
	)

	{
	Entity* ent_in_range;
	gentity_t *ed;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			if (!Q_stricmp(ent_in_range->targetname.c_str() , waypoint_name.c_str() ))
				{
				return (WayPointNode*)ent_in_range;
				}
			}
		}
	
	return NULL;
	}

/****************************************************************************

  FlyCircleAroundWaypoint Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, FlyCircleAroundWaypoint, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

FlyCircleAroundWaypoint::FlyCircleAroundWaypoint()
	{
	anim = "fly";	
	nearestPlayer = false;

	}

void FlyCircleAroundWaypoint::SetArgs
	(
	Event *ev
	)

	{
   anim = ev->GetString( 1 );
	fly_clockwise = ev->GetBoolean( 2 );
	waypointname = ev->GetString( 3 );
	
   if (ev->NumArgs() > 3 )
		fly.SetSpeed( ev->GetFloat( 4 ) );

   if (ev->NumArgs() > 4 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 5 ) );
	
	if ( !Q_stricmp(waypointname.c_str() , "player" ) )
		nearestPlayer = true;
	
	}

void FlyCircleAroundWaypoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void FlyCircleAroundWaypoint::Begin
	(
	Actor &self
	)

	{
	original_z = self.origin.z;

	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( 5.0 );
	}

qboolean	FlyCircleAroundWaypoint::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	trace_t trace;
	Vector dir;
	Vector angle;
	Vector left;
	qboolean too_far = false;
	Vector new_dir;
	Vector fly_dir;
	WayPointNode *goalNode;
	
	
	goalNode = NULL;
	if ( !self.IsEntityAlive( self.currentEnemy ) )
      {
      return false;
      }

	if ( self.lastmove == STEPMOVE_OK )
		{
		fly.SetTurnSpeed( 5.0 );
		
		if ( nearestPlayer )
			goalNode = GetWayPointNearestPlayer( self );
		else
			goalNode = GetWayPoint( self );

		if ( !goalNode )
			return false;
		
		dir = goalNode->origin - self.origin;
		dir.z = 0;

   	if ( dir.length() > 200 ) //radius
			{
			too_far = true;
			}


		angle = dir.toAngles();
		angle.AngleVectors( NULL, &left, NULL );

		if ( fly_clockwise )
			fly_dir = left;
		else
			fly_dir = left * -1;

		dir.normalize();

		if ( too_far )
			{
			new_dir = fly_dir * 0.5 + dir * 0.5;
			new_dir.normalize();
			}
		else
			{
			new_dir = fly_dir;
			}

		goal = self.origin + new_dir * 200;

		trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyCircle" );

		if ( trace.fraction < 1 )
			{
			if ( too_far )
				trace.fraction /= 2;

			new_dir = fly_dir * trace.fraction + dir * (1 - trace.fraction);
			new_dir.normalize();
   		goal = self.origin + new_dir * 200;
			}
		else
			{
			goal = trace.endpos;
			}

		fly.SetGoalPoint( goal );
		}
	else
		{
		fly.SetTurnSpeed( 20.0 );
		}

	fly.Evaluate( self );

	return true;
	}

WayPointNode *FlyCircleAroundWaypoint::GetWayPoint( Actor &self )
	{
	Entity* ent_in_range;
	gentity_t *ed;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			if (!Q_stricmp(ent_in_range->targetname.c_str() , waypointname.c_str() ))
				{
				return (WayPointNode*)ent_in_range;
				}
			}
		}
	
	return NULL;
	}

WayPointNode *FlyCircleAroundWaypoint::GetWayPointNearestPlayer( Actor &self)
	{
	Vector DistanceFromPlayer;
	float distance;
	Entity* ent_in_range;
	Entity* best_ent;

	gentity_t *ed;
	
	ent_in_range = NULL;
	best_ent = NULL;
	distance = 100000000;
	
	if ( !self.currentEnemy ) return NULL;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			DistanceFromPlayer = ent_in_range->origin - self.currentEnemy->origin;
			if (DistanceFromPlayer.length() < distance )
				{
				best_ent = ent_in_range;
				distance = DistanceFromPlayer.length();
				}
			}
		}
	
	return (WayPointNode*)best_ent;
	}

void FlyCircleAroundWaypoint::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}

/****************************************************************************

  HelicopterFlyToPoint Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, HelicopterFlyToPoint, NULL )
	{
		{ NULL, NULL }
	};

HelicopterFlyToPoint::HelicopterFlyToPoint()
	{
	turn_speed = 10.0;
	old_turn_speed = turn_speed;
	speed = 480.0;
	random_allowed = true;
	force_goal = false;
	adjustYawAndRoll = true;
	offsetOrigin = false;
	}

void HelicopterFlyToPoint::SetTurnSpeed( float new_turn_speed )
	{
	turn_speed = new_turn_speed;
	}

void HelicopterFlyToPoint::SetGoalPoint( const Vector &goal_point )
	{
	if ( goal_point != goal )
		avoidtime = 0;

	goal = goal_point;
	}

void HelicopterFlyToPoint::SetRandomAllowed( qboolean allowed )
	{
	random_allowed = allowed;
	}

void HelicopterFlyToPoint::SetSpeed( float speed_value )
	{
	speed = speed_value;
	}

void HelicopterFlyToPoint::ForceGoal( void )
	{
	force_goal = true;
	}

void HelicopterFlyToPoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HelicopterFlyToPoint::Begin
	(
	Actor &self
	)

	{
   avoidtime = 0;
	old_forward_speed = self.forwardspeed;
	stuck = 0;
	use_temp_goal = false;
	}

qboolean	HelicopterFlyToPoint::Evaluate
	(
	Actor &self
	)

	{
   trace_t trace;
   Vector dir;
   Vector ang;
	float time;
	float length;
	float old_yaw;
	float old_pitch;
	
	float x_offset = 0;
	float y_offset = 0;
	float z_offset = 0;


   if (offsetOrigin)
		{
   	x_offset = self.centroid.x - self.origin.x;
   	y_offset = self.centroid.y - self.origin.y;
	   z_offset = self.centroid.z - self.origin.z;
		
		self.origin.x+=x_offset;
	   self.origin.y+=y_offset;
	   //self.origin.z+=z_offset;
		}

	if ( self.lastmove != STEPMOVE_OK )
		stuck++;
	else
		stuck = 0;
	
	if ( stuck > 1 || ( avoidtime <= level.time ) )
      {
		time = G_Random( .3 ) + .3;

		use_temp_goal = false;

		if ( !force_goal )
			{
			trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyToPoint" );
						
			if ( trace.fraction < 0.5f || stuck > 2 )
				{
				old_turn_speed = self.turnspeed;
			   self.turnspeed = 60;
				temp_goal = ChooseRandomDirection( self, goal, &time, MASK_WATER, false );
				self.turnspeed = old_turn_speed;
				use_temp_goal = true;
				avoidtime = level.time + time;

				stuck = 0;
				}
			else
				{
				goal = trace.endpos;
				avoidtime = level.time + time;
				}
			}
		else
			{
			avoidtime = level.time + time;
			}
		
		if ( use_temp_goal )
			dir = temp_goal - self.origin;						
		else
			dir = goal - self.origin;			

		length = dir.length();
      dir.normalize();
		
		//new stuff
		self.FlightDir = dir;


      ang = dir.toAngles();
		
		if ( length > 150 && random_allowed && !use_temp_goal )
			{
			//ang[YAW]   += G_Random( 20 ) - 5.0;
			//ang[PITCH] += G_Random( 20 ) - 5.0;
			}

		target_angle = ang;

		target_angle[YAW]   = AngleNormalize180( target_angle[YAW] );
		target_angle[PITCH] = AngleNormalize180( target_angle[PITCH] );

		if ( self.currentEnemy )
			{
			Vector enemyDir;
			enemyDir = self.currentEnemy->origin - self.origin;
			enemyDir.normalize();
			target_angle[PITCH] = AngleNormalize180(-enemyDir.toPitch());
			if ( target_angle[PITCH] < -40 )
				target_angle[PITCH] = -40;

			if ( target_angle[PITCH] > 40 )
				target_angle[PITCH] = 40;

			target_angle[YAW] = enemyDir.toYaw();
			target_angle[ROLL] = 0;
			}
      }

	target_angle[YAW]   = AngleNormalize360( target_angle[YAW] );
	target_angle[PITCH] = AngleNormalize360( target_angle[PITCH] );

	if ( (self.angles[YAW] != target_angle[YAW]) || (self.angles[PITCH] != target_angle[PITCH]) )
      {
		self.forwardspeed = speed * 0.8f;
      }
	else
      {
		self.forwardspeed = speed;
      }

	old_yaw   = self.angles[YAW];
	old_pitch = self.angles[PITCH];
	
	ang[YAW]   = LerpAngle( self.angles[YAW],   target_angle[YAW],   turn_speed );
	ang[PITCH] = LerpAngle( self.angles[PITCH], target_angle[PITCH], turn_speed );
	ang[ROLL]  = self.angles[ROLL];
	
	/*
	if( adjustYawAndRoll )
		{
	   
		if ( (AngleDelta( ang[YAW], old_yaw ) > 0) && (ang[ROLL] > 315 || ang[ROLL] <= 45) )
			{
			ang[ROLL] += 5;
			}
		else if ( (AngleDelta( ang[YAW], old_yaw ) < 0) && (ang[ROLL] < 45 || ang[ROLL] >= 315) )
			{
			ang[ROLL] -= 5;
			}
		else if ( (AngleDelta( ang[YAW], old_yaw ) == 0 ) )
			{
			if ( ang[ROLL] != 0 )
				{
				
				if ( ang[ROLL] < 5 || ang[ROLL] > 355 )
					{
					ang[ROLL] = 0;
					}
				else
					{
					if ( ang[ROLL] < 180 )
						ang[ROLL] += 5;
					else
						ang[ROLL] -= 5;
					}

				}
			}
		}
   */
	
	if ( adjustYawAndRoll )
		{
		Vector travelAngleDelta = dir.toAngles();
		float yawDelta = dir[YAW] - self.angles[YAW];

		yawDelta = AngleNormalize360(yawDelta);

		if ( yawDelta > 0 && yawDelta <=180 )
			{
			ang[ROLL] = self.angles[ROLL] + 2;
			if ( AngleNormalize180(ang[ROLL]) > 30 )
				ang[ROLL] = 30;
			}
	
		if ( yawDelta >=180 && yawDelta <= 359 )
			{
			ang[ROLL] = self.angles[ROLL] - 2;
			if ( AngleNormalize180(ang[ROLL]) < -30 )
				ang[ROLL] = -30;
			}

		}
   
	ang[YAW]   = AngleNormalize360( ang[YAW] );
	ang[PITCH] = AngleNormalize360( ang[PITCH] );
	ang[ROLL]  = AngleNormalize360( ang[ROLL] );

	// Don't get stuck if still turning

	if ( ( AngleDelta( ang[YAW], old_yaw ) > .5 ) || ( AngleDelta( ang[YAW], old_yaw ) < -.5 ) ||
		  ( AngleDelta( ang[PITCH], old_pitch ) > .5 ) || ( AngleDelta( ang[PITCH], old_pitch ) < -.5 ) )
		{
		stuck = 0;
		}

	self.setAngles( ang );

	if (offsetOrigin)
		{
   	self.origin.x-=x_offset;
	   self.origin.y-=y_offset;
	   //self.origin.z-=z_offset;
		}

	return true;
	}

float HelicopterFlyToPoint::LerpAngle( float old_angle, float new_angle, float lerp_amount )
	{
	float diff;
	float abs_diff;
	float lerp_angle;

	new_angle = AngleNormalize360( new_angle );
	old_angle = AngleNormalize360( old_angle );

	diff = new_angle - old_angle;

	if ( diff > 180 )
      {
		diff -= 360;
      }

	if ( diff < -180 )
      {
		diff += 360;
      }

	lerp_angle = old_angle;
	
	abs_diff = diff;

	if ( abs_diff < 0 )
      {
		abs_diff = -abs_diff;
      }

	if ( abs_diff < lerp_amount )
      {
		lerp_amount = abs_diff;
      }

	if ( diff < 0 )
      {
		lerp_angle -= lerp_amount;
      }
	else if ( diff > 0 )
      {
		lerp_angle += lerp_amount;
      }
	
	lerp_angle = AngleNormalize360( lerp_angle );

	return lerp_angle;
	}

void HelicopterFlyToPoint::End
	(
	Actor &self
	)

	{
	self.forwardspeed = old_forward_speed;
	self.FlightDir = vec_zero;
	}

/****************************************************************************

  FlyCircle Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, HelicopterFlyCircle, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HelicopterFlyCircle::HelicopterFlyCircle()
	{
	anim = "fly";	
	}

void HelicopterFlyCircle::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );

	fly_clockwise = ev->GetBoolean( 2 );

	if (ev->NumArgs() > 2 )
		fly.setAdjustYawAndRoll( false );
		//fly.setAdjustYawAndRoll( ev->GetBoolean( 3 ) );
	
	if (ev->NumArgs() > 3 )
		circle_player = ev->GetBoolean ( 4 );
	else
		circle_player = false;	
	
	if (ev->NumArgs() > 4 )
		fly.SetSpeed( ev->GetFloat( 5 ) );
	}

void HelicopterFlyCircle::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HelicopterFlyCircle::Begin
	(
	Actor &self
	)

	{
	original_z = self.origin.z;

	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( 5.0 );
	}

qboolean	HelicopterFlyCircle::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	trace_t trace;
	Vector dir;
	Vector angle;
	Vector left;
	qboolean too_far = false;
	Vector new_dir;
	Vector fly_dir;
	
	//Vector or;

	//or = self.currentEnemy->centroid - self.origin;
	//or = or.toAngles();

	//self.angles = or;
	//self.setAngles( or );
	
	if ( !self.IsEntityAlive( self.currentEnemy ) && !circle_player )
      {
      return false;
      }

	if ( self.lastmove == STEPMOVE_OK )
		{
		fly.SetTurnSpeed( 5.0 );

		if (circle_player)
			{
			
			Player* player = 0;
			// Make sure the player is alive and well
			for(int i = 0; i < game.maxclients; i++)
			{
			player = GetPlayer(i);		
		
			// don't target while player is not in the game or he's in notarget
			if( !player || ( player->flags & FL_NOTARGET ) )
				{
				return false;
				}
			}
						
			dir = player->centroid - self.origin;
			dir.z = 0;

			//if ( dir.length() > (self.origin.z - player->centroid.z) / .5 )
			if ( dir.length() > 600 )
				{
				too_far = true;
				}

			}
		else
			{
			dir = self.currentEnemy->centroid - self.origin;
			dir.z = 0;

			if ( dir.length() > (self.origin.z - self.currentEnemy->centroid.z) / 2 )
				{
				too_far = true;
				}

			}

		angle = dir.toAngles();

		angle.AngleVectors( NULL, &left, NULL );
		
		Vector newAngles = self.angles;
		if ( fly_clockwise )
			{
			fly_dir = left;

			newAngles[ROLL] -= 5;
			if ( AngleNormalize180(newAngles[ROLL]) < -30 )
				newAngles[ROLL] = -30;
			
			}			
		else
			{
			fly_dir = left * -1;
			newAngles[ROLL] += 5;
			if ( AngleNormalize180(newAngles[ROLL]) > 30 )
				newAngles[ROLL] = 30;

			}
			
		self.setAngles(newAngles);

		dir.normalize();

		if ( too_far )
			{
			new_dir = fly_dir * 0.5 + dir * 0.5;
			new_dir.normalize();
			}
		else
			{
			new_dir = fly_dir;
			}

		//goal = self.origin + new_dir * 200;
		goal = self.origin + new_dir * 200;

		trace = G_Trace( self.origin, self.mins, self.maxs, goal, &self, self.edict->clipmask, false, "FlyCircle" );

		if ( trace.fraction < 1 )
			{
			if ( too_far )
				trace.fraction /= 2;

			new_dir = fly_dir * trace.fraction + dir * (1 - trace.fraction);
			new_dir.normalize();

			//goal = self.origin + new_dir * 200;
			goal = self.origin + new_dir * 200;
			}
		else
			{
			goal = trace.endpos;
			}

		fly.SetGoalPoint( goal );
		}
	else
		{
		fly.SetTurnSpeed( 20.0 );
		}

	fly.Evaluate( self );

	return true;
	}

void HelicopterFlyCircle::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}


/****************************************************************************

  HelicopterStrafeAttack Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, HelicopterStrafeAttack, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HelicopterStrafeAttack::HelicopterStrafeAttack()
	{
	anim = "fly";	
	}

void HelicopterStrafeAttack::SetArgs
	(
	Event *ev
	)

	{
	anim = ev->GetString( 1 );
	turnTime = 5;
	setUpLerp = false;
	completedLerp = false;
	}

void HelicopterStrafeAttack::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HelicopterStrafeAttack::Begin
	(
	Actor &self
	)

	{
   self.SetAnim(anim);

	//First we find the waypoint closest to the player
	//These waypoints should be pointed along the axis
	//that we want the helicopter to strafe
	WayPointNode *wp = GetWayPointNearestPlayer(self);
	
	str tName = wp->Target();
	WayPointNode *target = GetWayPoint(self , tName );

	//Set up goal location
	//goal = target->origin;
	goal = wp->origin;
	goal.z = self.origin.z;
	
	//We need the cross product
	Vector wpForward;
	Vector wpUp;
	Vector cross;

   wpForward = target->origin - wp->origin;
	wpForward.normalize();
	

	wpUp.x = 0;
	wpUp.y = 0;
	wpUp.z = 1;
	
	CrossProduct(wpForward, wpUp, cross );

	
	
	//wpOrigin.AngleVectors(NULL,&left,NULL);

	//Get the vector from the player to the actor
	Vector playerToActor;
	playerToActor = self.origin - self.currentEnemy->origin;


	//Normalize the vectors
	playerToActor.normalize();
	cross.normalize();

	//Now we get the Dot product to see if towardPlayer
	float dot;
	dot = DotProduct(cross,playerToActor);
	

	//Now we get our actual direction Vector;	
	if ( dot > 0 )
		dir = cross * -1;
	else
		dir = cross;

	
	//Now set our angles appropriately
	targetAngles = self.angles;
	targetAngles[YAW] = dir.toYaw();
	
	startYaw = AngleNormalize360(self.angles[YAW]);
	endYaw = AngleNormalize360(targetAngles[YAW]);
	
	if ( endYaw == 0 && startYaw > 180 )
		endYaw = 360;

	}

qboolean	HelicopterStrafeAttack::Evaluate
	(
	Actor &self
	)

	{
	if ( !self.currentEnemy )
		return false;
	
	if ( !setUpLerp )
		{
		lerpStart = level.time;
		lerpEnd = lerpStart + turnTime;
		setUpLerp = true;
		}
	
	if ( !completedLerp )
		LerpToNewAngle( self );


	//Get our travel destination
	Vector travelDir;
	travelDir = goal - self.origin;

	//Check if we are at our destination
	float length = travelDir.length();
	
	if ( length < 25 ) //We're close enough
		return false;
	
	travelDir.normalize();
	self.FlightDir = travelDir;
	self.forwardspeed = 300;
	

	return true;
	}

WayPointNode *HelicopterStrafeAttack::GetWayPointNearestPlayer( Actor &self)
	{
	Vector DistanceFromPlayer;
	float distance;
	Entity* ent_in_range;
	Entity* best_ent;

	gentity_t *ed;
	
	ent_in_range = NULL;
	best_ent = NULL;
	distance = 100000000;
	
	if ( !self.currentEnemy ) return NULL;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			DistanceFromPlayer = ent_in_range->origin - self.currentEnemy->origin;
			if (DistanceFromPlayer.length() < distance )
				{
				best_ent = ent_in_range;
				distance = DistanceFromPlayer.length();
				}
			}
		}
	
	return (WayPointNode*)best_ent;
	}

WayPointNode *HelicopterStrafeAttack::GetWayPoint( Actor &self , const str &name )
	{
	Entity* ent_in_range;
	gentity_t *ed;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			if (!Q_stricmp(ent_in_range->targetname.c_str() , name.c_str() ))
				{
				return (WayPointNode*)ent_in_range;
				}
			}
		}
	
	return NULL;
	}

void HelicopterStrafeAttack::LerpToNewAngle( Actor &self )
	{
	Vector ang;
	float newYaw;

	ang = self.angles;
	
	newYaw = ( endYaw - startYaw ) / ( lerpEnd - lerpStart );
	newYaw = newYaw * (level.time - lerpStart );
	newYaw = newYaw + startYaw;
		
	ang[YAW] = newYaw;
	// Clamp it down in the end
	if ( level.time >= lerpEnd )
		{
		ang[YAW] = endYaw;
		completedLerp = true;
		}

	self.setAngles(ang);

	}

void HelicopterStrafeAttack::End
	(
	Actor &self
	)

	{
	self.FlightDir = vec_zero;
	}


/****************************************************************************

  HelicopterFlyToWaypoint Class Definition

****************************************************************************/


CLASS_DECLARATION( Behavior, HelicopterFlyToWaypoint, NULL )
	{
		{ &EV_Behavior_Args,			SetArgs },
		{ NULL, NULL }
	};

HelicopterFlyToWaypoint::HelicopterFlyToWaypoint()
	{
	anim = "fly";	
	nearestPlayer = false;
	nearestPlayerTarget = false;

	}

void HelicopterFlyToWaypoint::SetArgs
	(
	Event *ev
	)

	{
   anim = ev->GetString( 1 );
	waypointname = ev->GetString( 2 );
	
   if (ev->NumArgs() > 2 )
		fly.SetSpeed( ev->GetFloat( 3 ) );

   if (ev->NumArgs() > 3 )
		fly.setAdjustYawAndRoll( ev->GetBoolean( 4 ) );
	
	if ( !Q_stricmp(waypointname.c_str() , "player" ) )
		nearestPlayer = true;

	if ( !Q_stricmp(waypointname.c_str() , "target" ) )
		nearestPlayerTarget = true;
	
	}

void HelicopterFlyToWaypoint::ShowInfo
	(
	Actor &self
	)

	{
   Behavior::ShowInfo( self );
	}

void HelicopterFlyToWaypoint::Begin
	(
	Actor &self
	)

	{
	if ( anim.length() )
      {
		self.SetAnim( anim );
      }

	fly.Begin( self );
	fly.SetTurnSpeed( 5.0 );
	}

qboolean	HelicopterFlyToWaypoint::Evaluate
	(
	Actor &self
	)

	{
   Vector goal;
	WayPointNode *goalNode;
	goalNode = NULL;

	if ( !self.IsEntityAlive( self.currentEnemy ) )
      {
      return false;
      }

	if ( self.lastmove == STEPMOVE_OK )
		{
		fly.SetTurnSpeed( 5.0 );
		
		if ( nearestPlayer )
			goalNode = GetWayPointNearestPlayer( self );
		else if ( nearestPlayerTarget )
			{
			goalNode = GetWayPointNearestPlayer( self );
			waypointname = goalNode->TargetName();			
			}
		
		if ( !nearestPlayer )
			goalNode = GetWayPoint( self );

		}
	

	if ( !goalNode )
		return false;

	goal = goalNode->origin;
	goal.z = self.origin.z;

	//Check if we have arrived
	Vector dir;
	dir = self.origin - goal;
	
	if ( dir.length() <= 25 )
		return false;
	
	fly.SetGoalPoint( goal );
	fly.Evaluate( self );

	return true;
	}

WayPointNode *HelicopterFlyToWaypoint::GetWayPoint( Actor &self )
	{
	Entity* ent_in_range;
	gentity_t *ed;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			if (!Q_stricmp(ent_in_range->targetname.c_str() , waypointname.c_str() ))
				{
				return (WayPointNode*)ent_in_range;
				}
			}
		}
	
	return NULL;
	}

WayPointNode *HelicopterFlyToWaypoint::GetWayPointNearestPlayer( Actor &self)
	{
	Vector DistanceFromPlayer;
	float distance;
	Entity* ent_in_range;
	Entity* best_ent;

	gentity_t *ed;
	
	ent_in_range = NULL;
	best_ent = NULL;
	distance = 100000000;
	
	if ( !self.currentEnemy ) return NULL;

	for ( int i = 0; i < MAX_GENTITIES; i++ )
		{
		ed = &g_entities[i];

		if ( !ed->inuse || !ed->entity )
			{
			continue;
			}
				
			
		ent_in_range = g_entities[i].entity;

		if( ent_in_range->isSubclassOf( WayPointNode ) )
			{
			DistanceFromPlayer = ent_in_range->origin - self.currentEnemy->origin;
			if (DistanceFromPlayer.length() < distance )
				{
				best_ent = ent_in_range;
				distance = DistanceFromPlayer.length();
				}
			}
		}
	
	return (WayPointNode*)best_ent;
	}

void HelicopterFlyToWaypoint::End
	(
	Actor &self
	)

	{
	fly.End( self );
	}