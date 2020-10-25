//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/viewthing.h                                   $
// $Revision:: 14                                                             $
//   $Author:: Steven                                                         $
//     $Date:: 5/30/01 10:18a                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/viewthing.h                                        $
// 
// 14    5/30/01 10:18a Steven
// Added viewoffset.
// 
// 13    4.05.01 3:29p Kharward
// Added cvars to control randomization of viewspawns.
// 
// 12    3.05.01 2:03p Kharward
// Added support for tracking number of viewthings spawned.  Also added lots
// of comments.
// 
// 11    2.05.01 7:40p Kharward
// Added more view commands for objplacer menu.
// 
// 10    24.04.01 7:21p Kharward
// Added the viewshoot command.  You can now use the objplacer.cfg to place
// and manipulate objects through wtih the mouse.
// 
// 9     20.04.01 7:18p Kharward
// Added more functions to support viewspawning things on to a map and saving
// them to disk for import into Radiant.  Save, Drop, MakeStatic
// functionality, as well as fixing problems with translation and rotation
// functions.
// 
// 8     19.04.01 7:13p Kharward
// Added more functionality for view utility functions.  Now can place
// objects, translate them, copy them, etc.  Hooked up with objplacer.urc.
// 
// 7     17.04.01 5:06p Kharward
// Added support for more view commands, namely viewset and viewlist
// commands.  Corresponds to viewlist3.urc menu items.
// 
// 6     13.04.01 6:50p Kharward
// Added support for lifting objects spawned, turning off the autodrop, and
// working  with sets of tiki list files, all of which should be model/.lst
// files
// 
// 5     12.04.01 6:27p Kharward
// Added support for viewlistread, viewlistnext, and viewlistprev commands to
// enable viewlist.urc menu to work.
// 
// 4     4/12/01 2:03p Ericf
// Added a new SetAnim function
//
// 12    6/14/00 3:50p Markd
// Cleaned up more Intel Compiler warnings
//
// 11    6/14/00 2:17p Markd
// fixed compiler warnings for Intel Compiler
//
// 10    5/27/00 2:56p Markd
// Save games 2nd pass
//
// 9     5/24/00 3:14p Markd
// first phase of save/load games
//
// 8     5/02/00 7:18p Markd
// Bullet proofed viewspawned stuff
//
// 7     3/17/00 3:45p Markd
// made viewthing slider changes for setanim
//
// 6     2/11/00 2:24p Markd
// Added printtime support
//
// 5     1/13/00 11:45a Markd
// Fixed viewspawn bug with surfaces, now I save them off and then restore
// them on each animation
//
// 4     12/17/99 8:27p Jimdose
// got rid of unused vars and functions
//
// 3     10/02/99 6:51p Markd
// Put in backend work for event documentation and fixed a lot of event
// documentation bugs
//
// 2     9/22/99 4:48p Markd
// fixed more G_GetEntity, G_FindClass and G_GetNextEntity bugs
//
// 1     9/10/99 10:55a Jimdose
//
// 1     9/08/99 3:16p Aldie
//
// 3     7/07/99 12:25p Markd
//
// 2     6/23/99 3:57p Markd
// Added viewthing support
//
// 1     6/23/99 11:00a Markd
//
// 20    10/08/98 12:35a Jimdose
// Added archive functions
//
// 19    10/04/98 11:11p Jimdose
// Made current_viewthing part of ViewMaster
//
// 18    9/09/98 5:57p Markd
// added viewautoanimate
//
// 17    7/10/98 6:20a Jimdose
// Added viewpitch, viewroll, and viewangles events
//
// 16    4/08/98 12:21a Jimdose
// Added viewdeleteall command
//
// 15    3/30/98 10:00a Markd
// Added nextskin and prevskin events
//
// 14    3/27/98 7:00p Markd
// Added new viewthing commands
//
// 13    3/23/98 1:33p Jimdose
// Revamped event and command system
//
// 12    3/12/98 9:49a Markd
// Added YAW event
//
// 11    3/11/98 11:30a Markd
// Added events and variable
//
// 10    3/07/98 2:05p Markd
// Fixed Viewthing
//
// 9     3/05/98 6:48p Markd
//
// 8     3/05/98 11:03a Markd
// Updated for Q2
//
// 6     10/28/97 6:55p Markd
// made initialorigin a public variable instead of a private one.
//
// 5     10/27/97 2:59p Jimdose
// Removed dependency on quakedef.h
//
// 4     10/23/97 6:37p Markd
// Added initialorigin stuff
//
// 3     10/01/97 6:37p Markd
// Added viewthing commands (ToggleAnimate and ChangeAnimation)
//
// 2     10/01/97 2:47p Markd
// working on wander AI
//
// 1     10/01/97 11:24a Markd
// new viewthing actor code
//
// DESCRIPTION:
// Actor code for the viewthing.
//

#ifndef __VIEWTHING_H__
#define __VIEWTHING_H__

#include "animate.h"

// forward declaration
class Viewthing ;

class ViewMaster : public Listener
	{
	public:
      CLASS_PROTOTYPE( ViewMaster );

		EntityPtr current_viewthing;
		Container<str>  _modelNamesArray ;
		Container<str>  _setNamesArray ;
		Vector          _lastBaseOrigin ;
		bool            _spawnAtLastItemsOrigin ;
		int             _currentSetIdx ;
		int             _numberOfModelsInSet ;
		int             _numberOfSets ;

		ViewMaster();
		~ViewMaster();
		
		void LoadSet ( Event *ev );
		void NextModelInSet ( Event *ev );
		void PrevModelInSet ( Event *ev );
		void JumpToModel    ( Event *ev );
		void PullToCamera   ( Event *ev );
		void SetXTranslation( Event *ev );
		void SetYTranslation( Event *ev );
		void SetZTranslation( Event *ev );
		void XTranslate     ( Event *ev );
		void YTranslate     ( Event *ev );
		void ZTranslate     ( Event *ev );
		void Offset		     ( Event *ev );
		void Copy           ( Event *ev );
		void Save           ( Event *ev );
		void Shoot          ( Event *ev );
		void ResetOrigin    ( Event *ev );
		void Delete         ( Event *ev );

		void LoadModelsInSet ( const str& setFilename);  // Loads up list of tikis in .lst files
		void spawnAtPosition(const str& modelName, const Vector& pos);
		void DeleteCurrentViewthing();
		void DisplayCurrentModelInSet(bool spawnAtLastOrigin=true);
		void ToggleDrop( Event *ev );
		void Spawn( Event *ev );

		// These iterate through models already spawned
		void Next( Event *ev );
		void Prev( Event *ev );

		// Additional functions
		void Init( void );
		void DeleteAll( Event *ev );
		void SetModelEvent( Event *ev );
		void PassEvent( Event *ev );
		virtual void Archive( Archiver &arc );

	protected:
		void _resetOrigin();
		void _setToPosition(Vector& pos);
		void _selectPrevious();
		void _selectNext();
		void _updateViewthingCounts(int countAdjustment=0); // supports manipulating final count--see notes in .cpp
		void _randomizeViewthing(Viewthing* viewthingPtr);  // randomizes scale and/or rotation of this viewthing
	};

inline void ViewMaster::Archive
	(
	Archiver &arc
	)

   {
   Listener::Archive( arc );

   arc.ArchiveSafePointer( &current_viewthing );
   }


// The DLL Global ViewMaster singleton
extern ViewMaster Viewmodel;



//-----------------------------------------------------------
// Class Viewthing
//      A viewspawned tiki model in the world. This class
//      provides a shell for viewing any tiki model in the
//      game.  The model can be animated and manipulated, but
//      does not act like a normally spawned object (it doesn't
//      execute scripts or AI.
//-----------------------------------------------------------
class Viewthing : public Entity
	{
	public:
      CLASS_PROTOTYPE( Viewthing );

		int      animstate;
		int      frame;
		int      lastframe;
		Vector   baseorigin;
		byte     origSurfaces[MAX_MODEL_SURFACES];
		int		 current_morph;
		qboolean _static ;
		qboolean _selected ;
		int      _pulseCount ;
						Viewthing();
		void			UpdateCvars( qboolean quiet = false );
		void            SetSelected( qboolean state = false );
		void			SetAnim           ( int num );
		void            Delete();

		void			PrintTime         ( Event *ev );
		void			ThinkEvent        ( Event *ev );
		void			LastFrameEvent    ( Event *ev );
		void			ToggleAnimateEvent( Event *ev );
		void			SetModelEvent     ( Event *ev );
		void			NextFrameEvent    ( Event *ev );
		void			PrevFrameEvent    ( Event *ev );
		void			NextAnimEvent     ( Event *ev );
		void			PrevAnimEvent     ( Event *ev );
		void			ScaleUpEvent      ( Event *ev );
		void			ScaleDownEvent    ( Event *ev );
		void			SetScaleEvent     ( Event *ev );
		void			SetYawEvent       ( Event *ev );
		void			SetPitchEvent     ( Event *ev );
		void			SetRollEvent      ( Event *ev );
		void			SetAnglesEvent    ( Event *ev );
		void            SetStatic         ( Event *ev );
		void			AttachModel       ( Event *ev );
		void			Delete            ( Event *ev );
		void			DetachAll         ( Event *ev );
		void			ChangeOrigin      ( Event *ev );
		void			SaveSurfaces      ( Event *ev );
		void			SetAnim           ( Event *ev );
		void            ChangeRollEvent   ( Event *ev );
		void            ChangePitchEvent  ( Event *ev );
		void            ChangeYawEvent    ( Event *ev );
		void			NextMorph         ( Event *ev );
		void			PrevMorph         ( Event *ev );
		void			Morph             ( Event *ev );
		void			Unmorph           ( Event *ev );
		void            Flash             ( Event *ev );

		virtual void	Archive( Archiver &arc );
	};

inline void Viewthing::Archive
	(
	Archiver &arc
	)

   {
   Entity::Archive( arc );
	animate->Archive( arc );

   arc.ArchiveInteger( &animstate );
   arc.ArchiveInteger( &frame );
   arc.ArchiveInteger( &lastframe );
   arc.ArchiveVector( &baseorigin );
   arc.ArchiveRaw( origSurfaces, sizeof( origSurfaces ) );
	arc.ArchiveInteger( &current_morph );
   }

#endif /* viewthing.h */