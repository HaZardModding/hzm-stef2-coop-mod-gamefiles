#include "playerheuristics.h"

static fileHandle_t heuristicFile=NULL;
static str heuristicFileName=NULL;

PlayerHeuristics::PlayerHeuristics()
	{
	//Single Player Stats
	shotsFired        = 0;
	shotsHit          = 0;
	numberOfDeaths    = 0;
	redemptiveKills   = 0;
	assassinKills     = 0;
	timeOnLevel       = 0;
	levelStartTime    = 0;
	levelEndTime      = 0;
	playerHealth      = 0;
	lastLevel         = "";
	currentLevel      = "";

	//Multiplayer Stats
	ping              = 0;
	itemsPickedUp     = 0;
	specialEvents     = 0;
		
	//Weapon Stats
	quetzalGunShots   = 0;
	mbowShots         = 0;

	//Skill Level
	skillLevel        = 0;
	}

PlayerHeuristics::PlayerHeuristics( PlayerHeuristics &pHeuristic )
	{
	//Single Player Stats
	shotsFired        = pHeuristic.shotsFired;
	shotsHit          = pHeuristic.shotsHit;
	numberOfDeaths    = pHeuristic.numberOfDeaths;
	redemptiveKills   = pHeuristic.redemptiveKills;
	assassinKills     = pHeuristic.assassinKills;
	timeOnLevel       = pHeuristic.timeOnLevel;
	levelStartTime    = pHeuristic.levelStartTime;
	levelEndTime      = pHeuristic.levelEndTime;
	playerHealth      = pHeuristic.playerHealth;
	lastLevel         = pHeuristic.lastLevel;
	currentLevel      = pHeuristic.currentLevel;

	//Multiplayer Stats
	ping              = pHeuristic.ping;
	itemsPickedUp     = pHeuristic.itemsPickedUp;
	specialEvents     = pHeuristic.specialEvents;
		
	//Weapon Stats
	quetzalGunShots   = pHeuristic.quetzalGunShots;
	mbowShots         = pHeuristic.mbowShots;

	//Skill Level
	skillLevel        = pHeuristic.skillLevel;
	}

PlayerHeuristics::~PlayerHeuristics()
	{

	}

void PlayerHeuristics::ShowHeuristics( Player *player )
	{
   //Show Player Information in the console
	
	levelEndTime = level.time;
	timeOnLevel+= levelEndTime;
	playerHealth = player->health;
		
	ping = player->client->ping;
	
	float accuracy = 0;

	if ( shotsFired != 0 )
		{
		accuracy = (float)shotsHit / (float)shotsFired;
		accuracy*= 100;
		}

	gi.Printf( "\nPlayer Heuristics:\n");
	gi.Printf( "Shots Fired:        %d\n", shotsFired );
	gi.Printf( "Shots Hit:	        %d\n", shotsHit );
	gi.Printf( "Accuracy:           %%%.2f\n", accuracy );
	gi.Printf( "Number of Deaths:   %d\n", numberOfDeaths );
	gi.Printf( "Redemptive Kills:   %d\n", redemptiveKills );
	gi.Printf( "Assassin Kills:     %d\n", assassinKills );
	gi.Printf( "Time On Level:      %f\n", timeOnLevel );
	gi.Printf( "Player Health:      %d\n", playerHealth );
	gi.Printf( "Ping:               %d\n", ping );
	gi.Printf( "Items Picked Up:    %d\n", itemsPickedUp );
	gi.Printf( "Special Events:     %d\n", specialEvents );
	gi.Printf( "Quetzal Gun Shots:  %d\n", quetzalGunShots );
	gi.Printf( "MBow Shots:			  %d\n", mbowShots );
	gi.Printf( "\n" );
	gi.Printf( "Skill Level:        %f\n", CalculateSkillLevel() );
	
	gi.Printf( "\n" );
   
	}

void PlayerHeuristics::SaveHeuristics( Player *player )
	{
	str token;
	str levelName;
	Script script;
	qboolean currentHeuristicsWritten;
	PlayerHeuristics *pHeuristic;
	
	//Precalculation for stats
	levelEndTime = level.time;
	timeOnLevel+= levelEndTime;
	playerHealth = player->health;
	ping = player->client->ping;
	skillLevel = CalculateSkillLevel();

	script.LoadFile( heuristicFileName );
	
	OpenPlayerHeuristicFile();
	if ( !heuristicFile )
		{
      script.Close();
		return;
		}
	
	//Save off a copy of our current stats
	pHeuristic = new PlayerHeuristics( *this );

   currentHeuristicsWritten = false;
   while( script.TokenAvailable( true ) )
		{
		token = script.GetToken(false);
      
		//The reason we saved off our old stats, and are reading through
		//is that in order to keep all the stats for all the other levels
		//we need to read them all in and write them back out, just replacing
		//the information we need for our current level
		if ( !Q_stricmp( token.c_str(), "Level:" ) )
			{
			levelName = script.GetToken(false);
			if ( Q_stricmp( levelName.c_str(), level.mapname.c_str() ) ) //Not Equal
				{
				script.UnGetToken();
				ReadInHeuristicData(script, levelName);
				}
			else
				{
				
				//Restore Values
				shotsFired        = pHeuristic->shotsFired;
				shotsHit          = pHeuristic->shotsHit;
				numberOfDeaths    = pHeuristic->numberOfDeaths;
				redemptiveKills   = pHeuristic->redemptiveKills;
				assassinKills     = pHeuristic->assassinKills;
				timeOnLevel       = pHeuristic->timeOnLevel;
				levelStartTime    = pHeuristic->levelStartTime;
				levelEndTime      = pHeuristic->levelEndTime;
				playerHealth      = pHeuristic->playerHealth;
				lastLevel         = pHeuristic->lastLevel;
				currentLevel      = pHeuristic->currentLevel;

				//Multiplayer Stats
				ping              = pHeuristic->ping;
				itemsPickedUp     = pHeuristic->itemsPickedUp;
				specialEvents     = pHeuristic->specialEvents;
		
				//Weapon Stats
				quetzalGunShots   = pHeuristic->quetzalGunShots;
				mbowShots         = pHeuristic->mbowShots;

				//Skill Level
				skillLevel        = pHeuristic->skillLevel;
				
				

				currentHeuristicsWritten = true;
				}
		
			WriteOutHeuristicData(levelName);
			}
		}

	if (!currentHeuristicsWritten)
		{
		currentHeuristicsWritten = true;
		WriteOutHeuristicData(level.mapname);
		}
	
	ClosePlayerHeuristicFile();
	}

void PlayerHeuristics::LoadHeuristics()
	{
   str token;
	Script script;
	
   CheckForHeuristicFile();

	//Clear Heuristic Data Structure;
	shotsFired = 0;
	shotsHit = 0;
	numberOfDeaths = 0;
	redemptiveKills = 0;
	assassinKills = 0;
	timeOnLevel = 0;
	levelStartTime = 0;
	levelEndTime = 0;
	playerHealth = 0;

	ping = 0;
	itemsPickedUp = 0;
	specialEvents = 0;
	
	quetzalGunShots = 0;
	mbowShots = 0;
	skillLevel = 0;
	
	script.LoadFile( heuristicFileName );
	
	ReadInHeuristicData(script, level.mapname);

	level.setSkill(skillLevel);

	script.Close();
	ClosePlayerHeuristicFile();
	}

void PlayerHeuristics::ReadInHeuristicData( Script& script, str& levelName )
	{
	str token;

	//Fill Structure from File
   while( script.TokenAvailable( true ) )
		{
		str heuristic;
		str endSection;
		token = script.GetToken( false );

		if ( !Q_stricmp( token.c_str(), levelName.c_str() ) )
			{
			endSection = levelName + "_end";

			while ( Q_stricmp( token.c_str(), endSection.c_str() ) )
				{
				token = script.GetToken( false );
				if ( !Q_stricmp( token.c_str(), "ShotsFired:" ) )
					{
  					heuristic = script.GetToken(false);
					shotsFired = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "ShotsHit:" ) )
					{
					heuristic = script.GetToken(false);
					shotsHit = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "NumberOfDeaths:" ) )
					{
					heuristic = script.GetToken(false);
					numberOfDeaths = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "RedemptiveKills:" ) )
					{
					heuristic = script.GetToken(false);
					redemptiveKills = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "AssassinKills:" ) )
					{
					heuristic = script.GetToken(false);
					assassinKills = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "TimeOnLevel:" ) )
					{
					heuristic = script.GetToken(false);
					timeOnLevel = atof(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "PlayerHealth:" ) )
					{
					heuristic = script.GetToken(false);
					playerHealth = atoi(heuristic.c_str());					
					}
				else if ( !Q_stricmp( token.c_str(), "Ping:" ) )
					{
					heuristic = script.GetToken(false);
					ping = atoi(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "ItemsPickedUp:" ) )
					{
					heuristic = script.GetToken(false);
					itemsPickedUp = atoi(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "SpecialEvents:" ) )
					{
					heuristic = script.GetToken(false);
					specialEvents = atoi(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "SkillLevel:" ) )
					{
					heuristic = script.GetToken(false);
					skillLevel = atof(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "QuetzalGunShots:" ) )
					{
					heuristic = script.GetToken(false);
					quetzalGunShots = atol(heuristic.c_str());
					}
				else if ( !Q_stricmp( token.c_str(), "MBowShots:" ) )
					{
					heuristic = script.GetToken(false);
					mbowShots = atol(heuristic.c_str());
					}
				}
			return;
			}
		}	  
	}

void PlayerHeuristics::WriteOutHeuristicData( str &levelName )
	{
	str s;
	str stat;
	
	//Build File String
	s = "Level: " + levelName + "\n";

	stat = shotsFired;
	s+= "ShotsFired: "		 + stat + "\n";
	
	stat = shotsHit;
	s+= "ShotsHit: "			 + stat + "\n";
	
	stat = numberOfDeaths;
	s+= "NumberOfDeaths: "   + stat + "\n";

	stat = redemptiveKills;
	s+= "RedemptiveKills: "  + stat + "\n";

	stat = assassinKills;
	s+= "AssassinKills: "    + stat + "\n";

	stat = timeOnLevel;
	s+= "TimeOnLevel: "		 + stat + "\n";

	stat = playerHealth;
	s+= "PlayerHealth: "		 + stat + "\n";

	stat = ping;
	s+= "Ping: "				 + stat + "\n";

	stat = itemsPickedUp;
	s+= "ItemsPickedUp: "	 + stat + "\n";

	stat = specialEvents;
	s+= "SpecialEvents: "	 + stat + "\n";

	stat = quetzalGunShots;
	s+= "QuetzalGunShots: "	 + stat + "\n" ;

	stat = mbowShots;
	s+= "MBowShots: "			+ stat + "\n";

	stat = skillLevel;
	s+= "SkillLevel: "	    + stat + "\n";

	s+= levelName + "_end";
	s+= "\n\n";

	gi.FS_Write( s, s.length(), heuristicFile );
   gi.FS_Flush( heuristicFile );

	}

void PlayerHeuristics::CreateInitialHeuristicFile()
	{
	//Clear Heuristic Data Structure;
	shotsFired = 0;
	shotsHit = 0;
	numberOfDeaths = 0;
	redemptiveKills = 0;
	assassinKills = 0;
	timeOnLevel = 0;
	levelStartTime = 0;
	levelEndTime = 0;
	playerHealth = 0;

	ping = 0;
	itemsPickedUp = 0;
	specialEvents = 0;
	
	quetzalGunShots = 0;
	mbowShots = 0;
	skillLevel = 0;

	OpenPlayerHeuristicFile();
	if ( !heuristicFile )
		{
      return;
		}
	
	WriteOutHeuristicData(level.mapname);
	ClosePlayerHeuristicFile();
	}



void PlayerHeuristics::OpenPlayerHeuristicFile()
	{
   if ( !heuristicFile )
      {
      heuristicFile = gi.FS_FOpenFileWrite( heuristicFileName.c_str() );
      }      
	}

void PlayerHeuristics::ClosePlayerHeuristicFile()
	{
   if ( heuristicFile )
      {
      gi.FS_FCloseFile( heuristicFile );
		heuristicFile = NULL;
      }
	}

void PlayerHeuristics::CheckForHeuristicFile()
	{
	str s,filename;
	int filesize;

   s = "heuristics";
   filename = gi.GetArchiveFileName( s, "log" );
	heuristicFileName = filename.c_str();

	filesize = gi.FS_ReadFile( heuristicFileName.c_str(), NULL, true );
	if ( filesize <= 0 ) //File Does Not Exsist
		CreateInitialHeuristicFile();
	}

float PlayerHeuristics::CalculateSkillLevel()
   {
   // Current Skill Level Formula
	// (((Accuracy * 100) * .75 ) + (1 - (Deaths * .25))) / 10
	// Returns a floating point number between 0 and 10

	// I expect this function to change a lot during the course of development
	// That is why it is written so verbosely.

	float Accuracy;
	float Deaths;
	float SkillLevel;

	Accuracy = (float)shotsHit / (float)shotsFired;
	Deaths = numberOfDeaths;

	SkillLevel = (((Accuracy * 100) * .75 ) + (1 - (Deaths * .25))) / 10;
	if (SkillLevel < 0 )
		{
		SkillLevel = 0.0f;
		}

	return SkillLevel;
	
	}

void PlayerHeuristics::SetShotsFired( long int shots )
	{
	shotsFired = shots;
	}

void PlayerHeuristics::IncrementShotsFired()
	{
   shotsFired++;
	}

void PlayerHeuristics::SetShotsHit( long int shots )
	{
   shotsHit = shots;
	}

void PlayerHeuristics::IncrementShotsHit()
	{
	shotsHit++;
	}

void PlayerHeuristics::SetNumberOfDeaths( long int deaths )
	{
   numberOfDeaths = deaths;
	}

void PlayerHeuristics::IncrementNumberOfDeaths()
	{
	numberOfDeaths++;
	}

void PlayerHeuristics::SetRedemptiveKills( long int kills )
	{
	redemptiveKills = kills;
	}

void PlayerHeuristics::IncrementRedemptiveKills()
	{
	redemptiveKills++;
	}

void PlayerHeuristics::SetAssassinKills( long int kills )
	{
	assassinKills = kills;
	}

void PlayerHeuristics::IncrementAssassinKills()
	{
	assassinKills++;
	}

void PlayerHeuristics::SetTimeOnLevel( float levelTime )
	{
	timeOnLevel = levelTime;
	}

void PlayerHeuristics::SetPlayerHealth( int health )
	{
	playerHealth = health;
	}

void PlayerHeuristics::SetPing( int ping_value )
	{
	ping = ping_value;
	}

void PlayerHeuristics::SetItemsPickedUp( int items )
	{
	itemsPickedUp = items;
	}

void PlayerHeuristics::IncrementItemsPickedUp()
	{
	itemsPickedUp++;
	}

void PlayerHeuristics::SetSpecialEvents( int specialevent )
	{
	specialEvents = specialevent;
	}

void PlayerHeuristics::IncrementSpecialEvents()
	{
	specialEvents++;
	}

void PlayerHeuristics::SetQGunShots( long int shots )
	{
	quetzalGunShots = shots;
	}

void PlayerHeuristics::IncrementQGunShots()
	{
	quetzalGunShots++;
	}

void PlayerHeuristics::SetMBowShots( long int shots )
	{
	mbowShots = shots;
	}

void PlayerHeuristics::IncrementMBowShots()
	{
	mbowShots++;
	}

void PlayerHeuristics::UpdateShotsFired(Player *player)
	{
	IncrementShotsFired();
	str WeaponName;

	Weapon* weapon = 0;
	
	weapon = player->GetActiveWeapon( WEAPON_DUAL );
	if (!weapon )
		{
		return;
		}
   
	WeaponName = weapon->getName();
	
	if ( !Q_stricmp( WeaponName.c_str(), "QGun" ) )
		{
		IncrementQGunShots();
		}
	else if ( !Q_stricmp( WeaponName.c_str(), "MedicineBow" ) )
		{
		IncrementMBowShots();
		};
	}