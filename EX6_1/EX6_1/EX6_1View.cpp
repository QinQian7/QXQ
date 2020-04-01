
// EX6_1View.cpp : CEX6_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX6_1.h"
#endif

#include "EX6_1Doc.h"
#include "EX6_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX6_1View

IMPLEMENT_DYNCREATE(CEX6_1View, CView)

BEGIN_MESSAGE_MAP(CEX6_1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEX6_1View ����/����

CEX6_1View::CEX6_1View()
{
	// TODO: �ڴ˴���ӹ������
	m = 0;
	n = 0;

}

CEX6_1View::~CEX6_1View()
{
}

BOOL CEX6_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX6_1View ����

void CEX6_1View::OnDraw(CDC* pDC)
{
	CEX6_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	CString s;
	if (m > 0)
	{
        s.Format(_T("MouseMove������%d�Σ������ƶ�%d�����ط���һ��"), m, n / m);
        pDC->TextOutW(300, 100, s);
	}	
	else
	{
		s.Format(_T("���ƶ����"));
		pDC->TextOutW(300, 100, s);
	}	
	m = pDoc->count;

}


// CEX6_1View ���

#ifdef _DEBUG
void CEX6_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX6_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX6_1Doc* CEX6_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX6_1Doc)));
	return (CEX6_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX6_1View ��Ϣ�������

void CEX6_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if (nFlags&MK_LBUTTON)
		m++;

	CView::OnMouseMove(nFlags, point);
}

void CEX6_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	a.x = point.x;

	CView::OnLButtonDown(nFlags, point);
}


void CEX6_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (a.x > point.x)
		n = a.x - point.x;
	else
		n = point.x - a.x;
	Invalidate();
	
	CView::OnLButtonUp(nFlags, point);
}


