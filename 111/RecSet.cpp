// RecSet.cpp : implementation file
//

#include "stdafx.h"
#include "111.h"
#include "RecSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecSet

IMPLEMENT_DYNAMIC(CRecSet, CRecordset)

CRecSet::CRecSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRecSet)
	m_Name = 0;
	m_Password = 0;
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRecSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=ODBCDSN");
}

CString CRecSet::GetDefaultSQL()
{
	return _T("[dbo].[logs]");
}

void CRecSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRecSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Name]"), m_Name);
	RFX_Long(pFX, _T("[Password]"), m_Password);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRecSet diagnostics

#ifdef _DEBUG
void CRecSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRecSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
