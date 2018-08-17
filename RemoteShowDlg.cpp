// RemoteShowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "RemoteShowDlg.h"
#include "Admindlg.h"
#include "clientdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CString g_folderAddress;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemoteShowDlg dialog

CRemoteShowDlg::CRemoteShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemoteShowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemoteShowDlg)
	m_pass = _T("");
	m_status = _T("");
	m_toggle = FALSE;
	m_name = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAIN);
}

void CRemoteShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemoteShowDlg)
	DDX_Text(pDX, IDC_PASS, m_pass);
	DDX_Text(pDX, IDC_STATUS, m_status);
	DDX_Check(pDX, IDC_TOGGLE_PASS, m_toggle);
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRemoteShowDlg, CDialog)
	//{{AFX_MSG_MAP(CRemoteShowDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TOGGLE_PASS, OnTogglePass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemoteShowDlg message handlers

BOOL CRemoteShowDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString fileName,s;
	
	GetModuleFileName(NULL,s.GetBuffer(512),512);
	s.ReleaseBuffer();
	//remove executable file name
	s.Delete(s.ReverseFind('\\'),s.GetLength()-s.ReverseFind('\\'));
	fileName=s;

	g_folderAddress=fileName;
	m_toggle=TRUE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemoteShowDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CRemoteShowDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRemoteShowDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CRemoteShowDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRemoteShowDlg::OnOK() 
{
	UpdateData(TRUE);
	if (m_name=="") {
		m_status="You must first enter a Name ;)";
		UpdateData(FALSE);
		return;
	}
	if (m_pass=="") {
		m_status="After a name, you have to enter a password ;)";
		UpdateData(FALSE);
		return;
	}
	if (m_name=="root" && m_pass=="hamedlinux") {
		SetWindowPos(0,0,0,0,0,0);
		CAdminDlg	dlg;
		dlg.DoModal();
	}
	else {
		if (m_pass.GetLength()<5) {
			m_status="Hey! Password must be at least 5 characters.";
			UpdateData(FALSE);
			return;
		}
		SetWindowPos(0,0,0,0,0,0);
		CClientDlg dlg;
		dlg.SetSocketAddress(m_pass);
		dlg.SetName(m_name);
		dlg.DoModal();
	}

	CDialog::OnOK();
}

void CRemoteShowDlg::OnTogglePass() 
{
	UpdateData(TRUE);
	CEdit* ed = (CEdit*) GetDlgItem(IDC_PASS);
	if (m_toggle) ed->SetPasswordChar('*');
	else ed->SetPasswordChar(0);
	ed->Invalidate();
	UpdateData(FALSE);
}
