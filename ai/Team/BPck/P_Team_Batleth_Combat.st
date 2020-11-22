//
// Name:     KlingonMercM9/behaviorpackages/batleth-combat.st
// Purpose:  AI for combatative klingon mercs with batleths
//

//
// Defines
//
$define	RANGE_MAX_DISTANCE_TO_COMBAT_NODE	512
$define RANGE_MAX_DISTANCE_TO_COVER_NODE	512
$define RANGE_MIN_DISTANCE_TO_COVER_NODE	128
$define RANGE_MELEE 						128
$define RANGE_ACTIVATION					192
$define CHANCE_PAIN							0.020

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		startactivationtimer
		headwatchtarget "enemy"
		cleartorsoanim
		groupattack
		}

	states
		{
		DELAY		: default
		}
	}

state DELAY
	{
	legs
		{
		idle : default
		}

	states
		{
		COMBAT_MAIN : ATTACKED
		COMBAT_MAIN : RANGE ( $RANGE_ACTIVATION$ )
		COMBAT_MAIN : ACTIVATION_DELAY_DONE
		}

	exitcommands
		{
		incontext "enteredcombat"		
		}

	}

//---------------------------------------------------------
state COMBAT_MAIN
//---------------------------------------------------------
	{
	states
		{
		COMBAT_WITH_MELEE_WEAPON				: default
		}
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON
//---------------------------------------------------------
	{
	entrycommands
		{
		SetActorFlag ( "updatehatebasedonattackers", 1 )		
		}

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_APPROACH_ENEMY	: CURRENT_ENEMY_HAS_NUMATTACKERS_LESS_THAN ( 2 )
		COMBAT_WITH_MELEE_WEAPON_HOLD			: default
		}
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_HOLD
//---------------------------------------------------------
	{
	entrycommands
		{
		evaluateenemies
		setactorflag "attackingenemy" 0		
		}

	legs
		{
		batleth_idle	: default
		}

	time ( .25 )

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_APPROACH_ENEMY	: HAVE_PATH_TO_ENEMY CURRENT_ENEMY_HAS_NUMATTACKERS_LESS_THAN ( 2 )		
		COMBAT_WITH_MELEE_WEAPON_RETRY			: TIME_DONE
		}
	}

state COMBAT_WITH_MELEE_WEAPON_RETRY
{
	states
		{
		COMBAT_WITH_MELEE_WEAPON_HOLD : default
		}
}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_BEGIN
//---------------------------------------------------------
	{
	entrycommands
		{
		setactorflag "attackingenemy" 1
		}

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_MAIN	: default
		}
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_MAIN
//---------------------------------------------------------
	{
	entrycommands
		{
		incontext "incombat"
		}

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN				: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_APPROACH_ENEMY		: default
		}
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_APPROACH_ENEMY
//---------------------------------------------------------
	{
	Behavior CloseInOnEnemy ( "run" , $RANGE_MELEE$ )

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_ATTACK	: RANGE ( $RANGE_MELEE$ )
		COMBAT_WITH_MELEE_WEAPON_ATTACK : BEHAVIOR_SUCCESS
		COMBAT_WITH_MELEE_WEAPON_HOLD	: BEHAVIOR_FAILED
		}	
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_ATTACK
//---------------------------------------------------------
	{
	Behavior DoAttack ( "" , 15 , 1 , "shuffle" )

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_WITH_MELEE_WEAPON_MAIN	: BEHAVIOR_SUCCESS
		COMBAT_WITH_MELEE_WEAPON_END	: BEHAVIOR_FAILED
		}
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_END
//---------------------------------------------------------
	{
	entrycommands
		{
		setactorflag "attackingenemy" 0
		}

	states
		{
		COMBAT_WITH_MELEE_WEAPON_PAIN			: SHOW_PAIN
		COMBAT_MAIN : default
		}
	}

state COMBAT_WITH_MELEE_WEAPON_PAIN
{
	states
		{
		COMBAT_WITH_MELEE_WEAPON_BIG_PAIN	  : MOD ( "explosion" )
		COMBAT_WITH_MELEE_WEAPON_BIG_PAIN	  : MOD ( "imod_primary" )
		COMBAT_WITH_MELEE_WEAPON_BIG_PAIN	  : MOD ( "plasmashotgun" )
		COMBAT_WITH_MELEE_WEAPON_BIG_PAIN	  : MOD ( "small_explosion" )
		COMBAT_WITH_MELEE_WEAPON_SMALL_PAIN : default
		}	
	}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_BIG_PAIN
//---------------------------------------------------------
{
	legs
		{
		pain_knockback : default
		}

	states
		{		
		COMBAT_WITH_MELEE_WEAPON : ANIM_DONE
		}
}

//---------------------------------------------------------
state COMBAT_WITH_MELEE_WEAPON_SMALL_PAIN
//---------------------------------------------------------
{
	entrycommands
		{
		saveofflasthitbone
		}

	legs
		{		
		pain_stomach 	: BONE_DAMAGED ( "Bip01 Pelvis" )
		pain_stomach 	: BONE_DAMAGED ( "Bip01 Spine" )
		pain_chest 		: BONE_DAMAGED ( "Bip01 Spine2" )
		pain_head 		: BONE_DAMAGED ( "Bip01 Head" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Clavicle" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Upperarm" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Forearm" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Hand" )
		pain_shoulder_L : BONE_DAMAGED ( "Bip01 L Finger2" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Clavicle" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Upperarm" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Forearm" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Hand" )
		pain_shoulder_R : BONE_DAMAGED ( "Bip01 R Finger2" )
		pain_leg_L 		: BONE_DAMAGED ( "Bip01 L Thigh" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Calf" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Foot" )
		pain_L_lowerleg : BONE_DAMAGED ( "Bip01 L Toe0" )		
		pain_leg_R 		: BONE_DAMAGED ( "Bip01 R Thigh" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Calf" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Foot" )
		pain_R_lowerleg : BONE_DAMAGED ( "Bip01 R Toe0" )
		pain_chest		: default
		}

	states
		{		
		COMBAT_WITH_MELEE_WEAPON : ANIM_DONE
		}

}
