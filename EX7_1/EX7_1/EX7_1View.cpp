
// EX7_1View.cpp : CEX7_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX7_1.h"
#endif

#include "EX7_1Doc.h"
#include "EX7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX7_1View

IMPLEMENT_DYNCREATE(CEX7_1View, CView)

BEGIN_MESSAGE_MAP(CEX7_1View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEX7_1View ����/����

CEX7_1View::CEX7_1View()
{
	// TODO: �ڴ˴���ӹ������
	 t = 0;
	 set = true;

}

CEX7_1View::~CEX7_1View()
{
}

BOOL CEX7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX7_1View ����

void CEX7_1View::OnDraw(CDC* pDC)
{
	CEX7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	CPoint a;
	GetClientRect(&cr);
	a = cr.CenterPoint();
	cr.left = a.x - 15;  cr.right = a.x + 15;
	cr.top = a.y - 15;  cr.bottom = a.y + 15;
	SetTimer(1,500,NULL);
	if (set)
	{
		cr.left -= t;  cr.right += t;
		cr.top -= t;  cr.bottom += t;
		pDC->Ellipse(cr.left, cr.top, cr.right, cr.bottom);
	}
}


// CEX7_1View ���

#ifdef _DEBUG
void CEX7_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX7_1Doc* CEX7_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX7_1Doc)));
	return (CEX7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX7_1View ��Ϣ�������


void CEX7_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	t += 5;
	Invalidate();

	CView::OnTimer(nIDEvent);
}
