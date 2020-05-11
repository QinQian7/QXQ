
// EX7_1View.cpp : CEX7_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX7_1.h"
#endif

#include "EX7_1Doc.h"
#include "EX7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX7_1View

IMPLEMENT_DYNCREATE(CEX7_1View, CView)

BEGIN_MESSAGE_MAP(CEX7_1View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CEX7_1View 构造/析构

CEX7_1View::CEX7_1View()
{
	// TODO: 在此处添加构造代码
	 t = 0;
	 set = true;

}

CEX7_1View::~CEX7_1View()
{
}

BOOL CEX7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX7_1View 绘制

void CEX7_1View::OnDraw(CDC* pDC)
{
	CEX7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	CPoint a;
	GetClientRect(&cr);
	a = cr.CenterPoint();
	cr.left = a.x - 15;  cr.right = a.x + 15;
	cr.top = a.y - 15;  cr.bottom = a.y + 15;
	SetTimer(1,500,NULL);
	if (set)
	{
		cr.left -= t;  cr.right += t;
		cr.top -= t;  cr.bottom += t;
		pDC->Ellipse(cr.left, cr.top, cr.right, cr.bottom);
	}
}


// CEX7_1View 诊断

#ifdef _DEBUG
void CEX7_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX7_1Doc* CEX7_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX7_1Doc)));
	return (CEX7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX7_1View 消息处理程序


void CEX7_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	t += 5;
	Invalidate();

	CView::OnTimer(nIDEvent);
}
