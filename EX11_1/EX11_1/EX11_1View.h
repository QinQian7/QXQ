
// EX11_1View.h : CEX11_1View ��Ľӿ�
//

#pragma once
#include "MyDlg0.h"

class CEX11_1View : public CView
{
protected: // �������л�����
	CEX11_1View();
	DECLARE_DYNCREATE(CEX11_1View)

// ����
public:
	CEX11_1Doc* GetDocument() const;

// ����
public:
	int show_hide;
	MyDlg0 *pD;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX11_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnShowhide();
};

#ifndef _DEBUG  // EX11_1View.cpp �еĵ��԰汾
inline CEX11_1Doc* CEX11_1View::GetDocument() const
   { return reinterpret_cast<CEX11_1Doc*>(m_pDocument); }
#endif

