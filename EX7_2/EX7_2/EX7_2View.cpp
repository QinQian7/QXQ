
// EX7_2View.cpp : CEX7_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX7_2.h"
#endif

#include "EX7_2Doc.h"
#include "EX7_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX7_2View

IMPLEMENT_DYNCREATE(CEX7_2View, CView)

BEGIN_MESSAGE_MAP(CEX7_2View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEX7_2View ����/����

CEX7_2View::CEX7_2View()
{
	// TODO: �ڴ˴���ӹ������
	t = 0;
	set = true;

}

CEX7_2View::~CEX7_2View()
{
}

BOOL CEX7_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX7_2View ����

void CEX7_2View::OnDraw(CDC* pDC)
{
	CEX7_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	CPoint a;
	CBrush cb;
	CRgn rgn;
	
	GetClientRect(&cr);
	a = cr.CenterPoint();
	cr.left = a.x - 15;  cr.right = a.x + 15;
	cr.top = a.y - 15;  cr.bottom = a.y + 15;
	SetTimer(1, 500, NULL);
	if (set)
	{
		cr.left -= t;  cr.right += t;
		cr.top -= t;  cr.bottom += t;
		cb.CreateSolidBrush(RGB(rand() % 225, rand() % 225, rand() % 225));
		rgn.CreateEllipticRgn(cr.left,cr.top,cr.right,cr.bottom);
		pDC->FillRgn(&rgn,&cb);

	}
}


// CEX7_2View ���

#ifdef _DEBUG
void CEX7_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX7_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX7_2Doc* CEX7_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX7_2Doc)));
	return (CEX7_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX7_2View ��Ϣ�������


void CEX7_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	t += 5;
	Invalidate();

	CView::OnTimer(nIDEvent);
}
