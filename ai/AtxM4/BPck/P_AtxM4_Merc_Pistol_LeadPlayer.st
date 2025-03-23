//
// Name:     Common_PackageLead
// Purpose:  General AI that directs the actor to follow a patrol path and fight any enemies they
//			 encounter. They will stop and face the player if the player gets too far away,
//			 and will attempt to run back to the player if they get even farther away.
//			 After combat is done they will regain the patrol path and continue on.
//

$define MIN_WAIT_FOR_PLAYER_RANGE 256
$define MAX_WAIT_FOR_PLAYER_RANGE 512
$define FOLLOW_PLAYER_RANGE 1024
$define RANGE_FUXXORED 1052

$define CHASE_RANGE 550

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	states
		{
		THINK : default
		}
	}

//---------------------------------------------------------
state THINK
//---------------------------------------------------------
	{
	states
		{
		FOLLOW_THE_LEADER	: SHOULD_DO_ACTION ( "follow" ) FOLLOW_TARGET_OUT_OF_RANGE
		LEAD : SHOULD_DO_ACTION ( "lead" )
		IDLE : default
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
		FOLLOW_FUXXORED		: FOLLOW_TARGET_OUT_OF_RANGE !PLAYER_RANGE ( $RANGE_FUXXORED$ )
		//CORE_PAIN			: SHOW_PAIN
		//CORE_COWER			: OTHER_DIED 
		THINK			: BEHAVIOR_SUCCESS
		IDLE 		: BEHAVIOR_FAILED
		}
}

state FOLLOW_FUXXORED
{
	Behavior CloseInOnPlayer ( "run" , 256 )
	time ( 1.0 )

	states
		{
		FOLLOW_THE_LEADER : TIME_DONE
		THINK		  : BEHAVIOR_SUCCESS
		}

}

//---------------------------------------------------------
state LEAD
//---------------------------------------------------------
	{
	Behavior Patrol ( "run" )

	states
		{
		TURN_TO_PLAYER   : !PLAYER_RANGE ( $MAX_WAIT_FOR_PLAYER_RANGE$ )
		IDLE			 : BEHAVIOR_SUCCESS
		IDLE			 : BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state IDLE
//---------------------------------------------------------
	{
	behavior WatchEntity ( 1 , 10 , "idle" , 1 )

	states
		{
		THINK : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state TURN_TO_PLAYER
//---------------------------------------------------------
	{
	Behavior RotateToEntity ( 10.0 , "walk" , "player" )

	states
		{
		WAIT_FOR_PLAYER : BEHAVIOR_SUCCESS
		THINK			: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state WAIT_FOR_PLAYER
//---------------------------------------------------------
	{
	legs
		{
		idle :  default
		}

	states
		{
		FOLLOW_PLAYER 	: !PLAYER_RANGE ( $FOLLOW_PLAYER_RANGE$ )
		THINK 			: !PLAYER_RANGE ( $MAX_WAIT_FOR_PLAYER_RANGE$ )
		THINK 			: PLAYER_RANGE ( $MIN_WAIT_FOR_PLAYER_RANGE$ )
		WAIT_FOR_PLAYER : ANIM_DONE
		}
	}


//---------------------------------------------------------
state FOLLOW_PLAYER
//---------------------------------------------------------
	{
	Behavior CloseInOnPlayer ( "run" , $MIN_WAIT_FOR_PLAYER_RANGE$ )

	states
		{
		WAIT_FOR_PLAYER : BEHAVIOR_SUCCESS
		WAIT_FOR_PLAYER : BEHAVIOR_FAILED
		THINK 			: HAVE_ENEMY CAN_SEE_ENEMY
		}
	}