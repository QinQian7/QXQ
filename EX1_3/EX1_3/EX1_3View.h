
// EX1_3View.h : CEX1_3View ��Ľӿ�
//

#pragma once


class CEX1_3View : public CView
{
protected: // �������л�����
	CEX1_3View();
	DECLARE_DYNCREATE(CEX1_3View)

// ����
public:
	CEX1_3Doc* GetDocument() const;

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
	virtual ~CEX1_3View();
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

#ifndef _DEBUG  // EX1_3View.cpp �еĵ��԰汾
inline CEX1_3Doc* CEX1_3View::GetDocument() const
   { return reinterpret_cast<CEX1_3Doc*>(m_pDocument); }
#endif

