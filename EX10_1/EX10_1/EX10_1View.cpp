
// EX10_1View.cpp : CEX10_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX10_1.h"
#endif

#include "EX10_1Doc.h"
#include "EX10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX10_1View

IMPLEMENT_DYNCREATE(CEX10_1View, CView)

BEGIN_MESSAGE_MAP(CEX10_1View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CEX10_1View ����/����

CEX10_1View::CEX10_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX10_1View::~CEX10_1View()
{
}

BOOL CEX10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX10_1View ����

void CEX10_1View::OnDraw(CDC* pDC)
{
	CEX10_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(90, 90, 380, 130);
	pDC->TextOutW(100, 100, str);

}


// CEX10_1View ���

#ifdef _DEBUG
void CEX10_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX10_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX10_1Doc* CEX10_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX10_1Doc)));
	return (CEX10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX10_1View ��Ϣ�������


void CEX10_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CCHAR c;
	CString s;
	c = nChar;
	s.Format(_T("%c"),c);
	str += s;
	
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
