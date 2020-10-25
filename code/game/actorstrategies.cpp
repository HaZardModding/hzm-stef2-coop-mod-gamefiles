#include "actorstrategies.h"
#include "player.h"


//=========================================
// ActorThink Implementation
//=========================================
// Think can be subclassed if needed, ( ie BossThink, NPC Think ) etc.
// Granted, this may not be likely, but the flexibility is there, and
// it keeps this rather large function out of Actor.

///////////////////////////////////////////
//
// Name: ActorThink()
// 
// Description: Constructor
//
///////////////////////////////////////////
ActorThink::ActorThink()
   {
	
	}


///////////////////////////////////////////
//
// Name: Think()
// 
// Description: Base Think Strategy
//
///////////////////////////////////////////
void ActorThink::Think( Actor *act )
   {
	// Update boss health if necessary

	if ( act->GetActorFlag( ACTOR_FLAG_UPDATE_BOSS_HEALTH ) && act->max_boss_health && act->mode == ACTOR_MODE_AI )
		{
		char bosshealth_string[20];
		sprintf( bosshealth_string, "%.5f", act->health / act->max_boss_health );
		gi.cvar_set( "bosshealth", bosshealth_string );
		}

	// Check for the ground

	if ( act->last_origin != act->origin )
		act->SetActorFlag( ACTOR_FLAG_HAVE_MOVED, true );

	if ( !( act->flags & FL_SWIM ) && !( act->flags & FL_FLY ) )
		{
		if ( act->GetActorFlag( ACTOR_FLAG_HAVE_MOVED ) ||
  		   ( act->groundentity && act->groundentity->entity && act->groundentity->entity->entnum != ENTITYNUM_WORLD ) )
			act->CheckGround();
		}

	// Do falling stuff

	if ( act->groundentity )
		{
		if ( !act->Immune( MOD_FALLING ) && !( act->flags & FL_FLY ) && ( act->origin.z + 1000 < act->last_ground_z ) )
			act->Damage( world, world, 1000, act->origin, vec_zero, vec_zero, 0, DAMAGE_NO_ARMOR, MOD_FALLING );

		act->last_ground_z = act->origin.z;
		}

	act->last_origin = act->origin;

	if ( !act->deadflag )
		{
		// Check to see if stunned

		act->CheckStun();

		// See if can talk to the player
		
		if(act->DialogMode == DIALOG_TYPE_ANXIOUS)
			act->TryTalkToPlayer();

		act->TryBlink();
		
		//Handle Game Specific Stuff
		if ( act->gameComponent )
			act->gameComponent->HandleThink();
		
		// Make sure we can still see our enemy

		if ( act->max_inactive_time && act->currentEnemy && act->next_enemy_try_sight_time < level.time && !act->IsBlind() )
			{
			float next_sight_delay;

			next_sight_delay = act->max_inactive_time / 5 + G_CRandom( 0.5 );

			if ( next_sight_delay < 1 )
				next_sight_delay = 1;

			act->next_enemy_try_sight_time = level.time + next_sight_delay;

			if ( !level.ai_on )
				{
				act->last_enemy_sight_time = level.time;
				}
			else
				{
				if ( act->CanSeeEnemyFrom( act->origin ) )
					{
					act->last_enemy_sight_time = level.time;
					if ( act->paranoiaTime >= level.time )
						act->updateParanoia( STIMULI_SIGHT );
					}
				else
					if ( level.time >= act->paranoiaTime )
						{
						act->decreaseParanoia(1);
						}

				if ( act->last_enemy_sight_time + act->max_inactive_time < level.time )
					act->currentEnemy = NULL;
				}
			}

		// If actor doesn't have an enemy right now try to find one
		if ( act->targetType != ATTACK_SCRIPTED_ONLY && act->targetType != ATTACK_LEVEL_INTERACTION )
			{
			if ( !act->IsBlind() && !act->IsEntityAlive ( act->currentEnemy ) && !act->GetActorFlag(ACTOR_FLAG_WAIT_FOR_NEW_ENEMY) && act->next_find_enemy_time <= level.time )
				{
				if ( level.ai_on )
					act->FindEnemy();
				act->next_find_enemy_time = level.time + .8 + G_Random( .4 );
				}
			
			if ( !act->currentEnemy )
				act->FindEnemy();
			}

		// Make sure actor is not immobilized

		if ( act->flags & FL_IMMOBILE || act->flags & FL_PARTIAL_IMMOBILE )
			{
			act->animate->StopAnimating();
			return;
			}

		// Do the state machine for this creature

		act->ProcessActorStateMachine();

		// See if we should go back to sleep

		if ( ( act->mode == ACTOR_MODE_AI || act->mode == ACTOR_MODE_IDLE ) && !act->currentEnemy && !act->GetActorFlag( ACTOR_FLAG_INVESTIGATING )
				&& act->next_try_sleep_time < level.time )
			{
			Player *player;

			act->next_try_sleep_time = level.time + 1.0;
			
			for(int i = 0; i < game.maxclients; i++)
				{
				player = GetPlayer(i);
				
				//if ( act->mode == ACTOR_MODE_IDLE && player && !(player->flags & FL_NOTARGET) && gi.inPVS( player->centroid, act->centroid ) &&
				//	( world->farplane_distance == 0 || Distance( player->centroid, act->centroid ) < world->farplane_distance ) )
			   if ( act->mode == ACTOR_MODE_IDLE && player && !(player->flags & FL_NOTARGET) && gi.inPVS( player->centroid, act->centroid ) &&
					( world->farplane_distance == 0 || act->CanSee(player) ))
					act->last_time_active = level.time;

				if ( !level.ai_on )
					act->last_time_active = level.time;

				if ( act->max_inactive_time && act->last_time_active + 5 < level.time )
					{
					if ( act->mode == ACTOR_MODE_AI )
						{
						act->EndMode();

						act->Sleep();

						if ( act->idle_thread.length() > 1 )
							{
							//ScriptThread *thread = ExecuteThread( idle_thread, false );
							ExecuteThread( act->idle_thread, false );
							}
						}
					else
						{
						act->Sleep();
						}
					}
				}
			}
		else if ( act->currentEnemy || act->GetActorFlag( ACTOR_FLAG_INVESTIGATING ) || act->mode == ACTOR_MODE_SCRIPT || act->mode == ACTOR_MODE_TALK )
			{
			act->last_time_active = level.time;
			}

		if ( act->actortype == IS_INANIMATE )
			{
			if ( act->behavior && !act->behavior->Evaluate( *act ) )
				{
				// stop thinking
				act->flags &= ~FL_THINK;
				act->EndBehavior();

				// remove them from the active list
				ActiveList.RemoveObject( (Actor*)act );
				}

			if ( act->headBehavior && !act->headBehavior->Evaluate( *act ) )
				{
				// stop thinking
				act->flags &= ~FL_THINK;
				act->EndHeadBehavior();

				// remove them from the active list
				ActiveList.RemoveObject( ( Actor * )act );
				}

			if ( act->eyeBehavior && !act->eyeBehavior->Evaluate( *act ) )
				{
				// stop thinking
				act->flags &= ~FL_THINK;
				act->EndEyeBehavior();

				// remove them from the active list
				ActiveList.RemoveObject( ( Actor * )act );
				}
			
			if ( act->torsoBehavior && !act->torsoBehavior->Evaluate( *act ) )
				{
				// stop thinking
				act->flags &= ~FL_THINK;
				act->EndTorsoBehavior();

				// remove them from the active list
				ActiveList.RemoveObject( ( Actor * )act );
				}			
			
			return;
			}

		act->eyeposition[ 2 ] = act->maxs[ 2 ] + act->eyeoffset[ 2 ];
		//angles.z = 0;

		// Process the current behavior

		if ( act->behavior && !act->behavior->Evaluate( *act ) )
			{
			if ( stricmp( act->behavior->getClassname(), "Talk" ) == 0 )
				{
				act->EndBehavior();
				act->EndMode();
				}
			else
				{
				act->EndBehavior();
				}			

			// Process state machine again because the behavior finished
			act->ProcessActorStateMachine();
			}

		// Process the current head behavior

		if ( act->headBehavior && !act->headBehavior->Evaluate( *act ) )
			{
			act->EndHeadBehavior();

			// Process state machine again because the behavior finished
			act->ProcessActorStateMachine();
			}

		// Process the current eye behavior

		if ( act->eyeBehavior && !act->eyeBehavior->Evaluate( *act ) )
			{
			act->EndEyeBehavior();

			// Process state machine again because the behavior finished
			act->ProcessActorStateMachine();
			}

		// Process the current torso behavior

		if ( act->torsoBehavior && !act->torsoBehavior->Evaluate( *act ) )
			{
			act->EndTorsoBehavior();

			// Process state machine again because the behavior finished
			act->ProcessActorStateMachine();
			}

		// Reset the animation is done flag

		act->SetActorFlag( ACTOR_FLAG_ANIM_DONE, false );
		act->SetActorFlag( ACTOR_FLAG_TORSO_ANIM_DONE, false );

		// Change the animation if necessary

		if ( act->newanimnum != -1 || act->newTorsoAnimNum != -1)
			act->ChangeAnim();	
	
      }

	// Do the movement

	if ( !(act->flags & FL_IMMOBILE) && !(act->flags & FL_PARTIAL_IMMOBILE) )
		{
		act->CalcMove();
		act->lastmove = STEPMOVE_STUCK;

		if ( act->flags & FL_SWIM )
			act->lastmove = act->WaterMove();
		else if ( act->flags & FL_FLY )
			act->lastmove = act->AirMove();
		else
			act->lastmove = act->TryMove();
		}

	if ( !act->deadflag )
		{
		// See if we should damage the actor because of waterlevel

		if ( act->waterlevel == 3 && !( act->flags & FL_SWIM ) )
			{
			// if out of air, start drowning
			if ( act->air_finished < level.time )
				{
				// we may have been in a water brush when we spawned, so check our water level again to be sure
				act->CheckWater();
				if ( act->waterlevel < 3 )
					{
					// we're ok, so reset our air
					act->air_finished = level.time + 5;
					}
				else if ( act->next_drown_time < level.time && act->health > 0 )
					{
					// drown!
					act->next_drown_time = level.time + 1;

					//Sound( "snd_uwchoke", CHAN_VOICE );
					act->BroadcastSound();

					act->Damage( world, world, 15, act->origin, vec_zero, vec_zero, 0, DAMAGE_NO_ARMOR, MOD_DROWN );
					}
				}
			}
		else
			{
			act->air_finished = level.time + 5;
			}

		if (
            ( act->movetype != MOVETYPE_NONE ) &&
		      ( act->movetype != MOVETYPE_STATIONARY ) &&
				act->GetActorFlag( ACTOR_FLAG_TOUCH_TRIGGERS ) &&
				act->GetActorFlag( ACTOR_FLAG_HAVE_MOVED )
         )
			G_TouchTriggers( act );

		if ( act->groundentity && ( act->groundentity->entity != world ) && !M_CheckBottom( act ) )
			{
			// G_FixCheckBottom( this );
			act->flags |= FL_PARTIALGROUND;
			}
		}
	}


