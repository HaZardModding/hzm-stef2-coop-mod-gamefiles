//-----------------------------------------------------------------------------
//
//  $Logfile:: /fakk2_code/fakk2_new/game/body.cpp                           $
// $Revision:: 2                                                              $
//   $Author:: Aldie                                                          $
//     $Date:: 10/02/00 5:38p                                                 $
//
// Copyright (C) 2000 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /fakk2_code/fakk2_new/game/body.cpp                                $
//
// 2     10/02/00 5:38p Aldie
// Added gibbing to multiplayer stuff
//
// DESCRIPTION:
// Dead bodies

#include "g_local.h"
#include "animate.h"
#include "gibs.h"
#include "body.h"

CLASS_DECLARATION( Entity, Body, NULL )
   {
      { &EV_Damage,    Damage },
      { NULL,          NULL }
   };

//=============================================================
//Body::Body
//=============================================================
Body::Body
   (
   )

   {
   takedamage         = DAMAGE_YES;
	edict->s.eType     = ET_MODELANIM;
   health             = 10;
   edict->clipmask    = MASK_DEADSOLID;
   edict->svflags    |= SVF_DEADMONSTER;

   setSolidType( SOLID_BBOX );
   setContents( CONTENTS_CORPSE );
   setMoveType( MOVETYPE_NONE );

   PostEvent( EV_DeathSinkStart, 3 );

	animate = new Animate( this );
   }

//=============================================================
//Body::Damage
//=============================================================
void Body::Damage
   (
   Event *ev
   )

   {
	str gib_name;
	int number_of_gibs;
	float scale;
	Entity *ent;
	str real_gib_name;

	if ( !com_blood->integer )
		return;

	gib_name       = "fx_rgib";
   number_of_gibs = 5;
   scale          = 1.2;

	// Spawn the gibs
	real_gib_name = gib_name;
	real_gib_name += number_of_gibs;
	real_gib_name += ".tik";

	ent = new Entity( ENTITY_CREATE_FLAG_ANIMATE );
	ent->setModel( real_gib_name.c_str() );
	ent->setScale( scale );
	ent->setOrigin( centroid );
	ent->animate->RandomAnimate( "idle" );
	ent->PostEvent( EV_Remove, 1 );

	Sound( "snd_decap", CHAN_BODY, 1, 300 );

   this->hideModel();
   this->takedamage = DAMAGE_NO;
   }
