//{{AFX_INCLUDES()
#include "shockwaveflash.h"
//}}AFX_INCLUDES
#if !defined(AFX_CLIENTDLG_H__C0B72D3C_D52F_41BA_B98A_EE5B8B20D8EB__INCLUDED_)
#define AFX_CLIENTDLG_H__C0B72D3C_D52F_41BA_B98A_EE5B8B20D8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientDlg.h : header file
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
// CClientDlg dialog

class CClientDlg : public CDialog
{
// Construction
public:
	void SetName(CString name);
	void SetSocketAddress(CString address);
	CClientDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT };
	CStatic	m_img;
	CShockwaveFlash	m_player;
	CString	m_stat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	afx_msg LRESULT SOnAccept(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnClose(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnSend(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnReceive(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT SOnConnect(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	UINT flasher;
	void ShutDown(unsigned int type);
	CHSocket	m_connect;
	CString		m_hostName,
				m_myName;
	UINT		m_hostPort;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__C0B72D3C_D52F_41BA_B98A_EE5B8B20D8EB__INCLUDED_)
