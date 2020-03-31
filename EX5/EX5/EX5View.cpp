
// EX5View.cpp : CEX5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX5.h"
#endif

#include "EX5Doc.h"
#include "EX5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX5View

IMPLEMENT_DYNCREATE(CEX5View, CView)

BEGIN_MESSAGE_MAP(CEX5View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEX5View 构造/析构

CEX5View::CEX5View()
{
	// TODO: 在此处添加构造代码

}

CEX5View::~CEX5View()
{
}

BOOL CEX5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX5View 绘制

void CEX5View::OnDraw(CDC* pDC)
{
	CEX5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	s.Format(_T("(%d,%d)"), pDoc->a.x, pDoc->a.y);
	pDC->TextOutW(100, 100, s);
	pDC->Rectangle(pDoc->cr);
	
}


// CEX5View 打印

BOOL CEX5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEX5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEX5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEX5View 诊断

#ifdef _DEBUG
void CEX5View::AssertValid() const
{
	CView::AssertValid();
}

void CEX5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX5Doc* CEX5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX5Doc)));
	return (CEX5Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX5View 消息处理程序


void CEX5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX5Doc* pDoc = GetDocument();
	pDoc->b.x = point.x;
	pDoc->b.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CEX5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX5Doc* pDoc = GetDocument();
	pDoc->cr.left = pDoc->b.x;
	pDoc->cr.top = pDoc->b.y;
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CEX5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX5Doc* pDoc = GetDocument();
	pDoc->a = point;
	InvalidateRect(NULL, FALSE);

	CView::OnMouseMove(nFlags, point);
}
