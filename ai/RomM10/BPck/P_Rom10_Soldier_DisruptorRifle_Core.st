//---------------------------------------------------------
$define RANGE_WORK			256
$define RANGE_PATROL		256
$define STAGE_TURN			  8
$define TIME_PLAYER_ATTACK	.75
//---------------------------------------------------------

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	entrycommands
	{
		setvartime ( "playerattacked" )
		//turntowardsplayer
		//printmessage "START"
	}

	states
	{
		CORE_MAIN	: default
	}
}

//---------------------------------------------------------
state CORE_MAIN
//---------------------------------------------------------
{
	entrycommands
	{
		forgetenemies
		//printmessage "CORE_MAIN"
	}

	states
	{
		CORE_PAIN			: SHOW_PAIN
		TO_COMBAT			: OTHER_DIED
		
		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		TO_COMBAT			: CAN_SEE_ENEMY

		PATROL				: SHOULD_DO_ACTION ( "patrol" ) VALID_PATROL_NODE_IN_RANGE ( $RANGE_PATROL$ )
		WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( $RANGE_WORK$ )
		WANDER				: SHOULD_DO_ACTION ( "wander" )
		HOLD				: default
	}
}

//---------------------------------------------------------
state PATROL
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "patrol"
		//printmessage "PATROL"
	}

	Behavior Patrol ( "walk" )

	states
	{
		CORE_PAIN			: SHOW_PAIN

		TO_COMBAT			: OTHER_DIED
		TO_COMBAT			: ATTACKED
		TO_COMBAT 			: PAIN

		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED 			: CAN_SEE_ENEMY
		
		WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( $RANGE_WORK$ )
		CORE_MAIN			: BEHAVIOR_SUCCESS
		PATROL_FAILED		: BEHAVIOR_FAILED
	}
}

//---------------------------------------------------------
state PATROL_FAILED
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "PATROL_FAILED"
	}

	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		CORE_PAIN		: SHOW_PAIN
		TO_COMBAT		: ATTACKED
		TO_COMBAT 		: PAIN
		TO_COMBAT		: OTHER_DIED

		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED 		: CAN_SEE_ENEMY
		
		//[b60025] chrissstrahl - allow actor get out of Patrol state
		CORE_MAIN		: TIME_DONE
	}
}


//---------------------------------------------------------
state WORK
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "work"
		//printmessage "WORK"
	}

	Behavior Work ( "walk" )

	states
	{
		CORE_PAIN		: SHOW_PAIN
		TO_COMBAT		: OTHER_DIED
		TO_COMBAT		: ATTACKED
		TO_COMBAT 		: PAIN

		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED 		: CAN_SEE_ENEMY

		CORE_MAIN	: BEHAVIOR_SUCCESS
		WORK_FAILED	: BEHAVIOR_FAILED
	}
}

//---------------------------------------------------------
state WORK_FAILED
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "WORK_FAILED"
	}
	
	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		TO_COMBAT			: OTHER_DIED
		TO_COMBAT			: ATTACKED
		TO_COMBAT 			: PAIN
		
		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED 			: CAN_SEE_ENEMY

		WORK	: TIME_DONE
	}
}

//---------------------------------------------------------
state WANDER
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "wander"
		//printmessage "WANDER"
	}

	//[b60025] chrissstrahl - Fixed: Wander STATE, changed min dist to 32 from 96
	Behavior MoveRandomDirection ( "walk" , 128 , 32 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		TO_COMBAT			: OTHER_DIED
		TO_COMBAT			: ATTACKED
		TO_COMBAT 			: PAIN

		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED				: CAN_SEE_ENEMY

		WANDER_WAIT			: BEHAVIOR_SUCCESS
		WANDER_FAILED		: BEHAVIOR_FAILED
	}
}

//---------------------------------------------------------
state WANDER_WAIT
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "WANDER_WAIT"
	}
	
	Behavior HoldPosition

	time ( 7.5 , 10 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		TO_COMBAT			: OTHER_DIED
		TO_COMBAT			: ATTACKED
		TO_COMBAT 			: PAIN

		//[b60025] chrissstrahl - Actor can now resume core behaviour after Combat
		ALERTED 			: CAN_SEE_ENEMY

		CORE_MAIN			: TIME_DONE
	}
}

//---------------------------------------------------------
state WANDER_FAILED
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "WANDER_FAILED"
	}
	
	Behavior HoldPosition

	time ( 1.0 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		TO_COMBAT			: OTHER_DIED
		TO_COMBAT			: ATTACKED
		TO_COMBAT 			: PAIN

		//[b60025] chrissstrahl - allow actor to attack enemy when seeing him
		ALERTED 			: CAN_SEE_ENEMY

		WANDER	: TIME_DONE
		
		//[b60025] chrissstrahl - Fixed: Getting stuck in WANDER states
		CORE_MAIN : default
	}
}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "HOLD"
	}
	
	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		CORE_PAIN	: SHOW_PAIN
		TO_COMBAT	: OTHER_DIED
		TO_COMBAT	: ATTACKED
		TO_COMBAT 	: PAIN
		ALERTED 	: TIME_DONE HAVE_ENEMY
		CORE_MAIN	: TIME_DONE
	}
}

////---------------------------------------------------------
//state CORE_COWER
////---------------------------------------------------------
//{
//	entrycommands
//	{
//		cleartorsoanim
//	}
//	legs
//	{
//		cower : default
//	}
//
//	time ( 5 , 7.0 )
//
//	states
//	{
//		ALERTED 	: HAVE_ENEMY
//		CORE_MAIN : TIME_DONE
//	}
//}

//---------------------------------------------------------
state CORE_PAIN
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "CORE_PAIN"
	}
	
	states
	{
		CORE_BIG_PAIN	  : MOD ( "explosion" )
		CORE_BIG_PAIN	  : MOD ( "imod_primary" )
		CORE_BIG_PAIN	  : MOD ( "plasmashotgun" )
		CORE_BIG_PAIN	  : MOD ( "small_explosion" )
		CORE_SMALL_PAIN : default
	}
}

//---------------------------------------------------------
state CORE_BIG_PAIN
//---------------------------------------------------------
{
	legs
	{
		pain_knockback : default
	}

	states
	{
		TO_COMBAT : ANIM_DONE
	}
}

//---------------------------------------------------------
state CORE_SMALL_PAIN
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
		TO_COMBAT : ANIM_DONE
	}

}

//---------------------------------------------------------
state TO_COMBAT
//---------------------------------------------------------
{
	entrycommands
	{
		groupattack
		selectclosestenemy
		
		//[b60025] chrissstrahl - Fixed: AI not being able to reenter combat again
		//setvar ( "manual_state" , "combat" )
		usebehaviorpackage ( "romulan_m10_soldier_rifle_combat" )
		
		//printmessage "TO_COMBAT"
	}
}

//---------------------------------------------------------
state ALERTED
//---------------------------------------------------------
{
	entrycommands
	{
		turntowardsenemy
		forgetenemies
		//jhefty -- this is a male voice, but the riflemen are all women
		//playdialog ( "localization/sound/dialog/m10l1/rom_whatthat.mp3" , 1 , 192 , 0)
		
		//printmessage "ALERTED"
	}

	legs
	{
		//patrol_whosthere : CHANCE ( 0.25 )
		//d : CHANCE ( 0.25 )
		patrol_spotted : default
	}

	states
	{
		TO_COMBAT	: ATTACKED
		TO_COMBAT 	: PAIN
		TO_COMBAT	: CAN_SEE_ENEMY
		INVESTIGATE : ANIM_DONE
	}
}

//---------------------------------------------------------
state INVESTIGATE
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "INVESTIGATE"
	}
	
	Behavior Investigate ( "walk" , 5 , 0 , "patrol_search" , 3 )

	Time ( 2 );

	states
	{
		TO_COMBAT	: ATTACKED
		TO_COMBAT 	: PAIN
		TO_COMBAT	: CAN_SEE_ENEMY

		TO_COMBAT	: TIME_DONE HAVE_ENEMY

		CORE_PAIN 	: SHOW_PAIN

		CORE_MAIN 	: BEHAVIOR_DONE
	}
}

