#if !defined(AFX_EXITDLG_H__FC03A7A2_4D10_4625_9003_2CF08D25DBD4__INCLUDED_)
#define AFX_EXITDLG_H__FC03A7A2_4D10_4625_9003_2CF08D25DBD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExitDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExitDlg dialog

class CExitDlg : public CDialog
{
// Construction
public:
	CString GetAction();
	CExitDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExitDlg)
	enum { IDD = IDD_EXIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExitDlg)
	afx_msg void OnAction();
	virtual void OnCancel();
	afx_msg void OnLogoff();
	afx_msg void OnPoweroff();
	afx_msg void OnRestart();
	afx_msg void OnShutdown();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_act;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXITDLG_H__FC03A7A2_4D10_4625_9003_2CF08D25DBD4__INCLUDED_)
