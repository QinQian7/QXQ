
// EX1_4View.cpp : CEX1_4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX1_4.h"
#endif

#include "EX1_4Doc.h"
#include "EX1_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX1_4View

IMPLEMENT_DYNCREATE(CEX1_4View, CView)

BEGIN_MESSAGE_MAP(CEX1_4View, CView)
END_MESSAGE_MAP()

// CEX1_4View 构造/析构

CEX1_4View::CEX1_4View()
{
	// TODO: 在此处添加构造代码

}

CEX1_4View::~CEX1_4View()
{
}

BOOL CEX1_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX1_4View 绘制

void CEX1_4View::OnDraw(CDC* /*pDC*/)
{
	CEX1_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	CBrush newbrush(RGB(200, 200, 300));
	CBrush *oldbrush;
	oldbrush = dc.SelectObject(&newbrush);
	dc.Ellipse(cr);
	dc.SelectObject(oldbrush);
}


// CEX1_4View 诊断

#ifdef _DEBUG
void CEX1_4View::AssertValid() const
{
	CView::AssertValid();
}

void CEX1_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX1_4Doc* CEX1_4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX1_4Doc)));
	return (CEX1_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX1_4View 消息处理程序
