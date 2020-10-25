::chrissstrahl 2019.10.28
::Most of this stuff is copy and paste from superuser.com or stackoverflow.com
@Echo OFF
::%~dp0 //cur script dir
set spacer=	
set removedFiles=0
set criticalErrors=0
set errorList=The following Errors occured:%spacer%
color 0B
:start
echo CHECKING IF GAME IS RUNNING
qprocess "ef2.exe">NUL
if %ERRORLEVEL% EQU 0 goto running
qprocess "quake3.exe">NUL
if %ERRORLEVEL% EQU 0 goto running
:welcome
cls
echo ===============================================================================
echo  WELCOME to the HaZardModding uninstaller tool. This tool will uninstall the
echo  HaZardModding Coop Mod for Star Trek Elite Force II.
echo  - Removing all associated files.
echo  - Restoring default files.
echo ===============================================================================
echo.
echo ! This tool might require administrative privilegs to work correctly
echo.
echo Press Y to completly remove the HZM Coop Mod now.
set engage=n
set /p engage=
if %engage% == Y goto detect
if %engage% == y goto detect
if %engage% == t goto test
echo %engage%
goto exit

::detect files dir
:detect
echo DETECTING YOUR GAME INSTALLATION
::WINDOWS 10
for /f "tokens=2*" %%a in ('reg query "HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Activision\Elite Force II" /v InstallPath 2^>^&1^|find "REG_"') do @set fn=%%b
if exist "%fn%base/pak0.pk3" goto useRegEntry
::OLD WINDOWS
for /f "tokens=2*" %%a in ('reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Activision\Elite Force II" /v InstallPath 2^>^&1^|find "REG_"') do @set fn=%%b
if exist "%fn%base/pak0.pk3" goto useRegEntry
echo NO REGESTRY ENTRY FOUND, QUICK SEARCHING FOLDER
if exist ../base/ goto enterParentBase
if exist ../EF2/base/ goto enterParentEF2Base
if exist /base/ goto enterBase
if exist /EF2/base/ goto enterEF2Base
:detect2
if exist pak0.pk3 goto uninstall
set errorList=%errorList%The /EF2/base/ folder could not be found.%spacer%
set /A criticalErrors=%criticalErrors%+1
echo.
echo The tool could not find the HZM Coop Mod files.
echo No changes where made, tool aborting.
echo.
goto exit

:useRegEntry
echo VALID REGESTRY ENTRY FOUND
cd %fn%/base/
goto detect2

:enterParentBase
cd ../base/
goto detect2

:enterParentEF2Base
cd ../base/
goto detect2

:enterBase
cd /base/
goto detect2

:enterEF2Base
cd /EF2/base/
goto detect2

::UNINSTALL here
:uninstall
echo GAME INSTALLATION DETECTED
echo STARTING UNINSTALL
CALL :removeFile "gamex86.dll"
CALL :removeFile "ef2gamei386.so"
CALL :removeFile "zzzzzz_co-op_hzm_mod.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_mod_vlp.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_mod_dialogENG.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_mod_dialogDEU.pk3"
CALL :removeFile "z_hzm_co-op_v1.0.pk3"
CALL :removeFile "zzz_co-op_inventory.pk3"
CALL :removeFile "hzm_co-op_matrix-2.0.pk3"
CALL :removeFile "zzz_co-op_clientside.pk3"
CALL :removeFile "hzm_co-op_matrix-2.1.pk3"
CALL :removeFile "zzz_co-op_maps_secrets-2.0.pk3"
CALL :removeFile "zzz_co-op_maps_secrets-2.1.pk3"
CALL :removeFile "zz_advanced_health_hud_mod.pk3"
CALL :removeFile "zzz_co-op_maps_trainings-2.1.pk3"
CALL :removeFile "zzzzzz_co-op_noblueteamarrow.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_script_mod_mini.pk3"
CALL :removeFile "zzzzzzz_co-op_hzm_script_mod_pak50.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_script_mod_deutsch.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_script_mod_english.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_script_mod_8player.pk3"
CALL :removeFile "zzzzzz_co-op_hzm_script_mod_clientonly.pk3"
CALL :removeFile "zzzzzzzzzzzzzzzzzzzzzzzzzzz_co-op_hzm_script_mod_zPak50.pk3"
CALL :removeBetaFiles
CALL :restoreGamex86
echo.
echo %removedFiles% files where removed succsessfuly.
echo.
if %engage% == t ( CALL :removeDir "%TEMP%\EF2" )

::unzip -source C:\myDir\myZip.zip -destination C:\MyDir -keep yes -force no
::https://stackoverflow.com/questions/21704041/creating-batch-script-to-unzip-a-file-without-additional-zip-tools
::echo 
goto exit

:removeBetaFiles
@echo off
setlocal
echo - removing beta files
del !*.pk3
goto eof

::RESTORE DLL
::CALL %cd%/_tools_/gamex86_restore.exe -InstallPath ./ -y
:restoreGamex86
echo - restoring default gamex86.dll
if exist gamex86.bak (
	CALL :renameFile "gamex86.bak" "gamex86.dll"
) else (
	set errorList=%errorList%gamex86.bak could not be found.%spacer%
	set /A criticalErrors=%criticalErrors%+1
)
echo off
goto :eof

::removing given file
::del %~1 /f /q
:removeFile
if exist %~1 (
	echo - removing %~1
	del %~1 /f /q
::del %~1
	set /A removedFiles=%removedFiles%+1
)
goto :eof

::rename given file
::ren %~1 %~2
:renameFile
if exist %~1 (
	echo - renaming %~1 to %~2 
	ren %~1 %~2 
)
goto :eof

::removing given directory
:removeDir
if exist %~1 (
	echo - removing folder %~1
	rd /s /q %~1
)
goto :eof

::creates testfiles and fakes the directory of the game
::this is used for testing if all features of this tool work
::CALL :removeDir "%TEMP%\EF2\"
:test
if not exist "%TEMP%\EF2\" mkdir "%TEMP%\EF2"
if not exist "%TEMP%\EF2\base\" mkdir "%TEMP%\EF2\base"
CD /D %TEMP%\EF2\base\
if not exist "%TEMP%\EF2\base\pak0.pk3" ( CALL :createTestFile "pak0.pk3" )
CALL :createTestFile "gamex86.bak"
CALL :createTestFile "gamex86.dll"
CALL :createTestFile "ef2gamei386.so"
CALL :createTestFile "zzzzzz_co-op_hzm_mod.pk3"
CALL :createTestFile "zzzzzz_co-op_hzm_mod_vlp.pk3"
CALL :createTestFile "zzzzzz_co-op_hzm_mod_dialogENG.pk3"
CALL :createTestFile "zzzzzz_co-op_hzm_mod_dialogDEU.pk3"
CALL :createTestFile "!coop_test.pk3"
::%SystemRoot%\explorer.exe "%TEMP%\EF2\base\"
goto detect2

::creates a test file for testing mode
:createTestFile
echo>This is a test file, it has no use anmyore and can be deleted>%~1
goto :eof

:running
cls
echo WELCOME to the HaZardModding uninstaller tool.
echo.
echo Please close the game, it seams to be still running...
echo.
pause
goto start

::exit here
:exit
if %criticalErrors% GTR 0 (
	echo WARNING: %criticalErrors% Critical Errors occured.
	echo %errorList%
)
echo.
echo Press any key to exit...
pause>NUL
exit