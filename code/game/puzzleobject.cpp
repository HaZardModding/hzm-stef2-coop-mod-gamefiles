//-----------------------------------------------------------------------------
//
//  $Logfile:: /Code/DLLs/game/puzzleobject.cpp                               $
// $Revision:: 8                                                              $
//     $Date:: 9/04/02 4:22p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Code/DLLs/game/puzzleobject.cpp                                    $
// 
// 8     9/04/02 4:22p Jmartel
// 
// 7     8/12/02 12:17p Jmartel
// 
// 6     8/09/02 3:21p Jmartel
// added activate/deActivate events
// 
// 5     8/01/02 9:07a Steven
// Updated think stuff to use new interface.
// 
// 4     7/18/02 7:08p Jmartel
// - changed state system a bit and filled in some holes
// - at Shawn's advice, changed animation names to work around RandomAnimate
// doing what it's supposed to do.
// 
// 3     5/15/02 2:38p Singlis
// fixed a few bugs in the puzzle object.
// 
// 2     5/14/02 8:18p Singlis
// renamed cancelled to canceled and made the quake ed description more
// descriptive
// 
// 1     5/14/02 6:13p Singlis
// initial checkin

#include "_pch_cpp.h"
#include "PuzzleObject.hpp"
#include "sentient.h"
#include "player.h"
#include "Equipment.h"


//Event EV_
Event EV_PuzzleObject_SetOpenDistance
	(
	"puzzleobject_opendistance",
	EV_DEFAULT,
	"f",
	"openDistance",
	"Sets the open distance from player that the puzzle object will open or close"
	);

Event EV_PuzzleObject_AnimationDone
	(
	"puzzleobject_animdone",
	EV_CODEONLY,
	NULL,
	NULL,
	"Called when the puzzle object's animation is done."
	);

Event EV_PuzzleObject_SetItemToUse
	(
	"puzzleobject_itemtouse",
	EV_DEFAULT,
	"s",
	"item",
	"The item to use on the puzzle"
	);

Event EV_PuzzleObject_SetItemUsedThread
	(
	"puzzleobject_itemusedthread",
	EV_DEFAULT,
	"s",
	"threadname",
	"The thread to call when the item is used"
	);

Event EV_PuzzleObject_SetFailedThread
	(
	"puzzleobject_failedthread",
	EV_DEFAULT,
	"s",
	"threadname",
	"The thread to call when the puzzle fails"
	);

Event EV_PuzzleObject_SetSolvedThread
	(
	"puzzleobject_solvedthread",
	EV_DEFAULT,
	"s",
	"threadname",
	"The thread to call when the puzzle is solved"
	);

Event EV_PuzzleObject_SetCanceledThread
	(
	"puzzleobject_canceledthread",
	EV_DEFAULT,
	"s",
	"threadname",
	"The thread to call when the puzzle is canceled"
	);

Event EV_PuzzleObject_Failed
	(
	"puzzleobject_failed",
	EV_DEFAULT,
	NULL,
	NULL,
	"Received when the puzzle fails"
	);

Event EV_PuzzleObject_Canceled
	(
	"puzzleobject_canceled",
	EV_DEFAULT,
	NULL,
	NULL,
	"Received when the puzzle is canceled"
	);

Event EV_PuzzleObject_Solved
	(
	"puzzleobject_solved",
	EV_DEFAULT,
	NULL,
	NULL,
	"Received when the puzzle is solved"
	);

Event EV_PuzzleObject_Reset
	(
	"puzzleobject_reset",
	EV_DEFAULT,
	NULL,
	NULL,
	"Resets a previously solved puzzle so that it can be triggered again"
	);

Event EV_PuzzleObject_Activate
	(
	"puzzleobject_activate",
	EV_DEFAULT,
	NULL,
	NULL,
	"Lets the object think and respond to the player again.  DOES NOT affect any change in animation."
	);

Event EV_PuzzleObject_DeActivate
	(
	"puzzleobject_deactivate",
	EV_DEFAULT,
	NULL,
	NULL,
	"Makes the object unresponsive to input and the player.  DOES NOT affect any change in animation."
	);

//---------------------------------------------------------
//             PUZZLE OBJECT
//---------------------------------------------------------
/*****************************************************************************/
/*QUAKED puzzle_object (0 0.5 1) (-16 -16 0) (16 16 32)

Puzzle object is the basic framework for all the puzzles. It communicates 
with the script through events and threads to process the puzzle state.
All logic for the puzzle object exists in the script. 

The puzzle object contains four threads, which are ItemUsed, Solved, Canceled and Failed. 
These are explained in the Key Value Pairs section. The Puzzle object also contains an 
item used string. This allows the level designer to specify the item the player must 
use to activate the puzzle. 

Key Value Pairs:
model						 <model name>	- the tiki model to use for the puzzle object
puzzleobject_opendistance	 <distance>		- the amount of distance the player should be before the puzzle opens.
puzzleobject_itemtouse		 <item name>	- the name of the item the player must use to execute the puzzle
puzzleobject_itemusedthread	 <thread name>	- the name of the thread called when the item is used.
puzzleobject_failedthread	 <thread name>	- the name of the thread called when the puzzle fails
puzzleobject_canceledthread	 <thread name>  - the name of the thread called when the puzzle is canceled
puzzleobject_solvedthread	 <thread name>	- the name of the thread called when the puzzle is solved.

******************************************************************************/
CLASS_DECLARATION( Entity, PuzzleObject, "puzzle_object" )
{
	{ &EV_PuzzleObject_SetOpenDistance,		setOpenDistance		},
	{ &EV_PuzzleObject_AnimationDone,		animationDone		},
	{ &EV_PuzzleObject_SetItemToUse,		setItemToUse		},
	{ &EV_PuzzleObject_SetItemUsedThread,	setItemUsedThread	},
	{ &EV_PuzzleObject_SetFailedThread,		setFailedThread		},
	{ &EV_PuzzleObject_SetSolvedThread,		setSolvedThread		},
	{ &EV_PuzzleObject_SetCanceledThread,	setCanceledThread	},
	{ &EV_PuzzleObject_Failed,				failed				},
	{ &EV_PuzzleObject_Canceled,			canceled			},
	{ &EV_PuzzleObject_Solved,				solved				},
	{ &EV_PuzzleObject_Reset,				reset				},
	{ &EV_Use,								useEvent			},
	{ &EV_PuzzleObject_Activate,			activate			},
	{ &EV_PuzzleObject_DeActivate,			deActivate			},
	{NULL, NULL}
};

//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
PuzzleObject::PuzzleObject() 
{
	animate = new Animate( this );

	_saveState = PUZZLE_STATE_IDLE;
	_puzzleState = PUZZLE_STATE_IDLE;
	animate->RandomAnimate( "puzzle_idle" );

	edict->s.eType = ET_MODELANIM;
	_openDistance = 200.0f;
	turnThinkOn();
}



//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
PuzzleObject::~PuzzleObject()
{

}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::Think( void )
{
	bool playerNearby = false;
	Player *player;
	Vector dir;
	float distance;

	// when idle, handle player walking in and out of range
	if( (_puzzleState == PUZZLE_STATE_IDLE) || (_puzzleState == PUZZLE_STATE_IDLE_OPEN) )
	{
		// get the player's distance from the puzzle	
		player = (Player *)g_entities[ 0 ].entity;
		if ( player )
		{
			dir = player->origin - origin;
			distance = dir.length();

			if ( distance < _openDistance )
			{
				playerNearby = true;
			}
		}

		// if the player is near, open up
		if( (_puzzleState == PUZZLE_STATE_IDLE) && (playerNearby == true) )
		{
			_puzzleState = PUZZLE_STATE_OPENING;
			animate->RandomAnimate( "puzzle_opening", EV_PuzzleObject_AnimationDone );
		}

		// if the player has moved away, close up
		if( (_puzzleState == PUZZLE_STATE_IDLE_OPEN) && (playerNearby == false) )
		{
			_puzzleState = PUZZLE_STATE_CLOSING;
			animate->RandomAnimate("puzzle_closing", EV_PuzzleObject_AnimationDone );
		}
	}
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::setOpenDistance(Event* event)
{
	_openDistance = event->GetFloat(1);
}

void PuzzleObject::setItemToUse(Event* event)
{
	_itemToUse = event->GetString(1);
}
//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::setItemUsedThread(Event* event)
{
	_itemUsedThread = event->GetString(1);
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::setFailedThread(Event* event)
{
	_failedThread = event->GetString(1);
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::setSolvedThread(Event* event)
{
	_solvedThread = event->GetString(1);
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::setCanceledThread(Event* event)
{
	_canceledThread = event->GetString(1);
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::failed(Event* event)
{
	if(_failedThread.length() != 0)
	{
		ExecuteThread(_failedThread, true, this);
	}

	// close and lapse into locked mode
	_puzzleState = PUZZLE_STATE_CLOSING_LOCKED;
	animate->RandomAnimate( "puzzle_closing", EV_PuzzleObject_AnimationDone );
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::canceled(Event* event)
{
	if(_canceledThread.length() != 0)
	{
		ExecuteThread( _canceledThread, true, this);
	}

	// close and lapse into normal mode
	_puzzleState = PUZZLE_STATE_CLOSING;
	animate->RandomAnimate( "puzzle_closing", EV_PuzzleObject_AnimationDone );
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::solved(Event* event)
{
	if(_solvedThread.length() != 0)
	{
		ExecuteThread(_solvedThread, true, this);
	}

	// close and lapse into solved mode
	_puzzleState = PUZZLE_STATE_CLOSING_SOLVED;
	animate->RandomAnimate( "puzzle_closing", EV_PuzzleObject_AnimationDone );
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::animationDone(Event* event)
{
	if( _puzzleState == PUZZLE_STATE_OPENING )
	{
		_puzzleState = PUZZLE_STATE_IDLE_OPEN;
		animate->RandomAnimate( "puzzle_waitingopen" );
	}
	else if( _puzzleState == PUZZLE_STATE_CLOSING )
	{
		_puzzleState = PUZZLE_STATE_IDLE;
		animate->RandomAnimate( "puzzle_idle" );
	}
	else if( _puzzleState == PUZZLE_STATE_CLOSING_SOLVED )
	{
		_puzzleState = PUZZLE_STATE_IDLE_SOLVED;
		animate->RandomAnimate( "puzzle_idle" );
	}
	else if( _puzzleState == PUZZLE_STATE_CLOSING_LOCKED )
	{
		_puzzleState = PUZZLE_STATE_IDLE_LOCKED;
		animate->RandomAnimate( "puzzle_idle" );
	}
}


//-----------------------------------------------------
//
// Name:		
// Class:		
//
// Description:	
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::useEvent(Event* event)
{
	// don't get retriggered if the puzzle is busy
	if(	_puzzleState != PUZZLE_STATE_IDLE_OPEN )
		return;

	if( _itemToUse.length() == 0 || _itemUsedThread.length() == 0)
		return;

	//retrieve the item the player is using. 
	//if it matches the itemUsed string, 
	//then execute the usedItem thread.

	// Get the entity that is using us
	Entity* entity;
	entity = event->GetEntity( 1 );

	if( entity 
		&& entity->isSubclassOf( Equipment ) 
		&& !stricmp( ((Equipment*)entity)->getName().c_str(), _itemToUse.c_str()) )
	{
		// let script take it from here
		ExecuteThread( _itemUsedThread, true, this );

		_puzzleState = PUZZLE_STATE_ACTIVE_OPEN;
		animate->RandomAnimate( "puzzle_openon" );

	}
}

//-----------------------------------------------------
//
// Name:		reset
// Class:		PuzzleObject
//
// Description:	Resets the puzzle's state to idle so it will 
//				animate correctly if played again and can be used again
//
// Parameters:	
//
// Returns:		
//-----------------------------------------------------
void PuzzleObject::reset( Event* event )
{
	_puzzleState = PUZZLE_STATE_IDLE;
	animate->RandomAnimate( "puzzle_idle" );
}

void PuzzleObject::activate( Event* event )
{
	_puzzleState = _saveState;
}

void PuzzleObject::deActivate( Event* event )
{
	_saveState = _puzzleState;
	_puzzleState = PUZZLE_STATE_DEACTIVATED;
}