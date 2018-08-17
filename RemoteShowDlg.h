// RemoteShowDlg.h : header file
//

#if !defined(AFX_REMOTESHOWDLG_H__C6E1A1D6_29B8_4B9D_BCDC_BE68A927FB4A__INCLUDED_)
#define AFX_REMOTESHOWDLG_H__C6E1A1D6_29B8_4B9D_BCDC_BE68A927FB4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CRemoteShowDlg dialog

class CRemoteShowDlg : public CDialog
{
// Construction
public:
	CRemoteShowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRemoteShowDlg)
	enum { IDD = IDD_REMOTESHOW_DIALOG };
	CString	m_pass;
	CString	m_status;
	BOOL	m_toggle;
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemoteShowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRemoteShowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTogglePass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTESHOWDLG_H__C6E1A1D6_29B8_4B9D_BCDC_BE68A927FB4A__INCLUDED_)
