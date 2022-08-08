//---------------------------------------------------------
$define RANGE_MAX_DISTANCE_TO_COMBAT_NODE 512
$define TIME_WAIT_AT_NODE .5
$define RANGE_MELEE 96
$define TIME_CHASE 1.5
$define CHANCE_TAUNT .25
//---------------------------------------------------------

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		GOTO_CURRENT_NODE	: VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_NODE_AVAILABLE	: default
		}
}

//---------------------------------------------------------
state NO_NODE_AVAILABLE
//---------------------------------------------------------
{
	entrycommands
		{
		printmessage "WARNING: Female Bug has no COMBAT NODE available"
		}

	behavior CloseInOnEnemy ( "run" , 100.0 )
	time ( $TIME_CHASE$ )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		BEGIN_GOOP_LAUNCH	: TIME_DONE
		BEGIN_GOOP_LAUNCH	: BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state GOTO_CURRENT_NODE
//---------------------------------------------------------
{
	behavior GotoCurrentHelperNode ( "run" , 1 )
	
	states
		{
		PAIN				: SHOW_PAIN
		WAIT_AT_NODE		: BEHAVIOR_SUCCESS
		NO_NODE_AVAILABLE	: BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state GOTO_NEXT_NODE
//---------------------------------------------------------
{
	behavior GotoCurrentHelperNode ( "run" , 1 )
	
	states
		{
		PAIN				: SHOW_PAIN
		ATTACK_FROM_NODE	: BEHAVIOR_SUCCESS
		NO_NODE_AVAILABLE	: BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state WAIT_AT_NODE
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "idle" , 1 )
	time ( $TIME_WAIT_AT_NODE$ )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		GOTO_NEXT_NODE		: TIME_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_NODE_AVAILABLE	: TIME_DONE
		}
}

//---------------------------------------------------------
state ATTACK_FROM_NODE
//---------------------------------------------------------
{
	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )

		TAUNT				: CHANCE ( $CHANCE_TAUNT$ )
		BEGIN_GOOP_LAUNCH	: default
		}
}

state TAUNT
{
	behavior WatchEntity ( 100 , 20 , "taunt" , 1 , "taunt" )

	states
		{
		GOTO_CURRENT_NODE	: BEHAVIOR_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_NODE_AVAILABLE	: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state BEGIN_GOOP_LAUNCH
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "from_walk" , 1 , "from_walk" )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		GOOP_LAUNCH_BEGIN	: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state GOOP_LAUNCH_BEGIN
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "to_attack3" , 1 , "to_attack3" )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		GOOP_LAUNCH_ROTATE	: BEHAVIOR_DONE
		}
}


//---------------------------------------------------------
state GOOP_LAUNCH_ROTATE
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "attack_3" , 1 , "attack_3" )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		END_GOOP_LAUNCH		: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state END_GOOP_LAUNCH
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "from_attack3" , 1 , "from_attack3" )

	states
		{
		PAIN				: SHOW_PAIN
		START_MELEE_ATTACKS	: RANGE ( $RANGE_MELEE$ )
		GOTO_CURRENT_NODE	: BEHAVIOR_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ )
		NO_NODE_AVAILABLE	: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state START_MELEE_ATTACKS
//---------------------------------------------------------
{
	states
		{
		MELEE_STING_ATTACK	: CHANCE ( .5 )
		MELEE_SNAP_ATTACK	: default
		}
}

//---------------------------------------------------------
state MELEE_STING_ATTACK
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "attack_2" , 1 , "attack_2" )

	states
		{
		GOTO_CURRENT_NODE	: BEHAVIOR_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ ) !RANGE ( $RANGE_MELEE$ )
		MELEE_RESET			: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state MELEE_SNAP_ATTACK
//---------------------------------------------------------
{
	behavior WatchEntity ( 100 , 20 , "attack_1" , 1 , "attack_1" )

	states
		{
		GOTO_CURRENT_NODE	: BEHAVIOR_DONE VALID_COMBAT_NODE_IN_RANGE ( $RANGE_MAX_DISTANCE_TO_COMBAT_NODE$ ) !RANGE ( $RANGE_MELEE$ )
		MELEE_RESET			: BEHAVIOR_DONE
		}
}

//---------------------------------------------------------
state MELEE_RESET
//---------------------------------------------------------
{
	states
		{
		NO_NODE_AVAILABLE	: !RANGE ( $RANGE_MELEE$ )
		START_MELEE_ATTACKS	: default
		}
}

//[b611] chrissstrahl - gamefix - bug_female-nosack.tik not playing death animation when killed, added ti tiki: setTendency "hasNoSack" 1.0
//---------------------------------------------------------
state DEATH
//---------------------------------------------------------
{
	states
	{
		DEATH_NOSACK	: SHOULD_DO_ACTION ( "hasNoSack" )
		DEATH_SACK		: default
	}
}
//bug_female-nosack.tik
//---------------------------------------------------------
state DEATH_NOSACK
//---------------------------------------------------------
{
	legs
		{
			death : default
		}
}

//bug_female.tik
//---------------------------------------------------------
state DEATH_SACK
//---------------------------------------------------------
{
	legs
		{
			death_spawn : default
		}
}
//end gamefix

//---------------------------------------------------------
state PAIN
//---------------------------------------------------------
{
	states
		{
		PAIN_GENERAL : default
		}
}

//---------------------------------------------------------
state PAIN_GENERAL
//---------------------------------------------------------
{
	legs
		{
		pain : default
		}

	states
		{
		GOTO_CURRENT_NODE : ANIM_DONE  		
		}
}


