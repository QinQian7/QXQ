
// EX10_1View.cpp : CEX10_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX10_1.h"
#endif

#include "EX10_1Doc.h"
#include "EX10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX10_1View

IMPLEMENT_DYNCREATE(CEX10_1View, CView)

BEGIN_MESSAGE_MAP(CEX10_1View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CEX10_1View 构造/析构

CEX10_1View::CEX10_1View()
{
	// TODO: 在此处添加构造代码

}

CEX10_1View::~CEX10_1View()
{
}

BOOL CEX10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX10_1View 绘制

void CEX10_1View::OnDraw(CDC* pDC)
{
	CEX10_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(90, 90, 380, 130);
	pDC->TextOutW(100, 100, str);

}


// CEX10_1View 诊断

#ifdef _DEBUG
void CEX10_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX10_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX10_1Doc* CEX10_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX10_1Doc)));
	return (CEX10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX10_1View 消息处理程序


void CEX10_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CCHAR c;
	CString s;
	c = nChar;
	s.Format(_T("%c"),c);
	str += s;
	
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
