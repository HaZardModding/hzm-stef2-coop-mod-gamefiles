#include "actorutil.h"

//======================================
// SensoryPerception Implementation
//======================================

//
// Name:        SensoryPerception()
// Parameters:  None
// Description: Constructor
//
SensoryPerception::SensoryPerception()
	{
   //Initialize our Actor
	act = NULL;
	}

//
// Name:        SensoryPerception()
// Parameters:  Actor* actor -- The actor pointer to be assigned
//                              to the internal actor pointer
// Description: Constructor
//
SensoryPerception::SensoryPerception(Actor *actor )
	{
   //Initialize our Actor
   SetActor(actor);
	}

//
// Name:        ~SensoryPerception()
// Parameters:  None
// Description: Destructor
//
SensoryPerception::~SensoryPerception()
	{

	}

//
// Name:        SetActor()
// Parameters:  Actor *actor -- The actor pointer to be assigned
//                              to the internal actor pointer
// Description: Sets the internal actor pointer
//
SensoryPerception::SetActor(Actor *actor )
	{
	if ( actor )
		act = actor;
	else 
		gi.Error( ERR_DROP, "SensoryPerception::SetActor -- actor is NULL" );
	}

//
// Name:        WithinVisionDistance()
// Parameters:  Entity *ent -- The entity to be checked
// Description: Checks if the passed in entity is 
//              within the vision_distance of the actor, or the 
//              farplane_distance of the world ( whichever is smaller )
//
qboolean SensoryPerception::WithinVisionDistance( Entity *ent )
	{
	float distance;

	_checkActor();

	// Use whichever is less : the actor's vision distance or the distance of the farplane (fog)
	if ( (world->farplane_distance != 0) && (world->farplane_distance < act->vision_distance) )
		distance = world->farplane_distance;
	else
		distance = act->vision_distance;

	return act->WithinDistance( ent, distance );
	}

//
// Name:        InFOV()
// Parameters:  Vector &pos -- The position vector to be checked
//              float check_fov -- The fov number to be used
//              float check_fovdot -- the dot product
// Description: Checks if the passed in pos to see if it is in the FOV
//
qboolean SensoryPerception::InFOV( const Vector &pos, float check_fov, float check_fovdot	)
	{
	Vector delta;
	float	 dot;
	Vector temp;
	Vector tag_pos;
	Vector forward;


	_checkActor();

	if ( check_fov == 360 )
		return true;
	temp = act->EyePosition();
	delta = pos - act->EyePosition();

   if ( !delta.x && !delta.y )
      {
      // special case for straight up and down
      return true;
      }

	// give better vertical vision
	delta.z = 0;

	delta.normalize();
	
	//The code below is fucked.  The head bone is pointing almost
	//straight up, so it doesn't work very well
	/*
	tag_num = gi.Tag_NumForName( edict->s.modelindex, "Bip01 Head" );
	if ( tag_num < 0 )
		{
		dot = DotProduct( orientation[ 0 ], delta );
		return ( dot > check_fovdot );
		}

	GetTag( "Bip01 Head", &tag_pos, &forward );
	dot = DotProduct( &forward[0] , delta );
	return ( dot > check_fovdot );
	*/

	dot = DotProduct( act->orientation[ 0 ], delta );
	return ( dot > check_fovdot );

	}


//
// Name:        InFOV()
// Parameters:  Vector &pos -- The position to be checked
// Description: Calls another version of InFOV
//
qboolean SensoryPerception::InFOV
	(
	const Vector &pos
	)

	{
	return InFOV( pos, act->fov, act->fovdot );
	}


//
// Name:        InFOV()
// Parameters:  Entity* ent -- Provides the Position to check
// Description: Calls another version InFOV 
//
qboolean SensoryPerception::InFOV
	(
	Entity *ent
	)

	{
	return InFOV( ent->centroid );
	}

//
// Name:        CanSeeEntity()
// Parameters:  Entity *start - The entity trying to see
//              Entity *target - The entity that needs to be seen
//              qboolean useFOV - take FOV into consideration or not
//              qboolean useVisionDistance - take visionDistance into consideration
// Description: Wraps a lot of the different CanSee Functions into one
//
qboolean SensoryPerception::CanSeeEntity(Entity *start, Entity *target, qboolean useFOV, qboolean useVisionDistance )
	{
   
	// Check for NULL
	if ( !start || !target )
		return false;

	// Check for FOV
	if ( useFOV )
		{
		if ( !InFOV( target ) )
			return false;
		}

	// Check for vision distance
	if ( useVisionDistance )
		{
      if ( !WithinVisionDistance( target ) )
			return false;
		}
	
	// Do Trace
	trace_t trace;
	Vector p;
	Vector eyePos;

	p = target->centroid;
	eyePos = vec_zero;

	// If the start entity is an actor, then we want to add in the eyeposition
	if ( start->isSubclassOf ( Actor ) )
		{
		Actor *a;
		a = (Actor*)start;

		if ( !a )
			return false;

		eyePos = a->EyePosition();
		}

	// Check if he's visible
	trace = G_Trace( start->origin + eyePos, vec_zero, vec_zero, p, start, MASK_OPAQUE, false, "SensoryPerception::CanSeeEntity" );
	if ( trace.fraction == 1.0 || trace.ent == target->edict )
		return true;
			
	// Check if his head is visible
	p.z = target->absmax.z;
	trace = G_Trace( start->origin + eyePos, vec_zero, vec_zero, p, start, MASK_OPAQUE, false, "SensoryPerception::CanSeeEntity" );
	if ( trace.fraction == 1.0 || trace.ent == target->edict )
		return true;			


	return false;

	}


//
// Name:        CanSeeEntity()
// Parameters:  Vector &start -- The starting position
//              Entity *target - The entity that needs to be seen
//              qboolean useFOV - take FOV into consideration or not
//              qboolean useVisionDistance - take visionDistance into consideration
// Description: Wraps a lot of the different CanSee Functions into one
qboolean SensoryPerception::CanSeeEntity( Vector &start , Entity *target, qboolean useFOV , qboolean useVisionDistance )
	{
	// Check for NULL
	if ( !target )
		return false;

	// Check for FOV
	if ( useFOV )
		{
		if ( !InFOV( target ) )
			return false;
		}

	// Check for vision distance
	if ( useVisionDistance )
		{
      if ( !WithinVisionDistance( target ) )
			return false;
		}
	
	// Do Trace
	trace_t trace;
	Vector p;
	Vector eyePos;

	p = target->centroid;
	eyePos = vec_zero;

	// Check if he's visible
	trace = G_Trace( start, vec_zero, vec_zero, p, act, MASK_OPAQUE, false, "SensoryPerception::CanSeeEntity" );
	if ( trace.fraction == 1.0 || trace.ent == target->edict )
		return true;
			
	// Check if his head is visible
	p.z = target->absmax.z;
	trace = G_Trace( start, vec_zero, vec_zero, p, act, MASK_OPAQUE, false, "SensoryPerception::CanSeeEntity" );
	if ( trace.fraction == 1.0 || trace.ent == target->edict )
		return true;			


	return false;
	}


//
// Name:        CanSeeEntityComplex
// Parameters:  Entity *start - The entity trying to see
//              Entity *target - The entity that needs to be seen
//              qboolean useFOV - take FOV into consideration or not
//              qboolean useVisionDistance - take visionDistance into consideration
// Description: More detailed can see check
//
qboolean SensoryPerception::CanSeeEntityComplex(Entity *start, Entity *target, qboolean useFOV, qboolean useVisionDistance )
	{
	
	// Check for NULL
	if ( !start || !target )
		return false;

	_checkActor();

	// Check if target is alive
	if ( !act->IsEntityAlive( target ) )
      return false;
	
	return _CanSeeComplex(start->centroid, target, useFOV, useVisionDistance );

	}



//
// Name:        CanSeeEntityComplex
// Parameters:  Entity *start - The entity trying to see
//              Entity *target - The entity that needs to be seen
//              qboolean useFOV - take FOV into consideration or not
//              qboolean useVisionDistance - take visionDistance into consideration
// Description: More detailed can see check
//
qboolean SensoryPerception::CanSeeEntityComplex( Vector &start, Entity *target, qboolean useFOV , qboolean useVisionDistance )
	{
	// Check for NULL
	if ( !target )
		return false;

	_checkActor();

	// Check if target is alive
	if ( !act->IsEntityAlive( target ) )
      return false;

	return _CanSeeComplex(start, target, useFOV, useVisionDistance );

	}


//
// Name:        _CanSeeComplex
// Parameters:  Vector &start - start position
//              Vector &end   - end position
//              qboolean useFOV - take FOV into consideration or not
//              qboolean useVisionDistance             
// Description: Creates a plane to do a more complex check of vision
//
qboolean SensoryPerception::_CanSeeComplex( Vector &start, Entity *target , qboolean useFOV, qboolean useVisionDistance )
	{
	Vector	d;
	Vector	p1;
	Vector	p2;

	d = target->centroid - start;
	d.z = 0;
	d.normalize();
	
	p1.x = -d.y;
	p1.y = d.x;
	p1 *= max( act->size.x, act->size.y ) * 1.44 * 0.5;
	p2 = p1;

	p1.z = act->mins.z;
	p2.z = act->maxs.z;	
	if ( CanSeeEntity( start + p1, target , useFOV , useVisionDistance ) )
		{
		return true;
		}
	if ( CanSeeEntity( start + p2, target , useFOV , useVisionDistance ) )
		{
		return true;
		}

	p1.z = -p1.z;
	p2.z = -p2.z;
	if ( CanSeeEntity( start - p1, target , useFOV , useVisionDistance ) )
		{
		return true;
		}
	if ( CanSeeEntity( start - p2, target , useFOV , useVisionDistance ) )
		{
		return true;
		}

   return false;
	}

//
// Name:        _checkActor()
// Parameters:  None
// Description: Checks to make sure act is not null.  If it is null, it calls the
//              gi.Error function which will kill the map and server, as well as 
//              print the errormessage to the console 
//
void SensoryPerception::_checkActor()
	{
	if ( !act )
		gi.Error( ERR_DROP, "SensoryPerception::SetActor -- actor is NULL" );
	}


//======================================
// EnemyManager Implementation
//=====================================

//
// Constructors & Destructors
//

EnemyManager::EnemyManager()
	{

	}

EnemyManager::~EnemyManager()
	{

	}