//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/teamArena.h                                     $
// $Revision:: 2                                                              $
//   $Author:: Kharward                                                       $
//     $Date:: 12.05.01 5:00p                                                 $
//
// Copyright (C) 2001 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/teamArena.h                                          $
// 
// 2     12.05.01 5:00p Kharward
// Added support for determining if a team match is over.
// 
// 1     11.05.01 5:22p Kharward
// Initial check in of Multiplayer Team-related classes.
// 
// 
// Description:
//    Classes for Team based multiplayer games.  TeamArena is an
//    abstract base class for Team-support in Multiplayer games.
//    Derived classes implement specific team play, such as capture
//    the flag (CTF).  I suppose if you're reading this, you already
//    knew what CTF stood for.
//

// Forward declarations
class TeamArena ;
class CaptureTheFlagArena ;

#ifndef __TEAM_ARENA_H__
#define __TEAM_ARENA_H__


#include "multiplayerArena.h" // for base class MultiplayerArena and dependent headers


//-----------------------------------------------------------------------
// TeamArena --  Abstract base class providing common team-based 
//               multiplayer functionality.  Uses the Team class to 
//               compose multiple teams of players.  Tracks team
//               kills and assigns skins and such.
//-----------------------------------------------------------------------
class TeamArena : public MultiplayerArena
	{
	private:
		Container<Team *>					_teamList;      // list of teams
		unsigned int                        _maxTeams ;     // maximum number of teams allowed (default is 2)
		bool								_forceJoin ;    // true forces players to join a team upon entering arena (default true)
		bool								_friendlyFire ; // true means you can damage your teammates (default false)
		Team*								_leadTeam ;     // If set, this team is currently "winning"


	protected:
		// Abstract constructor
		TeamArena(const str& name="Team Arena");
	
		/* virtual */ void					_endMatch();    // Notifies teams of end of match
		/* virtual */ void                  _beginMatch();  // Notifies teams of start of match
	
		// Event-catchers
		void                                SetTeamStartingHealth( Event *ev );
		void                                AddTeamStartingWeapon( Event *ev );
		void                                AddTeamStartingAmmo  ( Event *ev );

		// Utility functions
		Team*                               _findTeamByName(const str& teamName);
		void                                _deleteTeams();
		void                                _deleteTeam(Team* team);
		void                                _addTeamStartingAmmo(Team* team, SimpleAmmoType ammo);
		void                                _addTeamStartingWeapon(Team* team, const str& weapon);
		void                                _setTeamStartingHealth(Team* team, unsigned int startingHealth);


	public:
		CLASS_PROTOTYPE( TeamArena );
		virtual	~TeamArena();

		// Queries
		/* virtual */ bool					isEndOfMatch();                            // Checks for team frag limits met
		bool                                isForceJoining()                           { return _forceJoin ; }

		// Gets
		unsigned int                        getMaxTeams()                              { return _maxTeams ; }
		Team*                               getLeadTeam()                              { return _leadTeam ; }

		// Sets
		virtual void                        SetMaxTeams(unsigned int maxTeams)         { _maxTeams = maxTeams ; }
		virtual void                        SetTeamStartingHealth(const str& teamName, unsigned int startingHealth);


		// Player specific functions
		/* virtual */ void					AddPlayer( Player *player );                    // if force join is set, will stick on team with fewest members
		/* virtual */ void					RemovePlayer( Player *player );
		/* virtual */ void					PlayerKilled( Player *player );
		/* virtual */ void					Score( Player *player );

		// Team specific functions
		virtual void                        AddTeamStartingWeapon(const str& teamName, const str& startingWeapon);
		virtual void                        AddTeamStartingAmmo(const str& teamName,    const str& ammoName, int amount);
		virtual Team*                       AddTeam(const str& name);
		virtual void                        RemoveTeam(const str& name);
	};


//---------------------------------------------------------------------
// CaptureTheFlagArena -- Capture the Flag Multiplayer.  Classic CTF
//                        style gameplay.
//---------------------------------------------------------------------
CLASS_ARENA( CaptureTheFlagArena );
class CaptureTheFlagArena : public TeamArena
	{
	private:
		Team*                               _redTeam ;
		Team*                               _blueTeam ;

	protected:
		/* virtual */ void					_endMatch();    // Notifies teams of end of match

	public:
		CLASS_PROTOTYPE( CaptureTheFlagArena );
		CaptureTheFlagArena(const str& name="Capture The Flag");
		~CaptureTheFlagArena();

		/* virtual */ void                  AddPlayer( Player *player );
		/* virtual */ void                  ActivatePlayer( Player *player );
		/* virtual */ void                  PlayerKilled( Player *player );
	};


#endif /* __TEAM_ARENA_H__ */