
// EX1_1View.cpp : CEX1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX1_1.h"
#endif

#include "EX1_1Doc.h"
#include "EX1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX1_1View

IMPLEMENT_DYNCREATE(CEX1_1View, CView)

BEGIN_MESSAGE_MAP(CEX1_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX1_1View ����/����

CEX1_1View::CEX1_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX1_1View::~CEX1_1View()
{
}

BOOL CEX1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX1_1View ����

void CEX1_1View::OnDraw(CDC* pDC)
{
	CEX1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CEX1_1View ��ӡ

BOOL CEX1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX1_1View ���

#ifdef _DEBUG
void CEX1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX1_1Doc* CEX1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX1_1Doc)));
	return (CEX1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX1_1View ��Ϣ�������


void CEX1_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 300 + 100;
	CRect rc(point.x-r,point.y-r,point.x+r,point.y+r);
	CClientDC dc(this);
	dc.Ellipse(rc);
	
	CView::OnLButtonDown(nFlags, point);
}
