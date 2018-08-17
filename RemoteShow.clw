; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdminDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RemoteShow.h"

ClassCount=8
Class1=CRemoteShowApp
Class2=CRemoteShowDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_REMOTESHOW_DIALOG
Resource4=IDD_EXIT_DIALOG (English (U.S.))
Resource5=IDD_ABOUTBOX (English (U.S.))
Class4=CAdminDlg
Class5=CHSocket
Resource6=IDD_REMOTESHOW_DIALOG (English (U.S.))
Class6=CClientDlg
Resource7=IDD_ADMIN_DLG
Class7=CMsgDlg
Resource8=IDD_CLIENT
Class8=CExitDlg
Resource9=IDD_MESSAGE

[CLS:CRemoteShowApp]
Type=0
HeaderFile=RemoteShow.h
ImplementationFile=RemoteShow.cpp
Filter=N

[CLS:CRemoteShowDlg]
Type=0
HeaderFile=RemoteShowDlg.h
ImplementationFile=RemoteShowDlg.cpp
Filter=D
LastObject=IDC_NAME
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RemoteShowDlg.h
ImplementationFile=RemoteShowDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_REMOTESHOW_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CRemoteShowDlg

[DLG:IDD_REMOTESHOW_DIALOG (English (U.S.))]
Type=1
Class=CRemoteShowDlg
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_PASS,edit,1350631552
Control6=IDC_STATIC,static,1342177283
Control7=IDOK,button,1342242817
Control8=IDC_TOGGLE_PASS,button,1342242819
Control9=ID_HELP,button,1342242816
Control10=IDCANCEL,button,1342242816
Control11=IDC_STATUS,edit,1350633600

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[CLS:CAdminDlg]
Type=0
HeaderFile=AdminDlg.h
ImplementationFile=AdminDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SHOCKWAVEFLASH1
VirtualFilter=dWC

[CLS:CHSocket]
Type=0
HeaderFile=HSocket.h
ImplementationFile=HSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CHSocket

[DLG:IDD_ADMIN_DLG]
Type=1
Class=CAdminDlg
ControlCount=33
Control1=IDC_STATIC,button,1342177287
Control2=IDC_USERS,combobox,1344339969
Control3=IDC_ACCEPT,button,1342242816
Control4=IDC_DENY,button,1342242816
Control5=IDC_DISCONNECT,button,1342242816
Control6=IDC_DC_ALL,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_SET_MOVIE,button,1342242816
Control9=IDC_FORWARD,button,1342242816
Control10=IDC_PLAY,button,1342242816
Control11=IDC_BACKWARD,button,1342242816
Control12=IDC_PAUSE,button,1342242816
Control13=IDC_FRAME,button,1342242816
Control14=IDC_FRAME_NO,edit,1350631552
Control15=IDC_STATIC,button,1342177287
Control16=IDC_MINIMIZE,button,1342242816
Control17=IDC_FLASH_SCREEN,button,1342242816
Control18=IDC_EXIT,button,1342242816
Control19=IDC_POWER,button,1342242816
Control20=IDC_SEND_MESSAGE,button,1342242816
Control21=IDC_GET_MESSAGE,button,1342242816
Control22=IDOK,button,1342242817
Control23=IDCANCEL,button,1342242816
Control24=IDC_STATUS,edit,1350633600
Control25=IDC_SHOCKWAVEFLASH1,{D27CDB6E-AE6D-11CF-96B8-444553540000},1342242816
Control26=IDC_IMAGE,static,1342181379
Control27=IDC_AUTO_ACCEPT,button,1342242819
Control28=IDC_MOVIE_LIST,ComboBoxEx32,1344340226
Control29=IDC_STATIC,static,1342177283
Control30=IDC_STATIC,static,1342177283
Control31=IDC_STATIC,static,1342177283
Control32=IDC_STATIC,static,1342181383
Control33=IDC_FRAME_NUMBER,static,1342308352

[DLG:IDD_CLIENT]
Type=1
Class=CClientDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_SHOCKWAVEFLASH,{D27CDB6E-AE6D-11CF-96B8-444553540000},1342242816
Control3=IDC_STATUS,static,1342308352
Control4=IDC_IMG,static,1342177283

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_IMG

[DLG:IDD_MESSAGE]
Type=1
Class=CMsgDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PAD,edit,1350631556
Control5=IDC_STATIC,static,1342177283

[CLS:CMsgDlg]
Type=0
HeaderFile=MsgDlg.h
ImplementationFile=MsgDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMsgDlg
VirtualFilter=dWC

[DLG:IDD_EXIT_DIALOG (English (U.S.))]
Type=1
Class=CExitDlg
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_LOGOFF,button,1342177289
Control3=IDC_POWEROFF,button,1342177289
Control4=IDC_RESTART,button,1342177289
Control5=IDC_SHUTDOWN,button,1342177289
Control6=IDC_ACTION,button,1342242816
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342177283

[CLS:CExitDlg]
Type=0
HeaderFile=ExitDlg.h
ImplementationFile=ExitDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CExitDlg

