// DESCRIPTION:
// PlayerHeuristics Class Definition.
//

class PlayerHeuristics;

// PlayerHeuristics class
//
// This class and file are in a state of transition, and currently, is coded like ass.
// I have, at least, managed to pull most of the heuristic stuff out of player.cpp and place it here,
// for now.
//
// Future Plans:
// Where this mess is headed -- Eventually, I would like to create a new system where we have a 
// Heuristics manager that is seperate from anything in the game ( like Player, or Weapon ) and 
// Thus could be used by anyone to track their own stats.  
//
// PlayerHeuristics would still be around, though its role would change to that of an intermediary
// between the new Heuristics Manager and Player.  It would control what stats it's tracking and 
// manage any _PLAYER_ specific heuristic data.
//

#ifndef __PLAYER_HEURISTICS_H__
#define __PLAYER_HEURISTICS_H__

#include "player.h"

class PlayerHeuristics : public Class
{
	public:
		
				 PlayerHeuristics();
				 PlayerHeuristics( PlayerHeuristics &pHeuristic );
				~PlayerHeuristics();
		
		void ShowHeuristics( Player *player );
		void SaveHeuristics( Player *player );
		void LoadHeuristics();
		void ReadInHeuristicData(Script& script, str& levelName);
		void WriteOutHeuristicData(str& levelName);
		void CreateInitialHeuristicFile();
		void OpenPlayerHeuristicFile();
		void ClosePlayerHeuristicFile();
		void CheckForHeuristicFile();
		float CalculateSkillLevel();
		
		void	SetShotsFired( long int shots);	
		void	IncrementShotsFired();
		void	SetShotsHit( long int shots);
		void	IncrementShotsHit();
		void	SetNumberOfDeaths( long int deaths);  
		void	IncrementNumberOfDeaths();
		void	SetRedemptiveKills( long int kills);
		void	IncrementRedemptiveKills();
		void  SetAssassinKills( long int kills);
		void	IncrementAssassinKills();
		void  SetTimeOnLevel( float levelTime );
		void	SetPlayerHealth( int health );
		void	SetPing (int ping_value );
		void	SetItemsPickedUp ( int items );
		void  IncrementItemsPickedUp ();
		void	SetSpecialEvents( int specialevent );
		void  IncrementSpecialEvents();
		void	SetQGunShots( long int shots );
		void	IncrementQGunShots();
		void	SetMBowShots( long int shots );
		void  IncrementMBowShots();		
		void  UpdateShotsFired( Player *player );
		
		//Single Player Stats
		long int shotsFired;
		long int	shotsHit;
		long int	numberOfDeaths;
		long int redemptiveKills;
		long int assassinKills;
		float    timeOnLevel;
		float    levelStartTime;
		float    levelEndTime;
		int      playerHealth;
		str      lastLevel;
		str      currentLevel;

		//Multiplayer Stats
		int      ping;
		int      itemsPickedUp;
		int      specialEvents;
		
		//Weapon Stats
		long int	quetzalGunShots;
		long int mbowShots;

		//Skill Level
		float		skillLevel;

};




#endif /* __PLAYER_HEURISTICS_H__ */