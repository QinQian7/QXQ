
// EX12_2View.h : CEX12_2View ��Ľӿ�
//

#pragma once


class CEX12_2View : public CView
{
protected: // �������л�����
	CEX12_2View();
	DECLARE_DYNCREATE(CEX12_2View)

// ����
public:
	CEX12_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX12_2View();
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

#ifndef _DEBUG  // EX12_2View.cpp �еĵ��԰汾
inline CEX12_2Doc* CEX12_2View::GetDocument() const
   { return reinterpret_cast<CEX12_2Doc*>(m_pDocument); }
#endif

