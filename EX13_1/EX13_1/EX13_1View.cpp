
// EX13_1View.cpp : CEX13_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX13_1.h"
#endif

#include "EX13_1Doc.h"
#include "EX13_1View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX13_1View

IMPLEMENT_DYNCREATE(CEX13_1View, CView)

BEGIN_MESSAGE_MAP(CEX13_1View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &CEX13_1View::OnPopout)
END_MESSAGE_MAP()

// CEX13_1View ����/����

CEX13_1View::CEX13_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX13_1View::~CEX13_1View()
{
}

BOOL CEX13_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX13_1View ����

void CEX13_1View::OnDraw(CDC* /*pDC*/)
{
	CEX13_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX13_1View ���

#ifdef _DEBUG
void CEX13_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX13_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX13_1Doc* CEX13_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX13_1Doc)));
	return (CEX13_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX13_1View ��Ϣ�������


void CEX13_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}



void CEX13_1View::OnPopout()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString S;
		//S = dlg.s;
        //S= filename;
		dlg.s = filename;
	}
	
}
