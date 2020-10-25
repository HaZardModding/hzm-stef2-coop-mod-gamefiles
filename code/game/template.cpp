//-----------------------------------------------------------------------------
//
//  $Logfile:: /FAKK2/code/game/template.cpp                                  $
// $Revision:: 2                                                              $
//   $Author:: Markd                                                          $
//     $Date:: 2/11/99 4:28p                                                  $
//
// Copyright (C) 1998 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /FAKK2/code/game/template.cpp                                       $
// 
// DESCRIPTION:
// This module explictly declares templates for the game code.
// Any templates you use must be explictly instantiated here.
//
// ZOID:  Templates have moved to template.cpp for explict template instantiation
// as it stands now, whatever cpp file that included a header would have instantiated
// this template and that results in multiple symbol errors on link.
// NOTE:  This worked under MSVC++ because MS's linker treats global symbols with the
// same size as "communal" and would happy link them.  It causes bloat tho.
//
// Oct 19th, 1998 Zoid
//

#include "g_local.h"		

#include "actor.h"			
#include "archive.h"		
#include "behavior.h"
#include "bspline.h"		
#include "camera.h"		
#include "class.h"			
//#include "console.h"		
#include "container.h"		
#include "doors.h"			
#include "entity.h"		
#include "gamescript.h"	
#include "gravpath.h"		
#include "listener.h"		
#include "navigate.h"		
#include "path.h"			
#include "scriptmaster.h"	
#include "scriptvariable.h"
#include "sentient.h"
//#include "spidermine.h"
//#include "surface.h"
#include "trigger.h"
#include "vehicle.h"
#include "weapon.h"
#include "worldspawn.h"

#if 0
template class Container<StateInfo *>;
template class Container<EntityPtr>;
template class Container<Class *>;
template class Container<pointer_fixup_t *>;
template class Container<Console *>;
template class Container<int>;
template class Container<str>;
template class Container<SpawnArg>;
template class Container<SpawnArgs>;
template class Container<SpawnArgGroup>;
template class Container<script_label_t *>;
template class Container<GameScript *>;
template class SafePtr<GravPathNode>;
template class Container<GravPathNodePtr>;
template class Container<GravPath *>;
template class Container<str *>;
template class Container<Response>;
template class Stack<PathNode *>;
template class SafePtr<PathNode>;
template class PathFinder<StandardMovement>;
template class Container<PathNodePtr>;
template class Container<float>;
template class Container<Vector>;
template class SafePtr<Path>;
template class SafePtr<ScriptThread>;
template class Container<ScriptThread *>;
template class Container<ScriptVariable *>;
template class SafePtr<ScriptVariable>;
template class SafePtr<Sentient>;
template class Container<Sentient *>;
template class SafePtr<Detonator>;
template class SafePtr<Mine>;
template class Container<MinePtr>;
template class Container<Surface *>;
template class Container<Entity *>;
template class Container<TargetList *>;

template class SafePtr<TouchField>;
template class SafePtr<Vehicle>;
template class SafePtr<Weapon>;
template class SafePtr<World>;
template class SafePtr<Entity>;
template class SafePtr<Door>;
template class SafePtr<Entity>;
template class SafePtr<Behavior>;
template class SafePtr<SplinePath>;
template class SafePtr<Camera>;
template class SafePtr<Class>;
template class Stack<ActorState *>;
template class PathFinder<FindCoverMovement>;
template class PathFinder<FindFleeMovement>;
template class PathFinder<FindEnemyMovement>;
#endif
