//
// Name:     Humanoid_MasterStateMap.st
// Purpose:  MasterStateMap for Humanoids
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
		usebehaviorpackage ( "romulan_m10_instguard_pistol_core" )
		}

	states
		{
		AI_OFF 			: !IN_AI_MODE
		COMBAT 			: HAVE_ENEMY CAN_SEE_ENEMY
		TO_ENEMY		: ATTACKED_BY_PLAYER
		}
	}
//---------------------------------------------------------
state COMBAT
//---------------------------------------------------------
	{
	entrycommands
		{
		setposturestate ( "STAND" , "STAND" )
		usebehaviorpackage ( "romulan_m10_instguard_pistol_combat" )
		groupattack
		}

	states
		{
		AI_OFF : !IN_AI_MODE
		CORE : !HAVE_ENEMY
		}
	}


//---------------------------------------------------------
state TO_ENEMY
//---------------------------------------------------------
	{
	entrycommands
		{
		actortype "enemy"
		visiondistance 1500
		setposturestate ( "STAND" , "STAND" )
		groupactortype "enemy"
		selectclosestenemy
		runthread "m10l1_FromStateMachine_ToEnemy"
		groupattack
		}

	states
		{
		AI_OFF 			  : !IN_AI_MODE
		COMBAT 			  : HAVE_ENEMY CAN_SEE_ENEMY
		COMBAT			  : ATTACKED
		COMBAT			  : HAVE_ENEMY NOISE_HEARD
		}
	}

//---------------------------------------------------------
state SCRIPTED
//---------------------------------------------------------
	{
	}		