//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/bg_pmove.c                                     $
// $Revision:: 26                                                             $
//     $Date:: 8/02/01 3:01p                                                  $
//
// Copyright (C) 1999 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/bg_pmove.c                                          $
// 
// 26    8/02/01 3:01p Sketcher
// More work on PM_VehicleMove
// 
// 25    8/02/01 2:51p Sketcher
// More Vehicle Prediction Work... Oh how I hate it.
// 
// 24    8/02/01 12:05p Sketcher
// Fixed more vehicle stuff
// 
// 23    8/02/01 12:03p Sketcher
// Trying to get vehicles to work better.  Still need to fix prediction
// 
// 22    7/27/01 8:30a Sketcher
// The view on the horse vehicle is now locked ( but hard coded -- will change
// that soon ) Also, prediction needs to be fixed to handle the vehicle stuff
// 
// 21    6/20/01 11:16a Steven
// Fixed some falling issues.
// 
// 20    5/23/01 10:10a Ericf
// Fixed stairs physics bug
// 
// 19    5/22/01 5:02p Ericf
// Removed some old unused code
// 
// 18    5/22/01 4:52p Ericf
// Player physics work... put back Q3 style land smoothing.
// 
// 17    5/12/01 3:21p Ericf
// Jump duck code
// 
// 16    5/10/01 7:05p Ericf
// Fixed a horse viewheight bug
// 
// 15    5/09/01 4:46p Ericf
// More Horse Stuff
// 
// 14    5/01/01 2:53p Ericf
// More horse code
// 
// 13    4/30/01 2:47p Ericf
// Ladders and AG47 View Code
// 
// 12    3/28/01 3:23p Steven
// Added warning printfs.
// 
// 4     6.02.01 12:10p Ericf
// Big player physics changes...
// 
// 3     31.01.01 12:35p Ericf
// Fixed getting stuck on slopes
// 
// 2     26.01.01 1:19p Ericf
// Removed the stuckjump check
//
// 48    9/20/00 6:58p Aldie
// Another temporary checkin for deathmatch stuff
//
// 47    7/26/00 11:22p Markd
// changed sampling time in pmove to be 20FPS not 15
//
// 46    7/25/00 2:41p Markd
// made terminal velocity lethal
//
// 45    7/25/00 12:47p Markd
// Added new player sounds
//
// 44    7/24/00 12:46p Markd
// fixed rope movment
//
// 43    7/16/00 10:28a Markd
// fixed some movement code issues
//
// 42    7/11/00 1:36p Steven
// Tweaked falling values a little.
//
// 41    7/10/00 6:50p Markd
// fixed some issues with water running
//
// 40    6/28/00 3:38p Markd
// Tweaked fatal falling distance
//
// 39    6/26/00 7:14p Markd
// tweaked stuck move code
//
// 38    6/25/00 12:37p Markd
// fixed player getting stuck
//
// 37    6/25/00 11:21a Markd
// fixed slime code for player
//
// 36    6/20/00 3:43p Markd
// fixed walking animations
//
// 35    6/14/00 11:18a Markd
// cleaned up code using Intel compiler
//
// 34    6/06/00 7:41p Markd
// Turned on an extraneous PM_ClipVelocity which was in Q3
//
// 33    6/06/00 5:02p Markd
// fixed player movement stuff
//
// 32    6/01/00 7:00p Markd
// added partial friciton for slippery surfaces
//
// 31    5/11/00 11:05a Steven
// Added pushing of actors out of the way.
//
// 30    5/06/00 5:25p Markd
// fixed camera and pipe hang issues
//
// 29    4/27/00 11:59a Jimdose
// trying new slidemove
//
// 28    4/15/00 5:40p Markd
// fixed falling damage and getting into and out of water
//
// 27    4/15/00 1:30p Markd
// added check_was_running code so that player does not always stop short
//
// 26    4/07/00 3:00p Markd
// Added legs dangling code for pipehanging
//
// 25    2/24/00 4:16p Jimdose
// moved defines into bg_pulic.h
//
// 24    2/23/00 4:51p Jimdose
// added AddPlane
//
// 23    2/23/00 10:07a Markd
// Fixed slick surface support
//
// 22    2/18/00 4:15p Jimdose
// Pmove_GroundTrace now calls PM_CheckDuck to ensure that the bounding boxes
// are set
//
// 21    2/17/00 4:20p Jimdose
// improved sliding on slopes
// removed auto wall avoidance and replaced it with slide move
//
// 20    2/15/00 8:56p Jimdose
// added move feedback checks for state system
// added wall avoidance code
//
// 19    2/11/00 2:20p Markd
// Added water support to turbo movement
//
// 18    2/11/00 10:35a Markd
// Added faster running when run is held down a sufficient time
//
// 17    1/27/00 11:35a Markd
// Fixed solid/notsolid client side entities
//
// 16    1/25/00 8:07p Jimdose
// changed stepsize to 31
//
// 15    1/22/00 12:44p Jimdose
// PM_StepMove no clears out the velocity when blocked
//
// 14    1/19/00 10:01p Jimdose
// no longer restrict movement when in air
//
// 13    1/12/00 8:02p Markd
// Fixed msec command for dropping timers in pmove
//
// 12    1/05/00 7:25p Jimdose
// made angle functions all use the same coordinate system
// AngleVectors now returns left instead of right
// no longer need to invert pitch
//
// 11    12/09/99 3:40p Jimdose
// fixed speed going up slopes
//
// 10    12/09/99 11:00a Markd
// merged in latest player movement code and broke jumping, yay!
//
// 9     10/27/99 10:21a Steven
// Added new flag PMF_NO_MOVE.
//
// 8     10/12/99 2:23p Markd
// Rewrote camera and player movetype system
//
// 7     10/08/99 2:09p Markd
// Added PM_LOCKVIEW to changing view while in camera
//
// 6     9/16/99 7:43p Jimdose
// fixed up merge
//
// DESCRIPTION:
//

#include "q_shared.h"
#include "bg_public.h"

// all of the locals will be zeroed before each
// pmove, just to make damn sure we don't have
// any differences when running on client or server
typedef struct {
	vec3_t		forward, left, up;
	vec3_t		flat_forward, flat_left, flat_up;
   float       forward_speed, side_speed;
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

pmove_t	*pm;
pml_t		pml;
qboolean slopeSlideFlag = qfalse;

// movement parameters
const float	pm_swimScale         = 0.50f;
const float	pm_wadeScale         = 0.70f;
const float	pm_slipperyfriction  = 0.25f;

int c_pmove = 0;

void PM_CrashLand( void );

/*
===============
PM_AddTouchEnt
===============
*/
void PM_AddTouchEnt
   (
   int entityNum
   )

   {
	int i;

	if ( entityNum == ENTITYNUM_WORLD )
      {
		return;
	   }

	if ( pm->numtouch == MAXTOUCH )
      {
		return;
	   }

	// see if it is already added
	for( i = 0; i < pm->numtouch; i++ )
      {
		if ( pm->touchents[ i ] == entityNum )
         {
			return;
		   }
	   }

	// add it
	pm->touchents[ pm->numtouch ] = entityNum;
	pm->numtouch++;
   }

/*
==================
PM_ClipVelocity

Slide off of the impacting surface
==================
*/
void PM_ClipVelocity
   (
   vec3_t in,
   vec3_t normal,
   vec3_t out,
   float overbounce
   )

   {
	float	backoff;
	float	change;
	int	i;

	backoff = DotProduct( in, normal );

	if ( backoff < 0 )
      {
		backoff *= overbounce;
	   }
   else
      {
		backoff /= overbounce;
	   }

	for( i = 0; i < 3; i++ )
      {
		change = normal[ i ] * backoff;
		out[ i ] = in[ i ] - change;
	   }
   }

/*
==================
PM_SlideMove

Returns qtrue if the velocity was clipped in some way
==================
*/
#define	MAX_CLIP_PLANES	5
qboolean	PM_SlideMove( qboolean gravity ) {
	int			bumpcount, numbumps;
	vec3_t		dir;
	float		d;
	int			numplanes;
	vec3_t		planes[MAX_CLIP_PLANES];
	vec3_t		primal_velocity;
	vec3_t		clipVelocity;
	int			i, j, k;
	trace_t	trace;
	vec3_t		end;
	float		time_left;
	float		into;
	vec3_t		endVelocity;
	vec3_t		endClipVelocity;
	int gravtmp;

	numbumps = 4;

	VectorCopy (pm->ps->velocity, primal_velocity);

	if ( gravity ) {
		if ( pm->ps->pm_flags & PMF_FLIGHT )
			gravtmp = 0;
		else
			gravtmp = pm->ps->gravity;

		VectorCopy( pm->ps->velocity, endVelocity );
		endVelocity[2] -= gravtmp * pml.frametime;
		pm->ps->velocity[2] = ( pm->ps->velocity[2] + endVelocity[2] ) * 0.5;
		primal_velocity[2] = endVelocity[2];
		if ( pml.groundPlane ) {
			// slide along the ground plane
			PM_ClipVelocity (pm->ps->velocity, pml.groundTrace.plane.normal,
				pm->ps->velocity, OVERCLIP );
		}
	}

	time_left = pml.frametime;

	// never turn against the ground plane
	if ( pml.groundPlane ) {
		numplanes = 1;
		VectorCopy( pml.groundTrace.plane.normal, planes[0] );
	} else {
		numplanes = 0;
	}

	// never turn against original velocity
	VectorNormalize2( pm->ps->velocity, planes[numplanes] );
	numplanes++;

	for ( bumpcount=0 ; bumpcount < numbumps ; bumpcount++ ) {

		// calculate position we are trying to move to
		VectorMA( pm->ps->origin, time_left, pm->ps->velocity, end );

		// add exact pull from gravity
	//	if ( gravity && !(pm->ps->pm_flags & PMF_FLIGHT) ) {
	//		pm->ps->origin[2] += 0.5 * time_left * time_left;
	//	}

		// see if we can make it there
		pm->trace ( &trace, pm->ps->origin, pm->mins, pm->maxs, end, pm->ps->clientNum, pm->tracemask, qtrue );

      if ( trace.startsolid && trace.entityNum != ENTITYNUM_WORLD )
         {
         // stuck in an entity, so try to pretend it's not there
         pm->trace ( &trace, pm->ps->origin, pm->mins, pm->maxs, end, trace.entityNum, pm->tracemask, qtrue );
         }

      if (trace.allsolid) {
			// entity is completely trapped in another solid
			pm->ps->velocity[2] = 0;	// don't build up falling damage, but allow sideways acceleration
			return qtrue;
		}

      if ( pm->trypush && pm->trypush( trace.entityNum, pm->ps->origin, end ) )
			continue;

		if (trace.fraction > 0) {
			// actually covered some distance
			VectorCopy (trace.endpos, pm->ps->origin);
		}

		if (trace.fraction == 1) {
			 break;		// moved the entire distance
		}

      /*if ( ( trace.plane.normal[ 2 ] < MIN_WALK_NORMAL ) && ( trace.plane.normal[ 2 ] > 0 ) )
      {
         // treat steep walls as vertical
         trace.plane.normal[ 2 ] = 0;
         VectorNormalize( trace.plane.normal );
      }*/

		// save entity for contact
		PM_AddTouchEnt( trace.entityNum );

      time_left -= time_left * trace.fraction;

		if (numplanes >= MAX_CLIP_PLANES) {
			// this shouldn't really happen
			VectorClear( pm->ps->velocity );
			return qtrue;
		}

		//
		// if this is the same plane we hit before, nudge velocity
		// out along it, which fixes some epsilon issues with
		// non-axial planes
		//
		for ( i = 0 ; i < numplanes ; i++ ) {
			if ( DotProduct( trace.plane.normal, planes[i] ) > 0.99 ) {
				VectorAdd( trace.plane.normal, pm->ps->velocity, pm->ps->velocity );
				break;
			}
		}
		if ( i < numplanes ) {
			continue;
		}
		VectorCopy (trace.plane.normal, planes[numplanes]);
		numplanes++;

		//
		// modify velocity so it parallels all of the clip planes
		//

		// find a plane that it enters
		for ( i = 0 ; i < numplanes ; i++ ) {
			into = DotProduct( pm->ps->velocity, planes[i] );
			if ( into >= 0.1 ) {
				continue;		// move doesn't interact with the plane
			}

			// see how hard we are hitting things
			if ( -into > pml.impactSpeed ) {
				pml.impactSpeed = -into;
			}

			// slide along the plane
			PM_ClipVelocity (pm->ps->velocity, planes[i], clipVelocity, OVERCLIP );

			// slide along the plane
			PM_ClipVelocity (endVelocity, planes[i], endClipVelocity, OVERCLIP );

			// see if there is a second plane that the new move enters
			for ( j = 0 ; j < numplanes ; j++ ) {
				if ( j == i ) {
					continue;
				}
				if ( DotProduct( clipVelocity, planes[j] ) >= 0.1 ) {
					continue;		// move doesn't interact with the plane
				}

				// try clipping the move to the plane
				PM_ClipVelocity( clipVelocity, planes[j], clipVelocity, OVERCLIP );
				PM_ClipVelocity( endClipVelocity, planes[j], endClipVelocity, OVERCLIP );

				// see if it goes back into the first clip plane
				if ( DotProduct( clipVelocity, planes[i] ) >= 0 ) {
					continue;
				}

				// slide the original velocity along the crease
				CrossProduct (planes[i], planes[j], dir);
				VectorNormalize( dir );
				d = DotProduct( dir, pm->ps->velocity );
				VectorScale( dir, d, clipVelocity );

				CrossProduct (planes[i], planes[j], dir);
				VectorNormalize( dir );
				d = DotProduct( dir, endVelocity );
				VectorScale( dir, d, endClipVelocity );

				// see if there is a third plane the the new move enters
				for ( k = 0 ; k < numplanes ; k++ ) {
					if ( k == i || k == j ) {
						continue;
					}
					if ( DotProduct( clipVelocity, planes[k] ) >= 0.1 ) {
						continue;		// move doesn't interact with the plane
					}

					// stop dead at a triple plane interaction
					VectorClear( pm->ps->velocity );
					return qtrue;
				}
			}

			// if we have fixed all interactions, try another move
			VectorCopy( clipVelocity, pm->ps->velocity );
			VectorCopy( endClipVelocity, endVelocity );
			break;
		}
	}

	if ( gravity ) {
		VectorCopy( endVelocity, pm->ps->velocity );
	}

	// don't change velocity if in a timer (FIXME: is this correct?)
	if ( pm->ps->pm_time ) {
		VectorCopy( primal_velocity, pm->ps->velocity );
	}

	return ( bumpcount != 0 );
}
/*
void PM_StepSlideMove( qboolean gravity ) {
	vec3_t		start_o, start_v;
	trace_t		trace;
//	float		down_dist, up_dist;
//	vec3_t		delta, delta2;
	vec3_t		up, down;
	vec3_t		down_o, down_v;

	VectorCopy (pm->ps->origin, start_o);
	VectorCopy (pm->ps->velocity, start_v);

	if ( PM_SlideMove( gravity ) == 0 ) {
		return;		// we got exactly where we wanted to go first try
	}

	VectorCopy(start_o, down);
	down[2] -= STEPSIZE;
	pm->trace (&trace, start_o, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask, qtrue);
	VectorSet(up, 0, 0, 1);
	// never step up when you still have up velocity
	if ( pm->ps->velocity[2] > 0 && (trace.fraction == 1.0 ||
										DotProduct(trace.plane.normal, up) < 0.7)) {
		return;
	}

	VectorCopy (start_o, up);
	up[2] += STEPSIZE;

	// test the player position if they were a stepheight higher
	pm->trace (&trace, up, pm->mins, pm->maxs, up, pm->ps->clientNum, pm->tracemask, qtrue);
	if ( trace.allsolid ) {
		if ( pm->debugLevel ) {
			Com_Printf("%i:bend can't step\n", c_pmove);
		}
		return;		// can't step up
	}

	// try slidemove from this position
	VectorCopy (up, pm->ps->origin);
	VectorCopy (start_v, pm->ps->velocity);

	PM_SlideMove( gravity );

	VectorCopy (pm->ps->origin, down_o);
	VectorCopy (pm->ps->velocity, down_v);

	// push down the final amount
	VectorCopy (pm->ps->origin, down);
	down[2] -= STEPSIZE;
	pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask, qtrue );

	if ( !trace.allsolid )
		{
      if ( 	( trace.fraction < 1.0 ) && trace.plane.normal[ 2 ] < MIN_WALK_NORMAL )
			{
			slopeSlideFlag = qtrue;
         //VectorCopy (start_o, pm->ps->origin);
         //return;
			} else
				slopeSlideFlag = qfalse;
		}
   

	VectorCopy (trace.endpos, pm->ps->origin);

	if ( trace.fraction < 1.0 ) {
		PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP );
	}

	// use the step move
	pm->stepped = qtrue;
	if ( pm->debugLevel ) {
		Com_Printf("%i:stepped\n", c_pmove);
	}
}*/

void PM_StepSlideMove( qboolean gravity ) {
	vec3_t		start_o, start_v;
	vec3_t		down_o, down_v;
	trace_t		trace;
	vec3_t		up, down;

	VectorCopy (pm->ps->origin, start_o);
	VectorCopy (pm->ps->velocity, start_v);

	if ( PM_SlideMove( gravity ) == 0 ) {
		return;		// we got exactly where we wanted to go first try	
	}

	VectorCopy (pm->ps->origin, down_o);
	VectorCopy (pm->ps->velocity, down_v);

	VectorCopy (start_o, up);
	up[2] += STEPSIZE;

	// test the player position if they were a stepheight higher
	pm->trace (&trace, up, pm->mins, pm->maxs, up, pm->ps->clientNum, pm->tracemask, qtrue);
	if ( trace.allsolid ) {
		if ( pm->debugLevel ) {
			Com_WPrintf("%i:bend can't step\n", c_pmove);
		}
		return;		// can't step up
	}

	// try slidemove from this position
	VectorCopy (up, pm->ps->origin);
	VectorCopy (start_v, pm->ps->velocity);

	PM_SlideMove( gravity );

	// push down the final amount
	VectorCopy (pm->ps->origin, down);
	down[2] -= STEPSIZE;
	pm->trace (&trace, pm->ps->origin, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask, qtrue );
	if ( !trace.allsolid ) {
		VectorCopy (trace.endpos, pm->ps->origin);
	}
	if ( trace.fraction < 1.0 ) {
		PM_ClipVelocity( pm->ps->velocity, trace.plane.normal, pm->ps->velocity, OVERCLIP );
	}

	// Why is this code here?  It's used in Quake3 but causes problems with stairs here

	// if the down trace can trace back to the original position directly, don't step
/*	pm->trace(&trace, pm->ps->origin, pm->mins, pm->maxs, start_o, pm->ps->clientNum, pm->tracemask, qtrue);
	if ( trace.fraction == 1.0 ) {
		// use the original move
		VectorCopy (down_o, pm->ps->origin);
		VectorCopy (down_v, pm->ps->velocity);
		if ( pm->debugLevel ) {
			Com_Printf("%i:bend\n", c_pmove);
		}
	} else {*/
		// use the step move
		pm->stepped = qtrue;		// allow client to smooth out the step
		if ( pm->debugLevel ) {
			Com_Printf("%i:stepped\n", c_pmove);
		}
//	}
}

/*
==================
PM_Friction

Handles both ground friction and water friction
==================
*/
void PM_Friction
   (
   void
   )

   {
	vec3_t	vec;
	float	   *vel;
	float	   speed;
   float	   newspeed;
   float	   control;
	float	   drop;

	vel = pm->ps->velocity;

	VectorCopy( vel, vec );
	if ( pml.walking )
      {
      // ignore slope movement
		vec[ 2 ] = 0;
	   }

	speed = VectorLength( vec );
	if ( speed < 1 )
      {
      // allow sinking underwater
		vel[ 0 ] = 0;
		vel[ 1 ] = 0;

		return;
	   }

	drop = 0;

	// apply ground friction
	if ( pml.walking )
      {
		// if getting knocked back, no friction
		if ( !( pm->ps->pm_flags & PMF_TIME_KNOCKBACK ) )
         {
			control = ( speed < pm->ps->pm_stopspeed ) ? pm->ps->pm_stopspeed : speed;
         if ( pml.groundTrace.surfaceFlags & SURF_SLICK )
            {
   			drop += control * pm_slipperyfriction * pml.frametime;
            }
         else
            {
   			drop += control * pm->ps->pm_friction * pml.frametime;
            }
		   }
	   }

	// apply water friction
	if ( pm->waterlevel )
      {
      if ( pm->watertype & CONTENTS_SLIME )
         {
   		drop += speed * pm->ps->pm_waterfriction * 5 * pm->waterlevel * pml.frametime;
   		//drop += speed * pm->ps->pm_waterfriction * 2 * pml.frametime;
         }
      else
         {
   		drop += speed * pm->ps->pm_waterfriction * pm->waterlevel * pml.frametime;
         }
	   }

	// scale the velocity
	newspeed = speed - drop;
	if ( newspeed < 0 )
      {
		newspeed = 0;
	   }

	newspeed /= speed;

	vel[0] = vel[ 0 ] * newspeed;
	vel[1] = vel[ 1 ] * newspeed;
	vel[2] = vel[ 2 ] * newspeed;
   }


/*
==============
PM_Accelerate

Handles user intended acceleration
==============
*/
void PM_Accelerate
   (
   vec3_t wishdir,
   float wishspeed,
   float accel
   )

   {
	int	i;
	float	addspeed;
   float accelspeed;
   float currentspeed;

	currentspeed = DotProduct( pm->ps->velocity, wishdir );
	addspeed = wishspeed - currentspeed;
	if ( addspeed <= 0 )
      {
		return;
	   }

	accelspeed = accel * pml.frametime * wishspeed;
	if ( accelspeed > addspeed )
      {
		accelspeed = addspeed;
	   }

	for( i = 0; i < 3; i++ )
      {
		pm->ps->velocity[ i ] += accelspeed * wishdir[ i ];
	   }
   }


/*
============
PM_CmdScale

Returns the scale factor to apply to cmd movements
This allows the clients to use axial -127 to 127 values for all directions
without getting a sqrt(2) distortion in speed.
============
*/

float PM_CmdScale
   (
   usercmd_t *cmd
   )

   {
	int	max;
	float	total;
	float	scale;

	max = abs( cmd->forwardmove );
	if ( abs( cmd->rightmove ) > max )
      {
		max = abs( cmd->rightmove );
	   }

	if ( abs( cmd->upmove ) > max )
      {
		max = abs( cmd->upmove );
	   }

	if ( !max )
      {
		return 0;
	   }

	total = sqrt( cmd->forwardmove * cmd->forwardmove + cmd->rightmove * cmd->rightmove + cmd->upmove * cmd->upmove );
	scale = pm->ps->speed * max / ( 127.0 * total );

	return scale;
   }

/*
=============
PM_CheckJump
=============
*/
qboolean PM_CheckJump( void ) {
	if ( pm->ps->pm_flags & PMF_TIME_LAND ) {
		// hasn't been long enough since landing to jump again
		return qfalse;
	}

	if ( pm->cmd.upmove < 10 ) {
		// not holding jump
		return qfalse;
	}

	// must wait for jump to be released
	if ( pm->ps->pm_flags & PMF_JUMP_HELD ) {
		return qfalse;
	}

	pml.groundPlane = qfalse;		// jumping away
	pml.walking = qfalse;
	pm->ps->pm_flags |= PMF_JUMP_HELD;

	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	pm->ps->velocity[2] = pm->ps->jumpheight;

	return qtrue;
}

/*
=============
PM_CheckWaterJump
=============
*/
qboolean	PM_CheckWaterJump
   (
   void
   )

   {
	vec3_t	spot;
	int		cont;

	if ( pm->ps->pm_time )
      {
		return qfalse;
	   }

	// check for water jump
	if ( ( pm->waterlevel < 2 ) )
      {
		return qfalse;
	   }
   // if we are below the surface and not in slime, return
	if ( !( pm->watertype & CONTENTS_SLIME ) && ( pm->waterlevel == 3 ) )
      {
		return qfalse;
	   }

   VectorMA( pm->ps->origin, 80, pml.flat_forward, spot );
	spot[ 2 ] += pm->ps->viewheight - 16 ;
	cont = pm->pointcontents( spot, pm->ps->clientNum );
	if ( !( cont & pm->tracemask ) )
      {
		return qfalse;
	   }

	spot[ 2 ] += 48;
	cont = pm->pointcontents( spot, pm->ps->clientNum );
	if ( cont )
      {
		return qfalse;
	   }

	// jump out of water
	VectorScale( pml.flat_forward, 150, pm->ps->velocity );
	pm->ps->velocity[ 2 ] = 600;

	pm->ps->pm_flags |= PMF_TIME_WATERJUMP;
	pm->ps->pm_time = 2000;

	return qtrue;
   }

//============================================================================


/*
===================
PM_WaterJumpMove

Flying out of the water
===================
*/
void PM_WaterJumpMove
   (
   void
   )

   {
	// waterjump has no control, but falls
	PM_StepSlideMove( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );

	pm->ps->velocity[ 2 ] -= pm->ps->gravity * pml.frametime;
	if ( pm->ps->velocity[ 2 ] < 0 )
      {
		// cancel as soon as we are falling down again
		pm->ps->pm_flags &= ~PMF_ALL_TIMES;
		pm->ps->pm_time = 0;
	   }
   }

#define SLIME_SINK_SPEED -10.0f
/*
===================
PM_WaterMove

===================
*/
void PM_WaterMove
   (
   void
   )

   {
	int		i;
	vec3_t	wishvel;
	float	   wishspeed;
	vec3_t	wishdir;
	float	   scale;

	if ( PM_CheckWaterJump() )
      {
		PM_WaterJumpMove();
		return;
   	}

   //
   // clamp our speed if we are in slime
   //
   if ( pm->watertype & CONTENTS_SLIME )
      {
      if ( pm->ps->velocity[ 2 ] < SLIME_SINK_SPEED )
         {
         pm->ps->velocity[ 2 ] = SLIME_SINK_SPEED;
         }
      }

	PM_Friction();

	scale = PM_CmdScale( &pm->cmd );

	//
	// user intentions
	//
	if ( !scale )
      {
		wishvel[ 0 ] = 0;
		wishvel[ 1 ] = 0;
      if ( pm->watertype & CONTENTS_SLIME )
         {
	      wishvel[ 2 ] = SLIME_SINK_SPEED;		// sink towards bottom
         }
      else
         {
		   wishvel[ 2 ] = -60;		// sink towards bottom
         }
	   }
   else
      {
		for( i = 0; i < 3; i++ )
         {
			wishvel[ i ] = scale * pml.flat_forward[ i ] * pm->cmd.forwardmove - scale * pml.flat_left[ i ] * pm->cmd.rightmove;
         }

		wishvel[ 2 ] += scale * pm->cmd.upmove;
	   }
   if ( ( pm->watertype & CONTENTS_SLIME ) && ( pm->waterlevel > 2 ) && ( wishvel[ 2 ] < 0 ) )
      {
      wishvel[ 2 ] = 0;
      }

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );

	if ( wishspeed > pm->ps->speed * pm_swimScale )
      {
		wishspeed = pm->ps->speed * pm_swimScale;
	   }

	PM_Accelerate( wishdir, wishspeed, pm->ps->pm_wateraccelerate );

	PM_SlideMove( qfalse );
   }

/*
===================
PM_StuckJumpMove

Flying out of someplace we were stuck
===================
*/
void PM_StuckJumpMove
   (
   void
   )

   {
	// stuckjump has no control, but falls
	PM_StepSlideMove( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );

	pm->ps->velocity[ 2 ] -= pm->ps->gravity * pml.frametime;
	if ( pm->ps->velocity[ 2 ] < -48 )
      {
		// cancel as soon as we are falling at decent clip again
		pm->ps->pm_flags &= ~PMF_ALL_TIMES;
		pm->ps->pm_time = 0;
	   }
   }

/*
===================
PM_FlyMove

Only with the flight powerup
===================
*/
void PM_FlyMove( void ) {
	float	   speed;
   float    drop;
   float    friction;
   float    control;
   float    newspeed;
	int		i;
	vec3_t	wishvel;
	float		fmove;
   float    smove;
	vec3_t	wishdir;
	float		wishspeed;
	float		scale;

	// friction

	speed = VectorLength( pm->ps->velocity );
	if ( speed < 1 )
	   {
		VectorCopy( vec3_origin, pm->ps->velocity );
	   }
	else
	   {
		drop = 0;

      // extra friction
		friction = pm->ps->pm_friction * 1.5;

		control = speed < pm->ps->pm_stopspeed ? pm->ps->pm_stopspeed : speed;
		drop += control * friction * pml.frametime;

		// scale the velocity
		newspeed = speed - drop;
		if ( newspeed < 0 )
         {
			newspeed = 0;
         }
		newspeed /= speed;

		VectorScale( pm->ps->velocity, newspeed, pm->ps->velocity );
	   }

	// accelerate
	scale = PM_CmdScale( &pm->cmd );

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;
   pm->ps->pm_runtime = 0;

	for( i = 0; i < 3; i++ )
      {
		wishvel[ i ] = pml.flat_forward[ i ] * fmove - pml.flat_left[ i ] * smove;
      }

	wishvel[ 2 ] += pm->cmd.upmove;

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );
	wishspeed *= scale;

	PM_Accelerate( wishdir, wishspeed, pm->ps->pm_accelerate );

	// move
	PM_StepSlideMove( qtrue );
	//VectorMA( pm->ps->origin, pml.frametime, pm->ps->velocity, pm->ps->origin );
}

/*
=============
PM_CheckStuckJump
=============
*/
#define MAX_XY_VELOCITY 50
qboolean	PM_CheckStuckJump
   (
   void
   )

   {
   vec3_t   diff;

	if ( pm->ps->pm_time )
      {
		return qfalse;
	   }

	if ( pm->waterlevel > 1 )
      {
		return qfalse;
	   }

   VectorSubtract( pm->ps->origin, pml.previous_origin, diff );
   if ( VectorLength( diff ) )
      {
      return qfalse;
      }
   if ( VectorLength( pm->ps->velocity ) < 100 )
      {
      return qfalse;
      }

	// For Redemption we don't actually want to force a jump -Eric

   // we have been falling, we haven't moved and our velocity is getting dangerously high
   // let's give ourselves a boost straight up and opposite our current velocity
  /* pm->ps->velocity[ 0 ] = -pm->ps->velocity[ 0 ];
   if ( pm->ps->velocity[ 0 ] > MAX_XY_VELOCITY )
      pm->ps->velocity[ 0 ] = MAX_XY_VELOCITY;
   else if ( pm->ps->velocity[ 0 ] < -MAX_XY_VELOCITY )
      pm->ps->velocity[ 0 ] = -MAX_XY_VELOCITY;

   pm->ps->velocity[ 1 ] = -pm->ps->velocity[ 1 ];
   if ( pm->ps->velocity[ 1 ] > MAX_XY_VELOCITY )
      pm->ps->velocity[ 1 ] = MAX_XY_VELOCITY;
   else if ( pm->ps->velocity[ 1 ] < -MAX_XY_VELOCITY )
      pm->ps->velocity[ 1 ] = -MAX_XY_VELOCITY;

	pm->ps->velocity[ 2 ] = 500;

	pm->ps->pm_flags |= PMF_TIME_STUCKJUMP;
	pm->ps->pm_time = 2000;*/

	return qtrue;
   }

/*
=============
PM_CheckTerminalVelocity
=============
*/
#define TERMINAL_VELOCITY 1200
void PM_CheckTerminalVelocity
   (
   void
   )
   {
   float oldspeed;
   float speed;

   //
   // how fast were we falling
   //
   oldspeed = -pml.previous_velocity[ 2 ];

   //
   // how fast are we falling
   //
   speed = -pm->ps->velocity[ 2 ];

	if ( speed <= 0 )
      {
		return;
	   }

	if ( ( oldspeed <= TERMINAL_VELOCITY ) && ( speed > TERMINAL_VELOCITY ) )
      {
		pm->pmoveEvent = EV_TERMINAL_VELOCITY;
   	}
   }

/*
===================
PM_AirMove

===================
*/
void PM_AirMove
   (
   void
   )

   {
	vec3_t		wishvel;
	float		   fmove;
   float       smove;
	vec3_t		wishdir;
	float		   wishspeed;
	float		   scale;
	usercmd_t	cmd;

	vec3_t		original_start;
	vec3_t		original_end;
	float			old_speed;
	vec3_t original_diff;
	float original_dist;
	vec3_t new_diff;
	float new_dist;
	float new_speed;
	float max_new_speed;

	// Save some information about original state of things

	VectorCopy( pm->ps->origin, original_start );
	VectorMA( pm->ps->origin, pml.frametime, pm->ps->velocity, original_end );
	old_speed = VectorLength( pm->ps->velocity );

   //PM_Friction();

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;
   pm->ps->pm_runtime = 0;

	cmd = pm->cmd;
	scale = PM_CmdScale( &cmd );

   wishvel[ 0 ] = pml.flat_forward[ 0 ] * fmove - pml.flat_left[ 0 ] * smove;
   wishvel[ 1 ] = pml.flat_forward[ 1 ] * fmove - pml.flat_left[ 1 ] * smove;
	wishvel[ 2 ] = 0;

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );
	wishspeed *= scale;

	// not on ground, so little effect on velocity
	PM_Accelerate( wishdir, wishspeed, pm->ps->pm_airaccelerate );

	// we may have a ground plane that is very steep, even
	// though we don't have a groundentity
	// slide along the steep plane
	if ( pml.groundPlane )
      {
		PM_ClipVelocity( pm->ps->velocity, pml.groundTrace.plane.normal, pm->ps->velocity, OVERCLIP );
	   }

   if ( !pml.walking && pml.groundPlane )
      {
      vec3_t vel;

		VectorCopy( pm->ps->velocity, vel );
		vel[ 2 ] -= pm->ps->gravity * pml.frametime;
		pm->ps->velocity[ 2 ] = ( pm->ps->velocity[ 2 ] + vel[ 2 ] ) * 0.5;
      PM_SlideMove( qfalse );
      VectorCopy( vel, pm->ps->velocity );
      }
   else
      {
      PM_SlideMove( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );
      }
	
	if ( PM_CheckStuckJump() )
      {
		PM_StuckJumpMove();
   	}

	// Get the distance we tried to move

	VectorSubtract( original_start, original_end, original_diff );
	original_dist = VectorLength( original_diff );

	// Get the distance we actually moved

	VectorSubtract( original_start, pm->ps->origin, new_diff );
	new_dist = VectorLength( new_diff );

	if ( new_dist < original_dist && new_dist > 0 )
		{
		// Modify our velocity based on how far we got to move

		max_new_speed = old_speed * ( new_dist / original_dist );

		new_speed = VectorLength( pm->ps->velocity );

		if ( new_speed > max_new_speed )
			{
			VectorNormalize( pm->ps->velocity );
			VectorScale( pm->ps->velocity, max_new_speed, pm->ps->velocity );
			}
		}

   PM_CheckTerminalVelocity();
   }

void AddPlane
   (
   vec3_t norm,
   vec3_t planes[ MAX_CLIP_PLANES ],
   int *numplanes
   )

   {
   int i;

   if ( *numplanes >= MAX_CLIP_PLANES )
      {
      return;
      }

   for( i = 0; i < *numplanes; i++ )
      {
      if ( VectorCompare( planes[ i ], norm ) )
         {
         // don't add the plane twice
         return;
         }
      }

   VectorCopy( norm, planes[ *numplanes ] );
	( *numplanes )++;
   }

void PM_StepMove
   (
   void
   )

   {
   trace_t trace;
   vec3_t up;
   vec3_t down;
   vec3_t oldvelocity;
   vec3_t oldorigin;
   vec3_t velocity1;
   vec3_t origin1;

   VectorCopy( pm->ps->velocity, oldvelocity );
   VectorCopy( pm->ps->origin, oldorigin );

   if ( PM_SlideMove( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) ) )
      {
      VectorCopy( pm->ps->velocity, velocity1 );
      VectorCopy( pm->ps->origin, origin1 );

      VectorCopy( oldvelocity, pm->ps->velocity );

      VectorCopy( oldorigin, up );
      up[ 2 ] += STEPSIZE;

      //pm->trace( &trace, oldorigin, pm->mins, pm->maxs, up, pm->ps->clientNum, pm->tracemask, qtrue );
      pm->trace( &trace, up, pm->mins, pm->maxs, up, pm->ps->clientNum, pm->tracemask, qtrue );
      VectorCopy( trace.endpos, pm->ps->origin );

      PM_SlideMove( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );

      VectorCopy( pm->ps->origin, down );
      down[ 2 ] = oldorigin[ 2 ];

      pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, down, pm->ps->clientNum, pm->tracemask, qtrue );
      if ( trace.plane.normal[ 2 ] < MIN_WALK_NORMAL )
         {
         // use the first move
         VectorCopy( velocity1, pm->ps->velocity );
         VectorCopy( origin1, pm->ps->origin );
         }
      else
         {
         VectorCopy( trace.endpos, pm->ps->origin );
         pm->stepped = qtrue;
         }
      }
   }

/*
===================
PM_WalkMove

===================
*/

void PM_WalkMove
   (
   void
   )

   {
   int         i;
	vec3_t		wishvel;
	float		   fmove;
   float       smove;
	vec3_t		wishdir;
	float		   wishspeed;
	float		   scale;
	usercmd_t	cmd;
	float		   accelerate;
   float	      waterScale;

	if ( ( pm->waterlevel > 1 ) && DotProduct( pml.forward, pml.groundTrace.plane.normal ) > 0 )
      {
		// begin swimming
		PM_WaterMove();

		return;
	   }

	if ( PM_CheckJump () ) {
		// jumped away
		if ( pm->waterlevel > 1 ) {
			PM_WaterMove();
		} else {
			PM_AirMove();
		}
		return;
	}

	PM_Friction();

   fmove = pm->cmd.forwardmove;
   smove = pm->cmd.rightmove;

	cmd = pm->cmd;
	scale = PM_CmdScale( &cmd );

   if ( ( pm->cmd.buttons & BUTTON_RUN ) && fmove && !smove )
      {
      pm->ps->pm_runtime += pml.msec;
      }
   else
      {
      pm->ps->pm_runtime = 0;
      }

   //
   // only run faster if we have exceeded our running time
   //
/*   if ( ( pm->ps->stats[STAT_WATER_LEVEL] >= MINIMUM_WATER_FOR_TURBO ) && ( pm->ps->pm_runtime > WATER_TURBO_TIME ) )
      {
      scale *= WATER_TURBO_SPEED;
      }*/

	// project the forward and right directions onto the ground plane
	PM_ClipVelocity (pml.flat_forward, pml.groundTrace.plane.normal, pml.flat_forward, OVERCLIP );
	PM_ClipVelocity (pml.flat_left, pml.groundTrace.plane.normal, pml.flat_left, OVERCLIP );

	VectorNormalize (pml.flat_forward);
	VectorNormalize (pml.flat_left);

	for( i = 0 ; i < 3 ; i++ )
      {
		wishvel[ i ] = pml.flat_forward[ i ] * fmove - pml.flat_left[ i ] * smove;
	   }

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );
	wishspeed *= scale;

	// clamp the speed lower if wading or walking on the bottom
	if ( pm->waterlevel )
      {
		waterScale = pm->waterlevel / 3.0;
		waterScale = 1.0 - ( 1.0 - pm_swimScale ) * waterScale;
		if ( wishspeed > pm->ps->speed * waterScale )
         {
			wishspeed = pm->ps->speed * waterScale;
		   }
	   }

	// when a player gets hit, they temporarily lose
	// full control, which allows them to be moved a bit
	if ( ( pml.groundTrace.surfaceFlags & SURF_SLICK ) || pm->ps->pm_flags & PMF_TIME_KNOCKBACK )
      {
		accelerate = pm->ps->pm_airaccelerate;
	   }
   else
      {
		accelerate = pm->ps->pm_accelerate;
	   }

	PM_Accelerate( wishdir, wishspeed, accelerate );

	if ( ( pml.groundTrace.surfaceFlags & SURF_SLICK ) || pm->ps->pm_flags & PMF_TIME_KNOCKBACK )
      {
		pm->ps->velocity[ 2 ] -= pm->ps->gravity * pml.frametime;
	   }

	// don't do anything if standing still
	if ( !pm->ps->velocity[ 0 ] && !pm->ps->velocity[ 1 ] )
		return;

   PM_StepSlideMove ( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );
   }

/*
==============
PM_DeadMove
==============
*/
void PM_DeadMove
   (
   void
   )

   {
	float	forward;

	if ( !pml.walking )
      {
		return;
	   }

	// extra friction
	forward = VectorLength( pm->ps->velocity );
	forward -= 20;
	if ( forward <= 0 )
      {
		VectorClear( pm->ps->velocity );
	   }
   else
      {
		VectorNormalize( pm->ps->velocity );
		VectorScale( pm->ps->velocity, forward, pm->ps->velocity );
	   }
   }


/*
===============
PM_NoclipMove
===============
*/
void PM_VehicleMove
   (
   void
   )

   {
	
  	vec3_t		wishvel;
	float		   fmove;
   float       smove;
	vec3_t		wishdir;
	float		   wishspeed;
	float		   scale;
	usercmd_t	cmd;
	float		   accelerate;
  
   fmove = pm->cmd.forwardmove;
   smove = pm->cmd.rightmove;

	cmd = pm->cmd;
	scale = PM_CmdScale( &cmd );

   pm->ps->pm_runtime = 0;

	wishvel[0] = pm->ps->velocity[0];
	wishvel[1] = pm->ps->velocity[1];
	wishvel[2] = pm->ps->velocity[2];

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );
	wishspeed *= scale;
	
	accelerate = pm->ps->pm_accelerate;
	PM_Accelerate( wishdir, wishspeed, accelerate );

	// don't do anything if standing still
	if ( !pm->ps->velocity[ 0 ] && !pm->ps->velocity[ 1 ] )
		return;

   //PM_StepSlideMove ( !( pm->ps->pm_flags & PMF_NO_GRAVITY ) );
   }



/*
===============
PM_NoclipMove
===============
*/
void PM_NoclipMove
   (
   void
   )

   {
	float	   speed;
   float    drop;
   float    friction;
   float    control;
   float    newspeed;
	int		i;
	vec3_t	wishvel;
	float		fmove;
   float    smove;
	vec3_t	wishdir;
	float		wishspeed;
	float		scale;

	if ( pm->ps->pm_flags & PMF_ONHORSE )
		pm->ps->viewheight = AG47_VIEWHEIGHT;
	else
		pm->ps->viewheight = DEFAULT_VIEWHEIGHT;

	// friction

	speed = VectorLength( pm->ps->velocity );
	if ( speed < 1 )
	   {
		VectorCopy( vec3_origin, pm->ps->velocity );
	   }
	else
	   {
		drop = 0;

      // extra friction
		friction = pm->ps->pm_friction * 1.5;

		control = speed < pm->ps->pm_stopspeed ? pm->ps->pm_stopspeed : speed;
		drop += control * friction * pml.frametime;

		// scale the velocity
		newspeed = speed - drop;
		if ( newspeed < 0 )
         {
			newspeed = 0;
         }
		newspeed /= speed;

		VectorScale( pm->ps->velocity, newspeed, pm->ps->velocity );
	   }

	// accelerate
   // allow the player to move twice as fast in noclip
	scale = PM_CmdScale( &pm->cmd ) * 2;

	fmove = pm->cmd.forwardmove;
	smove = pm->cmd.rightmove;
   pm->ps->pm_runtime = 0;

	for( i = 0; i < 3; i++ )
      {
		wishvel[ i ] = pml.flat_forward[ i ] * fmove - pml.flat_left[ i ] * smove;
      }

	wishvel[ 2 ] += pm->cmd.upmove;

	VectorCopy( wishvel, wishdir );
	wishspeed = VectorNormalize( wishdir );
	wishspeed *= scale;

	PM_Accelerate( wishdir, wishspeed, pm->ps->pm_accelerate );

	// move
	VectorMA( pm->ps->origin, pml.frametime, pm->ps->velocity, pm->ps->origin );
   }

//============================================================================

/*
=============
PM_CorrectAllSolid
=============
*/
void PM_CorrectAllSolid
   (
   void
   )

   {
	if ( pm->debugLevel )
      {
		Com_Printf( "%i:allsolid\n", c_pmove );
	   }

	// FIXME: jitter around
	pm->ps->groundEntityNum = ENTITYNUM_NONE;
	pml.groundPlane = qfalse;
	pml.walking = qfalse;
   }

/*
=============
PM_GroundTrace
=============
*/
void PM_GroundTrace
   (
   void
   )

   {
	vec3_t   point;
	vec3_t	tmporg;
	trace_t  trace;

	point[ 0 ] = pm->ps->origin[ 0 ];
	point[ 1 ] = pm->ps->origin[ 1 ];
	point[ 2 ] = pm->ps->origin[ 2 ] - 0.25;

	pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask, qtrue );
	pml.groundTrace = trace;
	pm->ps->groundTrace = trace;

	// do something corrective if the trace starts in a solid...
	if ( trace.allsolid )
      {
		// We're gonna start with our origin a tad higher and see if it works
		tmporg[ 0 ] = pm->ps->origin[ 0 ];
		tmporg[ 1 ] = pm->ps->origin[ 1 ];
		tmporg[ 2 ] = pm->ps->origin[ 2 ] + 2.0;

		// Trace down to the same point
		pm->trace( &trace, tmporg, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask, qtrue );
		pml.groundTrace = trace;
		pm->ps->groundTrace = trace;

		// It's hopeless if we start all solid again
		if ( trace.allsolid )
			{
			PM_CorrectAllSolid();
			pm->ps->walking = pml.walking;
			pm->ps->groundPlane = pml.groundPlane;

			return;
			}
	   }

	// if the trace didn't hit anything, we are in free fall
	if ( trace.fraction == 1.0 )
      {
		if ( pm->ps->groundEntityNum != ENTITYNUM_NONE )
         {
			if ( pm->debugLevel )
            {
				Com_Printf( "%i:lift\n", c_pmove );
			   }
		   }

		pm->ps->groundEntityNum = ENTITYNUM_NONE;
		pml.groundPlane = qfalse;
		pml.walking = qfalse;

      pm->ps->walking = pml.walking;
      pm->ps->groundPlane = pml.groundPlane;

      return;
	   }

	// slopes that are too steep will not be considered onground
	// check slopeSlideFlag to avoid the "falling" bug
	if ( trace.plane.normal[ 2 ] < MIN_WALK_NORMAL )
      {
      vec3_t oldvel;
      float d;

		if ( pm->debugLevel )
         {
			Com_Printf( "%i:steep\n", c_pmove );
		   }

		// if they can't slide down the slope, let them
		// walk (sharp crevices)
      VectorCopy( pm->ps->velocity, oldvel );
      VectorSet( pm->ps->velocity, 0, 0, -1 / pml.frametime );
      PM_SlideMove( qfalse );

      d = VectorLength( pm->ps->velocity );
      VectorCopy( oldvel, pm->ps->velocity );
      if ( d > ( 0.1f / pml.frametime ) )
         {
		   pm->ps->groundEntityNum = ENTITYNUM_NONE;
		   pml.groundPlane = qtrue;
		   pml.walking = qfalse;

         pm->ps->walking = pml.walking;
         pm->ps->groundPlane = pml.groundPlane;

		   return;
         }
	   }

	// check if getting thrown off the ground
	if ( pm->ps->velocity[ 2 ] > 0 && DotProduct( pm->ps->velocity, trace.plane.normal ) > 10 )
      {
		if ( pm->debugLevel )
         {
			Com_Printf( "%i:kickoff\n", c_pmove );
		   }
		pm->ps->groundEntityNum = ENTITYNUM_NONE;
		pml.groundPlane = qfalse;
		pml.walking = qfalse;

      pm->ps->walking = pml.walking;
      pm->ps->groundPlane = pml.groundPlane;

		return;
	   }

	pml.groundPlane = qtrue;
	pml.walking = qtrue;

	// hitting solid ground will end a waterjump
	if ( pm->ps->pm_flags & PMF_TIME_WATERJUMP )
	   {
		pm->ps->pm_flags &= ~( PMF_TIME_WATERJUMP | PMF_TIME_LAND);
		pm->ps->pm_time = 0;
	   }

	// hitting solid ground will end a stuckjump
	if ( pm->ps->pm_flags & PMF_TIME_STUCKJUMP )
	   {
		pm->ps->pm_flags &= ~( PMF_TIME_STUCKJUMP );
		pm->ps->pm_time = 0;
	   }

	if ( pm->ps->groundEntityNum == ENTITYNUM_NONE )
      {
		// just hit the ground
		if ( pm->debugLevel )
         {
			Com_Printf( "%i:Land\n", c_pmove );
		   }

		PM_CrashLand();
	   }

	pm->ps->groundEntityNum = trace.entityNum;

   //if ( !( pml.groundTrace.surfaceFlags & SURF_SLICK ) )
  // pm->ps->velocity[ 2 ] = 0;

	PM_AddTouchEnt( trace.entityNum );

   pm->ps->walking = pml.walking;
   pm->ps->groundPlane = pml.groundPlane;
   }


/*
=============
PM_SetWaterLevel	FIXME: avoid this twice?  certainly if not moving
=============
*/
void PM_SetWaterLevel
   (
   void
   )

   {
	vec3_t  point;
	int	  cont;
	int	  sample1;
	int	  sample2;

   //
   // get waterlevel, accounting for ducking
   //
	pm->waterlevel = 0;
	pm->watertype = 0;

	sample2 = pm->ps->viewheight - MINS_Z;
	sample1 = sample2 * 3 / 4;

   VectorCopy( pm->ps->origin, point );
   point[ 2 ] += MINS_Z + 1;
	cont = pm->pointcontents( point, pm->ps->clientNum );
	if ( cont & MASK_WATER )
	   {
		pm->watertype = cont;
		pm->waterlevel = 1;

      point[ 2 ] = pm->ps->origin[ 2 ] + MINS_Z + sample1;
		cont = pm->pointcontents( point, 0 );
		if ( cont & MASK_WATER )
		   {
			pm->waterlevel = 2;
         point[ 2 ] = pm->ps->origin[ 2 ] + MINS_Z + sample2;
			cont = pm->pointcontents( point, 0 );
			if ( cont & MASK_WATER )
            {
				pm->waterlevel = 3;
            }
		   }
	   }
   }


/*
==============
PM_CheckDuck

Sets mins, maxs, and pm->ps->viewheight
==============
*/
void PM_CheckDuck
   (
   void
   )

   {
	pm->mins[ 0 ] = MINS_X;
	pm->mins[ 1 ] = MINS_Y;
	pm->mins[ 2 ] = MINS_Z;
	pm->maxs[ 0 ] = MAXS_X;
	pm->maxs[ 1 ] = MAXS_Y;

	pm->ps->viewheight = DEFAULT_VIEWHEIGHT;

	if ( pm->ps->pm_type == PM_DEAD )
      {
		pm->maxs[ 2 ] = DEAD_MINS_Z;
		pm->ps->viewheight = DEAD_VIEWHEIGHT;

		return;
	   }

	if ( (pm->ps->pm_flags & PMF_DUCKED) && !(pm->ps->pm_flags & PMF_ONHORSE) )
	   {
		pm->maxs[ 2 ] = CROUCH_MAXS_Z;
		// Set the viewheight only if we're on the ground,
		// otherwise ducking in mid-air does not change the view height
		// since we're assuming the feet are coming up.
		if ( pm->ps->groundPlane && pm->ps->walking )
			pm->ps->viewheight = CROUCH_VIEWHEIGHT;
	   }
	else if ( pm->ps->pm_flags & PMF_ONHORSE )
		{
		// Hardcoded AG47's bounding box
		pm->mins[0] = -32;
		pm->mins[1] = -32;
		pm->mins[2] = 0;
		pm->maxs[0] = 32;
		pm->maxs[1] = 32;
		pm->maxs[2] = AG47_MAXS_Z;
		pm->ps->viewheight = AG47_VIEWHEIGHT;
		}
	else
	   {
		pm->maxs[ 2 ] = MAXS_Z;
		pm->ps->viewheight = DEFAULT_VIEWHEIGHT;
	   }
   }


//===================================================================

/*
=================
PM_CrashLand

Check for hard landings that generate sound events

  fall from 128: 400 = 160000
  fall from 256: 580 = 336400
  fall from 384: 720 = 518400
  fall from 512: 800 = 640000
  fall from 640: 960 =

  damage = deltavelocity*deltavelocity  * 0.0001

=================
*/
void PM_CrashLand
   (
   void
   )

   {
	float delta;
	/* float	dist;
	float	vel;
   float	acc;
	float	t;
	float	a, b, c, den; */
	vec3_t diff;

	// calculate the exact velocity on landing
	/* dist = pm->ps->origin[ 2 ] - pml.previous_origin[ 2 ];
	vel = pml.previous_velocity[ 2 ];
	acc = -pm->ps->gravity;

	a = acc / 2;
	b = vel;
	c = -dist;

	den =  b * b - 4 * a * c;
	if ( den < 0 )
      {
		return;
	   }

	t = ( -b - sqrt( den ) ) / ( 2 * a );

	delta = vel + t * acc;

	if (delta < -200)
		{
		pm->ps->pm_flags |= PMF_TIME_LAND;
		// don't allow another jump for a little while
		if (delta < -400)
			pm->ps->pm_time = 200;	
		else
			pm->ps->pm_time = 144;
		} */

	// Get the change in speed

	VectorSubtract( pm->ps->velocity, pml.previous_velocity, diff );
	delta = VectorLength( diff );

	delta = delta * delta * 0.0001;

	// never take falling damage if completely underwater
	if ( pm->waterlevel == 3 )
      {
		return;
	   }

	// reduce falling damage if there is standing water
	if ( pm->waterlevel == 2 )
      {
		delta *= 0.25f;
	   }

	if ( pm->waterlevel == 1 )
      {
		delta *= 0.5f;
	   }

	if ( delta < 1 )
      {
		return;
	   }

	pm->landed = qtrue;
	pm->landedVelocity = pml.previous_velocity[2];

	// SURF_NODAMAGE is used for bounce pads where you don't ever
	// want to take damage or play a crunch sound
	if ( !( pml.groundTrace.surfaceFlags & SURF_NODAMAGE ) )
      {
		if ( delta > 135 )
         {
			pm->pmoveEvent = EV_FALL_FATAL;
   		}
		else if ( delta > 95 )
         {
			pm->pmoveEvent = EV_FALL_FAR;
   		}
      else if ( delta > 60 )
         {
			pm->pmoveEvent = EV_FALL_MEDIUM;
		   }
      else if ( delta > 14 )
         {
			pm->pmoveEvent = EV_FALL_SHORT;
		   }
	   }
   }

/*
==============
PM_WaterEvents

Generate sound events for entering and leaving water
==============
*/
void PM_WaterEvents
   (
   void
   )

   {
   // FIXME?
	//
	// if just entered a water volume, play a sound
	//
	if ( !pml.previous_waterlevel && pm->waterlevel )
      {
		pm->pmoveEvent = EV_WATER_TOUCH;
	   }

	//
	// if just completely exited a water volume, play a sound
	//
	if ( pml.previous_waterlevel && ! pm->waterlevel )
      {
		pm->pmoveEvent = EV_WATER_LEAVE;
	   }

	//
	// check for head just going under water
	//
	if ( ( pml.previous_waterlevel != 3 ) && ( pm->waterlevel == 3 ) )
      {
		pm->pmoveEvent = EV_WATER_UNDER;
	   }

	//
	// check for head just coming out of water
	//
	if ( ( pml.previous_waterlevel == 3 ) && ( pm->waterlevel != 3 ) )
      {
		pm->pmoveEvent = EV_WATER_CLEAR;
	   }
   }

/*
================
PM_DropTimers
================
*/
void PM_DropTimers
   (
   void
   )

   {
	// drop misc timing counter
	if ( pm->ps->pm_time )
      {
		if ( pml.msec >= pm->ps->pm_time )
         {
			pm->ps->pm_flags &= ~PMF_ALL_TIMES;
			pm->ps->pm_time = 0;
		   }
      else
         {
			pm->ps->pm_time -= pml.msec;
		   }
	   }
   }

/*
================
PM_UpdateViewAngles

This can be used as another entry point when only the viewangles
are being updated isntead of a full move
================
*/
void PM_UpdateViewAngles
   (
   playerState_t *ps,
   const usercmd_t *cmd
   )

   {
	short	temp;
	int	i;

	if ( ps->pm_flags & PMF_FROZEN )
      {
      // no view changes at all
		return;
	   }

   /*
	if ( ps->stats[ STAT_HEALTH ] <= 0 )
      {
      // no view changes at all
		return;
	   }
   */

	// circularly clamp the angles with deltas
	for( i = 0; i < 3; i++ )
      {
		temp = cmd->angles[ i ] + ps->delta_angles[ i ];
		if ( i == PITCH )
         {
			// don't let the player look up or down more than 90 degrees
			if ( temp > 16000 )
            {
				ps->delta_angles[ i ] = 16000 - cmd->angles[ i ];
				temp = 16000;
			   }
         else if ( temp < -16000 )
            {
				ps->delta_angles[ i ] = -16000 - cmd->angles[ i ];
				temp = -16000;
			   }
		   }

		ps->viewangles[ i ] = SHORT2ANGLE( temp );
	   }
   }

void Pmove_GroundTrace
   (
   pmove_t *pmove
   )

   {
   memset (&pml, 0, sizeof(pml));
   pml.msec = 1;
	pml.frametime = 0.001f;
	pm = pmove;
   PM_CheckDuck();
   PM_GroundTrace();
   }


/*
================
Pmove

Can be called by either the server or the client
================
*/
void PmoveSingle (pmove_t *pmove)
   {
   vec3_t tempVec;
   qboolean walking;

	pm = pmove;

	// this counter lets us debug movement problems with a journal
	// by setting a conditional breakpoint fot the previous frame
	c_pmove++;

	// clear results
	pm->numtouch = 0;
	pm->watertype = 0;
	pm->waterlevel = 0;
	pm->landed = qfalse;

	if ( pm->ps->stats[STAT_HEALTH] <= 0 )
      {
		pm->tracemask &= ~CONTENTS_BODY;	// corpses can fly through bodies
	   }

	// adding fake talk balloons
	if ( pmove->cmd.buttons & BUTTON_TALK )
      {
		pmove->cmd.buttons = 0;
		pmove->cmd.forwardmove = 0;
		pmove->cmd.rightmove = 0;
		pmove->cmd.upmove = 0;
	   }

	// clear all pmove local vars
	memset (&pml, 0, sizeof(pml));

	// determine the time
	pml.msec = pmove->cmd.serverTime - pm->ps->commandTime;
	if ( pml.msec < 1 )
      {
		pml.msec = 1;
	   }
   else if ( pml.msec > 200 )
      {
		pml.msec = 200;
	   }

	pm->ps->commandTime = pmove->cmd.serverTime;

	// save old org in case we get stuck
	VectorCopy( pm->ps->origin, pml.previous_origin );

	// save old velocity for crashlanding
	VectorCopy( pm->ps->velocity, pml.previous_velocity );

	pml.frametime = pml.msec * 0.001f;

	// update the viewangles
	if (!pm->ps->in_vehicle )
		{
		PM_UpdateViewAngles( pm->ps, &pm->cmd );

		AngleVectors( pm->ps->viewangles, pml.forward, pml.left, pml.up );
	   VectorClear( tempVec );
	   tempVec[ YAW ] = pm->ps->viewangles[ YAW ];
		AngleVectors( tempVec, pml.flat_forward, pml.flat_left, pml.flat_up );
		}

	if ( pm->ps->in_vehicle )
		{
		PM_VehicleMove();
		return;
		}

	if ( pm->cmd.upmove < 10 ) {
		// not holding jump
		pm->ps->pm_flags &= ~PMF_JUMP_HELD;
	}

	if ( pm->ps->pm_type >= PM_DEAD )
      {
		pm->cmd.forwardmove = 0;
		pm->cmd.rightmove = 0;
		pm->cmd.upmove = 0;
	   }

	if ( pm->ps->pm_type == PM_NOCLIP )
      {
		PM_NoclipMove ();
		PM_DropTimers ();
		return;
	   }

	if ( pm->ps->pm_flags & PMF_FROZEN || pm->ps->pm_flags & PMF_NO_MOVE )
      {
		return;		// no movement at all
	   }

	PM_CheckDuck();

	// set watertype, and waterlevel
	PM_SetWaterLevel();
	pml.previous_waterlevel = pmove->waterlevel;

	// set groundentity
	PM_GroundTrace();

	if ( pm->ps->pm_type == PM_DEAD )
      {
		PM_DeadMove();
	   }

	PM_DropTimers();

	if ( pm->ps->pm_flags & PMF_FLIGHT )
		// flight powerup doesn't allow jump and has different friction
		PM_FlyMove();
   else if ( pm->ps->pm_flags & PMF_TIME_WATERJUMP )
      {
		PM_WaterJumpMove();
	   }
   else if ( pml.walking )
      {
		// walking on ground
		PM_WalkMove();
	   }
   else if ( pm->waterlevel > 1 )
      {
		// swimming
		PM_WaterMove();
	   }
   else if ( pm->ps->pm_flags & PMF_TIME_STUCKJUMP )
      {
		PM_StuckJumpMove();
	   }
   else
      {
		// airborne
		if ( !pm->ps->in_vehicle )
			PM_AirMove();
	   }

   walking = pml.walking;

	// set groundentity, watertype, and waterlevel
	PM_GroundTrace();
	PM_SetWaterLevel();

   // don't fall down stairs or do really short falls
   if ( !pml.walking && ( walking || ( ( pml.previous_velocity[ 2 ] >= 0 ) && ( pm->ps->velocity[ 2 ] <= 0 ) ) ) )
      {
	   vec3_t   point;
	   trace_t  trace;

	   point[ 0 ] = pm->ps->origin[ 0 ];
	   point[ 1 ] = pm->ps->origin[ 1 ];
	   point[ 2 ] = pm->ps->origin[ 2 ] - 0.5;

	   pm->trace( &trace, pm->ps->origin, pm->mins, pm->maxs, point, pm->ps->clientNum, pm->tracemask, qtrue );
      if ( ( trace.fraction < 1.0f ) && ( !trace.allsolid ) )
         {
   		VectorCopy( trace.endpos, pm->ps->origin );

         // allow client to smooth out the step
   		pm->stepped = qtrue;

         // requantify the player's position
         PM_GroundTrace();
   	   PM_SetWaterLevel();
         }
      }

	// entering / leaving water splashes
	PM_WaterEvents();


	// test stuff
	
	// snap some parts of playerstate to save network bandwidth
	SnapVector( pm->ps->velocity );
   }

/*
================
Pmove

Can be called by either the server or the client
================
*/
void Pmove (pmove_t *pmove) {
	int			finalTime;

	finalTime = pmove->cmd.serverTime;

	if ( finalTime < pmove->ps->commandTime ) {
		return;	// should not happen
	}

	if ( finalTime > pmove->ps->commandTime + 1000 ) {
		pmove->ps->commandTime = finalTime - 1000;
	}

	// chop the move up if it is too long, to prevent framerate
	// dependent behavior
	while ( pmove->ps->commandTime != finalTime ) {
		int		msec;

		msec = finalTime - pmove->ps->commandTime;

		if ( msec > 50 ) {
			msec = 50;
		}
		pmove->cmd.serverTime = pmove->ps->commandTime + msec;
		PmoveSingle( pmove );
		//Com_Printf("Vel: %f\n",pm->ps->velocity[2]);
	}

}
