//
// Name:     nausicaan-m9-merc-knife-combat.st
// Purpose:  AI for combatative nausicaan merc with knife
//

$define RANGE_SPAR_MAX 192
$define RANGE_SPAR_MIN 160
$define DISTANCE_STRAFE 64
$define CHANCE_REPEAT_STRAFE 1.0
$define CHANCE_DO_STRAFE .65
$define COUNT_STRAFE_REPEATS 4
$define TIME_STRAFE_MIN 3.0
$define CHANCE_ATTACK_COMBO_1 1.0
$define CHANCE_ATTACK_COMBO_2 0.5
$define CHANCE_ATTACK_COMBO_3 0.25
$define CHANCE_ATTACK 0.45
$define CHANCE_BLOCK 0.65
$define CHANCE_PARRY 0.25

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "enteredcombat"
		headwatchtarget "enemy"
		setvartime "LAST_STRAFE_FAILURE"
		setvartime "LAST_STRAFE_SUCCESS"
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		COMBAT_MAIN		: default
		}
	}

state COMBAT_MAIN
	{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		SPAR			  : default
		}
	}

state CLOSE_IN_ON_ENEMY
	{
	Behavior CloseInOnEnemy ( "run" , $RANGE_SPAR_MIN$ )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		IMMEDIATE_ATTACK : RANGE ( $RANGE_SPAR_MIN$ ) 
		SPAR : BEHAVIOR_SUCCESS
		CLOSE_IN_ON_ENEMY_FAILED	: BEHAVIOR_FAILED
		}	
	}

state CLOSE_IN_ON_ENEMY_FAILED
	{
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		COMBAT_MAIN : TIME_DONE
		}
	}

state SPAR
	{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		ATTACK_SEQUENCE : CHANCE ( $CHANCE_ATTACK$ )
		STRAFE_SEQUENCE : CHANCE ( $CHANCE_DO_STRAFE$ ) CHECK_VAR_TIME_DIFFERENCE ( "LAST_STRAFE_SUCCESS" , $TIME_STRAFE_MIN$ )		
		COMBAT_IDLE : default
		}
	}

state COMBAT_IDLE
	{
	Behavior WatchEntity ( 1 , 15 , "knife_idle" , 0 , "knife_idle" )

	time ( 1.0 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : TIME_DONE
		}
	}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//								ATTACK SEQUENCE STATES
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
state ATTACK_SEQUENCE
{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		START_ATTACK_COMBO_3 : CHANCE ( $CHANCE_ATTACK_COMBO_3$ )
		START_ATTACK_COMBO_2 : CHANCE ( $CHANCE_ATTACK_COMBO_2$ )
		START_ATTACK_COMBO_1 : default
		}
}

state START_ATTACK_COMBO_1
{
	legs
		{
		knife_combo1_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		//BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		FIRE_ATTACK_COMBO_1 : ANIM_DONE		
		}
	
}

state FIRE_ATTACK_COMBO_1
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo1" , 0 , "knife_combo1" )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK CHANCE ( $CHANCE_BLOCK$ )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}
}

state START_ATTACK_COMBO_2
{
	legs
		{
		knife_combo2_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		//BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		FIRE_ATTACK_COMBO_2 : ANIM_DONE		
		}
}

state FIRE_ATTACK_COMBO_2
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo2" , 0 , "knife_combo2" )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK CHANCE ( $CHANCE_BLOCK$ )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}
}

state START_ATTACK_COMBO_3
{
	legs
		{
		knife_combo3_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		//BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		FIRE_ATTACK_COMBO_3 : ANIM_DONE		
		}
}

state FIRE_ATTACK_COMBO_3
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo3" , 0 , "knife_combo3" )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK CHANCE ( $CHANCE_BLOCK$ )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		POSTFIRE_ATTACK_COMBO_3 : BEHAVIOR_SUCCESS
		}
}

state POSTFIRE_ATTACK_COMBO_3
{
	legs
		{
		knife_combo3_postfire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		//BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : ANIM_DONE
		}
}

state IMMEDIATE_ATTACK
{
	legs
		{
		knife_combo1_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		IMMEDIATE_ATTACK_FIRE : ANIM_DONE		
		}
}

state IMMEDIATE_ATTACK_FIRE
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo1" , 0 , "knife_combo1" )

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//								STRAFE SEQUENCE STATES
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
state STRAFE_SEQUENCE
//------------------------------------------------------------------------------
{
	entrycommands
		{
		turntowardsenemy
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		CHECK_STRAFE_LEFT : CHANCE ( .5 )
		CHECK_STRAFE_RIGHT : default
		}
}

//------------------------------------------------------------------------------
state CHECK_STRAFE_LEFT
//------------------------------------------------------------------------------
{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_LEFT : LEFT_CLEAR ( $DISTANCE_STRAFE$ )
		CHECK_STRAFE_RIGHT_BECAUSE_LEFT_FAILED : default
		}
}

state CHECK_STRAFE_RIGHT_BECAUSE_LEFT_FAILED
{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_RIGHT : RIGHT_CLEAR ( $DISTANCE_STRAFE$ )		
		STRAFE_FAILED : default
		}
}


//------------------------------------------------------------------------------
state CHECK_STRAFE_RIGHT
//------------------------------------------------------------------------------
{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_RIGHT : RIGHT_CLEAR ( $DISTANCE_STRAFE$ )
		CHECK_STRAFE_RIGHT_BECAUSE_LEFT_FAILED : default
		}
}

state CHECK_STRAFE_LEFT_BECAUSE_RIGHT_FAILED
{
	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_LEFT : LEFT_CLEAR ( $DISTANCE_STRAFE$ )		
		STRAFE_FAILED : default
		}
}

state DO_STRAFE_LEFT
{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		knife_strafeL : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_LEFT_REPEAT : CHANCE ( $CHANCE_REPEAT_STRAFE$ ) LEFT_CLEAR ( $DISTANCE_STRAFE$ ) !STAGE ( $COUNT_STRAFE_REPEATS$ )
		CLEAR_STRAFE_COUNT : default
		}
}

state DO_STRAFE_LEFT_REPEAT
{
	entrycommands
		{
		gotonextstage
		}

	time ( .25 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_LEFT : TIME_DONE
		}
}

state DO_STRAFE_RIGHT
{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		knife_strafeR : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_RIGHT_REPEAT : CHANCE ( $CHANCE_REPEAT_STRAFE$ ) RIGHT_CLEAR ( $DISTANCE_STRAFE$ ) !STAGE ( $COUNT_STRAFE_REPEATS$ )
		CLEAR_STRAFE_COUNT : default
		}
}

state DO_STRAFE_RIGHT_REPEAT
{
	entrycommands
		{
		gotonextstage
		}

	time ( .25 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		DO_STRAFE_RIGHT : TIME_DONE
		}
}

state CLEAR_STRAFE_COUNT
{
	entrycommands
		{
		gotostage 1
		setvartime "LAST_STRAFE_SUCCESS"
		}

	time ( .25 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		COMBAT_MAIN : TIME_DONE
		}
}

state STRAFE_FAILED
{
	entrycommands
		{
		setvartime "LAST_STRAFE_FAILURE"
		}

	legs
		{
		idle : default
		}

	time ( .30 )

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		BLOCK_ATTACK    : INCOMING_MELEE_ATTACK
		COMBAT_MAIN : TIME_DONE
		}
	
}

state BLOCK_ATTACK
{
	states
		{
		END				: HEALTH ( 2 )
		PARRY_ATTACK	: CHANCE ( $CHANCE_PARRY$ )
		DO_BLOCK_ATTACK : default
		}
}

state DO_BLOCK_ATTACK
{
	entrycommands
		{
		turntowardsplayer
		}

	legs
		{
		knife_block : default
		}

	states
		{
		END				: HEALTH ( 2 )
		PAIN			: SHOW_PAIN
		IMMEDIATE_ATTACK_NO_PAIN : !INCOMING_MELEE_ATTACK RANGE ( $RANGE_SPAR_MIN$ )
		COMBAT_MAIN : !INCOMING_MELEE_ATTACK
		}
}

state PARRY_ATTACK
{
	legs
		{
		knife_combo2_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		IMMEDIATE_ATTACK_FIRE : ANIM_DONE		
		}
}

state PARRY_ATTACK_FIRE
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo2" , 0 , "knife_combo2" )

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}

}

state PAIN
{
	entrycommands
		{
		runthread npcBoo
		}

	states
		{
		END				: HEALTH ( 2 )
		BIG_PAIN : default
		}
}

//---------------------------------------------------------
state BIG_PAIN
//---------------------------------------------------------
{
	legs
		{
		pain_knockback : default
		}

	states
		{	
		END				: HEALTH ( 2 )
		IMMEDIATE_ATTACK_NO_PAIN : ANIM_DONE RANGE ( $RANGE_SPAR_MIN$ )	
		COMBAT_MAIN : ANIM_DONE
		}	
}

//---------------------------------------------------------
state SMALL_PAIN
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
		END				: HEALTH ( 2 )	
		IMMEDIATE_ATTACK_NO_PAIN : ANIM_DONE RANGE ( $RANGE_SPAR_MIN$ )
		COMBAT_MAIN : ANIM_DONE
		}

}

state IMMEDIATE_ATTACK_NO_PAIN
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo1" , 0 , "knife_combo1" )

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}
}

state IMMEDIATE_ATTACK_NO_PAIN
{
	legs
		{
		knife_combo1_prefire : default
		}

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		IMMEDIATE_ATTACK_FIRE : ANIM_DONE		
		}
}

state IMMEDIATE_ATTACK_NO_PAIN_FIRE
{
	Behavior WatchEntity ( 1 , 15 , "knife_combo1" , 0 , "knife_combo1" )

	states
		{
		END				: HEALTH ( 2 )
		CLOSE_IN_ON_ENEMY : !RANGE ( $RANGE_SPAR_MAX$ )
		COMBAT_MAIN : BEHAVIOR_SUCCESS
		}

}

state END
{
	entrycommands
		{
		runthread endBarFightSequence
		}

	legs
		{
		death : default
		}
}