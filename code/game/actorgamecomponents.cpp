#include "actorgamecomponents.h"
#include "player.h"

CLASS_DECLARATION( Listener , ActorGameComponent, "actor_game_component" )
	{
		{ NULL, NULL }
	};



//=========================================
// EFGameComponent Implementation
//=========================================
CLASS_DECLARATION( ActorGameComponent, EFGameComponent, "ef_game_component" )
	{
		{ NULL, NULL }
	};

///////////////////////////////////////////
//
// Name: EFGameComponent()
// 
// Description: Constructor
//
///////////////////////////////////////////
EFGameComponent::EFGameComponent()
	{
 
	}



///////////////////////////////////////////
//
// Name: HandleDeath()
//
// Description: Base Death Handler
//
///////////////////////////////////////////
void EFGameComponent::HandleDeath( Entity *ent )
	{

	}


///////////////////////////////////////////
//
// Name: HandleArmorDamage
//
// Description Allows Game specific handling
// of damage
//
///////////////////////////////////////////
void EFGameComponent::HandleArmorDamage( Event *ev )
	{

	
	}

///////////////////////////////////////////
//
// Name: HandleArmorDamage
//
// Description Allows Game specific handling
// of some Think functionality -- will be
// called from the Actor's Think Strategy
//
///////////////////////////////////////////
void EFGameComponent::HandleThink()
	{


	}

///////////////////////////////////////////
//
// Name: HandleEvent()
// 
// Description: Base Event Handler
//
///////////////////////////////////////////
void EFGameComponent::HandleEvent( Event *ev )
	{
	Event *new_event;
	new_event = new Event( ev );
	ProcessEvent(new_event);
	}

////////////////////////////////////////////////////
//
// DoCheck
//
// Description: Base Check Handler
////////////////////////////////////////////////////

qboolean EFGameComponent::DoCheck ( Conditional &condition )
	{
   return false;
	}

////////////////////////////////////////////////////
//
// DoCheck
//
// Description: Sets the Actor
////////////////////////////////////////////////////
void EFGameComponent::SetActor ( Actor *actor )
   {
	if ( actor )
		act = actor;
	}