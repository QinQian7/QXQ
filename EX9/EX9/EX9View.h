
// EX9View.h : CEX9View ��Ľӿ�
//

#pragma once


class CEX9View : public CView
{
protected: // �������л�����
	CEX9View();
	DECLARE_DYNCREATE(CEX9View)

// ����
public:
	CEX9Doc* GetDocument() const;

// ����
public:
	CString filename;
	CImage img;
	int a;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CEX9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // EX9View.cpp �еĵ��԰汾
inline CEX9Doc* CEX9View::GetDocument() const
   { return reinterpret_cast<CEX9Doc*>(m_pDocument); }
#endif

