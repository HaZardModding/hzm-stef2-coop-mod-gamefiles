//-----------------------------------------------------------------------------
//
//  $Logfile:: /red_code/game/dm_manager.cpp                                 $
// $Revision:: 7                                                              $
//   $Author:: Kharward                                                       $
//     $Date:: 12.05.01 5:00p                                                 $
//
// Copyright (C) 2000 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
// $Log:: /red_code/game/dm_manager.cpp                                      $
// 
// 7     12.05.01 5:00p Kharward
// Added support for getting the gametype from the server through cvars and
// added a check to see if the match is over.
// 
// 6     11.05.01 5:23p Kharward
// Changed player class so that it now has uses the new Team class for being a
// member of a multiplayer team.  Added methods to retrieve and set the teams.
// Adjusted existing functions appropriately.
// 
// 5     9.05.01 7:23p Kharward
// Changed to use MultiplayerArena rather than DM_Arena.  Currently explicitly
// instantiates a DeathmatchArena rather than allowing player to choose.
// 
// 2     12/11/00 3:16p Steven
// Made str passing const references.
//
// 21    10/06/00 7:15p Aldie
// General DM fixes
//
// 20    10/06/00 5:05p Aldie
//
// 19    10/04/00 6:50p Aldie
// Changed scores
//
// 18    10/02/00 5:38p Aldie
// Added gibbing to multiplayer stuff
//
// 17    10/02/00 11:54a Aldie
// Fix for pirnt all clients
//
// 16    9/28/00 6:51p Aldie
// Added more multiplayer options (voting)
//
// 15    9/28/00 1:46p Aldie
// Yet another multiplayer update
//
// 14    9/26/00 6:58p Aldie
// Another dm update - lots of stuff added
//
// 13    9/22/00 6:29p Aldie
// Fix for more than 1 team selection
//
// 12    9/22/00 6:10p Aldie
// Skin support
//
// 11    9/20/00 6:58p Aldie
// Another temporary checkin for deathmatch stuff
//
// 10    9/18/00 6:00p Aldie
// Periodic update for FakkArena deathmatch code.
//
// 9     9/12/00 7:03p Aldie
// Complete overhaul of the deathmatch stuff I wrote 2 weeks ago.  More to
// come.  Intermediate checkin
//
// 8     9/01/00 7:09p Aldie
// More fakk arena work
//
// 7     8/30/00 6:35p Aldie
// More updates for deathmatch
//
// 6     30.08.00 5:30p Ericf
// Added more stuff, almost ready for testing
//
// 5     8/30/00 4:31p Aldie
// Adding more functionality to dm
//
// 4     30.08.00 3:36p Ericf
// Another Revision...
//
// 3     30.08.00 3:15p Ericf
// Second Initial Update
//
// 2     30.08.00 11:37a Ericf
// First Version
//
// DESCRIPTION:
//

#include "player.h"
#include "dm_manager.h"
#include "teamArena.h"

#define TIME_MATCH_END_TO_START       8 // Seconds between match end and next match start
#define TIME_DELAY_DEATH_TO_SPECTATOR 3 // Seconds to wait from time of player's death till they become a spectator
#define TIME_COUNTDOWN                8 // Seconds to countdown for beginning a match

// Global DM Manager
DM_Manager dmManager;

//=================================================================
//
// DM_Team Object
//
//=================================================================
CLASS_DECLARATION( Listener, DM_Team, NULL )
   {
      { NULL, NULL }
   };

//=================================================================
//DM_Team::DM_Team
//=================================================================
DM_Team::DM_Team
   (
   )

   {
   m_teamwins      = 0;
   m_wins_in_a_row = 0;
   m_teamnumber    = -1;
   }

//=================================================================
//DM_Team::AddPlayer - Add a player to the team
//=================================================================
void DM_Team::AddPlayer
   (
   Player *player
   )

   {
   m_players.AddObject( player );
   }

//=================================================================
//DM_Team::AddPlayer - Remove a player from the team
//=================================================================
void DM_Team::RemovePlayer
   (
   Player *player
   )

   {
   m_players.RemoveObject( player );
   }

//=================================================================
//DM_Team::AddPlayer - Update the status bar for the team.  It will
//show the wins and wins in a row.
//=================================================================
void DM_Team::UpdateTeamStatus
   (
   void
   )

   {
   int i;

   for ( i=1; i<=m_players.NumObjects(); i++ )
      {
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         {
         continue;
         }

      player->UpdateStatus( va( "%d wins (%d in a row)", m_teamwins, m_wins_in_a_row ) );
      }
   }

//=================================================================
//DM_Team::TeamWin - Add a win to the team
//=================================================================
void DM_Team::TeamWin
   (
   void
   )

   {
   int i;

   m_teamwins++;
   m_wins_in_a_row++;

   for ( i=1; i<=m_players.NumObjects(); i++ )
      {
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         {
         continue;
         }

      player->WonMatch();
      }

   UpdateTeamStatus();
   }

//=================================================================
//DM_Team::TeamLoss - Add a loss to the team
//=================================================================
void DM_Team::TeamLoss
   (
   void
   )

   {
   int i;

   m_wins_in_a_row = 0;

   for ( i=1; i<=m_players.NumObjects(); i++ )
      {
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         {
         continue;
         }

      player->LostMatch();
      }

   UpdateTeamStatus();
   }

//=================================================================
//DM_Team::TeamInvulnerable - Make the team invulnerable to damage.
//Used for between matches.
//=================================================================
void DM_Team::TeamInvulnerable
   (
   void
   )

   {
   int i;

   for ( i=1; i<=m_players.NumObjects(); i++ )
      {
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         {
         continue;
         }

      player->takedamage = DAMAGE_NO;
      }
   }

//=================================================================
//DM_Team::BeginFight - Begin the fight for the team allowing them
//to take damage.  Player::BeginFight will spawn them in the
//appropriate place.
//=================================================================
void DM_Team::BeginFight
   (
   void
   )

   {
   int i;

   for ( i=1; i<=m_players.NumObjects(); i++ )
      {
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( player )
         {
         player->BeginFight();
         player->takedamage = DAMAGE_YES;
         }
      }
   }

/*
//==========================================================================
// DM_Arena Object
//
// A DM_Arena is created for each arena that resides in a level.  The level designer
// can set the attributes of this arena using script commands
//==========================================================================
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
Event EV_Arena_SetPlayersPerTeam
   (
   "playersperteam",
   EV_DEFAULT,
   "i",
   "num",
   "set the number of players for each team"
   );
Event EV_Arena_Countdown
   (
   "countdown",
   EV_DEFAULT,
   NULL,
   NULL,
   "Start the countdown for the match"
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
   "addweapon",
   EV_DEFAULT,
   "s",
   "weaponmodel",
   "Add this weapon to the list of weapons that will be used in this match"
   );
Event EV_Arena_AddAmmo
   (
   "addammo",
   EV_DEFAULT,
   "si",
   "ammotype amount",
   "Add this ammo to the players when they start the match"
   );

CLASS_DECLARATION( Listener, DM_Arena, NULL )
   {
      { &EV_Arena_SetName,                   SetName },
      { &EV_Arena_SetHealth,                 SetHealth },
      //{ &EV_Arena_SetWater,                  SetWater },
      { &EV_Arena_SetPlayersPerTeam,         SetPlayersPerTeam },
      { &EV_Arena_Countdown,                 Countdown },
      { &EV_Arena_EndMatch,                  EndMatch },
      { &EV_Arena_AddWeapon,                 AddWeapon },
      { &EV_Arena_AddAmmo,                   AddAmmo },
      { NULL, NULL }
   };


//=================================================================
//DM_Arena::Score - Send the score to the player in this arena
//=================================================================
void DM_Arena::Score
   (
   Player *player
   )

   {
   char		   entry[1024];
	char		   string[1400];
   int         i,j,count=0;
   int         stringlength = 0;

   assert( player );
   if ( !player )
      {
      warning( "DM_Arena::Score", "Null Player specified.\n" );
      return;
      }

   string[0]  = 0;

	for( i=1; i<=m_players.NumObjects(); i++ )
		{
      Player *pl;

      pl = m_players.ObjectAt( i );
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

//=================================================================
//DM_Arena::CenterPrintClientsInArena - Centerprint the string to all
//clients in this arena
//=================================================================
void DM_Arena::CenterPrintClientsInArena
   (
   const str &string
   )

   {
   int i;

   for( i=1; i<=m_players.NumObjects(); i++ )
		{
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         continue;

      gi.centerprintf( player->edict, string );
      }
   }

//=================================================================
//DM_Arena::HUDPrintClientsInArena - HUDprint the string to all
//clients in this arena
//=================================================================
void DM_Arena::HUDPrintClientsInArena
   (
   const str &string
   )

   {
   int i;

   for( i=1; i<=m_players.NumObjects(); i++ )
		{
      Player *player = m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         continue;

      player->HUDPrint( string );
      }
   }

//=================================================================
//DM_Arena::IsTeamAlive - Checks the team to see if any players are
//still alive.
//=================================================================
bool DM_Arena::IsTeamAlive
   (
   DM_TeamPtr team
   )

   {
   int i;

   for ( i=1; i<=team->m_players.NumObjects(); i++ )
      {
      Player *player;

      player = team->m_players.ObjectAt( i );
      assert( player );
      if ( !player )
         {
         continue;
         }

      if ( !player->deadflag && !player->IsSpectator() )
         {
         return true;
         }
      }
   return false;
   }

//=================================================================
//DM_Arena::EndMatch - Ends the current match.  Puts the players still
//in the arena into the non-fighting state so they can't use their weapons.
//Calls ResetTeams() to try and start another match
//=================================================================
void DM_Arena::EndMatch
   (
   Event *ev
   )

   {
   int i,j;

   m_fightInProgress = false;

   // Turn off fighting for any players that are still alive.
   for ( i=1; i <= m_fightingTeams.NumObjects(); i++ )
      {
      DM_TeamPtr team;

      team = m_fightingTeams.ObjectAt( i );

      assert( team );

      if ( !team )
         {
         return;
         }

      for ( j=1; j<=team->m_players.NumObjects(); j++ )
         {
         Player *player = team->m_players.ObjectAt( j );

         assert( player );
         if ( player )
            {
            player->EndFight();
            }
         }
      }

   ResetTeams();
   }

//=================================================================
//DM_Arena::ResetArena - Resets the arena.  This is called when
//something bad or unexpected happens.
//=================================================================
void DM_Arena::ResetArena
   (
   void
   )

   {
   // Something bad happened reset the entire arena
   }

int DM_Arena::GetLinePosition
   (
   Player *player
   )

   {
   DM_Team *team;

   team = player->GetDM_Team();

   if ( team )
      {
      return m_teamQueue.IndexOfObject( team );
      }
   else
      {
      return 0;
      }
   }

//=================================================================
//DM_Arena::TeamForfeitMatch - The team has forfeited the match.  Usually
//happens when a player is the last one to leave the team.
//=================================================================
void DM_Arena::TeamForfeitMatch
   (
   DM_TeamPtr forfeitTeam
   )

   {
   DM_TeamPtr t1,t2;

   // There should be at least 2 teams in the list
   assert( m_fightingTeams.NumObjects() == 2 );
   if ( m_fightingTeams.NumObjects() != 2 )
      {
      warning( "DM_Arena::TeamForfeitMatch", "Invalid number of fighting teams\n" );
      return;
      }

   // This team has left the arena, so forfeit to the other team
   t1 = m_fightingTeams.ObjectAt( 1 );
   t2 = m_fightingTeams.ObjectAt( 2 );

   if ( forfeitTeam == t1 ) // Team 2 wins by forfeit
      {
      m_fightingTeams.RemoveObject( t1 );
      m_teamQueue.Enqueue( t1 );
      CenterPrintClientsInArena( va( "%s Wins by Forfeit", t2->getName().c_str() ) );
      }
   else if ( forfeitTeam == t2 ) // Team 1 wins by forfeit
      {
      m_fightingTeams.RemoveObject( t2 );
      m_teamQueue.Enqueue( t2 );
      CenterPrintClientsInArena( va( "%s Wins by Forfeit", t1->getName().c_str() ) );
      }

   PostEvent( EV_Arena_EndMatch, TIME_MATCH_END_TO_START );
   }

//=================================================================
//DM_Arena::CheckEndMatch - Checks to see if a match has ended.  A win
//is defined as the other team being completely dead.
//=================================================================
void DM_Arena::CheckEndMatch
   (
   void
   )

   {
   DM_TeamPtr t1,t2;
   bool team1_alive = false;
   bool team2_alive = false;

   // The fight is over when one team is completely eliminated.

   // The fight is already over, but another player might have died in the time between rounds
   // we should only get in here when there are two teams only
   if ( m_fightingTeams.NumObjects() != 2 )
      {
      return;
      }

   t1 = m_fightingTeams.ObjectAt( 1 );
   t2 = m_fightingTeams.ObjectAt( 2 );

   team1_alive = IsTeamAlive( t1 );
   team2_alive = IsTeamAlive( t2 );

   if ( team1_alive && team2_alive ) // Game still going on, return
      {
      return;
      }
   else if ( !team1_alive && !team2_alive ) // Draw
      {
      // Leave both teams on the active list and reset
      CenterPrintClientsInArena( "Match Draw\n" );
      }
   else if ( !team1_alive && team2_alive ) // Team 2 wins
      {
      // Remove team 1 from arena
      m_fightingTeams.RemoveObject( t1 );
      m_teamQueue.Enqueue( t1 );

      t1->TeamLoss();

      t2->TeamInvulnerable();
      t2->TeamWin();

      CenterPrintClientsInArena( va( "%s Wins", t2->getName().c_str() ) );
      }
   else if ( team1_alive && !team2_alive ) // Team 1 wins
      {
      // Remove team 2 from arena
      m_fightingTeams.RemoveObject( t2 );
      m_teamQueue.Enqueue( t2 );

      t1->TeamWin();
      t1->TeamInvulnerable();

      t2->TeamLoss();
      CenterPrintClientsInArena( va( "%s Wins", t1->getName().c_str() ) );
      }

   // Post the end of the match in 5 seconds, so the winning team can run around a bit in glory
   PostEvent( EV_Arena_EndMatch, TIME_MATCH_END_TO_START );
   }

//=================================================================
//DM_Arena::PlayerKilled - When a player is killed, put him into spectator
//mode.  Also check to see if the fight is over.
//=================================================================
void DM_Arena::PlayerKilled
   (
   Player *player
   )

   {
   // When a player is killed, put them into spectator mode and check to see if the fight is over.
   assert( player );
   if ( !player )
      {
      return;
      }

   // Put into spectator mode after a few seconds, but leave the body
   player->DeadBody( NULL );
   player->hideModel();
   player->takedamage = DAMAGE_NO;
   player->PostEvent( EV_Player_Spectator, TIME_DELAY_DEATH_TO_SPECTATOR );

   // Check to see if the fight is over when somebody dies
   CheckEndMatch();
   }

//=================================================================
//DM_Arena::CountdownFinished - When the fight countdown is finished,
//update all the players so that they can fight.
//=================================================================
void DM_Arena::CountdownFinished
   (
   void
   )

   {
   int i;

   CenterPrintClientsInArena( "FIGHT!" );

   for ( i=1; i <= m_fightingTeams.NumObjects(); i++ )
      {
      DM_TeamPtr team;

      team = m_fightingTeams.ObjectAt( i );

      assert( team );
      if ( !team )
         {
         return;
         }

      team->BeginFight();
      }
   }

//=================================================================
//DM_Arena::Countdown - Start off a countdown for the match
//=================================================================
void DM_Arena::Countdown
   (
   Event *ev
   )

   {
   if ( m_countdown == 0 )
      {
      CountdownFinished();
      }
   else
      {
      DM_TeamPtr t1, t2;

      if ( m_fightingTeams.NumObjects() != 2 )
         {
         // One of the teams left before the countdown was finished,
         // so reset the teams.
         ResetTeams();
         return;
         }

      t1 = m_fightingTeams.ObjectAt( 1 );
      t2 = m_fightingTeams.ObjectAt( 2 );

      if ( t1 && t2 )
         {
         CenterPrintClientsInArena( va( "%s versus %s\n...%d...",
                                    t1->getName().c_str(),
                                    t2->getName().c_str(),
                                    m_countdown
                                  )
                              );
         }

      // Repost the event
      m_countdown--;
      PostEvent( EV_Arena_Countdown, 1 );
      }
   }

//=================================================================
//DM_Arena::AddAmmo - Add amoo to the ammo list
//=================================================================
void DM_Arena::AddAmmo
   (
   Event *ev
   )

   {
   SimpleAmmoType  *ammo;

   ammo = new SimpleAmmoType;

   ammo->type   = ev->GetString( 1 );
   ammo->amount = ev->GetInteger( 2 );

   m_ammoList.AddObject( ammo );
   }

//=================================================================
//DM_Arena::AddWeapon - Add a weapon to the weapon list
//=================================================================
void DM_Arena::AddWeapon
   (
   Event *ev
   )

   {
   str string;

   string = ev->GetString( 1 );
   m_weaponList.AddObject( string );
   }

//=================================================================
//DM_Arena::GiveWeaponsAndAmmo - Give the specified weapons and ammo to the player
//=================================================================
void DM_Arena::GiveWeaponsAndAmmo
   (
   Player *player
   )

   {
   int i,count;
   // Give the player the appropriate weapons

   assert( player );
   if ( !player )
      {
      warning( "DM_Arena::GiveWeapons", "NULL player specified.\n" );
      return;
      }

   count = m_weaponList.NumObjects();
   if ( !count )
      {
      // Give the default weapons
      }
   else
      {
      for ( i=1; i<=count; i++ )
         {
         Event *ev = new Event( "weapon" );
         ev->AddToken( m_weaponList.ObjectAt( i ) );
         player->ProcessEvent( ev );
         }
      }

   count = m_ammoList.NumObjects();
   if ( !count )
      {
      // Give the default ammo
      }
   else
      {
      for ( i=1; i<=count; i++ )
         {
         Event *ev = new Event( "ammo" );
         ev->AddString( m_ammoList.ObjectAt( i )->type );
         ev->AddInteger( m_ammoList.ObjectAt( i )->amount );
         player->ProcessEvent( ev );
         }
      }

   }

//=================================================================
//DM_Arena::ActivatePlayers - Take all of the fighting players and put
//them into the arena.
//=================================================================
#define NUM_SKINS 2
static char teamSkins[NUM_SKINS][32] =
   {
   "models/johnny.tik",
   "models/johnny.tik",
   };

void DM_Arena::ActivatePlayers
   (
   void
   )

   {
   int i,j;
   DM_TeamPtr team;
   bool oneOnOne = true;

   m_spawncounter = 1;

   // Should be two teams now to activate
   assert( m_fightingTeams.NumObjects() == 2 );

   // If all the teams have 1 player, then this is a 1v1 match
   for ( i=1; i<=m_fightingTeams.NumObjects(); i++ )
      {
      team = m_fightingTeams.ObjectAt( i );

      assert( team );
      if ( !team )
         continue;

      if ( team->m_players.NumObjects() != 1 )
         {
         oneOnOne = false;
         break;
         }
      }

   ResetSpawnpoints();

   // Take the active teams players and add spawn them into the arena
   for ( i=1; i<=m_fightingTeams.NumObjects(); i++ )
      {
      team = m_fightingTeams.ObjectAt( i );

      assert( team );
      if ( !team )
         continue;

      team->UpdateTeamStatus();

      for ( j=1; j<=team->m_players.NumObjects(); j++ )
         {
         Player *player = team->m_players.ObjectAt( j );

         assert( player );
         if ( !player )
            {
            continue;
            }

         player->WarpToPoint( this->GetSpawnpoint() );
         player->EnterArena( this->m_starting_health, this->m_starting_water );

         // If this is a 1 on 1 match, then let the players set their own skins, otherwise use the red and blue ones
         if ( oneOnOne )
            {
            player->setModel( player->client->pers.dm_playermodel );
            }
         else
            {
            // Depending on the team index pick a skin
            if ( i == 1 )
               {
               player->setModel( teamSkins[ 0 ] );
               }
            else
               {
               player->setModel( teamSkins[ 1 ] );
               }
            }

         GiveWeaponsAndAmmo( player );
         }
      }
   }

//=================================================================
//DM_Arena::BeginMatch - Kick off a match.
//=================================================================
void DM_Arena::BeginMatch
   (
   void
   )

   {
   // Start the countdown for fighting
   m_fightInProgress = true;
   m_countdown       = TIME_COUNTDOWN;
   ProcessEvent( EV_Arena_Countdown );
   }

//=================================================================
//DM_Arena::ResetTeams: Resets the teams and adds players to
//the active list.  Then call BeginFight if the teams are ready
//=================================================================
void DM_Arena::ResetTeams
   (
   void
   )

   {
   int i,j;

   // Only reset the teams if a fight is not in progress
   if ( m_fightInProgress )
      {
      return;
      }

   // Make sure there are 2 active teams in the list
   while ( m_fightingTeams.NumObjects() < 2 )
      {
      DM_TeamPtr team = ( DM_Team * )m_teamQueue.Dequeue();

      if ( team )
         {
         m_fightingTeams.AddObject( team );
         }
      else
         {
         break;
         }
      }

   if ( m_fightingTeams.NumObjects() == 2 )
      {
      // Put the active teams into the arena
      ActivatePlayers();
      BeginMatch();
      }
   else
      {
      // Couldn't get a match started, so spectate the players that are waiting
      for ( i=1; i<=m_fightingTeams.NumObjects(); i++ )
         {
         DM_TeamPtr team = m_fightingTeams.ObjectAt( i );

         assert( team );
         if ( !team )
            {
            continue;
            }

         for ( j=1; j<=team->m_players.NumObjects(); j++ )
            {
            Player *player;

            player = team->m_players.ObjectAt( j );

            assert( player );
            if ( !player )
               {
               continue;
               }

            player->Spectator();
            player->UpdateStatus( "Waiting for Opponent" );
            }
         }
      }
   }

//=================================================================
//DM_Arena::JoinTeam: Join the specified team
//=================================================================
void DM_Arena::JoinTeam
   (
   Player *player,
   int team_number
   )

   {
   int         i;
   DM_TeamPtr  team=NULL;

   assert( player );
   if ( !player )
      {
      return;
      }

   // Search the team list for the specified index
   for ( i=1; i<=m_teams.NumObjects(); i++ )
      {
      team = m_teams.ObjectAt( i );

      assert( team );
      if ( !team )
         {
         continue;
         }

      if ( team->getNumber() == team_number )
         {
         break;
         }
      }

   if ( !team )
      {
      warning( "DM_Arena::JoinTeam", "Team not found in list\n" );
      return;
      }

   // Check to make sure that we can join this team based on the player limit for this arena
   if ( team->m_players.NumObjects() >= m_num_players_per_team )
      {
      gi.centerprintf( player->edict, "That team is full" );
      return;
      }

   // Leave any other teams first
   if ( player->GetTeam() )
      {
      LeaveTeam( player );
      }

   team->AddPlayer( player );
   player->SetDM_Team( team );
   }

//=================================================================
//DM_Arena::RemoveTeam: Remove the team from the arena
//=================================================================
void DM_Arena::RemoveTeam
   (
   DM_TeamPtr team
   )

   {
   int i;

   // Team is about to be removed, check to see if this team is currently involved in a match
   if ( m_fightingTeams.ObjectInList( team ) )
      {
      if ( ( m_fightingTeams.NumObjects() == 2 ) && ( m_fightInProgress ) )
         {
         TeamForfeitMatch( team );
         }
      m_fightingTeams.RemoveObject( team );
      }

   // Spectate all the members of the team
   for ( i=1; i<=team->m_players.NumObjects(); i++ )
      {
      Player *player;

      player = team->m_players.ObjectAt( i );

      assert( player );
      if ( !player )
         {
         continue;
         }

      player->Spectator();
      }

   // Remove team from queue and list
   if ( m_teamQueue.Inqueue( team ) )
      {
      m_teamQueue.Remove( team );
      }

   m_teams.RemoveObject( team );
   delete team;
   }

//=================================================================
//DM_Arena::LeaveTeam: Leave the current team that the player is on
//=================================================================
void DM_Arena::LeaveTeam
   (
   Player *player
   )

   {
   DM_TeamPtr team;

   assert( player );
   if ( !player )
      {
      return;
      }

   // Remove the player from the team
   team = player->GetDM_Team();

   if ( !team )
      {
      warning( "DM_Arena::LeaveTeam", "Could not find a team for this player\n" );
      return;
      }

   if ( m_teams.ObjectInList( team ) )
      {
      team->RemovePlayer( player );
      player->Spectator();

      // Check for empty team
      if ( !team->m_players.NumObjects() )
         {
         RemoveTeam( team );
         }
      }
   else
      {
      warning( "DM_Arena::LeaveTeam", "Could not find team in the arena\n" );
      return;
      }

   player->SetDM_Team( NULL );
   }

//=================================================================
//DM_Arena::CreateTeam: Creates a new team by the specified player
//=================================================================
void DM_Arena::CreateTeam
   (
   Player *player
   )

   {
   DM_TeamPtr team;

   // Create a new team based on the player's name
   if ( !player )
      {
      return;
      }

   team = new DM_Team;
   if ( !team )
      {
      warning( "DM_Arena::CreateTeam", "Could not create the team\n" );
      return;
      }

   // Set up the team
   team->setName( va( "%s's Team", player->client->pers.netname ) );
   team->AddPlayer( player );

   // Add it to the list of teams
   m_teams.AddObject( team );

   // Create a new team index
   team->setNumber( m_teamcount++ );

   player->SetDM_Team( team );

   // Add this team to the queue
   m_teamQueue.Enqueue( team );
   }

void DM_Arena::ResetSpawnpoints
   (
   void
   )

   {
   int i;

   // This builds a list of all the spawnpoints in the arena, which will be
   // removed when
   m_unusedSpawnpoints.ClearObjectList();

   for( i=1; i<=m_spawnpoints.NumObjects(); i++ )
      {
      m_unusedSpawnpoints.AddObject( m_spawnpoints.ObjectAt( i ) );
      }
   }

Entity *DM_Arena::GetSpawnpoint
   (
   void
   )

   {
   Entity *spot=NULL;
   int numPoints = m_unusedSpawnpoints.NumObjects();

   if ( !numPoints )
      {
      warning( "DM_Arena::GetSpawnpoint", "No spawnpoints found in arena\n" );
      return NULL;
      }
   else
      {
      int selection = ( G_Random() * numPoints ) + 1;
      spot = ( Entity * )m_unusedSpawnpoints.ObjectAt( selection );
      m_unusedSpawnpoints.RemoveObjectAt( selection );
      return spot;
      }
   }

//=================================================================
//DM_Arena::GetRandomSpawnpoint a spawnpoint in the arena. If
//useCounter is set, then the spawnpoints are generated sequentially
//=================================================================
Entity *DM_Arena::GetRandomSpawnpoint
   (
   bool useCounter
   )

   {
   Entity *spot=NULL;

   int numPoints = m_spawnpoints.NumObjects();

   if ( !numPoints )
      {
      warning( "DM_Arena::GetRandomSpawnpoint", "No spawnpoints found in arena\n" );
      return NULL;
      }
   else
      {
      if ( useCounter )
         {
         if ( m_spawncounter > numPoints )
            m_spawncounter = 1;

         spot = ( Entity * )m_spawnpoints.ObjectAt( m_spawncounter );
         m_spawncounter++;
         return spot;
         }
      else
         {
         int selection = ( G_Random() * numPoints ) + 1;
         spot = ( Entity * )m_spawnpoints.ObjectAt( selection );
         return spot;
         }
      }
   }

//=================================================================
//DM_Arena::SetName
//=================================================================
void DM_Arena::SetName
   (
   Event *ev
   )

   {
   m_name = ev->GetString( 1 );
   UpdateArenaInfo();
   }

//=================================================================
//DM_Arena::UpdateArenaInfo - Update the configstrings with all the
//team names
//=================================================================
void DM_Arena::UpdateArenaInfo
   (
   void
   )

   {
   assert( m_id > 0 );

   if ( m_id > 0 )
      {
      str s;

      s = va( "#%d-%s-(%d) player(s)", m_id, m_name.c_str(), m_players.NumObjects() );
      gi.setConfigstring( CS_ARENA_INFO + m_id, s );
      }
   else
      {
      warning( "DM_Arena::SetName", "Arena id number is not set\n" );
      }
   }

//=================================================================
//DM_Arena::AddPlayer - Add a player to the list of active players in this arena
//=================================================================
void DM_Arena::AddPlayer
   (
   Player *player
   )

   {
   // Add a player to this arena
   m_players.AddObject( player );

   player->SetDM_Arena( this );

   UpdateArenaInfo();
   HUDPrintClientsInArena( va( "%s joined the arena\n", player->client->pers.netname ) );


   }

//=================================================================
//DM_Arena::RemovePlayer - Remove the specified player from this arena
//=================================================================
void DM_Arena::RemovePlayer
   (
   Player *player
   )

   {
   int i,count;

   // Remove player from the list and print message to clients in this arena
   if ( m_players.ObjectInList( player ) )
      {
      m_players.RemoveObject( player );
      HUDPrintClientsInArena( va( "%s left the arena\n", player->client->pers.netname ) );
      }

   // Check to see if any teams have this player and remove that player
   count = m_teams.NumObjects();

   for ( i=count; i>0; i-- )
      {
      DM_TeamPtr team = m_teams.ObjectAt( i );

      if ( team->m_players.ObjectInList( player ) )
         {
         team->m_players.RemoveObject( player );

         // Removed the player, now try to remove the team
         if ( !team->m_players.NumObjects() )
            {
            RemoveTeam( team );
            }
         }
      }

   // Player is out of arena and out of any teams
   player->SetDM_Arena( NULL );
   player->SetDM_Team( NULL );

   // Update information and build the configstrings
   UpdateArenaInfo();
//   dmManager.RebuildTeamConfigstrings();
   }

//=================================================================
//DM_Arena::SetNumPlayersPerTeam - Sets the number of players that can be on a single team.
//=================================================================
void DM_Arena::SetPlayersPerTeam
   (
   Event *ev
   )

   {
   m_num_players_per_team = ev->GetInteger( 1 );
   }

//=================================================================
//DM_Arena::SetHealth - Set the starting health of the players
//=================================================================
void DM_Arena::SetHealth
   (
   Event *ev
   )

   {
   m_starting_health = ev->GetInteger( 1 );
   }


//=================================================================
//DM_Arena::setID - set the ID number of the arena
//=================================================================
void DM_Arena::setID
   (
   int id
   )

   {
   m_id = id;

   // Find all the deathmatch starts that match this id number
   PlayerDeathmatchStart *start = NULL;

   // Count the number of deathmatch starts in this arena
   for( start = ( PlayerDeathmatchStart * )G_FindClass( start, "info_player_deathmatch" );
        start ;
        start = ( PlayerDeathmatchStart * )G_FindClass( start, "info_player_deathmatch" ) )
      {
      // See if this spot matches this arena id number (or not set in which case we add it as a hack for non-arena maps FIXME
      if ( !start->arena || (start->arena == this->m_id) )
         {
         m_spawnpoints.AddObject( start );
         }
      }
   }
//=================================================================
//DM_Arena::~DM_Arena
//=================================================================
DM_Arena::~DM_Arena
   (
   )
   {
   int i;

   // delete all the teams
   for ( i=m_teams.NumObjects(); i>0; i-- )
      {
      DM_Team *team;

      team = m_teams.ObjectAt( i );
      assert( team );

      if ( !team )
         continue;

      delete team;
      }
   }

//=================================================================
//DM_Arena::DM_Arena
//=================================================================
DM_Arena::DM_Arena
   (
   )

   {
   m_name                  = "Unnamed Arena";
   m_num_players_per_team  = 1;
   m_starting_health       = 100;
   m_starting_water        = 100;
   m_id                    = -1;
   m_countdown             = 5;
   m_fightInProgress       = false;
   m_teamcount             = 0;
   }


*/

CLASS_DECLARATION( Listener, DM_Manager, NULL )
	{
		{ NULL, NULL }
	};

cvar_t* dm_gametype    = 0 ;
cvar_t* dm_fraglimit   = 0 ;

//=================================================================
//DM_Manager::DM_Manager
//=================================================================
DM_Manager::DM_Manager()
	:	_gameType(0)
   {
   }

//=================================================================
//DM_Manager::~DM_Manager
//=================================================================
DM_Manager::~DM_Manager()
	{
		Reset();
	}

//================================================================
// Name:        Init
// Class:       DM_Manager
//              
// Description: Initializes cvars that the manager uses.
//              
// Parameters:  None
//              
// Returns:     None
//              
//================================================================
void DM_Manager::Init
	(
	void
	)
	{
		dm_gametype  = gi.cvar("mp_gametype", "", 0);
		dm_fraglimit = gi.cvar("fraglimit",   "", 0);
	}


//=================================================================
//DM_Manager::Reset - Delete all the arenas
//=================================================================
void DM_Manager::Reset
	(
	void
	)

	{
		int i;

		// Delete all the arenas and all the teams
		for ( i=_arenas.NumObjects(); i>0; i-- )
		{
			MultiplayerArena *arena = _arenas.ObjectAt( i );

			assert( arena );
			if ( ! arena )
			{
				continue;
			}

			_arenas.RemoveObjectAt( i );
			delete arena;
		}
	}


//=================================================================
//DM_Manager::AddPlayer - Adds a player to the active players list
//=================================================================
void DM_Manager::AddPlayer
   (
   Player *player
   )
   {
   // Do any global type stuff here.  None needed so far
   }



//=================================================================
//DM_Manager::RemovePlayer - Remove the player from the game
//=================================================================
void DM_Manager::RemovePlayer
   (
   Player *player
   )
   {
   assert( player );

   if ( !player )
      {
      return;
      }

   RemovePlayerFromAllArenas( player );
   }



//=================================================================
//DM_Manager::RemovePlayerFromAllArenas - Remove the specified player from all arenas
//=================================================================
void DM_Manager::RemovePlayerFromAllArenas
	(
	Player *player
	)

	{
		int i;

		// Go through all the arenas and remove the player
		for ( i=1; i<=_arenas.NumObjects(); i++ )
		{
			MultiplayerArena *arena = _arenas.ObjectAt( i );

			assert( arena );
			if ( arena )
			{
				arena->RemovePlayer( player );
			}
		}
   }



//=================================================================
//DM_Manager::JoinArena - Join the specified arena
//=================================================================
void DM_Manager::JoinArena
	(
	Player *player,
	int arenaId
	)
	{
		MultiplayerArena *arena;

		// Make sure that the new arena exists
		if ( ( arenaId < 1 ) || ( arenaId > _arenas.NumObjects() ) )
		{
			warning( "DM_Manager::JoinArena", "Arena number (%d) is out of range\n", arenaId );
			return;
		}

		// Leave the current arena if any
		arena = player->GetMultiplayerArena();
		if ( arena )
		{
			arena->RemovePlayer( player );
		}


		// Get the new arena
		arena = _arenas.ObjectAt( arenaId );
		assert( arena );
		if ( !arena )
		{
			warning( "DM_Manager::JoinArena", "Arena number (%d) was not found\n" );
			return;
		}

		arena->AddPlayer( player );
	}


//=================================================================
//DM_Manager::PlayerKilled - A player is killed
//=================================================================
void DM_Manager::PlayerKilled
	(
	Player *player
	)
	{

		assert(player);
		if ( !player )
		{
			return;
		}

		MultiplayerArena *arena = player->GetMultiplayerArena();
		if ( arena )
		{
			arena->PlayerKilled( player );
			if (arena->isEndOfMatch())
			{
				arena->EndMatch();
			}
		}
	}


//=================================================================
//DM_Manager::InitArenas - Initialize all the arenas
//=================================================================
void DM_Manager::InitArenas
	(
	void
	)
	{
		if ( level.m_numArenas <= 0 )
		{
			gi.Error( ERR_DROP, "Invalid number of arenas specified: %d\n", level.m_numArenas );
			return;
		}

		// Create all the arena data structures
		for (int idx = 0; idx < level.m_numArenas; idx++ )
		{
			MultiplayerArena *arena = 0 ;
			switch (dm_gametype->integer)
			{
			case 1:  arena = new CaptureTheFlagArena(); break ;
			default: arena = new DeathmatchArena(); break ;
			}

			assert( arena );
			if ( !arena )
			{
				warning( "DM_Manager::InitArenas", "Could not allocate new arena\n" );
				continue;
			}

			// Set the id number of the arena based on the location in the list
			arena->setID( idx + 1 );
			arena->setFragLimit( dm_fraglimit->integer );

			// add the arena to the current arena list
			_arenas.AddObject( arena );
		}
	}


//=================================================================
//DM_Manager::ArenaCommand - Process commands and send them to the specified arena
//=================================================================
void DM_Manager::ArenaCommand
	(
	Event *ev
	)
	{
		str         string;
		int         i,num;

		assert(ev);
		if (!ev)
		{
			warning("DM_Manager::ArenaCommand", "NULL Event!\n");
			return ;
		}

		if (ev->NumArgs() != 1)
		{
			warning("DM_Manager::ArenaCommand", "Wrong number of args in event\n");
			return ;
		}
		
		string = ev->GetString( 1 );
		if ( !stricmp( string, "all" ) )
		{
			num = _arenas.NumObjects();

			for ( i=1; i<=num; i++ )
			{
				MultiplayerArena *arena = _arenas.ObjectAt( num );

				assert( arena );
				if ( !arena )
				{
					gi.Error( ERR_DROP, "Arena number %d was not found in the Arena Manager.\n", num );
				}
				_passEventToArena(ev, arena);
			}
		}
		else
		{
			num = ev->GetInteger( 1 );
			// Bounds check the num to make sure the arena exists
			if ( num > _arenas.NumObjects() )
			{
				gi.Error( ERR_DROP, "Arena number (%d) is greater than the total number of arenas in this level (%d)\n", num, _arenas.NumObjects() );
			}

			MultiplayerArena *arena = _arenas.ObjectAt( num );

			assert( arena );
			if ( !arena )
			{
				gi.Error( ERR_DROP, "Arena number %d was not found in the Arena Manager.\n", num );
			}
			_passEventToArena(ev, arena);
		}
	}


//=================================================================
//DM_Manager::ArenaPrint - Print the string to the arena that the player is in
//=================================================================
void DM_Manager::ArenaPrint
   (
   Entity *ent,
   const char *txt
   )

   {
   assert( ent );

   if ( !ent )
      {
      warning( "DM_Manager::ArenaPrint", "Null entity\n" );
      return;
      }

   // Make sure this is a player
   if ( !ent->isSubclassOf( Player ) )
      {
      return;
      }

   Player           *player = ( Player * )ent;
   MultiplayerArena *arena;

   arena = player->GetMultiplayerArena();
   if ( arena )
      {
      arena->HUDPrintClientsInArena( txt );
      }
   }



//=================================================================
//DM_Manager::Score - Do the scores for this arena
//=================================================================
void DM_Manager::Score
   (
   Player *player
   )

   {
   MultiplayerArena *arena;

   arena = player->GetMultiplayerArena();
   if ( arena )
      {
      arena->Score( player );
      }
   else
      {
      gi.SendServerCommand( player->edict-g_entities, "scores 0" );
      }
   }



//=================================================================
//DM_Manager::PrintAllClients - Print message to all clients in the
//game
//=================================================================
void DM_Manager::PrintAllClients
   (
   const str &s
   )

   {
   int i;

   for( i = 0; i < maxclients->integer; i++ )
		{
      gentity_t *ent = g_entities + i;
		if ( !ent->inuse || !ent->client || !ent->entity )
			{
			continue;
			}

      Player *player = ( Player * )ent->entity;
      player->HUDPrint( s );
      }
   }



//-------------------------------------------------------------------
//             P R O T E C T E D   M E T H O D S
//-------------------------------------------------------------------


//================================================================
// Name:        _passEventToArena
// Class:       DM_Manager
//              
// Description: Passes the specified event through.  Because this
//              is a protected function, call by another DM_Manager
//              function, we won't do error checking on event.
//
//              The first argument of the specified event is removed,
//              because it was the argument that told us which arena
//              to pass through.
//              
// Parameters:  Event*            -- Event to pass through.  All but first argument
//                                   is passed.
//              MultiplayerArena* -- Arena to pass event to.
//              
// Returns:     None
//              
//================================================================
void DM_Manager::_passEventToArena
	(
	Event* ev,
	MultiplayerArena* arena
	)
	{
		// Create a new event without the first parm
		Event *newEvent;
		int numargs = ev->NumArgs();
		int argc = numargs - 2 + 1;

		newEvent = new Event( ev->GetToken( 2 ) );
		for(int idx = 1; idx < argc; idx++ )
		{
			newEvent->AddToken( ev->GetToken( 2 + idx ) );
		}
		arena->ProcessEvent( newEvent );		
	}

