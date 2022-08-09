$define RANGE_ENEMY_SEARCH 512
$define RANGE_ATTACK 100

//---------------------------------------------------------
state IDLE
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon IDLE"
	settendency "isopen" 0.0
	fov 360
	}
	
legs
	{
	close-idle : default
	}
	
	time ( 10 )
	
states
	{
	AUTO : default
	}
}

//---------------------------------------------------------
state AUTO
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon AUTO"
	}
	
states
	{
	AI_OFF : !IN_AI_MODE
	COMBAT : HAVE_ENEMY
	CORE : default
	}
}

//---------------------------------------------------------
state AI_OFF
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon AI_OFF"
	}
	
legs
{
	idle : default
}
	
states
	{
	AUTO : IN_AI_MODE
	}
}

//---------------------------------------------------------
state OPEN
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon OPEN"
	settendency "isopen" 1.0
	}
	
legs
	{
	open : default
	}

states
	{
	OPENED : ANIM_DONE
	}
}
//---------------------------------------------------------
state OPENED
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon OPENED"
	}
	
legs
	{
	idle : default
	}

states
	{
	CORE : ANIM_DONE
	}
}
//---------------------------------------------------------
state CLOSING
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon CLOSING"
	settendency "isopen" 0.0
	}
	
legs
	{
	closing : default
	}

states
	{
	CLOSED : ANIM_DONE
	}
}
//---------------------------------------------------------
state CLOSED
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon CLOSED"
	}
	
legs
	{
	close-idle : default
	}

states
	{
	CORE : ANIM_DONE
	}
}


//---------------------------------------------------------
state DEATH
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon DEATH"
	notsolid
	displayeffect electric
	//selfdetonate
	}

states
	{
		CLOSING : SHOULD_DO_ACTION ( "isopen" ) 
	}
}

//---------------------------------------------------------
state CORE
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon CORE"
	evaluateenemies
	}

states
	{
	AI_OFF : !IN_AI_MODE
	//COMBAT : HAVE_ENEMY CAN_ATTACK_ENEMY
	OPEN :		!SHOULD_DO_ACTION ( "isopen" ) HAVE_ENEMY //CAN_SHOOT_ENEMY
	CORE_LINGER :	SHOULD_DO_ACTION ( "isopen" ) !HAVE_ENEMY //CAN_SHOOT_ENEMY
	COMBAT :	HAVE_ENEMY //CAN_SHOOT_ENEMY
	}
}

//---------------------------------------------------------
state CORE_LINGER
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon CORE_LINGER"
	evaluateenemies
	}
	
legs
	{
	idle : default
	}
	
	time ( 7 , 15 )

states
	{
	AI_OFF : !IN_AI_MODE
	CORE : HAVE_ENEMY
	CLOSING :	SHOULD_DO_ACTION ( "isopen" ) TIME_DONE
	}
}

//---------------------------------------------------------
state COMBAT
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon COMBAT"
	evaluateenemies
	turntowardsenemy
	}
	
legs
	{
	idle : default
	}
	
	time ( 0.5 )

states
	{
	AI_OFF :		!IN_AI_MODE
	CORE :			!HAVE_ENEMY
	COMBAT_DECIDE :	TIME_DONE
	}
}

//---------------------------------------------------------
state COMBAT_DECIDE
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon COMBAT_DECIDE"
	evaluateenemies
	turntowardsenemy
	}
	
	
legs
	{
	idle : default
	}
	
	//Behavior WatchEntity ( 1 , 15 , "idle" , 0 , "idle" )
	time ( 0.1 )

states
	{
	AI_OFF : !IN_AI_MODE
	CORE : ANIM_DONE !HAVE_ENEMY !CAN_SHOOT_ENEMY
	//CORE : !CAN_ATTACK_ENEMY
	COMBAT_ATTACK : CAN_ATTACK_ENEMY CAN_SEE_ENEMY
	CORE : ANIM_DONE
	//COMBAT : BEHAVIOR_SUCCESS
	//COMBAT : BEHAVIOR_FAILED
	}
}

//---------------------------------------------------------
state COMBAT_ATTACK
//---------------------------------------------------------
{
entrycommands
	{
	printmessage "cannon COMBAT_ATTACK"
	evaluateenemies
	turntowardsenemy
	}
	
	Behavior WatchEntity ( 1 , 30 , "idle" , 0 , "fire" )

states
	{
	//COMBAT_ATTACK : CAN_ATTACK_ENEMY
	COMBAT_DECIDE : BEHAVIOR_SUCCESS
	COMBAT_DECIDE : BEHAVIOR_FAILED
	}
}





