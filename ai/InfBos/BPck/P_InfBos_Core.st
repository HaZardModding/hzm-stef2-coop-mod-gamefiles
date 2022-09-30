//
// Name:     InformantBoss_PackageCore
// Purpose:  AI for Non Combat State InformantBoss
//

//
// Includes
//

//
// Defines
//
$define INFORMANT_RANGE_WORK 256
$define INFORMANT_RANGE_PATROL 256

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
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
		PATROL				: SHOULD_DO_ACTION ( "patrol" ) VALID_PATROL_NODE_IN_RANGE ( $INFORMANT_RANGE_PATROL$ )
		WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( $INFORMANT_RANGE_WORK$ )
		WANDER				: SHOULD_DO_ACTION ( "wander" )
		HOLD				: default
		}
}

//---------------------------------------------------------
state PATROL
//---------------------------------------------------------
	{
	Behavior Patrol ( "walk" )

	states
		{
		WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( $INFORMANT_RANGE_WORK$ )	
		CORE_MAIN			: BEHAVIOR_SUCCESS
		PATROL_FAILED		: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state PATROL_FAILED
//---------------------------------------------------------
	{
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		PATROL	: TIME_DONE
		}
	}


//---------------------------------------------------------
state WORK
//---------------------------------------------------------
{
	Behavior Work ( "walk" )

	states
		{
		CORE_MAIN	: BEHAVIOR_SUCCESS
		WORK_FAILED	: BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state WORK_FAILED
//---------------------------------------------------------
{
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		WORK	: TIME_DONE
		}
}

//---------------------------------------------------------
state WANDER
//---------------------------------------------------------
	{
	Behavior MoveRandomDirection ( "walk" , 500 , 96 )

	states
		{
		WANDER_WAIT			: BEHAVIOR_SUCCESS
		WANDER_FAILED		: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state WANDER_WAIT
//---------------------------------------------------------
{
	legs
		{
		idle : default
		}

	time ( 1.25 , 1.75 )

	states
		{
		CORE_MAIN			: TIME_DONE
		}
}

//---------------------------------------------------------
state WANDER_FAILED
//---------------------------------------------------------
	{
	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		WANDER	: TIME_DONE
		}
	}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
	{
	entrycommands
		{
		printmessage "CORE: STATE HOLD"
		}

	legs
		{
		idle : default
		}

	time ( 1.0 )

	states
		{
		CORE_MAIN			: TIME_DONE
		}
	}

