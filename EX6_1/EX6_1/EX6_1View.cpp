
// EX6_1View.cpp : CEX6_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX6_1.h"
#endif

#include "EX6_1Doc.h"
#include "EX6_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX6_1View

IMPLEMENT_DYNCREATE(CEX6_1View, CView)

BEGIN_MESSAGE_MAP(CEX6_1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEX6_1View 构造/析构

CEX6_1View::CEX6_1View()
{
	// TODO: 在此处添加构造代码
	m = 0;
	n = 0;

}

CEX6_1View::~CEX6_1View()
{
}

BOOL CEX6_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX6_1View 绘制

void CEX6_1View::OnDraw(CDC* pDC)
{
	CEX6_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	CString s;
	if (m > 0)
	{
        s.Format(_T("MouseMove发生了%d次，横向移动%d个像素发生一次"), m, n / m);
        pDC->TextOutW(300, 100, s);
	}	
	else
	{
		s.Format(_T("请移动鼠标"));
		pDC->TextOutW(300, 100, s);
	}	
	m = pDoc->count;

}


// CEX6_1View 诊断

#ifdef _DEBUG
void CEX6_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX6_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX6_1Doc* CEX6_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX6_1Doc)));
	return (CEX6_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX6_1View 消息处理程序

void CEX6_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if (nFlags&MK_LBUTTON)
		m++;

	CView::OnMouseMove(nFlags, point);
}

void CEX6_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	a.x = point.x;

	CView::OnLButtonDown(nFlags, point);
}


void CEX6_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (a.x > point.x)
		n = a.x - point.x;
	else
		n = point.x - a.x;
	Invalidate();
	
	CView::OnLButtonUp(nFlags, point);
}


