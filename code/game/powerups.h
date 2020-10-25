#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "g_local.h"
#include "item.h"

class PowerupEntity : public Item
	{
	public:
      CLASS_PROTOTYPE( PowerupEntity );

	                  PowerupEntity();
      virtual Item   *ItemPickup( Entity *other, qboolean add_to_inventory );
	};

#endif /* Powerup.h */