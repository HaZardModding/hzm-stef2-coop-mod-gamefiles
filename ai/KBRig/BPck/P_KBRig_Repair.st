//
// Name:     Rig_PackageIdle
// Purpose:  Allows the Rig to be idle
//
// Notes:    None
// 

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		runthread "bossAI_EnterRepairState"
		}

	states
		{
		THINK		: default
		}
	
	exitcommands
		{
		childusebehaviorpackage left_arm rigarms_repair
		childusebehaviorpackage right_arm rigarms_repair
		}
	}

//---------------------------------------------------------
state THINK
//---------------------------------------------------------
	{
	states
		{
		TO_REPAIR	: default		
		}
	} 

//---------------------------------------------------------
state TO_REPAIR
//---------------------------------------------------------
	{
	legs
		{
		idle_to_repair : default
		}

	states
		{
		REPAIR : ANIM_DONE
		}
	}

//---------------------------------------------------------
state REPAIR
//---------------------------------------------------------
	{
	entrycommands
		{
		setdamagethreshold 20 -1
		cleardamagethreshold
		
		}

	legs
		{
		repair_idle : default
		}	
	
	time ( 10 )

	states
		{
		FROM_REPAIR : TIME_DONE
		FROM_REPAIR : DAMAGE_THRESHOLD_EXCEEDED
		}
	}

//---------------------------------------------------------
state FROM_REPAIR
//---------------------------------------------------------
	{
	legs
		{
		repair_to_idle : default
		}

	states
		{
		END : ANIM_DONE
		}

	exitcommands
		{
		runthread "bossAI_ExitRepairState"
		}
	}

//---------------------------------------------------------
state END
//---------------------------------------------------------
	{
	entrycommands
		{
		setdamagethreshold 20 5
		cleardamagethreshold
		addtomyarmor 250
		setmasterstate "AUTO"		
		}
	}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
	{
	legs
		{
		idle : default
		}
 
	time ( 1.5 , 3 )

	states
		{
		THINK 		:	TIME_DONE
		}
	}
