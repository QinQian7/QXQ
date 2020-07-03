
// EX11_1View.cpp : CEX11_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX11_1.h"
#endif

#include "EX11_1Doc.h"
#include "EX11_1View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX11_1View

IMPLEMENT_DYNCREATE(CEX11_1View, CView)

BEGIN_MESSAGE_MAP(CEX11_1View, CView)
	ON_COMMAND(ID_POPOUT, &CEX11_1View::OnPopout)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SHOWHIDE, &CEX11_1View::OnShowhide)
END_MESSAGE_MAP()

// CEX11_1View ����/����

CEX11_1View::CEX11_1View()
{
	// TODO: �ڴ˴���ӹ������
	show_hide = 1;
	pD = NULL;
}

CEX11_1View::~CEX11_1View()
{
}

BOOL CEX11_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX11_1View ����

void CEX11_1View::OnDraw(CDC* /*pDC*/)
{
	CEX11_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX11_1View ���

#ifdef _DEBUG
void CEX11_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX11_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX11_1Doc* CEX11_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX11_1Doc)));
	return (CEX11_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX11_1View ��Ϣ�������


void CEX11_1View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		
		CString str = _T("�����˳��Ի���");
		GetDC()->TextOutW(300, 100, str);

	}


}


void CEX11_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	pD=new MyDlg0;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);

	CView::OnLButtonDblClk(nFlags, point);
}


void CEX11_1View::OnShowhide()
{
	// TODO: �ڴ���������������
	if (show_hide == 1)
		show_hide = 0;
	else
		show_hide = 1;
	pD->ShowWindow(show_hide);
}
