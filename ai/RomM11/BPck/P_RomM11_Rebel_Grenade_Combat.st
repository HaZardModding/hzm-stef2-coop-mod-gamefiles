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
$define RANGE_MAX_DISTANCE_TO_COMBAT_NODE 512
$define RANGE_MIN_DISTANCE_TO_COMBAT_NODE 0
$define RANGE_MELEE							96
$define RANGE_ATTACK						1800

$define TIME_COVER_RECHECK 1.0
$define TIME_WAIT_ON_ATTACK_MIN				1.0
$define TIME_WAIT_ON_ATTACK_MAX				1.5
$define TIME_WAIT_AT_COVER_MIN				1.0
$define TIME_WAIT_AT_COVER_MAX				1.0
$define CHANCE_REPEAT_ATTACK				.45
$define COUNT_MAX_REPEATS					2
//---------------------------------------------------------

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
		entrycommands
		{
		setvartime ( "last_dodge" )
		groupattack 1
		selectclosestenemy
		}

	states
		{
		GOTO_COMBAT_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_VALID_POSITION_AVAILABLE : default
		}
	}

//---------------------------------------------------------
state NO_VALID_POSITION_AVAILABLE
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "NO_VALID_POSITION_AVAILABLE" )
	}
	states
		{
		NO_VALID_POSITION_AVAILABLE_ATTACK : RANGE ( $RANGE_ATTACK$ , 0 , 0 , 1 )
		NO_VALID_POSITION_AVAILABLE_WAIT : default
		}
	}

state NO_VALID_POSITION_AVAILABLE_WAIT
	{
	entrycommands
	{
		printmessage ( "NO_VALID_POSITION_AVAILABLE_WAIT" )
	}
	Behavior WatchEntity ( 1 , 15 , "idle" , 0 , "idle" )

	states
		{
		NO_VALID_POSITION_AVAILABLE_ATTACK : RANGE ( $RANGE_ATTACK$ , 0 , 0 , 1 )
		}

	}

state NO_VALID_POSITION_AVAILABLE_ATTACK
	{
	entrycommands
		{
		printmessage ( "NO_VALID_POSITION_AVAILABLE_ATTACK" )
		turntowardsenemy
		}

	legs
		{
		grenade_throw : default
		}

	states
		{
		GENERAL_COMBAT_PAIN		: SHOW_PAIN
		LOOK_FOR_POSITION 		: ANIM_DONE
		}
	}

//---------------------------------------------------------
state LOOK_FOR_POSITION
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "LOOK_FOR_POSITION" )
	}
	states
		{
		GOTO_COMBAT_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_VALID_POSITION_AVAILABLE : default
		}
	}

//---------------------------------------------------------
state GOTO_COMBAT_POSITION
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage ( "GOTO_COMBAT_POSITION" )
		incontext "incombat"
		}

	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		AT_COMBAT_POSITION 				: BEHAVIOR_SUCCESS
		NO_VALID_POSITION_AVAILABLE	: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state AT_COMBAT_POSITION
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "AT_COMBAT_POSITION" )
	}
	
	Behavior WatchEntity ( 1 , 15 , "idle" , 0 , "idle" )

	time ( $TIME_WAIT_ON_ATTACK_MIN$ , $TIME_WAIT_ON_ATTACK_MAX$ )

	states
		{
		ATTACK_FROM_COMBAT_POSITION : TIME_DONE RANGE ( $RANGE_ATTACK$ , 0 , 0 , 1 )
		}
	}


//---------------------------------------------------------
state ATTACK_FROM_COMBAT_POSITION
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "ATTACK_FROM_COMBAT_POSITION" )
	}
	
	states
		{
		GOTO_ATTACK_POSITION : VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_VALID_POSITION_AVAILABLE : default
		}
	}

//---------------------------------------------------------
state GOTO_ATTACK_POSITION
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "GOTO_ATTACK_POSITION" )
	}
	
	behavior GotoCurrentHelperNode ( "run" )

	states
		{
		AT_ATTACK_POSITION 				: BEHAVIOR_SUCCESS
		NO_VALID_POSITION_AVAILABLE	: BEHAVIOR_FAILED
		}
	}

state AT_ATTACK_POSITION
	{
	entrycommands
		{
		printmessage ( "AT_ATTACK_POSITION" )
		turntowardsenemy
		}

	legs
		{
		grenade_throw : default
		}

	states
		{
		GENERAL_COMBAT_PAIN				: SHOW_PAIN
		GOTO_COMBAT_POSITION 			: ANIM_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_VALID_POSITION_AVAILABLE	: ANIM_DONE
		}
	}




//---------------------------------------------------------
state GENERAL_COMBAT_PAIN
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage ( "GENERAL_COMBAT_PAIN" )
		}
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
	entrycommands
		{
		printmessage ( "GENERAL_COMBAT_BIG_PAIN" )
		}
	legs
		{
		pain_knockback : default
		}

	states
		{
		POST_PAIN_ATTACK : ANIM_DONE
		}
}

//---------------------------------------------------------
state GENERAL_COMBAT_SMALL_PAIN
//---------------------------------------------------------
{
	entrycommands
		{
		printmessage ( "GENERAL_COMBAT_SMALL_PAIN" )
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
		POST_PAIN_ATTACK : ANIM_DONE
		}

}

state POST_PAIN_ATTACK
{
	entrycommands
		{
		printmessage ( "POST_PAIN_ATTACK" )
		turntowardsenemy
		}

	legs
		{
		grenade_throw : default
		}

	states
		{
		GOTO_COMBAT_POSITION	: ANIM_DONE
		}
}