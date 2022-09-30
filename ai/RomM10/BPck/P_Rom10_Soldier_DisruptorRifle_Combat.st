//
//---------------------------------------------------------------------------------------------------------------
// Name:     Package_DisruptorRifleCombat
// Purpose:  Gives Rifle "Duck and Cover" AI to M11 Romulans
//
// Rules -- Crate Cover must be 64 units high
// 		 -- Wall Cover Node must be marked with a key/value pair of setcovertype/wall
//---------------------------------------------------------------------------------------------------------------
//


//---------------------------------------------------------
$define RANGE_MAX_DISTANCE_TO_COVER_NODE 512
$define RANGE_MIN_DISTANCE_TO_COVER_NODE 0
$define RANGE_MELEE							96

$define TIME_COVER_RECHECK 1.0
$define TIME_WAIT_ON_ATTACK_MIN				1.0
$define TIME_WAIT_ON_ATTACK_MAX				1.5
$define TIME_WAIT_AT_COVER_MIN				1.0
$define TIME_WAIT_AT_COVER_MAX				1.0
$define CHANCE_REPEAT_ATTACK				.45
$define COUNT_MAX_REPEATS					5
$define RANGE_CAN_ATTACK					512
$define CHANCE_SWITCH_NODES					0.3
//---------------------------------------------------------

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	states
	{
		START_AI_ON : IN_AI_MODE
		START_AI_OFF : default
	}
}

// hack to avoid problems with script calling ai_off calling state machine calling script calling killthread on script that called ai_off
// Love, Josh.
// Extra Smoochies from Jared!
//---------------------------------------------------------
state START_AI_ON 
//---------------------------------------------------------
{
	entrycommands
	{
		runthread m10l2a_FromStateMachine_KillDialog
	}
	states
	{
		START_AI_OFF : default
	}
}

//---------------------------------------------------------
state START_AI_OFF
//---------------------------------------------------------
	{
	entrycommands
		{
		setvartime ( "last_dodge" )
		attackplayer
		groupattack
		turntowardsplayer
		visiondistance 1024
		}

	time ( 0.5 )

	states
		{
		STUPID_STEALTH_DIALOG_HACK		: TIME_DONE CAN_SEE_ENEMY

		WAIT			: !CAN_SEE_ENEMY TIME_DONE !RANGE ( $RANGE_CAN_ATTACK$ )
		ALARM			: TIME_DONE !CHECK_VAR ( "pulledAlarm" , "true" ) SHOULD_DO_ACTION ( "pullalarm" ) VALID_CUSTOM_NODE_IN_RANGE ( "alarm" , 512 )
		GOTO_COVER_POSITION : TIME_DONE VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		NO_VALID_COVER_AVAILIABLE : TIME_DONE
		}
	}

state STUPID_STEALTH_DIALOG_HACK
{
	entrycommands
		{
		incontext "incombat"
		}

	states
		{
		WAIT			: !CAN_SEE_ENEMY !RANGE ( $RANGE_CAN_ATTACK$ )
		ALARM			: !CHECK_VAR ( "pulledAlarm" , "true" ) SHOULD_DO_ACTION ( "pullalarm" ) VALID_CUSTOM_NODE_IN_RANGE ( "alarm" , 512 )
		GOTO_COVER_POSITION : VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		NO_VALID_COVER_AVAILIABLE : default
		}
}

//---------------------------------------------------------
state WAIT
//---------------------------------------------------------
	{
		entrycommands
			{
			startactivationtimer
			}

		legs
			{
			idle : default
			}

		states
			{
				//[b60011] Chrissstrahl - allow up to disable this scriptdependency
				EARLY_OUT : ACTIVATION_DELAY_DONE !SHOULD_DO_ACTION ( "noscript" )
				START 	: RANGE ( $RANGE_CAN_ATTACK$ )
				START 	: CAN_SEE_ENEMY
			}

	}

state EARLY_OUT
{
	entrycommands
		{
		runthread m10l2a_FromStateMachine_EarlyOut
		}
}

//---------------------------------------------------------
state ALARM
//---------------------------------------------------------
	{

	entrycommands
		{
		incontext "pullalarm"
		setvar ( "pulledAlarm" , "true" )
		sendeventtogroup aggressive 1.0
		}

	Behavior UseAlarm ( "run" )

	states
		{
		ALARM_SUCCESS	: BEHAVIOR_SUCCESS
		ALARM_FAILED	: BEHAVIOR_FAILED
		ALARM_FAILED	: !SHOULD_DO_ACTION ( "pullalarm" )
		}
	}

//---------------------------------------------------------
state ALARM_FAILED
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage "COMBAT:  ALARM_FAILED"
		}

	states
		{
		GOTO_COVER_POSITION : VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		NO_VALID_COVER_AVAILIABLE : default
		}
	}

//---------------------------------------------------------
state ALARM_SUCCESS
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage "COMBAT:  ALARM_SUCCESS"
		}

	states
		{
		GOTO_COVER_POSITION : VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		NO_VALID_COVER_AVAILIABLE : default
		}
	}

//---------------------------------------------------------
state GOTO_COVER_POSITION
//---------------------------------------------------------
	{
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		GOTO_COVER_POSITION_NOFIRE	:	!CAN_ATTACK_ENEMY
		AT_COMBAT_POSITION : BEHAVIOR_SUCCESS
		NO_VALID_COVER_AVAILIABLE : BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state GOTO_COVER_POSITION_NOFIRE
	{
	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		AT_COMBAT_POSITION : BEHAVIOR_SUCCESS
		NO_VALID_COVER_AVAILIABLE : BEHAVIOR_FAILED
		}
	}
//---------------------------------------------------------



//---------------------------------------------------------
state NO_VALID_COVER_AVAILIABLE
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		LOOK_FOR_COVER 	: TORSO_BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state LOOK_FOR_COVER
//---------------------------------------------------------
	{
	states
		{
		GOTO_COVER_POSITION : VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		NO_VALID_COVER_AVAILIABLE : default
		}
	}

//---------------------------------------------------------
state AT_COMBAT_POSITION
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		to_crouch : default
		}

	states
		{
		WAIT_AT_COMBAT_POSITION : ANIM_DONE
		}
	}

//---------------------------------------------------------
state WAIT_AT_COMBAT_POSITION
//---------------------------------------------------------
	{
	legs
		{
		crouch_idle : default
		}

	time ( $TIME_WAIT_ON_ATTACK_MIN$ , $TIME_WAIT_ON_ATTACK_MAX$ )

	states
		{
		COVER_COMBAT_SPOTTED_STAND_UP : TIME_DONE CHANCE ( $CHANCE_SWITCH_NODES$ ) ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_COMBAT_POSITION : TIME_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_FROM_COMBAT_POSITION
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		from_crouch : default
		}

	states
		{
		ATTACK_FROM_WALL_COVER : ANIM_DONE CURRENT_NODE_COVERTYPE ( "wall" )
		COVER_COMBAT_SPOTTED : ANIM_DONE ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_CRATE_COVER : ANIM_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_FROM_WALL_COVER
//---------------------------------------------------------
{
	Behavior CloseInOnEnemy ( "run" , $RANGE_MELEE$ )

	states
		{
		GENERAL_COMBAT_PAIN				: SHOW_PAIN
		ATTACK_FROM_WALL_COVER_ATTACK	: CAN_ATTACK_ENEMY
		RETURN_TO_WALL_COVER			: BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state ATTACK_FROM_WALL_COVER_ATTACK
//---------------------------------------------------------
{
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		GENERAL_COMBAT_PAIN				: SHOW_PAIN
		RETURN_TO_WALL_COVER		: TORSO_BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state RETURN_TO_WALL_COVER
//---------------------------------------------------------
{
	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		GENERAL_COMBAT_PAIN				: SHOW_PAIN
		AT_COMBAT_POSITION : BEHAVIOR_SUCCESS
		NO_VALID_COVER_AVAILIABLE : BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state WAIT_AT_WALL_COVER
//---------------------------------------------------------
{
	legs
		{
		crouch_idle : default
		}

	time ( $TIME_WAIT_AT_COVER_MIN$ , $TIME_WAIT_AT_COVER_MAX$ )

	states
		{
		COVER_COMBAT_SPOTTED_STAND_UP : TIME_DONE CHANCE ( $CHANCE_SWITCH_NODES$ ) ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_WALL_COVER : TIME_DONE
		}
}

//---------------------------------------------------------
state ATTACK_FROM_CRATE_COVER
//---------------------------------------------------------
{
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		GENERAL_COMBAT_PAIN				: SHOW_PAIN
		ATTACK_FROM_CRATE_COVER_DUCK 	: TORSO_BEHAVIOR_DONE STAGE ( $COUNT_MAX_REPEATS$ )
		ATTACK_FROM_CRATE_COVER_REPEAT_ATTACK	: TORSO_BEHAVIOR_DONE CHANCE ( $CHANCE_REPEAT_ATTACK$ )
		COVER_COMBAT_SPOTTED 			: TORSO_BEHAVIOR_DONE ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_CRATE_COVER_DUCK 	: TORSO_BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state ATTACK_FROM_CRATE_COVER_REPEAT_ATTACK
//---------------------------------------------------------
{
	entrycommands
		{
		gotonextstage
		}

	states
		{
		ATTACK_FROM_CRATE_COVER : default
		}
}

//---------------------------------------------------------
state ATTACK_FROM_CRATE_COVER_DUCK
//---------------------------------------------------------
{
	entrycommands
		{
		gotostage 1
		}

	legs
		{
		to_crouch : default
		}

	states
		{
		ATTACK_FROM_CRATE_COVER_WAIT : ANIM_DONE
		}
}

//---------------------------------------------------------
state ATTACK_FROM_CRATE_COVER_WAIT
//---------------------------------------------------------
{
	legs
		{
		crouch_idle : default
		}

	time ( $TIME_WAIT_AT_COVER_MIN$ , $TIME_WAIT_AT_COVER_MAX$ )

	states
		{
		COVER_COMBAT_SPOTTED_STAND_UP : TIME_DONE CHANCE ( $CHANCE_SWITCH_NODES$ ) ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_CRATE_COVER_STANDUP_TO_ATTACK : TIME_DONE
		}
}

//---------------------------------------------------------
state ATTACK_FROM_CRATE_COVER_STANDUP_TO_ATTACK
//---------------------------------------------------------
{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		from_crouch : default
		}

	states
		{
		COVER_COMBAT_SPOTTED 	: ANIM_DONE ENEMY_CAN_SEE_CURRENT_NODE
		ATTACK_FROM_CRATE_COVER : ANIM_DONE
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_PAIN
//---------------------------------------------------------
	{
	states
		{
		GENERAL_COMBAT_BIG_PAIN	  : MOD ( "explosion" )
		GENERAL_COMBAT_BIG_PAIN	  : MOD ( "imod_primary" )
		GENERAL_COMBAT_BIG_PAIN	  : MOD ( "plasmashotgun" )
		GENERAL_COMBAT_BIG_PAIN	  : MOD ( "small_explosion" )
		GENERAL_COMBAT_SMALL_PAIN : default
		}
	}

//---------------------------------------------------------
state GENERAL_COMBAT_BIG_PAIN
//---------------------------------------------------------
{
	legs
		{
		pain_knockback : default
		}

	states
		{
		GOTO_COVER_POSITION : ANIM_DONE
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_SMALL_PAIN
//---------------------------------------------------------
{
	entrycommands
		{
		saveofflasthitbone
		}

	legs
		{
		pain_stomach 	: BONE_DAMAGED ( "Bip01 Pelvis" )
		pain_stomach 	: BONE_DAMAGED ( "Bip01 Spine" )
		pain_chest 		: BONE_DAMAGED ( "Bip01 Spine2" )
		pain_head 		: BONE_DAMAGED ( "Bip01 Head" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Clavicle" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Upperarm" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Forearm" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Hand" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Finger2" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Clavicle" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Upperarm" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Forearm" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Hand" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Finger2" )
		pain_leg_L 		: BONE_DAMAGED ( "Bip01 L Thigh" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Calf" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Foot" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Toe0" )
		pain_leg_R 		: BONE_DAMAGED ( "Bip01 R Thigh" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Calf" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Foot" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Toe0" )
		pain_chest		: default
		}

	states
		{
		GOTO_COVER_POSITION : ANIM_DONE
		}

}

//------------------------------------------------------------------------------
state COVER_COMBAT_SPOTTED_STAND_UP
//------------------------------------------------------------------------------
{
	legs
		{
		from_crouch : default
		}

	states
		{
		COVER_COMBAT_SPOTTED 	: ANIM_DONE
		}
}

//------------------------------------------------------------------------------
state COVER_COMBAT_SPOTTED
//------------------------------------------------------------------------------
{
	states
		{
		GOTO_COVER_POSITION 			: VALID_COVER_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COVER_NODE$ , $RANGE_MIN_DISTANCE_TO_COVER_NODE$ )
		COVER_COMBAT_WITH_RANGED_WEAPON_FAILED 	: default
		}
}

state COVER_COMBAT_WITH_RANGED_WEAPON_FAILED
{
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		GENERAL_COMBAT_PAIN			: SHOW_PAIN
		ATTACK_FROM_CRATE_COVER_DUCK : TORSO_BEHAVIOR_DONE !ENEMY_CAN_SEE_CURRENT_NODE
		COVER_COMBAT_SPOTTED		: TORSO_BEHAVIOR_DONE
		}
}