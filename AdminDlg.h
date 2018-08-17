//{{AFX_INCLUDES()
#include "shockwaveflash.h"
//}}AFX_INCLUDES
#if !defined(AFX_ADMINDLG_H__3DEBB95B_FE0B_4089_BD17_5F432329647B__INCLUDED_)
#define AFX_ADMINDLG_H__3DEBB95B_FE0B_4089_BD17_5F432329647B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdminDlg.h : header file
//
#include "HSocket.h"

#ifndef WM_S_ACCEPT
#define WM_S_ACCEPT		WM_USER+5
#endif
#ifndef WM_S_CLOSE
#define WM_S_CLOSE		WM_USER+6
#endif
#ifndef WM_S_SEND
#define WM_S_SEND		WM_USER+7
#endif
#ifndef WM_S_RECEIVE
#define WM_S_RECEIVE	WM_USER+8
#endif
#ifndef WM_S_CONNECT
#define WM_S_CONNECT	WM_USER+9
#endif

#define MAX_CLIENTS	15
/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog

class CAdminDlg : public CDialog
{
// Construction
public:
	CAdminDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdminDlg)
	enum { IDD = IDD_ADMIN_DLG };
	CComboBoxEx	m_movieList;
	CComboBox	m_usersList;
	CString	m_status;
	BOOL	m_autoAccept;
	CString	m_frameNo;
	CShockwaveFlash	m_player;
	CString	m_currFrame;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdminDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdminDlg)
	afx_msg void OnAccept();
	afx_msg void OnDeny();
	afx_msg void OnDisconnect();
	afx_msg void OnDcAll();
	afx_msg void OnSetMovie();
	afx_msg void OnForward();
	afx_msg void OnBackward();
	afx_msg void OnFrame();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	afx_msg void OnMinimize();
	afx_msg void OnPower();
	afx_msg void OnFlashScreen();
	afx_msg void OnSendMessage();
	afx_msg void OnExit();
	afx_msg void OnGetMessage();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnAutoAccept();
	afx_msg void OnSelchangeMovieList();
	//}}AFX_MSG
	afx_msg LRESULT SOnAccept(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnClose(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnSend(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnReceive(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnConnect(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	void UpdatePlayer(UINT direction);
	void StringToChar(char *buf, CString str);
	void FindMovies();
	void NetSend(CString message);
	void InformUser(CString message,int userID);
	void BroadCast(CString Message);
//	BOOL m_autoAccept;
	BOOL Listen();
	BOOL Initialize();
	CHSocket m_listenSocket;

	typedef struct _connection {
		CHSocket	socket;
		int			index;
	} connection;
	
	typedef struct _socketAddress {
		int m_serverPort;
		CString m_serverIP;
	} HSocketAddress;

	HSocketAddress  m_socketAddress;
	connection m_connection[MAX_CLIENTS];
	BOOL	m_thereIsaRequest;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINDLG_H__3DEBB95B_FE0B_4089_BD17_5F432329647B__INCLUDED_)
