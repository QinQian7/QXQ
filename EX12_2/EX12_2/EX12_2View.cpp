
// EX12_2View.cpp : CEX12_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX12_2.h"
#endif

#include "EX12_2Doc.h"
#include "EX12_2View.h"
#include "Plus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_2View

IMPLEMENT_DYNCREATE(CEX12_2View, CView)

BEGIN_MESSAGE_MAP(CEX12_2View, CView)
	ON_COMMAND(ID_POPOUT, &CEX12_2View::OnPopout)
END_MESSAGE_MAP()

// CEX12_2View 构造/析构

CEX12_2View::CEX12_2View()
{
	// TODO: 在此处添加构造代码

}

CEX12_2View::~CEX12_2View()
{
}

BOOL CEX12_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX12_2View 绘制

void CEX12_2View::OnDraw(CDC* /*pDC*/)
{
	CEX12_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX12_2View 诊断

#ifdef _DEBUG
void CEX12_2View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_2Doc* CEX12_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_2Doc)));
	return (CEX12_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_2View 消息处理程序


void CEX12_2View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	Plus dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		int X, Y, R;
		
		X = dlg.x;
		Y = dlg.y;
	}

}
