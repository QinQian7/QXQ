// Plus.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EX12_2.h"
#include "Plus.h"
#include "afxdialogex.h"


// Plus �Ի���

IMPLEMENT_DYNAMIC(Plus, CDialogEx)

Plus::Plus(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

Plus::~Plus()
{
}

void Plus::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, r);
}


BEGIN_MESSAGE_MAP(Plus, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON1, &Plus::OnBnClickedButton1)
END_MESSAGE_MAP()


// Plus ��Ϣ�������





void Plus::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);
}
