
// EX2_1View.h : CEX2_1View ��Ľӿ�
//

#pragma once


class CEX2_1View : public CView
{
protected: // �������л�����
	CEX2_1View();
	DECLARE_DYNCREATE(CEX2_1View)

// ����
public:
	CEX2_1Doc* GetDocument() const;

// ����
public:

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
	virtual ~CEX2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // EX2_1View.cpp �еĵ��԰汾
inline CEX2_1Doc* CEX2_1View::GetDocument() const
   { return reinterpret_cast<CEX2_1Doc*>(m_pDocument); }
#endif

