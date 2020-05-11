
// EX8_3View.h : CEX8_3View 类的接口
//

#pragma once


class CEX8_3View : public CView
{
protected: // 仅从序列化创建
	CEX8_3View();
	DECLARE_DYNCREATE(CEX8_3View)

// 特性
public:
	CEX8_3Doc* GetDocument() const;

// 操作
public:
	int set;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CEX8_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawline();
	afx_msg void OnDrawrectangle();
	afx_msg void OnDrawellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX8_3View.cpp 中的调试版本
inline CEX8_3Doc* CEX8_3View::GetDocument() const
   { return reinterpret_cast<CEX8_3Doc*>(m_pDocument); }
#endif

