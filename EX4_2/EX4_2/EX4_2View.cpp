
// EX4_2View.cpp : CEX4_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX4_2.h"
#endif

#include "EX4_2Doc.h"
#include "EX4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX4_2View

IMPLEMENT_DYNCREATE(CEX4_2View, CView)

BEGIN_MESSAGE_MAP(CEX4_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX4_2View ����/����

CEX4_2View::CEX4_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX4_2View::~CEX4_2View()
{
}

BOOL CEX4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX4_2View ����

void CEX4_2View::OnDraw(CDC* /*pDC*/)
{
	CEX4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX4_2View ��ӡ

BOOL CEX4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX4_2View ���

#ifdef _DEBUG
void CEX4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX4_2Doc* CEX4_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX4_2Doc)));
	return (CEX4_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX4_2View ��Ϣ�������


void CEX4_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX4_2Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->A + pDoc->B);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}
