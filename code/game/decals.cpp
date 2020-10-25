//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/decals.cpp                                     $
// $Revision:: 3                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 12/11/00 3:16p                                                 $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/decals.cpp                                          $
// 
// 3     12/11/00 3:16p Steven
// Made str passing const references.
// 
// 2     12/11/00 9:33a Steven
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

#include "decals.h"


CLASS_DECLARATION( Entity, Decal, NULL )
	{
		{ NULL, NULL }
	};

Decal::Decal
   (
   )

   {
   edict->s.eType = ET_DECAL;
   edict->s.modelindex  = 1;	      // must be non-zero
   PostEvent( EV_Remove, FRAMETIME );
   }

void Decal::setDirection
   (
   const Vector &dir
   )

   {
   edict->s.surfaces[0] = DirToByte( ( Vector )dir );
   }

void Decal::setShader
   (
   const str &decal_shader
   )

   {
   str temp_shader;

   shader = decal_shader;
   edict->s.tag_num = gi.imageindex( shader.c_str() );

	temp_shader = shader + ".spr";
	CacheResource( temp_shader, this );
   }

void Decal::setOrientation
   (
   const str &deg
   )

   {
   Vector ang;

   if ( !deg.icmp( "random" ) )
      ang[2] = random() * 360;
   else
      ang[2] = atof( deg );

   setAngles( ang );
   }

void Decal::setRadius
   (
   float rad
   )

   {
   edict->s.scale = rad;
   }
