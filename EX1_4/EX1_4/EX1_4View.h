
// EX1_4View.h : CEX1_4View ��Ľӿ�
//

#pragma once


class CEX1_4View : public CView
{
protected: // �������л�����
	CEX1_4View();
	DECLARE_DYNCREATE(CEX1_4View)

// ����
public:
	CEX1_4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX1_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // EX1_4View.cpp �еĵ��԰汾
inline CEX1_4Doc* CEX1_4View::GetDocument() const
   { return reinterpret_cast<CEX1_4Doc*>(m_pDocument); }
#endif

