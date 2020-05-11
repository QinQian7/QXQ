
// EX8_3View.cpp : CEX8_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX8_3.h"
#endif

#include "EX8_3Doc.h"
#include "EX8_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX8_3View

IMPLEMENT_DYNCREATE(CEX8_3View, CView)

BEGIN_MESSAGE_MAP(CEX8_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DrawLine, &CEX8_3View::OnDrawline)
	ON_COMMAND(ID_DrawRectangle, &CEX8_3View::OnDrawrectangle)
	ON_COMMAND(ID_DrawEllipse, &CEX8_3View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEX8_3View 构造/析构

CEX8_3View::CEX8_3View()
{
	// TODO: 在此处添加构造代码

}

CEX8_3View::~CEX8_3View()
{
}

BOOL CEX8_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX8_3View 绘制

void CEX8_3View::OnDraw(CDC* pDC)
{
	CEX8_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码


}


// CEX8_3View 打印

BOOL CEX8_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEX8_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEX8_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEX8_3View 诊断

#ifdef _DEBUG
void CEX8_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX8_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX8_3Doc* CEX8_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX8_3Doc)));
	return (CEX8_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX8_3View 消息处理程序


void CEX8_3View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	set = 1;
}


void CEX8_3View::OnDrawrectangle()
{
	// TODO: 在此添加命令处理程序代码
	set = 2;

}


void CEX8_3View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	set = 3;
}


void CEX8_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX8_3Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;


	CView::OnLButtonDown(nFlags, point);
}


void CEX8_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX8_3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CRect cr(pDoc->a.x, pDoc->a.y, point.x, point.y);
	switch (set)
	{
	    case 1:
		    dc.MoveTo(pDoc->a.x, pDoc->a.y);
		    dc.LineTo(point.x, point.y);
		    break;
		case 2:
			dc.Rectangle(cr);
			break;
		case 3:
			dc.Ellipse(cr);
			break;
		
	}
	

	CView::OnLButtonUp(nFlags, point);
}
