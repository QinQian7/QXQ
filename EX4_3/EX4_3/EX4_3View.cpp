
// EX4_3View.cpp : CEX4_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX4_3.h"
#endif

#include "EX4_3Doc.h"
#include "EX4_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX4_3View

IMPLEMENT_DYNCREATE(CEX4_3View, CView)

BEGIN_MESSAGE_MAP(CEX4_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
//	ON_COMMAND(ID_SHOWMUNBER, &CEX4_3View::OnShowmunber)
END_MESSAGE_MAP()

// CEX4_3View 构造/析构

CEX4_3View::CEX4_3View()
{
	// TODO: 在此处添加构造代码

}

CEX4_3View::~CEX4_3View()
{
}

BOOL CEX4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX4_3View 绘制

void CEX4_3View::OnDraw(CDC* pDC)
{
	CEX4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
}


// CEX4_3View 打印

BOOL CEX4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEX4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEX4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEX4_3View 诊断

#ifdef _DEBUG
void CEX4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CEX4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX4_3Doc* CEX4_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX4_3Doc)));
	return (CEX4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX4_3View 消息处理程序


void CEX4_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX4_3Doc* pDoc = GetDocument();
	pDoc->a = rand() % 20 + 5;
	pDoc->b = rand() % 20 + 10;
	m = pDoc->a;
	n = pDoc->b;
	CString a, b, s;
	a.Format(_T("%d"), pDoc->a);
	b.Format(_T("%d"), pDoc->b);
	s = _T("点击无效");
	CClientDC dc(this);
	if (point.x > pDoc->A.left && point.x<pDoc->A.right && point.y>pDoc->A.top && point.y < pDoc->A.bottom)
		dc.TextOutW(150, 125, a);
	else
		if (point.x > pDoc->B.left && point.x<pDoc->B.right && point.y>pDoc->B.top && point.y < pDoc->B.bottom)
			dc.TextOutW(250, 125, b);
		else
			dc.TextOutW(400,200,s);
	

	CView::OnLButtonDown(nFlags, point);
}


void CEX4_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CEX4_3Doc* pDoc = GetDocument();
	CString c;
	c.Format(_T("%d"), m + n);
	CClientDC dc(this);
	if (point.x > pDoc->C.left && point.x<pDoc->C.right && point.y>pDoc->C.top && point.y < pDoc->C.bottom)
		dc.TextOutW(350,125,c);

	CView::OnRButtonDown(nFlags, point);
}




