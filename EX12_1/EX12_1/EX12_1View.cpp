
// EX12_1View.cpp : CEX12_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX12_1.h"
#endif

#include "EX12_1Doc.h"
#include "EX12_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_1View

IMPLEMENT_DYNCREATE(CEX12_1View, CView)

BEGIN_MESSAGE_MAP(CEX12_1View, CView)
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEX12_1View 构造/析构

CEX12_1View::CEX12_1View()
{
	// TODO: 在此处添加构造代码

}

CEX12_1View::~CEX12_1View()
{
}

BOOL CEX12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX12_1View 绘制

void CEX12_1View::OnDraw(CDC* pDC)
{
	CEX12_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->Rectangle(xu,yu,xd,yd);

}


// CEX12_1View 诊断

#ifdef _DEBUG
void CEX12_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_1Doc* CEX12_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_1Doc)));
	return (CEX12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_1View 消息处理程序


void CEX12_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p = point;
	W = 100, L = 50;
	xu = p.x; yu = p.y;
	xd = xu + W; yd = yu + L;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}




void CEX12_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect cr(50,50,150,100);
	dc.Rectangle(cr);
	CView::OnRButtonDown(nFlags, point);
}
