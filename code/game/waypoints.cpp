//-----------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/waypoints.cpp                                       $
// $Revision:: 8                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 12/10/01 3:21p                                                 $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/waypoints.cpp                                            $
// 
// 8     12/10/01 3:21p Sketcher
// Changed QuakeEd Entry
// 
// 7     12/07/01 8:53a Sketcher
// Added new waypoint types
// 
// 6     11/05/01 8:35a Sketcher
// Added Patrol Waypoint Nodes
// 
// 5     10/15/01 2:18p Steven
// Added sourcesafe header.
//
// DESCRIPTION:
//
// Waypoint.cpp
//
// Implementation for Waypoint Class
//

#include "waypoints.h"

Event EV_WayPoint_SetActorAnim
   (
	"setactoranim",
	EV_DEFAULT,
	"s",
	"anim_name",
	"sets what primary anim to set an actor to, when it reaches this waypoint"
	);

Event EV_WayPoint_SetThread
   (
   "setwaypointthread",
	EV_DEFAULT,
	"s",
	"thread_name",
	"sets the script thread to be called when the actor reaches this waypoint"
	);

CLASS_DECLARATION( Entity , WayPointNode , "info_waypointnode_waypointnode" )
	{
		{ &EV_WayPoint_SetActorAnim,	     SetActorAnim	             },
		{ &EV_WayPoint_SetThread,	        SetWayPointThread	       },    		
		{ NULL, NULL }
	};


WayPointNode::WayPointNode()
	{
	Thread =           "";
	ActorAnim =        "";		
	}

WayPointNode::~WayPointNode()
	{

	}

//
// Accessors
//
const str &WayPointNode::GetThread()
	{
	return Thread;
	}

const str &WayPointNode::GetActorAnim()
	{
	return ActorAnim;
	}

void WayPointNode::SetActorAnim( const str &anim )
	{
	ActorAnim = anim;
	}

void WayPointNode::SetWayPointThread( const str &thread )
	{
	Thread = thread;
	}
//
// Events
//
void WayPointNode::SetWayPointThread ( Event *ev )
	{
   Thread = ev->GetString( 1 );
	}


void WayPointNode::SetActorAnim ( Event *ev )
	{
   ActorAnim = ev->GetString( 1 );
	}


/*****************************************************************************/
/*QUAKED info_waypointnode_waypointnode (1 0 1) (-12 -12 0) (12 12 12) 
******************************************************************************/


CLASS_DECLARATION( Entity , PatrolWayPointNode , "info_waypointnode_patrolwaypointnode" )
	{
		{ &EV_WayPoint_SetActorAnim,	     SetActorAnim	             },
		{ &EV_WayPoint_SetThread,	        SetWayPointThread	       },    		
		{ NULL, NULL }
	};


PatrolWayPointNode::PatrolWayPointNode()
	{
	SetWayPointThread("");
	SetActorAnim("");		
	}

PatrolWayPointNode::~PatrolWayPointNode()
	{

	}

/*****************************************************************************/
/*QUAKED info_waypointnode_patrolwaypointnode (0 0 1) (-12 -12 0) (12 12 12) 
******************************************************************************/

CLASS_DECLARATION( Entity , CallVolumeWayPointNode , "info_waypointnode_callvolume" )
	{
		{ &EV_WayPoint_SetActorAnim,	     SetActorAnim	             },
		{ &EV_WayPoint_SetThread,	        SetWayPointThread	       },    		
		{ NULL, NULL }
	};


CallVolumeWayPointNode::CallVolumeWayPointNode()
	{
	SetWayPointThread("");
	SetActorAnim("");		
	}

CallVolumeWayPointNode::~CallVolumeWayPointNode()
	{

	}

/*****************************************************************************/
/*QUAKED info_waypointnode_callvolume (.5 .5 .5) (-12 -12 0) (12 12 12) 
******************************************************************************/



CLASS_DECLARATION( Entity , PositionWayPointNode , "info_waypointnode_position" )
	{
		{ &EV_WayPoint_SetActorAnim,	     SetActorAnim	             },
		{ &EV_WayPoint_SetThread,	        SetWayPointThread	       },          
		{ NULL, NULL }
	};


PositionWayPointNode::PositionWayPointNode()
	{
	SetWayPointThread("");
	SetActorAnim("");	
   _reserved = false;
	}

PositionWayPointNode::~PositionWayPointNode()
	{

	}

void PositionWayPointNode::Reserve( qboolean reserve )
   {
   _reserved = reserve;
   }

qboolean PositionWayPointNode::IsReserved()
   {
   return _reserved;
   }

/*****************************************************************************/
/*QUAKED info_waypointnode_position (.8 0 .8) (-12 -12 0) (12 12 12) 
******************************************************************************/
