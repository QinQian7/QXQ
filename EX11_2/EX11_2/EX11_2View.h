
// EX11_2View.h : CEX11_2View ��Ľӿ�
//

#pragma once


class CEX11_2View : public CView
{
protected: // �������л�����
	CEX11_2View();
	DECLARE_DYNCREATE(CEX11_2View)

// ����
public:
	CEX11_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX11_2View();
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
};

#ifndef _DEBUG  // EX11_2View.cpp �еĵ��԰汾
inline CEX11_2Doc* CEX11_2View::GetDocument() const
   { return reinterpret_cast<CEX11_2Doc*>(m_pDocument); }
#endif

