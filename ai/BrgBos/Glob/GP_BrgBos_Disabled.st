//
// Name:     BorgBoss_Global
// Purpose:  Global State File for Borg Boss
//
// Notes:    None

$define STAGE_2_HEALTH 800
$define STAGE_3_HEALTH 500
$define STAGE_4_HEALTH 300

//---------------------------------------------------------
globalstate GLOBAL_MAIN
//---------------------------------------------------------
   {
   states
      { 
      GOTO_STAGE_4_START_CHECK        : !STAGE ( 4 ) HEALTH ( $STAGE_4_HEALTH$ )
      GOTO_STAGE_3_START              : !STAGE ( 3 ) HEALTH ( $STAGE_3_HEALTH$ ) !HEALTH ( $STAGE_4_HEALTH$ )      
      GOTO_STAGE_2_START              : !STAGE ( 2 ) HEALTH ( $STAGE_2_HEALTH$ ) !HEALTH ( $STAGE_3_HEALTH$ )
      }
   }

//---------------------------------------------------------
state GOTO_STAGE_4_START_CHECK
//---------------------------------------------------------
   {
   ignoreglobalstate

   behavior AnimatedTeleportToPlayer ( "teleport_start" , "teleport_end" )
   time ( .5 )

   states
      {
      GOTO_STAGE_4_BEGIN : BEHAVIOR_SUCCESS TIME_DONE
      }
   }

//---------------------------------------------------------
state GOTO_STAGE_4_BEGIN
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      runthread stage_change_cinema_start
      }


//   legs
//      {
//      deactivated : default
//      }
//   
//   time ( 3 )

//   states
//      {
//      GOTO_STAGE_4 : TIME_DONE
//      }
   }

//---------------------------------------------------------
state GOTO_STAGE_4
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
        
      //No Draw Head
      surface material5 +nodraw            
      surface material11 +nodraw
      
      //No Draw Phaser
      surface material13 +nodraw
      surface material14 +nodraw
      surface material16 +nodraw
      }

   legs
      {
      change_stage_3 : default
      }

   states
      {
      GOTO_STAGE_FINISH : ANIM_DONE
      }

   exitcommands
      {
      displayeffect noelectric
      gotostage 4
      }
   }

//---------------------------------------------------------
state GOTO_STAGE_3_START
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      runthread stage_change_cinema_start      
      }

//   legs
//      {
//      deactivated : default
//      }
//   
//   time ( 3 )

//   states
//      {
//      GOTO_STAGE_3 : TIME_DONE
//      }
   }

//---------------------------------------------------------
state GOTO_STAGE_3
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      //No Draw Chest
      surface material6  +nodraw   

      //No Draw L Shoulder
      surface material10 +nodraw

      //No Draw R Arm
      surface material9  +nodraw
      }

   legs
      {
      change_stage_2 : default
      }

   states
      {
      GOTO_STAGE_FINISH : ANIM_DONE
      }

   exitcommands
      {
      displayeffect noelectric
      gotostage 3
      }
   }

//---------------------------------------------------------
state GOTO_STAGE_2_START
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      runthread stage_change_cinema_start      
      }

//   legs
//      {
//      deactivated : default
//      }
   
//   time ( 3 )

//   states
//      {
//      GOTO_STAGE_2 : TIME_DONE
//      }
   }

//---------------------------------------------------------
state GOTO_STAGE_2
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      //No Draw L Leg
      surface material8 +nodraw    

      //No Draw Stomach
      surface material7 +nodraw
      }

   legs
      {
      change_stage_1 : default
      }

   states
      {
      GOTO_STAGE_FINISH : ANIM_DONE
      }

   exitcommands
      {
      displayeffect noelectric
      gotostage 2      
      }
   }

//---------------------------------------------------------
state GOTO_STAGE_FINISH
//---------------------------------------------------------
   {
   ignoreglobalstate

   entrycommands
      {
      displayeffect noelectric            
      runthread stage_change_cinema_end
	  setactorflag "disabled" 0 	
      }

   states
      {
      THINK : default
      }
   }
