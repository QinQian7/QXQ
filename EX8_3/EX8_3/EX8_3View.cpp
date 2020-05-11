
// EX8_3View.cpp : CEX8_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX8_3.h"
#endif

#include "EX8_3Doc.h"
#include "EX8_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX8_3View

IMPLEMENT_DYNCREATE(CEX8_3View, CView)

BEGIN_MESSAGE_MAP(CEX8_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DrawLine, &CEX8_3View::OnDrawline)
	ON_COMMAND(ID_DrawRectangle, &CEX8_3View::OnDrawrectangle)
	ON_COMMAND(ID_DrawEllipse, &CEX8_3View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEX8_3View ����/����

CEX8_3View::CEX8_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX8_3View::~CEX8_3View()
{
}

BOOL CEX8_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX8_3View ����

void CEX8_3View::OnDraw(CDC* pDC)
{
	CEX8_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���


}


// CEX8_3View ��ӡ

BOOL CEX8_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX8_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX8_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX8_3View ���

#ifdef _DEBUG
void CEX8_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX8_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX8_3Doc* CEX8_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX8_3Doc)));
	return (CEX8_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX8_3View ��Ϣ�������


void CEX8_3View::OnDrawline()
{
	// TODO: �ڴ���������������
	set = 1;
}


void CEX8_3View::OnDrawrectangle()
{
	// TODO: �ڴ���������������
	set = 2;

}


void CEX8_3View::OnDrawellipse()
{
	// TODO: �ڴ���������������
	set = 3;
}


void CEX8_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX8_3Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CEX8_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX8_3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CRect cr(pDoc->a.x, pDoc->a.y, point.x, point.y);
	switch (set)
	{
	    case 1:
		    dc.MoveTo(pDoc->a.x, pDoc->a.y);
		    dc.LineTo(point.x, point.y);
		    break;
		case 2:
			dc.Rectangle(cr);
			break;
		case 3:
			dc.Ellipse(cr);
			break;
		
	}
	

	CView::OnLButtonUp(nFlags, point);
}
