
// EX12_2View.cpp : CEX12_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX12_2.h"
#endif

#include "EX12_2Doc.h"
#include "EX12_2View.h"
#include "Plus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_2View

IMPLEMENT_DYNCREATE(CEX12_2View, CView)

BEGIN_MESSAGE_MAP(CEX12_2View, CView)
	ON_COMMAND(ID_POPOUT, &CEX12_2View::OnPopout)
END_MESSAGE_MAP()

// CEX12_2View ����/����

CEX12_2View::CEX12_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX12_2View::~CEX12_2View()
{
}

BOOL CEX12_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX12_2View ����

void CEX12_2View::OnDraw(CDC* /*pDC*/)
{
	CEX12_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX12_2View ���

#ifdef _DEBUG
void CEX12_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_2Doc* CEX12_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_2Doc)));
	return (CEX12_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_2View ��Ϣ�������


void CEX12_2View::OnPopout()
{
	// TODO: �ڴ���������������
	Plus dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		int X, Y, R;
		
		X = dlg.x;
		Y = dlg.y;
	}

}
