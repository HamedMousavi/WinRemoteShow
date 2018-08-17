// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "ClientDlg.h"
#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define DEFULT_HOST_PORT 1000;
extern CString g_folderAddress;
/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog


CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_stat = _T("");
	//}}AFX_DATA_INIT
}


void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_IMG, m_img);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH, m_player);
	DDX_Text(pDX, IDC_STATUS, m_stat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_S_ACCEPT,SOnAccept)
	ON_MESSAGE (WM_S_CONNECT,SOnConnect)
	ON_MESSAGE (WM_S_SEND,SOnSend)
	ON_MESSAGE (WM_S_RECEIVE,SOnReceive)
	ON_MESSAGE (WM_S_CLOSE,SOnClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

void CClientDlg::OnOK() 
{
//	CDialog::OnOK();
}

void CClientDlg::OnCancel() 
{
	UINT iLen=0,iSent=0;
	CString message="BYE";
	iLen = message.GetLength();
	iSent = m_connect.Send(LPCTSTR(message), iLen);
	m_connect.Close();
	CDialog::OnCancel();
}

BOOL CClientDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetWindowText("RemoteShow - Client [Hello!]");
	HICON Hi = AfxGetApp()->LoadIcon(IDI_MFC);
	SetIcon(Hi,FALSE);
	
	ShowWindow(SW_MAXIMIZE);

	CRect r;
	GetClientRect(r);

	m_player.SetWindowPos(0,r.left,r.top,r.right,r.bottom-30,0);
	(GetDlgItem(IDCANCEL))->SetWindowPos(0,r.right-50,r.bottom-29,50,30,0);
	GetDlgItem(IDC_STATUS)->SetWindowPos(0,r.left+50,r.bottom-20,400,30,0);
	GetDlgItem(IDC_IMG)->SetWindowPos(0,r.left+10,r.bottom-30,-1,-1,SWP_NOSIZE);
//	m_hostPort=DEFULT_HOST_PORT;
//	m_myName="NONE";
	m_connect.SetParent(this);
	flasher=0;

	if ( !(m_connect.Create()) ) {
		//Prompt("Faild to connect,due to Creation problem.");
		return FALSE;
	}
	if ( !(m_connect.Connect(m_hostName,m_hostPort)) ) {
		return FALSE;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

LRESULT CClientDlg::SOnAccept(WPARAM wParam,LPARAM lParam)
{
	return 0;
}

LRESULT CClientDlg::SOnClose(WPARAM wParam,LPARAM lParam)
{
	AfxMessageBox("Disconnected :((");
	return 0;
}

LRESULT CClientDlg::SOnSend(WPARAM wParam,LPARAM lParam)
{
	return 0;
}

LRESULT CClientDlg::SOnConnect(WPARAM wParam,LPARAM lParam)
{
	return 0;
}

LRESULT CClientDlg::SOnReceive(WPARAM wParam,LPARAM lParam)
{
	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	CString strRecvd;

	iRcvd = m_connect.Receive(pBuf, iBufSize);

	pBuf[iRcvd] = NULL;
	strRecvd = pBuf;

	//MessageBox(strRecvd);
	if (strRecvd == "PLAY" ) {
		m_player.Play();
	} else if (strRecvd == "FORWARD" ) {
		m_player.Forward();
	} else if (strRecvd == "BACKWARD" ) {
		m_player.Back();
	} else if (strRecvd == "PAUSE" ) {
		m_player.Stop();
	} else if (strRecvd == "MINIMIZE" ) {
		CloseWindow();
	} else if (strRecvd == "FLASH_SCREEN" ) {
		SetTimer(0,500,0);
	} else if (strRecvd == "EXIT" ) {
		OnCancel();
	} else if (strRecvd == "LOG_OFF" ) {
		ShutDown(EWX_LOGOFF);
	} else if (strRecvd == "POWER_OFF" ) {
		ShutDown(EWX_POWEROFF);
	} else if (strRecvd == "RESTART" ) {
		ShutDown(EWX_REBOOT);
	} else if (strRecvd == "SHUT_DOWN" ) {
		ShutDown(EWX_SHUTDOWN);
	} else if (strRecvd == "NAME" ) {
		m_connect.Send("NAME"+m_myName,m_myName.GetLength()+4);
		m_stat="Welcome "+m_myName+". Please wait for Server to join you to Linux community!";
		UpdateData(FALSE);
	} else if (strRecvd == "MESSAGE" ) {
		CMsgDlg dlg;
		if (dlg.DoModal()==IDOK) {
			m_connect.Send(dlg.GetMessage(),dlg.GetMessage().GetLength());
		}
	} else {
		if (strRecvd.Find("SET_MOVIE",0)!=-1) {
			//"SET_MOVIE[%s]"
			int index=strRecvd.Find("[",0);
			strRecvd.Delete(0,index+1);
			strRecvd.Delete(strRecvd.GetLength()-1,1);
			m_player.SetMovie(g_folderAddress+"\\Movies\\"+strRecvd);

			m_stat="Welcome to Linux community "+m_myName+".";
			UpdateData(FALSE);
			HICON Hi = AfxGetApp()->LoadIcon(IDI_MSG);
			m_img.SetIcon(Hi);

		} else if (strRecvd.Find("GOTO",0)!=-1) {
			int index=strRecvd.Find("[",0);
			strRecvd.Delete(0,index+1);
			strRecvd.Delete(strRecvd.GetLength()-1,1);
			int frameNo=atoi(strRecvd);
			m_player.GotoFrame(frameNo);
		} else if (strRecvd.Find("MAIL",0)!=-1) {
			int index=strRecvd.Find("[",0);
			strRecvd.Delete(0,index+1);
			strRecvd.Delete(strRecvd.GetLength()-1,1);
			AfxMessageBox(strRecvd);
		}
	}
	return 1;
}

void CClientDlg::SetSocketAddress(CString address)
{
	int index=address.Find("-",0);
	if (index== -1) {
		m_hostPort=1000;
		m_hostName="loopback";
		return;
	}
	m_hostName=address.Left(index);
	address.Delete(0,index+1);
	m_hostPort=atoi(address);
}

void CClientDlg::ShutDown(unsigned int type)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp; 
 
	// Get a token for this process. 
 
	if (!OpenProcessToken(GetCurrentProcess(), 
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
			MessageBox("Error:OpenProcessToken");
			return;
	}
 
	// Get the LUID for the shutdown privilege. 
 
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
			&tkp.Privileges[0].Luid); 
 
	tkp.PrivilegeCount = 1;  // one privilege to set    
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 
	// Get the shutdown privilege for this process. 
 
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
			(PTOKEN_PRIVILEGES)NULL, 0); 
 
	// Cannot test the return value of AdjustTokenPrivileges. 
 
	if (GetLastError() != ERROR_SUCCESS) {
			MessageBox("Error:AdjustTokenPrivileges");
			return;
	}
 
	// Shut down the system and force all applications to close. 
 
	if (!ExitWindowsEx(type | EWX_FORCE, 0)) {
			MessageBox("Error:ExitWindowsEx");
			return;
	}
}

void CClientDlg::SetName(CString name)
{
	m_myName=name;
}

void CClientDlg::OnTimer(UINT nIDEvent) 
{
	FlashWindow(TRUE);
	flasher++;
	if (flasher==10) {
		KillTimer(0);
		FlashWindow(FALSE);
		flasher=0;
	}
	CDialog::OnTimer(nIDEvent);
}
