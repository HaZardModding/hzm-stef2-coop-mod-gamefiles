//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/dm_manager.h                                   $
// $Revision:: 4                                                              $
//   $Author:: Kharward                                                       $
//     $Date:: 12.05.01 5:00p                                                 $
//
// Copyright (C) 2000 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/dm_manager.h                                        $
// 
// 4     12.05.01 5:00p Kharward
// Added support for getting the gametype from the server through cvars and
// added a check to see if the match is over.
// 
// 3     9.05.01 7:23p Kharward
// Changed to use MultiplayerArena rather than DM_Arena.  Currently explicitly
// instantiates a DeathmatchArena rather than allowing player to choose.
// 
// 2     12/11/00 3:18p Steven
// Made str passing const references.
//
// 17    10/06/00 7:15p Aldie
// General DM fixes
//
// 16    10/02/00 11:55a Aldie
// Removed a useless container
//
// 15    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 14    9/28/00 1:46p Aldie
// Yet another multiplayer update
//
// 13    9/26/00 6:58p Aldie
// Another dm update - lots of stuff added
//
// 12    9/20/00 6:58p Aldie
// Another temporary checkin for deathmatch stuff
//
// 11    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 10    9/12/00 7:03p Aldie
// Complete overhaul of the deathmatch stuff I wrote 2 weeks ago.  More to
// come.  Intermediate checkin
//
// 9     9/01/00 7:09p Aldie
// More fakk arena work
//
// 8     8/30/00 6:35p Aldie
// More updates for deathmatch
//
// 7     30.08.00 5:30p Ericf
// Added more stuff, almost ready for testing
//
// 6     8/30/00 4:31p Aldie
// Adding more functionality to dm
//
// 5     30.08.00 3:35p Ericf
// Another revision...
//
// 4     30.08.00 3:26p Ericf
// Second Update
//
// 3     30.08.00 3:15p Ericf
// Second Update
//
// 2     30.08.00 11:38a Ericf
// First Version
//
// DESCRIPTION:
//

// Forward declaration
class Player;
class DM_Team ;

#ifndef __DM_MANAGER__
#define __DM_MANAGER__

// Typedefs
typedef SafePtr<DM_Team> DM_TeamPtr;
typedef SafePtr<Player> PlayerPtr;

#include "g_local.h"
#include "queue.h"
#include "playerstart.h"
#include "multiplayerArena.h"  // for MultiplayerArena and derived classes





//-------------------------------------------------------------------
// DM_Team -- Defines a team.  For use with DM_Arena class which is no
//            longer being used.
//-------------------------------------------------------------------
class DM_Team : public Listener
   {
   public:
      Container<Player *>     m_players;
      str                     m_teamname;
      int                     m_teamnumber;
      int                     m_index;
      int                     m_countdown;
      int                     m_teamwins;
      int                     m_wins_in_a_row;

      CLASS_PROTOTYPE( DM_Team );

                           DM_Team();

      void                 AddPlayer( Player *player );
      void                 RemovePlayer( Player *player );
      inline void          setName( const str &name ){ m_teamname = name; };
      inline str           getName( void ){ return m_teamname; };
      inline void          setNumber( int n ){ m_teamnumber = n; };
      inline int           getNumber( void ){ return m_teamnumber; };
      inline void          setIndex( int n ){ m_index = n; };
      inline int           getIndex( void ){ return m_index; };
      void                 TeamWin( void );
      void                 TeamLoss( void );
      void                 UpdateTeamStatus( void );
      void                 TeamInvulnerable( void );
      void                 BeginFight( void );
   };

/*
//-------------------------------------------------------------------
// DM_Arena -- Old team-centric FAKK multiplayer class.  Uses DM_Team
//             to categorize players into two teams.  Because this was
//             so team-centric, it is no longer being used.
//
//             Replaced with arena classes derived from MultiplayerArena.
//------------------------------------------------------------------
class DM_Arena : public Listener
   {
   private:
      friend class DM_Manager;
      str			m_name;
      int			m_num_players_per_team;
      int			m_num_active_players;
      int			m_starting_health;
      int			m_starting_water;
      int			m_id;
      int         m_countdown;
      int         m_spawncounter;
      bool        m_fightInProgress;
      int         m_teamcount;

      Container<Player *>					   m_players;
      Container<PlayerDeathmatchStart *>	m_spawnpoints;
      Container<PlayerDeathmatchStart *>	m_unusedSpawnpoints;
      Container<DM_TeamPtr>               m_fightingTeams;
      Queue                               m_teamQueue;
      Container<DM_TeamPtr>               m_teams;
      Container<str>                      m_weaponList;
      Container<SimpleAmmoType *>         m_ammoList;

      void                 ResetArena( void );
      void                 SetName( Event *ev );
      void                 SetHealth( Event *ev );
      void                 SetWater( Event *ev );
      void                 SetPlayersPerTeam( Event *ev );
      void                 UpdateArenaInfo( void );
      void                 ActivatePlayers( void );
      void                 Countdown( Event *ev );
      void                 CountdownFinished( void );
      void                 CheckEndMatch( void );
      void                 EndMatch( Event *ev );
      void                 BeginMatch( void );
      bool                 IsTeamAlive( DM_TeamPtr team );
      void                 TeamForfeitMatch( DM_TeamPtr forfeitTeam );
      void                 AddWeapon( Event *ev );
      void                 AddAmmo( Event *ev );
      void                 GiveWeaponsAndAmmo( Player *player );
      void                 HUDPrintClientsInArena( const str &string );
      void                 ResetSpawnpoints( void );
      Entity *             GetSpawnpoint( void );

   public:

      CLASS_PROTOTYPE( DM_Arena );

                           DM_Arena();
                           ~DM_Arena();
      void                 setID( int id );
      inline int           getID( void ){ return m_id; };
      void                 AddPlayer( Player *player );
      void                 RemovePlayer( Player *player );
      Entity *             GetRandomSpawnpoint( bool useCounter = false );
      void                 CreateTeam( Player *creator );
      void                 LeaveTeam( Player *player );
      void                 JoinTeam( Player *player, int team_number );
      void                 RemoveTeam( DM_TeamPtr team );
      void                 ResetTeams( void );
      void                 CenterPrintClientsInArena( const str &string );
      void                 PlayerKilled( Player *player );
      int                  GetLinePosition( Player *player );
      void                 Score( Player *player );
   };
*/

//----------------------------------------------------------------------
// DM_Manager -- Manages all aspects of multiplayer gameplay.  Instantiates
//               MultiplayerArena classes and adds players to the arenas.
//               The arenas themselves handle all rules of the game (such
//               as dividing players into teams).
//----------------------------------------------------------------------
class DM_Manager : public Listener
   {
	private:
		Container<MultiplayerArena *>   _arenas;
		unsigned int                    _gameType ;

	protected:
		void                            _passEventToArena(Event* ev, MultiplayerArena* arena);

	public:
		CLASS_PROTOTYPE( DM_Manager );

		DM_Manager();
		~DM_Manager();

		// Event-catchers
		void							ArenaCommand( Event *ev );
		void							NextGameType( Event *ev );

		void							AddPlayer( Player *player );
		void							JoinArena( Player *player, int arena_id_num );
		void							RemovePlayerFromAllArenas( Player *player );
		void							RemovePlayer( Player *player );
		void							PlayerKilled( Player *player );
		void							Reset( void );
		void                            Init( void );
		void							InitArenas( void );
		void							ArenaPrint( Entity *ent, const char *txt );
		void							Score( Player *player );
		void							PrintAllClients( const str &s );
	};


// Public access to dll global singleton DM_Manager
extern DM_Manager dmManager;


#endif // __DM_MANAGER__