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

void CAdmin::OnAdd() //������¼�������ݿ���2�������Ӽ�¼��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//��������뵽�༭������ݴ��ݵ������ı����С�
    CTableID c1;   //��������ݿ��б�Tid��
	CPinfor  c2;   //��������ݿ��б�Re��
    c1.Open();     //�����ݿ�
    c1.AddNew();    //����һ����¼��
	c1.m_ID = m_ID;
	c1.m_Password = m_Password;
	c1.m_Label = 0;//��ͨ�û������Ϊ0��
	c1.Update();//���������1����¼��
	c1.Close();//�ر����ݿ⡣

	c2.Open();   //�����ݿ��Re��
	c2.AddNew();   //�������ݼ�¼��
	c2.m_ID = m_ID;
	c2.m_Name = m_Name;  //����
	c2.m_Sex = m_Sex;   //�Ա�
	c2.m_Birth = m_Birth;  //����
	c2.m_Father = m_Fname;  //��������
	c2.m_Mother = m_Mname;  //ĸ������
	c2.m_Alive  = m_Alive;  //�Ƿ��������������ɴ˿�������1���������ڡ�
	c2.m_Bel  =  m_Belong;  //�Ƿ񱾼ҡ�
	c2.m_Tip  =  m_Tips;   //��ע����ʱ���á�
    c2.Update();  //�����������¼��
	c2.Close();  //�ر����ݿ⡣

	AfxMessageBox("�����ɹ���");
}

void CAdmin::OnDelete() //ɾ�����ݿ���һ��ID����Ӧ�ģ�2�����еļ�¼��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);  //�����뵽�༭���е����ݴ��ݵ��ñ༭������ı����С�
	CTableID c1;
	CPinfor  c2;
	CRede   c3;  //���汻ɾ���ļ�¼��Ϣ��
	CString s1;
	s1.Format("%d",m_ID);  //��ID�е�ֵ��int��ת��ΪCString
    c1.m_strFilter = "ID="+s1;  //�ҵ���ɾ���ļ�¼����λ�á�
	c2.m_strFilter = "ID="+s1;  //�ҵ���ɾ���ļ�¼����λ��
	  c1.Open();
	  c2.Open();
	c3.Open();  //�����ݿ�
	c3.AddNew();  //������¼��
	c3.m_IDd = c2.m_ID;  //����ID
    c3.m_Named = c2.m_Name; 
	c3.m_Sexd = c2.m_Sex;
	c3.m_Birthd = c2.m_Birth;
	c3.m_Fatherd = c2.m_Father;
	c3.m_Motherd = c2.m_Mother;
	c3.m_Beld = c2.m_Bel;
	c3.Update();  //
	c3.Close();  //�ر����ݿ⡣


	c1.Delete();  //ɾ����¼��
  
	c2.Delete();
	c1.Close();  //�ر����ݿ�
	c2.Close();  //�ر����ݿ�

	AfxMessageBox("ɾ���ɹ���");  //����1��С������ʾɾ���ɹ���
}


void CAdmin::OnChange() //�޸�Ҫ�ڲ�ѯ֮��������Ϊ��֪���޸�ʲô���ݡ����ֻ�漰��һ�ű�
{
	// TODO: Add your control notification handler code here
	   UpdateData(true);  //���༭���е����ݴ��ݵ������ı����С�
    	CPinfor c1;
        CString s1;
	s1.Format("%d",m_ID);  //��ID�е�ֵ��int��ת��ΪCString
    c1.m_strFilter = "ID="+s1;  //�ҵ����޸ĵļ�¼����λ�á�
	c1.Open();  //�����ݿ�
	c1.Edit();  //��ʾ�޸ġ�
	if(m_Name!=c1.m_Name)
		c1.m_Name = m_Name;  //ֻ�е�ǰ�༭�����������ݿ��м�¼�����ݲ�ͬ���޸�
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
	c1.Close();  //�ر����ݿ�
	AfxMessageBox("�޸ĳɹ���");
}

void CAdmin::OnShow() //���������ID,��ѯ�������Ϣ��
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

void CAdmin::OnChangePassW() //�ڹ���Ա�˸ı����롣
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

void CAdmin::OnList() //��ת����1��ҳ�棬��ѯ���ݿ���������Ϣ��
{

	// TODO: Add your control notification handler code here
	CInforg dlg;
    dlg.m_Count = 0;
	//dlg.m_List.SetExtendedStyle(LVS_EX_GRIDLINES);  //��������ߺ�����ѡ�����ԡ�
		//m_List.DeleteAllItems();  //����б���������
    //dlg.m_List.InsertColumn(0,_T("ID"),LVCFMT_CENTER);
	//dlg.m_List.InsertColumn(1,_T("����"),LVCFMT_CENTER);
	/*m_List.InsertColumn(2,_T("�Ա�"),LVCFMT_CENTER);
	m_List.InsertColumn(3,_T("��������"),LVCFMT_CENTER);
	m_List.InsertColumn(4,_T("����"),LVCFMT_CENTER);
	m_List.InsertColumn(5,_T("ĸ��"),LVCFMT_CENTER);
	m_List.InsertColumn(6,_T("�Ƿ�����"),LVCFMT_CENTER);
	m_List.InsertColumn(7,_T("�Ƿ񱾼�"),LVCFMT_CENTER);
	m_List.InsertColumn(8,_T("��ע"),LVCFMT_CENTER);
    */
//	dlg.m_List.SetColumnWidth(0,80);  //�����п�
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
