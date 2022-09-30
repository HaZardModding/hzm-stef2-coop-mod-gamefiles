//
// Name:     BorgBoss_Stage3
// Purpose:  Functionality for Stage 3
//
//

//Includes
$include ai/BrgBos/Glob/GP_BrgBos_Global.st

$define MELEE_RANGE 128

//---------------------------------------------------------
state START
//---------------------------------------------------------
   {
	entrycommands
		{
		headwatchtarget "enemy"

 		resistance "phaser" 95
		resistance "vaporize" 90
		resistance "comp_rifle" 95
		resistance "vaporize_comp" 85
		resistance "imod_primary" 75
		resistance "imod_secondary" 85
		
		displayeffect noelectric
		setactorflag "disabled" 0 
		immortal 1
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
      REINFORCMENTS :  !HAS_THING ( 1 )
      TELEPORT_START : default 
      }
   }


//---------------------------------------------------------
state REINFORCMENTS
//---------------------------------------------------------
   {
   entrycommands
      {
      runthread borgspawn
      havething ( 1 , 1 )
      }
      
   states
      {
      THINK : default
      }
   }

//---------------------------------------------------------
state TELEPORT_START
//---------------------------------------------------------
   {
   behavior AnimatedTeleportToPosition ( "teleport" , 4 , "teleport_start" , "teleport_end" )

   states
      {
      TELEPORT_ATTACK : BEHAVIOR_DONE
      }

   }

//---------------------------------------------------------
state TELEPORT_ATTACK
//---------------------------------------------------------
   {
   ignoreglobalstate

    entrycommands
      {
      turntowardsenemy
      }

	behavior DoAttack ( "phaser_burst" , 30 , 1 )
   
   states
      {
      TELEPORT_ATTACK_RESET : BEHAVIOR_SUCCESS CHANCE ( .15 )
      TELEPORT_ATTACK_WAIT : BEHAVIOR_SUCCESS
	  TELEPORT_ATTACK_WAIT : BEHAVIOR_FAILED
      }   
   }

state TELEPORT_ATTACK_WAIT
	{
    behavior RotateToEntity ( 2.5 , "idle" )
    
	states
		{
		THINK : BEHAVIOR_SUCCESS
		TELEPORT_ATTACK_FAILED : BEHAVIOR_FAILED
		}
	}

state TELEPORT_ATTACK_FAILED
	{
		entrycommands
		{
		evaluateenemies
		}

	time ( 0.5 )
    
	states
		{
		TELEPORT_ATTACK_WAIT : TIME_DONE
		}
	}

//---------------------------------------------------------
state TELEPORT_ATTACK_RESET
//---------------------------------------------------------
   {
   states
      {
      TELEPORT_ATTACK : default
      }
   }

//---------------------------------------------------------
state NO_PATH_AVAILABLE
//---------------------------------------------------------
  {
   ignoreglobalstate

    entrycommands
      {
      turntowardsenemy
      }

	behavior DoAttack ( "phaser_burst" , 30 , 1 )
   
   states
      {
      THINK : BEHAVIOR_DONE
      }  
  }