
// EX4_1View.cpp : CEX4_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX4_1.h"
#endif

#include "EX4_1Doc.h"
#include "EX4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX4_1View

IMPLEMENT_DYNCREATE(CEX4_1View, CView)

BEGIN_MESSAGE_MAP(CEX4_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CEX4_1View 构造/析构

CEX4_1View::CEX4_1View()
{
	// TODO: 在此处添加构造代码

}

CEX4_1View::~CEX4_1View()
{
}

BOOL CEX4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX4_1View 绘制

void CEX4_1View::OnDraw(CDC* /*pDC*/)
{
	CEX4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX4_1View 打印

BOOL CEX4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEX4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEX4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEX4_1View 诊断

#ifdef _DEBUG
void CEX4_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX4_1Doc* CEX4_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX4_1Doc)));
	return (CEX4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX4_1View 消息处理程序


void CEX4_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}


void CEX4_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正在抬起");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonUp(nFlags, point);
}
