
// EX11_2View.cpp : CEX11_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX11_2.h"
#endif

#include "EX11_2Doc.h"
#include "EX11_2View.h"
#include "Change.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX11_2View

IMPLEMENT_DYNCREATE(CEX11_2View, CView)

BEGIN_MESSAGE_MAP(CEX11_2View, CView)
	ON_COMMAND(ID_POPOUT, &CEX11_2View::OnPopout)
END_MESSAGE_MAP()

// CEX11_2View ����/����

CEX11_2View::CEX11_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX11_2View::~CEX11_2View()
{
}

BOOL CEX11_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX11_2View ����

void CEX11_2View::OnDraw(CDC* /*pDC*/)
{
	CEX11_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX11_2View ���

#ifdef _DEBUG
void CEX11_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX11_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX11_2Doc* CEX11_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX11_2Doc)));
	return (CEX11_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX11_2View ��Ϣ�������


void CEX11_2View::OnPopout()
{
	// TODO: �ڴ���������������
	Change dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
