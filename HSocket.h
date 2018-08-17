#if !defined(AFX_HSOCKET_H__F5F1FC5F_E973_4F77_838F_0AF04D87071C__INCLUDED_)
#define AFX_HSOCKET_H__F5F1FC5F_E973_4F77_838F_0AF04D87071C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CHSocket command target

class CHSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CHSocket();
	virtual ~CHSocket();

// Overrides
public:
	void SetParent(CDialog* pWnd);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CHSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
	CDialog* m_pWnd;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HSOCKET_H__F5F1FC5F_E973_4F77_838F_0AF04D87071C__INCLUDED_)
