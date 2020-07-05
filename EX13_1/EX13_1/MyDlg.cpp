// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EX13_1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "EX13_1View.h"

// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &MyDlg::OnEnChangeEdit1)
	
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnEnChangeEdit1()
{
	
	this->UpdateData(true);
    s = s;
	UpdateData(false);
}



