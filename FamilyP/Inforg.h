#if !defined(AFX_INFORG_H__354C984B_1E5C_4E2F_B1D4_6B29432BA6DA__INCLUDED_)
#define AFX_INFORG_H__354C984B_1E5C_4E2F_B1D4_6B29432BA6DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Inforg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInforg dialog

class CInforg : public CDialog
{
// Construction
public:
	CInforg(CWnd* pParent = NULL);   // standard constructor
    void SetLine();  //设置列表的表格线。
// Dialog Data
	//{{AFX_DATA(CInforg)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_List;
	int		m_Count;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInforg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInforg)
	afx_msg void OnShowall();
	afx_msg void OnDeShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORG_H__354C984B_1E5C_4E2F_B1D4_6B29432BA6DA__INCLUDED_)
