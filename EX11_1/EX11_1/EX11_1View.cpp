
// EX11_1View.cpp : CEX11_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX11_1.h"
#endif

#include "EX11_1Doc.h"
#include "EX11_1View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX11_1View

IMPLEMENT_DYNCREATE(CEX11_1View, CView)

BEGIN_MESSAGE_MAP(CEX11_1View, CView)
	ON_COMMAND(ID_POPOUT, &CEX11_1View::OnPopout)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SHOWHIDE, &CEX11_1View::OnShowhide)
END_MESSAGE_MAP()

// CEX11_1View 构造/析构

CEX11_1View::CEX11_1View()
{
	// TODO: 在此处添加构造代码
	show_hide = 1;
	pD = NULL;
}

CEX11_1View::~CEX11_1View()
{
}

BOOL CEX11_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX11_1View 绘制

void CEX11_1View::OnDraw(CDC* /*pDC*/)
{
	CEX11_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX11_1View 诊断

#ifdef _DEBUG
void CEX11_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX11_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX11_1Doc* CEX11_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX11_1Doc)));
	return (CEX11_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX11_1View 消息处理程序


void CEX11_1View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg0 dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		
		CString str = _T("你已退出对话框");
		GetDC()->TextOutW(300, 100, str);

	}


}


void CEX11_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	pD=new MyDlg0;
	pD->Create(IDD_DIALOG1);
	pD->ShowWindow(1);

	CView::OnLButtonDblClk(nFlags, point);
}


void CEX11_1View::OnShowhide()
{
	// TODO: 在此添加命令处理程序代码
	if (show_hide == 1)
		show_hide = 0;
	else
		show_hide = 1;
	pD->ShowWindow(show_hide);
}
