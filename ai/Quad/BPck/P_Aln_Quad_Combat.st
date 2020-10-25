//
// Name:     Quadraped_PackageCombat
// Purpose:  Combat AI for the Quadraped
//

$define CHANCE_ATTACKPATTERN_1  .20
$define CHANCE_ATTACKPATTERN_2	.60
$define CHANCE_ATTACKPATTERN_3	.45
$define CHANCE_DODGE			.80
$define CHANCE_SIDESTEP			.33
$define CHANCE_CHESTBURST		.45
$define SMALL_PAIN_CHANCE 		.65


$define RANGE_PREFERRED_MAX 640

$include ai/quad/mdul/M_Aln_Quad_Sidestep.ai
$include ai/quad/mdul/M_Aln_Quad_AttackChestBurst.ai
$include ai/quad/mdul/M_Aln_Quad_AttackPattern1.ai
$include ai/quad/mdul/M_Aln_Quad_AttackPattern2.ai
$include ai/quad/mdul/M_Aln_Quad_AttackPattern3.ai

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "start" )
		settendency ( "multiplayer" , 0 )
		multiplayer settendency ( "multiplayer" , 1 )
	}
	//hzm eof
	states
		{
		THINK : default
		}
}

//---------------------------------------------------------
state THINK
//---------------------------------------------------------
{
	//hzm chrissstrahl - make ai select the closest enemy each time
	entrycommands
	{
		ClearCurrentEnemy
		SelectClosestEnemy
		turntowardsenemy
		printmessage ( "think" )
	}
	//hzm eof
	
	states
		{
		SPARRING : HAVE_ENEMY !ENEMY_DEAD !ENEMY_NOCLIP CAN_ATTACK_ENEMY
		HOLD : default
		}	
}

//---------------------------------------------------------
state SPARRING
//---------------------------------------------------------
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "sparring" )
	}
	//hzm eof
	states
		{
		//hzm chrissstrahl test - only approach if player is not in noclip (or spectator or notarget)
		APPROACH  				: !RANGE ( $RANGE_PREFERRED_MAX$ ) !ENEMY_NOCLIP
		DODGE			 		:  INCOMING_PROJECTILE CHANCE ( $CHANCE_DODGE$ )
		SIDESTEP  		 		:  RANGE ( $RANGE_PREFERRED_MAX$ ) CHANCE ( $SIDESTEP_CHANCE$ )		
		SELECT_ATTACK_PATTERN	:	default
		}
}

//---------------------------------------------------------
state APPROACH
//---------------------------------------------------------
{

	entrycommands
	{
		printmessage ( "approach" )//hzm chrissstrahl - print status
		turntowardsenemy
	}
	
	Behavior CloseInOnEnemy ( "run" , $RANGE_PREFERRED_MAX$ )
	//Behavior CloseInOnPlayer ( "run" , $RANGE_PREFERRED_MAX$ ) //hzm gameupdate chrissstrahl, does not work right at all, maybe in 2020 we fix this fuck

	states
		{
		DODGE : INCOMING_PROJECTILE CHANCE ( $CHANCE_DODGE$ )
		//hzm chrissstrahl better without	//NO_PATH_SHOULDERCANNON_START : CAN_ATTACK_ENEMY !HAVE_PATH_TO_ENEMY
		THINK : BEHAVIOR_SUCCESS
		HOLD : BEHAVIOR_FAILED
		}
}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "hold" )
	}
	//hzm eof
	legs
		{
		base : default
		}
	states
		{
		THINK : ANIM_DONE
		}
}

//---------------------------------------------------------
state SELECT_ATTACK_PATTERN
//---------------------------------------------------------
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "SELECT_ATTACK_PATTERN" )
	}
	//hzm eof
	states
		{
		ATTACK_PATTERN1	: CHANCE ( $CHANCE_ATTACKPATTERN_1$ )
		ATTACK_PATTERN3 : CHANCE ( $CHANCE_ATTACKPATTERN_3$ )
		ATTACK_PATTERN2 : default				
		}
}

state DEATH
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "death" )
	}
	//hzm eof		

	legs
	{
		//death_pain : CHECK_VAR ( "special_death" , "true" )
		death : default
	}
}

//---------------------------------------------------------
state PAIN
//---------------------------------------------------------
	{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "pain" )
	}
	//hzm eof
	legs
		{
		pain : default
		}

	states
		{
		THINK   : ANIM_DONE
		}
	}

//---------------------------------------------------------
state NO_PATH_SHOULDERCANNON_START
//---------------------------------------------------------
{	
	behavior WatchEntity  ( 100 , 20 , "base_to_shoulderattack" , 1 , "base_to_shoulderattack" )
	
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "NO_PATH_SHOULDERCANNON_START" )
	}
	//hzm eof
	
	states
		{	
		PAIN  : SHOW_PAIN CHANCE ( $SMALL_PAIN_CHANCE$ )	
		NO_PATH_SHOULDERCANNON_FIRE : BEHAVIOR_DONE
		}
}


//---------------------------------------------------------
state NO_PATH_SHOULDERCANNON_FIRE
//---------------------------------------------------------
	{
	behavior WatchEntity  ( 100 , 20 , "nopathattack_fire" , 1 , "nopathattack_fire" )
	
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "NO_PATH_SHOULDERCANNON_FIRE" )
	}
	//hzm eof
	
	states
		{
		NO_PATH_SHOULDERCANNON_END : BEHAVIOR_DONE
		}
	}


//---------------------------------------------------------
state NO_PATH_SHOULDERCANNON_END
//---------------------------------------------------------
	{
	behavior WatchEntity  ( 100 , 20 , "shoulderattack_to_base" , 1 , "shoulderattack_to_base" )
	
	time ( 0.5 ) 
	
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "NO_PATH_SHOULDERCANNON_END" )
	}
	//hzm eof
	
	states
		{		
		PAIN  : SHOW_PAIN CHANCE ( $SMALL_PAIN_CHANCE$ ) !SHOULD_DO_ACTION ( "multiplayer" )
		THINK : BEHAVIOR_DONE TIME_DONE
		}
	}

state END_ATTACK_PATTERN
{
	//hzm chrissstrahl - print status
	entrycommands
	{
		printmessage ( "END_ATTACK_PATTERN" )
	}
	//hzm eof
	
	states
		{
		ATTACK_CHESTBURST_WARN 		: CHANCE ( $CHANCE_CHESTBURST$ )
		SELECT_ATTACK_PATTERN		: default
		}
}