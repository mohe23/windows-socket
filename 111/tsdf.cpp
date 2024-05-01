// tsdf.cpp : implementation file
//

#include "stdafx.h"
#include "111.h"
#include "tsdf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ctsdf dialog


Ctsdf::Ctsdf(CWnd* pParent /*=NULL*/)
	: CDialog(Ctsdf::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ctsdf)
	m_name = _T("");
	m_pass = _T("");
	//}}AFX_DATA_INIT
}


void Ctsdf::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ctsdf)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ctsdf, CDialog)
	//{{AFX_MSG_MAP(Ctsdf)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ctsdf message handlers

void Ctsdf::OnButton1() 
{
	// TODO: Add your control notification handler code here
//	UpdateData(false);
}
