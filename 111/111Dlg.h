// 111Dlg.h : header file
//

#if !defined(AFX_111DLG_H__5FA57163_EF8E_496E_9530_302EF0DBEAC8__INCLUDED_)
#define AFX_111DLG_H__5FA57163_EF8E_496E_9530_302EF0DBEAC8__INCLUDED_

#include "RecSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy111Dlg dialog

class CMy111Dlg : public CDialog
{
// Construction
public:
	CRecSet m_setRec;
	CMy111Dlg(CWnd* pParent = NULL);	// standard constructor
    void ShowVal();//按照教程添加的函数。
// Dialog Data
	//{{AFX_DATA(CMy111Dlg)
	enum { IDD = IDD_MY111_DIALOG };
	CString	m_te;
	CString	m_pa;
	CString	m_rpa;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy111Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy111Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnLogs();
	afx_msg void OnAdd();
	afx_msg void OnShowall();
	afx_msg void OnRepair();
	afx_msg void OnRequest();
	afx_msg void OnDelete();
	afx_msg void OnButton6();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_111DLG_H__5FA57163_EF8E_496E_9530_302EF0DBEAC8__INCLUDED_)
