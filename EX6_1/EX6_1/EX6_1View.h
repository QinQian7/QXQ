
// EX6_1View.h : CEX6_1View ��Ľӿ�
//

#pragma once


class CEX6_1View : public CView
{
protected: // �������л�����
	CEX6_1View();
	DECLARE_DYNCREATE(CEX6_1View)

// ����
public:
	CEX6_1Doc* GetDocument() const;

// ����
public:
	CPoint a;
	int m, n;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX6_1View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX6_1View.cpp �еĵ��԰汾
inline CEX6_1Doc* CEX6_1View::GetDocument() const
   { return reinterpret_cast<CEX6_1Doc*>(m_pDocument); }
#endif

