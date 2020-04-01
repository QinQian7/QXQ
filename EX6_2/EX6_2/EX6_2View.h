
// EX6_2View.h : CEX6_2View 类的接口
//

#pragma once


class CEX6_2View : public CView
{
protected: // 仅从序列化创建
	CEX6_2View();
	DECLARE_DYNCREATE(CEX6_2View)

// 特性
public:
	CEX6_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CEX6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // EX6_2View.cpp 中的调试版本
inline CEX6_2Doc* CEX6_2View::GetDocument() const
   { return reinterpret_cast<CEX6_2Doc*>(m_pDocument); }
#endif

