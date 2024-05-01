// excel.cpp : implementation file
//

#include "stdafx.h"
#include "111.h"
#include "excel.h"
#include"RecSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cexcel dialog


Cexcel::Cexcel(CWnd* pParent /*=NULL*/)
	: CDialog(Cexcel::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cexcel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cexcel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cexcel)
	DDX_Control(pDX, IDC_LIST4, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cexcel, CDialog)
	//{{AFX_MSG_MAP(Cexcel)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cexcel message handlers

    
void Cexcel::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//添加网格线和整行选中属性。
	m_List.InsertColumn(0,_T("用户名"),LVCFMT_CENTER);//初始化表头。
	m_List.InsertColumn(1,_T("密码"),LVCFMT_CENTER);
	/*m_List.InsertColumn(2,_T("时间"),LVCFMT_CENTER);
	m_List.InsertColumn(3,_T("温度（℃）"),LVCFMT_CENTER);
	m_List.InsertColumn(4,_T("湿度（%RH）"),LVCFMT_CENTER);
	m_List.InsertColumn(5,_T("光照强度（lx）"),LVCFMT_CENTER);
	m_List.InsertColumn(6,_T("CO2浓度（ppm）"),LVCFMT_CENTER);
	m_List.InsertColumn(7,_T("备注"),LVCFMT_CENTER);*/

	m_List.SetColumnWidth(0,150);//设置列宽
	m_List.SetColumnWidth(1,160);

    CRecSet  c1;
	CString s1,s2;
	int r=0;
	c1.Open();//打开数据库。
	while(!c1.IsEOF()){
	   s1.Format("%d",c1.m_Name);
	   s2.Format("%d",c1.m_Password);
       m_List.InsertItem(r,s1);//创建1行，将s1写入第1列。
	   m_List.SetItemText(r,1,s2);//这个函数需要3个参数。将s2写入第2列。
	   c1.MoveNext();//将指针指向下一条记录。
	   r++;
	}
	c1.Close();
/*	m_List.SetColumnWidth(2,80);
	m_List.SetColumnWidth(3,75);
	m_List.SetColumnWidth(4,80);
	m_List.SetColumnWidth(5,85);
	m_List.SetColumnWidth(6,85);
	m_List.SetColumnWidth(7,80);
	

    m_List.InsertItem(0,"32");//创建1行，并将“32”写入第1列。
	m_List.SetItemText(0,1,"23");//将数据写入第2列。
	m_List.SetItemText(0,2,"24");
	m_List.SetItemText(0,3,"25");
	m_List.SetItemText(0,4,"26");
	m_List.SetItemText(0,5,"27");
    m_List.SetItemText(0,6,"28");
	m_List.SetItemText(0,7,"29");

	m_List.InsertItem(1,"32");
	m_List.SetItemText(1,1,"23");
	m_List.SetItemText(1,2,"24");
	m_List.SetItemText(1,3,"25");
	m_List.SetItemText(1,4,"26");
	m_List.SetItemText(1,5,"27");
    m_List.SetItemText(1,6,"28");
	m_List.SetItemText(1,7,"29");*/

    
}
