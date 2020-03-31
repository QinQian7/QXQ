
// EX1_2View.cpp : CEX1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX1_2.h"
#endif

#include "EX1_2Doc.h"
#include "EX1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX1_2View

IMPLEMENT_DYNCREATE(CEX1_2View, CView)

BEGIN_MESSAGE_MAP(CEX1_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX1_2View ����/����

CEX1_2View::CEX1_2View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

CEX1_2View::~CEX1_2View()
{
}

BOOL CEX1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX1_2View ����

void CEX1_2View::OnDraw(CDC* pDC)
{
	CEX1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca[i]);
}


// CEX1_2View ��ӡ

BOOL CEX1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX1_2View ���

#ifdef _DEBUG
void CEX1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX1_2Doc* CEX1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX1_2Doc)));
	return (CEX1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX1_2View ��Ϣ�������


void CEX1_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	ca.Add(cr);
	this->Invalidate();


	CView::OnLButtonDown(nFlags, point);
}
