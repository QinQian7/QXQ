
// EX3_1View.h : CEX3_1View ��Ľӿ�
//

#pragma once


class CEX3_1View : public CView
{
protected: // �������л�����
	CEX3_1View();
	DECLARE_DYNCREATE(CEX3_1View)

// ����
public:
	CEX3_1Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&> ca;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CEX3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX3_1View.cpp �еĵ��԰汾
inline CEX3_1Doc* CEX3_1View::GetDocument() const
   { return reinterpret_cast<CEX3_1Doc*>(m_pDocument); }
#endif

