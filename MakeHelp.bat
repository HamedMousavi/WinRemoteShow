@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by REMOTESHOW.HPJ. >"hlp\RemoteShow.hm"
echo. >>"hlp\RemoteShow.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\RemoteShow.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\RemoteShow.hm"
echo. >>"hlp\RemoteShow.hm"
echo // Prompts (IDP_*) >>"hlp\RemoteShow.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\RemoteShow.hm"
echo. >>"hlp\RemoteShow.hm"
echo // Resources (IDR_*) >>"hlp\RemoteShow.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\RemoteShow.hm"
echo. >>"hlp\RemoteShow.hm"
echo // Dialogs (IDD_*) >>"hlp\RemoteShow.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\RemoteShow.hm"
echo. >>"hlp\RemoteShow.hm"
echo // Frame Controls (IDW_*) >>"hlp\RemoteShow.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\RemoteShow.hm"
REM -- Make help for Project REMOTESHOW


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\RemoteShow.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\RemoteShow.hlp" goto :Error
if not exist "hlp\RemoteShow.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\RemoteShow.hlp" Debug
if exist Debug\nul copy "hlp\RemoteShow.cnt" Debug
if exist Release\nul copy "hlp\RemoteShow.hlp" Release
if exist Release\nul copy "hlp\RemoteShow.cnt" Release
echo.
goto :done

:Error
echo hlp\RemoteShow.hpj(1) : error: Problem encountered creating help file

:done
echo.
