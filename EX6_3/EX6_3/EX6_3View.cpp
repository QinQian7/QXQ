
// EX6_3View.cpp : CEX6_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX6_3.h"
#endif

#include "EX6_3Doc.h"
#include "EX6_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX6_3View

IMPLEMENT_DYNCREATE(CEX6_3View, CView)

BEGIN_MESSAGE_MAP(CEX6_3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEX6_3View ����/����

CEX6_3View::CEX6_3View()
{
	// TODO: �ڴ˴���ӹ������
	set = true; r = 0; l = 0;
	a.left = 300;  a.right = 350;
	a.top = 100;  a.bottom = 150;
}

CEX6_3View::~CEX6_3View()
{
}

BOOL CEX6_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX6_3View ����

void CEX6_3View::OnDraw(CDC* pDC)
{
	CEX6_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	GetClientRect(&cr);
	if (set)
	{
		SetTimer(1, 200, NULL);
		a.top += r;
		a.bottom += r;
		pDC->Ellipse(a.left, a.top, a.right, a.bottom);
	}
	else 
		KillTimer(1);
	if (!set)
	{
		SetTimer(2, 200, NULL);
		a.top -= r;
		a.bottom -= r;
		pDC->Ellipse(a.left,a.top,a.right,a.bottom);
	}
	else KillTimer(2);

}


// CEX6_3View ���

#ifdef _DEBUG
void CEX6_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX6_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX6_3Doc* CEX6_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX6_3Doc)));
	return (CEX6_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX6_3View ��Ϣ�������


void CEX6_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent)
	{
	case 1:
		if (a.bottom < cr.bottom)
		{
			r = 15;
		}
		else set = false;
		break;
	case 2:
		if (a.top > cr.top)
		{
			l = 15;
		}
		else set = true;
		break;
	}
	Invalidate();


	
	
	CView::OnTimer(nIDEvent);
}
