// RemoteShow.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "RemoteShowDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRemoteShowApp

BEGIN_MESSAGE_MAP(CRemoteShowApp, CWinApp)
	//{{AFX_MSG_MAP(CRemoteShowApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemoteShowApp construction

CRemoteShowApp::CRemoteShowApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRemoteShowApp object

CRemoteShowApp theApp;

BOOL g_appType;
CString g_folderAddress;

/////////////////////////////////////////////////////////////////////////////
// CRemoteShowApp initialization

BOOL CRemoteShowApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CRemoteShowDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
