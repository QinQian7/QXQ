
// EX7_2View.h : CEX7_2View ��Ľӿ�
//

#pragma once


class CEX7_2View : public CView
{
protected: // �������л�����
	CEX7_2View();
	DECLARE_DYNCREATE(CEX7_2View)

// ����
public:
	CEX7_2Doc* GetDocument() const;

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
	virtual ~CEX7_2View();
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

#ifndef _DEBUG  // EX7_2View.cpp �еĵ��԰汾
inline CEX7_2Doc* CEX7_2View::GetDocument() const
   { return reinterpret_cast<CEX7_2Doc*>(m_pDocument); }
#endif

