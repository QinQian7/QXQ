
// EX8_3View.h : CEX8_3View ��Ľӿ�
//

#pragma once


class CEX8_3View : public CView
{
protected: // �������л�����
	CEX8_3View();
	DECLARE_DYNCREATE(CEX8_3View)

// ����
public:
	CEX8_3Doc* GetDocument() const;

// ����
public:
	int set;

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
	virtual ~CEX8_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX8_3View.cpp �еĵ��԰汾
inline CEX8_3Doc* CEX8_3View::GetDocument() const
   { return reinterpret_cast<CEX8_3Doc*>(m_pDocument); }
#endif

