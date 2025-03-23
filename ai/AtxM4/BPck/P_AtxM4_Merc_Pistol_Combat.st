
//------------------------------------------------------------------------------------------------
// Name:	 human-m9-merc-pistol-combat.st
// Purpose:	 AI	for	combatative	human mercs with pistols
//------------------------------------------------------------------------------------------------

$define	RANGE_MAX_DISTANCE_TO_COMBAT_NODE	512
$define	RANGE_MAX_DISTANCE_TO_COVER_NODE	512
$define	RANGE_MIN_DISTANCE_TO_COVER_NODE	128
$define	RANGE_MELEE							96
$define	RANGE_THREAT						192.0
$define	RANGE_MIN_ENGAGEMENT				320.0
$define	RANGE_MAX_ENGAGEMENT				448.0
$define	RANGE_RETREAT						96.0
$define	DISTANCE_STRAFE						64.0
$define	CHANCE_DUCK_COMBAT					0
$define	CHANCE_ROLL							0
$define	CHANCE_ATTACK						.45
$define	CHANCE_SPLIT						.5
$define	CHANCE_STRAFE						.35
$define	CHANCE_SPAR							.75
$define	CHANCE_PAIN							.020
$define	CHANCE_CROUCH_FIRE					.25
$define	RANGE_MAX_DISTANCE_TO_COMBAT_NODE	512
$define	RANGE_MAX_DISTANCE_TO_COVER_NODE	512
$define	RANGE_MIN_DISTANCE_TO_COVER_NODE	128
$define	DODGE_CHANCE						.40
$define	TIME_DODGE							1.0

//------------------------------------------------------------------------------------------------
state START
{
	entrycommands
	{
		incontext "enteredcombat"
		groupattack
	}

	states
	{
		COMBAT_MAIN		: default
	}
}

//------------------------------------------------------------------------------------------------
state COMBAT_MAIN
{
	states
	{
		FOLLOW_THE_LEADER						: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		GENERAL_COMBAT_WITH_RANGED_WEAPON		: HAVE_ACTIVE_WEAPON
		HOLD									: default // should	never happen
	}
}

//---------------------------------------------------------
state FOLLOW_THE_LEADER
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "combatfollow"
		}

	TorsoBehavior torsoAimAndFireWeapon ( 0 , 0 , 1 )
	Behavior GroupFollow ( 96 , 192 )

	states
		{		
		COMBAT_MAIN			: WITHIN_FOLLOW_TARGET_MIN_RANGE
		COMBAT_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
	}

//------------------------------------------------------------------------------------------------
state HOLD
{
	entrycommands
	{
		printmessage "COMBAT:  HOLD"
	}

	legs
	{
		idle : default
	}

	time ( 1 )

	states
	{
		COMBAT_MAIN	: TIME_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON
{
	entrycommands
	{
		setvartime ( "last_dodge" )
		selectclosestenemy
	}

	states
	{
		GENERAL_COMBAT_PAIN							: SHOW_PAIN
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN		: default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN
{
	entrycommands
	{
		incontext "incombat"
		selectclosestenemy
	}


	states
	{
		GENERAL_COMBAT_DODGE									: CHANCE ( $DODGE_CHANCE$ ,	1 )	IN_CONE_OF_FIRE	CHECK_VAR_TIME_DIFFERENCE (	"last_dodge" , $TIME_DODGE$	)
		GENERAL_COMBAT_MELEE_ATTACK								: RANGE	( $RANGE_MELEE$	)
		GENERAL_COMBAT_APPROACH									: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_SEEK										: !CAN_ATTACK_ENEMY	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING				: SHOULD_DO_ACTION ( "spar"	) CHANCE ( $CHANCE_SPAR$ )
		GENERAL_COMBAT_STANDING_ATTACK							: default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_APPROACH
{
	states
	{
		GENERAL_COMBAT_APPROACH_FIRING						: CAN_ATTACK_ENEMY
		GENERAL_COMBAT_APPROACH_NO_FIRING					: default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_APPROACH_NO_FIRING
{
	Behavior CloseInOnEnemy	( "run"	, $RANGE_MIN_ENGAGEMENT$ )

	states
	{
		GENERAL_COMBAT_PAIN									: SHOW_PAIN
		GENERAL_COMBAT_APPROACH_FIRING						: CAN_ATTACK_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: RANGE	( $RANGE_MIN_ENGAGEMENT$ ) SHOULD_DO_ACTION	( "spar" ) CHANCE (	$CHANCE_SPAR$ )
		GENERAL_COMBAT_STANDING_ATTACK						: RANGE	( $RANGE_MIN_ENGAGEMENT$ )
		GENERAL_COMBAT_SEEK_FAILED							: BEHAVIOR_FAILED
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_APPROACH_FIRING
{
	Behavior CloseInOnEnemy	( "run"	, $RANGE_MIN_ENGAGEMENT$ )
	TorsoBehavior torsoAimAndFireWeapon	( 0	)

	states
	{
		GENERAL_COMBAT_APPROACH_NO_FIRING					: !CAN_ATTACK_ENEMY
		GENERAL_COMBAT_PAIN									: SHOW_PAIN
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: RANGE	( $RANGE_MIN_ENGAGEMENT$ ) SHOULD_DO_ACTION	( "spar" ) CHANCE (	$CHANCE_SPAR$ )
		GENERAL_COMBAT_STANDING_ATTACK						: TORSO_BEHAVIOR_DONE RANGE	( $RANGE_MIN_ENGAGEMENT$ )
		GENERAL_COMBAT_APPROACH_FIRING_REPEAT				: TORSO_BEHAVIOR_DONE
		GENERAL_COMBAT_SEEK_FAILED							: BEHAVIOR_FAILED
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_APPROACH_FIRING_REPEAT
{
	states
	{
		GENERAL_COMBAT_APPROACH_FIRING : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_SEEK
{
	Behavior CloseInOnEnemy	( "run"	, $RANGE_MELEE$	)
	TorsoBehavior torsoAimAndFireWeapon	( 0	)

	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN			: CAN_ATTACK_ENEMY
		GENERAL_COMBAT_SEEK_FAILED						: BEHAVIOR_SUCCESS
		GENERAL_COMBAT_SEEK_FAILED						: BEHAVIOR_FAILED
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_SEEK_FAILED
{

	Behavior CloseInOnPlayer ( "run" , $RANGE_MELEE$ )
	TorsoBehavior torsoAimAndFireWeapon	( 0	)


	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN			: CAN_ATTACK_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON				: BEHAVIOR_SUCCESS
		GENERAL_COMBAT_WITH_RANGED_WEAPON				: BEHAVIOR_FAILED
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_STANDING_ATTACK
{
	states
	{
		GENERAL_COMBAT_APPROACH								: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_SEEK									: !CAN_ATTACK_ENEMY	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: SHOULD_DO_ACTION ( "spar"	) CHANCE ( $CHANCE_SPAR$ )
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE	: default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING
{
	TorsoBehavior torsoAimAndFireWeapon	( 0	)
	Behavior MoveRandomDirection ( "walk" ,	256	, 96 , 0 , 1 , 1 )

	states
	{
		GENERAL_COMBAT_PAIN						: SHOW_PAIN
		GENERAL_COMBAT_MELEE_ATTACK				: RANGE	( $RANGE_MELEE$	)
		GENERAL_COMBAT_APPROACH					: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_DODGE					: CHANCE ( $DODGE_CHANCE$ ,	1 )	IN_CONE_OF_FIRE	CHECK_VAR_TIME_DIFFERENCE (	"last_dodge" , $TIME_DODGE$	)
		GENERAL_COMBAT_HOLD						: TORSO_BEHAVIOR_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE
{
	TorsoBehavior torsoAimAndFireWeapon	( 0	)
	Behavior WatchEntity ( 1 , 15 ,	"shuffle" ,	0 ,	"idle_weapon_legs" )

	states
	{
		GENERAL_COMBAT_PAIN						: SHOW_PAIN
		GENERAL_COMBAT_APPROACH					: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_HOLD						: TORSO_BEHAVIOR_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON_CROUCH_AND_FIRE
{
	entrycommands
	{
		turntowardsenemy
	}

	TorsoBehavior torsoAimAndFireWeapon	( 0	)
	Behavior WatchEntity ( 1 , 15 ,	"crouch_idle" ,	0 ,	"crouch_idle" )

	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_UP	: TORSO_BEHAVIOR_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_UP
{
	legs
	{
		from_crouch	: default
	}

	states
	{
		GENERAL_COMBAT_APPROACH					: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_HOLD						: ANIM_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_HOLD
{
	entrycommands
	{
		selectclosestenemy
	}

	TorsoBehavior torsoAimAndFireWeapon	( 1	)
	Behavior WatchEntity ( 1 , 15 ,	"shuffle" ,	0 ,	"idle_weapon_legs" )

	states
	{
		GENERAL_COMBAT_PAIN							: SHOW_PAIN
		GENERAL_COMBAT_MELEE_ATTACK					: RANGE	( $RANGE_MELEE$	)
		GENERAL_COMBAT_DODGE						: CHANCE ( $DODGE_CHANCE$ ,	1 )	IN_CONE_OF_FIRE	CHECK_VAR_TIME_DIFFERENCE (	"last_dodge" , $TIME_DODGE$	)
		GENERAL_COMBAT_APPROACH						: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN		: BEHAVIOR_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_DODGE
{
	entrycommands
	{
		setvartime ( "last_dodge" )
	}

	states
	{
		GENERAL_COMBAT_CHECK_LEFT :	CHANCE ( $CHANCE_SPLIT$	)
		GENERAL_COMBAT_CHECK_RIGHT : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_CHECK_LEFT
{
	states
	{
		GENERAL_COMBAT_SELECT_DODGE_LEFT : LEFT_CLEAR (	$DISTANCE_STRAFE$ )
		GENERAL_COMBAT_CHECK_LEFT_FAILED : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_CHECK_LEFT_FAILED
{
	states
	{
		GENERAL_COMBAT_SELECT_DODGE_RIGHT :	RIGHT_CLEAR	( $DISTANCE_STRAFE$	)
		CANT_DODGE : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_CHECK_RIGHT
{
	states
	{
		GENERAL_COMBAT_SELECT_DODGE_RIGHT :	RIGHT_CLEAR	( $DISTANCE_STRAFE$	)
		GENERAL_COMBAT_CHECK_RIGHT_FAILED :	default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_CHECK_RIGHT_FAILED
{
	states
	{
		GENERAL_COMBAT_SELECT_DODGE_LEFT : LEFT_CLEAR (	$DISTANCE_STRAFE$ )
		CANT_DODGE : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_SELECT_DODGE_LEFT
{
	states
	{
		GENERAL_COMBAT_DODGE_LEFT :	default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_SELECT_DODGE_RIGHT
{
	states
	{
		GENERAL_COMBAT_DODGE_RIGHT : default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_DODGE_LEFT
{
	entrycommands
	{
		turntowardsenemy
	}

	legs
	{
		swat_dodge_L : default
	}

	states
	{
		GENERAL_COMBAT_PAIN									: SHOW_PAIN
		GENERAL_COMBAT_APPROACH								: ANIM_DONE	!RANGE ( $RANGE_MAX_ENGAGEMENT$	) HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: ANIM_DONE	SHOULD_DO_ACTION ( "spar" )	CHANCE ( $CHANCE_SPAR$ )
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE	: ANIM_DONE

	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_DODGE_RIGHT
{
	entrycommands
	{
		turntowardsenemy
	}

	legs
	{
		swat_dodge_R : default
	}

	states
	{
		GENERAL_COMBAT_PAIN									: SHOW_PAIN
		GENERAL_COMBAT_APPROACH								: ANIM_DONE	!RANGE ( $RANGE_MAX_ENGAGEMENT$	) HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: ANIM_DONE	SHOULD_DO_ACTION ( "spar" )	CHANCE ( $CHANCE_SPAR$ )
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE	: ANIM_DONE
	}
}

//------------------------------------------------------------------------------------------------
state CANT_DODGE
{
	TorsoBehavior torsoAimAndFireWeapon	( 0	)
	Behavior WatchEntity ( 1 , 15 ,	"shuffle" ,	0 ,	"idle_weapon_legs" )

	states
	{
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		GENERAL_COMBAT_APPROACH				: !RANGE ( $RANGE_MAX_ENGAGEMENT$ )	HAVE_PATH_TO_ENEMY
		GENERAL_COMBAT_HOLD					: TORSO_BEHAVIOR_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_PAIN
{
	states
	{
		GENERAL_COMBAT_BIG_PAIN	  :	MOD	( "explosion" )
		GENERAL_COMBAT_BIG_PAIN	  :	MOD	( "imod_primary" )
		GENERAL_COMBAT_BIG_PAIN	  :	MOD	( "plasmashotgun" )
		GENERAL_COMBAT_BIG_PAIN	  :	MOD	( "small_explosion"	)
		GENERAL_COMBAT_SMALL_PAIN :	default
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_BIG_PAIN
{
	legs
	{
		pain_knockback : default
	}

	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN : ANIM_DONE
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_SMALL_PAIN
{
	entrycommands
	{
		saveofflasthitbone
	}

	legs
	{
		pain_stomach	: BONE_DAMAGED ( "Bip01	Pelvis"	)
		pain_stomach	: BONE_DAMAGED ( "Bip01	Spine" )
		pain_chest		: BONE_DAMAGED ( "Bip01	Spine2"	)
		pain_head		: BONE_DAMAGED ( "Bip01	Head" )
		pain_shoulder_L	: BONE_DAMAGED ( "Bip01	L Clavicle"	)
		pain_shoulder_L	: BONE_DAMAGED ( "Bip01	L Upperarm"	)
		pain_shoulder_L	: BONE_DAMAGED ( "Bip01	L Forearm" )
		pain_shoulder_L	: BONE_DAMAGED ( "Bip01	L Hand"	)
		pain_shoulder_L	: BONE_DAMAGED ( "Bip01	L Finger2" )
		pain_shoulder_R	: BONE_DAMAGED ( "Bip01	R Clavicle"	)
		pain_shoulder_R	: BONE_DAMAGED ( "Bip01	R Upperarm"	)
		pain_shoulder_R	: BONE_DAMAGED ( "Bip01	R Forearm" )
		pain_shoulder_R	: BONE_DAMAGED ( "Bip01	R Hand"	)
		pain_shoulder_R	: BONE_DAMAGED ( "Bip01	R Finger2" )
		pain_leg_L		: BONE_DAMAGED ( "Bip01	L Thigh" )
		pain_L_lowerleg	: BONE_DAMAGED ( "Bip01	L Calf"	)
		pain_L_lowerleg	: BONE_DAMAGED ( "Bip01	L Foot"	)
		pain_L_lowerleg	: BONE_DAMAGED ( "Bip01	L Toe0"	)
		pain_leg_R		: BONE_DAMAGED ( "Bip01	R Thigh" )
		pain_R_lowerleg	: BONE_DAMAGED ( "Bip01	R Calf"	)
		pain_R_lowerleg	: BONE_DAMAGED ( "Bip01	R Foot"	)
		pain_R_lowerleg	: BONE_DAMAGED ( "Bip01	R Toe0"	)
		pain_chest		: default
	}

	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN : ANIM_DONE
	}

}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_MELEE_ATTACK
{
	Behavior DoAttack (	"" , 15	, 1	, "shuffle"	)

	states
	{
		GENERAL_COMBAT_RETREAT					: BEHAVIOR_SUCCESS RANGE ( $RANGE_MELEE$ )
		GENERAL_COMBAT_RETREAT					: BEHAVIOR_FAILED RANGE	( $RANGE_MELEE$	)
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN	: BEHAVIOR_SUCCESS
		GENERAL_COMBAT_WITH_RANGED_WEAPON_MAIN	: BEHAVIOR_FAILED
	}
}

//------------------------------------------------------------------------------------------------
state GENERAL_COMBAT_RETREAT
{
	Behavior BackAwayFromEnemy ( "swat_backpedal_run" ,	96.0 , 64.0	)
	TorsoBehavior torsoAimAndFireWeapon	( 0	, 1	)

	states
	{
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: BEHAVIOR_SUCCESS SHOULD_DO_ACTION	( "spar" ) CHANCE (	$CHANCE_SPAR$ )
		GENERAL_COMBAT_WITH_RANGED_WEAPON_SPARRING			: BEHAVIOR_FAILED SHOULD_DO_ACTION ( "spar"	) CHANCE ( $CHANCE_SPAR$ )
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE	: BEHAVIOR_SUCCESS
		GENERAL_COMBAT_WITH_RANGED_WEAPON_STAND_AND_FIRE	: BEHAVIOR_FAILED
	}
}