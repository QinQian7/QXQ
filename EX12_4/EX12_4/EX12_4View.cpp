
// EX12_4View.cpp : CEX12_4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX12_4.h"
#endif

#include "EX12_4Doc.h"
#include "EX12_4View.h"
#include "Combine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX12_4View

IMPLEMENT_DYNCREATE(CEX12_4View, CView)

BEGIN_MESSAGE_MAP(CEX12_4View, CView)
	ON_COMMAND(ID_POPOUT, &CEX12_4View::OnPopout)
END_MESSAGE_MAP()

// CEX12_4View 构造/析构

CEX12_4View::CEX12_4View()
{
	// TODO: 在此处添加构造代码

}

CEX12_4View::~CEX12_4View()
{
}

BOOL CEX12_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX12_4View 绘制

void CEX12_4View::OnDraw(CDC* /*pDC*/)
{
	CEX12_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX12_4View 诊断

#ifdef _DEBUG
void CEX12_4View::AssertValid() const
{
	CView::AssertValid();
}

void CEX12_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX12_4Doc* CEX12_4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX12_4Doc)));
	return (CEX12_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX12_4View 消息处理程序


void CEX12_4View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	Combine dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		int X;
		CString S1, S2;		
		S1 = dlg.s1;
		X = dlg.x;
		S2 = dlg.s2;
	}
}
