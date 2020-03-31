
// EX2_2View.cpp : CEX2_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX2_2.h"
#endif

#include "EX2_2Doc.h"
#include "EX2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX2_2View

IMPLEMENT_DYNCREATE(CEX2_2View, CView)

BEGIN_MESSAGE_MAP(CEX2_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CEX2_2View ����/����

CEX2_2View::CEX2_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX2_2View::~CEX2_2View()
{
}

BOOL CEX2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX2_2View ����

void CEX2_2View::OnDraw(CDC* pDC)
{
	CEX2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDoc->s.Format(pDoc->s+"%d",pDoc->a);
	pDC->TextOutW(200, 200, pDoc->s);
}


// CEX2_2View ��ӡ

BOOL CEX2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX2_2View ���

#ifdef _DEBUG
void CEX2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX2_2Doc* CEX2_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX2_2Doc)));
	return (CEX2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX2_2View ��Ϣ�������
