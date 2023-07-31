//[b60014] chrissstrahl - removed coop trigger references - this file is used for the level editor

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



