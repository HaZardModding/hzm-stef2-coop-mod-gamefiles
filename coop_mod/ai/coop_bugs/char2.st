//coop_bugs - bug that gives the player a tip where to cross over
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

state DIG_OUT
{
	entrycommands
	{
		spawneffect fx/fx-explosion-debris-idryllruins-dustpuff.tik origin
		playSound "sound/environment/rock/rock_divein.wav" 3 0.7 512
		settendency	"digoutdone" 1
		show
	}
	Time ( 0.05 )	
	states
	{
		THINK : TIME_DONE
	}
}

state THINK
{
	states
	{
		DIG_OUT	: !SHOULD_DO_ACTION ( "digoutdone" )
		AI_OFF : !IN_AI_MODE
		PATROL : VALID_PATROL_NODE_IN_RANGE ( 256 ) //was 1024
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
		THINK : ANIM_DONE
	}
}
state PATROL
{
	entrycommands
	{
	unreservecurrenthelpernode
	}

	Behavior Patrol ( "walk" )

	states
	{
	PATROL_FAILED	: BEHAVIOR_FAILED
	PATROL_DONE		: BEHAVIOR_SUCCESS
	}
}
state PATROL_FAILED
{
	legs
	{
	idle : default
	}

	time ( .75 , 1.0 )

	states
	{
	PATROL : TIME_DONE
	}
}
state PATROL_DONE
{
	entrycommands
	{
		unreservecurrenthelpernode
		
		spawneffect fx/fx-explosion-debris-idryllruins-dustpuff.tik origin
		playSound "sound/environment/rock/rock_divein.wav" 3 0.7 512
		remove
	}
}


