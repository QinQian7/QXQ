
// EX9View.cpp : CEX9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX9.h"
#endif

#include "EX9Doc.h"
#include "EX9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX9View

IMPLEMENT_DYNCREATE(CEX9View, CView)

BEGIN_MESSAGE_MAP(CEX9View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CEX9View::OnFileOpen)
END_MESSAGE_MAP()

// CEX9View 构造/析构

CEX9View::CEX9View()
{
	// TODO: 在此处添加构造代码

}

CEX9View::~CEX9View()
{
}

BOOL CEX9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX9View 绘制

void CEX9View::OnDraw(CDC* pDC)
{
	CEX9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPoint c;
	CRect cr;
	GetClientRect(&cr);
	c = cr.CenterPoint();
	
	if (a==IDOK) 
	{
	    img.Draw(pDC->m_hDC, c.x - img.GetWidth() / 2, c.y - img.GetHeight() / 2, img.GetWidth(), img.GetHeight());
	}
	
}


// CEX9View 诊断

#ifdef _DEBUG
void CEX9View::AssertValid() const
{
	CView::AssertValid();
}

void CEX9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX9Doc* CEX9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX9Doc)));
	return (CEX9Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX9View 消息处理程序


void CEX9View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码


	CFileDialog cfd(true);
	 a = cfd.DoModal();
	 if (a == IDOK)
	filename = cfd.GetPathName();
	img.Load(filename);
	Invalidate();
}
