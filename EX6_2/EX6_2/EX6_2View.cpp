
// EX6_2View.cpp : CEX6_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX6_2.h"
#endif

#include "EX6_2Doc.h"
#include "EX6_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX6_2View

IMPLEMENT_DYNCREATE(CEX6_2View, CView)

BEGIN_MESSAGE_MAP(CEX6_2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX6_2View ����/����

CEX6_2View::CEX6_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX6_2View::~CEX6_2View()
{
}

BOOL CEX6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX6_2View ����

void CEX6_2View::OnDraw(CDC* pDC)
{
	CEX6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->A);
}


// CEX6_2View ���

#ifdef _DEBUG
void CEX6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX6_2Doc* CEX6_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX6_2Doc)));
	return (CEX6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX6_2View ��Ϣ�������





void CEX6_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX6_2Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);

	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->A.left > cr.left )
		{
			pDoc->A.left -= 5;
			pDoc->A.right -= 5;
		}
		break;
	case VK_RIGHT:
		if(pDoc->A.right < cr.right)
		{
			pDoc->A.left += 5;
			pDoc->A.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->A.top > cr.top)
		{
			pDoc->A.top -= 5;
			pDoc->A.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->A.bottom <cr.bottom )
		{
			pDoc->A.bottom += 5;
			pDoc->A.top += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->A.left > cr.left && pDoc->A.top > cr.top)
		{
			pDoc->A.left -= 5;
			pDoc->A.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->A.left < pDoc->A.right && pDoc->A.top < pDoc->A.bottom)
		{
			pDoc->A.left += 5;
			pDoc->A.top += 5;
		}
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CEX6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX6_2Doc* pDoc = GetDocument();
	pDoc->A.left = 600; pDoc->A.right = 650;
	pDoc->A.top = 400; pDoc->A.bottom = 450;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
