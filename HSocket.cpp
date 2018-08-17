// HSocket.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteShow.h"
#include "HSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
/////////////////////////////////////////////////////////////////////////////
// CHSocket

CHSocket::CHSocket()
{
	m_pWnd=NULL;
}

CHSocket::~CHSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CHSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CHSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CHSocket member functions

void CHSocket::OnAccept(int nErrorCode) 
{
	if (m_pWnd==NULL) return;
	
	if (nErrorCode == 0) m_pWnd->SendMessage(WM_S_ACCEPT,0,0);

//	CAsyncSocket::OnAccept(nErrorCode);
}

void CHSocket::OnClose(int nErrorCode) 
{
	if (m_pWnd==NULL) return;
    
	if (nErrorCode == 0) m_pWnd->SendMessage(WM_S_CLOSE,0,0);

//	CAsyncSocket::OnClose(nErrorCode);
}

void CHSocket::OnConnect(int nErrorCode) 
{
	if (m_pWnd==NULL) return;
    
	if (0 != nErrorCode)
   {
      switch( nErrorCode )
      {
         case WSAEADDRINUSE: 
            AfxMessageBox("The specified address is already in use.\n");
            break;
         case WSAEADDRNOTAVAIL: 
            AfxMessageBox("The specified address is not available from the local machine.\n");
            break;
         case WSAEAFNOSUPPORT: 
            AfxMessageBox("Addresses in the specified family cannot be\
               used with this socket.\n");
            break;
         case WSAECONNREFUSED: 
            AfxMessageBox("The attempt to connect was forcefull rejected.\n");
            break;
         case WSAEDESTADDRREQ: 
            AfxMessageBox("A destination address is required.\n");
            break;
         case WSAEFAULT: 
            AfxMessageBox("The lpSockAddrLen argument is incorrect.\n");
            break;
         case WSAEINVAL: 
            AfxMessageBox("The socket is already bound to an address.\n");
            break;
         case WSAEISCONN: 
            AfxMessageBox("The socket is already connected.\n");
            break;
         case WSAEMFILE: 
            AfxMessageBox("No more file descriptors are available.\n");
            break;
         case WSAENETUNREACH: 
            AfxMessageBox("The network cannot be reached from this host at this time.\n");
            break;
         case WSAENOBUFS: 
            AfxMessageBox("No buffer space is available. The socket cannot be connected.\n");
            break;
         case WSAENOTCONN: 
            AfxMessageBox("The socket is not connected.\n");
            break;
         case WSAENOTSOCK: 
            AfxMessageBox("The descriptor is a file, not a socket.\n");
            break;
         case WSAETIMEDOUT: 
            AfxMessageBox("The attempt to connect timed out without establishing a connection. \n");
            break;
         default:
            TCHAR szError[256];
            wsprintf(szError, "OnConnect error: %d", nErrorCode);
            AfxMessageBox(szError);
            break;
      }
      AfxMessageBox("Please close the application");
	} else if (nErrorCode == 0)	m_pWnd->SendMessage(WM_S_CONNECT,0,0);

//	CAsyncSocket::OnConnect(nErrorCode);
}

void CHSocket::OnReceive(int nErrorCode) 
{
	if (m_pWnd==NULL) return;
    
	if (nErrorCode == 0)m_pWnd->SendMessage(WM_S_RECEIVE,0,0);

//	CAsyncSocket::OnReceive(nErrorCode);
}

void CHSocket::OnSend(int nErrorCode) 
{
	if (m_pWnd==NULL) return;
    
	if (nErrorCode == 0) m_pWnd->SendMessage(WM_S_SEND,0,0);

//	CAsyncSocket::OnSend(nErrorCode);
}

void CHSocket::SetParent(CDialog *pWnd)
{
	ASSERT(pWnd);
	m_pWnd=pWnd;
}
