
// EX4_1View.h : CEX4_1View ��Ľӿ�
//

#pragma once


class CEX4_1View : public CView
{
protected: // �������л�����
	CEX4_1View();
	DECLARE_DYNCREATE(CEX4_1View)

// ����
public:
	CEX4_1Doc* GetDocument() const;

// ����
public:

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
	virtual ~CEX4_1View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX4_1View.cpp �еĵ��԰汾
inline CEX4_1Doc* CEX4_1View::GetDocument() const
   { return reinterpret_cast<CEX4_1Doc*>(m_pDocument); }
#endif

