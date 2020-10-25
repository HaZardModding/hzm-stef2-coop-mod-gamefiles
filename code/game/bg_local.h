//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/bg_local.h                                     $
// $Revision:: 2                                                              $
//     $Date:: 8.01.01 10:43a                                                 $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/bg_local.h                                          $
// 
// 2     8.01.01 10:43a Ericf
// Changed slope walk angle
//
// 4     6/01/00 7:00p Markd
// added partial friciton for slippery surfaces
//
// 3     12/11/99 3:37p Markd
// q3a gold checkin, first time
//
// 2     9/10/99 3:08p Jimdose
// merge
//
// DESCRIPTION:
// bg_local.h -- local definitions for the bg (both games) files
//

#ifndef __BG_LOCAL_H__
#define __BG_LOCAL_H__

#ifdef __cplusplus
extern "C" {
#endif

#define	MIN_WALK_NORMAL	0.65		// can't walk on very steep slopes

#define	STEPSIZE		18

#define	JUMP_VELOCITY	270

#define	TIMER_LAND		130
#define	TIMER_GESTURE	(34*66+50)

#define	OVERCLIP		1.001

// all of the locals will be zeroed before each
// pmove, just to make damn sure we don't have
// any differences when running on client or server
typedef struct {
	vec3_t		forward, right, up;
	float		frametime;

	int			msec;

	qboolean	walking;
	qboolean	groundPlane;
	trace_t		groundTrace;

	float		impactSpeed;

	vec3_t		previous_origin;
	vec3_t		previous_velocity;
	int			previous_waterlevel;
} pml_t;

extern	pmove_t		*pm;
extern	pml_t		pml;

// movement parameters
extern	float	pm_stopspeed;
extern	float	pm_duckScale;
extern	float	pm_swimScale;
extern	float	pm_wadeScale;

extern	float	pm_accelerate;
extern	float	pm_airaccelerate;
extern	float	pm_wateraccelerate;
extern	float	pm_flyaccelerate;

extern	float	pm_friction;
extern	float	pm_waterfriction;
extern	float	pm_flightfriction;
extern	float	pm_slipperyfriction;

extern	int		c_pmove;

void PM_ClipVelocity( vec3_t in, vec3_t normal, vec3_t out, float overbounce );
void PM_AddTouchEnt( int entityNum );
void PM_AddEvent( int newEvent );

qboolean	PM_SlideMove( qboolean gravity );
void		PM_StepSlideMove( qboolean gravity );

#ifdef __cplusplus
	}
#endif

#endif /* !__BG_LOCAL_H__ */