//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/inventoryitem.h                                $
// $Revision:: 2                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 5/01/01 1:57p                                                  $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/inventoryitem.h                                     $
// 
// 2     5/01/01 1:57p Steven
// Got rid of antisbjuice stuff.
//
// 2     6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 1     9/10/99 10:54a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 4     8/27/99 5:06p Steven
// Added anti Sucknblaugh juice powerup.
//
// DESCRIPTION:
// Items that are visible in the player's inventory


#ifndef __INVITEM_H__
#define __INVITEM_H__

#include "item.h"

class InventoryItem : public Item
	{
	public:
      CLASS_PROTOTYPE( InventoryItem );

                     InventoryItem();
      virtual void   UseEvent( Event *ev );
	};

extern Event EV_InventoryItem_Use;

#endif /* inventoryitem.h */