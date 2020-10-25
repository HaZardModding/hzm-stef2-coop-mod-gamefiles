//-----------------------------------------------------------------------------
//
//  $Logfile::                                                                $
// $Revision::                                                                $
//   $Author::                                                                $
//     $Date::                                                                $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log::                                                                     $
//
// DESCRIPTION:
// Torch

#include "torch.h"

CLASS_DECLARATION( Weapon, Torch, "weapon_torch" )
	{
		{ NULL, NULL }
	};

Torch::Torch
   (
   )

   {
   setModel( "torch.tik" );
   SetAmmo( NULL, 0, 0 );
	SetRank( 20, 1 );	
   SetType( WEAPON_1HANDED );
   }
