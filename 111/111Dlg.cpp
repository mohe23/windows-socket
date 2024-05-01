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

    m_setRec.Open();//���ս̳̲������ģ���

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


void CMy111Dlg::ShowVal()//����ӵĺ�����
{
  CString strTmp;
  m_setRec.MoveFirst();
  strTmp.Format("%d",m_setRec.m_Password);//��int��ֵת��ΪCString�͡�
  //GetDlgItem(IDC_EDIT1)->SetWindowText(strTmp);
  m_te = strTmp;//��CStringֵ��ֵ�����༭�򡱡�
  UpdateData(false);//��ֵ��ʾ�ڡ��༭����
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
	UpdateData(true);//��ȡ�ֶ�����ġ��û������롰���롱��
	CString st1,st2;
	CRecSet c1;
	c1.Open();//�����ݿ�
	int flag=0;//��flag=0:������û��������ڣ�flag=1:�û�������
	while(!c1.IsEOF()){
	    st1.Format("%d",c1.m_Name);//��ȡ1���û�����
		if(m_te==st1){//��ǰ���ݿ��м�¼�ġ��û�����������ġ��û�������ͬ��
			flag=1;//��ʾ������û������ڡ�
		    st2.Format("%d",c1.m_Password);//��ȡ���ݿ��б����û�����Ӧ�����롣
			if(st2==m_pa){//�����ݿ��м�¼�������������������ͬ��
			      AfxMessageBox("��¼�ɹ���");
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
   /* m_setRec.MoveFirst();//��ȡ���ݿ���һ�����е�1�����ݣ�ʵ�������ֻ��1������
	st1.Format("%d",m_setRec.m_Name);//��ȡ���ݿ����Ѵ桰�û�������
	st2.Format("%d",m_setRec.m_Password);//��ȡ���ݿ��С����롱��
    if(m_te==st1&&m_pa==st2)//�����ֶ����롱�����ݿ�����ͬ�����ʾ��¼�ɹ���
		AfxMessageBox("��¼�ɹ���");
	else
        AfxMessageBox("��¼ʧ�ܣ��û�����������󣡣�");*/
	if(flag==0)
	   AfxMessageBox("�û��������ڣ���ע�ᣡ");
	
c1.Close();//���ݿ�رա�
}

void CMy111Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//����ֶ�����ġ��û������롰���롱��
	CRecSet c1;//���1������
	c1.Open();//�����ݿ��ļ���
	c1.AddNew();//��������ݡ�
	c1.m_Name = atoi(m_te);//�¼�¼�еġ��û���������������������ݣ��ٽ����ݴ�CStringת��Ϊint��
	c1.m_Password = atoi(m_pa);//�¼�¼�еġ����롱��
    c1.Update();//�����ݿ��б�����������¼��
	c1.Close();//�ر��ļ���
	AfxMessageBox("ע��ɹ���");
}

void CMy111Dlg::OnShowall() 
{
	// TODO: Add your control notification handler code here
/*	CRecSet c1;//�����Ķ���
	int y=20;
	CString str;//��ʱ������
	c1.Open();//�����ݿ⡣
    CClientDC dc(this);//�ͻ���
	while(!c1.IsEOF()){//�ж��Ƿ��ļ�β��
	    str.Format("Name: %d, Password: %d",c1.m_Name,c1.m_Password);//
		dc.TextOut(20,y,str);//dc���ú���TextOut��ʾ���ݡ�
		c1.MoveNext();//ָ��Ĭ���ڵ�1����¼�����ʹ��ָ�����ơ�
		y+=20;//����
	}
	c1.Close();
	*/
	Cexcel exdlg;
    /*exdlg.m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//��������ߺ�����ѡ�����ԡ�
	exdlg.m_List.InsertColumn(0,_T("�û���"),LVCFMT_CENTER);//��ʼ����ͷ��
	exdlg.m_List.InsertColumn(1,_T("����"),LVCFMT_CENTER);
	exdlg.m_List.SetColumnWidth(0,150);//�����п�
	exdlg.m_List.SetColumnWidth(1,160);
	*/
	exdlg.DoModal();
}

void CMy111Dlg::OnRepair() 
{
	// TODO: Add your control notification handler code here
	CRecSet c1;
	UpdateData(true);//��ô��޸ļ�¼��Name�ֶΡ�
	c1.m_strFilter="Name="+m_te;//�������������ҵ����޸ĵļ�¼��
	c1.Open();
	c1.Edit();//��ʾ�޸ġ�
	c1.m_Password=atoi(m_rpa);//�������Ϊ������������ݡ�
	c1.Update();
	c1.Close();
   AfxMessageBox("�޸ĳɹ���");
}

void CMy111Dlg::OnRequest() 
{
	// TODO: Add your control notification handler code here
	CRecSet c1;
	CString str;
	UpdateData(true);//��ô���ѯ��¼��Name�ֶΡ�
	c1.m_strFilter="Name="+m_te;//����Name�ֶ��ҵ�����ѯ�ļ�¼��
	c1.Open();
	str.Format("%d",c1.m_Password);
	m_pa = str;
	UpdateData(false);//����õļ�¼�ġ����롱��ʾ��
	c1.Close();
	AfxMessageBox("��ѯ�ɹ���");//�����Ҳ����ţ�������������������������������������������������������������������������
}

void CMy111Dlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
		CRecSet c1;
	UpdateData(true);//��ô�ɾ����¼��Name�ֶΡ�
	c1.m_strFilter="Name="+m_te;//�������������ҵ���ɾ���ļ�¼��
	c1.Open();
	c1.Delete();//��ʾɾ����
	//c1.m_Password=atoi(m_rpa);//�������Ϊ������������ݡ�
	//c1.Update();
	c1.Close();
   AfxMessageBox("ɾ���ɹ���");
}

void CMy111Dlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	Ctsdf dlg;

  UpdateData(true);//���༭�������ݴ��ݵ���༭��󶨵ı����С�
	dlg.m_name = m_te;
	dlg.m_pass = m_pa;
//	UpdateData(false);//��������ʾ�ڱ༭���С�
		dlg.DoModal();
}

void CMy111Dlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
