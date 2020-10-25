//
//---------------------------------------------------------------------------------------------------------------
// Name:     Package_DisruptorPistolCombat
// Purpose:  Gives Pistol "Grunt" AI to M11 Romulans
//
// Rules:
//
//---------------------------------------------------------------------------------------------------------------
//

//---------------------------------------------------------
$define RANGE_MAX_DISTANCE_TO_COMBAT_NODE	512
$define RANGE_SPARRING						384
$define TIME_WAIT_ON_ATTACK_MIN				1.0
$define TIME_WAIT_ON_ATTACK_MAX				1.5
$define TIME_CHASE_TIME_MAX					2.5
$define TIME_DODGE							1.0
$define CHANCE_DODGE						.65
$define CHANCE_DIVE							.05
$define CHANCE_MANUEVER_FIRE				.35
$define CHANCE_SPLIT						.5
$define RANGE_MELEE 						96
$define DISTANCE_STRAFE 					64.0
$define RANGE_MIN_DISTANCE_TO_COVER_NODE	0
$define RANGE_MAX_DISTANCE_TO_COVER_NODE	512
$define RANGE_CAN_ATTACK					512
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
		
		//attackplayer //hzm chrissstrahl - this does not work right
		//turntowardsplayer //hzm chrissstrahl - this does not work right
		//hzm chrissstrahl - this should work better
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
		//hzm eof
		
		groupattack
		visiondistance 1024
		}

	time ( 0.5 )

	states
		{
		STUPID_STEALTH_DIALOG_HACK		: TIME_DONE CAN_SEE_ENEMY

		WAIT			:  !CAN_SEE_ENEMY TIME_DONE !RANGE ( $RANGE_CAN_ATTACK$ )
		ALARM			:  TIME_DONE !CHECK_VAR ( "pulledAlarm" , "true" ) SHOULD_DO_ACTION ( "pullalarm" ) VALID_CUSTOM_NODE_IN_RANGE ( "alarm" , 512 )
		GENERAL_COMBAT_PAIN							: TIME_DONE SHOW_PAIN
		GOTO_COMBAT_POSITION : TIME_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		CLOSE_IN_ON_ENEMY : TIME_DONE
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
		WAIT			:  !CAN_SEE_ENEMY !RANGE ( $RANGE_CAN_ATTACK$ )
		ALARM			:  !CHECK_VAR ( "pulledAlarm" , "true" ) SHOULD_DO_ACTION ( "pullalarm" ) VALID_CUSTOM_NODE_IN_RANGE ( "alarm" , 512 )
		GENERAL_COMBAT_PAIN							: SHOW_PAIN
		GOTO_COMBAT_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		CLOSE_IN_ON_ENEMY : default
		}
}

//---------------------------------------------------------
state WAIT
//---------------------------------------------------------
	{
		legs
			{
			idle : default
			}

		states
			{
				START 	: RANGE ( $RANGE_CAN_ATTACK$ )
				START 	: CAN_SEE_ENEMY
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
		GOTO_COMBAT_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		CLOSE_IN_ON_ENEMY : default
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
		GOTO_COMBAT_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		CLOSE_IN_ON_ENEMY : default
		}
	}

//---------------------------------------------------------
state GOTO_COMBAT_POSITION
//---------------------------------------------------------
	{
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		AT_COMBAT_POSITION : BEHAVIOR_SUCCESS
		CLOSE_IN_ON_ENEMY : BEHAVIOR_FAILED
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
		CLOSE_IN_ON_ENEMY : ANIM_DONE
		}

	}

//---------------------------------------------------------
state CLOSE_IN_ON_ENEMY
//---------------------------------------------------------
	{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
	}
	//hzm eof

	Behavior CloseInOnEnemy ( "run" , $RANGE_SPARRING$ )
	TorsoBehavior torsoAimAndFireWeapon ( 0 )

	states
		{
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		AT_SPARRING_RANGE					: BEHAVIOR_SUCCESS
		CLOSE_IN_ON_ENEMY_FAILED 			: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state CLOSE_IN_ON_ENEMY_FAILED
//---------------------------------------------------------
	{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
	}
	//hzm eof

	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		CLOSE_IN_ON_ENEMY						: TORSO_BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state AT_SPARRING_RANGE
//---------------------------------------------------------
	{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
	}
	//hzm eof
	states
		{
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		CLOSE_IN_ON_ENEMY		: !RANGE ( $RANGE_SPARRING$ )
		MELEE_COMBAT			: RANGE ( $RANGE_MELEE$ )
		GENERAL_COMBAT_DODGE	: CHANCE ( $CHANCE_DODGE$ , 1 ) IN_CONE_OF_FIRE CHECK_VAR_TIME_DIFFERENCE ( "last_dodge" , $TIME_DODGE$ )
		MANUEVER				: CAN_SEE_ENEMY
		CLOSE_IN_ON_ENEMY 		: default
		}
	}

//---------------------------------------------------------
state GENERAL_COMBAT_DODGE
//---------------------------------------------------------
{
	entrycommands
		{
		setvartime ( "last_dodge" )
		}

	states
		{
		GENERAL_COMBAT_CHECK_LEFT : CHANCE ( $CHANCE_SPLIT$ )
		GENERAL_COMBAT_CHECK_RIGHT : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_CHECK_LEFT
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_SELECT_DODGE_LEFT : LEFT_CLEAR ( $DISTANCE_STRAFE$ )
		GENERAL_COMBAT_CHECK_LEFT_FAILED : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_CHECK_LEFT_FAILED
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_SELECT_DODGE_RIGHT : RIGHT_CLEAR ( $DISTANCE_STRAFE$ )
		CANT_DODGE : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_CHECK_RIGHT
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_SELECT_DODGE_RIGHT : RIGHT_CLEAR ( $DISTANCE_STRAFE$ )
		GENERAL_COMBAT_CHECK_RIGHT_FAILED : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_CHECK_RIGHT_FAILED
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_SELECT_DODGE_LEFT : LEFT_CLEAR ( $DISTANCE_STRAFE$ )
		CANT_DODGE : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_SELECT_DODGE_LEFT
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_DIVE_LEFT : CHANCE ( $CHANCE_DIVE$ )
		GENERAL_COMBAT_DODGE_LEFT : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_SELECT_DODGE_RIGHT
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_DIVE_RIGHT : CHANCE ( $CHANCE_DIVE$ )
		GENERAL_COMBAT_DODGE_RIGHT : default
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_DIVE
//---------------------------------------------------------
{
	states
		{
		GENERAL_COMBAT_DIVE_LEFT : CHANCE ( $CHANCE_SPLIT$ )
		GENERAL_COMBAT_DIVE_RIGHT : default
		}

}

//---------------------------------------------------------
state GENERAL_COMBAT_DODGE_LEFT
//---------------------------------------------------------
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
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		CLOSE_IN_ON_ENEMY									: ANIM_DONE !RANGE ( $RANGE_SPARRING$ ) HAVE_PATH_TO_ENEMY
		AT_SPARRING_RANGE 									: ANIM_DONE
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_DODGE_RIGHT
//---------------------------------------------------------
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
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		CLOSE_IN_ON_ENEMY									: ANIM_DONE !RANGE ( $RANGE_SPARRING$ ) HAVE_PATH_TO_ENEMY
		AT_SPARRING_RANGE 									: ANIM_DONE
		}
}


//---------------------------------------------------------
state GENERAL_COMBAT_DIVE_LEFT
//---------------------------------------------------------
{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		diveroll_L : default
		}

	states
		{
		CLOSE_IN_ON_ENEMY									: ANIM_DONE !RANGE ( $RANGE_SPARRING$ ) HAVE_PATH_TO_ENEMY
		AT_SPARRING_RANGE 									: ANIM_DONE
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_DIVE_RIGHT
//---------------------------------------------------------
{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		diveroll_R : default
		}

	states
		{
		CLOSE_IN_ON_ENEMY									: ANIM_DONE !RANGE ( $RANGE_SPARRING$ ) HAVE_PATH_TO_ENEMY
		AT_SPARRING_RANGE 									: ANIM_DONE
		}
}

//---------------------------------------------------------
state CANT_DODGE
//---------------------------------------------------------
{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
	}
	//hzm eof
	
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior WatchEntity ( 1 , 15 , "shuffle" , 0 , "idle_weapon_legs" )

	states
		{
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		CLOSE_IN_ON_ENEMY									: !RANGE ( $RANGE_SPARRING$ ) HAVE_PATH_TO_ENEMY
		AT_SPARRING_RANGE 									: TORSO_BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state MANUEVER
//---------------------------------------------------------
	{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
	}
	//hzm eof
		
	TorsoBehavior torsoAimAndFireWeapon ( 0 )
	Behavior MoveRandomDirection ( "walk" , 256 , 96 , 0 , 1 , 1 )

	Time ( 3 )

	states
		{
		GENERAL_COMBAT_PAIN		: SHOW_PAIN
		AT_SPARRING_RANGE		: TORSO_BEHAVIOR_DONE
		CLOSE_IN_ON_ENEMY		: TIME_DONE
		}
	}

//------------------------------------------------------------------------------
state MELEE_COMBAT
//------------------------------------------------------------------------------
{
	Behavior DoAttack ( "" , 15 , 1 , "shuffle" )

	states
		{
		MELEE_COMBAT_RETREAT					: BEHAVIOR_SUCCESS RANGE ( $RANGE_MELEE$ )
		MELEE_COMBAT_RETREAT					: BEHAVIOR_FAILED RANGE ( $RANGE_MELEE$ )
		AT_SPARRING_RANGE						: BEHAVIOR_SUCCESS
		AT_SPARRING_RANGE						: BEHAVIOR_FAILED
		}
}

//------------------------------------------------------------------------------
state MELEE_COMBAT_RETREAT
//------------------------------------------------------------------------------
	{
	Behavior BackAwayFromEnemy ( "swat_backpedal_run" , 96.0 , 64.0 )
	TorsoBehavior torsoAimAndFireWeapon ( 0 , 1 )

	states
		{
		GENERAL_COMBAT_PAIN					: SHOW_PAIN
		AT_SPARRING_RANGE 			: BEHAVIOR_SUCCESS
		AT_SPARRING_RANGE 			: BEHAVIOR_FAILED
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
		AT_SPARRING_RANGE : ANIM_DONE
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
		AT_SPARRING_RANGE : ANIM_DONE
		}

}
