// Combine.cpp : 实现文件
//

#include "stdafx.h"
#include "EX12_4.h"
#include "Combine.h"
#include "afxdialogex.h"


// Combine 对话框

IMPLEMENT_DYNAMIC(Combine, CDialogEx)

Combine::Combine(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, x(0)
	, s2(_T(""))
{

}

Combine::~Combine()
{
}

void Combine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDV_MaxChars(pDX, s1, 20);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDV_MinMaxInt(pDX, x, 0, 200);
	DDX_Text(pDX, IDC_EDIT3, s2);
	DDV_MaxChars(pDX, s2, 30);
}


BEGIN_MESSAGE_MAP(Combine, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Combine::OnBnClickedButton1)
END_MESSAGE_MAP()


// Combine 消息处理程序


void Combine::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString s;
	s.Format(_T("%d"), x);
	s2 = s1 + s;
	UpdateData(false);

}
