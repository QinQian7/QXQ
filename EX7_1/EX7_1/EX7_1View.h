
// EX7_1View.h : CEX7_1View ��Ľӿ�
//

#pragma once


class CEX7_1View : public CView
{
protected: // �������л�����
	CEX7_1View();
	DECLARE_DYNCREATE(CEX7_1View)

// ����
public:
	CEX7_1Doc* GetDocument() const;

// ����
public:
	int t;
	bool set;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX7_1View();
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

#ifndef _DEBUG  // EX7_1View.cpp �еĵ��԰汾
inline CEX7_1Doc* CEX7_1View::GetDocument() const
   { return reinterpret_cast<CEX7_1Doc*>(m_pDocument); }
#endif

