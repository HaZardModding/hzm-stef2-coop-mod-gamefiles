//
// Name:     InformantBoss_PackageCombat
// Purpose:  AI for Combat State InformantBoss
//

//
// Includes
//
$include ai/InfBos/Mdul/M_InfBoss_Combat.ai
$include ai/InfBos/Mdul/M_InfBoss_Pain.ai
$include ai/InfBos/Mdul/M_InfBoss_Stage1.ai
$include ai/InfBos/Mdul/M_InfBoss_Stage2.ai
$include ai/InfBos/Mdul/M_InfBoss_Stage3.ai


//
// Defines
//

//---------------------------------------------------------
state START
//---------------------------------------------------------
	{
	entrycommands
		{
		groupattack
		}

	states
		{
		COMBAT_MAIN		: default
		}
	}

//---------------------------------------------------------
state COMBAT_MAIN
//---------------------------------------------------------
	{
	states
		{
		STAGE3_GENERAL_COMBAT_WITH_RANGED_WEAPON : STAGE ( 3 )
		STAGE2_GENERAL_COMBAT_WITH_RANGED_WEAPON	: STAGE ( 2 )
		STAGE1_GENERAL_COMBAT_WITH_RANGED_WEAPON : default
		}
	}

//---------------------------------------------------------
state HOLD
//---------------------------------------------------------
	{
	entrycommands
		{
//		printmessage "COMBAT:  HOLD"
		}

	legs
		{
		idle : default
		}

	time ( 1 )

	states
		{
		COMBAT_MAIN	: TIME_DONE
		}
	}

state GOTO_STAGE_2
{
	entrycommands
		{
//		printmessage "STAGE 2"
		runthread m10l2b_FromStateMachine_StageTransition
		gotostage 2
		}

	states
		{
		COMBAT_MAIN : default
		}

}

state GOTO_STAGE_3
{
	entrycommands
		{
//		printmessage "STAGE 3"
		runthread m10l2b_FromStateMachine_StageTransition
		gotostage 3
		}

	states
		{
		COMBAT_MAIN : default
		}
}