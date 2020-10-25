//
// Name:     BorgDrone_PackageAttack
// Purpose:  Allows the Borg Drone To Attack
//
// Notes:    Borg will not attack unless their "aggresiveness" is set to 1.0
//


//Includes
$include ai/BrgDrn/Glob/GP_BrgDrn.st


$define MELEE_RANGE          112
$define FAST_APPROACH       300
$define MIN_DISRUPTOR_RANGE 128

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

	time ( 0 , .5 )

	states
		{
		THINK : TIME_DONE
		//THINK : default	     
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
		NO_PATH_ATTACK	: NO_PATH
		APPROACH  		: CHANCE ( .65 )
		ATTACK     		: default
		}  	
	}
  
//---------------------------------------------------------
state APPROACH
//---------------------------------------------------------
	{
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
	Behavior CloseInOnEnemy ( "run" , $MELEE_RANGE$ )  	  
 
	time ( .5 )

	states
		{
		NO_PATH_ATTACK	: NO_PATH
		ATTACK_MELEE   : RANGE ( $MELEE_RANGE$ )     
		}
	}

//---------------------------------------------------------  
state APPROACH_SLOW
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )  	  
 
	time ( .5 )

	states
		{
		NO_PATH_ATTACK	: NO_PATH
		ATTACK_MELEE   : RANGE ( $MELEE_RANGE$ )     
		}
	}

//---------------------------------------------------------
state ATTACK
//---------------------------------------------------------
	{
	
	time ( .4 )
	
	states
		{
		ATTACK_PLANT   : CHANCE ( .35 ) RANGE  ( $MELEE_RANGE$ )
		ATTACK_KNEEL   : CHANCE ( .35 ) RANGE  ( $MELEE_RANGE$ )
		ATTACK_MELEE   : RANGE  ( $MELEE_RANGE$ )
		THINK : TIME_DONE
		}	
	}
  
//---------------------------------------------------------
state ATTACK_MELEE
//---------------------------------------------------------
	{
	states
		{
		ATTACK_PLANT   : CHANCE ( .35 ) RANGE ( $MELEE_RANGE$ )
		ATTACK_KNEEL   : CHANCE ( .35 ) RANGE ( $MELEE_RANGE$ )
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

	legs
		{
		plant : default
		}
  
	states
		{
		THINK : ANIM_DONE
		}
	}
	
//---------------------------------------------------------
state NO_PATH_ATTACK
//---------------------------------------------------------
	{
	Behavior DoAttack ( "communicator" )
  
	states
		{
		BLOW_UP 			: BEHAVIOR_DONE	CHANCE ( .35 )
		NO_PATH_ATTACK_PAUSE : BEHAVIOR_DONE	
		}  	
	}
  
//---------------------------------------------------------
state NO_PATH_ATTACK_PAUSE
//---------------------------------------------------------
	{
	legs
		{
		idle : default	
		}	
  
	time ( .5 , 1.5 )
  
	states
		{
		THINK : TIME_DONE	
		}
	}
	
//---------------------------------------------------------	
state BLOW_UP
//---------------------------------------------------------
{
	legs
	{
		explode : default	
	}	
 
	states
	{
		THINK : ANIM_DONE
	}
}
	