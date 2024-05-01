// Rede.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "Rede.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRede

IMPLEMENT_DYNAMIC(CRede, CRecordset)

CRede::CRede(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRede)
	m_IDd = 0;
	m_Named = _T("");
	m_Sexd = _T("");
	m_Birthd = _T("");
	m_Fatherd = _T("");
	m_Motherd = _T("");
	m_Beld = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRede::GetDefaultConnect()
{
	return _T("ODBC;DSN=PFamily");
}

CString CRede::GetDefaultSQL()
{
	return _T("[dbo].[DeRe]");
}

void CRede::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRede)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[IDd]"), m_IDd);
	RFX_Text(pFX, _T("[Named]"), m_Named);
	RFX_Text(pFX, _T("[Sexd]"), m_Sexd);
	RFX_Text(pFX, _T("[Birthd]"), m_Birthd);
	RFX_Text(pFX, _T("[Fatherd]"), m_Fatherd);
	RFX_Text(pFX, _T("[Motherd]"), m_Motherd);
	RFX_Text(pFX, _T("[Beld]"), m_Beld);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRede diagnostics

#ifdef _DEBUG
void CRede::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRede::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
