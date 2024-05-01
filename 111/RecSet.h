#if !defined(AFX_RECSET_H__F2D123AE_74E1_4EE5_B5DF_D98E6600BE94__INCLUDED_)
#define AFX_RECSET_H__F2D123AE_74E1_4EE5_B5DF_D98E6600BE94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecSet recordset

class CRecSet : public CRecordset
{
public:
	CRecSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRecSet)

// Field/Param Data
	//{{AFX_FIELD(CRecSet, CRecordset)
	long	m_Name;
	long	m_Password;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecSet)
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

#endif // !defined(AFX_RECSET_H__F2D123AE_74E1_4EE5_B5DF_D98E6600BE94__INCLUDED_)
