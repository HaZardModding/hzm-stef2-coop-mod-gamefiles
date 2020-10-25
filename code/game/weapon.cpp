//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/weapon.cpp                                     $
// $Revision:: 52                                                             $
//   $Author:: Ericf                                                          $
//     $Date:: 8/09/01 3:48p                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/weapon.cpp                                          $
// 
// 52    8/09/01 3:48p Ericf
// Fixed Crosshair aiming in any FOV
// 
// 51    7/31/01 5:54p Ericf
// Fixed 3rd person shooting with the crosshair
// 
// 50    7/27/01 3:09p Ericf
// New crosshair / view math
// 
// 49    7/26/01 2:42p Ericf
// Crosshair color targeting stuff
// 
// 48    7/20/01 2:18p Ericf
// Movable Crosshair code
// 
// 47    7/02/01 1:39p Ericf
// Fixes to alot of weapons
// 
// 46    6/27/01 4:03p Ericf
// Fix for required ammo in different modes
// 
// 45    6/27/01 2:30p Ericf
// Burst mode fixes
// 
// 44    6/26/01 3:55p Ericf
// Burst mode fixes
// 
// 43    6/20/01 1:18p Ericf
// Toned down accuracy spread alittle
// 
// 42    5/25/01 12:51p Ericf
// Fixed a weapon bug
// 
// 41    5/25/01 11:28a Ericf
// Some small ammo handling fixes
// 
// 40    5/24/01 1:36p Ericf
// Implemented world model display in 3rd person
// 
// 39    5/23/01 11:10a Ericf
// Small change to ReadyToFire function
// 
// 38    5/14/01 3:45p Ericf
// Changed in weapon fire timing
// 
// 37    5/12/01 1:37p Ericf
// Burst Mode code added
// 
// 36    5/09/01 5:20p Ericf
// Changed right hand tag
// 
// 35    5/08/01 2:39p Ericf
// Added Has Inventory Ammo condition
// 
// 34    4/30/01 3:52p Sketcher
// Weapons now automatically fire with SOUNDTYPE_WEAPONFIRE so Actors can now
// react based on that
// 
// 33    4/18/01 1:37p Ericf
// Alternate Draw Bow Strain event
// 
// 32    4/16/01 11:51a Ericf
// Fixed a small switch mode weapon bug
// 
// 31    4/05/01 5:49p Ericf
// Added Target Idle Weapons
// 
// 30    4/05/01 11:39a Ericf
// Fixed an aimtype bug
// 
// 29    3/28/01 11:28a Ericf
// Added Switch Mode weapons code
// 
// 28    26.03.01 11:44a Ericf
// Changed naming for fire modes, no longer PRIMARY and ALTERNATE, but now
// MODE1 and MODE2 for future expansion to more than 2 mode weapons
// 
// 27    15.03.01 11:44a Ericf
//
// 26    15.03.01 11:36a Ericf
// Added Redemptive Damage
// 
// 15    7.02.01 11:27a Ericf
// Got rid of MuzzleClear checks temporarily (broken)
// 
// 14    6.02.01 4:37p Ericf
// Entirely new GetMuzzlePosition function for aiming
// 
// 13    31.01.01 12:38p Ericf
// More weapon work...
// 
// 12    30.01.01 9:46a Ericf
// Cleaned up regen ammo code
// 
// 11    29.01.01 11:04a Ericf
// Fixed QGun ammo display
// 
// 10    26.01.01 3:50p Ericf
// Added change idle event
// 
// 9     26.01.01 1:23p Ericf
// Lots of changes to animation system
// 
// 8     16.01.01 1:47p Ericf
// View/World model stuff
// 
// 7     12/11/00 9:34a Steven
// Changed passing of most vectors to const reference.
// 
// 6     8.12.00 10:55a Ericf
// Fixed weapons screwed up.
// 
// 5     1.12.00 3:44p Ericf
// Added SetViewModel Event
// 
// 4     1.12.00 3:42p Ericf
// 
// 3     12-01-00 1:55p Markd
// All weapons are RF_WEAPONMODEL
//
// 103   8/30/00 4:35p Aldie
// Added some functionality to get dm working
//
// 102   7/29/00 2:28p Aldie
// Added a nosound weapon check
//
// 101   7/25/00 8:38p Markd
// added no ammo sounds to weapons
//
// 100   7/21/00 8:37p Steven
// Made weapons give ammo back to owner when they are put away and made weapons
// not reload when they are being putaway.
//
// 99    7/19/00 7:26p Steven
// Fixed some warnings.
//
// 98    7/19/00 6:22p Steven
// Made it so you don't get ammo from a weapon you already have.
//
// 97    7/17/00 4:19p Aldie
// Changed to using v_angle instead of torsoangles for some aiming stuff.
//
// 96    7/16/00 4:38p Steven
// Moved action level stuff to actor pain and killed.
//
// 95    7/15/00 1:06p Aldie
// Added specialmove stuff for weapons so we can do special movement with some
// dualhanded weapons
//
// 94    7/12/00 5:36p Markd
// fixed ammo reporting to support bullets in clip
//
// 93    7/12/00 3:21p Aldie
// Added alternate modes to sword
//
// 92    7/11/00 9:57p Aldie
// Added torsoaim command
//
// 91    7/05/00 4:00p Steven
// Added a makenoise event.
//
// 90    6/27/00 7:17p Aldie
// Added worldhitspawn
//
// 89    6/27/00 2:48p Aldie
// Changed some weapon aiming stuff again.  Aimed shots are automatically
// determined now.
//
// 88    6/24/00 7:38p Aldie
// Put the weapon into the idle state
//
// 87    6/23/00 8:41p Markd
// made a lot of changes to different constructors for saved game support
//
// 86    6/20/00 3:11p Steven
// Fixed picking up of weapons.
//
// 85    6/19/00 6:20p Steven
// Fixed some melee attack stuff.
//
// 84    6/14/00 5:40p Aldie
// Fix event declaration
//
// 83    6/01/00 3:18p Markd
// rewrote giveItem and item management in sentient
//
// 82    5/31/00 5:06p Aldie
// New aiming method
//
// 81    5/30/00 6:55p Aldie
// Cleaned up the Shoot function
//
// 80    5/26/00 6:31p Aldie
// Added alternate fire to soulsucker and bug fix to AmmoAvailable()
//
// 79    5/26/00 3:42p Aldie
// Took out cinematic check for reloading clips
//
// 78    5/20/00 5:23p Aldie
// Added some comments
//
// 77    5/17/00 12:08p Aldie
// Added some comments
//
// 76    5/11/00 5:54p Steven
// Added melee firetype to weapon::shoot.
//
// 75    5/08/00 3:20p Aldie
// Added initial crosshair work
//
// 74    5/07/00 5:00p Markd
// fixed weapon pickup code
//
// 73    5/06/00 1:55p Aldie
// Added even more ammo checking fixes
//
// 72    5/06/00 11:49a Aldie
// More fixes for ammo again
//
// 71    5/06/00 11:12a Aldie
// Added block effect and fixed some problems with ammo
//
// 70    5/06/00 10:40a Steven
// Made it so there is action level and means of death variables for each
// weapon mode.
//
// 69    5/05/00 7:38p Aldie
// Fix ammo init
//
// 68    5/05/00 2:17p Steven
// Added means of death to weapons.
//
// 67    5/01/00 2:46p Steven
// Update the players actio level each time we shoot.
//
// 66    5/01/00 11:32a Aldie
// Added some comments
//
// 65    4/26/00 5:25p Aldie
// Changes to weapons to avoid having to specify the classname
//
// 64    4/24/00 5:24p Aldie
// Fixed some problems with the "clear" animation to clear effects if a weapon
// get stuck in a solid
//
// 63    4/17/00 11:19a Aldie
// Added comment
//
// 62    4/15/00 5:18p Aldie
// Added stun events and fixed yet another bug with Ammo and AutoPutaway
//
// 61    4/15/00 2:29p Aldie
// Added fix for ammo checking with weapons that don't use ammo
//
// 60    4/15/00 1:43p Aldie
// Added usenoammo command for a weapon that cannot be used when it has no ammo
//
// 59    4/14/00 7:12p Aldie
// Fixed some ammo checking bugs
//
// 58    4/13/00 7:03p Aldie
// Changed formatting
//
// 57    4/10/00 4:55p Aldie
// Change setFrame(0) to stopAnimating
//
// 56    4/10/00 11:28a Aldie
// Added weapon attaching to the sentients
//
// 55    4/07/00 6:00p Aldie
// Added flashing and fixed radius damage for explosions
//
// 54    4/07/00 4:01p Aldie
// Code changes to support flashbangs
//
// 53    3/22/00 6:45p Aldie
// Added some checks to prevent firing through walls
//
// 52    3/02/00 4:43p Aldie
// Added some ammo functionality for the HUD
//
// 51    2/25/00 6:43p Aldie
// Put back in a call to ForceIdle
//
// 50    2/25/00 5:02p Aldie
// Changed some reloading and put in a fix for the animation problem with the
// firing of the weapons
//
// 49    2/24/00 7:26p Aldie
// went back to the old muzzleposition code
//
// 48    2/23/00 6:21p Aldie
// More inventory changes
//
// 47    2/22/00 11:30a Steven
// Added means of death MOD_BULLET.
//
// 46    2/17/00 6:26p Aldie
// Fixed naming conventions for weapon hand and also added various attachtotag
// functionality for weapons that attach to different tags depending on which
// hand they are wielded in.
//
// 45    2/14/00 5:44p Jimdose
// got rid of ANIM_BLEND_TORSO
//
// 44    2/14/00 11:41a Aldie
// Added melee to firetype and getfiretype
//
// 43    2/11/00 7:25p Aldie
// Fixed some rope setup problems and fixed some reloading issues with loop
// fire weapons
//
// 42    2/10/00 3:56p Aldie
// Added "none" to firetype for the shield
//
// 41    2/09/00 8:02p Aldie
// Added loopfire weapons
//
// 40    2/09/00 2:58p Steven
// Fixed up some BroadcastSound issues with the weapons.
//
// 39    2/07/00 7:38p Aldie
// Fixed swiping, also various weapons fixes for sword and for sling
//
// 38    2/04/00 3:11p Aldie
// Changed sword attack method for water usage
//
// 37    2/02/00 12:04p Aldie
// Modified GetMuzzlePosition
//
// 36    2/01/00 5:28p Aldie
// More updates for auto aiming
//
// 35    1/29/00 6:17p Aldie
// Fixed some problems when state doesn't exist.
//
// 34    1/26/00 3:31p Markd
// made weapons have extra lighting by default
//
// 33    1/24/00 7:31p Aldie
// Changed a couple of calls in HasAmmo and HasAmmoInClip
//
// 32    1/24/00 7:21p Aldie
// Put UnlimitedAmmo check into UseAmmo
//
// 31    1/22/00 3:38p Aldie
// Fixed some weapons code
//
// 30    1/22/00 12:42p Jimdose
// got rid of calls to vec3()
//
// 29    1/20/00 3:27p Aldie
// Fix for reloading
//
// 28    1/19/00 7:46p Aldie
// Fixed func_spawns of various types and removed some unused misc classes
//
// 27    1/19/00 12:10p Aldie
// Added some chargeup functionality
//
// 26    1/18/00 6:49p Aldie
// Init some bulletvars differently
//
// 25    1/13/00 4:55p Aldie
// Fixed error message
//
// 24    1/11/00 7:29p Jimdose
// added Tag_OrientationEx
//
// 23    1/10/00 10:30a Jimdose
// removed unused code
//
// 22    1/05/00 7:25p Jimdose
// made angle functions all use the same coordinate system
// AngleVectors now returns left instead of right
// no longer need to invert pitch
//
// 21    12/17/99 6:35p Jimdose
// changed spawnarg code
// added Level class for spawning and map control
// got rid of unused or superflous variables
// changed setjmp/longjmp calls to try/throw/catch exception handling
//
// 20    12/16/99 5:04p Aldie
// Removed auto aim hack
//
// 19    12/13/99 10:14a Aldie
// Temp update for bug fixing due to merge
//
// 18    12/07/99 6:09p Aldie
// Added weapon charging
//
// 17    12/03/99 7:02p Aldie
// More ammo joy
//
// 16    12/02/99 6:53p Aldie
// Changed naming conventions from "both" to "dualhanded"  Also put in the
// inventory renderer for the hud file
//
// 15    12/01/99 4:56p Markd
// fixed some reference versus pointer issues with RandomAnimate and NewAnim
//
// 14    12/01/99 11:26a Aldie
// Couple of fixes for emitters and more ammo stuff
//
// 13    11/29/99 6:32p Aldie
// Lots of changes for ammo system
//
// 12    11/22/99 6:46p Aldie
// Started working on ammo changes - will finish after Thanksgiving break
//
// 11    11/22/99 11:17a Aldie
// Made some util macros
//
// 10    11/19/99 5:45p Aldie
// Update for primary and alternate fire weapons.  Removed PRIMARY and SECONDAY
// mode weapons of Sin, removed SILENCED properties, and changed ammo types to
// use the new system.  Still need to fix ammo checking for weapons.
//
// 9     11/01/99 4:01p Jimdose
// made work with bone controllers
//
// 8     10/19/99 7:53p Markd
// eliminated 3 part model system
//
// 7     10/02/99 6:51p Markd
// Put in backend work for event documentation and fixed a lot of event
// documentation bugs
//
// 6     9/30/99 4:37p Aldie
// Fixed some comma errors for events
//
// 5     9/30/99 1:49p Aldie
// Documentation of commands
//
// 4     9/27/99 5:45p Markd
// began documentation and cleanup phase after merge
//
// 3     9/16/99 4:49p Jimdose
// removed unused code
//
// 2     9/10/99 5:45p Jimdose
// merge
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 37    9/02/99 10:38p Aldie
// Better autoaim
//
// 36    9/02/99 5:41p Markd
// made CacheResource utility functions changed code every where else
//
// 35    9/02/99 3:06p Markd
// Fixed speakers, precaching of models and appending "models" and
// automatically caching in projectiles.
//
// 34    9/01/99 8:35p Aldie
// Dont autoaim on dead stuff
//
// 33    9/01/99 7:58p Aldie
// Added autoaiming hack
//
// 32    8/28/99 10:40a Markd
// removed bullet hole support until we need it.
//
// 31    8/19/99 12:01p Aldie
// Added in firing time checks
//
// 30    8/11/99 7:35p Aldie
// Added hand checking to weapons
//
// 29    8/11/99 11:51a Aldie
// Fix if statement for firetype
//
// 28    8/10/99 2:30p Aldie
//
// 27    8/09/99 5:07p Aldie
// More changes to accomodate weapons system
//
// 26    8/06/99 6:40p Aldie
// Started moving over to new weapons system
//
// 25    8/03/99 3:38p Aldie
// If the tag_barrel is not found, print a warning
//
// 24    7/30/99 6:24p Aldie
// Updated weapons and utils to use new methods
//
// 23    7/29/99 7:38p Aldie
// Updated weapons to new system
//
// 22    7/23/99 3:27p Aldie
//
// DESCRIPTION:
// Source file for Weapon class.  The weapon class is the base class for
// all weapons in Sin.  Any entity created from a class derived from the weapon
// class will be usable by any Sentient (players and monsters) as a weapon.
//

#include "g_local.h"
#include "entity.h"
#include "item.h"
#include "weapon.h"
#include "scriptmaster.h"
#include "sentient.h"
#include "misc.h"
#include "specialfx.h"
#include "actor.h"
#include "weaputils.h"
#include "player.h"
#include "decals.h"

#define TargetIdleTime 0.2

Event EV_Weapon_Shoot
   (
   "shoot",
   EV_DEFAULT,
   "S",
   "mode",
   "Shoot the weapon"
   );
Event EV_Weapon_DoneRaising
   (
   "ready",
   EV_DEFAULT,
   NULL,
   NULL,
   "Signals the end of the ready animation so the weapon can be used"
   );
Event EV_Weapon_DoneFiring
   (
   "donefiring",
   EV_DEFAULT,
   NULL,
   NULL,
   "Signals the end of the fire animation"
   );
Event EV_Weapon_Idle
   (
   "idle",
   EV_DEFAULT,
   NULL,
   NULL,
   "Puts the weapon into an idle state"
   );
Event	EV_Weapon_SecondaryUse
   (
   "secondaryuse",
   EV_DEFAULT,
   NULL,
   NULL,
   "Puts the weapon into its secondary mode of operation"
   );
Event	EV_Weapon_DoneReloading
   (
   "donereloading",
   EV_DEFAULT,
   NULL,
   NULL,
   "Signals the end of the reload animation"
   );
Event EV_Weapon_SetAmmoClipSize
   (
   "clipsize",
   EV_DEFAULT,
   "i",
   "ammoClipSize",
   "Set the amount of rounds a clip of the weapon holds"
   );
Event EV_Weapon_SetAmmoInClip
   (
   "ammo_in_clip",
   EV_DEFAULT,
   "i",
   "ammoInClip",
   "Set the amount of ammo in the clip"
   );
Event EV_Weapon_ProcessModelCommands
   (
   "process_mdl_cmds",
   EV_DEFAULT,
   NULL,
   NULL,
   "Forces a processing of the init commands for the model"
   );
Event EV_Weapon_SetMaxRange
   (
   "maxrange",
   EV_DEFAULT,
   "f",
   "maxRange",
   "Set the maximum range of a weapon so the AI knows how to use it"
   );
Event EV_Weapon_SetMinRange
   (
   "minrange",
   EV_DEFAULT,
   "f",
   "minRange",
   "Set the minimum range of a weapon so the AI knows how to use it"
   );
Event EV_Weapon_ActionIncrement
   (
   "actionincrement",
   EV_DEFAULT,
   "i",
   "actionLevelIncrement",
   "Set the action level increment of the weapon.\n"
   "When the weapon is fired, it will raise the action level by this amount"
   );
Event EV_Weapon_NotDroppable
   (
   "notdroppable",
   EV_DEFAULT,
   NULL,
   NULL,
   "Makes a weapon not droppable"
   );
Event EV_Weapon_SetAimAnim
   (
   "setaimanim",
   EV_DEFAULT,
   "si",
   "aimAnimation aimFrame",
   "Set the aim animation and frame for when a weapon fires"
   );
Event EV_Weapon_SetFireType
   (
   "firetype",
   EV_DEFAULT,
   "s",
   "firingType",
   "Set the firing type of the weapon (projectile or bullet)"
   );
Event EV_Weapon_SetProjectile
   (
   "projectile",
   EV_DEFAULT,
   "s",
   "projectileModel",
   "Set the model of the projectile that this weapon fires"
   );
Event EV_Weapon_SetBulletDamage
   (
   "bulletdamage",
   EV_DEFAULT,
   "f",
   "bulletDamage",
   "Set the damage that the bullet causes"
   );
Event EV_Weapon_SetBulletKnockback
   (
   "bulletknockback",
   EV_DEFAULT,
   "f",
   "bulletKnockback",
   "Set the knockback that the bullet causes"
   );
Event EV_Weapon_SetBulletCount
   (
   "bulletcount",
   EV_DEFAULT,
   "f",
   "bulletCount",
   "Set the number of bullets this weapon shoots when fired"
   );
Event EV_Weapon_SetBulletRange
   (
   "bulletrange",
   EV_DEFAULT,
   "f",
   "bulletRange",
   "Set the range of the bullets"
   );
Event EV_Weapon_SetBulletSpread
   (
   "bulletspread",
   EV_DEFAULT,
   "ff",
   "bulletSpreadX bulletSpreadY",
   "Set the max spread of the bullet in the x and y axis"
   );
Event EV_Weapon_SetRange
   (
   "range",
   EV_DEFAULT,
   "f",
   "range",
   "Set the range of the weapon"
   );
Event EV_Weapon_Hand
   (
   "hand",
   EV_DEFAULT,
   "s",
   "weaponHand",
   "Set the hand the weapon can be wielded in (lefthand, righthand, both, or any)"
   );
Event EV_Weapon_Mode
   (
   "modeset",
   EV_DEFAULT,
   "SSSSSSSSS",
   "arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9",
   "Set a value for a mode by passing commands through"
   );
Event EV_Weapon_AmmoType
   (
   "ammotype",
   EV_DEFAULT,
   "s",
   "name",
   "Set the type of ammo this weapon uses"
   );
Event EV_Weapon_StartAmmo
   (
   "startammo",
   EV_DEFAULT,
   "i",
   "amount",
   "Set the starting ammo of this weapon"
   );
Event EV_Weapon_AmmoRequired
   (
   "ammorequired",
   EV_DEFAULT,
   "i",
   "amount",
   "Set the amount of ammo this weapon requires to fire"
   );
Event EV_Weapon_MaxChargeTime
   (
   "maxchargetime",
   EV_DEFAULT,
   "i",
   "time",
   "Set the maximum time the weapon may be charged up"
   );
Event EV_Weapon_GiveStartingAmmo
   (
   "startingammotoowner",
   EV_DEFAULT,
   NULL,
   NULL,
   "Internal event used to give ammo to the owner of the weapon"
   );
Event EV_Weapon_AutoAim
   (
   "autoaim",
   EV_DEFAULT,
   NULL,
   NULL,
   "Turn on auto aiming for the weapon"
   );
Event EV_Weapon_Crosshair
   (
   "crosshair",
   EV_DEFAULT,
   "b",
   "bool",
   "Turn on/off the crosshair for this weapon"
   );
Event EV_Weapon_TorsoAim
   (
   "torsoaim",
   EV_DEFAULT,
   "b",
   "bool",
   "Turn on/off the torsoaim for this weapon"
   );
Event EV_Weapon_SetQuiet
   (
   "quiet",
   EV_DEFAULT,
   NULL,
   NULL,
   "Makes the weapon make no noise."
   );
Event EV_Weapon_SetLoopFire
   (
   "loopfire",
   EV_DEFAULT,
   NULL,
   NULL,
   "Makes the weapon fire by looping the fire animation."
   );
Event EV_Weapon_LeftAttachToTag
   (
   "leftattachtotag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to it's owner when wielded in the left hand."
   );
Event EV_Weapon_RightAttachToTag
   (
   "rightattachtotag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to it's owner when wielded in the right hand."
   );
Event EV_Weapon_DualAttachToTag
   (
   "dualattachtotag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to it's owner when wielded dual handed."
   );
Event EV_Weapon_HolsterTagLeft
   (
   "leftholstertag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to when the weapon is put away from the left hand."
   );
Event EV_Weapon_HolsterTagRight
   (
   "rightholstertag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to when the weapon is put away from the right hand."
   );
Event EV_Weapon_HolsterTagDual
   (
   "dualholstertag",
   EV_DEFAULT,
   "s",
   "tagname",
   "Set the name of the tag to attach this to when the weapon is put away from dual handed"
   );
Event EV_Weapon_LeftHolsterAngles
   (
   "leftholsterangles",
   EV_DEFAULT,
   "v",
   "angles",
   "Set the angles of this weapon when it's attached to the left holster"
   );
Event EV_Weapon_RightHolsterAngles
   (
   "rightholsterangles",
   EV_DEFAULT,
   "v",
   "angles",
   "Set the angles of this weapon when it's attached to the right holster"
   );
Event EV_Weapon_DualHolsterAngles
   (
   "dualholsterangles",
   EV_DEFAULT,
   "v",
   "angles",
   "Set the angles of this weapon when it's attached to the dual holster"
   );
Event EV_Weapon_HolsterScale
   (
   "holsterscale",
   EV_DEFAULT,
   "f",
   "scale",
   "Set the scale of the weapon when it's attached to the holster"
   );
Event EV_Weapon_AutoPutaway
   (
   "autoputaway",
   EV_DEFAULT,
   "b",
   "bool",
   "Set the weapon to be automatically put away when out of ammo"
   );
Event EV_Weapon_UseNoAmmo
   (
   "usenoammo",
   EV_DEFAULT,
   "b",
   "bool",
   "Set the weapon to be able to be used when it's out of ammo"
   );
Event EV_Weapon_SetMeansOfDeath
   (
   "meansofdeath",
   EV_DEFAULT,
   "s",
   "meansOfDeath",
   "Set the meansOfDeath of the weapon."
   );
Event EV_Weapon_SetWorldHitSpawn
   (
   "worldhitspawn",
   EV_DEFAULT,
   "s",
   "modelname",
   "Set a model to be spawned when the weapon strikes the world."
   );
Event EV_Weapon_MakeNoise
   (
   "makenoise",
   EV_DEFAULT,
   "FB",
   "noise_radius force",
   "Makes the weapon make noise that actors can hear."
   );
Event EV_Weapon_SetWorldModel
   (
   "worldmodel",
   EV_DEFAULT,
   "s",
   "filename",
   "Set the world model name"
   );
Event EV_Weapon_DonePutaway
	(
	"doneputaway",
	EV_DEFAULT,
   NULL,
   NULL,
   "Called when the weapon is done with it's putaway anim"
	);
Event EV_Weapon_SetRegenAmmo
   (
   "regenammo",
   EV_DEFAULT,
   "ii",
   "regenamount regentime",
   "Specifics that a weapon regenerates ammo over time"
   );
Event EV_Weapon_RegenThink
   (
   "regenthink",
   EV_DEFAULT,
   NULL,
   NULL,
   "Event that gives ammo to the player"
   );
Event EV_Weapon_ChangeIdle
   (
   "changeidle",
   EV_DEFAULT,
   NULL,
   NULL,
   "Changes the idle animation"
   );
Event EV_Weapon_DrawBowStrain
	(
	"drawbowstrain",
	EV_DEFAULT,
   NULL,
   NULL,
   "Starts the bow draw strain animation"
	);
Event EV_Weapon_AltDrawBowStrain
	(
	"altdrawbowstrain",
	EV_DEFAULT,
   NULL,
   NULL,
   "Starts the alternate bow draw strain animation"
	);
Event EV_Weapon_SetAccuracy
	(
	"setaccuracy",
	EV_DEFAULT,
   "fffff",
   "stoppedac acchange walkac runac crouchac",
   "Starts the bow draw strain animation"
	);
Event EV_Weapon_SetReticuleTime
	(
	"setreticuletime",
	EV_DEFAULT,
   "f",
   "reticuletime",
   "Reticule time"
	);
Event EV_Weapon_SetZoomFOV
	(
	"setzoomfov",
	EV_DEFAULT,
   "f",
   "zoomfov",
   "Zoom FOV"
	);
Event EV_Weapon_SetRedemptive
	(
	"redemptive",
	EV_DEFAULT,
   "b",
   "redemptive",
   "Sets the weapon to Redemptive"
	);
Event EV_Weapon_SetAimType
	(
	"setaim",
	EV_DEFAULT,
   "s",
   "aimtype",
   "Sets the aimtype of the weapon (changes according to player state)"
	);
Event EV_Weapon_SetFireTimer
	(
	"setfiretimer",
	EV_DEFAULT,
	"sf",
   "mode mintime",
   "Specifies the minimum time between shots"
	);
Event EV_Weapon_UseSameClip
	(
	"usesameclip",
	EV_DEFAULT,
	NULL,
   NULL,
   "Specifies that ammo comes out of the same clip in all fire modes"
	);
Event EV_Weapon_SetRedemptiveDamage
	(
	"redemptivedamage",
	EV_DEFAULT,
	NULL,
   NULL,
   "Sets the redemptive damage"
	);
Event EV_Weapon_SetMaxModes
	(
	"maxmode",
	EV_DEFAULT,
	"s",
	"maxmode",
   "Overrides the maximum number of modes for this weapon (default is 2)"
	);
Event EV_Weapon_SetSwitchMode
	(
	"switchmode",
	EV_DEFAULT,
	NULL,
   NULL,
   "Specifies that this is a switch mode weapon (right button switches)"
	);
Event	EV_Weapon_DoneSwitching
   (
   "doneswitching",
   EV_DEFAULT,
   NULL,
   NULL,
   "Signals the end of the switching to mode animation"
   );
Event	EV_Weapon_DoneSwitchToMiddle
   (
   "doneswitchtomiddle",
   EV_DEFAULT,
   NULL,
   NULL,
   "Signals the end of the switching to 'neutral' animation"
   );
Event	EV_Weapon_TargetIdle
   (
   "targetidle",
   EV_DEFAULT,
   NULL,
   NULL,
   "This weapon have a specific on-target idle"
   );
Event EV_Weapon_TargetIdleThink
   (
   "targetidlethink",
   EV_DEFAULT,
   NULL,
   NULL,
   "Think event to check for target on target idle weapons"
   );
Event EV_Weapon_SetBurstMode
   (
   "burstmode",
   EV_DEFAULT,
   "i",
   "burstcount",
   "Set this mode to be burst mode, that uses burstcount ammo"
   );


// Delete me after the code is updated for everyone
Event EV_Weapon_Alternate
   (
   "alternate",
   EV_DEFAULT,
   "SSSSSSSSS",
   "arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9",
   "Set the alternate mode of the weapon, by passing commands through"
   );


CLASS_DECLARATION( Item, Weapon, NULL )
	{
	   { &EV_Item_Pickup,			            PickupWeapon },
	   { &EV_Weapon_DoneRaising,	            DoneRaising },
		{ &EV_Weapon_DoneFiring,	            DoneFiring },
	   { &EV_Weapon_Idle,			            Idle },
		{ &EV_BroadcastSound,		         	WeaponSound },
	   { &EV_Weapon_DoneReloading,            DoneReloading },
      { &EV_Weapon_SetAmmoClipSize,          SetAmmoClipSize },
      { &EV_Weapon_SetAmmoInClip,            SetAmmoInClip },
      { &EV_Weapon_ProcessModelCommands,     ProcessWeaponCommandsEvent },
		{ &EV_Weapon_SetMaxRange,				   SetMaxRangeEvent },
		{ &EV_Weapon_SetMinRange,				   SetMinRangeEvent },
      { &EV_Weapon_ActionIncrement,    	   SetActionLevelIncrement },
      { &EV_Weapon_NotDroppable,    	      NotDroppableEvent },
      { &EV_Weapon_SetAimAnim,               SetAimAnim },
      { &EV_Weapon_Shoot,                    Shoot },
      { &EV_Weapon_SetFireType,              SetFireType },
		{ &EV_Weapon_DonePutaway,					DonePutaway },
      { &EV_Weapon_SetProjectile,            SetProjectile },
      { &EV_Weapon_SetBulletDamage,          SetBulletDamage },
      { &EV_Weapon_SetBulletCount,           SetBulletCount },
      { &EV_Weapon_SetBulletKnockback,       SetBulletKnockback },
      { &EV_Weapon_SetBulletRange,           SetBulletRange },
      { &EV_Weapon_SetRange,                 SetRange },
      { &EV_Weapon_SetBulletSpread,          SetBulletSpread },
      { &EV_Weapon_Hand,                     SetHand },
      { &EV_Weapon_Mode,		               ModeSet },
      { &EV_Weapon_AmmoType,                 SetAmmoType },
      { &EV_Weapon_StartAmmo,                SetStartAmmo },
      { &EV_Weapon_AmmoRequired,             SetAmmoRequired },
      { &EV_Weapon_MaxChargeTime,            SetMaxChargeTime },
      { &EV_Weapon_GiveStartingAmmo,         GiveStartingAmmoToOwner },
      { &EV_Weapon_AutoAim,                  AutoAim },
      { &EV_Weapon_Crosshair,                Crosshair },
      { &EV_Weapon_TorsoAim,                 TorsoAim },
      { &EV_Weapon_LeftAttachToTag,          LeftAttachToTag },
      { &EV_Weapon_RightAttachToTag,         RightAttachToTag },
      { &EV_Weapon_DualAttachToTag,          DualAttachToTag },
      { &EV_Weapon_HolsterTagLeft,           LeftHolsterAttachToTag },
      { &EV_Weapon_HolsterTagRight,          RightHolsterAttachToTag },
      { &EV_Weapon_HolsterTagDual,           DualHolsterAttachToTag },
      { &EV_Weapon_RightHolsterAngles,       SetRightHolsterAngles },
      { &EV_Weapon_LeftHolsterAngles,        SetLeftHolsterAngles },
      { &EV_Weapon_DualHolsterAngles,        SetDualHolsterAngles },
      { &EV_Weapon_HolsterScale,             SetHolsterScale },
		{ &EV_Weapon_SetQuiet,		            SetQuiet },
		{ &EV_Weapon_SetLoopFire,	            SetLoopFire },
      { &EV_Weapon_AutoPutaway,              SetAutoPutaway },
      { &EV_Weapon_UseNoAmmo,                SetUseNoAmmo },
		{ &EV_Weapon_SetMeansOfDeath,          SetMeansOfDeath },
		{ &EV_Weapon_SetWorldHitSpawn,         SetWorldHitSpawn },
		{ &EV_Weapon_MakeNoise,			         MakeNoise },
		{ &EV_Weapon_SetWorldModel,				SetWorldModel },
		{ &EV_Weapon_SetRegenAmmo,					SetRegenAmmo },
		{ &EV_Weapon_RegenThink,					RegenThink },
		{ &EV_Weapon_ChangeIdle,					ChangeIdle },
		{ &EV_Weapon_DrawBowStrain,				DrawBowStrain },
		{ &EV_Weapon_AltDrawBowStrain,			AltDrawBowStrain },
		{ &EV_Weapon_SetAccuracy,					SetAccuracy },
		{ &EV_Weapon_SetReticuleTime,				SetReticuleTime },
		{ &EV_Weapon_SetZoomFOV,					SetZoomFOV },
		{ &EV_Weapon_SetRedemptive,				SetRedemptive },
		{ &EV_Weapon_SetAimType,					SetAimType },
		{ &EV_Weapon_SetFireTimer,					SetFireTimer },
		{ &EV_Weapon_UseSameClip,					UseSameClip },
		{ &EV_Weapon_SetRedemptiveDamage,		SetRedemptiveDamage },
		{ &EV_Weapon_SetMaxModes,					SetMaxModes },
		{ &EV_Weapon_SetSwitchMode,				SetSwitchMode },
		{ &EV_Weapon_DoneSwitchToMiddle,			DoneSwitchToMiddle },
		{ &EV_Weapon_DoneSwitching,				DoneSwitching },
		{ &EV_Weapon_TargetIdle,					TargetIdle },
		{ &EV_Weapon_TargetIdleThink,				TargetIdleThink },
		{ &EV_Weapon_SetBurstMode,					SetBurstMode },

		{ &EV_Weapon_Alternate,						Alternate },
		{ NULL, NULL }
	};

//======================
//Weapon::Weapon
//======================
Weapon::Weapon()
	{
   if ( LoadingSavegame )
      {
      // Archive function will setup all necessary data
      return;
      }

   // Owner of the weapon
	owner					      = NULL;

   // Starting rank of the weapon
	rank					      = 0;

   // Amount of ammo required for weapon
   INITIALIZE_WEAPONMODE_VAR( ammorequired, 0 );

   // Starting ammo of the weapon
   INITIALIZE_WEAPONMODE_VAR( startammo, 0 );

   // Amount of ammo the clip can hold
   INITIALIZE_WEAPONMODE_VAR( ammo_clip_size, 0 );

   // Amount of ammo in clip
   INITIALIZE_WEAPONMODE_VAR( ammo_in_clip, 0 );

   // Amount of time to pass before broadcasting a weapon sound again
   nextweaponsoundtime     = 0;

   // The initial state of the weapon
	weaponstate			      = WEAPON_HOLSTERED;

   // Is the weapon droppable when the owner is killed
   notdroppable            = false;

   // Aim animation for behavior of monsters
   aimanim                 = -1;
   aimframe                = 0;

   // start off unattached
   attached = false;

	// maximum effective firing distance (for autoaim)
	maxrange = 1000;

	// minimum safe firing distance (for AI)
	minrange = 0;

	// speed of the projectile (0 == infinite speed)
	memset( projectilespeed, 0, sizeof( projectilespeed ) );

   // default action_level_increment
	INITIALIZE_WEAPONMODE_VAR( action_level_increment, 2 );

   // Weapons don't move
   setMoveType( MOVETYPE_NONE );

   // What type of ammo this weapon fires
   INITIALIZE_WEAPONMODE_VAR( firetype, (firetype_t)0 );

   // Init the bullet specs
   INITIALIZE_WEAPONMODE_VAR( bulletdamage,    0 );
	INITIALIZE_WEAPONMODE_VAR( redemptivedamage,0 );
   INITIALIZE_WEAPONMODE_VAR( bulletcount,     1 );
   INITIALIZE_WEAPONMODE_VAR( bulletrange,     1024 );
   INITIALIZE_WEAPONMODE_VAR( bulletknockback, 0 );
   INITIALIZE_WEAPONMODE_VAR( ammo_type,       "" );
   INITIALIZE_WEAPONMODE_VAR( loopfire,        false );
	INITIALIZE_WEAPONMODE_VAR( burstmode,		  qfalse);
	burstcount = 0;
	burstcountmax = 0;

   // Init the max amount of time a weapon may be charged (5 seconds)
   INITIALIZE_WEAPONMODE_VAR( max_charge_time,   5 );
   charge_fraction = 1.0f;

   // Tag to attach this weapon to on its owner when used in the left hand and in the right hand
   left_attachToTag  = "tag_weapon_left";
   right_attachToTag = "tag_rhand";
   dual_attachToTag  = "tag_weapon_dual";

   // putaway is flagged true when the weapon should be put away by state machine
   putaway = false;

   // Default to being able to use the weapon in any hand
   hand    = WEAPON_ANY;

   // This is used for setting mode functionality when initializing stuff
   firemodeindex = FIRE_MODE1;

   // Name and index
   setName( "Unnamed Weapon" );

   // do better lighting on all weapons
   edict->s.renderfx |= RF_EXTRALIGHT;

   // make all weapons RF_WEAPONMODELs
   edict->s.renderfx |= RF_WEAPONMODEL;

   // Weapons do not auto aim automatically
   autoaim = false;

   // No crosshair visible
   crosshair = false;

   // Don't torsoaim
   torsoaim = false;

	// Weapons default to making noise
	quiet = false;
	next_noise_time = 0;
	next_noammo_time = 0;

   // Used to keep track of last angles and scale before holstering
   lastValid = qfalse;
   lastScale = 1.0f;
   holsterScale = 1.0f;

   // Weapon will not be putaway by default when out of ammo
   auto_putaway = qfalse;

   // Weapon will be able to be used when it has no ammo
   use_no_ammo  = qtrue;

	// Default weapon doesn't regen ammo
	regenAmount = 0;
	regenTime = 0.0;

	// Default accuracy value
	for ( int i=0; i<MAX_FIREMODES; i++ )
		for ( int j=0; j<MAX_ACCURACYTYPES; j++ )
		accuracy[i][j] = 0.0; // Defaults to perfect accuracy

	aimtype = ACCURACY_STOPPED;

	// Reticule and zoom fov defaults
	reticuletime = 0.0;
	zoomfov = 90.0;

	redemptive = qfalse;
	usesameclip = qfalse;

	curmode = FIRE_MODE1;
	maxmode = FIRE_MODE2;

	chargetime = 0.0;

	switchmode = qfalse;
	targetidle = qfalse;
	targetidleflag = qfalse;

	chx = 0;
	chy = 0;

	INITIALIZE_WEAPONMODE_VAR(next_fire_time, 0.0);
	INITIALIZE_WEAPONMODE_VAR(fire_timer, 0.0);

	INITIALIZE_WEAPONMODE_VAR( meansofdeath, MOD_SWORD );

   PostEvent( EV_Weapon_Idle, 0 );
   }


//======================
//Weapon::Weapon
//======================
Weapon::Weapon
   (
   const char *file
   )

   {
   // The tik file holds all the information available for a weapon
   Weapon();
   }

//======================
//Weapon::~Weapon
//======================
Weapon::~Weapon()
	{
   DetachGun();
	}

//======================
//Weapon::GetRank
//======================
int Weapon::GetRank
	(
	void
	)

	{
	return rank;
	}

//======================
//Weapon::GetOrder
//======================
int Weapon::GetOrder
	(
	void
	)

	{
	return order;
	}

//======================
//Weapon::SetRank
//======================
void Weapon::SetRank
	(
	int order,
	int rank
	)

	{
	this->order = order;
	this->rank = rank;
	}

//======================
//Weapon::SetAutoPutaway
//======================
void Weapon::SetAutoPutaway
   (
   Event *ev
   )

   {
   auto_putaway = ev->GetBoolean( 1 );
   }

//======================
//Weapon::SetUseNoAmmo
//======================
void Weapon::SetUseNoAmmo
   (
   Event *ev
   )

   {
   use_no_ammo = ev->GetBoolean( 1 );
   }

//======================
//Weapon::SetStartAmmo
//======================
void Weapon::SetStartAmmo
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   startammo[firemodeindex] = ev->GetInteger( 1 );
   }

//======================
//Weapon::SetMaxChargeTime
//======================
void Weapon::SetMaxChargeTime
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   max_charge_time[firemodeindex] = ev->GetFloat( 1 );
   }

//======================
//Weapon::SetAmmoRequired
//======================
void Weapon::SetAmmoRequired
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   ammorequired[firemodeindex] = ev->GetInteger( 1 );
   }

//======================
//Weapon::GetStartAmmo
//======================
int Weapon::GetStartAmmo
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      return startammo[mode];
   else
      {
      warning( "Weapon::GetStartAmmo", "Invalid mode %d\n", mode );
      return 0;
      }
   }

//======================
//Weapon::GetAmmoType
//======================
str Weapon::GetAmmoType
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      return ammo_type[mode];
   else
      {
      warning( "Weapon::GetAmmoType", "Invalid mode %d\n", mode );
      return "UnknownAmmo";
      }
   }

//======================
//Weapon::SetAmmoType
//======================
void Weapon::SetAmmoType
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );

   if ( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) )
      ammo_type[firemodeindex] = ev->GetString( 1 );
   else
      {
      warning( "Weapon::SetAmmoType", "Invalid mode %d\n", firemodeindex );
      return;
      }
   }

//======================
//Weapon::SetAmmoAmount
//======================
void Weapon::SetAmmoAmount
	(
	int amount,
   firemode_t mode
	)

	{
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   // If the clip can hold ammo, then set the amount in the clip to the specified amount
   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      {
      if ( ammo_clip_size[mode] )
         ammo_in_clip[mode] = amount;
      }
   else
      {
      warning( "Weapon::SetAmmoAmount", "Invalid mode %d\n", mode );
      return;
      }
	}

//======================
//Weapon::GetClipSize
//======================
int Weapon::GetClipSize
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      return ammo_clip_size[mode];
   else
      {
      warning( "Weapon::GetClipSize", "Invalid mode %d\n", mode );
      return 0;
      }
   }

//======================
//Weapon::UseAmmo
//======================
void Weapon::UseAmmo
	(
	int amount,
   firemode_t mode
	)

	{
   if ( UnlimitedAmmo( mode ) )
      return;

   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::UseAmmo", "Invalid mode %d\n", mode );

   // Remove ammo from the clip if it's available
   if ( ammo_clip_size[mode] )
      {
      ammo_in_clip[mode] -= amount;
      if (ammo_in_clip[mode] < 0)
         {
         warning("UseAmmo","Used more ammo than in clip.\n");
         ammo_in_clip[mode] = 0;
         }
      owner->AmmoAmountInClipChanged( ammo_type[mode], ammo_in_clip[mode] );
      }
   else
      {
	   assert( owner );
	   if ( owner && owner->isClient() && !UnlimitedAmmo( mode ) )
		   {
         // Remove ammo from the player's inventory
         owner->UseAmmo( ammo_type[mode], ammorequired[mode] );
		   }
      }

	// Need to check curmode here because 'mode' could inaccurate
	// because of the usesameclip flag
	if ( !usesameclip )
		{
		if ( burstmode[mode] ) 
			{
			burstcount -= ammorequired[mode];
			}
		}
	else
		{
		if ( burstmode[curmode] ) 
			burstcount -= ammorequired[mode];
		}
	}

//======================
//Weapon::GetMuzzlePosition
//======================
void Weapon::GetMuzzlePosition
	(
   Vector *position,
	Vector *forward,
	Vector *right,
	Vector *up
	)

	{
	Vector endpoint, vorg;
   orientation_t barrel_or;
	Vector f, r, u, viewWeapOrg, pview, pos;
	Sentient *owner;
	Player *player;
   
	owner = this->owner;
	assert( owner );

	if ( owner->isSubclassOf( Player ) )
		player = ( Player * )owner;
	else
		{
		warning("GetMuzzlePosition called from Weapon class for a non-player character.",NULL);
		return;
		}

	// Assign player based variables
	vorg = player->origin;
	pview = player->GetVAngles();

	// Offset by the view since the origin is at the feet
	vorg.z += player->viewheight;

	// Get our f, r, u vectors and set an endpoint
	AngleVectors( pview, f, r, u );

	// Create our point in worldspace.  Lots of hardcoded crap here.  
	// This will only work correctly with the default FOV (since we don't have access any real numbers)
	// We also don't have access to the znear value.
	endpoint = GetViewEndPoint();
	Vector dir = endpoint - vorg;
	int len = dir.length();
	dir.normalize();
	endpoint = vorg + dir * (len + 5);
	/*Vector p,s;
	p.x = (float)chx * (-4.0f / 320.0f);
	p.y = (float)chy * (-3.0f / 240.0f);
	s = 4.0f * f + p.x * r + p.y * u;
	s.normalize();
	endpoint = vorg + (s * 3000);*/

	// Now we get the origin of the weapon that the CLIENT knows (first person)
	viewWeapOrg = vorg;
	setScale(0.5); // Client scales the weapon to half-size
	VectorMA( viewWeapOrg, -9, r, viewWeapOrg );
	VectorMA( viewWeapOrg, -7.5, u, viewWeapOrg );
	
	// Weapon is about at viewWeapOrg position, neglecting viewbob/pullback

	// Do a trace to get our endpoint
	trace_t trace = G_Trace( vorg, vec_zero, vec_zero, endpoint, owner, MASK_SHOT, true, "Weapon::GetMuzzlePosition" );
	// Get the tag_barrel of the gun, otherwise use the owners centroid
	if ( !this->GetRawTag( "tag_barrel", &barrel_or ) )
		{
      warning( "Weapon::GetMuzzlePosition", "Could not find tag \"%s\"", current_attachToTag.c_str() );
      *position = owner->centroid;		
		} 
	else
		*position = barrel_or.origin;
	
   // Translate the barrel's orientation through the weapon's orientation
   VectorCopy( viewWeapOrg, pos );
	VectorMA( pos, barrel_or.origin[0], f, pos );
	VectorMA( pos, barrel_or.origin[1], r, pos );
	VectorMA( pos, barrel_or.origin[2], u, pos );

	// Final barrel position
	*position = pos;

	// Now set a NEW f,r,u vector based on changed needed to hit the center of the screen
	Vector f2 = trace.endpos - *position;
	AngleVectors( f2.toAngles(), f, r, u );
   
	if ( forward ) 
		*forward = f;
   if ( right )
      *right = r;
   if ( up )
      *up = u;

	//G_DebugLine( *position, trace.endpos, 1,0,0,1 );
	}

//======================
//Weapon::SetAmmoClipSize
//======================
void Weapon::SetAmmoClipSize
	(
   Event * ev
	)

	{
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
	ammo_clip_size[firemodeindex] = ev->GetInteger( 1 );
	}

//======================
//Weapon::SetAmmoInClip
//======================
void Weapon::SetAmmoInClip
	(
   Event * ev
	)

	{
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
	ammo_in_clip[firemodeindex] = ev->GetInteger( 1 );
	}

//======================
//Weapon::Shoot
//======================
// This function is called from the weapon tiki file
// With a loopfire weapon, this function may be called 
// multiple times without having called "Fire", so we need
// to also call UseAmmo here for loopfire weapons
void Weapon::Shoot
   (
   Event *ev
   )

   {
   Vector      pos, forward, right, up, delta;
   firemode_t  mode = FIRE_MODE1;
	firemode_t  realmode = FIRE_MODE1;

   if ( ev->NumArgs() > 0 )
      {
      mode = WeaponModeNameToNum( ev->GetString( 1 ) );
		realmode = mode;
      if ( mode == FIRE_ERROR )
         return;
      }

	// Override the firemode if we're a switch weapon
	if ( switchmode ) 
		mode = curmode;

/*	if ( next_fire_time[mode] > level.time )
		return;

	// Set the fire timer if we have one
	if ( fire_timer[mode] > 0.0 )
		next_fire_time[mode] = fire_timer[mode] + level.time;*/

	// Set accuracy spread
	bulletspread[mode].x = 50 * accuracy[mode][aimtype];
	bulletspread[mode].y = 50 * accuracy[mode][aimtype];

	if ( usesameclip )
		mode = FIRE_MODE1;

   // If we are in loopfire, we need to keep checking ammo and using it up
   if ( loopfire[mode] )
      {
      if ( HasAmmo( mode ) )
         {
         // Use up the appropriate amount of ammo, it's already been checked that we have enough
         UseAmmo( ammorequired[mode], mode );
			if ( mode != realmode )
				{
				if ( burstmode[realmode] )
					burstcount -= ammorequired[realmode];
				}
			if ( switchmode ) 
				mode = curmode;
         }
      else
         {
			if ( switchmode ) 
				mode = curmode;
			ForceIdle();
         }
      }

   GetMuzzlePosition( &pos, &forward, &right, &up );

   if ( firetype[mode] == FT_PROJECTILE )
      {
      ProjectileAttack( pos,
                        forward,
                        owner,
                        projectileModel[mode],
                        charge_fraction
                      );
      }
   else if ( firetype[mode] == FT_BULLET )
      {
     
		BulletAttack( pos,
                    forward,
                    right,
                    up,
                    bulletrange[mode],
                    bulletdamage[mode],
						  redemptivedamage[mode],
                    bulletknockback[mode],
                    0,
				        GetMeansOfDeath( mode ),
                    bulletspread[mode],
                    bulletcount[mode],
                    owner
                  );
      }
   else if ( firetype[mode] == FT_SPECIAL_PROJECTILE )
      {
      this->SpecialFireProjectile( pos,
                                   forward,
                                   right,
                                   up,
                                   owner,
                                   projectileModel[mode],
                                   charge_fraction
                                 );
      }
	else if ( firetype[mode] == FT_MELEE ) // this is a weapon that fires like a sword
		{
		Vector melee_pos, melee_end;
		Vector dir;
		float damage;
		meansOfDeath_t meansofdeath;
		float knockback;

		dir = owner->centroid - pos;
		dir.z = 0;

		melee_pos = pos - forward * dir.length();
		melee_end = melee_pos + forward * bulletrange[mode];

		damage = bulletdamage[mode];
		knockback = 0;

		// If we have the strength powerup, boost the damage
		if ( owner->isSubclassOf( Player ) )
			{
			Sentient *sent = (Sentient *) owner; // Can't convert from a safe ptr, convert to sent ptr first
			Player *player = (Player *)sent;
			if ( player->GetPowerupType() == POWERUP_STRENGTH )
				damage *= 2.0;
			}

		meansofdeath = GetMeansOfDeath( mode );

      Container<Entity *>victimlist;

		if ( !MeleeAttack( melee_pos, melee_end, damage, owner, meansofdeath, 15, -45, 45, knockback, true, &victimlist ) )
   		{
         // Try to hit the world since we didn't do any damage to anything
	   	trace_t trace = G_Trace( melee_pos, Vector( -8,-8,-8 ), Vector( 8,8,8 ), melee_end, owner, MASK_MELEE, false, "Weapon::Shoot" );

		   Entity *victim = G_GetEntity( trace.entityNum );

		   if ( victim && ( ( victim == world ) || ( victim->takedamage == DAMAGE_NO ) ) )
			   {
			   vec3_t  newangles;
			   vectoangles( trace.plane.normal, newangles );
            WorldHitSpawn( mode, trace.endpos, newangles, 0.1 );

	         str realname = this->GetRandomAlias( "impact_world" );
            if ( realname.length() > 1 )
		         this->Sound( realname, CHAN_VOICE );
			   }
   		}
      }

	if ( !quiet )
		{
		if ( next_noise_time <= level.time )
			{
			BroadcastSound();
			next_noise_time = level.time + 1;
			}
		}
   }

//======================
//Weapon::SetAimAnim
//======================
void Weapon::SetAimAnim
   (
   Event *ev
   )

   {
   str anim;

   anim     = ev->GetString( 1 );
   aimanim  = gi.Anim_NumForName( edict->s.modelindex, anim.c_str() );
   aimframe = ev->GetInteger( 2 );
   }

//======================
//Weapon::SetOwner
//======================
void Weapon::SetOwner
	(
	Sentient *ent
	)

	{
	assert( ent );
	if ( !ent )
		{
		// return to avoid any buggy behaviour
		return;
		}

	Item::SetOwner( ent );

	setOrigin( vec_zero );
   setAngles( vec_zero );
	}

//======================
//Weapon::AmmoAvailable
//======================
int Weapon::AmmoAvailable
   (
   firemode_t mode
   )

   {
   // Returns the amount of ammo the owner has that is available for use
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      {
      warning( "Weapon::AmmoAvailable", "Invalid mode %d\n", mode );
      return 0;
      }

   // Make sure there is an owner before querying the amount of ammo
   if ( owner )
      {
      return owner->AmmoCount( ammo_type[mode] );
      }
   else
      {
      warning( "Weapon::AmmoAvailable", "Weapon does not have an owner.\n" );
      return 0;
      }
   }

//======================
//Weapon::UnlimitedAmmo
//======================
qboolean Weapon::UnlimitedAmmo
   (
   firemode_t mode
   )

   {
	if ( !owner )
		{
		return false;
		}

   if ( !owner->isClient() || ( owner->flags & FL_GODMODE ) || DM_FLAG( DF_INFINITE_AMMO ) )
		{
		return true;
		}
   else if ( !stricmp( ammo_type[mode], "None" ) )
      {
      return true;
      }

   return false;
   }

//======================
//Weapon::HasInvAmmo
//======================
// Checks to see if we have any ammo in general
qboolean Weapon::HasInvAmmo
	(
   firemode_t mode
	)

	{
	if ( !ammorequired[mode] )
		return false;

	return ( AmmoAvailable( mode ) >= ammorequired[mode] );
	}

//======================
//Weapon::HasAmmo
//======================
qboolean Weapon::HasAmmo
	(
   firemode_t mode
	)

	{
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      {
      warning( "Weapon::HasAmmo", "Invalid mode %d\n", mode );
      return false;
      }

	if ( !owner )
		{
		return false;
		}

   if ( UnlimitedAmmo( mode ) )
		{
		return true;
		}

   // If the weapon uses a clip, check for ammo in the right clip
   if ( ammo_clip_size[mode] )
      {
      return HasAmmoInClip( mode );
      }
   else // Otherwise check if ammo is available in general
      {
      if ( !ammorequired[mode] )
         return false;

      return ( AmmoAvailable( mode ) >= ammorequired[mode] );
      }
	}

//======================
//Weapon::HasAmmoInClip
//======================
qboolean Weapon::HasAmmoInClip
	(
	firemode_t mode
	)

	{
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::HasAmmoInClip", "Invalid mode %d\n", mode );

   if ( ammo_clip_size[mode] )
      {
      if ( ammo_in_clip[mode] >= ammorequired[mode] )
	   	{
		   return true;
		   }
      }
   return false;
	}

//======================
//Weapon::ForceState
//======================
void Weapon::ForceState
   (
   weaponstate_t state
   )

   {
   weaponstate = state;
   }

//======================
//Weapon::ReadyToFire
//======================
qboolean Weapon::ReadyToFire
	(
	firemode_t mode,
   qboolean   playsound
	)

	{
   // Make sure the weapon is in the ready state and the weapon has ammo
   if ( weaponstate == WEAPON_READY )
      {
		// If the weapon doesn't take ammo, we're always ready.
		str ammotype = GetAmmoType( ( firemode_t )mode );
		if ( ammotype == "None" )
			return qtrue;

		if ( usesameclip )
			mode = FIRE_MODE1;

	   if ( HasAmmo( mode ) )
         {
         return qtrue;
         }
      if ( playsound && ( level.time >	next_noammo_time ) )
         {
         Sound( "snd_noammo" );
         next_noammo_time = level.time + 0.25f;
         }
      }
   return qfalse;
	}

//======================
//Weapon::PutAway
//======================
void Weapon::PutAway
	(
	void
	)

	{
//	int i;
//	int original_ammo_count;
//	int new_ammo_count;


   // set the putaway flag to true, so the state machine know to put this weapon away
   putaway = true;

	if ( !owner )
		return;

	// Give ammo back to owner
/*
	for( i = 0 ; i < MAX_FIREMODES ; i++ )
		{
		if ( ammo_in_clip[ i ] )
			{
			// Add ammo to owner
			original_ammo_count = owner->AmmoCount( ammo_type[ i ] );
			owner->GiveAmmo( ammo_type[ i ], ammo_in_clip[ i ] );
			new_ammo_count = owner->AmmoCount( ammo_type[ i ] );

			// Subtract ammo from weapon

			ammo_in_clip[ i ] = ammo_in_clip[ i ] - (new_ammo_count - original_ammo_count);

			owner->AmmoAmountInClipChanged( ammo_type[ i ], ammo_in_clip[ i ] );
			}
		}*/
   }

//======================
//Weapon::DetachFromOwner
//======================
void Weapon::DetachFromOwner
	(
	void
	)

	{
   animate->StopAnimating();
   DetachGun();
 	weaponstate = WEAPON_HOLSTERED;
   current_attachToTag = "";
	}

//======================
//Weapon::AttachToOwner
//======================
void Weapon::AttachToOwner
	(
	weaponhand_t hand
	)

	{
   AttachGun( hand );
	if ( regenAmount > 0 )
		PostEvent(EV_Weapon_RegenThink, regenTime);
	if ( targetidle )
		PostEvent(EV_Weapon_TargetIdleThink, TargetIdleTime);
   ForceIdle();
	}

//======================
//Weapon::AttachToHolster
//======================
void Weapon::AttachToHolster
   (
   weaponhand_t hand
   )

   {
   AttachGun( hand, qtrue );
   animate->RandomAnimate( "holster", EV_Weapon_Idle );
   }

//======================
//Weapon::Drop
//======================
qboolean Weapon::Drop
	(
	void
	)

	{
   float radius;
   Vector temp;

	if ( !owner )
		{
		return false;
		}

   if ( !IsDroppable() )
      {
      return false;
      }

   DetachGun();

   temp[ 2 ] = 40;
   if ( owner )
      {
      setOrigin( owner->origin + temp );
      }
   else
      {
      setOrigin( origin + temp );
      }

   // hack to fix the bounds when the gun is dropped
   // once dropped reset the rotated bounds
   flags |= FL_ROTATEDBOUNDS;

   gi.CalculateBounds( edict->s.modelindex, edict->s.scale, mins, maxs );
   radius = ( mins - maxs ).length() * 0.25f;
   mins.x = mins.y = -radius;
   maxs.x = maxs.y = radius;
   setSize( mins, maxs );

   // stop animating
   animate->SetFrame( 0 );

	// drop the weapon
	PlaceItem();
   if ( owner )
      {
      temp[ 0 ] = G_CRandom( 50 );
      temp[ 1 ] = G_CRandom( 50 );
      temp[ 2 ] = 100;
	   velocity = owner->velocity * 0.5 + temp;
	   setAngles( owner->angles );
      }

	avelocity = Vector( 0, G_CRandom( 360 ), 0 );

   // FIXME - Make this work right if we need it
   /*
	if ( owner && owner->isClient() )
		{
		spawnflags |= DROPPED_PLAYER_ITEM;
      if ( ammo_clip_size )
         startammo = ammo_in_clip;
      else
         startammo = 0;

      // If owner is dead, put all his ammo of that type in the gun.
      if ( owner->deadflag )
         {
         startammo = AmmoAvailable();
         }
		}
	else
		{
		spawnflags |= DROPPED_ITEM;
      if ( ammo_clip_size && ammo_in_clip )
         startammo = ammo_in_clip;
      else
         startammo >>= 2;

      if ( startammo == 0 )
         {
         startammo = 1;
         }
		}
   */

   // Wait some time before the last owner can pickup this weapon
   last_owner = owner;
   last_owner_trigger_time = level.time + 2.5f;

   // Cancel reloading events
   CancelEventsOfType( EV_Weapon_DoneReloading );

   // Remove this from the owner's item list
   if ( owner )
      {
      owner->RemoveItem( this );
      }

   owner = NULL;

   // Fade out dropped weapons, to keep down the clutter
   PostEvent( EV_FadeOut, 30 );
	return true;
	}

//======================
//Weapon::Charge
//======================
void Weapon::Charge
   (
   firemode_t mode
   )

   {
   }

//======================
//Weapon::ReleaseFire
//======================
void Weapon::ReleaseFire
   (
   firemode_t mode,
   float      charge_time
   )

   {
   // Calculate and store off the charge fraction to use when the weapon actually shoots

   // Clamp to max_charge_time
   if ( charge_time > max_charge_time[mode] )
      charge_fraction = 1.0f;
   else
      charge_fraction = charge_time / max_charge_time[mode];

   // Call regular fire function
   Fire( mode );
   }

//======================
//Weapon::Fire
//======================
// This function is called from the state machine
// to tell the tiki which weapon animation to play
// The tiki file will most likely post the "shoot" event
// shortly after this function is called
void Weapon::Fire
	(
	firemode_t mode
	)

	{
   Event *done_event=NULL;
	firemode_t realmode;
   Vector pos;
	char anim[128];

   // Sanity check the mode
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::Fire", "Invalid mode %d\n", mode );

	realmode = mode;

	// Override the firemode if we're a switch weapon
	if ( switchmode )
		mode = curmode;

	if ( next_fire_time[mode] > level.time )
		return;

	// Set the fire timer if we have one
	if ( fire_timer[mode] > 0.0 )
		next_fire_time[mode] = fire_timer[mode] + level.time;

   // If we are in loopfire mode, then we don't pass a DoneFiring event
   if ( !loopfire[mode] )
      {
      // The DoneFiring event requires to know the firing mode so save that off in the event
      done_event = new Event( EV_Weapon_DoneFiring );
      done_event->AddInteger( mode );
      }

   // Set the state of the weapon to FIRING
	weaponstate = WEAPON_FIRING;

   // Cancel any old done firing events
	CancelEventsOfType( EV_Weapon_DoneFiring );

   // Play the correct animation
	if ( !switchmode )
		{
		if ( mode == FIRE_MODE1 )
			animate->RandomAnimate( "fire", done_event );
		else if ( mode == FIRE_MODE2 )
			animate->RandomAnimate( "alternatefire", done_event );
		}
	else
		{
		sprintf(anim,"fire_mode%d",(int)mode+1);
		if ( animate->HasAnim( anim ) )
			animate->RandomAnimate( anim, done_event );
		}

	// Use up the appropriate amount of ammo, it's already been checked that we have enough
	if ( usesameclip )
		mode = FIRE_MODE1;

	if ( ammorequired[mode] != ammorequired[realmode] )
		UseAmmo(ammorequired[realmode], mode);
	else
		UseAmmo( ammorequired[mode], mode );
	if ( mode != realmode )
		{
		if ( burstmode[realmode] )
			burstcount -= ammorequired[realmode];
		}
	}

//======================
//Weapon::DetachGun
//======================
void Weapon::DetachGun
	(
	void
	)

	{
	if ( attached )
		{
		StopSound( CHAN_WEAPONIDLE );
      attached = false;
      detach();
		hideModel();
		}
	}

//======================
//Weapon::AttachGun
//======================
void Weapon::AttachGun
	(
	weaponhand_t   hand,
   qboolean       holstering
	)

	{
	int tag_num = 0;

	if ( !owner )
		{
      current_attachToTag = "";
		return;
		}

   if (attached)
      {
      DetachGun();
		return;
      }

	// This is somewhat of a HACK.  setViewModel sets the viewmodelindex.
	// This is really the worldmodel, I don't want to go and change "viewmodel"
	// in every function to "worldmodel" just to do the same thing.
	if ( worldmodel.length() > 4) // at least has a .tik on it
		setViewModel(worldmodel);

   if ( holstering )
      {
      // Save off these values if we are holstering the weapon.  We will restore them when
      // the users raises the weapons again.
      lastAngles = this->angles;
      lastScale  = this->edict->s.scale;
      lastValid  = qtrue;
      }
   else if ( lastValid )
      {
      // Restore the last
      setScale( lastScale );
      setAngles( lastAngles );
      lastValid = qfalse;
      }

   switch( hand )
      {
		case WEAPON_DUAL:
         if ( holstering )
            {
            current_attachToTag = rightholster_attachToTag;
            setAngles( rightHolsterAngles );
            setScale( holsterScale );
            }
         else
            {
            current_attachToTag = right_attachToTag;
            }
         break;

      default:
         warning( "Weapon::AttachGun", "Invalid hand for attachment of weapon specified" );
         break;
      }

   if ( !current_attachToTag.length() )
      return;

   tag_num = gi.Tag_NumForName( owner->edict->s.modelindex, this->current_attachToTag.c_str() );

   NoLerpThisFrame();
	if	( tag_num >= 0 )
	   {
      attached = true;
 		attach( owner->entnum, tag_num );
		showModel();
		setOrigin();
		}
	else
		{
      warning( "Weapon::AttachGun", "Attachment of weapon to tag \"%s\": Tag Not Found\n", this->current_attachToTag.c_str() );
		}
	}

//======================
//Weapon::GiveStartingAmmoToOwner
//======================
void Weapon::GiveStartingAmmoToOwner
   (
   Event *ev
   )

   {
   str   ammotype;
   int   mode;

   assert( owner );

   if ( !owner )
      {
      warning( "Weapon::GiveStartingAmmoToOwner", "Owner not found\n" );
      return;
      }

   // Give the player the starting ammo
   for ( mode=FIRE_MODE1; mode<MAX_FIREMODES; mode++ )
      {
      ammotype = GetAmmoType( ( firemode_t )mode );
      if ( ammotype.length() )
         {
         owner->GiveAmmo( ammotype, this->GetStartAmmo( ( firemode_t )mode ) );
         }
      }
   }
//======================
//Weapon::PickupWeapon
//======================
void Weapon::PickupWeapon
	(
	Event *ev
	)

	{
   Sentient       *sen;
   Entity         *other;
   Weapon         *weapon;
   qboolean       hasweapon;
   //qboolean       giveammo[MAX_FIREMODES];
   //int            mode;

   other = ev->GetEntity( 1 );
   assert( other );

   if ( !other->isSubclassOf( Sentient ) )
      {
      return;
      }

   sen = ( Sentient * )other;

   // If this is the last owner, check to see if he can pick it up
   if ( ( sen == last_owner ) && ( level.time < last_owner_trigger_time ) )
      {
      return;
      }

	hasweapon = sen->HasItem( item_name );

   if ( !hasweapon )
      {
      weapon = ( Weapon * )ItemPickup( other );
      if ( !weapon )
         {
         // Item Pickup failed, so don't give ammo either.
         return;
         }
      }
/*   else
      {
      for ( mode = FIRE_MODE1; mode < MAX_FIREMODES; mode++ )
         {
         giveammo[mode] = ( sen->isClient() && ammo_type[mode].length() && startammo[mode] );

         if ( !giveammo[mode] )
            {
            return;
            }

         sen->GiveAmmo( ammo_type[mode].c_str(), startammo[mode] );
         }
      } */
   }

//======================
//Weapon::ForceIdle
//======================
void Weapon::ForceIdle
   (
   void
   )

   {
   // Force the weapon to the idle animation
	weaponstate = WEAPON_READY;

	// Clear our fire timer
	//INITIALIZE_WEAPONMODE_VAR(next_fire_time, 0.0);
	
	float r = G_Random(100.0f);
	char anim[128];


	// If this is a switchmode weapon, we have a very different idle system
	if ( switchmode )
		{
		if ( r < 5.0f )
			{
			sprintf(anim,"idle_rare_mode%d",(int)curmode+1);
			if ( animate->HasAnim( anim ) )
				{
				animate->RandomAnimate( anim );
				return;
				}
			}

		if ( r < 15.0 )
			{
			sprintf(anim,"idle_uncommon_mode%d",(int)curmode+1);
			if ( animate->HasAnim( anim ) )
				{
				animate->RandomAnimate( anim );
				return;
				}
			}
		
		sprintf(anim,"idle_common_mode%d",(int)curmode+1);
		if ( animate->HasAnim( anim ) )
			{
			animate->RandomAnimate( anim );
			return;
			}
		
		// We shouldn't get here if the anims are set up correctly
		// for the switch mode weapon
		animate->RandomAnimate("idle");
		return;
		}

	if ( r < 5.0f && animate->HasAnim("idle_rare") )
		{
		animate->RandomAnimate( "idle_rare" );
		return;
		}

	if ( r < 15.0 && animate->HasAnim("idle_uncommon") )
		{
		animate->RandomAnimate("idle_uncommon");
		return;
		}
	
	if ( animate->HasAnim("idle_common") )
		{
		animate->RandomAnimate( "idle_common" );
		return;
		}

	// We shouldn't get here if the anims are set up correctly
	animate->RandomAnimate("idle");
	}

//======================
//Weapon::DoneRaising
//======================
void Weapon::DoneRaising
	(
	Event *ev
	)

	{
	weaponstate = WEAPON_READY;
   ForceIdle();

	if ( !owner )
		{
		PostEvent( EV_Remove, 0 );
		return;
		}

	// Done raising, start regeneration if we do.
	if ( regenAmount != 0 )
		PostEvent(EV_Weapon_RegenThink, regenTime);
	if ( targetidle )
		PostEvent(EV_Weapon_TargetIdleThink, TargetIdleTime);
	}

//======================
//Weapon::ClientFireDone
//======================
void Weapon::ClientFireDone
   (
   void
   )

   {
   // This is called when the client's firing animation is done
   }

//======================
//Weapon::DoneFiring
//======================
void Weapon::DoneFiring
	(
	Event *ev
	)

	{
   // This is called when the weapon's firing animation is done 
	// If this weapon has a fire_stop animation, play it (tiki will force us back to idle)
	if ( animate->HasAnim("fire_stop") )
		animate->RandomAnimate("fire_stop");
	else
		ForceIdle();

   // Check to see if the auto_putaway flag is set, and the weapon is out of ammo.  If so, then putaway the
   // weapon.
   if (
      ( !HasAmmo( FIRE_MODE1 )   || ( !stricmp( ammo_type[ FIRE_MODE1 ], "None" ) ) ) &&
      ( !HasAmmo( FIRE_MODE2 ) || ( !stricmp( ammo_type[ FIRE_MODE2 ], "None" ) ) ) &&
      auto_putaway
      )
      {
      PutAway();
      }
	}

//======================
//Weapon::DoneReloading
//======================
void Weapon::DoneReloading
	(
	Event *ev
	)

	{
   int         amount;
   int         amount_used;
   firemode_t  mode;

   // Get the mode from the passed in event
   mode = (firemode_t)ev->GetInteger( 1 );

   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::DoneReloading", "Invalid mode %d\n", mode );

	if ( regenAmount > 0 )
		{
		int tmpamount = 0;
		Ammo *ammo;
		ammo = owner->FindAmmoByName( ammo_type[mode] );
		if ( ammo ) 
			{
			tmpamount = (ammo->getMaxAmount() / 2) - owner->AmmoCount( ammo_type[mode] );
			owner->GiveAmmo( ammo_type[ mode ],  tmpamount);
			ForceIdle();
			return;
			}
		}

	// If we need to do a REAL reload (not a burst reload) we skip the test
	// altogether.
	firemode_t realmode = mode;
	if ( usesameclip )
		mode = FIRE_MODE1;
	if ( !(ammo_clip_size[mode] && !ammo_in_clip[mode] && AmmoAvailable(mode)) )
		{
		int tmp = 0;
		if ( switchmode )
			tmp = burstmode[curmode];
		else
			tmp = burstmode[realmode];

		if ( tmp )
			{
			int tmpamount = 0;
			Ammo *ammo;
			ammo = owner->FindAmmoByName( ammo_type[mode] );
			if ( ammo ) 
				{
				tmpamount = owner->AmmoCount( ammo_type[mode] );
				
				// Try the clip ammo if we have none in our main inventory
				if ( tmpamount == 0 ) 
					tmpamount = ammo_in_clip[mode];

				if ( tmpamount > burstcountmax )
					burstcount = burstcountmax;
				else 
					burstcount = tmpamount;
				
				// We're out of ammo
				if ( burstcount == 0 )
					burstcount = -1;

				ForceIdle();
				return;
				}
			}
		}

   // Calc the amount the clip should get
   amount = ammo_clip_size[mode] - ammo_in_clip[mode];

   assert( owner );
	if ( owner && owner->isClient() && !UnlimitedAmmo( mode ) )
		{
      // use up the ammo from the player
      amount_used = owner->UseAmmo( ammo_type[mode], amount );

      // Stick it in the clip
      if ( ammo_clip_size[mode] )
         ammo_in_clip[mode] = amount_used + ammo_in_clip[mode];

      assert( ammo_in_clip[mode] <= ammo_clip_size[mode] );
      if ( ammo_in_clip[mode] > ammo_clip_size[mode] )
         ammo_in_clip[mode] = ammo_clip_size[mode];

		if ( burstmode[curmode] && ammo_in_clip[mode] >= burstcountmax )
			burstcount = burstcountmax;
 		}
   owner->AmmoAmountInClipChanged( ammo_type[mode], ammo_in_clip[mode] );

   ForceIdle();
   }

//======================
//Weapon::CheckReload - Checks to see if we NEED to reload the weapon
//======================
qboolean Weapon::CheckReload
	(
	firemode_t mode
	)

	{
   // Check to see if the weapon needs to be reloaded
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::CheckReload", "Invalid mode %d\n", mode );

	if ( putaway )
		return false;
	
	// If we're a burst mode weapon, see if we need to "reload"
	int tmp = 0;
	if ( switchmode )
		tmp = burstmode[curmode];
	else
		tmp = burstmode[mode];
	firemode_t oldmode = mode;
	if ( usesameclip )
		mode = FIRE_MODE1;
	if ( tmp && weaponstate != WEAPON_RELOADING && burstcount <= 0 )
		{
		if ( !(ammo_clip_size[mode] && !ammo_in_clip[mode] && AmmoAvailable( mode )) )
			{
			Event *ev1;
			ev1 = new Event( EV_Weapon_DoneReloading );
			ev1->AddInteger( oldmode );
			animate->RandomAnimate( "idle_special", ev1 );
			weaponstate = WEAPON_RELOADING;
			return true;
			}
		}
	mode = oldmode;

	if ( usesameclip && mode > FIRE_MODE1 )
		return false;

	if ( weaponstate != WEAPON_READY )
      return false;

   if ( ammo_clip_size[mode] && !ammo_in_clip[mode] && AmmoAvailable( mode ) )
      {
      Event *ev1;

      ev1 = new Event( EV_Weapon_DoneReloading );
      ev1->AddInteger( mode );

      if ( animate->HasAnim( "reload" ) )
         {
   	   weaponstate = WEAPON_RELOADING;
         animate->RandomAnimate( "reload", ev1 );
         }
      else
         {
         ProcessEvent( ev1 );
         }
      return true;
      }

	// We're a regenerating weapon out of ammo
	if ( !AmmoAvailable(mode) && regenAmount > 0 )
		{
		Event *ev1;

      ev1 = new Event( EV_Weapon_DoneReloading );
      ev1->AddInteger( mode );

      if ( animate->HasAnim( "idle_special" ) )
         {
   	   weaponstate = WEAPON_RELOADING;
         animate->RandomAnimate( "idle_special", ev1 );
         }
      else
         {
         ProcessEvent( ev1 );
         }
		return true;
		}

   return false;
	}

//======================
//Weapon::ForceReload - Reload the clip if it's not full already
//======================
qboolean Weapon::ForceReload
	(
	)

	{
	// Only primary mode can reload
	firemode_t mode = FIRE_MODE1;

	// Weapon has to be in the ready state
   if ( weaponstate != WEAPON_READY )
      return false;

	// Make sure it's not put away
	if ( putaway )
		return false;

	// We can't reload regenerating weapons
	if ( regenAmount > 0 )
		return false;

	// If our clip is not full and we have ammo available...
	// HACK: targetidle is currently only used on the TOW weapon,
	// so instead of making an entirely new event JUST for this, we use it here.
   if ( ( ( ammo_clip_size[mode] != ammo_in_clip[mode] ) && AmmoAvailable( mode ) ) || targetidle)
      {
      Event *ev1;

      ev1 = new Event( EV_Weapon_DoneReloading );
      ev1->AddInteger( mode );

      if ( animate->HasAnim( "reload" ) )
         {
   	   weaponstate = WEAPON_RELOADING;
         animate->RandomAnimate( "reload", ev1 );
         }
      else
         {
         ProcessEvent( ev1 );
         }
      return true;
      }

   return false;
	}

//======================
//Weapon::Idle
//======================
void Weapon::Idle
	(
	Event *ev
	)

	{
   ForceIdle();
	}

//======================
//Weapon::GetMaxRange
//======================
float	Weapon::GetMaxRange
	(
	void
	)

	{
	return maxrange;
	}

//======================
//Weapon::GetMinRange
//======================
float	Weapon::GetMinRange
	(
	void
	)

	{
	return minrange;
	}

//======================
//Weapon::SetMaxRangeEvent
//======================
void Weapon::SetMaxRangeEvent
	(
	Event *ev
	)

	{
	maxrange = ev->GetFloat( 1 );
	}

//======================
//Weapon::SetMinRangeEvent
//======================
void Weapon::SetMinRangeEvent
	(
	Event *ev
	)

	{
	minrange = ev->GetFloat( 1 );
	}

//======================
//Weapon::NotDroppableEvent
//======================
void Weapon::NotDroppableEvent
	(
	Event *ev
	)

	{
   notdroppable = true;
	}

//======================
//Weapon::SetMaxRange
//======================
void Weapon::SetMaxRange
	(
	float val
	)

	{
	maxrange = val;
	}

//======================
//Weapon::SetMinRange
//======================
void Weapon::SetMinRange
	(
	float val
	)

	{
	minrange = val;
	}

//======================
//Weapon::WeaponSound
//======================
void Weapon::WeaponSound
	(
	Event *ev
	)

	{
	Event *e;

	// Broadcasting a sound can be time consuming.  Only do it once in a while on really fast guns.
	if ( nextweaponsoundtime > level.time )
		{
		if ( owner )
			{
			owner->BroadcastSound(SOUND_RADIUS, SOUNDTYPE_WEAPONFIRE);;
			}
		else
			{
			BroadcastSound(SOUND_RADIUS, SOUNDTYPE_WEAPONFIRE);;
			}
		return;
		}

	if ( owner )
		{
		e = new Event( ev );
		owner->ProcessEvent( e );
		}
	else
		{
		Item::BroadcastSound();
		}

	// give us some breathing room
	nextweaponsoundtime = level.time + 0.4;
	}

//======================
//Weapon::Removable
//======================
qboolean Weapon::Removable
   (
   void
   )

   {
   if (
         ( ( int )( dmflags->integer ) & DF_WEAPONS_STAY ) &&
         !( spawnflags & ( DROPPED_ITEM | DROPPED_PLAYER_ITEM ) )
      )
      return false;
   else
      return true;
   }

//======================
//Weapon::Pickupable
//======================
qboolean Weapon::Pickupable
   (
   Entity *other
   )

   {
   Sentient *sen;

   if ( !other->isSubclassOf( Sentient ) )
		{
		return false;
		}
   else if ( !other->isClient() )
      {
      return false;
      }

   sen = ( Sentient * )other;

   //FIXME
   // This should be in player

   // If we have the weapon and weapons stay, then don't pick it up
   if ( ( ( int )( dmflags->integer ) & DF_WEAPONS_STAY ) && !( spawnflags & ( DROPPED_ITEM | DROPPED_PLAYER_ITEM ) ) )
      {
      Weapon   *weapon;

      weapon = ( Weapon * )sen->FindItem( getName() );

      if ( weapon )
         return false;
      }

   return true;
   }

//======================
//Weapon::AutoChange
//======================
qboolean Weapon::AutoChange
   (
   void
   )

   {
   return true;
   }

//======================
//Weapon::ClipAmmo
//======================
int Weapon::ClipAmmo
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( !( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) ) )
      warning( "Weapon::ClipAmmo", "Invalid mode %d\n", mode );

   if (ammo_clip_size)
      return ammo_in_clip[mode];
   else
      return -1;
   }

//======================
//Weapon::ProcessWeaponCommandsEvent
//======================
void Weapon::ProcessWeaponCommandsEvent
	(
	Event *ev
	)

	{
   int index;

   index = ev->GetInteger( 1 );
   ProcessInitCommands( index );
	}

//======================
//Weapon::SetActionLevelIncrement
//======================
void Weapon::SetActionLevelIncrement
   (
   Event *ev
   )
   {
	assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   action_level_increment[firemodeindex] = ev->GetInteger( 1 );
   }

//======================
//Weapon::ActionLevelIncrement
//======================
int Weapon::ActionLevelIncrement
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      return action_level_increment[mode];
   else
      {
      warning( "Weapon::ActionLevelIncrement", "Invalid mode %d\n", mode );
      return 0;
      }
   }

//======================
//Weapon::IsDroppable
//======================
qboolean Weapon::IsDroppable
	(
	void
	)
	{
	if ( notdroppable )
		{
		return false;
		}
   else
      {
      return true;
      }
   }

//======================
//Weapon::SetFireType
//======================
void Weapon::SetFireType
   (
   Event *ev
   )

   {
   str ftype;

   ftype = ev->GetString( 1 );

   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );

   if ( !ftype.icmp( "projectile" ) )
      firetype[firemodeindex] = FT_PROJECTILE;
   else if ( !ftype.icmp( "bullet" ) )
      firetype[firemodeindex] = FT_BULLET;
   else if ( !ftype.icmp( "melee" ) )
      firetype[firemodeindex] = FT_MELEE;
   else if ( !ftype.icmp( "special_projectile" ) )
      firetype[firemodeindex] = FT_SPECIAL_PROJECTILE;
   else if ( !ftype.icmp( "none" ) )
      firetype[firemodeindex] = FT_NONE;
   else
      warning( "Weapon::SetFireType", "unknown firetype: %s\n", ftype.c_str() );
   }

//======================
//Weapon::GetFireType
//======================
firetype_t Weapon::GetFireType
   (
   firemode_t mode
   )

   {
   return firetype[mode];
   }

//======================
//Weapon::SetProjectile
//======================
void Weapon::SetProjectile
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   projectileModel[firemodeindex] = ev->GetString( 1 );
   CacheResource( projectileModel[firemodeindex].c_str(), this );
   }

//======================
//Weapon::SetBulletDamage
//======================
void Weapon::SetBulletDamage
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   bulletdamage[firemodeindex] = ev->GetFloat( 1 );
   }

//======================
//Weapon::SetBulletKnockback
//======================
void Weapon::SetBulletKnockback
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   bulletknockback[firemodeindex] = ev->GetFloat( 1 );
   }

//======================
//Weapon::SetBulletRange
//======================
void Weapon::SetBulletRange
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   bulletrange[firemodeindex] = ev->GetFloat( 1 );
   }

//======================
//Weapon::SetRange
//======================
void Weapon::SetRange
   (
   Event *ev
   )

   {
   SetBulletRange( ev );
   }

//======================
//Weapon::SetBulletCount
//======================
void Weapon::SetBulletCount
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   bulletcount[firemodeindex] = ev->GetFloat( 1 );
   }

//======================
//Weapon::SetBulletSpread
//======================
void Weapon::SetBulletSpread
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   bulletspread[firemodeindex].x = ev->GetFloat( 1 );
   bulletspread[firemodeindex].y = ev->GetFloat( 2 );
   }

//======================
//Weapon::SetHand
//======================
void Weapon::SetHand
   (
   Event *ev
   )

   {
   str side;

   side = ev->GetString( 1 );

  /* if ( !stricmp( side.c_str(), "righthand" ) || !stricmp( side.c_str(), "right" ) )
      hand = WEAPON_RIGHT;
   else if ( !stricmp( side.c_str(), "lefthand" ) || !stricmp( side.c_str(), "left" ) )
      hand = WEAPON_LEFT;*/
   if ( !stricmp( side.c_str(), "dualhand" ) || !stricmp( side.c_str(), "dual" ) )
      hand = WEAPON_DUAL;
  /* else if ( !stricmp( side.c_str(), "any" ) )
      hand = WEAPON_ANY;*/
   else
      {
      warning( "Weapon::SetHand", "Unknown side %s\n", side.c_str() );
      assert( 0 );
      }
   }

//======================
//Weapon::Alternate - old code, delete me
//======================
void Weapon::Alternate
   (
   Event *ev
   )

   {
   int i;

   Event *modeev = new Event( ev->GetToken( 1 ) );

	firemodeindex = FIRE_MODE2;

   for( i=2; i<=ev->NumArgs(); i++ )
      {
      modeev->AddToken( ev->GetToken( i ) );
      }

   ProcessEvent( modeev );
   firemodeindex = FIRE_MODE1;
   }

//======================
//Weapon::ModeSet
//======================
void Weapon::ModeSet
   (
   Event *ev
   )

   {
   int i;
	str modestr;

   Event *modeev = new Event( ev->GetToken( 2 ) );

   modestr = ev->GetToken( 1 );

	firemodeindex = WeaponModeNameToNum(modestr);

   for( i=3; i<=ev->NumArgs(); i++ )
      {
      modeev->AddToken( ev->GetToken( i ) );
      }

   ProcessEvent( modeev );
   firemodeindex = FIRE_MODE1;
   }

//====================
//Weapon::AutoAim
//====================
void Weapon::AutoAim
   (
   Event *ev
   )

   {
   autoaim = true;
   }

//====================
//Weapon::Crosshair
//====================
void Weapon::Crosshair
   (
   Event *ev
   )

   {
   crosshair = ev->GetBoolean( 1 );
   }

//====================
//Weapon::TorsoAim
//====================
void Weapon::TorsoAim
   (
   Event *ev
   )

   {
   torsoaim = ev->GetBoolean( 1 );
   }

//====================
//Weapon::LeftAttachToTag
//====================
void Weapon::LeftAttachToTag
   (
   Event *ev
   )

   {
   left_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::RightAttachToTag
//====================
void Weapon::RightAttachToTag
   (
   Event *ev
   )

   {
   right_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::DualAttachToTag
//====================
void Weapon::DualAttachToTag
   (
   Event *ev
   )

   {
   dual_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::LeftHolsterAttachToTag
//====================
void Weapon::LeftHolsterAttachToTag
   (
   Event *ev
   )

   {
   leftholster_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::RightHolsterAttachToTag
//====================
void Weapon::RightHolsterAttachToTag
   (
   Event *ev
   )

   {
   rightholster_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::DualHolsterAttachToTag
//====================
void Weapon::DualHolsterAttachToTag
   (
   Event *ev
   )

   {
   dualholster_attachToTag = ev->GetString( 1 );
   }

//====================
//Weapon::SetLeftHolsterAngles
//====================
void Weapon::SetLeftHolsterAngles
   (
   Event *ev
   )

   {
   leftHolsterAngles = ev->GetVector( 1 );
   }

//====================
//Weapon::SetRightHolsterAngles
//====================
void Weapon::SetRightHolsterAngles
   (
   Event *ev
   )

   {
   rightHolsterAngles = ev->GetVector( 1 );
   }

//====================
//Weapon::SetDualHolsterAngles
//====================
void Weapon::SetDualHolsterAngles
   (
   Event *ev
   )

   {
   dualHolsterAngles = ev->GetVector( 1 );
   }

//====================
//Weapon::SetHolsterScale
//====================
void Weapon::SetHolsterScale
   (
   Event *ev
   )

   {
   holsterScale = ev->GetFloat( 1 );
   }

//====================
//Weapon::SetQuiet
//====================
void Weapon::SetQuiet
   (
   Event *ev
   )

   {
   quiet = true;
   }

//====================
//Weapon::SetLoopFire
//====================
void Weapon::SetLoopFire
   (
   Event *ev
   )

   {
	assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   loopfire[firemodeindex] = true;
   }

//======================
//Weapon::SetMeansOfDeath
//======================
void Weapon::SetMeansOfDeath
   (
   Event *ev
   )

   {
	assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
	meansofdeath[firemodeindex] = (meansOfDeath_t )MOD_string_to_int( ev->GetString( 1 ) );
   }

//======================
//Weapon::GetMeansOfDeath
//======================
meansOfDeath_t Weapon::GetMeansOfDeath
   (
   firemode_t mode
   )

   {
   assert( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) );

   if ( ( mode >= 0 ) && ( mode < MAX_FIREMODES ) )
      return meansofdeath[mode];
   else
      {
      warning( "Weapon::GetMeansOfDeath", "Invalid mode %d\n", mode );
      return MOD_NONE;
      }
   }

//======================
//Weapon::SetAimTarget
//======================
void Weapon::SetAimTarget
   (
   Entity *ent
   )

   {
   aim_target = ent;
   }

//======================
//Weapon::WorldHitSpawn
//======================
void Weapon::WorldHitSpawn
   (
   firemode_t  mode,
   const Vector      &origin,
   const Vector      &angles,
   float       life
   )

   {
   if ( !worldhitspawn[mode].length() )
      return;

   Entity *ent;

   ent = new Entity( ENTITY_CREATE_FLAG_ANIMATE );
   ent->setModel( worldhitspawn[mode] );
   ent->setMoveType( MOVETYPE_NONE );
   ent->animate->RandomAnimate( "idle" );
   ent->setOrigin( origin );
   ent->setAngles( angles );

   ent->PostEvent( EV_Remove, life );
   }

//======================
//Weapon::SetWorldHitSpawn
//======================
void Weapon::SetWorldHitSpawn
   (
   Event *ev
   )

   {
   assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
	worldhitspawn[firemodeindex] = ev->GetString( 1 );
   }

void Weapon::MakeNoise
   (
   Event *ev
   )

   {
	float radius = 500;
	qboolean force = false;

	if ( ev->NumArgs() > 0 )
		radius = ev->GetFloat( 1 );

	if ( ev->NumArgs() > 1 )
		force = ev->GetBoolean( 2 );

	if ( attached && ( next_noise_time <= level.time || force ) )
		{
		BroadcastSound( radius , SOUNDTYPE_WEAPONFIRE );
		next_noise_time = level.time + 1;
		}
	}

//======================
//Weapon::SetViewModel
//======================
void Weapon::SetWorldModel
   (
   Event *ev
   )
	{
	if ( ev->NumArgs() > 0 )
		worldmodel = ev->GetString( 1 );
   }

void Weapon::DonePutaway
	(
	Event *ev
	)

	{
	// Tell the state machine we're lowering the weapon
	// so it will continue to do it's normal deactivate code
	weaponstate = WEAPON_LOWERING;

	// Kill any regeneration going on if we are doing it
	if ( regenAmount != 0 || regenTime != 0.0 )
		{
		CancelEventsOfType( EV_Weapon_RegenThink );	
		}
	if ( targetidle )
		CancelEventsOfType( EV_Weapon_TargetIdleThink );
	}

void Weapon::SetRegenAmmo
   (
   Event *ev
   )
	{
	if ( ev->NumArgs() > 0 )
		{
		regenAmount = atoi(ev->GetString( 1 ));	
		regenTime = 1.0; // default time
		}
	if ( ev->NumArgs() > 1 )
		regenTime = atof(ev->GetString( 2 ));
   }

void Weapon::RegenThink
   (
   Event *ev
   )
	{
   CancelEventsOfType( EV_Weapon_RegenThink );
   PostEvent( EV_Weapon_RegenThink, regenTime );

	if ( owner )
		{ 
		owner->GiveAmmo( ammo_type[ FIRE_MODE1 ], regenAmount );
		}
   }

void Weapon::ChangeIdle
	(
	Event *ev
	)

	{
   ForceIdle();

	if ( !owner )
		{
		PostEvent( EV_Remove, 0 );
		return;
		}
	}

void Weapon::DrawBowStrain
   (
   Event *ev
   )
	{
	if ( animate->HasAnim( "draw_strain" ) )
		animate->RandomAnimate( "draw_strain" );
	}

void Weapon::AltDrawBowStrain
   (
   Event *ev
   )
	{
	if ( animate->HasAnim( "alternate_draw_strain" ) )
		animate->RandomAnimate( "alternate_draw_strain" );
	}

void Weapon::SetAccuracy
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() < 6 )
		{
		gi.DPrintf("SetAccuracy: Too few parameters\n");
		return;
		}
	firemode_t mode = WeaponModeNameToNum( ev->GetToken( 1 ) );
	accuracy[mode][ACCURACY_STOPPED] = ev->GetFloat( 2 );
	accuracy[mode][ACCURACY_CHANGE] = ev->GetFloat( 3 );
	accuracy[mode][ACCURACY_WALK] = ev->GetFloat( 4 );
	accuracy[mode][ACCURACY_RUN] = ev->GetFloat( 5 );
	accuracy[mode][ACCURACY_CROUCH] = ev->GetFloat( 6 );
	}

void Weapon::SetZoomFOV
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() > 0 )
		zoomfov = ev->GetFloat( 1 );
	}

void Weapon::SetReticuleTime
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() > 0 )
		reticuletime = ev->GetFloat( 1 );
	}

void Weapon::SetRedemptive
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() > 0 )
		redemptive = ev->GetBoolean( 1 );
	}

void Weapon::SetAimType
	(
	Event *ev
	)
	{
	
	str aimstr;

	Sentient *owner;
	Player *player = NULL;
	owner = this->owner;
	assert( owner );
	if ( owner->isSubclassOf( Player ) )
		player = ( Player * )owner;

	if ( ev->NumArgs() > 0 )
		aimstr = ev->GetString( 1 );

	// Crouching is a special case... you'll always have the "crouch" accuracy
	// rating in your crouched, regardless of whether you're walking or not.
	if ( player && player->GetCrouch() || aimstr == "crouch")
		aimtype = ACCURACY_CROUCH;
	else 
		{
		if ( aimstr == "stopped" )
			aimtype = ACCURACY_STOPPED;	
		if ( aimstr == "walk" )
			aimtype = ACCURACY_WALK;
		if ( aimstr == "run" )
			aimtype = ACCURACY_RUN;
		if ( aimstr == "change" )
			aimtype = ACCURACY_CHANGE;
		}

	if ( aimstr != "stopped" && aimstr != "walk" && aimstr != "run" 
		&& aimstr != "crouch" && aimstr != "change" )
		{
		warning("SetAimType: Invalid aimtype, %s, defaulting to stopped",aimstr);
		aimtype = ACCURACY_STOPPED;
		}

	if ( g_showaccuracymod->integer )
		gi.DPrintf("Accuracy Mod: %s = %f\n", aimstr.c_str(), accuracy[curmode][aimtype] );
	}

void Weapon::SetFireTimer
	(
	Event *ev
	)
	{
   firemode_t  mode = FIRE_MODE1;

   if ( ev->NumArgs() > 0 )
      {
      mode = WeaponModeNameToNum( ev->GetString( 1 ) );

      if ( mode == FIRE_ERROR )
         return;
      }
	if ( ev->NumArgs() > 1 )
		{
		fire_timer[mode] += ev->GetFloat( 2 );
		}

	}

void Weapon::UseSameClip
	(
	Event *ev
	)
	{
	usesameclip = qtrue;
	}

void Weapon::SetRedemptiveDamage
	(
	Event *ev
	)
	{
	assert( ( firemodeindex >= 0 ) && ( firemodeindex < MAX_FIREMODES ) );
   redemptivedamage[firemodeindex] = ev->GetFloat( 1 );
	}

qboolean Weapon::HasFullClip
	(
	)
	{
	firemode_t mode = FIRE_MODE1;

	if ( ammo_in_clip[mode] == ammo_clip_size[mode] )
		return qtrue;

	return qfalse;
	}

void Weapon::SetAccuracyPowerup
	( 
	qboolean powerOn
	)
	{
	accPowerup = powerOn;
	}

void Weapon::SetMaxModes
	(
	Event *ev
	)
	{
	if ( ev->NumArgs() < 1 )
		{
		maxmode = FIRE_MODE2;
		return;
		}

	maxmode = WeaponModeNameToNum( ev->GetToken( 1 ) );
	}

void Weapon::SetSwitchMode
	(
	Event *ev
	)
	{
	switchmode = qtrue;
	}

// Target Idle Weapon functions
void Weapon::TargetIdle
	(
	Event *ev
	)
	{
	targetidle = qtrue;
	}

void Weapon::TargetIdleThink
   (
   Event *ev
   )
	{
   CancelEventsOfType( EV_Weapon_TargetIdleThink );

	// HACK sortof: If the weapon is playing it's put away animation,
	// we don't do this event.  For some reason a CancelEventsOfType
	// call in the Putaway function failed to cancel this event.
	if  ( animate->GetName() == "putaway" )
		return;

   PostEvent( EV_Weapon_TargetIdleThink, TargetIdleTime );
	
	Sentient *owner;
	Player *player;
	owner = this->owner;
	assert( owner );



	if ( owner->isSubclassOf( Player ) )
		{
		player = ( Player * )owner;
		Vector pos, forward, right, up, endpoint, vorg;   
		GetMuzzlePosition( &pos, &forward, &right, &up );
		vorg = player->origin;
		vorg.z += player->viewheight;

		endpoint = vorg + (forward * 4000);
		trace_t trace = G_Trace( pos, vec_zero, vec_zero, endpoint, player, MASK_SHOT, true, "Weapon::TargetIdleThink" );
		if ( trace.ent && trace.entityNum != ENTITYNUM_WORLD && trace.ent->entity->isSubclassOf( Sentient ))
			{
			if ( !trace.ent->entity->deadflag )
				{
				if ( !strstr(animate->GetName(), "idle_target") )
					animate->RandomAnimate( "idle_target" );
				targetidleflag = qtrue;
				}
			return;
			}
		else 
			if ( targetidleflag )
				{
				targetidleflag = qfalse;
				ForceIdle();
				}

		}
   }
// ****************************

// Weapon Mode switching functions
void Weapon::SwitchMode
   (
   )

   {
	char anim[128];

	Event *ev1;
   ev1 = new Event( EV_Weapon_DoneSwitchToMiddle );

	strcpy(anim,"");
	sprintf(anim,"switch_mode%d_neutral",(int)curmode+1);

   if ( animate->HasAnim( anim ) )
      {
   	weaponstate = WEAPON_SWITCHINGMODE;
      animate->RandomAnimate( anim, ev1 );
      }
   else
      {
      ProcessEvent( ev1 );
      }
	}

void Weapon::DoneSwitchToMiddle
	(
	Event *ev
	)
	{
	int mode;
	char anim[128];

	Event *ev1;
   ev1 = new Event( EV_Weapon_DoneSwitching );

	if ( curmode == maxmode )
		mode = FIRE_MODE1;
	else
		mode = (int)curmode + 1;
	
	strcpy(anim,"");
	sprintf(anim,"switch_mode%d",mode);

   if ( animate->HasAnim( anim ) )
      {
   	weaponstate = WEAPON_SWITCHINGMODE;
      animate->RandomAnimate( anim, ev1 );
      }
   else
      {
      ProcessEvent( ev1 );
      }
	}

void Weapon::DoneSwitching
	(
	Event *ev
	)
	{
	if ( curmode == maxmode )
		curmode = FIRE_MODE1;
	else
		curmode = (firemode_t)((int)curmode + 1);

	weaponstate = WEAPON_READY;
	
	// Clear our fire timer
	INITIALIZE_WEAPONMODE_VAR(next_fire_time, 0.0);
	
	ForceIdle();
	}
// *************

void Weapon::SetBurstMode
	(
	Event *ev
	)
	{
	burstmode[firemodeindex] = qtrue;
	if ( ev->NumArgs() > 0 )
		burstcountmax = ev->GetInteger( 1 );
	else
		burstcountmax = 10; // Default to 10

	burstcount = burstcountmax;
	}

void Weapon::SetCHOffset(int chx, int chy)
	{
	this->chx = chx;
	this->chy = chy;
	}

// This function returns the endpoint of where the crosshair is located on the
// screen.  Regardless of whether we're in camera, first or 3rd person view.
Vector Weapon::GetViewEndPoint()
	{
	Sentient *owner = this->owner;
	Player *player;
	playerState_s *ps;
	trace_t trace;
	Vector f,r,u,p,s;
	Vector pos, forward, endpoint, vorg, dir;

	if ( !owner->isSubclassOf( Player ) )
		return Vector(0,0,0);

	player = (Player *)owner;
	ps = &player->client->ps;

	if (ps->pm_flags & PMF_CAMERA_VIEW ) // 3rd person automatic camera
		{
		vorg = ps->camera_origin;
		AngleVectors( ps->camera_angles, f, r, u );
		}
	else if ( !thirdperson ) // First person
		{
		vorg = player->origin;
		vorg.z += player->viewheight;
		AngleVectors( player->GetVAngles(), f, r, u );
		}
	else // Third person
		{
		vorg = realvieworg;
		AngleVectors( player->GetVAngles(), f, r, u );
		}

	float xmax,ymax, fov_x, fov_y, x;

   fov_x = player->client->ps.fov;
	x = 640 / tan( fov_x / 360 * M_PI );
	fov_y = atan2( 480, x );
	fov_y = fov_y * 360 / M_PI;

	ymax = 4.0f * tan( fov_y * M_PI / 360.0 );
	xmax = 4.0f * tan( fov_x * M_PI / 360.0 );
	
	p.x = (float)chx * (-xmax / 320.0f);
	p.y = (float)chy * (-ymax / 240.0f);
	s = 4.0f * f + p.x * r + p.y * u;
	s.normalize();
	endpoint = vorg + (s * 3000);	

	//G_DebugLine( vorg + (f * 6), endpoint, 1,0,1,1 );

	trace = G_Trace( vorg, vec_zero, vec_zero, endpoint, player, MASK_SHOT, true, "Weapon::GetViewEndPoint" );
	endpoint = trace.endpos;

	return endpoint;
	}

qboolean Weapon::GetTargeted()
	{
	Sentient *owner;
	owner = this->owner;
	Player *player;
	Vector f,r,u,p,s;
	Vector pos, forward, endpoint, vorg, dir; 
	playerState_s *ps;
	trace_t trace;
	int len;

	if ( owner->isSubclassOf( Player ) )
		{
		player = ( Player * )owner;
		ps = &player->client->ps;
		GetMuzzlePosition( &pos, NULL, NULL, NULL ); // Just need the position of the muzzle
		endpoint = GetViewEndPoint();
		
		// Get the vector from the muzzle to the crosshair + alittle
		dir = endpoint - pos;
		len = dir.length();
		dir.normalize();
		endpoint = pos + dir * (len + 5);
		
		//G_DebugLine( pos, endpoint, 1,1,1,1 );
		trace = G_Trace( pos, vec_zero, vec_zero, endpoint, player, MASK_SHOT, true, "Weapon::GetTarget2" );
		if ( trace.ent && trace.entityNum != ENTITYNUM_WORLD && trace.ent->entity->isSubclassOf( Sentient ))
			{
			if ( !trace.ent->entity->deadflag )
				return qtrue;
			}
		}
	return false;
	}

void Weapon::SetRealViewOrigin( Vector rv )
	{
	realvieworg = rv;
	}

void Weapon::SetThirdPerson( qboolean tp )
	{
	thirdperson = tp;
	}