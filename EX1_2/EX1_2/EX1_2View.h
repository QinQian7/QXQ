
// EX1_2View.h : CEX1_2View ��Ľӿ�
//

#pragma once


class CEX1_2View : public CView
{
protected: // �������л�����
	CEX1_2View();
	DECLARE_DYNCREATE(CEX1_2View)

// ����
public:
	CEX1_2Doc* GetDocument() const;

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
	virtual ~CEX1_2View();
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

#ifndef _DEBUG  // EX1_2View.cpp �еĵ��԰汾
inline CEX1_2Doc* CEX1_2View::GetDocument() const
   { return reinterpret_cast<CEX1_2Doc*>(m_pDocument); }
#endif

