//
// Name:     Humanoid_PackageCore
// Purpose:  AI for Non Combat State Humanoids
//

//
// Includes
//

//
// Defines
//
$define RANGE_WORK 256
$define RANGE_PATROL 256
$define STAGE_TURN 8
$define TIME_PLAYER_ATTACK .75 

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		setvartime ( "playerattacked" )
		
		//[b60025] chrissstrahl - this is required now since we do not check distance to player but to followtarget
		//we don't need to set it in multiplayer/coop
		multiplayer setTendency ( "fix_follow_player_sp" , "1.0" )
		}

	states
		{
		//[b60025] chrissstrahl - this is required now since we do not check distance to player but to followtarget
		FIX_FOLLOW_PLAYER_SP : !SHOULD_DO_ACTION ( "fix_follow_player_sp" )
		
		CORE_MAIN	: default
		}
	}
	
//[b60025] chrissstrahl - this is required now since we do not check distance to player but to followtarget
//---------------------------------------------------------
state FIX_FOLLOW_PLAYER_SP
//---------------------------------------------------------
{
entrycommands
	{
	setTendency ( "fix_follow_player_sp" , "1.0" )
	followtarget ( "$player" )
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
	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 

		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		WANDER				: SHOULD_DO_ACTION ( "wander" )				
		HOLD				: default
		}
}

//---------------------------------------------------------
state WANDER
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "wander"
		}

	Behavior MoveRandomDirection ( "walk" , 128 , 96 )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 

		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		WANDER_WAIT			: BEHAVIOR_SUCCESS
		WANDER_FAILED		: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state WANDER_WAIT
//---------------------------------------------------------
{
	Behavior HoldPosition

	time ( 7.5 , 10 )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 

		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: TIME_DONE
		}
}

//---------------------------------------------------------
state WANDER_FAILED
//---------------------------------------------------------
	{
	Behavior HoldPosition

	time ( 1.0 )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 

		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		WANDER	: TIME_DONE
		}
	}


//---------------------------------------------------------
state FOLLOW_THE_LEADER
//---------------------------------------------------------
{
	entrycommands
		{
		incontext "noncombatfollow"
		}

	Behavior GroupFollow ( 256 , 320 )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 

		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}

state PLAYER_ATTACKED
{

	states
		{
		UPGRADE_STAGE		: CHECK_VAR_TIME_DIFFERENCE ( "playerattacked" , $TIME_PLAYER_ATTACK$ )
		CORE_PAIN			: default
		}
}

state UPGRADE_STAGE
{
	entrycommands
		{
		incontext "playerattacked"	
		gotonextstage
		setvartime ( "playerattacked" )
		}

	states
		{
		TURN_AGAINST_PLAYER : STAGE ( $STAGE_TURN$ )
		CORE_PAIN			: default
		}
}

state TURN_AGAINST_PLAYER
{
	entrycommands
		{
		incontext "turnonplayer"
		attackplayer
		groupattack	1	
		failmission 8
		}	
}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
	{
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		GET_OUT_OF_THE_WAY	: IN_THE_WAY
		CORE_PAIN			: SHOW_PAIN
		CORE_COWER			: OTHER_DIED 
		CORE_MAIN			: TIME_DONE		
		}
	}

//---------------------------------------------------------
state HANDLE_CALL_VOLUME
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "incallvolume"
		}

	Behavior GotoLiftPosition

	states
		{
		CORE_MAIN				: !PLAYER_IN_CALL_VOLUME
		CORE_MAIN				: BEHAVIOR_SUCCESS
		CALL_VOLUME_FAILED		: BEHAVIOR_FAILED	 
		}
	}

//---------------------------------------------------------
state CALL_VOLUME_FAILED
//---------------------------------------------------------
{
	legs
		{
		idle : default
		}
		
	Time ( 1 )
	
	states
	{
		CORE_MAIN : TIME_DONE
	}
	
}

//---------------------------------------------------------
state GET_OUT_OF_THE_WAY 
//---------------------------------------------------------
{
	Behavior MoveFromConeOfFire ( "walk" )
	time ( 1.5 )

	states
		{
		CORE_MAIN	: BEHAVIOR_SUCCESS		
		HOLD		: BEHAVIOR_FAILED		
		CORE_MAIN  	: TIME_DONE
		}	  
}

state CORE_COWER
{
	entrycommands
		{
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
		CORE_MAIN : ANIM_DONE
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
		CORE_MAIN : ANIM_DONE
		}

}
