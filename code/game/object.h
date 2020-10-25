//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/object.h                                       $
// $Revision:: 3                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 5/23/01 7:32a                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/object.h                                            $
// 
// 3     5/23/01 7:32a Sketcher
// Made changes to throw object and actor
//
// 5     6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 4     5/27/00 2:56p Markd
// Save games 2nd pass
//
// 3     5/24/00 3:14p Markd
// first phase of save/load games
//
// 2     1/27/00 11:35a Markd
// Fixed solid/notsolid client side entities
//
// 1     9/10/99 10:54a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 5     8/26/99 5:57p Markd
// Re-added fx_sprite support
//
// DESCRIPTION:
// Object class
//

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "g_local.h"
#include "sentient.h"
#include "animate.h"
#include "specialfx.h"

class Object : public Entity
	{
	public:
      CLASS_PROTOTYPE( Object );

							   Object();
      void              Killed( Event *ev );
      void              SetAngle( Event *ev );
      void              Setup( Event *ev );
      void              SetAnim( Event *ev );
      void              MakeShootable( Event *ev );
	};

extern Event EV_ThrowObject_Pickup;
extern Event EV_ThrowObject_Throw;

class ThrowObject : public Object
	{
   private:
      int               owner;
      Vector            pickup_offset;
      str               throw_sound;
		float             damage;
		qboolean          hurt_target;

	public:
      CLASS_PROTOTYPE( ThrowObject );
							   ThrowObject();
      void              Touch(Event *ev);
      void              Throw( Event * ev );		
		void              Throw( Entity *owner, float speed, Sentient *targetent, float gravity, float throw_damage );
      void              Pickup( Event * ev );
		void              Pickup( Entity* ent, const str &bone );
      void              PickupOffset( Event * ev );
      void              ThrowSound( Event * ev );
	   virtual void      Archive( Archiver &arc );
	};

inline void ThrowObject::Archive
	(
	Archiver &arc
	)
   {
   Object::Archive( arc );

   arc.ArchiveInteger( &owner );
   arc.ArchiveVector( &pickup_offset );
   arc.ArchiveString( &throw_sound );
	arc.ArchiveFloat( &damage );
	arc.ArchiveBoolean( &hurt_target );
   }

#endif /* object.h */