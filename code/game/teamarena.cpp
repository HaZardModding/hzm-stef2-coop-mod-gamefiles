//------------------------------------------------------------------------------
//
//  $Logfile:: /EF2/game/teamArena.cpp                                         $
// $Revision:: 3                                                               $
//   $Author:: Steven                                                          $
//     $Date:: 8/29/01 6:06p                                                   $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /EF2/game/teamArena.cpp                                              $
// 
// 3     8/29/01 6:06p Steven
// Took out some bogus checking code.
// 
// 2     12.05.01 5:00p Kharward
// Added support for determining if a team match is over.
// 
// 1     11.05.01 5:22p Kharward
// Initial check in of Multiplayer Team-related classes.
//
// Description:
//    Implementation of Team and TeamArena classes.  These classes provide
//    Team-based multiplayer support.
//

#include "teamArena.h"

// Connect events to class methods
CLASS_DECLARATION( MultiplayerArena, TeamArena, NULL )
   {
      { NULL, NULL }
   };


//-----------------------------------------------------------------
//                   T E A M   A R E N A
//-----------------------------------------------------------------

//================================================================
// Name:        TeamArena
// Class:       TeamArena
//              
// Description: Constructor
//              
// Parameters:  const str& -- name of the arena
//              
// Returns:     None
//              
//================================================================
TeamArena::TeamArena
	(
	const str& name
	)
	:	MultiplayerArena(name),
		_forceJoin(true),
		_friendlyFire(false),
		_maxTeams(2),
		_leadTeam(NULL)
	{
	}


//================================================================
// Name:        ~TeamArena
// Class:       TeamArena
//              
// Description: Destructor
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================

TeamArena::~TeamArena()
	{
		_deleteTeams();
	}

//================================================================
// Name:        isEndOfMatch   
// Class:       TeamArena
//              
// Description: Determines if either team has met the frag limit.
//              If so, announces a winner (should the base team 
//              arena be so bold?). 
//
//              If there is no frag limit set, no check is made.
//              
// Parameters:  None
//              
// Returns:     bool -- true if the match has ended based on fraglimit
//              
//================================================================
bool TeamArena::isEndOfMatch
	(
	void
	)
	{
		if (!getFragLimit())
		{
			return false ;
		}
		for (int idx=1; idx <= _teamList.NumObjects(); idx++) 
		{
			Team* team = _teamList.ObjectAt(idx);
			if (team->getDeaths() > getFragLimit())
			{
				CenterPrintClientsInArena(va("%s team Loses!\n", team->getName()));
				return true ;
			}
		}
		return false ;
	}

//================================================================
// Name:        AddPlayer
// Class:       TeamArena
//              
// Description: Adds a player to the arena.  If force join is on,
//              this player will be force to join with the fewest
//              players.
//              
// Parameters:  Player* -- player to add
//              
// Returns:     None
//              
//================================================================
void TeamArena::AddPlayer
	(
	Player *player
	)
	{
		MultiplayerArena::AddPlayer(player);	
		if (isForceJoining())
		{
			Team* pickedTeam   = 0 ;
			Team* team         = 0 ;
			int minimumPlayers = 0 ;

			for (int idx = 1; idx <= _teamList.NumObjects(); idx++)
			{
				team    = _teamList.ObjectAt(idx);
				
				assert(team);
				if (!team)
				{
					continue ;
				}
				
				int players = team->getActivePlayers();
				if ( (players < minimumPlayers) || (!pickedTeam) )
				{
					pickedTeam     = team ;
					minimumPlayers = players ;
				}
			}

			if (pickedTeam)
			{
				pickedTeam->AddPlayer(player);
				CenterPrintClientsInArena(va("%s joined the %s team.\n", player->client->pers.netname, pickedTeam->getName()));
			}
		}
	}


//================================================================
// Name:        RemovePlayer
// Class:       TeamArena
//              
// Description: Removes a player from the arena.  If the player is
//              a member of a team, the player is removed from the
//              team as well.
//              
// Parameters:  Player* -- player to remove
//              
// Returns:     None
//              
//================================================================
void TeamArena::RemovePlayer
	(
	Player *player
	)
	{
		MultiplayerArena::RemovePlayer(player);
		Team* team = player->GetMultiplayerTeam();
		if (team)
		{
			team->RemovePlayer(player);
		}
	}


//================================================================
// Name:        AddTeam
// Class:       TeamArena
//              
// Description: Adds a team to the arena.  Checks to ensure that the
//              max number of teams has not yet been exceeded.
//              
// Parameters:  const str& -- new name of team
//              
// Returns:     Team* -- Created team (NULL if failed to create)
//              
//================================================================
Team* TeamArena::AddTeam
	(
	const str& teamName
	)
	{
		Team* team = _findTeamByName(teamName);
		if (team)
		{
			warning("TeamArena::AddTeam", va("Team %s already exists\n", teamName));
			return NULL ;
		}

		team = new Team(teamName);
		team->setMaxPlayers(getMaxPlayers() / getMaxTeams());
		_teamList.AddObject( team );

		return team ;
	}


//================================================================
// Name:        RemoveTeam
// Class:       TeamArena
//              
// Description: Removes and deletes the team specified by name from
//              the arena.  Calls _deleteTeam to do actual removal.
//              
// Parameters:  
//              
// Returns:     
//              
//================================================================
void TeamArena::RemoveTeam
	(
	const str& teamName
	)
	{
		Team* team = _findTeamByName(teamName);
		_deleteTeam(team);
	}



//================================================================
// Name:        AddTeamStartingAmmo
// Class:       TeamArena
//              
// Description: Adds team-specific ammo.  This enables a particular
//              team to receive a specific amount and/or type of ammo.
//              Calls _addTeamStartingAmmo() to actually give it to the team.
//              
// Parameters:  const str& teamName -- team to receive the ammo
//              const str& ammoName -- name of ammo to give
//              int        amount   -- amount of ammo to give
//              
// Returns:     None
//              
//================================================================
void TeamArena::AddTeamStartingAmmo
	(
	const str& teamName,
	const str& ammoName,
	int        amount
	)
	{
		Team* team = _findTeamByName(teamName);
		SimpleAmmoType ammoType(ammoName, amount);
		_addTeamStartingAmmo(team, ammoType);
	}


//================================================================
// Name:        AddTeamStartingAmmo
// Class:       TeamArena
//              
// Description: Event-catcher.  Adds team-specific ammo.  This enables a particular
//              team to receive a specific amount and/or type of ammo.
//              Calls _addTeamStartingAmmo() to actually give it to the team.
//              
// Parameters:  Event* -- Event
//                Arg 1: String name of team
//                Arg 2: String name of ammo
//                Arg 3: Integer amount of ammo
//              
// Returns:     None
//              
//================================================================
void TeamArena::AddTeamStartingAmmo
	(
	Event* ev
	)
	{
		assert(ev);
		if (!ev)
		{
			warning("TeamArena::AddTeamStartingAmmo", "NULL event\n");
			return ;
		}

		if (ev->NumArgs() != 3)
		{
			warning("TeamArena::AddTeamStartingAmmo", "Usage: addTeamAmmo <team> <ammo> <amount>\n");
			return ;
		}

		Team* team = _findTeamByName(ev->GetString( 1 ));
		SimpleAmmoType ammoType(ev->GetString( 2 ), ev->GetInteger( 3 ));
		_addTeamStartingAmmo(team, ammoType);
	}


//================================================================
// Name:        AddTeamStartingWeapon
// Class:       TeamArena
//              
// Description: Adds team-specific weapon.  This enables a particular
//              team to receive a specific weapon. Calls _addTeamStartingWeapon() 
//              to actually give it to the team.
//              
// Parameters:  const str& teamName   -- team to receive the ammo
//              const str& weaponName -- name of weapon to give
//              
// Returns:     None
//              
//================================================================
void TeamArena::AddTeamStartingWeapon
	(
	const str& teamName,
	const str& weaponName
	)
	{
		Team* team = _findTeamByName(teamName);
		_addTeamStartingWeapon(team, weaponName);
	}


//================================================================
// Name:        AddTeamStartingWeapon
// Class:       TeamArena
//              
// Description: Event-catcher.  Adds team-specific weapon.  This enables a particular
//              team to receive a specific weapon.
//              Calls _addTeamStartingWeapon() to actually give it to the team.
//              
// Parameters:  Event* -- Event
//                Arg 1: String name of team
//                Arg 2: String name of weapon
//              
// Returns:     None
//              
//================================================================
void TeamArena::AddTeamStartingWeapon
	(
	Event *ev
	)
	{
		assert(ev);
		if (!ev)
		{
			warning("TeamArena::AddTeamStartingWeapon", "NULL event\n");
			return ;
		}

		if (ev->NumArgs() != 2)
		{
			warning("TeamArena::AddTeamStartingWeapon", "Usage: addTeamWeapon <team> <weapon>\n");
			return ;
		}

		Team* team = _findTeamByName(ev->GetString( 1 ));
		_addTeamStartingWeapon(team, ev->GetString( 2 ));
	}



//================================================================
// Name:        setTeamStartingHealth
// Class:       TeamArena
//              
// Description: Sets the starting health for the team.  Calls
//              _setTeamStartingHealth to do actual work.
//              
// Parameters:  const str&   -- team name
//              unsigned int -- amount of health
//              
// Returns:     None
//              
//================================================================
void TeamArena::SetTeamStartingHealth
	(
	const str    &teamName,
	unsigned int  startingHealth
	)
	{
		Team* team = _findTeamByName(teamName);
		_setTeamStartingHealth(team, startingHealth);
	}


//================================================================
// Name:        SetTeamStartingHealth
// Class:       TeamArena
//              
// Description: Event-catcher.  Sets the starting health for the 
//              specified team.  Calls _setTeamStartingHealth to
//              do the actual work.
//              
// Parameters:  Event* -- Event
//                 Arg 1: String  -- team name
//                 Arg 2: Integer -- amount
//              
// Returns:     None
//              
//================================================================
void TeamArena::SetTeamStartingHealth
	(
	Event *ev
	)
	{
		assert(ev);
		if (!ev)
		{
			warning("TeamArena::SetTeamStartingHealth", "NULL event\n");
			return ;
		}

		if (ev->NumArgs() != 2)
		{
			warning("TeamArena::SetTeamStartingHealth", "Usage: setTeamHealth <team> <health>\n");
			return ;
		}

		Team* team = _findTeamByName(ev->GetString( 1 ));
		_setTeamStartingHealth(team, ev->GetInteger( 2 ));
	}


//================================================================
// Name:        PlayerKilled
// Class:       TeamArena
//              
// Description: Specified player has been killed.  Notifies the
//              player's team of the death.
//              
// Parameters:  Player* -- player that has been killed
//              
// Returns:     None
//              
//================================================================
void TeamArena::PlayerKilled
	(
	Player* player
	)
	{
		assert(player);
		if (!player) 
		{
			return;
		}

		MultiplayerArena::PlayerKilled(player);
		Team* team = player->GetMultiplayerTeam();
		if (team)
		{
			team->AddDeath(player);
		}
	}


//================================================================
// Name:        Score
// Class:       TeamArena
//              
// Description: Tracks the score for the player.
//              
// Parameters:  Player* -- pointer to player to calculate a score for
//              
// Returns:     None
//              
//================================================================
/* virtual */
void TeamArena::Score
	(
	Player* player
	)
	{
	}



//----------------------------------------------------------------
//             P R O T E C T E D   M E T H O D S 
//----------------------------------------------------------------


//================================================================
// Name:        _addTeamStartingAmmo
// Class:       TeamArena
//              
// Description: Adds the specified ammo to the specified team.
//              
// Parameters:  Team*          -- team to receive the ammo
//              SimpleAmmoType -- ammo to receive 
//              
// Returns:     None
//              
//================================================================
void TeamArena::_addTeamStartingAmmo
	(
	Team*         team,
	SimpleAmmoType ammo
	)
	{
		// Check for valid team
		assert(team);
		if (!team)
		{
			warning("TeamArena::_addTeamStartingAmmo", "NULL team passed\n");
			return ;
		}

		// Check for valid ammo type 
		assert(ammo.type.length());
		if (!ammo.type.length())
		{
			warning("TeamArena::_addTeamStartingAmmo", "No ammo type specified\n");
			return ;
		}

		// Check for valid amount
		assert(ammo.amount > 0);
		if (ammo.amount < 0)
		{
			warning("TeamArena::_addTeamStartingAmmo", "Negative ammo amount specified\n");
			return ;
		}

		team->AddStartingAmmo(ammo);
	}


//================================================================
// Name:        _addTeamStartingWeapon
// Class:       TeamArena
//              
// Description: Adds the specified weapon to the specified team.
//              
// Parameters:  Team*       -- team to receive the ammo
//              const str&  -- weapon to receive 
//              
// Returns:     None
//              
//================================================================
void TeamArena::_addTeamStartingWeapon
	(
	Team*      team,
	const str& weaponName
	)
	{
		// Check for valid team
		assert(team);
		if (!team)
		{
			warning("TeamArena::_addTeamStartingWeapon", "NULL team passed\n");
			return ;
		}

		// Check for valid weaponName
		assert(weaponName.length());
		if (!weaponName.length())
		{
			warning("TeamArena::_addTeamStartingWeapon", "No weapon specified\n");
			return ;
		}

		team->AddStartingWeapon(weaponName);
	}


//================================================================
// Name:        _setTeamStartingHealth
// Class:       TeamArena
//              
// Description: Sets the specified team's starting health to the
//              specified value.  A starting health of 0 means to
//              use the arena's default value (typicaly 100).
//              
// Parameters:  Team*        -- team to affect
//              unsigned int -- amount of starting health (must be >= 0)
//              
// Returns:     None
//              
//================================================================
void TeamArena::_setTeamStartingHealth
	(
	Team*        team,
	unsigned int startingHealth
	)
	{
		// Check for valid team
		assert(team);
		if (!team)
		{
			warning("TeamArena::_addTeamStartingWeapon", "NULL team passed\n");
			return ;
		}

		/* assert(startingHealth >= 0);
		if (startingHealth < 0)
		{
			warning("TeamArena::_setTeamStartingHealth", va("Cannot set health to %d\n", startingHealth));
			return ;
		} */

		team->setStartingHealth(startingHealth);
	}


//================================================================
// Name:        _deleteTeams
// Class:       TeamArena
//              
// Description: Deletes all the teams currently in the arena.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void TeamArena::_deleteTeams()
	{
		for (int idx = 1; idx <= _teamList.NumObjects(); idx++)
		{
			Team* team = _teamList.ObjectAt(idx);
			_deleteTeam(team);
		}
	}


//================================================================
// Name:        _deleteTeam
// Class:       TeamArena
//              
// Description: Removes the specified team from the arena and deletes it.
//              Minimal error checking since it is an internal function.
//              
// Parameters:  Team* -- team to remove and delete
//              
// Returns:     None
//              
//================================================================
void TeamArena::_deleteTeam
	(
	Team* team
	)
	{
		assert(team);
		if (!team)
		{
			warning("TeamArena::_removeTeam", "NULL Team passed\n");
			return ;
		}

		_teamList.RemoveObject(team);
		delete team ;
	}



//================================================================
// Name:        _beginMatch
// Class:       TeamArena
//              
// Description: Called when a match begins.  Calls BeginMatch on
//              every team in the arena.  The teams are responsible
//              for preparing the participants for battle.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void TeamArena::_beginMatch()
	{
		for (int idx = 1; idx <= _teamList.NumObjects(); idx++)
		{
			Team* team = _teamList.ObjectAt(idx);
			team->BeginMatch();
		}
	}


//================================================================
// Name:        _endMatch
// Class:       TeamArena
//              
// Description: Called when a match ends.  Calls EndMatch on
//              every team in the arena.  The teams are responsible
//              for removing the players from battle-readiness.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void TeamArena::_endMatch()
	{
		for (int idx = 1; idx <= _teamList.NumObjects(); idx++)
		{
			Team* team = _teamList.ObjectAt(idx);
			team->EndMatch();
		}
	}


//================================================================
// Name:        _findTeamByName
// Class:       TeamArena
//              
// Description: Retrieves a pointer to the team having the specified name.
//              
// Parameters:  const str& -- name of the team to retrieve
//              
// Returns:     Team* -- pointer to team found (NULL if not found)
//              
//================================================================
Team* TeamArena::_findTeamByName
	(
	const str& teamName
	)
	{
		assert(teamName.length());
		if (!teamName.length())
		{
			warning("TeamArena::_findTeamByName", "Team name not specified\n");
			return NULL ;
		}

		Team* team = NULL ;
		for (int idx = 1; idx <= _teamList.NumObjects(); idx++)
		{
			team = _teamList.ObjectAt(idx);
			if (team->getName() == teamName)
			{
				return team ;
			}
		}

		return NULL ;
	}



//----------------------------------------------------------------
//          C A P T U R E   T H E   F L A G   A R E N A
//----------------------------------------------------------------


// Connect events to class methods
CLASS_DECLARATION( TeamArena, CaptureTheFlagArena, NULL )
   {
      { NULL, NULL }
   };

REGISTER_ARENA( CaptureTheFlagArena );

//================================================================
// Name:        CaptureTheFlagArena
// Class:       CaptureTheFlagArena
//              
// Description: Constructor
//              
// Parameters:  const str& -- name of the arena
//              
// Returns:     None
//              
//================================================================
CaptureTheFlagArena::CaptureTheFlagArena
	(
	const str &name
	)
	:	TeamArena(name)
	{
		_redTeam  = AddTeam("Red");
		_blueTeam = AddTeam("Blue");
	}


//================================================================
// Name:        ~CaptureTheFlagArena
// Class:       CaptureTheFlagArena
//              
// Description: Destructor
//              
// Parameters:  None
//              
// Returns:     None, dammit
//              
//================================================================
CaptureTheFlagArena::~CaptureTheFlagArena()
	{
	}



//================================================================
// Name:        PlayerKilled
// Class:       CaptureTheFlagArena
//              
// Description: Marks a player as having been killed.  Respawns
//              the player.
//             
//              This version in theory would respawn the player
//              on the appropriate side, but there aren't any
//              sides yet.
// 
// Parameters:  Player* -- player killed
//              
// Returns:     None
//              
//================================================================
void CaptureTheFlagArena::PlayerKilled
	(
	Player* player
	)
	{
		TeamArena::PlayerKilled(player);
		player->WarpToPoint(_getRandomSpawnpoint());
		ActivatePlayer(player);
		player->Init();
	}


//================================================================
// Name:        AddPlayer
// Class:       CaptureTheFlagArena
//              
// Description: Adds a player to the team with the lowest number
//              of players.  Calls TeamArena::AddPlayer to do this.
// 
//              If both teams have at least one player, the match
//              begins.
//              
// Parameters:  Player* -- player to add
//              
// Returns:     None
//              
//================================================================
void CaptureTheFlagArena::AddPlayer
	(
	Player *player
	)
	{
		TeamArena::AddPlayer( player );
		
		if (!isFightInProgress())
		{
			if (_redTeam->getActivePlayers() && _blueTeam->getActivePlayers())
			{
				BeginMatch();
			}
		}
	}


//================================================================
// Name:        ActivatePlayer
// Class:       CaptureTheFlagArena
//              
// Description: Sets up the player for fighting.
//              
// Parameters:  Player* -- player to activate
//              
// Returns:     None
//              
//================================================================
void CaptureTheFlagArena::ActivatePlayer
	(
	Player *player
	)
	{
		MultiplayerArena::ActivatePlayer(player);
        player->BeginFight();
        player->takedamage = DAMAGE_YES;
	}


//----------------------------------------------------------------
//              P R O T E C T E D   M E T H O D S
//----------------------------------------------------------------
void CaptureTheFlagArena::_endMatch
	(
	void
	)
	{
		CenterPrintClientsInArena("Match over\n");
	}