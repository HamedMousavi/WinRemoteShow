// ExitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "ExitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExitDlg dialog


CExitDlg::CExitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExitDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExitDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExitDlg, CDialog)
	//{{AFX_MSG_MAP(CExitDlg)
	ON_BN_CLICKED(IDC_ACTION, OnAction)
	ON_BN_CLICKED(IDC_LOGOFF, OnLogoff)
	ON_BN_CLICKED(IDC_POWEROFF, OnPoweroff)
	ON_BN_CLICKED(IDC_RESTART, OnRestart)
	ON_BN_CLICKED(IDC_SHUTDOWN, OnShutdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExitDlg message handlers

void CExitDlg::OnAction() 
{
	CDialog::OnOK();
}

void CExitDlg::OnCancel() 
{
//	m_act="";
	CDialog::OnCancel();
}

void CExitDlg::OnLogoff() 
{
	m_act="LOG_OFF";
}

void CExitDlg::OnPoweroff() 
{
	m_act="POWER_OFF";
}

void CExitDlg::OnRestart() 
{
	m_act="RESTART";
}

void CExitDlg::OnShutdown() 
{
	m_act="SHUT_DOWN";
}

CString CExitDlg::GetAction()
{
	return m_act;
}

BOOL CExitDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_act="";

	HICON Hi = AfxGetApp()->LoadIcon(IDI_POWER);
	SetIcon(Hi,FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
