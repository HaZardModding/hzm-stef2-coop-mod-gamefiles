$include ai/aliens/quadraped/modules/Quadraped_ModuleDefine.ai

//---------------------------------------------------------
globalstate GLOBAL_MAIN
//---------------------------------------------------------
	{
	states
		{
		PAIN  : SHOW_PAIN CHANCE ( $SMALL_PAIN_CHANCE$ )
		MELEE : RANGE ( $MELEE_RANGE_MAX$ ) CHANCE ( .80 )
		MELEE_BACK_PEDAL : RANGE ( $MELEE_RANGE_MAX$ ) REAR_CLEAR ( 64.0 )
		MELEE : RANGE ( $MELEE_RANGE_MAX$ )
		}
	}

//---------------------------------------------------------
state PAIN
//---------------------------------------------------------
	{
	ignoreglobalstate

	//entrycommands
	//	{
	//	nodamage
	//	}

	legs
		{
		pain : default
		}

	states
		{
		POST_PAIN   : ANIM_DONE
		}

	//exitcommands
	//	{
	//	takedamage
	//	}

	}

//---------------------------------------------------------
state POST_PAIN
//---------------------------------------------------------
	{
	ignoreglobalstate

	states
		{
		THINK : default
		}
	}

//---------------------------------------------------------
state MELEE
//---------------------------------------------------------
	{
	ignoreglobalstate

	states
		{
		BEGIN_MELEE_STOMP : CHANCE ( $MELEE_STOMP_CHANCE$ )
		BEGIN_MELEE_HORN  : CHANCE ( $MELEE_HORN_CHANCE$ )
		BEGIN_MELEE_SWIPE : default
		}
	}

//---------------------------------------------------------
state BEGIN_MELEE_STOMP
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "base_to_stomp" , 1 , "base_to_stomp" )

	states
		{
		MELEE_STOMP : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state MELEE_STOMP
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "stomp" , 1 , "stomp" )

	states
		{
		END_MELEE_STOMP : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state END_MELEE_STOMP
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "stomp_to_base" , 1 , "stomp_to_base" )

	states
		{
		MELEE_BACK_PEDAL : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state BEGIN_MELEE_SWIPE
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "base_to_swipe" , 1 , "base_to_swipe" )
	states
		{
		MELEE_SWIPE : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state MELEE_SWIPE
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "swipe" , 1 , "swipe" )

	states
		{
		END_MELEE_SWIPE : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state END_MELEE_SWIPE
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "swipe_to_base" , 1 , "swipe_to_base" )

	states
		{
		MELEE_BACK_PEDAL : BEHAVIOR_DONE
		}
	}



//---------------------------------------------------------
state BEGIN_MELEE_HORN
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "base_to_horn" , 1 , "base_to_horn" )

	states
		{
		MELEE_HORN : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state MELEE_HORN
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "horn" , 1 , "horn" )

	states
		{
		END_MELEE_HORN : BEHAVIOR_DONE 
		}
	}

//---------------------------------------------------------
state END_MELEE_HORN
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior WatchEntity  ( 100 , 20 , "horn_to_base" , 1 , "horn_to_base" )

	states
		{
		MELEE_BACK_PEDAL : BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state MELEE_BACK_PEDAL
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		turntowardsenemy
		}

	Behavior BackAwayFromEnemy ( "backpedal" , 100 , 64 )

	states
		{
		THINK : BEHAVIOR_SUCCESS
		THINK : BEHAVIOR_FAILED
		}
	}