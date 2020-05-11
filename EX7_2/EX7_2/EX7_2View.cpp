
// EX7_2View.cpp : CEX7_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX7_2.h"
#endif

#include "EX7_2Doc.h"
#include "EX7_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX7_2View

IMPLEMENT_DYNCREATE(CEX7_2View, CView)

BEGIN_MESSAGE_MAP(CEX7_2View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEX7_2View 构造/析构

CEX7_2View::CEX7_2View()
{
	// TODO: 在此处添加构造代码
	t = 0;
	set = true;

}

CEX7_2View::~CEX7_2View()
{
}

BOOL CEX7_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX7_2View 绘制

void CEX7_2View::OnDraw(CDC* pDC)
{
	CEX7_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	CPoint a;
	CBrush cb;
	CRgn rgn;
	
	GetClientRect(&cr);
	a = cr.CenterPoint();
	cr.left = a.x - 15;  cr.right = a.x + 15;
	cr.top = a.y - 15;  cr.bottom = a.y + 15;
	SetTimer(1, 500, NULL);
	if (set)
	{
		cr.left -= t;  cr.right += t;
		cr.top -= t;  cr.bottom += t;
		cb.CreateSolidBrush(RGB(rand() % 225, rand() % 225, rand() % 225));
		rgn.CreateEllipticRgn(cr.left,cr.top,cr.right,cr.bottom);
		pDC->FillRgn(&rgn,&cb);

	}
}


// CEX7_2View 诊断

#ifdef _DEBUG
void CEX7_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX7_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX7_2Doc* CEX7_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX7_2Doc)));
	return (CEX7_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX7_2View 消息处理程序


void CEX7_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	t += 5;
	Invalidate();

	CView::OnTimer(nIDEvent);
}
