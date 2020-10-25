//-----------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/waypoints.h                                         $
// $Revision:: 6                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 11/05/01 8:35a                                                 $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/waypoints.h                                              $
// 
// 6     11/05/01 8:35a Sketcher
// Added Patrol Waypoint Nodes
// 
// 5     10/15/01 2:19p Steven
// Added sourcesafe header.
//
// DESCRIPTION:

//
// Forward Declarations
//
class WayPointNode;

#ifndef __WAYPOINTS_H__
#define __WAYPOINTS_H__

#include "entity.h"

class WayPointNode : public Entity
  {
	public:
		CLASS_PROTOTYPE( WayPointNode );
							  WayPointNode();
							 ~WayPointNode();

		//Events
		virtual void  SetWayPointThread ( Event *ev );		
		virtual void  SetActorAnim      ( Event *ev );
		        void  SetTargetname     ( Event *ev );
              void  SetTarget         ( Event *ev );
		
		
		virtual void  SetWayPointThread ( const str &thread );
		virtual void  SetActorAnim ( const str &thread );

		virtual const str     &GetThread();
		virtual const str     &GetActorAnim();		
			
	private:
      str Thread;
		str ActorAnim;				

  };

class PatrolWayPointNode : public WayPointNode
	{
	public:
		CLASS_PROTOTYPE( PatrolWayPointNode );
							  PatrolWayPointNode();
							 ~PatrolWayPointNode();
	
	};

class CallVolumeWayPointNode : public WayPointNode
   {
	public:
		CLASS_PROTOTYPE( CallVolumeWayPointNode );
							  CallVolumeWayPointNode();
							 ~CallVolumeWayPointNode();    
   };

class PositionWayPointNode : public WayPointNode
   {
   private:
      qboolean         _reserved;

	public:
		CLASS_PROTOTYPE( PositionWayPointNode );
							  PositionWayPointNode();
							 ~PositionWayPointNode(); 

      void Reserve( qboolean reserve );
      qboolean IsReserved();
      
   };

#endif /* __WAYPOINTS_H__ */
