
// EX2_3View.cpp : CEX2_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX2_3.h"
#endif

#include "EX2_3Doc.h"
#include "EX2_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX2_3View

IMPLEMENT_DYNCREATE(CEX2_3View, CView)

BEGIN_MESSAGE_MAP(CEX2_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEX2_3View ����/����

CEX2_3View::CEX2_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX2_3View::~CEX2_3View()
{
}

BOOL CEX2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX2_3View ����

void CEX2_3View::OnDraw(CDC* /*pDC*/)
{
	CEX2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX2_3View ��ӡ

BOOL CEX2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX2_3View ���

#ifdef _DEBUG
void CEX2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX2_3Doc* CEX2_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX2_3Doc)));
	return (CEX2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX2_3View ��Ϣ�������


void CEX2_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX2_3Doc* pDoc = GetDocument();
	pDoc->count++;

	CView::OnLButtonDown(nFlags, point);
}


void CEX2_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEX2_3Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(200,200,s);

	CView::OnRButtonDown(nFlags, point);
}
