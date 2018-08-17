// MsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog


CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsgDlg)
	m_message = _T("");
	//}}AFX_DATA_INIT
}


void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsgDlg)
	DDX_Text(pDX, IDC_PAD, m_message);
	DDV_MaxChars(pDX, m_message, 1000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CMsgDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg message handlers

void CMsgDlg::OnOK() 
{
	CDialog::OnOK();
}

void CMsgDlg::OnCancel() 
{
	CDialog::OnCancel();
}

CString CMsgDlg::GetMessage()
{
	return m_message;
}

BOOL CMsgDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	HICON Hi = AfxGetApp()->LoadIcon(IDI_MAIL);
	SetIcon(Hi,FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
