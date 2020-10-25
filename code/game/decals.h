//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/decals.h                                       $
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
// $Log:: /red_code/game/decals.h                                            $
// 
// 3     12/11/00 3:18p Steven
// Made str passing const references.
// 
// 2     12/11/00 9:34a Steven
// Changed passing of most vectors to const reference.
//
// 4     6/23/00 11:49a Markd
// fixed various imagindexes and saved games
//
// 3     6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 2     1/29/00 2:48p Aldie
// Added impact mark functionality and Decal class
//
// DESCRIPTION:
// Decal entities

#ifndef __DECAL_H__
#define __DECAL_H__

#include "g_local.h"

class Decal : public Entity
	{
   private:
      str            shader;

	public:
      CLASS_PROTOTYPE( Decal );

	                  Decal();
      void           setDirection( const Vector &dir );
      void           setShader( const str &shader );
      void           setOrientation( const str &deg );
      void           setRadius( float rad );
      virtual void   Archive( Archiver &arc );
	};

inline void Decal::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.ArchiveString( &shader );
   if ( arc.Loading() )
      {
      setShader( shader );
      }
   }

#endif // __DECAL_H__