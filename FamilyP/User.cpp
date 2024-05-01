// User.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "User.h"
#include "TableID.h"
#include "Pinfor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUser dialog


CUser::CUser(CWnd* pParent /*=NULL*/)
	: CDialog(CUser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUser)
	m_Name = _T("");
	m_Sex = _T("");
	m_Birth = _T("");
	m_Fname = _T("");
	m_Mname = _T("");
	m_Alive = _T("");
	m_Belong = _T("");
	m_Tips = _T("");
	m_ID = 0;
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void CUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUser)
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Sex);
	DDX_Text(pDX, IDC_EDIT3, m_Birth);
	DDX_Text(pDX, IDC_EDIT4, m_Fname);
	DDX_Text(pDX, IDC_EDIT5, m_Mname);
	DDX_Text(pDX, IDC_EDIT6, m_Alive);
	DDX_Text(pDX, IDC_EDIT7, m_Belong);
	DDX_Text(pDX, IDC_EDIT8, m_Tips);
	DDX_Text(pDX, IDC_EDIT10, m_ID);
	DDX_Text(pDX, IDC_EDIT9, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUser, CDialog)
	//{{AFX_MSG_MAP(CUser)
	ON_BN_CLICKED(IDC_BUTTON1, OnChangeP)
	ON_BN_CLICKED(IDC_BUTTON2, OnShowinfor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUser message handlers

void CUser::OnChangeP()  //修改个人密码。
{
	// TODO: Add your control notification handler code here
	UpdateData(true);  //将编辑框中内容传递到编辑框关联的变量中。传递ID这个主码。
	CTableID c2; //Tid这张表。
    CString s1;
	s1.Format("%d",m_ID);  //将ID中的值由int型转化为CString
    c2.m_strFilter = "ID="+s1;  //找到待查询的记录所在位置。
	c2.Open();  //打开数据库
	if(m_Password!=c2.m_Password){
		   c2.Edit();  //修改时要加上这句，！！！！！！！
	       c2.m_Password = m_Password;
		   c2.Update();  //修改
		   AfxMessageBox("已更改为新密码！");
	}
	else
		AfxMessageBox("新密码与旧密码相同，请重新输入新密码");  

    c2.Close();  //数据库有开就有关。
}

void CUser::OnShowinfor() //根据ID这一主码，显示该成员的所有信息。
{
	// TODO: Add your control notification handler code here
		UpdateData(true);  //将编辑框中的内容传递到关联的变量中。主要是获得ID
    	CPinfor c1;
        CString s1;
	s1.Format("%d",m_ID);  //将ID中的值由int型转化为CString
    c1.m_strFilter = "ID="+s1;  //找到待查询的记录所在位置。
	c1.Open();  //打开数据库
	m_Name   = c1.m_Name;  //将数据库中一条记录中不同属性传递到对话框编辑框关联的变量中。
	m_Sex    = c1.m_Sex;
	m_Birth  = c1.m_Birth;
	m_Fname  = c1.m_Father;
	m_Mname  = c1.m_Mother;
	m_Alive  = c1.m_Alive;
	m_Belong = c1.m_Bel;
    m_Tips   = c1.m_Tip;
	UpdateData(false);  //将编辑框关联的变量的内容回显到编辑框中。
	c1.Close();

	AfxMessageBox("查询成功！");

}
