// Admin.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "Admin.h"
#include "TableID.h"
#include "Pinfor.h"
#include "Rede.h"
#include "Inforg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdmin dialog


CAdmin::CAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(CAdmin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdmin)
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


void CAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdmin)
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_Sex);
	DDX_Text(pDX, IDC_EDIT4, m_Birth);
	DDX_Text(pDX, IDC_EDIT5, m_Fname);
	DDX_Text(pDX, IDC_EDIT6, m_Mname);
	DDX_Text(pDX, IDC_EDIT7, m_Alive);
	DDX_Text(pDX, IDC_EDIT8, m_Belong);
	DDX_Text(pDX, IDC_EDIT9, m_Tips);
	DDX_Text(pDX, IDC_EDIT10, m_ID);
	DDX_Text(pDX, IDC_EDIT11, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdmin, CDialog)
	//{{AFX_MSG_MAP(CAdmin)
	ON_BN_CLICKED(IDC_BUTTON1, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON3, OnChange)
	ON_BN_CLICKED(IDC_BUTTON4, OnShow)
	ON_BN_CLICKED(IDC_BUTTON5, OnChangePassW)
	ON_BN_CLICKED(IDC_BUTTON6, OnList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdmin message handlers

void CAdmin::OnAdd() //新增记录。对数据库中2个表都增加记录。
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//这个将输入到编辑框的内容传递到关联的变量中。
    CTableID c1;   //这个是数据库中表Tid。
	CPinfor  c2;   //这个是数据库中表Re。
    c1.Open();     //打开数据库
    c1.AddNew();    //新增一条记录。
	c1.m_ID = m_ID;
	c1.m_Password = m_Password;
	c1.m_Label = 0;//普通用户，标记为0。
	c1.Update();//向表中增加1条记录。
	c1.Close();//关闭数据库。

	c2.Open();   //打开数据库表Re。
	c2.AddNew();   //新增数据记录。
	c2.m_ID = m_ID;
	c2.m_Name = m_Name;  //姓名
	c2.m_Sex = m_Sex;   //性别
	c2.m_Birth = m_Birth;  //生日
	c2.m_Father = m_Fname;  //父亲姓名
	c2.m_Mother = m_Mname;  //母亲姓名
	c2.m_Alive  = m_Alive;  //是否在世。！！！由此可以延伸1个逝世日期。
	c2.m_Bel  =  m_Belong;  //是否本家。
	c2.m_Tip  =  m_Tips;   //备注，暂时无用。
    c2.Update();  //向表中新增记录。
	c2.Close();  //关闭数据库。

	AfxMessageBox("新增成功！");
}

void CAdmin::OnDelete() //删除数据库中一个ID所对应的，2个表中的记录。
{
	// TODO: Add your control notification handler code here
	UpdateData(true);  //将输入到编辑框中的内容传递到该编辑框关联的变量中。
	CTableID c1;
	CPinfor  c2;
	CRede   c3;  //保存被删除的记录信息。
	CString s1;
	s1.Format("%d",m_ID);  //将ID中的值由int型转化为CString
    c1.m_strFilter = "ID="+s1;  //找到待删除的记录所在位置。
	c2.m_strFilter = "ID="+s1;  //找到待删除的记录所在位置
	  c1.Open();
	  c2.Open();
	c3.Open();  //打开数据库
	c3.AddNew();  //新增记录。
	c3.m_IDd = c2.m_ID;  //保存ID
    c3.m_Named = c2.m_Name; 
	c3.m_Sexd = c2.m_Sex;
	c3.m_Birthd = c2.m_Birth;
	c3.m_Fatherd = c2.m_Father;
	c3.m_Motherd = c2.m_Mother;
	c3.m_Beld = c2.m_Bel;
	c3.Update();  //
	c3.Close();  //关闭数据库。


	c1.Delete();  //删除记录。
  
	c2.Delete();
	c1.Close();  //关闭数据库
	c2.Close();  //关闭数据库

	AfxMessageBox("删除成功！");  //跳出1个小弹窗提示删除成功。
}


void CAdmin::OnChange() //修改要在查询之后，这样是为了知道修改什么内容。这个只涉及到一张表。
{
	// TODO: Add your control notification handler code here
	   UpdateData(true);  //将编辑框中的内容传递到关联的变量中。
    	CPinfor c1;
        CString s1;
	s1.Format("%d",m_ID);  //将ID中的值由int型转化为CString
    c1.m_strFilter = "ID="+s1;  //找到待修改的记录所在位置。
	c1.Open();  //打开数据库
	c1.Edit();  //表示修改。
	if(m_Name!=c1.m_Name)
		c1.m_Name = m_Name;  //只有当前编辑框内容与数据库中记录的内容不同才修改
	if(m_Sex!=c1.m_Sex)
		c1.m_Sex = m_Sex;
	if(m_Birth!=c1.m_Birth)
		c1.m_Birth = m_Birth;
	if(m_Fname!=c1.m_Father)
		c1.m_Father = m_Fname;
	if(m_Mname!=c1.m_Mother)
		c1.m_Mother = m_Mname;
	if(m_Alive!=c1.m_Alive)
		c1.m_Alive = m_Alive;
	if(m_Belong!=c1.m_Bel)
		c1.m_Bel = m_Belong;
	if(m_Tips!=c1.m_Tip)
		c1.m_Tip = m_Tips;

	c1.Update();
	c1.Close();  //关闭数据库
	AfxMessageBox("修改成功！");
}

void CAdmin::OnShow() //根据输入的ID,查询其个人信息。
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

void CAdmin::OnChangePassW() //在管理员端改变密码。
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

void CAdmin::OnList() //跳转到另1个页面，查询数据库中所有信息。
{

	// TODO: Add your control notification handler code here
	CInforg dlg;
    dlg.m_Count = 0;
	//dlg.m_List.SetExtendedStyle(LVS_EX_GRIDLINES);  //添加网格线和整行选中属性。
		//m_List.DeleteAllItems();  //清除列表所有内容
    //dlg.m_List.InsertColumn(0,_T("ID"),LVCFMT_CENTER);
	//dlg.m_List.InsertColumn(1,_T("姓名"),LVCFMT_CENTER);
	/*m_List.InsertColumn(2,_T("性别"),LVCFMT_CENTER);
	m_List.InsertColumn(3,_T("出生日期"),LVCFMT_CENTER);
	m_List.InsertColumn(4,_T("父名"),LVCFMT_CENTER);
	m_List.InsertColumn(5,_T("母名"),LVCFMT_CENTER);
	m_List.InsertColumn(6,_T("是否在世"),LVCFMT_CENTER);
	m_List.InsertColumn(7,_T("是否本家"),LVCFMT_CENTER);
	m_List.InsertColumn(8,_T("备注"),LVCFMT_CENTER);
    */
//	dlg.m_List.SetColumnWidth(0,80);  //设置列宽。
  //  dlg.m_List.SetColumnWidth(1,70);  
	/*m_List.SetColumnWidth(2,50);
	m_List.SetColumnWidth(3,100);
	m_List.SetColumnWidth(4,70);
	m_List.SetColumnWidth(5,70);
	m_List.SetColumnWidth(6,80);
	m_List.SetColumnWidth(7,80);
    m_List.SetColumnWidth(8,80);*/



	dlg.DoModal();
}
