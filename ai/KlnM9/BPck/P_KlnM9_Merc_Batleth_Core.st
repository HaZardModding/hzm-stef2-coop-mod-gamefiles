//
// Name:	 KlingonMercM9/behaviorpackages/batleth-core.st
// Purpose:	 AI	for	combatative	klingon	mercs with batleths
//

//
// Includes
//

//
// Defines
//
$define	RANGE_WORK 256
$define	RANGE_PATROL 256
$define	STAGE_TURN 8
$define	TIME_PLAYER_ATTACK .75

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	entrycommands
	{
		setvartime ( "playerattacked" )
//printmessage "START CORE"
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
//printmessage "CORE_MAIN CORE"
}

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		//SNIPER_WAIT			: SHOULD_DO_ACTION ( "snipeenemy" )
		//FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" )	FOLLOW_TARGET_OUT_OF_RANGE
		//HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume"	) PLAYER_IN_CALL_VOLUME
		//GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" )	IN_THE_WAY
		//WORK				: SHOULD_DO_ACTION ( "work"	) VALID_WORK_NODE_IN_RANGE ( $RANGE_WORK$ )
		
		//hzm coop mod chrissstrahl - we want this to work - utilized on coop_gbs7
		PATROL				: SHOULD_DO_ACTION ( "patrol" )	VALID_PATROL_NODE_IN_RANGE ( $RANGE_PATROL$	)
		
		//[b60025] chrissstrahl - allow ai to wander if friendly or teammmate - disable with $actor.setTendency("wander",0);
		//these are used in singleplayer in mission 9 klingon base as enemies, we don't want their behaviour changed there
		WANDER				: SHOULD_DO_ACTION ( "wander" ) CHANCE ( 0.25 ) !ACTORTYPE ( "enemy" )
		
		
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
//printmessage "PATROL CORE"
	}

	Behavior Patrol	( "walk" )

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		WORK				: SHOULD_DO_ACTION ( "work"	) VALID_WORK_NODE_IN_RANGE ( $RANGE_WORK$ )
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
//printmessage "PATROL_FAILED CORE"
}

	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		PATROL	: TIME_DONE
	}
}


//---------------------------------------------------------
state WORK
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "work"
//printmessage "WORK CORE"
	}

	Behavior Work (	"walk" )

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

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
//printmessage "WORK_FAILED CORE"
}

	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

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
//printmessage "WANDER CORE"
	}

	Behavior MoveRandomDirection ( "walk" , 192 , 64 )

	states
	{
		//SNIPER_WAIT			: SHOULD_DO_ACTION ( "snipeenemy" )
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		//FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" )	FOLLOW_TARGET_OUT_OF_RANGE
		//HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume"	) PLAYER_IN_CALL_VOLUME
		//GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" )	IN_THE_WAY
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
		//printmessage "WANDER_WAIT CORE"
		
		//[b60025] chrissstrahl - allow to look at player for a moment
		headwatchtarget player
		setheadwatchmaxdistance 256
	}

	Behavior HoldPosition

	time ( 7.5 , 10	)

	states
	{
		//SNIPER_WAIT			: SHOULD_DO_ACTION ( "snipeenemy" )
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		//FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" )	FOLLOW_TARGET_OUT_OF_RANGE
		//HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume"	) PLAYER_IN_CALL_VOLUME
		//GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" )	IN_THE_WAY
		CORE_MAIN			: TIME_DONE
	}
	
	exitcommands
	{
		//[b60025] chrissstrahl - allow to look at player for a moment - reset
		headwatchtarget none
		setheadwatchmaxdistance -1
	}
}

//---------------------------------------------------------
state WANDER_FAILED
//---------------------------------------------------------
{
entrycommands
{
	//printmessage "WANDER_FAILED CORE"
}
	Behavior HoldPosition

	time ( 1.0 )

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED

		//GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" )	IN_THE_WAY
		WANDER	: TIME_DONE
	}
}

//state SNIPER_WAIT
//{
//	Behavior HoldPosition
//}
//
//state FOLLOW_THE_LEADER
//{
//	entrycommands
//	{
//		incontext "noncombatfollow"
//	}
//
//	Behavior GroupFollow ( 256 , 320 )
//
//	states
//	{
//		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
//		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume"	) PLAYER_IN_CALL_VOLUME
//		CORE_PAIN			: SHOW_PAIN
//		CORE_COWER			: OTHER_DIED
//
//		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" )	IN_THE_WAY
//		CORE_MAIN			: BEHAVIOR_SUCCESS
//		//WANDER_WAIT			: BEHAVIOR_SUCCESS
//		HOLD				: BEHAVIOR_FAILED
//	}
//}

state PLAYER_ATTACKED
{
	entrycommands
	{
//[b60025] chrissstrahl
//printmessage "PLAYER_ATTACKED CORE"
	}

	states
	{
		UPGRADE_STAGE		: CHECK_VAR_TIME_DIFFERENCE	( "playerattacked" , $TIME_PLAYER_ATTACK$ )
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
		
//[b60025] chrissstrahl
//printmessage "UPGRADE_STAGE CORE"
	}

	states
	{
		TURN_AGAINST_PLAYER	: STAGE	( $STAGE_TURN$ )
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
		failmission	8
		
//printmessage "TURN_AGAINST_PLAYER CORE"
	}
}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
{
entrycommands
{
	//printmessage "HOLD CORE"
}

	legs
	{
		idle : default
	}

	time ( 1.0 )

	states
	{
		//GET_OUT_OF_THE_WAY	: IN_THE_WAY
		CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED
		CORE_MAIN			: TIME_DONE
	}
}

////---------------------------------------------------------
//state HANDLE_CALL_VOLUME
////---------------------------------------------------------
//{
//	entrycommands
//	{
//		incontext "incallvolume"
//	}
//
//	Behavior GotoLiftPosition
//
//	states
//	{
//		CORE_MAIN				: !PLAYER_IN_CALL_VOLUME
//		CORE_MAIN				: BEHAVIOR_SUCCESS
//		CALL_VOLUME_FAILED		: BEHAVIOR_FAILED
//	}
//}
//
////---------------------------------------------------------
//state CALL_VOLUME_FAILED
////---------------------------------------------------------
//{
//	legs
//	{
//		duck	: default
//	}
//}
//
////---------------------------------------------------------
//state GET_OUT_OF_THE_WAY
////---------------------------------------------------------
//{
//	Behavior MoveFromConeOfFire	( "walk" )
//	time ( 1.5 )
//
//	states
//	{
//		CORE_MAIN	: BEHAVIOR_SUCCESS
//		HOLD		: BEHAVIOR_FAILED
//		CORE_MAIN	: TIME_DONE
//	}
//}
//
//state CORE_COWER
//{
//	entrycommands
//	{
//		cleartorsoanim
//	}
//	legs
//	{
//		cower :	default
//	}
//
//	time ( 5 , 7.0 )
//
//	states
//	{
//		CORE_MAIN :	TIME_DONE
//	}
//}
//
//---------------------------------------------------------
state CORE_PAIN
//---------------------------------------------------------
{
entrycommands
{
	//printmessage "CORE_PAIN CORE"
}
	states
	{
		CORE_BIG_PAIN	  :	MOD	( "explosion" )
		CORE_BIG_PAIN	  :	MOD	( "imod_primary" )
		CORE_BIG_PAIN	  :	MOD	( "plasmashotgun" )
		CORE_BIG_PAIN	  :	MOD	( "small_explosion"	)
		CORE_SMALL_PAIN	: default
	}
}

//---------------------------------------------------------
state CORE_BIG_PAIN
//---------------------------------------------------------
{
entrycommands
{
//printmessage "CORE_BIG_PAIN CORE"
}
	legs
	{
		pain_knockback : default
	}

	states
	{
		CORE_MAIN :	ANIM_DONE
	}
}

//---------------------------------------------------------
state CORE_SMALL_PAIN
//---------------------------------------------------------
{
	entrycommands
	{
		saveofflasthitbone
//printmessage "CORE_SMALL_PAIN CORE"
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
		CORE_MAIN :	ANIM_DONE
	}

}
