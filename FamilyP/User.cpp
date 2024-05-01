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

void CUser::OnChangeP()  //�޸ĸ������롣
{
	// TODO: Add your control notification handler code here
	UpdateData(true);  //���༭�������ݴ��ݵ��༭������ı����С�����ID������롣
	CTableID c2; //Tid���ű�
    CString s1;
	s1.Format("%d",m_ID);  //��ID�е�ֵ��int��ת��ΪCString
    c2.m_strFilter = "ID="+s1;  //�ҵ�����ѯ�ļ�¼����λ�á�
	c2.Open();  //�����ݿ�
	if(m_Password!=c2.m_Password){
		   c2.Edit();  //�޸�ʱҪ������䣬��������������
	       c2.m_Password = m_Password;
		   c2.Update();  //�޸�
		   AfxMessageBox("�Ѹ���Ϊ�����룡");
	}
	else
		AfxMessageBox("���������������ͬ������������������");  

    c2.Close();  //���ݿ��п����йء�
}

void CUser::OnShowinfor() //����ID��һ���룬��ʾ�ó�Ա��������Ϣ��
{
	// TODO: Add your control notification handler code here
		UpdateData(true);  //���༭���е����ݴ��ݵ������ı����С���Ҫ�ǻ��ID
    	CPinfor c1;
        CString s1;
	s1.Format("%d",m_ID);  //��ID�е�ֵ��int��ת��ΪCString
    c1.m_strFilter = "ID="+s1;  //�ҵ�����ѯ�ļ�¼����λ�á�
	c1.Open();  //�����ݿ�
	m_Name   = c1.m_Name;  //�����ݿ���һ����¼�в�ͬ���Դ��ݵ��Ի���༭������ı����С�
	m_Sex    = c1.m_Sex;
	m_Birth  = c1.m_Birth;
	m_Fname  = c1.m_Father;
	m_Mname  = c1.m_Mother;
	m_Alive  = c1.m_Alive;
	m_Belong = c1.m_Bel;
    m_Tips   = c1.m_Tip;
	UpdateData(false);  //���༭������ı��������ݻ��Ե��༭���С�
	c1.Close();

	AfxMessageBox("��ѯ�ɹ���");

}
