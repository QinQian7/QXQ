
// EX1_4View.cpp : CEX1_4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX1_4.h"
#endif

#include "EX1_4Doc.h"
#include "EX1_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX1_4View

IMPLEMENT_DYNCREATE(CEX1_4View, CView)

BEGIN_MESSAGE_MAP(CEX1_4View, CView)
END_MESSAGE_MAP()

// CEX1_4View ����/����

CEX1_4View::CEX1_4View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX1_4View::~CEX1_4View()
{
}

BOOL CEX1_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX1_4View ����

void CEX1_4View::OnDraw(CDC* /*pDC*/)
{
	CEX1_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	CBrush newbrush(RGB(200, 200, 300));
	CBrush *oldbrush;
	oldbrush = dc.SelectObject(&newbrush);
	dc.Ellipse(cr);
	dc.SelectObject(oldbrush);
}


// CEX1_4View ���

#ifdef _DEBUG
void CEX1_4View::AssertValid() const
{
	CView::AssertValid();
}

void CEX1_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX1_4Doc* CEX1_4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX1_4Doc)));
	return (CEX1_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX1_4View ��Ϣ�������
