//
// Name:     BorgDrone_PackageAttack
// Purpose:  Allows the Borg Drone To Attack
//
// Notes:    Borg will not attack unless their "aggresiveness" is set to 1.0
//


//Includes
$include ai/BrgDrn/Glob/GP_BrgDrn.st


$define MELEE_RANGE          90
$define FAST_APPROACH       300
$define MIN_DISRUPTOR_RANGE 128
$define DEATH_HEALTH 100

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{	
	ignoreglobalstate

	entrycommands
		{      
		incontext "startcombat"
		setactorflag "updateactionlevel" 1
		flags "-notarget"
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
	ignoreglobalstate
	entrycommands
		{
		evaluateenemies
		}

	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		PAIN			: SHOW_PAIN
		NO_PATH_ATTACK	: NO_PATH
		APPROACH  		: CHANCE ( .65 )
		ATTACK     		: default
		}  	
	}
  
//---------------------------------------------------------
state APPROACH
//---------------------------------------------------------
	{
	entrycommands
		{
		headwatchtarget "enemy"
		}
	states
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH_FAST : CHANCE ( .65 )
		APPROACH_SLOW : default	
		}	
	}
	
//---------------------------------------------------------  
state APPROACH_FAST
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "run" , 70 )  	  
	
	time ( 1 )
	
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		NO_PATH_ATTACK	: NO_PATH
		ATTACK   		: RANGE ( $MELEE_RANGE$ )  
		THINK  			: BEHAVIOR_FAILED
		THINK  			: BEHAVIOR_SUCCESS
		THINK  			: TIME_DONE
		}
	}

//---------------------------------------------------------  
state APPROACH_SLOW
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "run" , $MELEE_RANGE$ )

	states
		{
		NO_PATH_ATTACK	: NO_PATH
		ATTACK_MELEE   : RANGE ( $MELEE_RANGE$ )
		NO_PATH_ATTACK  : BEHAVIOR_FAILED	
		THINK  			: BEHAVIOR_SUCCESS	
		}
	}
	
//---------------------------------------------------------  
state APPROACH_SLOW
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "run" , $MELEE_RANGE$ )

	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		NO_PATH_ATTACK	: NO_PATH
		ATTACK_MELEE   : RANGE ( $MELEE_RANGE$ )
		NO_PATH_ATTACK  : BEHAVIOR_FAILED	
		THINK  			: BEHAVIOR_SUCCESS	
		}
	}

//---------------------------------------------------------
state ATTACK
//---------------------------------------------------------
	{
	
	legs
	{
		idle : default	
	}
	
	time ( .4  )
	
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		ATTACK_PLANT   : CHANCE ( .35 ) RANGE  ( 70 )
		ATTACK_KNEEL   : CHANCE ( .35 ) RANGE  ( $MELEE_RANGE$ )
		ATTACK_MELEE   : RANGE  ( 80 )
		NO_PATH_ATTACK : default
		}	
	}
  
//---------------------------------------------------------
state LEAP
//---------------------------------------------------------
	{	
	behavior LeapToEnemy ( 30 )
	
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		ATTACK_PLANT : RANGE ( 70 ) CHANCE ( .35 )
		ATTACK_KNEEL : RANGE ( 80 )
		THINK : BEHAVIOR_SUCCESS
		THINK : BEHAVIOR_FAILED
		}

	entrycommands
		{
		setvelocity 0 0 -300
		}
	}
  
//---------------------------------------------------------
state ATTACK_MELEE
//---------------------------------------------------------
	{
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		ATTACK_PLANT   : CHANCE ( .1 ) RANGE ( 70 )
		ATTACK_KNEEL   : CHANCE ( .1 ) RANGE ( 110 )
		MELEE_ATTACK :  RANGE  ( $MELEE_RANGE$ )
		THINK : default
		}
	}

//---------------------------------------------------------
state MELEE_ATTACK
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		melee : default
		}
  
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		THINK : ANIM_DONE
		}
	} 

//---------------------------------------------------------
state ATTACK_KNEEL
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		stand_to_kneel : default
		}
  
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_PLANT
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}
		
		behavior GotoDeadEnemy ( "run" )

	//legs
		//{
		//plant : default
		//}
  
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		//THINK : ANIM_DONE
		THINK : BEHAVIOR_SUCCESS
		THINK : BEHAVIOR_FAILED
		}
	}
	
//---------------------------------------------------------
state NO_PATH_ATTACK
//---------------------------------------------------------
	{
	
	Behavior MoveRandomDirection ( "walk" , 192 , 64 )
  
	states
		{
		DEAD_YELLOW				: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW				: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE				: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN				: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED				: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		LEAP					: RANGE ( 160 ) CHANCE ( .5 )
		THINK					: BEHAVIOR_SUCCESS
		NO_PATH_ATTACK_PAUSE	: BEHAVIOR_FAILED
		}  	
	}
	
//---------------------------------------------------------
state SLEEP_ATTACK
//---------------------------------------------------------
	{
	legs
		{
		sleep : default
		}
	
	time ( 5 , 10 )
	
	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		ATTACK : TIME_DONE RANGE ( 90 )
		}
	
	}
	
//---------------------------------------------------------
state COMMUNICATOR_BLOW
//---------------------------------------------------------
	{
	Behavior DoAttack ( "communicator" )
	
	states
		{
		BLOW_UP 			: BEHAVIOR_DONE
		}
	}
  
//---------------------------------------------------------
state NO_PATH_ATTACK_PAUSE
//---------------------------------------------------------
	{
	Behavior MoveRandomDirection ( "walk" , 192 , 64 )	

	states
		{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
		THINK : BEHAVIOR_FAILED
		THINK : BEHAVIOR_SUCCESS
		}
	}
	
//---------------------------------------------------------	
state BLOW_UP
//---------------------------------------------------------
{
	entrycommands
	{
	selfdetonate
	displayeffect ( "FadeOut" "Phaser" )
	doradiusdamage ( 100 "vaporize" 500 111 0 )
	}
	
	legs
	{
		idle : default	
	}
	
	time ( 2.5 )
 
	states
	{
		REMOVE : TIME_DONE
	}
	exitcommands
	{
	stopsound 0
	stopsound 1
	stopsound 2
	stopsound 3
	kill
	remove
	}
}


//---------------------------------------------------------	
state PAIN
//---------------------------------------------------------
{
entrycommands
	{
	saveofflasthitbone
	}

legs
	{		
	pain : default
	}

states
	{
		DEAD_YELLOW		: MOD ( "vaporize" )!HEALTH ( DEATH_HEALTH )
		DEAD_YELLOW		: MOD ( "vaporize_comp" )!HEALTH ( DEATH_HEALTH )
		DEAD_BLUE		: MOD ( "vaporize_photon" )!HEALTH ( DEATH_HEALTH )
		DEAD_GREEN		: MOD ( "vaporize_disruptor" )!HEALTH ( DEATH_HEALTH )
		DEAD_RED		: MOD ( "sniper" )!HEALTH ( DEATH_HEALTH )
	//DEAD			: MOD ( "lava" )
	//DEAD			: MOD ( "fire" )
	SLEEP_ATTACK	: CHANCE ( .2 )
	THINK			: ANIM_DONE
	}
}

//---------------------------------------------------------	
state DEAD_YELLOW
//---------------------------------------------------------
{
	entrycommands
		{
		immortal 0
		kill
		displayEffect ( "FadeOut" , "Phaser" )
		}
		
	time ( 3 )
		
	states
		{
		REMOVE : TIME_DONE
		}
}

//---------------------------------------------------------	
state DEAD_BLUE
//---------------------------------------------------------
{
	entrycommands
		{
		immortal 0
		kill
		displayEffect ( "FadeOut" , "Photon" )
		}
		
	time ( 3 )
		
	states
		{
		REMOVE : TIME_DONE
		}
}

//---------------------------------------------------------	
state DEAD_GREEN
//---------------------------------------------------------
{
	entrycommands
		{
		immortal 0
		kill
		displayEffect ( "FadeOut" , "Disruptor" )
		}
		
	time ( 3 )
		
	states
		{
		REMOVE : TIME_DONE
		}
}

//---------------------------------------------------------	
state DEAD_RED
//---------------------------------------------------------
{
	entrycommands
		{
		immortal 0
		kill
		displayEffect ( "FadeOut" , "Sniper" )
		}
		
	time ( 3 )
		
	states
		{
		REMOVE : TIME_DONE
		}
}

//---------------------------------------------------------	
state REMOVE
//---------------------------------------------------------
{
	entrycommands
		{
		remove
		}
		
	states
		{
		}
}
	