//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/armor.cpp                                      $
// $Revision:: 7                                                              $
//   $Author:: Sketcher                                                       $
//     $Date:: 3/15/01 10:12a                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/armor.cpp                                           $
// 
// 7     3/15/01 10:12a Sketcher
// Another Test
// * 
// * 6     3/15/01 10:09a Sketcher
// * Testing
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
// 5     6/23/00 8:41p Markd
// made a lot of changes to different constructors for saved game support
//
// 4     6/01/00 3:18p Markd
// rewrote giveItem and item management in sentient
//
// 3     1/26/00 3:33p Aldie
// Change Amount to getAmount. Added some 'listinventory' command.  Added give
// all cheat to execute the script in global/giveall.txt
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// 1     9/10/99 10:53a Jimdose
//
// 1     9/08/99 3:15p Aldie
//
//
// DESCRIPTION:
// Standard armor that prevents a percentage of damage per hit.
//

#include "g_local.h"
#include "armor.h"
#include "player.h"

CLASS_DECLARATION( Item, ArmorEntity, NULL )
	{
		{ NULL, NULL }
	};

ArmorEntity::ArmorEntity
   (
   )

	{
   if ( LoadingSavegame )
      {
      // all data will be setup by the archive function
      return;
      }
   setName( "UnknownArmor" );
   amount       = 0;	
	SetMax( 200 );
	}

Item *ArmorEntity::ItemPickup
   (
   Entity *other,
	qboolean add_to_inventory
   )

   {
   Player *player;
	str      realname;
	

   if ( !other->isSubclassOf( Player ) )
      return NULL;

   player = ( Player * )other;
	
	armortype_t atype = ARMORTYPE_NONE;
	if ( item_name == "Heavy" ) atype = ARMORTYPE_HEAVY;
	if ( item_name == "Medium" ) atype = ARMORTYPE_MEDIUM;
	if ( item_name == "Light" ) atype = ARMORTYPE_LIGHT;
	if ( item_name == "Shard" ) atype = ARMORTYPE_SHARD;
		
	// Check if we NEED to pick up the armor, if the armor we are about to pick up is
	// less than the armor we have, we don't want to pick it up
	int currentArmorValue = player->GetArmorValue();
	
	if( atype == ARMORTYPE_SHARD )
		{
		if(currentArmorValue < MaxAmount() )
			{
			if((currentArmorValue + amount) > MaxAmount())
				setAmount(MaxAmount());
			else
				setAmount(currentArmorValue + amount);				
			}
		else
			return NULL;
		}
	else
		{
   	if( currentArmorValue >= amount )
	   	return NULL;
		}
	
	// Play pickup sound
   realname = GetRandomAlias( "snd_pickup" );
   if ( realname.length() > 1 )
		player->Sound( realname, CHAN_ITEM );

   // Cancel some events
	CancelEventsOfType( EV_Item_DropToFloor );
	CancelEventsOfType( EV_Item_Respawn );
   CancelEventsOfType( EV_FadeOut );

   // Hide the model
	setSolidType( SOLID_NOT );
	hideModel();

   // Respawn?
	if ( !Respawnable() )
		PostEvent( EV_Remove, FRAMETIME );
   else
		PostEvent( EV_Item_Respawn, RespawnTime() );

   // fire off any pickup_thread's
   if ( pickup_thread.length() )
      {
      ExecuteThread( pickup_thread );
      }

   // Give the player the Armor
	player->SetArmorValue(amount);

   return NULL; // This doesn't create any items
   }


