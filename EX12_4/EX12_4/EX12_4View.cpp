
// EX12_4View.cpp : CEX12_4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX12_4.h"
#endif

#include "EX12_4Doc.h"
#include "EX12_4View.h"
#include "Combine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_4View

IMPLEMENT_DYNCREATE(CEX12_4View, CView)

BEGIN_MESSAGE_MAP(CEX12_4View, CView)
	ON_COMMAND(ID_POPOUT, &CEX12_4View::OnPopout)
END_MESSAGE_MAP()

// CEX12_4View ����/����

CEX12_4View::CEX12_4View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX12_4View::~CEX12_4View()
{
}

BOOL CEX12_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX12_4View ����

void CEX12_4View::OnDraw(CDC* /*pDC*/)
{
	CEX12_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX12_4View ���

#ifdef _DEBUG
void CEX12_4View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_4Doc* CEX12_4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_4Doc)));
	return (CEX12_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_4View ��Ϣ�������


void CEX12_4View::OnPopout()
{
	// TODO: �ڴ���������������
	Combine dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int X;
		CString S1, S2;		
		S1 = dlg.s1;
		X = dlg.x;
		S2 = dlg.s2;
	}
}
