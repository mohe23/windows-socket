#if !defined(AFX_USER_H__28E7259C_40AD_417E_BB1B_4E80FCDDE4E0__INCLUDED_)
#define AFX_USER_H__28E7259C_40AD_417E_BB1B_4E80FCDDE4E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// User.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUser dialog

class CUser : public CDialog
{
// Construction
public:
	CUser(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUser)
	enum { IDD = IDD_DIALOG2 };
	CString	m_Name;
	CString	m_Sex;
	CString	m_Birth;
	CString	m_Fname;
	CString	m_Mname;
	CString	m_Alive;
	CString	m_Belong;
	CString	m_Tips;
	int		m_ID;
	CString	m_Password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUser)
	afx_msg void OnChangeP();
	afx_msg void OnShowinfor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USER_H__28E7259C_40AD_417E_BB1B_4E80FCDDE4E0__INCLUDED_)
