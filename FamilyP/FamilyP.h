// FamilyP.h : main header file for the FAMILYP application
//

#if !defined(AFX_FAMILYP_H__8569BE6C_53CA_4494_9E57_14EFCEA2EAFB__INCLUDED_)
#define AFX_FAMILYP_H__8569BE6C_53CA_4494_9E57_14EFCEA2EAFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFamilyPApp:
// See FamilyP.cpp for the implementation of this class
//

class CFamilyPApp : public CWinApp
{
public:
	CFamilyPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilyPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFamilyPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAMILYP_H__8569BE6C_53CA_4494_9E57_14EFCEA2EAFB__INCLUDED_)
