//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/vehicle.h                                      $
// $Revision:: 13                                                             $
//   $Author:: Sketcher                                                       $
//     $Date:: 8/08/01 9:35a                                                  $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/vehicle.h                                           $
// 
// 13    8/08/01 9:35a Sketcher
// Added an event to make the player use a specified entity, and fixed getting
// on and off the stupid horse
// 
// 12    8/07/01 8:52a Sketcher
// More vehicle work
// 
// 11    8/02/01 12:03p Sketcher
// Trying to get vehicles to work better.  Still need to fix prediction
// 
// 10    7/27/01 5:45p Sketcher
// Switched from Enum to a strategy pattern for movement handling
// 
// 9     7/27/01 8:30a Sketcher
// The view on the horse vehicle is now locked ( but hard coded -- will change
// that soon ) Also, prediction needs to be fixed to handle the vehicle stuff
// 
// 8     7/26/01 1:47p Sketcher
// Added the ability for the horsevehicle to follow waypoints
// 
// 7     7/26/01 10:20a Sketcher
// More Vehicle Modifications... What a surprise
// 
// 5     7/25/01 2:18p Sketcher
// More Vehicle Modifications
// 
// 4     7/24/01 4:41p Sketcher
// More Vehicle Changes
// 
// 3     7/23/01 2:37p Sketcher
// First Pass at horse vehicle.  Still needs lots of cleanup
// 
// 2     12/11/00 9:36a Steven
// Changed passing of most vectors to const reference.
//
// 4     6/14/00 2:17p Markd
// fixed compiler warnings for Intel Compiler
//
// 3     5/27/00 2:56p Markd
// Save games 2nd pass
//
// 2     5/24/00 3:14p Markd
// first phase of save/load games
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// DESCRIPTION:
// Script controlled vehicles.
//

class Vehicle;
class HorseVehicle;

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "g_local.h"
#include "entity.h"
#include "sentient.h"
#include "scriptslave.h"
#include "waypoints.h"

extern Event EV_Vehicle_Enter;
extern Event EV_Vehicle_Exit;
extern Event EV_Vehicle_Drivable;
extern Event EV_Vehicle_UnDrivable;
extern Event EV_Vehicle_Lock;
extern Event EV_Vehicle_UnLock;
extern Event EV_Vehicle_SeatAnglesOffset;
extern Event EV_Vehicle_SeatOffset;
extern Event EV_Vehicle_DriverAnimation;
extern Event EV_Vehicle_SetWeapon;
extern Event EV_Vehicle_ShowWeapon;
extern Event EV_Vehicle_SetSpeed;
extern Event EV_Vehicle_SetTurnRate;

extern Event EV_FollowPath_SetWayPointName;

typedef enum
	{
	CROSSHAIR_MODE_STRAIGHT,
	CROSSHAIR_MODE_RIGHT,
	CROSSHAIR_MODE_LEFT
	} crosshairMode_t;

typedef enum
	{
	JUMPMODE_START,
	JUMPMODE_HOLD,
	JUMPMODE_LAND,
	JUMPMODE_DONE,
	} jumpMode_t;

typedef enum
	{
	DUCKMODE_START,
	DUCKMODE_HOLD,
	DUCKMODE_FINISH,
	DUCKMODE_DONE,
	} duckMode_t;

//================================================
// VehicleMoveMode Classes
//
// The move mode classes provide a way for all new
// vehicles to easily change they're movement 
// strategy
//=================================================
class VehicleMoveMode : public Listener
	{
	public:
			CLASS_PROTOTYPE( VehicleMoveMode );
			VehicleMoveMode ();

		virtual void Move( Vehicle *vehicle );	
		virtual void HandleEvent( Event *ev );
	};

class HVMoveMode_Standard : public VehicleMoveMode
	{
	public:
			  HVMoveMode_Standard ();
		void Move( Vehicle *vehicle );
	};

class HVMoveMode_Strafe  : public VehicleMoveMode
	{
	public:
			  HVMoveMode_Strafe ();
		void Move( Vehicle *vehicle );
	};

class HVMoveMode_Locked : public VehicleMoveMode
	{
	public:
			  HVMoveMode_Locked ();
		void Move( Vehicle *vehicle );

	};

class HVMoveMode_FollowPath : public VehicleMoveMode
	{
	public:
		CLASS_PROTOTYPE( HVMoveMode_FollowPath );

			  HVMoveMode_FollowPath ();
		void Move( Vehicle *vehicle );
	   void SetWaypointName ( Event *ev );
		void HandleEvent ( Event *ev );

	private:
		void     _SetWayPoint( const str& name );
		void     _RunThread( const str &thread_name );

	private:
		WayPointNode*	  _currentWaypoint;
		str				  _currentWaypointName;
		qboolean			  _pathcompleted;	

	};


//================================================
// Old Vehicle Base class -- Needs to be changed
//================================================
class VehicleBase : public ScriptModel
	{
	public:
		VehicleBase *vlink;
		Vector		 offset;

      CLASS_PROTOTYPE( VehicleBase );

		VehicleBase();
      virtual void Archive(	Archiver &arc );
	};

inline void VehicleBase::Archive
	(
	Archiver &arc
	)
   {
   ScriptModel::Archive( arc );

   arc.ArchiveObjectPointer( ( Class ** )&vlink );
   arc.ArchiveVector( &offset );
   }


/*QUAKED script_wheelsback (0 .5 .8) ?
*/
class BackWheels : public VehicleBase
	{
	public:
      CLASS_PROTOTYPE( BackWheels );
	};

/*QUAKED script_wheelsfront (0 .5 .8) ?
*/
class FrontWheels : public VehicleBase
	{
	public:
      CLASS_PROTOTYPE( FrontWheels );
	};


class Vehicle : public VehicleBase
	{
	public:
		float					turnimpulse;
		float					moveimpulse;
		float					jumpimpulse;
		float					currentspeed;

		Vector           _DriverBBoxMaxs;
		Vector           _DriverBBoxMins;
		Vector           _originalBBoxMaxs;
		Vector           _originalBBoxMins;

	protected:
		SentientPtr			driver;
		SentientPtr			lastdriver;
		float					maxturnrate;
		
		float					turnangle;
		
		float					speed;
      float             conesize;
      float             maxtracedist;
      str               weaponName;
      str               driveranim;
      Vector            last_origin;
      Vector            seatangles;
      Vector            seatoffset;
      Vector            driveroffset;
      Vector            Corners[4];

      qboolean          drivable;
      qboolean          locked;
      qboolean          hasweapon;
      qboolean          showweapon;
      qboolean          steerinplace;
      qboolean          jumpable;


		//Test stuff
		float             usetime;

      virtual void      WorldEffects( void );
      virtual void      CheckWater( void );
		virtual void		DriverUse( Event *ev );
		virtual void		VehicleStart( Event *ev );
		virtual void		VehicleTouched( Event *ev );
		virtual void		VehicleBlocked( Event *ev );
		virtual void		Postthink( void );
		virtual void		Drivable( Event *ev );
		virtual void		UnDrivable( Event *ev );
		virtual void		Jumpable( Event *ev );
		virtual void		SeatAnglesOffset( Event *ev );
		virtual void		SeatOffset( Event *ev );
      virtual void      SetDriverAngles( const Vector &angles );
		virtual void		Lock( Event *ev );
		virtual void		UnLock( Event *ev );
		virtual void		SetWeapon( Event *ev );
		virtual void		ShowWeaponEvent( Event *ev );
		virtual void		DriverAnimation( Event *ev );
		virtual void		SetSpeed( Event *ev );
		virtual void		SetTurnRate( Event *ev );
		virtual void		SteerInPlace( Event *ev );
		

	public:

      CLASS_PROTOTYPE( Vehicle );

								Vehicle();

		virtual qboolean	Drive( usercmd_t *ucmd );
		virtual qboolean	HasWeapon( void );
		virtual qboolean	ShowWeapon( void );
      Sentient				*Driver( void );
		virtual qboolean	IsDrivable( void );
      virtual void      Archive(	Archiver &arc );
		virtual void      HandleEvent( Event *ev );
	};

inline void Vehicle::Archive
	(
	Archiver &arc
	)
   {
   VehicleBase::Archive( arc );

   arc.ArchiveSafePointer( &driver );
   arc.ArchiveSafePointer( &lastdriver );
   arc.ArchiveFloat( &maxturnrate );
   arc.ArchiveFloat( &currentspeed );
   arc.ArchiveFloat( &turnangle );
   arc.ArchiveFloat( &turnimpulse );
   arc.ArchiveFloat( &moveimpulse );
   arc.ArchiveFloat( &jumpimpulse );
   arc.ArchiveFloat( &speed );
   arc.ArchiveFloat( &conesize );
   arc.ArchiveFloat( &maxtracedist );
   arc.ArchiveString( &weaponName );
   arc.ArchiveString( &driveranim );
   arc.ArchiveVector( &last_origin );
   arc.ArchiveVector( &seatangles );
   arc.ArchiveVector( &seatoffset );
   arc.ArchiveVector( &driveroffset );

   arc.ArchiveVector( &Corners[ 0 ] );
   arc.ArchiveVector( &Corners[ 1 ] );
   arc.ArchiveVector( &Corners[ 2 ] );
   arc.ArchiveVector( &Corners[ 3 ] );

   arc.ArchiveBoolean( &drivable );
   arc.ArchiveBoolean( &locked );
   arc.ArchiveBoolean( &hasweapon );
   arc.ArchiveBoolean( &showweapon );
   arc.ArchiveBoolean( &steerinplace );
   arc.ArchiveBoolean( &jumpable );
   }

class DrivableVehicle : public Vehicle
	{
	public:

      CLASS_PROTOTYPE( DrivableVehicle );

								DrivableVehicle();

		virtual void		Killed( Event *ev );
	};


//=================================================
// Horse Vehicle
// A lot of this functionality needs to be redone
// in a cleaner vehicle base class
//=================================================

class HorseVehicle : public DrivableVehicle
	{
   public:

		CLASS_PROTOTYPE( HorseVehicle );
   						  HorseVehicle();							 
							 ~HorseVehicle();
		//Virtual Functions
		qboolean	Drive( usercmd_t *ucmd );
		void		Postthink( void );
		void		DriverUse( Event *ev );
		
		//Other Functions
		void     SetVehicleMoveMode( Event *ev );
		void     SetForcedForwardSpeed ( Event *ev );
		void     SetWaypointName( Event *ev );
		void     SetMinYawThreshold( Event *ev );
		void     SetMaxYawThreshold( Event *ev );
		void     SetMinPitchThreshold( Event *ev );
		void     SetMaxPitchThreshold( Event *ev );
		void     PassToMoveMode( Event *ev );
		void     AnimDone( Event *ev );
		void     DriverAnimDone ( Event *ev );
		void     HandleEvent ( Event *ev );



	private:
		void     _SetSpeed( Event *ev );
		void     _CalculateOrientation();		
		void     _PlayMovementSound();
		void     _AnimateVehicle(const str &anim, qboolean useEvent = false );
		void     _AnimateDriver( const str &anim, qboolean useEvent = false );
		void     _PositionDriverModel();
		void     _InitializeJump();
		void     _HandleJump();
		void     _InitializeDuck();		
		void     _HandleDuck();
		void     _SetMoveMode( const str &modeName );
		void     _SetCrossHairMode();
		void     _SetBaseYaw();
		
		
	
	//Member Vars
	private:		
		
		float            _baseYaw;

		float				  _driverYaw;
		float				  _lastYaw;
		float				  _minYawThreshold;
		float				  _maxYawThreshold;
		
		float				  _driverPitch;
		float				  _lastPitch;
		float				  _minPitchThreshold;
		float				  _maxPitchThreshold;

		float				  _forcedForwardSpeed;
		float				  _jumptime;
		
		qboolean			  _jumpflag;
		qboolean			  _jumped;
		float				  _jumpSpeed;

		qboolean         _animDone;
		qboolean         _driverAnimDone;

		float            _holdtime;
		jumpMode_t       _jumpmode;
		duckMode_t       _duckmode;
	
		qboolean         _duckflag;
		qboolean         _ducked;
		qboolean         _duckheld;

		crosshairMode_t  _currentCrosshairMode;
		crosshairMode_t  _newCrosshairMode;


		
		VehicleMoveMode* _moveMode;

	};



typedef SafePtr<Vehicle> VehiclePtr;

#endif /* vehicle.h */