#include "powerups.h"
#include "player.h"

CLASS_DECLARATION( Item, PowerupEntity, NULL )
	{
		{ NULL, NULL }
	};

PowerupEntity::PowerupEntity
   (
   )

	{
   if ( LoadingSavegame )
      {
      // all data will be setup by the archive function
      return;
      }
   setName( "UnknownPowerup" );
   amount = 30;
	}

Item *PowerupEntity::ItemPickup
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

   // Give the player the powerup
	Event ev;
	powerup_t ptype = POWERUP_NONE;

	if ( item_name == "Speed" ) ptype = POWERUP_SPEED;
	if ( item_name == "Stealth" ) ptype = POWERUP_STEALTH;
	if ( item_name == "Protection" ) ptype = POWERUP_PROTECTION;
	if ( item_name == "Flight" ) ptype = POWERUP_FLIGHT;
	if ( item_name == "Strength" ) ptype = POWERUP_STRENGTH;
	if ( item_name == "Accuracy" ) ptype = POWERUP_ACCURACY;

	ev.AddInteger(amount);
	ev.AddInteger(ptype);
	player->SetPowerupTimer( &ev );

   return NULL; // This doesn't create any items
   }
