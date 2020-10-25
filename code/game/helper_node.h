//-----------------------------------------------------------------------------
//
//  $Logfile:: /Code/DLLs/game/helper_node.h                                  $
// $Revision:: 12                                                             $
//   $Author:: Sketcher                                                       $
//     $Date:: 3/28/02 7:22a                                                  $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /Code/DLLs/game/helper_node.h                                      $
// 
// 12    3/28/02 7:22a Sketcher
// Added Priority measure to Helper Nodes and moved previously global
// functions into the class as static functions
// 
// 11    3/20/02 1:53p Sketcher
// Added ActivationRange and associated functionality
// 
// 10    3/19/02 2:35p Sketcher
// HelperNodes now inherits from Listener instead of entity, so it shouldn't
// count against the edict count
// 
// 9     3/15/02 9:23p Sketcher
// Added Node Descriptor Stuff
// 
// 8     3/14/02 10:48a Sketcher
// Modifications in preparation of release to the level designers
// 
// 7     3/13/02 1:56p Sketcher
// Modifications for entry and exit threads
// 
// 6     3/12/02 11:07p Sketcher
// Added and entry and exit thread, instead of a single thread
// 
// 5     3/10/02 12:55p Steven
// Save game stuff.
// 
// 4     2/25/02 1:18p Sketcher
// Additional Global Functions
// 
// 3     2/21/02 1:18p Sketcher
// Implementation of HelperNodes
// 
// 2     2/05/02 11:08a Sketcher
// Initial checkin of some shit... Not used yet
// 
// 7     12/07/01 8:53a Sketcher
// Added new waypoint types
// 
// 6     11/05/01 8:35a Sketcher
// Added Patrol Waypoint Nodes
// 
// 5     10/15/01 2:19p Steven
// Added sourcesafe header.
//
// DESCRIPTION:

//
// Forward Declarations
//
class HelperNode;
class HelperNodeController;

// This is declared here, because we reference class actor, 
// but we can't just #include "actor.h" because of
// cyclical reference problem revolving around the
// the typedef'd HelperNodePtr.
class Actor;


#ifndef __HELPER_NODE_H__
#define __HELPER_NODE_H__  

#include "entity.h"
typedef SafePtr<HelperNode> HelperNodePtr;

// Spawn Flag Masks
#define NODETYPE_FLEE		(1<<0)
#define NODETYPE_WORK      (1<<1)
#define NODETYPE_ANIM      (1<<2)
#define NODETYPE_COVER     (1<<3)
#define NODETYPE_PATROL    (1<<4)
#define NODETYPE_SNIPER    (1<<5)
#define NODETYPE_CUSTOM    (1<<6)
#define NODETYPE_COMBAT    (1<<7)

//Enums
typedef enum
   {
   COVER_TYPE_NONE,
   COVER_TYPE_CRATE,
   COVER_TYPE_WALL,
   COVER_TYPE_TOTAL_NUMBER
   } CoverType_t;

typedef enum
   {
   COVER_DIRECTION_NONE,
   COVER_DIRECTION_LEFT,
   COVER_DIRECTION_RIGHT,
   COVER_DIRECTION_ALL,
   COVER_DIRECTION_TOTAL_NUMBER
   } CoverDirection_t;

typedef enum
   {
   DESCRIPTOR_NONE,
   DESCRIPTOR_CORRIDOR,
   DESCRIPTOR_TOTAL_NUMBER
   } NodeDescriptorType_t;

// Created by the level to handle the archiving of HelperNodes
class HelperNodeController : public Entity
   {
   public:
      virtual void               Archive( Archiver &arc );
   };


class HelperNode : public Listener
  {
	public:
		CLASS_PROTOTYPE( HelperNode );
							  HelperNode();
							 ~HelperNode();

      // Core Functionality
      void             SetTarget         ( Event *ev );
      void             SetTargetName     ( Event *ev );
      void             SetAngle          ( Event *ev );
      void             SetOrigin         ( Event *ev );

      void             SetTarget         ( const str &name   );
      void             SetTargetName     ( const str &name   );
      void             SetAngle          ( const Vector &ang );
      void             SetOrigin         ( const Vector &pos );


		//Event Interface
	  virtual void     SetEntryThread     ( Event *ev );				
      virtual void     SetExitThread      ( Event *ev );				
      virtual void     SetAnim            ( Event *ev );
      virtual void     SetAnimTarget      ( Event *ev );
      virtual void     SetKillTarget      ( Event *ev );
      virtual void     SetCustomType      ( Event *ev );
      virtual void     SetID              ( Event *ev );
      virtual void     SetAnimCount       ( Event *ev );
      virtual void     SetMaxKills        ( Event *ev );
      virtual void     SetWait            ( Event *ev );
      virtual void     SetWaitRandom      ( Event *ev );
      virtual void     SetMinHealth       ( Event *ev );
      virtual void     SetMinEnemyRange   ( Event *ev );
	  virtual void     SetActivationRange ( Event *ev );
      virtual void     SetFlags           ( Event *ev );
      virtual void     SetAnimActive      ( Event *ev );
      virtual void     SetCoverActive     ( Event *ev );
      virtual void     SetCoverType       ( Event *ev );
      virtual void     SetCoverDir        ( Event *ev );
      virtual void     SetWaitForAnim     ( Event *ev );
      virtual void     SetCriticalChange  ( Event *ev );
      virtual void     SetDescriptor      ( Event *ev );   
	  virtual void     SetPriority        ( Event *ev );
      

      //Mutators      
      virtual void     SetEntryThread    ( const str& thread );
      virtual void     SetExitThread     ( const str& thread );
      virtual void     SetAnim           ( const str& anim );
      virtual void     SetAnimTarget     ( const str& animtarget );
      virtual void     SetKillTarget     ( const str& killtarget );
      virtual void     SetCustomType     ( const str& customtype );
      virtual void     SetID             ( int ID );
      virtual void     SetAnimCount      ( int animcount );
      virtual void     SetMaxKills       ( int maxkills );
      virtual void     SetWait           ( float wait );
      virtual void     SetWaitRandom     ( float wait );
      virtual void     SetMinHealth      ( float health );
      virtual void     SetMinEnemyRange  ( float range );
	  virtual void     SetActivationRange ( float range );
      virtual void     SetFlags          ( unsigned int flags );
      virtual void     SetAnimActive     ( qboolean animactive );
      virtual void     SetCoverActive    ( qboolean coveractive );
      virtual void     SetWaitForAnim    ( qboolean wait );
      virtual void     SetCoverType      ( CoverType_t covertype );
      virtual void     SetCoverDir       ( CoverDirection_t coverdir );
      virtual void     SetCriticalChange ( qboolean change );
      virtual void     SetDescriptor     ( NodeDescriptorType_t descriptor );
	  virtual void     SetPriority       ( float priority );
      
      

      //Accessors
      const str&       GetEntryThread();
      const str&       GetExitThread();
      const str&       GetAnim();
      const str&       GetAnimTarget();
      const str&       GetKillTarget();
      const str&       GetCustomType();

      int              GetID();
      int              GetAnimCount();
      int              GetMaxKills();

      float            GetWaitTime();
      float            GetMinHealth();
      float            GetMinEnemyRange();
	  float            GetActivationRange();
	  float            GetPriority();

      CoverType_t      GetCoverType();
      CoverDirection_t GetCoverDirection();
      NodeDescriptorType_t GetDescriptor();
      
      //Queries
      qboolean         isOfType( unsigned int mask );
      qboolean         isAnimActive();
      qboolean         isCoverActive();
      qboolean         isWaitRandom();
      qboolean         isWaitForAnim();
      qboolean         isChanged();
	  qboolean         isReserved();

      //Utility
      void             RunEntryThread();
      void             RunExitThread();
	  void             ReserveNode();
	  void             UnreserveNode();
      
      //For Convience
      Vector            origin;
		str					target;
		str					targetname;
      Vector            angles;
  
		//Static Functions
		static HelperNode* FindClosestHelperNode( Actor &self , int mask , float  maxDist );	
		static HelperNode* FindClosestHelperNode( Actor &self , const str& customType , float maxDist );
		static HelperNode* FindHighestPriorityNode( Actor& self , const str& customType );
		static HelperNode* FindHighestPriorityNode( Actor& self, const str& customType , const str& targetedTo );
		static HelperNode* GetTargetedHelperNode( const str& targetName );
		int GetHelperNodeMask( const str& type );		
		
	  // Archiving
	  void     Archive( Archiver &arc );

   protected:
      void                 _init();
      CoverType_t          _CoverTypeForString( const str& covertype );
      CoverDirection_t     _CoverDirectionForString( const str& coverdir );
      NodeDescriptorType_t _DescriptorForString( const str& descriptor );
      
			
	private:
      str                  _entryThread;
      str                  _exitThread;
      str                  _anim;
      str                  _animtarget;
      str                  _killtarget;
      str                  _customType;

      int                  _id;
      int                  _animcount;
      int                  _maxkills;

      qboolean             _animactive;
      qboolean             _coveractive;
      qboolean             _waitrandom;
      qboolean             _waitforanim;
      qboolean             _criticalchange;
	  bool                 _reserved;
 
      float                _waittime;
      float                _minhealth;
      float                _minenemyrange;
	  float                _activationRange;
	  float                _priority;
      
      CoverType_t          _covertype;
      CoverDirection_t     _coverdir;

      unsigned int         _nodeflags;  
      NodeDescriptorType_t _descriptor;      
		

  };


inline void HelperNode::ReserveNode()
	{
	_reserved = true;
	}

inline void HelperNode::UnreserveNode()
	{
	_reserved = false;
	}

inline void HelperNode::Archive( Archiver &arc )
{
	arc.ArchiveString	( &_entryThread	);
	arc.ArchiveString	( &_exitThread	);
	arc.ArchiveString	( &_anim );
	arc.ArchiveString	( &_animtarget );
	arc.ArchiveString	( &_killtarget );
	arc.ArchiveString	( &_customType );

	arc.ArchiveInteger	( &_id );
	arc.ArchiveInteger	( &_animcount );
	arc.ArchiveInteger	( &_maxkills );

	arc.ArchiveBoolean	( &_animactive );
	arc.ArchiveBoolean	( &_coveractive );
	arc.ArchiveBoolean	( &_waitrandom );
	arc.ArchiveBoolean	( &_waitforanim );
	arc.ArchiveBoolean	( &_criticalchange );
	arc.ArchiveBool		( &_reserved );

	arc.ArchiveFloat	( &_waittime );
	arc.ArchiveFloat	( &_minhealth );
	arc.ArchiveFloat	( &_minenemyrange );
	arc.ArchiveFloat	( &_activationRange );
	arc.ArchiveFloat    ( &_priority  );

	ArchiveEnum( _covertype,  CoverType_t          );
	ArchiveEnum( _coverdir,   CoverDirection_t     );
	ArchiveEnum( _descriptor, NodeDescriptorType_t );

	arc.ArchiveVector	( &origin     );
	arc.ArchiveVector	( &angles     );
	arc.ArchiveString	( &target     );
	arc.ArchiveString	( &targetname );
	arc.ArchiveUnsigned	( &_nodeflags  );
   
}



// Global Utility Functions
void AddHelperNodeToList( HelperNode* node );
void RemoveHelperNodeFromList( HelperNode* node );



#endif /* __HELPER_NODE_H__ */