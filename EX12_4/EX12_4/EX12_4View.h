
// EX12_4View.h : CEX12_4View ��Ľӿ�
//

#pragma once


class CEX12_4View : public CView
{
protected: // �������л�����
	CEX12_4View();
	DECLARE_DYNCREATE(CEX12_4View)

// ����
public:
	CEX12_4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX12_4View();
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

#ifndef _DEBUG  // EX12_4View.cpp �еĵ��԰汾
inline CEX12_4Doc* CEX12_4View::GetDocument() const
   { return reinterpret_cast<CEX12_4Doc*>(m_pDocument); }
#endif

