
// Group9_Mock_PEX.h : main header file for the Group9_Mock_PEX application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// AppClass:
// See Group9_Mock_PEX.cpp for the implementation of this class
//

class AppClass : public CWinApp
{
public:
	AppClass();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern AppClass theApp;
