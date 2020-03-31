
// EX1_3View.h : CEX1_3View 类的接口
//

#pragma once


class CEX1_3View : public CView
{
protected: // 仅从序列化创建
	CEX1_3View();
	DECLARE_DYNCREATE(CEX1_3View)

// 特性
public:
	CEX1_3Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CEX1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX1_3View.cpp 中的调试版本
inline CEX1_3Doc* CEX1_3View::GetDocument() const
   { return reinterpret_cast<CEX1_3Doc*>(m_pDocument); }
#endif

