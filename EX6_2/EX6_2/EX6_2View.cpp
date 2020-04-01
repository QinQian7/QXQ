
// EX6_2View.cpp : CEX6_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX6_2.h"
#endif

#include "EX6_2Doc.h"
#include "EX6_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX6_2View

IMPLEMENT_DYNCREATE(CEX6_2View, CView)

BEGIN_MESSAGE_MAP(CEX6_2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CEX6_2View 构造/析构

CEX6_2View::CEX6_2View()
{
	// TODO: 在此处添加构造代码

}

CEX6_2View::~CEX6_2View()
{
}

BOOL CEX6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX6_2View 绘制

void CEX6_2View::OnDraw(CDC* pDC)
{
	CEX6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->A);
}


// CEX6_2View 诊断

#ifdef _DEBUG
void CEX6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX6_2Doc* CEX6_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX6_2Doc)));
	return (CEX6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX6_2View 消息处理程序





void CEX6_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX6_2Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);

	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->A.left > cr.left )
		{
			pDoc->A.left -= 5;
			pDoc->A.right -= 5;
		}
		break;
	case VK_RIGHT:
		if(pDoc->A.right < cr.right)
		{
			pDoc->A.left += 5;
			pDoc->A.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->A.top > cr.top)
		{
			pDoc->A.top -= 5;
			pDoc->A.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->A.bottom <cr.bottom )
		{
			pDoc->A.bottom += 5;
			pDoc->A.top += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->A.left > cr.left && pDoc->A.top > cr.top)
		{
			pDoc->A.left -= 5;
			pDoc->A.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->A.left < pDoc->A.right && pDoc->A.top < pDoc->A.bottom)
		{
			pDoc->A.left += 5;
			pDoc->A.top += 5;
		}
	}
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CEX6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX6_2Doc* pDoc = GetDocument();
	pDoc->A.left = 600; pDoc->A.right = 650;
	pDoc->A.top = 400; pDoc->A.bottom = 450;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
