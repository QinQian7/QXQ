
// EX4_3View.h : CEX4_3View ��Ľӿ�
//

#pragma once


class CEX4_3View : public CView
{
protected: // �������л�����
	CEX4_3View();
	DECLARE_DYNCREATE(CEX4_3View)

// ����
public:
	CEX4_3Doc* GetDocument() const;

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
	virtual ~CEX4_3View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShowmunber();
};

#ifndef _DEBUG  // EX4_3View.cpp �еĵ��԰汾
inline CEX4_3Doc* CEX4_3View::GetDocument() const
   { return reinterpret_cast<CEX4_3Doc*>(m_pDocument); }
#endif

