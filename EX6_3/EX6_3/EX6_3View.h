
// EX6_3View.h : CEX6_3View ��Ľӿ�
//

#pragma once


class CEX6_3View : public CView
{
protected: // �������л�����
	CEX6_3View();
	DECLARE_DYNCREATE(CEX6_3View)

// ����
public:
	CEX6_3Doc* GetDocument() const;

// ����
public:
	bool set;
	int r,l;
	CRect a, cr;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX6_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // EX6_3View.cpp �еĵ��԰汾
inline CEX6_3Doc* CEX6_3View::GetDocument() const
   { return reinterpret_cast<CEX6_3Doc*>(m_pDocument); }
#endif

