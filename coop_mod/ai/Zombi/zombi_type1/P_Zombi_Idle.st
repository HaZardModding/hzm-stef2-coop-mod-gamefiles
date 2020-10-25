//
// Name:     BorgDrone_PackageIdle
// Purpose:  Idle Functionality
//
//

//---------------------------------------------------------
state START
//---------------------------------------------------------
  {
  entrycommands
      {
      }

  states
     {
     THINK : default	
     }
  }

//---------------------------------------------------------  
state THINK
//---------------------------------------------------------
  {
  legs
     {
    idle : default	
     }	

  states
     {
     START : ANIM_DONE	
     }  	
  }