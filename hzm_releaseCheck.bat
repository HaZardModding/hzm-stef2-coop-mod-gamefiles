@echo off
cls
color 0B
echo.
echo ---PLEASE-CHECK-THESE-FILES-BEFORE-RELEASE----
echo This is meant to help improve the process of
echo preparing a relase of the HZM Coop Mod.
echo.
echo -1--------------------------setup_mainmenu.inc
echo Check Build version in Main menu include file.
echo :: cvarvisibility coop_ver 6xx !=
echo ----------------------------------------------
start coop_mod\ui\setup_mainmenu.inc
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2-----------------------------------setup.cfg
echo Check Coop Version Commands
echo seta coop_ver 6xx
echo seta coop_verInfo "coopinstalled 6xx"
echo ----------------------------------------------
start coop_mod\cfg\setup.cfg
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo Check Build version in Gamecode, game.h
echo #define COOP_BUILD 6xx
echo ----------------------------------------------
cd ../
start GAMECODE\code\dlls\game\game.h
cd GAMEFILES
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo Check if INI-Files need updating.
echo New Enemies and Kill Messages ?
echo New Maps, new Map voting Options ?
echo ----------------------------------------------
start deathlist.ini
start maplist.ini
start vote_maplist.ini
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo -5------------------------globalstrings.loc---
echo Check if global localization files need updating.
echo Are there any new strings added for menus/huds ?
echo ----------------------------------------------
start loc\deu\stringresource\globalstrings.loc
start loc\eng\stringresource\globalstrings.loc
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo -5------------------------globalstrings.loc---
echo -6------------------------hcm_changelog.txt---
echo Check changelog if all entries are made and
echo file looks clean.
echo Located in Relaase Folder!
echo ----------------------------------------------
cd ../
start RELASE
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo -5------------------------globalstrings.loc---
echo -6------------------------hcm_changelog.txt---
echo -7---------------------------hcm_readme.pdf---
echo Check changelog if the Readme file needs update.
echo Verify readme to be latest version.
echo ----------------------------------------------
cd GAMEFILES
start hcm_readme.pdf
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo -5------------------------globalstrings.loc---
echo -6------------------------hcm_changelog.txt---
echo -7---------------------------hcm_readme.pdf---
echo -8-------------compile and copy then upload---
echo Check compile and copy latest gamecode.
echo Create and copy windows dll and linux so.
echo Create and copy all needed pk3 files.
echo Upload to HZM Updater Web Folder.
echo ----------------------------------------------
cd ../
start RELASE
start GAMEFILES
start GAMECODE\coop_game.sln
cd ../../../../games/COOP EF2/
start base
pause

cls
echo -1--------------coop_mod\ui\setup_mainmenu.inc
echo -2----------------------coop_mod\cfg\setup.cfg
echo -3------------------c++ Gamecode Build Version
echo -4--------------------------------INI-FILES---
echo -5------------------------globalstrings.loc---
echo -6------------------------hcm_changelog.txt---
echo -7---------------------------hcm_readme.pdf---
echo -8-------------compile and copy then upload---
echo.
echo ----------------------------------------------
echo YAY, all should now be complete!
echo ----------------------------------------------
pause>NUL
