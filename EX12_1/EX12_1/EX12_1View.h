
// EX12_1View.h : CEX12_1View ��Ľӿ�
//

#pragma once


class CEX12_1View : public CView
{
protected: // �������л�����
	CEX12_1View();
	DECLARE_DYNCREATE(CEX12_1View)

// ����
public:
	CEX12_1Doc* GetDocument() const;

// ����
public:
	CPoint p;
	int xu, yu, xd, yd, W, L;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX12_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX12_1View.cpp �еĵ��԰汾
inline CEX12_1Doc* CEX12_1View::GetDocument() const
   { return reinterpret_cast<CEX12_1Doc*>(m_pDocument); }
#endif

