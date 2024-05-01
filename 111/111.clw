; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMy111Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "111.h"

ClassCount=6
Class1=CMy111App
Class2=CMy111Dlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG2
Resource2=IDR_MAINFRAME
Class4=CRecSet
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG1
Class5=Ctsdf
Resource5=IDD_MY111_DIALOG
Class6=Cexcel
Resource6=IDD_DIALOG3

[CLS:CMy111App]
Type=0
HeaderFile=111.h
ImplementationFile=111.cpp
Filter=N

[CLS:CMy111Dlg]
Type=0
HeaderFile=111Dlg.h
ImplementationFile=111Dlg.cpp
Filter=D
LastObject=CMy111Dlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=111Dlg.h
ImplementationFile=111Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY111_DIALOG]
Type=1
Class=CMy111Dlg
ControlCount=15
Control1=IDC_STATIC,static,1342177294
Control2=IDC_BUTTON3,button,1342242816
Control3=IDC_BUTTON8,button,1342242816
Control4=IDC_BUTTON5,button,1342242816
Control5=IDC_BUTTON7,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON1,button,1342242816
Control8=IDC_BUTTON2,button,1342242816
Control9=IDC_BUTTON6,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT1,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT2,edit,1350631552
Control14=IDC_EDIT4,edit,1350631552
Control15=IDC_STATIC,static,1342308352

[CLS:CRecSet]
Type=0
HeaderFile=RecSet.h
ImplementationFile=RecSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CRecSet

[DB:CRecSet]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[Name], 4, 4
Column2=[Password], 4, 4

[DLG:IDD_DIALOG1]
Type=1
Class=CAboutDlg
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=Ctsdf
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816

[CLS:Ctsdf]
Type=0
HeaderFile=tsdf.h
ImplementationFile=tsdf.cpp
BaseClass=CDialog
Filter=D
LastObject=Ctsdf
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=Cexcel
ControlCount=2
Control1=IDC_LIST4,SysListView32,1350631425
Control2=IDC_BUTTON1,button,1342242816

[CLS:Cexcel]
Type=0
HeaderFile=excel.h
ImplementationFile=excel.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST4
VirtualFilter=dWC

