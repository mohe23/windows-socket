#if !defined(AFX_TSDF_H__E1FB5CAE_3010_4F9F_99A3_AFD75F537533__INCLUDED_)
#define AFX_TSDF_H__E1FB5CAE_3010_4F9F_99A3_AFD75F537533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tsdf.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ctsdf dialog

class Ctsdf : public CDialog
{
// Construction
public:
	Ctsdf(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ctsdf)
	enum { IDD = IDD_DIALOG2 };
	CString	m_name;
	CString	m_pass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ctsdf)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ctsdf)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TSDF_H__E1FB5CAE_3010_4F9F_99A3_AFD75F537533__INCLUDED_)
