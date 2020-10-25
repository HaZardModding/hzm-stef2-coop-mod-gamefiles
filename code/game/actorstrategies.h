//============================
// Forward Declarations
//============================
class ActorThink;

#ifndef __ACTORSTRATEGIES_H__
#define __ACTORSTRATEGIES_H__

#include "actor.h"

/* Actor Strategies 
I am replacing the old way that Actor::Think was done by implementing a group of strategies for it
instead.  This will form the foundation for new flexiblility within the actor class.  

What I am trying to achieve is a specialized "think" for different types of actors.  A Boss, for instance,
would use BossThink, an Non-Attacking-NPC could use NPCThink.  Using the event system we already have inplace
it will be easy to change thinking modalities on the fly, allowing us to make a cowardly NPC turn into a 
roaring death machine if he gets shot.
*/

extern Container<Actor *> SleepList;
extern Container<Actor *> ActiveList;
//============================
// Class ActorThink 
//============================
//
// Base class from which all Actor Think Strategies are derived.
//
class ActorThink : public Class
   {
	public:
		      		 ActorThink();
	virtual void    Think( Actor *act );
		
	};

#endif /* __ACTORSTRATEGIES_H__ */