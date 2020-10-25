//-----------------------------------------------------------------------------
//
//  $Logfile:: /fakk2_code/fakk2/fgame/left_torch.cpp                         $
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
// $Log:: /fakk2_code/fakk2/fgame/left_torch.cpp                              $
// 
// 3     8/06/99 6:40p Aldie
// Started removing concept of currentWeapon
//
// DESCRIPTION:
// Torch

#include "left_torch.h"

CLASS_DECLARATION( Torch, LeftTorch, "weapon_lefttorch" )
	{
		{ NULL, NULL }
	};

LeftTorch::LeftTorch
   (
   )

   {
   setModel( "lefttorch.tik" );
	SetRank( 20, 3 );	
   }
