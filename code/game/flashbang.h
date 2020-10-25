//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/flashbang.h                                    $
// $Revision:: 3                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 12/11/00 3:18p                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/flashbang.h                                         $
// 
// 3     12/11/00 3:18p Steven
// Made str passing const references.
// 
// 2     12/11/00 9:35a Steven
// Changed passing of most vectors to const reference.
//
// 6     5/26/00 7:44p Markd
// 2nd phase save games
//
// 5     5/24/00 3:14p Markd
// first phase of save/load games
//
// 4     4/15/00 5:18p Aldie
// Added stun events and fixed yet another bug with Ammo and AutoPutaway
//
// 3     4/07/00 6:00p Aldie
// Added flashing and fixed radius damage for explosions
//
// 2     4/07/00 4:01p Aldie
// First version
//
// DESCRIPTION:
// Flashbang weapon

#ifndef __FLASHBANG_H__
#define __FLASHBANG_H__

#include "weapon.h"
#include "weaputils.h"

class Flashbang : public Weapon
   {
   public:
      CLASS_PROTOTYPE( Flashbang );

                     Flashbang();

      virtual void   SpecialFireProjectile( const Vector &pos,
                                            const Vector &forward,
                                            const Vector &right,
                                            const Vector &up,
                                            Entity *owner,
                                            const str    &projectileModel,
                                            float  charge_fraction
                                          );

   };

class FlashbangProjectile : public Projectile
   {
   private:
      float    stunRadius;
      float    stunTime;

   public:
      CLASS_PROTOTYPE( FlashbangProjectile );

      FlashbangProjectile();
      virtual void   Explode( Event *ev );
      void           StunTime( Event *ev );
      void           StunRadius( Event *ev );
	   virtual void   Archive( Archiver &arc );
	};

inline void FlashbangProjectile::Archive
	(
	Archiver &arc
	)
   {
   Projectile::Archive( arc );

   arc.ArchiveFloat( &stunRadius );
   arc.ArchiveFloat( &stunTime );
   }

#endif // __FLASHBANG_H__