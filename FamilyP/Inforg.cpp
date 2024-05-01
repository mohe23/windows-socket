// Inforg.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "Inforg.h"
#include "Pinfor.h"
#include "Rede.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInforg dialog


CInforg::CInforg(CWnd* pParent /*=NULL*/)
	: CDialog(CInforg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInforg)
	m_Count = 0;
	//}}AFX_DATA_INIT
}


void CInforg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInforg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_Count);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInforg, CDialog)
	//{{AFX_MSG_MAP(CInforg)
	ON_BN_CLICKED(IDC_BUTTON1, OnShowall)
	ON_BN_CLICKED(IDC_BUTTON2, OnDeShow)
	//ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInforg message handlers

void  CInforg::SetLine()  //列表添加网格线。
{
                    m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);  //添加网格线和整行选中属性。
		//m_List.DeleteAllItems();  //清除列表所有内容
                    m_List.InsertColumn(0,_T("ID"),LVCFMT_CENTER);
	                m_List.InsertColumn(1,_T("姓名"),LVCFMT_CENTER);
	                m_List.InsertColumn(2,_T("性别"),LVCFMT_CENTER);
	                m_List.InsertColumn(3,_T("出生日期"),LVCFMT_CENTER);
                 	m_List.InsertColumn(4,_T("父名"),LVCFMT_CENTER);
	                m_List.InsertColumn(5,_T("母名"),LVCFMT_CENTER);
	                m_List.InsertColumn(7,_T("是否在世"),LVCFMT_CENTER);
	                m_List.InsertColumn(6,_T("是否本家"),LVCFMT_CENTER);
	                m_List.InsertColumn(8,_T("备注"),LVCFMT_CENTER);
    
	                 m_List.SetColumnWidth(0,80);  //设置列宽。
                     m_List.SetColumnWidth(1,70);  
	                 m_List.SetColumnWidth(2,50);
	                 m_List.SetColumnWidth(3,100);
	                 m_List.SetColumnWidth(4,70);
	                 m_List.SetColumnWidth(5,70);
	                 m_List.SetColumnWidth(6,80);
	                 m_List.SetColumnWidth(7,80);
                     m_List.SetColumnWidth(8,80);               
}	


void CInforg::OnShowall() 
{
	// TODO: Add your control notification handler code here
    if(0==m_Count) //只有第1次点击按钮时，才画网格线，再次点击，不会出现网格线。
		SetLine();  

	CPinfor c1;
	CString s1;
	int r=0;
	m_List.DeleteAllItems();  //这个是删除除表头之外的所有内容。这个是防止重复点击时造成信息混乱。

	c1.Open();//打开数据库。
	while(!c1.IsEOF()){
	   s1.Format("%d",c1.m_ID);
	   //s2.Format("%d",c1.m_Password);
       m_List.InsertItem(r,s1);//创建1行，将s1写入第1列。
	   m_List.SetItemText(r,1,c1.m_Name);//这个函数需要3个参数。将s2写入第2列。
	   m_List.SetItemText(r,2,c1.m_Sex);
	   m_List.SetItemText(r,3,c1.m_Birth);
	   m_List.SetItemText(r,4,c1.m_Father);
	   m_List.SetItemText(r,5,c1.m_Mother);
	   m_List.SetItemText(r,7,c1.m_Alive);
	   m_List.SetItemText(r,6,c1.m_Bel);
	   m_List.SetItemText(r,8,c1.m_Tip);

	   c1.MoveNext();//将指针指向下一条记录。
	   r++;
	}
	c1.Close();
	m_Count++;  //将m_Count的值加1，防止再次调用设置网格线函数。
	UpdateData(false);  //将编辑框关联的变量的值显示出来。
}

void CInforg::OnDeShow() 
{
	// TODO: Add your control notification handler code here
		//m_List.DeleteAllItems();  //清除列表所有内容
//	m_List.DeleteItem(0);
	if(0==m_Count) //只有第1次点击按钮时，才画网格线，再次点击，不会出现网格线。
		SetLine();  

	CRede c1;
	CString s1;
	int r=0;
	m_List.DeleteAllItems();  //这个是删除除表头之外的所有内容。这个是防止重复点击时造成信息混乱。

	c1.Open();//打开数据库。
	while(!c1.IsEOF()){
	   s1.Format("%d",c1.m_IDd);
	   //s2.Format("%d",c1.m_Password);
       m_List.InsertItem(r,s1);//创建1行，将s1写入第1列。
	   m_List.SetItemText(r,1,c1.m_Named);//这个函数需要3个参数。将s2写入第2列。
	   m_List.SetItemText(r,2,c1.m_Sexd);
	   m_List.SetItemText(r,3,c1.m_Birthd);
	   m_List.SetItemText(r,4,c1.m_Fatherd);
	   m_List.SetItemText(r,5,c1.m_Motherd);
	   m_List.SetItemText(r,6,c1.m_Beld);

	   c1.MoveNext();//将指针指向下一条记录。
	   r++;
	}
	c1.Close();
	 m_Count++;
		UpdateData(false);  //将编辑框关联的变量的值显示出来。
}

