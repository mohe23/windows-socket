// 111Dlg.cpp : implementation file
//
#include<graphics.h>
#include<conio.h>
#include "stdafx.h"
#include "111.h"
#include "111Dlg.h"
#include"tsdf.h"
#include"excel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_DIALOG1 };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_LIST4, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy111Dlg dialog

CMy111Dlg::CMy111Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy111Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy111Dlg)
	m_te = _T("");
	m_pa = _T("");
	m_rpa = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy111Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy111Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_te);
	DDX_Text(pDX, IDC_EDIT2, m_pa);
	DDX_Text(pDX, IDC_EDIT4, m_rpa);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy111Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy111Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnLogs)
	ON_BN_CLICKED(IDC_BUTTON3, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON4, OnShowall)
	ON_BN_CLICKED(IDC_BUTTON5, OnRepair)
	ON_BN_CLICKED(IDC_BUTTON7, OnRequest)
	ON_BN_CLICKED(IDC_BUTTON8, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy111Dlg message handlers

BOOL CMy111Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

//	m_List.SetExtendedStyle(LVS_EX_GRIDLINES)

    m_setRec.Open();//按照教程步骤做的！！

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy111Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy111Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy111Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CMy111Dlg::ShowVal()//新添加的函数。
{
  CString strTmp;
  m_setRec.MoveFirst();
  strTmp.Format("%d",m_setRec.m_Password);//将int型值转化为CString型。
  //GetDlgItem(IDC_EDIT1)->SetWindowText(strTmp);
  m_te = strTmp;//将CString值赋值给“编辑框”。
  UpdateData(false);//将值显示在“编辑框”中
}

void CMy111Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//m_setRec.Open();
	ShowVal();
//	m_setRec.Close();

}

void CMy111Dlg::OnLogs() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//获取手动输入的“用户名”与“密码”。
	CString st1,st2;
	CRecSet c1;
	c1.Open();//打开数据库
	int flag=0;//若flag=0:输入的用户名不存在；flag=1:用户名存在
	while(!c1.IsEOF()){
	    st1.Format("%d",c1.m_Name);//获取1个用户名。
		if(m_te==st1){//当前数据库中记录的“用户名”与输入的“用户名”相同。
			flag=1;//表示输入的用户名存在。
		    st2.Format("%d",c1.m_Password);//获取数据库中表中用户名对应的密码。
			if(st2==m_pa){//若数据库中记录的密码与输入的密码相同。
			      AfxMessageBox("登录成功！");
				  break;//跳出循环！
			}
			else{//数据库中记录的密码与输入的密码不同。

			    AfxMessageBox("您输入的密码错误！，请重新输入");
				break;
			}
		}
		else//若当前用户名与输入的用户名不符
          c1.MoveNext();//将数据库中记录向下移。
	}
   /* m_setRec.MoveFirst();//读取数据库中一个表中第1行内容（实际这个表只有1个表。）
	st1.Format("%d",m_setRec.m_Name);//获取数据库中已存“用户名”。
	st2.Format("%d",m_setRec.m_Password);//获取数据库中“密码”。
    if(m_te==st1&&m_pa==st2)//若“手动输入”与数据库中相同，则表示登录成功。
		AfxMessageBox("登录成功！");
	else
        AfxMessageBox("登录失败，用户名或密码错误！！");*/
	if(flag==0)
	   AfxMessageBox("用户名不存在，请注册！");
	
c1.Close();//数据库关闭。
}

void CMy111Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//获得手动输入的“用户名”与“密码”。
	CRecSet c1;//获得1个对象。
	c1.Open();//打开数据库文件。
	c1.AddNew();//添加新数据。
	c1.m_Name = atoi(m_te);//新记录中的“用户名”。即我们输入的内容，再将数据从CString转化为int。
	c1.m_Password = atoi(m_pa);//新记录中的“密码”。
    c1.Update();//向数据库中表增加这条记录。
	c1.Close();//关闭文件。
	AfxMessageBox("注册成功！");
}

void CMy111Dlg::OnShowall() 
{
	// TODO: Add your control notification handler code here
/*	CRecSet c1;//获得类的对象。
	int y=20;
	CString str;//临时变量。
	c1.Open();//打开数据库。
    CClientDC dc(this);//客户区
	while(!c1.IsEOF()){//判断是否到文件尾。
	    str.Format("Name: %d, Password: %d",c1.m_Name,c1.m_Password);//
		dc.TextOut(20,y,str);//dc调用函数TextOut显示内容。
		c1.MoveNext();//指针默认在第1条记录，这句使得指针下移。
		y+=20;//换行
	}
	c1.Close();
	*/
	Cexcel exdlg;
    /*exdlg.m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//添加网格线和整行选中属性。
	exdlg.m_List.InsertColumn(0,_T("用户名"),LVCFMT_CENTER);//初始化表头。
	exdlg.m_List.InsertColumn(1,_T("密码"),LVCFMT_CENTER);
	exdlg.m_List.SetColumnWidth(0,150);//设置列宽
	exdlg.m_List.SetColumnWidth(1,160);
	*/
	exdlg.DoModal();
}

void CMy111Dlg::OnRepair() 
{
	// TODO: Add your control notification handler code here
	CRecSet c1;
	UpdateData(true);//获得待修改记录的Name字段。
	c1.m_strFilter="Name="+m_te;//根据输入内容找到待修改的记录。
	c1.Open();
	c1.Edit();//表示修改。
	c1.m_Password=atoi(m_rpa);//将密码改为我们输入的内容。
	c1.Update();
	c1.Close();
   AfxMessageBox("修改成功！");
}

void CMy111Dlg::OnRequest() 
{
	// TODO: Add your control notification handler code here
	CRecSet c1;
	CString str;
	UpdateData(true);//获得待查询记录的Name字段。
	c1.m_strFilter="Name="+m_te;//根据Name字段找到待查询的记录。
	c1.Open();
	str.Format("%d",c1.m_Password);
	m_pa = str;
	UpdateData(false);//将获得的记录的“密码”显示。
	c1.Close();
	AfxMessageBox("查询成功！");//若查找不到呐？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
}

void CMy111Dlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
		CRecSet c1;
	UpdateData(true);//获得待删除记录的Name字段。
	c1.m_strFilter="Name="+m_te;//根据输入内容找到待删除的记录。
	c1.Open();
	c1.Delete();//表示删除。
	//c1.m_Password=atoi(m_rpa);//将密码改为我们输入的内容。
	//c1.Update();
	c1.Close();
   AfxMessageBox("删除成功！");
}

void CMy111Dlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	Ctsdf dlg;

  UpdateData(true);//将编辑框中数据传递到与编辑框绑定的变量中。
	dlg.m_name = m_te;
	dlg.m_pass = m_pa;
//	UpdateData(false);//将数据显示在编辑框中。
		dlg.DoModal();
}

void CMy111Dlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
