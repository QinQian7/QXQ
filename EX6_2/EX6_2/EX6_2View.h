
// EX6_2View.h : CEX6_2View ��Ľӿ�
//

#pragma once


class CEX6_2View : public CView
{
protected: // �������л�����
	CEX6_2View();
	DECLARE_DYNCREATE(CEX6_2View)

// ����
public:
	CEX6_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX6_2View.cpp �еĵ��԰汾
inline CEX6_2Doc* CEX6_2View::GetDocument() const
   { return reinterpret_cast<CEX6_2Doc*>(m_pDocument); }
#endif

