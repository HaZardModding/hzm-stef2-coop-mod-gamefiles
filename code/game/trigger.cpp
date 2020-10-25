//hzm gameupdate/coop mod chrissstrahl - used for the LevelEditor to update descriptions of new features to the triggers

/* ############################## ENTITY BIND ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_bind(1 1 0) (-8 -8 -8) (8 8 8) UNBIND
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Binds a entity to the specified (master) entity (this is used for script objects)

"uservar1" Specifies master entity 
"uservar2-10" Entity targetnames meant to be bound to master (will overwrite target)
"target" Entity to bind to master
*/

/* ############################## ACTOR HEADWATCH ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_headwatch(1 1 0) (-8 -8 -8) (8 8 8) NOT_ACTIVATOR CLOSEST_PLAYER WATCH_ACTIVATOR STOP
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Makes Actor watch given entity

[ if ] STOP is set, the Actor will stop watching
[ if ] NOT_ACTIVATOR is set, the Activating actor will not be handled
[ if ] CLOSEST_PLAYER is set, the actor will turn towards their closest player
[ if ] TOWARDS_ACTIVATOR is set, the actor will turn towards the activator

"uservar1" Entity to watch
"uservar2" Head turn speed
"uservar3-10" Targetname of actors to handle
"target" Sets Actor to handle (uservar3-10 overwrite)
*/

/* ############################## ACTOR TURNTOWARDS ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_turntowards(1 1 0) (-8 -8 -8) (8 8 8) NOT_ACTIVATOR CLOSEST_PLAYER TOWARDS_ACTIVATOR
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Turns Actor towards given entity

[ if ] NOT_ACTIVATOR is set, the Activating actor will not be handled
[ if ] CLOSEST_PLAYER is set, the actor will turn towards their closest player
[ if ] TOWARDS_ACTIVATOR is set, the actor will turn towards the activator

"uservar1" Entity to turn towards to
"uservar2" Extra yaw to turn
"uservar3-10" Targetname of actors to handle
"target" Sets Actor to handle (uservar3-10 overwrite)
*/

/* ############################## ENTITY VIEWMODE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_viewmode(1 1 0) (-8 -8 -8) (8 8 8) REMOVE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Makes a Entity visible for players only if in specified Tricorder-Viewmode

"uservar1" Viewmode-Name
"uservar2-10" Entity targetnames to apply the viewmode to (will overwrite target)
"target" Entity to apply the viewmode to

:::AVIALABLE VIEWMODES:::::::::
tracegas
structuralintegrity
phaseshift
nightvision
torpedostrike
enemydetect
tripwire
*/

/* ############################## ENTITY ARCHETYPE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_archetype(1 1 0) (-8 -8 -8) (8 8 8) REMOVE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets Archetype of Entity

[ if ] REMOVE is set any archetype will be removed instead

"uservar1" Specifies Archetype to set
"uservar2-10" Entity targetnames meant to set Archetype to
"target" Entity to set Archetype
*/

/* ############################## ACTOR FIELDOFVIEW ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_fieldofview(1 1 0) (-8 -8 -8) (8 8 8) NOT_ACTIVATOR
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets the field of view of a Actor, allows for easier stealth missions

[ if ] NOT_ACTIVATOR is set the activating Actor will not be handled

"uservar1" Field of view angle
"uservar2" Vision distance
"uservar3-10" Targetname of actors to handle
"target" Sets Actor to handle (uservar3-10 overwrite)
*/

/* ############################## WORLD WATER ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_water(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] sets Water Color and Water alpha

"uservar1" sets water color [vector](0 0 0 - 1 1 1)
"uservar2" sets water alpha ( 0-1 )
*/

/* ############################## WORLD BROKEN ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_broken(1 1 0) (-8 -8 -8) (8 8 8) REMOVE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Adds a Broken Item/Weapon to the Level
[ ! ] May not work with all weapons and items!

"uservar1-10" sets name of broken item

:::WEAPONS::::::::
attrex-rifle
batleth
burstrifle
compressionrifle
drull-staff
enterprise
fieldassaultrifle
grenadelauncher
IMod
phaser
phaser-STX
photon
rom-datapad
rom-radgun
rom-disruptor
sniperrifle
tetryon
tricorder
tricorder-STX
:::TIKI PATH EXAMPLE:::
models/weapons/worldmodel-IMod.tik
*/

/* ############################## WORLD VIEWMODE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_viewmode(1 1 0) (-8 -8 -8) (8 8 8) REMOVE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Adds Tricorder-Viewmode the the level

"uservar1-6" Viewmode-Name

:::AVIALABLE VIEWMODES:::::::::
tracegas
structuralintegrity
phaseshift
torpedostrike
enemydetect
tripwire
*/

/* ############################## PLAYER HUD ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_player_hud(1 1 0) (-8 -8 -8) (8 8 8) REMOVE ALL_PLAYERS
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Adds a Hud to player(s)

[ if ] REMOVE is set, the hud will be removed instead
[ if ] ALL_PLAYERS is set, this applies to all players

"uservar1" sets the name of the hud to add
*/

/* ############################## MISSION MARKER ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_mission_marker(1 1 0) (-8 -8 -8) (8 8 8) UNMARK
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Marks a Mission relevant entity on the Radar
[ info ] This also works with Coop Levels

[ if ] UNMARK is set the objects will be unmarked (removed from the radar)

"uservar1" sets targetname of object to mark
*/

/* ############################## GAME SAVE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_game_save(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Creates a savegame
[ ! ] Only works in Singleplayer

"uservar1" sets the name of the savegame (minimum 3, maximum 32 Letters)
*/

/* ############################## WORLD FOG ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_fog(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets fog on the world

"uservar1" sets distance the player can see (min: 512, Max: 10000 )
"uservar2" sets distance entities are visible  (min: 2048, Max: 10000 )
"uservar3" set the fog color (from 0 0 0 to 1 1 1)
*/

/* ############################## WORLD WEATHER ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_weather(1 1 0) (-8 -8 -8) (8 8 8) RAIN RAIN_PLAIN SNOW
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Stops or starts weather on the level, if nothing is selected it will stop

[ if ] RAIN is set it will rain
[ if ] RAIN_PLAINE is set it will rain (without splash effects)
[ if ] SNOW is set it wil snow

"uservar1" sets amount of weather (min: 0, Max: 400 )
*/

/* ############################## WORLD PHYSICS ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_world_physics(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets the world its physics parameters

"uservar1" sets gravity (min: 50, Max: 1600 )
"uservar2" sets maxSpeed (min: 50, Max: 2000 )
"uservar3" sets airAccelerate (min: 1, Max: 3 )
*/

/* ############################## MISSION STORY ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_mission_story(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] sets a mission story for the player(s)
[ info ] Story is shown in the Coop Mission Objective Menu

"uservar1" sets English Mission Backgroundstory
"uservar2" sets German Mission Backgroundstory
*/

/* ############################## MISSION TACTICAL ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_mission_tactical(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] sets tactical info for player(s)
[ info ] tactical info is shown in the Coop Mission Objective Menu 

"uservar1" sets tactical info 1 text in english
"uservar2" sets tactical info 2 text in english
"uservar3" sets tactical info 3 text in english
"uservar4" sets tactical info 1 text in german
"uservar5" sets tactical info 2 text in german
"uservar6" sets tactical info 3 text in german

/* ############################## MISSION OBJECTIVE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_mission_ojective(1 1 0) (-8 -8 -8) (8 8 8) COMPLETE FAIL
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] sets a mission objective for the player(s)
[ info ] objectives are shown in the Coop Mission Objective Menu

[ if ] COMPLETE is set the objective will be completed
[ if ] FAIL is set the objective will be failed

"uservar1" sets objective item number (1-8)
"uservar2" sets objective english text
"uservar3" sets objective german text
*/

/* ############################## MISSION COMPLETE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_mission_complete(1 1 0) (-8 -8 -8) (8 8 8) FAIL SHOW_SUCCESS
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets mission status

[ if ] FAIL is set the mission will fail instead
[ if ] SHOW_SUCCESS is set the Mission Success Screen will be shown

"uservar1" sets next map to load
"uservar2" sets English reason of failure
"uservar3" sets German reason of failure
*/

/* ############################## DOOR MANAGE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_door_manage(1 1 0) (-8 -8 -8) (8 8 8) OPEN CLOSE UNLOCK LOCK
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Manages func_door entities

[ if ] OPEN is set the door will open (if not locked)
[ if ] CLOSE is set the door will close (if not closed)
[ if ] UNLOCK is set the door will unlock
[ if ] LOCK is set the door lock

"target" sets the entity that is meant to play the animation
*/

/* ############################## ENTITY ANIMATE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_animate(1 1 0) (-8 -8 -8) (8 8 8) HOLD IDLE AI_ON DIE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Animates any Entity.
[ info ] To work on a actor, AI_OFF must be set on the actor
[ info ] Does not work on MAKE_STATIC Models
[ info ] Some Animations might not work on all Models

== Works only with Actors ==
[ if ] HOLD is set the animation will be played once and held at the last frame
[ if ] IDLE is set the animation will be played once, followed by the idle animation
[ if ] AI_ON is set the ai will activate after the animation (needs ONCE enabled)
[ if ] DIE is set the ai will die after the animation (needs ONCE enabled)
===

"uservar1" sets the animation to play
"target" sets the entity that is meant to play the animation
*/

/* ############################## ENTITY SCALE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_scale(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Scales the attached Model of a entity, but not the entity it self.

"uservar1" sets scale to set
*/

/* ############################## ENTITY CONTENTS ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_contents(1 1 0) (-8 -8 -8) (8 8 8) NOT_SOLID
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets the contents of a entity to solid.

[ if ] NOT_SOLID is set the entity will become notsolid

"target" sets target entity
*/

/* ############################## ENTITY VISIBILITY ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_visibility(1 1 0) (-8 -8 -8) (8 8 8) HIDE SHOW DEPTH NO_DEPTH
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Handles the visibility of a entity
[ WARNING ] Even if hidden the entity its contents will still be solid!

[ if ] SHOW is set the entity will become visible
[ if ] HIDE is set the entity will become invisible
[ if ] DEPTH is set the entity will become visible through objects
[ if ] NO_DEPTH is set the it will cancel the effects of DEPTH

"target" sets the entity that is meant to be affected
*/

/* ############################## ENTITY HEALTH ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_health(1 1 0) (-8 -8 -8) (8 8 8) ADD TAKE IMMORTAL NOT_IMMORTAL ALL_PLAYERS
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets health of a entity to value of uservar1, (including Actors and triggers)
[ info ] if no target set, this will apply to the activator

[ if ] ADD is set the health ammount in uservar1 will be added
[ if ] TAKE is set the health ammount in uservar1 will be taken
=== WORKS ONLY ON ACTORS ===
[ if ] IMMORTAL is set the entity will go down to 1 health but not below and it will not die
[ if ] NOT_IMMORTAL is set the effect of IMMOTRTAL is canceled (some Actors start as immortal on default)
===
[ if ] ALL_PLAYERS is set the this will affect all players

"uservar1" sets the ammount of health to set, add or take
"uservar2" sets the maximum/minimum health to set when ADD/TAKE is set
"target" sets the entity that is meant to be handled
*/

/* ############################## ENTITY WARP ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_warp(1 1 0) (-8 -8 -8) (8 8 8) ANTI_STUCK NOT_ACTIVATOR FORCE_ANGLE NO_VELOCITY ALL_PLAYERS
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Warps a entity to the new location

[ if ] ANTI_STUCK is set the entity will be warped and made notsolid untill it has been cleared of all players and actors
[ ! ] ANTI_STUCK will make entity solid
[ if ] NOT_ACTIVATOR is set the activating entity will not be moved
[ if ] FORCE_ANGLE is set the angle of the targer or set in uservar2 will be enforced
[ if ] NO_VELOCITY is set the velocity of the entity will be set to 0 before moving it
[ if ] ALL_PLAYERS is set it will only move the players

"target" sets the targeted entity its position as destination (do not set uservar1)
"uservar1" sets the new coordinates	(if set it will overwrite target)
"uservar2" sets the new angles (facing direction overwrites target angle)
"uservar3" sets a offset to the given location (X Y Z)
"uservar4-10" sets targetname of entity to be moved
*/

/* ############################## ENTITY TRANSPORT ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_entity_transport(1 1 0) (-8 -8 -8) (8 8 8) ANTI_STUCK NOT_ACTIVATOR FORCE_ANGLE ALL_PLAYERS ROMULAN IDRYLL BORG
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Transports a entity to the new location

[ if ] ANTI_STUCK is set the entity will be warped and made notsolid untill it has been cleared of all players and actors
[ ! ] ANTI_STUCK will make entity solid
[ if ] NOT_ACTIVATOR is set the activating entity will not be handled
[ if ] FORCE_ANGLE is set the angle of the targer or set in uservar2 will be enforced
[ if ] ALL_PLAYERS is set it will only move the players
[ if ] ROMULAN is set the beam animation will be romulan
[ if ] IDRYLL is set the beam animation will be idryll
[ if ] BORG is set the beam animation will be borg

"target" sets the targeted entity its position as destination (do not set uservar1)
"uservar1" sets the new coordinates	(if set it will overwrite target)
"uservar2" sets the new angles (facing direction overwrites target angle)
"uservar3" sets a offset to the given location (X Y Z)
"uservar4-10" sets targetname of entity to be moved
*/

/* ############################## TRIGGER ENABLE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_trigger_enable(1 1 0) (-8 -8 -8) (8 8 8) DISABLE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Enables a trigger so it can be activated

[ if ] DISABLE is set the trigger will be disabled instead

"uservar1" sets the targetname of the trigger to enable/disable
*/´

/* ##############################  ACTOR AI ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_ai(1 1 0) (-8 -8 -8) (8 8 8) AI_ON AI_OFF AGGRESSIVE NOT_AGGRESSIVE SLEEP WAKEUP DISABLE NOT_DISABLE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Turns ON/OFF actor ai among other things.

[ if ] AI_ON is set the trigger will turn the actor ai ON
[ if ] AI_OFF is set the trigger will turn the actor ai OFF
[ if ] AGGRESSIVE is set the actor will attack its enemies (needs ai_on)
[ if ] NOT_AGGRESSIVE is set the actor will stop beeing aggressive
[ if ] SLEEP is set the actor will sleep until a enemy is spotted  (needs ai_on)
[ if ] WAKEUP is set the actor will sleep until a enemy is spotted  (needs ai_on)
[ if ] DISABLE is set the actor will be disabled (needs ai_on)
[ if ] NOT_DISABLE is set the actor will be no longer be disabled (needs ai_on)

"target" specifies the actor to control
*/

/* ##############################  ACTOR DEATH ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_death(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Activates given trigger/door/entity once the actor has been killed

"delay" sets delay in seconds of this trigger firing
"target" specifies the actor
"uservar1" specifies the trigger to activate if this Actor dies
"uservar2" sets English reason of failure
"uservar3" sets German reason of failure
*/

/* ############################## ACTOR PLAYDIALOG ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_playdialog(1 1 0) (-8 -8 -8) (8 8 8) HEAD_HUD WAITFORDIALOG AI_ON
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Will make Actor play a dialog
[ info ] Dialogs are played from:
loc/Eng/sound/dialog/ AND ALSO loc/Deu/sound/dialog/
[ info ] set path like this: dm/mp_picard1.mp3

[ if ] HEAD_HUD is set a HUD with the Head of the Actor will be shown
[ if ] WAITFORDIALOG is set the trigger/door in uservar4 will be activated on dialog end
[ if ] AI_ON is set the Actor ai will be activated after the dialog

"uservar1" part of the path from the dialog to play
"uservar2" volume of the dialog, default 1
"uservar3" minimum hearing distance for the dialog, default 128
"uservar4" trigger/door to activate when the dialog is finished (needs WAITFORDIALOG set)
"target" specifies the actor to play this dialog
"delay" will delay the firing of this trigger
*/

/* ############################## ACTOR WALKTO ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_actor_walkto(1 1 0) (-8 -8 -8) (8 8 8) RUN AI_ON
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.
[ ! ] For this to work you need to place info_pathnodes to layout the path a actor can take.

[ info ] Makes targeted actor walk to a specific info_pathnodes

[ default ] actor will be using the animation "walk"
[ if ] RUN is set the actor will run (if supported)
[ if ] AI_ON is set the ai of the actor will turn be enabled after reaching its destination

"uservar1" specifies the targetname of the info_pathnode where the actor should go to
"uservar2" specifies the animation to use instead of "walk" or "run"
"uservar3" specifies the entity that shall be triggered after the actor has reached its destination
"target" specifies the actor to control
*/

/* ############################## CINEMATIC START ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_start(1 1 0) (-8 -8 -8) (8 8 8) LETTER_BOX MOVE_ACTIVATOR ANTI_STUCK
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Starts a cinematic sequence

[ if ] LETTER_BOX is set, the game will add cinematic letterboxes (also hiding the hud)
[ if ] MOVE_ACTIVATOR is set, the activating player will be moved to the entity or position specified in uservar1
[ if ] ANTI_STUCK and MOVE_ACTIVATOR is set, the activator will handled in a fashion so it will not become stuck in a actor or player

"uservar1" specifies a entity or coordinates to move the activator to
"uservar2" specifies the angle the activator should look towards to after being moved (only if uservar1 holds cooridinates)
*/

/* ############################## CINEMATIC SKIP ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_skip(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Allows to skip the current ciematic sequence by players

"target" sets the trigger to activate when cinematic is skipped
*/

/* ############################## CINEMATIC END ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_end(1 1 0) (-8 -8 -8) (8 8 8) LETTER_BOX FADE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Ends a cinematic sequence
*/

/* ############################## CINEMATIC CUECAMERA ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_cuecamera(1 1 0) (-8 -8 -8) (8 8 8) CUT
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets view of players to camera position

[ if ] CUT is set, the transition to the camera will be instant, without transition from the current camera

"uservar1" sets the time the transition between the player view and camera will take
"target" specified the targetname of the camera to view from
*/

/* ############################## CINEMATIC FOLLOWPATH ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_followpath(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets path the camera is suppose to follow

"uservar1" specifies the targetname of the camera
"uservar2" specifies the targetname of the camera
*/

/* ############################## CINEMATIC FOV ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_cinematic_fov(1 1 0) (-8 -8 -8) (8 8 8)
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sets view of field angle on a camera. Will force a cut to this camera

"uservar1" specifies the field of view angle
"target" specified the targetname of the camera to view from
*/


/* ############################## camera ############################ */
/*****************************************************************************/
/*QUAKED camera (0 0 0) (-4 -4 -4) (4 4 4)
[ ! ] This is a fixed camera entity.
[ ! ] Requires a targetname to work.
[ ! ] Needs to be controlled, has no function of its own

[ info ] Used for cinematic sequences

"targetname" sets targetname of camera
*/

/* ##############################  PLAYER FOREACH ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_player_foreach(1 1 0) (-8 -8 -8) (8 8 8) SPECTATORS NOT_DEAD
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Activates entity (or entities) once for each player that is on the server

[ if ] SPECTATORS is set spectators will be counted in
[ if ] NOT_DEAD is set dead/respawning players will not be counted in
[ if ] uservar1 is set, it will be counted up for each player by 1,
starting from 1 to 8, as follows: $targetname1, $targetname2, $targetname3...

"target" sets a trigger/door/entity to activate (will be overwritten if uservar1 is set)
"uservar1" sets the targetname of the trigger to activate (without ending number)
"uservar2" sets the minimum of times this trigger should be fired
"uservar3" sets the maximum of times this trigger should be fired
"uservar4" additional times this trigger should be fired
"wait" sets time to wait between each activation
*/

/* ############################## PLAYER ITEM ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_player_item(1 1 0) (-8 -8 -8) (8 8 8) TAKE ALL_PLAYERS REGISTER USE
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Gives a item (weapon/powerup...) to player(s)

[ default ] gives weapon to the activating player
[ if ] TAKE is set, the item will be taken instead
[ if ] ALL_PLAYERS is set, all players will get the item
[ if ] REGISTER is set the item will be given upon spawning (max 15 items)
[ if ] TAKE and REGSITER are both set the item will be unregistred
[ if ] USE is set the Player will instantly use the item (switch to weapon)

"uservar1-10" item model or item name

:::WEAPONS::::::::
attrex-rifle
batleth
burstrifle
compressionrifle
drull-staff
enterprise
fieldassaultrifle
grenadelauncher
IMod
phaser
phaser-STX
photon
rom-datapad
rom-radgun
rom-disruptor
sniperrifle
tetryon
tricorder
tricorder-STX
:::TIKI PATH EXAMPLE:::
models/weapons/worldmodel-IMod.tik
*/

/* ############################## PLAYER AMMO ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_player_ammo(1 1 0) (-8 -8 -8) (8 8 8) ALL_PLAYERS
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Gives ammo to player(s)
[ info ] Ammo types are: Plasma, Phaser, Idryll, Fed
[ info ] Accepts also negative value in uservar2

[ if ] ALL_PLAYERS is set, all players will get ammo

"uservar1" ammo type name
"uservar2" amount of ammo to give
*/

/* ############################## MESSAGE PLAYER ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_player_message(1 1 0) (-8 -8 -8) (8 8 8) ALL_PLAYERS CENTER_PRINT
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Sends a message to player(s)

[ default ] sends the message to the activating player
[ if ] ALL_PLAYERS is set, the message will be shown to all valid players
[ if ] CENTER_PRINT is set, the message will also be printed to the center of the screen

"uservar1" specifies the maximum distance the players can have to the trigger to see the message
"uservar2" specifies the minimum distance the players need to have to the trigger to see the message
"message" the text to show to player(s)
*/


/* ############################## MESSAGE CONSOLE ############################ */
/*****************************************************************************/
/*QUAKED trigger_coop_console_message(1 1 0) (-8 -8 -8) (8 8 8) WARNING
[ ! ] This fixed size trigger cannot be touched, it can only be fired by other events or triggers.

[ info ] Prints a message to the game console used for server log

[ if ] WARNING is set the message will only be printed if com_printwarnings is active

"message" the text to print to console
*/


/*****************************************************************************/
/*QUAKED trigger_multiple (1 0 0) ? x x NOT_PLAYERS MONSTERS PROJECTILES SCRIPTSLAVE

Variable sized repeatable trigger.  Must be targeted at one or more entities.

If "delay" is set, the trigger waits some time after activating before firing.

If "destructible" is set, the trigger will take damage and lose health.
If "triggerondamage" is set, trigger will fire when ever it takes damage.
If "triggerondeath" is set, trigger will fire when it dies.  This forces destructible
to be on, since it would otherwise never die.
If "instantdeath" is set, trigger will die when it takes damage of this type.

To make a trigger fire every time it takes damage set triggerondamage to true.  To make a 
trigger fire everytime it takes damage and to eventually die, set triggerondamage
to true, destructible to true, and give it a health.  To make a trigger that
triggers on death only, set triggerondeath to be true.  This will also turn
on destructible.  To make a trigger that triggers everytime it takes damage
and when it dies, set both triggerondamage to be true and triggerondeath to
be true.

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

if "angle" is set, the trigger will only fire when someone is facing the
direction of the angle.
"cone" the cone in which a directed trigger can be triggered (default 60 degrees)

"wait" : Seconds between triggerings. (.2 default)
"cnt" how many times it can be triggered (infinite default)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)
if SCRIPTSLAVE is set, the trigger will respond to script slaves

set "message" to text string

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_relay (1 0 0) (-8 -8 -8) (8 8 8) x x NOT_PLAYERS MONSTERS PROJECTILES

This fixed size trigger cannot be touched, it can only be fired by other events.
It can contain killtargets, targets, delays, and messages.

If NOT_PLAYERS is set, the trigger does not respond to events triggered by players
If MONSTERS is set, the trigger will respond to events triggered by monsters
If PROJECTILES is set, the trigger will respond to events triggered by projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_secret (1 0 0) ? NOTOUCH x NOT_PLAYERS MONSTERS PROJECTILES
Secret counter trigger.  Automatically sets and increments script variables \
level.total_secrets and level.found_secrets.

set "message" to text string

"key" The item needed to activate this. (default nothing)

if "angle" is set, the trigger will only fire when someone is facing the
direction of the angle.
"cone" the cone in which a directed trigger can be triggered (default 60 degrees)

"thread" name of thread to trigger.  This can be in a different script file as well \
by using the '::' notation.  (defaults to "global/universal_script.scr::secret")

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOTOUCH is set, trigger will not respond to touch
If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_setvariable (1 0 0) ? NOTOUCH LEVEL NOT_PLAYERS MONSTERS PROJECTILES

Sets a variable specified by "variable" and "value".
Variable is assumed to be of the "global" variety unless LEVEL is set.
Variable sized trigger. Triggers once by default.
You must set the key "target" to the name of another object in the
level that has a matching

"variable" - variable to set
"value" - value to set in variable, value can also be one of the following reserved\
tokens.
   - "increment" - add one to the variable
   - "decrement" - subtract one from the variable
   - "toggle" - if 1, then zero.  If zero then 1.

If "health" is set, the trigger must be killed to activate it.
If "delay" is set, the trigger waits some time after activating before firing.

"targetname".  If "health" is set, the trigger must be killed to activate.

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

if "killtarget" is set, any objects that have a matching "target" will be
removed when the trigger is fired.

if "angle" is set, the trigger will only fire when someone is facing the
direction of the angle.
"cone" the cone in which a directed trigger can be triggered (default 60 degrees)

"key" The item needed to activate this. (default nothing)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOTOUCH is set, trigger will not respond to touch
if LEVEL is set, variable will be a level variable otherwise it will be a game variable
If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

set "message" to text string

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_once (1 0 0) ? NOTOUCH x NOT_PLAYERS MONSTERS PROJECTILES SCRIPTSLAVE 7 8
this is a test -----------------------

Variable sized trigger. Triggers once, then removes itself.
You must set the key "target" to the name of another object in the
level that has a matching

If "health" is set, the trigger must be killed to activate it.
If "delay" is set, the trigger waits some time after activating before firing.

"targetname".  If "health" is set, the trigger must be killed to activate.

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

if "killtarget" is set, any objects that have a matching "target" will be
removed when the trigger is fired.

if "angle" is set, the trigger will only fire when someone is facing the
direction of the angle.
"cone" the cone in which a directed trigger can be triggered (default 60 degrees)

"key" The item needed to activate this. (default nothing)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOTOUCH is set, trigger will not respond to touch
If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)
If SCRIPTSLAVE is set, the trigger will respond to script slaves

set "message" to text string

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_push (1 0 0) ? x x NOT_PLAYERS NOT_MONSTERS NOT_PROJECTILES

Pushes entities as if they were caught in a heavy wind.

"speed" indicates the rate that entities are pushed (default 1000).

"angle" indicates the direction the wind is blowing (-1 is up, -2 is down)

"key" The item needed to activate this. (default nothing)

"target" if target is set, then a velocity will be calculated based on speed

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not push players
If NOT_MONSTERS is set, the trigger will not push monsters
If NOT_PROJECTILES is set, the trigger will not push projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_pushany (1 0 0) ? x x NOT_PLAYERS NOT_MONSTERS NOT_PROJECTILES

Pushes entities as if they were caught in a heavy wind.

"speed" indicates the rate that entities are pushed (default 1000).
"angles" indicates the direction of the push
"key" The item needed to activate this. (default nothing)
"target" if target is set, then a velocity will be calculated based on speed

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not push players
If NOT_MONSTERS is set, the trigger will not push monsters
If NOT_PROJECTILES is set, the trigger will not push projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED sound_speaker (0 0.75 0.75) (-8 -8 -8) (8 8 8) AMBIENT-ON AMBIENT-OFF NOT_PLAYERS MONSTERS PROJECTILES TOGGLE

play a sound when it is used

AMBIENT-ON specifies an ambient sound that starts on
AMBIENT-OFF specifies an ambient sound that starts off
TOGGLE specifies that the speaker toggles on triggering

if (AMBIENT-?) is not set, then the sound is sent over explicitly this creates more net traffic

"volume" how loud 0-4 (1 default full volume, ambients do not respond to volume)
"noise" sound to play
"channel" channel on which to play sound\
(0 auto, 1 weapon, 2 voice, 3 item, 4 body, 8 don't use PHS) (voice is default)
"key" The item needed to activate this. (default nothing)
"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

Normal sounds play each time the target is used.

Ambient Looped sounds have a volume 1, and the use function toggles it on/off.

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED sound_randomspeaker (0 0.75 0.75) (-8 -8 -8) (8 8 8) x x NOT_PLAYERS MONSTERS PROJECTILES x x

play a sound at random times

"mindelay" minimum delay between sound triggers (default 3)
"maxdelay" maximum delay between sound triggers (default 10)
"chance" chance that sound will play when fired (default 1)
"volume" how loud 0-4 (1 default full volume)
"noise" sound to play
"channel" channel on which to play sound\
(0 auto, 1 weapon, 2 voice, 3 item, 4 body, 8 don't use PHS) (voice is default)
"key"          The item needed to activate this. (default nothing)

Normal sounds play each time the target is used.

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_changelevel (1 0 0) ? NO_INTERMISSION x NOT_PLAYERS MONSTERS PROJECTILES

When the player touches this, he gets sent to the map listed in the "map" variable.
Unless the NO_INTERMISSION flag is set, the view will go to the info_intermission
spot and display stats.

"spawnspot"  name of the spawn location to start at in next map.
"key"          The item needed to activate this. (default nothing)
"thread" This defaults to "LevelComplete" and should point to a thread that is called just
before the level ends.

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_use (1 0 0) ? VISIBLE x NOT_PLAYERS MONSTERS

Activates targets when 'used' by an entity
"key"          The item needed to activate this. (default nothing)
"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_useonce (1 0 0) ? VISIBLE x NOT_PLAYERS MONSTERS

Activates targets when 'used' by an entity, but only once
"key"          The item needed to activate this. (default nothing)
"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_hurt (1 0 0) ? x x NOT_PLAYERS NOT_MONSTERS PROJECTILES

"damage" amount of damage to cause. (default 10)
"key"          The item needed to activate this. (default nothing)
"damagetype" what kind of damage should be given to the player. (default CRUSH)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not hurt players
If NOT_MONSTERS is set, the trigger does not hurt monsters
If PROJECTILES is set, the trigger will hurt projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_damagetargets (1 0 0) ? SOLID x NOT_PLAYERS NOT_MONSTERS PROJECTILES

"damage" amount of damage to cause. If no damage is specified, objects\
are damaged by the current health+1

"key"          The item needed to activate this. (default nothing)

if a trigger_damagetargets is shot at and the SOLID flag is set,\
the damage is passed on to the targets

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not hurt players
If NOT_MONSTERS is set, the trigger does not hurt monsters
If PROJECTILES is set, the trigger will hurt projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_camerause (1 0 0) ? VISIBLE x NOT_PLAYERS MONSTERS

Activates 'targeted' camera when 'used'
If activated, toggles through cameras
"key"          The item needed to activate this. (default nothing)
"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_exit (1 0 0) ?

When the player touches this, an exit icon will be displayed in his hud.
This is to inform him that he is near an exit.

"triggerable" turn trigger on
"nottriggerable" turn trigger off

******************************************************************************/

/*****************************************************************************/
/*       trigger_box (0.5 0.5 0.5) ? x x NOT_PLAYERS MONSTERS PROJECTILES

Variable sized repeatable trigger.  Must be targeted at one or more entities.  Made to
be spawned via script.

If "health" is set, the trigger must be killed to activate each time.
If "delay" is set, the trigger waits some time after activating before firing.

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

"wait" : Seconds between triggerings. (.2 default)
"cnt" how many times it can be triggered (infinite default)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

set "message" to text string

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_music (1 0 0) ? NORMAL ACTION NOT_PLAYERS MONSTERS PROJECTILES SUSPENSE MYSTERY SURPRISE

Variable sized repeatable trigger to change the music mood.

If "delay" is set, the trigger waits some time after activating before firing.
"current" can be used to set the current mood
"fallback" can be used to set the fallback mood
"altcurrent" can be used to set the current mood of the opposite face, if multiFaceted
"altfallback" can be used to set the fallback mood of the opposite face, if multiFaceted
"edgeTriggerable" trigger only fires when entering a trigger
"multiFaceted" if 1, then trigger is North/South separate triggerable\
if 2, then trigger East/West separate triggerable

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.
"wait" : Seconds between triggerings. (1.0 default)
"cnt" how many times it can be triggered (infinite default)
"oneshot" make this a one time trigger

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

NORMAL, ACTION, SUSPENSE, MYSTERY, and SURPRISE are the moods that can be triggered

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_reverb (1 0 0) ? x x NOT_PLAYERS MONSTERS PROJECTILES

Variable sized repeatable trigger to change the reverb level in the game

If "delay" is set, the trigger waits some time after activating before firing.
"reverbtype" what kind of reverb should be used
"reverblevel" how much of the reverb effect should be applied
"altreverbtype" what kind of reverb should be used
"altreverblevel" how much of the reverb effect should be applied
"edgeTriggerable" trigger only fires when entering a trigger
"multiFaceted" if 1, then trigger is North/South separate triggerable\
if 2, then trigger East/West separate triggerable

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.
"wait" : Seconds between triggerings. (1.0 default)
"cnt" how many times it can be triggered (infinite default)
"oneshot" make this a one time trigger

"triggerable" turn trigger on
"nottriggerable" turn trigger off

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_pushobject (1 0 0) ?
Special trigger that can only be triggered by a push object.

"triggername" if set, trigger only responds to objects with a targetname the same as triggername.
"cnt" how many times it can be triggered (default 1, use -1 for infinite)
******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_givepowerup (1 0 0) ? x x NOT_PLAYERS MONSTERS x

Variable sized repeatable trigger to give a powerup to the player

"oneshot" makes this triggerable only once
"powerupname" sets the name of the powerup to give to the player

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_worktrigger (1 0 0) ?

Trigger will be used to tell the AI how to do "work".  When the AI activates
trigger, the thread you specifiy will execute.  The AI will also play the 
Animation you set in the trigger.

"triggerable" turn trigger on
"nottriggerable" turn trigger off
"setworkanim" Sets the animation the Actor will use when "working"


******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_levelinteraction (1 0 0) ?

Trigger that will be damaged by the AI to fire off a "level_interaction" thread
for example, a boss that shoots crates and knocks them over onto players

"triggerable" turn trigger on
"nottriggerable" turn trigger off
"health" should be set so that the trigger can take damage

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_groupevent (1 0 0) ? x x NOT_PLAYERS MONSTERS PROJECTILES

Variable sized repeatable trigger.  Must be targeted at one or more entities.

If "health" is set, the trigger must be killed to activate each time.
If "delay" is set, the trigger waits some time after activating before firing.

"thread" name of thread to trigger.  This can be in a different script file as well\
by using the '::' notation.

if "angle" is set, the trigger will only fire when someone is facing the
direction of the angle.
"cone" the cone in which a directed trigger can be triggered (default 60 degrees)

"wait" : Seconds between triggerings. (.2 default)
"cnt" how many times it can be triggered (infinite default)

"triggerable" turn trigger on
"nottriggerable" turn trigger off

"setpassevent" Sets the event you wish to pass to the group.  
"setgroupnumber" Sets the number of the group you wish to pass the event to.

If NOT_PLAYERS is set, the trigger does not respond to players
If MONSTERS is set, the trigger will respond to monsters
If PROJECTILES is set, the trigger will respond to projectiles (rockets, grenades, etc.)

set "message" to text string

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_volume_callvolume (1 0 0) ?

Allows you to specify a list of actors that are required to be inside this
volume before the thread fires.  This is a good utility if you need to "herd"
a group of actors into one spot for an event to occur ( Such as Teammates and
Lifts ).  When the player enters this trigger, a flag is set on all the actors
in the required list that notifies them that the player is in the volume.  The AI
for those actors is then responsible for getting them into the volume.  Once
all the required actors that are still in the level ( in case some were killed or
otherwise removed ) the specified thread will fire


******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_EntryAndExit (1 0 0) ? x x NOT_PLAYERS MONSTERS PROJECTILES

Triggers entryThread when entity enters the trigger, calls thread while inside,
and calls exitThread when entity leaves the trigger.

Key Value Pairs:
thread <ThreadName>
entryThread <EntryThreadName>
exitThread <ExitThreadName>

******************************************************************************/

//---------------------------------------------------------
//             T R I G G E R   V O L U M E
//---------------------------------------------------------
/*****************************************************************************/
/*QUAKED trigger_volume (1 0 0) ? x x NOT_PLAYERS MONSTERS PROJECTILES

Triggers entryThread when entity enters the trigger, calls thread while inside,
and calls exitThread when entity leaves the trigger.

Key Value Pairs:
thread <ThreadName>
entryThread <EntryThreadName>
exitThread <ExitThreadName>

******************************************************************************/

/*****************************************************************************/
/*QUAKED trigger_ladder (1 0 0) ? x x NOT_PLAYERS MONSTERS

Tells any entity that touches it that it is on a ladder

Angle/Angles specifies the direction away from the ladder

******************************************************************************/



