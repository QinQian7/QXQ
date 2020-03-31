
// EX5View.cpp : CEX5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX5.h"
#endif

#include "EX5Doc.h"
#include "EX5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX5View

IMPLEMENT_DYNCREATE(CEX5View, CView)

BEGIN_MESSAGE_MAP(CEX5View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEX5View ����/����

CEX5View::CEX5View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX5View::~CEX5View()
{
}

BOOL CEX5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX5View ����

void CEX5View::OnDraw(CDC* pDC)
{
	CEX5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	s.Format(_T("(%d,%d)"), pDoc->a.x, pDoc->a.y);
	pDC->TextOutW(100, 100, s);
	pDC->Rectangle(pDoc->cr);
	
}


// CEX5View ��ӡ

BOOL CEX5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX5View ���

#ifdef _DEBUG
void CEX5View::AssertValid() const
{
	CView::AssertValid();
}

void CEX5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX5Doc* CEX5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX5Doc)));
	return (CEX5Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX5View ��Ϣ�������


void CEX5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX5Doc* pDoc = GetDocument();
	pDoc->b.x = point.x;
	pDoc->b.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CEX5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX5Doc* pDoc = GetDocument();
	pDoc->cr.left = pDoc->b.x;
	pDoc->cr.top = pDoc->b.y;
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CEX5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX5Doc* pDoc = GetDocument();
	pDoc->a = point;
	InvalidateRect(NULL, FALSE);

	CView::OnMouseMove(nFlags, point);
}
