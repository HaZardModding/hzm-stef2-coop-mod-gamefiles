//---------------------------------------------------------
state START
//---------------------------------------------------------
   {
	states
		{
		AI_OFF : !IN_AI_MODE
		AUTO   : default
		}
   }

//---------------------------------------------------------
state AI_OFF
//---------------------------------------------------------
	{
	entrycommands
		{
		usebehaviorpackage ( "general_ai_off" )
		}
		
	states
		{
		START : IN_AI_MODE
		}
	}

//---------------------------------------------------------
state AUTO
//---------------------------------------------------------
	{
	states
		{
		ATTACK : RANGE ( 90 )		
		ATTACK : IS_AGGRESSIVE ( .9 ) RANGE ( 1500 , 100 , -100 )		
		CORE : default
		}
	}

//---------------------------------------------------------
state CORE
//---------------------------------------------------------
	{
	entrycommands
		{
		usebehaviorpackage ( "coop_zombiH_core" )
		}
		
	states
		{
		ATTACK : RANGE ( 90 )
		ATTACK : IS_AGGRESSIVE ( .9 ) RANGE ( 1500 , 100 , -100 )
		AI_OFF : !IN_AI_MODE
		}
	}

//---------------------------------------------------------
state ATTACK
//---------------------------------------------------------
{
	entrycommands
		{
		usebehaviorpackage ( "coop_zombiH_attack" )
		}
		
	states
		{
		CORE : !HAVE_ENEMY 
		AI_OFF : !IN_AI_MODE
		}
}


//---------------------------------------------------------
state SCRIPTED
//---------------------------------------------------------
	{
	}
