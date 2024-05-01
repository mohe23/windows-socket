#if !defined(AFX_TABLEID_H__F096063F_88F1_44B6_8C42_3DB506B0D0BA__INCLUDED_)
#define AFX_TABLEID_H__F096063F_88F1_44B6_8C42_3DB506B0D0BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TableID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTableID recordset

class CTableID : public CRecordset
{
public:
	CTableID(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTableID)

// Field/Param Data
	//{{AFX_FIELD(CTableID, CRecordset)
	long	m_ID;
	CString	m_Password;
	int		m_Label;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTableID)
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

#endif // !defined(AFX_TABLEID_H__F096063F_88F1_44B6_8C42_3DB506B0D0BA__INCLUDED_)
