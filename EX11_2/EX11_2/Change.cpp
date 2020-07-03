// Change.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EX11_2.h"
#include "Change.h"
#include "afxdialogex.h"


// Change �Ի���

IMPLEMENT_DYNAMIC(Change, CDialogEx)

Change::Change(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, str1(_T(""))
	, str2(_T(""))
{

}

Change::~Change()
{
}

void Change::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str1);
	DDX_Text(pDX, IDC_EDIT2, str2);
	
}


BEGIN_MESSAGE_MAP(Change, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON1, &Change::OnBnClickedButton1)
END_MESSAGE_MAP()


// Change ��Ϣ�������



void Change::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->UpdateData(true);
	s1 = str1;
	s2 = str2;
	str1 = s2;
	str2 = s1;
	UpdateData(false);
}
