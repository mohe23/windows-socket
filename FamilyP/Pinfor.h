#if !defined(AFX_PINFOR_H__C189B950_5D40_49EE_B2D1_8819E09FC78C__INCLUDED_)
#define AFX_PINFOR_H__C189B950_5D40_49EE_B2D1_8819E09FC78C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Pinfor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPinfor recordset

class CPinfor : public CRecordset
{
public:
	CPinfor(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPinfor)

// Field/Param Data
	//{{AFX_FIELD(CPinfor, CRecordset)
	long	m_ID;
	CString	m_Name;
	CString	m_Sex;
	CString	m_Birth;
	CString	m_Father;
	CString	m_Mother;
	CString	m_Alive;
	CString	m_Bel;
	CString	m_Tip;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPinfor)
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

#endif // !defined(AFX_PINFOR_H__C189B950_5D40_49EE_B2D1_8819E09FC78C__INCLUDED_)
