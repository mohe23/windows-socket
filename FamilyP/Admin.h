#if !defined(AFX_ADMIN_H__2769ACBB_CD3D_4BCC_902F_B55970E2F5D4__INCLUDED_)
#define AFX_ADMIN_H__2769ACBB_CD3D_4BCC_902F_B55970E2F5D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Admin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdmin dialog

class CAdmin : public CDialog
{
// Construction
public:
	CAdmin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdmin)
	enum { IDD = IDD_DIALOG1 };
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
	//{{AFX_VIRTUAL(CAdmin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdmin)
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnChange();
	afx_msg void OnShow();
	afx_msg void OnChangePassW();
	afx_msg void OnList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMIN_H__2769ACBB_CD3D_4BCC_902F_B55970E2F5D4__INCLUDED_)
