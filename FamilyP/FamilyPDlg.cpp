// FamilyPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FamilyP.h"
#include "FamilyPDlg.h"
#include "TableID.h"
#include "User.h"
#include "Admin.h"
#include "Pinfor.h"

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
	enum { IDD = IDD_ABOUTBOX };
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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFamilyPDlg dialog

CFamilyPDlg::CFamilyPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFamilyPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFamilyPDlg)
	m_ID = 0;
	m_Password = _T("");
	m_Infor = _T("");
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFamilyPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFamilyPDlg)
	DDX_Text(pDX, IDC_EDIT2, m_ID);
	DDX_Text(pDX, IDC_EDIT3, m_Password);
	DDX_Text(pDX, IDC_EDIT4, m_Infor);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFamilyPDlg, CDialog)
	//{{AFX_MSG_MAP(CFamilyPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnTps)
	ON_BN_CLICKED(IDC_BUTTON1, OnDengLu)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFamilyPDlg message handlers

BOOL CFamilyPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    
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

	m_ID = 1231000;
	m_Password = "JH000223";
	UpdateData(false);  //将编辑框关联的变量的值显示到编辑框中。
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFamilyPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFamilyPDlg::OnPaint() 
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
HCURSOR CFamilyPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFamilyPDlg::OnTps() //“提示”按钮的功能。
{
	// TODO: Add your control notification handler code here
    //m_Infor = "";
    //UpdateData(false);
	m_Infor = m_Infor+"本系统为家谱系统,"+"\n"+"不对外开放注册,"+"\n"+"如需要注册，请联系管理员JH,"+"\n"+"电话为159****0869";
	UpdateData(false);
}

void CFamilyPDlg::OnDengLu() //登录按钮，分为普通成员登录和管理员登录，分别跳到不同的界面。label=0，表示为普通用户，label=1:管理员。
{
	// TODO: Add your control notification handler code here
  /*	UpdateData(true);//将编辑框内容传递到关联的变量里。获得用户输入的id与密码。
    CString st1,st2;
	CTableID c1;
	c1.Open();//打开数据库
	int flag=0;//若flag=0:输入的用户名不存在；flag=1:用户名存在
	while(!c1.IsEOF()){
	    //st1.Format("%d",c1.m_Name);//获取1个用户名。
		if(m_ID==c1.m_ID){//当前数据库中记录的“用户名”与输入的“用户名”相同。
			flag=1;//表示输入的用户名存在。
		    //st2.Format("%d",c1.m_Password);//获取数据库中表中用户名对应的密码。
			if(m_Password==c1.m_Password){//若数据库中记录的密码与输入的密码相同。
				AfxMessageBox("登录成功！");
				if(1==c1.m_Label){//这个表示是管理员。
				   CAdmin adlg;
				   adlg.DoModal();//跳转到管理员界面。
				}
				else{//Label==0,表示是普通用户。
				   CUser udlg;
				   udlg.m_ID = m_ID;
				   udlg.DoModal();//跳转到个人用户界面。
				}
			      
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
	if(flag==0)
	   AfxMessageBox("用户名不存在，请点击“提示”按钮！");
	
c1.Close();//数据库关闭。*/

	UpdateData(true);//将编辑框内容传递到关联的变量里。获得用户输入的id与密码。
    CString s1;
	CTableID c1;
	s1.Format("%d",m_ID);  //将int型数据转化为CString型。
	c1.m_strFilter = "ID="+s1;
	c1.Open();//打开数据库
	if(""==c1.m_Password)  //密码是否为空，若是空，表示这个用户并没有注册，即不存在。
		AfxMessageBox("用户不存在，请点击“提示”按钮！");
	else{ //输入的ID对应的密码存在，即该用户存在。
		AfxMessageBox("登录成功！");
		if(1==c1.m_Label){  //表示这个是管理员ID。
		                     CAdmin adlg;
			                 adlg.DoModal();//跳转到管理员界面。
		}
		else{  //这个是普通用户ID。
		           CUser udlg;
				   udlg.m_ID = m_ID;
				   udlg.DoModal();//跳转到个人用户界面。
		}
	}
  
  c1.Close();  //关闭数据库。	
}

void CFamilyPDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	//m_str = "1234";
		CTableID c1;
		c1.m_strFilter = "ID='0'";
		c1.Open();
	    if(c1.m_Password==""&&c1.m_Label==0)
	    	m_str = "1234";
		UpdateData(false);  //编辑框关联的变量内容显示到编辑框中。
		c1.Close();
}
