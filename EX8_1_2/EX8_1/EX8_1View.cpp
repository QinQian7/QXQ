
// EX8_1View.cpp : CEX8_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EX8_1.h"
#endif

#include "EX8_1Doc.h"
#include "EX8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEX8_1View

IMPLEMENT_DYNCREATE(CEX8_1View, CView)

BEGIN_MESSAGE_MAP(CEX8_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowName, &CEX8_1View::OnShowname)
	ON_COMMAND(ID_ShowPicture, &CEX8_1View::OnShowpicture)
END_MESSAGE_MAP()

// CEX8_1View 构造/析构

CEX8_1View::CEX8_1View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CEX8_1View::~CEX8_1View()
{
}

BOOL CEX8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEX8_1View 绘制

void CEX8_1View::OnDraw(CDC* /*pDC*/)
{
	CEX8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEX8_1View 打印

BOOL CEX8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEX8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEX8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEX8_1View 诊断

#ifdef _DEBUG
void CEX8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX8_1Doc* CEX8_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX8_1Doc)));
	return (CEX8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX8_1View 消息处理程序


void CEX8_1View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("覃小倩");
	CClientDC dc(this);
	dc.TextOutW(600,200,s);
}


void CEX8_1View::OnShowpicture()
{
	// TODO: 在此添加命令处理程序代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	CClientDC dc(this);
	dc.BitBlt(0,0,m_nWidth,m_nHeight,&MemDC,0,0,SRCCOPY);

}
