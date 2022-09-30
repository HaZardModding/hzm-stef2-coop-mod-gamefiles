//
// Name:     BorgBoss_Stage1
// Purpose:  Functionality for Stage 1
//
//

//Includes
//$include ai/BrgBos/Glob/GP_BrgBos_Global.st

$define STAGE_2_HEALTH 800
$define STAGE_3_HEALTH 400
$define STAGE_4_HEALTH 200
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

		setactorflag "updateactionlevel" 1
		displayeffect noelectric
		setactorflag "disabled" 0 
		}

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )


		THINK : default
		}
	}

//---------------------------------------------------------
state THINK
//---------------------------------------------------------
	{
	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		NO_ENEMY			: !HAVE_ENEMY
		NO_PATH_AVAILABLE	: !HAVE_PATH_TO_ENEMY
		ATTACK_MELEE		: CHANCE ( .25 ) 
		ATTACK_PHASER		: CAN_SHOOT_ENEMY     
		STAGE1_CHASE_PLAYER	: default      
		}
	}


//---------------------------------------------------------
state ATTACK_MELEE
//---------------------------------------------------------
	{
	behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )
	time ( .75 )

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		ATTACK_MELEE_FAST : TIME_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_MELEE_FAST
//---------------------------------------------------------
	{
	behavior CloseInOnEnemy ( "walk_fast" , $MELEE_RANGE$ )
	time ( 3 , 5 )

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		NO_PATH_AVAILABLE	: !HAVE_PATH_TO_ENEMY
		THINK				: TIME_DONE            
		ATTACK_MELEE_PUNCH	: BEHAVIOR_SUCCESS
		}
	}

//---------------------------------------------------------
state ATTACK_MELEE_PUNCH
//---------------------------------------------------------
	{
	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		melee_punch : default
		}

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK	: ANIM_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_PHASER
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		phaser_start : default
		}

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		ATTACK_PHASER_CHARGE : ANIM_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_PHASER_CHARGE
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		phaser_charge : default
		}

	Behavior Watch ( 10 )

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		ATTACK_PHASER_SWEEP	: ANIM_DONE CHANCE ( .35 )
		ATTACK_PHASER_BURST	: ANIM_DONE 
		}
	}

//---------------------------------------------------------
state ATTACK_PHASER_SWEEP
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		turntowardsenemy
		}

	legs
		{
		phaser_sweep : default
		}

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK	: ANIM_DONE
		}
	}

//---------------------------------------------------------
state ATTACK_PHASER_BURST
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
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK	: BEHAVIOR_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_CHASE_PLAYER
//---------------------------------------------------------
	{
	behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )
	time ( .75 )

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		ATTACK_PHASER : CAN_SHOOT_ENEMY
		STAGE1_CHASE_PLAYER_FAST : TIME_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_CHASE_PLAYER_FAST
//---------------------------------------------------------
	{
	behavior CloseInOnEnemy ( "walk_fast" , $MELEE_RANGE$ )
	time ( 2 , 4 )

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		NO_PATH_AVAILABLE	: !HAVE_PATH_TO_ENEMY
		ATTACK_PHASER	: CAN_SHOOT_ENEMY
		THINK			: TIME_DONE
		}
	}

//---------------------------------------------------------
state NO_PATH_AVAILABLE
//---------------------------------------------------------
	{
	entrycommands
		{
		unreservecurrenthelpernode
		}
	
	Behavior GotoHelperNodeNearestEnemy ( "combat" , "walk" , 9090 )
	time ( 1 , 2 )

	states
		{      
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK : HAVE_PATH_TO_ENEMY
		NO_PATH_AVAILABLE_ATTACK : BEHAVIOR_FAILED
		NO_PATH_AVAILABLE_ATTACK : BEHAVIOR_SUCCESS
		}
	}

//---------------------------------------------------------
state NO_PATH_AVAILABLE_ATTACK
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
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK	: BEHAVIOR_DONE
		}
	}

//--------------------------------------------------------
state NO_ENEMY
//--------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		idle : default
		}

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		THINK			: HAVE_ENEMY
		NO_ENEMY_RESET	: ANIM_DONE
		}
	}

//--------------------------------------------------------
state NO_ENEMY_RESET
//--------------------------------------------------------
	{
	ignoreglobalstate

	states
		{
		GOTO_STAGE_2_START	: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		STAGE1_PAIN							: PAIN CHANCE ( .025 )
		STAGE1_PAIN							: SMALL_PAIN CHANCE ( .025 )		

		NO_ENEMY	: default
		}
	}

//---------------------------------------------------------
state GOTO_STAGE_2_START
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		runthread stage_change_cinema_start
		}
	
	states
		{
		WAIT_FOR_STAGE : default
		}
	}

state WAIT_FOR_STAGE
{

}

//---------------------------------------------------------
state STAGE1_PAIN
//---------------------------------------------------------
	{
	ignoreglobalstate

	states
		{
		STAGE1_PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Clavicle" )
		STAGE1_PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Upperarm" )
		STAGE1_PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Forearm" )
		STAGE1_PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Hand" )
		
		STAGE1_PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Clavicle" )
		STAGE1_PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Upperarm" )
		STAGE1_PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Forearm" )
		STAGE1_PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Hand" )
		
		STAGE1_PAIN_HEAD           : BONE_DAMAGED ( "Bip01 Neck" )
		STAGE1_PAIN_HEAD           : BONE_DAMAGED ( "Bip01 Head" )
		
		STAGE1_PAIN_LEFT_LEG       : BONE_DAMAGED ( "Bip01 L Calf" )
		STAGE1_PAIN_LEFT_LEG       : BONE_DAMAGED ( "Bip01 L Thigh" )
		STAGE1_PAIN_LEFT_LEG       : BONE_DAMAGED  ( "Bip01 L Foot" )
		
		STAGE1_PAIN_RIGHT_LEG       : BONE_DAMAGED ( "Bip01 R Calf" )
		STAGE1_PAIN_RIGHT_LEG       : BONE_DAMAGED ( "Bip01 R Thigh" )
		STAGE1_PAIN_RIGHT_LEG       : BONE_DAMAGED  ( "Bip01 R Foot" )
		
		STAGE1_PAIN_GENERAL : default
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_LEFT_SHOULDER 
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		pain_arm_l : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_RIGHT_SHOULDER
//---------------------------------------------------------
	{
	ignoreglobalstate  

	legs
		{
		pain_arm_r : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_HEAD
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		pain_head : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_LEFT_LEG
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		pain_leg_l : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_RIGHT_LEG
//---------------------------------------------------------
	{
	ignoreglobalstate  

	legs
		{
		pain_leg_r : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}

//---------------------------------------------------------
state STAGE1_PAIN_GENERAL
//---------------------------------------------------------
	{
	ignoreglobalstate

	legs
		{
		pain_chest : default
		}

	states
		{
		THINK : ANIM_DONE
		}
	}
