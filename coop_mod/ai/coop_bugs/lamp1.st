//coop_bugs - lamp that can be attacked by AI
state SCRIPTED
{
}
state AI_OFF
{
	entrycommands
	{
		start
	}
	states
	{
		THINK : IN_AI_MODE
	}
}
state THINK
{
	states
	{
		AI_OFF : !IN_AI_MODE
		IDLE : default
	}
}

state IDLE
{

	legs
	{
		idle : default
	}
	states
	{
		DEATH : DEAD
	}
}

state DEATH
{
	entrycommands
	{
		runthread "lights_killed"
		setcustomshader "electriclines"
	}
	states
	{
	}
}



