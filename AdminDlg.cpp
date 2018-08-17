// AdminDlg.cpp : implementation file
//
#include "stdafx.h"
#include "RemoteShow.h"
#include "AdminDlg.h"
#include "ExitDlg.h"
#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CString g_folderAddress;
/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog


CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdminDlg)
	m_status = _T("");
	m_autoAccept = FALSE;
	m_frameNo = _T("");
	m_currFrame = _T("");
	//}}AFX_DATA_INIT
}


void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdminDlg)
	DDX_Control(pDX, IDC_MOVIE_LIST, m_movieList);
	DDX_Control(pDX, IDC_USERS, m_usersList);
	DDX_Text(pDX, IDC_STATUS, m_status);
	DDX_Check(pDX, IDC_AUTO_ACCEPT, m_autoAccept);
	DDX_Text(pDX, IDC_FRAME_NO, m_frameNo);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH, m_player);
	DDX_Text(pDX, IDC_FRAME_NUMBER, m_currFrame);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialog)
	//{{AFX_MSG_MAP(CAdminDlg)
	ON_BN_CLICKED(IDC_ACCEPT, OnAccept)
	ON_BN_CLICKED(IDC_DENY, OnDeny)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_DC_ALL, OnDcAll)
	ON_BN_CLICKED(IDC_SET_MOVIE, OnSetMovie)
	ON_BN_CLICKED(IDC_FORWARD, OnForward)
	ON_BN_CLICKED(IDC_BACKWARD, OnBackward)
	ON_BN_CLICKED(IDC_FRAME, OnFrame)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_MINIMIZE, OnMinimize)
	ON_BN_CLICKED(IDC_POWER, OnPower)
	ON_BN_CLICKED(IDC_FLASH_SCREEN, OnFlashScreen)
	ON_BN_CLICKED(IDC_SEND_MESSAGE, OnSendMessage)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_GET_MESSAGE, OnGetMessage)
	ON_BN_CLICKED(IDC_AUTO_ACCEPT, OnAutoAccept)
	ON_CBN_SELCHANGE(IDC_MOVIE_LIST, OnSelchangeMovieList)
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_S_ACCEPT,SOnAccept)
	ON_MESSAGE (WM_S_CONNECT,SOnConnect)
	ON_MESSAGE (WM_S_SEND,SOnSend)
	ON_MESSAGE (WM_S_RECEIVE,SOnReceive)
	ON_MESSAGE (WM_S_CLOSE,SOnClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg message handlers

void CAdminDlg::OnAccept()
{
	if (m_thereIsaRequest == FALSE) {
		MessageBox("There is not any request to accept!!");
		return;
	};

	m_thereIsaRequest=FALSE;

	for (int i=0;i<MAX_CLIENTS;i++) {
		if (m_connection[i].index==0) break;
	}

	if (i>=MAX_CLIENTS) {
		MessageBox("Connection Over flow...Acception request denided.");
		return;
	}
	
	m_connection[i].index=1;
	m_listenSocket.Accept((m_connection[i].socket));

	CString name;
	name.Format("%d:NewUser",i);
	m_usersList.AddString(name);

	m_status="Request accepted.Ascking for name...";
	UpdateData(FALSE);
	m_connection[i].socket.Send("NAME",4);
}

void CAdminDlg::OnDeny() 
{
	m_status="Request Rejected...";
	UpdateData(FALSE);
}
void CAdminDlg::OnDisconnect() 
{
}

void CAdminDlg::OnDcAll() 
{
	m_listenSocket.Close();

	for (int i=0;i<MAX_CLIENTS;i++) {
		if (m_connection[i].index!=0)
			m_connection[i].socket.Close();
	}
}

void CAdminDlg::OnSetMovie() 
{
	CString str,name;
	m_movieList.GetWindowText(name);

	if (name=="") return;

	str.Format("SET_MOVIE[%s]",name);
	NetSend(str);
}

void CAdminDlg::OnForward() 
{
	NetSend("FORWARD");
	UpdatePlayer(0);
}

void CAdminDlg::OnBackward() 
{
	NetSend("BACKWARD");
	UpdatePlayer(1);
}

void CAdminDlg::OnFrame() 
{
	UpdateData(TRUE);
	if (m_frameNo=="") return;
	CString str;
	str.Format("GOTO[%d]",atoi(m_frameNo));
	NetSend(str);
	m_player.GotoFrame(atoi(m_frameNo));
}

void CAdminDlg::OnPlay() 
{
	NetSend("PLAY");
	UpdatePlayer(2);
}

void CAdminDlg::OnPause() 
{
	NetSend("PAUSE");
	UpdatePlayer(3);
}

void CAdminDlg::OnMinimize() 
{
	NetSend("MINIMIZE");
}

void CAdminDlg::OnPower() 
{
	CExitDlg dlg;
	if (dlg.DoModal()==IDOK){
		NetSend(dlg.GetAction());
	}
}

void CAdminDlg::OnFlashScreen() 
{
	NetSend("FLASH_SCREEN");
}

void CAdminDlg::OnSendMessage()
{
	CMsgDlg dlg;
	if (dlg.DoModal()!=IDOK) return;
	CString Msg=dlg.GetMessage();
	NetSend("MAIL["+Msg+"]");
}

void CAdminDlg::OnExit() 
{
	NetSend("EXIT");
}

void CAdminDlg::OnGetMessage() 
{
	NetSend("MESSAGE");
}

void CAdminDlg::OnOK()
{
//	CDialog::OnOK();
}

void CAdminDlg::OnCancel() 
{
	m_listenSocket.Close();

	for (int i=0;i<MAX_CLIENTS;i++) {
		if (m_connection[i].index!=0)
			m_connection[i].socket.Close();
	}
	CDialog::OnCancel();
}

BOOL CAdminDlg::Initialize()
{
	for (int i=0;i<MAX_CLIENTS;i++) {
		m_connection[i].index=0;
		m_connection[i].socket.SetParent(this);
	}
	m_socketAddress.m_serverIP="loopback";
	m_socketAddress.m_serverPort=1000;
	m_thereIsaRequest=FALSE;
	m_usersList.AddString("All Users");
	FindMovies();

	return TRUE;		
}

LRESULT CAdminDlg::SOnAccept(WPARAM wParam,LPARAM lParam)
{
	if (m_autoAccept) {
		int i=0;
		while(m_connection[i].index!=0) i+=1;
		
		if (i>=MAX_CLIENTS) {
			MessageBox("Connection Over flow...Acception request denided.");
			return 1;
		}

		m_connection[i].index=1;
		m_listenSocket.Accept((m_connection[i].socket));

		CString name;
		name.Format("%d:NewUser",i);
		m_usersList.AddString(name);

		m_status="Request accepted.Asking for name...";
		m_connection[i].socket.Send("NAME",4);

		UpdateData(FALSE);
		return 0;
	}

	m_status="A user requested to connect...  Please press <Accept> if you let him join your community.";
	UpdateData(FALSE);
	m_thereIsaRequest = TRUE;
	return 0;
}

LRESULT CAdminDlg::SOnClose(WPARAM wParam,LPARAM lParam)
{
	m_status="Closing Connections...";
	UpdateData(FALSE);
	return 0;
}

LRESULT CAdminDlg::SOnSend(WPARAM wParam,LPARAM lParam)
{
	m_status="Sending Data";
	UpdateData(FALSE);
	return 0;
}

LRESULT CAdminDlg::SOnReceive(WPARAM wParam,LPARAM lParam)
{
	m_status="Receiving a message...";
	UpdateData(FALSE);

	char *pBuf = new char[1025];
	int iBufSize = 1024;
	int iRcvd;
	CString strRecvd;

	for (int i=0;i<MAX_CLIENTS;i++) {
		if (m_connection[i].index!=0) {
			iRcvd = m_connection[i].socket.Receive(pBuf, iBufSize);
			if (iRcvd != SOCKET_ERROR) break;
		}
	}
	pBuf[iRcvd] = NULL;
	strRecvd = pBuf;

	if (strRecvd=="BYE") {
		m_connection[i].index=0;
		m_connection[i].socket.Close();
		CString str;
		int res;
		str.Format("%d",i);
		if ((res=m_usersList.FindString(0,str))!=-1)
			m_usersList.DeleteString(res);
		
	} else {
		int index=0;
		if ((index=strRecvd.Find("NAME",0))==-1) {
			MessageBox(strRecvd);
			return 0;
		}

		//else
		strRecvd.Delete(index,4);
		m_status="User:["+strRecvd+"] request accepted.";
		UpdateData(FALSE);
		CString str;
		str.Format("%d:",i);
		index=m_usersList.FindString(0,str);
		if (index==-1) return 0;
		//if(m_usersList.get)
		CString old;
		m_usersList.GetLBText(index,old);
		if (old.Find("NewUser",0)==-1) return 0;
		m_usersList.DeleteString(index);
		m_usersList.InsertString(index,str+strRecvd);
		return 0;
	}

	m_status="Message received successfully.";
	UpdateData(FALSE);
	return 0;
}

LRESULT CAdminDlg::SOnConnect(WPARAM wParam,LPARAM lParam)
{
	m_status="A connection stablished...";
	UpdateData(FALSE);
	return 0;
}

BOOL CAdminDlg::Listen()
{
	m_listenSocket.SetParent(this);
	if ( !(m_listenSocket.Create(m_socketAddress.m_serverPort)) ) return FALSE;
	if ( !(m_listenSocket.Listen()) ) return FALSE;
	m_status="Start Listenning...";
	UpdateData(FALSE);
	return TRUE;
}

BOOL CAdminDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	Initialize();
	if (!Listen()) MessageBox("Error");
	HICON Hi = AfxGetApp()->LoadIcon(IDI_ADMIN);
	SetIcon(Hi,FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdminDlg::BroadCast(CString Message)
{
	for (int i=0;i<MAX_CLIENTS;i++)
		if (m_connection[i].index!=0) 
			m_connection[i].socket.Send(LPCSTR(Message),Message.GetLength());
}

void CAdminDlg::InformUser(CString message,int userID)
{
	if (m_connection[userID].index==0) {
		MessageBox("Not such a user, or user is not active...");
		return;
	}
	m_connection[userID].socket.Send(LPCSTR(message),message.GetLength());
}

void CAdminDlg::NetSend(CString message)
{
	CString str;
	m_usersList.GetWindowText(str);
	if (str=="") {
		MessageBox("Please select a client first.");
		return;
	}

	if (str=="All Users") {
		BroadCast(message);
	} else {
		char idC = str.GetAt(0);
		str=idC;
		int id =(atoi(str));

		InformUser(message,id);
	}
}

void CAdminDlg::OnAutoAccept() 
{
	UpdateData(TRUE);
}

void CAdminDlg::FindMovies()
{
	CFileFind finder;
	
	CString fileName;

	fileName=g_folderAddress+"\\Movies\\*.*";
	//MessageBox(fileName);
	BOOL bWorking = finder.FindFile(fileName);

	CString fName;
	COMBOBOXEXITEM item;
	char buff[80];
	int index=0;

	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		fName=finder.GetFileName();
		fName.TrimLeft();
		fName.TrimRight();

		if (fName!="." || fName!="..") {
			StringToChar((&buff[0]),fName);
			item.mask=CBEIF_TEXT;
			item.iItem=index++;
			item.pszText=buff;
			item.cchTextMax=(fName).GetLength();
			m_movieList.InsertItem(&item);
		}
	}
}

void CAdminDlg::StringToChar(char *buf, CString str)
{
	for (int i=0;i<str.GetLength();i++) {
		buf[i]=str[i];
	}
	buf[i]='\0';
}

void CAdminDlg::OnSelchangeMovieList() 
{
	CString name;
	m_movieList.GetWindowText(name);
	m_player.SetMovie(g_folderAddress+"\\Movies\\"+name);
}

void CAdminDlg::UpdatePlayer(UINT direction)
{
//0:next, 1:back, 2:play, 3:pause, 4:setframe
	switch (direction) {
	case(0): m_player.Forward(); break;
	case(1): m_player.Back(); break;
	case(2): m_player.Play(); break;
	case(3): m_player.Stop(); break;
	}
	m_currFrame.Format("%ld",m_player.GetFrameNum());
	UpdateData(FALSE);
}
