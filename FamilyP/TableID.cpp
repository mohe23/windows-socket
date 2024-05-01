// TableID.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "TableID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTableID

IMPLEMENT_DYNAMIC(CTableID, CRecordset)

CTableID::CTableID(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTableID)
	m_ID = 0;
	m_Password = _T("");
	m_Label = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTableID::GetDefaultConnect()
{
	return _T("ODBC;DSN=PFamily");
}

CString CTableID::GetDefaultSQL()
{
	return _T("[dbo].[Tid]");
}

void CTableID::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTableID)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Password]"), m_Password);
	RFX_Int(pFX, _T("[Label]"), m_Label);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTableID diagnostics

#ifdef _DEBUG
void CTableID::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTableID::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
