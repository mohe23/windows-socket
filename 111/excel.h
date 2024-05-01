#if !defined(AFX_EXCEL_H__42223E50_808D_4AF6_A250_4B692D6FF551__INCLUDED_)
#define AFX_EXCEL_H__42223E50_808D_4AF6_A250_4B692D6FF551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// excel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cexcel dialog

class Cexcel : public CDialog
{
// Construction
public:
	Cexcel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cexcel)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cexcel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cexcel)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXCEL_H__42223E50_808D_4AF6_A250_4B692D6FF551__INCLUDED_)
