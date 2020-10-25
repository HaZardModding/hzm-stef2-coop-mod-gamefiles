//
// Name:     Romulan_DisruptorRifleMasterStateMap.st
// Purpose:  Masterstate map for Rifle Using Romulans
//

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
	{
		//turntowardsenemy
	}
	
	states
		{
		AUTO : default
		}
	}

//---------------------------------------------------------
state AI_OFF
//---------------------------------------------------------
	{
	entrycommands
		{
		setposturestate ( "STAND" , "STAND" )
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
		AI_OFF : !IN_AI_MODE
		COMBAT : HAVE_ENEMY
		CORE : default
		}
	}

//---------------------------------------------------------
state CORE
//---------------------------------------------------------
	{
	entrycommands
		{
		setposturestate ( "STAND" , "STAND" )
		usebehaviorpackage ( "romulan_m10_soldier_rifle_core" )
		}

	states
		{
		AI_OFF : !IN_AI_MODE
		COMBAT : CHECK_VAR ( "manual_state" , "combat" )
		}
	}

//---------------------------------------------------------
state COMBAT
//---------------------------------------------------------
	{
	entrycommands
		{
//city 5, use weapon when abort working on console
		giveactorweapon "actorweapons/romulan-disruptor-rifle.tik" 
		useactorweapon "RomulanDisruptorRifle"
		runthread "player_detected"
		
		setposturestate ( "STAND" , "STAND" )
		usebehaviorpackage ( "romulan_m10_soldier_rifle_combat" )
		incontext "startcombat"
		}

	states
		{
		AI_OFF : !IN_AI_MODE
		CORE : CHECK_VAR ( "manual_state" , "core" )
		}

	exitcommands
		{
		incontext "postcombat"
		}
	}

//---------------------------------------------------------
state SCRIPTED
//---------------------------------------------------------
	{
	}	
