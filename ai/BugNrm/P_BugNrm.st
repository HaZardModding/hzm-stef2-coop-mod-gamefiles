//
// SolanSpydantYoung.st -- AI file for the Solan III Spydant creature
//
$define ATTACK_RANGE 128
$define SUICIDE_RANGE 1024


////////////////////////////////////////////////////////////////////////////////////
//
// Idle-Type States
//
///////////////////////////////////////////////////////////////////////////////////
state SCRIPTED
{
}

state AI_OFF
{
	states
	{
		THINK : IN_AI_MODE
	}
}

state IDLE
{
	states
	{
		REAL_IDLE : !HAVE_ENEMY
		THINK : default
	}
}

state REAL_IDLE
{
	legs
	{
		idle : default
	}

	states
	{
		THINK : HAVE_ENEMY
		IDLE_RESET : ANIM_DONE
	}

}

state IDLE_RESET
{
	states
	{
		REAL_IDLE : default
	}
}

state ATTACK
{
	//behavior GetCloseToPlayer ( "walk" , 1 , 20 )
	behavior CloseInOnPlayer ( "walk" , 90 )
	time ( 1.0 )

	states
	{
		AI_OFF : !IN_AI_MODE
		DIGHIDE : !HAVE_ENEMY !RANGE ( $ATTACK_RANGE$ )
		DIGHIDE : !HAVE_PATH_TO_ENEMY !RANGE ( $ATTACK_RANGE$ )
		MELEE_JUMP : RANGE ( $ATTACK_RANGE$ ) CHANCE ( .85 )
		MELEE : RANGE ( $ATTACK_RANGE$ )
		ATTACK_RETRY : BEHAVIOR_FAILED
		ATTACK_RESET : TIME_DONE
	}
}

state ATTACK_RETRY
{
	legs
	{
		idle : default
	}

	time ( .5 )

	states
	{
		ATTACK : TIME_DONE
	}
}

state ATTACK_RESET
{
	states
	{
		ATTACK : default
	}
}

state MELEE
{
	entrycommands
	{
		turntowardsenemy
	}

	legs
	{
		attack1 : default
	}

	states
	{
		THINK : ANIM_DONE
	}
}

state MELEE_JUMP
{
	entrycommands
	{
		turntowardsenemy
	}

	behavior LeapToEnemy ( 65 );

	legs
	{
		attack1 : default
	}

	states
	{
		BACKPEDAL : BEHAVIOR_DONE
	}
}

state BACKPEDAL
{

	behavior BackAwayFromEnemy ( "backpedal" , 50 ,100 )
	time ( 1.0 )

	states
	{
		THINK : BEHAVIOR_DONE
		THINK : TIME_DONE
	}
}

state THINK
{
	states
	{
		AI_OFF : !IN_AI_MODE
		ATTACK : default
	}
}


state DIGHIDE
{
	Behavior MoveRandomDirection ( "walk" , 128 , 96 )

	Time ( 0.1 , 1 )

	states
	{
		ATTACK : HAVE_ENEMY HAVE_PATH_TO_ENEMY
		DIGHIDE_DIGIN : TIME_DONE
	}
}

state DIGHIDE_DIGIN
{
	entrycommands
	{
		spawneffect fx/fx-explosion-debris-idryllruins-dustpuff.tik origin
		playSound "sound/environment/rock/rock_divein.wav" 3 0.7 512
		animateonce attack
	}
	Time ( 0.05 )
	states
	{
		DIGHIDE_HIDE : TIME_DONE
	}
}

state DIGHIDE_HIDE
{
	entrycommands
	{
		hide
		notsolid
		flags "+notarget"
	}

	// after 60 seconds of hiding with no way to attack, just die because the player has probably moved on

	Time ( 60 )
	Behavior HoldPosition

	states
	{
		DIGHIDE_DIGOUT : HAVE_ENEMY HAVE_PATH_TO_ENEMY
		//SUICIDE : TIME_DONE RANGE ( $SUICIDE_RANGE$ )
	}
}

state DIGHIDE_DIGOUT
{
	exitcommands
	{
		spawneffect fx/fx-explosion-debris-idryllruins-dustpuff.tik origin
		playSound "sound/environment/rock/rock_divein.wav" 3 0.7 512
		flags "-notarget"
	}

	Behavior HoldPosition
	Time ( 0.1 , 1 )
	states
	{
		DIGHIDE_SHOW : TIME_DONE
	}
}

state DIGHIDE_SHOW
{
	entrycommands
	{
		show
		solid
	}

	Time ( 0.3 )

	states
	{
		ATTACK : TIME_DONE
	}
}

state SUICIDE
{
	entrycommands
	{
		suicide
	}
}