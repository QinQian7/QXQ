
// EX12_1View.cpp : CEX12_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX12_1.h"
#endif

#include "EX12_1Doc.h"
#include "EX12_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_1View

IMPLEMENT_DYNCREATE(CEX12_1View, CView)

BEGIN_MESSAGE_MAP(CEX12_1View, CView)
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEX12_1View ����/����

CEX12_1View::CEX12_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX12_1View::~CEX12_1View()
{
}

BOOL CEX12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX12_1View ����

void CEX12_1View::OnDraw(CDC* pDC)
{
	CEX12_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->Rectangle(xu,yu,xd,yd);

}


// CEX12_1View ���

#ifdef _DEBUG
void CEX12_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_1Doc* CEX12_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_1Doc)));
	return (CEX12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_1View ��Ϣ�������


void CEX12_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p = point;
	W = 100, L = 50;
	xu = p.x; yu = p.y;
	xd = xu + W; yd = yu + L;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}




void CEX12_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect cr(50,50,150,100);
	dc.Rectangle(cr);
	CView::OnRButtonDown(nFlags, point);
}
