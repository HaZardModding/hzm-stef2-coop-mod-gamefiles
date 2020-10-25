//-----------------------------------------------------------------------------
//
//  $Logfile:: /fakk2_code/fakk2_new/game/body.h                             $
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
// $Log:: /fakk2_code/fakk2_new/game/body.h                                  $
//
// 2     10/02/00 5:38p Aldie
// Added gibbing to multiplayer stuff
//
// DESCRIPTION:
// Dead bodies

#ifndef __BODY_H__
#define __BODY_H__

//=============================================================
//class Body
//=============================================================
class Body : public Entity
   {
   private:
      void Damage( Event *ev );

   public:
      CLASS_PROTOTYPE( Body );
      Body();
   };

#endif //__BODY_H__