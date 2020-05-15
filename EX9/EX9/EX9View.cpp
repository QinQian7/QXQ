
// EX9View.cpp : CEX9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "EX9.h"
#endif

#include "EX9Doc.h"
#include "EX9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX9View

IMPLEMENT_DYNCREATE(CEX9View, CView)

BEGIN_MESSAGE_MAP(CEX9View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CEX9View::OnFileOpen)
END_MESSAGE_MAP()

// CEX9View ����/����

CEX9View::CEX9View()
{
	// TODO: �ڴ˴���ӹ������

}

CEX9View::~CEX9View()
{
}

BOOL CEX9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX9View ����

void CEX9View::OnDraw(CDC* pDC)
{
	CEX9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPoint c;
	CRect cr;
	GetClientRect(&cr);
	c = cr.CenterPoint();
	
	if (a==IDOK) 
	{
	    img.Draw(pDC->m_hDC, c.x - img.GetWidth() / 2, c.y - img.GetHeight() / 2, img.GetWidth(), img.GetHeight());
	}
	
}


// CEX9View ���

#ifdef _DEBUG
void CEX9View::AssertValid() const
{
	CView::AssertValid();
}

void CEX9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX9Doc* CEX9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX9Doc)));
	return (CEX9Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX9View ��Ϣ�������


void CEX9View::OnFileOpen()
{
	// TODO: �ڴ���������������


	CFileDialog cfd(true);
	 a = cfd.DoModal();
	 if (a == IDOK)
	filename = cfd.GetPathName();
	img.Load(filename);
	Invalidate();
}
