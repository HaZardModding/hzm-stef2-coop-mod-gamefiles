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
$define MIN_WAIT_FOR_PLAYER_RANGE 256
//[b611] chrissstrahl - changed for better ai behaviour
$define PLAYER_DISTANCE_OPTIMAL_FOR_LEAD_CONTINUE 256
$define MAX_WAIT_FOR_PLAYER_RANGE 512

//cleartorsoanim
//resettorso
//endtorsobehavior
//chrissstrahl - new states to make bathleth team ai smarter - 2020.10.10
//added state for patroling (fast/slow), following player and more stuff

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
	entrycommands
	{
	//printmessage "CORE_MAIN"
	cleartorsoanim
	}
	
	states
	{
		
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		//chrissstrahl - added states for smarter ai - 2020.10.10
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		
		//[b60025] chrissstrahl - allow following objects
		FOLLOW_OBJECT		: SHOULD_DO_ACTION ( "followobject" ) FOLLOW_TARGET_OUT_OF_RANGE
		
		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		//[b610] chrissstrahl - changed so the ai does not go back and forth because of bad distance checks
		//[b60025] chrissstrahl - added !follow check and added patrol
		LEAD				: !SHOULD_DO_ACTION ( "follow" ) SHOULD_DO_ACTION ( "patrol" )
		LEAD				: !SHOULD_DO_ACTION ( "follow" ) SHOULD_DO_ACTION ( "lead" ) PLAYER_RANGE ( $PLAYER_DISTANCE_OPTIMAL_FOR_LEAD_CONTINUE$ )
		WANDER				: SHOULD_DO_ACTION ( "wander" ) 
		//end chrissstrahl
		HOLD				: default
	}
}


//---------------------------------------------------------
state WANDER
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "WANDER"
		incontext "wander"
	}

	Behavior MoveRandomDirection ( "walk" ,	128	, 32 ) //chrissstrahl - fixed min distance - 2020.10.10

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		WANDER_WAIT			: BEHAVIOR_SUCCESS
		WANDER_FAILED		: BEHAVIOR_FAILED
		//chrissstrahl - added states for smarter ai - 2020.10.10
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		//end chrissstrahl
	}
}

//---------------------------------------------------------
state WANDER_WAIT
//---------------------------------------------------------
{
	Behavior HoldPosition
	
	entrycommands
	{
	//printmessage "WANDER_WAIT"
	headwatchtarget player
	setheadwatchmaxdistance 196
	}
	
	legs
	{
		batleth_idle : default
	}

	time ( 1.5 , 5 ) //[b60025] chrissstrahl - changed from 3 sec to 5

	states
	{
		//chrissstrahl - added states for smarter ai - 2020.10.10
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		
		//[b60025] chrissstrahl - allow following objects
		FOLLOW_OBJECT		: SHOULD_DO_ACTION ( "followobject" ) FOLLOW_TARGET_OUT_OF_RANGE
		
		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		
		//[b60025] chrissstrahl - added !follow check and added patrol
		LEAD				: !SHOULD_DO_ACTION ( "follow" ) SHOULD_DO_ACTION ( "patrol" )
		LEAD				: !SHOULD_DO_ACTION ( "follow" ) SHOULD_DO_ACTION ( "lead" ) PLAYER_RANGE ( $PLAYER_DISTANCE_OPTIMAL_FOR_LEAD_CONTINUE$ )

		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		CORE_MAIN			: TIME_DONE
	}
	exitcommands
	{
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
		//printmessage "WANDER_FAILED"
	}
	
	Behavior HoldPosition

	time ( 1.0 )

	states
	{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate"	)
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "friend" )
		CORE_PAIN			: SHOW_PAIN
		WANDER	: TIME_DONE
	}
}

//---------------------------------------------------------
state PLAYER_ATTACKED
//---------------------------------------------------------
{
	entrycommands
	{
		//printmessage "PLAYER_ATTACKED"
	}
	states
	{
		UPGRADE_STAGE		: CHECK_VAR_TIME_DIFFERENCE	( "playerattacked" , $TIME_PLAYER_ATTACK$ )
		CORE_PAIN			: default
	}
}

//---------------------------------------------------------
state UPGRADE_STAGE
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "playerattacked"
		gotonextstage
		setvartime ( "playerattacked" )
		//printmessage( "UPGRADE_STAGE" )
	}

	states
	{
		TURN_AGAINST_PLAYER	: STAGE	( $STAGE_TURN$ )
		CORE_PAIN			: default
	}
}

//---------------------------------------------------------
state TURN_AGAINST_PLAYER
//---------------------------------------------------------
{
	entrycommands
	{
		incontext "turnonplayer"
		attackplayer
		groupattack	1
		failmission	8
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
		batleth_idle : default
	}

	time ( 1.0 )

	states
	{
		CORE_PAIN			: SHOW_PAIN
		CORE_MAIN			: TIME_DONE
	}
}

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
		//printmessage "CORE_BIG_PAIN"
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
		//printmessage("CORE_SMALL_PAIN")
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

//---------------------------------------------------------
state GET_OUT_OF_THE_WAY 
//---------------------------------------------------------
{
	entrycommands
	{
	//printmessage "GET_OUT_OF_THE_WAY"
	}
	
	Behavior MoveFromConeOfFire ( "walk" )
	time ( 1.5 )
	
	states
		{
		CORE_MAIN	: BEHAVIOR_SUCCESS		
		HOLD		: BEHAVIOR_FAILED		
		CORE_MAIN  	: TIME_DONE
		}
}

//---------------------------------------------------------
state FOLLOW_THE_LEADER
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	incontext "noncombatfollow"
	//printmessage "FOLLOW_THE_LEADER"
	}
		
	Behavior GroupFollow ( 256 , 320 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth
	//Behavior CloseInOnPlayer ( "run" , $MIN_WAIT_FOR_PLAYER_RANGE$ )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "follow" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}		
}

//---------------------------------------------------------
state HANDLE_CALL_VOLUME
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "incallvolume"
		//printmessage("HANDLE_CALL_VOLUME")
		}

	Behavior GotoLiftPosition

	states
		{
		CORE_MAIN				: !PLAYER_IN_CALL_VOLUME
		CORE_MAIN				: BEHAVIOR_SUCCESS
		//[b609] chrissstrahl - changed to prevent possible AI infinity loop error
		//CALL_VOLUME_FAILED		: BEHAVIOR_FAILED	 
		HOLD		: BEHAVIOR_FAILED	 
		}
	}
	
//---------------------------------------------------------
state LEAD
//---------------------------------------------------------
	{
	entrycommands
		{
		//printmessage "LEAD"
		}

	states
		{
		LEAD_SLOW			: SHOULD_DO_ACTION ( "patrol" )
		LEAD_SLOW			: SHOULD_DO_ACTION ( "leadslow" )
		LEAD_FAST			: default
		}
	}
	
//---------------------------------------------------------
state LEAD_SLOW
//---------------------------------------------------------
	{
	entrycommands
		{
		//printmessage "LEAD_SLOW"
		}
		
	Behavior Patrol ( "walk" )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		TURN_TO_PLAYER   	: !SHOULD_DO_ACTION ( "patrol" ) !PLAYER_RANGE ( $MAX_WAIT_FOR_PLAYER_RANGE$ )
		CORE_MAIN			 : BEHAVIOR_SUCCESS
		CORE_MAIN			 : BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state LEAD_FAST
//---------------------------------------------------------
	{
	entrycommands
		{
		//printmessage "LEAD_FAST"
		}
		
	Behavior Patrol ( "run" )

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		CORE_PAIN			: SHOW_PAIN
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		TURN_TO_PLAYER   	: !PLAYER_RANGE ( $MAX_WAIT_FOR_PLAYER_RANGE$ )
		CORE_MAIN			 : BEHAVIOR_SUCCESS
		CORE_MAIN			 : BEHAVIOR_FAILED
		}
	}
	
//---------------------------------------------------------
state TURN_TO_PLAYER
//---------------------------------------------------------
	{
	entrycommands
		{
		//printmessage "TURN_TO_PLAYER"
		}
		
	Behavior RotateToEntity ( 10.0 , "idle" , "player" )

	states
		{
		WAIT_FOR_PLAYER : BEHAVIOR_SUCCESS
		WANDER_WAIT		: BEHAVIOR_FAILED
		}
	}
	
//---------------------------------------------------------
state WAIT_FOR_PLAYER
//---------------------------------------------------------
	{
	entrycommands
	{
		//printmessage "WAIT_FOR_PLAYER"
	}
	legs
		{
		idle :  default
		}

	states
		{
		CORE_MAIN 		: !PLAYER_RANGE ( $MAX_WAIT_FOR_PLAYER_RANGE$ )
		CORE_MAIN 		: PLAYER_RANGE ( $MIN_WAIT_FOR_PLAYER_RANGE$ )
		WAIT_FOR_PLAYER : ANIM_DONE
		}
	}


//[b60025] chrissstrahl - allow following objects
// SCRIPT USAGE, ai needs to be on:
// $actor.setTendency("follow",0);
// $actor.setTendency("followobject",1);
// $actor.followtarget( $objectToFollow );
//---------------------------------------------------------
state FOLLOW_OBJECT
//---------------------------------------------------------
{
	states
	{
		FOLLOW_OBJECT_300	: SHOULD_DO_ACTION ( "followobjectdist300" )
		FOLLOW_OBJECT_500	: SHOULD_DO_ACTION ( "followobjectdist500" )
		FOLLOW_OBJECT_750	: SHOULD_DO_ACTION ( "followobjectdist750" )
		FOLLOW_OBJECT_1000	: SHOULD_DO_ACTION ( "followobjectdist1000" )
		FOLLOW_OBJECT_DEFAULT : default
	}
}

//75 - 150
//---------------------------------------------------------
state FOLLOW_OBJECT_DEFAULT
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	}
		
	Behavior GroupFollow ( 75 , 150 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "followobject" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}

//150 - 300
// SCRIPT USAGE, additional parameter:
// $actor.setTendency("followobjectdist300",1);
//---------------------------------------------------------
state FOLLOW_OBJECT_300
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	}
		
	Behavior GroupFollow ( 150 , 300 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "followobject" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}

//300 - 500
// SCRIPT USAGE, additional parameter:
// $actor.setTendency("followobjectdist500",1);
//---------------------------------------------------------
state FOLLOW_OBJECT_500
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	}
		
	Behavior GroupFollow ( 300 , 500 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "followobject" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}

//500 - 750
// SCRIPT USAGE, additional parameter:
// $actor.setTendency("followobjectdist750",1);
//---------------------------------------------------------
state FOLLOW_OBJECT_750
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	}
		
	Behavior GroupFollow ( 500 , 750 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "followobject" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}

//750 - 1000
// SCRIPT USAGE, additional parameter:
// $actor.setTendency("followobjectdist1000",1);
//---------------------------------------------------------
state FOLLOW_OBJECT_1000
//---------------------------------------------------------
{
	entrycommands
	{
	endtorsobehavior
	cleartorsoanim
	}
		
	Behavior GroupFollow ( 750 , 1000 ) //fixed in gameplay.gdb batlethhold animations //this messes up the animation when actor holds batleth

	states
		{
		PLAYER_ATTACKED		: ATTACKED_BY_PLAYER ACTORTYPE ( "teammate" )
		HANDLE_CALL_VOLUME	: SHOULD_DO_ACTION ( "handlecallvolume" ) PLAYER_IN_CALL_VOLUME
		CORE_MAIN			: !SHOULD_DO_ACTION ( "followobject" )
		CORE_PAIN			: SHOW_PAIN
		GET_OUT_OF_THE_WAY	: SHOULD_DO_ACTION ( "getoutoftheway" ) IN_THE_WAY
		CORE_MAIN			: BEHAVIOR_SUCCESS
		HOLD				: BEHAVIOR_FAILED
		}
}
