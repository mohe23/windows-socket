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

void  CInforg::SetLine()  //�б���������ߡ�
{
                    m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);  //��������ߺ�����ѡ�����ԡ�
		//m_List.DeleteAllItems();  //����б���������
                    m_List.InsertColumn(0,_T("ID"),LVCFMT_CENTER);
	                m_List.InsertColumn(1,_T("����"),LVCFMT_CENTER);
	                m_List.InsertColumn(2,_T("�Ա�"),LVCFMT_CENTER);
	                m_List.InsertColumn(3,_T("��������"),LVCFMT_CENTER);
                 	m_List.InsertColumn(4,_T("����"),LVCFMT_CENTER);
	                m_List.InsertColumn(5,_T("ĸ��"),LVCFMT_CENTER);
	                m_List.InsertColumn(7,_T("�Ƿ�����"),LVCFMT_CENTER);
	                m_List.InsertColumn(6,_T("�Ƿ񱾼�"),LVCFMT_CENTER);
	                m_List.InsertColumn(8,_T("��ע"),LVCFMT_CENTER);
    
	                 m_List.SetColumnWidth(0,80);  //�����п�
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
    if(0==m_Count) //ֻ�е�1�ε����ťʱ���Ż������ߣ��ٴε����������������ߡ�
		SetLine();  

	CPinfor c1;
	CString s1;
	int r=0;
	m_List.DeleteAllItems();  //�����ɾ������ͷ֮����������ݡ�����Ƿ�ֹ�ظ����ʱ�����Ϣ���ҡ�

	c1.Open();//�����ݿ⡣
	while(!c1.IsEOF()){
	   s1.Format("%d",c1.m_ID);
	   //s2.Format("%d",c1.m_Password);
       m_List.InsertItem(r,s1);//����1�У���s1д���1�С�
	   m_List.SetItemText(r,1,c1.m_Name);//���������Ҫ3����������s2д���2�С�
	   m_List.SetItemText(r,2,c1.m_Sex);
	   m_List.SetItemText(r,3,c1.m_Birth);
	   m_List.SetItemText(r,4,c1.m_Father);
	   m_List.SetItemText(r,5,c1.m_Mother);
	   m_List.SetItemText(r,7,c1.m_Alive);
	   m_List.SetItemText(r,6,c1.m_Bel);
	   m_List.SetItemText(r,8,c1.m_Tip);

	   c1.MoveNext();//��ָ��ָ����һ����¼��
	   r++;
	}
	c1.Close();
	m_Count++;  //��m_Count��ֵ��1����ֹ�ٴε������������ߺ�����
	UpdateData(false);  //���༭������ı�����ֵ��ʾ������
}

void CInforg::OnDeShow() 
{
	// TODO: Add your control notification handler code here
		//m_List.DeleteAllItems();  //����б���������
//	m_List.DeleteItem(0);
	if(0==m_Count) //ֻ�е�1�ε����ťʱ���Ż������ߣ��ٴε����������������ߡ�
		SetLine();  

	CRede c1;
	CString s1;
	int r=0;
	m_List.DeleteAllItems();  //�����ɾ������ͷ֮����������ݡ�����Ƿ�ֹ�ظ����ʱ�����Ϣ���ҡ�

	c1.Open();//�����ݿ⡣
	while(!c1.IsEOF()){
	   s1.Format("%d",c1.m_IDd);
	   //s2.Format("%d",c1.m_Password);
       m_List.InsertItem(r,s1);//����1�У���s1д���1�С�
	   m_List.SetItemText(r,1,c1.m_Named);//���������Ҫ3����������s2д���2�С�
	   m_List.SetItemText(r,2,c1.m_Sexd);
	   m_List.SetItemText(r,3,c1.m_Birthd);
	   m_List.SetItemText(r,4,c1.m_Fatherd);
	   m_List.SetItemText(r,5,c1.m_Motherd);
	   m_List.SetItemText(r,6,c1.m_Beld);

	   c1.MoveNext();//��ָ��ָ����һ����¼��
	   r++;
	}
	c1.Close();
	 m_Count++;
		UpdateData(false);  //���༭������ı�����ֵ��ʾ������
}

