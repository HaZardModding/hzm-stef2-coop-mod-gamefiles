//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/multiplayerArena.h                              $
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
// $Log:: /red_code/game/multiplayerArena.h                                   $
// 
// 4     12.05.01 5:00p Kharward
// Added support for determining if the match is over by fraglimit.
// 
// 3     11.05.01 5:24p Kharward
// Added team class so that all multiplayer games can use it.  Made some
// modifications to support team based play.
// 
// 2     10.05.01 12:01p Kharward
// Added ActivatePlayer to Deathmatch arena.
// 
// 1     9.05.01 7:22p Kharward
// MultiplayerArena class and derived classes (DeathmatchArena)
// 
// Description:
//    Contains classes for playing multiplayer games.  The base class,
//    MultiplayerArena, is abstract, and provides common functionality
//    such as tracking players.  Derived classes provide game-specific
//    functionality, such as DeathmatchArena which is straight deathmatch.
//

// Forward declarations
class SimpleAmmoType ;
class Team ;
class MultiplayerArena ;
class DeathmatchArena ;

#ifndef __MULTIPLAYER_ARENA_H__
#define __MULTIPLAYER_ARENA_H__

#include "g_local.h"          // common game stuff
#include "player.h"           // for Player
#include "playerstart.h"      // for PlayerDeathmatchStart
#include "container.h"        // for Container
#include "str.h"              // for str

#define CLASS_ARENA( className )     class className##Register : public ArenaRegister { public: className##Register() : ArenaRegister(#className) { } };
#define REGISTER_ARENA( className )  className##Register className##RegisterInstance


//-------------------------------------------------------------------
// SimpleAmmoType -- Defines a type of ammo and a quantity.  Used for
//                   starting players with specified ammo in multiplayer.
//-------------------------------------------------------------------
class SimpleAmmoType : public Class
	{
	public:
		SimpleAmmoType() : type(""), amount(0) { } 
		SimpleAmmoType(const str& ammoType, int ammoAmount) : type(ammoType), amount(ammoAmount) { }
		str   type;
		int   amount;
	};


//-----------------------------------------------------------------------
// ArenaRegister -- This class is just a container for all possible arena types.
//                  Arena classes that define their own proxy class derived
//                  from this type will ensure they get identified as a possible
//                  multiplayer game type.
//-----------------------------------------------------------------------
class ArenaRegister
	{
	private:
		static Container<str>        _arenaList ;

	protected:
		ArenaRegister(const str& className)                          { _arenaList.AddObject(className); }

	public:
		virtual ~ArenaRegister()                                     { }

		static Container<str>&       getArenaList()                  { return _arenaList ; }
	};


//-----------------------------------------------------------------------
// Team -- A multiplayer team.  The team has a name, starting ammo, weapons,
//         and health, and skins.  The team class tracks kills and deaths
//         on a team basis.
//-----------------------------------------------------------------------
class Team : public Listener
	{
	private:
		Container<Player*>                  _playerList ;       // Players on this team
		Container<str>                      _weaponList ;       // starting weapons for just this team
		Container<SimpleAmmoType>           _ammoList ;         // starting ammo for just this team
		Container<PlayerDeathmatchStart*>   _spawnpointList;    // spawnpoints for just this team
		unsigned int                        _maxPlayers ;       // Maximum players on this team
		unsigned int                        _startingHealth ;   // starting health for just this team
		unsigned int                        _wins ;             // matches won
		unsigned int                        _losses ;           // matches lost
		unsigned int                        _kills ;            // kills of an opposing team
		unsigned int                        _deaths ;           // kills of this team
		bool                                _isFighting ;       // true if match has begun
		str                                 _name ;             // can be used to reference the team thru events

	protected:
		void                                _giveInitialConditions(Player *player); // gives initial health, ammo, and weapons to player
		void                                _activatePlayer(Player* player);        // prepares player for fight
		void                                _deactivatePlayer(Player* player);      // turns off fighting for player

	public:
		CLASS_PROTOTYPE( Team );
		Team(const str& name="Unnamed Team");
		virtual ~Team();

		// Queries
		bool                                isStartingHealth()                  { return (_startingHealth > 0) ? true : false ; }
		bool                                isFighting()                        { return _isFighting ; }

		// Gets
		const str&                          getName()                           { return _name ; }
		unsigned int                        getKills()                          { return _kills ; }
		unsigned int                        getDeaths()                         { return _deaths ; }
		unsigned int                        getWins()                           { return _wins ; }
		unsigned int                        getLosses()                         { return _losses ; }
		unsigned int                        getMaxPlayers()                     { return _maxPlayers ; }
		unsigned int                        getActivePlayers()                  { return _playerList.NumObjects(); }

		// Sets
		void                                setStartingHealth(unsigned int h)   { _startingHealth = h ; }
		void                                setMaxPlayers(unsigned int players) { _maxPlayers = players ; }
		
		// Match functions
		void                                BeginMatch();
		void                                EndMatch();

		// Player functions
		void                                AddPlayer(Player* player);
		void                                RemovePlayer(Player* player);

		// Initial conditions functions
		void                                AddStartingWeapon(const str& weaponName);
		void                                AddStartingAmmo(SimpleAmmoType ammo);
		void                                AddSpawnpoint(PlayerDeathmatchStart* spawnpoint);

		// Stat functions
		void                                AddKill(Player* killer, Player* victim=NULL);  // try to track who we killed
		void                                AddDeath(Player* victim, Player* killer=NULL); // try to track who killed us
		void                                Win();
		void                                Lose();
};


//-----------------------------------------------------------------------
// MultiplayerArena --  Abstract base class providing common functionality
//                      to all multiplayer game types.  Tracks players 
//                      entering the arena, starting the match, etc.
//-----------------------------------------------------------------------
class MultiplayerArena : public Listener
	{
	private:

		Container<Player *>					_playerList;
		Container<PlayerDeathmatchStart *>	_spawnpointList;
		Container<PlayerDeathmatchStart *>	_unusedSpawnpointList;
		Container<str>                      _weaponList;
		Container<SimpleAmmoType *>         _ammoList;
		unsigned int						_maxPlayers ;
		unsigned int						_activePlayers ;
		unsigned int						_spawncounter ;
		unsigned int                        _startingHealth ;
		unsigned int						_fragLimit ;
		bool								_fightInProgress ;
		int									_id ;
		str									_name;


	protected:
		// Abstract constructor
		MultiplayerArena(const str& name="Unnamed Arena");
		
		Entity *							_getSpawnpoint( void );
		Entity *							_getRandomSpawnpoint( bool useCounter = false );
		
		virtual void                        _endMatch();
		virtual void                        _beginMatch();
		virtual void                        _giveInitialConditions(Player* player);

		// Event-catchers
		void								SetName          ( Event *ev );
		void								SetMaxPlayers    ( Event *ev );
		void								SetStartingHealth( Event *ev );
		void								AddStartingWeapon( Event *ev );
		void								AddStartingAmmo  ( Event *ev );
		void								EndMatch         ( Event *ev );

	public:
		CLASS_PROTOTYPE( MultiplayerArena );
		virtual	~MultiplayerArena();

		// Queries
		virtual bool                        isEndOfMatch( void );
		bool								isFightInProgress()                             { return _fightInProgress ; }

		// Gets
		inline int							getID( void )                                   { return _id; }
		inline unsigned int                 getStartingHealth( void )                       { return _startingHealth ; }
		inline unsigned int                 getMaxPlayers( void )                           { return _maxPlayers ; }
		inline unsigned int                 getActivePlayers( void )                        { return _activePlayers ; }
		inline unsigned int					getFragLimit( void )							{ return _fragLimit ; }
		
		// Sets
		void								setID( int id );
		void                                setStartingHealth( unsigned int startingHealth) { _startingHealth = startingHealth ; }
		void								setFragLimit( unsigned int fragLimit)           { _fragLimit      = fragLimit ; }

		// Arena wide functions
		virtual void						ResetSpawnpoints( void );
		virtual void						ResetArena( void );
		virtual void						BeginMatch( void );
		virtual void                        EndMatch( void );
		virtual void						UpdateArenaInfo( void );

		// Player specific functions
		virtual void						ActivatePlayer( Player *player );
		virtual void						AddPlayer( Player *player );
		virtual void						RemovePlayer( Player *player );
		virtual void						PlayerKilled( Player *player );		
		virtual void						Score( Player *player );

		// Utility functions
		void								AddStartingWeapon(const str& weaponViewmodel);
		void								CenterPrintClientsInArena( const str &string );
		void								HUDPrintClientsInArena( const str &string );
	};



//-----------------------------------------------------------------------
// DeathmatchArena --  Implements plain-old deathmatch (PODM).
//-----------------------------------------------------------------------
CLASS_ARENA( DeathmatchArena );
class DeathmatchArena : public MultiplayerArena
	{
	private:

	protected:		
//		virtual void						BeginMatch( void );
//		virtual void						UpdateArenaInfo( void );
//		virtual void						CheckEndMatch( void );

	public:
		CLASS_PROTOTYPE( DeathmatchArena );
		DeathmatchArena(const str& name="Deathmatch Arena");
		virtual	~DeathmatchArena();
		
		/* virtual */ void					AddPlayer     ( Player *player );
		/* virtual */ void					ActivatePlayer( Player *player );
		/* virtual */ void					PlayerKilled  ( Player *player );
	};


#endif /* __MULTIPLAYER_ARENA_H__ */