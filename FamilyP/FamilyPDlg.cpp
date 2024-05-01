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
	UpdateData(false);  //���༭������ı�����ֵ��ʾ���༭���С�
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

void CFamilyPDlg::OnTps() //����ʾ����ť�Ĺ��ܡ�
{
	// TODO: Add your control notification handler code here
    //m_Infor = "";
    //UpdateData(false);
	m_Infor = m_Infor+"��ϵͳΪ����ϵͳ,"+"\n"+"�����⿪��ע��,"+"\n"+"����Ҫע�ᣬ����ϵ����ԱJH,"+"\n"+"�绰Ϊ159****0869";
	UpdateData(false);
}

void CFamilyPDlg::OnDengLu() //��¼��ť����Ϊ��ͨ��Ա��¼�͹���Ա��¼���ֱ�������ͬ�Ľ��档label=0����ʾΪ��ͨ�û���label=1:����Ա��
{
	// TODO: Add your control notification handler code here
  /*	UpdateData(true);//���༭�����ݴ��ݵ������ı��������û������id�����롣
    CString st1,st2;
	CTableID c1;
	c1.Open();//�����ݿ�
	int flag=0;//��flag=0:������û��������ڣ�flag=1:�û�������
	while(!c1.IsEOF()){
	    //st1.Format("%d",c1.m_Name);//��ȡ1���û�����
		if(m_ID==c1.m_ID){//��ǰ���ݿ��м�¼�ġ��û�����������ġ��û�������ͬ��
			flag=1;//��ʾ������û������ڡ�
		    //st2.Format("%d",c1.m_Password);//��ȡ���ݿ��б����û�����Ӧ�����롣
			if(m_Password==c1.m_Password){//�����ݿ��м�¼�������������������ͬ��
				AfxMessageBox("��¼�ɹ���");
				if(1==c1.m_Label){//�����ʾ�ǹ���Ա��
				   CAdmin adlg;
				   adlg.DoModal();//��ת������Ա���档
				}
				else{//Label==0,��ʾ����ͨ�û���
				   CUser udlg;
				   udlg.m_ID = m_ID;
				   udlg.DoModal();//��ת�������û����档
				}
			      
				  break;//����ѭ����
			}
			else{//���ݿ��м�¼����������������벻ͬ��

			    AfxMessageBox("�������������󣡣�����������");
				break;
			}
		}
		else//����ǰ�û�����������û�������
          c1.MoveNext();//�����ݿ��м�¼�����ơ�
	}
	if(flag==0)
	   AfxMessageBox("�û��������ڣ���������ʾ����ť��");
	
c1.Close();//���ݿ�رա�*/

	UpdateData(true);//���༭�����ݴ��ݵ������ı��������û������id�����롣
    CString s1;
	CTableID c1;
	s1.Format("%d",m_ID);  //��int������ת��ΪCString�͡�
	c1.m_strFilter = "ID="+s1;
	c1.Open();//�����ݿ�
	if(""==c1.m_Password)  //�����Ƿ�Ϊ�գ����ǿգ���ʾ����û���û��ע�ᣬ�������ڡ�
		AfxMessageBox("�û������ڣ���������ʾ����ť��");
	else{ //�����ID��Ӧ��������ڣ������û����ڡ�
		AfxMessageBox("��¼�ɹ���");
		if(1==c1.m_Label){  //��ʾ����ǹ���ԱID��
		                     CAdmin adlg;
			                 adlg.DoModal();//��ת������Ա���档
		}
		else{  //�������ͨ�û�ID��
		           CUser udlg;
				   udlg.m_ID = m_ID;
				   udlg.DoModal();//��ת�������û����档
		}
	}
  
  c1.Close();  //�ر����ݿ⡣	
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
		UpdateData(false);  //�༭������ı���������ʾ���༭���С�
		c1.Close();
}
