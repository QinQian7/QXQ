
// EX3_2View.cpp : CEX3_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX3_2.h"
#endif

#include "EX3_2Doc.h"
#include "EX3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX3_2View

IMPLEMENT_DYNCREATE(CEX3_2View, CView)

BEGIN_MESSAGE_MAP(CEX3_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX3_2View ����/����

CEX3_2View::CEX3_2View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);

}

CEX3_2View::~CEX3_2View()
{
}

BOOL CEX3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX3_2View ����

void CEX3_2View::OnDraw(CDC* pDC)
{
	CEX3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca[i]);
}


// CEX3_2View ��ӡ

BOOL CEX3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX3_2View ���

#ifdef _DEBUG
void CEX3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX3_2Doc* CEX3_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX3_2Doc)));
	return (CEX3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX3_2View ��Ϣ�������


void CEX3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 50 + 10;
	int b = rand() % 50 + 30;
	if (a != b || a<b)
	{
		CRect rc(point.x - b, point.y - a, point.x + b, point.y + a);
		ca.Add(rc);
	}
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
