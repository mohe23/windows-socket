#if !defined(AFX_REDE_H__3BF1D0BE_4A99_4231_A3A4_BC62188F8ABB__INCLUDED_)
#define AFX_REDE_H__3BF1D0BE_4A99_4231_A3A4_BC62188F8ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rede.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRede recordset

class CRede : public CRecordset
{
public:
	CRede(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRede)

// Field/Param Data
	//{{AFX_FIELD(CRede, CRecordset)
	long	m_IDd;
	CString	m_Named;
	CString	m_Sexd;
	CString	m_Birthd;
	CString	m_Fatherd;
	CString	m_Motherd;
	CString	m_Beld;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRede)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDE_H__3BF1D0BE_4A99_4231_A3A4_BC62188F8ABB__INCLUDED_)
