
// EX3_1View.cpp : CEX3_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX3_1.h"
#endif

#include "EX3_1Doc.h"
#include "EX3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX3_1View

IMPLEMENT_DYNCREATE(CEX3_1View, CView)

BEGIN_MESSAGE_MAP(CEX3_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX3_1View ����/����

CEX3_1View::CEX3_1View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);

}

CEX3_1View::~CEX3_1View()
{
}

BOOL CEX3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX3_1View ����

void CEX3_1View::OnDraw(CDC* pDC)
{
	CEX3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca[i]);

}


// CEX3_1View ��ӡ

BOOL CEX3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX3_1View ���

#ifdef _DEBUG
void CEX3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX3_1Doc* CEX3_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX3_1Doc)));
	return (CEX3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX3_1View ��Ϣ�������


void CEX3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rc;
	this->GetClientRect(&rc);
	CRect cr(0,0,rc.bottom,rc.bottom);
    ca.Add(cr);
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
