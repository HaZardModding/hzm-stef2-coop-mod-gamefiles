//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/armor.h                                        $
// $Revision:: 6                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 3/15/01 10:13a                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/armor.h                                             $
// 
// 6     3/15/01 10:13a Sketcher
// Once Again, I have added armor, and I think this time source will check
// things in correctly
// * 
// * 5     3/15/01 9:54a Sketcher
// * Crossing my fingers for source chafe again
// * 
// * 4     3/15/01 9:43a Sketcher
// * Trying Sourcesafe again
// * 
// * 3     3/15/01 9:35a Sketcher
// * Stupid Source Safe messed up the comments last time, I hope this check in
// * works
// * 
// * 2     3/15/01 9:04a Sketcher
// * Added Standard Armor
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 1     9/10/99 10:53a Jimdose
//
// 1     9/08/99 3:15p Aldie
//
// DESCRIPTION:
// Standard armor that prevents a percentage of damage per hit.
//

#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "item.h"

class ArmorEntity : public Item
	{
	public:
      CLASS_PROTOTYPE( ArmorEntity );

	                  ArmorEntity();
      virtual Item   *ItemPickup( Entity *other, qboolean add_to_inventory );
	};


#endif /* armor.h */