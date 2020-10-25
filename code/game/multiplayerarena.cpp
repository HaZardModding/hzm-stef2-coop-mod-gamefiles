//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/multiplayerArena.cpp                            $
// $Revision:: 4                                                              $
//   $Author:: Kharward                                                       $
//     $Date:: 12.05.01 5:00p                                                 $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/multiplayerArena.cpp                                 $
// 
// 4     12.05.01 5:00p Kharward
// Added support for determining if the match is over by fraglimit.
// 
// 3     11.05.01 5:24p Kharward
// Added team class so that all multiplayer games can use it.  Made some
// modifications to support team based play.
// 
// 2     10.05.01 12:00p Kharward
// Fixed bug in respawning after a death in deathmatch.  Added better support
// for adding weapons to weapon list at start of match.
// 
// 1     9.05.01 7:22p Kharward
// MultiplayerArena class and derived classes (DeathmatchArena)
// 
// Description:
//     Implementation of MultiplayerArena abstract base class and derived
//     classes.  These classes provided multiplayer support.
//


#include "multiplayerArena.h"


//------------------------------------------------------------------
//                A R E N A   R E G I S T E R
//------------------------------------------------------------------
Container<str> ArenaRegister::_arenaList ;

//------------------------------------------------------------------
//                        T E A M
//------------------------------------------------------------------

// Connect events to class methods
CLASS_DECLARATION( Listener, Team, NULL )
   {
      { NULL, NULL }
   };

//================================================================
// Name:        Team
// Class:       Team
//              
// Description: Constructor
//              
// Parameters:  const str& -- name of the team
//              
// Returns:     None
//              
//================================================================
Team::Team
	(
	const str& name
	)
	:	_name(name),
		_startingHealth(0), // indicates use arena's default
		_maxPlayers(5),
		_wins(0),
		_losses(0),
		_kills(0),
		_deaths(0),
		_isFighting(false)
	{
	}


//================================================================
// Name:        ~Team
// Class:       Team
//              
// Description: Destructor
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
Team::~Team()
	{
	}

//================================================================
// Name:        AddDeath
// Class:       Team
//              
// Description: Adds a death for this team if the specified victim
//              is indeed on the team.  Also notifies all participants
//              in the arena of the event.
//              
// Parameters:  Player *victim -- this team's player who died
//              Player *killer -- opposing team's player who made the kill.  Not used in base class
//              
// Returns:     None
//              
//================================================================
void Team::AddDeath
	(
	Player* victim,
	Player* 
	)
	{
		assert(victim);
		if (!victim)
		{
			warning("Team::AddDeath", "NULL Player\n");
			return ;
		}

		if (!_playerList.ObjectInList(victim))
		{
			warning("Team::AddDeath", va("%s is not a member of %s", victim->client->pers.netname, getName()));
			return ;
		}

		_deaths++ ;		
	}

//================================================================
// Name:        AddKill
// Class:       Team
//              
// Description: Adds a kill for this team if the specified killer
//              is indeed on the team.
//              
// Parameters:  Player* killer -- this team's player who made the kill
//              Player* victim -- opposing team's player who died.  Not used base class
//              
// Returns:     None
//              
//================================================================
void Team::AddKill
	(
	Player *killer,
	Player *
	)
	{
		assert(killer);
		if (!killer)
		{
			warning("Team::AddKill", "NULL Player\n");
			return ;
		}

		if (!_playerList.ObjectInList(killer))
		{
			warning("Team::AddKill", va("%s is not a member of %s", killer->client->pers.netname, getName()));
			return ;
		}

		_kills++ ;
	}

//================================================================
// Name:        Win
// Class:       Team
//              
// Description: Increments number of wins for this team.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void Team::Win()
	{
		_wins++ ;
	}



//================================================================
// Name:        Lose
// Class:       Team
//              
// Description: Increments number of losses for this team
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void Team::Lose()
	{
		_losses++ ;
	}



//================================================================
// Name:        BeginMatch
// Class:       Team
//              
// Description: Activates all the players on the team
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void Team::BeginMatch()
	{
		for (int idx = 1; idx <= _playerList.NumObjects(); idx++)
		{
			Player *player = _playerList.ObjectAt(idx);
			assert(player);
			if (!player)
			{
				warning("Team::endMatch", "NULL Player in team list\n");
				continue ;
			}
			_activatePlayer(player);
		}
	}


//================================================================
// Name:        EndMatch
// Class:       Team
//              
// Description: Deactivates all the players on the team
//              (turns off fighting).
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void Team::EndMatch()
	{
		for (int idx = 1; idx <= _playerList.NumObjects(); idx++)
		{
			Player *player = _playerList.ObjectAt(idx);
			assert(player);
			if (!player)
			{
				warning("Team::endMatch", "NULL Player in team list\n");
				continue ;
			}
			_deactivatePlayer(player);
		}
	}


//================================================================
// Name:        AddPlayer
// Class:       Team
//              
// Description: Adds a player to the team.
//              
// Parameters:  Player* -- player to add
//              
// Returns:     None
//              
//================================================================
void Team::AddPlayer
	(
	Player* player
	)
	{
		assert(player);
		if (!player)
		{
			warning("Team::AddPlayer", va("Attempt to add NULL player to %s\n", getName()));
			return ;
		}

		if (_playerList.NumObjects() == _maxPlayers)
		{
			warning("Team::AddPlayer", va("The %s team is full!\n", getName()));
			return ;
		}
		_playerList.AddObject(player);
		player->SetMultiplayerTeam(this);
		
		// If we are in the middle of a match, prepare them for fighting
		if (isFighting())
		{
			_activatePlayer( player );
		}
	}


//================================================================
// Name:        RemovePlayer
// Class:       Team
//              
// Description: Removes a player from the team
//              
// Parameters:  Player* -- player to remove
//              
// Returns:     None
//              
//================================================================
void Team::RemovePlayer
	(
	Player *player
	)
	{
		assert(player);
		if (!player)
		{
			warning("Team::RemovePlayer", va("Attempt to add NULL player to %s\n", getName()));
			return ;
		}

		if (_playerList.ObjectInList(player))
		{
			warning("Team::RemovePlayer", va("Player %s is not on team %s\n", player->client->pers.netname, getName()));
			return ;
		}
		_playerList.RemoveObject(player);
		player->SetMultiplayerTeam(NULL);
}


//================================================================
// Name:        AddStartingAmmo
// Class:       Team
//              
// Description: Adds the specified ammo to the list of initial ammo
//              to give players on this team.
//              
// Parameters:  SimpleAmmoType -- ammo to add
//              
// Returns:     None
//              
//================================================================
void Team::AddStartingAmmo
	(
	SimpleAmmoType ammo
	)
	{
		_ammoList.AddObject(ammo);
	}


//================================================================
// Name:        AddStartingWeapon
// Class:       Team
//              
// Description: Adds the specified starting weapon to the list of
//              weapons.
//              
// Parameters:  const str& -- weapon to add
//              
// Returns:     None
//              
//================================================================
void Team::AddStartingWeapon
	(
	const str& weaponName
	)
	{
		_weaponList.AddObject(weaponName);
	}

//----------------------------------------------------------------
//               P R O T E C T E D   M E T H O D S
//----------------------------------------------------------------


//================================================================
// Name:        _giveInitialConditions
// Class:       Team
//              
// Description: Gives the specified player the starting health, ammo,
//              and weapons for this team.  If starting health is 0,
//              no health is applied to the player meaning the player
//              will get the arena default (typically 100).
//              
// Parameters:  Player* -- player to recieve initial conditions
//              
// Returns:     None
//              
//================================================================
void Team::_giveInitialConditions
	(
	Player *player
	)
	{
		assert(player);
		if (!player)
		{
			warning("Team::_giveWeaponsAndAmmo", "NULL Player passed\n");
			return ;
		}

		if (isStartingHealth())
		{
//			Event* healthEvent = new Event(EV_Set_Health);
//			healthEvent->AddInteger(getStartingHealth());
//			player->ProcessEvent(healthEvent);
		}

		int idx = 0;
		// Give weapons
		for (idx=1; idx <= _weaponList.NumObjects(); idx++)
		{
			player->giveItem(_weaponList.ObjectAt(idx));
		}

		// Give ammo
		for (idx=1; idx <= _ammoList.NumObjects(); idx++)
		{
			SimpleAmmoType& ammo = _ammoList.ObjectAt(idx);
			player->giveItem(ammo.type, ammo.amount);
		}
	}


//================================================================
// Name:        _activatePlayer
// Class:       Team
//              
// Description: Activates the specified player.  This player is 
//              given any special weapons and ammo and the appropriate
//              starting health (if any).
//
//              This routine also attempts to give the player a 
//              team speicfic spawn point if there is one.
//
//              
// Parameters:  Player* -- player to activate
//              
// Returns:     None
//              
//================================================================
void Team::_activatePlayer
	(
	Player *player
	)
	{
		_giveInitialConditions(player);
		player->BeginFight();
		player->takedamage = DAMAGE_YES ;
	}	



//================================================================
// Name:        _deactivatePlayer
// Class:       Team
//              
// Description: Removes the player from battle.  For now, this is
//              simply turning off the fighting enabled flag and
//              putting them into spectator mode.
//              
// Parameters:  Player* -- player to deactivate
//              
// Returns:     None
//              
//================================================================
void Team::_deactivatePlayer
	(
	Player *player
	)
	{
		assert(player);
		if (!player)
		{
			warning("Team::_deactivatePlayer", va("NULL Player passed to %s team\n", getName()));
			return ;
		}

		player->EndFight();
		player->takedamage = DAMAGE_NO ;
}



// MultiplayerArena Events

Event EV_Arena_SetName
   (
   "name",
   EV_DEFAULT,
   "s",
   "name",
   "set the name of the arena"
   );
Event EV_Arena_SetHealth
   (
   "starting_health",
   EV_DEFAULT,
   "i",
   "health",
   "set the starting health of each player"
   );
Event EV_Arena_EndMatch
   (
   "endmatch",
   EV_DEFAULT,
   NULL,
   NULL,
   "End the current match"
   );
Event EV_Arena_AddWeapon
   (
   "addstartingweapon",
   EV_DEFAULT,
   "s",
   "weaponmodel",
   "Add this weapon to the list of weapons that will be used in this match"
   );
Event EV_Arena_AddAmmo
   (
   "addstartingammo",
   EV_DEFAULT,
   "si",
   "ammotype amount",
   "Add this ammo to the players when they start the match"
   );


// Connect events to class methods
CLASS_DECLARATION( Listener, MultiplayerArena, NULL )
   {
      { &EV_Arena_SetName,                   SetName },
      { &EV_Arena_SetHealth,                 SetStartingHealth },
      { &EV_Arena_EndMatch,                  EndMatch },
      { &EV_Arena_AddWeapon,                 AddStartingWeapon },
      { &EV_Arena_AddAmmo,                   AddStartingAmmo },
      { NULL, NULL }
   };


//================================================================
// Name:        MultiplayerArena
// Class:       MultiplayerArena
//              
// Description: Constructor
//              
// Parameters:  const str& -- name of the arena
//              
// Returns:     None
//              
//================================================================
MultiplayerArena::MultiplayerArena(const str& name)
	:	_name(name),
		_maxPlayers(20),
		_id(-1),
		_startingHealth(100),
		_fragLimit(0),
		_fightInProgress(false)
	{
	}


//================================================================
// Name:        ~MultiplayerArena
// Class:       MultiplayerArena
//              
// Description: Destructor
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
MultiplayerArena::~MultiplayerArena()
	{
		int idx = 0 ;
		for (idx = 1; idx <= _ammoList.NumObjects(); idx++)
		{
			SimpleAmmoType* ammo = _ammoList.ObjectAt(idx);
			delete ammo ;
			ammo = 0 ;
		}
	}


//================================================================
// Name:        isEndOfMatch
// Class:       MultiplayerArena
//              
// Description: Checks to see if the end of match conditions have been
//              met.  Only condition in the base class is a single
//              player exceeding the frag limit (if set).
//              
// Parameters:  None
//              
// Returns:     bool -- true if the match should now end
//              
//================================================================
bool MultiplayerArena::isEndOfMatch
	(
	void
	)
	{
		if (!getFragLimit()) return false ;

		for (int idx=1; idx <= _playerList.NumObjects(); idx++)
		{
			Player* player = _playerList.ObjectAt(idx);
			if (player->GetNumKills() >= getFragLimit())
			{
				return true ;
			}
		}
		return false ;
	}


//================================================================
// Name:        Score
// Class:       MultiplayerArena
//              
// Description: Sends the current score to the specified player.
//              
// Parameters:  Player* -- player to send score to.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::Score
	(
	Player *player
	)
	{
		char		   string[1400];
		char		   entry[1024];
		int            j            = 0 ;
		int            count        = 0 ;
		int            stringlength = 0 ;

		assert( player );
		if ( !player )
		{
			warning( "MultiplayerArena::Score", "Null Player specified.\n" );
			return;
		}

		string[0]  = 0;
		entry[0]   = 0;

		// This for loop builds a string containing all the players scores.
		for(int idx = 1; idx <= _playerList.NumObjects(); idx++ )
		{
			Player *pl = _playerList.ObjectAt( idx );
			
			assert( pl );
			if ( !pl )
			{
				continue;
			}

			Com_sprintf( entry, sizeof( entry ), "%i %i %i %i %i %i %i ",
												   pl->client->ps.clientNum,
												   pl->GetNumKills(),
												   pl->GetNumDeaths(),
												   pl->GetMatchesWon(),
												   pl->GetMatchesLost(),
												   (int)(level.time - pl->client->pers.enterTime)/60,
												   pl->client->ping
						);

			j = strlen(entry);
			if (stringlength + j > 1024)
				break;
			strcpy (string + stringlength, entry);
			stringlength += j;
			count++;
		}

		gi.SendServerCommand( player->edict-g_entities, "scores %i %s", count, string );
	}



//================================================================
// Name:        CenterPrintClientsInArena
// Class:       MultiplayerArena
//              
// Description: Prints specified message to all players in the arena.
//              Prints to center of their screen.  Typically used
//              to communicate changes in arena state.
//              
// Parameters:  const str& -- message to send
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::CenterPrintClientsInArena
   (
   const str &string
   )
   {
		for(int idx=1; idx<=_playerList.NumObjects(); idx++ )
		{
			Player *player = _playerList.ObjectAt( idx );

			assert( player );
			if ( !player )
				continue;

			gi.centerprintf( player->edict, string );
		}
	}

//================================================================
// Name:        HUDPrintClientsInArena
// Class:       MultiplayerArena
//              
// Description: Prints specified message to all players in the arena.
//              Prints to their HUD using HUDPrint.  Typically used
//              for I don't know what.
//              
// Parameters:  const str& -- message to send
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::HUDPrintClientsInArena
	(
	const str &string
	)
	{
		for(int idx=1; idx <= _playerList.NumObjects(); idx++ )
		{
			Player *player = _playerList.ObjectAt( idx );

			assert( player );
			if ( !player )
				continue;

			player->HUDPrint( string );
		}
	}


//================================================================
// Name:        EndMatch
// Class:       MultiplayerArena
//              
// Description: Event method.  Ends the current match.  All players
//              are set to non-fighting state. Calls _endMatch to
//              enable sub-classes to customize match ending.
//              
// Parameters:  Event* -- pointer to triggering event.  Not used.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::EndMatch
	(
	Event *
	)
	{
		EndMatch();
	}


//=================================================================
//DM_Arena::ResetArena - Resets the arena.  This is called when
//something bad or unexpected happens.
//=================================================================
void MultiplayerArena::ResetArena
	(
	void
	)
	{
	// Something bad happened reset the entire arena
	}




//================================================================
// Name:        PlayerKilled
// Class:       MultiplayerArena
//              
// Description: Do appropriate thing when player has been killed.
//              Base class puts up a dead body and hides the player
//              model.
//              
// Parameters:  Player* -- player that was killed.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::PlayerKilled
	(
	Player *player
	)
	{
		assert(player);
		if (!player)
		{
			warning("MultiplayerArena::PlayerKilled", "NULL Player\n");
			return ;
		}

		player->DeadBody( NULL );
		player->hideModel();
	}

//================================================================
// Name:        AddStartingWeapon
// Class:       MultiplayerArena
//              
// Description: Adds the specified weapon to the list of weapons
//              the player starts with.  The string must be a .tik
//              file.
//              
// Parameters:  const str& -- viewmodel name (eg. viewmodel_peacemaker.tik);
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::AddStartingWeapon
	(
	const str& weaponViewmodel
	)
	{
		_weaponList.AddObject(weaponViewmodel);
	}


//================================================================
// Name:        AddStartingWeapon
// Class:       MultiplayerArena
//              
// Description: Event method.  Adds the specified weapon to the list
//              of weapons given to each player when they join an arena.
//              
// Parameters:  Event* -- Event.  First argument is string name of weapon.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::AddStartingWeapon
	(
	Event *ev
	)
	{
		str string = ev->GetString( 1 );
		_weaponList.AddObject( string );
	}


//================================================================
// Name:        AddStartingAmmo
// Class:       MultiplayerArena
//              
// Description: Event method.  Adds the specified ammo to the list
//              of ammo given to each player when they join an arena.
//              
// Parameters:  Event* -- Event. First argument is string name of ammo,
//                        second argument is amount.
//                        
// Returns:     None
//              
//================================================================
void MultiplayerArena::AddStartingAmmo
	(
	Event *ev
	)
	{
		SimpleAmmoType *ammo = new SimpleAmmoType(ev->GetString( 1 ), ev->GetInteger( 2 ));
		_ammoList.AddObject( ammo );
	}



//================================================================
// Name:        ActivatePlayer
// Class:       MultiplayerArena
//              
// Description: Activates the specified player.  Activation includes
//              loading skin and giving appropriate weapons and ammo.
//              
// Parameters:  Player* -- player to be activated
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::ActivatePlayer
	(
	Player* player
	)
	{
		assert( player );
		if ( !player )
		{
			warning("MultiplayerArena::ActivatePlayer", "NULL Player\n");
			return ;
		}

		player->EnterArena( _startingHealth, 0 );
		player->setModel( player->client->pers.dm_playermodel );
		_giveInitialConditions( player );
	}



//================================================================
// Name:        BeginMatch
// Class:       MultiplayerArena
//              
// Description: Begins the match.  Resets the spawn points and calls
//              _beginMatch so subclasses can do their special thing.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::BeginMatch
	(
	void
	)
	{
		_fightInProgress = true ;
		ResetSpawnpoints();
		_beginMatch();
	}



//================================================================
// Name:        EndMatch
// Class:       MultiplayerArena
//              
// Description: Ends the match.  Resets the spawn points and calls
//              _endMatch so subclasses can do their special thing.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::EndMatch
	(
	void
	)
	{
		_fightInProgress = false ;
		ResetSpawnpoints();
		_endMatch();
	}

//================================================================
// Name:        ResetSpawnpoints
// Class:       MultiplayerArena
//              
// Description: Resets the spawnpoints in the arena.  This list
//              of spawnpoints is doled out as people enter the arena.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::ResetSpawnpoints
	(
	void
	)
	{
		// This builds a list of all the spawnpoints in the arena, which will be
		// removed as each one is used at start
		_unusedSpawnpointList.ClearObjectList();

		for( int idx = 1; idx <= _spawnpointList.NumObjects(); idx++ )
		{
			_unusedSpawnpointList.AddObject( _spawnpointList.ObjectAt( idx ) );
		}
	}


//================================================================
// Name:        SetName
// Class:       MultiplayerArena
//              
// Description: Event method.  Sets the name of the arena to the
//              specified string.
//              
// Parameters:  Event* -- Event pointer.  First string argument is
//                        the new name of the arena.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::SetName
	(
	Event *ev
	)
	{
		_name = ev->GetString( 1 );
		UpdateArenaInfo();
	}

//================================================================
// Name:        UpdateArenaInfo
// Class:       MultiplayerArena
//              
// Description: Updates the config string with name of the arena.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::UpdateArenaInfo
	(
	void
	)
	{

		assert( _id > 0 );
		if (_id < 0) 
		{
			warning( "MultiplayerArena::UpdateArenaInfo", "Arena id number is not set\n");
			return ;
		}

		str s = va( "#%d-%s-(%d) player(s)", _id, _name.c_str(), _playerList.NumObjects() );
		gi.setConfigstring( CS_ARENA_INFO + _id, s );
	}



//================================================================
// Name:        AddPlayer
// Class:       MultiplayerArena
//              
// Description: Adds the specified player to the list of players
//              
// Parameters:  Player* -- player to add
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::AddPlayer
	(
	Player *player
	)
	{
		_playerList.AddObject( player );
		player->SetMultiplayerArena( this ); // give player a pointer to this arena
		HUDPrintClientsInArena( va( "%s joined the arena\n", player->client->pers.netname ) );
	}


//================================================================
// Name:        RemovePlayer
// Class:       MultiplayerArena
//              
// Description: Removes a player from this arena.
//              
// Parameters:  Player* -- player to remove
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::RemovePlayer
	(
	Player *player
	)
	{
		// Remove player from the list and print message to clients in this arena
		if ( _playerList.ObjectInList( player ) )
		{
			_playerList.RemoveObject( player );
			HUDPrintClientsInArena( va( "%s left the arena\n", player->client->pers.netname ) );
		}

		// Player is out of arena
		player->SetMultiplayerArena( NULL );

		UpdateArenaInfo();
	}


//================================================================
// Name:        SetMaxPlayers
// Class:       MultiplayerArena
//              
// Description: Sets the maximum players allowed in the arena.
//              
// Parameters:  Event* -- Event.  First integer argument is the max
//                        number of players.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::SetMaxPlayers
	(
	Event *ev
	)
	{
		_maxPlayers = ev->GetInteger( 1 );
	}



//================================================================
// Name:        SetStartingHealth
// Class:       MultiplayerArena
//              
// Description: Sets the starting health for all players
//              
// Parameters:  Event* -- Event.  First integer argument is the 
//                        amount of starting health for all players.
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::SetStartingHealth
	(
	Event *ev
	)
	{
		assert(ev);
		if (!ev)
		{
			return ;
		}

		if (ev->NumArgs() != 1)
		{
			return ;
		}

		_startingHealth = ev->GetInteger( 1 );
	}


//================================================================
// Name:        setID
// Class:       MultiplayerArena
//              
// Description: Sets the ID for this arena.  Once this id has been
//              specified, all player deathmatch starting objects
//              with a matching ID are put into the spawnpoint list.
//
//              This enables a map to have multiple arenas with each
//              having distinct deathmatch start points.
//
//              At this time, if a deathmatch starting point is found
//              without an arena, it is added as a deathmatch for this
//              arena.  This is for ease of use with maps that have not
//              been setup as having multiple arenas.  However, it would
//              also probably screw up a multiple arena map that wasn't
//              properly built.  FYI
//              
// Parameters:  int -- ID for this arena
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::setID
	(
	int id
	)
	{
		_id = id;

		// Find all the deathmatch starts that match this id number
		PlayerDeathmatchStart *deathmatchStart = ( PlayerDeathmatchStart * )G_FindClass( NULL, "info_player_deathmatch" );
		while (deathmatchStart)
		{
			if (!deathmatchStart->arena || deathmatchStart->arena == _id)
			{
				 _spawnpointList.AddObject( deathmatchStart );
			}
			deathmatchStart = ( PlayerDeathmatchStart * )G_FindClass( deathmatchStart, "info_player_deathmatch" );
		}
	}



//----------------------------------------------------------------
//             P R O T E C T E D   M E T H O D S
//----------------------------------------------------------------


//================================================================
// Name:        _beginMatch
// Class:       MultiplayerArena
//              
// Description: Begins the match.  All players in the arena have
//              BeginFight() called on them to enable fighting.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::_beginMatch()
	{
		for(int idx=1; idx <= _playerList.NumObjects(); idx++ )
		{
			Player *player = _playerList.ObjectAt( idx );

			assert( player );
			if ( !player )
			{
				continue;
			}

            player->BeginFight();
		}
	}
//================================================================
// Name:        _endMatch
// Class:       MultiplayerArena
//              
// Description: Ends the match.  All players in the arena have
//              EndFight() called on them to disable fighting.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::_endMatch()
	{
		for(int idx=1; idx <= _playerList.NumObjects(); idx++ )
		{
			Player *player = _playerList.ObjectAt( idx );

			assert( player );
			if ( !player )
			{
				continue;
			}

            player->EndFight();
		}
	}

//================================================================
// Name:        _giveInitialConditions
// Class:       MultiplayerArena
//              
// Description: Gives the specified player the weapons and ammo
//              designated for this arena.
//              
// Parameters:  Player* -- player to receive weapons
//              
// Returns:     None
//              
//================================================================
void MultiplayerArena::_giveInitialConditions
	(
	Player *player
	)
	{
		int idx ;

		assert( player );
		if ( !player )
		{
			warning( "MultiplayerArena::_giveInitialConditions", "NULL player specified.\n" );
			return;
		}

		for ( idx=1; idx <= _weaponList.NumObjects(); idx++ )
		{
			Event *ev = new Event( "weapon" );
			ev->AddToken( _weaponList.ObjectAt( idx ) );
			player->ProcessEvent( ev ); // deletes the created Event
		}

		for ( idx=1; idx <= _ammoList.NumObjects(); idx++ )
		{
			Event *ev = new Event( "ammo" );
			ev->AddString( _ammoList.ObjectAt( idx )->type );
			ev->AddInteger( _ammoList.ObjectAt( idx )->amount );
			player->ProcessEvent( ev ); // deletes the created Event
		}
	}

//================================================================
// Name:        _getSpawnpoint
// Class:       MultiplayerArena
//              
// Description: Retrieves a spawnpoint from the spawnpoint list.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
Entity* MultiplayerArena::_getSpawnpoint
	(
	void
	)
	{
		Entity *spot  = NULL;
		int numPoints = _unusedSpawnpointList.NumObjects();

		if ( !numPoints )
		{
			warning( "MultiplayerArena::GetSpawnpoint", "No spawnpoints found in arena\n" );
			return NULL;
		}
		else
		{
			int selection = ( G_Random() * numPoints ) + 1;
			spot = ( Entity * )_unusedSpawnpointList.ObjectAt( selection );
			_unusedSpawnpointList.RemoveObjectAt( selection );
			return spot;
		}
	}


//================================================================
// Name:        _getRandomSpawnpoint
// Class:       MultiplayerArena
//              
// Description: Retrieves a random spawnpoint from the spawnpoint list.
//              
// Parameters:  bool -- set to true if you want spawnpoint doled out
//                      on order of player's arriving in arena (ie non-random).
//              
// Returns:     None
//              
//================================================================
Entity* MultiplayerArena::_getRandomSpawnpoint
	(
	bool useCounter
	)
	{
		Entity *spot=NULL;

		int numPoints = _spawnpointList.NumObjects();

		if ( !numPoints )
		{
			warning( "MultiplayerArena::GetRandomSpawnpoint", "No spawnpoints found in arena\n" );
			return NULL;
		}

		if ( useCounter )
		{
			if ( _spawncounter > numPoints )
			{
				_spawncounter = 1; // reuse spawn points 
			}

			spot = ( Entity * )_spawnpointList.ObjectAt( _spawncounter );
			_spawncounter++;
			return spot;
		}
				
		int selection = ( G_Random() * numPoints ) + 1;
		spot = ( Entity * )_spawnpointList.ObjectAt( selection );
		return spot;
	}



//--------------------------------------------------------------
//             D E A T H M A T C H   A R E N A
//--------------------------------------------------------------

// Connect events to class methods
CLASS_DECLARATION( MultiplayerArena, DeathmatchArena, NULL )
   {
      { NULL, NULL }
   };

REGISTER_ARENA( DeathmatchArena );

//================================================================
// Name:        DeathmatchArena
// Class:       DeathmatchArena
//              
// Description: Constructor
//              
// Parameters:  const str& -- name of the arena
//              
// Returns:     None
//              
//================================================================
DeathmatchArena::DeathmatchArena
	(
		const str& name
	)
	:	MultiplayerArena(name)
	{
		AddStartingWeapon("viewmodel_peacemaker.tik");
	}


//================================================================
// Name:        ~DeathmatchArena
// Class:       DeathmatchArena
//              
// Description: Destructor
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
DeathmatchArena::~DeathmatchArena()
	{
		//
	}



//================================================================
// Name:        PlayerKilled
// Class:       DeathmatchArena
//              
// Description: Tags specified player as having been killed.
//              
// Parameters:  Player* -- player that has been killed
//              
// Returns:     None
//              
//================================================================
void DeathmatchArena::PlayerKilled
	(
	Player* player
	)
	{
		assert(player);
		if (!player)
		{
			warning("DeathmatchArena::PlayerKilled", "NULL player\n");
			return ;
		}

		MultiplayerArena::PlayerKilled(player);
		player->WarpToPoint(_getRandomSpawnpoint());
		ActivatePlayer(player);
		player->Init();
	}


//================================================================
// Name:        AddPlayer
// Class:       DeathmatchArena
//              
// Description: Adds a player to the arena.  In deathmatch, this
//              also sets their spawn point and immediately sets 
//              them up for fighting.
//              
// Parameters:  Player* -- Player to add and prepare for fighting
//              
// Returns:     None
//              
//================================================================
void DeathmatchArena::AddPlayer
	(
	Player* player
	)
	{
		assert(player);
		if (!player)
		{
			warning("DeathmatchArena::AddPlayer", "NULL Player\n");
			return ; 
		}

		MultiplayerArena::AddPlayer(player);
		player->WarpToPoint( _getSpawnpoint() );
		ActivatePlayer(player);
		CenterPrintClientsInArena( va( "%s joined the match.\n", player->client->pers.netname ) );
	}


//================================================================
// Name:        ActivatePlayer
// Class:       DeathmatchArena
//              
// Description: Enables deathmatching for the player.  Calls the
//              base class ActivatePlayer to get common activation
//              functionality, such as entering the arena and setting
//              base health, ammo, and weapons.
//
//              Toggles fighting on and damage taking on.
//              
// Parameters:  Player* -- pointer to player to activate
//              
// Returns:     None
//              
//================================================================
/* virtual */
void DeathmatchArena::ActivatePlayer
	(
	Player* player
	)
	{
		MultiplayerArena::ActivatePlayer(player);
        player->BeginFight();
        player->takedamage = DAMAGE_YES;
	}

