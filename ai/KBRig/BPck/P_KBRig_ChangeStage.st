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
   states
      {
      THINK : default
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
	entrycommands
		{
		printmessage "Changing Stage"
		}
   states
      {
      CHANGE_STAGE2 : STAGE ( 1 )
	  CHANGE_STAGE3 : STAGE ( 2 )
	  CHANGE_STAGE4 : STAGE ( 3 )
	  CHANGE_STAGE4 : STAGE ( 4 )
      }
   } 

//---------------------------------------------------------
state CHANGE_STAGE2
//---------------------------------------------------------
{
	ignoreglobalstate

	entrycommands
		{
		runthread "bossAI_EnterPhase2"
		}

	legs
		{
		to_stage2 : default
		}

	states
		{
		TRANSITION_END : ANIM_DONE
		}

	exitcommands
		{
		gotostage 2
		//runthread "bossAI_EnterPhase2"
		}
}

//---------------------------------------------------------
state CHANGE_STAGE3
//---------------------------------------------------------
{
	ignoreglobalstate

	entrycommands
		{
		runthread "bossAI_EnterPhase3"
		}

	legs
		{
		to_stage3 : default
		}

	states
		{
		TRANSITION_END : ANIM_DONE
		}

	exitcommands
		{
		gotostage 3
		//runthread "bossAI_EnterPhase3"
		}
}

//---------------------------------------------------------
state CHANGE_STAGE4
//---------------------------------------------------------
{
	ignoreglobalstate

	entrycommands
		{
		gotostage 4
		runthread "bossAI_EnterPhase4"
		}

	legs
		{
		to_stage4 : default
		}

	states
		{
		TRANSITION_END : ANIM_DONE
		}

	exitcommands
		{
		
		//runthread "bossAI_EnterPhase4"
		}
}
//---------------------------------------------------------
state TRANSITION_END
//---------------------------------------------------------
{
	entrycommands
		{
		setmasterstate "AUTO"
		}
}