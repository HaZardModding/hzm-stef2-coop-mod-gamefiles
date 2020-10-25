//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/debuglines.h                                   $
// $Revision:: 2                                                              $
//     $Date:: 12/11/00 9:34a                                                 $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/debuglines.h                                        $
// 
// 2     12/11/00 9:34a Steven
// Changed passing of most vectors to const reference.
//
// 4     3/15/00 2:04p Markd
// fixed up camera node system and added new debug oriented circle
//
// 3     3/02/00 6:04p Markd
// Added Debug Arrow and DebugHighlightFacet
//
// 2     1/06/00 11:08p Jimdose
// cleaning up unused code
//
// DESCRIPTION:
//

#ifndef __DEBUGLINES_H__
#define __DEBUGLINES_H__

#include "g_local.h"

void G_InitDebugLines( void );
void G_DebugLine( const Vector &start, const Vector &end, float r, float g, float b, float alpha );
void G_LineStipple( int factor, unsigned short pattern );
void G_LineWidth( float width );
void G_Color3f( float r, float g, float b	);
void G_Color3v( const Vector &color );
void G_Color4f( float r, float g,	float b,	float alpha	);
void G_Color3vf( const Vector &color, float alpha );
void G_BeginLine( void );
void G_Vertex( const Vector &v );
void G_EndLine( void );
void G_DebugBBox( const Vector &org, const Vector &mins, const Vector &maxs, float r, float g, float b, float alpha );
void G_DrawDebugNumber( const Vector &org, float number, float scale, float r, float g, float b, int precision = 0 );
void G_DebugCircle( const Vector &org, float radius, float r, float g, float b, float alpha, qboolean horizontal = false );
void G_DebugOrientedCircle( const Vector &org, float radius, float r, float g, float b, float alpha, Vector angles );
void G_DebugPyramid( const Vector &org, float radius, float r, float g, float b, float alpha );
void G_DrawCoordSystem( const Vector &pos, const Vector &f, const Vector &r, const Vector &u, int len );
void G_DebugArrow( const Vector &org, const Vector &dir, float length, float r, float g, float b, float alpha );
void G_DrawCSystem( void );

typedef enum
   {
   north,
   south,
   east,
   west,
   up,
   down
   } facet_t;

void G_DebugHighlightFacet( const Vector &org, const Vector &mins, const Vector &maxs, facet_t facet, float r, float g, float b, float alpha );

#endif /* !__DEBUGLINES_H__ */