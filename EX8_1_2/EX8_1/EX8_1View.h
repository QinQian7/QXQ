
// EX8_1View.h : CEX8_1View ��Ľӿ�
//

#pragma once


class CEX8_1View : public CView
{
protected: // �������л�����
	CEX8_1View();
	DECLARE_DYNCREATE(CEX8_1View)

// ����
public:
	CEX8_1Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

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
	virtual ~CEX8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
	afx_msg void OnShowpicture();
};

#ifndef _DEBUG  // EX8_1View.cpp �еĵ��԰汾
inline CEX8_1Doc* CEX8_1View::GetDocument() const
   { return reinterpret_cast<CEX8_1Doc*>(m_pDocument); }
#endif

