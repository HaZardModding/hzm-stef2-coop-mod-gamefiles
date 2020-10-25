//============================
// Forward Declarations
//============================
class ActorGameComponent;
class RedemptionGameComponent;

#ifndef __ACTORGAMECOMPONENTS_H__
#define __ACTORGAMECOMPONENTS_H__

#include "actor.h"

/*
ActorGameComponents
What I am trying to do here, is encapsulate any game specific pieces for actor.  Each game will 
subclass off of the base class, then the Actor class will point to the component class it will
use.  I am hoping this will make life much easier for mod makers as well
*/

//============================
// Class ActorGameComponent
//============================
//
// Base class from which all Actor Game Components are derived.
//
class ActorGameComponent : public Listener
	{
	public:
		CLASS_PROTOTYPE( ActorGameComponent );

		                  ActorGameComponent()              {}
		virtual void	   HandleEvent( Event *ev )          {}
		virtual void	   HandleArmorDamage( Event *ev )    {}
		virtual void	   HandleDeath( Entity *ent )        {}
		virtual void	   HandleThink()                     {}
		
		virtual qboolean  DoCheck( Conditional &condition ) { return false; }
		virtual void	   SetActor( Actor *actor )          {}

	};

/*
Redemption Specific Stuff
*/
//============================
// Class RedemptionGameComponent
//============================
class EFGameComponent : public ActorGameComponent
	{
	public:
		CLASS_PROTOTYPE( EFGameComponent );

				EFGameComponent();
		void  HandleEvent( Event *ev );		
		void  HandleArmorDamage( Event *ev );
		
		void  HandleDeath(Entity *ent);
		void  HandleThink();

		void  SetActor                ( Actor *actor );

		qboolean DoCheck( Conditional &condition );

	private:
		Actor *act;
	};

#endif /*__ACTORGAMECOMPONENTS_H__*/