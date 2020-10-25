#include "shrapnelbomb.h"

Event EV_ShrapnelBomb_ShrapnelModel
   (
   "setshrapnelmodel",
	EV_DEFAULT,
	"s",
	"modelname",
	"The model of the shrapnel pieces that are spawned when the main bomb explodes"
	);

Event EV_ShrapnelBomb_ShrapnelCount
   (
	"setshrapnelcount",
	EV_DEFAULT,
	"i",
	"count",
	"The number of shrapnel pieces to spawn"
	);

CLASS_DECLARATION( Projectile, ShrapnelBomb, NULL )
   {
		{ &EV_ShrapnelBomb_ShrapnelCount, SetShrapnelCount	},
		{ &EV_ShrapnelBomb_ShrapnelModel,  SetShrapnelModel	},

		{ NULL, NULL	}
	};

ShrapnelBomb::ShrapnelBomb()   
   {
	if ( LoadingSavegame ) return;

	shrapnelCount = 5;
	}

void ShrapnelBomb::Explode
   (
   Event *ev
	)

	{
	Vector dir;

	//Spawn shrapnel
	for (int i = 0; i<shrapnelCount; i++ )
		{
		dir = origin;
		dir.normalize();
		
		//Adjust Vector
		dir += Vector ( G_CRandom( .5 ), G_CRandom( .5 ), G_CRandom( .5 ) );
		
		//Get a Random Yaw
		float yaw = G_Random(360);
		Vector angles = dir.toAngles();
		
		//Set the new Yaw
		angles[YAW] = yaw;
		
		//Set the new dir vector for the spawned shrapnel
		Vector newDir;
		angles.AngleVectors( &newDir );
				

		ProjectileAttack( this->origin, newDir, this, shrapnelModel, 1.0 , (velocity.length() / 2) );
		}

	velocity = Vector ( 0,0,0 );
	setMoveType( MOVETYPE_NONE );
	this->animate->RandomAnimate("explode");	

	PostEvent( EV_Remove, 1 );
	}

void ShrapnelBomb::SetShrapnelCount
   (
	Event *ev
	)
	
	{
	shrapnelCount = ev->GetInteger( 1 );
	}

void ShrapnelBomb::SetShrapnelModel
   (
	Event *ev
	)

	{
	shrapnelModel = ev->GetString( 1 );
	}