; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInforg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FamilyP.h"

ClassCount=9
Class1=CFamilyPApp
Class2=CFamilyPDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_FAMILYP_DIALOG
Class4=CAdmin
Resource4=IDD_ABOUTBOX
Class5=CUser
Class6=CTableID
Class7=CPinfor
Class8=CRede
Resource5=IDD_DIALOG2
Class9=CInforg
Resource6=IDD_DIALOG3

[CLS:CFamilyPApp]
Type=0
HeaderFile=FamilyP.h
ImplementationFile=FamilyP.cpp
Filter=N

[CLS:CFamilyPDlg]
Type=0
HeaderFile=FamilyPDlg.h
ImplementationFile=FamilyPDlg.cpp
Filter=D
LastObject=IDC_EDIT1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FamilyPDlg.h
ImplementationFile=FamilyPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FAMILYP_DIALOG]
Type=1
Class=CFamilyPDlg
ControlCount=11
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_BUTTON1,button,1342242816
Control8=IDC_BUTTON2,button,1342242816
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_EDIT1,edit,1350631552
Control11=IDC_BUTTON3,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CAdmin
ControlCount=27
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT3,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT4,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT5,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT6,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT7,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT8,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT9,edit,1350631552
Control17=IDC_BUTTON1,button,1342242816
Control18=IDC_BUTTON2,button,1342242816
Control19=IDC_BUTTON3,button,1342242816
Control20=IDC_BUTTON4,button,1342242816
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT10,edit,1350631552
Control24=IDC_STATIC,static,1342308352
Control25=IDC_EDIT11,edit,1350631552
Control26=IDC_BUTTON5,button,1342242816
Control27=IDC_BUTTON6,button,1342242816

[CLS:CAdmin]
Type=0
HeaderFile=Admin.h
ImplementationFile=Admin.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON3
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CUser
ControlCount=23
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT5,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT6,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT7,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT8,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT9,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_EDIT10,edit,1350631552
Control22=IDC_BUTTON1,button,1342242816
Control23=IDC_BUTTON2,button,1342242816

[CLS:CUser]
Type=0
HeaderFile=User.h
ImplementationFile=User.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUser

[CLS:CTableID]
Type=0
HeaderFile=TableID.h
ImplementationFile=TableID.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTableID

[DB:CTableID]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 4, 4
Column2=[Password], 1, 8
Column3=[Label], 5, 2

[CLS:CPinfor]
Type=0
HeaderFile=Pinfor.h
ImplementationFile=Pinfor.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPinfor

[DB:CPinfor]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[ID], 4, 4
Column2=[Name], 1, 3
Column3=[Sex], 1, 1
Column4=[Birth], 1, 10
Column5=[Father], 1, 3
Column6=[Mother], 1, 3
Column7=[Alive], 1, 2
Column8=[Bel], 1, 3
Column9=[Tip], 1, 10

[CLS:CRede]
Type=0
HeaderFile=Rede.h
ImplementationFile=Rede.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CRede

[DB:CRede]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[IDd], 4, 4
Column2=[Named], -8, 8
Column3=[Sexd], -8, 4
Column4=[Birthd], -8, 20
Column5=[Fatherd], -8, 8
Column6=[Motherd], -8, 8
Column7=[Beld], -8, 6

[DLG:IDD_DIALOG3]
Type=1
Class=CInforg
ControlCount=4
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_EDIT1,edit,1082196096

[CLS:CInforg]
Type=0
HeaderFile=Inforg.h
ImplementationFile=Inforg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

