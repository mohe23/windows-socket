// Pinfor.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "Pinfor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPinfor

IMPLEMENT_DYNAMIC(CPinfor, CRecordset)

CPinfor::CPinfor(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPinfor)
	m_ID = 0;
	m_Name = _T("");
	m_Sex = _T("");
	m_Birth = _T("");
	m_Father = _T("");
	m_Mother = _T("");
	m_Alive = _T("");
	m_Bel = _T("");
	m_Tip = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPinfor::GetDefaultConnect()
{
	return _T("ODBC;DSN=PFamily");
}

CString CPinfor::GetDefaultSQL()
{
	return _T("[dbo].[Re]");
}

void CPinfor::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPinfor)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[Sex]"), m_Sex);
	RFX_Text(pFX, _T("[Birth]"), m_Birth);
	RFX_Text(pFX, _T("[Father]"), m_Father);
	RFX_Text(pFX, _T("[Mother]"), m_Mother);
	RFX_Text(pFX, _T("[Alive]"), m_Alive);
	RFX_Text(pFX, _T("[Bel]"), m_Bel);
	RFX_Text(pFX, _T("[Tip]"), m_Tip);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPinfor diagnostics

#ifdef _DEBUG
void CPinfor::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPinfor::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
