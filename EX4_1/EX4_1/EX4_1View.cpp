
// EX4_1View.cpp : CEX4_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX4_1.h"
#endif

#include "EX4_1Doc.h"
#include "EX4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX4_1View

IMPLEMENT_DYNCREATE(CEX4_1View, CView)

BEGIN_MESSAGE_MAP(CEX4_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEX4_1View ����/����

CEX4_1View::CEX4_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX4_1View::~CEX4_1View()
{
}

BOOL CEX4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX4_1View ����

void CEX4_1View::OnDraw(CDC* /*pDC*/)
{
	CEX4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX4_1View ��ӡ

BOOL CEX4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX4_1View ���

#ifdef _DEBUG
void CEX4_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX4_1Doc* CEX4_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX4_1Doc)));
	return (CEX4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX4_1View ��Ϣ�������


void CEX4_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�����������");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}


void CEX4_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonUp(nFlags, point);
}
