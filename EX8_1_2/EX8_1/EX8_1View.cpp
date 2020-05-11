
// EX8_1View.cpp : CEX8_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowName, &CEX8_1View::OnShowname)
	ON_COMMAND(ID_ShowPicture, &CEX8_1View::OnShowpicture)
END_MESSAGE_MAP()

// CEX8_1View ����/����

CEX8_1View::CEX8_1View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEX8_1View ����

void CEX8_1View::OnDraw(CDC* /*pDC*/)
{
	CEX8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEX8_1View ��ӡ

BOOL CEX8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEX8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEX8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEX8_1View ���

#ifdef _DEBUG
void CEX8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CEX8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEX8_1Doc* CEX8_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEX8_1Doc)));
	return (CEX8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEX8_1View ��Ϣ�������


void CEX8_1View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s = _T("��Сٻ");
	CClientDC dc(this);
	dc.TextOutW(600,200,s);
}


void CEX8_1View::OnShowpicture()
{
	// TODO: �ڴ���������������
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	CClientDC dc(this);
	dc.BitBlt(0,0,m_nWidth,m_nHeight,&MemDC,0,0,SRCCOPY);

}
