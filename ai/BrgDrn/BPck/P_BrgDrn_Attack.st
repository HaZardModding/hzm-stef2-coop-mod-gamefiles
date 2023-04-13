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
		EXIT_ALCOVE		: ACTOR_FLAG ( "inalcove" )
	    NO_PATH_ATTACK   : ACTOR_FLAG ( "turretmode" )
		NO_PATH_ATTACK	: NO_PATH
		APPROACH  		: CHANCE ( .65 )
		ATTACK     		: default
		}  	
	}

//---------------------------------------------------------
state EXIT_ALCOVE
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		resetmovedir
		}

	legs
		{
		alcove_activate : default	
		}		
  
	states
		{
		THINK : ANIM_DONE	
		}	
	}
  
//---------------------------------------------------------
state APPROACH
//---------------------------------------------------------
	{
	states
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH_SLOW : default	
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
		APPROACH_FAST_ARMDOWN  : TIME_DONE CHANCE ( .5 )
		APPROACH_FAST_ARMUP  : TIME_DONE 
		ATTACK_MELEE   : RANGE ( $MELEE_RANGE$ )     
		}
	}

//---------------------------------------------------------  
state APPROACH_FAST_ARMDOWN
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "walk_fast_armdown" , $MELEE_RANGE$ )  	  
 
	time ( 1.0 )
	states
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH     : BEHAVIOR_DONE
		ATTACK_MELEE : RANGE ( $MELEE_RANGE$ )     
		APPROACH_FAST_ARMDOWN_REEVALUATE : TIME_DONE
		}
	}

//---------------------------------------------------------  
state APPROACH_FAST_ARMDOWN_REEVALUATE
//---------------------------------------------------------  
{
	entrycommands
		{
		evaluateenemies
		}

	states	
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH_FAST_ARMDOWN : default
		}
}

//---------------------------------------------------------  
state APPROACH_FAST_ARMUP
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "walk_fast_armup" , $MELEE_RANGE$ )  	  
 
	time ( 1.0 )
	states
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH     : BEHAVIOR_DONE
		ATTACK_MELEE : RANGE ( $MELEE_RANGE$ )  
   		APPROACH_FAST_ARMUP_REEVALUATE : TIME_DONE
		}
	}

//---------------------------------------------------------   
state APPROACH_FAST_ARMUP_REEVALUATE
//---------------------------------------------------------  
{
	entrycommands
		{
		evaluateenemies
		}

	states	
		{
		NO_PATH_ATTACK	: NO_PATH
		APPROACH_FAST_ARMUP : default
		}
}
 
//---------------------------------------------------------
state ATTACK
//---------------------------------------------------------
	{
	states
		{ 
		ASSIMILATE         : RANGE  ( $MELEE_RANGE$ )	     
		ATTACK_PHOTONBLAST : CHANCE ( .25 )     
		//ATTACK_DISRUPTOR   : !RANGE ( $MIN_DISRUPTOR_RANGE$ )
		ATTACK_PHOTONBLAST : RANGE ( $MIN_DISRUPTOR_RANGE$ )     
		}	
	}
  
//---------------------------------------------------------
state ATTACK_MELEE
//---------------------------------------------------------
	{
	states
		{
		ASSIMILATE   : CHANCE ( .35 )
		MELEE_ATTACK : default
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
		attack_melee : default
		}
  
	states
		{
		THINK : ANIM_DONE
		}
	}  

//---------------------------------------------------------
state ATTACK_DISRUPTOR
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}  

	Behavior DoBeamAttack ( "tag_L_arm" , "borgbeam" , "fx/fx-borgdrone-beamimpact.tik" , "fx/fx-borgdrone-plasmarelease.tik", "attack_disruptor" , 1 , .5 , 30 , 0 )   
  
	states
		{     
		THINK              : BEHAVIOR_SUCCESS
		THINK              : BEHAVIOR_FAILED
		}	
	}
  
//-------------------------------------------------[b60013]
//Chrissstrahl - adds option to disable ranged attack
state ATTACK_PHOTONBLAST
//---------------------------------------------------------
	{  
	time ( .25 , .5 )
  
	states
		{
		ATTACK_PHOTONBLAST_ATTACK	: !SHOULD_DO_ACTION ( "norangedattack" )
		ASSIMILATE					: RANGE  ( $MELEE_RANGE$ )	
		THINK						: TIME_DONE	
		}  	
	}
	
//---------------------------------------------------------
state ATTACK_PHOTONBLAST_ATTACK
//---------------------------------------------------------
	{  
	Behavior DoAttack ( "attack_photonblast" )
  
	states
		{
		ASSIMILATE         : RANGE  ( $MELEE_RANGE$ )	     
		THINK              : BEHAVIOR_DONE	
		}  	
	}
  
//---------------------------------------------------------
state ASSIMILATE
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		assimilate_start : default
		}
  
	states
		{
		ASSIMILATE_HOLD : ANIM_DONE
		}
	}

//---------------------------------------------------------
state ASSIMILATE_HOLD
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	Behavior Watch 

	legs
		{
		assimilate_hold : default
		}
  
	states
		{
		ASSIMILATE_END : !RANGE  ( $MELEE_RANGE$ )	
		}
	}

//---------------------------------------------------------
state ASSIMILATE_END
//---------------------------------------------------------
	{
	legs
		{
		assimilate_end : default
		}
  
	states
		{
		THINK : ANIM_DONE
		}
	}

//-------------------------------------------------[b60013]
//Chrissstrahl - adds option to disable ranged attack
state NO_PATH_ATTACK
//---------------------------------------------------------
	{ 
	
	states
		{
		NO_PATH_ATTACK_RANGED : !SHOULD_DO_ACTION ( "norangedattack" )
		NO_PATH_ATTACK_PAUSE : default	
		}  	
	}
	
//---------------------------------------------------------
state NO_PATH_ATTACK_RANGED
//---------------------------------------------------------
{
Behavior DoAttack ( "attack_photonblast" )

states
	{
	NO_PATH_ATTACK_PAUSE : BEHAVIOR_DONE	
	}  	
}
  
//---------------------------------------------------------
state NO_PATH_ATTACK_PAUSE
//---------------------------------------------------------
	{
	legs
		{
		idle_armup : default	
		}	
  
	time ( .5 , 1.5 )
  
	states
		{
		THINK : TIME_DONE	
		}
	}