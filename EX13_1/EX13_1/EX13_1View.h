
// EX13_1View.h : CEX13_1View ��Ľӿ�
//

#pragma once


class CEX13_1View : public CView
{
protected: // �������л�����
	CEX13_1View();
	DECLARE_DYNCREATE(CEX13_1View)

// ����
public:
	CEX13_1Doc* GetDocument() const;

// ����
public:
	CString filename;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX13_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	afx_msg void OnPopout();
};

#ifndef _DEBUG  // EX13_1View.cpp �еĵ��԰汾
inline CEX13_1Doc* CEX13_1View::GetDocument() const
   { return reinterpret_cast<CEX13_1Doc*>(m_pDocument); }
#endif

