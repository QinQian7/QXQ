
// EX1_3View.cpp : CEX1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX1_3.h"
#endif

#include "EX1_3Doc.h"
#include "EX1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX1_3View

IMPLEMENT_DYNCREATE(CEX1_3View, CView)

BEGIN_MESSAGE_MAP(CEX1_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX1_3View ����/����

CEX1_3View::CEX1_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX1_3View::~CEX1_3View()
{
}

BOOL CEX1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX1_3View ����

void CEX1_3View::OnDraw(CDC* /*pDC*/)
{
	CEX1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX1_3View ��ӡ

BOOL CEX1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX1_3View ���

#ifdef _DEBUG
void CEX1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX1_3Doc* CEX1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX1_3Doc)));
	return (CEX1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX1_3View ��Ϣ�������


void CEX1_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	dc.Ellipse(cr);

	CView::OnLButtonDown(nFlags, point);
}
