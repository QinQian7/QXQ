
// EX13_1View.cpp : CEX13_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX13_1.h"
#endif

#include "EX13_1Doc.h"
#include "EX13_1View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX13_1View

IMPLEMENT_DYNCREATE(CEX13_1View, CView)

BEGIN_MESSAGE_MAP(CEX13_1View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &CEX13_1View::OnPopout)
END_MESSAGE_MAP()

// CEX13_1View 构造/析构

CEX13_1View::CEX13_1View()
{
	// TODO: 在此处添加构造代码

}

CEX13_1View::~CEX13_1View()
{
}

BOOL CEX13_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX13_1View 绘制

void CEX13_1View::OnDraw(CDC* /*pDC*/)
{
	CEX13_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX13_1View 诊断

#ifdef _DEBUG
void CEX13_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX13_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX13_1Doc* CEX13_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX13_1Doc)));
	return (CEX13_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX13_1View 消息处理程序


void CEX13_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}



void CEX13_1View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		CString S;
		//S = dlg.s;
        //S= filename;
		dlg.s = filename;
	}
	
}
