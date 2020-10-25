//coop_bugs - bugs spawner
state SCRIPTED
{
}
state AI_OFF
{	
	states
	{
		START : IN_AI_MODE
	}
}

state IDLE
{	
	time ( 0.5 )
	states
	{
		THINK : TIME_DONE
	}
}

state THINK
{
	entrycommands
	{
		evaluateenemies
		selectclosestenemy
	}
	
	states
	{
		AI_OFF	:	!IN_AI_MODE
		DIE		: 	HEALTH_PERCENT_LESS_THAN ( 0.2 )
		SPAWN	:	HAVE_ENEMY RANGE ( 1500 )
		SPAWN	:	PAIN
	}
}

state SPAWN
{
	entrycommands
	{
		runthread "pods_spawn"
	}

	time ( 1 )

	states
	{
		THINK : TIME_DONE
	}
}

state DIE
{
	entrycommands
	{
		runthread "pods_die"
	}

	states
	{
	}
}
