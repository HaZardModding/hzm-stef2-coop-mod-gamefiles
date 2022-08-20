//
// Name:     BorgDrone_PackageCore
// Purpose:  Handles Core Functionality for the borg ( Patrol , Work, and Hibernate )
//
// Notes:  Need to have nodes near by, or the borg will just stand there in an idle animation
//

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		flags "+notarget"            
		}

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
		CORE : default
		}  	
	}

//---------------------------------------------------------
state CORE
//---------------------------------------------------------
	{
	states
		{
		PATROL			: SHOULD_DO_ACTION ( "patrol" )
		WORK			: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( 128.0 )		
		CORE_FAILED		: default
		}
	}  

//---------------------------------------------------------
state CORE_FAILED
//---------------------------------------------------------
	{
	legs
		{
		sleep : default
		}

	time ( 1.5 )

	states
		{
		CORE : TIME_DONE
		}
	}

//---------------------------------------------------------
state PATROL
//---------------------------------------------------------
	{
	Behavior Patrol ( "walk" )

	states
		{
		WORK 				: SHOULD_DO_ACTION ( "work" ) VALID_WORK_NODE_IN_RANGE ( 128.0 )	
		CORE				: BEHAVIOR_SUCCESS
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
		PATROL : TIME_DONE
		}
	}

//---------------------------------------------------------
state WORK
//---------------------------------------------------------
	{
	Behavior Work ( "walk" )

	states
		{
		CORE		: BEHAVIOR_SUCCESS
		WORK_FAILED : BEHAVIOR_FAILED
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
		WORK : TIME_DONE
		}
	}
