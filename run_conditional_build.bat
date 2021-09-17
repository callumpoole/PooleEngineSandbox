:: Ask to remove old DIR? /S is force, but it will ask Y or N since there's no /Q for quiet
if "%~1"=="Y" goto REMOVE_BUILD_SILENT
if "%~1"=="N" goto MAKE_SOLUTION
if exist build\ goto REMOVE_BUILD_PROMPT

goto MAKE_SOLUTION

:REMOVE_BUILD_SILENT
rmdir build /S /Q
goto MAKE_SOLUTION

:REMOVE_BUILD_PROMPT
rmdir build /S
goto MAKE_SOLUTION

:: Go to dir, make solution file
:MAKE_SOLUTION
mkdir build
cd build
cmake ..

:: Ask to build it too?
if "%~2"=="Y" goto BUILD_ANYWAY
if "%~2"=="N" goto END

goto BUILD_PROMPT

:BUILD_ANYWAY
cmake --build .
::Allow them to read the build output
@pause
goto END

@echo off
setlocal
:BUILD_PROMPT
SET /P BUILD_TOO=Build it too (Y/[N])?
IF /I "%BUILD_TOO%" NEQ "Y" GOTO END_BUILD_PROMPT

cmake --build .
::Allow them to read the build output
@pause

:END_BUILD_PROMPT
endlocal
@echo on

:END