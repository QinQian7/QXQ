
// EX10_1View.h : CEX10_1View ��Ľӿ�
//

#pragma once


class CEX10_1View : public CView
{
protected: // �������л�����
	CEX10_1View();
	DECLARE_DYNCREATE(CEX10_1View)

// ����
public:
	CEX10_1Doc* GetDocument() const;

// ����
public:
	CString str;
	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX10_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // EX10_1View.cpp �еĵ��԰汾
inline CEX10_1Doc* CEX10_1View::GetDocument() const
   { return reinterpret_cast<CEX10_1Doc*>(m_pDocument); }
#endif

