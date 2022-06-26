$define EXPLODE_RANGE 200

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	states
	{
		IDLE : default
	}
}

//---------------------------------------------------------
state IDLE
//---------------------------------------------------------
{
entrycommands
	{
	//printmessage "explosive IDLE"
	fov 360
	}
	
legs
	{
	idle : default
	}
	
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
	//printmessage "explosive AUTO"
	}
	
states
	{
	AI_OFF : !IN_AI_MODE
	CORE : default
	}
}

//---------------------------------------------------------
state AI_OFF
//---------------------------------------------------------
{
entrycommands
	{
	//printmessage "explosive AI_OFF"
	}
	
states
	{
	AUTO : IN_AI_MODE
	}
}

//---------------------------------------------------------
state CORE
//---------------------------------------------------------
{
entrycommands
	{
	//printmessage "explosive CORE"
	}
	
states
	{
	AI_OFF : !IN_AI_MODE
	EXPLODE : HAVE_ENEMY RANGE ( $EXPLODE_RANGE$ )
	}
}

//---------------------------------------------------------
state EXPLODE
//---------------------------------------------------------
{
	entrycommands
	{
	//printmessage "explosive Explode"
	selfdetonate
	radiusattack "origin" "Explosion" 600 400 25 1
	}
	
	//checkenemyrange
	//doexplosion( [ String explosionModel ], [ Float explosionRadius ] )
	
	time ( 0.1 )
	
	states
	{
		REMOVE : TIME_DONE
	}
}
//---------------------------------------------------------
state REMOVE
//---------------------------------------------------------
{
	entrycommands
	{
	//printmessage "explosive Remove"
	//selfdetonate
	//radiusattack "origin" "Explosion" 300 300 25 1
	remove
	}
	
	//checkenemyrange
	//doexplosion( [ String explosionModel ], [ Float explosionRadius ] )
	
	states
	{
	}
}

