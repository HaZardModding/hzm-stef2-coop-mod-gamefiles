:: @echo on
@echo off

:: echo Please Wait. Generating List of All TIKs sorted by Category
:: Note, now that TIKs are located in many subdirectories, 
:: global sorting is impossible, so these are sorted separately 
:: for each subdirectory.
dir *.scr /b /o a /s > maps.lst
dir *.script /b /o a /s > maps2.lst
pause

@echo off

:: pause

:: echo Complete