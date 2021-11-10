//
// Name:     Package_GrenadeCore
// Purpose:  AI for Non Combat State Romulans
//

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
		printmessage ( "CORE_MAIN" )
	}
	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

		//PATROL				: SHOULD_DO_ACTION ( "patrol" ) VALID_PATROL_NODE_IN_RANGE ( $RANGE_PATROL$ )
		//WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( $RANGE_WORK$ )
		//WANDER				: SHOULD_DO_ACTION ( "wander" )				
		HOLD				: default
		}
}

//---------------------------------------------------------
state PATROL
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage ( "PATROL" )
		incontext "patrol"
		}

	Behavior Patrol ( "walk" )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

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
		printmessage ( "PATROL_FAILED" )
	}
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

		PATROL	: TIME_DONE
		}
	}


//---------------------------------------------------------
state WORK
//---------------------------------------------------------
{
	entrycommands
		{
		printmessage ( "WORK" )
		incontext "work"
		}

	Behavior Work ( "walk" )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

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
		printmessage ( "WORK_FAILED" )
	}
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

		WORK	: TIME_DONE
		}
}

//---------------------------------------------------------
state WANDER
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage ( "WANDER" )
		incontext "wander"
		}

	Behavior MoveRandomDirection ( "walk" , 128 , 96 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation

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
		printmessage ( "WANDER_WAIT" )
	}
	Behavior HoldPosition

	time ( 7.5 , 10 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation
		CORE_MAIN			: TIME_DONE
		}
}

//---------------------------------------------------------
state WANDER_FAILED
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "WANDER_FAILED" )
	}
	Behavior HoldPosition

	time ( 1.0 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation
		WANDER	: TIME_DONE
		}
	}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "HOLD" )
	}
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED //[b610] chrissstrahl - this NPC does not have this animation
		CORE_MAIN			: TIME_DONE		
		}
	}

//---------------------------------------------------------
state CORE_COWER
//---------------------------------------------------------
{
	entrycommands
		{
		printmessage ( "CORE_COWER" )
		cleartorsoanim
		}
	legs
		{
		cower : default
		}

	time ( 5 , 7.0 )

	states
		{
		CORE_MAIN : TIME_DONE
		}
}

//---------------------------------------------------------
state CORE_PAIN
//---------------------------------------------------------
	{
	entrycommands
	{
		printmessage ( "CORE_PAIN" )
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
	entrycommands
	{
		printmessage ( "CORE_BIG_PAIN" )
	}
	legs
		{
		pain_knockback : default
		}

	states
		{		
		CORE_MAIN : ANIM_DONE
		}
}

//---------------------------------------------------------
state CORE_SMALL_PAIN
//---------------------------------------------------------
{
		entrycommands
		{
		printmessage ( "CORE_SMALL_PAIN" )
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
		CORE_MAIN : ANIM_DONE
		}

}
