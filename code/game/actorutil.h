//============================
// Forward Declarations
//============================
class SensoryPerception;

#ifndef __ACTORUTIL_H__
#define __ACTORUTIL_H__

#include "actor.h"

/* Actor Utilities 
These classes will be used to help simplify the Actor class, and move some of the large subsystems it contained into
these smaller classes.  
*/

//============================
// Class SensoryPerception
//============================
//
// Class used to handle all sensory perception by actors.
//
class SensoryPerception : public Class
   {
	public:
		   SensoryPerception();
			SensoryPerception(Actor *actor );
		  ~SensoryPerception();		
		  
		  SetActor( Actor *actor );

         // Vision functions
   		qboolean	WithinVisionDistance( Entity *ent	);
		   qboolean	InFOV( const Vector &pos, float check_fov, float check_fovdot );
		   qboolean	InFOV( const Vector &pos );
		   qboolean	InFOV( Entity *ent );
		   
			// New Vision Functions -- Simplified Vision
			qboolean CanSeeEntity( Entity *start , Entity *target, qboolean useFOV, qboolean useVisionDistance );
			qboolean CanSeeEntity( Vector &start , Entity *target, qboolean useFOV, qboolean useVisionDistance );
			
			// New Vision Functions -- More Sophisticated Vision
			qboolean CanSeeEntityComplex( Entity *start , Entity *target, qboolean useFOV, qboolean useVisionDistance );
	      qboolean CanSeeEntityComplex( Vector &start , Entity *target, qboolean useFOV, qboolean useVisionDistance );			

	private: //Functions
		   void     _checkActor( void );
			qboolean _CanSeeComplex( Vector &start , Entity *target , qboolean useFOV , qboolean useVisionDistance );

	private: //Member Variablis
		   Actor *act;
	};

class EnemyManager : public Class
	{
   public:
		   EnemyManager();
	     ~EnemyManager();
	};

//Future Classes
//class UnitManager   -- Used to allow groups to function in coordination
//class ThreadManager -- Used to manage threads
//class Communication -- Used to handle dialog and communication with the player
//class Locomotion    -- Used to handle actor movement ( Still under heavy thought )
//class Combat        -- Used to handle actor combat ( Still under heavy thought )


#endif /* __ACTORUTIL_H__ */