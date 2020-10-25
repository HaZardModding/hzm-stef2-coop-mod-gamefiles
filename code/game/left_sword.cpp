//-----------------------------------------------------------------------------
//
//  $Logfile:: /fakk2_code/fakk2/fgame/left_sword.cpp                         $
// $Revision:: 3                                                              $
//   $Author:: Aldie                                                          $
//     $Date:: 8/06/99 6:40p                                                  $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /fakk2_code/fakk2/fgame/left_sword.cpp                              $
// 
// 3     8/06/99 6:40p Aldie
// Started removing concept of currentWeapon
//
// DESCRIPTION:s
// 

#include "left_sword.h"
#include "weaputils.h"

CLASS_DECLARATION( Sword, LeftSword, "weapon_leftsword" )
	{
		{ NULL, NULL }
	};

LeftSword::LeftSword
   (
   )

   {
   setModel( "leftsword.tik" );
	SetRank( 20, 2 );	
   }

