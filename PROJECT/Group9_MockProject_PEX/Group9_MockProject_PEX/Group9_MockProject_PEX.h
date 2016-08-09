
// Group9_MockProject_PEX.h : main header file for the Group9_MockProject_PEX application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGroup9_MockProject_PEXApp:
// See Group9_MockProject_PEX.cpp for the implementation of this class
//

class CGroup9_MockProject_PEXApp : public CWinApp
{
public:
	CGroup9_MockProject_PEXApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGroup9_MockProject_PEXApp theApp;
