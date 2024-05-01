// FamilyPDlg.h : header file
//

#if !defined(AFX_FAMILYPDLG_H__32BF2B97_7FD6_4FCA_8C15_B2020961E4BF__INCLUDED_)
#define AFX_FAMILYPDLG_H__32BF2B97_7FD6_4FCA_8C15_B2020961E4BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFamilyPDlg dialog

class CFamilyPDlg : public CDialog
{
// Construction
public:
	CFamilyPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFamilyPDlg)
	enum { IDD = IDD_FAMILYP_DIALOG };
	int		m_ID;
	CString	m_Password;
	CString	m_Infor;
	CString	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilyPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFamilyPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTps();
	afx_msg void OnDengLu();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAMILYPDLG_H__32BF2B97_7FD6_4FCA_8C15_B2020961E4BF__INCLUDED_)
