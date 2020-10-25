@Echo OFF
::EQU=Equal
::NEQ=!Equal
::LSS=Less
::LEQ=Less or Equal
::GTR=Greather then
::GEQ=Greather or Equal then
::ERRORLEVEL 1/0
cls
set calls=0
color 0B
::SET PARAMETERS================================================================
set config=stef2_coop_server.cfg
set dedicated=
set cheats=
set skill=
set maxclients=
set netport=
set password=
set startmap=
set selectMap=
set sv_hostname=
set mp_timelimit=
set executablename=
title=Coop SV CONF
:start
::Check OS
::ver | FINDSTR /IL "6.0." > NUL
::if %ERRORLEVEL% EQU 0 goto noVixta
::ver | FINDSTR /IL "6.1." > NUL
::if %ERRORLEVEL% EQU 0 goto noWin7

:check_dedicated
if not exist dedicated.exe goto check_ef2server
set executablename=dedicated.exe
goto selectDedicated

:check_ef2server
if not exist ef2server.exe goto check_quake3
set executablename=ef2server.exe
goto selectDedicated

:check_quake3
if not exist quake3.exe goto check_ef2
set executablename=quake3.exe
goto selectDedicated

:check_ef2
if not exist ef2.exe goto up
set executablename=ef2.exe
goto selectDedicated

REM Go one dir up, the bat file might be inside the base folder
:up
cd "../"
goto check_dedicatedUp

:check_dedicatedUp
if not exist dedicated.exe goto check_ef2serverUp
set executablename=dedicated.exe
goto selectDedicated

:check_ef2serverUp
if not exist ef2server.exe goto check_quake3Up
set executablename=ef2server.exe
goto selectDedicated

:check_quake3Up
if not exist quake3.exe goto check_ef2Up
set executablename=quake3.exe
goto selectDedicated

:check_ef2Up
if not exist ef2.exe goto wrongDir
set executablename=ef2.exe
goto selectDedicated

:wrongDir
cls
echo.
echo ---------------CAN-NOT-START-SERVER-----------
echo Could not find EF2.exe or quake3.exe!
echo Put this file in /base/ or where the ef2.exe or quake3.exe is located!
echo ----------------------------------------------
echo.
echo ***QUIT***
pause >NUL
exit


::LET USER SET PARAMATERS=======================================================
:selectDedicated
cls
IF /i "%username%"=="chrissstrahl" (
	copy "D:\GAMES\Star Trek\Elite Force II\Server EF2\base\gamex86.dll" "D:\GAMES\Star Trek\Elite Force II\STEF2_server\base\gamex86.dll"
	copy "D:\GAMES\Star Trek\Elite Force II\Server EF2\base\zzzzzz_co-op_hzm_script_mod.pk3" "D:\GAMES\Star Trek\Elite Force II\STEF2_server\base\zzzzzz_co-op_hzm_script_mod.pk3"
)
echo ===============================================================================
echo  WELCOME to the HaZardModding dedicated server tool. This tool allowes you
echo  to start and configure a dedicated STEF2 server in Windows. This tool will
echo  automatically restart the server, as neded.
echo ===============================================================================
echo.
echo 1. This tool might require administrative privilegs to work correctly
echo.
echo 2. The ef2.exe or quake3.exe might require administrative privilegs
echo.
echo 3 The ef2.exe or quake3.exe may need to be authorized in the Windows
echo   Firewall for outgoing and incomming data traffic
echo.
echo 4 You might need to activate Portforwarding for the ports 29253 and
echo   29254, targeting the computer that is hosting this dedicated server
echo.
echo 5. You can PRESS ENTER to SKIP or keep DEFAULT values at any option
echo.
echo PLEASE SELECT Server-Type you want to start (default=2)
echo ----------------------------------------------------
echo 1=LAN
echo 2=INTERNET (default press ENTER)
set dedicated=2
set /p dedicated=
if %dedicated% == 1 goto selectCheats
if %dedicated% == 2 goto selectCheats
goto selectDedicated

:selectCheats
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo -----------------------------------------------
echo.
echo Do you wish to activate cheats?
echo 0=No (default)
echo 1=Yes
echo 2=Back, change Server Type
set cheats=0
set /p cheats=
if %cheats% == 0 goto selectSkill
if %cheats% == 1 goto selectSkill
if %cheats% == 2 goto selectDedicated
goto selectCheats

:selectSkill
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo -----------------------------------------------
echo.
echo Please Select SKILL level, default is Normal!
echo 0=Easy
echo 1=Normal (default)
echo 2=Hard
echo 3=Very Hard
echo 4=Back, change cheats
set skill=1
set /p skill=
if %skill% == 0 goto selectMaxclients
if %skill% == 1 goto selectMaxclients
if %skill% == 2 goto selectMaxclients
if %skill% == 3 goto selectMaxclients
if %skill% == 4 goto selectCheats
goto selectSkill

:selectMaxclients
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo -----------------------------------------------
echo.
echo Please Select Maximum Number Of Player-Slots (2-8)!
echo Less slots costs Less Bandwidth/Performance (default 4)
echo 0=Back, change skill
set maxclients=4
set /p maxclients=
if %maxclients% == 0 goto selectSkill
if %maxclients% == 2 goto selectNetPort
if %maxclients% == 3 goto selectNetPort
if %maxclients% == 4 goto selectNetPort
if %maxclients% == 5 goto selectNetPort
if %maxclients% == 6 goto selectNetPort
if %maxclients% == 7 goto selectNetPort
if %maxclients% == 8 goto selectNetPort
goto selectMaxclients

:selectNetPort
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
REM echo Time Limit	=%mp_timelimit%
echo -----------------------------------------------
echo.
echo Press enter to SKIP and keep default
echo.
echo WARNING====================
echo IF YOU CHANGE THE DEFAULT PORT, YOU WILL ALSO NEED TO
echo ADD OR ADJUST THAT PORT IN YOUR PORTFORWARDING SETTINGS
echo.
echo Enter netport, preferably above 1200 (default 29253)
echo ===========================
echo 0=Back, change Max Clients
set netport=29253
set /p netport=
if %netport% == 0 goto selectMaxclients
if %netport% == LSS 23 goto selectNetPort
if %netport% == 80 goto selectNetPort
if %netport% == 81 goto selectNetPort
if %netport% == 88 goto selectNetPort
goto setHostname

:setHostname
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo -----------------------------------------------
echo.
echo Enter a Server Name of your choise.
echo.
echo - You can NOT use color codes due to batch limitations.
echo - You can NOT use space, unless you "qoute the name"
echo Edit the cvar sv_hostname directly to add colors.
echo 0=Back, change netport
echo.
set sv_hostname=Coop-%username%
set /p sv_hostname=
if %sv_hostname% == 0 goto selectNetPort
goto selectLevel

:selectLevel
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select the Type of Level you want the Server to start with.
echo.
echo 1=Start a Secret Level
echo 2=Start a Training
echo 3=Start a Mission
echo 4=Start a Custom Level
echo 5=Start a GBS Mod Level
echo 6=Start a ROTEC Mod Level
echo 7=Start a City Mod Level
echo 8=Enter Map Name
echo 0=Back, change Server Name
set selectMap=8
set /p selectMap=
if %selectMap% == 1 goto selectLevelSecret
if %selectMap% == 2 goto selectLevelTraining
if %selectMap% == 3 goto selectLevelMission
if %selectMap% == 4 goto selectCustomLevel
if %selectMap% == 5 goto selectGBSLevel
if %selectMap% == 6 goto selectROTECLevel
if %selectMap% == 7 goto selectCityLevel
if %selectMap% == 8 goto enterLevelName
if %selectMap% == 0 goto setHostname
goto selectLevel

:selectLevelSecret
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select a SECERET map you want to start
echo 1 = secret1		(Swamp Shack)
echo 2 = secret2 		(Modern Ruin)
echo 3 = ef2_minigame2	(The Gauntlet)
echo 4 = secret3		(Cloning Facility)
echo 5 = zoo1		(Game Concept Art Gallery)
echo 6 = testmorph		(Character Gallery)
echo 0 = Back, select a different Map
set /p selectMap=
if %selectMap% == 1 set startmap=secret1
if %selectMap% == 2 set startmap=secret2
if %selectMap% == 3 set startmap=ef2_minigame2
if %selectMap% == 4 set startmap=secret3
if %selectMap% == 5 set startmap=zoo1
if %selectMap% == 6 set startmap=testmorph
if %selectMap% == 0 goto selectLevel
goto setPassword

:selectLevelTraining
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select a TRAINING map you want to start
echo 1 = ent-training1	(Training with Tuvok: Jump/Duck/Climb )
echo 2 = ent-training2	(Training with Tuvok: Strafe/Suit/Consoles )
echo 3 = ent-training3	(Training with Tuvok: Tricorder/Modulation )
echo 4 = ent-training4	(Training with Tuvok: Weapons )
echo 0 = Back, select a different Map
set /p selectMap=
if %selectMap% == 1 set startmap=ent-training1
if %selectMap% == 2 set startmap=ent-training2
if %selectMap% == 3 set startmap=ent-training3
if %selectMap% == 4 set startmap=ent-training4
if %selectMap% == 0 goto selectLevel
goto setPassword

:selectLevelMission
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select a MISSION you want to start
echo 1  = m1l1a-borg_sphere		(End Game - Borg Sphere)
echo 2  = m2l0-sfa			(Reassignment - Starfleet Academy)
echo 3  = m3l1a-forever		(Derelict - USS Dallas)
echo 4  = m4l1a-attrexian_station	(Demise - Attrexian Station)
echo 5  = m5l1a-drull_ruins1		(Discovery - Alien Planet)
echo 6  = m6l0-attack		(Destruction - Enterprise-E)
echo 7  = m7l1a-attrexian_colony	(Search and Rescue - Attrexian Colony)
echo 8  = m8l1a-drull_ruins2		(Payback - Ancient Idryll Planet)
echo 9  = m9l1a-klingon_base		(Mercenaries - K7 Starbase)
echo 10 = m10l1a-romulan_base	(Incognito - Secret Romulan Installation)
echo 11 = m11l1a-drull_ruins3	(End Game 2 - Master Control Facility)
echo 0 = Back, select a different Map
set /p selectMap=
if %selectMap% == 0 goto selectLevel
if %selectMap% == 11 set startmap=m11l1a-drull_ruins3
if %selectMap% == 10 set startmap=m10l1a-romulan_base
if %selectMap% == 9 set startmap=m9l1a-klingon_base
if %selectMap% == 8 set startmap=m8l1a-drull_ruins2
if %selectMap% == 7 set startmap=m7l1a-attrexian_colony
if %selectMap% == 6 set startmap=m6l0-attack
if %selectMap% == 5 set startmap=m5l1a-drull_ruins1
if %selectMap% == 4 set startmap=m4l1a-attrexian_station
if %selectMap% == 3 set startmap=m3l1a-forever
if %selectMap% == 2 set startmap=m2l0-sfa
if %selectMap% == 1 set startmap=m1l1a-borg_sphere
goto setPassword

:selectCustomLevel
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select a CUSTOM level you want to start
echo 1  = Bat'leth Arena		(coop_blArena)
echo 2  = Ice Station		(coop_iceStation)
echo 3  = Co-op H'atoria Outpost	(coop_hatoriaOutpost)	
echo 4  = Paradise Island		(coop_paradiseIsland)
echo 5  = Paradise Island -2-	(coop_paradiseIsland2)
echo 6  = Alien			(coop_alien)
echo 7  = Bugs			(coop_bugs)
echo 8  = Rescue Cell		(coop_rescueChell)
echo 9  = Exuinox		(coop_equinox)
echo 0  = Back, select a different Map
set /p selectMap=
if %selectMap% == 0 goto selectLevel
if %selectMap% == 9 set startmap=coop_equinox
if %selectMap% == 8 set startmap=coop_rescueChell
if %selectMap% == 7 set startmap=coop_bugs
if %selectMap% == 6 set startmap=coop_alien
if %selectMap% == 5 set startmap=coop_paradiseIsland2
if %selectMap% == 4 set startmap=coop_paradiseIsland
if %selectMap% == 3 set startmap=coop_hatoriaOutpost
if %selectMap% == 2 set startmap=coop_iceStation
if %selectMap% == 1 set startmap=coop_blArena
goto setPassword

:selectGBSLevel
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select the A Gate two Birds and the Beautiful Sky Mod level you want to start
echo 1  = coop_gbs1		(START - Holodeck)
echo 2  = coop_gbs2		(USS ATLANTIS - Bar)
echo 3  = coop_gbs3		(USS ATLANTIS - Engenniereing)
echo 4  = coop_gbs4		(USS ATLANTIS - Sickbay)
echo 5  = coop_gbs5		(USS ATLANTIS - Transporter Room)
echo 6  = coop_gbs6		(USS ATLANTIS - Shuttlebay)
echo 7  = coop_gbs7		(ANTIOCH SYSTEM - Klingon Base)
echo 8  = coop_gbs8		(ROMULAN WARBIRD)
echo 9  = coop_gbs9		(ROMULAN OUTPOST - Surface)
echo 10 = coop_gbs10		(ROMULAN OUTPOST - Installation)
echo 11 = coop_gbsCredits	(GBS Credits)
echo 0  = Back, select a different Map
set /p selectMap=
if %selectMap% == 0 goto selectLevel
if %selectMap% == 11 set startmap=coop_gbsCredits
if %selectMap% == 10 set startmap=coop_gbs10
if %selectMap% == 9 set startmap=coop_gbs9
if %selectMap% == 8 set startmap=coop_gbs8
if %selectMap% == 7 set startmap=coop_gbs7
if %selectMap% == 6 set startmap=coop_gbs6
if %selectMap% == 5 set startmap=coop_gbs5
if %selectMap% == 4 set startmap=coop_gbs4
if %selectMap% == 3 set startmap=coop_gbs3
if %selectMap% == 2 set startmap=coop_gbs2
if %selectMap% == 1 set startmap=coop_gbs1
goto setPassword

:selectROTECLevel
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select the Return of the Empty Crown Mod level you want to start
echo 1  = coop_rotec1		(START - USS Odyssey-A)
echo 2  = coop_rotec2		(Attrexia - Landing)
echo 3  = coop_rotec3		(Attrexia - Installation)
echo 4  = coop_rotec4		(Attrexia - Mining)
echo 5  = coop_rotec5		(Attrexia - Central)
echo 6  = coop_rotec6		(Attrexia - Central)
echo 7  = coop_rotec7		(USS Odyssey-A - Back again)
echo 8  = coop_rotec8		(USS Odyssey-A - Relaxation)
echo 0  = Back, select a different Map
set /p selectMap=
if %selectMap% == 0 goto selectLevel
if %selectMap% == 1 set startmap=coop_rotec1
if %selectMap% == 2 set startmap=coop_rotec2
if %selectMap% == 3 set startmap=coop_rotec3
if %selectMap% == 4 set startmap=coop_rotec4
if %selectMap% == 5 set startmap=coop_rotec5
if %selectMap% == 6 set startmap=coop_rotec6
if %selectMap% == 7 set startmap=coop_rotec7
if %selectMap% == 8 set startmap=coop_rotec8
goto setPassword

:selectCityLevel
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Select the Aftermath Mod level you want to start
echo 1  = coop_aftermath1		(START - E1 The City pt1)
echo 2  = coop_aftermath2		(E1 The City pt2)
echo 3  = coop_aftermath3		(E1 The City pt3)
echo 4  = coop_aftermath4		(E1 The City pt4)
echo 0  = Back, select a different Map
set /p selectMap=
if %selectMap% == 0 goto selectLevel
if %selectMap% == 1 set startmap=coop_aftermath1
if %selectMap% == 2 set startmap=coop_aftermath2
if %selectMap% == 3 set startmap=coop_aftermath3
if %selectMap% == 4 set startmap=coop_aftermath4
goto setPassword

:enterLevelName
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo -----------------------------------------------
echo.
echo Enter the exact mapname of the level you want to start
set startmap=zoo1
set /p startmap=
if %startmap% == 0 goto enterLevelName
if "%startmap%" == "" goto enterLevelName
goto setPassword

:setConfig
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo map		=%startmap%
echo -----------------------------------------------
echo.
echo Set a filename for your server config
echo Please note that the logfile will also use that name
echo.
echo You can either select a predefined Config name or simply
echo type your own filename and press enter.
echo.
echo 0	= Coop Mod (default):		stef2_coop_server.cfg
echo 1	= Dedicated Multiplayer:	stef2_dedicated_server.cfg
set config=stef2_coop_server.cfg
set /p config=
if "%config%" == "0" goto setConfigCoop
if "%config%" == "1" goto setConfigDedicated
if "%config%" == "" goto setConfig
goto start_warning

:setConfigCoop
set config=stef2_coop_server.cfg
goto start_warning

:setConfigDedicated
set config=stef2_dedicated_server.cfg
goto start_warning

:setPassword
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo map		=%startmap%
echo -----------------------------------------------
echo.
echo Set a Password to make your Server private
echo Passwords are Case Sensitive! No whitespace/spacebar or special characters
echo.
echo BLANK	= Set no password (empty)
echo 0	= Go back and select a different Map
set password=
set /p password="Set Password: "
if "%password%" == "0" goto selectLevel
goto start_warning

:start_warning
cls
echo.
echo PARAMETERS:
echo executable	=%executablename%
echo dedicated	=%dedicated%
echo cheats		=%cheats%
echo skill		=%skill%
echo Slots		=%maxclients%
echo net_port	=%netport%
echo Server Name	=%sv_hostname%
echo map		=%startmap%
echo password	=%password%
echo config		=%config%
echo -----------------------------------------------
echo.
echo ++++++++++++++++++++++++++++++++++++++++++++++++++
echo THE SERVER IS NOW CONFIGURED FULLY AND WILL START
echo UPON PRESSING ENTER...
echo ++++++++++++++++++++++++++++++++++++++++++++++++++
echo.
echo 0	= Go back and select a different password
echo 1	= Set different server config name
set engage=99
set /p engage=
if %engage% == 0 goto setPassword
if %engage% == 1 goto setConfig
goto start_sv

:start_sv
cls
set /A calls=%calls% + 1
title=Coop SV #%calls%
if %calls% == 2000 goto callsToMuch
ipconfig
echo.
echo.
echo ------------------------------------------
echo STARTING dedicated Coop SERVER! RESTARTS: %calls%
echo ------------------------------------------
echo START LEVEL:	%startmap%
echo executable	=%executablename%
if %dedicated% LSS 2	echo dedicated	=%dedicated%	(LocalAreaNetwork)
if %dedicated% == 2		echo dedicated	=%dedicated%	(Internet)

if %cheats% == 0		echo cheats		=%cheats%	(off)
if %cheats% == 1		echo cheats		=%cheats%	(on)

if %skill% == 0			echo skill		=%skill%	(Easy)
if %skill% == 1			echo skill		=%skill%	(Normal)
if %skill% == 2			echo skill		=%skill%	(Hard)
if %skill% == 3			echo skill		=%skill%	(Ritualistic)

echo Slots		=%maxclients%

if %netport% == 29253	echo net_port	=%netport%	(default)
if %netport% NEQ 29253	echo net_port	=%netport%	(costum)
echo Server Name	=%sv_hostname%
if "%password%" == "" (
	echo password	=Empty/None
) else (
	echo password	=%password%
)
echo Config		=%config%
echo.
echo (Enter net_port into game console to check real netport)
echo.

REM sv_cheats used to be cheats
REM sv_cheats used to be cheats
REM sv_cheats used to be cheats
REM sv_cheats used to be cheats
 
if %startmap%==restart_server (
	if "%password%" == "" (
		%executablename% +logfile 1 +set cheats %cheats% +set developer %cheats% +set config %config% +set g_gametype 1 +set net_port %netport% +set dedicated %dedicated% +set skill %skill% +set sv_maxclients %maxclients% +set sv_hostname %sv_hostname% +map zoo1
	) else (
		%executablename% +logfile 1 +set cheats %cheats% +set developer %cheats% +set config %config% +set g_gametype 1 +set net_port %netport% +set dedicated %dedicated% +set skill %skill% +set sv_maxclients %maxclients% +set password %password% +set sv_hostname %sv_hostname% +map zoo1
	)

) else (
	if "%password%" == "" (
		%executablename% +logfile 1 +set cheats %cheats% +set developer %cheats% +set config %config% +set g_gametype 1 +set net_port %netport% +set dedicated %dedicated% +set skill %skill% +set sv_maxclients %maxclients% +set sv_hostname %sv_hostname% +map %startmap%
	) else (
		%executablename% +logfile 1 +set cheats %cheats% +set developer %cheats% +set config %config% +set g_gametype 1 +set net_port %netport% +set dedicated %dedicated% +set skill %skill% +set sv_maxclients %maxclients% +set password %password% +set sv_hostname %sv_hostname% +map %startmap%
	)
)

set startmap=restart_server
goto start_sv

:callsToMuch
cls
echo.
echo ----------------------------------------------
echo The Bat File was called %calls% times, and has
echo stopped now, a error is assumed! Contact us.
echo ----------------------------------------------
echo.
echo ***QUIT***
pause >NUL
exit

