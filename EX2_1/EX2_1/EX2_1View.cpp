
// EX2_1View.cpp : CEX2_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX2_1.h"
#endif

#include "EX2_1Doc.h"
#include "EX2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX2_1View

IMPLEMENT_DYNCREATE(CEX2_1View, CView)

BEGIN_MESSAGE_MAP(CEX2_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CEX2_1View ����/����

CEX2_1View::CEX2_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX2_1View::~CEX2_1View()
{
}

BOOL CEX2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX2_1View ����

void CEX2_1View::OnDraw(CDC* pDC)
{
	CEX2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s = _T("����Сٻ ");
	int a = 20;
	s.Format(s+"%d",a);
	pDC->TextOutW(200,200,s);
}


// CEX2_1View ��ӡ

BOOL CEX2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX2_1View ���

#ifdef _DEBUG
void CEX2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX2_1Doc* CEX2_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX2_1Doc)));
	return (CEX2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX2_1View ��Ϣ�������
