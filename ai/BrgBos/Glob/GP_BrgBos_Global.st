//
// Name:     BorgBoss_Global
// Purpose:  Global State File for Borg Boss
//
// Notes:    None

$define STAGE_2_HEALTH 800
$define STAGE_3_HEALTH 500
$define STAGE_4_HEALTH 300
$define CHASE_RANGE 600
$define TELEPORT_RANGE 1000
$define TELEPORT_RANGE_MAX_HEIGHT 500
$define TELEPORT_RANGE_MIN_HEIGHT -500
$define MELEE_RANGE 128

//---------------------------------------------------------
globalstate GLOBAL_MAIN
//---------------------------------------------------------
	{
	states
		{
		PAIN							: PAIN CHANCE ( .025 )
		PAIN							: SMALL_PAIN CHANCE ( .025 )
		//GLOBAL_NO_PATH_AVAILABLE		: !HAVE_PATH_TO_ENEMY      
		//GLOBAL_TELEPORT_TO_PLAYER_START	: !NO_PATH !RANGE ( $TELEPORT_RANGE$ , $TELEPORT_RANGE_MAX_HEIGHT$ , $TELEPORT_RANGE_MIN_HEIGHT$ )
		//CHASE_PLAYER					: HAVE_PATH_TO_ENEMY !RANGE ( $CHASE_RANGE$ )
		GOTO_STAGE_4_START				: !STAGE ( 4 ) HEALTH ( $STAGE_4_HEALTH$ )
		GOTO_STAGE_3_START				: !STAGE ( 3 ) HEALTH ( $STAGE_3_HEALTH$ ) !HEALTH ( $STAGE_4_HEALTH$ )      
		//GOTO_STAGE_2_START				: !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
		}
	}

//---------------------------------------------------------
state CHASE_PLAYER
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )
	time ( .75 )

	states
		{
		CHASE_PLAYER_FAST				: TIME_DONE
		THINK							: RANGE ( $CHASE_RANGE$ )
		GLOBAL_NO_PATH_AVAILABLE		: !HAVE_PATH_TO_ENEMY      
		GLOBAL_TELEPORT_TO_PLAYER_START	: !NO_PATH !RANGE ( $TELEPORT_RANGE$ , $TELEPORT_RANGE_MAX_HEIGHT$ , $TELEPORT_RANGE_MIN_HEIGHT$ )
		}
	}

//---------------------------------------------------------
state CHASE_PLAYER_FAST
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )

	states
		{
		THINK								: RANGE ( $CHASE_RANGE$ )
		GLOBAL_NO_PATH_AVAILABLE			: NO_PATH      
		GLOBAL_TELEPORT_TO_PLAYER_START		: !NO_PATH !RANGE ( $TELEPORT_RANGE$ , $TELEPORT_RANGE_MAX_HEIGHT$ , $TELEPORT_RANGE_MIN_HEIGHT$ )
		}
	}

//---------------------------------------------------------
state CHASE_PLAYER_FAST_NO_TELEPORT
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior CloseInOnEnemy ( "walk" , $MELEE_RANGE$ )

	states
		{
		THINK								: RANGE ( $CHASE_RANGE$ )
		GLOBAL_NO_PATH_AVAILABLE			: NO_PATH      		
		}
	}

//---------------------------------------------------------
state GOTO_STAGE_4_START
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior AnimatedTeleportToPlayer ( "teleport_start" , "teleport_end" )
	time ( .5 )

	states
		{
		GOTO_STAGE_4_BEGIN : BEHAVIOR_SUCCESS TIME_DONE
		GOTO_STAGE4_RETRY : BEHAVIOR_DONE TIME_DONE
		}
	}

state GOTO_STAGE4_RETRY
	{
	states
		{
		GOTO_STAGE_4_START : default
		}
	}

//---------------------------------------------------------
state GOTO_STAGE_4_BEGIN
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		runthread stage_change_cinema_start
		}

//	legs
//		{
//		deactivated : default
//		}

//	time ( 3 )

//	states
//		{
//		GOTO_STAGE_4 : TIME_DONE
//		}
	}

//---------------------------------------------------------
state GOTO_STAGE_4
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		//No Draw Head
		surface material5 +nodraw            
		surface material11 +nodraw

		//No Draw Phaser
		surface material13 +nodraw
		surface material14 +nodraw
		surface material16 +nodraw
		}

	legs
		{
		change_stage_3	: default
		}

	states
		{
		GOTO_STAGE_FINISH : ANIM_DONE
		}

	exitcommands
		{
		displayeffect noelectric
		gotostage 4
		}
	}

//---------------------------------------------------------
state GOTO_STAGE_3_START
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		runthread stage_change_cinema_start
		}

//	legs
//		{
//		deactivated : default
//		}

//	time ( 3 )

//	states
//		{
//		GOTO_STAGE_3 : TIME_DONE
//		}
	}

//---------------------------------------------------------
state GOTO_STAGE_3
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		//No Draw Chest
		surface material6  +nodraw   

		//No Draw L Shoulder
		surface material10 +nodraw

		//No Draw R Arm
		surface material9  +nodraw
		}

	legs
		{
		change_stage_2 : default
		}

	states
		{
		GOTO_STAGE_FINISH : ANIM_DONE
		}

	exitcommands
		{
		displayeffect noelectric
		gotostage 3
		}
	}



//---------------------------------------------------------
state GOTO_STAGE_FINISH
//---------------------------------------------------------
	{
	ignoreglobalstate

	entrycommands
		{
		displayeffect noelectric      
		runthread stage_change_cinema_end
		}

	states
		{
		THINK : default
		}
	}

//---------------------------------------------------------
state GLOBAL_TELEPORT_TO_PLAYER_START
//---------------------------------------------------------
	{
	ignoreglobalstate

	behavior AnimatedTeleportToPlayer ( "teleport_start" , "teleport_end" )

	states
		{
		THINK : BEHAVIOR_SUCCESS
		CHASE_PLAYER_FAST_NO_TELEPORT : BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state GLOBAL_NO_PATH_AVAILABLE
//---------------------------------------------------------
	{
	ignoreglobalstate

	Behavior GotoHelperNodeNearestEnemy ( "combat" , "walk" , 9090 )
	time ( 1 , 2 )

	states
		{      
		THINK : HAVE_PATH_TO_ENEMY
		GLOBAL_WANDER : BEHAVIOR_FAILED
		THINK : BEHAVIOR_SUCCESS
		}
	}


state GLOBAL_WANDER
	{
	ignoreglobalstate

	Behavior Wander ( "walk" )
	time ( 1 , 2 )

	states
		{
		THINK : TIME_DONE
		}
	}

//---------------------------------------------------------
state PAIN
//---------------------------------------------------------
	{
	ignoreglobalstate

	states
		{
		PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Clavicle" )
		PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Upperarm" )
		PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Forearm" )
		PAIN_LEFT_SHOULDER : BONE_DAMAGED ( "Bip01 L Hand" )
		
		PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Clavicle" )
		PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Upperarm" )
		PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Forearm" )
		PAIN_RIGHT_SHOULDER : BONE_DAMAGED ( "Bip01 R Hand" )
		
		PAIN_HEAD           : BONE_DAMAGED ( "Bip01 Neck" )
		PAIN_HEAD           : BONE_DAMAGED ( "Bip01 Head" )
		
		PAIN_LEFT_LEG       : BONE_DAMAGED ( "Bip01 L Calf" )
		PAIN_LEFT_LEG       : BONE_DAMAGED ( "Bip01 L Thigh" )
		PAIN_LEFT_LEG       : BONE_DAMAGED  ( "Bip01 L Foot" )
		
		PAIN_RIGHT_LEG       : BONE_DAMAGED ( "Bip01 R Calf" )
		PAIN_RIGHT_LEG       : BONE_DAMAGED ( "Bip01 R Thigh" )
		PAIN_RIGHT_LEG       : BONE_DAMAGED  ( "Bip01 R Foot" )
		
		PAIN_GENERAL : default
		}
	}

//---------------------------------------------------------
state PAIN_LEFT_SHOULDER 
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
state PAIN_RIGHT_SHOULDER
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
state PAIN_HEAD
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
state PAIN_LEFT_LEG
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
state PAIN_RIGHT_LEG
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
state PAIN_GENERAL
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